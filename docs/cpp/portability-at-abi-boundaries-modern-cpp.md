---
title: Portabilidade nos limites da ABI
description: Nivelar C++ interfaces para C chamando convenções em limites de interface binários.
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: abbd405e-3038-427c-8c24-e00598f0936a
ms.openlocfilehash: b3b2b217739ff5900c8ef0329ff3e8909a3fe036
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303318"
---
# <a name="portability-at-abi-boundaries"></a>Portabilidade nos limites da ABI

Use tipos e convenções suficientemente portáteis em limites de interface binários. Um "tipo portátil" é um tipo interno C ou uma struct que contém apenas tipos internos de C. Os tipos de classe só podem ser usados quando o chamador e o receptor concordem no layout, na Convenção de chamada, etc. Isso só é possível quando ambos são compilados com as mesmas configurações de compilador e compilador.

## <a name="how-to-flatten-a-class-for-c-portability"></a>Como mesclar uma classe para portabilidade C

Quando os chamadores podem ser compilados com outro compilador/linguagem, então "achatar" para uma API **"C" externa** com uma Convenção de chamada específica:

```cpp
// class widget {
//   widget();
//   ~widget();
//   double method( int, gadget& );
// };
extern "C" {        // functions using explicit "this"
   struct widget;   // opaque type (forward declaration only)
   widget* STDCALL widget_create();      // constructor creates new "this"
   void STDCALL widget_destroy(widget*); // destructor consumes "this"
   double STDCALL widget_method(widget*, int, gadget*); // method uses "this"
}
```

## <a name="see-also"></a>Consulte também

[Bem-vindo de volta paraC++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
