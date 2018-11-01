---
title: Aviso LNK4086 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4086
helpviewer_keywords:
- LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
ms.openlocfilehash: c6a5a0714e070e6cf3aee8efcdfbdfa07fa9ee69
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50427853"
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)

ponto de entrada 'function' não é stdcall com bytes 'número' argumentos; imagem não pode ser executada

O ponto de entrada para uma DLL deve ser `__stdcall`. Qualquer um recompilar a função com o [/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) opção ou especifique `__stdcall` ou WINAPI quando você define a função.