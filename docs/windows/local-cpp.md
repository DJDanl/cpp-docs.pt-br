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
ms.openlocfilehash: 007d95d5db0785deae08744b46738d7188e4da70
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
