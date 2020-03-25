---
title: Aviso do compilador (nível 1) C4251
ms.date: 11/04/2016
f1_keywords:
- C4251
helpviewer_keywords:
- C4251
ms.assetid: a9992038-f0c2-4fc4-a9be-4509442cbc1e
ms.openlocfilehash: 8a723b7ce7fc79fb6be9c9dd2b500631098622b0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163213"
---
# <a name="compiler-warning-level-1-c4251"></a>Aviso do compilador (nível 1) C4251

' identifier ': classe ' type ' precisa ter a interface DLL a ser usada por clientes da classe ' type2 '

Para minimizar a possibilidade de dados corrompidos ao exportar uma classe com [__declspec (dllexport)](../../cpp/dllexport-dllimport.md), verifique se:

- Todos os dados estáticos são acessados por meio de funções exportadas da DLL.

- Nenhum método embutido da sua classe pode modificar dados estáticos.

- Nenhum método embutido de sua classe usa funções CRT ou outras funções de biblioteca usam dados estáticos (veja [possíveis erros passando objetos CRT entre limites de dll](../../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md) para obter mais informações).

- Nenhum método de sua classe (independentemente de inlining) pode usar tipos em que a instanciação no EXE e na DLL têm diferenças de dados estáticos.

Você pode evitar a exportação de classes definindo uma DLL que define uma classe com funções virtuais e funções que você pode chamar para instanciar e excluir objetos do tipo.  Você pode simplesmente chamar as funções virtuais no tipo.

C4251 pode ser ignorado se você estiver derivando de um tipo na biblioteca C++ padrão, compilando uma versão de depuração ( **/MTD**) e onde a mensagem de erro do compilador se refere a _Container_base.

```cpp
// C4251.cpp
// compile with: /EHsc /MTd /W2 /c
#include <vector>
using namespace std;
class Node;
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4251
```
