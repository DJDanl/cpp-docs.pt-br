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
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78890948"
---
# <a name="csplitterwnd-class"></a>Classe CSplitterWnd

Fornece a funcionalidade de uma janela divisora, que é uma janela que contém vários painéis.

## <a name="syntax"></a>Sintaxe

```
class CSplitterWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSplitterWnd:: CSplitterWnd](#csplitterwnd)|Chamada para construir um objeto de `CSplitterWnd`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSplitterWnd:: ActivateNext](#activatenext)|Executa o próximo painel ou comando do painel anterior.|
|[CSplitterWnd:: CanActivateNext](#canactivatenext)|Verifica se o comando próximo painel ou painel anterior é possível no momento.|
|[CSplitterWnd:: criar](#create)|Chame para criar uma janela de divisão dinâmica e anexe-a ao objeto `CSplitterWnd`.|
|[CSplitterWnd:: CreateScrollBarCtrl](#createscrollbarctrl)|Cria um controle de barra de rolagem compartilhado.|
|[CSplitterWnd:: CreateStatic](#createstatic)|Chame para criar uma janela divisora estática e anexe-a ao objeto `CSplitterWnd`.|
|[CSplitterWnd:: CreateView](#createview)|Chame para criar um painel em uma janela divisora.|
|[CSplitterWnd::D eleteColumn](#deletecolumn)|Exclui uma coluna da janela divisora.|
|[CSplitterWnd::D eleteRow](#deleterow)|Exclui uma linha da janela divisora.|
|[CSplitterWnd::D eleteView](#deleteview)|Exclui uma exibição da janela divisora.|
|[CSplitterWnd::D oKeyboardSplit](#dokeyboardsplit)|Executa o comando de divisão do teclado, geralmente "divisão da janela".|
|[CSplitterWnd::D oScroll](#doscroll)|Executa a rolagem sincronizada de janelas divididas.|
|[CSplitterWnd::D oScrollBy](#doscrollby)|Rola as janelas divididas por um determinado número de pixels.|
|[CSplitterWnd:: GetActivePane](#getactivepane)|Determina o painel ativo do foco ou da exibição ativa no quadro.|
|[CSplitterWnd:: GetColumnCount](#getcolumncount)|Retorna a contagem de colunas do painel atual.|
|[CSplitterWnd:: GetColumnInfo](#getcolumninfo)|Retorna informações sobre a coluna especificada.|
|[CSplitterWnd:: GetPane](#getpane)|Retorna o painel na linha e coluna especificadas.|
|[CSplitterWnd:: GetRowCount](#getrowcount)|Retorna a contagem de linhas do painel atual.|
|[CSplitterWnd:: GetRowInfo](#getrowinfo)|Retorna informações sobre a linha especificada.|
|[CSplitterWnd:: getscrollstyle](#getscrollstyle)|Retorna o estilo de barra de rolagem compartilhada.|
|[CSplitterWnd:: IdFromRowCol](#idfromrowcol)|Retorna a ID da janela filho do painel na linha e coluna especificadas.|
|[CSplitterWnd:: IsChildPane](#ischildpane)|Chame para determinar se a janela é atualmente um painel filho desta janela de divisão.|
|[CSplitterWnd:: istracking](#istracking)|Determina se a barra de divisão está sendo movida no momento.|
|[CSplitterWnd:: RecalcLayout](#recalclayout)|Chame para reexibir a janela do separador depois de ajustar o tamanho da linha ou da coluna.|
|[CSplitterWnd:: SetActivePane](#setactivepane)|Define um painel para ser o ativo no quadro.|
|[CSplitterWnd:: SetColumnInfo](#setcolumninfo)|Chame para definir as informações de coluna especificadas.|
|[CSplitterWnd:: SetRowInfo](#setrowinfo)|Chame para definir as informações de linha especificadas.|
|[CSplitterWnd:: SetScrollStyle](#setscrollstyle)|Especifica o novo estilo de barra de rolagem para o suporte à barra de rolagem compartilhada da janela do Splitter.|
|[CSplitterWnd:: SplitColumn](#splitcolumn)|Indica onde uma janela do quadro se divide verticalmente.|
|[CSplitterWnd:: SplitRow](#splitrow)|Indica onde uma janela do quadro se divide horizontalmente.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSplitterWnd:: OnDraw](#ondraw)|Chamado pelo Framework para desenhar a janela separadora.|
|[CSplitterWnd:: OnDrawSplitter](#ondrawsplitter)|Renderiza uma imagem de uma janela de divisão.|
|[CSplitterWnd:: OnInvertTracker](#oninverttracker)|Renderiza a imagem de uma janela de divisão para ter o mesmo tamanho e forma que a janela do quadro.|

## <a name="remarks"></a>Comentários

Um painel é geralmente um objeto específico do aplicativo derivado de [cvisualização](../../mfc/reference/cview-class.md), mas pode ser qualquer objeto [CWnd](../../mfc/reference/cwnd-class.md) que tenha a ID da janela filho apropriada.

Um objeto `CSplitterWnd` geralmente é inserido em um objeto pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) . Crie um objeto `CSplitterWnd` usando as seguintes etapas:

1. Insira uma variável de membro `CSplitterWnd` no quadro pai.

2. Substitua a função de membro [CFrameWnd:: OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) do quadro pai.

3. De dentro do `OnCreateClient`substituído, chame a função de membro [Create](#create) ou [createstatic](#createstatic) de `CSplitterWnd`.

Chame a função de membro `Create` para criar uma janela de divisão dinâmica. Uma janela separadora dinâmica normalmente é usada para criar e rolar vários painéis ou exibições individuais do mesmo documento. A estrutura cria automaticamente um painel inicial para o divisor; em seguida, a estrutura cria, redimensiona e descarta painéis adicionais à medida que o usuário opera os controles da janela do divisor.

Ao chamar `Create`, você especifica uma altura mínima de linha e largura de coluna que determinam quando os painéis são muito pequenos para serem totalmente exibidos. Depois de chamar `Create`, você pode ajustar esses mínimos chamando as funções de membro [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) .

Use também as funções de membro `SetColumnInfo` e `SetRowInfo` para definir uma largura "ideal" para uma coluna e a altura "ideal" para uma linha. Quando a estrutura exibe uma janela divisor, ela primeiro exibe o quadro pai e, em seguida, a janela separadora. Em seguida, a estrutura apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo para o inferior direito da área do cliente da janela do divisor.

Todos os painéis em uma janela de divisor dinâmico devem ser da mesma classe. Aplicativos conhecidos que dão suporte a janelas de divisor dinâmico incluem o Microsoft Word e o Microsoft Excel.

Use a função membro `CreateStatic` para criar uma janela divisora estática. O usuário pode alterar apenas o tamanho dos painéis em uma janela divisora estática, e não seu número ou ordem.

Você deve criar especificamente todos os painéis do divisor estático ao criar o divisor estático. Certifique-se de criar todos os painéis antes de o quadro pai `OnCreateClient` função membro retornar, ou a estrutura não exibirá a janela corretamente.

A função de membro `CreateStatic` inicializa automaticamente um divisor estático com uma altura mínima de linha e largura de coluna 0. Depois de chamar `Create`, ajuste esses mínimos chamando as funções de membro [SetColumnInfo](#setcolumninfo) e [SetRowInfo](#setrowinfo) . Além disso, use `SetColumnInfo` e `SetRowInfo` depois de chamar `CreateStatic` para indicar as dimensões do painel ideal desejado.

Os painéis individuais de um divisor estático geralmente pertencem a classes diferentes. Para obter exemplos de janelas de divisores estáticos, consulte o editor de gráficos e o Gerenciador de arquivos do Windows.

Uma janela divisor dá suporte a barras de rolagem especiais (além das barras de rolagem que os painéis podem ter). Essas barras de rolagem são filhos do objeto `CSplitterWnd` e são compartilhadas com os painéis.

Você cria essas barras de rolagem especiais ao criar a janela separadora. Por exemplo, um `CSplitterWnd` que tem uma linha, duas colunas e o estilo de WS_VSCROLL exibirá uma barra de rolagem vertical que é compartilhada por dois painéis. Quando o usuário move a barra de rolagem, WM_VSCROLL mensagens são enviadas para ambos os painéis. Quando os painéis definem a posição da barra de rolagem, a barra de rolagem compartilhada é definida.

Para obter mais informações sobre janelas de Splitter, consulte a [Nota técnica 29](../../mfc/tn029-splitter-windows.md).

Para obter mais informações sobre como criar janelas de divisão dinâmica, consulte:

- [Rabisco](../../overview/visual-cpp-samples.md) de exemplo do MFC

- Exemplo de [VIEWEX](../../overview/visual-cpp-samples.md)do MFC.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSplitterWnd`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxext. h

