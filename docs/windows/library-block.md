---
title: library_block | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.library_block
dev_langs:
- C++
helpviewer_keywords:
- library_block attribute
ms.assetid: ae7a7ebe-5e1a-4eda-a058-11bbd058ece8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dbd97897138edffba12baf47d64465b1f6ca0df4
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877885"
---
# <a name="libraryblock"></a>library_block
Coloca uma construção dentro do bloco da biblioteca IDL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[library_block]  
  
```  
  
## <a name="remarks"></a>Comentários  
 Quando você coloca uma construção dentro do bloco de biblioteca, você garantir que ele será passado para a biblioteca de tipos, independentemente se ele é referenciado. Por padrão, somente as construções modificado pelo [coclass](../windows/coclass.md), [dispinterface](../windows/dispinterface.md), e [idl_module](../windows/idl-module.md) atributos são colocados no bloco de biblioteca.  
  
## <a name="example"></a>Exemplo  
 O código a seguir, uma interface personalizada é colocada dentro do bloco de biblioteca.  
  
```  
// cpp_attr_ref_library_block.cpp  
// compile with: /LD  
#include <windows.h>  
[module(name="MyLib")];  
[object, library_block, uuid("9E66A290-4365-11D2-A997-00C04FA37DDB")]  
__interface IMyInterface {  
   HRESULT f1();  
};  
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
 [Atributos independentes](../windows/stand-alone-attributes.md)   
