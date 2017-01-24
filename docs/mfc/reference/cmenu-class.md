---
title: "Classe de CMenu | Microsoft Docs"
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
  - "CMenu"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMenu"
  - "HMENU"
  - "menus, classe base"
  - "menus, classe"
  - "menus, criando"
  - "menus, gerenciando"
ms.assetid: 40cacfdc-d45c-4ec7-bf28-991c72812499
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMenu
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma encapsulamento do windows `HMENU`.  
  
## Sintaxe  
  
```  
class CMenu : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMenu::CMenu](../Topic/CMenu::CMenu.md)|Constrói um objeto de `CMenu` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMenu::AppendMenu](../Topic/CMenu::AppendMenu.md)|Acrescenta um novo item ao final do menu.|  
|[CMenu::Attach](../Topic/CMenu::Attach.md)|Anexa um tratador do menu do windows a um objeto de `CMenu` .|  
|[CMenu::CheckMenuItem](../Topic/CMenu::CheckMenuItem.md)|Coloca uma marca de seleção ao lado de ou remover uma marca de seleção de um item de menu no menu pop\-up.|  
|[CMenu::CheckMenuRadioItem](../Topic/CMenu::CheckMenuRadioItem.md)|Coloque um botão de opção ao lado de um item de menu e remove o botão de opção de quaisquer outros itens de menu no grupo.|  
|[CMenu::CreateMenu](../Topic/CMenu::CreateMenu.md)|Criar um menu em branco e anexá\-la a um objeto de `CMenu` .|  
|[CMenu::CreatePopupMenu](../Topic/CMenu::CreatePopupMenu.md)|Criar um menu pop\-up em branco e anexá\-la a um objeto de `CMenu` .|  
|[CMenu::DeleteMenu](../Topic/CMenu::DeleteMenu.md)|Excluir um item de menu especificado.  Se o item de menu possui um menu pop\-up associado for, a alça o menu pop\-up e libera memória usada por ele.|  
|[CMenu::DeleteTempMap](../Topic/CMenu::DeleteTempMap.md)|Exclui todos os objetos temporários de `CMenu` criados pela função de membro de `FromHandle` .|  
|[CMenu::DestroyMenu](../Topic/CMenu::DestroyMenu.md)|O menu for anexado a um objeto de qualquer `CMenu` e libera a memória que ocupa o menu.|  
|[CMenu::Detach](../Topic/CMenu::Detach.md)|Dispara um identificador do menu do windows de um objeto de `CMenu` e retorna o identificador.|  
|[CMenu::DrawItem](../Topic/CMenu::DrawItem.md)|Chamado pela estrutura quando uma aparência visual de um menu proprietário desenhado alterar.|  
|[CMenu::EnableMenuItem](../Topic/CMenu::EnableMenuItem.md)|Habilita, desativa ou escurece \(cinza\) um item de menu.|  
|[CMenu::FromHandle](../Topic/CMenu::FromHandle.md)|Retorna um ponteiro para um objeto de `CMenu` dado um identificador do menu do windows.|  
|[CMenu::GetDefaultItem](../Topic/CMenu::GetDefaultItem.md)|Determina o item de menu padrão no menu especificado.|  
|[CMenu::GetMenuContextHelpId](../Topic/CMenu::GetMenuContextHelpId.md)|Recupera a identificação de contexto da ajuda associado com o menu.|  
|[CMenu::GetMenuInfo](../Topic/CMenu::GetMenuInfo.md)|Recupera informações em um menu específico.|  
|[CMenu::GetMenuItemCount](../Topic/CMenu::GetMenuItemCount.md)|Determina o número de itens em um menu pop\-up ou de nível superior.|  
|[CMenu::GetMenuItemID](../Topic/CMenu::GetMenuItemID.md)|Obtém o identificador do item de menu para um item de menu na posição especificada.|  
|[CMenu::GetMenuItemInfo](../Topic/CMenu::GetMenuItemInfo.md)|Recupera informações sobre um item de menu.|  
|[CMenu::GetMenuState](../Topic/CMenu::GetMenuState.md)|Retorna o status do item de menu especificado ou o número de itens em um menu pop\-up.|  
|[CMenu::GetMenuString](../Topic/CMenu::GetMenuString.md)|Recupera o rótulo do item de menu especificado.|  
|[CMenu::GetSafeHmenu](../Topic/CMenu::GetSafeHmenu.md)|Retorna `m_hMenu` empacotado por esse objeto de `CMenu` .|  
|[CMenu::GetSubMenu](../Topic/CMenu::GetSubMenu.md)|Recupera um ponteiro para um menu pop\-up.|  
|[CMenu::InsertMenu](../Topic/CMenu::InsertMenu.md)|Insere um novo item de menu na posição especificada, movendo outros itens abaixo do menu.|  
|[CMenu::InsertMenuItem](../Topic/CMenu::InsertMenuItem.md)|Insere um novo item de menu na posição especificada em um menu.|  
|[CMenu::LoadMenu](../Topic/CMenu::LoadMenu.md)|Carrega um recurso do menu do arquivo executável e anexá\-la a um objeto de `CMenu` .|  
|[CMenu::LoadMenuIndirect](../Topic/CMenu::LoadMenuIndirect.md)|Carrega um menu de um modelo de menu na memória e anexá\-la a um objeto de `CMenu` .|  
|[CMenu::MeasureItem](../Topic/CMenu::MeasureItem.md)|Chamado pela estrutura para determinar dimensões de menu quando um menu proprietário desenhado é criado.|  
|[CMenu::ModifyMenu](../Topic/CMenu::ModifyMenu.md)|Modifique um item de menu existente na posição especificada.|  
|[CMenu::RemoveMenu](../Topic/CMenu::RemoveMenu.md)|Excluir um item de menu com um menu pop\-up associado de menu especificado.|  
|[CMenu::SetDefaultItem](../Topic/CMenu::SetDefaultItem.md)|Define o item de menu padrão para o menu especificado.|  
|[CMenu::SetMenuContextHelpId](../Topic/CMenu::SetMenuContextHelpId.md)|Define a identificação de contexto de ajuda a ser associado com o menu.|  
|[CMenu::SetMenuInfo](../Topic/CMenu::SetMenuInfo.md)|Define informações em um menu específico.|  
|[CMenu::SetMenuItemBitmaps](../Topic/CMenu::SetMenuItemBitmaps.md)|Associa bitmaps especificados de sinal com um item de menu.|  
|[CMenu::SetMenuItemInfo](../Topic/CMenu::SetMenuItemInfo.md)|Alterar informações sobre um item de menu.|  
|[CMenu::TrackPopupMenu](../Topic/CMenu::TrackPopupMenu.md)|Exibe um menu pop\-up flutuante no local especificado e controla a seleção de itens de menu pop\-up.|  
|[CMenu::TrackPopupMenuEx](../Topic/CMenu::TrackPopupMenuEx.md)|Exibe um menu pop\-up flutuante no local especificado e controla a seleção de itens de menu pop\-up.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMenu::operator HMENU](../Topic/CMenu::operator%20HMENU.md)|Recupera a alça de objeto do menu.|  
|[CMenu::operator\! \=](../Topic/CMenu::operator%20!=.md)|Determina se dois objetos de menu não são iguais.|  
|[\=\= De CMenu::operator](../Topic/CMenu::operator%20==.md)|Determina se dois objetos de menu são iguais.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMenu::m\_hMenu](../Topic/CMenu::m_hMenu.md)|Especifica o identificador para o menu do windows anexado ao objeto de `CMenu` .|  
  
## Comentários  
 Fornece funções de membro para criar, acompanhar, atualizar, e destruir um menu.  
  
 Crie um objeto de `CMenu` no quadro de pilha como um local, então chama as funções de membro de `CMenu` quando necessário para manipular o novo menu.  Em seguida, chame [CWnd::SetMenu](../Topic/CWnd::SetMenu.md) para definir o menu para uma janela, tiver usado imediatamente por uma chamada para a função de membro de [Desanexar](../Topic/CMenu::Detach.md) do objeto de `CMenu` .  A função de membro de `CWnd::SetMenu` define o menu da janela para o novo menu, faz com que a janela para ser redesenhado para refletir a alteração no menu, e também passa a propriedade de menu para a janela.  A chamada a **Desanexar** dispara `HMENU` do objeto de `CMenu` , de modo que quando a variável local de `CMenu` passa para fora do escopo, o destrutor do objeto de `CMenu` não tente destruir um menu que não possui.  O próprio menu é destruído automaticamente quando a janela é destruída.  
  
 Você pode usar a função de membro de [LoadMenuIndirect](../Topic/CMenu::LoadMenuIndirect.md) para criar um menu de um modelo na memória, mas um menu criado de um recurso por uma chamada a [LoadMenu](../Topic/CMenu::LoadMenu.md) é mantido mais facilmente, e o próprio recurso de menu pode ser criado e modificado pelo editor do menu.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CMenu`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Exemplo CTRLTEST MFC](../../top/visual-cpp-samples.md)   
 [Exemplo DYNAMENU MFC](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)