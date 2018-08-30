---
title: last_is | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.last_is
dev_langs:
- C++
helpviewer_keywords:
- last_is attribute
ms.assetid: 9e045ac0-fa38-4249-af55-67bde5d0a58c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e7b699f5b6aa023473416b822a94d9b3a91c2b07
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221113"
---
# <a name="lastis"></a>last_is

Especifica o índice do último elemento da matriz a ser transmitido.

## <a name="syntax"></a>Sintaxe

```cpp
[ last_is(
   "expression"
) ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*  
Uma ou mais expressões de linguagem C. Slots de argumentos vazia são permitidos.

## <a name="remarks"></a>Comentários

O **last_is** atributo C++ tem a mesma funcionalidade que o [last_is](/windows/desktop/Midl/last-is) atributo MIDL.

## <a name="example"></a>Exemplo

Ver [first_is](../windows/first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Campo do **struct** ou **união**, a interface do parâmetro, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[Atributos de parâmetro](../windows/parameter-attributes.md)  
[first_is](../windows/first-is.md)  
[max_is](../windows/max-is.md)  
[length_is](../windows/length-is.md)  
[size_is](../windows/size-is.md)  