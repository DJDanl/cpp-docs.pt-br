---
title: Erro do compilador C3510
ms.date: 11/04/2016
f1_keywords:
- C3510
helpviewer_keywords:
- C3510
ms.assetid: c48387bc-0300-4a4d-97f7-3fb90f82a451
ms.openlocfilehash: dbb65628aa6e0da94a91a59724ca8e1cd5b56491
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187346"
---
# <a name="compiler-error-c3510"></a>Erro do compilador C3510

não é possível localizar a biblioteca de tipos dependente 'type_lib'

[no_registry](../../preprocessor/no-registry.md) e [auto_search](../../preprocessor/auto-search.md) foram passados para `#import` , mas o compilador não pôde localizar uma biblioteca de tipos referenciada.

Para resolver esse erro, certifique-se de que todas as bibliotecas de tipos e bibliotecas de tipo de referência estão disponíveis para o compilador.

O exemplo a seguir gera C3510:

Suponha que as bibliotecas de dois tipos a seguir foram criadas e que C3510a.tlb foi excluído ou não no caminho.

```
// C3510a.idl
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]
library C3510aLib
{
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12c")]
   enum E_C3510
   {
      one, two, three
   };
};
```

E, em seguida, o código-fonte da biblioteca de tipos segundo:

```
// C3510b.idl
// post-build command: del /f C3510a.tlb
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]
library C3510bLib
{
   importlib ("C3510a.tlb");
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]
   struct S_C3510 {
      enum E_C3510 e;
   };
};
```

E, em seguida, o código do cliente:

```
// C3510.cpp
#import "c3510b.tlb" no_registry auto_search   // C3510
int main() {
   C3510aLib::S_C4336 ccc;
}
```