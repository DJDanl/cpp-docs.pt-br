---
title: "Testando erros de extra&#231;&#227;o | Microsoft Docs"
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
  - "erros de extração"
ms.assetid: 6a681028-adba-4557-8f7b-f137932905f8
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Testando erros de extra&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções de processamento de erro de saída, discutidas em [Funções de processamento de erro](../standard-library/output-file-stream-member-functions.md), se aplicam aos fluxos de entrada.  Os testes para erros durante a extração são importantes.  Considere esta instrução:  
  
```  
cin >> n;  
```  
  
 Se `n` é um inteiro assinado, um valor maior que 32.767 \(o máximo permitido o valor, ou MAX\_INT\) definem o bit de `fail` de fluxo, e o objeto de `cin` se tornam inutilizáveis.  Todas as extrações subsequentes resultam em um retorno imediato sem o valor armazenado.  
  
## Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)