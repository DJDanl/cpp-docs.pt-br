---
title: Aviso do compilador (nível 1) C4297
ms.date: 11/04/2016
f1_keywords:
- C4297
helpviewer_keywords:
- C4297
ms.assetid: ba92fcdc-9f70-4f60-abe6-281f9582ca59
ms.openlocfilehash: 31deba2f421b461ba56d13810b5064b353a0e602
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175669"
---
# <a name="compiler-warning-level-1-c4297"></a>Aviso do compilador (nível 1) C4297

' function ': função assumida para não gerar uma exceção, mas

Uma declaração de função contém um especificador de `noexcept` (possivelmente implícito), um especificador de exceção `throw` vazio ou um atributo [__declspec (nothrow)](../../cpp/nothrow-cpp.md) e a definição contém uma ou mais instruções [throw](../../cpp/try-throw-and-catch-statements-cpp.md) . Para resolver o C4297, não tente gerar exceções em funções declaradas `__declspec(nothrow)`, `noexcept(true)` ou `throw()`. Como alternativa, remova a especificação `noexcept`, `throw()`ou `__declspec(nothrow)`.

Por padrão, o compilador gera especificadores de `noexcept(true)` implícitos para destruidores definidos pelo usuário e funções de desalocador e funções de membro especiais geradas pelo compilador. Isso está de acordo com o padrão ISO C++ 11. Para evitar a geração de especificadores noexcept implícitos e reverter o compilador para o comportamento não padrão de Visual Studio 2013, use a opção **/Zc: implicitNoexcept-** Compiler. Para obter mais informações, consulte [/Zc: implicitNoexcept (especificadores de exceção implícita)](../../build/reference/zc-implicitnoexcept-implicit-exception-specifiers.md).

Para obter mais informações sobre especificações de exceção, consulte [especificações de exceção (throw)](../../cpp/exception-specifications-throw-cpp.md). Além disso, consulte [/eh (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md) para obter informações sobre como modificar o comportamento de manipulação de exceções no momento da compilação.

Esse aviso também é gerado para funções de __declspec ([dllexport](../../cpp/dllexport-dllimport.md)) marcadas como externas "C", mesmo C++ que elas sejam funções.

O exemplo a seguir gera C4297:

```cpp
// C4297.cpp
// compile with: /W1 /LD
void __declspec(nothrow) f1()   // declared nothrow
// try the following line instead
// void f1()
{
   throw 1;   // C4297
}
```
