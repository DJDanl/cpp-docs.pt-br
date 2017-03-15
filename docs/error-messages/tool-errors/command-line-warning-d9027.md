---
title: Linha de comando aviso D9027 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D9027
dev_langs:
- C++
helpviewer_keywords:
- D9027
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b8d7841b6dbf3cdf42573104d958e53f7f2e115d
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-warning-d9027"></a>Aviso D9027 (linha de comando)
arquivo de origem '\<filename >' ignorado  
  
 CL.exe ignorado o arquivo de fonte de entrada.  
  
 Esse aviso pode ser causado por um espaço entre a opção /Fo e um nome de arquivo de saída em uma linha de comando com a opção /c. Por exemplo:  
  
```  
cl /c /Fo output.obj input.c   
```  
  
 Porque há um espaço entre /Fo e `output.obj,` CL.exe usa `output.obj` como o nome do arquivo de entrada. Para corrigir o problema, remova o espaço:  
  
```  
cl /c /Fooutput.obj input.c   
```
