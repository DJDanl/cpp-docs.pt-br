---
title: Hidden (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.hidden
helpviewer_keywords:
- hidden attribute
ms.assetid: 199c96dd-fc07-46c7-af93-92020aebebe7
ms.openlocfilehash: 6b420e8f50bd217de460a81f5faaf9583c701376
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168090"
---
# <a name="hidden"></a>oculto

Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.

## <a name="syntax"></a>Sintaxe

```cpp
[hidden]
```

## <a name="remarks"></a>Comentários

O atributo **Hidden** C++ tem a mesma funcionalidade que o atributo MIDL [oculto](/windows/win32/Midl/hidden) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de como usar **Hidden**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**, **classe**, **struct**, método, Propriedade|
|**Repetível**|Não|
|**Atributos necessários**|**coclass** (quando aplicado à **classe** ou **estrutura**)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)
