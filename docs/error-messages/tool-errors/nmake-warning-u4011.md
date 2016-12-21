---
title: "Aviso U4011 (NMAKE) | Microsoft Docs"
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
  - "U4011"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U4011"
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso U4011 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“destino”: nem todos os objetos disponíveis; destino não compilado  
  
 Um dependente de destino fornecido não existia ou foi expirado, e um comando para atualizar o dependente retornou um código de saída diferente de zero.  A opção \/K os NMAKE para continuar a processar blocos de construção e não relacionados para emitir um código de saída 1 quando a sessão de NMAKE é concluída.  
  
 Esse aviso é precedido aviso [U4010](../Topic/NMAKE%20Warning%20U4010.md) para cada dependente que não criou ou não atualizados.