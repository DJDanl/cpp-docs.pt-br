---
title: Aviso do compilador (nível 1) C4772
ms.date: 11/04/2016
f1_keywords:
- C4772
helpviewer_keywords:
- C4772
ms.assetid: dafe6fd8-9faf-41f5-9d66-a55838742c14
ms.openlocfilehash: 89156b2f29fd21160e6abddc3ecb21efaee6dde1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175123"
---
# <a name="compiler-warning-level-1-c4772"></a>Aviso do compilador (nível 1) C4772

> \#importação referenciou um tipo de uma biblioteca de tipos ausente; '*tipo ausente*' usado como um espaço reservado

Uma biblioteca de tipos foi referenciada com a diretiva [#import](../../preprocessor/hash-import-directive-cpp.md) . No entanto, a biblioteca de tipos continha uma referência a outra biblioteca de tipos que não foi referenciada com `#import`. Esse outro arquivo. tlb não foi encontrado pelo compilador.

Observe que o compilador não encontrará bibliotecas de tipos em diretórios diferentes se você usar a opção de compilador [/i (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md) para especificar esses diretórios. Se você quiser que o compilador encontre bibliotecas de tipos em diretórios diferentes, adicione esses diretórios à variável de ambiente PATH.

Por padrão, esse aviso é emitido como um erro. C4772 não pode ser suprimido com/W0.

## <a name="example"></a>Exemplo

Essa é a primeira biblioteca de tipos necessária para reproduzir C4772.

```IDL
// c4772a.idl
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]
library C4772aLib
{
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c100")]
   enum E_C4772a
   {
      one, two, three
   };
};
```

Essa é a segunda biblioteca de tipos necessária para reproduzir o C4772.

```IDL
// c4772b.idl
// post-build command: del /f C4772a.tlb
// C4772a.tlb is available when c4772b.tlb is built
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]
library C4772bLib
{
   importlib ("c4772a.tlb");
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]
   struct S_C4772b
   {
      enum E_C4772a e;
   };
};
```

O exemplo a seguir gera C4772:

```cpp
// C4772.cpp
// assumes that C4772a.tlb is not available to the compiler
// #import "C4772a.tlb"
#import "C4772b.tlb"   // C4772 uncomment previous line to resolve
                       // and make sure c4772a.tlb is on disk
```
