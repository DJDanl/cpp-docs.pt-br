---
title: "Erro fatal CVT1100 (CVTRES) | Microsoft Docs"
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
  - "CVT1100"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CVT1100"
ms.assetid: 886e88dd-5818-4b5f-84f2-d2a3d75f0aaf
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal CVT1100 (CVTRES)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

recurso duplicado — tipo:type, nome:name, idioma:language, sinalizadores:flags, tamanho:size  
  
 O recurso foi especificado mais de uma vez.  
  
 Você pode obter esse erro se o vinculador estiver criando uma biblioteca de tipos e você não especificou [\/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md) e um recurso em seu projeto já usa 1.  Nesse caso, especifique \/TLBID e especifique outro número até 65535.