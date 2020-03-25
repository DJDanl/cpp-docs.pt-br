---
title: oleautomation (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.oleautomation
helpviewer_keywords:
- oleautomation attribute
ms.assetid: c1086c91-260b-4dc3-b244-662852d09906
ms.openlocfilehash: 201916eeb235d48473d21188da42d19cafb93bce
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214639"
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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|**dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
