---
title: no_implementation
ms.date: 11/04/2016
f1_keywords:
- no_implementation
helpviewer_keywords:
- no_implementation attribute
ms.assetid: bdc67785-e131-409c-87bc-f4d2f4abb07b
ms.openlocfilehash: d4e55d06bef823d28c5deb3467654bc530a3853e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456778"
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

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)