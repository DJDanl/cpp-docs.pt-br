---
title: '&lt;regex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <regex>
helpviewer_keywords:
- regex header
ms.assetid: 5dd4ef74-6063-4dbc-b692-1960bb736f0b
ms.openlocfilehash: 60548e96e0922fdcff00456b03bf9fa15bb7e3b3
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841474"
---
# <a name="ltregexgt"></a>&lt;regex&gt;

Define um modelo de classe para analisar [expressões regulares (C++)](../standard-library/regular-expressions-cpp.md)e vários modelos de classe e funções para Pesquisar texto para correspondências com um objeto de expressão regular.

## <a name="syntax"></a>Sintaxe

```cpp
#include <regex>
```

## <a name="remarks"></a>Comentários

Para criar um objeto de expressão regular, use o modelo de classe [Basic_regex classe](../standard-library/basic-regex-class.md) ou uma de suas especializações, [Regex](../standard-library/regex-typedefs.md#regex) e [wregex](../standard-library/regex-typedefs.md#wregex), junto com os sinalizadores de sintaxe do tipo [regex_constants:: syntax_option_type](../standard-library/regex-constants-class.md#syntax_option_type).

Para Pesquisar texto referente a correspondências a um objeto de expressão regular, use as funções de modelo [regex_match](../standard-library/regex-functions.md#regex_match) e [regex_search](../standard-library/regex-functions.md#regex_search), junto com os sinalizadores de correspondência do tipo [regex_constants:: match_flag_type](../standard-library/regex-constants-class.md#match_flag_type). Essas funções retornam resultados usando o modelo de classe [Match_results classe](../standard-library/match-results-class.md) e suas especializações, [cmatch](../standard-library/regex-typedefs.md#cmatch), [wcmatch](../standard-library/regex-typedefs.md#wcmatch), [smatch](../standard-library/regex-typedefs.md#smatch)e [wsmatch](../standard-library/regex-typedefs.md#wsmatch), junto com o modelo de [classe sub_match classe](../standard-library/sub-match-class.md) e suas especializações, [csub_match](../standard-library/regex-typedefs.md#csub_match), [wcsub_match](../standard-library/regex-typedefs.md#wcsub_match), [ssub_match](../standard-library/regex-typedefs.md#ssub_match)e [wssub_match](../standard-library/regex-typedefs.md#wssub_match).

Para substituir o texto que corresponde a um objeto de expressão regular, use a função de modelo [regex_replace](../standard-library/regex-functions.md#regex_replace), junto com os sinalizadores de correspondência do tipo [regex_constants:: match_flag_type](../standard-library/regex-constants-class.md#match_flag_type).

Para iterar por meio de várias correspondências de um objeto de expressão regular, use os modelos de classe [regex_iterator](../standard-library/regex-iterator-class.md) classe e [regex_token_iterator classe](../standard-library/regex-token-iterator-class.md) ou uma de suas especializações, [cregex_iterator](../standard-library/regex-typedefs.md#cregex_iterator), [sregex_iterator](../standard-library/regex-typedefs.md#sregex_iterator), [wcregex_iterator](../standard-library/regex-typedefs.md#wcregex_iterator), [wsregex_iterator](../standard-library/regex-typedefs.md#wsregex_iterator), [cregex_token_iterator](../standard-library/regex-typedefs.md#cregex_token_iterator), [sregex_token_iterator](../standard-library/regex-typedefs.md#sregex_token_iterator), [wcregex_token_iterator](../standard-library/regex-typedefs.md#wcregex_token_iterator)ou [wsregex_token_iterator](../standard-library/regex-typedefs.md#wsregex_token_iterator), junto com os sinalizadores de correspondência do tipo [regex_constants:: match_flag_type](../standard-library/regex-constants-class.md#match_flag_type).

Para modificar os detalhes da gramática de expressões regulares, grave uma classe que implementa as características da expressão regular.

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_regex](../standard-library/basic-regex-class.md)|Encapsula uma expressão regular.|
|[match_results](../standard-library/match-results-class.md)|Contém uma sequência de subcorrespondências.|
|[regex_constants](../standard-library/regex-constants-class.md)|Retém as constantes sortidas.|
|[regex_error](../standard-library/regex-error-class.md)|Relata uma expressão regular inválida.|
|[regex_iterator](../standard-library/regex-iterator-class.md)|Itera os resultados de correspondência.|
|[regex_traits](../standard-library/regex-traits-class.md)|Descreve as características dos elementos de correspondência.|
|[regex_traits\<char>](../standard-library/regex-traits-char-class.md)|Descreve as características de **`char`** para correspondência.|
|[regex_traits<wchar_t>](../standard-library/regex-traits-wchar-t-class.md)|Descreve as características de **`wchar_t`** para correspondência.|
|[regex_token_iterator](../standard-library/regex-token-iterator-class.md)|Itera as subcorrespondências.|
|[sub_match](../standard-library/sub-match-class.md)|Descreve uma subcorrespondência.|

### <a name="type-definitions"></a>Definições de tipo

|Nome|Descrição|
|-|-|
|[cmatch](../standard-library/regex-typedefs.md#cmatch)|Definição de tipo para **`char`** `match_results` .|
|[cregex_iterator](../standard-library/regex-typedefs.md#cregex_iterator)|Definição de tipo para **`char`** `regex_iterator` .|
|[cregex_token_iterator](../standard-library/regex-typedefs.md#cregex_token_iterator)|Definição de tipo para **`char`** `regex_token_iterator` .|
|[csub_match](../standard-library/regex-typedefs.md#csub_match)|Definição de tipo para **`char`** `sub_match` .|
|[Regex](../standard-library/regex-typedefs.md#regex)|Definição de tipo para **`char`** `basic_regex` .|
|[smatch](../standard-library/regex-typedefs.md#smatch)|Definição de tipo para `string` `match_results`.|
|[sregex_iterator](../standard-library/regex-typedefs.md#sregex_iterator)|Definição de tipo para `string` `regex_iterator`.|
|[sregex_token_iterator](../standard-library/regex-typedefs.md#sregex_token_iterator)|Definição de tipo para `string` `regex_token_iterator`.|
|[ssub_match](../standard-library/regex-typedefs.md#ssub_match)|Definição de tipo para `string` `sub_match`.|
|[wcmatch](../standard-library/regex-typedefs.md#wcmatch)|Definição de tipo para **`wchar_t`** `match_results` .|
|[wcregex_iterator](../standard-library/regex-typedefs.md#wcregex_iterator)|Definição de tipo para **`wchar_t`** `regex_iterator` .|
|[wcregex_token_iterator](../standard-library/regex-typedefs.md#wcregex_token_iterator)|Definição de tipo para **`wchar_t`** `regex_token_iterator` .|
|[wcsub_match](../standard-library/regex-typedefs.md#wcsub_match)|Definição de tipo para **`wchar_t`** `sub_match` .|
|[wregex](../standard-library/regex-typedefs.md#wregex)|Definição de tipo para **`wchar_t`** `basic_regex` .|
|[wsmatch](../standard-library/regex-typedefs.md#wsmatch)|Definição de tipo para `wstring` `match_results`.|
|[wsregex_iterator](../standard-library/regex-typedefs.md#wsregex_iterator)|Definição de tipo para `wstring` `regex_iterator`.|
|[wsregex_token_iterator](../standard-library/regex-typedefs.md#wsregex_token_iterator)|Definição de tipo para `wstring` `regex_token_iterator`.|
|[wssub_match](../standard-library/regex-typedefs.md#wssub_match)|Definição de tipo para `wstring` `sub_match`.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[regex_match](../standard-library/regex-functions.md#regex_match)|Corresponde exatamente a uma expressão regular.|
|[regex_replace](../standard-library/regex-functions.md#regex_replace)|Substitui expressões regulares correspondentes.|
|[regex_search](../standard-library/regex-functions.md#regex_search)|Pesquisa por uma correspondência de expressão regular.|
|[permuta](../standard-library/regex-functions.md#swap)|Alterna objetos `basic_regex` ou `match_results`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador = =](../standard-library/regex-operators.md#op_eq_eq)|Comparação de vários objetos, é igual a.|
|[operador! =](../standard-library/regex-operators.md#op_neq)|Comparação de vários objetos, não é igual a.|
|[<do operador ](../standard-library/regex-operators.md#op_lt)|Comparação de vários objetos, menor que.|
|[operador\<=](../standard-library/regex-operators.md#op_gt_eq)|Comparação de vários objetos, menor ou igual a.|
|[>do operador ](../standard-library/regex-operators.md#op_gt)|Comparação de vários objetos, maior que.|
|[>do operador =](../standard-library/regex-operators.md#op_gt_eq)|Comparação de vários objetos, maior ou igual a.|
|[<<do operador ](../standard-library/regex-operators.md#op_lt_lt)|Insere um `sub_match` em um fluxo.|

## <a name="see-also"></a>Confira também

[Expressões regulares (C++)](../standard-library/regular-expressions-cpp.md)\
[Classe regex_constants](../standard-library/regex-constants-class.md)\
[Classe regex_error](../standard-library/regex-error-class.md)\
[\<regex> funções](../standard-library/regex-functions.md)\
[Classe regex_iterator](../standard-library/regex-iterator-class.md)\
[\<regex> operações](../standard-library/regex-operators.md)\
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)\
[Classe regex_traits](../standard-library/regex-traits-class.md)\
[\<regex> TYPEDEFs](../standard-library/regex-typedefs.md)
