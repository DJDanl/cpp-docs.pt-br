---
title: Erro do compilador C2483
ms.date: 09/15/2017
f1_keywords:
- C2483
helpviewer_keywords:
- C2483
ms.assetid: 5762b325-914b-442d-a604-e4617ba04038
ms.openlocfilehash: d1a5632328c00ca2dcd03519d03fbdb648776a51
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50637873"
---
# <a name="compiler-error-c2483"></a>Erro do compilador C2483

>'*identificador*': objeto com o construtor ou destruidor não pode ser declarado 'thread'

Essa mensagem de erro está obsoleta no Visual Studio 2015 e versões posteriores. Nas versões anteriores, as variáveis declaradas com o `thread` atributo não pode ser inicializado com um construtor ou outra expressão que requer avaliação de tempo de execução. Uma expressão estática é necessário para inicializar `thread` dados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2483 no Visual Studio 2013 e versões anteriores.

```cpp
// C2483.cpp
// compile with: /c
__declspec(thread) struct A {
   A(){}
   ~A(){}
} aa;   // C2483 error

__declspec(thread) struct B {} b;   // OK
```

## <a name="see-also"></a>Consulte também

[thread](../../cpp/thread.md)