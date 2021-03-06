#include "ts_model.h"

/************************************************
   @brief visitors/
   \namespace visitors
 ***********************************************/
namespace visitors
{
    /************************************************
     * @brief visit(const document_node *node).
     * visit
     ***********************************************/
    void document_dump::visit(const document_node *node) const
    {
        m_writer.writeStartDocument();
        std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node){ node->visit(*this); } );
        m_writer.writeEndDocument();
    }
    /************************************************
     * @brief visit(const DTD_node *node).
     *  visit
     ***********************************************/
    void document_dump::visit(const DTD_node *node) const
    {
        m_writer.writeDTD(node->id());
    }
    /************************************************
     * @brief visit(const element_node *node).
     * visit
     ***********************************************/
    void document_dump::visit(const element_node *node) const
    {
        m_writer.writeStartElement(node->name());
        m_writer.writeAttributes(node->attributes());
        m_writer.writeCharacters(node->text());
        std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node){ node->visit(*this); } );
        m_writer.writeEndElement();
    }
    /************************************************
     * @brief visit(const document_node *node).
     * visit
     ***********************************************/
    void string_extractor_replacer::visit(const document_node *node)
    {
        std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node){ node->visit(*this); } );
    }
    /************************************************
     * @brief visit(const DTD_node *).
     * visit
     ***********************************************/
    void string_extractor_replacer::visit(const DTD_node * /*node*/) { }
    /************************************************
     * @brief visit(element_node *node).
     * visit
     ***********************************************/
    void string_extractor_replacer::visit(element_node *node)
    {
        if(st_WaitForMessage == m_state && element_node::ent_message == node->element_node_type())
        {
            m_state = st_WaitForSource | st_WaitForTranslation;
        }
        else if(st_WaitForSource & m_state && element_node::ent_source == node->element_node_type())
        {
            assert(!source);
            source = node;
            m_state &= ~st_WaitForSource;

            if(!(m_state & st_WaitForTranslation)) 
            {
                m_state |= st_Complete;
            }
            else
            {
                return;
            }
        }
        else if(st_WaitForTranslation & m_state && element_node::ent_translation == node->element_node_type())
        {
            assert(!translation);
            translation = node;
            m_state &= ~st_WaitForTranslation;

            if(!(m_state & st_WaitForSource)) 
            {
                m_state |= st_Complete;
            }
            else
            {
                return;
            }
        }

        if(st_Complete & m_state)
        {
            bool bSkipProcessing = false;

            if(!m_with_unfinished || !m_with_vanished || !m_unfinished_only)
            {
                QString attr_type = translation->attributes().value("type").toString();
                if(m_unfinished_only)
                {
                    bSkipProcessing = "unfinished" != attr_type;
                }
                else
                {
                    bSkipProcessing =  ("unfinished" == attr_type && !m_with_unfinished)
                                    || (("vanished" == attr_type || "obsolete" == attr_type) && !m_with_vanished);
                }
            }

            if(!bSkipProcessing)
            {
                hash_t hash = 0;
                QString text;

                if(!translation->text().isEmpty())
                {
                    text = translation->text();
                } 
                else
                {
                    text = source->text();
                }

                hash = efl_hash(text.toStdWString().c_str());
                translation->set_text(QString("[[[%1]]]").arg(hash, 8, 16, QChar('0')).toUpper());
                text = QString("%1 \"%2\"").arg(translation->text(), text);

                text.replace("\n", "\\n");
                text.replace("\r", "\\r");
                text.replace("\t", "\\t");

                m_vqs.insert(map_hashQString::value_type(hash, text));
            }

            source = translation = nullptr;
            m_state = st_WaitForMessage;
        }

        std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node) { node->visit(*this); });
    }
    /************************************************
     * @brief visit(const document_node *node).
     * visit
     ***********************************************/
    void back_string_replacer::visit(const document_node *node)
    {
        std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node){ node->visit(*this); } );
    }
    /************************************************
     * @brief visit(const DTD_node *).
     * visit
     ***********************************************/
    void back_string_replacer::visit(const DTD_node * /*node*/) { }
    /************************************************
     * @brief visit(element_node *node).
     * visit
     ***********************************************/
    void back_string_replacer::visit(element_node *node)
    {
        if(st_WaitForMessage == m_state && element_node::ent_message == node->element_node_type())
        {
            m_state = st_WaitForSource | st_WaitForTranslation;
        }
        else if(st_WaitForSource & m_state && element_node::ent_source == node->element_node_type())
        {
            assert(!source);
            source = node;
            m_state &= ~st_WaitForSource;

            if(!(m_state & st_WaitForTranslation)) 
            {
                m_state |= st_Complete;
            }
            else
            {
                return;
            }
        }
        else if(st_WaitForTranslation & m_state && element_node::ent_translation == node->element_node_type())
        {
            assert(!translation);
            translation = node;
            m_state &= ~st_WaitForTranslation;

            if(!(m_state & st_WaitForSource)) 
            {
                m_state |= st_Complete;
            }
            else
            {
                return;
            }
        }

        if(st_Complete & m_state)
        {
            map_QStringQString::const_iterator it = m_strings.find(translation->text());

            if(m_strings.end() == it)
            {
				std::cerr << "Unprocessed tags <source>: " << source->text().toUtf8().constData() 
						<< " <translation>: " << translation->text().toUtf8().constData() << std::endl;
            }
            else
            {
                QString text = it->second;

                text.replace("\\n", "\n");
                text.replace("\\r", "\r");
                text.replace("\\t", "\t");

                translation->set_text(text);
            }

            source = translation = nullptr;
            m_state = st_WaitForMessage;
        }

        std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node){ node->visit(*this); } );
    }
    /************************************************
     * @brief visit(TS_node *node).
     * visit
     ***********************************************/
    void back_string_replacer::visit(TS_node *node)
	{
        if(!m_langid.isEmpty())
        {
			node->replace_attribute_value("language", m_langid);
		}

		std::for_each(node->m_childs.begin(), node->m_childs.end(), [this](const base_node::base_node_ptr node)
		{ 
			node->visit(*this); 
		});
	}
}
/******************************* End of File *********************************/
