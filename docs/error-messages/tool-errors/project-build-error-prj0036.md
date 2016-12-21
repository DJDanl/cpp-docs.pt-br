---
title: "Erro PRJ0036 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0036"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0036"
ms.assetid: ee215cd1-2d66-474d-9a63-b9096f1c4923
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0036 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A propriedade 'Additional Files' para a Ferramenta de Implantação da Web continha uma entrada inválida.  
  
 A propriedade de arquivos extra na página de propriedades de implantação de Web continha um erro, possivelmente devido a um problema macro de avaliação.  Esse erro também poderia significar que o caminho é formado ruim, contendo caracteres ou combinações de caracteres que são ilegais em um caminho de arquivo.  
  
 Para resolver este erro, corrija a macro ou corrigir a especificação de caminho.  O caminho valor de tabela é um caminho absoluto do diretório do projeto.  
  
 Esse erro também poderia significar que um dos arquivos referenciados não existe.