---
title: Classe moneypunct
ms.date: 11/04/2016
f1_keywords:
- xlocmon/std::moneypunct
- xlocmon/std::moneypunct::char_type
- xlocmon/std::moneypunct::string_type
- xlocmon/std::moneypunct::curr_symbol
- xlocmon/std::moneypunct::decimal_point
- xlocmon/std::moneypunct::do_curr_symbol
- xlocmon/std::moneypunct::do_decimal_point
- xlocmon/std::moneypunct::do_frac_digits
- xlocmon/std::moneypunct::do_grouping
- xlocmon/std::moneypunct::do_neg_format
- xlocmon/std::moneypunct::do_negative_sign
- xlocmon/std::moneypunct::do_pos_format
- xlocmon/std::moneypunct::do_positive_sign
- xlocmon/std::moneypunct::do_thousands_sep
- xlocmon/std::moneypunct::frac_digits
- xlocmon/std::moneypunct::grouping
- xlocmon/std::moneypunct::neg_format
- xlocmon/std::moneypunct::negative_sign
- xlocmon/std::moneypunct::pos_format
- xlocmon/std::moneypunct::positive_sign
- xlocmon/std::moneypunct::thousands_sep
helpviewer_keywords:
- std::moneypunct [C++]
- std::moneypunct [C++], char_type
- std::moneypunct [C++], string_type
- std::moneypunct [C++], curr_symbol
- std::moneypunct [C++], decimal_point
- std::moneypunct [C++], do_curr_symbol
- std::moneypunct [C++], do_decimal_point
- std::moneypunct [C++], do_frac_digits
- std::moneypunct [C++], do_grouping
- std::moneypunct [C++], do_neg_format
- std::moneypunct [C++], do_negative_sign
- std::moneypunct [C++], do_pos_format
- std::moneypunct [C++], do_positive_sign
- std::moneypunct [C++], do_thousands_sep
- std::moneypunct [C++], frac_digits
- std::moneypunct [C++], grouping
- std::moneypunct [C++], neg_format
- std::moneypunct [C++], negative_sign
- std::moneypunct [C++], pos_format
- std::moneypunct [C++], positive_sign
- std::moneypunct [C++], thousands_sep
ms.assetid: cf2650da-3e6f-491c-95d5-23e57f582ee6
ms.openlocfilehash: b6cd2524f8ae010e81d06a30d9a001398a106622
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68460200"
---
# <a name="moneypunct-class"></a>Classe moneypunct

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para descrever as sequências do tipo *CharType* usado para representar um campo de entrada monetário ou um campo de saída monetária. Se o parâmetro de modelo *intl* for *true*, as convenções internacionais serão observadas.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, bool Intl>
class moneypunct;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres.

*Intl*\
Um sinalizador que especifica se as convenções internacionais devem ser observadas.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

