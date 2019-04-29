---
title: Compilador aviso (nível 1) C4711
ms.date: 11/04/2016
f1_keywords:
- C4711
helpviewer_keywords:
- C4711
ms.assetid: 270506ab-fead-4328-b714-2978113be238
ms.openlocfilehash: c10b19b39fcb40527c9e9276f47ecff42ca5a643
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280380"
---
# <a name="compiler-warning-level-1-c4711"></a>Compilador aviso (nível 1) C4711

'function' selecionada para expansão embutida de função

O compilador executada inlining em determinada função, embora ele não foi marcado para inlining.

C4711 estará habilitada se [/Ob2](../../build/reference/ob-inline-function-expansion.md) for especificado.

Inlining é executada, a critério do compilador. Esse aviso é informativo.

Esse aviso é desativado por padrão. Para habilitar um aviso, use [#pragma aviso](../../preprocessor/warning.md). Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.