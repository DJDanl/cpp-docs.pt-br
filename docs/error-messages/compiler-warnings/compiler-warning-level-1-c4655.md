---
title: "Compilador C4655 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4655"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4655"
ms.assetid: 540f2c7a-e4a1-49af-84b4-03eeea1bbf41
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4655 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**'**   
 ***Símbolo*  ': o tipo de variável é novo desde a última compilação ou é definido de forma diferente em outro lugar**  
  
 Você alterados ou adicionados a um novo tipo de dados desde a última compilação bem\-sucedida. Editar e continuar não dá suporte a alterações em tipos de dados existente.  
  
 Esse aviso é seguido por um [C1092 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](../Topic/Supported%20Code%20Changes%20\(C++\).md).  
  
### Para remover esse aviso sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados a seu estado antes do erro.  
  
2.  Do **Depurar** menu, escolha **Aplicar alterações de código**.  
  
### Para remover esse aviso sem alterar o código\-fonte  
  
1.  Do **Depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.