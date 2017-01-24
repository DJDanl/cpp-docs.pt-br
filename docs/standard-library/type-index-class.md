---
title: "Classe type_index | Microsoft Docs"
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
  - "typeindex/std::type_index"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe type_index"
ms.assetid: db366119-74cb-43e8-aacf-9679e561fa2f
caps.latest.revision: 14
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe type_index
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de `type_index` envolve um ponteiro para [Classe type\_info](../cpp/type-info-class.md) para ajudar na indexação por esses objetos.  
  
```  
class type_index {  
public:  
    type_index(const type_info& tinfo);  
    const char *name() const;  
    size_t hash_code() const;  
    bool operator==(const type_info& right) const;  
    bool operator!=(const type_info& right) const;  
    bool operator<(const type_info& right) const;  
    bool operator<=(const type_info& right) const;  
    bool operator>(const type_info& right) const;  
    bool operator>=(const type_info& right) const;  
};  
```  
  
 O construtor inicializa `ptr` a `&tinfo`.  
  
 `name` retorna `ptr->name()`.  
  
 retorna `ptr->hash_code().`de`hash_code`  
  
 `operator==` retorna `*ptr == right.ptr`.  
  
 `operator!=` retorna `!(*this == right)`.  
  
 `operator<` retorna `*ptr->before(*right.ptr)`.  
  
 retorna `!(right < *this).`de`operator<=`  
  
 retorna `right < *this`de`operator>`.  
  
 `operator>=` retorna `!(*this < right)`.  
  
## Consulte também  
 [Informações de tipo de tempo de execução](../Topic/Run-Time%20Type%20Information.md)   
 [\<typeindex\>](../standard-library/typeindex.md)