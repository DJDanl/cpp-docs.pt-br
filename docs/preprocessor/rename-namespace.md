---
title: rename_namespace
ms.date: 10/18/2018
f1_keywords:
- rename_namespace
helpviewer_keywords:
- rename_namespace attribute
ms.assetid: 45006d2b-36cd-4bec-98b9-3b8ec45299e3
ms.openlocfilehash: 6521fe0a5bfbe482bf2aed8f5a32221abdc6d6d3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531583"
---
# <a name="renamenamespace"></a>rename_namespace

**Específico do C++**

Renomeia o namespace que contém o conteúdo da biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```
rename_namespace("NewName")
```

### <a name="parameters"></a>Parâmetros

*NewName*<br/>
O nome do novo namespace.

## <a name="remarks"></a>Comentários

Ele usa um único argumento, *NewName*, que especifica o novo nome para o namespace.

Para remover o namespace, use o [no_namespace](../preprocessor/no-namespace.md) atributo em vez disso.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)