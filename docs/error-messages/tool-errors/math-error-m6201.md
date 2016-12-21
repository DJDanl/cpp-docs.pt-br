---
title: "Erro M6201 (Math) | Microsoft Docs"
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
  - "M6201"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "M6201"
ms.assetid: 4041c331-d9aa-4dd4-b565-7dbe0218538c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro M6201 (Math)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: erro de \_DOMAIN  
  
 Um argumento para a função foi determinada fora do domínio de valores de entrada válidos para essa função.  
  
## Exemplo  
  
```  
result = sqrt(-1.0)   // C statement  
result = SQRT(-1.0)   !  FORTRAN statement  
```  
  
 Esse erro chama a função de `_matherr` com o nome, seus argumentos, e o tipo de erro.  Você pode reescrever a função de `_matherr` para personalizar a manipulação de erros de ponto flutuante matemáticas de determinado tempo de execução.