---
title: dispinterface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.dispinterface
dev_langs:
- C++
helpviewer_keywords:
- dispinterface attribute
ms.assetid: 61c5a4a1-ae92-47e9-8ee4-f847be90172b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 10f398e83650dc63c002801ac999816e48f7bdd4
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="dispinterface"></a>dispinterface
Coloca uma interface no arquivo. idl como uma interface de expedição.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[dispinterface]  
  
```  
  
## <a name="remarks"></a>Comentários  
 Quando o **dispinterface** atributo C++ precede uma interface, ele faz com que a interface a ser colocado dentro do bloco de biblioteca no arquivo. idl gerado.  
  
 A menos que você especifique uma classe base, uma interface de Despache será derivado `IDispatch`. Você deve especificar um [id](../windows/id.md) para os membros de uma interface de expedição.  
  
 O exemplo de uso de [dispinterface](http://msdn.microsoft.com/library/windows/desktop/aa366802) na documentação do MIDL:  
  
```  
dispinterface helloPro   
   { interface hello; };   
```  
  
 não é válido para o **dispinterface** atributo.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [associável](../windows/bindable.md) para obter um exemplo de como usar **dispinterface**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`interface`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|**duplo**, **objeto**, **oleautomation**, `local`, **ms_union**|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos por uso](../windows/attributes-by-usage.md)   
 [UUID](../windows/uuid-cpp-attributes.md)   
 [Duplo](../windows/dual.md)   
 [Personalizado](../windows/custom-cpp.md)   
 [object](../windows/object-cpp.md)   
 [__interface](../cpp/interface.md)   
