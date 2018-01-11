---
title: RDX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.rdx
dev_langs: C++
helpviewer_keywords: rdx attribute
ms.assetid: ff8e4312-c1ad-4934-bdaa-86f54409651e
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d656af60ec14309227fc73d81bd0f14638637d48
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rdx"></a>rdx
Cria uma chave do registro ou modifica uma chave do registro existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ rdx(   
   key,   
   valuename=NULL,   
   regtype   
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `key`  
 O nome da chave a ser criado ou aberto.  
  
 `valuename`(opcional)  
 Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.  
  
 *regtype*  
 O tipo de chave do registro que está sendo adicionado. Pode ser um dos seguintes: **texto**, **dword**, **binário**, ou `CString`.  
  
## <a name="remarks"></a>Comentários  
 O **rdx** atributo C++ cria ou modifica uma chave do registro existente para um componente COM. O atributo adiciona uma macro BEGIN_RDX_MAP para o objeto que implementa o membro de destino. `RegistryDataExchange`, uma função inserida como resultado de macro BEGIN_RDX_MAP, pode ser usada para transferir dados entre o registro e os membros de dados  
  
 Esse atributo pode ser usado em conjunto com o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributos ou outros atributos que implica uma destas opções.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe** ou `struct` membro|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="example"></a>Exemplo  
 O código a seguir adiciona uma chave do Registro chamada MyValue para o sistema que descreve o componente COM CMyClass.  
  
```  
// cpp_attr_ref_rdx.cpp  
// compile with: /LD /link /OPT:NOREF  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
  
[module (name="MyLib")];  
  
class CMyClass {  
public:  
   CMyClass() {  
      strcpy_s(m_sz, "SomeValue");  
   }  
  
   [ rdx(key = "HKCR\\MyApp.MyApp.1", valuename = "MyValue", regtype = "text")]   
   char m_sz[256];  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Atributos COM](../windows/com-attributes.md)   
 [registration_script](../windows/registration-script.md)   
