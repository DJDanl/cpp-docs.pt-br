---
title: ODL (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.odl
helpviewer_keywords:
- odl attribute
ms.assetid: 75dcb314-b50f-4a63-9180-507ac1bc78f3
ms.openlocfilehash: a2f3c58e40dc14d256ca694bb1266aed13dc9620
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842813"
---
# <a name="odl"></a>odl

Identifica uma interface como uma interface de linguagem de descrição de objeto (ODL). O compilador MIDL não requer o atributo **ODL** ; Ele é reconhecido apenas por compatibilidade com arquivos. odl mais antigos.

## <a name="syntax"></a>Sintaxe

```cpp
[odl]
```

## <a name="remarks"></a>Comentários

O atributo **ODL** C++ tem a mesma funcionalidade que o atributo MIDL [ODL](/windows/win32/Midl/odl) .

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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
