---
title: Aviso do compilador (nível 4) C4571
ms.date: 11/04/2016
f1_keywords:
- C4571
helpviewer_keywords:
- C4571
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
ms.openlocfilehash: 3a8f2093e90f8a681d171e19e2b8a066546f8684
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990660"
---
# <a name="compiler-warning-level-4-c4571"></a>Aviso do compilador (nível 4) C4571

informação: a semântica catch (...) foi alterada desde o C++ Visual 7,1; as exceções estruturadas (SEH) não são mais detectadas

C4571 é gerado para cada bloco catch (...) durante a compilação com **o/EHS**.

Ao compilar com **o/EHS**, um bloco catch (...) não capturará uma exceção estruturada (dividir por zero, ponteiro nulo, por exemplo); um bloco catch (...) só capturará exceções explicitamente, C++ geradas.  Para saber mais, veja [Tratamento de exceção](../../cpp/exception-handling-in-visual-cpp.md).

Esse aviso está desativado por padrão.  Ative este aviso para garantir que quando você compilar com **o/EHS** seus blocos catch (...) não pretendem capturar exceções estruturadas.  Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Você pode resolver o C4571 de uma das seguintes maneiras:

- Compile com **/EHA** se você ainda quiser que seus blocos catch (...) detectem exceções estruturadas.

- Não habilite C4571 se não quiser que os blocos catch (...) detectem exceções estruturadas, mas você ainda deseja usar blocos catch (...).  Você ainda pode capturar exceções estruturadas usando as palavras-chave de manipulação de exceção estruturada ( **__try**, **__except**e **__finally**).  Mas lembre-se de que os destruidores **o/EHS** compilados só serão C++ chamados quando uma exceção for lançada, não quando ocorrer uma exceção SEH.

- Substitua o bloco catch (...) com blocos catch para C++ exceções específicas e, opcionalmente, adicione manipulação de exceção estruturada em volta da C++ manipulação de exceção ( **__try**, **__except**e **__finally**).  Consulte [manipulação de exceção estruturada (C++C/)](../../cpp/structured-exception-handling-c-cpp.md) para obter mais informações.

Consulte [/eh (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4571.

```cpp
// C4571.cpp
// compile with: /EHs /W4 /c
#pragma warning(default : 4571)
int main() {
   try {
      int i = 0, j = 1;
      j /= i;   // this will throw a SE (divide by zero)
   }
   catch(...) {}   // C4571 warning
}
```
