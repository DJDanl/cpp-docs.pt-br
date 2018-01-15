---
title: size_is | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.size_is
dev_langs: C++
helpviewer_keywords: size_is attribute
ms.assetid: 70192d09-f6c5-4d52-b3fe-303f8cb10aa5
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0dfddd72ed6db154868bd058f0e0e3ef9963a255
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sizeis"></a>size_is
Especifique o tamanho da memória alocada para ponteiros de tamanhos, tamanho ponteiros para ponteiros de tamanhos e único ou matrizes multidimensionais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ size_is(  
   "expression"  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *expressão*  
 O tamanho da memória alocada para ponteiros de tamanhos.  
  
## <a name="remarks"></a>Comentários  
 O **size_is** atributo C++ tem a mesma funcionalidade que o [size_is](http://msdn.microsoft.com/library/windows/desktop/aa367164) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [first_is](../windows/first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Campo em `struct` ou **união**, a interface de parâmetro, o método de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|**max_is**|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
 [first_is](../windows/first-is.md)   
 [last_is](../windows/last-is.md)   
 [max_is](../windows/max-is.md)   
 [length_is](../windows/length-is.md)   
