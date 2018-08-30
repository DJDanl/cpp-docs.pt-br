---
title: Compilador aviso (nível 1) C4160 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4160
dev_langs:
- C++
helpviewer_keywords:
- C4160
ms.assetid: a9610cb7-cac4-4a74-8b4e-049030ebb92b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c62bf021065870f2ddd64cd7ee08cc00504cf7bd
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43219669"
---
# <a name="compiler-warning-level-1-c4160"></a>Compilador aviso (nível 1) C4160

> #<a name="pragma-pop--did-not-find-previously-pushed-identifier-identifier"></a>pragma (pop,...): não foi possível localizar o identificador anteriormente enviado '*identificador*'

## <a name="remarks"></a>Comentários

Uma instrução pragma no seu código-fonte tenta inserir um identificador que não tenha sido enviado. Para evitar esse aviso, certifique-se de que o identificador que estão sendo removido foi enviado corretamente.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4160 e mostra como corrigi-lo:

```cpp
// C4160.cpp
// compile with: /W1
#pragma pack(push)

#pragma pack(pop, id)   // C4160
// use identifier when pushing to resolve the warning
// #pragma pack(push, id)

int main() {
}
```