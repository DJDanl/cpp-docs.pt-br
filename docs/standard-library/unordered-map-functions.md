---
title: Funções &lt;unordered_map&gt;
ms.date: 11/04/2016
f1_keywords:
- unordered_map/std::swap
- unordered_map/std::swap (unordered_map)
- unordered_map/std::swap (unordered_multimap)
ms.assetid: cf2e4115-f205-4a0e-90be-a143ffcc1f44
helpviewer_keywords:
- std::swap (unordered_map/multimap)
ms.openlocfilehash: 9e572e4ba8cb4c6cb15329342a7947c35ece7270
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844256"
---
# <a name="ltunordered_mapgt-functions"></a>Funções &lt;unordered_map&gt;

[trocar (unordered_map)](#swap) 
 [trocar (unordered_multimap)](#swap_function_multimap)

## <a name="swap-unordered_map"></a><a name="swap"></a> trocar (unordered_map)

Alterna o conteúdo de dois contêineres.

```cpp
template <class Key, class Ty, class Hash, class Pred, class Alloc>
void swap(
    unordered_map <Key, Ty, Hash, Pred, Alloc>& left,
    unordered_map <Key, Ty, Hash, Pred, Alloc>& right);
```

### <a name="parameters"></a>parâmetros

*Chaves*\
O tipo principal.

*Ty*\
O tipo mapeado.

*Tralha*\
O tipo de objeto da função de hash.

*Pred*\
O tipo de objeto da função de comparação de igualdade.

*Alocação*\
A classe do alocador.

*mantida*\
O primeiro contêiner para alternância.

*Certo*\
O segundo contêiner para alternância.

### <a name="remarks"></a>Comentários

A função de modelo executa `left.` [unordered_map:: swap](../standard-library/unordered-map-class.md#swap) `(right)` .

### <a name="example"></a>Exemplo

```cpp
// std__unordered_map__u_m_swap.cpp
// compile with: /EHsc
#include <unordered_map>
#include <iostream>

typedef std::unordered_map<char, int> Mymap;
int main()
    {
    Mymap c1;

    c1.insert(Mymap::value_type('a', 1));
    c1.insert(Mymap::value_type('b', 2));
    c1.insert(Mymap::value_type('c', 3));

// display contents " [c 3] [b 2] [a 1]"
    for (Mymap::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << " [" << it->first << ", " << it->second << "]";
    std::cout << std::endl;

    Mymap c2;

    c2.insert(Mymap::value_type('d', 4));
    c2.insert(Mymap::value_type('e', 5));
    c2.insert(Mymap::value_type('f', 6));

    c1.swap(c2);

// display contents " [f 6] [e 5] [d 4]"
    for (Mymap::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << " [" << it->first << ", " << it->second << "]";
    std::cout << std::endl;

    swap(c1, c2);

// display contents " [c 3] [b 2] [a 1]"
    for (Mymap::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << " [" << it->first << ", " << it->second << "]";
    std::cout << std::endl;

    return (0);
    }
```

```Output
[c, 3] [b, 2] [a, 1]
[f, 6] [e, 5] [d, 4]
[c, 3] [b, 2] [a, 1]
```

## <a name="swap-unordered_multimap"></a><a name="swap_function_multimap"></a> trocar (unordered_multimap)

Alterna o conteúdo de dois contêineres.

```cpp
template <class Key, class Ty, class Hash, class Pred, class Alloc>
void swap(
    unordered_multimap <Key, Ty, Hash, Pred, Alloc>& left,
    unordered_multimap <Key, Ty, Hash, Pred, Alloc>& right);
```

### <a name="parameters"></a>parâmetros

*Chaves*\
O tipo principal.

*Ty*\
O tipo mapeado.

*Tralha*\
O tipo de objeto da função de hash.

*Pred*\
O tipo de objeto da função de comparação de igualdade.

*Alocação*\
A classe do alocador.

*mantida*\
O primeiro contêiner para alternância.

*Certo*\
O segundo contêiner para alternância.

### <a name="remarks"></a>Comentários

A função de modelo executa `left.` [unordered_multimap:: swap](../standard-library/unordered-multimap-class.md#swap) `(right)` .

### <a name="example"></a>Exemplo

```cpp
// std__unordered_map__u_mm_swap.cpp
// compile with: /EHsc
#include <unordered_map>
#include <iostream>

typedef std::unordered_multimap<char, int> Mymap;
int main()
{
    Mymap c1;

    c1.insert(Mymap::value_type('a', 1));
    c1.insert(Mymap::value_type('b', 2));
    c1.insert(Mymap::value_type('c', 3));

    // display contents " [c 3] [b 2] [a 1]"
    for (Mymap::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << " [" << it->first << ", " << it->second << "]";
    std::cout << std::endl;

    Mymap c2;

    c2.insert(Mymap::value_type('d', 4));
    c2.insert(Mymap::value_type('e', 5));
    c2.insert(Mymap::value_type('f', 6));

    c1.swap(c2);

    // display contents " [f 6] [e 5] [d 4]"
    for (Mymap::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << " [" << it->first << ", " << it->second << "]";
    std::cout << std::endl;

    swap(c1, c2);

    // display contents " [c 3] [b 2] [a 1]"
    for (Mymap::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << " [" << it->first << ", " << it->second << "]";
    std::cout << std::endl;

    return (0);
}
```

```Output
[c, 3] [b, 2] [a, 1]
[f, 6] [e, 5] [d, 4]
[c, 3] [b, 2] [a, 1]
```

## <a name="see-also"></a>Confira também

[<unordered_map>](../standard-library/unordered-map.md)
