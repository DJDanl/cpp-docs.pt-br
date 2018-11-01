---
title: Aviso LNK4237 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4237
helpviewer_keywords:
- LNK4237
ms.assetid: 87bfec39-5241-464f-9feb-517b49f352ea
ms.openlocfilehash: 62ce0a0edc7f15bc5a19e4630133976f413da35a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588611"
---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)

/Subsystem: Native especificado durante a importação do 'dll'; Use /Subsystem: console ou /Subsystem: Windows.

[/Subsystem: Native](../../build/reference/subsystem-specify-subsystem.md) foi especificada ao criar um aplicativo do windows (Win32) que diretamente usa um ou mais das seguintes opções:

- kernel32.dll

- arquivo Gdi32.dll

- User32. dll

- um dos arquivo msvcrt\* dlls.

Resolver este aviso não especificando **/Subsystem: Native**.