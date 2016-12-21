---
title: "&lt;regex&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<regex>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho regex [TR1]"
ms.assetid: 5dd4ef74-6063-4dbc-b692-1960bb736f0b
caps.latest.revision: 23
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;regex&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define uma classe de modelo para analisar[Expressões regulares \(C\+\+\)](../standard-library/regular-expressions-cpp.md)e várias classes de modelo e funções para pesquisar texto corresponde a um objeto de expressão regular.  
  
## Sintaxe  
  
```  
#include <regex>  
```  
  
## Comentários  
 Para criar um objeto de expressão regular, use a classe de modelo[Classe basic\_regex](../Topic/basic_regex%20Class.md)ou um de seus especializações[Typedef regex](../Topic/regex%20Typedef.md)e[Typedef wregex](../Topic/wregex%20Typedef.md)junto com os sinalizadores de sintaxe do tipo[regex\_constants::syntax\_option\_type](../Topic/regex_constants::syntax_option_type.md).  
  
 Para pesquisar texto corresponde a um objeto de expressão regular, use as funções de modelo[Função regex\_match](../Topic/regex_match%20Function.md)e[Função regex\_search](../Topic/regex_search%20Function.md)junto com os sinalizadores de correspondência de tipo[regex\_constants::match\_flag\_type](../Topic/regex_constants::match_flag_type.md).  Essas funções retornam resultados usando a classe de modelo[Classe match\_results](../standard-library/match-results-class.md)e seus especializações[Typedef cmatch](../Topic/cmatch%20Typedef.md)[Typedef wcmatch](../Topic/wcmatch%20Typedef.md)[Typedef smatch](../Topic/smatch%20Typedef.md)e[Typedef wsmatch](../Topic/wsmatch%20Typedef.md)junto com a classe de modelo[Classe sub\_match](../standard-library/sub-match-class.md)e seus especializações[Typedef csub\_match](../Topic/csub_match%20Typedef.md)[Typedef wcsub\_match](../Topic/wcsub_match%20Typedef.md)[Typedef ssub\_match](../Topic/ssub_match%20Typedef.md)e[Typedef wssub\_match](../Topic/wssub_match%20Typedef.md).  
  
 Para substituir o texto que corresponda a um objeto de expressão regular, use a função de modelo[Função regex\_replace](../Topic/regex_replace%20Function.md)junto com os sinalizadores de correspondência de tipo[regex\_constants::match\_flag\_type](../Topic/regex_constants::match_flag_type.md).  
  
 Para iterar por meio de várias correspondências de um objeto de expressão regular, use as classes de modelo[Classe regex\_iterator](../standard-library/regex-iterator-class.md)e[Classe regex\_token\_iterator](../Topic/regex_token_iterator%20Class.md)ou um de seus especializações[Typedef cregex\_iterator](../Topic/cregex_iterator%20Typedef.md)[Typedef sregex\_iterator](../Topic/sregex_iterator%20Typedef.md)[TypeDef wcregex\_iterator](../Topic/wcregex_iterator%20Typedef.md)[Typedef wsregex\_iterator](../Topic/wsregex_iterator%20Typedef.md)[Typedef cregex\_token\_iterator](../Topic/cregex_token_iterator%20Typedef.md)[Typedef sregex\_token\_iterator](../Topic/sregex_token_iterator%20Typedef.md)[Typedef wcregex\_token\_iterator](../Topic/wcregex_token_iterator%20Typedef.md)ou[Typedef wsregex\_token\_iterator](../Topic/wsregex_token_iterator%20Typedef.md)junto com os sinalizadores de correspondência de tipo[regex\_constants::match\_flag\_type](../Topic/regex_constants::match_flag_type.md).  
  
 Para modificar os detalhes da gramática de expressões regulares, escreva uma classe que implementa as características da expressão regular.  
  
### Classes  
  
|||  
|-|-|  
|[basic\_regex](../Topic/basic_regex%20Class.md)|Encapsula uma expressão regular.|  
|[match\_results](../standard-library/match-results-class.md)|Contém uma seqüência de subcorrespondências.|  
|[regex\_constants](../Topic/regex_constants%20Class.md)|Contém constantes variadas.|  
|[regex\_error](../standard-library/regex-error-class.md)|Relatórios de uma expressão regular inválida.|  
|[regex\_iterator](../standard-library/regex-iterator-class.md)|Itera por meio de resultados de correspondência.|  
|[regex\_traits](../standard-library/regex-traits-class.md)|Descreve as características dos elementos da correspondência.|  
|[regex\_traits \< char \>](../standard-library/regex-traits-char-class.md)|Descreve características de`char`para correspondência.|  
|[regex\_traits \< wchar\_t \>](../standard-library/regex-traits-wchar-t-class.md)|Descreve características de`wchar_t`para correspondência.|  
|[regex\_token\_iterator](../Topic/regex_token_iterator%20Class.md)|Itera subcorrespondências.|  
|[sub\_match](../standard-library/sub-match-class.md)|Descreve uma subcorrespondência.|  
  
