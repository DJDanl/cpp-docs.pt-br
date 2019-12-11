---
title: Erro das Ferramentas de Vinculador LNK1107
ms.date: 11/04/2016
f1_keywords:
- LNK1107
helpviewer_keywords:
- LNK1107
ms.assetid: a37a893d-5efa-4eba-8f40-6c5518b4b9d0
ms.openlocfilehash: c75966d9c6c22f1bd2123fb30282bb2bed467130
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991034"
---
# <a name="linker-tools-error-lnk1107"></a>Erro das Ferramentas de Vinculador LNK1107

arquivo inválido ou corrompido: não é possível ler no local

A ferramenta não pôde ler o arquivo. Recrie o arquivo.

LNK1107 também poderá ocorrer se você tentar passar um módulo (extensão. dll ou. netmodule criado com [/CLR: noAssembly](../../build/reference/clr-common-language-runtime-compilation.md) ou [/noAssembly](../../build/reference/noassembly-create-a-msil-module.md)) para o vinculador; em vez disso, passe o arquivo. obj.

Se você compilar o exemplo a seguir:

```cpp
// LNK1107.cpp
// compile with: /clr /LD
public ref class MyClass {
public:
   void Test(){}
};
```

e, em seguida, especificar o **link LNK1107. dll** na linha de comando, você receberá LNK1107.  Para resolver o erro, especifique o **link LNK1107. obj** em vez disso.
