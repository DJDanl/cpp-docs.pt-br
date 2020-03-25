---
title: Aviso LNK4086 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4086
helpviewer_keywords:
- LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
ms.openlocfilehash: 6e012ceb5e20855353c69bbcde85fb78afad2011
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183417"
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)

o EntryPoint ' function ' não é __stdcall com ' Number ' bytes de argumentos; a imagem pode não ser executada

O ponto de entrada para uma DLL deve ser `__stdcall`. Recompile a função com a opção [/gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) ou especifique `__stdcall` ou WINAPI tenha ao definir a função.
