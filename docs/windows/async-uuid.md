---
title: async_uuid | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.async_uuid
dev_langs:
- C++
helpviewer_keywords:
- async_uuid attribute
ms.assetid: 235cb0d7-be58-4dd9-983c-e2a21bbc42c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0596b15daff5567e2572bf8c1f2b401cdf300a49
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642406"
---
# <a name="asyncuuid"></a>async_uuid
Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[async_uuid (  
   uuid  
)]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *uuid*  
 Um UUID que identifica a versão da interface.  
  
## <a name="remarks"></a>Comentários  
 O **async_uuid** atributo C++ tem a mesma funcionalidade que o [async_uuid](http://msdn.microsoft.com/library/windows/desktop/aa366735) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// cpp_attr_ref_async_uuid.cpp  
// compile with: /LD  
#include <Windows.h>  
[module(name="Test")];  
[object, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb"),   
async_uuid("e8583106-38fd-487e-912e-4fc8645c677e")]  
__interface ICustom {  
   HRESULT Custom([in] long l, [out, retval] long *pLong);  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|`interface`|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|**dupla**, **dispinterface**|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   