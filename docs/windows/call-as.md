---
title: call_as | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.call_as
dev_langs: C++
helpviewer_keywords: call_as attribute
ms.assetid: a09d7f1f-353b-4870-9b45-f0284161695d
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3df1cd801a82533592594618742b7727051bde53
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="callas"></a>call_as
Permite que um [local](../windows/local-cpp.md) função a ser mapeada para uma função remota para que quando a função remota é chamada, a função local é invocada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ call_as(  
   function  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *function*  
 A função local que você deseja ser chamado quando uma função remota é invocada.  
  
## <a name="remarks"></a>Comentários  
 O **call_as** atributo C++ tem a mesma funcionalidade que o [call_as](http://msdn.microsoft.com/library/windows/desktop/aa366748) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como você pode usar **call_as** para mapear uma função nonremotable (**f1**) para uma função remota (**Remf1**):  
  
```  
// cpp_attr_ref_call_as.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="MyLib")];  
[dual, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IMInterface {  
   [local] HRESULT f1 ( int i );  
   [call_as(f1)] HRESULT Remf1 ( int i );   
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Método de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [local](../windows/local-cpp.md)   
