---
title: Erro do compilador C2555
ms.date: 11/04/2016
f1_keywords:
- C2555
helpviewer_keywords:
- C2555
ms.assetid: 5e49ebb8-7c90-457a-aa12-7ca7ab6574b2
ms.openlocfilehash: ebf3e4a3aff48311edd5fb95b01a7b2d23990231
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202418"
---
# <a name="compiler-error-c2555"></a>Erro do compilador C2555

' class1:: function1 ': tipo de retorno da função virtual de substituição difere e não é covariant de ' class2:: function2 '

Uma função virtual e uma função de substituição derivada têm listas de parâmetros idênticas, mas diferentes tipos de retorno. Uma função de substituição em uma classe derivada não pode diferir de uma função virtual em uma classe base somente por seu tipo de retorno.

Para resolver esse erro, converta o valor de retorno depois que a função virtual tiver sido chamada.

Você também poderá ver esse erro se compilar com/CLR.   Por exemplo, o equivalente C++ Visual para a seguinte C# declaração:

```
Guid[] CheckSources(Guid sourceID, Guid[] carouselIDs);
```

é

```
Guid CheckSources(Guid sourceID, Guid carouselIDs[]) [];
```

O exemplo a seguir gera C2555:

```cpp
// C2555.cpp
// compile with: /c
struct X {
   virtual void func();
};
struct Y : X {
   char func();  // C2555
   void func2();   // OK
};
```
