---
title: "Erro fatal C1054 | Microsoft Docs"
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
  - "C1054"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1054"
ms.assetid: 9cfb7307-b22a-4418-b7c0-2621b0ab5b1b
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1054
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: inicializadores muito profundamente aninhadas  
  
 O código exceder o limite de aninhamento em inicializadores \(10\-15 níveis, dependendo da combinação de tipos que estão sendo inicializados\).  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplificar os tipos de dados que estão sendo inicializados para reduzir o aninhamento.  
  
2.  Inicializar variáveis em instruções separadas depois da declaração.