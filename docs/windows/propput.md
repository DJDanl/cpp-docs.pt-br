---
title: propput | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.propput
dev_langs:
- C++
helpviewer_keywords:
- propput attribute
ms.assetid: 1f84dda9-9cce-4e16-aaf0-b2c5219827f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a4e67da1e77882f6bc2e7fd7b5df57b9f0fa97c0
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612269"
---
# <a name="propput"></a>propput

Especifica uma função de definição de propriedade.

## <a name="syntax"></a>Sintaxe

```cpp
[propput]
```

## <a name="remarks"></a>Comentários

O **propput** atributo C++ tem a mesma funcionalidade que o [propput](http://msdn.microsoft.com/library/windows/desktop/aa367146) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](../windows/bindable.md) para uso do exemplo **propput**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`propget`, `propputref`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[propget](../windows/propget.md)  
[propputref](../windows/propputref.md)