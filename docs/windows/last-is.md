---
title: last_is | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.last_is
dev_langs:
- C++
helpviewer_keywords:
- last_is attribute
ms.assetid: 9e045ac0-fa38-4249-af55-67bde5d0a58c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f27c0a12ddf5fe87f7065a16d042bd0afcfc0315
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877515"
---
# <a name="lastis"></a>last_is
Especifica o índice do último elemento de matriz a ser transmitido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ last_is(  
   "expression"  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Expressão*  
 Uma ou mais expressões de linguagem C. Slots de argumentos vazia são permitidos.  
  
## <a name="remarks"></a>Comentários  
 O **last_is** atributo C++ tem a mesma funcionalidade que o [last_is](http://msdn.microsoft.com/library/windows/desktop/aa367066) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte [first_is](../windows/first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Campo em `struct` ou **união**, a interface de parâmetro, o método de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
 [first_is](../windows/first-is.md)   
 [max_is](../windows/max-is.md)   
 [length_is](../windows/length-is.md)   
 [size_is](../windows/size-is.md)   
