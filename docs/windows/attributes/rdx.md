---
title: RDX (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.rdx
helpviewer_keywords:
- rdx attribute
ms.assetid: ff8e4312-c1ad-4934-bdaa-86f54409651e
ms.openlocfilehash: f61eaf535102c8885e828176434acf221dfe2457
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836875"
---
# <a name="rdx"></a>rdx

Cria uma chave do registro ou modifica uma chave do registro existente.

## <a name="syntax"></a>Sintaxe

```cpp
[ rdx(key, valuename=NULL, regtype) ]
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
O nome da chave a ser criada ou aberta.

*valueName*<br/>
Adicional Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.

*regtype*<br/>
O tipo de chave do registro que está sendo adicionado. Pode ser um dos seguintes: `text` , `dword` , `binary` ou `CString` .

## <a name="remarks"></a>Comentários

O atributo **RDX** C++ cria ou modifica uma chave de registro existente para um componente com. O atributo adiciona uma macro BEGIN_RDX_MAP ao objeto que implementa o membro de destino. `RegistryDataExchange`, uma função injetada como resultado da macro BEGIN_RDX_MAP, pode ser usada para transferir dados entre o registro e os membros de dados

Esse atributo pode ser usado em conjunto com os atributos [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) ou outros atributos que implicam um deles.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`** ou **`struct`** membro|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="example"></a>Exemplo

O código a seguir adiciona uma chave do registro chamada MyValue ao sistema que descreve o componente COM do CMyClass.

```cpp
// cpp_attr_ref_rdx.cpp
// compile with: /LD /link /OPT:NOREF
#define _ATL_ATTRIBUTES
#include "atlbase.h"

[module (name="MyLib")];

class CMyClass {
public:
   CMyClass() {
      strcpy_s(m_sz, "SomeValue");
   }

   [ rdx(key = "HKCR\\MyApp.MyApp.1", valuename = "MyValue", regtype = "text")]
   char m_sz[256];
};
```

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[registration_script](registration-script.md)
