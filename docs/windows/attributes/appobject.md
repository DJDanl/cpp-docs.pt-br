---
title: appobject (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.appobject
helpviewer_keywords:
- appobject attribute
ms.assetid: 8ce30b73-e945-403e-a755-6bc78078a695
ms.openlocfilehash: ae3547a32e6d5984a9ef95e495ba119c3a2ed385
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222154"
---
# <a name="appobject"></a>appobject

Identifica a coclass como um objeto Application, que está associado a um aplicativo Full. exe e indica que as funções e as propriedades da coclass estão disponíveis globalmente nesta biblioteca de [tipos](../../mfc/automation-clients-using-type-libraries.md).

## <a name="syntax"></a>Sintaxe

```cpp
[appobject]
```

## <a name="remarks"></a>Comentários

O atributo **appobject** C++ tem a mesma funcionalidade que o atributo MIDL [appobject](/windows/win32/Midl/appobject) .

## <a name="example"></a>Exemplo

O código a seguir mostra uma definição de classe simples precedida por um bloco de atributo que inclui **appobject**:

```cpp
// cpp_attr_ref_appobject.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLib", uuid="f1ce17f0-a5df-4d26-95f6-0a122197ac5b")];

[object, uuid="905de6db-7a12-45ab-9f8b-b39f5112f010"]
__interface ICustom {};

[coclass, appobject,uuid="00395340-745f-4b69-bd58-e2921452b9fc"]
class A : public ICustom {
   int i;
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|`coclass`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)
