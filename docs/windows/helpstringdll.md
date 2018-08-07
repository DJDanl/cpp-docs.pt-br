---
title: helpstringdll | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpstringdll
dev_langs:
- C++
helpviewer_keywords:
- helpstringdll attribute [C++]
ms.assetid: 121271fa-f061-492b-b87f-bbfcf4b02e7b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 27303f294f2414e2ea3f15de0c5bbfb1723628aa
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570074"
---
# <a name="helpstringdll"></a>helpstringdll
Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ helpstringdll(  
   "string"  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *string*  
 A DLL de usar para executar a pesquisa de cadeia de caracteres do documento.  
  
## <a name="remarks"></a>Comentários  
 O **helpstringdll** atributo C++ tem a mesma funcionalidade que o [helpstringdll](http://msdn.microsoft.com/library/windows/desktop/aa366860) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// cpp_attr_ref_helpstringdll.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLib", helpstringdll="xx.dll")];  
  
[object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IMyI   
{  
   HRESULT xxx();  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, **interface**, método de interface|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   