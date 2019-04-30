---
title: Compilador aviso (nível 1) C4160
ms.date: 08/27/2018
f1_keywords:
- C4160
helpviewer_keywords:
- C4160
ms.assetid: a9610cb7-cac4-4a74-8b4e-049030ebb92b
ms.openlocfilehash: 988c1fcbe0826582dceaa527811c688711fd8906
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391836"
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