---
title: pointer_default | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.pointer_default
dev_langs:
- C++
helpviewer_keywords:
- pointer_default attribute
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: aac6e0456bf8a63712c498114d403c05af5ccddb
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43212202"
---
# <a name="pointerdefault"></a>pointer_default

Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.

## <a name="syntax"></a>Sintaxe

```cpp
[ pointer_default(
   value
) ]
```

### <a name="parameters"></a>Parâmetros

*value*  
Um valor que descreve o tipo de ponteiro: **ptr**, **ref**, ou **exclusivo**.

## <a name="remarks"></a>Comentários

O **pointer_default** atributo C++ tem a mesma funcionalidade que o [pointer_default](/windows/desktop/Midl/pointer-default) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](../windows/defaultvalue.md) para uso do exemplo **pointer_default**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  