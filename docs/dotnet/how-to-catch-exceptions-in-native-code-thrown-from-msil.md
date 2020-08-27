---
title: 'Como: capturar exceções em código nativo lançadas pela MSIL'
description: Exemplos de como capturar exceções no código nativo lançado do MSIL.
ms.date: 11/04/2016
helpviewer_keywords:
- exceptions, catching
- catching exceptions, thrown from MSIL
- MSIL, catching exceptions in native code
ms.assetid: c15afd2b-8505-43bf-8a4a-f1d41532a124
ms.openlocfilehash: b68a771d27e091f86331703b55bc2eb52dfbb41b
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898574"
---
# <a name="how-to-catch-exceptions-in-native-code-thrown-from-msil"></a>Como: capturar exceções em código nativo lançadas pela MSIL

No código nativo, você pode capturar a exceção C++ nativa do MSIL.  Você pode capturar exceções CLR com **`__try`** e **`__except`** .

Para obter mais informações, consulte as práticas recomendadas de [manipulação de exceção estruturada (C/c++)](../cpp/structured-exception-handling-c-cpp.md) e [c++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md).

## <a name="example-1"></a>Exemplo 1

O exemplo a seguir define um módulo com duas funções, uma que gera uma exceção nativa e outra que gera uma exceção MSIL.

```cpp
// catch_MSIL_in_native.cpp
// compile with: /clr /c
void Test() {
   throw ("error");
}

void Test2() {
   throw (gcnew System::Exception("error2"));
}
```

## <a name="example-2"></a>Exemplo 2

O exemplo a seguir define um módulo que captura uma exceção nativa e MSIL.

```cpp
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

## <a name="see-also"></a>Confira também

[Tratamento de exceção](../extensions/exception-handling-cpp-component-extensions.md)
