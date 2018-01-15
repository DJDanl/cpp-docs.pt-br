---
title: local (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.local
dev_langs: C++
helpviewer_keywords: local attribute
ms.assetid: 35cdd668-bd8e-492a-b7b8-263e7b662437
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3543adfe0cb25f7946e6ed6c81c4bd66a7b60324
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="local-c"></a>local (C++)
Quando usado no cabeçalho da interface, permite que você use o compilador MIDL como um gerador de cabeçalho. Quando usada em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[local]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O `local` atributo C++ tem a mesma funcionalidade que o [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte [call_as](../windows/call-as.md) para obter um exemplo de como usar `local`.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`interface`, método de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|**dispinterface**|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [call_as](../windows/call-as.md)   
