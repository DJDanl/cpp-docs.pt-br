---
title: "Classe messages_byname | Microsoft Docs"
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
  - "messages_byname"
  - "std::messages_byname"
  - "std.messages_byname"
  - "xlocmes/std::messages_byname"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe messages_byname"
ms.assetid: c6c64841-3e80-43c8-b54c-fed41833ad6b
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe messages_byname
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe derivada do modelo descreve um objeto que pode servir como uma faceta de uma localidade específica, habilitando a recuperação de mensagens localizadas.  
  
## Sintaxe  
  
```  
template<class CharType>  
    class messages_byname : public messages<CharType> {  
public:  
    explicit messages_byname(  
        const char *_Locname,  
        size_t _Refs = 0  
    );  
    explicit messages_byname(  
        const string& _Locname,  
        size_t _Refs = 0  
    );   
protected:  
    virtual ~messages_byname();  
};  
```  
  
#### Parâmetros  
 `_Locname`  
 Uma localidade nomeada.  
  
 `_Refs`  
 Uma contagem inicial de referência.  
  
## Comentários  
 O comportamento é determinado pela localidade nomeada `_Locname`.  Cada construtor inicializa o objeto base com [mensagens](../Topic/messages::messages.md)\<CharType\>\(`_Refs`\).  
  
## Requisitos  
 localidade \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)