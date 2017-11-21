---
title: dispinterface | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.dispinterface
dev_langs: C++
helpviewer_keywords: dispinterface attribute
ms.assetid: 61c5a4a1-ae92-47e9-8ee4-f847be90172b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e52d050b9b05ccb72969c531297367e729c258b1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
 [duplo](../windows/dual.md)   
 [personalizado](../windows/custom-cpp.md)   
 [object](../windows/object-cpp.md)   
 [__interface](../cpp/interface.md)   
