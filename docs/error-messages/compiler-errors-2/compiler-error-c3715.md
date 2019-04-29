---
title: Erro do compilador C3715
ms.date: 11/04/2016
f1_keywords:
- C3715
helpviewer_keywords:
- C3715
ms.assetid: ee5dce88-ddc4-4bdb-9464-47467ce1674f
ms.openlocfilehash: 94a451bbe936507ac3b33747065a9b6aac9edd02
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328322"
---
# <a name="compiler-error-c3715"></a>Erro do compilador C3715

'ponteiro': deve ser um ponteiro para o 'class'

Você especificou um ponteiro na [hook](../../cpp/hook.md) ou [unhook](../../cpp/unhook.md) que não apontou para uma classe válida. Para corrigir esse erro, certifique-se de que seu `__hook` e `__unhook` chamadas especificam ponteiros para classes válidos.