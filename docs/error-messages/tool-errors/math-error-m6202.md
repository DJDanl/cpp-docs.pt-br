---
title: "Erro M6202 (Math) | Microsoft Docs"
ms.custom: ""
ms.date: "11/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "M6202"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "M6202"
ms.assetid: 4d17045f-c6dc-4705-9512-e9af12c35fb4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro M6202 (Math)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: erro de \_SING  
  
 Um argumento para a função determinada fosse um valor de singularidade para essa função.  A função não é definida para esse argumento.  
  
 Esse erro chama a função de `_matherr` com o nome, seus argumentos, e o tipo de erro.  Você pode reescrever a função de `_matherr` para personalizar a manipulação de erros de ponto flutuante matemáticas de determinado tempo de execução.