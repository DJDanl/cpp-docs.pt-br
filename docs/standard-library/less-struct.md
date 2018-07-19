---
title: Struct less | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xfunctional/std::less
dev_langs:
- C++
helpviewer_keywords:
- less struct
- less function
ms.assetid: 39349da3-11cd-4774-b2cc-b46af5aae5d7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c146862a18d4292dd6c375dda83063bbcf4dee4
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38954349"
---
# <a name="less-struct"></a>Struct less

Um predicado binário que executa o menor-que operação (`operator<`) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type = void>
struct less : public binary_function <Type, Type, bool>
{
    bool operator()(const Type& Left, const Type& Right) const;
};

// specialized transparent functor for operator<
template <>
struct less<void>
{
    template <class T, class U>
    auto operator()(T&& Left, U&& Right) const
        -> decltype(std::forward<T>(Left) <std::forward<U>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo de*, *T*, *U* qualquer tipo que dá suporte a um `operator<` que usa operandos dos tipos especificados ou inferidos.

*Esquerda* o operando esquerdo da menor-que a operação. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *T*.

*Direita* o operando direito da menor-que a operação. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *U*.

## <a name="return-value"></a>Valor de retorno

O resultado de `Left < Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator<`.

## <a name="remarks"></a>Comentários

O predicado binário `less` <  `Type`> fornece uma ordenação fraca estrita de um conjunto de valores de elemento do tipo *tipo* em classes de equivalência, se e somente se esse tipo satisfizer o padrão de matemático requisitos para ser ordenado dessa forma. As especializações de qualquer tipo de ponteiro produzem uma ordenação total dos elementos, pois todos os elementos de valores distintos são ordenados em relação uns aos outros.

## <a name="example"></a>Exemplo

```cpp
// functional_less.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

struct MyStruct {
   MyStruct(int i) : m_i(i){}

   bool operator < (const MyStruct & rhs) const {
      return m_i < rhs.m_i;
   }

   int m_i;
};

int main() {
   using namespace std;
   vector <MyStruct> v1;
   vector <MyStruct>::iterator Iter1;
   vector <MyStruct>::reverse_iterator rIter1;

   int i;
   for ( i = 0 ; i < 7 ; i++ )
       v1.push_back( MyStruct(rand()));

   cout << "Original vector v1 = ( " ;
   for ( Iter1 = v1.begin() ; Iter1 != v1.end() ; Iter1++ )
cout << Iter1->m_i << " ";
   cout << ")" << endl;

   // To sort in ascending order,
   sort( v1.begin( ), v1.end( ), less<MyStruct>());

   cout << "Sorted vector v1 = ( " ;
   for ( Iter1 = v1.begin() ; Iter1 != v1.end() ; Iter1++ )
cout << Iter1->m_i << " ";
   cout << ")" << endl;
 }
```

## <a name="output"></a>Saída

```Output
Original vector v1 = (41 18467 6334 26500 19169 15724 11478)
Sorted vector v1 = (41 6334 11478 15724 18467 19169 26500)
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
