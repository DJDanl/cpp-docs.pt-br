---
title: rename_namespace
ms.date: 10/18/2018
f1_keywords:
- rename_namespace
helpviewer_keywords:
- rename_namespace attribute
ms.assetid: 45006d2b-36cd-4bec-98b9-3b8ec45299e3
ms.openlocfilehash: 7b3917a7114ca44d092f10a7831bb35bc64e9387
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59039865"
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