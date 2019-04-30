---
title: pointer_default (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.pointer_default
helpviewer_keywords:
- pointer_default attribute
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
ms.openlocfilehash: 37bd2b16fb7a7c1c186f59897898e08cc73fffae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407504"
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

O **pointer_default** C++ atributo tem a mesma funcionalidade que o [pointer_default](/windows/desktop/Midl/pointer-default) atributo MIDL.

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