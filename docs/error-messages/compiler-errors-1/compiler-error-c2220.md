---
title: "Erro do Compilador C2220 | Microsoft Docs"
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
  - "C2220"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2220"
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2220
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

aviso tratado como o erro \- nenhum arquivo do objeto gerado  
  
 [\/WX](../../build/reference/compiler-option-warning-level.md) informa que o compilador trata de todos os avisos como erros.  Como ocorreu um erro, nenhum objeto ou arquivo executável foi gerado.  
  
 Esse erro aparece somente quando o sinalizador **\/WX** é definido e um aviso aparece durante a compilação.  Para corrigir esse erro, você deve eliminar cada aviso em seu projeto.  
  
### Para corrigir, use uma das seguintes técnicas  
  
-   Corrija os problemas que causam avisos em seu projeto.  
  
-   Compile em um nível de aviso inferior, por exemplo, use **\/W3** em vez de **\/W4**.  
  
-   Use um pragma [warning](../../preprocessor/warning.md) para desabilitar ou suprimir um aviso específico.  
  
-   Não use **\/WX** para compilar.