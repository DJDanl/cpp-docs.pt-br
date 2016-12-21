---
title: "Usando abort | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "Abort"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função abort"
ms.assetid: 3ba39b78-ef74-4a8d-8dee-2d62442de174
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando abort
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamar a função [abort](../c-runtime-library/reference/abort.md) causa o encerramento imediato.  Ignora o processo normal de destruição para objetos estáticos globais inicializados.  Também ignora o processamento especial que foi especificado usando a função `atexit`.  
  
## Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)