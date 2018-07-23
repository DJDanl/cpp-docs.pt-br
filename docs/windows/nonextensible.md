---
title: nonextensible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.nonextensible
dev_langs:
- C++
helpviewer_keywords:
- nonextensible attribute
ms.assetid: c7ef1554-809f-4ea0-a7cd-dc7786d40c3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 87cdbf66676ed2a3e6054006270b39ad80325857
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33881595"
---
# <a name="nonextensible"></a>nonextensible
Especifica que o `IDispatch` implementação inclui apenas as propriedades e métodos listados na descrição de interface e não podem ser estendidos com membros adicionais em tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[nonextensible]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **nonextensible** atributo C++ tem a mesma funcionalidade que o [nonextensible](http://msdn.microsoft.com/library/windows/desktop/aa367120) atributo MIDL.  
  
 O uso de **nonextensible** também requer o [oleautomation](../windows/oleautomation.md) atributo.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um uso de **nonextensible** atributo:  
  
```  
// cpp_attr_ref_nonextensible.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="ATLFIRELib")];  
[export] typedef long HRESULT;  
  
[dual, nonextensible, ms_union, oleautomation,   
uuid("00000000-0000-0000-0000-000000000001")]  
__interface IFireTabCtrl  
{  
   HRESULT procedure (int i);   
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`interface`|  
|**Repetível**|Não|  
|**Atributos necessários.**|**duplo** e **oleautomation**, ou **dispinterface**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
