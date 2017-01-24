---
title: "Classe de CWinAppEx | Microsoft Docs"
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
  - "CWinAppEx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWinAppEx"
ms.assetid: a3d3e053-3e22-463f-9444-c73abb1bb9d7
caps.latest.revision: 37
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinAppEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CWinAppEx` trata o estado do aplicativo, salvar o estado para o Registro, carrega o estado do Registro, inicializa gerentes do aplicativo, e fornece links 2 esses mesmos gerentes do aplicativo.  
  
## Sintaxe  
  
```  
class CWinAppEx : public CWinApp  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinAppEx::CWinAppEx](../Topic/CWinAppEx::CWinAppEx.md)|Constrói um objeto de `CWinAppEx` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinAppEx::CleanState](../Topic/CWinAppEx::CleanState.md)|Remove as informações sobre o aplicativo de Registro do Windows.|  
|[CWinAppEx::EnableLoadWindowPlacement](../Topic/CWinAppEx::EnableLoadWindowPlacement.md)|Especifica se o aplicativo será carregado o tamanho e local inicial da janela de quadro chave do Registro.|  
|[CWinAppEx::EnableTearOffMenus](../Topic/CWinAppEx::EnableTearOffMenus.md)|Permite menus de rasgo \- fora do aplicativo.|  
|[CWinAppEx::EnableUserTools](../Topic/CWinAppEx::EnableUserTools.md)|Permite que o usuário para criar comandos de menu personalizados no aplicativo.|  
|[CWinAppEx::ExitInstance](../Topic/CWinAppEx::ExitInstance.md)|Chamado pela estrutura de dentro da função de membro de `Run` para sair de essa instância do aplicativo.  Overrides \( [CWinApp::ExitInstance](../Topic/CWinApp::ExitInstance.md).\)|  
|[CWinAppEx::GetBinary](../Topic/CWinAppEx::GetBinary.md)|Ler dados binários que são associados com o valor do Registro especificado.|  
|[CWinAppEx::GetContextMenuManager](../Topic/CWinAppEx::GetContextMenuManager.md)|Retorna um ponteiro para o objeto global de [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) .|  
|[CWinAppEx::GetDataVersion](../Topic/CWinAppEx::GetDataVersion.md)||  
|[CWinAppEx::GetDataVersionMajor](../Topic/CWinAppEx::GetDataVersionMajor.md)|Retorna a versão principal do aplicativo salva no Registro do Windows.|  
|[CWinAppEx::GetDataVersionMinor](../Topic/CWinAppEx::GetDataVersionMinor.md)|Retorna a versão secundária do aplicativo salva no Registro do Windows.|  
|[CWinAppEx::GetInt](../Topic/CWinAppEx::GetInt.md)|Ler os dados numéricos que são associados com o valor especificado do Registro.|  
|[CWinAppEx::GetKeyboardManager](../Topic/CWinAppEx::GetKeyboardManager.md)|Retorna um ponteiro para o objeto global de [CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md) .|  
|[CWinAppEx::GetMouseManager](../Topic/CWinAppEx::GetMouseManager.md)|Retorna um ponteiro para o objeto global de [CMouseManager](../../mfc/reference/cmousemanager-class.md) .|  
|[CWinAppEx::GetObject](../Topic/CWinAppEx::GetObject.md)|Ler `CObject`\- os dados derivado que são associados com o valor especificado do Registro.|  
|[CWinAppEx::GetRegSectionPath](../Topic/CWinAppEx::GetRegSectionPath.md)|Retorna uma cadeia de caracteres que é o caminho de uma chave do Registro.  Este caminho concatena o caminho relativo fornecido pelo caminho do aplicativo.|  
|[CWinAppEx::GetRegistryBase](../Topic/CWinAppEx::GetRegistryBase.md)|Retorna o caminho de Registro para o aplicativo.|  
|[CWinAppEx::GetSectionBinary](../Topic/CWinAppEx::GetSectionBinary.md)|Ler dados binários que estão associados com a chave e o valor especificado do Registro.|  
|[CWinAppEx::GetSectionInt](../Topic/CWinAppEx::GetSectionInt.md)|Dados numéricos de leitura do Registro associado com a chave e o valor especificado.|  
|[CWinAppEx::GetSectionObject](../Topic/CWinAppEx::GetSectionObject.md)|Ler os dados de `CObject` que estão associados com a chave e o valor especificado do Registro.|  
|[CWinAppEx::GetSectionString](../Topic/CWinAppEx::GetSectionString.md)|Dados de cadeia de caracteres de leitura que estão associados com a chave e o valor especificado do Registro.|  
|[CWinAppEx::GetShellManager](../Topic/CWinAppEx::GetShellManager.md)|Retorna um ponteiro para o objeto global de [CShellManager](../../mfc/reference/cshellmanager-class.md) .|  
|[CWinAppEx::GetString](../Topic/CWinAppEx::GetString.md)|Dados de cadeia de caracteres de leitura que são associados com o valor especificado do Registro.|  
|[CWinAppEx::GetTooltipManager](../Topic/CWinAppEx::GetTooltipManager.md)|Retorna um ponteiro para o objeto global de [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) .|  
|[CWinAppEx::GetUserToolsManager](../Topic/CWinAppEx::GetUserToolsManager.md)|Retorna um ponteiro para o objeto global de [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) .|  
|[CWinAppEx::InitContextMenuManager](../Topic/CWinAppEx::InitContextMenuManager.md)|Inicializa o objeto de `CContextMenuManager` .|  
|[CWinAppEx::InitKeyboardManager](../Topic/CWinAppEx::InitKeyboardManager.md)|Inicializa o objeto de `CKeyboardManager` .|  
|[CWinAppEx::InitMouseManager](../Topic/CWinAppEx::InitMouseManager.md)|Inicializa o objeto de `CMouseManager` .|  
|[CWinAppEx::InitShellManager](../Topic/CWinAppEx::InitShellManager.md)|Inicializa a classe de `CShellManager`|  
|[CWinAppEx::InitTooltipManager](../Topic/CWinAppEx::InitTooltipManager.md)|Inicializa a classe de `CTooltipManager` .|  
|[CWinAppEx::IsResourceSmartUpdate](../Topic/CWinAppEx::IsResourceSmartUpdate.md)||  
|[CWinAppEx::IsStateExists](../Topic/CWinAppEx::IsStateExists.md)|Indica se a chave especificada está no Registro.|  
|[CWinAppEx::LoadState](../Topic/CWinAppEx::LoadState.md)|Carrega o estado do aplicativo do Registro.|  
|[CWinAppEx::OnAppContextHelp](../Topic/CWinAppEx::OnAppContextHelp.md)|Chamado pela estrutura quando a ajuda do contexto de um usuário para a caixa de diálogo de **Personalização** .|  
|[CWinAppEx::OnViewDoubleClick](../Topic/CWinAppEx::OnViewDoubleClick.md)|Chama o comando definido pelo usuário quando o usuário clica duas vezes em qualquer lugar no aplicativo.|  
|[CWinAppEx::OnWorkspaceIdle](../Topic/CWinAppEx::OnWorkspaceIdle.md)||  
|[CWinAppEx::SaveState](../Topic/CWinAppEx::SaveState.md)|Grava o estado da estrutura do aplicativo no Registro do Windows.|  
|[CWinAppEx::SetRegistryBase](../Topic/CWinAppEx::SetRegistryBase.md)|Defina o caminho da chave do Registro padrão.  Essa chave servirá como uma raiz para todas as chamadas subseqüentes do Registro.|  
|[CWinAppEx::ShowPopupMenu](../Topic/CWinAppEx::ShowPopupMenu.md)|Exibe um menu pop\-up.|  
|[CWinAppEx::WriteBinary](../Topic/CWinAppEx::WriteBinary.md)|Grava dados binários ao valor do Registro especificado.|  
|[CWinAppEx::WriteInt](../Topic/CWinAppEx::WriteInt.md)|Grava os dados numéricos para o valor do Registro especificado.|  
|[CWinAppEx::WriteObject](../Topic/CWinAppEx::WriteObject.md)|Grava os dados que são derivados de [Classe de CObject](../Topic/CObject%20Class.md) ao valor do Registro especificado.|  
|[CWinAppEx::WriteSectionBinary](../Topic/CWinAppEx::WriteSectionBinary.md)|Grava dados binários a um valor da chave de Registro especificada.|  
|[CWinAppEx::WriteSectionInt](../Topic/CWinAppEx::WriteSectionInt.md)|Grava os dados numéricos para um valor da chave de Registro especificada.|  
|[CWinAppEx::WriteSectionObject](../Topic/CWinAppEx::WriteSectionObject.md)|O grava dados derivados da classe `CObject` um valor da chave de Registro especificada.|  
|[CWinAppEx::WriteSectionString](../Topic/CWinAppEx::WriteSectionString.md)|Grava os dados de cadeia de caracteres em um valor de chave de Registro especificada.|  
|[CWinAppEx::WriteString](../Topic/CWinAppEx::WriteString.md)|Grava os dados da cadeia de caracteres ao valor do Registro especificado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinAppEx::LoadCustomState](../Topic/CWinAppEx::LoadCustomState.md)|Chamado pela estrutura quando o estado do aplicativo é carregado.|  
|[CWinAppEx::LoadWindowPlacement](../Topic/CWinAppEx::LoadWindowPlacement.md)|Chamado pela estrutura ao carregar o tamanho e a localidade do seu aplicativo do Registro.  Os dados carregados incluem o tamanho e local de quadro chave no último de aplicativo se é desligado.|  
|[CWinAppEx::OnClosingMainFrame](../Topic/CWinAppEx::OnClosingMainFrame.md)|Chamado pela estrutura quando uma janela de quadro chave processar `WM_CLOSE`.|  
|[CWinAppEx::PreLoadState](../Topic/CWinAppEx::PreLoadState.md)|Chamado pela estrutura imediatamente antes do estado do aplicativo é carregado.|  
|[CWinAppEx::PreSaveState](../Topic/CWinAppEx::PreSaveState.md)|Chamado pela estrutura imediatamente antes do estado do aplicativo é salvo.|  
|[CWinAppEx::ReloadWindowPlacement](../Topic/CWinAppEx::ReloadWindowPlacement.md)|Recarrega o tamanho e local da janela fornecida do Registro|  
|[CWinAppEx::SaveCustomState](../Topic/CWinAppEx::SaveCustomState.md)|Chamado pela estrutura depois que grava o estado do aplicativo no Registro.|  
|[CWinAppEx::StoreWindowPlacement](../Topic/CWinAppEx::StoreWindowPlacement.md)|Chamado pela estrutura para escrever o tamanho e local de quadro chave do Registro.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinAppEx::m\_bForceImageReset](../Topic/CWinAppEx::m_bForceImageReset.md)|Especifica se a estrutura vá de todas as imagens barra de ferramentas quando a janela de quadro chave que contém a barra de ferramentas é carregada.|  
  
