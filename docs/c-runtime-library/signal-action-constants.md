---
title: "Constantes de a&#231;&#227;o de sinal | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "SIG_IGN"
  - "SIG_DFL"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante SIG_DFL"
  - "Constante SIG_IGN"
  - "constantes de ação de sinal"
ms.assetid: c3cb4f15-d39e-4d9d-84f9-0d33e3eb5993
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de a&#231;&#227;o de sinal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A ação tomada quando o sinal de interrupção é recebido depende do valor de `func`.  
  
## Sintaxe  
  
```  
#include <signal.h>  
```  
  
## Comentários  
 O argumento de `func` deve ser um endereço de função ou uma das constantes manifestas listadas abaixo e definidas em SIGNAL.H.  
  
 `SIG_DFL`  
 Resposta de sistema padrão do.  Se o programa de chamada fluxo de E\/S, os buffers criadas pela biblioteca de tempo de execução não são liberados.  
  
 `SIG_IGN`  
 Ignora o sinal de interrupção.  Esse valor nunca deve ser atribuído a `SIGFPE`, desde que o estado de ponto flutuante do processo for deixado indefinido.  
  
 `SIG_SGE`  
 Indica um erro ocorreu no sinal.  
  
 `SIG_ACK`  
 Indica que uma confirmação esteve recebida.  
  
 `SIG_ERR`  
 Um tipo de retorno de um sinal que indica um erro ocorreu.  
  
## Consulte também  
 [signal](../c-runtime-library/reference/signal.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)