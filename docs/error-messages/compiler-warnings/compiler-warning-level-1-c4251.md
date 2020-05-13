---
title: Aviso do compilador (nível 1) C4251
ms.date: 04/21/2020
f1_keywords:
- C4251
helpviewer_keywords:
- C4251
ms.assetid: a9992038-f0c2-4fc4-a9be-4509442cbc1e
ms.openlocfilehash: 9f261d3deb7f1cac8cd5c60b920e0be49bc8b7a6
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032324"
---
# <a name="compiler-warning-level-1-c4251"></a>Aviso do compilador (nível 1) C4251

> '*type*' : class '*type1*' precisa ter dll-interface para ser usado por clientes da classe '*type2*'

## <a name="remarks"></a>Comentários

Para minimizar a possibilidade de corrupção de dados ao exportar uma classe declarada como [__declspec(dllexport),](../../cpp/dllexport-dllimport.md)certifique-se de que:

- Todos os seus dados estáticos são acessados através de funções que são exportadas da DLL.

- Nenhum método inforro da sua classe pode modificar dados estáticos.

- Nenhum método inforro da sua classe usa funções CRT ou outras funções de biblioteca que usam dados estáticos. Para obter mais informações, consulte [Potenciais erros que passam objetos CRT através dos limites da DLL](../../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md).

- Nenhum método da sua classe (inforrado ou não) pode usar tipos onde a instanciação no EXE e dLL têm diferenças de dados estáticos.

Você pode evitar problemas ao exportar uma classe de uma DLL: Defina sua classe para ter funções virtuais e funções para instanciar e excluir objetos do tipo. Em seguida, basta chamar funções virtuais no tipo.

C4251 pode ser ignorado se sua classe for derivada de um tipo na Biblioteca Padrão C++, você está compilando uma versão de `_Container_base`depuração **(/MTd),** e onde a mensagem de erro do compilador se refere a .

## <a name="example"></a>Exemplo

Esta amostra exporta `VecWrapper` uma classe `std::vector`especializada derivada de .

```cpp
// C4251.cpp
// compile with: /EHsc /MTd /W2 /c
#include <vector>
using namespace std;
class Node;
class __declspec(dllexport) VecWrapper : vector<Node *> {};   // C4251
```
