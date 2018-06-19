---
title: Threading (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.threading
dev_langs:
- C++
helpviewer_keywords:
- threading attribute
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f21ea8c16b4e09a5ad1845a10797be00f91b0d8f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891318"
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
|**Aplica-se a**|**class**, `struct`|  
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
