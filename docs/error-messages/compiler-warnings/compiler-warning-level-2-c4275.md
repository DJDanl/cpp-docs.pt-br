---
title: Compilador aviso (nível 2) C4275
ms.date: 11/04/2016
f1_keywords:
- C4275
helpviewer_keywords:
- C4275
ms.assetid: 18de967a-0a44-4dbc-a2e8-fc4c067ba909
ms.openlocfilehash: 985a622e2c89306c453ae6c860d21e6265d0fff1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594318"
---
# <a name="compiler-warning-level-2-c4275"></a>Compilador aviso (nível 2) C4275

não - DLL-interface classkey 'Identificador' usado como base para classkey 'Identificador de interface da DLL'

Uma classe exportada foi derivada de uma classe que não foi exportada.

Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [dllexport](../../cpp/dllexport-dllimport.md), certifique-se de que:

- Todos os seus dados estáticos é acessado por meio de funções exportadas da DLL.

- Nenhum método embutido da sua classe pode modificar dados estáticos.

- Nenhum método embutido da sua classe usa funções de CRT ou outras funções de biblioteca usam dados estáticos.

- Nenhuma função de classe embutidas usa funções de CRT ou outras funções de biblioteca, onde, por exemplo, acessar dados estáticos.

- Nenhum método de sua classe (independentemente de inlining) pode usar os tipos em que a instanciação no EXE e DLL têm diferenças de dados estáticos.

Você pode evitar a exportação de classes definindo a uma DLL que define uma classe com funções virtuais e funções que você pode chamar para instanciar e excluir objetos do tipo.  Você pode chamar funções virtuais apenas no tipo.

C4275 podem ser ignorados no Visual C++, se você estiver derivando de um tipo na biblioteca padrão C++, Compilando uma versão de depuração (**/MTd**) e onde a mensagem de erro do compilador se refere ao _Container_base.

```
// C4275.cpp
// compile with: /EHsc /MTd /W2 /c
#include <vector>
using namespace std;
class Node;
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4275
```