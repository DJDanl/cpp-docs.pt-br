---
title: Classe CSplitterWnd | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSplitterWnd
- AFXEXT/CSplitterWnd
- AFXEXT/CSplitterWnd::CSplitterWnd
- AFXEXT/CSplitterWnd::ActivateNext
- AFXEXT/CSplitterWnd::CanActivateNext
- AFXEXT/CSplitterWnd::Create
- AFXEXT/CSplitterWnd::CreateScrollBarCtrl
- AFXEXT/CSplitterWnd::CreateStatic
- AFXEXT/CSplitterWnd::CreateView
- AFXEXT/CSplitterWnd::DeleteColumn
- AFXEXT/CSplitterWnd::DeleteRow
- AFXEXT/CSplitterWnd::DeleteView
- AFXEXT/CSplitterWnd::DoKeyboardSplit
- AFXEXT/CSplitterWnd::DoScroll
- AFXEXT/CSplitterWnd::DoScrollBy
- AFXEXT/CSplitterWnd::GetActivePane
- AFXEXT/CSplitterWnd::GetColumnCount
- AFXEXT/CSplitterWnd::GetColumnInfo
- AFXEXT/CSplitterWnd::GetPane
- AFXEXT/CSplitterWnd::GetRowCount
- AFXEXT/CSplitterWnd::GetRowInfo
- AFXEXT/CSplitterWnd::GetScrollStyle
- AFXEXT/CSplitterWnd::IdFromRowCol
- AFXEXT/CSplitterWnd::IsChildPane
- AFXEXT/CSplitterWnd::IsTracking
- AFXEXT/CSplitterWnd::RecalcLayout
- AFXEXT/CSplitterWnd::SetActivePane
- AFXEXT/CSplitterWnd::SetColumnInfo
- AFXEXT/CSplitterWnd::SetRowInfo
- AFXEXT/CSplitterWnd::SetScrollStyle
- AFXEXT/CSplitterWnd::SplitColumn
- AFXEXT/CSplitterWnd::SplitRow
- AFXEXT/CSplitterWnd::OnDraw
- AFXEXT/CSplitterWnd::OnDrawSplitter
- AFXEXT/CSplitterWnd::OnInvertTracker
dev_langs:
- C++
helpviewer_keywords:
- static splitter windows
- multiple views
- splitter windows
- views, multiple per frame
- dynamic splitter windows
- CSplitterWnd class
ms.assetid: fd0de258-6dbe-4552-9e47-a39de0471d51
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: d015aa604c5394ccbe8c7471b70c84763cc00a5b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csplitterwnd-class"></a>Classe CSplitterWnd
Fornece a funcionalidade de uma janela separadora, que é uma janela que contém vários painéis.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSplitterWnd : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWnd::CSplitterWnd](#csplitterwnd)|Chamada para construir uma `CSplitterWnd` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWnd::ActivateNext](#activatenext)|Executa o comando próximo painel ou painel anterior.|  
|[CSplitterWnd::CanActivateNext](#canactivatenext)|Verifica se o comando próximo painel ou painel anterior é possível neste momento.|  
|[CSplitterWnd::Create](#create)|Chamada para criar uma janela separadora dinâmica e anexá-lo a `CSplitterWnd` objeto.|  
|[CSplitterWnd::CreateScrollBarCtrl](#createscrollbarctrl)|Cria um controle de barra de rolagem compartilhado.|  
|[CSplitterWnd::CreateStatic](#createstatic)|Chamada para criar uma janela de separador estático e anexá-lo a `CSplitterWnd` objeto.|  
|[CSplitterWnd::CreateView](#createview)|Chamada para criar um painel em uma janela separadora.|  
|[CSplitterWnd::DeleteColumn](#deletecolumn)|Exclui uma coluna da janela separadora.|  
|[CSplitterWnd::DeleteRow](#deleterow)|Exclui uma linha da janela separadora.|  
|[CSplitterWnd::DeleteView](#deleteview)|Exclui uma exibição da janela separadora.|  
|[CSplitterWnd::DoKeyboardSplit](#dokeyboardsplit)|Executa o teclado dividir o comando, geralmente "divisão da janela".|  
|[CSplitterWnd::DoScroll](#doscroll)|Executa a rolagem sincronizada de janelas separadoras.|  
|[CSplitterWnd::DoScrollBy](#doscrollby)|Rola pelas janelas separadoras por um determinado número de pixels.|  
|[CSplitterWnd::GetActivePane](#getactivepane)|Determina o painel ativo do foco ou da exibição ativa no quadro.|  
|[CSplitterWnd::GetColumnCount](#getcolumncount)|Retorna o número de colunas do painel atual.|  
|[CSplitterWnd::GetColumnInfo](#getcolumninfo)|Retorna informações sobre a coluna especificada.|  
|[CSplitterWnd::GetPane](#getpane)|Retorna o painel na linha e coluna especificadas.|  
|[CSplitterWnd::GetRowCount](#getrowcount)|Retorna a contagem de linhas do painel atual.|  
|[CSplitterWnd::GetRowInfo](#getrowinfo)|Retorna informações sobre a linha especificada.|  
|[CSplitterWnd::GetScrollStyle](#getscrollstyle)|Retorna o estilo de barra de rolagem compartilhado.|  
|[CSplitterWnd::IdFromRowCol](#idfromrowcol)|Retorna o filho janela ID do painel na linha e coluna especificadas.|  
|[CSplitterWnd::IsChildPane](#ischildpane)|Chamada para determinar se a janela está atualmente um painel filho desta janela divisor.|  
|[CSplitterWnd::IsTracking](#istracking)|Determina se barra divisória atualmente está sendo movida.|  
|[CSplitterWnd::RecalcLayout](#recalclayout)|Chamada para reexibir janela separadora depois de ajustar o tamanho de linha ou coluna.|  
|[CSplitterWnd::SetActivePane](#setactivepane)|Define um painel para ser o ativo no quadro.|  
|[CSplitterWnd::SetColumnInfo](#setcolumninfo)|Chamada para definir as informações de coluna especificada.|  
|[CSplitterWnd::SetRowInfo](#setrowinfo)|Chamada para definir as informações de linha especificado.|  
|[CSplitterWnd::SetScrollStyle](#setscrollstyle)|Especifica que o novo estilo de barra de rolagem da janela de separador compartilhada suporte a barra de rolagem.|  
|[CSplitterWnd::SplitColumn](#splitcolumn)|Indica onde uma janela do quadro se divide verticalmente.|  
|[CSplitterWnd::SplitRow](#splitrow)|Indica onde uma janela do quadro se divide horizontalmente.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWnd::OnDraw](#ondraw)|Chamado pela estrutura para desenhar a janela separadora.|  
|[CSplitterWnd::OnDrawSplitter](#ondrawsplitter)|Renderiza uma imagem de uma janela dividida.|  
|[CSplitterWnd::OnInvertTracker](#oninverttracker)|Processa a imagem de uma janela dividida para ser o mesmo tamanho e forma da janela do quadro.|  
  
## <a name="remarks"></a>Comentários  
 Um painel é geralmente um objeto específico do aplicativo derivado de [CView](../../mfc/reference/cview-class.md), mas pode ser qualquer [CWnd](../../mfc/reference/cwnd-class.md) objeto que tem a ID da janela filho apropriados.  
  
 A `CSplitterWnd` objeto normalmente é incorporado em um pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto. Criar um `CSplitterWnd` objeto usando as seguintes etapas:  
  
1.  Inserir uma `CSplitterWnd` variável de membro no quadro principal.  
  
2.  Substituição do quadro pai [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.  
  
3.  De dentro de substituído `OnCreateClient`, chame o [criar](#create) ou [CreateStatic](#createstatic) função de membro `CSplitterWnd`.  
  
 Chamar o **criar** função de membro para criar uma janela separadora dinâmica. Uma janela separadora dinâmica normalmente é usada para criar e rolar um número de painéis individuais ou exibições do mesmo documento. O framework cria automaticamente um painel inicial para o divisor; em seguida, a estrutura cria, redimensiona e descarta painéis adicionais quando o usuário usasse os controles de janela separadora.  
  
 Quando você chama **criar**, especifique uma mínimo de linha altura e largura da coluna que determinam quando os painéis são muito pequenos para ser exibido. Depois de você chamar **criar**, você pode ajustar esses valores mínimos chamando o [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) funções de membro.  
  
 Use também o `SetColumnInfo` e `SetRowInfo` funções de membro para definir uma largura "ideal" para uma coluna e a altura "ideal" para uma linha. Quando a estrutura exibe uma janela separadora, ele exibe primeiro quadro principal, em seguida, janela separadora. O framework, em seguida, apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando no canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.  
  
 Todos os painéis em uma janela de separador dinâmico devem ser da mesma classe. Aplicativos que oferecem suporte a janelas separadoras dinâmicas incluem o Microsoft Word e Microsoft Excel.  
  
 Use o `CreateStatic` a função de membro para criar uma janela de separador estático. O usuário pode alterar apenas o tamanho dos painéis em um divisor estático de janela, não o número ou ordem.  
  
 Especificamente, você deve criar painéis do todo o separador estático quando você cria o divisor estático. Certifique-se de criar todos os painéis antes do quadro pai `OnCreateClient` retornos da função de membro, ou ocorrerá framework não exibir a janela corretamente.  
  
 O `CreateStatic` função de membro automaticamente inicializa um separador estático com uma largura mínima de linha de altura e a coluna 0. Depois de você chamar **criar**, ajustar esses valores mínimos chamando o [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) funções de membro. Também use `SetColumnInfo` e `SetRowInfo` depois de você chamar `CreateStatic` para indicar desejadas dimensões painel ideal.  
  
 Os painéis individuais de um separador estático geralmente pertencem a classes diferentes. Para obter exemplos de janelas separadoras estáticas, consulte editor de gráficos e o Gerenciador de arquivos do Windows.  
  
 Uma janela separadora dá suporte a barras de rolagem especial (exceto as barras de rolagem que podem ter painéis). Essas barras de rolagem são filhos do `CSplitterWnd` de objeto e são compartilhadas com os painéis.  
  
 Você cria essas barras de rolagem especial quando criar janela separadora. Por exemplo, um `CSplitterWnd` que tem uma linha, duas colunas e o **WS_VSCROLL** estilo exibirá uma barra de rolagem vertical que é compartilhada por dois painéis. Quando o usuário move a barra de rolagem, `WM_VSCROLL` as mensagens são enviadas para os dois painéis. Quando os painéis de definir a posição da barra de rolagem, a barra de rolagem compartilhado é definida.  
  
 Para obter mais informações sobre janelas separadoras, consulte:  
  
- [Nota técnica 29](../../mfc/tn029-splitter-windows.md)  
  
-   Artigo da Base de dados de Conhecimento Q262024: como: Use CPropertySheet como um filho de CSplitterWnd  
  
 Para obter mais informações sobre como criar janelas separadoras dinâmicas, consulte:  
  
-   Exemplo MFC [Rabisco](../../visual-cpp-samples.md)  
  
-   Exemplo MFC [VIEWEX](../../visual-cpp-samples.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CSplitterWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="activatenext"></a>CSplitterWnd::ActivateNext  
 Chamado pela estrutura para executar o comando próximo painel ou painel anterior.  
  
```  
virtual void ActivateNext(BOOL bPrev = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bPrev`  
 Indica qual é a janela para ativar. **TRUE** para anterior; **FALSE** para Avançar.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é um comando de alto nível que é usado pelo [CView](../../mfc/reference/cview-class.md) classe delegar o `CSplitterWnd` implementação.  
  
##  <a name="canactivatenext"></a>CSplitterWnd::CanActivateNext  
 Chamado pela estrutura para verificar se o comando próximo painel ou painel anterior é possível neste momento.  
  
```  
virtual BOOL CanActivateNext(BOOL bPrev = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bPrev`  
 Indica qual é a janela para ativar. **TRUE** para anterior; **FALSE** para Avançar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é um comando de alto nível que é usado pelo [CView](../../mfc/reference/cview-class.md) classe delegar o `CSplitterWnd` implementação.  
  
##  <a name="create"></a>CSplitterWnd::Create  
 Para criar uma janela separadora dinâmica, chame o **criar** função de membro.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    int nMaxRows,  
    int nMaxCols,  
    SIZE sizeMin,  
    CCreateContext* pContext,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | SPLS_DYNAMIC_SPLIT,  
    UINT nID = AFX_IDW_PANE_FIRST);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 A janela de quadro pai de janela separadora.  
  
 *nMaxRows*  
 O número máximo de linhas na janela separadora. Esse valor não deve exceder 2.  
  
 *nMaxCols*  
 O número máximo de colunas na janela separadora. Esse valor não deve exceder 2.  
  
 `sizeMin`  
 Especifica o tamanho mínimo em que um painel pode ser exibido.  
  
 `pContext`  
 Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Na maioria dos casos, isso pode ser o `pContext` passado para a janela do quadro pai.  
  
 `dwStyle`  
 Especifica o estilo da janela.  
  
 `nID`  
 A ID de janela filho da janela. A ID pode ser **AFX_IDW_PANE_FIRST** , a menos que a janela separadora está aninhada em outra janela do divisor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode incorporar um `CSplitterWnd` em uma pasta pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto por meio das seguintes etapas:  
  
1.  Inserir uma `CSplitterWnd` variável de membro no quadro principal.  
  
2.  Substituição do quadro pai [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.  
  
3.  Chamar o **criar** função membro dentro de substituído `OnCreateClient`.  
  
 Quando você cria uma janela separadora de dentro de um quadro principal, passam do quadro pai `pContext` parâmetro para a janela do divisor. Caso contrário, esse parâmetro pode ser **nulo**.  
  
 A mínimo da linha inicial altura e largura de coluna de uma janela separadora dinâmica são definidas pelo `sizeMin` parâmetro. Esses valores mínimos, que determinam se um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro.  
  
 Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de nota técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&125;](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_1.cpp)]  
  
##  <a name="createscrollbarctrl"></a>CSplitterWnd::CreateScrollBarCtrl  
 Chamado pela estrutura para criar um controle de barra de rolagem compartilhado.  
  
```  
virtual BOOL CreateScrollBarCtrl(
    DWORD dwStyle,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo da janela.  
  
 `nID`  
 A ID de janela filho da janela. A ID pode ser **AFX_IDW_PANE_FIRST** , a menos que a janela separadora está aninhada em outra janela do divisor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substituir `CreateScrollBarCtrl` para incluir controles adicionais ao lado de uma barra de rolagem. O comportamento padrão é criar controles de barra de rolagem Windows normais.  
  
##  <a name="createstatic"></a>CSplitterWnd::CreateStatic  
 Para criar uma janela de separador estático, chame o `CreateStatic` função de membro.  
  
```  
virtual BOOL CreateStatic(
    CWnd* pParentWnd,  
    int nRows,  
    int nCols,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE,  
    UINT nID = AFX_IDW_PANE_FIRST);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 A janela de quadro pai de janela separadora.  
  
 `nRows`  
 O número de linhas. Esse valor não deve exceder 16.  
  
 *nCols*  
 O número de colunas. Esse valor não deve exceder 16.  
  
 `dwStyle`  
 Especifica o estilo da janela.  
  
 `nID`  
 A ID de janela filho da janela. A ID pode ser **AFX_IDW_PANE_FIRST** , a menos que a janela separadora está aninhada em outra janela do divisor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A `CSplitterWnd` geralmente são inseridos em uma pasta pai `CFrameWnd` ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto por meio das seguintes etapas:  
  
1.  Inserir uma `CSplitterWnd` variável de membro no quadro principal.  
  
2.  Substituição do quadro pai `OnCreateClient` função de membro.  
  
3.  Chamar o `CreateStatic` função membro dentro de substituído [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient).  
  
 Uma janela de separador estático contém um número fixo de painéis, geralmente a partir de classes diferentes.  
  
 Quando você cria uma janela de separador estático, ao mesmo tempo crie todos os seus painéis. O [CreateView](#createview) função de membro é geralmente usada para essa finalidade, mas você pode criar outras classes nonview também.  
  
 A mínimo da linha inicial altura e largura de coluna para uma janela de separador estático é 0. Esses valores mínimos, que determinam quando um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro.  
  
 Para adicionar barras de rolagem em uma janela de separador estático, adicione o **WS_HSCROLL** e **WS_VSCROLL** estilos para `dwStyle`.  
  
 Consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de nota técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe para obter mais informações sobre janelas separadoras estáticas.  
  
##  <a name="createview"></a>CSplitterWnd::CreateView  
 Cria painéis para uma janela de separador estático.  
  
```  
virtual BOOL CreateView(
    int row,  
    int col,  
    CRuntimeClass* pViewClass,  
    SIZE sizeInit,  
    CCreateContext* pContext);
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica a linha de janela de separador no qual colocar a nova exibição.  
  
 `col`  
 Especifica a coluna de janela de separador no qual colocar a nova exibição.  
  
 `pViewClass`  
 Especifica o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) da nova exibição.  
  
 *sizeInit*  
 Especifica o tamanho inicial do novo modo de exibição.  
  
 `pContext`  
 Um ponteiro para um contexto de criação usado para criar o modo de exibição (geralmente o `pContext` passado para o quadro de pai substituído [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) a função de membro em que está sendo criada janela separadora).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Todos os painéis de uma janela de separador estático devem ser criados antes do framework exibe o divisor.  
  
 A estrutura também chama essa função de membro para criar novos painéis quando o usuário de uma janela separadora dinâmica divide um painel, linha ou coluna.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&4;](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_2.cpp)]  
  
##  <a name="csplitterwnd"></a>CSplitterWnd::CSplitterWnd  
 Chamada para construir uma `CSplitterWnd` objeto.  
  
```  
CSplitterWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Construir uma `CSplitterWnd` objeto em duas etapas. Primeiro, chame o construtor, que cria o `CSplitterWnd` de objeto e, em seguida, chame o [criar](#create) a função de membro, que cria a janela separadora e anexa-o para o `CSplitterWnd` objeto.  
  
##  <a name="deletecolumn"></a>CSplitterWnd::DeleteColumn  
 Exclui uma coluna da janela separadora.  
  
```  
virtual void DeleteColumn(int colDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 *colDelete*  
 Especifica a coluna a ser excluída.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura para implementar a lógica de janela separadora dinâmica (ou seja, se a janela do divisor tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), implementar divisores dinâmicos mais avançados.  
  
##  <a name="deleterow"></a>CSplitterWnd::DeleteRow  
 Exclui uma linha da janela separadora.  
  
```  
virtual void DeleteRow(int rowDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rowDelete*  
 Especifica a linha a ser excluída.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura para implementar a lógica de janela separadora dinâmica (ou seja, se a janela do divisor tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), implementar divisores dinâmicos mais avançados.  
  
##  <a name="deleteview"></a>CSplitterWnd::DeleteView  
 Exclui uma exibição da janela separadora.  
  
```  
virtual void DeleteView(
    int row,  
    int col);
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica a linha de janela divisão na qual se deseja excluir a exibição.  
  
 `col`  
 Especifica a coluna de janela divisão na qual se deseja excluir a exibição.  
  
### <a name="remarks"></a>Comentários  
 Se o modo ativo está sendo excluído, a exibição seguinte será ativa. A implementação padrão supõe que o modo de exibição serão automaticamente excluir na [PostNcDestroy](../../mfc/reference/cwnd-class.md#postncdestroy).  
  
 Essa função de membro é chamada pela estrutura para implementar a lógica de janela separadora dinâmica (ou seja, se a janela do divisor tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), implementar divisores dinâmicos mais avançados.  
  
##  <a name="dokeyboardsplit"></a>CSplitterWnd::DoKeyboardSplit  
 Executa o teclado dividir o comando, geralmente "divisão da janela".  
  
```  
virtual BOOL DoKeyboardSplit();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é um comando de alto nível que é usado pelo [CView](../../mfc/reference/cview-class.md) classe delegar o `CSplitterWnd` implementação.  
  
##  <a name="doscroll"></a>CSplitterWnd::DoScroll  
 Executa a rolagem sincronizada de janelas separadoras.  
  
```  
virtual BOOL DoScroll(
    CView* pViewFrom,  
    UINT nScrollCode,  
    BOOL bDoScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pViewFrom`  
 Um ponteiro para o modo de exibição do qual se origina a mensagem de rolagem.  
  
 `nScrollCode`  
 Um código de barras de rolagem que indica o usuário da solicitação de rolagem. Esse parâmetro é composto de duas partes: um byte de ordem inferior, que determina o tipo de rolagem horizontalmente ocorrendo, e um byte de ordem superior, que determina o tipo de rolagem vertical ocorrendo:  
  
- **SB_BOTTOM** rola para baixo.  
  
- **SB_LINEDOWN** Rola uma linha para baixo.  
  
- **SB_LINEUP** Rola uma linha para cima.  
  
- **SB_PAGEDOWN** Rola uma página para baixo.  
  
- **SB_PAGEUP** Rola uma página para cima.  
  
- **SB_TOP** rolar para cima.  
  
 `bDoScroll`  
 Determina se a ação de rolagem especificada ocorrerá. Se `bDoScroll` é **TRUE** (isto é, se existir uma janela filho e se as janelas de divisão tem um intervalo de rolagem), em seguida, a ação especificada de rolagem podem ocorrer; se `bDoScroll` é **FALSE** (ou seja, se nenhuma janela filho existe, ou os modos de exibição de divisão não tem nenhum intervalo de rolagem), e rolagem não ocorrerá.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero caso a rolagem sincronizada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura para executar a rolagem sincronizada de janelas separadoras quando o modo de exibição recebe uma mensagem de rolagem. Substituição para solicitar uma ação do usuário antes de rolagem sincronizada é permitido.  
  
##  <a name="doscrollby"></a>CSplitterWnd::DoScrollBy  
 Rola pelas janelas separadoras por um determinado número de pixels.  
  
```  
virtual BOOL DoScrollBy(
    CView* pViewFrom,  
    CSize sizeScroll,  
    BOOL bDoScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pViewFrom`  
 Um ponteiro para o modo de exibição do qual se origina a mensagem de rolagem.  
  
 `sizeScroll`  
 Número de pixels para ser rolado horizontalmente e verticalmente.  
  
 bDoScroll  
 Determina se a ação de rolagem especificada ocorrerá. Se `bDoScroll` é **TRUE** (isto é, se existir uma janela filho e se as janelas de divisão tem um intervalo de rolagem), em seguida, a ação especificada de rolagem podem ocorrer; se `bDoScroll` é **FALSE** (ou seja, se nenhuma janela filho existe, ou os modos de exibição de divisão não tem nenhum intervalo de rolagem), e rolagem não ocorrerá.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero caso a rolagem sincronizada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura em resposta a uma mensagem de rolagem executar sincronizados rolagem do windows dividido pela quantidade, em pixels, indicado por `sizeScroll`. Valores positivos indicam rolando para baixo e para a direita; valores negativos indicam rolar para cima e para a esquerda.  
  
 Substitua para exigir uma ação do usuário antes de permitir a rolagem.  
  
##  <a name="getactivepane"></a>CSplitterWnd::GetActivePane  
 Determina o painel ativo do foco ou da exibição ativa no quadro.  
  
```  
virtual CWnd* GetActivePane(
    int* pRow = NULL,  
    int* pCol = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRow`  
 Um ponteiro para um **int** para recuperar o número de linha do painel ativo.  
  
 `pCol`  
 Um ponteiro para um **int** para recuperar o número de coluna do painel ativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o painel ativo. **NULO** não se existir nenhum painel ativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura para determinar o painel ativo em uma janela separadora. Substitua para exigir uma ação do usuário antes de obter o painel ativo.  
  
##  <a name="getcolumncount"></a>CSplitterWnd::GetColumnCount  
 Retorna o número de colunas do painel atual.  
  
```  
int GetColumnCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número atual de colunas no separador. Para um separador estático, isso também será o número máximo de colunas.  
  
##  <a name="getcolumninfo"></a>CSplitterWnd::GetColumnInfo  
 Retorna informações sobre a coluna especificada.  
  
```  
void GetColumnInfo(
    int col,  
    int& cxCur,  
    int& cxMin) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `col`  
 Especifica uma coluna.  
  
 *cxCur*  
 Uma referência a um `int` seja definida como a largura da coluna atual.  
  
 `cxMin`  
 Uma referência a um `int` a ser definido para a atual largura mínima da coluna.  
  
##  <a name="getpane"></a>CSplitterWnd::GetPane  
 Retorna o painel na linha e coluna especificadas.  
  
```  
CWnd* GetPane(
    int row,  
    int col) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica uma linha.  
  
 `col`  
 Especifica uma coluna.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o painel na linha e coluna especificadas. O painel retornado é geralmente um [CView](../../mfc/reference/cview-class.md)-classe derivada.  
  
##  <a name="getrowcount"></a>CSplitterWnd::GetRowCount  
 Retorna a contagem de linhas do painel atual.  
  
```  
int GetRowCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número atual de linhas na janela do divisor. Para uma janela de separador estático, isso também será o número máximo de linhas.  
  
##  <a name="getrowinfo"></a>CSplitterWnd::GetRowInfo  
 Retorna informações sobre a linha especificada.  
  
```  
void GetRowInfo(
    int row,  
    int& cyCur,  
    int& cyMin) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica uma linha.  
  
 `cyCur`  
 Referência a `int` seja definida como a altura atual da linha em pixels.  
  
 `cyMin`  
 Referência a `int` seja definida como a altura mínima atual da linha em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para obter informações sobre a linha especificada. O `cyCur` parâmetro é preenchido com a altura atual da linha especificada, e `cyMin` é preenchido com a altura mínima da linha.  
  
##  <a name="getscrollstyle"></a>CSplitterWnd::GetScrollStyle  
 Retorna o estilo de barra de rolagem compartilhado de janela separadora.  
  
```  
DWORD GetScrollStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma ou mais das seguintes janelas estilo sinalizadores, se for bem-sucedido:  
  
- **WS_HSCROLL** se o divisor atualmente gerencia as barras de rolagem horizontal compartilhado.  
  
- **WS_VSCROLL** se o divisor atualmente gerencia as barras de rolagem vertical compartilhado.  
  
 Se for zero, a janela separadora não gerencia atualmente barras de rolagem compartilhado.  
  
##  <a name="idfromrowcol"></a>CSplitterWnd::IdFromRowCol  
 Obtém o filho janela ID para o painel na linha e coluna especificadas.  
  
```  
int IdFromRowCol(
    int row,  
    int col) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica a linha de janela divisor.  
  
 `col`  
 Especifica a coluna de janela divisor.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de janela filho para o painel.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é usada para criar nonviews como painéis e pode ser chamada antes do painel existe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&5;](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_3.cpp)]  
  
##  <a name="ischildpane"></a>CSplitterWnd::IsChildPane  
 Determina se `pWnd` atualmente é um painel de filho desta janela divisor.  
  
```  
BOOL IsChildPane(
    CWnd* pWnd,  
    int* pRow,  
    int* pCol);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto a ser testada.  
  
 `pRow`  
 Um ponteiro para um `int` para armazenar o número da linha.  
  
 `pCol`  
 Um ponteiro para um `int` para armazenar um número de coluna.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for diferente de zero, `pWnd` atualmente é um painel de filho desta janela divisor, e `pRow` e `pCol` são preenchidos com a posição do painel na janela do divisor. Se `pWnd` não é um painel filho desta janela divisor, 0 é retornado.  
  
### <a name="remarks"></a>Comentários  
 Em versões do Visual C++ anteriores 6.0, essa função foi definida como  
  
 `BOOL IsChildPane(CWnd* pWnd, int& row, int& col);`  
  
 Esta versão agora é obsoleto e não deve ser usado.  
  
##  <a name="istracking"></a>CSplitterWnd::IsTracking  
 Chame essa função de membro para determinar se a barra de divisão na janela atualmente está sendo movida.  
  
```  
BOOL IsTracking();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma operação de divisão está em andamento. Caso contrário, 0.  
  
##  <a name="ondrawsplitter"></a>CSplitterWnd::OnDrawSplitter  
 Renderiza uma imagem de uma janela dividida.  
  
```  
virtual void OnDrawSplitter(
    CDC* pDC,  
    ESplitType nType,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o contexto de dispositivo no qual desenhar. Se `pDC` é **nulo**, em seguida, [CWnd::RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) é chamado, a estrutura e sem nenhuma divisão janela é desenhada.  
  
 `nType`  
 Um valor igual a **enum ESplitType**, que pode ser um dos seguintes:  
  
- **splitBox** o divisor arraste caixa.  
  
- `splitBar`A barra que aparece entre as janelas de divisão de dois.  
  
- **splitIntersection** a interseção das janelas de divisão. Esse elemento não será chamado quando em execução no Windows 95/98.  
  
- **splitBorder** as bordas da janela de divisão.  
  
 `rect`  
 Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto especificando o tamanho e a forma das janelas de divisão.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura para desenhar e especifique as características exatas de uma janela separadora. Substituir `OnDrawSplitter` da personalização avançada de imagens de vários componentes gráficos de uma janela separadora. As imagens padrão é semelhante ao divisor no Microsoft Works para Windows ou o Microsoft Windows 95/98, as interseções das barras separadoras são combinadas.  
  
 Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de nota técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.  
  
##  <a name="oninverttracker"></a>CSplitterWnd::OnInvertTracker  
 Processa a imagem de uma janela dividida para ser o mesmo tamanho e forma da janela do quadro.  
  
```  
virtual void OnInvertTracker(const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Referência a um `CRect` objeto especificando o retângulo de controle.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura durante o redimensionamento de divisores. Substituir `OnInvertTracker` da personalização avançada de imagens de janela separadora. As imagens padrão é semelhante ao divisor no Microsoft Works para Windows ou o Microsoft Windows 95/98, as interseções das barras separadoras são combinadas.  
  
 Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de nota técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.  
  
##  <a name="recalclayout"></a>CSplitterWnd::RecalcLayout  
 Chamada para reexibir janela separadora depois de ajustar o tamanho de linha ou coluna.  
  
```  
virtual void RecalcLayout();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para reexibir corretamente a janela separadora após você ter ajustado os tamanhos de linha e coluna com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro. Se você alterar os tamanhos de linha e coluna como parte do processo de criação antes de janela separadora estiver visível, não é necessário chamar essa função de membro.  
  
 O framework chama essa função membro sempre que o usuário redimensiona a janela do divisor ou mover uma divisão.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CSplitterWnd::SetColumnInfo](#setcolumninfo).  
  
##  <a name="setactivepane"></a>CSplitterWnd::SetActivePane  
 Define um painel para ser o ativo no quadro.  
  
```  
virtual void SetActivePane(
    int row,  
    int col,  
    CWnd* pWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Se `pWnd` é **nulo**, especifica a linha no painel ativos.  
  
 `col`  
 Se `pWnd` é **nulo**, especifica a coluna no painel ativos.  
  
 `pWnd`  
 Um ponteiro para um `CWnd` objeto. Se **nulo**, o painel especificado por `row` e `col` seja definida como ativa. Se não **nulo**, especifica o painel que seja definido como ativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pela estrutura para definir um painel como ativa quando o usuário altera o foco para um painel dentro da janela de quadro. Você pode chamar explicitamente `SetActivePane` para alterar o foco para o modo de exibição especificado.  
  
 Especificar o painel, fornecendo a linha e coluna, **ou** fornecendo `pWnd`.  
  
##  <a name="setcolumninfo"></a>CSplitterWnd::SetColumnInfo  
 Chamada para definir as informações de coluna especificada.  
  
```  
void SetColumnInfo(
    int col,  
    int cxIdeal,  
    int cxMin);
```  
  
### <a name="parameters"></a>Parâmetros  
 `col`  
 Especifica uma coluna de janela divisor.  
  
 *cxIdeal*  
 Especifica uma largura ideal para a coluna da janela de separador em pixels.  
  
 `cxMin`  
 Especifica uma largura mínima da coluna da janela de separador em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para definir uma nova largura mínima e largura ideal para uma coluna. O valor mínimo da coluna determina quando a coluna será muito pequena para ser exibido.  
  
 Quando a estrutura exibe a janela do divisor, ele apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando no canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&6;](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_4.cpp)]  
  
##  <a name="setrowinfo"></a>CSplitterWnd::SetRowInfo  
 Chamada para definir as informações de linha especificado.  
  
```  
void SetRowInfo(
    int row,  
    int cyIdeal,  
    int cyMin);
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica uma linha da janela de separador.  
  
 *cyIdeal*  
 Especifica uma altura ideal para a linha da janela de separador em pixels.  
  
 `cyMin`  
 Especifica uma altura mínima da linha da janela de separador em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para definir uma nova altura mínima e altura ideal para uma linha. O valor mínimo da linha determina quando a linha será muito pequena para ser exibido.  
  
 Quando a estrutura exibe a janela do divisor, ele apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando no canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.  
  
##  <a name="setscrollstyle"></a>CSplitterWnd::SetScrollStyle  
 Especifica que o novo estilo de rolagem da janela de separador compartilhada suporte a barra de rolagem.  
  
```  
void SetScrollStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 O novo estilo de rolagem da janela de separador compartilhado suporte a barra de rolagem, que pode ser um dos seguintes valores:  
  
- **WS_HSCROLL** criar/Mostrar horizontal compartilhado barras de rolagem.  
  
- **WS_VSCROLL** criar/Mostrar vertical compartilhado barras de rolagem.  
  
### <a name="remarks"></a>Comentários  
 Depois que uma barra de rolagem é criada ele não será destruído mesmo se `SetScrollStyle` for chamado sem estilo; em vez disso, as barras de rolagem estão ocultos. Isso permite que as barras de rolagem manter seu estado, mesmo que eles estejam ocultos. Depois de chamar `SetScrollStyle` é necessário chamar [RecalcLayout](#recalclayout) para todas as alterações tenham efeito.  
  
##  <a name="splitcolumn"></a>CSplitterWnd::SplitColumn  
 Indica onde uma janela do quadro se divide verticalmente.  
  
```  
virtual BOOL SplitColumn(int cxBefore);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cxBefore*  
 A posição, em pixels, antes que a divisão ocorre.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada quando uma janela de divisão vertical é criada. `SplitColumn`indica o local padrão onde ocorre a divisão.  
  
 `SplitColumn`é chamado pela estrutura para implementar a lógica de janela separadora dinâmica (ou seja, se a janela do divisor tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), implementar divisores dinâmicos mais avançados.  
  
##  <a name="splitrow"></a>CSplitterWnd::SplitRow  
 Indica onde uma janela do quadro se divide horizontalmente.  
  
```  
virtual BOOL SplitRow(int cyBefore);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cyBefore*  
 A posição, em pixels, antes que a divisão ocorre.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada quando uma janela de splitter horizontal é criada. `SplitRow`indica o local padrão onde ocorre a divisão.  
  
 `SplitRow`é chamado pela estrutura para implementar a lógica de janela separadora dinâmica (ou seja, se a janela do divisor tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), implementar divisores dinâmicos mais avançados.  
  
##  <a name="ondraw"></a>CSplitterWnd::OnDraw  
 Chamado pela estrutura para desenhar a janela separadora.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC VIEWEX](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)

