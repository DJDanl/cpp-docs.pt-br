---
title: immediatebind (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.immediatebind
helpviewer_keywords:
- immediatebind attribute
ms.assetid: 186d40e6-9166-4d0c-9853-4e7e4d25226f
ms.openlocfilehash: 35e8ea4a761fd3cf36da335dc8519ba71772b4e9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50647714"
---
# <a name="immediatebind"></a>immediatebind

Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de associação de dados.

## <a name="syntax"></a>Sintaxe

```cpp
[immediatebind]
```

## <a name="remarks"></a>Comentários

O **immediatebind** atributo C++ tem a mesma funcionalidade que o [immediatebind](/windows/desktop/Midl/immediatebind) atributo MIDL.

## <a name="example"></a>Exemplo

Ver [associável](bindable.md) para obter um exemplo de como usar **immediatebind**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[defaultbind](defaultbind.md)<br/>
[displaybind](displaybind.md)<br/>
[requestedit](requestedit.md)