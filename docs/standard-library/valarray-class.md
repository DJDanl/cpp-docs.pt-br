---
title: Classe valarray
ms.date: 03/27/2019
f1_keywords:
- valarray/std::valarray
- valarray/std::valarray::value_type
- valarray/std::valarray::apply
- valarray/std::valarray::cshift
- valarray/std::valarray::free
- valarray/std::valarray::max
- valarray/std::valarray::min
- valarray/std::valarray::resize
- valarray/std::valarray::shift
- valarray/std::valarray::size
- valarray/std::valarray::sum
- valarray/std::valarray::swap
helpviewer_keywords:
- std::valarray [C++]
- std::valarray [C++], value_type
- std::valarray [C++], apply
- std::valarray [C++], cshift
- std::valarray [C++], free
- std::valarray [C++], max
- std::valarray [C++], min
- std::valarray [C++], resize
- std::valarray [C++], shift
- std::valarray [C++], size
- std::valarray [C++], sum
- std::valarray [C++], swap
ms.assetid: 19b862f9-5d09-4003-8844-6ddd02c1a3a7
ms.openlocfilehash: f116758591461614acfa7c171bff2b1675f453e4
ms.sourcegitcommit: 49cf365176557456f56c994e06ea1a38f73e938b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/09/2020
ms.locfileid: "78937416"
---
# <a name="valarray-class"></a>Classe valarray

O modelo de classe descreve um objeto que controla uma sequência de elementos do tipo `Type` que são armazenados como uma matriz, projetados para executar operações matemáticas de alta velocidade e otimizados para desempenho computacional.

## <a name="remarks"></a>Comentários

A classe é uma representação do conceito matemático de um conjunto ordenado de valores e os elementos são numerados sequencialmente a partir de zero. A classe é descrita como um “quase contêiner”, pois dá suporte a alguns, mas não todos os recursos de primeira classe que contêineres de sequência oferecem, como o [vetor](../standard-library/vector-class.md). Ele difere do vetor de modelo de classe de duas maneiras importantes:

- Ele define várias operações aritméticas entre os elementos correspondentes de `valarray<Type>` objetos do mesmo tipo e comprimento, como *Xarr* = cos ( *yarr*) + sin ( *Zarr*).

