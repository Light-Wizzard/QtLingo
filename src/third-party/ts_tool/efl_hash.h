#ifndef __EFL_HASH_h__
#define __EFL_HASH_h__
/************************************************
 *  @brief type of efl_hash.
 *  \typedef hash_t
 ***********************************************/
typedef unsigned long hash_t;
/************************************************
 * @brief do some fancy bitwanking on the string.
 * efl_hash
 ***********************************************/
inline hash_t efl_hash(const wchar_t * s)
{
    const wchar_t *name = (const wchar_t*) (wchar_t*) s;
    unsigned long h = 0;
    while (*name != L'\0')
    {
        unsigned long g;
        h = (h << 4) + (hash_t)(*name++);
        if ((g = (h & 0xF0000000UL))!=0) { h ^= (g >> 24); }
        h &= ~g;
    }
    return h;
}
#endif // __EFL_HASH_h__
/******************************* End of File *********************************/
