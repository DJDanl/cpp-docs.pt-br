---
title: includelib (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.includelib
dev_langs:
- C++
helpviewer_keywords:
- includelib attribute
ms.assetid: cd90ea6e-5ae8-4f11-b8d1-662db95412b2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 252a5d953dd05edc494daf8c4a45322d5511f979
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878886"
---
# <a name="includelib-c"></a>includelib (C++)
Faz com que um arquivo. IDL ou. h ser incluída no arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ includelib(  
   name.idl  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Name.idl*  
 O nome do arquivo. IDL que você deseja incluído como parte do arquivo. idl gerado.  
  
## <a name="remarks"></a>Comentários  
 O `includelib` C++ atributo faz com que um arquivo. IDL ou. h ser incluído no arquivo. idl gerado, após o `importlib` instrução.  
  
## <a name="example"></a>Exemplo  
 O código a seguir é mostrado em um arquivo. cpp:  
  
```  
// cpp_attr_ref_includelib.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[includelib("includelib.idl")];  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Sim|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [Importação](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [Incluir](../windows/include-cpp.md)   
 [importlib](../windows/importlib.md)   
