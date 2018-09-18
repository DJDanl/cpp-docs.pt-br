---
title: Compilador aviso (nível 1) C4342 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4342
dev_langs:
- C++
helpviewer_keywords:
- C4342
ms.assetid: 47d4d5ab-069f-4cdc-98c3-10d649577a37
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6aeb582ff891cc9d186604af5d2ca2c2844b1cb0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016254"
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