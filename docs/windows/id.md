---
title: ID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.id
dev_langs:
- C++
helpviewer_keywords:
- id attribute
ms.assetid: a48d2c99-c5d2-4f46-bf96-5ac88dcb5d0c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5a89758933aef4646aaf11d08d7193d48a44f468
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013539"
---
# <a name="id"></a>id
Especifica um *dispid* parâmetro para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ id(  
   dispid  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *DISPID*  
 A ID de expedição para o método de interface.  
  
## <a name="remarks"></a>Comentários  
 O **identificação** atributo C++ tem a mesma funcionalidade que o [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [associável](../windows/bindable.md) para obter um exemplo de como usar **id**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Método de interface|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [Atributos de membro de dados](../windows/data-member-attributes.md)   
 [DefaultValue](../windows/defaultvalue.md)   
 [in](../windows/in-cpp.md)   
 [out](../windows/out-cpp.md)   