---
title: "Constantes de sinal | Microsoft Docs"
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
  - "SIGTERM"
  - "SIGFPE"
  - "SIGABRT"
  - "SIGILL"
  - "SIGINT"
  - "SIGSEGV"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante SIGABRT"
  - "Constante SIGFPE"
  - "Constante SIGILL"
  - "Constante SIGINT"
  - "constantes de sinal"
  - "Constante SIGSEGV"
  - "Constante SIGTERM"
ms.assetid: a3b39281-dae7-4e44-8d68-e6a610c669dd
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de sinal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
#include <signal.h>  
```  
  
## Comentários  
 O argumento de `sig` deve ser uma das constantes manifestas listadas abaixo \(definido em SIGNAL.H\).  
  
 `SIGABRT`  
 Encerramento anormal.  A ação padrão encerra o programa de chamada com o código de saída 3.  
  
 `SIGABRT_COMPAT`  
 Mesmo que SIGABRT.  Para compatibilidade com outras plataformas.  
  
 `SIGFPE`  
 Erro de ponto flutuante, como o estouro, de divisão por zero, ou a operação inválida.  A ação padrão encerra o programa de chamada.  
  
 `SIGILL`  
 Instrução ilegal.  A ação padrão encerra o programa de chamada.  
  
 `SIGINT`  
 CTRL\+C de interrupção.  A ação padrão encerra o programa de chamada com o código de saída 3.  
  
 `SIGSEGV`  
 Acesso ilegal de armazenamento.  A ação padrão encerra o programa de chamada.  
  
 `SIGTERM`  
 Solicitação de término enviada ao programa.  A ação padrão encerra o programa de chamada com o código de saída 3.  
  
 `SIG_ERR`  
 Um tipo de retorno de um sinal que indica um erro ocorreu.  
  
## Consulte também  
 [signal](../c-runtime-library/reference/signal.md)   
 [raise](../c-runtime-library/reference/raise.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)