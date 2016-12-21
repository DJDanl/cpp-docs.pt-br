---
title: "Erro fatal U1073 (NMAKE) | Microsoft Docs"
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
  - "U1073"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1073"
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1073 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não saiba como fazer “targetname”  
  
 O destino especificado não existe, e não há nenhum comando para executar ou regra de inferência a ser aplicado.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Verifique a ortografia do nome de destino.  
  
2.  Se *o targetname* é um pseudotarget, especificá\-lo como um destino em outro bloco de descrição.  
  
3.  Se *o targetname* é uma invocação macro, certifique\-se de que não expande a uma cadeia de caracteres nula.