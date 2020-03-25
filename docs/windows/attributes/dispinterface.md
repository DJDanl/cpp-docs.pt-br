---
title: dispinterface (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.dispinterface
helpviewer_keywords:
- dispinterface attribute
ms.assetid: 61c5a4a1-ae92-47e9-8ee4-f847be90172b
ms.openlocfilehash: 66567b0a1b043136e0a754e3a52bbdd7c463e178
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168233"
---
# <a name="dispinterface"></a>dispinterface

Coloca uma interface no arquivo. idl como uma interface de expedição.

## <a name="syntax"></a>Sintaxe

```cpp
[dispinterface]
```

## <a name="remarks"></a>Comentários

Quando o atributo **dispinterface** C++ precede uma interface, ele faz com que a interface seja colocada dentro do bloco de biblioteca no arquivo. idl gerado.

A menos que você especifique uma classe base, uma interface de expedição será derivada de `IDispatch`. Você deve especificar uma [ID](id.md) para os membros de uma interface de expedição.

O exemplo de uso de [dispinterface](/windows/win32/Midl/dispinterface) na documentação de MIDL:

```cpp
dispinterface helloPro
   { interface hello; };
```

Não é válido para o atributo **dispinterface** .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de como usar **dispinterface**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`dual`, `object`, `oleautomation`, `local`, `ms_union`|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos por uso](attributes-by-usage.md)<br/>
[uuid](uuid-cpp-attributes.md)<br/>
[dual](dual.md)<br/>
[custom](custom-cpp.md)<br/>
[object](object-cpp.md)<br/>
[__interface](../../cpp/interface.md)
