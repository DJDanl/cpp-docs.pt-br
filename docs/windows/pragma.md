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
ms.openlocfilehash: cab41277a7e5560fd842bf720fd776961d918d99
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878142"
---
# <a name="pragma"></a>(pragma)
Emite a cadeia de caracteres especificada no arquivo. idl gerado sem o uso de aspas. .  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ pragma(  
   pragma_statement  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pragma_statement*  
 O pragma de que você deseja ir para o arquivo. idl gerado.  
  
## <a name="remarks"></a>Comentários  
 O **pragma** atributo C++ tem a mesma funcionalidade que o [pragma](http://msdn.microsoft.com/library/windows/desktop/aa367143) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [pack](../preprocessor/pack.md)   
