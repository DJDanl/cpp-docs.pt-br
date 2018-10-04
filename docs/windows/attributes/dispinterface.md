---
title: dispinterface (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
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
ms.openlocfilehash: 3b02244e0576f99cc0a6940f2ee4a13511cfbe6f
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790067"
---
# <a name="dispinterface"></a>dispinterface

Coloca uma interface no arquivo. idl como uma interface de expedição.

## <a name="syntax"></a>Sintaxe

```cpp
[dispinterface]
```

## <a name="remarks"></a>Comentários

Quando o **dispinterface** atributo C++ precede uma interface, ele faz com que a interface a ser colocado dentro do bloco de biblioteca no arquivo. idl gerado.

A menos que você especifique uma classe base, uma interface de expedição será derivado `IDispatch`. Você deve especificar um [id](id.md) para os membros de uma interface de expedição.

O exemplo de uso de [dispinterface](/windows/desktop/Midl/dispinterface) na documentação do MIDL:

```cpp
dispinterface helloPro
   { interface hello; };
```

não é válido para o **dispinterface** atributo.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](bindable.md) para obter um exemplo de como usar **dispinterface**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`dual`, `object`, `oleautomation`, `local`, `ms_union`|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos por uso](attributes-by-usage.md)<br/>
[uuid](uuid-cpp-attributes.md)<br/>
[dual](dual.md)<br/>
[custom](custom-cpp.md)<br/>
[object](object-cpp.md)<br/>
[__interface](../../cpp/interface.md)  