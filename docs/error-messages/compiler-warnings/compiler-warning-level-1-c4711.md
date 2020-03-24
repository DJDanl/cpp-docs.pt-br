---
title: Aviso do compilador (nível 1) C4711
ms.date: 11/04/2016
f1_keywords:
- C4711
helpviewer_keywords:
- C4711
ms.assetid: 270506ab-fead-4328-b714-2978113be238
ms.openlocfilehash: 9e2adf3583012a670f936c2b86a9ddc393fe53c6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175331"
---
# <a name="compiler-warning-level-1-c4711"></a>Aviso do compilador (nível 1) C4711

função ' function ' selecionada para expansão embutida

O compilador realizou a inbase na função especificada, embora não tenha sido marcada para inlining.

C4711 será habilitado se [/Ob2](../../build/reference/ob-inline-function-expansion.md) for especificado.

O inlining é executado no critério do compilador. Esse aviso é informativo.

Esse aviso está desativado por padrão. Para habilitar um aviso, use [#pragma Aviso](../../preprocessor/warning.md). Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.
