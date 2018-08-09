---
title: support_error_info | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.support_error_info
dev_langs:
- C++
helpviewer_keywords:
- support_error_info attribute
ms.assetid: 20a2b55c-4738-4b35-a71d-e5e9c3a7e3bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5e07d218158ff5615fbdc26a5f48b7cf828596ed
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014163"
---
# <a name="supporterrorinfo"></a>support_error_info
Implementa o suporte para retornar erros detalhados.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ support_error_info(  
   error_interface=uuid  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *error_interface*  
 O identificador da implementação de interface `IErrorInfo`.  
  
## <a name="remarks"></a>Comentários  
 O **support_error_info** atributo C++ implementa o suporte para retorno de erros detalhados, contextuais encontrados pelo objeto de destino para o cliente. Para o objeto dar suporte a erros, os métodos do `IErrorInfo` interface deve ser implementada pelo objeto. Para obter mais informações, consulte [que dão suporte a IDispatch e IErrorInfo](../atl/supporting-idispatch-and-ierrorinfo.md).  
  
 Esse atributo adiciona o [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) classe como uma classe base para o objeto de destino. Isso resulta em uma implementação padrão de `ISupportErrorInfo` e pode ser usado quando uma única interface gera erros em um objeto.  
  
## <a name="example"></a>Exemplo  
 O código a seguir adiciona o suporte padrão para o `ISupportErrorInfo` da interface para o `CMyClass` objeto.  
  
```cpp  
// cpp_attr_ref_support_error_info.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module (name="mymod")];  
[object, uuid("f0b17d66-dc6e-4662-baaf-76758e09c878")]  
__interface IMyErrors  
{  
};  
  
[ coclass, support_error_info("IMyErrors"),  
  uuid("854dd392-bdc7-4781-8667-8757936f2a4f") ]  
class CMyClass  
{  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**class**|  
|**Repetível**|Sim|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos COM](../windows/com-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   