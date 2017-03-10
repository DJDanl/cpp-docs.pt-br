---
title: '&lt;regex&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <regex>
dev_langs:
- C++
helpviewer_keywords:
- regex header
ms.assetid: 5dd4ef74-6063-4dbc-b692-1960bb736f0b
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 248e9ba676b906af62f6804f4939e04158a8e2ef
ms.openlocfilehash: 4e172f8bf72fd528027c333cf411a307aa97d786
ms.lasthandoff: 02/25/2017

---
# <a name="ltregexgt"></a>&lt;regex&gt;
Define uma classe de modelo para analisar [Expressões Regulares (C++)](../standard-library/regular-expressions-cpp.md) e várias classes de modelo e funções para pesquisar no texto correspondências de um objeto de expressão regular.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <regex>  
```  
  
## <a name="remarks"></a>Comentários  
 Para criar um objeto de expressão regular, use a classe de modelo [Classe basic_regex](../standard-library/basic-regex-class.md) ou uma de suas especializações, [regex](../standard-library/regex-typedefs.md#regex_typedef) e [wregex](../standard-library/regex-typedefs.md#wregex_typedef), junto com os sinalizadores de sintaxe do tipo [regex_constants::syntax_option_type](../standard-library/regex-constants-class.md#regex_constants__syntax_option_type).  
  
 Para pesquisar correspondências a um objeto de expressão regular no texto, use as funções de modelo [Função regex_match](../standard-library/regex-functions.md#regex_match_function) e [Função regex_search](../standard-library/regex-functions.md#regex_search_function), junto com os sinalizadores de correspondência do tipo [regex_constants::match_flag_type](../standard-library/regex-constants-class.md#regex_constants__match_flag_type). Essas funções retornam resultados usando a classe de modelo [match_results Class](../standard-library/match-results-class.md) e suas especializações, [cmatch](../standard-library/regex-typedefs.md#cmatch_typedef), [wcmatch](../standard-library/regex-typedefs.md#wcmatch_typedef), [smatch](../standard-library/regex-typedefs.md#smatch_typedef) e [wsmatch](../standard-library/regex-typedefs.md#wsmatch_typedef), junto com a classe de modelo [sub_match Class](../standard-library/sub-match-class.md) e suas especializações, [csub_match](../standard-library/regex-typedefs.md#csub_match_typedef), [wcsub_match](../standard-library/regex-typedefs.md#wcsub_match_typedef), [ssub_match](../standard-library/regex-typedefs.md#ssub_match_typedef) e [wssub_match](../standard-library/regex-typedefs.md#wssub_match_typedef).  
  
 Para substituir o texto que corresponde a um objeto de expressão regular, use a função de modelo [Função regex_replace](../standard-library/regex-functions.md#regex_replace_function) junto com os sinalizadores de correspondência do tipo [regex_constants::match_flag_type](../standard-library/regex-constants-class.md#regex_constants__match_flag_type).  
  
 Para iterar por meio de várias correspondências de um objeto de expressão regular, use as classes de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) e [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) ou uma de suas especializações, [cregex_iterator](../standard-library/regex-typedefs.md#cregex_iterator_typedef), [sregex_iterator](../standard-library/regex-typedefs.md#sregex_iterator_typedef), [wcregex_iterator](../standard-library/regex-typedefs.md#wcregex_iterator_typedef), [wsregex_iterator](../standard-library/regex-typedefs.md#wsregex_iterator_typedef), [cregex_token_iterator](../standard-library/regex-typedefs.md#cregex_token_iterator_typedef), [sregex_token_iterator](../standard-library/regex-typedefs.md#sregex_token_iterator_typedef), [wcregex_token_iterator](../standard-library/regex-typedefs.md#wcregex_token_iterator_typedef) ou [wsregex_token_iterator](../standard-library/regex-typedefs.md#wsregex_token_iterator_typedef), junto com os sinalizadores de correspondência do tipo [regex_constants::match_flag_type](../standard-library/regex-constants-class.md#regex_constants__match_flag_type).  
  
 Para modificar os detalhes da gramática de expressões regulares, grave uma classe que implementa as características da expressão regular.  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[basic_regex](../standard-library/basic-regex-class.md)|Encapsula uma expressão regular.|  
|[match_results](../standard-library/match-results-class.md)|Contém uma sequência de subcorrespondências.|  
|[regex_constants](../standard-library/regex-constants-class.md)|Retém as constantes sortidas.|  
|[regex_error](../standard-library/regex-error-class.md)|Relata uma expressão regular inválida.|  
|[regex_iterator](../standard-library/regex-iterator-class.md)|Itera os resultados de correspondência.|  
|[regex_traits](../standard-library/regex-traits-class.md)|Descreve as características dos elementos de correspondência.|  
|[regex_traits\<char>](../standard-library/regex-traits-char-class.md)|Descreve as características de `char` para correspondência.|  
|[regex_traits<wchar_t>](../standard-library/regex-traits-wchar-t-class.md)|Descreve as características de `wchar_t` para correspondência.|  
|[regex_token_iterator](../standard-library/regex-token-iterator-class.md)|Itera as subcorrespondências.|  
|[sub_match](../standard-library/sub-match-class.md)|Descreve uma subcorrespondência.|  
  
### <a name="type-definitions"></a>Definições de tipo  
  
|||  
|-|-|  
|[cmatch](../standard-library/regex-typedefs.md#cmatch_typedef)|Definição de tipo para `char``match_results`.|  
|[cregex_iterator](../standard-library/regex-typedefs.md#cregex_iterator_typedef)|Definição de tipo para `char``regex_iterator`.|  
|[cregex_token_iterator](../standard-library/regex-typedefs.md#cregex_token_iterator_typedef)|Definição de tipo para `char``regex_token_iterator`.|  
|[csub_match](../standard-library/regex-typedefs.md#csub_match_typedef)|Definição de tipo para `char``sub_match`.|  
|[regex](../standard-library/regex-typedefs.md#regex_typedef)|Definição de tipo para `char``basic_regex`.|  
|[smatch](../standard-library/regex-typedefs.md#smatch_typedef)|Definição de tipo para `string``match_results`.|  
|[sregex_iterator](../standard-library/regex-typedefs.md#sregex_iterator_typedef)|Definição de tipo para `string``regex_iterator`.|  
|[sregex_token_iterator](../standard-library/regex-typedefs.md#sregex_token_iterator_typedef)|Definição de tipo para `string``regex_token_iterator`.|  
|[ssub_match](../standard-library/regex-typedefs.md#ssub_match_typedef)|Definição de tipo para `string``sub_match`.|  
|[wcmatch](../standard-library/regex-typedefs.md#wcmatch_typedef)|Definição de tipo para `wchar_t``match_results`.|  
|[wcregex_iterator](../standard-library/regex-typedefs.md#wcregex_iterator_typedef)|Definição de tipo para `wchar_t``regex_iterator`.|  
|[wcregex_token_iterator](../standard-library/regex-typedefs.md#wcregex_token_iterator_typedef)|Definição de tipo para `wchar_t``regex_token_iterator`.|  
|[wcsub_match](../standard-library/regex-typedefs.md#wcsub_match_typedef)|Definição de tipo para `wchar_t``sub_match`.|  
|[wregex](../standard-library/regex-typedefs.md#wregex_typedef)|Definição de tipo para `wchar_t``basic_regex`.|  
|[wsmatch](../standard-library/regex-typedefs.md#wsmatch_typedef)|Definição de tipo para `wstring``match_results`.|  
|[wsregex_iterator](../standard-library/regex-typedefs.md#wsregex_iterator_typedef)|Definição de tipo para `wstring``regex_iterator`.|  
|[wsregex_token_iterator](../standard-library/regex-typedefs.md#wsregex_token_iterator_typedef)|Definição de tipo para `wstring``regex_token_iterator`.|  
|[wssub_match](../standard-library/regex-typedefs.md#wssub_match_typedef)|Definição de tipo para `wstring``sub_match`.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[regex_match](../standard-library/regex-functions.md#regex_match_function)|Corresponde exatamente a uma expressão regular.|  
|[regex_replace](../standard-library/regex-functions.md#regex_replace_function)|Substitui expressões regulares correspondentes.|  
|[regex_search](../standard-library/regex-functions.md#regex_search_function)|Pesquisa por uma correspondência de expressão regular.|  
|[swap](../standard-library/regex-functions.md#swap_function)|Alterna objetos `basic_regex` ou `match_results`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator==](../standard-library/regex-operators.md#operator_eq_eq)|Comparação de vários objetos, é igual a.|  
|[operator!=](../standard-library/regex-operators.md#operator_neq)|Comparação de vários objetos, não é igual a.|  
|[operator<](../standard-library/regex-operators.md#operator_lt_)|Comparação de vários objetos, menor que.|  
|[operator\<=](../standard-library/regex-operators.md#operator_lt__eq)|Comparação de vários objetos, menor ou igual a.|  
|[operator>](../standard-library/regex-operators.md#operator_gt_)|Comparação de vários objetos, maior que.|  
|[operator>=](../standard-library/regex-operators.md#operator_gt__eq)|Comparação de vários objetos, maior ou igual a.|  
|[operator<<](../standard-library/regex-operators.md#operator_lt__lt_)|Insere um `sub_match` em um fluxo.|  
  
## <a name="see-also"></a>Consulte também  
[Expressões Regulares (C++)](../standard-library/regular-expressions-cpp.md)  
[Classe regex_constants](../standard-library/regex-constants-class.md)  
[Classe regex_error](../standard-library/regex-error-class.md)  
[\<Funções regex>](../standard-library/regex-functions.md)  
[Classe regex_iterator](../standard-library/regex-iterator-class.md)  
[\<Operadores regex>](../standard-library/regex-operators.md)  
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)  
[Classe regex_traits](../standard-library/regex-traits-class.md)  
[\<Typedef regex>](../standard-library/regex-typedefs.md)  




