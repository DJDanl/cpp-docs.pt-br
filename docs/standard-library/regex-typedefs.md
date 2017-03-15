---
title: Typedefs &lt;regex&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cmatch
- std::cmatch
- regex/std::cmatch
- cregex_iterator
- std::cregex_iterator
- regex/std::cregex_iterator
- cregex_token_iterator
- std::cregex_token_iterator
- regex/std::cregex_token_iterator
- csub_match
- std::csub_match
- regex/std::csub_match
- regex
- std::regex
- regex/std::regex
- smatch
- std::smatch
- regex/std::smatch
- sregex_iterator
- std::sregex_iterator
- regex/std::sregex_iterator
- sregex_token_iterator
- std::sregex_token_iterator
- regex/std::sregex_token_iterator
- ssub_match
- std::ssub_match
- regex/std::ssub_match
- wcmatch
- std::wcmatch
- regex/std::wcmatch
- wcregex_iterator
- std::wcregex_iterator
- regex/std::wcregex_iterator
- wcregex_token_iterator
- std::wcregex_token_iterator
- regex/std::wcregex_token_iterator
- wcsub_match
- std::wcsub_match
- regex/std::wcsub_match
- wregex
- std::wregex
- regex/std::wregex
- wsmatch
- std::wsmatch
- regex/std::wsmatch
- wsregex_iterator
- std::wsregex_iterator
- regex/std::wsregex_iterator
- wsregex_token_iterator
- std::wsregex_token_iterator
- regex/std::wsregex_token_iterator
- wssub_match
- std::wssub_match
- regex/std::wssub_match
ms.assetid: e6a69067-106c-4a24-9e08-7c867a3a2260
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 41b445ceeeb1f37ee9873cb55f62d30d480d8718
ms.openlocfilehash: 60822dd232399b27ccda3db829b636d817091a2d
ms.lasthandoff: 02/25/2017

