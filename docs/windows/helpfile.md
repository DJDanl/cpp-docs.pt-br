---
title: arquivo de ajuda | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpfile
dev_langs:
- C++
helpviewer_keywords:
- helpfile attribute
ms.assetid: d75161c1-1363-4019-ae09-e7e3b8a3971e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f4f25a8f3d5cc76d1b2b8d9a3d9996449f449466
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570441"
---
# <a name="helpfile"></a>helpfile
Define o nome do arquivo de ajuda para uma biblioteca de tipos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ helpfile(  
   "filename"  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *filename*  
 O nome do arquivo que contém os tópicos da Ajuda.  
  
## <a name="remarks"></a>Comentários  
 O **helpfile** atributo C++ tem a mesma funcionalidade que o [helpfile](http://msdn.microsoft.com/library/windows/desktop/aa366853) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [módulo](../windows/module-cpp.md) para obter um exemplo de como usar **helpfile**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, **propriedade**|  
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
 [HelpContext](../windows/helpcontext.md)   
 [helpstring](../windows/helpstring.md)   