---
title: "Erro fatal C1092 | Microsoft Docs"
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
  - "C1092"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1092"
ms.assetid: bcaa87f0-fbfc-4a33-844b-3b9f5d67f279
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1092
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A edição e Continue não dão suporte a alterações nos tipos de dados; construção necessária  
  
 Você adicionou ou modificou um tipo de dados desde a compilação bem\-sucedida a última vez.  
  
-   A edição e Continue não dão suporte a alterações nos tipos de dados existentes, incluindo a classe, o struct, ou as definições de enum.  Você deve parar de depuração e criar o aplicativo.  
  
-   A edição e Continue não dão suporte à adição de novas tipos de dados se um arquivo de base de dados do programa, como vcx 0.pdb \(onde *x* é a versão principal do Visual C\+\+ no uso\) é somente leitura.  Para adicionar tipos de dados, o compilador deve abrir o arquivo .pdb no modo de gravação.  
  
### Para remover este erro sem terminar a sessão atual de depuração  
  
1.  Alterar o tipo de dados a seu estado antes do erro.  
  
2.  No menu de **Depurar** , escolha **Aplicar Alterações de Código**.  
  
### Para remover este erro sem alterar seu código\-fonte  
  
1.  A partir do Menu **Debug**, escolha **Stop Debugging**.  
  
2.  No menu **Build**, escolha **Build**.  
  
 Para obter mais informações, consulte [Alterações de código com suporte](../Topic/Supported%20Code%20Changes%20\(C++\).md).