---
title: "Coprocessador de ponto flutuante e conven&#231;&#245;es de chamada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "processador de ponto flutuante"
  - "números de ponto flutuante"
  - "números de ponto flutuante, coprocessador"
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Coprocessador de ponto flutuante e conven&#231;&#245;es de chamada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você estiver escrevendo rotinas de assembly para o coprocessador de ponto flutuante, será necessário preservar as palavras de controle de ponto flutuante e limpar a pilha do coprocessador a menos que esteja retornando um valor **float** ou **double** \(que sua função deve retornar em ST\(0\)\).  
  
## Consulte também  
 [Convenções de chamada](../Topic/Calling%20Conventions.md)