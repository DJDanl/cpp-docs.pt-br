---
title: Erro do compilador C3715
ms.date: 11/04/2016
f1_keywords:
- C3715
helpviewer_keywords:
- C3715
ms.assetid: ee5dce88-ddc4-4bdb-9464-47467ce1674f
ms.openlocfilehash: 13befc17b94fdf2c22cb84bc64ed55b9375b3473
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165906"
---
# <a name="compiler-error-c3715"></a>Erro do compilador C3715

' pointer ': deve ser um ponteiro para ' class '

Você especificou um ponteiro em [__hook](../../cpp/hook.md) ou [__unhook](../../cpp/unhook.md) que não apontava para uma classe válida. Para corrigir esse erro, certifique-se de que suas chamadas `__hook` e `__unhook` especifiquem ponteiros para classes válidas.
