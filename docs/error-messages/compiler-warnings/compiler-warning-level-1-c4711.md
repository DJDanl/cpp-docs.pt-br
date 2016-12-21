---
title: "Aviso do compilador (n&#237;vel 1) C4711 | Microsoft Docs"
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
  - "C4711"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4711"
ms.assetid: 270506ab-fead-4328-b714-2978113be238
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4711
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a função “function” selecionou para a expansão de tabela embutida  
  
 O compilador executou inlining na função especificada, embora não foi marcado inlining.  
  
 C4711 será habilitado se [\/Ob2](../../build/reference/ob-inline-function-expansion.md) é especificado.  
  
 Inlining é executado na discreção do compilador.  Esse aviso é informativo.  
  
 Esse aviso é desativada por padrão.  Para habilitar um aviso, use [aviso de \#pragma](../../preprocessor/warning.md).  Consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para maiores informações.