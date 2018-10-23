---
title: embedded_idl | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- embedded_idl
dev_langs:
- C++
helpviewer_keywords:
- embedded_idl attribute
ms.assetid: f1c1c2e8-3872-4172-8795-8d1288a20452
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d7337595111b01ceeec53cc97f11ec2f35a081c5
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808336"
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