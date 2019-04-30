---
title: Erro do compilador C3904
ms.date: 11/04/2016
f1_keywords:
- C3904
helpviewer_keywords:
- C3904
ms.assetid: 08297605-e4f2-4c6c-b637-011f1fd40631
ms.openlocfilehash: 4675bf95012c8e6662d7dba281c38ed2d684c448
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406763"
---
# <a name="compiler-error-c3904"></a>Erro do compilador C3904

'property_accessor': deve especificar o parâmetro de número (s)

Verifique o número de parâmetros em seu `get` e `set` métodos em dimensões de propriedade.

- O número de parâmetros para o `get` método deve ser igual ao número de dimensões da propriedade ou ser zero para propriedades não indexadas.

- O número de parâmetros do `set` método deve ser um mais do que o número de dimensões da propriedade.

Para obter mais informações, consulte [propriedade](../../extensions/property-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3904.

```
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

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3904.

```
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