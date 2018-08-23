---
title: defaultvtable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.defaultvtable
dev_langs:
- C++
helpviewer_keywords:
- defaultvtable attribute
ms.assetid: 5b3ed483-f69e-44dd-80fc-952028eb9d73
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5bbbc225e4fee1aba380694fc3b39a7f59e1a294
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42611480"
---
# <a name="defaultvtable"></a>defaultvtable

Define uma interface como a interface de vtable padrão para um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ defaultvtable(
   interface
) ]
```

### <a name="parameters"></a>Parâmetros

*interface*  
A interface designada que você deseja ter vtable padrão para o objeto COM.

## <a name="remarks"></a>Comentários

O **defaultvtable** atributo C++ tem a mesma funcionalidade que o [defaultvtable](http://msdn.microsoft.com/library/windows/desktop/aa366795) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra os atributos em uma classe que usam **defaultvtable** para especificar uma interface padrão:

```cpp
// cpp_attr_ref_defaultvtable.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMyI1 {
   HRESULT x();
};

[object, uuid("00000000-0000-0000-0000-000000000002")]
__interface IMyI2 {
   HRESULT x();
};

[object, uuid("00000000-0000-0000-0000-000000000003")]
__interface IMyI3 {
   HRESULT x();
};

[coclass, source(IMyI3, IMyI1), default(IMyI3, IMyI2), defaultvtable(IMyI1),
uuid("00000000-0000-0000-0000-000000000004")]
class CMyC3 : public IMyI3 {};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  