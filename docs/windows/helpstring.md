---
title: HelpString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpstring
dev_langs:
- C++
helpviewer_keywords:
- helpstring attribute [C++]
ms.assetid: 0401e905-a63e-4fad-98d0-d1efea111966
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 81a3e45c5636fd193b7880e093711b5cc584bf99
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879000"
---
# <a name="helpstring"></a>helpstring
Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual se aplica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ helpstring(  
   "string"  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string`  
 O texto da cadeia de caracteres de Ajuda.  
  
## <a name="remarks"></a>Comentários  
 O **helpstring** atributo C++ tem a mesma funcionalidade que o [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [defaultvalue](../windows/defaultvalue.md) para obter um exemplo de como usar **helpstring**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`interface`, `typedef`, **classe**, método, propriedade|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Arquivo de ajuda](../windows/helpfile.md)   
 [helpcontext](../windows/helpcontext.md)   
