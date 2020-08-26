---
title: registration_script (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.registration_script
helpviewer_keywords:
- registration_script attribute
ms.assetid: 786f8072-9187-4163-a979-7a604dd4c888
ms.openlocfilehash: 8a57f0b3d0925d1e1096a31734fa4c9d666c5743
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846076"
---
# <a name="registration_script"></a>registration_script

Executa o script de registro personalizado especificado.

## <a name="syntax"></a>Sintaxe

```cpp
[ registration_script(script) ]
```

### <a name="parameters"></a>parâmetros

*script*<br/>
O caminho completo para um arquivo de script de registro personalizado (. rgs). Um valor de **nenhum**, como `script = "none"` , indica que a coclass não tem requisitos de registro.

## <a name="remarks"></a>Comentários

O atributo **registration_script** C++ executa o script de registro personalizado especificado pelo *script*. Se esse atributo não for especificado, um arquivo. rgs padrão (contendo informações para registrar o componente) será usado. Para obter mais informações sobre arquivos. rgs, consulte [o componente de registro do ATL (registrador)](../../atl/atl-registry-component-registrar.md).

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento.

## <a name="example"></a>Exemplo

O código a seguir especifica que o componente tem um script de registro chamado cpp_attr_ref_registration_script. rgs.

```cpp
// cpp_attr_ref_registration_script.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module (name="REG")];

[object, uuid("d9cd196b-6836-470b-9b9b-5b04b828e5b0")]
__interface IFace {};

// requires "cpp_attr_ref_registration_script.rgs"
// create sample .RGS file "cpp_attr_ref_registration_script.rgs" if it does not exist
[ coclass, registration_script(script="cpp_attr_ref_registration_script.rgs"),
  uuid("50d3ad42-3601-4f26-8cfe-0f1f26f98f67")]
class CMyClass:public IFace {};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Um ou mais dos seguintes: `coclass` , `progid` ou `vi_progid` .|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[rdx](rdx.md)
