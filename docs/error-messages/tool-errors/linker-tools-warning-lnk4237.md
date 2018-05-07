---
title: Aviso LNK4237 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4237
dev_langs:
- C++
helpviewer_keywords:
- LNK4237
ms.assetid: 87bfec39-5241-464f-9feb-517b49f352ea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5acccf52d3738985c7a83432342952af03bf78b4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)
/Subsystem: Native especificado durante a importação do 'dll'; Use /Subsystem ou /Subsystem: Windows.  
  
 [/Subsystem: Native](../../build/reference/subsystem-specify-subsystem.md) foi especificado ao criar um aplicativo do windows (Win32) que diretamente usa um ou mais dos seguintes:  
  
-   kernel32.dll  
  
-   Gdi32  
  
-   User32. dll  
  
-   uma das dlls msvcrt *.  
  
 Resolver este aviso não especificando **/Subsystem: Native**.