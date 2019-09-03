---
title: atributo de importação de embedded_idl
ms.date: 08/29/2019
f1_keywords:
- embedded_idl
helpviewer_keywords:
- embedded_idl attribute
ms.assetid: f1c1c2e8-3872-4172-8795-8d1288a20452
ms.openlocfilehash: 01948b171b20ad0a3bf3e7a41047f1fe3df185b0
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216332"
---
# <a name="embedded_idl-import-attribute"></a>atributo de importação de embedded_idl

**C++Determinados**

Especifica se a biblioteca de tipos é gravada `.tlh` no arquivo com o código gerado pelo atributo preservado.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **embedded_idl** [ **(** { **"emitidl"**  |  **"no_emitidl"** } **)** ]

### <a name="parameters"></a>Parâmetros

**emitidl**\
As informações de tipo importadas da *biblioteca de tipos* estão presentes no IDL gerado para o projeto atribuído. Esse comportamento é o padrão e estará em vigor se você não especificar um parâmetro para `embedded_idl`.

**"no_emitidl"** \
As informações de tipo importadas da *biblioteca de tipos* não estão presentes no IDL gerado para o projeto atribuído.

## <a name="example"></a>Exemplo

```cpp
// import_embedded_idl.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLib2")];
#import "\school\bin\importlib.tlb" embedded_idl("no_emitidl")
```

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
