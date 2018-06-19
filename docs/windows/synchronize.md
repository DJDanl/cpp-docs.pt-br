---
title: sincronizar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.synchronize
dev_langs:
- C++
helpviewer_keywords:
- synchronize attribute
ms.assetid: 15fc8544-955d-4765-b3d5-0f619c8b3f40
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 304ceece506465df0a51c56b247407d351fd23b3
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889791"
---
# <a name="synchronize"></a>synchronize
Sincroniza o acesso para o método de destino.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[synchronize]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **sincronizar** atributo C++ implementa o suporte para o método de destino de um objeto de sincronização. Sincronização permite que vários objetos usar um recurso comum (como um método de uma classe), controlando o acesso do método de destino.  
  
 O código inserido por este atributo chama a operação `Lock` método (determinado pelo modelo de threading) no início do método de destino. Quando o método for fechado, `Unlock` é chamado automaticamente. Para obter mais informações sobre essas funções, consulte [CComAutoThreadModule::Lock](../atl/reference/ccomautothreadmodule-class.md#lock)  
  
 Este atributo requer que o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicados ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se **progid** é aplicado, **vi_progid** e **coclass** também são aplicadas.  
  
## <a name="example"></a>Exemplo  
 O código a seguir fornece sincronização para o `UpdateBalance` método o `CMyClass` objeto.  
  
```  
// cpp_attr_ref_synchronize.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module(name="SYNC")];  
  
[coclass,  
 threading(both),  
 vi_progid("MyProject.MyClass"),  
 progid("MyProject.MyClass.1"),  
 uuid("7a7baa0d-59b8-4576-b754-79d07e1d1cc3")  
]  
class CMyClass {  
   float m_nBalance;  
  
   [synchronize]  
   void UpdateBalance(float nAdjust) {  
      m_nBalance += nAdjust;  
   }  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Método de classe, método|  
|**Repetível**|Não|  
|**Atributos necessários.**|Um ou mais dos seguintes: **coclass**, **progid**, ou **vi_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de COM](../windows/com-attributes.md)   
