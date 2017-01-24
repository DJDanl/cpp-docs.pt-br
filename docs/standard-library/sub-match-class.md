---
title: "Classe sub_match | Microsoft Docs"
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
  - "sub_match"
  - "std::tr1::sub_match"
  - "std.tr1.sub_match"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe sub_match [TR1]"
ms.assetid: 804e2b9e-d16a-4c4c-ac60-024e0b2dd0e8
caps.latest.revision: 19
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe sub_match
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve uma subcorrespondência.  
  
## Sintaxe  
  
```  
template<class BidIt>  
    class sub_match  
        : public std::pair<BidIt, BidIt> {  
public:  
    bool matched;  
    int compare(const sub_match& right) const;  
    int compare(const basic_string<value_type>& right) const;  
    int compare(const value_type *right) const;  
    difference_type length() const;  
    operator basic_string<value_type>() const;  
    basic_string<value_type> str() const;  
    typedef typename iterator_traits<BidIt>::value_type value_type;  
    typedef typename iterator_traits<BidIt>::difference_type difference_type;  
    typedef BidIt iterator;  
    };  
```  
  
#### Parâmetros  
 `BidIt`  
 O tipo de iterador para subcorrespondências.  
  
## Comentários  
 A classe de modelo descreve um objeto que designa uma seqüência de caracteres que corresponde a um grupo de captura em uma chamada para [Função regex\_match](../Topic/regex_match%20Function.md) ou [Função regex\_search](../Topic/regex_search%20Function.md). Objetos do tipo [Classe match\_results](../standard-library/match-results-class.md) conter uma matriz desses objetos, um para cada grupo de captura na expressão regular que foi usado na pesquisa.  
  
 Se o grupo de captura não foi correspondida membro de dados do objeto `matched` contém false e dois iteradores `first` e `second` \(herdado de base de `std::pair`\) são iguais. Se o grupo de captura é coincidente, `matched` é verdadeiro, o iterador `first` aponta para o primeiro caractere na sequência de destino que corresponde ao grupo de captura e o iterador `second` pontos de sequência de uma posição após o último caractere no destino que corresponde ao grupo de captura. Observe que para um comprimento de zero coincidir com o membro `matched` é verdadeiro, dois iteradores será iguais, e ambos apontará para a posição da correspondência.  
  
 Uma correspondência de comprimento zero pode ocorrer quando um grupo de captura consiste exclusivamente uma asserção, ou de uma repetição que permite zero repetições. Por exemplo:  
  
 "^" corresponde à sequência de destino "a"; o `sub_match` do objeto correspondente para capturar o grupo 0 mantém iteradores que apontam para o primeiro caractere na sequência.  
  
 "b\(a\*\) b" corresponde à sequência de destino "bb"; o `sub_match` do objeto correspondente ao grupo de captura 1 contém os iteradores que apontam para o segundo caractere na sequência.  
  
## Requisitos  
 **Cabeçalho:** \< regex \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<regex\>](../standard-library/regex.md)   
 [sub\_match](../standard-library/sub-match-class.md)   
 [Função regex\_match](../Topic/regex_match%20Function.md)   
 [Função regex\_search](../Topic/regex_search%20Function.md)