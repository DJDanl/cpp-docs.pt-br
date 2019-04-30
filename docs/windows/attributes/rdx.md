---
title: RDX (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.rdx
helpviewer_keywords:
- rdx attribute
ms.assetid: ff8e4312-c1ad-4934-bdaa-86f54409651e
ms.openlocfilehash: 2790c3de01d21242daee73fc442ad22d88739355
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407491"
---
# <a name="rdx"></a>rdx

Cria uma chave do registro ou modifica uma chave do registro existente.

## <a name="syntax"></a>Sintaxe

```cpp
[ rdx(key, valuename=NULL, regtype) ]
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
O nome da chave a ser criado ou aberto.

*valuename*<br/>
(Opcional) Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.

*regtype*<br/>
O tipo de chave do registro que está sendo adicionado. Pode ser uma das seguintes opções: `text`, `dword`, `binary`, ou `CString`.

## <a name="remarks"></a>Comentários

O **rdx** atributo C++ cria ou modifica uma chave do registro existente para um componente COM. O atributo adiciona uma macro BEGIN_RDX_MAP para o objeto que implementa o membro de destino. `RegistryDataExchange`, uma função injetada como resultado da macro BEGIN_RDX_MAP, pode ser usada para transferir dados entre o registro e os membros de dados

Esse atributo pode ser usado em conjunto com o [coclass](coclass.md), [progid](progid.md), ou [vi_progid](vi-progid.md) atributos ou outros atributos que implica uma destas opções.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe** ou **struct** membro|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="example"></a>Exemplo

O código a seguir adiciona uma chave do Registro chamada MyValue para o sistema que descreve o componente COM CMyClass.

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

## <a name="see-also"></a>Consulte também

[Atributos de COM](com-attributes.md)<br/>
[registration_script](registration-script.md)