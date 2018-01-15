---
title: importidl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.importidl
dev_langs: C++
helpviewer_keywords: importidl attribute
ms.assetid: 4b0a4b55-6c57-4e6e-bc7b-a12cc8063941
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cd3fb56898107b1eca7cd30e06d75d253a02655e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="importidl"></a>importidl
Insere o arquivo. idl especificado no arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ importidl(  
   idl_file  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `idl_file`  
 Identifica o nome do arquivo. IDL que você deseja mesclar com o arquivo. IDL que será gerado para o seu aplicativo.  
  
## <a name="remarks"></a>Comentários  
 O **importidl** atributo C++ coloca a seção fora do bloco de biblioteca (em `idl_file`) no arquivo de IDL gerado do programa e a seção da biblioteca (em `idl_file`) na seção de biblioteca do seu programa arquivo. idl gerado.  
  
 Você talvez queira usar **importidl**, por exemplo, se você quiser usar um arquivo. idl codificado manualmente com o arquivo. idl gerado.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_importidl.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[importidl("import.idl")];  
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
 [importlib](../windows/importlib.md)   
 [incluir](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)   
