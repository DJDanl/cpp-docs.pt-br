---
title: "Erro fatal C1055 | Microsoft Docs"
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
  - "C1055"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1055"
ms.assetid: a9fb9190-d7eb-4d5f-b1a2-a41e584a28c1
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1055
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: fora de chaves  
  
 O arquivo de origem contém muitos símbolos.  O compilador executado fora das chaves de hash para a tabela de símbolo.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Divida o arquivo de origem em arquivos menores.  
  
2.  Eliminar arquivos de cabeçalho desnecessários.  
  
3.  Reutilizar variáveis e temporários globais em vez de criar novos.