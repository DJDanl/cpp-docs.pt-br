---
title: Erro do compilador C3904
ms.date: 11/04/2016
f1_keywords:
- C3904
helpviewer_keywords:
- C3904
ms.assetid: 08297605-e4f2-4c6c-b637-011f1fd40631
ms.openlocfilehash: b2c5737a4442761cbaa84b532907e579eddb423d
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686059"
---
# <a name="compiler-error-c3904"></a>Erro do compilador C3904

' property_accessor ': deve especificar parâmetro (s) de número

Verifique o número de parâmetros em seus `get` métodos e em `set` relação às dimensões de propriedade.

- O número de parâmetros para o `get` método deve ser igual ao número de dimensões da propriedade ou ser zero para propriedades não indexadas.

- O número de parâmetros do `set` método deve ser mais um que o número de dimensões da propriedade.

Para obter mais informações, consulte [Propriedade](../../extensions/property-cpp-component-extensions.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3904.

```cpp
// C3904.cpp
// compile with: /clr /c
ref class X {
   property int P {
      // set
      void set();   // C3904
      // try the following line instead
      // void set(int);

      // get
      int get(int, int);   // C3904
      // try the following line instead
      // int get();
   };
};
```

O exemplo a seguir gera C3904.

```cpp
// C3904b.cpp
// compile with: /clr /c
ref struct X {
   property int Q[double, double, float, float, void*, int] {
      // set
      void set(double, void*);   // C3904
      // try the following line instead
      // void set(double, double, float, float, void*, int, int);

      // get
      int get();   // C3904
      // try the following line instead
      // int get(double, double, float, float, void*, int);
   }
};
```
