---
title: oleautomation (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.oleautomation
dev_langs:
- C++
helpviewer_keywords:
- oleautomation attribute
ms.assetid: c1086c91-260b-4dc3-b244-662852d09906
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ccc83dd6f51c3b7072b17d141f29e93c63688fa1
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50059526"
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

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)