---
title: size_is | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.size_is
dev_langs:
- C++
helpviewer_keywords:
- size_is attribute
ms.assetid: 70192d09-f6c5-4d52-b3fe-303f8cb10aa5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c6b5309d62db094bf706fe7d3d1bcec99c3ec9a9
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645445"
---
# <a name="sizeis"></a>size_is
Especifique o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ size_is(  
   "expression"  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Expressão*  
 O tamanho da memória alocada para ponteiros de tamanho.  
  
## <a name="remarks"></a>Comentários  
 O **size_is** atributo C++ tem a mesma funcionalidade que o [size_is](http://msdn.microsoft.com/library/windows/desktop/aa367164) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [first_is](../windows/first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Campo do **struct** ou **união**, a interface do parâmetro, o método de interface|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|`max_is`|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
 [first_is](../windows/first-is.md)   
 [last_is](../windows/last-is.md)   
 [max_is](../windows/max-is.md)   
 [length_is](../windows/length-is.md)   