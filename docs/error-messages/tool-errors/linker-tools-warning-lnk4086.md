---
title: Aviso LNK4086 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4086
helpviewer_keywords:
- LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
ms.openlocfilehash: f692f848825cd3d8e5e1fc042cb94d7cce8ea6bf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87195805"
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)

o EntryPoint ' function ' não é __stdcall com ' Number ' bytes de argumentos; a imagem pode não ser executada

O ponto de entrada para uma DLL deve ser **`__stdcall`** . Recompile a função com a opção [/gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) ou ESPECIFIQUE **`__stdcall`** ou WINAPI tenha ao definir a função.
