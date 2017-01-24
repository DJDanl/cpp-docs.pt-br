---
title: "Erro M6108 (Math) | Microsoft Docs"
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
  - "M6108"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "M6108"
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro M6108 (Math)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

raiz quadrada  
  
 O operando em uma operação de quadrado\- raiz não negativo.  
  
 O programa será encerrado com o código de saída 136.  
  
> [!NOTE]
>  A função de `sqrt` na biblioteca de tempo de execução C e a função intrínseca **SQRT** de FORTRAN não gerenciem esse erro.  As verificações de função C `sqrt` o argumento antes de executar a operação e retorna um erro avalia se o operando for negativo.  A função de **SQRT** FORTRAN gerencia o erro [M6201](../../error-messages/tool-errors/math-error-m6201.md) DOMAIN em vez desse erro.