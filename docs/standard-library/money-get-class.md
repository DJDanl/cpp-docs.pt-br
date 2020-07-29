---
title: Classe money_get
ms.date: 11/04/2016
f1_keywords:
- xlocmon/std::money_get
- xlocmon/std::money_get::char_type
- xlocmon/std::money_get::iter_type
- xlocmon/std::money_get::string_type
- xlocmon/std::money_get::do_get
- xlocmon/std::money_get::get
helpviewer_keywords:
- std::money_get [C++]
- std::money_get [C++], char_type
- std::money_get [C++], iter_type
- std::money_get [C++], string_type
- std::money_get [C++], do_get
- std::money_get [C++], get
ms.assetid: 692d3374-3fe7-4b46-8aeb-f8d91ed66b2e
ms.openlocfilehash: ab49dad1a24e57eb33834cc651d9ccdb50abe68c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224754"
---
# <a name="money_get-class"></a>Classe money_get

O modelo de classe descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo `CharType` para valores monetários.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class InputIterator = istreambuf_iterator<CharType>>
class money_get : public locale::facet;
```

### <a name="parameters"></a>parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres em uma localidade.

*InputIterator*\
O tipo de iterador do qual as funções get leem sua entrada.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[money_get](#money_get)|O construtor para objetos do tipo `money_get` que são usados para extrair valores numéricos das sequências que representam valores monetários.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[iter_type](#iter_type)|Um tipo que descreve um iterador de entrada.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[do_get](#do_get)|Uma função virtual chamada para extrair um valor numérico de uma sequência de caracteres que representa um valor monetário.|
|[get](#get)|Extrai um valor numérico de uma sequência de caracteres que representa um valor monetário.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<locale>

**Namespace:** std

## <a name="money_getchar_type"></a><a name="char_type"></a>money_get:: char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *CharType*.

## <a name="money_getdo_get"></a><a name="do_get"></a>money_get::d o_get

Uma função virtual chamada para extrair um valor numérico de uma sequência de caracteres que representa um valor monetário.

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    bool Intl,
    ios_base& Iosbase,
    ios_base::iostate& State,
    long double& val) const virtual iter_type do_get(iter_type first,
    iter_type last,
    bool Intl,
    ios_base& Iosbase,
    ios_base::iostate& State,
    string_type& val) const
```

### <a name="parameters"></a>parâmetros

*primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*Intl*\
Um valor booliano que indica o tipo de símbolo de moeda esperado na sequência: **`true`** se **`false`** for internacional, se for doméstico.

*Iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Status*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas ou não.

*Val*\
Uma cadeia de caracteres que armazena a sequência convertida.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada monetário.

### <a name="remarks"></a>Comentários

