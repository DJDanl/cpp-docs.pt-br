---
title: "Arquivo de comando BSCMAKE (arquivo de resposta) | Microsoft Docs"
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
  - "BSCMAKE, arquivo de comando"
  - "BSCMAKE, arquivo de resposta"
  - "arquivos de comando"
  - "arquivos de comando, BSCMAKE"
  - "arquivos de resposta"
  - "arquivos de resposta, BSCMAKE"
ms.assetid: abdffeea-35c7-4f2d-8c17-7d0d80bac314
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivo de comando BSCMAKE (arquivo de resposta)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode fornecer a parte ou qualquer linha de comando entrou em um arquivo de comando.  Especificar o arquivo de comando usando a seguinte sintaxe:  
  
```  
BSCMAKE @filename  
```  
  
 Apenas um arquivo de comando é permitido.  Você pode especificar um caminho com o *nome de arquivo*.  Antecedeu *o nome do arquivo* com uma arroba \(@\).  BSCMAKE pressupõe que uma extensão.  Você pode especificar *sbrfiles* adicionais na linha de comando após *o nome do arquivo*.  O arquivo de comando é um arquivo de texto que contém entrada a BSCMAKE na mesma ordem que você especificaria o na linha de comando.  Separar os argumentos de linha de comando com um ou mais espaços, guias, ou caracteres de nova linha.  
  
 O comando a seguir chama BSCMAKE usando um arquivo de comando:  
  
```  
BSCMAKE @prog1.txt  
```  
  
 O seguinte é um arquivo de comando de exemplo:  
  
```  
/n /v /o main.bsc /El  
/S (  
toolbox.h  
verdate.h c:\src\inc\screen.h  
)  
file1.sbr file2.sbr file3.sbr file4.sbr  
```  
  
## Consulte também  
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)