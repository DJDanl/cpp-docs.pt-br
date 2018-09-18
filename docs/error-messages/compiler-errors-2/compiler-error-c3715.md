---
title: Erro do compilador C3715 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3715
dev_langs:
- C++
helpviewer_keywords:
- C3715
ms.assetid: ee5dce88-ddc4-4bdb-9464-47467ce1674f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 63ae3486b4db21a3aa241d5ebdbbfa0cdc6806f2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46026550"
---
# <a name="compiler-error-c3715"></a>Erro do compilador C3715

'ponteiro': deve ser um ponteiro para o 'class'

Você especificou um ponteiro na [hook](../../cpp/hook.md) ou [unhook](../../cpp/unhook.md) que não apontou para uma classe válida. Para corrigir esse erro, certifique-se de que seu `__hook` e `__unhook` chamadas especificam ponteiros para classes válidos.