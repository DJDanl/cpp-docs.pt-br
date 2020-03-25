---
title: immediatebind (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.immediatebind
helpviewer_keywords:
- immediatebind attribute
ms.assetid: 186d40e6-9166-4d0c-9853-4e7e4d25226f
ms.openlocfilehash: d0fb85a3f5642bc5fffcad29892ca15bb13a1ce0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166908"
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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[defaultbind](defaultbind.md)<br/>
[displaybind](displaybind.md)<br/>
[requestedit](requestedit.md)
