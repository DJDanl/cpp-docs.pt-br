---
title: "Estouro negativo de valores de ponto flutuante | Microsoft Docs"
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
  - "C"
ms.assetid: 78af8016-643c-47db-b4f1-7f06cb4b243e
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estouro negativo de valores de ponto flutuante
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 4.5.1** Se as funções matemáticas definem a expressão de inteiro `errno` como o valor da macro `ERANGE` em erros de intervalo de estouro negativo  
  
 Um estouro negativo de ponto flutuante não define a expressão `errno` como `ERANGE`.  Quando um valor se aproxima de zero e acaba sofrendo um estouro negativo, o valor é definido como zero.  
  
## Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)