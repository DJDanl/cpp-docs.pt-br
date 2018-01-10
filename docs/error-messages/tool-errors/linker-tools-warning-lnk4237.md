---
title: Aviso LNK4237 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4237
dev_langs: C++
helpviewer_keywords: LNK4237
ms.assetid: 87bfec39-5241-464f-9feb-517b49f352ea
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 718058dae02e9dfe9b653abea91993ec6662f5c1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)
/Subsystem: Native especificado durante a importação do 'dll'; Use /Subsystem ou /Subsystem: Windows.  
  
 [/Subsystem: Native](../../build/reference/subsystem-specify-subsystem.md) foi especificado ao criar um aplicativo do windows (Win32) que diretamente usa um ou mais dos seguintes:  
  
-   kernel32.dll  
  
-   Gdi32  
  
-   User32. dll  
  
-   uma das dlls msvcrt *.  
  
 Resolver este aviso não especificando **/Subsystem: Native**.