---
title: entrada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.entry
dev_langs: C++
helpviewer_keywords: entry attribute
ms.assetid: ba4843e3-d7ad-4b86-9a15-0b4192f0f698
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9ffd90ccdcce39ab73f1c1b550b466541dacf8a1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="entry"></a>entry
Especifica uma função exportada ou uma constante em um módulo, identificando o ponto de entrada na DLL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ entry(  
   id  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `id`  
 A ID do ponto de entrada.  
  
## <a name="remarks"></a>Comentários  
 O **entrada** atributo C++ tem a mesma funcionalidade que o [entrada](http://msdn.microsoft.com/library/windows/desktop/aa366815) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [idl_module](../windows/idl-module.md) para um exemplo de uso de **entrada**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Atributo `idl_module`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de IDL](../windows/idl-attributes.md)   
