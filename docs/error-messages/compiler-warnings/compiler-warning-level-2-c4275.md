---
title: Compilador aviso (nível 2) C4275 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4275
dev_langs:
- C++
helpviewer_keywords:
- C4275
ms.assetid: 18de967a-0a44-4dbc-a2e8-fc4c067ba909
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7cb8f397243bb6531f33ac5e444914cfa36e5fe1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46022619"
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

Para obter mais informações sobre como exportar modelos, consulte [ http://support.microsoft.com/default.aspx?scid=KB; EN-US; 168958](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).

C4275 podem ser ignorados no Visual C++, se você estiver derivando de um tipo na biblioteca padrão C++, Compilando uma versão de depuração (**/MTd**) e onde a mensagem de erro do compilador se refere ao _Container_base.

```
// C4275.cpp
// compile with: /EHsc /MTd /W2 /c
#include <vector>
using namespace std;
class Node;
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4275
```