---
title: oleautomation | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: ea14cd3e8c1eebbdbcad3a21d64652acee635407
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43219933"
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

Consulte os exemplos para [defaultvalue](../windows/defaultvalue.md) e [nonextensible](../windows/nonextensible.md) para uso do exemplo **oleautomation**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  