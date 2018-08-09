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
ms.openlocfilehash: 3d6f6a4dc4f23460b3661da4ed3775708cac9b6d
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40016171"
---
# <a name="includelib-c"></a>includelib (C++)
Faz com que um arquivo. IDL ou. h a serem incluídos no arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ includelib(  
   name.idl  
) ];  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Name.idl*  
 O nome do arquivo. IDL que você deseja que seja incluído como parte do arquivo. idl gerado.  
  
## <a name="remarks"></a>Comentários  
 O **includelib** C++ atributo faz com que um arquivo. IDL ou. h ser incluído no arquivo. idl gerado, após o `importlib` instrução.  
  
## <a name="example"></a>Exemplo  
 O código a seguir é mostrado em um arquivo. cpp:  
  
```cpp  
// cpp_attr_ref_includelib.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[includelib("includelib.idl")];  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Sim|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [Importar](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [Incluir](../windows/include-cpp.md)   
 [importlib](../windows/importlib.md)   