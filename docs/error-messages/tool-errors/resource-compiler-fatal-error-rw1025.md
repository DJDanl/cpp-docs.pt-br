---
title: Recurso compilador Erro Fatal RW1025 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RW1025
dev_langs:
- C++
helpviewer_keywords:
- RW1025
ms.assetid: 561a02af-e7e0-442a-8ad3-a00b2ca1b62e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ba216e63cb0cae92b4541800493a2fb6195553a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-compiler-fatal-error-rw1025"></a>Erro fatal RW1025 (compilador de recurso)
Sem memória heap distante  
  
 Verifique se há software residentes na memória que pode ser ocupando muito espaço. Use o programa CHKDSK para saber quanta memória você tiver.  
  
 Se você estiver criando um arquivo de recurso grande, divida o script de recurso em dois arquivos. Depois de criar dois arquivos. res, use a linha de comando MS-DOS para reuni-las:  
  
```  
copy first.res /b + second.res /b full.res  
```