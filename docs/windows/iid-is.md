---
title: iid_is | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.iid_is
dev_langs:
- C++
helpviewer_keywords:
- iid_is attribute
ms.assetid: 2f9b42a9-7130-4b08-9b1e-0d5d360e10ff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 597d4c2e6fa9904906c2971c3c442a9f26779834
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215072"
---
# <a name="iidis"></a>iid_is

Especifica o IID da interface COM apontado por um ponteiro de interface.

## <a name="syntax"></a>Sintaxe

```cpp
[ iid_is(
   "expression"
) ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*  
Uma expressão de linguagem C que especifica uma IID de uma interface COM apontado por um ponteiro de interface.

## <a name="remarks"></a>Comentários

O **iid_is** atributo C++ tem a mesma funcionalidade que o [iid_is](/windows/desktop/Midl/iid-is) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra o uso de **iid_is**:

```cpp
// cpp_attr_ref_iid_is.cpp
// compile with: /LD
#include "wtypes.h"
#include "unknwn.h"
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]
__interface IFireTabCtrl : IDispatch
{
   [id(1)] HRESULT CreateInstance([in] REFIID riid,[out, iid_is("riid")]
   IUnknown ** ppvObject);
};

[module(name="ATLFIRELib")];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, membro de dados|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de parâmetro](../windows/parameter-attributes.md)  