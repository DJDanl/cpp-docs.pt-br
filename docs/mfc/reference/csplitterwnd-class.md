---
title: Classe CSplitterWnd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords:
- CSplitterWnd [MFC], CSplitterWnd
- CSplitterWnd [MFC], ActivateNext
- CSplitterWnd [MFC], CanActivateNext
- CSplitterWnd [MFC], Create
- CSplitterWnd [MFC], CreateScrollBarCtrl
- CSplitterWnd [MFC], CreateStatic
- CSplitterWnd [MFC], CreateView
- CSplitterWnd [MFC], DeleteColumn
- CSplitterWnd [MFC], DeleteRow
- CSplitterWnd [MFC], DeleteView
- CSplitterWnd [MFC], DoKeyboardSplit
- CSplitterWnd [MFC], DoScroll
- CSplitterWnd [MFC], DoScrollBy
- CSplitterWnd [MFC], GetActivePane
- CSplitterWnd [MFC], GetColumnCount
- CSplitterWnd [MFC], GetColumnInfo
- CSplitterWnd [MFC], GetPane
- CSplitterWnd [MFC], GetRowCount
- CSplitterWnd [MFC], GetRowInfo
- CSplitterWnd [MFC], GetScrollStyle
- CSplitterWnd [MFC], IdFromRowCol
- CSplitterWnd [MFC], IsChildPane
- CSplitterWnd [MFC], IsTracking
- CSplitterWnd [MFC], RecalcLayout
- CSplitterWnd [MFC], SetActivePane
- CSplitterWnd [MFC], SetColumnInfo
- CSplitterWnd [MFC], SetRowInfo
- CSplitterWnd [MFC], SetScrollStyle
- CSplitterWnd [MFC], SplitColumn
- CSplitterWnd [MFC], SplitRow
- CSplitterWnd [MFC], OnDraw
- CSplitterWnd [MFC], OnDrawSplitter
- CSplitterWnd [MFC], OnInvertTracker
ms.assetid: fd0de258-6dbe-4552-9e47-a39de0471d51
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 706425dd8d729937d310da9cc2f09eac8ec1ad57
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csplitterwnd-class"></a>Classe CSplitterWnd
Fornece a funcionalidade de uma janela separadora, que é uma janela que contém vários painéis.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSplitterWnd : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWnd::CSplitterWnd](#csplitterwnd)|Chamada para construir um `CSplitterWnd` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWnd::ActivateNext](#activatenext)|Executa o comando próximo painel ou painel anterior.|  
|[CSplitterWnd::CanActivateNext](#canactivatenext)|Verifica se o comando próximo painel ou painel anterior é possível neste momento.|  
|[CSplitterWnd::Create](#create)|Chamada para criar uma janela separadora dinâmica e anexá-lo para o `CSplitterWnd` objeto.|  
|[CSplitterWnd::CreateScrollBarCtrl](#createscrollbarctrl)|Cria um controle de barra de rolagem compartilhado.|  
|[CSplitterWnd::CreateStatic](#createstatic)|Chamada para criar uma janela separadora estático e anexá-lo para o `CSplitterWnd` objeto.|  
|[CSplitterWnd::CreateView](#createview)|Chamada para criar um painel em uma janela separadora.|  
|[CSplitterWnd::DeleteColumn](#deletecolumn)|Exclui uma coluna da janela separadora.|  
|[CSplitterWnd::DeleteRow](#deleterow)|Exclui uma linha da janela separadora.|  
|[CSplitterWnd::DeleteView](#deleteview)|Exclui uma exibição da janela separadora.|  
|[CSplitterWnd::DoKeyboardSplit](#dokeyboardsplit)|Executa o comando, geralmente "divisão da janela". de divisão do teclado|  
|[CSplitterWnd::DoScroll](#doscroll)|Executa a rolagem sincronizada de janelas separadoras.|  
|[CSplitterWnd::DoScrollBy](#doscrollby)|Rola pelas janelas separadoras por um determinado número de pixels.|  
|[CSplitterWnd::GetActivePane](#getactivepane)|Determina o painel ativo do foco ou da exibição ativa no quadro.|  
|[CSplitterWnd::GetColumnCount](#getcolumncount)|Retorna o número de colunas do painel atual.|  
|[CSplitterWnd::GetColumnInfo](#getcolumninfo)|Retorna informações sobre a coluna especificada.|  
|[CSplitterWnd::GetPane](#getpane)|Retorna o painel na linha e coluna especificadas.|  
|[CSplitterWnd::GetRowCount](#getrowcount)|Retorna a contagem de linhas do painel atual.|  
|[CSplitterWnd::GetRowInfo](#getrowinfo)|Retorna informações sobre a linha especificada.|  
|[CSplitterWnd::GetScrollStyle](#getscrollstyle)|Retorna o estilo de barra de rolagem compartilhado.|  
|[CSplitterWnd::IdFromRowCol](#idfromrowcol)|Retorna o filho ID da janela do painel na linha e coluna especificadas.|  
|[CSplitterWnd::IsChildPane](#ischildpane)|Chamada para determinar se a janela é atualmente um painel filho desta janela separadora.|  
|[CSplitterWnd::IsTracking](#istracking)|Determina se a barra de divisão no momento está sendo movida.|  
|[CSplitterWnd::RecalcLayout](#recalclayout)|Chamada para reexibir janela separadora depois de ajustar o tamanho de linha ou coluna.|  
|[CSplitterWnd::SetActivePane](#setactivepane)|Define um painel para ser um ativo no quadro.|  
|[CSplitterWnd::SetColumnInfo](#setcolumninfo)|Chamada para definir as informações de coluna especificada.|  
|[CSplitterWnd::SetRowInfo](#setrowinfo)|Chamada para definir as informações de linha especificado.|  
|[CSplitterWnd::SetScrollStyle](#setscrollstyle)|Especifica que o novo estilo de barra de rolagem para a janela de separador compartilhada suporte a barra de rolagem.|  
|[CSplitterWnd::SplitColumn](#splitcolumn)|Indica onde uma janela do quadro se divide verticalmente.|  
|[CSplitterWnd::SplitRow](#splitrow)|Indica onde uma janela do quadro se divide horizontalmente.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWnd::OnDraw](#ondraw)|Chamado pelo framework para desenhar a janela separadora.|  
|[CSplitterWnd::OnDrawSplitter](#ondrawsplitter)|Renderiza uma imagem de uma janela separadora.|  
|[CSplitterWnd::OnInvertTracker](#oninverttracker)|Processa a imagem de uma janela separadora para ser o mesmo tamanho e a forma como a janela do quadro.|  
  
## <a name="remarks"></a>Comentários  
 Um painel geralmente é um objeto específico do aplicativo derivado de [CView](../../mfc/reference/cview-class.md), mas pode ser qualquer [CWnd](../../mfc/reference/cwnd-class.md) objeto que tem a ID da janela filho apropriados.  
  
 Um `CSplitterWnd` objeto geralmente é inserido em um pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto. Criar um `CSplitterWnd` objeto usando as seguintes etapas:  
  
1.  Inserir um `CSplitterWnd` variável de membro no quadro pai.  
  
2.  Substituir o quadro de pai [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.  
  
3.  De dentro de substituído `OnCreateClient`, chame o [criar](#create) ou [CreateStatic](#createstatic) função membro de `CSplitterWnd`.  
  
 Chamar o **criar** função de membro para criar uma janela separadora dinâmica. Uma janela separadora dinâmica normalmente é usada para criar e rolar um número de painéis individuais ou exibições do mesmo documento. A estrutura cria automaticamente um painel inicial para o separador; em seguida, a estrutura cria, redimensiona e dispõe de painéis adicionais, como o usuário opere controles da janela separadora.  
  
 Quando você chama **criar**, especifique uma mínimo de linha altura e largura de coluna que determinam quando os painéis são muito pequenos para ser exibido. Depois de chamar **criar**, você pode ajustar esses mínimos chamando o [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) funções de membro.  
  
 Use também o `SetColumnInfo` e `SetRowInfo` funções de membro para definir uma largura "ideal" para uma coluna e a altura "ideal" para uma linha. Quando a estrutura é exibida uma janela separadora, ele primeiro mostra o quadro do pai, em seguida, a janela separadora. A estrutura, em seguida, apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.  
  
 Todos os painéis em uma janela separadora dinâmica devem ser da mesma classe. Aplicativos que dão suporte a janelas separadoras dinâmicas incluem o Microsoft Word e Microsoft Excel.  
  
 Use o `CreateStatic` a função de membro para criar uma janela separadora estático. O usuário pode alterar somente o tamanho dos painéis em uma janela, não o número ou a ordem de separador estático.  
  
 Especificamente, você deve criar painéis do todos o separador estático quando você cria o separador estático. Verifique se você criar todos os painéis antes do quadro pai `OnCreateClient` retorna da função de membro, ou ocorrerá framework não exibir a janela corretamente.  
  
 O `CreateStatic` função membro automaticamente inicializa um divisor estático com uma largura mínima de linha de altura e a coluna 0. Depois de chamar **criar**, ajustar esses mínimos chamando o [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) funções de membro. Também use `SetColumnInfo` e `SetRowInfo` depois de chamar `CreateStatic` indicar desejado dimensões painel ideal.  
  
 Geralmente, os painéis individuais de um separador estático pertencem a classes diferentes. Para obter exemplos de janelas separadoras estáticas, consulte o editor de elementos gráficos e o Gerenciador de arquivos do Windows.  
  
 Uma janela separadora dá suporte a barras de rolagem especial (além de barras de rolagem podem ter painéis). Essas barras de rolagem são filhos do `CSplitterWnd` de objeto e são compartilhados com os painéis.  
  
 Você cria essas barras de rolagem especial ao criar janela separadora. Por exemplo, um `CSplitterWnd` que tem uma linha, duas colunas e o **WS_VSCROLL** estilo exibirá uma barra de rolagem vertical é compartilhada por dois painéis. Quando o usuário move a barra de rolagem, `WM_VSCROLL` as mensagens são enviadas para os dois painéis. Quando os painéis de definir a posição da barra de rolagem, a barra de rolagem compartilhado é definida.  
  
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
 Chamado pelo framework para executar o comando próximo painel ou painel anterior.  
  
```  
virtual void ActivateNext(BOOL bPrev = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bPrev`  
 Indica qual janela para ativar. **TRUE** para anterior; **FALSE** para Avançar.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é um comando de alto nível que é usado pelo [CView](../../mfc/reference/cview-class.md) classe delegue a `CSplitterWnd` implementação.  
  
##  <a name="canactivatenext"></a>CSplitterWnd::CanActivateNext  
 Chamado pelo framework para verificar se o comando próximo painel ou painel anterior é possível neste momento.  
  
```  
virtual BOOL CanActivateNext(BOOL bPrev = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bPrev`  
 Indica qual janela para ativar. **TRUE** para anterior; **FALSE** para Avançar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é um comando de alto nível que é usado pelo [CView](../../mfc/reference/cview-class.md) classe delegue a `CSplitterWnd` implementação.  
  
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
 A janela pai do quadro de janela separadora.  
  
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
 Você pode inserir um `CSplitterWnd` em um pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto realizando as seguintes etapas:  
  
1.  Inserir um `CSplitterWnd` variável de membro no quadro pai.  
  
2.  Substituir o quadro de pai [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.  
  
3.  Chamar o **criar** função de membro de dentro substituído `OnCreateClient`.  
  
 Quando você cria uma janela separadora de dentro de um quadro pai, passar o quadro de pai `pContext` parâmetro para a janela separadora. Caso contrário, esse parâmetro pode ser **nulo**.  
  
 A mínimo da linha inicial altura e largura de coluna de uma janela separadora dinâmica são definidas pelo `sizeMin` parâmetro. Esses valores mínimos, que determinam se um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro.  
  
 Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#125](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_1.cpp)]  
  
##  <a name="createscrollbarctrl"></a>CSplitterWnd::CreateScrollBarCtrl  
 Chamado pelo framework para criar um controle de barra de rolagem compartilhado.  
  
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
 Para criar uma janela separadora estático, chame o `CreateStatic` função de membro.  
  
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
 A janela pai do quadro de janela separadora.  
  
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
 Um `CSplitterWnd` geralmente é inserido em um pai `CFrameWnd` ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto realizando as seguintes etapas:  
  
1.  Inserir um `CSplitterWnd` variável de membro no quadro pai.  
  
2.  Substituir o quadro de pai `OnCreateClient` função de membro.  
  
3.  Chamar o `CreateStatic` função de membro de dentro substituído [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient).  
  
 Uma janela separadora estático contém um número fixo de painéis, geralmente de classes diferentes.  
  
 Quando você cria uma janela separadora estático, ao mesmo tempo crie todos os seus painéis. O [CreateView](#createview) função de membro normalmente é usada para essa finalidade, mas você pode criar outras classes nonview também.  
  
 A mínimo da linha inicial altura e largura de coluna para uma janela separadora estático é 0. Esses valores mínimos, que determinam quando um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro.  
  
 Para adicionar barras de rolagem para uma janela separadora estático, adicione o **WS_HSCROLL** e **WS_VSCROLL** estilos para `dwStyle`.  
  
 Consulte o artigo "Janelas separadoras" [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe para obter mais informações sobre janelas separadoras estáticas.  
  
##  <a name="createview"></a>CSplitterWnd::CreateView  
 Cria painéis para uma janela separadora estático.  
  
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
 Especifica a linha de janela separadora para colocar o novo modo de exibição.  
  
 `col`  
 Especifica a coluna de janela separadora para colocar o novo modo de exibição.  
  
 `pViewClass`  
 Especifica o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) da nova exibição.  
  
 *sizeInit*  
 Especifica o tamanho inicial do novo modo de exibição.  
  
 `pContext`  
 Um ponteiro para um contexto de criação usado para criar o modo de exibição (geralmente o `pContext` passado para o quadro de pai substituído [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) a função de membro no qual janela separadora está sendo criada).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Todos os painéis de uma janela separadora estático devem ser criados antes do framework exibe o divisor.  
  
 A estrutura também chama essa função de membro para criar novos painéis, quando o usuário de uma janela separadora dinâmica divide um painel, linha ou coluna.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#4](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_2.cpp)]  
  
##  <a name="csplitterwnd"></a>CSplitterWnd::CSplitterWnd  
 Chamada para construir um `CSplitterWnd` objeto.  
  
```  
CSplitterWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Construir um `CSplitterWnd` objeto em duas etapas. Primeiro, chame o construtor, que cria o `CSplitterWnd` do objeto e, em seguida, chame o [criar](#create) a função de membro, que cria a janela separadora e anexa-o para o `CSplitterWnd` objeto.  
  
##  <a name="deletecolumn"></a>CSplitterWnd::DeleteColumn  
 Exclui uma coluna da janela separadora.  
  
```  
virtual void DeleteColumn(int colDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 *colDelete*  
 Especifica a coluna a ser excluído.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela separadora tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar mais avançados divisores dinâmicos.  
  
##  <a name="deleterow"></a>CSplitterWnd::DeleteRow  
 Exclui uma linha da janela separadora.  
  
```  
virtual void DeleteRow(int rowDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rowDelete*  
 Especifica a linha a ser excluída.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela separadora tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar mais avançados divisores dinâmicos.  
  
##  <a name="deleteview"></a>CSplitterWnd::DeleteView  
 Exclui uma exibição da janela separadora.  
  
```  
virtual void DeleteView(
    int row,  
    int col);
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica a linha de janela separadora no qual o modo de exibição.  
  
 `col`  
 Especifica a coluna de janela separadora no qual o modo de exibição.  
  
### <a name="remarks"></a>Comentários  
 Se o modo de exibição ativo está sendo excluído, a próxima exibição se tornará ativa. A implementação padrão supõe que o modo de exibição automaticamente excluir na [PostNcDestroy](../../mfc/reference/cwnd-class.md#postncdestroy).  
  
 Essa função de membro é chamada pelo framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela separadora tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar mais avançados divisores dinâmicos.  
  
##  <a name="dokeyboardsplit"></a>CSplitterWnd::DoKeyboardSplit  
 Executa o comando, geralmente "divisão da janela". de divisão do teclado  
  
```  
virtual BOOL DoKeyboardSplit();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é um comando de alto nível que é usado pelo [CView](../../mfc/reference/cview-class.md) classe delegue a `CSplitterWnd` implementação.  
  
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
 Um código de barras de rolagem que indica o usuário da solicitação de rolagem. Esse parâmetro é composto de duas partes: um byte de ordem inferior, que determina o tipo de rolagem horizontal ocorrer, e um byte de ordem superior, que determina o tipo de rolagem vertical ocorrendo:  
  
- **SB_BOTTOM** rola para baixo.  
  
- **SB_LINEDOWN** Rola uma linha para baixo.  
  
- **SB_LINEUP** Rola uma linha para cima.  
  
- **SB_PAGEDOWN** Rola uma página para baixo.  
  
- **SB_PAGEUP** Rola uma página para cima.  
  
- **SB_TOP** rolar para cima.  
  
 `bDoScroll`  
 Determina se a ação especificada de rolagem ocorre. Se `bDoScroll` é **TRUE** (ou seja, se uma janela filho existe e se as janelas de divisão tem um intervalo de rolagem), em seguida, a ação especificada de rolagem podem ocorrer; se `bDoScroll` é **FALSE** (ou seja, se Nenhuma janela filho existe, ou os modos divisão não tem nenhum intervalo de rolagem), e a rolagem não ocorrerá.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se ocorrer a rolagem sincronizada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework para executar a rolagem sincronizada de janelas separadoras quando o modo de exibição recebe uma mensagem de rolagem. Substituição para exigir uma ação do usuário antes de rolagem sincronizada é permitido.  
  
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
 Número de pixels de rolagem horizontal e verticalmente.  
  
 bDoScroll  
 Determina se a ação especificada de rolagem ocorre. Se `bDoScroll` é **TRUE** (ou seja, se uma janela filho existe e se as janelas de divisão tem um intervalo de rolagem), em seguida, a ação especificada de rolagem podem ocorrer; se `bDoScroll` é **FALSE** (ou seja, se Nenhuma janela filho existe, ou os modos divisão não tem nenhum intervalo de rolagem), e a rolagem não ocorrerá.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se ocorrer a rolagem sincronizada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework em resposta a uma mensagem de rolagem executar sincronizados rolagem das janelas de divisão por quantidade, em pixels, indicado por `sizeScroll`. Valores positivos indicam rolando para baixo e para a direita; valores negativos indicam a rolagem para cima e para a esquerda.  
  
 Substituição para exigir uma ação do usuário antes de permitir a rolagem.  
  
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
 Essa função de membro é chamada pelo framework para determinar o painel ativo em uma janela separadora. Substituição para exigir uma ação do usuário antes de obter o painel ativo.  
  
##  <a name="getcolumncount"></a>CSplitterWnd::GetColumnCount  
 Retorna o número de colunas do painel atual.  
  
```  
int GetColumnCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número atual de colunas no separador. Para uma separador estática, isso também será o número máximo de colunas.  
  
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
 Uma referência a um `int` a ser definido para a largura atual da coluna.  
  
 `cxMin`  
 Uma referência a um `int` seja definida como a largura mínima atual da coluna.  
  
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
 Retorna o número atual de linhas na janela separadora. Para uma janela de separador estático, isso também será o número máximo de linhas.  
  
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
 Chame essa função de membro para obter informações sobre a linha especificada. O `cyCur` parâmetro é preenchido com a altura atual da linha especificada, e `cyMin` é preenchida com a altura mínima da linha.  
  
##  <a name="getscrollstyle"></a>CSplitterWnd::GetScrollStyle  
 Retorna o estilo de barra de rolagem compartilhado para a janela separadora.  
  
```  
DWORD GetScrollStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ou mais dos seguintes janelas estilo sinalizadores, se for bem-sucedido:  
  
- **WS_HSCROLL** se o divisor atualmente gerencia as barras de rolagem horizontal compartilhado.  
  
- **WS_VSCROLL** se o divisor atualmente gerencia as barras de rolagem vertical compartilhado.  
  
 Se for zero, a janela separadora não gerencia as barras de rolagem compartilhado no momento.  
  
##  <a name="idfromrowcol"></a>CSplitterWnd::IdFromRowCol  
 Obtém o filho de ID de janela para o painel na linha e coluna especificadas.  
  
```  
int IdFromRowCol(
    int row,  
    int col) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Especifica a linha da janela separadora.  
  
 `col`  
 Especifica a coluna da janela separadora.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de janela filho para o painel.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é usada para criar nonviews como painéis e pode ser chamada antes do painel de existe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#5](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_3.cpp)]  
  
##  <a name="ischildpane"></a>CSplitterWnd::IsChildPane  
 Determina se `pWnd` atualmente é um painel de filho desta janela separadora.  
  
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
 Se for diferente de zero, `pWnd` atualmente é um painel de filho desta janela separadora, e `pRow` e `pCol` são preenchidas com a posição do painel na janela separadora. Se `pWnd` não é um painel filho desta janela separadora, será retornado 0.  
  
### <a name="remarks"></a>Comentários  
 Em versões do Visual C++ anteriores 6.0, essa função foi definida como  
  
 `BOOL IsChildPane(CWnd* pWnd, int& row, int& col);`  
  
 Esta versão agora está obsoleto e não deve ser usado.  
  
##  <a name="istracking"></a>CSplitterWnd::IsTracking  
 Chame essa função de membro para determinar se a barra de divisão na janela atualmente está sendo movida.  
  
```  
BOOL IsTracking();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma operação de divisão está em andamento. Caso contrário, 0.  
  
##  <a name="ondrawsplitter"></a>CSplitterWnd::OnDrawSplitter  
 Renderiza uma imagem de uma janela separadora.  
  
```  
virtual void OnDrawSplitter(
    CDC* pDC,  
    ESplitType nType,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o contexto de dispositivo no qual desenhar. Se `pDC` é **nulo**, em seguida, [CWnd::RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) é chamado pelo framework e sem nenhuma divisão janela é desenhada.  
  
 `nType`  
 Um valor de **enum ESplitType**, que pode ser um dos seguintes:  
  
- **splitBox** o divisor arraste caixa.  
  
- `splitBar`A barra que aparece entre as janelas de divisão de dois.  
  
- **splitIntersection** a interseção das janelas de divisão. Esse elemento não será chamado quando em execução no Windows 95/98.  
  
- **splitBorder** os limites da janela de divisão.  
  
 `rect`  
 Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica o tamanho e a forma das janelas de divisão.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework para desenhar e especifique as características exatas de uma janela separadora. Substituir `OnDrawSplitter` para a personalização avançada de imagens para os vários componentes de gráficos de uma janela separadora. As imagens padrão é semelhante para o separador no Microsoft Works para Windows ou o Microsoft Windows 95/98, as interseções das barras separadoras são mescladas em conjunto.  
  
 Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.  
  
##  <a name="oninverttracker"></a>CSplitterWnd::OnInvertTracker  
 Processa a imagem de uma janela separadora para ser o mesmo tamanho e a forma como a janela do quadro.  
  
```  
virtual void OnInvertTracker(const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Referência a um `CRect` objeto especificando o retângulo de controle.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework durante o redimensionamento de divisores. Substituir `OnInvertTracker` para a personalização avançada de imagens da janela separadora. As imagens padrão é semelhante para o separador no Microsoft Works para Windows ou o Microsoft Windows 95/98, as interseções das barras separadoras são mescladas em conjunto.  
  
 Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Janelas separadoras" no artigo [vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.  
  
##  <a name="recalclayout"></a>CSplitterWnd::RecalcLayout  
 Chamada para reexibir janela separadora depois de ajustar o tamanho de linha ou coluna.  
  
```  
virtual void RecalcLayout();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função de membro para reexibir corretamente a janela separadora após você ter ajustado tamanhos de linha e coluna com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro. Se você alterar os tamanhos de linha e coluna como parte do processo de criação antes de janela separadora estiver visível, não é necessário chamar essa função de membro.  
  
 O framework chama esta função de membro sempre que o usuário redimensiona a janela do divisor ou mover uma divisão.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CSplitterWnd::SetColumnInfo](#setcolumninfo).  
  
##  <a name="setactivepane"></a>CSplitterWnd::SetActivePane  
 Define um painel para ser um ativo no quadro.  
  
```  
virtual void SetActivePane(
    int row,  
    int col,  
    CWnd* pWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `row`  
 Se `pWnd` é **nulo**, especifica a linha no painel de ativos.  
  
 `col`  
 Se `pWnd` é **nulo**, especifica a coluna no painel ativos.  
  
 `pWnd`  
 Um ponteiro para um `CWnd` objeto. Se **nulo**, o painel especificado por `row` e `col` seja definida como ativa. Se não **nulo**, especifica o painel que seja definido como ativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework para definir um painel como ativo quando o usuário altera o foco para um painel dentro da janela do quadro. Você pode chamar explicitamente `SetActivePane` para alterar o foco para o modo de exibição especificado.  
  
 Especifique o painel, fornecendo a linha e coluna, **ou** fornecendo `pWnd`.  
  
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
 Especifica uma coluna da janela separadora.  
  
 *cxIdeal*  
 Especifica uma largura ideal para a coluna de janela de separador em pixels.  
  
 `cxMin`  
 Especifica uma largura mínima da coluna da janela de separador em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para definir uma nova largura mínima e largura ideal para uma coluna. O valor mínimo da coluna determina quando a coluna será muito pequena para ser exibido.  
  
 Quando a estrutura exibe a janela separadora, ele apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#6](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_4.cpp)]  
  
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
 Especifica uma linha da janela separadora.  
  
 *cyIdeal*  
 Especifica uma altura ideal para a linha da janela de separador em pixels.  
  
 `cyMin`  
 Especifica uma altura mínima da linha da janela de separador em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para definir uma nova altura mínima e a altura ideal para uma linha. O valor mínimo da linha determina quando a linha será muito pequena para ser exibido.  
  
 Quando a estrutura exibe a janela separadora, ele apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.  
  
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
 Quando uma barra de rolagem é criada ele não será destruído mesmo se `SetScrollStyle` for chamado sem esse estilo; em vez disso, as barras de rolagem são ocultos. Isso permite que as barras de rolagem manter seu estado, mesmo que eles estejam ocultos. Depois de chamar `SetScrollStyle` é necessário chamar [RecalcLayout](#recalclayout) para todas as alterações entrem em vigor.  
  
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
 Essa função de membro é chamada quando uma janela separadora vertical é criada. `SplitColumn`indica o local padrão onde ocorre a divisão.  
  
 `SplitColumn`é chamado pelo framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela separadora tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar mais avançados divisores dinâmicos.  
  
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
 Essa função de membro é chamada quando uma janela separadora horizontal é criada. `SplitRow`indica o local padrão onde ocorre a divisão.  
  
 `SplitRow`é chamado pelo framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela separadora tem o **SPLS_DYNAMIC_SPLIT** estilo). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar mais avançados divisores dinâmicos.  
  
##  <a name="ondraw"></a>CSplitterWnd::OnDraw  
 Chamado pelo framework para desenhar a janela separadora.  
  
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
