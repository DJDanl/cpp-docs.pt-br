---
title: pointer_default (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.pointer_default
dev_langs:
- C++
helpviewer_keywords:
- pointer_default attribute
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6e8ddf566082bfded1f20a2bfe04e7cef0b5dc14
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790069"
---
# <a name="pointerdefault"></a>pointer_default

Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.

## <a name="syntax"></a>Sintaxe

```cpp
[ pointer_default(value) ]
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Um valor que descreve o tipo de ponteiro: **ptr**, **ref**, ou **exclusivo**.

## <a name="remarks"></a>Comentários

O **pointer_default** atributo C++ tem a mesma funcionalidade que o [pointer_default](/windows/desktop/Midl/pointer-default) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](defaultvalue.md) para uso do exemplo **pointer_default**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)  