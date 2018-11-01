---
title: Erro do compilador C3665
ms.date: 11/04/2016
f1_keywords:
- C3665
helpviewer_keywords:
- C3665
ms.assetid: 893bb47e-8de1-43aa-af7d-fa47ad149ee9
ms.openlocfilehash: 30aaf67ac9f912059bb5726681e61feabc1e557d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644113"
---
# <a name="compiler-error-c3665"></a>Erro do compilador C3665

'destruidor': especificador 'palavra-chave' não é permitido em um destruidor/finalizador de substituição

Uma palavra-chave que não é permitido em um destruidor ou finalizador foi usada.

Por exemplo, um novo slot de não pode ser solicitado em um destruidor ou finalizador.  Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md) e [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

O exemplo a seguir gera C3665:

```
// C3665.cpp
// compile with: /clr
public ref struct R {
   virtual ~R() { }
   virtual void a() { }
};

public ref struct S : R {
   virtual ~S() new {}   // C3665
   virtual void a() new {}   // OK
};
```