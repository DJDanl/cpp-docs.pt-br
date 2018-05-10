---
title: personalizado (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.custom
dev_langs:
- C++
helpviewer_keywords:
- custom attributes, defining
ms.assetid: 3abac928-4d55-4ea6-8cf6-8427a4ad79f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7b37d87d5380b9d4dac69cee702654285461ead6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="custom-c"></a>custom (C++)
Define os metadados de um objeto na biblioteca de tipos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ custom(  
   uuid,   
   value  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *uuid*  
 Uma ID exclusiva.  
  
 *value*  
 Um valor que pode ser colocado em uma variante.  
  
## <a name="remarks"></a>Comentários  
 O **personalizado** atributo C++ fará com que informações sejam colocados em biblioteca de tipos. Você precisará de uma ferramenta que lê o valor personalizado da biblioteca de tipos.  
  
 O **personalizado** atributo tem a mesma funcionalidade que o [personalizado](http://msdn.microsoft.com/library/windows/desktop/aa366766) atributo MIDL.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Não-COM `interface`, **classe**, `enum`s, `idl_module` métodos, membros de interface, parâmetros de interface, `typedef`s, **união**s, `struct`s|  
|**Repetível**|Sim|  
|**Atributos necessários.**|**coclass** (quando usado em classe)|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
