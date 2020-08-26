---
title: objeto (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.object
helpviewer_keywords:
- object attribute
ms.assetid: f2d3c231-630d-4b4c-bd15-b1c30df362dd
ms.openlocfilehash: c0c0ff552d8a33ebe70f56b9b186e963cc8e9b3d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843099"
---
# <a name="object-c"></a>object (C++)

Identifica uma interface personalizada.

## <a name="syntax"></a>Sintaxe

```cpp
[object]
```

## <a name="remarks"></a>Comentários

Ao anteceder uma definição de interface, o atributo **Object** C++ faz com que a interface seja colocada no arquivo. idl como uma interface personalizada.

Qualquer interface marcada com objeto deve herdar de `IUnknown` . Essa condição será satisfeita se qualquer uma das interfaces base herdar de `IUnknown` . Se nenhuma das interfaces base herdar de `IUnknown` , o compilador fará com que a interface marcada com **Object** derive `IUnknown` .

## <a name="example"></a>Exemplo

Consulte [nonnavegáveis](nonbrowsable.md) para obter um exemplo de como usar o **objeto**.

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
[Atributos de interface](interface-attributes.md)<br/>
[dual](dual.md)<br/>
[dispinterface](dispinterface.md)<br/>
[Personalizar](custom-cpp.md)<br/>
[__interface](../../cpp/interface.md)
