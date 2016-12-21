---
title: "Aviso do compilador (n&#237;vel 1) C4042 | Microsoft Docs"
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
  - "C4042"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4042"
ms.assetid: e4bd861b-1194-426b-bf79-68c5b021eb0a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4042
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: tem a classe de armazenamento incorreto  
  
 A classe de armazenamento especificada não pode ser usada com esse identificador neste contexto.  O compilador usa a classe de armazenamento padrão em vez:  
  
-   `extern`, se o *identificador* é uma função.  
  
-   **auto**, se *o identificador* é um parâmetro formal ou variável local.  
  
-   Nenhuma classe de armazenamento, se *o identificador* é uma variável global.  
  
 Esse aviso pode ser causado especificando uma classe de armazenamento diferente **register** em uma declaração de parâmetro.  
  
 O exemplo C4042 gerencia  
  
```  
// C4042.cpp  
// compile with: /W1 /LD  
int func2( __declspec( thread ) int tls_i )    // C4042  
// try the following line instead  
// int func2( int tls_i )  
{  
   return tls_i;  
}  
```