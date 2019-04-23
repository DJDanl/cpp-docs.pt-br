---
title: Erro do compilador C3908
ms.date: 11/04/2016
f1_keywords:
- C3908
helpviewer_keywords:
- C3908
ms.assetid: 3c322482-c79e-4197-a578-2ad9bc379d1a
ms.openlocfilehash: e11d830c3d662ea424caadeb50df669700f8c78f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59778469"
---
# <a name="compiler-error-c3908"></a>Erro do compilador C3908

nível de acesso menos restritivo do que 'em construção'

Um método de acessador de propriedade (get ou set) não pode ter acesso menos restritivo do que o acesso especificado na propriedade em si.  Da mesma forma, para métodos de acessador de evento.

Para obter mais informações, consulte [propriedade](../../extensions/property-cpp-component-extensions.md) e [evento](../../extensions/event-cpp-component-extensions.md).

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