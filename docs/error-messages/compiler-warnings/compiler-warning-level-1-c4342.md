---
title: Compilador aviso (nível 1) C4342
ms.date: 11/04/2016
f1_keywords:
- C4342
helpviewer_keywords:
- C4342
ms.assetid: 47d4d5ab-069f-4cdc-98c3-10d649577a37
ms.openlocfilehash: 439c4976f25688fd9220c3f58ceb933266b5f15c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187496"
---
# <a name="compiler-warning-level-1-c4342"></a>Compilador aviso (nível 1) C4342

alteração de comportamento: '*função*' chamado, mas um operador de membro foi chamado em versões anteriores

Nas versões do Visual C++ anteriores ao Visual Studio 2002, um membro foi chamado, mas esse comportamento foi alterado e o compilador agora localiza a melhor correspondência no escopo de namespace.

Se um operador de membro for encontrado, o compilador anteriormente não consideraria qualquer namespace operadores de escopo. Se houver uma correspondência melhor no escopo do namespace, o compilador atual corretamente chama, ao passo que os compiladores anteriores o consideraria.

Esse aviso deve ser desabilitado após portar seu código para a versão atual com êxito.  O compilador pode fornecer falsos positivos, gerando esse aviso para o código em que não há nenhuma alteração de comportamento.

Esse aviso é desativado por padrão. Para obter mais informações, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

O exemplo a seguir gera C4342:

```cpp
// C4342.cpp
// compile with: /EHsc /W1
#include <fstream>
#pragma warning(default: 4342)
using namespace std;
struct X : public ofstream {
   X();
};

X::X() {
   open( "ofs_bug_ev.txt." );
   if ( is_open() ) {
      *this << "Text" << "<-should be text" << endl;   // C4342
      *this << ' ' << "<-should be space symbol" << endl;   // C4342
   }
}

int main() {
   X b;
   b << "Text" << "<-should be text" << endl;
   b << ' ' << "<-should be space symbol" << endl;
}
```