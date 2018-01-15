---
title: ReadOnly (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.readonly
dev_langs: C++
helpviewer_keywords: readonly attribute
ms.assetid: 1246cadd-5304-43a9-beea-51153d12704d
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 829ca2126ec43be54d96a98b2ada4f5952626e21
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="readonly-c"></a>readonly (C++)
Impede a atribuição a um membro de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[readonly]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **readonly** atributo C++ tem a mesma funcionalidade que o [readonly](http://msdn.microsoft.com/library/windows/desktop/aa367152) atributo MIDL.  
  
 Se você deseja proibir a modificação de um parâmetro de método, use o [na](../windows/in-cpp.md) atributo.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um uso de **readonly** atributo:  
  
```  
// cpp_attr_ref_readonly.cpp  
// compile with: /LD  
[idl_quote("midl_pragma warning(disable:2461)")];  
#include "unknwn.h"  
[module(name="ATLFIRELib")];  
  
[dispinterface, uuid(11111111-1111-1111-1111-111111111111)]  
__interface IFireTabCtrl  
{  
   [readonly, id(1)] int i();  
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
 [Atributos de membro de dados](../windows/data-member-attributes.md)   
