---
title: no_implementation
ms.date: 11/04/2016
f1_keywords:
- no_implementation
helpviewer_keywords:
- no_implementation attribute
ms.assetid: bdc67785-e131-409c-87bc-f4d2f4abb07b
ms.openlocfilehash: 26527ca69c66c73f5d41084dc42df5faa34481d3
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59030535"
---
# <a name="noimplementation"></a>no_implementation
**Específico do C++**

Suprime geração do cabeçalho .tli, que contém as implementações das funções de membro do wrapper.

## <a name="syntax"></a>Sintaxe

```
no_implementation
```

## <a name="remarks"></a>Comentários

Se esse atributo for especificado, o cabeçalho .tlh, com as declarações para expor itens do tipo biblioteca, será gerado sem uma instrução `#include` para incluir o arquivo de cabeçalho .tli.

Esse atributo é usado em conjunto com [implementation_only](../preprocessor/implementation-only.md).

**FIM de Específico do C++**

## <a name="see-also"></a>Consulte também

[Atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[Diretiva #import](../preprocessor/hash-import-directive-cpp.md)