---
title: Constantes globais no C++
ms.date: 11/04/2016
helpviewer_keywords:
- global constants
- constants, global
ms.assetid: df5a9bd4-d0a8-4c1c-956e-b481d0bded7d
ms.openlocfilehash: 3da61b7718dadba9b454ee079651ce6372f21756
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432611"
---
# <a name="global-constants-in-c"></a>Constantes globais no C++

Constantes globais do C++ têm vinculação estática. Isso é diferente de C. Se você tentar usar um globais constantes em C++ em vários arquivos de você obter um erro externo não resolvido. O compilador otimiza as constantes globais, não deixando nenhum espaço reservado para a variável.

Uma maneira de resolver esse erro é incluir as inicializações constantes em um arquivo de cabeçalho e inclua esse cabeçalho em seus arquivos CPP quando necessário, como se fosse o protótipo de função. Outra possibilidade é tornar a variável não constante e usar uma referência constante ao avaliar a ele.

O exemplo a seguir gera C2019:

```
// global_constants.cpp
// LNK2019 expected
void test(void);
const int lnktest1 = 0;

int main() {
   test();
}
```

E, em seguida,

```
// global_constants_2.cpp
// compile with: global_constants.cpp
extern int lnktest1;

void test() {
  int i = lnktest1;   // LNK2019
}
```

## <a name="see-also"></a>Consulte também

[Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)