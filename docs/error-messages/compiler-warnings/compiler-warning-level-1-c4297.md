---
title: Compilador aviso (nível 1) C4297
ms.date: 11/04/2016
f1_keywords:
- C4297
helpviewer_keywords:
- C4297
ms.assetid: ba92fcdc-9f70-4f60-abe6-281f9582ca59
ms.openlocfilehash: 07dd6c65498ddd0d377ec3e0fbc7b44e52bec96b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408622"
---
# <a name="compiler-warning-level-1-c4297"></a>Compilador aviso (nível 1) C4297

'function': função não deveria para lançar uma exceção, mas não

Uma declaração de função contém uma (possivelmente implícita) `noexcept` especificador, vazia `throw` especificador de exceção, ou um [__declspec(nothrow)](../../cpp/nothrow-cpp.md) atributo e a definição contém um ou mais [throw ](../../cpp/try-throw-and-catch-statements-cpp.md) instruções. Para resolver C4297, não tente gerar exceções em funções que são declaradas `__declspec(nothrow)`, `noexcept(true)` ou `throw()`. Como alternativa, remova os `noexcept`, `throw()`, ou `__declspec(nothrow)` especificação.

Por padrão, o compilador gera implícita `noexcept(true)` especificadores para funções de desalocador e destruidores definidos pelo usuário e funções de membro especial gerado pelo compilador. Isso está de acordo com o ISO c++11 standard. Para evitar a geração de especificadores de noexcept implícita e reverter o compilador para o comportamento não padrão do Visual Studio 2013, use o **/Zc:implicitNoexcept-** opção de compilador. Para obter mais informações, consulte [/ZC: implicitnoexcept (especificadores de exceção implícitos)](../../build/reference/zc-implicitnoexcept-implicit-exception-specifiers.md).

Para obter mais informações sobre especificações de exceção, consulte [especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md). Consulte também [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter informações sobre como modificar o comportamento em tempo de compilação de tratamento de exceção.

Esse aviso também é gerado para declspec ([dllexport](../../cpp/dllexport-dllimport.md)) funções marcadas extern "C", mesmo que sejam C++ funções.

O exemplo a seguir gera C4297:

```
// C4297.cpp
// compile with: /W1 /LD
void __declspec(nothrow) f1()   // declared nothrow
// try the following line instead
// void f1()
{
   throw 1;   // C4297
}
```