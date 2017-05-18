---
title: Estrutura _ATL_FUNC_INFO | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _ATL_FUNC_INFO
- ATL::_ATL_FUNC_INFO
- ATL._ATL_FUNC_INFO
dev_langs:
- C++
helpviewer_keywords:
- _ATL_FUNC_INFO structure
- ATL_FUNC_INFO structure
ms.assetid: 441ebe2c-f971-47de-9f52-a258e8d6f88e
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 7bc607931c486f3dd7a398b277048db77e9b2f62
ms.contentlocale: pt-br
ms.lasthandoff: 03/31/2017

---
# <a name="atlfuncinfo-structure"></a>Estrutura _ATL_FUNC_INFO
Contém informações sobre o tipo usado para descrever um método ou propriedade em um dispinterface.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct _ATL_FUNC_INFO {
    CALLCONV cc;
    VARTYPE vtReturn;
    SHORT nParams;
    VARTYPE pVarTypes[_ATL_MAX_VARTYPES];
};
```  
  
## <a name="members"></a>Membros  
 **Cc**  
 A convenção de chamada. Ao usar essa estrutura com a [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe, esse membro deve ser **CC_STDCALL**. `CC_CDECL`é a única opção com suporte no Windows CE para o `CALLCONV` campo o `_ATL_FUNC_INFO` estrutura. Não há suporte para qualquer outro valor, portanto, seu comportamento indefinido.  
  
 **vtReturn**  
 O tipo de variante da função de valor de retorno.  
  
 **nParams**  
 O número de parâmetros de função.  
  
 **pVarTypes**  
 Uma matriz de tipos variantes de parâmetros de função.  
  
## <a name="remarks"></a>Comentários  
 Internamente, ATL usa essa estrutura para manter informações obtidas de uma biblioteca de tipos. Talvez você precise manipular diretamente essa estrutura se você fornecer informações de tipo para um manipulador de eventos usado com o [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe e [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info) macro.  
  
## <a name="example"></a>Exemplo  
 Dado um método de dispinterface definido em IDL:  
  
 [!code-cpp[NVC_ATL_Windowing #139](../../atl/codesnippet/cpp/atl-func-info-structure_1.idl)]  
  
 Você deve definir um `_ATL_FUNC_INFO` estrutura:  
  
 [!code-cpp[NVC_ATL_Windowing #140](../../atl/codesnippet/cpp/atl-func-info-structure_2.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)   
 [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)






