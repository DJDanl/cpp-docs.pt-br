---
title: objeto (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.object
dev_langs:
- C++
helpviewer_keywords:
- object attribute
ms.assetid: f2d3c231-630d-4b4c-bd15-b1c30df362dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2c0705c5d841b63cd3f537ab39dbbe9122fea869
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39607904"
---
# <a name="object-c"></a>object (C++)
Identifica uma interface personalizada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[object]  
```  
  
## <a name="remarks"></a>Comentários  
 Quando precede uma definição de interface, o **objeto** C++ atributo faz com que a interface a ser colocado no arquivo. idl como uma interface personalizada.  
  
 Qualquer interface marcada com o objeto deve herdar de `IUnknown`. Essa condição é atendida se qualquer uma das interfaces base pode herdar de `IUnknown`. Se não há interfaces base herdam `IUnknown`, o compilador fará com que a interface marcada com **objeto** derivar `IUnknown`.  
  
## <a name="example"></a>Exemplo  
 Ver [nonbrowsable](../windows/nonbrowsable.md) para obter um exemplo de como usar **objeto**.  
  
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
 [Duplo](../windows/dual.md)   
 [Dispinterface](../windows/dispinterface.md)   
 [Personalizado](../windows/custom-cpp.md)   
 [__interface](../cpp/interface.md)   