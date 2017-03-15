---
title: "ML Fatal Error A1017 | Microsoft Docs"
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
  - "A1017"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A1017"
ms.assetid: bef0b312-5431-4e5a-b637-c19919acf01b
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Fatal Error A1017
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**faltando nome de arquivo de origem**  
  
 ML não foi possível encontrar um arquivo para montar ou passar para o vinculador.  
  
 Este erro é gerado quando você fornecer opções de linha de comando ML sem especificar um nome de arquivo deve agir.  Para montar os arquivos que não têm uma extensão de .asm, use o  **\/Ta** a opção de linha de comando.  
  
 Esse erro também pode ser gerado invocando ML sem parâmetros, se a variável de ambiente ML contém opções de linha de comando.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)