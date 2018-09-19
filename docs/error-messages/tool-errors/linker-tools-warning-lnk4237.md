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
ms.openlocfilehash: 479bd4ff8a4f48da679c9e17ec100668de84d089
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46113702"
---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)

/Subsystem: Native especificado durante a importação do 'dll'; Use /Subsystem: console ou /Subsystem: Windows.

[/Subsystem: Native](../../build/reference/subsystem-specify-subsystem.md) foi especificada ao criar um aplicativo do windows (Win32) que diretamente usa um ou mais das seguintes opções:

- kernel32.dll

- arquivo Gdi32.dll

- User32. dll

- um dos arquivo msvcrt\* dlls.

Resolver este aviso não especificando **/Subsystem: Native**.