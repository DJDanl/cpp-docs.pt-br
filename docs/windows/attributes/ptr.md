---
title: PTR (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.ptr
dev_langs:
- C++
helpviewer_keywords:
- ptr attribute
ms.assetid: 95eaea57-a5be-45f6-a612-ba2c9bc4645a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1f9f0fede8c5c3fd522aa7eb9dd95214062e3949
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50066702"
---
# <a name="ptr"></a>ptr

Designa um ponteiro como um ponteiro completo.

## <a name="syntax"></a>Sintaxe

```cpp
[ptr]
```

## <a name="remarks"></a>Comentários

O **ptr** atributo C++ tem a mesma funcionalidade que o [ptr](/windows/desktop/Midl/ptr) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](defaultvalue.md) para uso do exemplo **ptr**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface, **typedef**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)