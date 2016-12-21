---
title: "Classe de CAtlModule | Microsoft Docs"
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
  - "ATL::CAtlModule"
  - "CAtlModule"
  - "ATL.CAtlModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlModule"
ms.assetid: 63fe02f1-4c4b-4e7c-ae97-7ad7b4252415
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos usados por várias classes do módulo de ATL.  
  
## Sintaxe  
  
```  
  
   class ATL_NO_VTABLE CAtlModule :  
public _ATL_MODULE  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlModule::CAtlModule](../Topic/CAtlModule::CAtlModule.md)|o construtor.|  
|[CAtlModule::~CAtlModule](../Topic/CAtlModule::~CAtlModule.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlModule::AddCommonRGSReplacements](../Topic/CAtlModule::AddCommonRGSReplacements.md)|Substitua esse método para adicionar parâmetros para o mapa componente de substituição de Registro de ATL \(escrivão\).|  
|[CAtlModule::AddTermFunc](../Topic/CAtlModule::AddTermFunc.md)|Adiciona uma nova função a ser chamado quando o módulo finaliza.|  
|[CAtlModule::GetGITPtr](../Topic/CAtlModule::GetGITPtr.md)|Retorna o ponteiro global da interface.|  
|[CAtlModule::GetLockCount](../Topic/CAtlModule::GetLockCount.md)|Retorna a contagem de bloqueio.|  
|[CAtlModule::Lock](../Topic/CAtlModule::Lock.md)|Sai a contagem de bloqueio.|  
|[CAtlModule::Term](../Topic/CAtlModule::Term.md)|Libera quaisquer membros de dados.|  
|[CAtlModule::Unlock](../Topic/CAtlModule::Unlock.md)|Diminui a contagem de bloqueio.|  
|[CAtlModule::UpdateRegistryFromResourceD](../Topic/CAtlModule::UpdateRegistryFromResourceD.md)|Execute o script contido em um recurso especificado para registrar ou no unregister um objeto.|  
|[CAtlModule::UpdateRegistryFromResourceDHelper](../Topic/CAtlModule::UpdateRegistryFromResourceDHelper.md)|Este método é chamado por `UpdateRegistryFromResourceD` para executar a atualização do Registro.|  
|[CAtlModule::UpdateRegistryFromResourceS](../Topic/CAtlModule::UpdateRegistryFromResourceS.md)|Execute o script contido em um recurso especificado para registrar ou no unregister um objeto.  Este método leva estaticamente componente de Registro de ATL.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlModule::m\_libid](../Topic/CAtlModule::m_libid.md)|Contém o módulo atual.|  
|[CAtlModule::m\_pGIT](../Topic/CAtlModule::m_pGIT.md)|Ponteiro para a tabela global da interface.|  
  
## Comentários  
 Essa classe é usada por [classe de CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md), por [classe de CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md), e por [classe de CAtlServiceModuleT](../Topic/CAtlServiceModuleT%20Class.md) para fornecer suporte para aplicativos de DLL, aplicativos de EXE, e Serviços do Windows, respectivamente.  
  
 Para obter mais informações sobre módulos em ATL, consulte [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md).  
  
 Esta classe substitui [classe de CComModule](../../atl/reference/ccommodule-class.md) obsoleto usado em versões anteriores de ATL.  
  
## Hierarquia de herança  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)  
  
 `CAtlModule`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../Topic/ATL%20Module%20Classes.md)   
 [Componente de registro \(Registrar\)](../../atl/atl-registry-component-registrar.md)