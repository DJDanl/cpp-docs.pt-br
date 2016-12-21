---
title: "C2099 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C2099"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2099"
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2099 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

inicializador não é uma constante  
  
 Esse erro é emitido apenas pelo compilador C e ocorre apenas para variáveis não automático.  O compilador inicializa variáveis não automático no início do programa e os valores que são inicializados com devem ser constantes.  
  
## Exemplo  
 O exemplo a seguir gera C2099.  
  
```  
// C2099.c int j; int *p; j = *p;   // C2099 *p is not a constant  
```  
  
## Exemplo  
 C2099 também pode ocorrer porque o compilador não é capaz de executar a dobra constante em uma expressão em **\/fp:strict** porque o ponto flutuante configurações de ambiente de precisão \(consulte [\_controlfp\_s](../../c-runtime-library/reference/controlfp-s.md) para obter mais informações\) pode ser diferente da compilação para tempo de execução.  
  
 Quando constante dobra falhar, o compilador invocará inicialização dinâmica, que não é permitida em C.  
  
 Para resolver esse erro, compilar o módulo como um arquivo. cpp ou simplificar a expressão.  
  
 Para obter mais informações, consulte [\/fp \(especificar comportamento de ponto flutuante\)](../../build/reference/fp-specify-floating-point-behavior.md).  
  
 O exemplo a seguir gera C2099.  
  
```  
// C2099_2.c // compile with: /fp:strict /c float X = 2.0 - 1.0;   // C2099 float X2 = 1.0;   // OK  
```