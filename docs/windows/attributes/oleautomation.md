---
title: oleautomation (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.oleautomation
helpviewer_keywords:
- oleautomation attribute
ms.assetid: c1086c91-260b-4dc3-b244-662852d09906
ms.openlocfilehash: 47842454ce52c65cf71a317f39a7649b0f9dd27d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842176"
---
# <a name="oleautomation"></a>oleautomation

Indica que uma interface é compatível com a automação.

## <a name="syntax"></a>Sintaxe

```cpp
[oleautomation]
```

## <a name="remarks"></a>Comentários

O atributo **oleautomation** C++ tem a mesma funcionalidade que o atributo MIDL [oleautomation](/windows/win32/Midl/oleautomation) .

## <a name="example"></a>Exemplo

Consulte os exemplos de [DefaultValue](defaultvalue.md) e [extensível](nonextensible.md) para obter um exemplo de uso de **oleautomation**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
