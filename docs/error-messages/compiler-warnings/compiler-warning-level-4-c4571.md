---
title: Compilador aviso (nível 4) C4571
ms.date: 11/04/2016
f1_keywords:
- C4571
helpviewer_keywords:
- C4571
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
ms.openlocfilehash: 92164bf297a44871897b6c6150eb54f8c5ccf3cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62220449"
---
# <a name="compiler-warning-level-4-c4571"></a>Compilador aviso (nível 4) C4571

Informativo: semântica catch alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas

C4571 é gerado para cada bloco catch ao compilar com **/EHs**.

Ao compilar com **/EHs**, um bloco catch não vai capturar uma exceção estruturada (divisão por zero, um ponteiro nulo, por exemplo); um catch bloco será apenas catch geradas explicitamente, as exceções do C++.  Para saber mais, veja [Tratamento de exceção](../../cpp/exception-handling-in-visual-cpp.md).

Esse aviso é desativado por padrão.  Ativar esse aviso para garantir que quando você compila com **/EHs** blocos catch (...) não pretendem capturar exceções estruturadas.  Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Você pode resolver C4571 em uma das seguintes maneiras,

- Compilar com **/EHa** se você ainda deseja seus blocos catch para capturar exceções estruturadas.

- Não habilite C4571 se você não quiser que seus blocos catch para capturar exceções estruturadas, mas você ainda deseja usar blocos catch.  Você ainda pode capturar exceções estruturadas, usando as palavras-chave de tratamento de exceções estruturado (**Try**, **EXCEPT**, e **Finally**).  Mas lembre-se, quando compilado **/EHs** destruidores só serão chamados quando uma exceção de C++ é lançada, não quando ocorre uma exceção SEH.

- Substitua o bloco catch com blocos catch para determinado C++ exceções e, opcionalmente, adicione ao redor de tratamento de exceções estruturado o C++ tratamento de exceção (**Try**, **EXCEPT**, e **Finally**).  Ver [tratamento de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md) para obter mais informações.

Ver [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4571.

```
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