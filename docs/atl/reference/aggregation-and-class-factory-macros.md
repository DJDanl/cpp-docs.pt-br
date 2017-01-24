---
title: "Macros de f&#225;brica de distribui&#231;&#227;o e uma classe | Microsoft Docs"
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
  - "agregação [C++], Macros de ATL"
  - "fábricas de classe, Macros de ATL"
ms.assetid: d99d379a-0eec-481f-8daa-252dac18f163
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros de f&#225;brica de distribui&#231;&#227;o e uma classe
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esses macros fornecem maneiras para controlar a agregação e fábricas de declaração de classe.  
  
|||  
|-|-|  
|[DECLARE\_AGGREGATABLE](../Topic/DECLARE_AGGREGATABLE.md)|Declara que o objeto pode ser aggregate \(o padrão\).|  
|[DECLARE\_CLASSFACTORY](../Topic/DECLARE_CLASSFACTORY.md)|Declara o factory da classe para ser [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), a factory de classe padrão de ATL.|  
|[DECLARE\_CLASSFACTORY\_EX](../Topic/DECLARE_CLASSFACTORY_EX.md)|Declara o objeto de fábrica da classe para ser o factory da classe.|  
|[DECLARE\_CLASSFACTORY2](../Topic/DECLARE_CLASSFACTORY2.md)|Declara [CComClassFactory2](../Topic/CComClassFactory2%20Class.md) para ser o factory da classe.|  
|[DECLARE\_CLASSFACTORY\_AUTO\_THREAD](../Topic/DECLARE_CLASSFACTORY_AUTO_THREAD.md)|Declara [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) para ser o factory da classe.|  
|[DECLARE\_CLASSFACTORY\_SINGLETON](../Topic/DECLARE_CLASSFACTORY_SINGLETON.md)|Declara [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) para ser o factory da classe.|  
|[DECLARE\_GET\_CONTROLLING\_UNKNOWN](../Topic/DECLARE_GET_CONTROLLING_UNKNOWN.md)|Declara uma função virtual de `GetControllingUnknown` .|  
|[DECLARE\_NOT\_AGGREGATABLE](../Topic/DECLARE_NOT_AGGREGATABLE.md)|Declara que o objeto não pode ser agregado.|  
|[DECLARE\_ONLY\_AGGREGATABLE](../Topic/DECLARE_ONLY_AGGREGATABLE.md)|Declara que o objeto deve ser agregado.|  
|[DECLARE\_POLY\_AGGREGATABLE](../Topic/DECLARE_POLY_AGGREGATABLE.md)|Verifica o valor de desconhecido externo e declara o objeto aggregatable ou não aggregatable, conforme apropriado.|  
|[DECLARE\_PROTECT\_FINAL\_CONSTRUCT](../Topic/DECLARE_PROTECT_FINAL_CONSTRUCT.md)|Proteja o objeto externo de exclusão durante a compilação de um objeto interno.|  
|[DECLARE\_VIEW\_STATUS](../Topic/DECLARE_VIEW_STATUS.md)|Especifica os sinalizadores de **VIEWSTATUS** para o contêiner.|  
  
## Consulte também  
 [Macros](../../atl/reference/atl-macros.md)