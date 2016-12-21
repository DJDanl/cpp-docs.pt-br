---
title: "Construtor HString::HString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "corewrappers/Microsoft::WRL::Wrappers::HString::HString"
dev_langs: 
  - "C++"
ms.assetid: 6da12785-ed01-4720-a004-667db60298f1
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor HString::HString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe HString.  
  
## Sintaxe  
  
```cpp  
  
HString(HSTRING hstr = nullptr) throw();  
HString(HString&& other) throw();  
```  
  
#### Parâmetros  
 `hstr`  
 Um identificador de HSTRING.  
  
 `other`  
 Um objeto existente de HString.  
  
## Comentários  
 O primeiro construtor inicializa um novo objeto de HString que está vazia.  
  
 O segundo construtor inicializa um novo objeto de HString ao valor do parâmetro existente de `other` , e destruição no parâmetro de `other` .  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HString](../windows/hstring-class.md)