---
title: Ferramentas de vinculador LNK4086 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4086
dev_langs:
- C++
helpviewer_keywords:
- LNK4086
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 21a2ee7660f0ad78d04f7edb191929296c8d47a9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079226"
---
# <a name="linker-tools-warning-lnk4086"></a>Aviso LNK4086 (Ferramentas de Vinculador)

ponto de entrada 'function' não é stdcall com bytes 'número' argumentos; imagem não pode ser executada

O ponto de entrada para uma DLL deve ser `__stdcall`. Qualquer um recompilar a função com o [/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) opção ou especifique `__stdcall` ou WINAPI quando você define a função.