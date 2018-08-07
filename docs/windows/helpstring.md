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
ms.openlocfilehash: e661e911cc0dd583f2ce079f8ac047a354fa596f
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570925"
---
# <a name="helpstring"></a>helpstring
Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ helpstring(  
   "string"  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *string*  
 O texto da cadeia de caracteres de Ajuda.  
  
## <a name="remarks"></a>Comentários  
 O **helpstring** atributo C++ tem a mesma funcionalidade que o [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [defaultvalue](../windows/defaultvalue.md) para obter um exemplo de como usar **helpstring**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, propriedade|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
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