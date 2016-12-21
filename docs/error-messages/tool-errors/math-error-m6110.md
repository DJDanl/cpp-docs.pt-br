---
title: "Erro M6110 (Math) | Microsoft Docs"
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
  - "M6110"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "M6110"
ms.assetid: aac9ae37-6a6d-46e9-85d4-dfe03f1c3e11
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro M6110 (Math)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

estouro de pilha  
  
 Uma expressão de ponto flutuante gerou um estouro da pilha de ponto flutuante.  
  
 As exceções de ponto flutuante de permissão com base em fila estouro são interceptadas até um limite de sete níveis além dos oito níveis geralmente suportados por co\-processador de 8087\/287\/387.  
  
 O programa será encerrado com o código de saída 138.