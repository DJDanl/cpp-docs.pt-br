---
title: retval (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
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
ms.openlocfilehash: e2b71271dc0579e1d0682b95a0d3bdf57d197d1a
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790246"
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

Veja o exemplo de [associável](bindable.md) para uso do exemplo **retval**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|**out**|
|**Atributos inválidos**|**in**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)  