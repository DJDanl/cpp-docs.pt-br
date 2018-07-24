---
title: Ferramentas de vinculador LNK4237 aviso | Microsoft Docs
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
ms.openlocfilehash: fcc109fe3ccf06e0461deed449517850271a2024
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39209385"
---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)
/Subsystem: Native especificado durante a importação do 'dll'; Use /Subsystem: console ou /Subsystem: Windows.  
  
 [/Subsystem: Native](../../build/reference/subsystem-specify-subsystem.md) foi especificada ao criar um aplicativo do windows (Win32) que diretamente usa um ou mais das seguintes opções:  
  
-   kernel32.dll  
  
-   arquivo Gdi32.dll  
  
-   User32. dll  
  
-   um dos arquivo msvcrt\* dlls.  
  
 Resolver este aviso não especificando **/Subsystem: Native**.