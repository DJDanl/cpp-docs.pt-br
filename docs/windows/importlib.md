---
title: importlib | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.importlib
dev_langs: C++
helpviewer_keywords: importlib attribute
ms.assetid: f129e459-b8d3-4aca-a0bc-ee53e18b62ed
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7c62db5b1e10f115a57da1ea00cd87760b96a71f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="importlib"></a>importlib
Torna os tipos que já foi compilados em outra biblioteca de tipo disponível para a biblioteca de tipos que está sendo criada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ importlib(  
   "tlb_file"  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *tlb_file*  
 O nome de um arquivo. tlb, entre aspas, ser importado para a biblioteca de tipos do projeto atual.  
  
## <a name="remarks"></a>Comentários  
 O **importlib** C++ atributo faz com que um `importlib` instrução será colocado no bloco de biblioteca do arquivo. idl gerado. O **importlib** atributo tem a mesma funcionalidade que o [importlib](http://msdn.microsoft.com/library/windows/desktop/aa367050) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um exemplo de como usar **importlib**:  
  
```  
// cpp_attr_ref_importlib.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[importlib("importlib.tlb")];  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [Importar](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [incluir](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)