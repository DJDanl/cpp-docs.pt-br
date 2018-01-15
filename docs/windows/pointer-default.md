---
title: pointer_default | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.pointer_default
dev_langs: C++
helpviewer_keywords: pointer_default attribute
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b55bf95c7abdffe8dd0a0e0071d86f06baad344e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pointerdefault"></a>pointer_default
Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto os ponteiros de nível superior que aparecem em listas de parâmetros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ pointer_default(  
   value  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *value*  
 Um valor que descreve o tipo de ponteiro: **ptr**, `ref`, ou **exclusivo**.  
  
## <a name="remarks"></a>Comentários  
 O **pointer_default** atributo C++ tem a mesma funcionalidade que o [pointer_default](http://msdn.microsoft.com/library/windows/desktop/aa367141) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [defaultvalue](../windows/defaultvalue.md) para uso do exemplo **pointer_default**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`interface`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
