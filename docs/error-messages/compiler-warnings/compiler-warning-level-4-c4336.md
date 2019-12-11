---
title: Aviso do compilador (nível 4) C4336
ms.date: 11/04/2016
f1_keywords:
- C4336
helpviewer_keywords:
- C4336
ms.assetid: 93f199dd-d6dd-42c0-82d8-c12d101a7235
ms.openlocfilehash: e83bac9028980bdf3ef7449fbef065a8c9316d2d
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991340"
---
# <a name="compiler-warning-level-4-c4336"></a>Aviso do compilador (nível 4) C4336

importar biblioteca de tipos de referência cruzada ' type_lib1 ' antes de importar ' type_lib2 '

Uma biblioteca de tipos foi referenciada com a diretiva [#import](../../preprocessor/hash-import-directive-cpp.md) . No entanto, a biblioteca de tipos continha uma referência a outra biblioteca de tipos que não foi referenciada com `#import`. Esse outro arquivo. tlb foi encontrado pelo compilador.

Dadas duas bibliotecas de tipos em disco criadas a partir dos dois arquivos a seguir (compilado com MIDL. exe):

```
// c4336a.idl
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]
library c4336aLib
{
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12c")]
   enum E_C4336
   {
      one, two, three
   };
};
```

A segunda biblioteca de tipos:

```
// c4336b.idl
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]
library C4336bLib
{
   importlib ("c4336a.tlb");
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]
   struct S_C4336
   {
      enum E_C4336 e;
   };
};
```

O exemplo a seguir gera C4336:

```cpp
// C4336.cpp
// compile with: /W4 /LD
// #import "C4336a.tlb"
#import "C4336b.tlb"   // C4336, uncomment previous line to resolve
```
