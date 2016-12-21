---
title: "Classe de CComAutoThreadModule | Microsoft Docs"
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
  - "CComAutoThreadModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "módulos modelo de compartimento"
  - "Classe de CComAutoThreadModule"
ms.assetid: 13063ea5-a57e-4aac-97d3-227137262811
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComAutoThreadModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Até a data de ATL 7,0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
class ThreadAllocator= CComSimpleThreadAllocator   
>  
class CComAutoThreadModule :  
public CComModule  
```  
  
#### Parâmetros  
 `ThreadAllocator`  
 \[in\] a classe que gerencia a seleção de segmento.  o valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CreateInstance](../Topic/CComAutoThreadModule::CreateInstance.md)|Seleciona um segmento e então cria um objeto no apartment associado.|  
|[GetDefaultThreads](../Topic/CComAutoThreadModule::GetDefaultThreads.md)|\(Static\) Dinamicamente calcula o número de segmentos para o módulo com base no número de processadores.|  
|[Init](../Topic/CComAutoThreadModule::Init.md)|Cria segmentos de módulo.|  
|[Bloquear](../Topic/CComAutoThreadModule::Lock.md)|Sai a contagem de bloqueio no módulo e no segmento atual.|  
|[Unlock](../Topic/CComAutoThreadModule::Unlock.md)|Diminui a contagem de bloqueio no módulo e no segmento atual.|  
  
### Membros de dados  
  
### Membros de dados  
  
|||  
|-|-|  
|[dwThreadID](../Topic/CComAutoThreadModule::dwThreadID.md)|Contém o identificador do segmento atual.|  
|[m\_Allocator](../Topic/CComAutoThreadModule::m_Allocator.md)|Gerencia a seleção de segmento.|  
|[m\_nThreads](../Topic/CComAutoThreadModule::m_nThreads.md)|Contém o número de segmentos no módulo.|  
|[m\_pApartments](../Topic/CComAutoThreadModule::m_pApartments.md)|Gerencia a construção de módulo.|  
  
## Comentários  
  
> [!NOTE]
>  Essa classe é obsoleta, sendo substituído por classes derivadas de [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e de [CAtlModule](../../atl/reference/catlmodule-class.md) .  Informações que segue é para uso com versões mais antigas de ATL.  
  
 `CComAutoThreadModule` deriva de [CComModule](../../atl/reference/ccommodule-class.md) para implementar um servidor com agrupados, de apartamento\- modelo COM para EXEs e Serviços do Windows.  `CComAutoThreadModule` usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um compartimento para cada segmento no módulo.  
  
 Derive o módulo de `CComAutoThreadModule` quando você deseja criar objetos em vários construção.  Você também deve incluir a macro de [DECLARE\_CLASSFACTORY\_AUTO\_THREAD](../Topic/DECLARE_CLASSFACTORY_AUTO_THREAD.md) em sua definição de classe de objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como o factory da classe.  
  
 Por padrão, o ATL COM AppWizard \(assistente de projeto de ATL no Visual Studio .NET\) derivado seu módulo de `CComModule`.  Para usar `CComAutoThreadModule`, modifique a definição de classe.  Por exemplo:  
  
 [!code-cpp[NVC_ATL_AxHost#2](../../atl/codesnippet/CPP/ccomautothreadmodule-class_1.cpp)]  
  
## Hierarquia de herança  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 `IAtlAutoThreadModule`  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)  
  
 [CComModule](../../atl/reference/ccommodule-class.md)  
  
 `CComAutoThreadModule`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../Topic/ATL%20Module%20Classes.md)