---
title: Linha de comando D9027 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9027
dev_langs:
- C++
helpviewer_keywords:
- D9027
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dfe2493290c4e4cc5b744136b8e7036c6559220a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="command-line-warning-d9027"></a>Aviso D9027 (linha de comando)
arquivo de origem '\<filename >' ignorado  
  
 CL.exe ignorado o arquivo de fonte de entrada.  
  
 Esse aviso pode ser causado por um espaço entre a opção /Fo e um nome de arquivo de saída em uma linha de comando com a opção /c. Por exemplo:  
  
```  
cl /c /Fo output.obj input.c   
```  
  
 Porque há um espaço entre /Fo e `output.obj`, CL.exe usa `output.obj` como o nome do arquivo de entrada. Para corrigir o problema, remova o espaço:  
  
```  
cl /c /Fooutput.obj input.c   
```