// listnode* mergelist(listnode* s1,listnode* s2)
// {
//     if(s1==NULL || s2 == NULL)
//     {
//         return s1 == null ? s2 : s1;
//     }

//     //case1
//     if(s1->value <= s2->value)
//     {
//         s1->next = mergelist(s1->next,s2);
//         return s1;
//     }
//     //case 2
//     else
//     {
//         s2->next = mergelist(s1,s2->next);
//         return s2;
//     }
// }