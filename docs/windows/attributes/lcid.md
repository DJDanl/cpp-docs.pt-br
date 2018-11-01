---
title: LCID (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.lcid
helpviewer_keywords:
- LCID attribute
ms.assetid: 7f248c69-ee1c-42c3-9411-39cf27c9f43d
ms.openlocfilehash: e431736fcd38b3c08936e65ecf05594142ced4e1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50655306"
---
# <a name="lcid"></a>lcid

Permite que você passar um identificador de localidade para uma função.

## <a name="syntax"></a>Sintaxe

```cpp
[lcid]
```

## <a name="remarks"></a>Comentários

O **lcid** atributo C++ implementa a funcionalidade da [lcid](/windows/desktop/Midl/lcid) atributo MIDL. Se você quiser implementar a localidade para um bloco de biblioteca, use o **lcid =** `lcid` parâmetro para o [módulo](module-cpp.md) atributo.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_lcid.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLibrary")];
typedef long HRESULT;

[dual, uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA")]
__interface IStatic {
   HRESULT MyFunc([in, lcid] long LocaleID, [out, retval] BSTR * ReturnVal);
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)