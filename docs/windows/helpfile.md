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
ms.openlocfilehash: 926d0fec27bf323f559ad2fe0dffbd4208b1bf2a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876183"
---
# <a name="helpfile"></a>helpfile
Define o nome do arquivo de ajuda para uma biblioteca de tipos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ helpfile(  
   "filename"  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *filename*  
 O nome do arquivo que contém os tópicos da Ajuda.  
  
## <a name="remarks"></a>Comentários  
 O **helpfile** atributo C++ tem a mesma funcionalidade que o [helpfile](http://msdn.microsoft.com/library/windows/desktop/aa366853) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [módulo](../windows/module-cpp.md) para obter um exemplo de como usar **helpfile**.  
  
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
 [HelpContext](../windows/helpcontext.md)   
 [helpstring](../windows/helpstring.md)   
