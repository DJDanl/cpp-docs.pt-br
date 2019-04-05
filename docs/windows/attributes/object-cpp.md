---
title: objeto (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.object
helpviewer_keywords:
- object attribute
ms.assetid: f2d3c231-630d-4b4c-bd15-b1c30df362dd
ms.openlocfilehash: c0f544e84e5110761dfd01e25abef4352f055ff5
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59022353"
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

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[dual](dual.md)<br/>
[dispinterface](dispinterface.md)<br/>
[personalizado](custom-cpp.md)<br/>
[__interface](../../cpp/interface.md)