---
title: "Classe de COccManager | Microsoft Docs"
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
  - "COccManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Recipiente de controles ActiveX [C++], controle ao site"
  - "Classe de CNoTrackObject"
  - "Classe de COccManager"
  - "controles personalizados [MFC], sites"
ms.assetid: 7d47aeed-d1ab-48e3-b4cf-d429718e370a
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COccManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia vários sites de controle personalizado; implementado por `COleControlContainer` e por objetos de `COleControlSite` .  
  
## Sintaxe  
  
```  
class COccManager : public CNoTrackObject  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COccManager::CreateContainer](../Topic/COccManager::CreateContainer.md)|Cria um objeto de **COleContainer** .|  
|[COccManager::CreateDlgControls](../Topic/COccManager::CreateDlgControls.md)|Cria os controles ActiveX, hospedados pelo objeto associado de `COleContainer` .|  
|[COccManager::CreateSite](../Topic/COccManager::CreateSite.md)|Cria um objeto de `COleClientSite` .|  
|[COccManager::GetDefBtnCode](../Topic/COccManager::GetDefBtnCode.md)|Recupera o código do botão padrão.|  
|[COccManager::IsDialogMessage](../Topic/COccManager::IsDialogMessage.md)|Determina o destino de uma mensagem da caixa de diálogo.|  
|[COccManager::IsLabelControl](../Topic/COccManager::IsLabelControl.md)|Determina se o controle é especificado um controle do rótulo.|  
|[COccManager::IsMatchingMnemonic](../Topic/COccManager::IsMatchingMnemonic.md)|Determina se a mnemônicos atual corresponde a mnemônicos de controle específico.|  
|[COccManager::OnEvent](../Topic/COccManager::OnEvent.md)|Tentativas de manipular o evento especificado.|  
|[COccManager::PostCreateDialog](../Topic/COccManager::PostCreateDialog.md)|Libera os recursos alocados durante a criação da caixa de diálogo.|  
|[COccManager::PreCreateDialog](../Topic/COccManager::PreCreateDialog.md)|Processa um modelo da caixa de diálogo para controles ActiveX.|  
|[COccManager::SetDefaultButton](../Topic/COccManager::SetDefaultButton.md)|\/desativar Ativa o estado padrão de controle específico.|  
|[COccManager::SplitDialogTemplate](../Topic/COccManager::SplitDialogTemplate.md)|Separa todos os controles ActiveX existentes dos controles comuns no modelo especificado da caixa de diálogo.|  
  
## Comentários  
 A classe base, **CNoTrackObject**, é uma classe base indocumentado \(localizada em AFXTLS.H\).  Projetado para o uso da estrutura MFC, classes derivadas de classes de **CNoTrackObject** estão isentas de detecção de vazamento de memória.  Não é recomendável que você deriva diretamente de **CNoTrackObject**.  
  
## Hierarquia de herança  
 `CNoTrackObject`  
  
 `COccManager`  
  
## Requisitos  
 **Cabeçalho:** afxocc.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleControlSite](../../mfc/reference/colecontrolsite-class.md)   
 [Classe de COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)