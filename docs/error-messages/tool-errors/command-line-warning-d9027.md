---
title: Linha de comando D9027 de aviso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D9027
dev_langs:
- C++
helpviewer_keywords:
- D9027
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2769eb5f78cb1d5bdd6749e65429d83b69a2807b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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