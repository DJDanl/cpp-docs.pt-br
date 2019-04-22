---
title: rename_search_namespace
ms.date: 10/18/2018
f1_keywords:
- rename_search_namespace
helpviewer_keywords:
- rename_search_namespace attribute
ms.assetid: 47c9d7fd-59dc-4c62-87a1-9011a0040167
ms.openlocfilehash: ca5d24ca9cc12e9defaa395cf150bc3c04ee4439
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59022847"
---
# <a name="renamesearchnamespace"></a>rename_search_namespace

**Específico do C++**

Tem a mesma funcionalidade que o [rename_namespace](../preprocessor/rename-namespace.md) do atributo, mas é usado em bibliotecas de tipos que você usar o `#import` diretiva com o [auto_search](../preprocessor/auto-search.md) atributo.

## <a name="syntax"></a>Sintaxe

```
rename_search_namespace("NewName")
```

### <a name="parameters"></a>Parâmetros

*NewName*<br/>
O nome do novo namespace.

## <a name="remarks"></a>Comentários

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)