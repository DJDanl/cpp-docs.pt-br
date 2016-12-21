---
title: "Aviso do compilador (n&#237;vel 1) C4010 | Microsoft Docs"
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
  - "C4010"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4010"
ms.assetid: d607a9ff-8f8f-45c0-b07b-3b2f439e5485
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4010
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o comentário de linha única contém o caractere de acompanhamento de linha  
  
 Um comentário de linha única, que é apresentado por \/\/, contém uma barra invertida \(\\\) que serve como um caractere de linha acompanhamento.  O compilador consulte a próxima linha ser uma acompanhamento e tratá\-los como um comentário.  
  
 Quaisquer publicadores redirecionados sintaxe\- não indicam a linha após o caractere de continuação como um comentário.  Ignorar a cores de sintaxe em todas as linhas que gerencia esse aviso.  
  
 O seguinte exemplo gera C4010:  
  
```  
// C4010.cpp  
// compile with: /WX  
int main() {  
   // the next line is also a comment because of the backslash \  
   int a = 3; // C4010  
   a++;  
}  
```