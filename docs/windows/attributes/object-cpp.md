---
title: objeto (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.object
dev_langs:
- C++
helpviewer_keywords:
- object attribute
ms.assetid: f2d3c231-630d-4b4c-bd15-b1c30df362dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8828ada429875245d583c30d65259300a01f6a5d
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50067430"
---
# <a name="object-c"></a>object (C++)

Identifica uma interface personalizada.

## <a name="syntax"></a>Sintaxe

```cpp
[object]
```

## <a name="remarks"></a>Comentários

Quando precede uma definição de interface, o **objeto** C++ atributo faz com que a interface a ser colocado no arquivo. idl como uma interface personalizada.

Qualquer interface marcada com o objeto deve herdar de `IUnknown`. Essa condição é atendida se qualquer uma das interfaces base pode herdar de `IUnknown`. Se não há interfaces base herdam `IUnknown`, o compilador fará com que a interface marcada com **objeto** derivar `IUnknown`.

## <a name="example"></a>Exemplo

Ver [nonbrowsable](nonbrowsable.md) para obter um exemplo de como usar **objeto**.

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
[Atributos de interface](interface-attributes.md)<br/>
[dual](dual.md)<br/>
[dispinterface](dispinterface.md)<br/>
[custom](custom-cpp.md)<br/>
[__interface](../../cpp/interface.md)