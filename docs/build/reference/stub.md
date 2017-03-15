---
title: "STUB | Microsoft Docs"
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
  - "STUB"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução de arquivo .def STUB"
ms.assetid: 0a3b9643-19ed-47e9-8173-ee16bc8ed056
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# STUB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando usado em um arquivo de definição de módulo que cria um driver de dispositivo virtual \(VxD\), permite que você especifique um nome de arquivo que contenha uma estrutura de IMAGE\_DOS\_HEADER \(definida em WINNT.H\) a ser usado no driver do dispositivo virtual \(VxD\), em vez do cabeçalho padrão.  
  
```  
STUB:filename  
```  
  
## Comentários  
 Equivalente uma maneira de especificar *o nome de arquivo* é com o padrão do vinculador de [\/STUB](../../build/reference/stub-ms-dos-stub-file-name.md) .  
  
 O STUB é válido em um arquivo de definição de módulo apenas ao criar um VxD.  
  
## Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)