---
title: Erro do compilador C2261
ms.date: 11/04/2016
f1_keywords:
- C2261
helpviewer_keywords:
- C2261
ms.assetid: 60969482-9e83-49b5-9631-a04bc844da12
ms.openlocfilehash: 2df788efd93fb531822d858ea5aee1722487db81
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50535740"
---
# <a name="compiler-error-c2261"></a>Erro do compilador C2261

'string': referência de assembly é inválida e não pode ser resolvida

Um valor não era válido.

<xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> é usado para especificar um assembly amigável. Por exemplo, se quiser. dll especificar o b. dll como um assembly amigável, você especificaria (em dll): InternalsVisibleTo("b"). O tempo de execução, em seguida, permite que a b. dll acessar tudo na DLL (exceto tipos privados).

Para obter mais informações sobre a sintaxe correta ao especificar assemblies amigáveis, consulte [Assemblies de amigo (C++)](../../dotnet/friend-assemblies-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2261.

```
// C2261.cpp
// compile with: /clr /c
using namespace System::Runtime::CompilerServices;
[assembly: InternalsVisibleTo("a,a,a")];   // C2261
[assembly: InternalsVisibleTo("a.a")];   // OK
[assembly: InternalsVisibleTo("a")];   // OK
```