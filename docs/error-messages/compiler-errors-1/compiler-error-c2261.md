---
title: Erro do compilador C2261
ms.date: 11/04/2016
f1_keywords:
- C2261
helpviewer_keywords:
- C2261
ms.assetid: 60969482-9e83-49b5-9631-a04bc844da12
ms.openlocfilehash: f23c2a38f8e4d6781af73fb70a25cf4737e2c4e8
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758769"
---
# <a name="compiler-error-c2261"></a>Erro do compilador C2261

' String ': referência de assembly inválida e não pode ser resolvida

Um valor não era válido.

<xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> é usado para especificar um assembly Friend. Por exemplo, se a. dll quiser especificar b. dll como um assembly Friend, você especificaria (em uma. dll): InternalsVisibleTo ("b"). Em seguida, o tempo de execução permite que b. dll acesse tudo em um. dll (exceto tipos privados).

Para obter mais informações sobre a sintaxe correta ao especificar os assemblies Friend, consulte [Friend Assemblies (C++)](../../dotnet/friend-assemblies-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2261.

```cpp
// C2261.cpp
// compile with: /clr /c
using namespace System::Runtime::CompilerServices;
[assembly: InternalsVisibleTo("a,a,a")];   // C2261
[assembly: InternalsVisibleTo("a.a")];   // OK
[assembly: InternalsVisibleTo("a")];   // OK
```