### Definições de tipo  
  
|||  
|-|-|  
|[cmatch](../Topic/cmatch%20Typedef.md)|Definição de tipo para`char``match_results`.|  
|[cregex\_iterator](../Topic/cregex_iterator%20Typedef.md)|Definição de tipo para`char``regex_iterator`.|  
|[cregex\_token\_iterator](../Topic/cregex_token_iterator%20Typedef.md)|Definição de tipo para`char``regex_token_iterator`.|  
|[csub\_match](../Topic/csub_match%20Typedef.md)|Definição de tipo para`char``sub_match`.|  
|[regex](../Topic/regex%20Typedef.md)|Definição de tipo para`char``basic_regex`.|  
|[smatch](../Topic/smatch%20Typedef.md)|Definição de tipo para`string``match_results`.|  
|[sregex\_iterator](../Topic/sregex_iterator%20Typedef.md)|Definição de tipo para`string``regex_iterator`.|  
|[sregex\_token\_iterator](../Topic/sregex_token_iterator%20Typedef.md)|Definição de tipo para`string``regex_token_iterator`.|  
|[ssub\_match](../Topic/ssub_match%20Typedef.md)|Definição de tipo para`string``sub_match`.|  
|[wcmatch](../Topic/wcmatch%20Typedef.md)|Definição de tipo para`wchar_t``match_results`.|  
|[wcregex\_iterator](../Topic/wcregex_iterator%20Typedef.md)|Definição de tipo para`wchar_t``regex_iterator`.|  
|[wcregex\_token\_iterator](../Topic/wcregex_token_iterator%20Typedef.md)|Definição de tipo para`wchar_t``regex_token_iterator`.|  
|[wcsub\_match](../Topic/wcsub_match%20Typedef.md)|Definição de tipo para`wchar_t``sub_match`.|  
|[wregex](../Topic/wregex%20Typedef.md)|Definição de tipo para`wchar_t``basic_regex`.|  
|[wsmatch](../Topic/wsmatch%20Typedef.md)|Definição de tipo para`wstring``match_results`.|  
|[wsregex\_iterator](../Topic/wsregex_iterator%20Typedef.md)|Definição de tipo para`wstring``regex_iterator`.|  
|[wsregex\_token\_iterator](../Topic/wsregex_token_iterator%20Typedef.md)|Definição de tipo para`wstring``regex_token_iterator`.|  
|[wssub\_match](../Topic/wssub_match%20Typedef.md)|Definição de tipo para`wstring``sub_match`.|  
  
### Funções  
  
|||  
|-|-|  
|[regex\_match](../Topic/regex_match%20Function.md)|Corresponde exatamente uma expressão regular.|  
|[regex\_replace](../Topic/regex_replace%20Function.md)|Substitui expressões regulares correspondentes.|  
|[regex\_search](../Topic/regex_search%20Function.md)|Procura uma correspondência da expressão regular.|  
|[swap](../Topic/swap%20Function%20%3Cregex%3E.md)|Alterna`basic_regex`ou`match_results`objetos.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=\=](../Topic/operator==%20%3Cregex%3E.md)|Comparação de vários objetos, iguais.|  
|[operator\!\=](../Topic/operator!=%20%3Cregex%3E.md)|Comparação de vários objetos, não é iguais.|  
|[operador \<](../Topic/operator%3C%20%3Cregex%3E.md)|Comparação de vários objetos, menor que.|  
|[Operador \<\=](../Topic/operator%3C=%20%3Cregex%3E.md)|Comparação de vários objetos, menor ou igual.|  
|[Operador \>](../Topic/operator%3E%20%3Cregex%3E.md)|Comparação de vários objetos, maiores.|  
|[Operador \>\=](../Topic/operator%3E=%20%3Cregex%3E.md)|Comparação de vários objetos, maiores ou iguais.|  
|[Operador \<\<](../Topic/operator%3C%3C%20%3Cregex%3E.md)|Insere um`sub_match`em um fluxo.|  
  
## Consulte também  
 [Expressões regulares \(C\+\+\)](../standard-library/regular-expressions-cpp.md)