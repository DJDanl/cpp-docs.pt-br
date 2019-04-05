---
title: oleautomation (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.oleautomation
helpviewer_keywords:
- oleautomation attribute
ms.assetid: c1086c91-260b-4dc3-b244-662852d09906
ms.openlocfilehash: 74701742de904b76e7b1152c8ddb3f2f5dd953c2
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59031706"
---
# <a name="oleautomation"></a>oleautomation

Indica que uma interface é compatível com a automação.

## <a name="syntax"></a>Sintaxe

```cpp
[oleautomation]
```

## <a name="remarks"></a>Comentários

O **oleautomation** atributo C++ tem a mesma funcionalidade que o [oleautomation](/windows/desktop/Midl/oleautomation) atributo MIDL.

## <a name="example"></a>Exemplo

Consulte os exemplos para [defaultvalue](defaultvalue.md) e [nonextensible](nonextensible.md) para uso do exemplo **oleautomation**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)