---
# <a name="ltregexgt-typedefs"></a>Typedefs &lt;regex&gt;
||||  
|-|-|-|  
|[Typedef cmatch](#cmatch_typedef)|[Typedef cregex_iterator](#cregex_iterator_typedef)|[Typedef cregex_token_iterator](#cregex_token_iterator_typedef)|  
|[Typedef csub_match](#csub_match_typedef)|[Typedef regex](#regex_typedef)|[Typedef smatch](#smatch_typedef)|  
|[Typedef sregex_iterator](#sregex_iterator_typedef)|[Typedef sregex_token_iterator](#sregex_token_iterator_typedef)|[Typedef ssub_match](#ssub_match_typedef)|  
|[Typedef wcmatch](#wcmatch_typedef)|[Typedef wcregex_iterator](#wcregex_iterator_typedef)|[Typedef wcregex_token_iterator](#wcregex_token_iterator_typedef)|  
|[Typedef wcsub_match](#wcsub_match_typedef)|[Typedef wregex](#wregex_typedef)|[Typedef wsmatch](#wsmatch_typedef)|  
|[Typedef wsregex_iterator](#wsregex_iterator_typedef)|[Typedef wsregex_token_iterator](#wsregex_token_iterator_typedef)|[Typedef wssub_match](#wssub_match_typedef)|  
  
##  <a name="a-namecmatchtypedefa--cmatch-typedef"></a><a name="cmatch_typedef"></a>  Typedef cmatch  
 Definição de tipo para char match_results.  
  
```  
typedef match_results<const char*> cmatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="a-namecregexiteratortypedefa--cregexiterator-typedef"></a><a name="cregex_iterator_typedef"></a>  Typedef cregex_iterator  
 Definição de tipo para char regex_iterator.  
  
```  
typedef regex_iterator<const char*> cregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="a-namecregextokeniteratortypedefa--cregextokeniterator-typedef"></a><a name="cregex_token_iterator_typedef"></a>  Typedef cregex_token_iterator  
 Definição de tipo para char regex_token_iterator  
  
```  
typedef regex_token_iterator<const char*> cregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="a-namecsubmatchtypedefa--csubmatch-typedef"></a><a name="csub_match_typedef"></a>  Typedef csub_match  
 Definição de tipo para char sub_match.  
  
```  
typedef sub_match<const char*> csub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `const char*`.  
  
##  <a name="a-nameregextypedefa--regex-typedef"></a><a name="regex_typedef"></a>  Tydepef regex  
 Definição de tipo para char basic_regex.  
  
```  
typedef basic_regex<char> regex;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe basic_regex](../standard-library/basic-regex-class.md) para iteradores do tipo `char`.  
  
> [!NOTE]
>  Caracteres de bit alto terão resultados imprevisíveis com `regex`. Valores fora do intervalo de 0 a 127 podem resultar em um comportamento indefinido.  
  
##  <a name="a-namesmatchtypedefa--smatch-typedef"></a><a name="smatch_typedef"></a>  Typedef smatch  
 Definição de tipo para string match_results.  
  
```  
typedef match_results<string::const_iterator> smatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="a-namesregexiteratortypedefa--sregexiterator-typedef"></a><a name="sregex_iterator_typedef"></a>  Typedef sregex_iterator  
 Definição de tipo para string regex_iterator.  
  
```  
typedef regex_iterator<string::const_iterator> sregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="a-namesregextokeniteratortypedefa--sregextokeniterator-typedef"></a><a name="sregex_token_iterator_typedef"></a>  Typedef sregex_token_iterator  
 Definição de tipo para string regex_token_iterator.  
  
```  
typedef regex_token_iterator<string::const_iterator> sregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="a-namessubmatchtypedefa--ssubmatch-typedef"></a><a name="ssub_match_typedef"></a>  Typedef ssub_match  
 Definição de tipo para sub_match de cadeia de caractere.  
  
```  
typedef sub_match<string::const_iterator> ssub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `string::const_iterator`.  
  
##  <a name="a-namewcmatchtypedefa--wcmatch-typedef"></a><a name="wcmatch_typedef"></a>  Typedef wcmatch  
 Definição de tipo para wchar_t match_results.  
  
```  
typedef match_results<const wchar_t *> wcmatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="a-namewcregexiteratortypedefa--wcregexiterator-typedef"></a><a name="wcregex_iterator_typedef"></a>  Typedef wcregex_iterator  
 Definição de tipo para wchar_t regex_iterator.  
  
```  
typedef regex_iterator<const wchar_t*> wcregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="a-namewcregextokeniteratortypedefa--wcregextokeniterator-typedef"></a><a name="wcregex_token_iterator_typedef"></a>  Typedef wcregex_token_iterator  
 Definição de tipo para wchar_t regex_token_iterator.  
  
```  
typedef regex_token_iterator<const wchar_t*> wcregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="a-namewcsubmatchtypedefa--wcsubmatch-typedef"></a><a name="wcsub_match_typedef"></a>  Typedef wcsub_match  
 Definição de tipo para wchar_t sub_match.  
  
```  
typedef sub_match<const wchar_t*> wcsub_match;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe sub_match](../standard-library/sub-match-class.md) para iteradores do tipo `const wchar_t*`.  
  
##  <a name="a-namewregextypedefa--wregex-typedef"></a><a name="wregex_typedef"></a>  Typedef wregex  
 Definição de tipo para wchar_t basic_regex.  
  
```  
typedef basic_regex<wchar_t> wregex;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe basic_regex](../standard-library/basic-regex-class.md) para iteradores do tipo `wchar_t`.  
  
##  <a name="a-namewsmatchtypedefa--wsmatch-typedef"></a><a name="wsmatch_typedef"></a>  Typedef wsmatch  
 Definição de tipo para wstring match_results.  
  
```  
typedef match_results<wstring::const_iterator> wsmatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe match_results](../standard-library/match-results-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
##  <a name="a-namewsregexiteratortypedefa--wsregexiterator-typedef"></a><a name="wsregex_iterator_typedef"></a>  Typedef wsregex_iterator  
 Definição de tipo para wstring regex_iterator.  
  
```  
typedef regex_iterator<wstring::const_iterator> wsregex_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_iterator](../standard-library/regex-iterator-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
##  <a name="a-namewsregextokeniteratortypedefa--wsregextokeniterator-typedef"></a><a name="wsregex_token_iterator_typedef"></a>  Typedef wsregex_token_iterator  
 Definição de tipo para wstring regex_token_iterator.  
  
```  
typedef regex_token_iterator<wstring::const_iterator> wsregex_token_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md) para iteradores do tipo `wstring::const_iterator`.  
  
##  <a name="a-namewssubmatchtypedefa--wssubmatch-typedef"></a><a name="wssub_match_typedef"></a>  Typedef wssub_match  
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

