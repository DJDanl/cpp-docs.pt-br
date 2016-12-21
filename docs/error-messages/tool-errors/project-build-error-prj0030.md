---
title: "Erro PRJ0030 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0030"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0030"
ms.assetid: c48b3727-e166-46e7-bcd7-3e5b2ac5c1d4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0030 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Erro de expansão de macro.Avalie a recursão exceder 32 níveis para macro $ \(\).  
  
 Este erro é causado pela recursão em seus macros.  Por exemplo, se você definir a propriedade de **Diretório Intermediário** \(consulte\) [Página de propriedades geral projeto \(\)](../Topic/General%20Property%20Page%20\(Project\).md)como $ \(IntDir\), você terá a recursão.  
  
 Para resolver esse erro, não defina macros ou propriedades em termos de macros que são usados para definir.