---
title: "Erro CXX0025 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0025"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0025"
  - "CXX0025"
ms.assetid: 3e2fb541-63b3-46ac-9f93-3dadb253bcf6
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0025 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador precisa do struct\/união  
  
 Um operador que usa uma expressão de `struct` ou de tipo de **union** foi aplicado a uma expressão que não é `struct` ou **union**.  
  
 Os componentes da classe, a estrutura, ou variáveis de união deve ter um nome totalmente qualificado.  Os componentes não podem ser inseridos sem especificação completa.  
  
 Esse erro é idêntico a CAN0025.