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
ms.openlocfilehash: 6a98c9016281a67211a41d1c63fcb9886a0b3c35
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43222504"
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

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos por uso](../windows/attributes-by-usage.md)  
[uuid](../windows/uuid-cpp-attributes.md)  
[dual](../windows/dual.md)  
[custom](../windows/custom-cpp.md)  
[object](../windows/object-cpp.md)  
[__interface](../cpp/interface.md)  