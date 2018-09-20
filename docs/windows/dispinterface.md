---
title: dispinterface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.dispinterface
dev_langs:
- C++
helpviewer_keywords:
- dispinterface attribute
ms.assetid: 61c5a4a1-ae92-47e9-8ee4-f847be90172b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 008aade041a1a8effd432c0c01eb898bb15381f7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46414669"
---
# <a name="dispinterface"></a>dispinterface

Coloca uma interface no arquivo. idl como uma interface de expedição.

## <a name="syntax"></a>Sintaxe

```cpp
[dispinterface]
```

## <a name="remarks"></a>Comentários

Quando o **dispinterface** atributo C++ precede uma interface, ele faz com que a interface a ser colocado dentro do bloco de biblioteca no arquivo. idl gerado.

A menos que você especifique uma classe base, uma interface de expedição será derivado `IDispatch`. Você deve especificar um [id](../windows/id.md) para os membros de uma interface de expedição.

O exemplo de uso de [dispinterface](/windows/desktop/Midl/dispinterface) na documentação do MIDL:

```cpp
dispinterface helloPro
   { interface hello; };
```

não é válido para o **dispinterface** atributo.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](../windows/bindable.md) para obter um exemplo de como usar **dispinterface**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`dual`, `object`, `oleautomation`, `local`, `ms_union`|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos por uso](../windows/attributes-by-usage.md)<br/>
[uuid](../windows/uuid-cpp-attributes.md)<br/>
[dual](../windows/dual.md)<br/>
[custom](../windows/custom-cpp.md)<br/>
[object](../windows/object-cpp.md)<br/>
[__interface](../cpp/interface.md)  