---
title: Typedefs &lt;regex&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- regex/std::cmatch
- regex/std::cregex_iterator
- regex/std::cregex_token_iterator
- regex/std::csub_match
- regex/std::regex
- regex/std::smatch
- regex/std::sregex_iterator
- regex/std::sregex_token_iterator
- regex/std::ssub_match
- regex/std::wcmatch
- regex/std::wcregex_iterator
- regex/std::wcregex_token_iterator
- regex/std::wcsub_match
- regex/std::wregex
- regex/std::wsmatch
- regex/std::wsregex_iterator
- regex/std::wsregex_token_iterator
- regex/std::wssub_match
dev_langs: C++
ms.assetid: e6a69067-106c-4a24-9e08-7c867a3a2260
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 7dad87e2d6e402333db5f51bdf8deaee1090df86
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltregexgt-typedefs"></a>Typedefs &lt;regex&gt;
||||  
|-|-|-|  
|[cmatch](#cmatch)|[cregex_iterator](#cregex_iterator)|[cregex_token_iterator](#cregex_token_iterator)|  
|[csub_match](#csub_match)|[regex](#regex)|[smatch](#smatch)|  
|[sregex_iterator](#sregex_iterator)|[sregex_token_iterator](#sregex_token_iterator)|[ssub_match](#ssub_match)|  
|[wcmatch](#wcmatch)|[wcregex_iterator](#wcregex_iterator)|[wcregex_token_iterator](#wcregex_token_iterator)|  
|[wcsub_match](#wcsub_match)|[wregex](#wregex)|[wsmatch](#wsmatch)|  
|[wsregex_iterator](#wsregex_iterator)|[wsregex_token_iterator](#wsregex_token_iterator)|[wssub_match](#wssub_match)|  
  
##  <a name="cmatch"></a>  Typedef cmatch  
 Definição de tipo para char match_results.  
  
```  
typedef match_results<const char*> cmatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="cregex_iterator"></a>  Typedef cregex_iterator  
 Definição de tipo para char regex_iterator.  
  
```  
typedef regex_iterator<const char*> cregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="cregex_token_iterator"></a>  Typedef cregex_token_iterator  
 Definição de tipo para char regex_token_iterator  
  
```  
typedef regex_token_iterator<const char*> cregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="csub_match"></a>  Typedef csub_match  
 Definição de tipo para char sub_match.  
  
```  
typedef sub_match<const char*> csub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="regex"></a>  Tydepef regex  
 Definição de tipo para char basic_regex.  
  
```  
typedef basic_regex<char> regex;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe basic_regex](../standard-library/basic-regex-class.md) para iteradores do tipo `char`.  
  
> [!NOTE]
>  Caracteres de bit alto terão resultados imprevisíveis com `regex`. Valores fora do intervalo de 0 a 127 podem resultar em um comportamento indefinido.  
  
##  <a name="smatch"></a>  Typedef smatch  
 Definição de tipo para string match_results.  
  
```  
typedef match_results<string::const_iterator> smatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="sregex_iterator"></a>  Typedef sregex_iterator  
 Definição de tipo para string regex_iterator.  
  
```  
typedef regex_iterator<string::const_iterator> sregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="sregex_token_iterator"></a>  Typedef sregex_token_iterator  
 Definição de tipo para string regex_token_iterator.  
  
```  
typedef regex_token_iterator<string::const_iterator> sregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="ssub_match"></a>  Typedef ssub_match  
 Definição de tipo para sub_match de cadeia de caractere.  
  
```  
typedef sub_match<string::const_iterator> ssub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="wcmatch"></a>  Typedef wcmatch  
 Definição de tipo para wchar_t match_results.  
  
```  
typedef match_results<const wchar_t *> wcmatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="wcregex_iterator"></a>  Typedef wcregex_iterator  
 Definição de tipo para wchar_t regex_iterator.  
  
```  
typedef regex_iterator<const wchar_t*> wcregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="wcregex_token_iterator"></a>  Typedef wcregex_token_iterator  
 Definição de tipo para wchar_t regex_token_iterator.  
  
```  
typedef regex_token_iterator<const wchar_t*> wcregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="wcsub_match"></a>  Typedef wcsub_match  
 Definição de tipo para wchar_t sub_match.  
  
```  
typedef sub_match<const wchar_t*> wcsub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="wregex"></a>  Typedef wregex  
 Definição de tipo para wchar_t basic_regex.  
  
```  
typedef basic_regex<wchar_t> wregex;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe basic_regex](../standard-library/basic-regex-class.md) para iteradores do tipo `wchar_t`.  
  
##  <a name="wsmatch"></a>  Typedef wsmatch  
 Definição de tipo para wstring match_results.  
  
```  
typedef match_results<wstring::const_iterator> wsmatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
##  <a name="wsregex_iterator"></a>  Typedef wsregex_iterator  
 Definição de tipo para wstring regex_iterator.  
  
```  
typedef regex_iterator<wstring::const_iterator> wsregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
##  <a name="wsregex_token_iterator"></a>  Typedef wsregex_token_iterator  
 Definição de tipo para wstring regex_token_iterator.  
  
```  
typedef regex_token_iterator<wstring::const_iterator> wsregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
##  <a name="wssub_match"></a>  Typedef wssub_match  
 Definição de tipo para wstring sub_match.  
  
```  
typedef sub_match<wstring::const_iterator> wssub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
## <a name="see-also"></a>Consulte também  
[\<regex>](../standard-library/regex.md)  
[Classe regex_constants](../standard-library/regex-constants-class.md)  
[Classe regex_error](../standard-library/regex-error-class.md)  
[\<Funções regex>](../standard-library/regex-functions.md)  
[Classe regex_iterator](../standard-library/regex-iterator-class.md)  
[\<Operadores regex>](../standard-library/regex-operators.md)  
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)  
[Classe regex_traits](../standard-library/regex-traits-class.md)  
