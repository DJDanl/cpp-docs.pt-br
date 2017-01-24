---
title: "Classe regex_traits | Microsoft Docs"
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
  - "regex_traits"
  - "std::tr1::regex_traits"
  - "std.tr1.regex_traits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe regex_traits [TR1]"
ms.assetid: bc5a5eed-32fc-4eb7-913d-71c42e729e81
caps.latest.revision: 19
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe regex_traits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve as características dos elementos da correspondência.  
  
## Sintaxe  
  
```  
template<class Elem>  
    struct regex_traits {  
    regex_traits();  
  
    static size_type length(const char_type *str);  
    char_type translate(char_type ch) const;  
    char_type translate_nocase(char_type ch) const;  
    template<class FwdIt>  
        string_type transform(FwdIt first, FwdIt last) const;  
    template<class FwdIt>  
        string_type transform_primary(FwdIt first, FwdIt last) const;  
    template<class FwdIt>  
        char_class_type lookup_classname(FwdIt first, FwdIt last) const;  
    template<class FwdIt>  
        string_type lookup_collatename(FwdIt first, FwdIt last) const;  
    bool isctype(char_type ch, char_class_type cls) const;  
    int value(Elem ch, int base) const;  
    locale_type imbue(locale_type loc);  
    locale_type getloc() const;  
  
    typedef Elem char_type;  
    typedef T6 size_type;  
    typedef basic_string<Elem> string_type;  
    typedef T7 locale_type;  
    typedef T8 char_class_type;  
    };  
```  
  
#### Parâmetros  
 `Elem`  
 O tipo de elemento para descrever.  
  
## Comentários  
 A classe de modelo descreve várias características da expressão regular para tipo `Elem`. A classe de modelo [Classe basic\_regex](../Topic/basic_regex%20Class.md) usa essas informações para manipular elementos do tipo `Elem`.  
  
 Cada `regex_traits` objeto contém um objeto do tipo `regex_traits::locale` que é usado por algumas de suas funções de membro. A localidade padrão é uma cópia do `regex_traits::locale()`. A função de membro `imbue` substitui o objeto de localidade e a função de membro `getloc` retorna uma cópia do objeto de localidade.  
  
## Requisitos  
 **Cabeçalho:** \< regex \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<regex\>](../standard-library/regex.md)   
 [regex\_traits](../standard-library/regex-traits-class.md)   
 [\< char \> classe regex\_traits](../standard-library/regex-traits-char-class.md)   
 [\< wchar\_t \> classe regex\_traits](../standard-library/regex-traits-wchar-t-class.md)