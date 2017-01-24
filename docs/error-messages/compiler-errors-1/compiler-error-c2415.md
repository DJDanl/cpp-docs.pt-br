---
title: "C2415 de erro do compilador | Microsoft Docs"
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
  - "C2415"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2415"
ms.assetid: f225c913-2bea-46b1-b096-3d358ac94a15
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2415 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

tipo de operando inadequado  
  
 O não usa opcode operandos desse tipo.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Opcode o não oferece suporte ao número de operandos usados.  Verificar um manual da referência de assembly a idioma para determinar o número correto de operandos.  
  
2.  Um processador mais nova da suporte à instrução com tipos adicionais.  Ajuste a opção de [\/arch \(arquitetura mínima de CPU\)](../../build/reference/arch-minimum-cpu-architecture.md) usar o processador posterior.