---
title: "Compilador C4657 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4657"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4657"
ms.assetid: eb750050-cea6-4ead-b80c-d5dcd4971cfc
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4657 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

expressão envolve um tipo de dados é novo desde a última compilação  
  
 Você adicionou ou alterou um tipo de dados, tornando\-o novo ao código\-fonte desde a última compilação bem\-sucedida. Editar e continuar não dá suporte a alterações em tipos de dados existente.  
  
 Esse aviso sempre será seguido por [C1092 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](../Topic/Supported%20Code%20Changes%20\(C++\).md).  
  
### Para remover esse aviso sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados a seu estado antes do erro.  
  
2.  Do **Depurar** menu, escolha **Aplicar alterações de código**.  
  
### Para remover este erro sem alterar o código\-fonte  
  
1.  Do **Depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.