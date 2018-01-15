---
title: nonbrowsable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.nonbrowsable
dev_langs: C++
helpviewer_keywords: nonbrowsable attribute
ms.assetid: e71a98e7-4b65-454a-9829-342b9f2a84be
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 279d6e80fe100fbbd41e54c4a13640e3046cf73c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nonbrowsable"></a>nonbrowsable
Indica que um membro de interface não deve ser exibido em um navegador de propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[nonbrowsable]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **nonbrowsable** atributo C++ tem a mesma funcionalidade que o [nonbrowsable](http://msdn.microsoft.com/library/windows/desktop/aa367117) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_nonbrowsable.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLib")];  
  
[object, helpstring("help string"), helpstringcontext(1),   
uuid="11111111-1111-1111-1111-111111111111"]   
__interface IMyI  
{  
   [nonbrowsable] HRESULT xx();  
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
