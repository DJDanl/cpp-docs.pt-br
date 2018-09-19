---
title: Compilador aviso (nível 1) C4297 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4297
dev_langs:
- C++
helpviewer_keywords:
- C4297
ms.assetid: ba92fcdc-9f70-4f60-abe6-281f9582ca59
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f615df5933cfc93918b05758f042c8cf47aa92f1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099428"
---
# <a name="compiler-warning-level-1-c4297"></a>Compilador aviso (nível 1) C4297

'function': função não deveria para lançar uma exceção, mas não

Uma declaração de função contém uma (possivelmente implícita) `noexcept` especificador, vazia `throw` especificador de exceção, ou um [__declspec(nothrow)](../../cpp/nothrow-cpp.md) atributo e a definição contém um ou mais [throw ](../../cpp/try-throw-and-catch-statements-cpp.md) instruções. Para resolver C4297, não tente gerar exceções em funções que são declaradas `__declspec(nothrow)`, `noexcept(true)` ou `throw()`. Como alternativa, remova os `noexcept`, `throw()`, ou `__declspec(nothrow)` especificação.

Por padrão, o compilador gera implícita `noexcept(true)` especificadores para funções de desalocador e destruidores definidos pelo usuário e funções de membro especial gerado pelo compilador. Isso está de acordo com o ISO c++11 standard. Para evitar a geração de especificadores de noexcept implícita e reverter o compilador para o comportamento não padrão do Visual Studio 2013, use o **/Zc:implicitNoexcept-** opção de compilador. Para obter mais informações, consulte [/ZC: implicitnoexcept (especificadores de exceção implícitos)](../../build/reference/zc-implicitnoexcept-implicit-exception-specifiers.md).

Para obter mais informações sobre especificações de exceção, consulte [especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md). Consulte também [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter informações sobre como modificar o comportamento em tempo de compilação de tratamento de exceção.

Esse aviso também é gerado para declspec ([dllexport](../../cpp/dllexport-dllimport.md)) funções marcadas extern "C", mesmo se eles são funções de C++.

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