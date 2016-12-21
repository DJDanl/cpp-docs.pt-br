---
title: "Erro PRJ0032 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0032"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0032"
ms.assetid: bc6acbea-4041-4237-8b5a-f0434705d89f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0032 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A propriedade de “saída da etapa de criação personalizado do nível de projeto contém “a macro que avalia” out “ao macro\_expansion”.  
  
 Uma etapa de criação personalizado em um projeto tinha saída incorretos provavelmente devido a um problema macro de avaliação.  Esse erro também poderia significar que o caminho é formado ruim, contendo caracteres ou combinações de caracteres que são ilegais em um caminho de arquivo.  
  
 Para resolver este erro, corrija a macro ou corrigir a especificação de caminho.  O caminho valor de tabela é um caminho absoluto do diretório do projeto.