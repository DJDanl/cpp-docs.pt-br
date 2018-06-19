---
title: Public (atributos C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.public
dev_langs:
- C++
helpviewer_keywords:
- public attribute
ms.assetid: c42e1fd5-6cb1-48fe-8a03-95f2a2e0137c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1d798d828dd252ce8b5f3f49d5a9aaf525acc986
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33881725"
---
# <a name="public-c-attributes"></a>public (atributos C++)
Garante que um typedef para ir para a biblioteca de tipo mesmo que não é referenciado de dentro do arquivo. idl.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[public]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **pública** atributo C++ tem a mesma funcionalidade que o [pública](http://msdn.microsoft.com/library/windows/desktop/aa367150) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o **pública** atributo:  
  
```  
// cpp_attr_ref_public.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="ATLFIRELib")];  
[export, public] typedef long MEMBERID;  
  
[dispinterface, uuid(99999999-9999-9999-9999-000000000000)]  
__interface IFireTabCtrl : IDispatch  
{  
   [id(2)] long procedure ([in, optional] VARIANT i);  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`typedef`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)   
