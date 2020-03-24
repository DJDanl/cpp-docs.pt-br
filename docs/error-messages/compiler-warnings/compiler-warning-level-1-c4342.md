---
title: Aviso do compilador (nível 1) C4342
ms.date: 11/04/2016
f1_keywords:
- C4342
helpviewer_keywords:
- C4342
ms.assetid: 47d4d5ab-069f-4cdc-98c3-10d649577a37
ms.openlocfilehash: 8ac00d3d57f8cf7d6c85f3106dbe9b8c3cb9adf0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162914"
---
# <a name="compiler-warning-level-1-c4342"></a>Aviso do compilador (nível 1) C4342

alteração de comportamento: '*Function*' chamado, mas um operador membro foi chamado em versões anteriores

Em versões do Visual C++ antes do visual Studio 2002, um membro foi chamado, mas esse comportamento foi alterado e o compilador agora encontra a melhor correspondência no escopo do namespace.

Se um operador de membro foi encontrado, o compilador não consideraria nenhum operador de escopo de namespace anteriormente. Se houver uma correspondência melhor no escopo do namespace, o compilador atual o chamará corretamente, enquanto os compiladores anteriores não o consideram.

Esse aviso deve ser desabilitado depois que você portar com êxito o código para a versão atual.  O compilador pode fornecer falsos positivos, gerando este aviso para o código em que não há nenhuma alteração de comportamento.

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

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
