---
title: Aviso LNK4237 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4237
dev_langs:
- C++
helpviewer_keywords:
- LNK4237
ms.assetid: 87bfec39-5241-464f-9feb-517b49f352ea
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b1b6891d72e00fbf5f6f53842764d60b01d0fa07
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)
/SUBSYSTEM:NATIVE especificado durante a importação de 'dll'; Use /Subsystem: console ou /SUBSYSTEM:WINDOWS.  
  
 [/SUBSYSTEM:NATIVE](../../build/reference/subsystem-specify-subsystem.md) foi especificado ao criar um aplicativo do windows (Win32) que diretamente usa um ou mais destes procedimentos:  
  
-   Kernel32. dll  
  
-   Gdi32. dll  
  
-   User32. dll  
  
-   uma das dlls msvcrt *.  
  
 Resolver esse aviso não especificando **/SUBSYSTEM:NATIVE**.
