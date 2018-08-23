---
title: max_is | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.max_is
dev_langs:
- C++
helpviewer_keywords:
- max_is attribute
ms.assetid: 7c851f5c-6649-4d77-a792-247c37d8f560
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fc4d8486fe48841ae37ad0ceb41f0da7cfd62c5e
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596248"
---
# <a name="maxis"></a>max_is

Designa o valor máximo para um índice de matriz válida.

## <a name="syntax"></a>Sintaxe

```cpp
[ max_is(
   "expression"
) ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*  
Uma ou mais expressões de linguagem C. Slots de argumentos vazia são permitidos.

## <a name="remarks"></a>Comentários

O **max_is** atributo C++ tem a mesma funcionalidade que o [max_is](http://msdn.microsoft.com/library/windows/desktop/aa367074) atributo MIDL.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Campo do **struct** ou **união**, a interface do parâmetro, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**size_is**|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="example"></a>Exemplo

Ver [first_is](../windows/first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[Atributos de parâmetro](../windows/parameter-attributes.md)  
[first_is](../windows/first-is.md)  
[last_is](../windows/last-is.md)  
[length_is](../windows/length-is.md)  
[size_is](../windows/size-is.md)  