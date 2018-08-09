---
title: importlib | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.importlib
dev_langs:
- C++
helpviewer_keywords:
- importlib attribute
ms.assetid: f129e459-b8d3-4aca-a0bc-ee53e18b62ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c9676c6c28e9f142f0ec376fae31c3d26f1a2083
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011660"
---
# <a name="importlib"></a>importlib
Torna os tipos que já foram compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ importlib(  
   "tlb_file"  
) ];  
```  
  
### <a name="parameters"></a>Parâmetros  
 *tlb_file*  
 O nome de um arquivo. tlb, entre aspas, o que você deseja importado para a biblioteca de tipos do projeto atual.  
  
## <a name="remarks"></a>Comentários  
 O **importlib** C++ atributo faz com que um `importlib` instrução a ser colocado no bloco de biblioteca do arquivo. idl gerado. O **importlib** atributo tem a mesma funcionalidade que o [importlib](http://msdn.microsoft.com/library/windows/desktop/aa367050) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um exemplo de como usar **importlib**:  
  
```cpp  
// cpp_attr_ref_importlib.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[importlib("importlib.tlb")];  
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
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [Importar](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [Incluir](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)