---
title: em (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.in
dev_langs:
- C++
helpviewer_keywords:
- in attribute
ms.assetid: 7b450cc4-4d2e-4910-a195-7487c6b7c373
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6c09ae7e750a6372dd622f251a3b512e4ea67ef4
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606430"
---
# <a name="in-c"></a>in (C++)
Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[in]  
```  
  
## <a name="remarks"></a>Comentários  
 O **na** atributo C++ tem a mesma funcionalidade que o [em](http://msdn.microsoft.com/library/windows/desktop/aa367051) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Ver [associável](../windows/bindable.md) para obter um exemplo de como usar **em**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Parâmetro de interface, o método de interface|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|**retval**|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [DefaultValue](../windows/defaultvalue.md)   
 [ID](../windows/id.md)   
 [out](../windows/out-cpp.md)   