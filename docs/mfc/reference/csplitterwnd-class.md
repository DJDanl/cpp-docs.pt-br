---
title: Classe CSplitterWnd
ms.date: 11/04/2016
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
ms.openlocfilehash: 065735c13a3e763208142eb6bc989d3a496221f0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62323811"
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
|[CSplitterWnd::CSplitterWnd](#csplitterwnd)|Chamada para construir um `CSplitterWnd` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWnd::ActivateNext](#activatenext)|Executa o comando próximo painel ou painel anterior.|
|[CSplitterWnd::CanActivateNext](#canactivatenext)|Verifica se o comando próximo painel ou painel anterior é possível no momento.|
|[CSplitterWnd::Create](#create)|Chamada para criar uma janela divisora dinâmica e anexá-lo para o `CSplitterWnd` objeto.|
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
|[CSplitterWnd::GetColumnCount](#getcolumncount)|Retorna a contagem de colunas do painel atual.|
|[CSplitterWnd::GetColumnInfo](#getcolumninfo)|Retorna informações sobre a coluna especificada.|
|[CSplitterWnd::GetPane](#getpane)|Retorna o painel na linha especificada e na coluna.|
|[CSplitterWnd::GetRowCount](#getrowcount)|Retorna a contagem de linhas do painel atual.|
|[CSplitterWnd::GetRowInfo](#getrowinfo)|Retorna informações sobre a linha especificada.|
|[CSplitterWnd::GetScrollStyle](#getscrollstyle)|Retorna o estilo de barra de rolagem compartilhado.|
|[CSplitterWnd::IdFromRowCol](#idfromrowcol)|Retorna o filho do painel na linha especificada e na coluna de ID da janela.|
|[CSplitterWnd::IsChildPane](#ischildpane)|Chamada para determinar se a janela é atualmente um painel filho dessa janela divisor.|
|[CSplitterWnd::IsTracking](#istracking)|Determina se barra divisória atualmente está sendo movida.|
|[CSplitterWnd::RecalcLayout](#recalclayout)|Chamada para exibir novamente a janela divisora depois de ajustar o tamanho de linha ou coluna.|
|[CSplitterWnd::SetActivePane](#setactivepane)|Define um painel para ser o Active Directory no quadro.|
|[CSplitterWnd::SetColumnInfo](#setcolumninfo)|Chamada para definir as informações da coluna especificada.|
|[CSplitterWnd::SetRowInfo](#setrowinfo)|Chamada para definir as informações da linha especificada.|
|[CSplitterWnd::SetScrollStyle](#setscrollstyle)|Especifica que o novo estilo de barra de rolagem da janela de divisor compartilhada suporte a barra de rolagem.|
|[CSplitterWnd::SplitColumn](#splitcolumn)|Indica onde uma janela do quadro se divide verticalmente.|
|[CSplitterWnd::SplitRow](#splitrow)|Indica onde uma janela do quadro se divide horizontalmente.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWnd::OnDraw](#ondraw)|Chamado pelo framework para desenhar a janela separadora.|
|[CSplitterWnd::OnDrawSplitter](#ondrawsplitter)|Renderiza uma imagem de uma janela separadora.|
|[CSplitterWnd::OnInvertTracker](#oninverttracker)|Processa a imagem de uma janela separadora para ser o mesmo tamanho e a forma como a janela do quadro.|

## <a name="remarks"></a>Comentários

Um painel geralmente é um objeto específico do aplicativo derivado [CView](../../mfc/reference/cview-class.md), mas pode ser qualquer [CWnd](../../mfc/reference/cwnd-class.md) objeto que tem a ID da janela filho apropriados.

Um `CSplitterWnd` objeto geralmente é inserido em um pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto. Criar um `CSplitterWnd` objeto usando as seguintes etapas:

1. Incorporar um `CSplitterWnd` variável de membro no quadro principal.

2. Substituição do quadro pai [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.

3. De dentro do substituído `OnCreateClient`, chamar o [Create](#create) ou [CreateStatic](#createstatic) função de membro de `CSplitterWnd`.

Chamar o `Create` a função de membro para criar uma janela divisora dinâmica. Uma janela divisora dinâmica normalmente é usada para criar e rolar um número de painéis individuais ou exibições do mesmo documento. O framework cria automaticamente um painel inicial para o divisor; em seguida, a estrutura cria, redimensiona e descarta os painéis adicionais conforme o usuário opere controles da janela divisora.

Quando você chama `Create`, você especificar uma largura mínima de linha altura e a coluna que determinam quando os painéis são pequenos demais para ser exibido. Depois de chamar `Create`, você pode ajustar esses valores mínimos por meio da chamada a [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) funções de membro.

Use também o `SetColumnInfo` e `SetRowInfo` funções de membro para definir uma largura "ideal" para uma coluna e a altura "ideal" para uma linha. Quando o framework exibe uma janela separadora, ele exibe primeiro quadro principal, em seguida, a janela separadora. A estrutura, em seguida, apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando no canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.

Todos os painéis em uma janela divisora dinâmica devem ser da mesma classe. Aplicativos familiares que dão suporte a janelas separadoras dinâmicas incluem o Microsoft Word e Microsoft Excel.

Use o `CreateStatic` a função de membro para criar uma janela separadora estático. O usuário pode alterar apenas o tamanho dos painéis em um divisor estático de janela, e não seu número ou ordem.

Especificamente, você deve criar painéis do todos os o separador estático quando você cria o divisor estático. Verifique se você criou todos os painéis antes do quadro pai `OnCreateClient` retorna da função de membro, ou ocorrerá na estrutura não exibir a janela corretamente.

O `CreateStatic` função membro inicializa automaticamente um separador estático com uma largura mínimo da linha de altura e a coluna 0. Depois de chamar `Create`, ajustar esses valores mínimos por meio da chamada a [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) funções de membro. Use também `SetColumnInfo` e `SetRowInfo` depois de chamar `CreateStatic` indicar desejado dimensões ideais de painel.

Os painéis individuais de um separador estático geralmente pertencem às classes diferentes. Para obter exemplos de janelas separadoras estáticas, consulte o editor de gráficos e o Gerenciador de arquivos do Windows.

Uma janela separadora dá suporte a barras de rolagem especial (além das barras de rolagem que podem ter a painéis). Essas barras de rolagem são filhos do `CSplitterWnd` do objeto e são compartilhadas com os painéis.

Você cria essas barras de rolagem especial ao criar janela separadora. Por exemplo, um `CSplitterWnd` que tem uma linha, duas colunas e o estilo WS_VSCROLL exibirá uma barra de rolagem vertical é compartilhada por dois painéis. Quando o usuário move a barra de rolagem, mensagens WM_VSCROLL são enviadas para os dois painéis. Quando os painéis de definir a posição da barra de rolagem, a barra de rolagem compartilhado é definida.

Para obter mais informações sobre janelas separadoras, consulte [29 de observação técnica](../../mfc/tn029-splitter-windows.md).

Para obter mais informações sobre como criar janelas separadoras dinâmicas, consulte:

- Exemplo MFC [Rabisco](../../overview/visual-cpp-samples.md)

- Exemplo MFC [VIEWEX](../../overview/visual-cpp-samples.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSplitterWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="activatenext"></a>  CSplitterWnd::ActivateNext

Chamado pelo framework para executar o comando próximo painel ou painel anterior.

```
virtual void ActivateNext(BOOL bPrev = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bPrev*<br/>
Indica qual janela para ativar. **TRUE** para anterior; **Falsos** para Avançar.

### <a name="remarks"></a>Comentários

Essa função membro é um comando de alto nível que é usado pelas [CView](../../mfc/reference/cview-class.md) classe delegar para o `CSplitterWnd` implementação.

##  <a name="canactivatenext"></a>  CSplitterWnd::CanActivateNext

Chamado pelo framework para verificar se o comando próximo painel ou painel anterior é possível no momento.

```
virtual BOOL CanActivateNext(BOOL bPrev = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bPrev*<br/>
Indica qual janela para ativar. **TRUE** para anterior; **Falsos** para Avançar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é um comando de alto nível que é usado pelas [CView](../../mfc/reference/cview-class.md) classe delegar para o `CSplitterWnd` implementação.

##  <a name="create"></a>  CSplitterWnd::Create

Para criar uma janela divisora dinâmica, chame o `Create` função de membro.

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

*pParentWnd*<br/>
A janela pai do quadro de janela separadora.

*nMaxRows*<br/>
O número máximo de linhas na janela do divisor. Esse valor não deve exceder 2.

*nMaxCols*<br/>
O número máximo de colunas na janela separadora. Esse valor não deve exceder 2.

*sizeMin*<br/>
Especifica o tamanho mínimo em que um painel pode ser exibido.

*pContext*<br/>
Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Na maioria dos casos, isso pode ser o *pContext* passado para a janela do quadro pai.

*dwStyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A ID de janela filho da janela. A ID pode ser AFX_IDW_PANE_FIRST, a menos que a janela divisora está aninhada em outra janela do divisor.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode inserir uma `CSplitterWnd` em uma pasta pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto por meio das seguintes etapas:

1. Incorporar um `CSplitterWnd` variável de membro no quadro principal.

1. Substituição do quadro pai [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.

1. Chame o `Create` função de membro de dentro do substituído `OnCreateClient`.

Quando você cria uma janela separadora de dentro de um quadro pai, passar o quadro de pai *pContext* parâmetro para a janela do divisor. Caso contrário, esse parâmetro pode ser NULL.

A largura inicial mínimo da linha de altura e a coluna de uma janela divisora dinâmica são definidas pela *sizeMin* parâmetro. Esses valores mínimos, que determinam se um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro.

Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Divisor Windows" no artigo [vários tipos de documentos, exibições e Windows de quadro](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#125](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_1.cpp)]

##  <a name="createscrollbarctrl"></a>  CSplitterWnd::CreateScrollBarCtrl

Chamado pelo framework para criar um controle de barra de rolagem compartilhado.

```
virtual BOOL CreateScrollBarCtrl(
    DWORD dwStyle,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A ID de janela filho da janela. A ID pode ser AFX_IDW_PANE_FIRST, a menos que a janela divisora está aninhada em outra janela do divisor.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir `CreateScrollBarCtrl` para incluir controles extras ao lado de uma barra de rolagem. O comportamento padrão é criar controles da barra de rolagem Windows normais.

##  <a name="createstatic"></a>  CSplitterWnd::CreateStatic

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

*pParentWnd*<br/>
A janela pai do quadro de janela separadora.

*nRows*<br/>
O número de linhas. Esse valor não deve exceder 16.

*nCols*<br/>
O número de colunas. Esse valor não deve exceder 16.

*dwStyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A ID de janela filho da janela. A ID pode ser AFX_IDW_PANE_FIRST, a menos que a janela divisora está aninhada em outra janela do divisor.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Um `CSplitterWnd` geralmente é inserido em um pai `CFrameWnd` ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) objeto por meio das seguintes etapas:

1. Incorporar um `CSplitterWnd` variável de membro no quadro principal.

1. Substituição do quadro pai `OnCreateClient` função de membro.

1. Chame o `CreateStatic` função de membro de dentro do substituído [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient).

Uma janela separadora estático contém um número fixo de painéis, geralmente a partir de classes diferentes.

Quando você cria uma janela separadora estático, ao mesmo tempo crie todos os seus painéis. O [CreateView](#createview) função de membro normalmente é usada para essa finalidade, mas você pode criar outras classes nonview também.

A mínimo da linha inicial altura e largura de coluna para uma janela separadora estático é 0. Esses valores mínimos, que determinam quando um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro.

Para adicionar barras de rolagem para uma janela separadora estáticos, adicionar os estilos WS_HSCROLL e WS_VSCROLL *dwStyle*.

Consulte "Divisor Windows" no artigo [vários tipos de documentos, exibições e Windows de quadro](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe para obter mais informações sobre janelas separadoras estáticas.

##  <a name="createview"></a>  CSplitterWnd::CreateView

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

*row*<br/>
Especifica a linha da janela separador no qual colocar a nova exibição.

*col*<br/>
Especifica a coluna de janela separador no qual colocar a nova exibição.

*pViewClass*<br/>
Especifica o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) da nova exibição.

*sizeInit*<br/>
Especifica o tamanho inicial da nova exibição.

*pContext*<br/>
Um ponteiro para um contexto de criação usado para criar o modo de exibição (normalmente, o *pContext* passado para o quadro de pai substituído [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) a função de membro no qual é a janela divisora que está sendo criado).

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Todos os painéis de uma janela separadora estático devem ser criados antes que o framework exibe o divisor.

A estrutura também chama essa função de membro para criar novos painéis, quando o usuário de uma janela divisora dinâmica divide um painel, linha ou coluna.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#4](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_2.cpp)]

##  <a name="csplitterwnd"></a>  CSplitterWnd::CSplitterWnd

Chamada para construir um `CSplitterWnd` objeto.

```
CSplitterWnd();
```

### <a name="remarks"></a>Comentários

Construir um `CSplitterWnd` objeto em duas etapas. Primeiro, chame o construtor, que cria o `CSplitterWnd` do objeto e, em seguida, chame o [Create](#create) a função de membro, que cria a janela de divisor e anexa-o para o `CSplitterWnd` objeto.

##  <a name="deletecolumn"></a>  CSplitterWnd::DeleteColumn

Exclui uma coluna da janela separadora.

```
virtual void DeleteColumn(int colDelete);
```

### <a name="parameters"></a>Parâmetros

*colDelete*<br/>
Especifica a coluna a ser excluído.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework para implementar a lógica da janela divisora dinâmica (ou seja, se a janela divisora tem o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, junto com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="deleterow"></a>  CSplitterWnd::DeleteRow

Exclui uma linha da janela separadora.

```
virtual void DeleteRow(int rowDelete);
```

### <a name="parameters"></a>Parâmetros

*rowDelete*<br/>
Especifica a linha a ser excluída.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework para implementar a lógica da janela divisora dinâmica (ou seja, se a janela divisora tem o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, junto com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="deleteview"></a>  CSplitterWnd::DeleteView

Exclui uma exibição da janela separadora.

```
virtual void DeleteView(
    int row,
    int col);
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica a linha da janela de divisor na qual se deseja excluir o modo de exibição.

*col*<br/>
Especifica a coluna de janela divisora na qual se deseja excluir o modo de exibição.

### <a name="remarks"></a>Comentários

Se a exibição ativa está sendo excluída, a próxima exibição se tornará ativa. A implementação padrão supõe que o modo de exibição serão automaticamente excluir na [PostNcDestroy](../../mfc/reference/cwnd-class.md#postncdestroy).

Essa função membro é chamada pelo framework para implementar a lógica da janela divisora dinâmica (ou seja, se a janela divisora tem o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, junto com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="dokeyboardsplit"></a>  CSplitterWnd::DoKeyboardSplit

Executa o comando, geralmente "divisão da janela". de divisão do teclado

```
virtual BOOL DoKeyboardSplit();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é um comando de alto nível que é usado pelas [CView](../../mfc/reference/cview-class.md) classe delegar para o `CSplitterWnd` implementação.

##  <a name="doscroll"></a>  CSplitterWnd::DoScroll

Executa a rolagem sincronizada de janelas separadoras.

```
virtual BOOL DoScroll(
    CView* pViewFrom,
    UINT nScrollCode,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewFrom*<br/>
Um ponteiro para o modo de exibição da qual se origina a mensagem de rolagem.

*nScrollCode*<br/>
Um código de barras de rolagem que indica que o usuário da solicitação de rolagem. Esse parâmetro é composto de duas partes: um byte de ordem inferior, que determina o tipo de rolagem horizontal ocorrendo, e um byte de ordem superior, que determina o tipo de rolagem vertical ocorrendo:

    - SB_BOTTOM rola para baixo.

    - Uma linha para baixo SB_LINEDOWN rola.

    - Uma linha para cima SB_LINEUP rola.

    - Uma página para baixo SB_PAGEDOWN rola.

    - Uma página para cima SB_PAGEUP rola.

    - SB_TOP rola para cima.

*bDoScroll*<br/>
Determina se a ação de rolagem especificada ocorre. Se *bDoScroll* é TRUE (ou seja, se uma janela filho existe e se as janelas de divisão tem um intervalo de rolagem), em seguida, a ação de rolagem especificada podem ocorrer; se *bDoScroll* for FALSE (ou seja, se nenhuma janela filho existe, ou os modos de exibição de divisão não tem nenhum intervalo de rolagem), em seguida, a rolagem não ocorrerá.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a rolagem sincronizada ocorre; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework para executar a rolagem sincronizada de janelas separadoras quando o modo de exibição recebe uma mensagem de rolagem. Substituição para exigir uma ação do usuário antes que a rolagem sincronizada é permitida.

##  <a name="doscrollby"></a>  CSplitterWnd::DoScrollBy

Rola pelas janelas separadoras por um determinado número de pixels.

```
virtual BOOL DoScrollBy(
    CView* pViewFrom,
    CSize sizeScroll,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewFrom*<br/>
Um ponteiro para o modo de exibição da qual se origina a mensagem de rolagem.

*sizeScroll*<br/>
Número de pixels a ser rolada horizontalmente e verticalmente.

*bDoScroll*<br/>
Determina se a ação de rolagem especificada ocorre. Se *bDoScroll* é TRUE (ou seja, se uma janela filho existe e se as janelas de divisão tem um intervalo de rolagem), em seguida, a ação de rolagem especificada podem ocorrer; se *bDoScroll* for FALSE (ou seja, se nenhuma janela filho existe, ou os modos de exibição de divisão não tem nenhum intervalo de rolagem), em seguida, a rolagem não ocorrerá.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a rolagem sincronizada ocorre; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework em resposta a uma mensagem de rolagem executar sincronizados rolagem das janelas de divisão por quantidade, em pixels, indicado por *sizeScroll*. Valores positivos indicam rolando para baixo e para a direita; valores negativos indicam rolar para cima e para a esquerda.

Substituição para exigir uma ação do usuário antes de permitir a rolagem.

##  <a name="getactivepane"></a>  CSplitterWnd::GetActivePane

Determina o painel ativo do foco ou da exibição ativa no quadro.

```
virtual CWnd* GetActivePane(
    int* pRow = NULL,
    int* pCol = NULL);
```

### <a name="parameters"></a>Parâmetros

*pRow*<br/>
Um ponteiro para um **int** para recuperar o número de linha do painel ativo.

*pCol*<br/>
Um ponteiro para um **int** para recuperar o número da coluna do painel ativo.

### <a name="return-value"></a>Valor de retorno

Ponteiro para o painel ativo. NULL se não existir nenhum painel ativo.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework para determinar o painel ativo em uma janela separadora. Substituição para exigir uma ação do usuário antes de acessar o painel ativo.

##  <a name="getcolumncount"></a>  CSplitterWnd::GetColumnCount

Retorna a contagem de colunas do painel atual.

```
int GetColumnCount() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número atual de colunas no divisor de. Para um separador estático, isso também será o número máximo de colunas.

##  <a name="getcolumninfo"></a>  CSplitterWnd::GetColumnInfo

Retorna informações sobre a coluna especificada.

```
void GetColumnInfo(
    int col,
    int& cxCur,
    int& cxMin) const;
```

### <a name="parameters"></a>Parâmetros

*col*<br/>
Especifica uma coluna.

*cxCur*<br/>
Uma referência a um **int** seja definida como a largura atual da coluna.

*cxMin*<br/>
Uma referência a um **int** seja definida como a largura mínima atual da coluna.

##  <a name="getpane"></a>  CSplitterWnd::GetPane

Retorna o painel na linha especificada e na coluna.

```
CWnd* GetPane(
    int row,
    int col) const;
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica uma linha.

*col*<br/>
Especifica uma coluna.

### <a name="return-value"></a>Valor de retorno

Retorna o painel na linha especificada e na coluna. O painel retornado é geralmente um [CView](../../mfc/reference/cview-class.md)-classe derivada.

##  <a name="getrowcount"></a>  CSplitterWnd::GetRowCount

Retorna a contagem de linhas do painel atual.

```
int GetRowCount() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número atual de linhas na janela do divisor. Para uma janela separadora estático, isso também será o número máximo de linhas.

##  <a name="getrowinfo"></a>  CSplitterWnd::GetRowInfo

Retorna informações sobre a linha especificada.

```
void GetRowInfo(
    int row,
    int& cyCur,
    int& cyMin) const;
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica uma linha.

*cyCur*<br/>
Referência a **int** seja definida como a altura atual da linha em pixels.

*cyMin*<br/>
Referência a **int** seja definida como a altura mínima atual da linha em pixels.

### <a name="remarks"></a>Comentários

Chame essa função de membro para obter informações sobre a linha especificada. O *cyCur* parâmetro é preenchido com a altura atual da linha especificada, e *cyMin* é preenchida com a altura mínima da linha.

##  <a name="getscrollstyle"></a>  CSplitterWnd::GetScrollStyle

Retorna o estilo de barra de rolagem compartilhado para a janela do divisor.

```
DWORD GetScrollStyle() const;
```

### <a name="return-value"></a>Valor de retorno

Um ou mais dos seguintes janelas de estilo sinalizadores, se for bem-sucedido:

    - WS_HSCROLL se que o divisor atualmente gerencia compartilhada barras de rolagem horizontal.

    - WS_VSCROLL se que o divisor atualmente gerencia compartilhada barras de rolagem vertical.

Se for zero, a janela separadora não gerencia atualmente barras de rolagem compartilhado.

##  <a name="idfromrowcol"></a>  CSplitterWnd::IdFromRowCol

Obtém o filho para o painel na linha especificada e na coluna ID da janela.

```
int IdFromRowCol(
    int row,
    int col) const;
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica a linha de janela do divisor.

*col*<br/>
Especifica a coluna de janela do divisor.

### <a name="return-value"></a>Valor de retorno

A ID de janela filho para o painel.

### <a name="remarks"></a>Comentários

Essa função membro é usada para a criação de nonviews como painéis e pode ser chamada antes que o painel existe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#5](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_3.cpp)]

##  <a name="ischildpane"></a>  CSplitterWnd::IsChildPane

Determina se *Apropriei* atualmente é um painel filho dessa janela divisor.

```
BOOL IsChildPane(
    CWnd* pWnd,
    int* pRow,
    int* pCol);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto a ser testado.

*pRow*<br/>
Um ponteiro para um **int** no qual armazenar o número da linha.

*pCol*<br/>
Um ponteiro para um **int** para armazenar um número de coluna.

### <a name="return-value"></a>Valor de retorno

Se for diferente de zero, *Apropriei* atualmente é um painel filho dessa janela splitter, e *pRow* e *pCol* são preenchidas com a posição do painel na janela separadora. Se *Apropriei* não é um painel filho dessa janela divisora, 0 será retornado.

### <a name="remarks"></a>Comentários

Nas versões de Visual C++ anteriores à 6.0, essa função foi definida como

`BOOL IsChildPane(CWnd* pWnd, int& row, int& col);`

Esta versão agora é obsoleto e não deve ser usado.

##  <a name="istracking"></a>  CSplitterWnd::IsTracking

Chame essa função de membro para determinar se a barra de divisão na janela está sendo movida no momento.

```
BOOL IsTracking();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se uma operação de divisão está em andamento. Caso contrário, 0.

##  <a name="ondrawsplitter"></a>  CSplitterWnd::OnDrawSplitter

Renderiza uma imagem de uma janela separadora.

```
virtual void OnDrawSplitter(
    CDC* pDC,
    ESplitType nType,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto de dispositivo no qual desenhar. Se *pDC* for NULL, em seguida, [CWnd::RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) é chamado pelo framework e nenhuma divisão janela é desenhada.

*nType*<br/>
Um valor da `enum ESplitType`, que pode ser um dos seguintes:

    - `splitBox` Caixa de arrastar o divisor.

    - `splitBar` A barra que aparece entre as janelas de divisão de dois.

    - `splitIntersection` A interseção das janelas de divisão. Esse elemento não será chamado quando em execução no Windows 95/98.

    - `splitBorder` Os limites da janela de divisão.

*rect*<br/>
Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica o tamanho e a forma das janelas de divisão.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework para desenhar e especifique as características exatas de uma janela separadora. Substituir `OnDrawSplitter` para a personalização avançada das imagens para os vários componentes gráficas de uma janela separadora. As imagens padrão é semelhante ao divisor na Microsoft Works para Windows ou o Microsoft Windows 95/98, em que as interseções das barras de divisor são mescladas em conjunto.

Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Divisor Windows" no artigo [vários tipos de documentos, exibições e Windows de quadro](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.

##  <a name="oninverttracker"></a>  CSplitterWnd::OnInvertTracker

Processa a imagem de uma janela separadora para ser o mesmo tamanho e a forma como a janela do quadro.

```
virtual void OnInvertTracker(const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Referência a um `CRect` objeto que especifica o retângulo de controle.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework durante o redimensionamento de divisores. Substituir `OnInvertTracker` para a personalização avançada das imagens de janela separadora. As imagens padrão é semelhante ao divisor na Microsoft Works para Windows ou o Microsoft Windows 95/98, em que as interseções das barras de divisor são mescladas em conjunto.

Para obter mais informações sobre janelas separadoras dinâmicas, consulte "Divisor Windows" no artigo [vários tipos de documentos, exibições e Windows de quadro](../../mfc/multiple-document-types-views-and-frame-windows.md), [29 de observação técnica](../../mfc/tn029-splitter-windows.md)e o `CSplitterWnd` visão geral da classe.

##  <a name="recalclayout"></a>  CSplitterWnd::RecalcLayout

Chamada para exibir novamente a janela divisora depois de ajustar o tamanho de linha ou coluna.

```
virtual void RecalcLayout();
```

### <a name="remarks"></a>Comentários

Chame essa função de membro para exibir corretamente novamente a janela divisora após você ter ajustado os tamanhos de linha e coluna com o [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) funções de membro. Se você alterar os tamanhos de linha e coluna como parte do processo de criação antes da janela do divisor está visível, não é necessário chamar essa função de membro.

O framework chama essa função membro sempre que o usuário redimensiona a janela do divisor ou mover uma divisão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CSplitterWnd::SetColumnInfo](#setcolumninfo).

##  <a name="setactivepane"></a>  CSplitterWnd::SetActivePane

Define um painel para ser o Active Directory no quadro.

```
virtual void SetActivePane(
    int row,
    int col,
    CWnd* pWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Se *Apropriei* for NULL, que especifica a linha no painel de ativos.

*col*<br/>
Se *Apropriei* for NULL, que especifica a coluna no painel de ativos.

*pWnd*<br/>
Um ponteiro para um `CWnd` objeto. Se for NULL, o painel especificado por *linha* e *col* seja definida como ativa. Se não for NULL, especifica o painel que seja definido como ativo.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework para definir um painel como ativa quando o usuário altera o foco para um painel dentro da janela de quadro. Você pode chamar explicitamente `SetActivePane` para alterar o foco para a exibição especificada.

Especifique o painel, fornecendo linha e coluna, **ou** fornecendo *Apropriei*.

##  <a name="setcolumninfo"></a>  CSplitterWnd::SetColumnInfo

Chamada para definir as informações da coluna especificada.

```
void SetColumnInfo(
    int col,
    int cxIdeal,
    int cxMin);
```

### <a name="parameters"></a>Parâmetros

*col*<br/>
Especifica uma coluna de janela do divisor.

*cxIdeal*<br/>
Especifica uma largura ideal da coluna da janela de divisor em pixels.

*cxMin*<br/>
Especifica uma largura mínima da coluna da janela de divisor em pixels.

### <a name="remarks"></a>Comentários

Chame essa função de membro para definir uma nova largura mínima e a largura ideal para uma coluna. O valor mínimo da coluna determina quando a coluna será muito pequena para ser exibido.

Quando o framework exibe a janela do divisor, ele apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando no canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#6](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_4.cpp)]

##  <a name="setrowinfo"></a>  CSplitterWnd::SetRowInfo

Chamada para definir as informações da linha especificada.

```
void SetRowInfo(
    int row,
    int cyIdeal,
    int cyMin);
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica uma linha da janela de divisor.

*cyIdeal*<br/>
Especifica uma altura ideal da linha da janela de divisor em pixels.

*cyMin*<br/>
Especifica uma altura mínima da linha da janela de divisor em pixels.

### <a name="remarks"></a>Comentários

Chame essa função de membro para definir uma nova altura mínima e a altura ideal para uma linha. O valor mínimo da linha determina quando uma linha será muito pequena para ser exibido.

Quando o framework exibe a janela do divisor, ele apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando no canto superior esquerdo para o canto inferior direito da área de cliente da janela separadora.

##  <a name="setscrollstyle"></a>  CSplitterWnd::SetScrollStyle

Especifica que o novo estilo de rolagem da janela de divisor compartilhada suporte a barra de rolagem.

```
void SetScrollStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
O novo estilo de rolagem da janela de divisor compartilhado suporte a barra de rolagem, que pode ser um dos seguintes valores:

- WS_HSCROLL criar/Mostrar horizontal compartilhado barras de rolagem.

- WS_VSCROLL criar/Mostrar vertical compartilhado barras de rolagem.

### <a name="remarks"></a>Comentários

Depois que uma barra de rolagem é criada ele não será destruído, mesmo se `SetScrollStyle` for chamado sem esse estilo; em vez disso, essas barras de rolagem estão ocultos. Isso permite que as barras de rolagem manter seu estado, mesmo que eles estejam ocultos. Depois de chamar `SetScrollStyle` é necessário chamar [RecalcLayout](#recalclayout) para todas as alterações entrem em vigor.

##  <a name="splitcolumn"></a>  CSplitterWnd::SplitColumn

Indica onde uma janela do quadro se divide verticalmente.

```
virtual BOOL SplitColumn(int cxBefore);
```

### <a name="parameters"></a>Parâmetros

*cxBefore*<br/>
A posição, em pixels, antes que a divisão ocorre.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é chamada quando uma janela divisora vertical é criada. `SplitColumn` indica o local padrão onde a divisão ocorre.

`SplitColumn` é chamado pelo framework para implementar a lógica da janela divisora dinâmica (ou seja, se a janela divisora tem o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, junto com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="splitrow"></a>  CSplitterWnd::SplitRow

Indica onde uma janela do quadro se divide horizontalmente.

```
virtual BOOL SplitRow(int cyBefore);
```

### <a name="parameters"></a>Parâmetros

*cyBefore*<br/>
A posição, em pixels, antes que a divisão ocorre.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é chamada quando uma janela divisora horizontal é criada. `SplitRow` indica o local padrão onde a divisão ocorre.

`SplitRow` é chamado pelo framework para implementar a lógica da janela divisora dinâmica (ou seja, se a janela divisora tem o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, junto com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="ondraw"></a>  CSplitterWnd::OnDraw

Chamado pelo framework para desenhar a janela separadora.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Exemplo MFC VIEWEX](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
