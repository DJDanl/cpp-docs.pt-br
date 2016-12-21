---
title: "Classe de CUserToolsManager | Microsoft Docs"
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
  - "CUserToolsManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CUserToolsManager"
ms.assetid: bdfa37ae-efca-4616-abb5-9d0dcd2d335b
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CUserToolsManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Mantém a coleção de objetos de [Classe de CUserTool](../Topic/CUserTool%20Class.md) em um aplicativo.  Uma ferramenta de usuário é um item de menu que executa um aplicativo externo.  O objeto de `CUserToolsManager` permite que o usuário ou o desenvolvedor para adicionar novas ferramentas de usuário para o aplicativo.  Oferece suporte à execução de comandos associados com ferramentas de usuário, e também salva informações sobre ferramentas do usuário no Registro do Windows.  
  
## Sintaxe  
  
```  
class CUserToolsManager : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CUserToolsManager::CUserToolsManager](../Topic/CUserToolsManager::CUserToolsManager.md)|Constrói `CUserToolsManager`.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CUserToolsManager::CreateNewTool](../Topic/CUserToolsManager::CreateNewTool.md)|Cria uma nova ferramenta de usuário.|  
|[CUserToolsManager::FindTool](../Topic/CUserToolsManager::FindTool.md)|Retorna o ponteiro ao objeto de `CMFCUserTool` que está associado com um certo ID de comando|  
|[CUserToolsManager::GetArgumentsMenuID](../Topic/CUserToolsManager::GetArgumentsMenuID.md)|Retorna a identificação de recurso que está associado com o menu de **Argumentos** na guia de **Ferramentas** da caixa de diálogo de **Personalizar** .|  
|[CUserToolsManager::GetDefExt](../Topic/CUserToolsManager::GetDefExt.md)|Retorna a extensão padrão que a caixa de diálogo de **Abrir arquivo** \([CFileDialog::CFileDialog](../Topic/CFileDialog::CFileDialog.md)\) usa no campo de **Comando** na guia de **Ferramentas** da caixa de diálogo de **Personalizar**.|  
|[CUserToolsManager::GetFilter](../Topic/CUserToolsManager::GetFilter.md)|Retorna o filtro de arquivo que a caixa de diálogo de **Abrir arquivo** \([Classe de CFileDialog](../Topic/CFileDialog%20Class.md)\) usa no campo de **Comando** na guia de **Ferramentas** da caixa de diálogo de **Personalizar**.|  
|[CUserToolsManager::GetInitialDirMenuID](../Topic/CUserToolsManager::GetInitialDirMenuID.md)|Retorna a identificação de recurso que está associado com o menu de **Diretório inicial** na guia de **Ferramentas** da caixa de diálogo de **Personalizar** .|  
|[CUserToolsManager::GetMaxTools](../Topic/CUserToolsManager::GetMaxTools.md)|Retorna o número máximo de ferramentas do usuário que podem ser atribuídas no aplicativo.|  
|[CUserToolsManager::GetToolsEntryCmd](../Topic/CUserToolsManager::GetToolsEntryCmd.md)|Retorna a identificação de comando do espaço reservado de item de menu para ferramentas do usuário.|  
|[CUserToolsManager::GetUserTools](../Topic/CUserToolsManager::GetUserTools.md)|Retorna uma referência à lista de ferramentas do usuário.|  
|[CUserToolsManager::InvokeTool](../Topic/CUserToolsManager::InvokeTool.md)|Executa um aplicativo associado com a ferramenta de usuário que tem um certo ID de comando|  
|[CUserToolsManager::IsUserToolCmd](../Topic/CUserToolsManager::IsUserToolCmd.md)|Determina se uma identificação de comando está associado com uma ferramenta de usuário.|  
|[CUserToolsManager::LoadState](../Topic/CUserToolsManager::LoadState.md)|Carrega informações sobre ferramentas do usuário de Registro do Windows.|  
|[CUserToolsManager::MoveToolDown](../Topic/CUserToolsManager::MoveToolDown.md)|Move a ferramenta de usuário especificada para baixo na lista de ferramentas do usuário.|  
|[CUserToolsManager::MoveToolUp](../Topic/CUserToolsManager::MoveToolUp.md)|Move a ferramenta especificada do usuário acima na lista de ferramentas do usuário.|  
|[CUserToolsManager::RemoveTool](../Topic/CUserToolsManager::RemoveTool.md)|Remove a ferramenta especificada do usuário do aplicativo.|  
|[CUserToolsManager::SaveState](../Topic/CUserToolsManager::SaveState.md)|Armazena informações sobre ferramentas do usuário no Registro do Windows.|  
|[CUserToolsManager::SetDefExt](../Topic/CUserToolsManager::SetDefExt.md)|Especifica a extensão padrão que a caixa de diálogo de **Abrir arquivo** \([Classe de CFileDialog](../Topic/CFileDialog%20Class.md)\) usa no campo de **Comando** na guia de **Ferramentas** da caixa de diálogo de **Personalizar** .|  
|[CUserToolsManager::SetFilter](../Topic/CUserToolsManager::SetFilter.md)|Especifica o filtro de arquivo que a caixa de diálogo de **Abrir arquivo** \([Classe de CFileDialog](../Topic/CFileDialog%20Class.md)\) usa no campo de **Comando** na guia de **Ferramentas** da caixa de diálogo de **Personalizar**.|  
  
## Comentários  
 Para inserir ferramentas do usuário em seu aplicativo, você deve:  
  
 1.  Permitir a um item de menu e uma identificação associado de comando para uma entrada de menu a ferramenta do usuário.  
  
 2.  Reservar uma identificação seqüencial de comando para cada ferramenta de usuário que um usuário pode definir em seu aplicativo.  
  
 3.  Chame o método de [CWinAppEx::EnableUserTools](../Topic/CWinAppEx::EnableUserTools.md) e forneça os seguintes parâmetros: identificação de comando de menu, primeiro identificação do ferramenta de linha de comando do usuário, e a identificação a mais recente da ferramenta de linha de comando do usuário  
  
 Deve haver apenas um objeto global de `CUserToolsManager` pelo aplicativo.  
  
 Para um exemplo de ferramentas do usuário, consulte o exemplo de VisualStudioDemo projeto.  
  
## Exemplo  
 O exemplo a seguir demonstra como recuperar uma referência a um objeto de `CUserToolsManager` e como criar novas ferramentas do usuário.  Este trecho de código é parte de [Exemplo de demonstração do Visual Studio](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#38](../../mfc/reference/codesnippet/CPP/cusertoolsmanager-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxusertoolsmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [Classe de CUserTool](../Topic/CUserTool%20Class.md)