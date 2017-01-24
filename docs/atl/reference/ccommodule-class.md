---
title: "Classe de CComModule | Microsoft Docs"
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
  - "CComModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComModule"
  - "Módulos de DLL [C++], ATL"
ms.assetid: f5face2c-8fd8-40e6-9ec3-54ab74701769
caps.latest.revision: 23
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Até a data de ATL 7,0, `CComModule` é substituído: consulte [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
class CComModule : public _ATL_MODULE  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComModule::GetClassObject](../Topic/CComModule::GetClassObject.md)|Cria um objeto de um CLSID especificado.  Para apenas dlls.|  
|[CComModule::GetModuleInstance](../Topic/CComModule::GetModuleInstance.md)|Retorna `m_hInst`.|  
|[CComModule::GetResourceInstance](../Topic/CComModule::GetResourceInstance.md)|Retorna `m_hInstResource`.|  
|[CComModule::GetTypeLibInstance](../Topic/CComModule::GetTypeLibInstance.md)|Retorna `m_hInstTypeLib`.|  
|[CComModule::Init](../Topic/CComModule::Init.md)|Inicializa membros de dados.|  
|[CComModule::RegisterClassHelper](../Topic/CComModule::RegisterClassHelper.md)|Inserir o registro de classe padrão de um objeto no Registro do sistema.|  
|[CComModule::RegisterClassObjects](../Topic/CComModule::RegisterClassObjects.md)|Registra o objeto da classe.  Para EXEs somente.|  
|[CComModule::RegisterServer](../Topic/CComModule::RegisterServer.md)|Atualizar o Registro do sistema para cada objeto no mapa do objeto.|  
|[CComModule::RegisterTypeLib](../Topic/CComModule::RegisterTypeLib.md)|Registra uma biblioteca de tipo.|  
|[CComModule::RevokeClassObjects](../Topic/CComModule::RevokeClassObjects.md)|Revoga o objeto da classe.  Para EXEs somente.|  
|[CComModule::Term](../Topic/CComModule::Term.md)|Libera membros de dados.|  
|[CComModule::UnregisterClassHelper](../Topic/CComModule::UnregisterClassHelper.md)|Remove o registro padrão da classe de um objeto de Registro do sistema.|  
|[CComModule::UnregisterServer](../Topic/CComModule::UnregisterServer.md)|Desregistre cada objeto no mapa do objeto.|  
|[CComModule::UpdateRegistryClass](../Topic/CComModule::UpdateRegistryClass.md)|Desregistre registros ou registro de classe padrão de um objeto.|  
|[CComModule::UpdateRegistryFromResourceD](../Topic/CComModule::UpdateRegistryFromResourceD.md)|Execute o script contido em um recurso especificado para registrar ou no unregister um objeto.|  
|[CComModule::UpdateRegistryFromResourceS](../Topic/CComModule::UpdateRegistryFromResourceS.md)|Vincula estaticamente componente de Registro de ATL.  Execute o script contido em um recurso especificado para registrar ou no unregister um objeto.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComModule::m\_csObjMap](../Topic/CComModule::m_csObjMap.md)|Ensures sincronizou acesso a informações do mapa do objeto.|  
|[CComModule::m\_csTypeInfoHolder](../Topic/CComModule::m_csTypeInfoHolder.md)|Ensures sincronizou acesso a informações de biblioteca de tipo.|  
|[CComModule::m\_csWindowCreate](../Topic/CComModule::m_csWindowCreate.md)|Ensures sincronizou acesso a informações de classe de janela e dados estáticos usados durante a criação da janela.|  
|[CComModule::m\_hInst](../Topic/CComModule::m_hInst.md)|Contém o identificador para a instância do módulo.|  
|[CComModule::m\_hInstResource](../Topic/CComModule::m_hInstResource.md)|Por padrão, contém o identificador para a instância do módulo.|  
|[CComModule::m\_hInstTypeLib](../Topic/CComModule::m_hInstTypeLib.md)|Por padrão, contém o identificador para a instância do módulo.|  
|[CComModule::m\_pObjMap](../Topic/CComModule::m_pObjMap.md)|Os pontos no mapa do objeto mantido pelo módulo instância.|  
  
## Comentários  
  
> [!NOTE]
>  Essa classe é substituída, e os assistentes de geração de código de ATL agora usam as classes derivadas de [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e de [CAtlModule](../../atl/reference/catlmodule-class.md) .  Consulte [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md) para mais informações.  Informações que segue é para uso com os aplicativos criados com as versões mais antigas de ATL.  `CComModule` ainda é parte de ATL para trás para o recurso.  
  
 `CComModule` implementa um módulo de servidor COM, permitindo que um cliente acessar os componentes do módulo.  `CComModule` suporta os módulos de processo em \(DLL\) e o EXE \(local\).  
  
 Uma instância de `CComModule` usa um mapa de objeto para manter um conjunto de definições de objeto da classe.  Esse mapeamento de objeto é implementado como uma matriz de estruturas de `_ATL_OBJMAP_ENTRY` , e contém informações para:  
  
-   Inserindo e removendo descrições de objeto no Registro do sistema.  
  
-   Criando uma instância objetos através de uma fábrica da classe.  
  
-   Estabelecendo comunicação entre um cliente e o objeto raiz no componente.  
  
-   Executando o gerenciamento de vida útil de objeto da classe.  
  
 Quando você executa o ATL COM AppWizard, o assistente gera automaticamente `_Module`, uma instância global de `CComModule` ou uma classe derivada de ela.  Para obter mais informações sobre o assistente de projeto de ATL, consulte o artigo [Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md).  
  
 Além de `CComModule`, ATL fornece [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), que implementa um módulo de apartamento\- modelo para EXEs e Serviços do Windows.  Derive o módulo de `CComAutoThreadModule` quando você deseja criar objetos em vários construção.  
  
## Hierarquia de herança  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CComModule`  
  
## Requisitos  
 `Header:` atlbase.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)