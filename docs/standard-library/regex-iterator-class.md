---
title: "Classe regex_iterator | Microsoft Docs"
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
  - "std::tr1::regex_iterator"
  - "std.tr1.regex_iterator"
  - "regex_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe regex_iterator [TR1]"
ms.assetid: 0cfd8fd0-5a95-4f3c-bf8e-6ef028c423d3
caps.latest.revision: 16
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe regex_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Classe de iterador para correspondências.  
  
## Sintaxe  
  
```  
template<class BidIt, class Elem = iterator_traits<BidIt>::value_type,  
    class RXtraits = regex_traits<Elem> >  
        class regex_iterator {  
public:  
    typedef basic_regex<Elem, RXtraits> regex_type;  
    typedef match_results<BidIt> value_type;  
    typedef std::forward_iterator_tag iterator_category;  
    typedef std::ptrdiff_t difference_type;  
    typedef const match_results<BidIt>* pointer;  
    typedef const match_results<BidIt>& reference;  
  
    regex_iterator();  
    regex_iterator(BidIt first, BidIt last,  
        const regex_type& re,  
        regex_constants::match_flag_type f = regex_constants::match_default);  
  
    bool operator==(const regex_iterator& right);  
    bool operator!=(const regex_iterator& right);  
    const match_results<BidIt>& operator*();  
    const match_results<BidIt> *operator->();  
    regex_iterator& operator++();  
    regex_iterator& operator++(int);  
  
    BidIt begin;                            // exposition only  
    BidIt end;                              // exposition only  
    regex_type *pregex;                     // exposition only  
    regex_constants::match_flag_type flags; // exposition only  
    match_results<BidIt> match;             // exposition only  
    };  
```  
  
#### Parâmetros  
 `BidIt`  
 O tipo de iterador para subcorrespondências.  
  
 `Elem`  
 O tipo dos elementos para corresponder.  
  
 `RXtraits`  
 Classe de características para elementos.  
  
## Comentários  
 A classe de modelo descreve um objeto de iterador de avanço constante. Extrai objetos do tipo `match_results<BidIt>` aplicando repetidamente seu objeto de expressão regular `*pregex` na sequência de caracteres definida pelo intervalo iterador `[begin, end)`.  
  
## Exemplos  
 Consulte os tópicos a seguir para obter exemplos de expressões regulares:  
  
-   [Função regex\_match](../Topic/regex_match%20Function.md)  
  
-   [Função regex\_replace](../Topic/regex_replace%20Function.md)  
  
-   [Função regex\_search](../Topic/regex_search%20Function.md)  
  
-   [Função swap](../Topic/swap%20Function%20%3Cregex%3E.md)  
  
## Requisitos  
 **Cabeçalho:** \< regex \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<regex\>](../standard-library/regex.md)   
 [regex\_iterator](../standard-library/regex-iterator-class.md)