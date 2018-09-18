---
title: Erro do compilador C3246 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3246
dev_langs:
- C++
helpviewer_keywords:
- C3246
ms.assetid: ad85224a-e540-479b-a5eb-a3bc3964c30b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a588067fa21e0aeee54516bcec28cdf3648ac9f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047805"
---
# <a name="compiler-error-c3246"></a>Erro do compilador C3246

'class': não pode herdar de 'type', pois ele foi declarado como 'sealed'

Uma classe que está marcada como [lacrado](../../windows/sealed-cpp-component-extensions.md) não pode ser a classe base para todas as outras classes.

O exemplo a seguir gera C3246:

```
// C3246_2.cpp
// compile with: /clr /LD
ref class X sealed {};

ref class Y : public X {}; // C3246
```
