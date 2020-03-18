---
title: Operadores &lt;unordered_set&gt;
ms.date: 11/04/2016
f1_keywords:
- unordered_set/std::operator!=
- unordered_set/std::operator==
ms.assetid: 8653eea6-12f2-4dd7-aa2f-db38a71599a0
ms.openlocfilehash: 59a7154ed46ac788516bc9f42c3385ec8f07dcf1
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422503"
---
# <a name="ltunordered_setgt-operators"></a>Operadores &lt;unordered_set&gt;

## <a name="op_neq"></a>operador! =

Testa se o objeto [unordered_set](../standard-library/unordered-set-class.md) à esquerda do operador é diferente do objeto unordered_set à direita.

```cpp
bool operator!=(const unordered_set <Key, Hash, Pred, Allocator>& left, const unordered_set <Key, Hash, Pred, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `unordered_set`.

\ *à direita*
Um objeto do tipo `unordered_set`.

### <a name="return-value"></a>Valor retornado

**true** se os unordered_sets não forem iguais; **false** se forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre objetos unordered_set não é afetada pela ordem arbitrária em que eles armazenam seus elementos. Dois unordered_sets serão iguais se tiverem o mesmo número de elementos e os elementos em um contêiner forem uma permutação dos elementos do outro contêiner. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// unordered_set_ne.cpp
// compile by using: cl.exe /EHsc /nologo /W4 /MTd
#include <unordered_set>
#include <iostream>
#include <ios>

int main()
{
    using namespace std;

    unordered_set<char> c1, c2, c3;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    c2.insert('c');
    c2.insert('a');
    c2.insert('d');

    c3.insert('c');
    c3.insert('a');
    c3.insert('b');

   cout << boolalpha;
   cout << "c1 != c2: " << (c1 != c2) << endl;
   cout << "c1 != c3: " << (c1 != c3) << endl;
   cout << "c2 != c3: " << (c2 != c3) << endl;

    return (0);
}
```

**Saída:**

`c1 != c2: true`

`c1 != c3: false`

`c2 != c3: true`

## <a name="op_eq_eq"></a>operador = =

Testa se o objeto [unordered_set](../standard-library/unordered-set-class.md) à esquerda do operador é igual ao objeto unordered_set à direita.

```cpp
bool operator==(const unordered_set <Key, Hash, Pred, Allocator>& left, const unordered_set <Key, Hash, Pred, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `unordered_set`.

\ *à direita*
Um objeto do tipo `unordered_set`.

### <a name="return-value"></a>Valor retornado

**true** se os unordered_sets forem iguais; **false** se eles não forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre objetos unordered_set não é afetada pela ordem arbitrária em que eles armazenam seus elementos. Dois unordered_sets serão iguais se tiverem o mesmo número de elementos e os elementos em um contêiner forem uma permutação dos elementos do outro contêiner. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// unordered_set_eq.cpp
// compile by using: cl.exe /EHsc /nologo /W4 /MTd
#include <unordered_set>
#include <iostream>
#include <ios>

int main()
{
    using namespace std;

    unordered_set<char> c1, c2, c3;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    c2.insert('c');
    c2.insert('a');
    c2.insert('d');

    c3.insert('c');
    c3.insert('a');
    c3.insert('b');

   cout << boolalpha;
   cout << "c1 == c2: " << (c1 == c2) << endl;
   cout << "c1 == c3: " << (c1 == c3) << endl;
   cout << "c2 == c3: " << (c2 == c3) << endl;

    return (0);
}
```

```Output
c1 == c2: false
c1 == c3: true
c2 == c3: false
```

## <a name="op_neq_unordered_multiset"></a>operador! =

Testa se o objeto [unordered_multiset](../standard-library/unordered-multiset-class.md) à esquerda do operador é diferente do objeto unordered_multiset à direita.

```cpp
bool operator!=(const unordered_multiset <Key, Hash, Pred, Allocator>& left, const unordered_multiset <Key, Hash, Pred, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `unordered_multiset`.

\ *à direita*
Um objeto do tipo `unordered_multiset`.

### <a name="return-value"></a>Valor retornado

**true** se os unordered_multisets não forem iguais; **false** se forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre objetos unordered_multiset não é afetada pela ordem arbitrária em que eles armazenam seus elementos. Dois unordered_multisets serão iguais se tiverem o mesmo número de elementos e os elementos em um contêiner forem uma permutação dos elementos do outro contêiner. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// unordered_multiset_ne.cpp
// compile by using: cl.exe /EHsc /nologo /W4 /MTd
#include <unordered_set>
#include <iostream>
#include <ios>

int main()
{
    using namespace std;

    unordered_multiset<char> c1, c2, c3;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');
    c1.insert('c');

    c2.insert('c');
    c2.insert('c');
    c2.insert('a');
    c2.insert('d');

    c3.insert('c');
    c3.insert('c');
    c3.insert('a');
    c3.insert('b');

   cout << boolalpha;
   cout << "c1 != c2: " << (c1 != c2) << endl;
   cout << "c1 != c3: " << (c1 != c3) << endl;
   cout << "c2 != c3: " << (c2 != c3) << endl;

    return (0);
}
```

```Output
c1 != c2: true
c1 != c3: false
c2 != c3: true
```

## <a name="op_eq_eq_unordered_multiset"></a>operador = =

Testa se o objeto [unordered_multiset](../standard-library/unordered-multiset-class.md) à esquerda do operador é igual ao objeto unordered_multiset à direita.

```cpp
bool operator==(const unordered_multiset <Key, Hash, Pred, Allocator>& left, const unordered_multiset <Key, Hash, Pred, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `unordered_multiset`.

\ *à direita*
Um objeto do tipo `unordered_multiset`.

### <a name="return-value"></a>Valor retornado

**true** se os unordered_multisets forem iguais; **false** se eles não forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre objetos unordered_multiset não é afetada pela ordem arbitrária em que eles armazenam seus elementos. Dois unordered_multisets serão iguais se tiverem o mesmo número de elementos e os elementos em um contêiner forem uma permutação dos elementos do outro contêiner. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// unordered_multiset_eq.cpp
// compile by using: cl.exe /EHsc /nologo /W4 /MTd
#include <unordered_set>
#include <iostream>
#include <ios>

int main()
{
    using namespace std;

    unordered_multiset<char> c1, c2, c3;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');
    c1.insert('c');

    c2.insert('c');
    c2.insert('c');
    c2.insert('a');
    c2.insert('d');

    c3.insert('c');
    c3.insert('c');
    c3.insert('a');
    c3.insert('b');

   cout << boolalpha;
   cout << "c1 == c2: " << (c1 == c2) << endl;
   cout << "c1 == c3: " << (c1 == c3) << endl;
   cout << "c2 == c3: " << (c2 == c3) << endl;

    return (0);
}
```

```Output
c1 == c2: false
c1 == c3: true
c2 == c3: false
```
