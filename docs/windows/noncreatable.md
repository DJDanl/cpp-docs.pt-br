---
title: não passível de criação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.noncreatable
dev_langs:
- C++
helpviewer_keywords:
- noncreatable attribute
ms.assetid: 4d17937b-0bff-41af-ba57-53e18b7ab5a9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b31ede898e2b1976bc16be7cf89c0223c3709193
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221537"
---
# <a name="noncreatable"></a>noncreatable

Define um objeto que não pode ser instanciado por si só.

## <a name="syntax"></a>Sintaxe

```cpp
[noncreatable]
```

## <a name="remarks"></a>Comentários

O **noncreatable** atributo C++ tem a mesma funcionalidade que o [noncreatable](/windows/desktop/Midl/noncreatable) atributo MIDL e é passado para o gerado automaticamente. Arquivo IDL pelo compilador.

Quando esse atributo é usado dentro de um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento acima, o atributo também injeta a [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro. Essa macro indica ao ATL que o objeto não pode ser criado externamente.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_noncreatable.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[object, uuid("11111111-1111-1111-1111-111111111111")]
__interface A
{
};

[coclass, uuid("11111111-1111-1111-1111-111111111112"), noncreatable]
class CMyClass : public A
{
   HRESULT xx();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
