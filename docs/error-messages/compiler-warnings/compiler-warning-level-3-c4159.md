---
title: Compilador aviso (nível 3) C4159 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4159
dev_langs:
- C++
helpviewer_keywords:
- C4159
ms.assetid: e2cf964e-f4b8-4b2c-9569-1abb94307232
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 43e3d63ad1d482222c4ffa7aa7435d0e660f3985
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43223312"
---
# <a name="compiler-warning-level-3-c4159"></a>Compilador aviso (nível 3) C4159

> #<a name="pragma-pragmapop--has-popped-previously-pushed-identifier-identifier"></a>pragma pragma(pop,...): ativou o identificador anteriormente enviado '*identificador*'

## <a name="remarks"></a>Comentários

Seu código-fonte contém um **push** instrução com um identificador para um pragma seguido por um **pop-up** instrução sem um identificador. Como resultado, *identificador* é aparecidos e subsequentes usos da *identificador* pode causar um comportamento inesperado.

## <a name="example"></a>Exemplo

Para evitar esse aviso, dar um identificador do **pop-up** instrução. Por exemplo:

```cpp
// C4159.cpp
// compile with: /W3
#pragma pack(push, f)
#pragma pack(pop)   // C4159

// using the identifier resolves the warning
// #pragma pack(pop, f)

int main()
{
}
```