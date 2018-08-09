---
title: incluir (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.include
dev_langs:
- C++
helpviewer_keywords:
- include attribute
ms.assetid: d23f8b91-fe5b-48fa-9371-8bd73af7b8e3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c21bb7cf58c3c397237768942d60f79958f3278a
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013555"
---
# <a name="include-c"></a>include (C++)
Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ include(  
   header_file  
) ];  
```  
  
### <a name="parameters"></a>Parâmetros  
 *header_file*  
 O nome de um arquivo que você deseja que sejam incluído no arquivo. idl gerado.  
  
## <a name="remarks"></a>Comentários  
 O **incluem** C++ atributo faz com que um `#include` instrução a ser colocado abaixo do `import "docobj.idl"` instrução no arquivo. idl gerado.  
  
 O **incluem** atributo C++ tem a mesma funcionalidade que o [incluem](http://msdn.microsoft.com/library/windows/desktop/aa367052) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um exemplo de como usar **incluem**. Neste exemplo, o arquivo include.h contém apenas um `#include` instrução.  
  
```cpp  
// cpp_attr_ref_include.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[include(cpp_attr_ref_include.h)];  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [Importar](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [includelib](../windows/includelib-cpp.md)   
 [importlib](../windows/importlib.md)   