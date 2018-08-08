---
title: pointer_default | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.pointer_default
dev_langs:
- C++
helpviewer_keywords:
- pointer_default attribute
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 562bc3ebd0c80423eb94d2bc328f72aed8e67985
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604379"
---
# <a name="pointerdefault"></a>pointer_default
Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ pointer_default(  
   value  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *value*  
 Um valor que descreve o tipo de ponteiro: **ptr**, **ref**, ou **exclusivo**.  
  
## <a name="remarks"></a>Comentários  
 O **pointer_default** atributo C++ tem a mesma funcionalidade que o [pointer_default](http://msdn.microsoft.com/library/windows/desktop/aa367141) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [defaultvalue](../windows/defaultvalue.md) para uso do exemplo **pointer_default**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**interface**|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   