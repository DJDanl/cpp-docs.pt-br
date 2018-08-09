---
title: oculto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.hidden
dev_langs:
- C++
helpviewer_keywords:
- hidden attribute
ms.assetid: 199c96dd-fc07-46c7-af93-92020aebebe7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7d20927b284de5c565c5fa9ebf00f8be00a4b486
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648844"
---
# <a name="hidden"></a>oculto
Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[hidden]  
```  
  
## <a name="remarks"></a>Comentários  
 O **ocultos** atributo C++ tem a mesma funcionalidade que o [oculto](http://msdn.microsoft.com/library/windows/desktop/aa366861) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [associável](../windows/bindable.md) para obter um exemplo de como usar **oculto**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**interface**, **classe**, **struct**, método, propriedade|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|**coclass** (quando aplicado a **classe** ou **struct**)|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   