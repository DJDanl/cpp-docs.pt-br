---
title: embedded_idl
ms.date: 10/18/2018
f1_keywords:
- embedded_idl
helpviewer_keywords:
- embedded_idl attribute
ms.assetid: f1c1c2e8-3872-4172-8795-8d1288a20452
ms.openlocfilehash: 202d5b23a5e2e8e673e3c220b9618cfe6cd4f0d9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525600"
---
# <a name="embeddedidl"></a>embedded_idl

**Específico do C++**

Especifica que a biblioteca de tipos é gravada no arquivo .tlh com o código gerado pelo atributo preservado.

## <a name="syntax"></a>Sintaxe

```
embedded_idl[("param")]
```

### <a name="parameters"></a>Parâmetros

*param*<br/>
Pode ser um destes dois valores:

- **emitidl**: informações de tipo importadas de typelib estarão presentes no IDL gerado para o projeto atribuído.  Esse é o padrão e entrará em vigor se você não especificar um parâmetro para `embedded_idl`.

- **no_emitidl**: informações de tipo importadas de typelib não estarão presentes no IDL gerado para o projeto atribuído.

## <a name="example"></a>Exemplo

```cpp
// import_embedded_idl.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLib2")];
#import "\school\bin\importlib.tlb" embedded_idl("no_emitidl")
```

## <a name="remarks"></a>Comentários

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)