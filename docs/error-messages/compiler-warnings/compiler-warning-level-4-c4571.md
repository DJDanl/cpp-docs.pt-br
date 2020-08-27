---
title: Aviso do compilador (nível 4) C4571
description: Documenta o aviso do compilador do Microsoft C++ C4571.
ms.date: 08/24/2020
f1_keywords:
- C4571
helpviewer_keywords:
- C4571
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
ms.openlocfilehash: 35f2b30a8ab7cfcc27ed7aae3aedd9bc81efacc8
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898551"
---
# <a name="compiler-warning-level-4-c4571"></a>Aviso do compilador (nível 4) C4571

> Informação: a `catch(...)` semântica mudou desde Visual C++ 7,1; exceções estruturadas (SEH) não são mais detectadas

C4571 é gerado para cada `catch(...)` bloco quando você especifica a **`/EHs`** opção do compilador.

## <a name="remarks"></a>Comentários

Quando você especifica a **`/EHs`** opção do compilador, os `catch(...)` blocos não capturam exceções estruturadas. (Dividir por zero, ou exceções de ponteiro NULL, por exemplo.) Um `catch(...)` bloco só captura exceções C++ geradas explicitamente. Para saber mais, veja [Tratamento de exceção](../../cpp/exception-handling-in-visual-cpp.md).

Esse aviso está desativado por padrão.  Ative este aviso para garantir que, quando você compilar com **`/EHs`** seus `catch (...)` blocos, não pegue exceções estruturadas. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

Você pode resolver o C4571 de uma das seguintes maneiras:

- Compile com **`/EHa`** se você ainda quiser que seus `catch(...)` blocos detectem exceções estruturadas.

- Não habilite C4571 se não quiser que seus `catch(...)` blocos detectem exceções estruturadas, mas ainda deseja usar `catch(...)` blocos.  Você ainda pode capturar exceções estruturadas usando as palavras-chave de manipulação de exceção estruturada ( **`__try`** , **`__except`** , e **`__finally`** ).  Mas lembre-se de que, quando compilado usando **`/EHs`** , os destruidores são chamados apenas quando uma exceção de C++ é lançada, não quando ocorre uma exceção SEH.

- Substitua `catch(...)` blocos com blocos catch para exceções de c++ específicas e, opcionalmente, adicione manipulação de exceção estruturada em relação à manipulação de exceção do c++ ( **`__try`** , **`__except`** , e **`__finally`** ).   para obter mais informações, consulte [manipulação de exceção estruturada (C/C++)](../../cpp/structured-exception-handling-c-cpp.md) e [ `/EH` (modelo de manipulação de exceção)](../../build/reference/eh-exception-handling-model.md).

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
