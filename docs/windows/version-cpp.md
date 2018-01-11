---
title: "versão (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.version
dev_langs: C++
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: db6c31df932890799f68e2ae466b0a927f0f999f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="version-c"></a>version (C++)
Identifica uma versão específica entre várias versões de uma classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ version(  
   "version"  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *version*  
 O número de versão da coclass. Se não for especificado, 1.0 será colocado no arquivo. idl.  
  
## <a name="remarks"></a>Comentários  
 O **versão** atributo C++ tem a mesma funcionalidade que o [versão](http://msdn.microsoft.com/library/windows/desktop/aa367306) atributo MIDL e é passado para o arquivo. idl gerado.  
  
## <a name="example"></a>Exemplo  
 Consulte o [associável](../windows/bindable.md) exemplo para uso do exemplo **versão**.  
  
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
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
