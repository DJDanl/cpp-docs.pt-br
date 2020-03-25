---
title: objeto (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.object
helpviewer_keywords:
- object attribute
ms.assetid: f2d3c231-630d-4b4c-bd15-b1c30df362dd
ms.openlocfilehash: 4545d899c13a1eabf8ea5fb6fe3918fb5f05b626
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214641"
---
# <a name="object-c"></a>object (C++)

Identifica uma interface personalizada.

## <a name="syntax"></a>Sintaxe

```cpp
[object]
```

## <a name="remarks"></a>Comentários

Ao anteceder uma definição de interface, o atributo **Object** C++ faz com que a interface seja colocada no arquivo. idl como uma interface personalizada.

Qualquer interface marcada com objeto deve herdar de `IUnknown`. Essa condição será satisfeita se qualquer uma das interfaces base herdarem de `IUnknown`. Se nenhuma das interfaces base herdar de `IUnknown`, o compilador fará com que a interface marcada com **Object** derive de `IUnknown`.

## <a name="example"></a>Exemplo

Consulte [nonnavegáveis](nonbrowsable.md) para obter um exemplo de como usar o **objeto**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[dual](dual.md)<br/>
[dispinterface](dispinterface.md)<br/>
[custom](custom-cpp.md)<br/>
[__interface](../../cpp/interface.md)
