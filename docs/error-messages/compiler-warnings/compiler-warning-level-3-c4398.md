---
title: Compilador aviso (nível 3) C4398
ms.date: 11/04/2016
f1_keywords:
- C4398
helpviewer_keywords:
- C4398
ms.assetid: b6221432-9fed-4272-a547-a73f587904e6
ms.openlocfilehash: 4126a1267b41cdf9c0161c7e85a9057b2a301d77
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401963"
---
# <a name="compiler-warning-level-3-c4398"></a>Compilador aviso (nível 3) C4398

> '*variável*': objeto global de cada processo poderão não funcionar corretamente com múltiplos appdomains; considere o uso de __declspec(appdomain)

## <a name="remarks"></a>Comentários

Uma função virtual com [clrcall](../../cpp/clrcall.md) convenção de chamada em um tipo nativo faz com que a criação de um por vtable do domínio de aplicativo. Tipo de variável não pode corrigir corretamente quando usado em vários domínios de aplicativo.

Você pode resolver este aviso, marcando explicitamente a variável `__declspec(appdomain)`. Nas versões do Visual Studio anteriores ao Visual Studio 2017, você pode resolver este aviso, compilando com **/clr: pure**, que torna as variáveis globais por appdomain por padrão. O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [domínios de aplicativo e do Visual C++](../../dotnet/application-domains-and-visual-cpp.md).

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