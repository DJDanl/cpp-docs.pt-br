---
title: "Erro fatal C1002 | Microsoft Docs"
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
  - "C1002"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1002"
ms.assetid: bd6d274a-c7b4-43af-8bf2-23c5e442aa22
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1002
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o compilador tem espaço do heap na passagem 2  
  
 O compilador faltou espaço de memória dinâmica durante sua segunda fase, provavelmente devido a um programa com símbolos ou expressões complexas demais.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Divida o arquivo de origem em vários arquivos menores.  
  
2.  Interromper expressões em subexpressões menores.  
  
3.  Remover outros programas ou drivers que consomem memória.