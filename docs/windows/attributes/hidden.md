---
title: (C++ COM atributo oculto)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.hidden
helpviewer_keywords:
- hidden attribute
ms.assetid: 199c96dd-fc07-46c7-af93-92020aebebe7
ms.openlocfilehash: d1d87ea057b22984a0e0f8f5518899e36f7d0221
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59038415"
---
# <a name="hidden"></a>oculto

Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.

## <a name="syntax"></a>Sintaxe

```cpp
[hidden]
```

## <a name="remarks"></a>Comentários

O **ocultos** atributo C++ tem a mesma funcionalidade que o [oculto](/windows/desktop/Midl/hidden) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](bindable.md) para obter um exemplo de como usar **oculto**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **classe**, **struct**, método, propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** (quando aplicado a **classe** ou **struct**)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)