##  <a name="activatenext"></a>CSplitterWnd:: ActivateNext

Chamado pelo Framework para executar o próximo painel ou comando de painel anterior.

```
virtual void ActivateNext(BOOL bPrev = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bPrev*<br/>
Indica qual janela deve ser ativada. **Verdadeiro** para anterior; **False** para avançar.

### <a name="remarks"></a>Comentários

Essa função de membro é um comando de alto nível que é usado pela classe [cvisualização](../../mfc/reference/cview-class.md) para delegar à implementação de `CSplitterWnd`.

##  <a name="canactivatenext"></a>CSplitterWnd:: CanActivateNext

Chamado pelo Framework para verificar se o comando próximo painel ou painel anterior é possível no momento.

```
virtual BOOL CanActivateNext(BOOL bPrev = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bPrev*<br/>
Indica qual janela deve ser ativada. **Verdadeiro** para anterior; **False** para avançar.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é um comando de alto nível que é usado pela classe [cvisualização](../../mfc/reference/cview-class.md) para delegar à implementação de `CSplitterWnd`.

##  <a name="create"></a>CSplitterWnd:: criar

Para criar uma janela divisora dinâmica, chame a função membro `Create`.

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
A janela do quadro pai da janela do separador.

*nMaxRows*<br/>
O número máximo de linhas na janela divisora. Este valor não deve exceder 2.

*nMaxCols*<br/>
O número máximo de colunas na janela do separador. Este valor não deve exceder 2.

*sizeMin*<br/>
Especifica o tamanho mínimo no qual um painel pode ser exibido.

*pContext*<br/>
Um ponteiro para uma estrutura [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) . Na maioria dos casos, isso pode ser o *pContext* passado para a janela do quadro pai.

*dwStyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A ID da janela filho da janela. A ID pode ser AFX_IDW_PANE_FIRST, a menos que a janela do separador seja aninhada dentro de outra janela do Splitter.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode inserir um `CSplitterWnd` em um objeto pai [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) realizando as seguintes etapas:

1. Insira uma variável de membro `CSplitterWnd` no quadro pai.

1. Substitua a função de membro [CFrameWnd:: OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) do quadro pai.

1. Chame a função membro `Create` de dentro do `OnCreateClient`substituído.

Quando você cria uma janela de Splitter de dentro de um quadro pai, passe o parâmetro *pContext* do quadro pai para a janela separadora. Caso contrário, esse parâmetro pode ser nulo.

A altura mínima inicial da linha e a largura da coluna de uma janela de divisão dinâmica são definidas pelo parâmetro *sizeMin* . Esses mínimos, que determinam se um painel é muito pequeno para ser mostrado em sua totalidade, pode ser alterado com as funções de membro [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) .

Para obter mais informações sobre janelas de divisores dinâmicos, consulte "janelas de divisão" no artigo [vários tipos de documento, exibições e janelas de quadros](../../mfc/multiple-document-types-views-and-frame-windows.md), [Nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe `CSplitterWnd`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCWindowing#125](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_1.cpp)]

##  <a name="createscrollbarctrl"></a>CSplitterWnd:: CreateScrollBarCtrl

Chamado pelo Framework para criar um controle de barra de rolagem compartilhado.

```
virtual BOOL CreateScrollBarCtrl(
    DWORD dwStyle,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A ID da janela filho da janela. A ID pode ser AFX_IDW_PANE_FIRST, a menos que a janela do separador seja aninhada dentro de outra janela do Splitter.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua `CreateScrollBarCtrl` para incluir controles adicionais ao lado de uma barra de rolagem. O comportamento padrão é criar controles normais de barra de rolagem do Windows.

##  <a name="createstatic"></a>CSplitterWnd:: CreateStatic

Para criar uma janela divisora estática, chame a função membro `CreateStatic`.

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
A janela do quadro pai da janela do separador.

*nRows*<br/>
O número de linhas. Esse valor não deve exceder 16.

*nCols*<br/>
O número de colunas. Esse valor não deve exceder 16.

*dwStyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A ID da janela filho da janela. A ID pode ser AFX_IDW_PANE_FIRST, a menos que a janela do separador seja aninhada dentro de outra janela do Splitter.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma `CSplitterWnd` geralmente é inserida em um objeto `CFrameWnd` ou [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) pai, realizando as seguintes etapas:

1. Insira uma variável de membro `CSplitterWnd` no quadro pai.

1. Substitua a função membro `OnCreateClient` do quadro pai.

1. Chame a função membro `CreateStatic` de dentro do [CFrameWnd:: OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient)substituído.

Uma janela divisora estática contém um número fixo de painéis, geralmente de classes diferentes.

Ao criar uma janela divisora estática, você deve ao mesmo tempo criar todos os seus painéis. A função de membro [CreateView](#createview) geralmente é usada para essa finalidade, mas você também pode criar outras classes não de exibição.

A altura mínima inicial da linha e a largura da coluna para uma janela divisora estática é 0. Esses mínimos, que determinam quando um painel é muito pequeno para serem mostrados em sua totalidade, podem ser alterados com as funções de membro [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) .

Para adicionar barras de rolagem a uma janela separadora estática, adicione os estilos de WS_HSCROLL e de WS_VSCROLL a *dwStyle*.

Consulte "janelas de divisão" no artigo [vários tipos de documento, exibições e janelas de quadro](../../mfc/multiple-document-types-views-and-frame-windows.md), [Nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe `CSplitterWnd` para obter mais informações sobre janelas separadoras estáticas.

##  <a name="createview"></a>CSplitterWnd:: CreateView

Cria os painéis para uma janela divisora estática.

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
Especifica a linha de janela do separador na qual posicionar a nova exibição.

*col*<br/>
Especifica a coluna de janela do separador na qual posicionar a nova exibição.

*pViewClass*<br/>
Especifica o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) da nova exibição.

*sizeInit*<br/>
Especifica o tamanho inicial da nova exibição.

*pContext*<br/>
Um ponteiro para um contexto de criação usado para criar a exibição (geralmente o *pContext* passado para a função de membro [CFrameWnd:: OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) do quadro pai na qual a janela do separador está sendo criada).

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Todos os painéis de uma janela separadora estática devem ser criados antes de a estrutura exibir o divisor.

A estrutura também chama essa função de membro para criar novos painéis quando o usuário de uma janela de divisão dinâmica divide um painel, linha ou coluna.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCWindowing#4](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_2.cpp)]

##  <a name="csplitterwnd"></a>CSplitterWnd:: CSplitterWnd

Chamada para construir um objeto de `CSplitterWnd`.

```
CSplitterWnd();
```

### <a name="remarks"></a>Comentários

Construa um objeto `CSplitterWnd` em duas etapas. Primeiro, chame o construtor, que cria o objeto `CSplitterWnd` e, em seguida, chame a função [criar](#create) membro, que cria a janela separadora e a anexa ao objeto `CSplitterWnd`.

##  <a name="deletecolumn"></a>CSplitterWnd::D eleteColumn

Exclui uma coluna da janela divisora.

```
virtual void DeleteColumn(int colDelete);
```

### <a name="parameters"></a>Parâmetros

*colDelete*<br/>
Especifica a coluna a ser excluída.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo Framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela do separador tiver o estilo de SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="deleterow"></a>CSplitterWnd::D eleteRow

Exclui uma linha da janela divisora.

```
virtual void DeleteRow(int rowDelete);
```

### <a name="parameters"></a>Parâmetros

*Excluir*<br/>
Especifica a linha a ser excluída.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo Framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela do separador tiver o estilo de SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="deleteview"></a>CSplitterWnd::D eleteView

Exclui uma exibição da janela divisora.

```
virtual void DeleteView(
    int row,
    int col);
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica a linha de janela do separador na qual excluir a exibição.

*col*<br/>
Especifica a coluna de janela do separador na qual excluir a exibição.

### <a name="remarks"></a>Comentários

Se o modo de exibição ativo estiver sendo excluído, a próxima exibição ficará ativa. A implementação padrão pressupõe que a exibição será excluída automaticamente no [PostNcDestroy](../../mfc/reference/cwnd-class.md#postncdestroy).

Essa função de membro é chamada pelo Framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela do separador tiver o estilo de SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="dokeyboardsplit"></a>CSplitterWnd::D oKeyboardSplit

Executa o comando de divisão do teclado, geralmente "divisão da janela".

```
virtual BOOL DoKeyboardSplit();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é um comando de alto nível que é usado pela classe [cvisualização](../../mfc/reference/cview-class.md) para delegar à implementação de `CSplitterWnd`.

##  <a name="doscroll"></a>CSplitterWnd::D oScroll

Executa a rolagem sincronizada de janelas divididas.

```
virtual BOOL DoScroll(
    CView* pViewFrom,
    UINT nScrollCode,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewFrom*<br/>
Um ponteiro para a exibição da qual a mensagem de rolagem se origina.

*nScrollCode*<br/>
Um código de barra de rolagem que indica a solicitação de rolagem do usuário. Esse parâmetro é composto por duas partes: um byte de ordem inferior, que determina o tipo de rolagem que ocorre horizontalmente e um byte de ordem superior, que determina o tipo de rolagem que ocorre verticalmente:

    - SB_BOTTOM Rola para a parte inferior.

    - SB_LINEDOWN rola uma linha para baixo.

    - SB_LINEUP rola uma linha para cima.

    - SB_PAGEDOWN rola uma página para baixo.

    - SB_PAGEUP Rola uma página para cima.

    - SB_TOP rola para a parte superior.

*bDoScroll*<br/>
Determina se a ação de rolagem especificada ocorre. Se *bDoScroll* for verdadeiro (ou seja, se uma janela filho existir e se as janelas divididas tiverem um intervalo de rolagem), a ação de rolagem especificada poderá ocorrer; Se *bDoScroll* for false (ou seja, se não existir nenhuma janela filho ou se as exibições divididas não tiverem nenhum intervalo de rolagem), a rolagem não ocorrerá.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a rolagem sincronizada ocorrer; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo Framework para executar a rolagem sincronizada de janelas divididas quando a exibição recebe uma mensagem de rolagem. Substitua para exigir uma ação do usuário antes que a rolagem sincronizada seja permitida.

##  <a name="doscrollby"></a>CSplitterWnd::D oScrollBy

Rola as janelas divididas por um determinado número de pixels.

```
virtual BOOL DoScrollBy(
    CView* pViewFrom,
    CSize sizeScroll,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewFrom*<br/>
Um ponteiro para a exibição da qual a mensagem de rolagem se origina.

*sizeScroll*<br/>
Número de pixels a serem rolados horizontal e verticalmente.

*bDoScroll*<br/>
Determina se a ação de rolagem especificada ocorre. Se *bDoScroll* for verdadeiro (ou seja, se uma janela filho existir e se as janelas divididas tiverem um intervalo de rolagem), a ação de rolagem especificada poderá ocorrer; Se *bDoScroll* for false (ou seja, se não existir nenhuma janela filho ou se as exibições divididas não tiverem nenhum intervalo de rolagem), a rolagem não ocorrerá.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a rolagem sincronizada ocorrer; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pela estrutura em resposta a uma mensagem de rolagem, para executar a rolagem sincronizada das janelas divididas pela quantidade, em pixels, indicada por *sizeScroll*. Valores positivos indicam a rolagem para baixo e para a direita; valores negativos indicam rolar para cima e para a esquerda.

Substitua para exigir uma ação do usuário antes de permitir a rolagem.

##  <a name="getactivepane"></a>CSplitterWnd:: GetActivePane

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

### <a name="return-value"></a>Valor retornado

Ponteiro para o painel ativo. NULL se não houver painel ativo.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo Framework para determinar o painel ativo em uma janela divisora. Substitua para exigir uma ação do usuário antes de obter o painel ativo.

##  <a name="getcolumncount"></a>CSplitterWnd:: GetColumnCount

Retorna a contagem de colunas do painel atual.

```
int GetColumnCount() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número atual de colunas no divisor. Para um divisor estático, esse também será o número máximo de colunas.

##  <a name="getcolumninfo"></a>CSplitterWnd:: GetColumnInfo

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
Uma referência a um **int** a ser definida como a largura atual da coluna.

*cxMin*<br/>
Uma referência a um **int** a ser definida como a largura mínima atual da coluna.

##  <a name="getpane"></a>CSplitterWnd:: GetPane

Retorna o painel na linha e coluna especificadas.

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

### <a name="return-value"></a>Valor retornado

Retorna o painel na linha e coluna especificadas. O painel retornado geralmente é uma classe derivada de [cvisualização](../../mfc/reference/cview-class.md).

##  <a name="getrowcount"></a>CSplitterWnd:: GetRowCount

Retorna a contagem de linhas do painel atual.

```
int GetRowCount() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número atual de linhas na janela do separador. Para uma janela divisora estática, esse também será o número máximo de linhas.

##  <a name="getrowinfo"></a>CSplitterWnd:: GetRowInfo

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
Referência a **int** a ser definida como a altura atual da linha em pixels.

*cyMin*<br/>
Referência a **int** a ser definida como a altura mínima atual da linha em pixels.

### <a name="remarks"></a>Comentários

Chame essa função de membro para obter informações sobre a linha especificada. O parâmetro *cyCur* é preenchido com a altura atual da linha especificada e *cyMin* é preenchido com a altura mínima da linha.

##  <a name="getscrollstyle"></a>CSplitterWnd:: getscrollstyle

Retorna o estilo de barra de rolagem compartilhada para a janela separadora.

```
DWORD GetScrollStyle() const;
```

### <a name="return-value"></a>Valor retornado

Um ou mais dos seguintes sinalizadores de estilo do Windows, se for bem-sucedido:

    - WS_HSCROLL se o divisor atualmente gerencia as barras de rolagem horizontal compartilhadas.

    - WS_VSCROLL se o divisor atualmente gerencia as barras de rolagem vertical compartilhadas.

Se for zero, a janela separadora não gerenciará nenhuma barra de rolagem compartilhada no momento.

##  <a name="idfromrowcol"></a>CSplitterWnd:: IdFromRowCol

Obtém a ID da janela filho do painel na linha e coluna especificadas.

```
int IdFromRowCol(
    int row,
    int col) const;
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica a linha da janela do separador.

*col*<br/>
Especifica a coluna de janela do separador.

### <a name="return-value"></a>Valor retornado

A ID da janela filho do painel.

### <a name="remarks"></a>Comentários

Essa função de membro é usada para criar não exibições como painéis e pode ser chamada antes que o painel exista.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCWindowing#5](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_3.cpp)]

##  <a name="ischildpane"></a>CSplitterWnd:: IsChildPane

Determina se *pWnd* é atualmente um painel filho desta janela de divisão.

```
BOOL IsChildPane(
    CWnd* pWnd,
    int* pRow,
    int* pCol);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) a ser testado.

*pRow*<br/>
Um ponteiro para um **int** no qual armazenar o número da linha.

*pCol*<br/>
Um ponteiro para um **int** no qual armazenar um número de coluna.

### <a name="return-value"></a>Valor retornado

Se for diferente de zero, *pWnd* é atualmente um painel filho desta janela separadora, e *Prow* e *pCol* são preenchidos com a posição do painel na janela separadora. Se *pWnd* não for um painel filho desta janela de divisão, 0 será retornado.

### <a name="remarks"></a>Comentários

Em versões C++ visuais anteriores a 6,0, essa função foi definida como

`BOOL IsChildPane(CWnd* pWnd, int& row, int& col);`

Esta versão agora é obsoleta e não deve ser usada.

##  <a name="istracking"></a>CSplitterWnd:: istracking

Chame essa função de membro para determinar se a barra de divisão na janela está sendo movida no momento.

```
BOOL IsTracking();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se uma operação de divisor estiver em andamento; caso contrário, 0.

##  <a name="ondrawsplitter"></a>CSplitterWnd:: OnDrawSplitter

Renderiza uma imagem de uma janela de divisão.

```
virtual void OnDrawSplitter(
    CDC* pDC,
    ESplitType nType,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto do dispositivo no qual desenhar. Se o *PDC* for nulo, [CWnd:: RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) será chamado pela estrutura e nenhuma janela de divisão será desenhada.

*nType*<br/>
Um valor do `enum ESplitType`, que pode ser um dos seguintes:

    - `splitBox` a caixa de arrastar divisor.

    - `splitBar` a barra que aparece entre as duas janelas de divisão.

    - `splitIntersection` a interseção das janelas de divisão. Este elemento não será chamado durante a execução no Windows 95/98.

    - `splitBorder` as bordas da janela de divisão.

*Rect*<br/>
Uma referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) especificando o tamanho e a forma das janelas de divisão.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo Framework para desenhar e especificar as características exatas de uma janela divisora. Substitua `OnDrawSplitter` para personalização avançada das imagens para os vários componentes gráficos de uma janela separadora. A imagem padrão é semelhante ao divisor no Microsoft Works para Windows ou no Microsoft Windows 95/98, pois as interseções das barras do separador são mescladas juntas.

Para obter mais informações sobre janelas de divisores dinâmicos, consulte "janelas de divisão" no artigo [vários tipos de documento, exibições e janelas de quadros](../../mfc/multiple-document-types-views-and-frame-windows.md), [Nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe `CSplitterWnd`.

##  <a name="oninverttracker"></a>CSplitterWnd:: OnInvertTracker

Renderiza a imagem de uma janela de divisão para ter o mesmo tamanho e forma que a janela do quadro.

```
virtual void OnInvertTracker(const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Referência a um objeto `CRect` especificando o retângulo de controle.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pela estrutura durante o redimensionamento de divisores. Substitua `OnInvertTracker` para personalização avançada das imagens da janela do separador. A imagem padrão é semelhante ao divisor no Microsoft Works para Windows ou no Microsoft Windows 95/98, pois as interseções das barras do separador são mescladas juntas.

Para obter mais informações sobre janelas de divisores dinâmicos, consulte "janelas de divisão" no artigo [vários tipos de documento, exibições e janelas de quadros](../../mfc/multiple-document-types-views-and-frame-windows.md), [Nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe `CSplitterWnd`.

##  <a name="recalclayout"></a>CSplitterWnd:: RecalcLayout

Chame para reexibir a janela do separador depois de ajustar o tamanho da linha ou da coluna.

```
virtual void RecalcLayout();
```

### <a name="remarks"></a>Comentários

Chame essa função de membro para reexibir corretamente a janela separadora depois de ajustar os tamanhos de linha e coluna com as funções de membro [SetRowInfo](#setrowinfo) e [SetColumnInfo](#setcolumninfo) . Se você alterar os tamanhos de linha e coluna como parte do processo de criação antes que a janela do separador fique visível, não será necessário chamar essa função de membro.

A estrutura chama essa função de membro sempre que o usuário redimensiona a janela divisora ou move uma divisão.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CSplitterWnd:: SetColumnInfo](#setcolumninfo).

##  <a name="setactivepane"></a>CSplitterWnd:: SetActivePane

Define um painel para ser o ativo no quadro.

```
virtual void SetActivePane(
    int row,
    int col,
    CWnd* pWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Se *pWnd* for NULL, especificará a linha no painel que estará ativo.

*col*<br/>
Se *pWnd* for NULL, especificará a coluna no painel que estará ativa.

*pWnd*<br/>
Um ponteiro para um objeto `CWnd`. Se for NULL, o painel especificado por *Row* e *Col* será definido como ativo. Se não for NULL, especifica o painel definido como ativo.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pela estrutura para definir um painel como ativo quando o usuário altera o foco para um painel dentro da janela do quadro. Você pode chamar `SetActivePane` explicitamente para alterar o foco para a exibição especificada.

Especifique o painel fornecendo a linha e a coluna **ou** fornecendo *pWnd*.

##  <a name="setcolumninfo"></a>CSplitterWnd:: SetColumnInfo

Chame para definir as informações de coluna especificadas.

```
void SetColumnInfo(
    int col,
    int cxIdeal,
    int cxMin);
```

### <a name="parameters"></a>Parâmetros

*col*<br/>
Especifica uma coluna de janela de Splitter.

*cxIdeal*<br/>
Especifica uma largura ideal para a coluna de janela de Splitter em pixels.

*cxMin*<br/>
Especifica uma largura mínima para a coluna de janela do separador em pixels.

### <a name="remarks"></a>Comentários

Chame essa função de membro para definir uma nova largura mínima e uma largura ideal para uma coluna. O valor mínimo da coluna determina quando a coluna será muito pequena para ser totalmente exibida.

Quando a estrutura exibe a janela separadora, ela apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo para o lado inferior direito da área do cliente da janela do divisor.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCWindowing#6](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_4.cpp)]

##  <a name="setrowinfo"></a>CSplitterWnd:: SetRowInfo

Chame para definir as informações de linha especificadas.

```
void SetRowInfo(
    int row,
    int cyIdeal,
    int cyMin);
```

### <a name="parameters"></a>Parâmetros

*row*<br/>
Especifica uma linha de janela de Splitter.

*cyIdeal*<br/>
Especifica uma altura ideal para a linha da janela do separador em pixels.

*cyMin*<br/>
Especifica uma altura mínima para a linha de janela do separador em pixels.

### <a name="remarks"></a>Comentários

Chame essa função de membro para definir uma nova altura mínima e uma altura ideal para uma linha. O valor mínimo da linha determina quando a linha será muito pequena para ser totalmente exibida.

Quando a estrutura exibe a janela separadora, ela apresenta os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo para o lado inferior direito da área do cliente da janela do divisor.

##  <a name="setscrollstyle"></a>CSplitterWnd:: SetScrollStyle

Especifica o novo estilo de rolagem para o suporte à barra de rolagem compartilhada da janela de divisão.

```
void SetScrollStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
O novo estilo de rolagem para o suporte à barra de rolagem compartilhada da janela de divisão, que pode ser um dos seguintes valores:

- WS_HSCROLL criar/Mostrar barras de rolagem compartilhadas horizontais.

- WS_VSCROLL criar/Mostrar barras de rolagem compartilhada vertical.

### <a name="remarks"></a>Comentários

Depois que uma barra de rolagem é criada, ela não será destruída mesmo se `SetScrollStyle` for chamado sem esse estilo; em vez disso, essas barras de rolagem ficam ocultas. Isso permite que as barras de rolagem retenham seu estado, mesmo que estejam ocultas. Depois de chamar `SetScrollStyle` é necessário chamar [RecalcLayout](#recalclayout) para que todas as alterações entrem em vigor.

##  <a name="splitcolumn"></a>CSplitterWnd:: SplitColumn

Indica onde uma janela do quadro se divide verticalmente.

```
virtual BOOL SplitColumn(int cxBefore);
```

### <a name="parameters"></a>Parâmetros

*cxBefore*<br/>
A posição, em pixels, antes da qual a divisão ocorre.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada quando uma janela de divisor vertical é criada. `SplitColumn` indica o local padrão onde a divisão ocorre.

`SplitColumn` é chamado pelo Framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela do separador tiver o estilo de SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="splitrow"></a>CSplitterWnd:: SplitRow

Indica onde uma janela do quadro se divide horizontalmente.

```
virtual BOOL SplitRow(int cyBefore);
```

### <a name="parameters"></a>Parâmetros

*cyBefore*<br/>
A posição, em pixels, antes da qual a divisão ocorre.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada quando uma janela divisória horizontal é criada. `SplitRow` indica o local padrão onde a divisão ocorre.

`SplitRow` é chamado pelo Framework para implementar a lógica da janela separadora dinâmica (ou seja, se a janela do separador tiver o estilo de SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView](#createview), para implementar divisores dinâmicos mais avançados.

##  <a name="ondraw"></a>CSplitterWnd:: OnDraw

Chamado pelo Framework para desenhar a janela separadora.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Exemplo de VIEWEX do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
