---
title: Classe money_put
ms.date: 11/01/2018
f1_keywords:
- xlocmon/std::money_put
- xlocmon/std::money_put::char_type
- xlocmon/std::money_put::iter_type
- xlocmon/std::money_put::string_type
- xlocmon/std::money_put::do_put
- xlocmon/std::money_put::put
helpviewer_keywords:
- std::money_put [C++]
- std::money_put [C++], char_type
- std::money_put [C++], iter_type
- std::money_put [C++], string_type
- std::money_put [C++], do_put
- std::money_put [C++], put
ms.assetid: f439fd56-c9b1-414c-95e1-66c918c6eee6
ms.openlocfilehash: aafa6f9498ee315c25e73833baf3c13d99d36743
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689309"
---
# <a name="money_put-class"></a>Classe money_put

O modelo de classe descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores monetários em sequências do tipo `CharType`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType,
    class OutputIterator = ostreambuf_iterator<CharType>>
class money_put : public locale::facet;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *CharType*
O tipo usado em um programa para codificar caracteres em uma localidade.

@No__t_1 *OutputIterator*
O tipo de iterador para o qual as funções put monetárias gravam sua saída.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[money_put](#money_put)|O construtor para objetos do tipo `money_put`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[iter_type](#iter_type)|Um tipo que descreve um iterador de saída.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[do_put](#do_put)|Uma função virtual chamada para converter o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.|
|[put](#put)|Converte o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="char_type"></a>  money_put::char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **CharType**.

## <a name="do_put"></a>  money_put::do_put

Uma função virtual chamada para converter o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.

```cpp
virtual iter_type do_put(
    iter_type next,
    bool _Intl,
    ios_base& _Iosbase,
    CharType _Fill,
    const string_type& val) const;

virtual iter_type do_put(
    iter_type next,
    bool _Intl,
    ios_base& _Iosbase,
    CharType _Fill,
    long double val) const;
```

### <a name="parameters"></a>Parâmetros

*próximo* \
Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.

@No__t_1 *_Intl*
Um valor booliano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacional, **false** se nacional.

@No__t_1 *_Iosbase*
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório

@No__t_1 *_Fill*
Um caractere que é usado para espaçamento.

*valor* \
Um objeto de cadeia de caracteres a ser convertido.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda uma posição além do último elemento produzido.

### <a name="remarks"></a>Comentários

A primeira função de membro virtual protegido gera elementos sequenciais começando em *Next* para produzir um campo de saída monetária do *valor*do objeto [string_type](#string_type) . A sequência controlada por *Val* deve começar com um ou mais dígitos decimais, opcionalmente precedido por um sinal de subtração (-), que representa o valor. A função retorna um iterador que designa o primeiro elemento além do campo de saída monetário gerado.

A segunda função de membro virtual protegido comporta-se da mesma forma que a primeira, exceto que primeiro converte o *Val* em uma sequência de dígitos decimais, opcionalmente precedido por um sinal de subtração e converte essa sequência como acima.

O formato de um campo de saída monetário é determinado pelo [locale facet](../standard-library/locale-class.md#facet_class) fac retornado pela chamada (efetiva) [use_facet](../standard-library/locale-functions.md#use_facet) < [moneypunct](../standard-library/moneypunct-class.md)\< **CharType**, **intl**> >( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)).

Especificamente:

- **fac**. [pos_format](../standard-library/moneypunct-class.md#pos_format) determina a ordem na qual os componentes do campo são gerados para um valor não negativo.

- **fac**. [neg_format](../standard-library/moneypunct-class.md#neg_format) determina a ordem na qual os componentes do campo são gerados para um valor negativo.

- **fac**. [curr_symbol](../standard-library/moneypunct-class.md#curr_symbol) determina a sequência de elementos a ser gerada para um símbolo de moeda.

- **fac**. [positive_sign](../standard-library/moneypunct-class.md#positive_sign) determina a sequência de elementos a ser gerada para um sinal positivo.

- **fac**. [negative_sign](../standard-library/moneypunct-class.md#negative_sign) determina a sequência de elementos a ser gerada para um sinal negativo.

- **fac**. [grouping](../standard-library/moneypunct-class.md#grouping) determina como os dígitos são agrupados à esquerda da vírgula decimal.

- **fac**. [thousands_sep](../standard-library/moneypunct-class.md#thousands_sep) determina o elemento que separa grupos de dígitos à esquerda da vírgula decimal.

- **fac**. [decimal_point](../standard-library/moneypunct-class.md#decimal_point) determina a sequência que separa os dígitos de inteiros de qualquer dígito de fração.

- **fac**. [frac_digits](../standard-library/moneypunct-class.md#frac_digits) determina o número de dígitos de fração significativa à direita de qualquer vírgula decimal.

Se a cadeia de caracteres de sinal (**fac**. `negative_sign` ou **fac**. `positive_sign`) tiver mais de um elemento, apenas o primeiro elemento gerado quando o elemento for igual a **money_base::sign** aparecerá no padrão do formato (**fac**. `neg_format` ou **fac**. `pos_format`). Todos os elementos restantes são gerados ao final do campo de saída monetário.

Se **iosbase**. [flags](../standard-library/ios-base-class.md#flags) & [showbase](../standard-library/ios-functions.md#showbase) for diferente de zero, a cadeia de caracteres **fac**. `curr_symbol` será gerada quando o elemento igual a **money_base::symbol** aparece no padrão do formato. Caso contrário, nenhum símbolo de moeda será gerado.

Se nenhuma restrição de agrupamento for imposta por **fac**. **grouping** (o primeiro elemento tem o valor CHAR_MAX), então não há instâncias de **fac**. `thousands_sep` são gerados na parte de valor do campo de saída monetário (em que o elemento igual a **money_base::value** aparece no padrão de formato). Se **fac**. `frac_digits` for zero, nenhuma instância de **fac**. `decimal_point` será gerada após os dígitos decimais. Caso contrário, o campo de saída monetário resultante colocará os dígitos decimais **fac**. `frac_digits` de ordem baixa à direita da vírgula decimal.

O preenchimento ocorre para qualquer campo de saída numérico, exceto se **iosbase**. **flags** & **iosbase**. [internal](../standard-library/ios-functions.md#internal) for diferente de zero, o preenchimento será gerado quando o elemento igual a **money_base::space** aparece no padrão de formato, se ele aparecer. Caso contrário, o preenchimento interno ocorrerá antes da sequência gerada. O caractere de preenchimento é **fill**.

A função chama **iosbase**. **width**(0) para redefinir a largura do campo como zero.

### <a name="example"></a>Exemplo

Veja o exemplo de [put](#put), em que a função membro virtual é chamada por **put**.

## <a name="iter_type"></a>  money_put::iter_type

Um tipo que descreve um iterador de saída.

```cpp
typedef OutputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **OutputIterator.**

## <a name="money_put"></a>  money_put::money_put

O construtor para objetos do tipo `money_put`.

```cpp
explicit money_put(size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *_Refs*
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \> 1: esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::** [facet](../standard-library/locale-class.md#facet_class)( `_Refs`).

## <a name="put"></a>  money_put::put

Converte o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.

```cpp
iter_type put(
    iter_type next,
    bool _Intl,
    ios_base& _Iosbase,
    CharType _Fill,
    const string_type& val) const;

iter_type put(
    iter_type next,
    bool _Intl,
    ios_base& _Iosbase,
    CharType _Fill,
    long double val) const;
```

### <a name="parameters"></a>Parâmetros

*próximo* \
Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.

@No__t_1 *_Intl*
Um valor booliano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacional, **false** se nacional.

@No__t_1 *_Iosbase*
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório

@No__t_1 *_Fill*
Um caractere que é usado para espaçamento.

*valor* \
Um objeto de cadeia de caracteres a ser convertido.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda uma posição além do último elemento produzido.

### <a name="remarks"></a>Comentários

Ambas as funções membro retornam [do_put](#do_put)( `next`, `_Intl`, `_Iosbase`, `_Fill`, `val`).

### <a name="example"></a>Exemplo

```cpp
// money_put_put.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>

int main()
{
    std::locale loc( "german_germany" );
    std::basic_stringstream<char> psz;

    psz.imbue(loc);
    psz.flags(psz.flags() | std::ios_base::showbase); // force the printing of the currency symbol
    std::use_facet<std::money_put<char> >(loc).put(std::basic_ostream<char>::_Iter(psz.rdbuf()), true, psz, ' ', 100012);
    if (psz.fail())
        std::cout << "money_put() FAILED" << std::endl;
    else
        std::cout << "money_put() = \"" << psz.rdbuf()->str() << "\"" << std::endl;
}
```

```Output
money_put() = "EUR1.000,12"
```

## <a name="string_type"></a>  money_put::string_type

Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.

```cpp
typedef basic_string<CharType, Traits, Allocator> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar sequências de elementos da sequência de origem.

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)\
[Classe facet](../standard-library/locale-class.md#facet_class)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
