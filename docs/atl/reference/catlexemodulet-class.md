---
title: "Classe de CAtlExeModuleT | Microsoft Docs"
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
  - "ATL::CAtlExeModuleT<T>"
  - "CAtlExeModuleT"
  - "ATL.CAtlExeModuleT<T>"
  - "ATL::CAtlExeModuleT"
  - "ATL.CAtlExeModuleT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlExeModuleT"
ms.assetid: 82245f3d-91d4-44fa-aa86-7cc7fbd758d9
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlExeModuleT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa o módulo para um aplicativo.  
  
## Sintaxe  
  
```  
  
      template <  
   class T   
>  
class ATL_NO_VTABLE CAtlExeModuleT :  
   public CAtlModuleT< T >  
```  
  
#### Parâmetros  
 `T`  
 A classe derivada de `CAtlExeModuleT`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlExeModuleT::CAtlExeModuleT](../Topic/CAtlExeModuleT::CAtlExeModuleT.md)|o construtor.|  
|[CAtlExeModuleT::~CAtlExeModuleT](../Topic/CAtlExeModuleT::~CAtlExeModuleT.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlExeModuleT::InitializeCom](../Topic/CAtlExeModuleT::InitializeCom.md)|Inicializa COM.|  
|[CAtlExeModuleT::ParseCommandLine](../Topic/CAtlExeModuleT::ParseCommandLine.md)|Analisar a linha de comando e executar o registro se necessário.|  
|[CAtlExeModuleT::PostMessageLoop](../Topic/CAtlExeModuleT::PostMessageLoop.md)|Este método é chamado imediatamente após o loop de mensagens termina.|  
|[CAtlExeModuleT::PreMessageLoop](../Topic/CAtlExeModuleT::PreMessageLoop.md)|Este método é chamado imediatamente antes de inserir o loop de mensagens.|  
|[CAtlExeModuleT::RegisterClassObjects](../Topic/CAtlExeModuleT::RegisterClassObjects.md)|Registra o objeto da classe.|  
|[CAtlExeModuleT::RevokeClassObjects](../Topic/CAtlExeModuleT::RevokeClassObjects.md)|Revoga o objeto da classe.|  
|[CAtlExeModuleT::Run](../Topic/CAtlExeModuleT::Run.md)|Esse método executa o código no módulo de EXE para inicializar, executa o loop de mensagem, e limpa\-o.|  
|[CAtlExeModuleT::RunMessageLoop](../Topic/CAtlExeModuleT::RunMessageLoop.md)|Esse método executa o loop de mensagens.|  
|[CAtlExeModuleT::UninitializeCom](../Topic/CAtlExeModuleT::UninitializeCom.md)|Uninitializes COM.|  
|[CAtlExeModuleT::Unlock](../Topic/CAtlExeModuleT::Unlock.md)|Diminui a contagem de bloqueio de módulo.|  
|[CAtlExeModuleT::WinMain](../Topic/CAtlExeModuleT::WinMain.md)|Este método implementa o código necessário para executar EXE.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlExeModuleT::m\_bDelayShutdown](../Topic/CAtlExeModuleT::m_bDelayShutdown.md)|Um sinalizador que indica que deve haver um atraso que fecha o módulo.|  
|[CAtlExeModuleT::m\_dwPause](../Topic/CAtlExeModuleT::m_dwPause.md)|Um valor de pausa usado para garantir todos os objetos é liberado antes de desligamento.|  
|[CAtlExeModuleT::m\_dwTimeOut](../Topic/CAtlExeModuleT::m_dwTimeOut.md)|Um valor de tempo limite usado para atrasar descarrega de módulo.|  
  
## Comentários  
 `CAtlExeModuleT` representa o módulo para um aplicativo \(EXE\) e contém o código que oferece suporte à criação de EXE, processando a linha de comando, registrar a classe objetos, executando o loop de mensagem, e limpando na saída.  
  
 Essa classe é criada para melhorar o desempenho quando os objetos COM no servidor de EXE continuamente são criados e destruídos.  Depois que o objeto COM o último é solto, EXE espera uma duração especificada pelo membro de dados de [CAtlExeModuleT::m\_dwTimeOut](../Topic/CAtlExeModuleT::m_dwTimeOut.md) .  Se não houver nenhuma atividade durante esse período \(isto é, COM nenhum objeto é criado\), o processo de desligamento é iniciado.  
  
 O membro de dados de [CAtlExeModuleT::m\_bDelayShutdown](../Topic/CAtlExeModuleT::m_bDelayShutdown.md) é um sinalizador usado para determinar se EXE usar o mecanismo definido acima.  Se estiver definida como false, então o módulo terminará imediatamente.  
  
 Para obter mais informações sobre módulos em ATL, consulte [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md).  
  
## Hierarquia de herança  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CAtlExeModuleT`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [exemplo de ATLDuck](../../top/visual-cpp-samples.md)   
 [Classe de CAtlModuleT](../../atl/reference/catlmodulet-class.md)   
 [Classe CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)