---
title: Erro das LNK1107 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1107
dev_langs:
- C++
helpviewer_keywords:
- LNK1107
ms.assetid: a37a893d-5efa-4eba-8f40-6c5518b4b9d0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 73a1643d10ea9adc6ac6979eb2de023593ba8d01
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060701"
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