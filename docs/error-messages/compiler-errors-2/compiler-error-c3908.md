---
title: Erro do compilador C3908
ms.date: 11/04/2016
f1_keywords:
- C3908
helpviewer_keywords:
- C3908
ms.assetid: 3c322482-c79e-4197-a578-2ad9bc379d1a
ms.openlocfilehash: 84b21f20cbc8203a9cd70e487738c34c6ad3a89b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598920"
---
# <a name="compiler-error-c3908"></a>Erro do compilador C3908

nível de acesso menos restritivo do que 'em construção'

Um método de acessador de propriedade (get ou set) não pode ter acesso menos restritivo do que o acesso especificado na propriedade em si.  Da mesma forma, para métodos de acessador de evento.

Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md) e [evento](../../windows/event-cpp-component-extensions.md).

O exemplo a seguir gera C3908:

```
// C3908.cpp
// compile with: /clr
ref class X {
protected:
   property int i {
   public:   // C3908 property i is protected
      int get();
   private:
      void set(int);   // OK more restrictive
   };
};
```