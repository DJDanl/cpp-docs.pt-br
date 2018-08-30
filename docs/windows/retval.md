---
title: retval | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.retval
dev_langs:
- C++
helpviewer_keywords:
- retval attribute
ms.assetid: bfa16f08-157d-4eea-afde-1232c54b8501
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7ff83b156054774a06a371e7832dc73dc95a579c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221252"
---
# <a name="retval"></a>retval

Designa o parâmetro que recebe o valor de retorno do membro.

## <a name="syntax"></a>Sintaxe

```cpp
[retval]
```

## <a name="remarks"></a>Comentários

O **retval** atributo C++ tem a mesma funcionalidade que o [retval](/windows/desktop/Midl/retval) atributo MIDL.

**retval** deve aparecer no último argumento na declaração da função.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](../windows/bindable.md) para uso do exemplo **retval**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|**out**|
|**Atributos inválidos**|**in**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de parâmetro](../windows/parameter-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  