---
title: "Classe de CKeyboardManager | Microsoft Docs"
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
  - "CKeyboardManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CKeyboardManager"
ms.assetid: 4809ece6-89df-4479-8b53-9bf476ee107b
caps.latest.revision: 33
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CKeyboardManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia tabelas de tecla de atalho para a janela de quadro chave e as janelas filho do quadro.  
  
## Sintaxe  
  
```  
class CKeyboardManager : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CKeyboardManager::CKeyboardManager](../Topic/CKeyboardManager::CKeyboardManager.md)|Constrói um objeto de `CKeyboardManager` .|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CKeyboardManager::CleanUp](../Topic/CKeyboardManager::CleanUp.md)|Limpa todas as tabelas de tecla de atalho.|  
|[CKeyboardManager::FindDefaultAccelerator](../Topic/CKeyboardManager::FindDefaultAccelerator.md)|Recupera a tecla de atalho padrão do comando e a janela especificados.|  
|[CKeyboardManager::IsKeyHandled](../Topic/CKeyboardManager::IsKeyHandled.md)|Determina se uma chave é tratada pela tabela de aceleração.|  
|[CKeyboardManager::IsKeyPrintable](../Topic/CKeyboardManager::IsKeyPrintable.md)|Indica se um caractere é imprimível.|  
|[CKeyboardManager::IsShowAllAccelerators](../Topic/CKeyboardManager::IsShowAllAccelerators.md)|Indica se os menus mostram todas as teclas de atalho para um comando ou somente a tecla de atalho padrão.|  
|[CKeyboardManager::LoadState](../Topic/CKeyboardManager::LoadState.md)|Carrega as tabelas de tecla de atalho do Registro do Windows.|  
|[CKeyboardManager::ResetAll](../Topic/CKeyboardManager::ResetAll.md)|Recarrega as tabelas de tecla de atalho de recurso do aplicativo.|  
|[CKeyboardManager::SaveState](../Topic/CKeyboardManager::SaveState.md)|Salva as tabelas de tecla de atalho do Registro do Windows.|  
|[CKeyboardManager::ShowAllAccelerators](../Topic/CKeyboardManager::ShowAllAccelerators.md)|Especifica se a estrutura exibe todas as teclas de atalho para todos os comandos, ou uma única tecla de atalho para cada comando.  Este método não afeta os comandos que só tem uma tecla de atalho associada.|  
|[CKeyboardManager::TranslateCharToUpper](../Topic/CKeyboardManager::TranslateCharToUpper.md)|Converte um caractere ao registro superior.|  
|[CKeyboardManager::UpdateAccelTable](../Topic/CKeyboardManager::UpdateAccelTable.md)|Atualiza uma tabela de tecla de atalho com uma nova tabela de tecla de atalho.|  
  
## Comentários  
 Membros de esta classe permite que você salvar e carregar tabelas de tecla de atalho do Registro do Windows, para usar um modelo para atualizar as tabelas de tecla de atalho, e para localizar a tecla de atalho padrão para um comando em uma janela do quadro.  Além de isso, o objeto de `CKeyboardManager` permite que você controle como teclas de atalho são exibidas para o usuário.  
  
 Você não deve criar um objeto de `CKeyboardManager` manualmente.  Será criado automaticamente pela estrutura do seu aplicativo.  Em o entanto, você deve chamar [CWinAppEx::InitKeyboardManager](../Topic/CWinAppEx::InitKeyboardManager.md) durante o processo de inicialização do aplicativo.  Para obter um ponteiro para o gerenciador de teclado para seu aplicativo, chame [CWinAppEx::GetKeyboardManager](../Topic/CWinAppEx::GetKeyboardManager.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como recuperar um ponteiro para um objeto de `CKeyboardManager` de uma classe de `CWinAppEx` , e como exibir todas as teclas de atalho associadas com os comandos de menu.  Este trecho de código é parte de [Custom de páginas](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_CustomPages#5](../../mfc/reference/codesnippet/CPP/ckeyboardmanager-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxkeyboardmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [CWinAppEx::InitKeyboardManager](../Topic/CWinAppEx::InitKeyboardManager.md)   
 [Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)