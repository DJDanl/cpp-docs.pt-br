---
title: satype (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.satype
helpviewer_keywords:
- satype attribute
ms.assetid: 1716590b-6bcb-4aba-b1bc-82f7335f02c3
ms.openlocfilehash: 7588e8d855d648309c46d981898cfbbf7888f4c9
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59025718"
---
# <a name="satype"></a>satype

Especifica o tipo de dados a `SAFEARRAY` estrutura.

## <a name="syntax"></a>Sintaxe

```cpp
[ satype(data_type) ]
```

### <a name="parameters"></a>Parâmetros

*data_type*<br/>
O tipo de dados para o `SAFEARRAY` estrutura de dados que está sendo passada como um parâmetro para um método de interface.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

## <a name="remarks"></a>Comentários

O **satype** atributo C++ Especifica o tipo de dados a `SAFEARRAY`.

> [!NOTE]
> Um nível de indireção é descartado do `SAFEARRAY` ponteiro no arquivo. idl gerado a partir de como ele é declarado no arquivo. cpp.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_satype.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="MyModule")];
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]
__interface A {
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);
};
```

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[id](id.md)