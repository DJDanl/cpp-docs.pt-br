---
title: Threading (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.threading
dev_langs:
- C++
helpviewer_keywords:
- threading attribute
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 700e8915535a38233b1cd1e55669c1e3c5f372dd
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591547"
---
# <a name="threading-c"></a>threading (C++)

Especifica o modelo de threading para um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ threading(
   model=enumeration
) ]
```

### <a name="parameters"></a>Parâmetros

*modelo* (opcional)  
Um dos seguintes modelos de threads:

- `apartment` (apartment threading)

- `neutral` (Componentes do .NET framework sem interface do usuário)

- `single` (threading simples)

- `free` (gratuito threading)

- `both` (apartment e threading livre)

O valor padrão é `apartment`.

## <a name="remarks"></a>Comentários

O **threading** atributo C++ não aparece no arquivo. idl gerado, mas será usado na implementação do seu objeto COM.

Em projetos ATL, se o [coclass](../windows/coclass.md) atributo também estiver presente, o modelo de threading especificado por *modelo* é passado como o parâmetro de modelo para o [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) classe , inseridos pelo `coclass` atributo.

O **threading** atributo também protege o acesso a um [event_source](../windows/event-source.md).

## <a name="example"></a>Exemplo

Consulte a [licenciado](../windows/licensed.md) exemplo para uso do exemplo **threading**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de COM](../windows/com-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Suporte de multithreading para código anterior (Visual C++)](../parallel/multithreading-support-for-older-code-visual-cpp.md)  
[Apartments neutros](http://msdn.microsoft.com/library/windows/desktop/ms681813)  