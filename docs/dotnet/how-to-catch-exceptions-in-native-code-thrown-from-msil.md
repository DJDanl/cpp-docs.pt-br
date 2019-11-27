---
title: Como capturar exceções em código nativo lançadas a partir de MSIL
ms.date: 11/04/2016
helpviewer_keywords:
- exceptions, catching
- catching exceptions, thrown from MSIL
- MSIL, catching exceptions in native code
ms.assetid: c15afd2b-8505-43bf-8a4a-f1d41532a124
ms.openlocfilehash: c3afa29d8c9bee1c1f1cc2fd1869d108c08a249b
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246685"
---
# <a name="how-to-catch-exceptions-in-native-code-thrown-from-msil"></a>Como capturar exceções em código nativo lançadas a partir de MSIL

No código nativo, você pode capturar a C++ exceção nativa do MSIL.  Você pode capturar exceções CLR com `__try` e `__except`.

Para obter mais informações, consulte [manipulação de exceção estruturadaC++(C/)](../cpp/structured-exception-handling-c-cpp.md) e [práticas recomendadas modernas C++ para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir define um módulo com duas funções, uma que gera uma exceção nativa e outra que gera uma exceção MSIL.

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

O exemplo a seguir define um módulo que captura uma exceção nativa e MSIL.

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

[Tratamento de Exceção](../extensions/exception-handling-cpp-component-extensions.md)
