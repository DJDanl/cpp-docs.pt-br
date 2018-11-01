---
title: Como capturar exceções em código nativo lançadas a partir de MSIL
ms.date: 11/04/2016
helpviewer_keywords:
- exceptions, catching
- catching exceptions, thrown from MSIL
- MSIL, catching exceptions in native code
ms.assetid: c15afd2b-8505-43bf-8a4a-f1d41532a124
ms.openlocfilehash: 73c9a9af66a6e292c76b96ec47a5853684e602f9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50635552"
---
# <a name="how-to-catch-exceptions-in-native-code-thrown-from-msil"></a>Como capturar exceções em código nativo lançadas a partir de MSIL

No código nativo, você pode capturar a exceção de C++ nativo do MSIL.  Você pode capturar exceções de CLR com `__try` e `__except`.

Para obter mais informações, consulte [tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md) e [tratamento de exceções de C++](../cpp/cpp-exception-handling.md).

## <a name="example"></a>Exemplo

O exemplo a seguir define um módulo com duas funções, uma que gera uma exceção nativa e outra que gera uma exceção de MSIL.

```
// catch_MSIL_in_native.cpp
// compile with: /clr /c
void Test() {
   throw ("error");
}

void Test2() {
   throw (gcnew System::Exception("error2"));
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir define um módulo que captura uma nativo e uma exceção de MSIL.

```
// catch_MSIL_in_native_2.cpp
// compile with: /clr catch_MSIL_in_native.obj
#include <iostream>
using namespace std;
void Test();
void Test2();

void Func() {
   // catch any exception from MSIL
   // should not catch Visual C++ exceptions like this
   // runtime may not destroy the object thrown
   __try {
      Test2();
   }
   __except(1) {
      cout << "caught an exception" << endl;
   }

}

int main() {
   // catch native C++ exception from MSIL
   try {
      Test();
   }
   catch(char * S) {
      cout << S << endl;
   }
   Func();
}
```

```Output
error
caught an exception
```

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)