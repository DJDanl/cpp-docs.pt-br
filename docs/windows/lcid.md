---
title: LCID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.lcid
dev_langs:
- C++
helpviewer_keywords:
- LCID attribute
ms.assetid: 7f248c69-ee1c-42c3-9411-39cf27c9f43d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 919bf90fad228a3d7b4f574072e5f315da6427d8
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39602692"
---
# <a name="lcid"></a>lcid
Permite que você passar um identificador de localidade para uma função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[lcid]  
```  
  
## <a name="remarks"></a>Comentários  
 O **lcid** atributo C++ implementa a funcionalidade da [lcid](http://msdn.microsoft.com/library/windows/desktop/aa367067) atributo MIDL. Se você quiser implementar a localidade para um bloco de biblioteca, use o **lcid =** `lcid` parâmetro para o [módulo](../windows/module-cpp.md) atributo.  
  
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
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   