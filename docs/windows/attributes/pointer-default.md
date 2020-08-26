---
title: pointer_default (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.pointer_default
helpviewer_keywords:
- pointer_default attribute
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
ms.openlocfilehash: e4e5ce03e8c0e6ca19814f5d228305b0d97322f9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836186"
---
# <a name="pointer_default"></a>pointer_default

Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto para os ponteiros de nível superior que aparecem nas listas de parâmetros.

## <a name="syntax"></a>Sintaxe

```cpp
[ pointer_default(value) ]
```

### <a name="parameters"></a>parâmetros

*value*<br/>
Um valor que descreve o tipo de ponteiro: **PTR**, **ref**ou **Unique**.

## <a name="remarks"></a>Comentários

O atributo **pointer_default** C++ tem a mesma funcionalidade que o atributo MIDL [pointer_default](/windows/win32/Midl/pointer-default) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [DefaultValue](defaultvalue.md) para obter um exemplo de uso de **pointer_default**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
