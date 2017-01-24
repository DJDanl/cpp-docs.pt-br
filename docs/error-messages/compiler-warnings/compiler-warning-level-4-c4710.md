---
title: "Aviso do compilador (n&#237;vel 4) C4710 | Microsoft Docs"
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
  - "C4710"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4710"
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4710
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: função será embutida  
  
 A função determinada foi selecionada para a expansão embutido, mas o compilador não executou inlining.  
  
 Inlining é executado na discreção do compilador.  A palavra\-chave de **inline** , como a palavra\-chave de **register** , é usado como uma dica para o compilador.  O compilador usa heurística para determinar se ele deve embutido uma função específica acelerar o código durante a criação da velocidade, ou se ele deve embutido uma função específica tornar código durante a criação menor do espaço.  O compilador somente funções muito pequenas embutidos ao criar para o espaço.  
  
 Em alguns casos, o compilador não embutida uma função específica para razões mecânicas.  Consulte [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista dos motivos que o compilador não é uma função embutida.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.