---
title: "Aviso PRJ0029 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0029"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0029"
ms.assetid: f02c09c6-09f3-4d44-8cd4-9a25336be1ea
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso PRJ0029 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto não está definida.A etapa de compilação personalizada será ignorada.  
  
 Uma etapa personalizado de construção não foi executada porque nenhuma saída foi especificada.  
  
 Para resolver esse erro, siga um o seguinte:  
  
-   Exclua a etapa personalizado de construção de compilação.  
  
-   Adicione uma saída.  
  
-   Excluir o conteúdo do comando personalizado da etapa de compilação.