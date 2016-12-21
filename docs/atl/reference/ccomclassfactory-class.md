---
title: "Classe de CComClassFactory | Microsoft Docs"
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
  - "ATL.CComClassFactory"
  - "CComClassFactory"
  - "ATL::CComClassFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComClassFactory"
ms.assetid: e56dacf7-d5c4-4c42-aef4-a86d91981a1b
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComClassFactory
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa a interface de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) .  
  
## Sintaxe  
  
```  
  
   class CComClassFactory : public IClassFactory,   
public CComObjectRootEx< CComGlobalsThreadModel >  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComClassFactory::CreateInstance](../Topic/CComClassFactory::CreateInstance.md)|Cria um objeto de CLSID especificado.|  
|[CComClassFactory::LockServer](../Topic/CComClassFactory::LockServer.md)|Bloqueia o factory da classe na memória.|  
  
## Comentários  
 `CComClassFactory` implementa a interface de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) , que contém métodos para criar um objeto de um determinado CLSID, bem como bloquear o factory da classe na memória para permitir que os novos objetos criados mais rapidamente.  **IClassFactory** deve ser implementado para cada classe que você registra no Registro do sistema e a qual você atribui a uma CLSID.  
  
 Os objetos de ATL geralmente adquirem uma fábrica da classe derivando de [CComCoClass](../Topic/CComCoClass%20Class.md).  Essa classe inclui [DECLARE\_CLASSFACTORY](../Topic/DECLARE_CLASSFACTORY.md)macros, que declara `CComClassFactory` como o factory de classe padrão.  Para substituir essa opção, especifique um dos macros de `DECLARE_CLASSFACTORY`*XXX* em sua definição de classe.  Por exemplo, a macro de [DECLARE\_CLASSFACTORY\_EX](../Topic/DECLARE_CLASSFACTORY_EX.md) usa a classe especificada para o factory da classe:  
  
 [!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/CPP/ccomclassfactory-class_1.h)]  
  
 A definição de classe anterior especifica que **CMyClassFactory** será usado como o factory padrão da classe do objeto.  **CMyClassFactory** deve derivar de `CComClassFactory` e substituir `CreateInstance`.  
  
 ATL fornece outros três macros que declarar uma fábrica da classe:  
  
-   [DECLARE\_CLASSFACTORY2](../Topic/DECLARE_CLASSFACTORY2.md) usa [CComClassFactory2](../Topic/CComClassFactory2%20Class.md), que controla a criação através de uma licença.  
  
-   [DECLARE\_CLASSFACTORY\_AUTO\_THREAD](../Topic/DECLARE_CLASSFACTORY_AUTO_THREAD.md) usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria objetos em vários construção.  
  
-   [DECLARE\_CLASSFACTORY\_SINGLETON](../Topic/DECLARE_CLASSFACTORY_SINGLETON.md) usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói um único objeto de [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) .  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComGlobalsThreadModel](../Topic/CComGlobalsThreadModel.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)