---
title: "Classe de CVSListBox | Microsoft Docs"
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
  - "CVSListBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CVSListBox"
  - "Método de CVSListBox::PreTranslateMessage"
ms.assetid: c79be7b4-46ed-4af8-a41e-68962782d8ef
caps.latest.revision: 30
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CVSListBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CVSListBox` suporta um controle de lista editável.  
  
## Sintaxe  
  
```  
class CVSListBox : public CVSListBoxBase  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CVSListBox::CVSListBox](../Topic/CVSListBox::CVSListBox.md)|Constrói um objeto de `CVSListBox` .|  
|`CVSListBox::~CVSListBox`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CVSListBox::AddItem](../Topic/CVSListBox::AddItem.md)|Adiciona uma cadeia de caracteres em um controle de lista.  Overrides \( `CVSListBoxBase::AddItem`.\)|  
|[CVSListBox::EditItem](../Topic/CVSListBox::EditItem.md)|Iniciar uma operação de edição em texto de um controle de item de lista.  Overrides \( `CVSListBoxBase::EditItem`.\)|  
|[CVSListBox::GetCount](../Topic/CVSListBox::GetCount.md)|Retorna o número de cadeias de caracteres em um controle de lista editável.  Overrides \( `CVSListBoxBase::GetCount`.\)|  
|[CVSListBox::GetItemData](../Topic/CVSListBox::GetItemData.md)|Recupera um valor de 32 bits específico do aplicativo que está associado com um item de lista editável do controle.  Overrides \( `CVSListBoxBase::GetItemData`.\)|  
|[CVSListBox::GetItemText](../Topic/CVSListBox::GetItemText.md)|Recupera o texto de um item editável do controle de lista.  Overrides \( `CVSListBoxBase::GetItemText`.\)|  
|[CVSListBox::GetSelItem](../Topic/CVSListBox::GetSelItem.md)|Retorna o índice com base zero do item atualmente selecionado em um controle de lista editável.  Overrides \( `CVSListBoxBase::GetSelItem`.\)|  
|`CVSListBox::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Para mais informações e sintaxe do método, consulte [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).  Overrides \( `CVSListBoxBase::PreTranslateMessage`.\)|  
|[CVSListBox::RemoveItem](../Topic/CVSListBox::RemoveItem.md)|Remove um item de um controle de lista editável.  Overrides \( `CVSListBoxBase::RemoveItem`.\)|  
|[CVSListBox::SelectItem](../Topic/CVSListBox::SelectItem.md)|Seleciona uma cadeia de caracteres editável do controle de lista.  Overrides \( `CVSListBoxBase::SelectItem`.\)|  
|[CVSListBox::SetItemData](../Topic/CVSListBox::SetItemData.md)|Associa um valor de 32 bits específico do aplicativo com um item de lista editável do controle.  Overrides \( `CVSListBoxBase::SetItemData`.\)|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CVSListBox::GetListHwnd](../Topic/CVSListBox::GetListHwnd.md)|Retorna o identificador para o controle inserido atual de exibição de lista.|  
  
## Comentários  
 A classe de `CVSListBox` fornece um conjunto de botões de edição que permitem ao usuário para criar, modificar, excluir, ou reordenar os itens em um controle de lista.  
  
 A seguir está uma imagem do controle de lista editável.  A segunda entrada de lista, que é denominada “Item2”, editando é selecionada.  
  
 ![Controle CVSListBox](../../mfc/reference/media/cvslistbox.png "cvslistbox")  
  
 Se você usar o editor de recursos para adicionar um controle de lista editável, observe que o painel de **Caixa de Ferramentas** do editor não fornece um controle editável predefinido da lista.  Em vez de isso, adicione um controle estático como o controle de **Caixa de Grupo** .  A estrutura usa o controle estático como um espaço reservado para especificar o tamanho e a posição do controle de lista editável.  
  
 Para usar uma lista editável controle em um modelo da caixa de diálogo, declare uma variável de `CVSListBox` em sua classe da caixa de diálogo.  Suporte para trocar dados entre a variável e o controle, defina uma macro entrada de `DDX_Control` no método de `DoDataExchange` da caixa de diálogo.  Por padrão, o controle editável de lista é criado sem os botões de edição.  Use o método herdado de [CVSListBoxBase::SetStandardButtons](http://msdn.microsoft.com/pt-br/129e530f-97e9-42eb-b128-371c2a5686ba) para ativar os botões de edição.  
  
 Para obter mais informações, consulte o diretório exemplos, o exemplo de `New Controls` , arquivos de Page3.cpp e de Page3.h.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CStatic](../Topic/CStatic%20Class.md)  
  
 `CVSListBoxBase`  
  
 [CVSListBox](../../mfc/reference/cvslistbox-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxvslistbox.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)