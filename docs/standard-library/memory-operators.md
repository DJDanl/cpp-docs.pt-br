---
title: Operadores &lt;memory&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- memory/std::operator!=
- memory/std::operator>
- memory/std::operator>=
- memory/std::operator<
- memory/std::operator<=
- memory/std::operator<<
- memory/std::operator==
dev_langs:
- C++
ms.assetid: 257e3ba9-c4c2-4ae8-9b11-b156ba9c28de
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 01fe61112e5b36c8341e4a3209a9bec335549736
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="ltmemorygt-operators"></a>Operadores &lt;memory&gt;

||||
|-|-|-|
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|
|[operator&lt;](#op_lt)|[operator&lt;&lt;](#op_lt_lt)|[operator&lt;=](#op_lt_eq)|
|[operator==](#op_eq_eq)|

## <a name="op_neq"></a>  operator!=

Testa a desigualdade entre objetos.

```cpp
template <class Type, class Other>
bool operator!=(
    const allocator<Type>& left,
    const allocator<Other>& right) throw();

template <class T, class Del1, class U, class Del2>
bool operator!=(
    const unique_ptr<T, Del1>& left,
    const unique_ptr<U&, Del2>& right);

template <class Ty1, class Ty2>
bool operator!=(
    const shared_ptr<Ty1>& left,
    const shared_ptr<Ty2>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um dos objetos a ser testada para fins de desigualdade.

`right` Um dos objetos a ser testada para fins de desigualdade.

`Ty1` O tipo controlado pelo ponteiro compartilhado à esquerda.

`Ty2` O tipo controlado pelo ponteiro compartilhado à direita.

### <a name="return-value"></a>Valor de retorno

**true** se os objetos não forem iguais, **false** se os objetos forem iguais.

### <a name="remarks"></a>Comentários

O primeiro operador de modelo retorna false. (Todos os alocadores padrão são iguais.)

O segundo e o terceiro operadores de modelo retornam `!(left == right)`.

### <a name="example"></a>Exemplo

```cpp
// memory_op_me.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   allocator<double> Alloc;
   vector <char>:: allocator_type v1Alloc;

   if ( Alloc != v1Alloc )
      cout << "The allocator objects Alloc & v1Alloc not are equal."
           << endl;
   else
      cout << "The allocator objects Alloc & v1Alloc are equal."
           << endl;
}
```

```Output
The allocator objects Alloc & v1Alloc are equal.
```

### <a name="example"></a>Exemplo

```cpp
// std__memory__operator_ne.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
    {
    std::shared_ptr<int> sp0(new int(0));
    std::shared_ptr<int> sp1(new int(0));

    std::cout << "sp0 != sp0 == " << std::boolalpha
        << (sp0 != sp0) << std::endl;
    std::cout << "sp0 != sp1 == " << std::boolalpha
        << (sp0 != sp1) << std::endl;

    return (0);
    }

```

```Output
sp0 != sp0 == false
sp0 != sp1 == true
```

## <a name="op_eq_eq"></a>  operator==

Testa a igualdade entre objetos.

```cpp
template <class Type, class Other>
bool operator==(
    const allocator<Type>& left,
    const allocator<Other>& right) throw();

template <class Ty1, class Del1, class Ty2, class Del2>
bool operator==(
    const unique_ptr<Ty1, Del1>& left,
    const unique_ptr<Ty2, Del2>& right);

template <class Ty1, class Ty2>
bool operator==(
    const shared_ptr<Ty1>& left;,
    const shared_ptr<Ty2>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um dos objetos a ser testado para igualdade.

`right` Um dos objetos a ser testado para igualdade.

`Ty1` O tipo controlado pelo ponteiro compartilhado à esquerda.

`Ty2` O tipo controlado pelo ponteiro compartilhado à direita.

### <a name="return-value"></a>Valor de retorno

`true` se os objetos forem iguais, `false` se os objetos não forem iguais.

### <a name="remarks"></a>Comentários

O primeiro operador de modelo retorna true. (Todos os alocadores padrão são iguais.)

O segundo e o terceiro operadores de modelo retornam ` left.get() ==  right.get()`.

### <a name="example"></a>Exemplo

```cpp
// memory_op_eq.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   allocator<char> Alloc;
   vector <int>:: allocator_type v1Alloc;

   allocator<char> cAlloc(Alloc);
   allocator<int> cv1Alloc(v1Alloc);

   if ( cv1Alloc == v1Alloc )
      cout << "The allocator objects cv1Alloc & v1Alloc are equal."
           << endl;
   else
      cout << "The allocator objects cv1Alloc & v1Alloc are not equal."
           << endl;

   if ( cAlloc == Alloc )
      cout << "The allocator objects cAlloc & Alloc are equal."
           << endl;
   else
      cout << "The allocator objects cAlloc & Alloc are not equal."
           << endl;
}
```

```Output
The allocator objects cv1Alloc & v1Alloc are equal.
The allocator objects cAlloc & Alloc are equal.
```

### <a name="example"></a>Exemplo

```cpp
// std__memory__operator_eq.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
    {
    std::shared_ptr<int> sp0(new int(0));
    std::shared_ptr<int> sp1(new int(0));

    std::cout << "sp0 == sp0 == " << std::boolalpha
        << (sp0 == sp0) << std::endl;
    std::cout << "sp0 == sp1 == " << std::boolalpha
        << (sp0 == sp1) << std::endl;

    return (0);
    }

```

```Output
sp0 == sp0 == true
sp0 == sp1 == false
```

## <a name="op_gt_eq"></a>  operator&gt;=

Testa um objeto que é maior que ou igual a um segundo objeto.

```cpp
template <class T, class Del1, class U, class Del2>
bool operator>=(
    const unique_ptr<T, Del1>& left,
    const unique_ptr<U, Del2>& right);

template <class Ty1, class Ty2>
bool operator>=(
    const shared_ptr<Ty1>& left,
    const shared_ptr<Ty2>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um dos objetos a ser comparado.

`right` Um dos objetos a ser comparado.

`Ty1` O tipo controlado pelo ponteiro compartilhado à esquerda.

`Ty2` O tipo controlado pelo ponteiro compartilhado à direita.

### <a name="remarks"></a>Comentários

Os operadores de modelo retornam `left.get() >= right.get()`.

## <a name="op_lt"></a>  operator&lt;

Testa um objeto que é menor que um segundo objeto.

```cpp
template <class T, class Del1, class U, class Del2>
bool operator<(
    const unique_ptr<T, Del1>& left,
    const unique_ptr<U&, Del2>& right);

template <class Ty1, class Ty2>
bool operator<(
    const shared_ptr<Ty1>& left,
    const shared_ptr<Ty2>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um dos objetos a ser comparado.

`right` Um dos objetos a ser comparado.

`Ty1` O tipo controlado pelo ponteiro à esquerda.

`Ty2` O tipo controlado pelo ponteiro à direita.

## <a name="op_lt_eq"></a>  operator&lt;=

Testa um objeto que é maior ou igual a um segundo objeto de uma classe especificada.

```cpp
template <class T, class Del1, class U, class Del2>
bool operator<=(
    const unique_ptr<T, Del1>& left,
    const unique_ptr<U&, Del2>& right);

template <class Ty1, class Ty2>
bool operator<=(
    const shared_ptr<Ty1>& left,
    const shared_ptr<Ty2>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um dos objetos a ser comparado.

`right` Um dos objetos a ser comparado.

`Ty1` O tipo controlado pelo ponteiro compartilhado à esquerda.

`Ty2` O tipo controlado pelo ponteiro compartilhado à direita.

### <a name="remarks"></a>Comentários

Retornam os operadores de modelo `left.get() <= right.get()`

## <a name="op_gt"></a>  operator&gt;

Testa um objeto que é maior que um segundo objeto.

```cpp
template <class Ty1, class Del1, class Ty2, class Del2>
bool operator>(
    const unique_ptr<Ty1, Del1>& left,
    const unique_ptr<Ty2&, Del2gt;& right);

template <class Ty1, class Ty2>
bool operator>(
    const shared_ptr<Ty1>& left,
    const shared_ptr<Ty2>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um dos objetos a ser comparado.

`right` Um dos objetos a ser comparado.

`Ty1` O tipo controlado pelo ponteiro compartilhado à esquerda.

`Ty2` O tipo controlado pelo ponteiro compartilhado à direita.

## <a name="op_lt_lt"></a>  operator&lt;&lt;

Grava o ponteiro compartilhado no fluxo.

```cpp
template <class Elem, class Tr, class Ty>
std::basic_ostream<Elem, Tr>& operator<<(std::basic_ostream<Elem, Tr>& out,
    shared_ptr<Ty>& sp);
```

### <a name="parameters"></a>Parâmetros

`Elem` O tipo de elemento de fluxo.

`Tr` O tipo as características do elemento de fluxo.

`Ty` O tipo controlado pelo ponteiro compartilhado.

`out` O fluxo de saída.

`sp` O ponteiro compartilhado.

### <a name="remarks"></a>Comentários

A função do modelo retorna `out << sp.get()`.

### <a name="example"></a>Exemplo

```cpp
// std__memory__operator_sl.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
    {
    std::shared_ptr<int> sp0(new int(5));

    std::cout << "sp0 == " << sp0 << " (varies)" << std::endl;

    return (0);
    }

```

```Output
sp0 == 3f3040 (varies)
```

## <a name="see-also"></a>Consulte também

[\<memory>](../standard-library/memory.md)<br/>
