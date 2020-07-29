---
title: Exceções C++ não tratadas
ms.date: 11/04/2016
helpviewer_keywords:
- event handlers [C++], unhandled exceptions
- catch keyword [C++], handler not found
- exceptions [C++], unhandled
- C++ exception handling, unhandled exceptions
- unhandled exceptions [C++]
ms.assetid: 13f09c53-9254-4407-9db9-14e730e047cc
ms.openlocfilehash: 48b417c48a3cbb903f3fabaf31b1423e79a1a414
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233581"
---
# <a name="unhandled-c-exceptions"></a>Exceções C++ não tratadas

Se um manipulador correspondente (ou manipulador de reticências **`catch`** ) não puder ser encontrado para a exceção atual, a `terminate` função de tempo de execução predefinida será chamada. (Você também pode chamar explicitamente `terminate` em qualquer um de seus manipuladores.) A ação padrão do `terminate` é chamar `abort` . Se você quiser que `terminate` chame outra função em seu programa antes de sair do aplicativo, chame a função `set_terminate` com o nome da função a ser chamada como seu único argumento. Você pode chamar `set_terminate` em qualquer momento do programa. A `terminate` rotina sempre chama a última função fornecida como um argumento para `set_terminate` .

## <a name="example"></a>Exemplo

O exemplo a seguir gera uma exceção `char *`, mas não contém um manipulador designado para capturar exceções de tipo `char *`. A chamada para `set_terminate` instrui `terminate` a chamar `term_func`.

```cpp
// exceptions_Unhandled_Exceptions.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
void term_func() {
   cout << "term_func was called by terminate." << endl;
   exit( -1 );
}
int main() {
   try
   {
      set_terminate( term_func );
      throw "Out of memory!"; // No catch handler for this exception
   }
   catch( int )
   {
      cout << "Integer exception raised." << endl;
   }
   return 0;
}
```

## <a name="output"></a>Saída

```Output
term_func was called by terminate.
```

A função `term_func` deve encerrar o programa ou o thread atual, idealmente chamando `exit`. Caso contrário, retorna para seu chamador, `abort` é chamado.

## <a name="see-also"></a>Confira também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)
