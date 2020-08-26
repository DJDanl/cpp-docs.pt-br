---
title: satype (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.satype
helpviewer_keywords:
- satype attribute
ms.assetid: 1716590b-6bcb-4aba-b1bc-82f7335f02c3
ms.openlocfilehash: 16da256f491dbb0002d92cadaceda14a49eb2192
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842774"
---
# <a name="satype"></a>satype

Especifica o tipo de dados da `SAFEARRAY` estrutura.

## <a name="syntax"></a>Sintaxe

```cpp
[ satype(data_type) ]
```

### <a name="parameters"></a>parâmetros

*data_type*<br/>
O tipo de dados para a `SAFEARRAY` estrutura de dados que está sendo passada como um parâmetro para um método de interface.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

## <a name="remarks"></a>Comentários

O atributo **satype** C++ especifica o tipo de dados do `SAFEARRAY` .

> [!NOTE]
> Um nível de indireção é descartado do `SAFEARRAY` ponteiro no arquivo. idl gerado de como ele é declarado no arquivo. cpp.

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

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[id](id.md)
