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
ms.openlocfilehash: 6e10d147702908eff5dcdd8889f588030dcffbce
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384852"
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

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de parâmetro](../windows/parameter-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)  