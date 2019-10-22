---
title: '&lt;regex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <regex>
helpviewer_keywords:
- regex header
ms.assetid: 5dd4ef74-6063-4dbc-b692-1960bb736f0b
ms.openlocfilehash: 69adc738d5af3de5997e01c0f861400eb61f1712
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72686599"
---
# <a name="ltregexgt"></a>&lt;regex&gt;

Define um modelo de classe para analisar [expressões regularesC++()](../standard-library/regular-expressions-cpp.md)e vários modelos de classe e funções para Pesquisar texto em busca de correspondências com um objeto de expressão regular.

## <a name="syntax"></a>Sintaxe

```cpp
#include <regex>
```

## <a name="remarks"></a>Comentários

Para criar um objeto de expressão regular, use a [classe basic_regex](../standard-library/basic-regex-class.md) do modelo de classe ou uma de suas especializações, [Regex](../standard-library/regex-typedefs.md#regex) e [wregex](../standard-library/regex-typedefs.md#wregex), junto com os sinalizadores de sintaxe do tipo [regex_constants:: syntax_option_type](../standard-library/regex-constants-class.md#syntax_option_type).

Para Pesquisar texto referente a correspondências a um objeto de expressão regular, use as funções de modelo [regex_match](../standard-library/regex-functions.md#regex_match) e [regex_search](../standard-library/regex-functions.md#regex_search), junto com os sinalizadores de correspondência do tipo [regex_constants:: match_flag_type](../standard-library/regex-constants-class.md#match_flag_type). Essas funções retornam resultados usando a [Classe match_results](../standard-library/match-results-class.md) de modelo de classe e suas especializações, [cmatch](../standard-library/regex-typedefs.md#cmatch), [wcmatch](../standard-library/regex-typedefs.md#wcmatch), [smatch](../standard-library/regex-typedefs.md#smatch)e [wsmatch](../standard-library/regex-typedefs.md#wsmatch), junto com a [classe sub_match](../standard-library/sub-match-class.md) de modelo de classe e sua especializações, [csub_match](../standard-library/regex-typedefs.md#csub_match), [wcsub_match](../standard-library/regex-typedefs.md#wcsub_match), [ssub_match](../standard-library/regex-typedefs.md#ssub_match)e [wssub_match](../standard-library/regex-typedefs.md#wssub_match).

Para substituir o texto que corresponde a um objeto de expressão regular, use a função de modelo [regex_replace](../standard-library/regex-functions.md#regex_replace), junto com os sinalizadores de correspondência do tipo [regex_constants:: match_flag_type](../standard-library/regex-constants-class.md#match_flag_type).

Para iterar por meio de várias correspondências de um objeto de expressão regular, use a classe [regex_iterator](../standard-library/regex-iterator-class.md) Class templates e a [classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) ou uma de suas especializações, [cregex_iterator](../standard-library/regex-typedefs.md#cregex_iterator), [sregex_iterator](../standard-library/regex-typedefs.md#sregex_iterator), [ wcregex_iterator](../standard-library/regex-typedefs.md#wcregex_iterator), [wsregex_iterator](../standard-library/regex-typedefs.md#wsregex_iterator), [cregex_token_iterator](../standard-library/regex-typedefs.md#cregex_token_iterator), [sregex_token_iterator](../standard-library/regex-typedefs.md#sregex_token_iterator), [wcregex_token_iterator](../standard-library/regex-typedefs.md#wcregex_token_iterator)ou [wsregex_token_iterator](../standard-library/regex-typedefs.md#wsregex_token_iterator), junto com os sinalizadores de correspondência do tipo [regex_ constantes:: match_flag_type](../standard-library/regex-constants-class.md#match_flag_type).

Para modificar os detalhes da gramática de expressões regulares, grave uma classe que implementa as características da expressão regular.

### <a name="classes"></a>Classes

|Class|Descrição|
|-|-|
|[basic_regex](../standard-library/basic-regex-class.md)|Encapsula uma expressão regular.|
|[match_results](../standard-library/match-results-class.md)|Contém uma sequência de subcorrespondências.|
|[regex_constants](../standard-library/regex-constants-class.md)|Retém as constantes sortidas.|
|[regex_error](../standard-library/regex-error-class.md)|Relata uma expressão regular inválida.|
|[regex_iterator](../standard-library/regex-iterator-class.md)|Itera os resultados de correspondência.|
|[regex_traits](../standard-library/regex-traits-class.md)|Descreve as características dos elementos de correspondência.|
|[regex_traits\<char>](../standard-library/regex-traits-char-class.md)|Descreve as características do **Char** para correspondência.|
|[regex_traits<wchar_t>](../standard-library/regex-traits-wchar-t-class.md)|Descreve as características do **wchar_t** para correspondência.|
|[regex_token_iterator](../standard-library/regex-token-iterator-class.md)|Itera as subcorrespondências.|
|[sub_match](../standard-library/sub-match-class.md)|Descreve uma subcorrespondência.|

### <a name="type-definitions"></a>Definições de tipo

|||
|-|-|
|[cmatch](../standard-library/regex-typedefs.md#cmatch)|Definição de tipo para `match_results` de **caracteres** .|
|[cregex_iterator](../standard-library/regex-typedefs.md#cregex_iterator)|Definição de tipo para `regex_iterator` de **caracteres** .|
|[cregex_token_iterator](../standard-library/regex-typedefs.md#cregex_token_iterator)|Definição de tipo para `regex_token_iterator` de **caracteres** .|
|[csub_match](../standard-library/regex-typedefs.md#csub_match)|Definição de tipo para `sub_match` de **caracteres** .|
|[regex](../standard-library/regex-typedefs.md#regex)|Definição de tipo para `basic_regex` de **caracteres** .|
|[smatch](../standard-library/regex-typedefs.md#smatch)|Definição de tipo para `match_results` de `string`.|
|[sregex_iterator](../standard-library/regex-typedefs.md#sregex_iterator)|Definição de tipo para `regex_iterator` de `string`.|
|[sregex_token_iterator](../standard-library/regex-typedefs.md#sregex_token_iterator)|Definição de tipo para `regex_token_iterator` de `string`.|
|[ssub_match](../standard-library/regex-typedefs.md#ssub_match)|Definição de tipo para `sub_match` de `string`.|
|[wcmatch](../standard-library/regex-typedefs.md#wcmatch)|Definição de tipo para `match_results` de **wchar_t** .|
|[wcregex_iterator](../standard-library/regex-typedefs.md#wcregex_iterator)|Definição de tipo para `regex_iterator` de **wchar_t** .|
|[wcregex_token_iterator](../standard-library/regex-typedefs.md#wcregex_token_iterator)|Definição de tipo para `regex_token_iterator` de **wchar_t** .|
|[wcsub_match](../standard-library/regex-typedefs.md#wcsub_match)|Definição de tipo para `sub_match` de **wchar_t** .|
|[wregex](../standard-library/regex-typedefs.md#wregex)|Definição de tipo para `basic_regex` de **wchar_t** .|
|[wsmatch](../standard-library/regex-typedefs.md#wsmatch)|Definição de tipo para `match_results` de `wstring`.|
|[wsregex_iterator](../standard-library/regex-typedefs.md#wsregex_iterator)|Definição de tipo para `regex_iterator` de `wstring`.|
|[wsregex_token_iterator](../standard-library/regex-typedefs.md#wsregex_token_iterator)|Definição de tipo para `regex_token_iterator` de `wstring`.|
|[wssub_match](../standard-library/regex-typedefs.md#wssub_match)|Definição de tipo para `sub_match` de `wstring`.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[regex_match](../standard-library/regex-functions.md#regex_match)|Corresponde exatamente a uma expressão regular.|
|[regex_replace](../standard-library/regex-functions.md#regex_replace)|Substitui expressões regulares correspondentes.|
|[regex_search](../standard-library/regex-functions.md#regex_search)|Pesquisa por uma correspondência de expressão regular.|
|[swap](../standard-library/regex-functions.md#swap)|Alterna objetos `basic_regex` ou `match_results`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator==](../standard-library/regex-operators.md#op_eq_eq)|Comparação de vários objetos, é igual a.|
|[operator!=](../standard-library/regex-operators.md#op_neq)|Comparação de vários objetos, não é igual a.|
|[operator<](../standard-library/regex-operators.md#op_lt)|Comparação de vários objetos, menor que.|
|[operator\<=](../standard-library/regex-operators.md#op_gt_eq)|Comparação de vários objetos, menor ou igual a.|
|[operator>](../standard-library/regex-operators.md#op_gt)|Comparação de vários objetos, maior que.|
|[operator>=](../standard-library/regex-operators.md#op_gt_eq)|Comparação de vários objetos, maior ou igual a.|
|[operator<<](../standard-library/regex-operators.md#op_lt_lt)|Insere um `sub_match` em um fluxo.|

## <a name="see-also"></a>Consulte também

[Expressões regulares (C++)](../standard-library/regular-expressions-cpp.md) \
\ [classe regex_constants](../standard-library/regex-constants-class.md)
\ [classe regex_error](../standard-library/regex-error-class.md)
[\<regex > funções](../standard-library/regex-functions.md) \
\ [Classe regex_iterator](../standard-library/regex-iterator-class.md)
[operadores de > de \<regex](../standard-library/regex-operators.md) \
\ [classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)
\ [Classe regex_traits](../standard-library/regex-traits-class.md)
[\<Typedef regex>](../standard-library/regex-typedefs.md)
