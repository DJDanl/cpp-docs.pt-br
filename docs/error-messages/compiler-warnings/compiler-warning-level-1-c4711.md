---
title: Compilador aviso (nível 1) C4711 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4711
dev_langs:
- C++
helpviewer_keywords:
- C4711
ms.assetid: 270506ab-fead-4328-b714-2978113be238
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d184d5043dad1138f774ca7288a773bcc38c6d9f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46069932"
---
# <a name="compiler-warning-level-1-c4711"></a>Compilador aviso (nível 1) C4711

'function' selecionada para expansão embutida de função

O compilador executada inlining em determinada função, embora ele não foi marcado para inlining.

C4711 estará habilitada se [/Ob2](../../build/reference/ob-inline-function-expansion.md) for especificado.

Inlining é executada, a critério do compilador. Esse aviso é informativo.

Esse aviso é desativado por padrão. Para habilitar um aviso, use [#pragma aviso](../../preprocessor/warning.md). Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.