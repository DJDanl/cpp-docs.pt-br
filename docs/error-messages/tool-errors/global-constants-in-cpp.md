---
title: Constantes globais no C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- global constants
- constants, global
ms.assetid: df5a9bd4-d0a8-4c1c-956e-b481d0bded7d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 00d033c1c4fc8fc3e534c8e4ee0c3d7867b83834
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103159"
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