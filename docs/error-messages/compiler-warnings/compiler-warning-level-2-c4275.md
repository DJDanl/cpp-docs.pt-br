---
title: Aviso do compilador (nível 2) C4275
ms.date: 02/08/2019
f1_keywords:
- C4275
helpviewer_keywords:
- C4275
ms.assetid: 18de967a-0a44-4dbc-a2e8-fc4c067ba909
ms.openlocfilehash: ad12c1c27006a57c8339e9dad82e4d8e1a239a6e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161991"
---
# <a name="compiler-warning-level-2-c4275"></a>Aviso do compilador (nível 2) C4275

> classe de interface não-DLL '*class_1*' usada como base para a classe de interface de dll '*class_2*'

Uma classe exportada foi derivada de uma classe que não foi exportada.

Para minimizar a possibilidade de dados corrompidos ao exportar uma classe com [__declspec (dllexport)](../../cpp/dllexport-dllimport.md), verifique se:

- Todos os dados estáticos são acessados por meio de funções exportadas da DLL.

- Nenhum método embutido da sua classe pode modificar dados estáticos.

- Nenhum método embutido da sua classe usa funções CRT ou outras funções de biblioteca que usam dados estáticos.

- Nenhuma função de classe embutida usa funções CRT ou outras funções de biblioteca, nas quais você acessa dados estáticos.

- Nenhum método de sua classe (independentemente de inlining) pode usar tipos em que a instanciação no EXE e na DLL têm diferenças de dados estáticos.

Você pode evitar a exportação de classes definindo uma DLL que define uma classe com funções virtuais e funções que você pode chamar para instanciar e excluir objetos do tipo.  Você pode simplesmente chamar as funções virtuais no tipo.

C4275 pode ser ignorado no Visual C++ se você estiver derivando de um tipo na biblioteca C++ padrão, compilando uma versão de depuração ( **/MTD**) e onde a mensagem de erro do compilador se refere a `_Container_base`.

```cpp
// C4275.cpp
// compile with: /EHsc /MTd /W2 /c
#include <vector>
using namespace std;
class Node;
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4275
```
