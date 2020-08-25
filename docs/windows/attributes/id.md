---
title: ID (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.id
helpviewer_keywords:
- id attribute
ms.assetid: a48d2c99-c5d2-4f46-bf96-5ac88dcb5d0c
ms.openlocfilehash: f67bf21fbe0040884cba4a54ed8d2a230cb20cd6
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830547"
---
# <a name="id"></a>id

Especifica um parâmetro *DISPID* para uma função membro (uma propriedade ou um método, em uma interface ou Dispinterface).

## <a name="syntax"></a>Sintaxe

```cpp
[ id(dispid) ]
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
A ID de expedição para o método de interface.

## <a name="remarks"></a>Comentários

O atributo **ID** C++ tem a mesma funcionalidade que o atributo MIDL de [ID](/windows/win32/Midl/id) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de como usar **ID**.

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
[Atributos de membro de dados](data-member-attributes.md)<br/>
[ValorPadrão](defaultvalue.md)<br/>
[Em](in-cpp.md)<br/>
[fora](out-cpp.md)
