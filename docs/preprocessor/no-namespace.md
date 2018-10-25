---
title: no_namespace | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- no_namespace
dev_langs:
- C++
helpviewer_keywords:
- no_namespace attribute
ms.assetid: 5d81b741-a558-451b-b493-1f3b18967337
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e84cfad5a11c0d691c56e6e7ddcca17ea87e3f02
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50082912"
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