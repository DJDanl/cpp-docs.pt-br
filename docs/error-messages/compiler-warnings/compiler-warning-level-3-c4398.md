---
title: Compilador aviso (nível 3) C4398 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4398
dev_langs:
- C++
helpviewer_keywords:
- C4398
ms.assetid: b6221432-9fed-4272-a547-a73f587904e6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c38ade6b75242fdd5144481e3415e914cb6773c5
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704608"
---
# <a name="compiler-warning-level-3-c4398"></a>Compilador C4398 de aviso (nível 3)

> '*variável*': objeto global por processo poderão não funcionar corretamente com múltiplos appdomains; considere o uso de __declspec(appdomain)

## <a name="remarks"></a>Comentários

Uma função virtual com [clrcall](../../cpp/clrcall.md) convenção de chamada em um tipo nativo faz com que a criação de uma por vtable de domínio de aplicativo. Essa variável não pode corrigir corretamente quando usados em vários domínios de aplicativo.

Você pode resolver este aviso marcando explicitamente a variável `__declspec(appdomain)`. Nas versões do Visual Studio antes de 2017 do Visual Studio, você pode resolver este aviso ao compilar com **/clr: pure**, que torna as variáveis globais por appdomain por padrão. O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [domínios do aplicativo e do Visual C++](../../dotnet/application-domains-and-visual-cpp.md).

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