---
title: "Classe moneypunct_byname | Microsoft Docs"
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
  - "std.moneypunct_byname"
  - "std::moneypunct_byname"
  - "xlocmon/std::moneypunct_byname"
  - "moneypunct_byname"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe moneypunct_byname"
ms.assetid: e8a544d2-6aee-420d-b513-deb385c9b416
caps.latest.revision: 22
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe moneypunct_byname
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe derivada do modelo que descreve um objeto que pode servir como uma faceta de `moneypunct` de uma localidade específica, habilitando o campo monetário de entrada de formatação ou os campos monetários de saída.  
  
## Sintaxe  
  
```  
template<class CharType, bool Intl = false>  
class moneypunct_byname : public moneypunct<CharType, Intl>  
{  
public:  
    explicit moneypunct_byname(  
        const char *_Locname,  
        size_t _Refs = 0  
    );  
    explicit moneypunct_byname(  
        const string& _Locname,  
        size_t _Refs = 0  
    );   
protected:  
    virtual ~moneypunct_byname();  
};  
```  
  
## Comentários  
 O comportamento é determinado pela localidade nomeada `_Locname`.  Cada construtor inicializa o objeto base com [moneypunct](../Topic/moneypunct::moneypunct.md)\<CharType, internacional\>\(`_Refs`\).  
  
## Requisitos  
 localidade \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)