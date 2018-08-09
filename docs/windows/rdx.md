---
title: RDX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.rdx
dev_langs:
- C++
helpviewer_keywords:
- rdx attribute
ms.assetid: ff8e4312-c1ad-4934-bdaa-86f54409651e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 32dd702dd7d429c4437875a6aead86ae687dfb2b
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011043"
---
# <a name="rdx"></a>rdx
Cria uma chave do registro ou modifica uma chave do registro existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ rdx(   
   key,   
   valuename=NULL,   
   regtype   
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *key*  
 O nome da chave a ser criado ou aberto.  
  
 *ValueName* (opcional)  
 Especifica o campo de valor a ser definido. Se um campo de valor com esse nome ainda não existir na chave, ele será adicionado.  
  
 *regtype*  
 O tipo de chave do registro que está sendo adicionado. Pode ser uma das seguintes opções: `text`, `dword`, `binary`, ou `CString`.  
  
## <a name="remarks"></a>Comentários  
 O **rdx** atributo C++ cria ou modifica uma chave do registro existente para um componente COM. O atributo adiciona uma macro BEGIN_RDX_MAP para o objeto que implementa o membro de destino. `RegistryDataExchange`, uma função injetada como resultado da macro BEGIN_RDX_MAP, pode ser usada para transferir dados entre o registro e os membros de dados  
  
 Esse atributo pode ser usado em conjunto com o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributos ou outros atributos que implica uma destas opções.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**classe** ou **struct** membro|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="example"></a>Exemplo  
 O código a seguir adiciona uma chave do Registro chamada MyValue para o sistema que descreve o componente COM CMyClass.  
  
```cpp  
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