---
title: "Erro M6203 (Math) | Microsoft Docs"
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
  - "M6203"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "M6203"
ms.assetid: bd7fdd1c-83e4-4d6a-901e-10a0308bf5be
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro M6203 (Math)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: erro de \_OVERFLOW  
  
 O resultado fornecido da função era muito grande para ser representado.  
  
 Esse erro chama a função de `_matherr` com o nome, seus argumentos, e o tipo de erro.  Você pode reescrever a função de `_matherr` para personalizar a manipulação de erros de ponto flutuante matemáticas de determinado tempo de execução.