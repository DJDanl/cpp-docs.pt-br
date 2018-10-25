---
title: switch_is (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.switch_is
dev_langs:
- C++
helpviewer_keywords:
- switch_is attribute
ms.assetid: f1fffe5d-12d2-4e0f-8803-ccb715177d2d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0eb8c8b3a49e7aa4754762ce0c065c816e262bca
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50062906"
---
# <a name="switchis"></a>switch_is

Especifica a expressão ou um identificador que atua como o discriminador de união que seleciona o membro de união.

## <a name="syntax"></a>Sintaxe

```cpp
[switch_is]
```

## <a name="remarks"></a>Comentários

O **switch_is** atributo C++ tem a mesma funcionalidade que o [switch_is](/windows/desktop/Midl/switch-is) atributo MIDL.

## <a name="example"></a>Exemplo

Consulte a [caso](case-cpp.md) exemplo para uso do exemplo **switch_is**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**typedef**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[switch_type](switch-type.md)