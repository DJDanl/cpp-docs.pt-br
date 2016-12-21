---
title: "Classe CAtlDllModuleT | Microsoft Docs"
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
  - "ATL.CAtlDllModuleT"
  - "ATL::CAtlDllModuleT<T>"
  - "ATL::CAtlDllModuleT"
  - "ATL.CAtlDllModuleT<T>"
  - "CAtlDllModuleT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CAtlDllModuleT"
ms.assetid: 351d5767-8257-4878-94be-45a85e31a72d
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CAtlDllModuleT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe representa o módulo para uma DLL.  
  
## Sintaxe  
  
```  
  
template <  
   class   
T  
>  
class ATL_NO_VTABLE CAtlDllModuleT :  
   public CAtlModuleT<   
T  
 >  
  
```  
  
#### Parâmetros  
 `T`  
 Sua classe derivada de `CAtlDllModuleT`.  
  
## Membros  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlDllModuleT::CAtlDllModuleT](../Topic/CAtlDllModuleT::CAtlDllModuleT.md)|O construtor.|  
|[CAtlDllModuleT::~CAtlDllModuleT](../Topic/CAtlDllModuleT::~CAtlDllModuleT.md)|O destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlDllModuleT::DllCanUnloadNow](../Topic/CAtlDllModuleT::DllCanUnloadNow.md)|Testa se a DLL pode ser descarregada.|  
|[CAtlDllModuleT::DllGetClassObject](../Topic/CAtlDllModuleT::DllGetClassObject.md)|Retorna uma fábrica de classes.|  
|[CAtlDllModuleT::DllMain](../Topic/CAtlDllModuleT::DllMain.md)|O ponto de entrada opcional em uma biblioteca de vínculo dinâmico \(DLL\).|  
|[CAtlDllModuleT::DllRegisterServer](../Topic/CAtlDllModuleT::DllRegisterServer.md)|Adiciona entradas ao registro do sistema para objetos na DLL.|  
|[CAtlDllModuleT::DllUnregisterServer](../Topic/CAtlDllModuleT::DllUnregisterServer.md)|Remove as entradas no registro do sistema para objetos na DLL.|  
|[CAtlDllModuleT::GetClassObject](../Topic/CAtlDllModuleT::GetClassObject.md)|Retorna uma fábrica de classes. Chamado por [DllGetClassObject](../Topic/CAtlDllModuleT::DllGetClassObject.md).|  
  
## Comentários  
 `CAtlDllModuleT` representa o módulo para uma biblioteca de vínculo dinâmico \(DLL\) e fornece funções usadas por todos os projetos DLL. Essa especialização de [CAtlModuleT](../../atl/reference/catlmodulet-class.md) classe inclui suporte para registro.  
  
 Para obter mais informações sobre módulos em ATL, consulte [Classes de módulo ATL](../Topic/ATL%20Module%20Classes.md).  
  
## Hierarquia de herança  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CAtlDllModuleT`  
  
## Requisitos  
 **Cabeçalho:** atlbase. h  
  
## Consulte também  
 [Classe de CAtlModuleT](../../atl/reference/catlmodulet-class.md)   
 [Classe de CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../Topic/ATL%20Module%20Classes.md)