---
title: "Aviso do compilador (n&#237;vel 1) C4656 | Microsoft Docs"
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
  - "C4656"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4656"
ms.assetid: b5aaef74-2320-4345-a6ae-b813881a491c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4656
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo “”: o tipo de dados é novo ou foi alterado desde que o versão mais recente, ou é definido de forma diferente em outro lugar  
  
 Você adicionou ou modificou um tipo de dados, tornando o novo ao código\-fonte desde que a compilação bem\-sucedida a última vez.  A edição e Continue não dão suporte a alterações nos tipos de dados existentes.  
  
 Esse aviso será sempre seguido por [Erro fatal C1092](../../error-messages/compiler-errors-1/fatal-error-c1092.md).  Para obter mais informações, consulte [Alterações de código com suporte](../Topic/Supported%20Code%20Changes%20\(C++\).md).  
  
### Para remover esse aviso sem terminar a sessão atual de depuração  
  
1.  Alterar o tipo de dados a seu estado antes do erro.  
  
2.  No menu de **Depurar** , escolha **Aplicar Alterações de Código**.  
  
### Para remover este erro sem alterar seu código\-fonte  
  
1.  A partir do Menu **Debug**, escolha **Stop Debugging**.  
  
2.  No menu **Build**, escolha **Build**.