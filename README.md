Notions ft_container :

-Typedef
    Permet de definir un nouveau type.
        example : typedef   T     value_type;
        *Dans cet exemple, typedef indique que le type value_type representera le type T.*

-Typename
    Permet de signaler au compilateur que ce qui suit est un type et non un membre statique.
        exemple : typename  allocator_type::reference   reference
        *Dans cet exemple, typename indique que reference est un type de allocator_type*.

-Typedef / Typename :
    Permet de definir un nouveau type, a partir d'un type deja existant.
        exemple : typedef typename  allocator_type::reference	reference;
        *Dans cet exemple, typename indique que reference est un type de allocator_type typedef permet de l'apeller reference*.

-Explicit :
    Aucune conversion implicit n'est possible pour un constructeur avec le tag explicit. Il ne peut pas non plus etre 
    instancier par copy.
        exemlace : explicit     vector(size_type n);
        *Dans cet exemple, le constructeur de vector ne pourras pas prendre un autre type que size_type (pas de conversion implicit possible).*