---
title: "Arquivos .Exp como entrada de vinculador | Microsoft Docs"
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
  - "Arquivos .exp [C++]"
  - "arquivos EXP"
  - "exportando dados, exportar arquivos (.exp)"
  - "exportando funções"
  - "exportando funções, informações sobre funções exportadas"
  - "funções [C++], exportando"
  - "importar bibliotecas, arquivos de vinculador"
  - "vinculando [C++], exporta"
ms.assetid: 399f5636-0a4d-462e-b500-5f5b9ae5ad22
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos .Exp como entrada de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os arquivos de exportação \(\) .exp contêm informações sobre itens exportados de funções e de dados.  Quando o LIB cria uma biblioteca de importação, o também cria um arquivo de .exp.  Você usa o arquivo de .exp quando você vincula um programa que exporte a e importe de outro programa, direta ou indiretamente.  Se você vincular a um arquivo de .exp, o LINK não gerencia uma biblioteca de importação, como pressupõe que o LIB já criou um.  Para obter detalhes sobre arquivos de .exp e bibliotecas de importação, consulte [Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md).  
  
## Consulte também  
 [Arquivos de entrada LINK](../../build/reference/link-input-files.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)