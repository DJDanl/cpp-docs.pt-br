---
title: no_namespace
ms.date: 11/04/2016
f1_keywords:
- no_namespace
helpviewer_keywords:
- no_namespace attribute
ms.assetid: 5d81b741-a558-451b-b493-1f3b18967337
ms.openlocfilehash: f6bd60de02bf0166d5cf0b0cd1bc1de56ceda5bf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326554"
---
# <a name="nonamespace"></a>no_namespace
**Específico do C++**

Especifica que o nome do namespace não é gerado pelo compilador.

## <a name="syntax"></a>Sintaxe

```
no_namespace
```

## <a name="remarks"></a>Comentários

O conteúdo da biblioteca de tipos no arquivo de cabeçalho de `#import` normalmente é definido em um namespace. O nome do namespace é especificado no `library` instrução do arquivo IDL original. Se o **no_namespace** atributo for especificado, esse namespace não é gerado pelo compilador.

Se você quiser usar um nome de namespace diferentes, em seguida, use o [rename_namespace](../preprocessor/rename-namespace.md) atributo em vez disso.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)