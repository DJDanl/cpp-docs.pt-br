---
title: Problemas de inlining da função
ms.date: 11/04/2016
helpviewer_keywords:
- /Ob1 C++ compiler option
- inline functions, problems
- -Ob1 C++ compiler option
- /Ob2 C++ compiler option
- -Ob2 C++ compiler option
- function inlining problems
ms.assetid: 65d59943-4b3c-4a43-aeb6-dccbf7686740
ms.openlocfilehash: cb4653bd2f03683b9abad1eea0e9ffa88222090e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80184236"
---
# <a name="function-inlining-problems"></a>Problemas de inlining da função

Se você estiver usando o inlineação de função, deverá:

- Ter as funções embutidas implementadas no arquivo de cabeçalho que você inclui.

- Fazer com que o alinhamento seja ativado no arquivo de cabeçalho.

```cpp
// LNK2019_function_inline.cpp
// compile with: /c
// post-build command: lib LNK2019_function_inline.obj
#include <stdio.h>
struct _load_config_used {
   void Test();
   void Test2() { printf("in Test2\n"); }
};

void _load_config_used::Test() { printf("in Test\n"); }
```

e, em seguida,

```cpp
// LNK2019_function_inline_2.cpp
// compile with: LNK2019_function_inline.lib
struct _load_config_used {
   void Test();
   void Test2();
};

int main() {
   _load_config_used x;
   x.Test();
   x.Test2();   // LNK2019
}
```

Se você estiver usando a diretiva de compilador `#pragma inline_depth`, certifique-se de ter um valor de 2 ou mais definido. Um valor de zero desativará o alinhamento. Verifique também se você está usando as opções de compilador **/Ob1** ou **/Ob2** .

A combinação de opções de compilação embutidas e não embutidas em diferentes módulos pode, às vezes, causar problemas. Se uma C++ biblioteca for criada com o inlineação de função ativado ([/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md)), mas o arquivo de cabeçalho correspondente que descreve as funções tiver o inlining desativado (sem opção), você receberá o erro LNK2001. As funções não são embutidas no código do arquivo de cabeçalho, mas como não estão no arquivo de biblioteca, não há nenhum endereço para resolver a referência.

Da mesma forma, um projeto que usa o inlineo de função ainda define as funções em um arquivo. cpp em vez de no arquivo de cabeçalho também obterá LNK2019. O arquivo de cabeçalho é incluído em qualquer lugar considerado apropriado, mas as funções são embutidas somente quando o arquivo. cpp passa pelo compilador; Portanto, o vinculador vê as funções como externas não resolvidas quando usadas em outros módulos.

```cpp
// LNK2019_FIP.h
struct testclass {
   void PublicStatMemFunc1(void);
};
```

e, em seguida,

```cpp
// LNK2019_FIP.cpp
// compile with: /c
#include "LNK2019_FIP.h"
inline void testclass::PublicStatMemFunc1(void) {}
```

e, em seguida,

```cpp
// LNK2019_FIP_2.cpp
// compile with: LNK2019_FIP.cpp
// LNK2019 expected
#include "LNK2019_FIP.h"
int main() {
   testclass testclsObject;

   // module cannot see the implementation of PublicStatMemFunc1
   testclsObject.PublicStatMemFunc1();
}
```

## <a name="see-also"></a>Confira também

[Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)