## Comentários  
 Grande parte da funcionalidade fornecida pela estrutura MFC depende da classe de `CWinAppEx` .  Você pode inserir a classe de `CWinAppEx` em seu aplicativo de duas maneiras:  
  
-   Construir uma classe de `CWinAppEx` no segmento principal.  
  
-   Derive a classe do aplicativo principal de `CWinAppEx`.  
  
 Depois de você inserir `CWinAppEx` em seu aplicativo, você pode inicializar de gerentes do aplicativo.  Antes de você usar um gerente do aplicativo, você deve inicializá\-la chamando o apropriado inicializa o método.  Para obter um ponteiro para um gerente específico, chame o associado obtém o método.  A classe de `CWinAppEx` gerencia os seguintes gerentes do aplicativo: [Classe de CMouseManager](../../mfc/reference/cmousemanager-class.md), [Classe de CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md), [Classe de CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md), [Classe de CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md), e [Classe de CMenuTearOffManager](../../mfc/reference/cmenutearoffmanager-class.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 [CWinApp](../../mfc/reference/cwinapp-class.md)  
  
 [CWinAppEx](../../mfc/reference/cwinappex-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxwinappex.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CWinApp](../../mfc/reference/cwinapp-class.md)   
 [Classe de CMouseManager](../../mfc/reference/cmousemanager-class.md)   
 [Classe de CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)   
 [Classe de CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)   
 [Classe de CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)