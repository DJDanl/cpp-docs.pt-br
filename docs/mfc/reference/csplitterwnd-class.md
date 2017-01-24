---
title: "Classe de CSplitterWnd | Microsoft Docs"
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
  - "CSplitterWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSplitterWnd"
  - "o windows dinâmicos separator"
  - "vários modos de exibição"
  - "separador do windows"
  - "o windows estáticos separator"
  - "modos de exibição, várias por quadro"
ms.assetid: fd0de258-6dbe-4552-9e47-a39de0471d51
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSplitterWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma janela de separador, que é uma janela que contém vários painéis.  
  
## Sintaxe  
  
```  
class CSplitterWnd : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSplitterWnd::CSplitterWnd](../Topic/CSplitterWnd::CSplitterWnd.md)|Chame para construir um objeto de `CSplitterWnd` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSplitterWnd::ActivateNext](../Topic/CSplitterWnd::ActivateNext.md)|Executa o painel seguir ou o comando anterior do painel.|  
|[CSplitterWnd::CanActivateNext](../Topic/CSplitterWnd::CanActivateNext.md)|Verifica se o painel seguir ou o comando anterior do painel são atualmente possível.|  
|[CSplitterWnd::Create](../Topic/CSplitterWnd::Create.md)|Chame para criar uma janela dinâmico do separador para e anexá\-la ao objeto de `CSplitterWnd` .|  
|[CSplitterWnd::CreateScrollBarCtrl](../Topic/CSplitterWnd::CreateScrollBarCtrl.md)|Cria um controle compartilhado de barra de rolagem.|  
|[CSplitterWnd::CreateStatic](../Topic/CSplitterWnd::CreateStatic.md)|Chame para criar uma janela estática do separador para e anexá\-la ao objeto de `CSplitterWnd` .|  
|[CSplitterWnd::CreateView](../Topic/CSplitterWnd::CreateView.md)|Chame para criar um painel em uma janela separator.|  
|[CSplitterWnd::DeleteColumn](../Topic/CSplitterWnd::DeleteColumn.md)|Exclui uma coluna da janela separator.|  
|[CSplitterWnd::DeleteRow](../Topic/CSplitterWnd::DeleteRow.md)|Excluir uma linha de janela separator.|  
|[CSplitterWnd::DeleteView](../Topic/CSplitterWnd::DeleteView.md)|Exclui uma exibição da janela separator.|  
|[CSplitterWnd::DoKeyboardSplit](../Topic/CSplitterWnd::DoKeyboardSplit.md)|Executa o comando split do teclado, geralmente “separação de janela.”|  
|[CSplitterWnd::DoScroll](../Topic/CSplitterWnd::DoScroll.md)|Performs sincronizou rolagem de janelas de divisão.|  
|[CSplitterWnd::DoScrollBy](../Topic/CSplitterWnd::DoScrollBy.md)|O rola racharam windows por um determinado número de pixels.|  
|[CSplitterWnd::GetActivePane](../Topic/CSplitterWnd::GetActivePane.md)|Determina o painel ativa de foco ou modo de exibição ativo do elemento.|  
|[CSplitterWnd::GetColumnCount](../Topic/CSplitterWnd::GetColumnCount.md)|Retorna o número da coluna atual do painel.|  
|[CSplitterWnd::GetColumnInfo](../Topic/CSplitterWnd::GetColumnInfo.md)|Retorna informações na coluna especificada.|  
|[CSplitterWnd::GetPane](../Topic/CSplitterWnd::GetPane.md)|Retorna o painel na linha e coluna especificada.|  
|[CSplitterWnd::GetRowCount](../Topic/CSplitterWnd::GetRowCount.md)|Retorna o número da linha atual do painel.|  
|[CSplitterWnd::GetRowInfo](../Topic/CSplitterWnd::GetRowInfo.md)|Retorna informações na linha especificada.|  
|[CSplitterWnd::GetScrollStyle](../Topic/CSplitterWnd::GetScrollStyle.md)|Retorna o estilo compartilhado de barra de rolagem.|  
|[CSplitterWnd::IdFromRowCol](../Topic/CSplitterWnd::IdFromRowCol.md)|Retorna a identificação da janela filho do painel na linha e coluna especificada.|  
|[CSplitterWnd::IsChildPane](../Topic/CSplitterWnd::IsChildPane.md)|Chame para determinar se a janela estiver em um painel filho em essa janela separator.|  
|[CSplitterWnd::IsTracking](../Topic/CSplitterWnd::IsTracking.md)|Determina se a barra separator está sendo movida atualmente.|  
|[CSplitterWnd::RecalcLayout](../Topic/CSplitterWnd::RecalcLayout.md)|Chame para redisplay a janela separator após definir o tamanho da linha ou coluna.|  
|[CSplitterWnd::SetActivePane](../Topic/CSplitterWnd::SetActivePane.md)|Define um painel para ser ativo do elemento.|  
|[CSplitterWnd::SetColumnInfo](../Topic/CSplitterWnd::SetColumnInfo.md)|Chame para definir informações da coluna especificada.|  
|[CSplitterWnd::SetRowInfo](../Topic/CSplitterWnd::SetRowInfo.md)|Chame para definir informações da linha especificada.|  
|[CSplitterWnd::SetScrollStyle](../Topic/CSplitterWnd::SetScrollStyle.md)|Especifica o novo estilo de barra de rolagem para suporte compartilhado de barra de rolagem da janela separator.|  
|[CSplitterWnd::SplitColumn](../Topic/CSplitterWnd::SplitColumn.md)|Indica onde uma janela de quadro chave divide verticalmente.|  
|[CSplitterWnd::SplitRow](../Topic/CSplitterWnd::SplitRow.md)|Indica onde uma janela de quadro chave divide horizontalmente.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSplitterWnd::OnDraw](../Topic/CSplitterWnd::OnDraw.md)|Chamado pela estrutura para desenhar a janela separator.|  
|[CSplitterWnd::OnDrawSplitter](../Topic/CSplitterWnd::OnDrawSplitter.md)|Processa uma imagem de uma janela de divisão.|  
|[CSplitterWnd::OnInvertTracker](../Topic/CSplitterWnd::OnInvertTracker.md)|Processa a imagem de uma janela de divisão para ser o mesmo tamanho e a forma como a janela do quadro.|  
  
## Comentários  
 Um painel é geralmente um objeto específico do aplicativo derivado de [CView](../Topic/CView%20Class.md), mas pode ser qualquer objeto de [CWnd](../Topic/CWnd%20Class.md) que possui a identificação da janela filho apropriado  
  
 Um objeto de `CSplitterWnd` geralmente é inserido em um objeto pai de [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou de [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) .  Crie um objeto de `CSplitterWnd` usando as seguintes etapas:  
  
1.  Inserir um variável de membro de `CSplitterWnd` do elemento pai.  
  
2.  Substitua a função de membro pai de [CFrameWnd::OnCreateClient](../Topic/CFrameWnd::OnCreateClient.md) do quadro.  
  
3.  De dentro de `OnCreateClient`substituído, chame a função de membro de [Criar](../Topic/CSplitterWnd::Create.md) ou de [CreateStatic](../Topic/CSplitterWnd::CreateStatic.md) de `CSplitterWnd`.  
  
 Chame a função de membro de **Criar** para criar uma janela dinâmico separator.  Uma janela dinâmico do separador é normalmente usado para criar e rolar um número de painéis individuais, ou exibições, do mesmo documento.  a estrutura cria automaticamente um painel inicial para o separador; na estrutura, cria redimensiona, e libera os painéis adicionais enquanto o usuário funciona controles window separator.  
  
 Quando você chama **Criar**, você especifica uma altura e largura da coluna mínimas da linha que determina quando os painéis são muito pequenos ser exibidos inteiramente.  Depois de você chamar **Criar**, você pode ajustar esses mínimos chamando as funções de membro de [SetColumnInfo](../Topic/CSplitterWnd::SetColumnInfo.md) e de [SetRowInfo](../Topic/CSplitterWnd::SetRowInfo.md) .  
  
 Também use as funções de membro de `SetColumnInfo` e de `SetRowInfo` para definir uma largura “” ideal para uma coluna e altura “” ideal para uma linha.  Quando a estrutura exibe uma janela de separador, exibe o primeiro quadro pai, na janela separator.  A estrutura apresenta os painéis nas colunas e linhas de acordo com suas dimensões ideais, trabalhando superior esquerdo do canto inferior direito da área cliente da janela separator.  
  
 Todos os painéis em uma janela dinâmico separator deve ser a mesma classe.  Os aplicativos familiares que suportam o windows dinâmicos separator incluem o Microsoft Word e Microsoft Excel.  
  
 Use a função de membro de `CreateStatic` para criar uma janela estático separator.  O usuário pode alterar apenas o tamanho dos painéis em uma janela estática do separador, não o número ou ordem.  
  
 Você deve especificamente criar os painéis estáticos do separador quando você cria o separador estático.  Certifique\-se de que você criar todos os painéis antes que a função de membro pai de `OnCreateClient` do quadro, retorna ou estrutura não exibirá a janela corretamente.  
  
 A função de membro de `CreateStatic` inicializa automaticamente um separador estática com uma linha de altura e largura da coluna mínimas de 0.  Depois de você chamar **Criar**, ajuste esses mínimos chamando as funções de membro de [SetColumnInfo](../Topic/CSplitterWnd::SetColumnInfo.md) e de [SetRowInfo](../Topic/CSplitterWnd::SetRowInfo.md) .  Também use `SetColumnInfo` e `SetRowInfo` depois de você chamar `CreateStatic` para indicar dimensões ideais desejadas de painel.  
  
 Os painéis individuais de um separador estático geralmente pertencem às classes diferentes.  Para exemplos do windows estáticos do separador, consulte o editor de gráficos e o gerenciador de arquivos do windows.  
  
 Uma janela de separador suporta barras de rolagem especiais \(independentemente das barras de rolagem que os painéis podem ter\).  Essas barras de rolagem são filhos do objeto de `CSplitterWnd` e são compartilhados com os painéis.  
  
 Você cria essas barras de rolagem especiais quando você cria a janela separator.  Por exemplo, `CSplitterWnd` que tem uma linha, duas colunas, e estilo de **WS\_VSCROLL** exibirão uma barra de rolagem vertical que é compartilhada por dois painéis.  Quando o usuário move a barra de rolagem, as mensagens de `WM_VSCROLL` são enviadas para ambos os painéis.  Quando os painéis definem a posição da barra de rolagem, a barra de rolagem compartilhado está definida.  
  
 Para obter mais informações sobre windows do separador, consulte:  
  
-   [Observe técnica 29](../../mfc/tn029-splitter-windows.md)  
  
-   Artigo de Base de Dados de Conhecimento Q262024: HOWTO: use CPropertySheet como um filho de CSplitterWnd  
  
 Para obter mais informações sobre como criar janelas dinâmicos de separador, consulte:  
  
-   Exemplo [garrancho](../../top/visual-cpp-samples.md)MFC  
  
-   Exemplo [VIEWEX](../../top/visual-cpp-samples.md)MFC.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CSplitterWnd`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [Exemplo VIEWEX MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)