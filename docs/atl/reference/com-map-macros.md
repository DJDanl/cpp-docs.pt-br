---
title: "Macros de mapa COM | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interfaces COM, Macros de mapa COM"
ms.assetid: 0f33656d-321f-4996-90cc-9a7f21ab73c3
caps.latest.revision: 16
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros de mapa COM
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esses macros definem mapas da interface COM.  
  
|||  
|-|-|  
|[BEGIN\_COM\_MAP](../Topic/BEGIN_COM_MAP.md)|Marca o início de entradas do mapa da interface COM.|  
|[COM\_INTERFACE\_ENTRY](../Topic/COM_INTERFACE_ENTRY%20Macros.md)|Insere interfaces no mapa da interface COM.|  
|[COM\_INTERFACE\_ENTRY2](../Topic/COM_INTERFACE_ENTRY2.md)|Use este macro para desambiguar duas ramificações de herança.|  
|[COM\_INTERFACE\_ENTRY\_IID](../Topic/COM_INTERFACE_ENTRY_IID.md)|Use este macro para incorporar a interface no mapa COM e para especificar o IID.|  
|[COM\_INTERFACE\_ENTRY2\_IID](../Topic/COM_INTERFACE_ENTRY2_IID.md)|Mesmo que [COM\_INTERFACE\_ENTRY2](../Topic/COM_INTERFACE_ENTRY2.md), a não ser que você pode especificar um IID diferente.|  
|[COM\_INTERFACE\_ENTRY\_AGGREGATE](../Topic/COM_INTERFACE_ENTRY_AGGREGATE.md)|Quando a interface identificada por `iid` é consultada para, `COM_INTERFACE_ENTRY_AGGREGATE` encaminha a `punk`.|  
|[COM\_INTERFACE\_ENTRY\_AGGREGATE\_BLIND](../Topic/COM_INTERFACE_ENTRY_AGGREGATE_BLIND.md)|Mesmo que [COM\_INTERFACE\_ENTRY\_AGGREGATE](../Topic/COM_INTERFACE_ENTRY_AGGREGATE.md), exceto que consulte para qualquer IID leva a encaminhar a consulta a `punk`.|  
|[COM\_INTERFACE\_ENTRY\_AUTOAGGREGATE](../Topic/COM_INTERFACE_ENTRY_AUTOAGGREGATE.md)|Mesmo que [COM\_INTERFACE\_ENTRY\_AGGREGATE](../Topic/COM_INTERFACE_ENTRY_AGGREGATE.md), exceto se `punk` é **NULO**, cria automaticamente a agregação descrita por `clsid`.|  
|[COM\_INTERFACE\_ENTRY\_AUTOAGGREGATE\_BLIND](../Topic/COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND.md)|Mesmo que [COM\_INTERFACE\_ENTRY\_AUTOAGGREGATE](../Topic/COM_INTERFACE_ENTRY_AUTOAGGREGATE.md), exceto que consulte para qualquer IID leva a encaminhar a consulta a `punk`, e se `punk` é **NULO**, criando automaticamente a agregação descrita por `clsid`.|  
|[COM\_INTERFACE\_ENTRY\_BREAK](../Topic/COM_INTERFACE_ENTRY_BREAK.md)|Faz com que seu programa chama [DebugBreak](http://msdn.microsoft.com/library/windows/desktop/ms679297) quando a interface especificada é consultada para.|  
|[COM\_INTERFACE\_ENTRY\_CACHED\_TEAR\_OFF](../Topic/COM_INTERFACE_ENTRY_CACHED_TEAR_OFF.md)|Salva os dados \- específicos para cada instância.|  
|[COM\_INTERFACE\_ENTRY\_TEAR\_OFF](../Topic/COM_INTERFACE_ENTRY_TEAR_OFF.md)|Expõem suas interfaces de rasgo \- fora.|  
|[COM\_INTERFACE\_ENTRY\_CHAIN](../Topic/COM_INTERFACE_ENTRY_CHAIN.md)|Processa o mapa da classe base quando o processamento atinge essa entrada no mapa COM.|  
|[COM\_INTERFACE\_ENTRY\_FUNC](../Topic/COM_INTERFACE_ENTRY_FUNC.md)|Um mecanismo geral para ligar em `QueryInterface` de ATL lógica.|  
|[COM\_INTERFACE\_ENTRY\_FUNC\_BLIND](../Topic/COM_INTERFACE_ENTRY_FUNC_BLIND.md)|Mesmo que [COM\_INTERFACE\_ENTRY\_FUNC](../Topic/COM_INTERFACE_ENTRY_FUNC.md), exceto que consulte para alguns resultados de IID em uma chamada para `func`.|  
|[COM\_INTERFACE\_ENTRY\_NOINTERFACE](../Topic/COM_INTERFACE_ENTRY_NOINTERFACE.md)|Retorna **E\_NOINTERFACE** e encerra o processamento do mapa da quando a interface especificada é consultada para.|  
|[END\_COM\_MAP](../Topic/END_COM_MAP.md)|Marca end de entradas do mapa da interface COM.|  
  
## Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais do mapa COM](../../atl/reference/com-map-global-functions.md)