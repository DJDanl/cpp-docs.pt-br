---
title: Threading (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.threading
dev_langs: C++
helpviewer_keywords: threading attribute
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e44fec96391fff6700ecf4a453d7455bd75e9df7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="threading-c"></a>threading (C++)
Especifica o modelo de threading para um objeto COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ threading(  
   model=enumeration  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 ***modelo*** (opcional)  
 Um dos seguintes modelos de threads:  
  
-   **apartment** (apartment threading)  
  
-   **neutro** (componentes do .NET Framework com nenhuma interface do usuário)  
  
-   **único** (threading simples)  
  
-   **livre** (libere threading)  
  
-   **ambos** (apartment Threading e free threading)  
  
 O valor padrão é **apartment**.  
  
## <a name="remarks"></a>Comentários  
 O **threading** atributo C++ não aparecem no arquivo. idl gerado, mas será usado na implementação do objeto COM.  
  
 Em projetos ATL, se o [coclass](../windows/coclass.md) atributo também estiver presente, o modelo de threading especificado por *modelo* é passado como o parâmetro de modelo para o [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) classe , inseridas pelo **coclass** atributo.  
  
 O **threading** atributo também protege o acesso a um [event_source](../windows/event-source.md).  
  
## <a name="example"></a>Exemplo  
 Consulte o [licenciado](../windows/licensed.md) exemplo para uso do exemplo **threading**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|**coclass**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos COM](../windows/com-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Suporte multithread para código anterior (Visual C++)](../parallel/multithreading-support-for-older-code-visual-cpp.md)   
 [Neutros Apartments](http://msdn.microsoft.com/library/windows/desktop/ms681813)   
