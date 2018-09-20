---
title: size_is | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.size_is
dev_langs:
- C++
helpviewer_keywords:
- size_is attribute
ms.assetid: 70192d09-f6c5-4d52-b3fe-303f8cb10aa5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0505fde4ea92c643a6038d64d10ec06cda9cb60d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392327"
---
# <a name="sizeis"></a>size_is

Especifique o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.

## <a name="syntax"></a>Sintaxe

```cpp
[ size_is(
   "expression"
) ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*<br/>
O tamanho da memória alocada para ponteiros de tamanho.

## <a name="remarks"></a>Comentários

O **size_is** atributo C++ tem a mesma funcionalidade que o [size_is](/windows/desktop/Midl/size-is) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [first_is](../windows/first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Campo do **struct** ou **união**, a interface do parâmetro, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`max_is`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](../windows/parameter-attributes.md)<br/>
[first_is](../windows/first-is.md)<br/>
[last_is](../windows/last-is.md)<br/>
[max_is](../windows/max-is.md)<br/>
[length_is](../windows/length-is.md)  