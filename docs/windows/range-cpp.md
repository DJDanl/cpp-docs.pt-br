---
title: intervalo (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.range
dev_langs:
- C++
helpviewer_keywords:
- range attribute
ms.assetid: f352f79e-ecb3-4cdd-9cdd-8406ef473594
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 80b8546e461930ac184e0f5b3ed2b34499cc8d3c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384216"
---
# <a name="range-c"></a>range (C++)

Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.

## <a name="syntax"></a>Sintaxe

```cpp
[ range(
   low,
   high
) ]
```

### <a name="parameters"></a>Parâmetros

*low*<br/>
O valor baixo do intervalo.

*high*<br/>
O valor de intervalo alto.

## <a name="remarks"></a>Comentários

O **intervalo** atributo C++ tem a mesma funcionalidade que o [intervalo](/windows/desktop/Midl/range) atributo MIDL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_range.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[object, uuid("9E66A290-4365-11D2-A997-00C04FA37DDB")]
__interface ICustom {
   HRESULT Custom([in] long l, [out, retval] long *pLong);
   HRESULT length_is1([in, range(0, 999)] long f, [in, length_is(f)] char array[10]);
   HRESULT length_is2([in, range(-99, -1)] long f, [in, length_is("f"), size_is(10)] char *array);
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método de interface, o parâmetro de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)<br/>
[Atributos de parâmetro](../windows/parameter-attributes.md)<br/>
[Atributos de membro de dados](../windows/data-member-attributes.md)  