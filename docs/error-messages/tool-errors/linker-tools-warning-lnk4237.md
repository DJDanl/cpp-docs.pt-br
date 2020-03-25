---
title: Aviso LNK4237 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4237
helpviewer_keywords:
- LNK4237
ms.assetid: 87bfec39-5241-464f-9feb-517b49f352ea
ms.openlocfilehash: aaa26393f1ce76d3e1bc40e5ba4978d1bcdb4fc9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193752"
---
# <a name="linker-tools-warning-lnk4237"></a>Aviso LNK4237 (Ferramentas de Vinculador)

/SUBSYSTEM: NATIVE especificado ao importar de ' dll '; Use/SUBSYSTEM: CONSOLE ou/SUBSYSTEM: WINDOWS.

[/SUBSYSTEM: Native](../../build/reference/subsystem-specify-subsystem.md) foi especificado ao criar um aplicativo do Windows (Win32) que usa diretamente um ou mais dos seguintes:

- kernel32.dll

- gdi32.dll

- user32.dll

- uma das DLLs do\* do msvcrt.

Resolva este aviso não especificando **/SUBSYSTEM: Native**.
