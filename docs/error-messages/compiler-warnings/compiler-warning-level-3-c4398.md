---
title: Aviso do compilador (nível 3) C4398
ms.date: 11/04/2016
f1_keywords:
- C4398
helpviewer_keywords:
- C4398
ms.assetid: b6221432-9fed-4272-a547-a73f587904e6
ms.openlocfilehash: 041bf9f6bfce17b16f301604bb8706be30095c13
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198660"
---
# <a name="compiler-warning-level-3-c4398"></a>Aviso do compilador (nível 3) C4398

> '*Variable*': o objeto global per-Process pode não funcionar corretamente com vários AppDomains; Considere o uso de __declspec (AppDomain)

## <a name="remarks"></a>Comentários

Uma função virtual com [__clrcall](../../cpp/clrcall.md) Convenção de chamada em um tipo nativo faz com que a criação de um domínio por aplicativo vtable. Essa variável pode não corrigir corretamente quando usada em vários domínios de aplicativo.

Você pode resolver esse aviso marcando explicitamente a variável `__declspec(appdomain)`. Em versões do Visual Studio antes do Visual Studio 2017, você pode resolver esse aviso compilando com **/CLR: Pure**, o que torna as variáveis globais por AppDomain por padrão. A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Para obter mais informações, consulte [AppDomain](../../cpp/appdomain.md) e [domínios de aplicativo C++e Visual ](../../dotnet/application-domains-and-visual-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4398.

```cpp
// C4398.cpp
// compile with: /clr /W3 /c
struct S {
   virtual void f( System::String ^ );   // String^ parameter makes function __clrcall
};

S glob_s;   // C4398
__declspec(appdomain) S glob_s2;   // OK
```
