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
ms.openlocfilehash: 806dcb96916b2e92bffc2d217e318a8853672ae8
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39605065"
---
# <a name="libraryblock"></a>library_block
Coloca uma construção de dentro do bloco de biblioteca IDL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[library_block]  
```  
  
## <a name="remarks"></a>Comentários  
 Quando você coloca um constructo de dentro do bloco de biblioteca, você certifique-se de que ele será passado para a biblioteca de tipos, independentemente se ele é referenciado. Por padrão, somente construções modificado pela [coclass](../windows/coclass.md), [dispinterface](../windows/dispinterface.md), e [idl_module](../windows/idl-module.md) atributos são colocados no bloco de biblioteca.  
  
## <a name="example"></a>Exemplo  
 No código a seguir, uma interface personalizada é colocada dentro do bloco de biblioteca.  
  
```cpp  
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
 [Atributos independentes](../windows/stand-alone-attributes.md)   