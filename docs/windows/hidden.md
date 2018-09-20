---
title: oculto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.hidden
dev_langs:
- C++
helpviewer_keywords:
- hidden attribute
ms.assetid: 199c96dd-fc07-46c7-af93-92020aebebe7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 726a44a33be5fe82986d4696c5420e07d5c103ff
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416455"
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

Veja o exemplo de [associável](../windows/bindable.md) para obter um exemplo de como usar **oculto**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **classe**, **struct**, método, propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** (quando aplicado a **classe** ou **struct**)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de interface](../windows/interface-attributes.md)<br/>
[Atributos de classe](../windows/class-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)  