- Ele define uma variedade de maneiras interessantes de criar um script de `valarray<Type>` objeto, pelo [operador&#91;](#op_at)de sobrecarga.

Um objeto da classe `Type`:

- Tem um construtor padrão público, um destruidor, um construtor de cópia e um operador de atribuição com comportamento convencional.

- Define os operadores aritméticos e funções matemáticas, conforme necessário, definidos para os tipos de ponto flutuante com comportamento convencional.

Em particular, talvez não exista nenhuma diferença sutil entre a construção da cópia e a construção padrão seguida pela atribuição. Nenhuma das operações em objetos da classe `Type` pode gerar exceções.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[valarray](#valarray)|Constrói um `valarray` de um tamanho específico ou com elementos de um valor específico ou como uma cópia de outro `valarray` ou um subconjunto de outro `valarray`.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[value_type](#value_type)|Um tipo que representa o tipo de elemento armazenado em um `valarray`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[apply](#apply)|Aplica uma função especificada a cada elemento de um `valarray`.|
|[cshift](#cshift)|De forma cíclica, desloca todos os elementos em um `valarray` por meio de um número especificado de posições.|
|[gratuito](#free)|Libera a memória usada pelo `valarray`.|
|[max](#max)|Localiza o maior elemento em um `valarray`.|
|[min](#min)|Localiza o menor elemento em um `valarray`.|
|[resize](#resize)|Altera o número de elementos em um `valarray` para um número especificado, adicionando ou removendo elementos conforme necessário.|
|[shift](#shift)|Desloca todos os elementos em um `valarray` por meio de um número especificado de posições.|
|[size](#size)|Localiza o número de elementos em um `valarray`.|
|[sum](#sum)|Determina a soma de todos os elementos em um `valarray` de comprimento diferente de zero.|
|[swap](#swap)||

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!](#op_not)|Um operador unário que obtém os valores lógicos `NOT` de cada elemento em um `valarray`.|
|[operator%=](#op_mod_eq)|Obtém o resto da divisão dos elementos de uma matriz elemento a elemento por meio de um `valarray` especificado ou de um valor do tipo de elemento.|
|[operator&=](#op_and_eq)|Obtém o bit a bit `AND` de elementos em uma matriz com os elementos correspondentes em um `valarray` especificado ou com um valor do tipo de elemento.|
|[operator>>=](#op_gt_gt_eq)|Desloca para a direita os bits de cada elemento de um operando `valarray` por um número especificado de posições ou por uma quantidade elemento a elemento especificada por um segundo `valarray`.|
|[operator<<=](#op_lt_lt_eq)|Desloca para a esquerda os bits de cada elemento de um operando `valarray` por um número especificado de posições ou por uma quantidade elemento a elemento especificada por um segundo `valarray`.|
|[operator*=](#op_star_eq)|Multiplica os elementos de um `valarray` especificado ou um valor do tipo de elemento, elemento a elemento, para um operando `valarray`.|
|[operator+](#op_add)|Um operador unário que aplica a um sinal de adição a cada elemento em um `valarray`.|
|[operator+=](#op_add_eq)|Adiciona os elementos de um `valarray` especificado ou um valor do tipo de elemento, elemento a elemento, a um operando `valarray`.|
|[operator-](#operator-)|Um operador unário que aplica a um sinal de subtração a cada elemento em um `valarray`.|
|[operator-=](#operator-_eq)|Subtrai os elementos de um `valarray` especificado ou um valor do tipo de elemento, elemento a elemento, de um operando `valarray`.|
|[operator/=](#op_div_eq)|Divide um operando `valarray`, elemento a elemento, pelos elementos de um `valarray` especificado ou um valor do tipo de elemento.|
|[operator=](#op_eq)|Atribui elementos a um `valarray` cujos valores são especificados diretamente ou como parte de algum outro `valarray` ou por um `slice_array`, `gslice_array`, `mask_array` ou `indirect_array`.|
|[operator&#91;&#93;](#op_at)|Retorna uma referência a um elemento ou seu valor no índice ou subconjunto especificado.|
|[operator^=](#op_xor_eq)|Obtém o lógico exclusivo elemento a elemento ou operador (`XOR`) de uma matriz com uma valarray especificada ou um valor do tipo de elemento.|
|[operator&#124;=](#op_or_eq)|Obtém o bit a bit `OR` de elementos em uma matriz com os elementos correspondentes em um `valarray` especificado ou com um valor do tipo de elemento.|
|[operator~](#op_dtor)|Um operador unário que obtém os valores bit a bit `NOT` de cada elemento em um `valarray`.|

## <a name="apply"></a>usar

Aplica uma função especificada a cada elemento de uma valarray.

```cpp
valarray<Type> apply(Type _Func(Type)) const;

valarray<Type> apply(Type _Func(constType&)) const;
```

### <a name="parameters"></a>parâmetros

*_Func (tipo)* \
O objeto de função a ser aplicado a cada elemento da valarray operando.

*_Func (& de tipo const)* \
O objeto de função de const a ser aplicado a cada elemento da valarray operando.

### <a name="return-value"></a>Valor retornado

Uma valarray na qual houve aplicação de `_Func`, elemento a elemento, aos elementos da valarray operando.

### <a name="remarks"></a>Comentários

A função membro retorna um objeto da classe [valarray](../standard-library/valarray-class.md) **\<tipo >** , de [tamanho](#size), cada um dos elementos dos quais *estou* `_Func((*this)[I])`.

### <a name="example"></a>Exemplo

```cpp
// valarray_apply.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

using namespace std;

int __cdecl MyApplyFunc( int n )
{
   return n*2;
}

int main( int argc, char* argv[] )
{
   valarray<int> vaR(10), vaApplied(10);
   int i;

   for ( i = 0; i < 10; i += 3 )
      vaR[i] = i;

   for ( i = 1; i < 10; i += 3 )
      vaR[i] = 0;

   for ( i = 2; i < 10; i += 3 )
      vaR[i] = -i;

   cout << "The initial Right valarray is: (";
   for   ( i=0; i < 10; ++i )
      cout << " " << vaR[i];
   cout << " )" << endl;

   vaApplied = vaR.apply( MyApplyFunc );

   cout << "The element-by-element result of "
       << "applying MyApplyFunc to vaR is the\nvalarray: ( ";
   for ( i = 0; i < 10; ++i )
      cout << " " << vaApplied[i];
   cout << " )" << endl;
}
```

```Output
The initial Right valarray is: ( 0 0 -2 3 0 -5 6 0 -8 9 )
The element-by-element result of applying MyApplyFunc to vaR is the
valarray: (  0 0 -4 6 0 -10 12 0 -16 18 )
```

## <a name="cshift"></a>cshift

De forma cíclica, desloca todos os elementos em uma valarray por meio de um número especificado de posições.

```cpp
valarray<Type> cshift(int count) const;
```

### <a name="parameters"></a>parâmetros

*contagem*\
O número de locais para os quais os elementos serão deslocados para frente.

### <a name="return-value"></a>Valor retornado

Um novo valarray no qual todos os elementos foram movidos com posições de *contagem* cíclicamente em direção à frente do valarray, deixados em relação às suas posições no operando valarray.

### <a name="remarks"></a>Comentários

Um valor positivo de *Count* altera os locais de *contagem* de maneira cíclica dos elementos.

Um valor negativo de *Count* alterna os locais de *contagem* de forma cíclica correta.

### <a name="example"></a>Exemplo

```cpp
// valarray_cshift.cpp
// compile with: /EHsc

#include <valarray>
#include <iostream>

int main()
{
    using namespace std;
    int i;

    valarray<int> va1(10), va2(10);
    for (i = 0; i < 10; i+=1)
        va1[i] = i;
    for (i = 0; i < 10; i+=1)
        va2[i] = 10 - i;

    cout << "The operand valarray va1 is: (";
    for (i = 0; i < 10; i++)
        cout << " " << va1[i];
    cout << ")" << endl;

    // A positive parameter shifts elements right
    va1 = va1.cshift(4);
    cout << "The cyclically shifted valarray va1 is:\nva1.cshift (4) = (";
    for (i = 0; i < 10; i++)
        cout << " " << va1[i];
    cout << ")" << endl;

    cout << "The operand valarray va2 is: (";
    for (i = 0; i < 10; i++)
        cout << " " << va2[i];
    cout << ")" << endl;

    // A negative parameter shifts elements left
    va2 = va2.cshift(-4);
    cout << "The cyclically shifted valarray va2 is:\nva2.shift (-4) = (";
    for (i = 0; i < 10; i++)
        cout << " " << va2[i];
    cout << ")" << endl;
}
```

```Output
The operand valarray va1 is: ( 0 1 2 3 4 5 6 7 8 9)
The cyclically shifted valarray va1 is:
va1.cshift (4) = ( 4 5 6 7 8 9 0 1 2 3)
The operand valarray va2 is: ( 10 9 8 7 6 5 4 3 2 1)
The cyclically shifted valarray va2 is:
va2.shift (-4) = ( 4 3 2 1 10 9 8 7 6 5)
```

## <a name="free"></a>informações

Libera a memória usada pela valarray.

```cpp
void free();
```

### <a name="remarks"></a>Comentários

Essa função não padrão é equivalente a atribuir uma valarray vazio. Por exemplo:

```cpp
valarray<T> v;
v = valarray<T>();

// equivalent to v.free()
```

## <a name="max"></a>maximizar

Localiza o maior elemento em uma valarray.

```cpp
Type max() const;
```

### <a name="return-value"></a>Valor retornado

O valor máximo dos elementos na valarray operando.

### <a name="remarks"></a>Comentários

A função membro compara valores aplicando operadores **\<** ou **operador >** entre pares de elementos da classe `Type`, para os quais os operadores devem ser fornecidos para o elemento `Type`.

### <a name="example"></a>Exemplo

```cpp
// valarray_max.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i, MaxValue;

   valarray<int> vaR ( 10 );
   for ( i = 0 ; i < 10 ; i += 3 )
      vaR [ i ] =  i;
   for ( i = 1 ; i < 10 ; i += 3 )
      vaR [ i ] =  2*i - 1;
   for ( i = 2 ; i < 10 ; i += 3 )
      vaR [ i ] =  10 - i;

   cout << "The operand valarray is: ( ";
      for (i = 0 ; i < 10 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   MaxValue = vaR.max (  );
   cout << "The largest element in the valarray is: "
        << MaxValue  << "." << endl;
}
```

```Output
The operand valarray is: ( 0 1 8 3 7 5 6 13 2 9 ).
The largest element in the valarray is: 13.
```

## <a name="min"></a>min

Localiza o menor elemento em uma valarray.

```cpp
Type min() const;
```

### <a name="return-value"></a>Valor retornado

O valor mínimo dos elementos na valarray operando.

### <a name="remarks"></a>Comentários

A função membro compara valores aplicando operadores **\<** ou **operador >** entre pares de elementos da classe `Type`, para os quais os operadores devem ser fornecidos para o elemento `Type`.

### <a name="example"></a>Exemplo

```cpp
// valarray_min.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i, MinValue;

   valarray<int> vaR ( 10 );
   for ( i = 0 ; i < 10 ; i += 3 )
      vaR [ i ] =  -i;
   for ( i = 1 ; i < 10 ; i += 3 )
      vaR [ i ] =  2*i;
   for ( i = 2 ; i < 10 ; i += 3 )
      vaR [ i ] =  5 - i;

   cout << "The operand valarray is: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   MinValue = vaR.min ( );
   cout << "The smallest element in the valarray is: "
        << MinValue  << "." << endl;
}
/* Output:
The operand valarray is: ( 0 2 3 -3 8 0 -6 14 -3 -9 ).
The smallest element in the valarray is: -9.
*/
```

## <a name="op_not"></a>operador!

Um operador unário que obtém os valores de expressão **NOT** lógica de cada elemento em uma valarray.

```cpp
valarray<bool> operator!() const;
```

### <a name="return-value"></a>Valor retornado

A valarray de valores boolianos que são a negação dos valores de elemento da valarray operando.

### <a name="remarks"></a>Comentários

A operação lógica **NOT** nega os elementos, pois ela converte todos os zeros em um e considera todos os valores diferentes de zero como um e os converte em zero. A valarray retornado de valores boolianos tem o mesmo tamanho que a valarray operando.

Também há um bit-a- **not**[valarray:: Operator ~](#op_dtor) que nega o nível de bits individuais dentro da representação binária dos elementos **Char** e **int** de um valarray.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_lognot.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 10 );
   valarray<bool> vaNOT ( 10 );
   for ( i = 0 ; i < 10 ; i += 2 )
      vaL [ i ] =  0;
   for ( i = 1 ; i < 10 ; i += 2 )
      vaL [ i ] =  i-1;

   cout << "The initial valarray is:  ( ";
      for (i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   vaNOT = !vaL;
   cout << "The element-by-element result of "
        << "the logical NOT operator! is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaNOT [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is:  ( 0 0 0 2 0 4 0 6 0 8 ).
The element-by-element result of the logical NOT operator! is the
valarray: ( 1 1 1 0 1 0 1 0 1 0 ).
```

## <a name="op_mod_eq"></a>operador% =

Obtém o resto da divisão dos elementos de uma matriz elemento a elemento por meio de uma valarray especificada ou de um valor do tipo de elemento.

```cpp
valarray<Type>& operator%=(const valarray<Type>& right);

valarray<Type>& operator%=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando que dividirá, elemento a elemento, a valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são o restante da divisão com elemento do operando valarray *à direita*

### <a name="example"></a>Exemplo

```cpp
// valarray_class_op_rem.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 6 ), vaR ( 6 );
   for ( i = 0 ; i < 6 ; i += 2 )
      vaL [ i ] =  53;
   for ( i = 1 ; i < 6 ; i += 2 )
      vaL [ i ] =  -67;
   for ( i = 0 ; i < 6 ; i++ )
      vaR [ i ] =  3*i+1;

   cout << "The initial valarray is: ( ";
      for ( i = 0 ; i < 6 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The initial  right valarray is: ( ";
      for ( i = 0 ; i < 6 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL %= vaR;
   cout << "The remainders from the element-by-element "
        << "division is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 6 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is: ( 53 -67 53 -67 53 -67 ).
The initial  right valarray is: ( 1 4 7 10 13 16 ).
The remainders from the element-by-element division is the
valarray: ( 0 -3 4 -7 1 -3 ).
```

## <a name="op_and_eq"></a>= de&amp;do operador

Obtém o **AND** bit a bit de elementos em uma matriz com os elementos correspondentes em uma valarray especificada ou com um valor do tipo de elemento.

```cpp
valarray<Type>& operator&=(const valarray<Type>& right);

valarray<Type>& operator&=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
O valarray ou o valor de um tipo de elemento idêntico ao do operando valarray que deve ser combinado, elemento-Wise, pelo `AND` lógico com o operando valarray.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são os `AND` lógicos com elemento do operando valarray *à direita*

### <a name="remarks"></a>Comentários

Uma operação bit a ponto pode ser usada apenas para manipular bits em tipos de dados **Char** e **int** e variantes, e não em **float**, **Double**, **longdouble**, **void**, **bool**ou outros tipos de dados mais complexos.

O bit e AND tem a mesma tabela verdade que o `AND` lógico, mas se aplica ao tipo de dados no nível dos bits individuais. Determinado bit *b*1 e *b*2, *b*1 `AND` *b*2 será **true** se ambos os bits forem verdadeiros; **false** se pelo menos um for falso.

### <a name="example"></a>Exemplo

```cpp
// valarray_class_op_bitand.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 10 ), vaR ( 10 );
   for ( i = 0 ; i < 10 ; i += 2 )
      vaL [ i ] =  0;
   for ( i = 1 ; i < 10 ; i += 2 )
      vaL [ i ] =  i-1;
   for ( i = 0 ; i < 10 ; i++ )
      vaR [ i ] =  i;

   cout << "The initial valarray is:  ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The initial Right valarray is: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL &= vaR;
   cout << "The element-by-element result of "
        << "the logical AND operator&= is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is:  ( 0 0 0 2 0 4 0 6 0 8 ).
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).
The element-by-element result of the logical AND operator&= is the
valarray: ( 0 0 0 2 0 4 0 6 0 8 ).
```

## <a name="op_gt_gt_eq"></a>&gt;de&gt;do operador =

Desloca para a direita os bits de cada elemento de uma valarray operando por um número especificado de posições ou por um valor elemento a elemento especificado por uma segunda valarray.

```cpp
valarray<Type>& operator>>=(const valarray<Type>& right);

valarray<Type>& operator>>=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
O valor que indica a quantidade de deslocamentos para a direita ou a valarray cujos elementos indicam a quantidade elemento a elemento dos deslocamentos para a direita.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos foram deslocados para a direita na quantidade especificada *à direita*.

### <a name="remarks"></a>Comentários

Os números com sinais têm seus sinais preservados.

### <a name="example"></a>Exemplo

```cpp
// valarray_class_op_rs.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 8 ), vaR ( 8 );
   for ( i = 0 ; i < 8 ; i += 2 )
      vaL [ i ] =  64;
   for ( i = 1 ; i < 8 ; i += 2 )
      vaL [ i ] =  -64;
   for ( i = 0 ; i < 8 ; i++ )
      vaR [ i ] =  i;

   cout << "The initial operand valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The  right valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL >>= vaR;
   cout << "The element-by-element result of "
        << "the right shift is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial operand valarray is: ( 64 -64 64 -64 64 -64 64 -64 ).
The  right valarray is: ( 0 1 2 3 4 5 6 7 ).
The element-by-element result of the right shift is the
valarray: ( 64 -32 16 -8 4 -2 1 -1 ).
```

## <a name="op_lt_lt_eq"></a>&lt;de&lt;do operador =

Desloca para a esquerda os bits de cada elemento de uma valarray operando por um número especificado de posições ou por um valor elemento a elemento especificado por uma segunda valarray.

```cpp
valarray<Type>& operator<<=(const valarray<Type>& right);

valarray<Type>& operator<<=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
O valor que indica a quantidade de deslocamentos para a esquerda ou a valarray cujos elementos indicam a quantidade elemento a elemento dos deslocamentos para a esquerda.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos foram deslocados para a esquerda na quantidade especificada à *direita*.

### <a name="remarks"></a>Comentários

Os números com sinais têm seus sinais preservados.

### <a name="example"></a>Exemplo

```cpp
// valarray_class_op_ls.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 8 ), vaR ( 8 );
   for ( i = 0 ; i < 8 ; i += 2 )
      vaL [ i ] =  1;
   for ( i = 1 ; i < 8 ; i += 2 )
      vaL [ i ] =  -1;
   for ( i = 0 ; i < 8 ; i++ )
      vaR [ i ] =  i;

   cout << "The initial operand valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The  right valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL <<= vaR;
   cout << "The element-by-element result of "
        << "the left shift"
        << endl << "on the operand array is the valarray:"
        << endl << "( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial operand valarray is: ( 1 -1 1 -1 1 -1 1 -1 ).
The  right valarray is: ( 0 1 2 3 4 5 6 7 ).
The element-by-element result of the left shift
on the operand array is the valarray:
( 1 -2 4 -8 16 -32 64 -128 ).
```

## <a name="op_star_eq"></a>operador * =

Multiplica os elementos de uma valarray especificado ou um valor do tipo de elemento, elemento a elemento, para uma valarray operando.

```cpp
valarray<Type>& operator*=(const valarray<Type>& right);

valarray<Type>& operator*=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando que multiplicará, elemento a elemento, a valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são o produto com elemento do operando valarray e *direita*.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_emult.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 8 ), vaR ( 8 );
   for ( i = 0 ; i < 8 ; i += 2 )
      vaL [ i ] =  2;
   for ( i = 1 ; i < 8 ; i += 2 )
      vaL [ i ] =  -1;
   for ( i = 0 ; i < 8 ; i++ )
      vaR [ i ] =  i;

   cout << "The initial valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The initial Right valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL *= vaR;
   cout << "The element-by-element result of "
        << "the multiplication is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
/* Output:
The initial valarray is: ( 2 -1 2 -1 2 -1 2 -1 ).
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).
The element-by-element result of the multiplication is the
valarray: ( 0 -1 4 -3 8 -5 12 -7 ).
*/
```

## <a name="op_add"></a>operador +

Um operador unário que aplica a um sinal de adição a cada elemento em uma valarray.

```cpp
valarray<Type> operator+() const;
```

### <a name="return-value"></a>Valor retornado

Uma valarray cujos elementos são uma adição aos da matriz operando.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_eplus.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 10 );
   valarray<int> vaPLUS ( 10 );
   for ( i = 0 ; i < 10 ; i += 2 )
      vaL [ i ] =  -i;
   for ( i = 1 ; i < 10 ; i += 2 )
      vaL [ i ] =  i-1;

   cout << "The initial valarray is:  ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   vaPLUS = +vaL;
   cout << "The element-by-element result of "
        << "the operator+ is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaPLUS [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is:  ( 0 0 -2 2 -4 4 -6 6 -8 8 ).
The element-by-element result of the operator+ is the
valarray: ( 0 0 -2 2 -4 4 -6 6 -8 8 ).
```

## <a name="op_add_eq"></a>operador + =

Adiciona os elementos de uma valarray especificado ou um valor do tipo de elemento, elemento a elemento, a uma valarray operando.

```cpp
valarray<Type>& operator+=(const valarray<Type>& right);

valarray<Type>& operator+=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando que será adicionado, elemento a elemento, ao valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são a soma elementar do operando valarray e *Right*.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_eadd.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 8 ), vaR ( 8 );
   for ( i = 0 ; i < 8 ; i += 2 )
      vaL [ i ] =  2;
   for ( i = 1 ; i < 8 ; i += 2 )
      vaL [ i ] =  -1;
   for ( i = 0 ; i < 8 ; i++ )
      vaR [ i ] =  i;

   cout << "The initial valarray is: ( ";
      for (i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The initial  right valarray is: ( ";
      for (i = 0 ; i < 8 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL += vaR;
   cout << "The element-by-element result of "
        << "the sum is the"
        << endl << "valarray: ( ";
      for (i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is: ( 2 -1 2 -1 2 -1 2 -1 ).
The initial  right valarray is: ( 0 1 2 3 4 5 6 7 ).
The element-by-element result of the sum is the
valarray: ( 2 0 4 2 6 4 8 6 ).
```

## <a name="operator-"></a>operador

Um operador unário que aplica a um sinal de subtração a cada elemento em uma valarray.

```cpp
valarray<Type> operator-() const;
```

### <a name="return-value"></a>Valor retornado

Uma valarray cujos elementos são uma subtração dos da matriz operando.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_eminus.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 10 );
   valarray<int> vaMINUS ( 10 );
   for ( i = 0 ; i < 10 ; i += 2 )
      vaL [ i ] =  -i;
   for ( i = 1 ; i < 10 ; i += 2 )
      vaL [ i ] =  i-1;

   cout << "The initial valarray is:  ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   vaMINUS = -vaL;
   cout << "The element-by-element result of "
        << "the operator+ is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaMINUS [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is:  ( 0 0 -2 2 -4 4 -6 6 -8 8 ).
The element-by-element result of the operator+ is the
valarray: ( 0 0 2 -2 4 -4 6 -6 8 -8 ).
```

## <a name="operator-_eq"></a>operador-=

Subtrai os elementos de uma valarray especificada ou um valor do tipo de elemento, elemento a elemento, a uma valarray operando.

```cpp
valarray<Type>& operator-=(const valarray<Type>& right);

valarray<Type>& operator-=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando que será subtraído, elemento a elemento, da valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são a diferença de elemento do operando valarray e *direita*.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_esub.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 8 ), vaR ( 8 );
   for ( i = 0 ; i < 8 ; i += 2 )
      vaL [ i ] =  10;
   for ( i = 1 ; i < 8 ; i += 2 )
      vaL [ i ] =  0;
   for ( i = 0 ; i < 8 ; i++ )
      vaR [ i ] =  i;

   cout << "The initial valarray is: ( ";
      for (i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The initial  right valarray is: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL -= vaR;
   cout << "The element-by-element result of "
        << "the difference is the"
        << endl << "valarray: ( ";
      for ( i = 0 ; i < 8 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is: ( 10 0 10 0 10 0 10 0 ).
The initial  right valarray is: ( 0 1 2 3 4 5 6 7 ).
The element-by-element result of the difference is the
valarray: ( 10 -1 8 -3 6 -5 4 -7 ).
```

## <a name="op_div_eq"></a>operador/=

Divide uma valarray operando, elemento a elemento, pelos elementos de uma valarray especificada ou um valor do tipo de elemento.

```cpp
valarray<Type>& operator/=(const valarray<Type>& right);

valarray<Type>& operator/=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando que será dividido, elemento a elemento, no valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são o quociente com elemento do operando valarray dividido por *direita*.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_ediv.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<double> vaL ( 6 ), vaR ( 6 );
   for ( i = 0 ; i < 6 ; i += 2 )
      vaL [ i ] =  100;
   for ( i = 1 ; i < 6 ; i += 2 )
      vaL [ i ] =  -100;
   for ( i = 0 ; i < 6 ; i++ )
      vaR [ i ] =  2*i;

   cout << "The initial valarray is: ( ";
      for (i = 0 ; i < 6 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The initial Right valarray is: ( ";
      for (i = 0 ; i < 6 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL /= vaR;
   cout << "The element-by-element result of "
        << "the quotient is the"
        << endl << "valarray: ( ";
      for (i = 0 ; i < 6 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial valarray is: ( 100 -100 100 -100 100 -100 ).
The initial Right valarray is: ( 0 2 4 6 8 10 ).
The element-by-element result of the quotient is the
valarray: ( inf -50 25 -16.6667 12.5 -10 ).
```

## <a name="op_eq"></a>operador =

Atribui elementos a uma valarray cujos valores são especificados diretamente ou como parte de algumas outras valarray ou por um slice_array, gslice_array, mask_array ou indirect_array.

```cpp
valarray<Type>& operator=(const valarray<Type>& right);

valarray<Type>& operator=(valarray<Type>&& right);

valarray<Type>& operator=(const Type& val);

valarray<Type>& operator=(const slice_array<Type>& _Slicearray);

valarray<Type>& operator=(const gslice_array<Type>& _Gslicearray);

valarray<Type>& operator=(const mask_array<Type>& _Maskarray);

valarray<Type>& operator=(const indirect_array<Type>& _Indarray);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray a ser copiada para a valarray operando.

*valor*\
O valor a ser atribuído aos elementos da valarray operando.

*_Slicearray*\
A slice_array a ser copiada para a valarray operando.

*_Gslicearray*\
A gslice_array a ser copiada para a valarray operando.

*_Maskarray*\
A mask_array a ser copiada para a valarray operando.

*_Indarray*\
A indirect_array a ser copiada para a valarray operando.

### <a name="return-value"></a>Valor retornado

O primeiro operador de membro substitui a sequência controlada por uma cópia da sequência controlada pela *direita*.

O segundo operador de membro é o mesmo que o primeiro, mas com um [Declarador de Referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

O terceiro operador de membro substitui cada elemento da sequência controlada por uma cópia de *Val*.

Os operadores de membro restantes substituem os elementos da sequência controlada selecionada por seus argumentos, que são gerados somente pelo [operator&#91;&#93;](#op_at).

Se o valor de um membro na sequência controlada de substituição depender de um membro na sequência controlada inicial, o resultado será indefinido.

### <a name="remarks"></a>Comentários

Se o comprimento da sequência controlada for alterado, geralmente, o resultado será indefinido. Nessa implementação, no entanto, o efeito é simplesmente invalidar quaisquer ponteiros ou referências a elementos na sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_assign.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> va ( 10 ), vaR ( 10 );
   for ( i = 0 ; i < 10 ; i += 1 )
      va [ i ] = i;
   for ( i = 0 ; i < 10 ; i+=1 )
      vaR [ i ] = 10 -  i;

   cout << "The operand valarray va is:";
   for ( i = 0 ; i < 10 ; i++ )
      cout << " " << va [ i ];
   cout << endl;

   cout << "The operand valarray vaR is:";
      for ( i = 0 ; i < 10 ; i++ )
         cout << " " << vaR [ i ];
   cout << endl;

   // Assigning vaR to va with the first member functon
   va = vaR;
   cout << "The reassigned valarray va is:";
   for ( i = 0 ; i < 10 ; i++ )
      cout << " " << va [ i ];
   cout << endl;

   // Assigning elements of value 10 to va
   // with the second member functon
   va = 10;
   cout << "The reassigned valarray va is:";
      for ( i = 0 ; i < 10 ; i++ )
         cout << " " << va [ i ];
   cout << endl;
}
```

```Output
The operand valarray va is: 0 1 2 3 4 5 6 7 8 9
The operand valarray vaR is: 10 9 8 7 6 5 4 3 2 1
The reassigned valarray va is: 10 9 8 7 6 5 4 3 2 1
The reassigned valarray va is: 10 10 10 10 10 10 10 10 10 10

```

## <a name="op_at"></a>operador []

Retorna uma referência a um elemento ou seu valor no índice ou subconjunto especificado.

```cpp
Type& operator[](size_t _Off);

slice_array<Type> operator[](slice _Slicearray);

gslice_array<Type> operator[](const gslice& _Gslicearray);

mask_array<Type> operator[](const valarray<bool>& _Boolarray);

indirect_array<Type> operator[](const valarray<size_t>& _Indarray);

Type operator[](size_t _Off) const;

valarray<Type> operator[](slice _Slice) const;

valarray<Type> operator[](const gslice& _Gslicearray) const;

valarray<Type> operator[](const valarray<bool>& _Boolarray) const;

valarray<Type> operator[](const valarray<size_t>& _Indarray) const;
```

### <a name="parameters"></a>parâmetros

*_Off*\
O índice do elemento que terá um valor atribuído.

*_Slicearray*\
Uma slice_array de uma valarray que especifica um subconjunto a ser selecionado ou retornado para uma nova valarray.

*_Gslicearray*\
Uma gslice_array de uma valarray que especifica um subconjunto a ser selecionado ou retornado para uma nova valarray.

*_Boolarray*\
Uma bool_array de uma valarray que especifica um subconjunto a ser selecionado ou retornado para uma nova valarray.

*_Indarray*\
Uma indirect_array de uma valarray que especifica um subconjunto a ser selecionado ou retornado para uma nova valarray.

### <a name="return-value"></a>Valor retornado

Uma referência a um elemento ou seu valor no índice ou subconjunto especificado.

### <a name="remarks"></a>Comentários

O operador de membro é sobrecarregado para fornecer várias maneiras de selecionar sequências de elementos entre aqueles controlados por <strong>\*isso</strong>. O primeiro grupo de cinco operadores de membro funciona em conjunto com várias sobrecargas de [operator=](#op_eq) (e outros operadores de atribuição) para permitir a substituição seletiva (divisão) da sequência controlada. Os elementos selecionados devem existir.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento fora dos limites da valarray.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.

### <a name="example"></a>Exemplo

Veja os exemplos de [slice::slice](../standard-library/slice-class.md#slice) e [gslice::gslice](../standard-library/gslice-class.md#gslice) para obter um exemplo de como declarar e usar o operador.

## <a name="op_xor_eq"></a>operador ^ =

Obtém o lógico exclusivo elemento a elemento ou operador (**XOR**) de uma matriz com uma valarray especificada ou um valor do tipo de elemento.

```cpp
valarray<Type>& operator|=(const valarray<Type>& right);

valarray<Type>& operator|=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando que será combinado, elemento a elemento, pelo lógico exclusivo **XOR** com a valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são o **XOR** lógico exclusivo de elemento, do operando valarray e *direito*.

### <a name="remarks"></a>Comentários

O OR lógico exclusivo, chamado de **XOR**, tem a seguinte semântica: dados especificados, e *1 e*2 *,* *e*1 **XOR** *e*2 serão **verdadeiros** se exatamente um dos elementos for verdadeiro; **false** se ambos os elementos forem false ou se ambos os elementos forem verdadeiros.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_exor.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
    using namespace std;
    int i;

    valarray<int> vaL ( 10 ), vaR ( 10 );
    for ( i = 0 ; i < 10 ; i += 2 )
        vaL [ i ] =  1;
    for ( i = 1 ; i < 10 ; i += 2 )
        vaL [ i ] =  0;
    for ( i = 0 ; i < 10 ; i += 3 )
        vaR [ i ] =  i;
    for ( i = 1 ; i < 10 ; i += 3 )
        vaR [ i ] =  i-1;
    for ( i = 2 ; i < 10 ; i += 3 )
        vaR [ i ] =  i-1;

    cout << "The initial operand valarray is:  ( ";
        for (i = 0 ; i < 10 ; i++ )
            cout << vaL [ i ] << " ";
    cout << ")." << endl;

    cout << "The  right valarray is: ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << vaR [ i ] << " ";
    cout << ")." << endl;

    vaL ^= vaR;
    cout << "The element-by-element result of "
        << "the bitwise XOR operator^= is the"
        << endl << "valarray: ( ";
        for (i = 0 ; i < 10 ; i++ )
            cout << vaL [ i ] << " ";
    cout << ")." << endl;
}
```

```Output
The initial operand valarray is:  ( 1 0 1 0 1 0 1 0 1 0 ).
The  right valarray is: ( 0 0 1 3 3 4 6 6 7 9 ).
The element-by-element result of the bitwise XOR operator^= is the
valarray: ( 1 0 0 3 2 4 7 6 6 9 ).
```

## <a name="op_or_eq"></a>operador&#124;=

Obtém o bit a bit `OR` de elementos em uma matriz com os elementos correspondentes em uma valarray especificada ou com um valor do tipo de elemento.

```cpp
valarray<Type>& operator|=(const valarray<Type>& right);

valarray<Type>& operator|=(const Type& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
A valarray ou valor de um tipo de elemento idêntico ao da valarray operando será combinado, elemento a elemento, pelo bit a bit `OR` com a valarray operando.

### <a name="return-value"></a>Valor retornado

Um valarray cujos elementos são os `OR` bit a passo de um elemento do operando valarray *à direita*.

### <a name="remarks"></a>Comentários

Uma operação bit a ponto pode ser usada apenas para manipular bits em tipos de dados **Char** e **int** e variantes, e não em **float**, **Double**, **longdouble**, **void**, **bool**ou outros tipos de dados mais complexos.

O bit a bit `OR` tem a mesma tabela de verdade que o lógico `OR`, mas se aplica ao tipo de dados em nível de bits individuais. Determinados bits *b*1 e *b*2, *b*1 `OR` *b*2 será **verdadeiro** se pelo menos um dos bits for verdadeiro; **false** se ambos os bits forem falsos.

### <a name="example"></a>Exemplo

```cpp
// valarray_class_op_bitor.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> vaL ( 10 ), vaR ( 10 );
   for ( i = 0 ; i < 10 ; i += 2 )
      vaL [ i ] =  1;
   for ( i = 1 ; i < 10 ; i += 2 )
      vaL [ i ] =  0;
   for ( i = 0 ; i < 10 ; i += 3 )
      vaR [ i ] =  i;
   for ( i = 1 ; i < 10 ; i += 3 )
      vaR [ i ] =  i-1;
   for ( i = 2 ; i < 10 ; i += 3 )
      vaR [ i ] =  i-1;

   cout << "The initial operand valarray is:"
        << endl << "( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;

   cout << "The  right valarray is:"
        << endl << "( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << vaR [ i ] << " ";
   cout << ")." << endl;

   vaL |= vaR;
   cout << "The element-by-element result of "
        << "the logical OR"
        << endl << "operator|= is the valarray:"
        << endl << "( ";
      for (i = 0 ; i < 10 ; i++ )
         cout << vaL [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The initial operand valarray is:
( 1 0 1 0 1 0 1 0 1 0 ).
The  right valarray is:
( 0 0 1 3 3 4 6 6 7 9 ).
The element-by-element result of the logical OR
operator|= is the valarray:
( 1 0 1 3 3 4 7 6 7 9 ).
```

## <a name="op_dtor"></a>operador ~

Um operador unário que obtém os valores de `NOT` de bits de cada elemento em um valarray.

```cpp
valarray<Type> operator~() const;
```

### <a name="return-value"></a>Valor retornado

O valarray de valores Boolianos que são o `NOT` bit a bit dos valores de elemento do operando valarray.

### <a name="remarks"></a>Comentários

Uma operação bit a ponto pode ser usada apenas para manipular bits em tipos de dados **Char** e **int** e variantes e não em **float**, **Double**, **longdouble**, **void**, **bool** ou outros tipos de dados mais complexos.

O bit a bit `NOT` tem a mesma tabela de verdade que o lógico `NOT`, mas se aplica ao tipo de dados em nível de bits individuais. Considerando o bit *b*, ~ *b* será true se *b* for false e false se *b* for true. O **NOT**[operator!](#op_not) lógico se aplica no nível de elemento contando todos os valores diferentes de zero como **true** e o resultado é uma valarray de valores boolianos. Por outro lado, a `NOToperator~`bit a bit pode resultar em um valarray de valores diferentes de 0 ou 1, dependendo do resultado da operação bit a bit.

### <a name="example"></a>Exemplo

```cpp
// valarray_op_bitnot.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
    using namespace std;
    int i;

    valarray<unsigned short int> vaL1 ( 10 );
    valarray<unsigned short int> vaNOT1 ( 10 );
    for ( i = 0 ; i < 10 ; i += 2 )
        vaL1 [ i ] =  i;
    for ( i = 1 ; i < 10 ; i += 2 )
        vaL1 [ i ] =  5*i;

    cout << "The initial valarray <unsigned short int> is:  ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << vaL1 [ i ] << " ";
    cout << ")." << endl;

    vaNOT1 = ~vaL1;
    cout << "The element-by-element result of "
        << "the bitwise NOT operator~ is the"
        << endl << "valarray: ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << vaNOT1 [ i ] << " ";
    cout << ")." << endl << endl;

    valarray<int> vaL2 ( 10 );
    valarray<int> vaNOT2 ( 10 );
    for ( i = 0 ; i < 10 ; i += 2 )
        vaL2 [ i ] =  i;
    for ( i = 1 ; i < 10 ; i += 2 )
        vaL2 [ i ] =  -2 * i;

    cout << "The initial valarray <int> is:  ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << vaL2 [ i ] << " ";
    cout << ")." << endl;

    vaNOT2 = ~vaL2;
    cout << "The element-by-element result of "
        << "the bitwise NOT operator~ is the"
        << endl << "valarray: ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << vaNOT2 [ i ] << " ";
    cout << ")." << endl;

    // The negative numbers are represented using
    // the two's complement approach, so adding one
    // to the flipped bits returns the negative elements
    vaNOT2 = vaNOT2 + 1;
    cout << "The element-by-element result of "
        << "adding one"
        << endl << "is the negative of the "
        << "original elements the"
        << endl << "valarray: ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << vaNOT2 [ i ] << " ";
    cout << ")." << endl;
}
```

```Output
The initial valarray <unsigned short int> is:  ( 0 5 2 15 4 25 6 35 8 45 ).
The element-by-element result of the bitwise NOT operator~ is the
valarray: ( 65535 65530 65533 65520 65531 65510 65529 65500 65527 65490 ).

The initial valarray <int> is:  ( 0 -2 2 -6 4 -10 6 -14 8 -18 ).
The element-by-element result of the bitwise NOT operator~ is the
valarray: ( -1 1 -3 5 -5 9 -7 13 -9 17 ).
The element-by-element result of adding one
is the negative of the original elements the
valarray: ( 0 2 -2 6 -4 10 -6 14 -8 18 ).
```

## <a name="resize"></a>alonga

Altera o número de elementos em uma valarray para um número especificado.

```cpp
void resize(
    size_t _Newsize);

void resize(
    size_t _Newsize,
    const Type val);
```

### <a name="parameters"></a>parâmetros

*_Newsize*\
O número de elementos na valarray redimensionada.

*valor*\
O valor a ser atribuído aos elementos da valarray redimensionada.

### <a name="remarks"></a>Comentários

A primeira função membro inicializa elementos com o construtor padrão.

Quaisquer ponteiros ou referências a elementos na sequência controlada serão invalidadas.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro valarray::resize.

```cpp
// valarray_resize.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main()
{
    using namespace std;
    int i;
    size_t size1, sizeNew;

    valarray<int> va1(10);
    for (i = 0; i < 10; i+=1)
        va1[i] = i;

    cout << "The valarray contains ( ";
        for (i = 0; i < 10; i++)
            cout << va1[i] << " ";
    cout << ")." << endl;

    size1 = va1.size();
    cout << "The number of elements in the valarray is: "
         << size1  << "." <<endl << endl;

    va1.resize(15, 10);

    cout << "The valarray contains ( ";
        for (i = 0; i < 15; i++)
            cout << va1[i] << " ";
    cout << ")." << endl;
    sizeNew = va1.size();
    cout << "The number of elements in the resized valarray is: "
         << sizeNew  << "." <<endl << endl;
}
```

```Output
The valarray contains ( 0 1 2 3 4 5 6 7 8 9 ).
The number of elements in the valarray is: 10.

The valarray contains ( 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 ).
The number of elements in the resized valarray is: 15.
```

## <a name="shift"></a>alternância

Desloca todos os elementos em uma valarray por meio de um número especificado de posições.

```cpp
valarray<Type> shift(int count) const;
```

### <a name="parameters"></a>parâmetros

*contagem*\
O número de locais para os quais os elementos serão deslocados para frente.

### <a name="return-value"></a>Valor retornado

Um novo valarray no qual todos os elementos foram movidos posições de *contagem* em direção à frente do valarray, deixados em relação às suas posições no operando valarray.

### <a name="remarks"></a>Comentários

Um valor positivo de *contagem* alterna os locais de *contagem* à esquerda, com preenchimento zero.

Um valor negativo de *Count* alterna os locais de *contagem* direita de elementos, com preenchimento zero.

### <a name="example"></a>Exemplo

```cpp
// valarray_shift.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   valarray<int> va1 ( 10 ), va2 ( 10 );
   for ( i = 0 ; i < 10 ; i += 1 )
      va1 [ i ] =  i;
   for ( i = 0 ; i < 10 ; i += 1 )
      va2 [ i ] = 10 -  i;

   cout << "The operand valarray va1(10) is: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << va1 [ i ] << " ";
   cout << ")." << endl;

   // A positive parameter shifts elements left
   va1 = va1.shift ( 4 );
   cout << "The shifted valarray va1 is: va1.shift (4) = ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << va1 [ i ] << " ";
   cout << ")." << endl;

   cout << "The operand valarray va2(10) is: ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << va2 [ i ] << " ";
   cout << ")." << endl;

   // A negative parameter shifts elements right
   va2 = va2.shift ( - 4 );
   cout << "The shifted valarray va2 is: va2.shift (-4) = ( ";
      for ( i = 0 ; i < 10 ; i++ )
         cout << va2 [ i ] << " ";
   cout << ")." << endl;
}
```

```Output
The operand valarray va1(10) is: ( 0 1 2 3 4 5 6 7 8 9 ).
The shifted valarray va1 is: va1.shift (4) = ( 4 5 6 7 8 9 0 0 0 0 ).
The operand valarray va2(10) is: ( 10 9 8 7 6 5 4 3 2 1 ).
The shifted valarray va2 is: va2.shift (-4) = ( 0 0 0 0 10 9 8 7 6 5 ).
```

## <a name="size"></a>tamanho

Localiza o número de elementos em uma valarray.

```cpp
size_t size() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos na valarray operando.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro valarray::size.

```cpp
// valarray_size.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main()
{
    using namespace std;
    int i;
    size_t size1, size2;

    valarray<int> va1(10), va2(12);
    for (i = 0; i < 10; i += 1)
        va1[i] =  i;
    for (i = 0; i < 10; i += 1)
        va2[i] =  i;

    cout << "The operand valarray va1(10) is: ( ";
        for (i = 0; i < 10; i++)
            cout << va1[i] << " ";
    cout << ")." << endl;

    size1 = va1.size();
    cout << "The number of elements in the valarray va1 is: va1.size = "
         << size1  << "." <<endl << endl;

    cout << "The operand valarray va2(12) is: ( ";
        for (i = 0; i < 10; i++)
            cout << va2[i] << " ";
    cout << ")." << endl;

    size2 = va2.size();
    cout << "The number of elements in the valarray va2 is: va2.size = "
         << size2  << "." << endl << endl;

    // Initializing two more elements to va2
    va2[10] = 10;
    va2[11] = 11;
    cout << "After initializing two more elements,\n"
         << "the operand valarray va2(12) is now: ( ";
        for (i = 0; i < 12; i++)
            cout << va2[i] << " ";
    cout << ")." << endl;
    cout << "The number of elements in the valarray va2 is still: "
         << size2  << "." << endl;
}
```

```Output
The operand valarray va1(10) is: ( 0 1 2 3 4 5 6 7 8 9 ).
The number of elements in the valarray va1 is: va1.size = 10.

The operand valarray va2(12) is: ( 0 1 2 3 4 5 6 7 8 9 ).
The number of elements in the valarray va2 is: va2.size = 12.

After initializing two more elements,
the operand valarray va2(12) is now: ( 0 1 2 3 4 5 6 7 8 9 10 11 ).
The number of elements in the valarray va2 is still: 12.
```

## <a name="sum"></a>quantia

Determina a soma de todos os elementos em uma valarray de comprimento diferente de zero.

```cpp
Type sum() const;
```

### <a name="return-value"></a>Valor retornado

A soma dos elementos da valarray operando.

### <a name="remarks"></a>Comentários

Se o comprimento for maior que um, a função de membro adicionará valores à soma aplicando `operator+=` entre pares de elementos da classe `Type`, qual operador, consequentemente, precisa ser fornecido para elementos do tipo `Type`.

### <a name="example"></a>Exemplo

```cpp
// valarray_sum.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
    using namespace std;
    int i;
    int sumva = 0;

    valarray<int> va ( 10 );
    for ( i = 0 ; i < 10 ; i+=1 )
        va [ i ] =  i;

    cout << "The operand valarray va (10) is: ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << va [ i ] << " ";
    cout << ")." << endl;

    sumva = va.sum ( );
    cout << "The sum of elements in the valarray is: "
        << sumva  << "." <<endl;
}
```

```Output
The operand valarray va (10) is: ( 0 1 2 3 4 5 6 7 8 9 ).
The sum of elements in the valarray is: 45.
```

## <a name="swap"></a>permuta

Troca os elementos de dois `valarray`s.

```cpp
void swap(valarray& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
Um `valarray` que fornece os elementos a serem trocados.

### <a name="remarks"></a>Comentários

A função membro troca as sequências controladas entre `*this` e *direita*. Ela faz isso em tempo constante, não gera exceções e não invalida referências, ponteiros ou iteradores que designam elementos nas duas sequências controlados.

## <a name="valarray"></a>valarray

Constrói uma valarray de um tamanho específico ou com elementos de um valor específico ou como uma cópia de outra valarray ou um subconjunto de outra valarray.

```cpp
valarray();

explicit valarray(
    size_t Count);

valarray(
    const Type& Val,
    size_t Count);

valarray(
    const Type* Ptr,
    size_t Count);

valarray(
    const valarray<Type>& Right);

valarray(
    const slice_array<Type>& SliceArray);

valarray(
    const gslice_array<Type>& GsliceArray);

valarray(
    const mask_array<Type>& MaskArray);

valarray(
    const indirect_array<Type>& IndArray);

valarray(
    valarray<Type>&& Right);

valarray(
    initializer_list<Type> IList);
```

### <a name="parameters"></a>parâmetros

*Contagem*\
O número de elementos que estarão na valarray.

*Valor*\
O valor a ser usado ao inicializar os elementos na valarray.

\ *PTR*
Ponteiro para os valores a serem usados ao inicializar os elementos na valarray.

\ *à direita*
Uma valarray existente para inicializar a nova valarray.

\ *SliceArray*
Uma slice_array cujos valores de elemento serão usados ao inicializar os elementos da valarray em construção.

\ *GsliceArray*
Uma gslice_array cujos valores de elemento serão usados ao inicializar os elementos da valarray em construção.

\ *MaskArray*
Uma mask_array cujos valores de elemento serão usados ao inicializar os elementos da valarray em construção.

\ *IndArray*
Uma indirect_array cujos valores de elemento serão usados ao inicializar os elementos da valarray em construção.

*IList*\
A initializer_list que contém os elementos a serem copiados.

### <a name="remarks"></a>Comentários

O primeiro construtor (padrão) inicializa o objeto em uma matriz vazia. Os próximos três construtores inicializam o objeto para uma matriz de elementos *Count* da seguinte maneira:

- Para o `valarray(size_t Count)` explícito, cada elemento será inicializado com o construtor padrão.

- Por `valarray(const Type& Val, Count)`, cada elemento é inicializado com *Val*.

- Para `valarray(const Type* Ptr, Count)`, o elemento na posição `I` será inicializado com `Ptr`[ `I`].

Cada construtor restante inicializará o objeto para um objeto valarray\<Type> determinado pelo subconjunto especificado no argumento.

O último construtor é o mesmo que o próximo ou último, mas com um [Declarador de Referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

### <a name="example"></a>Exemplo

```cpp
// valarray_ctor.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main()
{
    using namespace std;
    int i;

    // The second member function
    valarray<int> va(10);
    for (auto i : va){
        va[i] = 2 * (i + 1);
    }

    cout << "The operand valarray va is:\n(";
    for (auto i : va) {
        cout << " " << va[i];
    }
    cout << " )" << endl;

    slice Slice(2, 4, 3);

    // The fifth member function
    valarray<int> vaSlice = va[Slice];

    cout << "The new valarray initialized from the slice is vaSlice =\n"
        << "va[slice( 2, 4, 3)] = (";
    for (int i = 0; i < 3; i++) {
        cout << " " << vaSlice[i];
    }
    cout << " )" << endl;

    valarray<int> va2{{ 1, 2, 3, 4 }};
    for (auto& v : va2) {
        cout << v << " ";
    }
    cout << endl;
}
```

```Output
The operand valarray va is:
( 0 2 2 2 2 2 2 2 2 2 )
The new valarray initialized from the slice is vaSlice =
va[slice( 2, 4, 3)] = ( 0 0 0 )
1 2 3 4
```

## <a name="value_type"></a>value_type

Um tipo que representa o tipo de elemento armazenado em uma valarray.

```cpp
typedef Type value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Type`.

### <a name="example"></a>Exemplo

```cpp
// valarray_value_type.cpp
// compile with: /EHsc
#include <valarray>
#include <iostream>

int main( )
{
    using namespace std;
    int i;
    valarray<int> va ( 10 );
    for ( i = 0 ; i < 10 ; i += 2 )
        va [ i ] =  i;
    for ( i = 1 ; i < 10 ; i += 2 )
        va [ i ] =  -1;

    cout << "The initial operand valarray is:  ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << va [ i ] << " ";
    cout << ")." << endl;

    // value_type declaration and initialization:
    valarray<int>::value_type Right = 10;

    cout << "The decalared value_type Right is: "
            << Right << endl;
    va *= Right;
    cout << "The resulting valarray is:  ( ";
        for ( i = 0 ; i < 10 ; i++ )
            cout << va [ i ] << " ";
    cout << ")." << endl;
}
```

```Output
The initial operand valarray is:  ( 0 -1 2 -1 4 -1 6 -1 8 -1 ).
The decalared value_type Right is: 10
The resulting valarray is:  ( 0 -10 20 -10 40 -10 60 -10 80 -10 ).
```

## <a name="see-also"></a>Confira também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
