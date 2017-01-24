---
title: "Executando um programa em pr&#233;-processamento | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "execução de programa [C++]"
ms.assetid: 5ecf123a-20e5-40cd-b8d8-dd5a9fdd4b24
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Executando um programa em pr&#233;-processamento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para usar o código de saída de um comando durante o pré\-processamento, especifique o comando, com os argumentos, dentro de colchetes \(\[\]\).  Todos os macros são expandidos antes que o comando seja executado.  NMAKE substitui a especificação de comando com o código de saída do comando, que pode ser usado em uma expressão para controlar pré\-processamento.  
  
## Consulte também  
 [Expressões no pré\-processamento de makefile](../build/expressions-in-makefile-preprocessing.md)