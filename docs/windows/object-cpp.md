---
title: objeto (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 9e1cf7f100c34023e6fea96c9764cce2371dcaaf
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412678"
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

Ver [nonbrowsable](../windows/nonbrowsable.md) para obter um exemplo de como usar **objeto**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de interface](../windows/interface-attributes.md)<br/>
[dual](../windows/dual.md)<br/>
[dispinterface](../windows/dispinterface.md)<br/>
[custom](../windows/custom-cpp.md)<br/>
[__interface](../cpp/interface.md)  