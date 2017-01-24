---
title: "Classe de CComClassFactoryAutoThread | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL::CComClassFactoryAutoThread"
  - "ATL.CComClassFactoryAutoThread"
  - "CComClassFactoryAutoThread"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComClassFactoryAutoThread"
ms.assetid: 22008042-533f-4dd9-bf7e-191ee571f9a1
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComClassFactoryAutoThread
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa a interface de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) , e permite que objetos criados em vários construção.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      class CComClassFactoryAutoThread : public IClassFactory,   
public CComObjectRootEx< CComGlobalsThreadModel >  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComClassFactoryAutoThread::CreateInstance](../Topic/CComClassFactoryAutoThread::CreateInstance.md)|Cria um objeto de CLSID especificado.|  
|[CComClassFactoryAutoThread::LockServer](../Topic/CComClassFactoryAutoThread::LockServer.md)|Bloqueia o factory da classe na memória.|  
  
## Comentários  
 `CComClassFactoryAutoThread` é semelhante a [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que objetos criados em vários construção.  Para aproveitar este suporte, derive o módulo de EXE de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  
  
 Os objetos de ATL geralmente adquirem uma fábrica da classe derivando de [CComCoClass](../Topic/CComCoClass%20Class.md).  Essa classe inclui [DECLARE\_CLASSFACTORY](../Topic/DECLARE_CLASSFACTORY.md)macros, que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como o factory de classe padrão.  Para usar `CComClassFactoryAutoThread`, especifique a macro de [DECLARE\_CLASSFACTORY\_AUTO\_THREAD](../Topic/DECLARE_CLASSFACTORY_AUTO_THREAD.md) em sua definição de classe de objeto.  Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/CPP/ccomclassfactoryautothread-class_1.h)]  
  
## Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IClassFactory`  
  
 `CComClassFactoryAutoThread`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364)   
 [Classe CComClassFactory2](../Topic/CComClassFactory2%20Class.md)   
 [Classe de CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)   
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComGlobalsThreadModel](../Topic/CComGlobalsThreadModel.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)