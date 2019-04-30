---
title: Aviso LNK4086 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4086
helpviewer_keywords:
- LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
ms.openlocfilehash: c6a5a0714e070e6cf3aee8efcdfbdfa07fa9ee69
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399922"
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)

ponto de entrada 'function' não é stdcall com bytes 'número' argumentos; imagem não pode ser executada

O ponto de entrada para uma DLL deve ser `__stdcall`. Qualquer um recompilar a função com o [/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) opção ou especifique `__stdcall` ou WINAPI quando você define a função.