---
title: Erro do compilador C3715
ms.date: 11/04/2016
f1_keywords:
- C3715
helpviewer_keywords:
- C3715
ms.assetid: ee5dce88-ddc4-4bdb-9464-47467ce1674f
ms.openlocfilehash: c3aff142215286a94a261a1f0fcb411296b57d5a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230773"
---
# <a name="compiler-error-c3715"></a>Erro do compilador C3715

' pointer ': deve ser um ponteiro para ' class '

Você especificou um ponteiro em [`__hook`](../../cpp/hook.md) ou [`__unhook`](../../cpp/unhook.md) que não apontava para uma classe válida. Para corrigir esse erro, verifique se o **`__hook`** e as **`__unhook`** chamadas especificam ponteiros para classes válidas.
