---
title: Estrutura _ATL_FUNC_INFO | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: c18e1c5a41ef910cfe327fdbdd8d8885ef30a092
ms.lasthandoff: 02/25/2017

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
 A convenção de chamada. Ao usar essa estrutura com o [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) , esse membro deve ser **CC_STDCALL**. `CC_CDECL`é a única opção com suporte no Windows CE para o `CALLCONV` campo o `_ATL_FUNC_INFO` estrutura. Não há suporte para qualquer outro valor, portanto, seu comportamento indefinido.  
  
 **vtReturn**  
 O tipo de variante da função de valor de retorno.  
  
 **nParams**  
 O número de parâmetros de função.  
  
 **pVarTypes**  
 Uma matriz de tipos variantes de parâmetros da função.  
  
## <a name="remarks"></a>Comentários  
 Internamente, ATL usa essa estrutura para armazenar informações obtidas de uma biblioteca de tipos. Talvez você precise manipular diretamente a essa estrutura se você fornecer informações de tipo para um manipulador de eventos usado com o [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe e [SINK_ENTRY_INFO](http://msdn.microsoft.com/library/1a0ae260-2c82-4926-a537-db01e5f206a7) macro.  
  
## <a name="example"></a>Exemplo  
 Dado um método dispinterface definido no IDL:  
  
 [!code-cpp[NVC_ATL_Windowing&#139;](../../atl/codesnippet/cpp/atl-func-info-structure_1.idl)]  
  
 Você deve definir um `_ATL_FUNC_INFO` estrutura:  
  
 [!code-cpp[NVC_ATL_Windowing&#140;](../../atl/codesnippet/cpp/atl-func-info-structure_2.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)   
 [SINK_ENTRY_INFO](http://msdn.microsoft.com/library/1a0ae260-2c82-4926-a537-db01e5f206a7)






