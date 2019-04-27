---
title: Erro do compilador C3218
ms.date: 11/04/2016
f1_keywords:
- C3218
helpviewer_keywords:
- C3218
ms.assetid: 0eea19e0-503e-4e07-ae8b-2cb2e95922cd
ms.openlocfilehash: 87084f9751b1593ec93a3062f23714bba403da9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182516"
---
# <a name="compiler-error-c3218"></a>Erro do compilador C3218

'type': não é permitido como uma restrição de tipo

Para um tipo seja uma restrição, ele deve ser um tipo de valor ou uma referência a uma classe gerenciada ou interface.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3218.

```
// C3218.cpp
// compile with: /clr /c
class A {};
ref class B {};

// Delete the following 3 lines to resolve.
generic <class T>
where T : A   // C3218
ref class C {};

// OK
generic <class T>
where  T : B
ref class D {};
```