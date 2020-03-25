---
title: ID (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.id
helpviewer_keywords:
- id attribute
ms.assetid: a48d2c99-c5d2-4f46-bf96-5ac88dcb5d0c
ms.openlocfilehash: 79e49b2c074cd82323c74489e33812c10c442c61
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168051"
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
[Atributos de membro de dados](data-member-attributes.md)<br/>
[defaultvalue](defaultvalue.md)<br/>
[Em](in-cpp.md)<br/>
[out](out-cpp.md)
