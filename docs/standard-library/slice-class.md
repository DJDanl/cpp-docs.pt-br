---
title: Classe slice | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- valarray/std::slice
- valarray/std::slice::size
- valarray/std::slice::start
- valarray/std::slice::stride
dev_langs:
- C++
helpviewer_keywords:
- std::slice [C++]
- std::slice [C++], size
- std::slice [C++], start
- std::slice [C++], stride
ms.assetid: 00f0b03d-d657-4b81-ba53-5a9034bb2bf2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6a2cff4aea707c98a4bce7060b16ce695d25c47d
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44109000"
---
# <a name="slice-class"></a>Classe slice

Uma classe de utilitário para valarray que é usada para definir subconjuntos unidimensionais de um valarray pai. Se um valarray for considerado uma matriz bidimensional com todos os elementos em uma matriz, a fatia extrairá um vetor em uma dimensão da matriz bidimensional.

## <a name="remarks"></a>Comentários

A classe armazena os parâmetros que caracterizam um objeto do tipo [slice_array](../standard-library/slice-array-class.md). O subconjunto de um valarray é indiretamente criado quando um objeto da classe slice aparece como um argumento para um objeto da classe [valarray](../standard-library/valarray-class.md#op_at)**\<Type>**. Os valores armazenados que especificam o subconjunto selecionado do valarray pai incluem:

- O índice inicial no valarray.

- Um comprimento total ou o número de elementos na slice.

- Um stride ou a distância entre índices subsequentes dos elementos em valarray.

Se o conjunto definido por uma slice for o subconjunto de um valarray constante, a slice será um novo valarray. Se o conjunto definido por uma slice for o subconjunto de um valarray não constante, a slice terá semântica de referência ao valarray original. O mecanismo de avaliação para valarrays não constantes economiza tempo e memória.

Operações em valarrays são asseguradas somente se os subconjuntos de origem e de destino definidos pelas slices forem diferentes e todos os índices forem válidos.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[slice](#slice)|Define um subconjunto de um `valarray` que consiste em um número de elementos que estão separados por uma distância igual entre eles e que começam em um elemento especificado.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[size](#size)|Localiza o número de elementos em uma slice de um `valarray`.|
|[start](#start)|Localiza o índice inicial de uma slice de um `valarray`.|
|[stride](#stride)|Encontra a distância entre os elementos em uma slice de um `valarray`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

## <a name="size"></a>  slice::size

Localiza o número de elementos em uma slice de um valarray.

```cpp
size_t size() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos em uma slice de um valarray.

### <a name="example"></a>Exemplo

```cpp
// slice_size.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   size_t sizeVA, sizeVAR;

   valarray<int> va ( 20 ), vaResult;
   for ( i = 0 ; i < 20 ; i += 1 )
      va [ i ] =  i+1;

   cout << "The operand valarray va is:\n ( ";
      for ( i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   sizeVA = va.size ( );
   cout << "The size of the valarray is: "
        << sizeVA << "." << endl << endl;

   slice vaSlice ( 3 , 6 , 3 );
   vaResult = va [ vaSlice ];

   cout << "The slice of valarray va is vaResult = "
        << "va[slice( 3, 6, 3)] =\n ( ";
      for ( i = 0 ; i < 6 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;

   sizeVAR = vaSlice.size ( );
   cout << "The size of slice vaSlice is: "
        << sizeVAR << "." << endl;
}
```

```Output
The operand valarray va is:
( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ).
The size of the valarray is: 20.

The slice of valarray va is vaResult = va[slice( 3, 6, 3)] =
( 4 7 10 13 16 19 ).
The size of slice vaSlice is: 6.
```

## <a name="slice"></a>  slice::slice

Define um subconjunto de um valarray que consiste em um número de elementos que estão separados por uma distância igual entre eles e que começam em um elemento especificado.

```cpp
slice();

slice(
    size_t _StartIndex,
    size_t _Len,
    size_t stride);
```

### <a name="parameters"></a>Parâmetros

*_StartIndex*<br/>
O índice de valarray do primeiro elemento no subconjunto.

*_Len*<br/>
O número de elementos no subconjunto.

*stride*<br/>
A distância entre elementos no subconjunto.

### <a name="return-value"></a>Valor de retorno

O construtor padrão armazena zeros para o índice inicial, o comprimento total e o stride. O segundo construtor armazena *_StartIndex* para o índice inicial, *_Len* para o comprimento total, e *stride* para o stride.

### <a name="remarks"></a>Comentários

O stride pode ser negativo.

### <a name="example"></a>Exemplo

```cpp
// slice_ctor.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> va ( 20 ), vaResult;
   for ( i = 0 ; i < 20 ; i+=1 )
      va [ i ] =  2 * (i + 1 );

   cout << "The operand valarray va is:\n( ";
      for ( i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   slice vaSlice ( 1 , 7 , 3 );
   vaResult = va [ vaSlice ];

   cout << "\nThe slice of valarray va is vaResult:"
        << "\nva[slice( 1, 7, 3)] = ( ";
      for ( i = 0 ; i < 7 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The operand valarray va is:
( 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 ).

The slice of valarray va is vaResult:
va[slice( 1, 7, 3)] = ( 4 10 16 22 28 34 40 ).
```

## <a name="start"></a>  slice::start

Localiza o índice inicial de uma slice de um valarray.

```cpp
size_t start() const;
```

### <a name="return-value"></a>Valor de retorno

O índice inicial de uma slice de um valarray.

### <a name="example"></a>Exemplo

```cpp
// slice_start.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   size_t startVAR;

   valarray<int> va ( 20 ), vaResult;
   for ( i = 0 ; i < 20 ; i += 1 )
      va [ i ] = i+1;

   cout << "The operand valarray va is:\n ( ";
      for ( i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   slice vaSlice ( 3 , 6 , 3 );
   vaResult = va [ vaSlice ];

   cout << "The slice of valarray va is vaResult = "
        << "va[slice( 3, 6, 3)] =\n ( ";
      for ( i = 0 ; i < 6 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;

   startVAR = vaSlice.start ( );
   cout << "The start index of slice vaSlice is: "
        << startVAR << "." << endl;
}
```

```Output
The operand valarray va is:
( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ).
The slice of valarray va is vaResult = va[slice( 3, 6, 3)] =
( 4 7 10 13 16 19 ).
The start index of slice vaSlice is: 3.
```

## <a name="stride"></a>  slice::stride

Encontra a distância entre os elementos em uma slice de um valarray.

```cpp
size_t stride() const;
```

### <a name="return-value"></a>Valor de retorno

A distância entre os elementos em uma slice de um valarray.

### <a name="example"></a>Exemplo

```cpp
// slice_stride.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   size_t strideVAR;

   valarray<int> va ( 20 ), vaResult;
   for ( i = 0 ; i < 20 ; i += 1 )
      va [ i ] =  3 * ( i + 1 );

   cout << "The operand valarray va is:\n ( ";
      for ( i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   slice vaSlice ( 4 , 5 , 3 );
   vaResult = va [ vaSlice ];

   cout << "The slice of valarray va is vaResult = "
        << "va[slice( 4, 5, 3)] =\n ( ";
      for ( i = 0 ; i < 5 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;

   strideVAR = vaSlice.stride ( );
   cout << "The stride of slice vaSlice is: "
        << strideVAR << "." << endl;
}
```

```Output
The operand valarray va is:
( 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60 ).
The slice of valarray va is vaResult = va[slice( 4, 5, 3)] =
( 15 24 33 42 51 ).
The stride of slice vaSlice is: 3.
```

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
