Notions ft_container :

-Typedef
    Permet de redefinir un nom de type.
        example : typedef   _Tp     value_type;
        *Dans cet exemple, typedef indique que le type value_type representera le type _Tp.*

-Typename
    Permet de signaler au compilateur que ce qui suit est une definition de type et non un membre statique.
        exemple : typename  allocator_type::reference   reference
        *Dans cet exemple, typename indique que reference est un type de allocator_type*.

-Typedef / Typename :
    Permet de redefinir un nom de type, a partir d'une definition de type.
        exemple : typedef typename  allocator_type::reference	reference;
        *Dans cet exemple, typename indique que reference est un type de allocator_type typedef permet de l'apeller reference*.

-Explicit