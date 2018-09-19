---
title: Compilador aviso (nível 3) C4073 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4073
dev_langs:
- C++
helpviewer_keywords:
- C4073
ms.assetid: 50081a6e-6acd-45ff-8484-9b1ea926cc5c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 24af5c41a524b4178f1402008203959c4e6b021d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088612"
---
# <a name="compiler-warning-level-3-c4073"></a>Compilador aviso (nível 3) C4073

inicializadores colocados em área de inicialização da biblioteca

Somente os desenvolvedores de biblioteca de terceiros devem usar a área de inicialização da biblioteca, que é especificada pelo [#pragma init_seg](../../preprocessor/init-seg.md). O exemplo a seguir gera C4073:

```
// C4073.cpp
// compile with: /W3
#pragma init_seg(lib)   // C4073

// try this line to resolve the warning
// #pragma init_seg(user)

int main() {
}
```