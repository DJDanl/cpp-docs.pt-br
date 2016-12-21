---
title: "Estrutura de _ATL_FUNC_INFORMATION | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_ATL_FUNC_INFO"
  - "ATL::_ATL_FUNC_INFO"
  - "ATL._ATL_FUNC_INFO"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura de _ATL_FUNC_INFORMATION"
  - "Estrutura de ATL_FUNC_INFORMATION"
ms.assetid: 441ebe2c-f971-47de-9f52-a258e8d6f88e
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de _ATL_FUNC_INFORMATION
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Contém informações de tipo usada para descrever um método ou propriedade em um dispinterface.  
  
## Sintaxe  
  
```  
  
      struct _ATL_FUNC_INFO{  
   CALLCONV cc;  
   VARTYPE vtReturn;  
   SHORT nParams;  
   VARTYPE pVarTypes[_ATL_MAX_VARTYPES];  
};  
```  
  
## Membros  
 **cc**  
 A convenção de chamada.  A o usar essa estrutura com a classe de [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) , esse membro deve ser **CC\_STDCALL**.  `CC_CDECL` é a única opção suportado no Windows CE para o campo de `CALLCONV` estrutura de `_ATL_FUNC_INFO` .  Qualquer outro valor não é suportado para seu comportamento indefinido.  
  
 **vtReturn**  
 O tipo variante do valor de retorno da função.  
  
 **nParams**  
 O número de parâmetros da função.  
  
 **pVarTypes**  
 Uma matriz de tipos de parâmetros variantes de função.  
  
## Comentários  
 Internamente, ATL usa essa estrutura para manter informações obtidas de uma biblioteca de tipo.  Você pode precisar manipular diretamente essa estrutura se você fornecer informações de tipo para um manipulador de eventos usado com a classe de [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) e a macro de [SINK\_ENTRY\_INFORMATION](../Topic/SINK_ENTRY_INFO.md) .  
  
## Exemplo  
 Dado um método de dispinterface definido em IDL:  
  
 [!code-cpp[NVC_ATL_Windowing#139](../../atl/codesnippet/CPP/atl-func-info-structure_1.idl)]  
  
 você deve definir uma estrutura de `_ATL_FUNC_INFO` :  
  
 [!code-cpp[NVC_ATL_Windowing#140](../../atl/codesnippet/CPP/atl-func-info-structure_2.h)]  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Classe de IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)   
 [SINK\_ENTRY\_INFORMATION](../Topic/SINK_ENTRY_INFO.md)