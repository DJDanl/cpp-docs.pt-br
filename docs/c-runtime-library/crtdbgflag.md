---
title: _crtDbgFlag | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _crtDbgFlag
- crtDbgFlag
dev_langs:
- C++
helpviewer_keywords:
- memory allocation, tracking flag
- crtDbgFlag constant
- _crtDbgFlag constant
- debug heap, tracking memory on
- debug heap, control flags
- enable memory allocation tracking flag
- memory, tracking on the debug heap
ms.assetid: 9e7adb47-8ab9-4e19-81d5-e2f237979973
caps.latest.revision: 8
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 4f4c3a874d59095d620a04d5ebb6ac88e2bdfa66
ms.lasthandoff: 02/25/2017

---
# <a name="crtdbgflag"></a>_crtDbgFlag
O sinalizador **_crtDbgFlag** é composto por cinco campos de bits que controlam como rastrear, verificar, relatar e despejar as alocações de memória da versão de depuração do heap. Os campos de bits do sinalizador são definidos pela função [_CrtSetDbgFlag](../c-runtime-library/reference/crtsetdbgflag.md). Esse sinalizador e seus campos de bits são declarados em Crtdbg.h. Esse sinalizador só fica disponível quando o sinalizador [_DEBUG](../c-runtime-library/debug.md) é definido no aplicativo.  
  
 Para saber mais sobre como usar esse sinalizador com outras funções de depuração, consulte [Funções de Relatório do Estado Heap](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="see-also"></a>Consulte também  
 [Sinalizadores de controle](../c-runtime-library/control-flags.md)
