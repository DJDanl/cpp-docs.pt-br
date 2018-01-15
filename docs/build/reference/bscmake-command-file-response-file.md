---
title: Arquivo de comando BSCMAKE (arquivo de resposta) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- BSCMAKE, response file
- BSCMAKE, command file
- response files, BSCMAKE
- command files, BSCMAKE
- response files
- command files
ms.assetid: abdffeea-35c7-4f2d-8c17-7d0d80bac314
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0c250af9f1af96bb051be0b2cd347ecd8d98d809
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bscmake-command-file-response-file"></a>Arquivo de comando BSCMAKE (arquivo de resposta)
Você pode fornecer parte ou toda a entrada de linha de comando em um arquivo de comando. Especifique o arquivo de comando usando a seguinte sintaxe:  
  
```  
BSCMAKE @filename  
```  
  
 Arquivo de comando somente uma é permitido. Você pode especificar um caminho com *filename*. Preceder *filename* com um sinal de arroba (@). BSCMAKE não assume uma extensão. Você pode especificar adicionais *sbrfiles* na linha de comando após *filename*. O arquivo de comando é um arquivo de texto que contém a entrada para BSCMAKE na mesma ordem como seria especificado na linha de comando. Separe os argumentos de linha de comando com um ou mais espaços, tabulações ou caracteres de nova linha.  
  
 O comando a seguir chama BSCMAKE usando um arquivo de comando:  
  
```  
BSCMAKE @prog1.txt  
```  
  
 Este é um arquivo de comando de exemplo:  
  
```  
/n /v /o main.bsc /El  
/S (  
toolbox.h  
verdate.h c:\src\inc\screen.h  
)  
file1.sbr file2.sbr file3.sbr file4.sbr  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)