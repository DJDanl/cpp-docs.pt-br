---
title: pragma | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.pragma
dev_langs:
- C++
helpviewer_keywords:
- pragma attribute
ms.assetid: 3f90d023-b8b5-4007-8311-008bb72cbea1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6f24c01c225cf971592083162fbebddd99700814
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209108"
---
# <a name="pragma"></a>(pragma)

Emite a cadeia de caracteres especificada no arquivo. idl gerado sem o uso de aspas.

## <a name="syntax"></a>Sintaxe

```cpp
[ pragma(
   pragma_statement
) ];
```

### <a name="parameters"></a>Parâmetros

*pragma_statement*  
O pragma que você deseja ir para o arquivo. idl gerado.

## <a name="remarks"></a>Comentários

O **pragma** atributo C++ tem a mesma funcionalidade que o [pragma](/windows/desktop/Midl/pragma) atributo MIDL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_pragma.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="MyLib")];
[pragma(pack(4))];

[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]
__interface A
{
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos independentes](../windows/stand-alone-attributes.md)  
[pack](../preprocessor/pack.md)  