---
title: Hidden (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.hidden
helpviewer_keywords:
- hidden attribute
ms.assetid: 199c96dd-fc07-46c7-af93-92020aebebe7
ms.openlocfilehash: ffa1ce01cfd570de7b699e415f10b27acf525047
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830950"
---
# <a name="hidden"></a>oculto

Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.

## <a name="syntax"></a>Sintaxe

```cpp
[hidden]
```

## <a name="remarks"></a>Comentários

O atributo C++ **oculto** tem a mesma funcionalidade que o atributo MIDL [oculto](/windows/win32/Midl/hidden) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de como usar **Hidden**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**interface**, **`class`** , **`struct`** , método, Propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** (quando aplicado a **`class`** or **`struct`** )|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos do método](method-attributes.md)
