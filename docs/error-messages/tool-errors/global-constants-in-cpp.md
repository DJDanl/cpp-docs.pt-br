---
title: Constantes globais no C++
ms.date: 11/04/2016
helpviewer_keywords:
- global constants
- constants, global
ms.assetid: df5a9bd4-d0a8-4c1c-956e-b481d0bded7d
ms.openlocfilehash: cabe5e92a496181d60536d7274eca388aba5c068
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195468"
---
# <a name="global-constants-in-c"></a>Constantes globais no C++

C++as constantes globais têm vínculo estático. Isso é diferente de C. Se você tentar usar uma constante global no C++ em vários arquivos, obterá um erro externo não resolvido. O compilador otimiza as constantes globais para fora, deixando nenhum espaço reservado para a variável.

Uma maneira de resolver esse erro é incluir as inicializações const em um arquivo de cabeçalho e incluir esse cabeçalho em seus arquivos CPP quando necessário, assim como se fosse um protótipo de função. Outra possibilidade é tornar a variável não constante e usar uma referência constante ao avaliá-la.

O exemplo a seguir gera C2019:

```cpp
// global_constants.cpp
// LNK2019 expected
void test(void);
const int lnktest1 = 0;

int main() {
   test();
}
```

e, em seguida,

```cpp
// global_constants_2.cpp
// compile with: global_constants.cpp
extern int lnktest1;

void test() {
  int i = lnktest1;   // LNK2019
}
```

## <a name="see-also"></a>Confira também

[Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)
