---
title: ID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.id
dev_langs:
- C++
helpviewer_keywords:
- id attribute
ms.assetid: a48d2c99-c5d2-4f46-bf96-5ac88dcb5d0c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9b5250a730b0ce80cbbe9698b4b5e636a85986b6
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43223180"
---
# <a name="id"></a>id

Especifica um *dispid* parâmetro para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).

## <a name="syntax"></a>Sintaxe

```cpp
[ id(
   dispid
) ]
```

### <a name="parameters"></a>Parâmetros

*DISPID*  
A ID de expedição para o método de interface.

## <a name="remarks"></a>Comentários

O **identificação** atributo C++ tem a mesma funcionalidade que o [id](/windows/desktop/Midl/id) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](../windows/bindable.md) para obter um exemplo de como usar **id**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[Atributos de membro de dados](../windows/data-member-attributes.md)  
[defaultvalue](../windows/defaultvalue.md)  
[in](../windows/in-cpp.md)  
[out](../windows/out-cpp.md)  