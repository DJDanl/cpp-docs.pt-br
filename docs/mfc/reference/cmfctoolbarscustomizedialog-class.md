---
title: "Classe de CMFCToolBarsCustomizeDialog | Microsoft Docs"
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
  - "CMFCToolBarsCustomizeDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarsCustomizeDialog"
ms.assetid: 78e2cddd-4f13-4097-afc3-1ad646a113f1
caps.latest.revision: 28
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarsCustomizeDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma caixa de diálogo sem\-modo da guia \([Classe de CPropertySheet](../../mfc/reference/cpropertysheet-class.md)\) que permite ao usuário para personalizar barras de ferramentas, os menus, os atalhos de teclado, as ferramentas definidos pelo usuário, e o estilo visual em um aplicativo.  Normalmente, o usuário acessa esta caixa de diálogo selecionando **Personalizar** do menu de **Ferramentas** .  
  
 a caixa de diálogo de **Personalizar** tem seis guias: **Comandos**, **Barras de Ferramentas**, **Ferramentas**, **Teclado**, **Menu**, e **Opções**.  
  
## Sintaxe  
  
```  
class CMFCToolBarsCustomizeDialog : public CPropertySheet  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog](../Topic/CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog.md)|Constrói um objeto de `CMFCToolBarsCustomizeDialog` .|  
|`CMFCToolBarsCustomizeDialog::~CMFCToolBarsCustomizeDialog`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddButton](../Topic/CMFCToolBarsCustomizeDialog::AddButton.md)|Insere um botão da barra de ferramentas na lista de comandos na página de **Comandos**|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddMenu](../Topic/CMFCToolBarsCustomizeDialog::AddMenu.md)|Carrega um menu de recursos e chama [CMFCToolBarsCustomizeDialog::AddMenuCommands](../Topic/CMFCToolBarsCustomizeDialog::AddMenuCommands.md) para adicionar menu que à lista de comandos na página de **Comandos** .|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddMenuCommands](../Topic/CMFCToolBarsCustomizeDialog::AddMenuCommands.md)|Carrega um menu de recursos e chama [CMFCToolBarsCustomizeDialog::AddMenuCommands](../Topic/CMFCToolBarsCustomizeDialog::AddMenuCommands.md) para adicionar menu que à lista de comandos na página de **Comandos** .|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddToolBar](../Topic/CMFCToolBarsCustomizeDialog::AddToolBar.md)|Carrega uma barra de ferramentas de recursos.  Em seguida, porque cada comando no menu chama o método de [CMFCToolBarsCustomizeDialog::AddButton](../Topic/CMFCToolBarsCustomizeDialog::AddButton.md) para inserir um botão na lista de comandos na página de **Comandos** sob a categoria especificada.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::Create](../Topic/CMFCToolBarsCustomizeDialog::Create.md)|Exibe a caixa de diálogo de **Personalização** .|  
|`CMFCToolBarsCustomizeDialog::EnableTools`|Reservado para uso futuro.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars](../Topic/CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars.md)|Habilita ou desabilita a criação de novas barras de ferramentas usando a caixa de diálogo de **Personalizar** .|  
|[CMFCToolBarsCustomizeDialog::FillAllCommandsList](../Topic/CMFCToolBarsCustomizeDialog::FillAllCommandsList.md)|Preenche o objeto fornecido de `CListBox` com comandos na categoria de **Todos os Comandos** .|  
|[CMFCToolBarsCustomizeDialog::FillCategoriesComboBox](../Topic/CMFCToolBarsCustomizeDialog::FillCategoriesComboBox.md)|Preenche o objeto fornecido de `CComboBox` com o nome de cada categoria de comando na caixa de diálogo de **Personalizar** .|  
|[CMFCToolBarsCustomizeDialog::FillCategoriesListBox](../Topic/CMFCToolBarsCustomizeDialog::FillCategoriesListBox.md)|Preenche o objeto fornecido de `CListBox` com o nome de cada categoria de comando na caixa de diálogo de **Personalizar** .|  
|[CMFCToolBarsCustomizeDialog::GetCommandName](../Topic/CMFCToolBarsCustomizeDialog::GetCommandName.md)|Retorna o nome que é associado com a identificação determinada de comando|  
|[CMFCToolBarsCustomizeDialog::GetCountInCategory](../Topic/CMFCToolBarsCustomizeDialog::GetCountInCategory.md)|Retorna o número de itens na lista fornecida que têm um rótulo determinada de texto.|  
|[CMFCToolBarsCustomizeDialog::GetFlags](../Topic/CMFCToolBarsCustomizeDialog::GetFlags.md)|Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.|  
|`CMFCToolBarsCustomizeDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage](../Topic/CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage.md)|Inicia um editor de imagem para que um usuário pode personalizar um ícone de botão da barra de ferramentas ou item de menu.|  
|[CMFCToolBarsCustomizeDialog::OnInitDialog](../Topic/CMFCToolBarsCustomizeDialog::OnInitDialog.md)|Substituições para aumentar a inicialização da folha de propriedades.  Overrides \( [CPropertySheet::OnInitDialog](../Topic/CPropertySheet::OnInitDialog.md).\)|  
|[CMFCToolBarsCustomizeDialog::PostNcDestroy](../Topic/CMFCToolBarsCustomizeDialog::PostNcDestroy.md)|Chamado pela estrutura após a janela foi destruída.  Overrides \( `CPropertySheet::PostNcDestroy`.\)|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::RemoveButton](../Topic/CMFCToolBarsCustomizeDialog::RemoveButton.md)|Remove o botão com a identificação especificado de comando de categoria especificada, ou de todas as categorias.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::RenameCategory](../Topic/CMFCToolBarsCustomizeDialog::RenameCategory.md)|Renomear uma categoria na caixa de lista de categorias na guia de **Comandos** .|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::ReplaceButton](../Topic/CMFCToolBarsCustomizeDialog::ReplaceButton.md)|Substitui um botão na lista de comandos na guia de **Comandos** com um novo objeto botão da barra de ferramentas.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::SetUserCategory](../Topic/CMFCToolBarsCustomizeDialog::SetUserCategory.md)|Adiciona uma categoria para a lista de categorias que serão exibidas na guia de **Comandos** .|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::CheckToolsValidity](../Topic/CMFCToolBarsCustomizeDialog::CheckToolsValidity.md)|Chamado pela estrutura para determinar se a lista de ferramentas definidos pelo usuário é válida.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnAfterChangeTool](../Topic/CMFCToolBarsCustomizeDialog::OnAfterChangeTool.md)|Chamado pela estrutura quando as propriedades de uma alteração definido pelo usuário de ferramenta.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnAssignKey](../Topic/CMFCToolBarsCustomizeDialog::OnAssignKey.md)|Determina se um atalho de teclado especificado pode ser atribuído a uma ação.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnBeforeChangeTool](../Topic/CMFCToolBarsCustomizeDialog::OnBeforeChangeTool.md)|Determina se uma ferramenta definido pelo usuário pode ser alterada.|  
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnInitToolsPage](../Topic/CMFCToolBarsCustomizeDialog::OnInitToolsPage.md)|Chamado pela estrutura quando o usuário escolher a guia de **Ferramentas** for solicitado.|  
  
## Comentários  
 Para exibir a caixa de diálogo de **Personalizar** , crie um objeto de `CMFCToolBarsCustomizeDialog` e chame o método de [CMFCToolBarsCustomizeDialog::Create](../Topic/CMFCToolBarsCustomizeDialog::Create.md) .  
  
 Quando a caixa de diálogo de **Personalizar** estiver ativo, o aplicativo funciona em um modo especial que limitam o usuário para tarefas de personalização.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCToolBarsCustomizeDialog` .  O exemplo mostra como substituir um botão da barra de ferramentas na caixa de listagem de comandos na página de **Comandos** , permitir a criação de novas barras de ferramentas usando a caixa de diálogo de **Personalizar** , e exibir a caixa de diálogo de **Personalização** .  Este trecho de código é parte de [Exemplo de demonstração de IE](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo#4](../../mfc/reference/codesnippet/CPP/cmfctoolbarscustomizedialog-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CPropertySheet](../../mfc/reference/cpropertysheet-class.md)  
  
 [CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxToolBarsCustomizeDialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CPropertySheet](../../mfc/reference/cpropertysheet-class.md)