---
title: Classe gslice
ms.date: 11/04/2016
f1_keywords:
- valarray/std::gslice
- valarray/std::gslice::size
- valarray/std::gslice::start
- valarray/std::gslice::stride
helpviewer_keywords:
- std::gslice [C++]
- std::gslice [C++], size
- std::gslice [C++], start
- std::gslice [C++], stride
ms.assetid: f47cffd0-ea59-4b13-848b-7a5ce1d7e2a3
ms.openlocfilehash: 9290fabc86ffbdb051b7c61fe1600cd2f7f17dca
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866239"
---
# <a name="gslice-class"></a>Classe gslice

Uma classe de utilitário para valarray que é usada para definir subconjuntos multidimensionais de um valarray. Se um valarray for considerado uma matriz multidimensional com todos os elementos em uma matriz, a fatia extrairá um vetor da matriz multidimensional.

## <a name="remarks"></a>Comentários

A classe armazena os parâmetros que caracterizam a um objeto do tipo [gslice_array](../standard-library/gslice-array-class.md). O subconjunto de um valarray é construído indiretamente quando um objeto da classe gslice aparece como um argumento para um objeto da classe [valarray](../standard-library/valarray-class.md#op_at) **\<Tipo>** . Os valores armazenados que especificam o subconjunto selecionado do valarray pai incluem:

- Um índice inicial.

- Um vetor de comprimento da classe `valarray<size_t>`.

- Um vetor Stride de classe `valarray<size_t>`.

Os dois vetores devem ter o mesmo tamanho.

Se o conjunto definido por um gslice for o subconjunto de um valarray constante, o gslice será um novo valarray. Se o conjunto definido por um gslice for o subconjunto de um valarray não constante, o gslice terá semântica de referência ao valarray original. O mecanismo de avaliação para valarrays não constantes economiza tempo e memória.

Operações em valarrays são garantidas somente se os subconjuntos de origem e de destino definidos pelos gslices forem diferentes e todos os índices forem válidos.

### <a name="constructors"></a>Construtores

|Construtor|DESCRIÇÃO|
|-|-|
|[gslice](#gslice)|Define um subconjunto de um `valarray` que consiste em várias fatias do `valarray` que são iniciados todos em um elemento especificado.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|DESCRIÇÃO|
|-|-|
|[size](#size)|Encontra os valores da matriz especificando os números dos elementos em uma fatia geral de um `valarray`.|
|[start](#start)|Localiza o índice inicial de uma fatia geral de um `valarray`.|
|[stride](#stride)|Encontra a distância entre os elementos em uma fatia geral de um `valarray`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray >

**Namespace:** std

## <a name="gslice"></a>  gslice::gslice

Uma classe de utilitário para valarray usada para definir fatias multidimensionais de um valarray.

```cpp
gslice();

gslice(
    size_t _StartIndex,
    const valarray<size_t>& _LenArray,
    const valarray<size_t>& _IncArray);
```

### <a name="parameters"></a>parâmetros

*_StartIndex*\
O índice de valarray do primeiro elemento no subconjunto.

*_LenArray*\
Uma matriz que especifica o número de elementos em cada fatia.

*_IncArray*\
Uma matriz que especifica a distância em cada fatia.

### <a name="return-value"></a>Valor retornado

O construtor padrão armazena zero para o índice inicial e vetores de comprimento zero para os vetores de comprimento e distância. O segundo Construtor armazena *_StartIndex* para o índice inicial, *_LenArray* para a matriz de comprimento e *_IncArray* para a matriz Stride.

### <a name="remarks"></a>Comentários

**gslice** define um subconjunto de um valarray que consiste em várias fatias do valarray, cada uma iniciada com o mesmo elemento especificado. A capacidade de usar matrizes para definir várias fatias é a única diferença entre `gslice` e [slice::slice](../standard-library/slice-class.md#slice). A primeira fatia tem um primeiro elemento com um índice de *_StartIndex*, vários elementos especificados pelo primeiro elemento de *_LenArray*e um stride fornecido pelo primeiro elemento de *_IncArray*. O conjunto seguinte de fatias ortogonais tem os primeiros elementos fornecidos pela primeira fatia. O segundo elemento de *_LenArray* especifica o número de elementos. O stride é fornecido pelo segundo elemento de *_IncArray*. Uma terceira dimensão de fatias usaria os elementos da matriz bidimensional como elementos iniciais e continuaria da mesma forma

### <a name="example"></a>Exemplo

```cpp
// gslice_ctor.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> va ( 20 ), vaResult;
   for ( i = 0 ; i < 20 ; i+=1 )
      va [ i ] =  i;

   cout << "The operand valarray va is:" << endl << "(";
   for ( i = 0 ; i < 20 ; i++ )
      cout << " " << va [ i ];
   cout << " )" << endl;

   valarray<size_t> Len ( 2 ), Stride ( 2 );
   Len [0] = 4;
   Len [1] = 4;
   Stride [0] = 7;
   Stride [1] = 4;

   gslice vaGSlice ( 0, Len, Stride );
   vaResult = va [ vaGSlice ];

   cout << "The valarray for vaGSlice is vaResult:" << endl
        << "va[vaGSlice] = (";

   for ( i = 0 ; i < 8 ; i++ )
      cout << " " << vaResult [ i ];
   cout << ")" << endl;
}
```

```Output
The operand valarray va is:
( 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 )
The valarray for vaGSlice is vaResult:
va[vaGSlice] = ( 0 4 8 12 7 11 15 19)
```

## <a name="size"></a>  gslice::size

Encontra os valores da matriz especificando os números dos elementos em uma fatia geral de um valarray.

```cpp
valarray<size_t> size() const;
```

### <a name="return-value"></a>Valor retornado

Um valarray que especifica o número de elementos em cada fatia de uma fatia geral de um valarray.

### <a name="remarks"></a>Comentários

A função membro retorna os tamanhos armazenados das fatias.

### <a name="example"></a>Exemplo

```cpp
// gslice_size.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   size_t sizeVA;

   valarray<int> va ( 20 ), vaResult;
   for ( i = 0 ; i < 20 ; i+=1 )
      va [ i ] =  i;

   cout << "The operand valarray va is:\n ( ";
      for ( i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   sizeVA = va.size ( );
   cout << "The size of the valarray is: "
        << sizeVA << "." << endl << endl;

   valarray<size_t> Len ( 2 ), Stride ( 2 );
   Len [0] = 4;
   Len [1] = 4;
   Stride [0] = 7;
   Stride [1] = 4;

   gslice vaGSlice ( 0, Len, Stride );
   vaResult = va [ vaGSlice ];
   const valarray <size_t> sizeGS = vaGSlice.size ( );

   cout << "The valarray for vaGSlice is vaResult:"
        << "\n va[vaGSlice] = ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;

   cout << "The size of vaResult is:"
        << "\n vaGSlice.size ( ) = ( ";
      for ( i = 0 ; i < 2 ; i++ )
         cout << sizeGS[ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The operand valarray va is:
( 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ).
The size of the valarray is: 20.

The valarray for vaGSlice is vaResult:
va[vaGSlice] = ( 0 4 8 12 7 11 15 19 ).
The size of vaResult is:
vaGSlice.size ( ) = ( 4 4 ).
```

## <a name="start"></a>  gslice::start

Localiza o índice inicial de uma fatia geral de um valarray.

```cpp
size_t start() const;
```

### <a name="return-value"></a>Valor retornado

O índice inicial de uma fatia geral de um valarray.

### <a name="example"></a>Exemplo

```cpp
// gslice_start.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> va ( 20 ), vaResult;
   for (i = 0 ; i < 20 ; i+=1 )
      va [ i ] =  i;

   cout << "The operand valarray va is:\n ( ";
      for ( i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   valarray<size_t> Len ( 2 ), Stride ( 2 );
   Len [0] = 4;
   Len [1] = 4;
   Stride [0] = 7;
   Stride [1] = 4;

   gslice vaGSlice ( 0, Len, Stride );
   vaResult = va [ vaGSlice ];
   size_t vaGSstart = vaGSlice.start ( );

   cout << "The valarray for vaGSlice is vaResult:"
        << "\n va[vaGSlice] = ( ";
      for (i = 0 ; i < 8 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;

   cout << "The index of the first element of vaResult is: "
        << vaGSstart << "." << endl;
}
```

```Output
The operand valarray va is:
( 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ).
The valarray for vaGSlice is vaResult:
va[vaGSlice] = ( 0 4 8 12 7 11 15 19 ).
The index of the first element of vaResult is: 0.
```

## <a name="stride"></a>  gslice::stride

Encontra a distância entre os elementos em uma fatia geral de um valarray.

```cpp
valarray<size_t> stride() const;
```

### <a name="return-value"></a>Valor retornado

Um valarray que especifica as distâncias entre os elementos em cada fatia de uma fatia geral de um valarray.

### <a name="example"></a>Exemplo

```cpp
// gslice_stride.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> va ( 20 ), vaResult;
   for (i = 0 ; i < 20 ; i+=1 )
      va [ i ] =  i;

   cout << "The operand valarray va is:\n ( ";
      for (i = 0 ; i < 20 ; i++ )
         cout << va [ i ] << " ";
   cout << ")." << endl;

   valarray<size_t> Len ( 2 ), Stride ( 2 );
   Len [0] = 4;
   Len [1] = 4;
   Stride [0] = 7;
   Stride [1] = 4;

   gslice vaGSlice ( 0, Len, Stride );
   vaResult = va [ vaGSlice ];
   const valarray <size_t> strideGS = vaGSlice.stride ( );

   cout << "The valarray for vaGSlice is vaResult:"
        << "\n va[vaGSlice] = ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaResult [ i ] << " ";
   cout << ")." << endl;

   cout << "The strides of vaResult are:"
        << "\n vaGSlice.stride ( ) = ( ";
      for ( i = 0 ; i < 2 ; i++ )
         cout << strideGS[ i ] << " ";
   cout << ")." << endl;

}
```

```Output
The operand valarray va is:
( 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ).
The valarray for vaGSlice is vaResult:
va[vaGSlice] = ( 0 4 8 12 7 11 15 19 ).
The strides of vaResult are:
vaGSlice.stride ( ) = ( 7 4 ).
```

## <a name="see-also"></a>Confira também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
