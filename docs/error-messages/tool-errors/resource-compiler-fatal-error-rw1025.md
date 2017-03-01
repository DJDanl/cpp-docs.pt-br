---
title: Recurso compilador Erro Fatal RW1025 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RW1025
dev_langs:
- C++
helpviewer_keywords:
- RW1025
ms.assetid: 561a02af-e7e0-442a-8ad3-a00b2ca1b62e
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
ms.openlocfilehash: 4029f07c4025720f92e7ca95cadcd915c542dc6e
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-fatal-error-rw1025"></a>Erro fatal RW1025 (compilador de recurso)
Sem memória heap distante  
  
 Verifique se há software residente na memória que pode ocupar muito espaço. Use o programa CHKDSK para descobrir quanta memória você tiver.  
  
 Se você estiver criando um arquivo grande de recursos, dividir o script de recurso em dois arquivos. Depois de criar dois arquivos. res, use a linha de comando do MS-DOS para reuni-las:  
  
```  
copy first.res /b + second.res /b full.res  
```
