---
title: odl (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.odl
helpviewer_keywords:
- odl attribute
ms.assetid: 75dcb314-b50f-4a63-9180-507ac1bc78f3
ms.openlocfilehash: 90f9f1df23542138b2fac0dcfe0e122f1993d805
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59025020"
---
# <a name="odl"></a>odl

Identifica uma interface como uma interface de linguagem de descrição do objeto (ODL). O compilador MIDL não requer o **odl** atributo; ele é reconhecido somente para compatibilidade com os arquivos. odl mais antigos.

## <a name="syntax"></a>Sintaxe

```cpp
[odl]
```

## <a name="remarks"></a>Comentários

O **odl** atributo C++ tem a mesma funcionalidade que o [odl](/windows/desktop/Midl/odl) atributo MIDL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_odl.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLIb")];

[odl, oleautomation, dual, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMyInterface
{
   HRESULT x();
};

[coclass, uuid("00000000-0000-0000-0000-000000000002")]
class cmyClass : public IMyInterface
{
public:
   HRESULT x(){}
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)