A primeira função membro virtual protegida virtual tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [ `first`, `last`) até ter reconhecido um campo de entrada monetária completo e não vazio. Se for bem-sucedido, ele converterá esse campo em uma sequência de um ou mais dígitos decimais, opcionalmente precedido por um sinal de menos ( `-` ), para representar o valor e armazenará o resultado no objeto [string_type](#string_type) *Val*. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada monetário. Caso contrário, a função armazena uma sequência vazia em *Val* e define `ios_base::failbit` no *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada monetário válido. Em ambos os casos, se o valor retornado for igual a `last`, a função definirá `ios_base::eofbit` em `State`.

A segunda função de membro protegido virtual se comporta da mesma forma que a primeira, exceto que, se for bem-sucedida, ela converterá a sequência de dígitos assinada opcionalmente em um valor do tipo **`long double`** e armazenará esse valor em *Val*.

O formato de um campo de entrada monetária é determinado pela [faceta de localidade](../standard-library/locale-class.md#facet_class)**fac** retornada pela chamada efetiva [use_facet](../standard-library/locale-functions.md#use_facet)  <  [moneypunct](../standard-library/moneypunct-class.md) \< **CharType**, **intl**>> ( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)).

Especificamente:

- **fac**. [neg_format](../standard-library/moneypunct-class.md#neg_format) determina a ordem na qual os componentes do campo ocorrem.

- **fac**. [curr_symbol](../standard-library/moneypunct-class.md#curr_symbol) determina a sequência de elementos que constitui um símbolo de moeda.

- **fac**. [positive_sign](../standard-library/moneypunct-class.md#positive_sign) determina a sequência de elementos que constitui um sinal positivo.

- **fac**. [negative_sign](../standard-library/moneypunct-class.md#negative_sign) determina a sequência de elementos que constitui um sinal negativo.

- **fac**. [grouping](../standard-library/moneypunct-class.md#grouping) determina como os dígitos são agrupados à esquerda da vírgula decimal.

- **fac**. [thousands_sep](../standard-library/moneypunct-class.md#thousands_sep) determina o elemento que separa grupos de dígitos à esquerda da vírgula decimal.

- **fac**. [decimal_point](../standard-library/moneypunct-class.md#decimal_point) determina o elemento que separa os dígitos de inteiros dos dígitos de fração.

- **fac**. [frac_digits](../standard-library/moneypunct-class.md#frac_digits) determina o número de dígitos de fração significativa à direita de qualquer vírgula decimal. Ao analisar um valor monetário com mais dígitos de fração do são chamados por `frac_digits`, `do_get` para de analisar após consumir no máximo `frac_digits` caracteres.

Se a cadeia de caracteres de sinal (**fac**. `negative_sign` ou **fac**. `positive_sign`) tiver mais de um elemento, apenas o primeiro elemento correspondido onde o elemento for igual a **money_base::sign** aparecerá no padrão do formato (**fac**. `neg_format`). Todos os elementos restantes são comparados ao final do campo de entrada monetário. Se nenhuma cadeia de caracteres tiver um primeiro elemento que corresponde ao próximo elemento no campo de entrada monetário, a cadeia de caracteres com sinal será assumida como vazia e o sinal positivo.

Se **iosbase**. [sinalizadores](../standard-library/ios-base-class.md#flags)  &  de o [defaultbase](../standard-library/ios-functions.md#showbase) é diferente de zero, a cadeia de caracteres **fac**. `curr_symbol` deverá corresponder onde o elemento igual a **money_base::symbol** aparece no padrão do formato. Caso contrário, se **money_base::symbol** ocorrer no final do padrão de formato e se nenhum elemento da sequência de caracteres com sinal continuar a ser correspondido, o símbolo de moeda não será correspondente. Caso contrário, o símbolo de moeda é opcionalmente correspondente.

Se nenhuma instância de **fac**. `thousands_sep` ocorrer na parte de valor do campo de entrada monetário (em que o elemento igual a **money_base::value** aparece no padrão de formato), não serão impostas restrições de agrupamento. Caso contrário, qualquer restrição de agrupamento é imposta por **fac**. **grouping** é imposta. Observe que a sequência de dígitos resultante representa um inteiro cujos dígitos decimais **fac**. `frac_digits` de ordem baixa são considerados à direita da vírgula decimal.

O espaço em branco arbitrário é correspondido onde o elemento igual a **money_base::space** aparece no padrão de formato, se ele aparecer em um local que não o final do padrão de formato. Caso contrário, nenhum espaço em branco interno é correspondente. Um elemento *ch* é considerado espaço em branco se [use_facet](../standard-library/locale-functions.md#use_facet)  <  [CType](../standard-library/ctype-class.md) \< **CharType**> > ( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)). [é](../standard-library/ctype-class.md#is)( **ctype_base:: Space**, *ch*) é **`true`** .

### <a name="example"></a>Exemplo

Consulte o exemplo de [get](#get), que chama `do_get`.

## <a name="money_getget"></a><a name="get"></a>money_get:: Get

Extrai um valor numérico de uma sequência de caracteres que representa um valor monetário.

```cpp
iter_type get(iter_type first,
    iter_type last,
    bool Intl,
    ios_base& Iosbase,
    ios_base::iostate& State,
    long double& val) const;

iter_type get(iter_type first,
    iter_type last,
    bool Intl,
    ios_base& Iosbase,
    ios_base::iostate& State,
    string_type& val) const;
```

### <a name="parameters"></a>parâmetros

*primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*Intl*\
Um valor booliano que indica o tipo de símbolo de moeda esperado na sequência: **`true`** se **`false`** for internacional, se for doméstico.

*Iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório

*Status*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Val*\
Uma cadeia de caracteres que armazena a sequência convertida.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada monetário.

### <a name="remarks"></a>Comentários

Ambas as funções de membro retornam [do_get](#do_get) `(first, last, Intl, Iosbase, State, val)` .

### <a name="example"></a>Exemplo

```cpp
// money_get_get.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;

int main( )
{
   locale loc( "german_germany" );

   basic_stringstream< char > psz;
   psz << use_facet<moneypunct<char, 1> >(loc).curr_symbol() << "-1.000,56";
   basic_stringstream< char > psz2;
   psz2 << "-100056" << use_facet<moneypunct<char, 1> >(loc).curr_symbol();

   ios_base::iostate st = 0;
   long double fVal;

   psz.flags( psz.flags( )|ios_base::showbase );
   // Which forced the READING the currency symbol
   psz.imbue(loc);
   use_facet < money_get < char > >( loc ).
      get( basic_istream<char>::_Iter( psz.rdbuf( ) ),
           basic_istream<char>::_Iter( 0 ), true, psz, st, fVal );

   if ( st & ios_base::failbit )
      cout << "money_get(" << psz.str( ) << ", intl = 1) FAILED"
           << endl;
   else
      cout << "money_get(" << psz.str( ) << ", intl = 1) = "
           << fVal/100.0 << endl;

   use_facet < money_get < char > >( loc ).
      get(basic_istream<char>::_Iter(psz2.rdbuf( )),
          basic_istream<char>::_Iter(0), false, psz2, st, fVal);

   if ( st & ios_base::failbit )
      cout << "money_get(" << psz2.str( ) << ", intl = 0) FAILED"
           << endl;
   else
      cout << "money_get(" << psz2.str( ) << ", intl = 0) = "
           << fVal/100.0 << endl;
};
```

## <a name="money_getiter_type"></a><a name="iter_type"></a>money_get:: iter_type

Um tipo que descreve um iterador de entrada.

```cpp
typedef InputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **InputIterator**.

## <a name="money_getmoney_get"></a><a name="money_get"></a>money_get:: money_get

O construtor para objetos do tipo `money_get` que são usados para extrair valores numéricos das sequências que representam valores monetários.

```cpp
explicit money_get(size_t _Refs = 0);
```

### <a name="parameters"></a>parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::**[faceta](../standard-library/locale-class.md#facet_class)(*_Refs*).

## <a name="money_getstring_type"></a><a name="string_type"></a>money_get:: string_type

Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.

```cpp
typedef basic_string<CharType, Traits, Allocator> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md).

## <a name="see-also"></a>Confira também

[\<locale>](../standard-library/locale.md)\
[Classe de faceta](../standard-library/locale-class.md#facet_class)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
