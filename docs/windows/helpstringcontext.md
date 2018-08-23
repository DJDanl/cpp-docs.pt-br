---
title: helpstringcontext | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpstringcontext
dev_langs:
- C++
helpviewer_keywords:
- helpstringcontext attribute [C++]
ms.assetid: d4cd135e-d91c-4aa3-9353-8aeb096f52cf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 34aed4325d2e946f59a4f17275d6b0aabe4de06c
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589967"
---
# <a name="helpstringcontext"></a>helpstringcontext

Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstringcontext(
   contextID
) ]
```

### <a name="parameters"></a>Parâmetros

*contextID*  
Um identificador de contexto de ajuda de 32 bits na **ajudar** arquivo.

## <a name="remarks"></a>Comentários

O **helpstringcontext** atributo C++ tem a mesma funcionalidade que o [helpstringcontext](http://msdn.microsoft.com/library/windows/desktop/aa366858) atributo ODL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_helpstringcontext.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[   object,
   helpstring("help string"),
   helpstringcontext(1),
   uuid="11111111-1111-1111-1111-111111111111"
]
__interface IMyI
{
   HRESULT xx();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[módulo](../windows/module-cpp.md)  