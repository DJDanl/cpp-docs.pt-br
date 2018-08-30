---
title: propputref | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.propputref
dev_langs:
- C++
helpviewer_keywords:
- propputref attribute
ms.assetid: 9b0aed74-fdc7-4e59-9117-949bea4f86dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b0b36342b7760eea074fe15506386bb3d7ce6764
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221236"
---
# <a name="propputref"></a>propputref

Especifica uma função de definição de propriedade que usa uma referência em vez de um valor.

## <a name="syntax"></a>Sintaxe

```cpp
[propputref]
```

## <a name="remarks"></a>Comentários

O **propputref** atributo C++ tem a mesma funcionalidade que o [propputref](/windows/desktop/Midl/propputref) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](../windows/bindable.md) para uso do exemplo **propputref**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`propget`, `propput`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[propget](../windows/propget.md)  
[propput](../windows/propput.md)  