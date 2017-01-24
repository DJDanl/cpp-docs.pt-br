---
title: "Erro BK1513 (BSCMAKE) | Microsoft Docs"
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
  - "BK1513"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BK1513"
ms.assetid: 9ba87c09-8d82-4c80-b0cf-a8de63dcf9da
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro BK1513 (BSCMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a atualização não incremental exige todos os arquivos .SBR  
  
 BSCMAKE não pode compilar um novo arquivo de informações \(.bsc\) do navegador porque um ou mais arquivos .sbr estão truncados.  Para localizar os nomes dos arquivos .sbr truncados, leia os avisos [BK4502](../../error-messages/tool-errors/bscmake-warning-bk4502.md) que acompanham este erro.  
  
 BSCMAKE pode atualizar um arquivo .bsc com um arquivo .sbr truncado, mas não é possível compilar um novo.  BSCMAKE pode criar um novo arquivo .bsc pelos seguintes motivos:  
  
-   Arquivo .bsc ausente.  
  
-   Nome de arquivo especificado incorreto para o arquivo .bsc.  
  
-   Arquivo .bsc corrompido.  
  
 Para resolver esse problema, exclua os arquivos .sbr truncados e recompile\-os ou limpe a solução e refaça a compilação.  \(No IDE, escolha **Compilar**, **Limpar Solução** e, em seguida, escolha **Compilar**, **Recompilar Solução**.\)