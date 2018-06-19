---
title: restrito | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.restricted
dev_langs:
- C++
helpviewer_keywords:
- restricted attribute
ms.assetid: 504a96be-b904-4269-8be1-920feba201b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e1d688d4ebca5d2cc01901f5fe1afaa4536b71bb
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892872"
---
# <a name="restricted"></a>restricted
Especifica que um membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ restricted(  
   interfaces  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `interfaces`  
 Uma ou mais interfaces que não podem ser chamados arbitrariamente em um objeto COM. Esse parâmetro só é válido quando aplicado a uma classe.  
  
## <a name="remarks"></a>Comentários  
 O **restrito** atributo C++ tem a mesma funcionalidade que o [restrito](http://msdn.microsoft.com/library/windows/desktop/aa367157) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o **restrito** atributo:  
  
```  
// cpp_attr_ref_restricted.cpp  
// compile with: /LD  
#include "windows.h"  
#include "unknwn.h"  
[module(name="MyLib")];  
  
[object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface a  
{  
};  
  
[object, uuid("00000000-0000-0000-0000-000000000002")]  
__interface b  
{  
};  
  
[coclass, restricted(a,b), uuid("00000000-0000-0000-0000-000000000003")]  
class c : public a, public b  
{  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Método de interface `interface`, **classe**, `struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|**coclass** (quando aplicado a **classe** ou `struct`)|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
