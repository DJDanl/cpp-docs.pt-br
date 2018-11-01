---
title: Erro das Ferramentas de Vinculador LNK1107
ms.date: 11/04/2016
f1_keywords:
- LNK1107
helpviewer_keywords:
- LNK1107
ms.assetid: a37a893d-5efa-4eba-8f40-6c5518b4b9d0
ms.openlocfilehash: 68048d9f824283d002a4ea8b64d88f37bbeefc48
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646557"
---
# <a name="linker-tools-error-lnk1107"></a>Erro das Ferramentas de Vinculador LNK1107

arquivo inválido ou corrompido: não é possível ler no local

A ferramenta não foi possível ler o arquivo. Recrie o arquivo.

Das LNK1107 também pode ocorrer se você tentar passar um módulo (extensão. dll ou. netmodule criado com [/clr:noAssembly](../../build/reference/clr-common-language-runtime-compilation.md) ou [/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)) para o vinculador; passar o arquivo. obj em vez disso.

Se você compilar o exemplo a seguir:

```
// LNK1107.cpp
// compile with: /clr /LD
public ref class MyClass {
public:
   void Test(){}
};
```

e, em seguida, especifique **vincular LNK1107.dll** na linha de comando, você obterá das LNK1107.  Para resolver o erro, especifique **vincular LNK1107.obj** em vez disso.