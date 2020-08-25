---
title: immediatebind (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.immediatebind
helpviewer_keywords:
- immediatebind attribute
ms.assetid: 186d40e6-9166-4d0c-9853-4e7e4d25226f
ms.openlocfilehash: d5241a6972ea0444a980e3e868c44e7e0c15dc64
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833043"
---
# <a name="immediatebind"></a>immediatebind

Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto associado a um dado.

## <a name="syntax"></a>Sintaxe

```cpp
[immediatebind]
```

## <a name="remarks"></a>Comentários

O atributo **immediatebind** C++ tem a mesma funcionalidade que o atributo MIDL [immediatebind](/windows/win32/Midl/immediatebind) .

## <a name="example"></a>Exemplo

Consulte [ligável](bindable.md) para obter um exemplo de como usar **immediatebind**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[defaultbind](defaultbind.md)<br/>
[displaybind](displaybind.md)<br/>
[requestedit](requestedit.md)
