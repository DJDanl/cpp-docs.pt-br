---
title: "Arquivos de sa&#237;da LIB | Microsoft Docs"
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
  - "Lib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de saída, LIB"
ms.assetid: e73d2f9b-a42d-402b-b7e3-3a94bebb317e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos de sa&#237;da LIB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os arquivos de saída gerados por LIB dependem do modo no qual o está sendo usado, conforme mostrado na seguinte tabela.  
  
|Modo|Saída|  
|----------|-----------|  
|Opção \(criação ou modificação de uma biblioteca\)|Biblioteca de COFF \(.lib\)|  
|Extraindo um membro com \/EXTRACT|Arquivo de objeto \(.obj\)|  
|Criando uma biblioteca do arquivo de importação e exportação com \/DEF|Importar a biblioteca \(.lib\) e o arquivo de exportação \(.exp\)|  
  
## Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)