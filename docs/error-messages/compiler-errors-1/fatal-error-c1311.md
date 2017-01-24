---
title: "Erro fatal C1311 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1311"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1311"
ms.assetid: 6590a06c-ce9d-4f17-8f62-c809343143b8
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1311
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O formato de COFF não pode inicializar estaticamente “var com” bytes do número do endereço  
  
 Um endereço cujo valor não é conhecido em tempo de compilação estaticamente não pode ser atribuído a uma variável cujo tipo tem o armazenamento de menos de quatro bytes.  
  
 Esse erro pode acontecer no código que é C\+\+ de outra forma válidos.  
  
 O exemplo a seguir mostra uma condição que pode causar C1311.  
  
```  
char c = (char)"Hello, world";   // C1311  
char *d = (char*)"Hello, world";   // OK  
```