---
title: Range (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.range
helpviewer_keywords:
- range attribute
ms.assetid: f352f79e-ecb3-4cdd-9cdd-8406ef473594
ms.openlocfilehash: 8ed0ba2c53992dd19d1c4491f8085e955146224c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839472"
---
# <a name="range-c"></a>range (C++)

Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.

## <a name="syntax"></a>Sintaxe

```cpp
[ range(low, high) ]
```

### <a name="parameters"></a>parâmetros

*pequena*<br/>
O valor de intervalo baixo.

*elevada*<br/>
O valor de intervalo alto.

## <a name="remarks"></a>Comentários

O atributo **intervalo** de C++ tem a mesma funcionalidade que o atributo MIDL de [intervalo](/windows/win32/Midl/range) .

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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método de interface, parâmetro de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de membro de dados](data-member-attributes.md)
