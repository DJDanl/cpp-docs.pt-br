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
ms.openlocfilehash: 85227e0bd0ca33f925e8fe72b6489fa81305d031
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62312204"
---
# <a name="unhandled-c-exceptions"></a>Exceções C++ não tratadas

Se um manipulador correspondente (ou botão de reticências **catch** manipulador) não pode ser encontrado para a exceção atual, predefinida `terminate` tempo de execução de função é chamado. (Você também pode chamar explicitamente `terminate` em qualquer um dos manipuladores.) A ação padrão de `terminate` é chamar `abort`. Se você quiser que `terminate` chame outra função em seu programa antes de sair do aplicativo, chame a função `set_terminate` com o nome da função a ser chamada como seu único argumento. Você pode chamar `set_terminate` em qualquer momento do programa. O `terminate` rotina sempre chama a função last especificada como um argumento para `set_terminate`.

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

## <a name="see-also"></a>Consulte também

[Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)