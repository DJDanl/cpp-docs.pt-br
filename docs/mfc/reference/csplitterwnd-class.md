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
ms.openlocfilehash: a872854af1695b8b2b347b21d73165d259b3a986
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753069"
---
# <a name="csplitterwnd-class"></a>Classe CSplitterWnd

Fornece a funcionalidade de uma janela divisora, que é uma janela que contém vários painéis.

## <a name="syntax"></a>Sintaxe

```
class CSplitterWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWnd::CSplitterWnd](#csplitterwnd)|Chame para `CSplitterWnd` construir um objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWnd::AtivarNext](#activatenext)|Executa o comando Next Pane ou Previous Pane.|
|[CSplitterWnd::CanActivateNext](#canactivatenext)|Verifica se o comando Next Pane ou Previous Pane é atualmente possível.|
|[CSplitterWnd::Criar](#create)|Ligue para criar uma janela divisora `CSplitterWnd` dinâmica e anexe-a ao objeto.|
|[CSplitterWnd::CreateScrollBarCtrl](#createscrollbarctrl)|Cria um controle de barra de rolagem compartilhada.|
|[CSplitterWnd::CreateStatic](#createstatic)|Ligue para criar uma janela de divisor `CSplitterWnd` estático e anexe-a ao objeto.|
|[CSplitterWnd::CreateView](#createview)|Ligue para criar um painel em uma janela de divisor.|
|[CSplitterWnd::DeleteColumn](#deletecolumn)|Exclui uma coluna da janela do divisor.|
|[CSplitterWnd::DeleteRow](#deleterow)|Exclui uma linha da janela do divisor.|
|[CSplitterWnd::DeleteView](#deleteview)|Exclui uma exibição da janela do divisor.|
|[CSplitterWnd::DoKeyboardSplit](#dokeyboardsplit)|Executa o comando de divisão do teclado, geralmente "Window Split".|
|[CSplitterWnd::DoScroll](#doscroll)|Executa rolagem sincronizada de janelas divididas.|
|[CSplitterWnd::DoScrollBy](#doscrollby)|Rola janelas divididas por um determinado número de pixels.|
|[CSplitterWnd::GetActivePane](#getactivepane)|Determina o painel ativo a partir do foco ou da exibição ativa no quadro.|
|[CSplitterWnd::GetColumnCount](#getcolumncount)|Retorna a contagem atual da coluna do painel.|
|[CSplitterWnd::GetColumnInfo](#getcolumninfo)|Retorna informações na coluna especificada.|
|[CSplitterWnd::GetPane](#getpane)|Retorna o painel na linha e coluna especificadas.|
|[CSplitterWnd::GetRowCount](#getrowcount)|Retorna a contagem atual da linha do painel.|
|[CSplitterWnd::GetRowInfo](#getrowinfo)|Retorna informações sobre a linha especificada.|
|[CSplitterWnd::GetScrollStyle](#getscrollstyle)|Retorna o estilo de barra de rolagem compartilhada.|
|[CSplitterWnd::IdFromRowCol](#idfromrowcol)|Retorna o ID da janela do filho do painel na linha e coluna especificadas.|
|[CSplitterWnd::IsChildPane](#ischildpane)|Ligue para determinar se a janela é atualmente um painel infantil desta janela de divisor.|
|[CSplitterWnd::IsTracking](#istracking)|Determina se a barra de divisor está sendo movida no momento.|
|[CSplitterWnd::RecalcLayout](#recalclayout)|Chamada para reexibir a janela do divisor depois de ajustar o tamanho da linha ou da coluna.|
|[CSplitterWnd::SetActivePane](#setactivepane)|Define um painel para ser o ativo no quadro.|
|[CSplitterWnd::SetColumnInfo](#setcolumninfo)|Ligue para definir as informações da coluna especificadas.|
|[CSplitterWnd::SetRowInfo](#setrowinfo)|Ligue para definir as informações da linha especificadas.|
|[CSplitterWnd::SetScrollStyle](#setscrollstyle)|Especifica o novo estilo de barra de rolagem para o suporte compartilhado da barra de rolagem da janela de divisor.|
|[CSplitterWnd::SplitColumn](#splitcolumn)|Indica onde uma janela de quadro se divide verticalmente.|
|[CSplitterWnd::SplitRow](#splitrow)|Indica onde uma janela de quadro se divide horizontalmente.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CSplitterWnd::OnDraw](#ondraw)|Chamado pela estrutura para desenhar a janela do divisor.|
|[CSplitterWnd::OnDrawSplitter](#ondrawsplitter)|Faz uma imagem de uma janela dividida.|
|[CSplitterWnd::OnInvertTracker](#oninverttracker)|Torna a imagem de uma janela dividida do mesmo tamanho e forma da janela do quadro.|

## <a name="remarks"></a>Comentários

Um painel é geralmente um objeto específico do aplicativo derivado do [CView,](../../mfc/reference/cview-class.md)mas pode ser qualquer objeto [CWnd](../../mfc/reference/cwnd-class.md) que tenha o ID da janela do filho apropriado.

Um `CSplitterWnd` objeto geralmente é incorporado em um objeto [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd.](../../mfc/reference/cmdichildwnd-class.md) Criar `CSplitterWnd` um objeto usando as seguintes etapas:

1. Incorporar uma `CSplitterWnd` variável de membro no quadro pai.

2. Substituir a função [cframewnd do quadro pai::OnCreateClient.](../../mfc/reference/cframewnd-class.md#oncreateclient)

3. A partir do `OnCreateClient`substituído, [Create](#create) chame a função criar `CSplitterWnd`ou [criarmembroÁtico](#createstatic) de .

Ligue `Create` para a função de membro para criar uma janela de divisor dinâmico. Uma janela de divisor dinâmico normalmente é usada para criar e rolar uma série de painéis individuais, ou visualizações, do mesmo documento. A estrutura cria automaticamente um painel inicial para o divisor; em seguida, a estrutura cria, redimensiona e elimina painéis adicionais à medida que o usuário opera os controles da janela do divisor.

Quando você `Create`chama, você especifica uma altura mínima da linha e largura da coluna que determinam quando os painéis são muito pequenos para serem totalmente exibidos. Depois de `Create`ligar, você pode ajustar esses mínimos chamando as funções de membro [SetColumnInfo](#setcolumninfo) e [SetRowInfo.](#setrowinfo)

Use também `SetColumnInfo` `SetRowInfo` as funções do membro para definir uma largura "ideal" para uma coluna e altura "ideal" para uma linha. Quando a estrutura exibe uma janela divisora, ela exibe primeiro o quadro pai e, em seguida, a janela do divisor. A estrutura então estabelece os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo ao canto inferior direito da área cliente da janela do divisor.

Todos os painéis em uma janela de divisor dinâmico devem ser da mesma classe. Aplicativos familiares que suportam janelas de divisor dinâmico incluem o Microsoft Word e o Microsoft Excel.

Use `CreateStatic` a função membro para criar uma janela de divisor estático. O usuário pode alterar apenas o tamanho dos painéis em uma janela de divisor estático, não seu número ou pedido.

Você deve criar especificamente todos os painéis do divisor estático quando criar o divisor estático. Certifique-se de criar todos os painéis `OnCreateClient` antes que a função de membro do quadro pai retorne ou a estrutura não exibirá a janela corretamente.

A `CreateStatic` função do membro inicializa automaticamente um divisor estático com uma altura mínima de linha e largura da coluna de 0. Depois de `Create`chamar, ajuste esses mínimos chamando as funções de membro [SetColumnInfo](#setcolumninfo) e [SetRowInfo.](#setrowinfo) Use `SetColumnInfo` também `SetRowInfo` e `CreateStatic` depois de ligar para indicar as dimensões ideais desejadas do painel.

Os painéis individuais de um divisor estático muitas vezes pertencem a classes diferentes. Para exemplos de janelas de divisor estática, consulte o editor gráfico e o Gerenciador de Arquivos do Windows.

Uma janela de divisor suporta barras de rolagem especiais (além das barras de rolagem que os painéis podem ter). Estas barras de `CSplitterWnd` rolagem são filhos do objeto e são compartilhadas com os painéis.

Você cria essas barras de rolagem especiais quando cria a janela do divisor. Por exemplo, `CSplitterWnd` um que tem uma linha, duas colunas e o estilo WS_VSCROLL exibirá uma barra de rolagem vertical que é compartilhada pelos dois painéis. Quando o usuário move a barra de rolagem, WM_VSCROLL mensagens são enviadas para ambos os painéis. Quando os painéis definirem a posição da barra de rolagem, a barra de rolagem compartilhada será definida.

Para obter mais informações sobre janelas de divisor, consulte [Nota Técnica 29](../../mfc/tn029-splitter-windows.md).

Para obter mais informações sobre como criar janelas de divisor dinâmicos, consulte:

- [Scribble](../../overview/visual-cpp-samples.md) amostra MFC

- [Visão EX](../../overview/visual-cpp-samples.md)de amostra de MFC .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSplitterWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="csplitterwndactivatenext"></a><a name="activatenext"></a>CSplitterWnd::AtivarNext

Chamado pela estrutura para executar o comando Next Pane ou Previous Pane.

```
virtual void ActivateNext(BOOL bPrev = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bPrev*<br/>
Indica qual janela ativar. **VERDADE** para anteriores; **FALSO** para o próximo.

### <a name="remarks"></a>Comentários

Esta função de membro é um comando de alto nível `CSplitterWnd` que é usado pela classe [CView](../../mfc/reference/cview-class.md) para delegar à implementação.

## <a name="csplitterwndcanactivatenext"></a><a name="canactivatenext"></a>CSplitterWnd::CanActivateNext

Chamado pela estrutura para verificar se o comando Next Pane ou Previous Pane é atualmente possível.

```
virtual BOOL CanActivateNext(BOOL bPrev = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bPrev*<br/>
Indica qual janela ativar. **VERDADE** para anteriores; **FALSO** para o próximo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é um comando de alto nível `CSplitterWnd` que é usado pela classe [CView](../../mfc/reference/cview-class.md) para delegar à implementação.

## <a name="csplitterwndcreate"></a><a name="create"></a>CSplitterWnd::Criar

Para criar uma janela de `Create` divisor dinâmico, chame a função de membro.

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

*Pparentwnd*<br/>
A janela de quadro dos pais da janela do divisor.

*nMaxRows*<br/>
O número máximo de linhas na janela do divisor. Este valor não deve exceder 2.

*nMaxCols*<br/>
O número máximo de colunas na janela do divisor. Este valor não deve exceder 2.

*sizeMin*<br/>
Especifica o tamanho mínimo em que um painel pode ser exibido.

*pContext*<br/>
Um ponteiro para uma estrutura [CCreateContext.](../../mfc/reference/ccreatecontext-structure.md) Na maioria dos casos, este pode ser o *pContext* passado para a janela do quadro pai.

*Dwstyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A janela da criança da janela. O ID pode ser AFX_IDW_PANE_FIRST a menos que a janela do divisor esteja aninhada dentro de outra janela de divisor.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode incorporar `CSplitterWnd` um objeto CFrameWnd ou CMDIChildWnd em um objeto [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIChildWnd,](../../mfc/reference/cmdichildwnd-class.md) tomando as seguintes etapas:

1. Incorporar uma `CSplitterWnd` variável de membro no quadro pai.

1. Substituir a função [cframewnd do quadro pai::OnCreateClient.](../../mfc/reference/cframewnd-class.md#oncreateclient)

1. Chame `Create` a função de membro `OnCreateClient`de dentro do substituído .

Quando você criar uma janela divisora de dentro de um quadro pai, passe o parâmetro *pContext* do quadro pai para a janela divisor. Caso contrário, este parâmetro pode ser NULO.

A altura mínima inicial da linha e a largura da coluna de uma janela divisora dinâmica são definidas pelo parâmetro *sizeMin.* Esses mínimos, que determinam se um painel é muito pequeno para ser mostrado em sua totalidade, podem ser alterados com as funções de membro [SetRowInfo](#setrowinfo) e [SetColumnInfo.](#setcolumninfo)

Para obter mais informações sobre janelas de divisordinâmicos, consulte "Splitter Windows" no artigo Vários `CSplitterWnd` tipos de [documentos, visualizações e windows de quadro,](../../mfc/multiple-document-types-views-and-frame-windows.md) [nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#125](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_1.cpp)]

## <a name="csplitterwndcreatescrollbarctrl"></a><a name="createscrollbarctrl"></a>CSplitterWnd::CreateScrollBarCtrl

Chamado pela estrutura para criar um controle de barra de rolagem compartilhado.

```
virtual BOOL CreateScrollBarCtrl(
    DWORD dwStyle,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A janela da criança da janela. O ID pode ser AFX_IDW_PANE_FIRST a menos que a janela do divisor esteja aninhada dentro de outra janela de divisor.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substituir `CreateScrollBarCtrl` para incluir controles extras ao lado de uma barra de rolagem. O comportamento padrão é criar controles normais da barra de rolagem do Windows.

## <a name="csplitterwndcreatestatic"></a><a name="createstatic"></a>CSplitterWnd::CreateStatic

Para criar uma janela de `CreateStatic` divisor estático, chame a função membro.

```
virtual BOOL CreateStatic(
    CWnd* pParentWnd,
    int nRows,
    int nCols,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE,
    UINT nID = AFX_IDW_PANE_FIRST);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
A janela de quadro dos pais da janela do divisor.

*nRows*<br/>
O número de linhas. Este valor não deve exceder 16.

*nCols*<br/>
O número de colunas. Este valor não deve exceder 16.

*Dwstyle*<br/>
Especifica o estilo da janela.

*nID*<br/>
A janela da criança da janela. O ID pode ser AFX_IDW_PANE_FIRST a menos que a janela do divisor esteja aninhada dentro de outra janela de divisor.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `CSplitterWnd` é geralmente incorporado `CFrameWnd` em um objeto pai ou [CMDIChildWnd,](../../mfc/reference/cmdichildwnd-class.md) tomando as seguintes etapas:

1. Incorporar uma `CSplitterWnd` variável de membro no quadro pai.

1. Anular a função de `OnCreateClient` membro do quadro pai.

1. Ligue `CreateStatic` para a função de membro dentro do [CFrameWnd substituído::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient).

Uma janela de divisor estático contém um número fixo de painéis, muitas vezes de classes diferentes.

Quando você cria uma janela de divisor estático, você deve ao mesmo tempo criar todos os seus painéis. A função de membro [CreateView](#createview) geralmente é usada para este fim, mas você também pode criar outras classes de não exibição.

A altura mínima inicial da linha e a largura da coluna para uma janela de divisor estático é 0. Esses mínimos, que determinam quando um painel é muito pequeno para serem mostrados em sua totalidade, podem ser alterados com as funções de membro [SetRowInfo](#setrowinfo) e [SetColumnInfo.](#setcolumninfo)

Para adicionar barras de rolagem a uma janela de divisor estático, adicione os estilos WS_HSCROLL e WS_VSCROLL ao *dwStyle*.

Consulte "Splitter Windows" no artigo [Vários tipos de documentos, visualizações e janelas de quadros,](../../mfc/multiple-document-types-views-and-frame-windows.md) [nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da `CSplitterWnd` classe para obter mais informações sobre janelas de divisor estática.

## <a name="csplitterwndcreateview"></a><a name="createview"></a>CSplitterWnd::CreateView

Cria os painéis para uma janela de divisor estático.

```
virtual BOOL CreateView(
    int row,
    int col,
    CRuntimeClass* pViewClass,
    SIZE sizeInit,
    CCreateContext* pContext);
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Especifica a linha de janela do divisor para colocar a nova exibição.

*col*<br/>
Especifica a coluna da janela do divisor para colocar a nova exibição.

*pViewClass*<br/>
Especifica o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) da nova exibição.

*tamanhoInit*<br/>
Especifica o tamanho inicial da nova exibição.

*pContext*<br/>
Um ponteiro para um contexto de criação usado para criar a exibição (geralmente o *pContext* passou para a função cframewnd do quadro [pai::onCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient) função de membro na qual a janela divisora está sendo criada).

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Todos os painéis de uma janela de divisor estático devem ser criados antes que a estrutura exiba o divisor.

A estrutura também chama essa função de membro para criar novos painéis quando o usuário de uma janela de divisor dinâmico divide um painel, linha ou coluna.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#4](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_2.cpp)]

## <a name="csplitterwndcsplitterwnd"></a><a name="csplitterwnd"></a>CSplitterWnd::CSplitterWnd

Chame para `CSplitterWnd` construir um objeto.

```
CSplitterWnd();
```

### <a name="remarks"></a>Comentários

Construa `CSplitterWnd` um objeto em dois passos. Primeiro, ligue para o construtor, que cria o `CSplitterWnd` objeto, e depois chame a função [Criar](#create) membro, que cria a janela do divisor e anexa-a ao `CSplitterWnd` objeto.

## <a name="csplitterwnddeletecolumn"></a><a name="deletecolumn"></a>CSplitterWnd::DeleteColumn

Exclui uma coluna da janela do divisor.

```
virtual void DeleteColumn(int colDelete);
```

### <a name="parameters"></a>Parâmetros

*colDelete*<br/>
Especifica a coluna a ser excluída.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pela estrutura para implementar a lógica da janela do divisor dinâmico (isto é, se a janela do divisor tiver o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView,](#createview)para implementar divisores dinâmicos mais avançados.

## <a name="csplitterwnddeleterow"></a><a name="deleterow"></a>CSplitterWnd::DeleteRow

Exclui uma linha da janela do divisor.

```
virtual void DeleteRow(int rowDelete);
```

### <a name="parameters"></a>Parâmetros

*linha Excluir*<br/>
Especifica a linha a ser excluída.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pela estrutura para implementar a lógica da janela do divisor dinâmico (isto é, se a janela do divisor tiver o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView,](#createview)para implementar divisores dinâmicos mais avançados.

## <a name="csplitterwnddeleteview"></a><a name="deleteview"></a>CSplitterWnd::DeleteView

Exclui uma exibição da janela do divisor.

```
virtual void DeleteView(
    int row,
    int col);
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Especifica a linha de janela do divisor para excluir a exibição.

*col*<br/>
Especifica a coluna da janela divisora na qual excluir a exibição.

### <a name="remarks"></a>Comentários

Se a exibição ativa estiver sendo excluída, a próxima exibição ficará ativa. A implementação padrão assume que a exibição será excluída automaticamente no [PostNcDestroy](../../mfc/reference/cwnd-class.md#postncdestroy).

Essa função de membro é chamada pela estrutura para implementar a lógica da janela do divisor dinâmico (isto é, se a janela do divisor tiver o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView,](#createview)para implementar divisores dinâmicos mais avançados.

## <a name="csplitterwnddokeyboardsplit"></a><a name="dokeyboardsplit"></a>CSplitterWnd::DoKeyboardSplit

Executa o comando de divisão do teclado, geralmente "Window Split".

```
virtual BOOL DoKeyboardSplit();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é um comando de alto nível `CSplitterWnd` que é usado pela classe [CView](../../mfc/reference/cview-class.md) para delegar à implementação.

## <a name="csplitterwnddoscroll"></a><a name="doscroll"></a>CSplitterWnd::DoScroll

Executa rolagem sincronizada de janelas divididas.

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
Um código de barra de rolagem que indica a solicitação de rolagem do usuário. Este parâmetro é composto de duas partes: um byte de baixa ordem, que determina o tipo de rolagem que ocorre horizontalmente, e um byte de alta ordem, que determina o tipo de rolagem que ocorre verticalmente:

- SB_BOTTOM Rola para baixo.

- SB_LINEDOWN rola uma linha para baixo.

- SB_LINEUP rola uma linha.

- SB_PAGEDOWN Rola uma página abaixo.

- SB_PAGEUP Rola uma página para cima.

- SB_TOP Rola até o topo.

*Bdoscroll*<br/>
Determina se a ação de rolagem especificada ocorre. Se *bDoScroll* for TRUE (isto é, se existir uma janela filho e se as janelas divididas tiverem um intervalo de rolagem), a ação de rolagem especificada poderá ocorrer; se *bDoScroll* for FALSE (ou seja, se não houver janela filho ou as exibições divididas não tiverem alcance de rolagem), então a rolagem não ocorrerá.

### <a name="return-value"></a>Valor retornado

Não zero se ocorrer rolagem sincronizada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada pela estrutura para executar rolagem sincronizada de janelas divididas quando a exibição recebe uma mensagem de rolagem. Substituir para exigir uma ação do usuário antes que a rolagem sincronizada seja permitida.

## <a name="csplitterwnddoscrollby"></a><a name="doscrollby"></a>CSplitterWnd::DoScrollBy

Rola janelas divididas por um determinado número de pixels.

```
virtual BOOL DoScrollBy(
    CView* pViewFrom,
    CSize sizeScroll,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewFrom*<br/>
Um ponteiro para a exibição da qual a mensagem de rolagem se origina.

*Sizescroll*<br/>
Número de pixels a serem rolados horizontal e verticalmente.

*Bdoscroll*<br/>
Determina se a ação de rolagem especificada ocorre. Se *bDoScroll* for TRUE (isto é, se existir uma janela filho e se as janelas divididas tiverem um intervalo de rolagem), a ação de rolagem especificada poderá ocorrer; se *bDoScroll* for FALSE (ou seja, se não houver janela filho ou as exibições divididas não tiverem alcance de rolagem), então a rolagem não ocorrerá.

### <a name="return-value"></a>Valor retornado

Não zero se ocorrer rolagem sincronizada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada pela estrutura em resposta a uma mensagem de rolagem, para executar rolagem sincronizada das janelas divididas pela quantidade, em pixels, indicada pelo *sizeScroll*. Valores positivos indicam rolagem para baixo e para a direita; valores negativos indicam rolagem para cima e para a esquerda.

Substituir para exigir uma ação do usuário antes de permitir o pergaminho.

## <a name="csplitterwndgetactivepane"></a><a name="getactivepane"></a>CSplitterWnd::GetActivePane

Determina o painel ativo a partir do foco ou da exibição ativa no quadro.

```
virtual CWnd* GetActivePane(
    int* pRow = NULL,
    int* pCol = NULL);
```

### <a name="parameters"></a>Parâmetros

*pRow*<br/>
Um ponteiro para um **int** para recuperar o número da linha do painel ativo.

*pCol*<br/>
Um ponteiro para um **int** para recuperar o número da coluna do painel ativo.

### <a name="return-value"></a>Valor retornado

Ponteiro para o painel ativo. NULL se não houver painel ativo.

### <a name="remarks"></a>Comentários

Esta função membro é chamada pela estrutura para determinar o painel ativo em uma janela de divisor. Substituir para exigir uma ação do usuário antes de obter o painel ativo.

## <a name="csplitterwndgetcolumncount"></a><a name="getcolumncount"></a>CSplitterWnd::GetColumnCount

Retorna a contagem atual da coluna do painel.

```
int GetColumnCount() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número atual de colunas no divisor. Para um divisor estático, este também será o número máximo de colunas.

## <a name="csplitterwndgetcolumninfo"></a><a name="getcolumninfo"></a>CSplitterWnd::GetColumnInfo

Retorna informações na coluna especificada.

```cpp
void GetColumnInfo(
    int col,
    int& cxCur,
    int& cxMin) const;
```

### <a name="parameters"></a>Parâmetros

*col*<br/>
Especifica uma coluna.

*cxCur*<br/>
Uma referência a um **int** a ser definido para a largura atual da coluna.

*cxMin*<br/>
Uma referência a um **int** a ser definido para a largura mínima atual da coluna.

## <a name="csplitterwndgetpane"></a><a name="getpane"></a>CSplitterWnd::GetPane

Retorna o painel na linha e coluna especificadas.

```
CWnd* GetPane(
    int row,
    int col) const;
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Especifica uma linha.

*col*<br/>
Especifica uma coluna.

### <a name="return-value"></a>Valor retornado

Retorna o painel na linha e coluna especificadas. O painel retornado é geralmente uma classe derivada do [CView.](../../mfc/reference/cview-class.md)

## <a name="csplitterwndgetrowcount"></a><a name="getrowcount"></a>CSplitterWnd::GetRowCount

Retorna a contagem atual da linha do painel.

```
int GetRowCount() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número atual de linhas na janela do divisor. Para uma janela de divisor estático, este também será o número máximo de linhas.

## <a name="csplitterwndgetrowinfo"></a><a name="getrowinfo"></a>CSplitterWnd::GetRowInfo

Retorna informações sobre a linha especificada.

```cpp
void GetRowInfo(
    int row,
    int& cyCur,
    int& cyMin) const;
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Especifica uma linha.

*cyCur*<br/>
Referência ao **int** a ser definido para a altura atual da linha em pixels.

*cyMin*<br/>
Referência ao **int** a ser definido para a altura mínima atual da linha em pixels.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para obter informações sobre a linha especificada. O parâmetro *cyCur* é preenchido com a altura atual da linha especificada, e o *cyMin* é preenchido com a altura mínima da linha.

## <a name="csplitterwndgetscrollstyle"></a><a name="getscrollstyle"></a>CSplitterWnd::GetScrollStyle

Retorna o estilo de barra de rolagem compartilhada para a janela do divisor.

```
DWORD GetScrollStyle() const;
```

### <a name="return-value"></a>Valor retornado

Uma ou mais das seguintes bandeiras de estilo do windows, se for bem sucedida:

- WS_HSCROLL Se o divisor atualmente gerenciar barras de rolagem horizontal compartilhadas.

- WS_VSCROLL Se o divisor atualmente gerenciar barras de rolagem verticais compartilhadas.

Se zero, a janela divisora não gerencia atualmente nenhuma barra de rolagem compartilhada.

## <a name="csplitterwndidfromrowcol"></a><a name="idfromrowcol"></a>CSplitterWnd::IdFromRowCol

Obtém o ID da janela da criança para o painel na linha e coluna especificadas.

```
int IdFromRowCol(
    int row,
    int col) const;
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Especifica a linha da janela do divisor.

*col*<br/>
Especifica a coluna da janela do divisor.

### <a name="return-value"></a>Valor retornado

A janela da criança id para o painel.

### <a name="remarks"></a>Comentários

Esta função de membro é usada para criar não-visualizações como painéis e pode ser chamada antes que o painel exista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#5](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_3.cpp)]

## <a name="csplitterwndischildpane"></a><a name="ischildpane"></a>CSplitterWnd::IsChildPane

Determina se *pWnd* é atualmente um painel infantil desta janela de divisor.

```
BOOL IsChildPane(
    CWnd* pWnd,
    int* pRow,
    int* pCol);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) a ser testado.

*pRow*<br/>
Um ponteiro para um **int** no qual armazenar o número da linha.

*pCol*<br/>
Um ponteiro para um **int** no qual armazenar um número de coluna.

### <a name="return-value"></a>Valor retornado

Se não zero, *pWnd* é atualmente um painel infantil desta janela de divisor, e *pRow* e *pCol* são preenchidos com a posição do painel na janela do divisor. Se *pWnd* não é um painel infantil desta janela de divisor, 0 é devolvido.

### <a name="remarks"></a>Comentários

Nas versões Do Visual C++ antes do 6.0, essa função foi definida como

`BOOL IsChildPane(CWnd* pWnd, int& row, int& col);`

Esta versão agora está obsoleta e não deve ser usada.

## <a name="csplitterwndistracking"></a><a name="istracking"></a>CSplitterWnd::IsTracking

Ligue para esta função de membro para determinar se a barra de divisor na janela está sendo movida no momento.

```
BOOL IsTracking();
```

### <a name="return-value"></a>Valor retornado

Não zero se uma operação de divisor estiver em andamento; caso contrário, 0.

## <a name="csplitterwndondrawsplitter"></a><a name="ondrawsplitter"></a>CSplitterWnd::OnDrawSplitter

Faz uma imagem de uma janela dividida.

```
virtual void OnDrawSplitter(
    CDC* pDC,
    ESplitType nType,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto do dispositivo no qual desenhar. Se *o pDC* for NULL, [então CWnd::RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) é chamado pela estrutura e nenhuma janela dividida será desenhada.

*nType*<br/>
Um valor `enum ESplitType`do , que pode ser um dos seguintes:

- `splitBox`A caixa de arrasto divisor.

- `splitBar`A barra que aparece entre as duas janelas divididas.

- `splitIntersection`A intersecção das janelas divididas. Este elemento não será chamado ao ser executado no Windows 95/98.

- `splitBorder`As janelas divididas beiram.

*Rect*<br/>
Uma referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) especificando o tamanho e a forma das janelas divididas.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada pela framework para desenhar e especificar as características exatas de uma janela de divisor. Substituição `OnDrawSplitter` para personalização avançada das imagens para os vários componentes gráficos de uma janela de divisor. As imagens padrão são semelhantes ao divisor no Microsoft Works for Windows ou Microsoft Windows 95/98, na qual as interseções das barras de divisor são misturadas.

Para obter mais informações sobre janelas de divisordinâmicos, consulte "Splitter Windows" no artigo Vários `CSplitterWnd` tipos de [documentos, visualizações e windows de quadro,](../../mfc/multiple-document-types-views-and-frame-windows.md) [nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe.

## <a name="csplitterwndoninverttracker"></a><a name="oninverttracker"></a>CSplitterWnd::OnInvertTracker

Torna a imagem de uma janela dividida do mesmo tamanho e forma da janela do quadro.

```
virtual void OnInvertTracker(const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Referência a `CRect` um objeto especificando o retângulo de rastreamento.

### <a name="remarks"></a>Comentários

Esta função membro é chamada pela estrutura durante o redimensionamento de divisores. Substituição `OnInvertTracker` para personalização avançada das imagens da janela do divisor. As imagens padrão são semelhantes ao divisor no Microsoft Works for Windows ou Microsoft Windows 95/98, na qual as interseções das barras de divisor são misturadas.

Para obter mais informações sobre janelas de divisordinâmicos, consulte "Splitter Windows" no artigo Vários `CSplitterWnd` tipos de [documentos, visualizações e windows de quadro,](../../mfc/multiple-document-types-views-and-frame-windows.md) [nota técnica 29](../../mfc/tn029-splitter-windows.md)e a visão geral da classe.

## <a name="csplitterwndrecalclayout"></a><a name="recalclayout"></a>CSplitterWnd::RecalcLayout

Chamada para reexibir a janela do divisor depois de ajustar o tamanho da linha ou da coluna.

```
virtual void RecalcLayout();
```

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para reexibir corretamente a janela do divisor depois de ter ajustado os tamanhos de linha e coluna com as funções de membro [SetRowInfo](#setrowinfo) e [SetColumnInfo.](#setcolumninfo) Se você alterar os tamanhos de linha e coluna como parte do processo de criação antes que a janela do divisor seja visível, não é necessário chamar essa função de membro.

A estrutura chama essa função de membro sempre que o usuário redimensiona a janela do divisor ou move uma divisão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CSplitterWnd::SetColumnInfo](#setcolumninfo).

## <a name="csplitterwndsetactivepane"></a><a name="setactivepane"></a>CSplitterWnd::SetActivePane

Define um painel para ser o ativo no quadro.

```
virtual void SetActivePane(
    int row,
    int col,
    CWnd* pWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Se *pWnd* for NULL, especificará a linha no painel que estará ativa.

*col*<br/>
Se *pWnd* for NULL, especificará a coluna no painel que estará ativa.

*Pwnd*<br/>
Um ponteiro para um objeto `CWnd`. Se NULA, o painel especificado por *linha* e *col* está definido ativo. Se não FOR NULO, especifica o painel que está definido como ativo.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada pela estrutura para definir um painel como ativo quando o usuário muda o foco para um painel dentro da janela do quadro. Você pode ligar `SetActivePane` explicitamente para alterar o foco para a exibição especificada.

Especifique o painel fornecendo linha e coluna, **ou** fornecendo *pWnd*.

## <a name="csplitterwndsetcolumninfo"></a><a name="setcolumninfo"></a>CSplitterWnd::SetColumnInfo

Ligue para definir as informações da coluna especificadas.

```cpp
void SetColumnInfo(
    int col,
    int cxIdeal,
    int cxMin);
```

### <a name="parameters"></a>Parâmetros

*col*<br/>
Especifica uma coluna de janela de divisor.

*cxIdeal*<br/>
Especifica uma largura ideal para a coluna de janela divisora em pixels.

*cxMin*<br/>
Especifica uma largura mínima para a coluna de janela divisora em pixels.

### <a name="remarks"></a>Comentários

Chame esta função de membro para definir uma nova largura mínima e largura ideal para uma coluna. O valor mínimo da coluna determina quando a coluna será muito pequena para ser totalmente exibida.

Quando a estrutura exibe a janela do divisor, ela coloca os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo ao canto inferior direito da área cliente da janela do divisor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#6](../../mfc/reference/codesnippet/cpp/csplitterwnd-class_4.cpp)]

## <a name="csplitterwndsetrowinfo"></a><a name="setrowinfo"></a>CSplitterWnd::SetRowInfo

Ligue para definir as informações da linha especificadas.

```cpp
void SetRowInfo(
    int row,
    int cyIdeal,
    int cyMin);
```

### <a name="parameters"></a>Parâmetros

*Linha*<br/>
Especifica uma linha de janela divisora.

*cyIdeal*<br/>
Especifica uma altura ideal para a linha da janela do divisor em pixels.

*cyMin*<br/>
Especifica uma altura mínima para a linha da janela do divisor em pixels.

### <a name="remarks"></a>Comentários

Chame esta função de membro para definir uma nova altura mínima e altura ideal para uma linha. O valor mínimo da linha determina quando a linha será muito pequena para ser totalmente exibida.

Quando a estrutura exibe a janela do divisor, ela coloca os painéis em colunas e linhas de acordo com suas dimensões ideais, trabalhando do canto superior esquerdo ao canto inferior direito da área cliente da janela do divisor.

## <a name="csplitterwndsetscrollstyle"></a><a name="setscrollstyle"></a>CSplitterWnd::SetScrollStyle

Especifica o novo estilo de rolagem para o suporte compartilhado da barra de rolagem da janela splitter.

```cpp
void SetScrollStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
O novo estilo de rolagem para o suporte compartilhado da barra de rolagem da janela splitter, que pode ser um dos seguintes valores:

- WS_HSCROLL Criar/mostrar barras de rolagem compartilhadas horizontais.

- WS_VSCROLL Criar/mostrar barras de rolagem compartilhadas verticais.

### <a name="remarks"></a>Comentários

Uma vez criada uma barra de rolagem, `SetScrollStyle` ela não será destruída mesmo que seja chamada sem esse estilo; em vez disso, essas barras de rolagem estão escondidas. Isso permite que as barras de rolagem mantenham seu estado mesmo que estejam escondidas. Depois `SetScrollStyle` de ligar é necessário chamar [RecalcLayout](#recalclayout) para que todas as alterações entrem em vigor.

## <a name="csplitterwndsplitcolumn"></a><a name="splitcolumn"></a>CSplitterWnd::SplitColumn

Indica onde uma janela de quadro se divide verticalmente.

```
virtual BOOL SplitColumn(int cxBefore);
```

### <a name="parameters"></a>Parâmetros

*cxAntes*<br/>
A posição, em pixels, antes da qual ocorre a divisão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada quando uma janela de divisor vertical é criada. `SplitColumn`indica o local padrão onde ocorre a divisão.

`SplitColumn`é chamado pela estrutura para implementar a lógica da janela do divisor dinâmico (isto é, se a janela do divisor tiver o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView,](#createview)para implementar divisores dinâmicos mais avançados.

## <a name="csplitterwndsplitrow"></a><a name="splitrow"></a>CSplitterWnd::SplitRow

Indica onde uma janela de quadro se divide horizontalmente.

```
virtual BOOL SplitRow(int cyBefore);
```

### <a name="parameters"></a>Parâmetros

*cyBefore*<br/>
A posição, em pixels, antes da qual ocorre a divisão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada quando uma janela de divisor horizontal é criada. `SplitRow`indica o local padrão onde ocorre a divisão.

`SplitRow`é chamado pela estrutura para implementar a lógica da janela do divisor dinâmico (isto é, se a janela do divisor tiver o estilo SPLS_DYNAMIC_SPLIT). Ele pode ser personalizado, juntamente com a função virtual [CreateView,](#createview)para implementar divisores dinâmicos mais avançados.

## <a name="csplitterwndondraw"></a><a name="ondraw"></a>CSplitterWnd::OnDraw

Chamado pela estrutura para desenhar a janela do divisor.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[MFC Amostra VIEWEX](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