O objeto estático const intl armazena o valor do parâmetro de modelo *Intl*.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[moneypunct](#moneypunct)|Construtor de objetos do tipo `moneypunct`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[curr_symbol](#curr_symbol)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.|
|[decimal_point](#decimal_point)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.|
|[do_curr_symbol](#do_curr_symbol)|Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.|
|[do_decimal_point](#do_decimal_point)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.|
|[do_frac_digits](#do_frac_digits)|A função membro virtual protegida retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.|
|[do_grouping](#do_grouping)|A função membro virtual protegida retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|
|[do_neg_format](#do_neg_format)|Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores negativos.|
|[do_negative_sign](#do_negative_sign)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.|
|[do_pos_format](#do_pos_format)|Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores positivos.|
|[do_positive_sign](#do_positive_sign)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.|
|[do_thousands_sep](#do_thousands_sep)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de separador de milhares.|
|[frac_digits](#frac_digits)|Retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.|
|[grouping](#grouping)|Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|
|[neg_format](#neg_format)|Retorna uma regra específica de localidade para formatação de saídas com valores negativos.|
|[negative_sign](#negative_sign)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.|
|[pos_format](#pos_format)|Retorna uma regra específica de localidade para formatação de saídas com valores positivos.|
|[positive_sign](#positive_sign)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.|
|[thousands_sep](#thousands_sep)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de separador de milhares.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="char_type"></a>  moneypunct::char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **CharType**.

## <a name="curr_symbol"></a>  moneypunct::curr_symbol

Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.

```cpp
string_type curr_symbol() const;
```

### <a name="return-value"></a>Valor de retorno

Uma cadeia de caracteres que contém o símbolo de moeda.

### <a name="remarks"></a>Comentários

A função membro retorna [do_curr_symbol](#do_curr_symbol).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_curr_symbol.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   const moneypunct < char, true > &mpunct = use_facet < moneypunct < char, true > >(loc);
   cout << loc.name( ) << " international currency symbol "<<  mpunct.curr_symbol( ) << endl;

   const moneypunct < char, false> &mpunct2 = use_facet < moneypunct < char, false> >(loc);
   cout << loc.name( ) << " domestic currency symbol "<<  mpunct2.curr_symbol( ) << endl;
};
```

## <a name="decimal_point"></a>  moneypunct::decimal_point

Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.

```cpp
CharType decimal_point() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.

### <a name="remarks"></a>Comentários

A função membro retorna [do_decimal_point](#do_decimal_point).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_decimal_pt.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc("german_germany");

   const moneypunct < char, true > &mpunct = use_facet
      < moneypunct < char, true > >(loc);
   cout << loc.name( ) << " international decimal point "
        << mpunct.decimal_point( ) << endl;

   const moneypunct < char, false> &mpunct2 = use_facet
      < moneypunct < char, false> >(loc);
   cout << loc.name( ) << " domestic decimal point "
        << mpunct2.decimal_point( ) << endl;
}
```

```Output
German_Germany.1252 international decimal point ,
German_Germany.1252 domestic decimal point ,
```

## <a name="do_curr_symbol"></a>  moneypunct::do_curr_symbol

Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.

```cpp
virtual string_type do_curr_symbol() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.

### <a name="example"></a>Exemplo

Veja o exemplo de [curr_symbol](#curr_symbol), em que a função membro virtual é chamada por `curr_symbol`.

## <a name="do_decimal_point"></a>  moneypunct::do_decimal_point

Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.

```cpp
virtual CharType do_decimal_point() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.

### <a name="example"></a>Exemplo

Veja o exemplo de [decimal_point](#decimal_point), em que a função membro virtual é chamada por `decimal_point`.

## <a name="do_frac_digits"></a>  moneypunct::do_frac_digits

Uma função membro virtual protegida retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.

```cpp
virtual int do_frac_digits() const;
```

### <a name="return-value"></a>Valor de retorno

Uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.

### <a name="example"></a>Exemplo

Veja o exemplo de [frac_digits](#frac_digits), em que a função membro virtual é chamada por `frac_digits`.

## <a name="do_grouping"></a>  moneypunct::do_grouping

Uma função membro virtual protegida que retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

```cpp
virtual string do_grouping() const;
```

### <a name="return-value"></a>Valor de retorno

Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

### <a name="example"></a>Exemplo

Consulte o exemplo de [agrupamento](#grouping), onde a função membro virtual é chamada por `grouping`.

## <a name="do_neg_format"></a>  moneypunct::do_neg_format

Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores negativos.

```cpp
virtual pattern do_neg_format() const;
```

### <a name="return-value"></a>Valor de retorno

A função membro virtual protegida retorna uma regra específica de localidade para determinar como gerar o campo de saída monetário para um valor negativo. Cada um dos quatro elementos de `pattern::field` pode ter os valores:

- `none`para corresponder a zero ou mais espaços ou não gerar nada.

- `sign`para corresponder ou gerar um sinal positivo ou negativo.

- `space`para corresponder a zero ou mais espaços ou gerar um espaço.

- `symbol`para corresponder ou gerar um símbolo de moeda.

- `value`para corresponder ou gerar um valor monetário.

Os componentes de um campo de saída monetária são gerados e os componentes de um campo de entrada monetária são correspondidos na ordem em `pattern::field`que esses elementos aparecem. `sign`Cada um `value` `symbol` dosvalores`space` ,, e ou deve aparecer exatamente uma vez. `none` O valor `none` não deve aparecer primeiro. O valor space não **deve** não devem aparecer primeiro ou por último. Se `Intl` for true, Order será `symbol`, `sign` `none` ,`value`, e.

A versão de modelo `moneypunct`\< **CharType**, **Intl**> retorna `{`**money_base::symbol**, **money_base::sign**, **money_base::value**, **money_base::none**`}`.

### <a name="example"></a>Exemplo

Veja o exemplo de [net_format](#neg_format), em que a função membro virtual é chamada por `neg_format`.

## <a name="do_negative_sign"></a>  moneypunct::do_negative_sign

Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.

```cpp
virtual string_type do_negative_sign() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como um sinal negativo.

### <a name="example"></a>Exemplo

Veja o exemplo de [negative_sign](#negative_sign), em que a função membro virtual é chamada por `negative_sign`.

## <a name="do_pos_format"></a>  moneypunct::do_pos_format

Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores positivos.

```cpp
virtual pattern do_pos_format() const;
```

### <a name="return-value"></a>Valor de retorno

A função membro virtual protegida retorna uma regra específica de localidade para determinar como gerar o campo de saída monetário para um valor positivo. (Ela também determina como corresponder os componentes de um campo de entrada monetário.) A codificação é a mesma usada para [do_neg_format](#do_neg_format).

A versão do modelo de moneypunct\< **CharType**, **Inputlterator**> retorna `{`**money_base::symbol**, **money_base::sign**, **money_base::value**, **money_base::none**`}`.

### <a name="example"></a>Exemplo

Veja o exemplo de [pos_format](#pos_format), em que a função membro virtual é chamada por `pos_format`.

## <a name="do_positive_sign"></a>  moneypunct::do_positive_sign

Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um sinal positivo.

```cpp
virtual string_type do_positive_sign() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como um sinal positivo.

### <a name="example"></a>Exemplo

Veja o exemplo de [positive_sign](#positive_sign), em que a função membro virtual é chamada por `positive_sign`.

## <a name="do_thousands_sep"></a>  moneypunct::do_thousands_sep

Uma função membro virtual protegida que retorna um elemento específico de localidade para ser usado como separador de grupo à esquerda da vírgula decimal.

```cpp
virtual CharType do_thousands_sep() const;
```

### <a name="return-value"></a>Valor de retorno

Um elemento específico de localidade a ser usado como um separador de grupo à esquerda de qualquer vírgula decimal.

### <a name="example"></a>Exemplo

Veja o exemplo de [thousands_sep](#thousands_sep), em que a função membro virtual é chamada por `thousands_sep`.

## <a name="frac_digits"></a>  moneypunct::frac_digits

Retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.

```cpp
int frac_digits() const;
```

### <a name="return-value"></a>Valor de retorno

Uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.

### <a name="remarks"></a>Comentários

A função membro retorna [do_frac_digits](#do_frac_digits).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_frac_digits.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
       use_facet <moneypunct <char, true> >(loc);
   for (unsigned int i = 0; i <mpunct.grouping( ).length( ); i++ )
   {
      cout << loc.name( ) << " international grouping:\n the "
           << i <<"th group to the left of the radix character "
           << "is of size " << (int)(mpunct.grouping ( )[i])
           << endl;
   }
   cout << loc.name( ) << " international frac_digits\n to the right"
        << " of the radix character: "
        << mpunct.frac_digits ( ) << endl << endl;

   const moneypunct <char, false> &mpunct2 =
       use_facet <moneypunct <char, false> >(loc);
   for (unsigned int i = 0; i <mpunct2.grouping( ).length( ); i++ )
   {
      cout << loc.name( ) << " domestic grouping:\n the "
           << i <<"th group to the left of the radix character "
           << "is of size " << (int)(mpunct2.grouping ( )[i])
           << endl;
   }
   cout << loc.name( ) << " domestic frac_digits\n to the right"
        << " of the radix character: "
        << mpunct2.frac_digits ( ) << endl << endl;
}
```

```Output
German_Germany.1252 international grouping:
the 0th group to the left of the radix character is of size 3
German_Germany.1252 international frac_digits
to the right of the radix character: 2

German_Germany.1252 domestic grouping:
the 0th group to the left of the radix character is of size 3
German_Germany.1252 domestic frac_digits
to the right of the radix character: 2
```

## <a name="grouping"></a>  moneypunct::grouping

Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

```cpp
string grouping() const;
```

### <a name="return-value"></a>Valor de retorno

Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

### <a name="remarks"></a>Comentários

A função membro retorna [do_grouping](#do_grouping).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_grouping.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
       use_facet <moneypunct <char, true> >( loc );
   for (unsigned int i = 0; i <mpunct.grouping( ).length( ); i++ )
   {
      cout << loc.name( ) << " international grouping:\n the "
           << i <<"th group to the left of the radix character "
           << "is of size " << (int)(mpunct.grouping ( )[i])
           << endl;
   }
   cout << loc.name( ) << " international frac_digits\n to the right"
        << " of the radix character: "
        << mpunct.frac_digits ( ) << endl << endl;

   const moneypunct <char, false> &mpunct2 =
       use_facet <moneypunct <char, false> >( loc );
   for (unsigned int i = 0; i <mpunct2.grouping( ).length( ); i++ )
   {
      cout << loc.name( ) << " domestic grouping:\n the "
           << i <<"th group to the left of the radix character "
           << "is of size " << (int)(mpunct2.grouping ( )[i])
           << endl;
   }
   cout << loc.name( ) << " domestic frac_digits\n to the right"
        << " of the radix character: "
        << mpunct2.frac_digits ( ) << endl << endl;
}
```

```Output
German_Germany.1252 international grouping:
the 0th group to the left of the radix character is of size 3
German_Germany.1252 international frac_digits
to the right of the radix character: 2

German_Germany.1252 domestic grouping:
the 0th group to the left of the radix character is of size 3
German_Germany.1252 domestic frac_digits
to the right of the radix character: 2
```

## <a name="moneypunct"></a>  moneypunct::moneypunct

Construtor de objetos do tipo `moneypunct`.

```cpp
explicit moneypunct(size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: O tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: O tempo de vida do objeto deve ser gerenciado manualmente.

- \> 1: Esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com [locale::facet](../standard-library/locale-class.md#facet_class)(_ *Refs*).

## <a name="neg_format"></a>  moneypunct::neg_format

Retorna uma regra específica de localidade para formatação de saídas com valores negativos.

```cpp
pattern neg_format() const;
```

### <a name="return-value"></a>Valor de retorno

Uma regra específica de localidade para formatação de saídas com valores negativos.

### <a name="remarks"></a>Comentários

A função membro retorna [do_neg_format](#do_neg_format).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_neg_format.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>

using namespace std;

int main( ) {
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
      use_facet <moneypunct <char, true > >(loc);
   cout << loc.name( ) << " international negative number format: "
        << mpunct.neg_format( ).field[0]
        << mpunct.neg_format( ).field[1]
        << mpunct.neg_format( ).field[2]
        << mpunct.neg_format( ).field[3] << endl;

   const moneypunct <char, false> &mpunct2 =
      use_facet <moneypunct <char, false> >(loc);
   cout << loc.name( ) << " domestic negative number format: "
        << mpunct2.neg_format( ).field[0]
        << mpunct2.neg_format( ).field[1]
        << mpunct2.neg_format( ).field[2]
        << mpunct2.neg_format( ).field[3] << endl;
}
```

## <a name="negative_sign"></a>  moneypunct::negative_sign

Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.

```cpp
string_type negative_sign() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.

### <a name="remarks"></a>Comentários

A função membro retorna [do_negative_sign](#do_negative_sign).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_neg_sign.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>

using namespace std;

int main( )
{
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
      use_facet <moneypunct <char, true> >(loc);
   cout << loc.name( ) << " international negative sign: "
        << mpunct.negative_sign( ) << endl;

   const moneypunct <char, false> &mpunct2 =
      use_facet <moneypunct <char, false> >(loc);
   cout << loc.name( ) << " domestic negative sign: "
        << mpunct2.negative_sign( ) << endl;

   locale loc2( "French" );

   const moneypunct <char, true> &mpunct3 =
      use_facet <moneypunct <char, true> >(loc2);
   cout << loc2.name( ) << " international negative sign: "
        << mpunct3.negative_sign( ) << endl;

   const moneypunct <char, false> &mpunct4 =
      use_facet <moneypunct <char, false> >(loc2);
   cout << loc2.name( ) << " domestic negative sign: "
        << mpunct4.negative_sign( ) << endl;
};
```

```Output
German_Germany.1252 international negative sign: -
German_Germany.1252 domestic negative sign: -
French_France.1252 international negative sign: -
French_France.1252 domestic negative sign: -
```

## <a name="pos_format"></a>  moneypunct::pos_format

Retorna uma regra específica de localidade para formatação de saídas com valores positivos.

```cpp
pattern pos_format() const;
```

### <a name="return-value"></a>Valor de retorno

Uma regra específica de localidade para formatação de saídas com valores positivos.

### <a name="remarks"></a>Comentários

A função membro retorna [do_pos_format](#do_pos_format).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_pos_format.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
      use_facet <moneypunct <char, true> >(loc);
   cout << loc.name( ) << " international positive number format: "
        << mpunct.pos_format( ).field[0]
        << mpunct.pos_format( ).field[1]
        << mpunct.pos_format( ).field[2]
        << mpunct.pos_format( ).field[3] << endl;

   const moneypunct <char, false> &mpunct2 =
      use_facet <moneypunct <char, false> >(loc);
   cout << loc.name( ) << " domestic positive number format: "
        << mpunct2.pos_format( ).field[0]
        << mpunct2.pos_format( ).field[1]
        << mpunct2.pos_format( ).field[2]
        << mpunct2.pos_format( ).field[3] << endl;
}
```

## <a name="positive_sign"></a>  moneypunct::positive_sign

Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.

```cpp
string_type positive_sign() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.

### <a name="remarks"></a>Comentários

-A função membro retorna [do_positive_sign](#do_positive_sign).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_pos_sign.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>

using namespace std;

int main( )
{
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
      use_facet <moneypunct <char, true > >(loc);
   cout << loc.name( ) << " international positive sign:"
        << mpunct.positive_sign( ) << endl;

   const moneypunct <char, false> &mpunct2 =
      use_facet <moneypunct <char, false> >(loc);
   cout << loc.name( ) << " domestic positive sign:"
        << mpunct2.positive_sign( ) << endl;

   locale loc2( "French" );

   const moneypunct <char, true> &mpunct3 =
      use_facet <moneypunct <char, true> >(loc2);
   cout << loc2.name( ) << " international positive sign:"
        << mpunct3.positive_sign( ) << endl;

   const moneypunct <char, false> &mpunct4 =
      use_facet <moneypunct <char, false> >(loc2);
   cout << loc2.name( ) << " domestic positive sign:"
        << mpunct4.positive_sign( ) << endl;
};
```

```Output
German_Germany.1252 international positive sign:
German_Germany.1252 domestic positive sign:
French_France.1252 international positive sign:
French_France.1252 domestic positive sign:
```

## <a name="string_type"></a>  moneypunct::string_type

Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.

```cpp
typedef basic_string<CharType, Traits, Allocator> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das sequências de pontuação.

## <a name="thousands_sep"></a>  moneypunct::thousands_sep

Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de separador de milhares.

```cpp
CharType thousands_sep() const;
```

### <a name="return-value"></a>Valor de retorno

Uma sequência de elementos específica de localidade a ser usada como separador de milhares

### <a name="remarks"></a>Comentários

A função membro retorna [do_thousands_sep](#do_thousands_sep).

### <a name="example"></a>Exemplo

```cpp
// moneypunct_thou_sep.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   const moneypunct <char, true> &mpunct =
       use_facet <moneypunct <char, true > >(loc);
   cout << loc.name( ) << " international thousands separator: "
        << mpunct.thousands_sep( ) << endl;

   const moneypunct <char, false> &mpunct2 =
      use_facet <moneypunct <char, false> >(loc);
   cout << loc.name( ) << " domestic thousands separator: "
        << mpunct2.thousands_sep( ) << endl << endl;

   locale loc2( "english_canada" );

   const moneypunct <char, true> &mpunct3 =
       use_facet <moneypunct <char, true> >(loc2);
   cout << loc2.name( ) << " international thousands separator: "
        << mpunct3.thousands_sep( ) << endl;

   const moneypunct <char, false> &mpunct4 =
      use_facet <moneypunct <char, false> >(loc2);
   cout << loc2.name( ) << " domestic thousands separator: "
        << mpunct4.thousands_sep( ) << endl;
}
```

```Output
German_Germany.1252 international thousands separator: .
German_Germany.1252 domestic thousands separator: .

English_Canada.1252 international thousands separator: ,
English_Canada.1252 domestic thousands separator: ,
```

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
