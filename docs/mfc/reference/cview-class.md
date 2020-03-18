---
title: Classe Cvisualização
ms.date: 11/04/2016
f1_keywords:
- CView
- AFXWIN/CView
- AFXWIN/CView::CView
- AFXWIN/CView::DoPreparePrinting
- AFXWIN/CView::GetDocument
- AFXWIN/CView::IsSelected
- AFXWIN/CView::OnDragEnter
- AFXWIN/CView::OnDragLeave
- AFXWIN/CView::OnDragOver
- AFXWIN/CView::OnDragScroll
- AFXWIN/CView::OnDrop
- AFXWIN/CView::OnDropEx
- AFXWIN/CView::OnInitialUpdate
- AFXWIN/CView::OnPrepareDC
- AFXWIN/CView::OnScroll
- AFXWIN/CView::OnScrollBy
- AFXWIN/CView::OnActivateFrame
- AFXWIN/CView::OnActivateView
- AFXWIN/CView::OnBeginPrinting
- AFXWIN/CView::OnDraw
- AFXWIN/CView::OnEndPrinting
- AFXWIN/CView::OnEndPrintPreview
- AFXWIN/CView::OnPreparePrinting
- AFXWIN/CView::OnPrint
- AFXWIN/CView::OnUpdate
helpviewer_keywords:
- CView [MFC], CView
- CView [MFC], DoPreparePrinting
- CView [MFC], GetDocument
- CView [MFC], IsSelected
- CView [MFC], OnDragEnter
- CView [MFC], OnDragLeave
- CView [MFC], OnDragOver
- CView [MFC], OnDragScroll
- CView [MFC], OnDrop
- CView [MFC], OnDropEx
- CView [MFC], OnInitialUpdate
- CView [MFC], OnPrepareDC
- CView [MFC], OnScroll
- CView [MFC], OnScrollBy
- CView [MFC], OnActivateFrame
- CView [MFC], OnActivateView
- CView [MFC], OnBeginPrinting
- CView [MFC], OnDraw
- CView [MFC], OnEndPrinting
- CView [MFC], OnEndPrintPreview
- CView [MFC], OnPreparePrinting
- CView [MFC], OnPrint
- CView [MFC], OnUpdate
ms.assetid: 9cff3c56-7564-416b-b9a4-71a9254ed755
ms.openlocfilehash: f6be846e80209ce94c84222d61c37a7964baad03
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421565"
---
# <a name="cview-class"></a>Classe Cvisualização

Fornece a funcionalidade básica para classes de exibição definidas pelo usuário.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CView : public CWnd
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Cvisualização:: Cvisualização](#cview)|Constrói um objeto `CView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Cvisualização::D oPreparePrinting](#doprepareprinting)|Exibe a caixa de diálogo Imprimir e cria o contexto do dispositivo de impressora; Chame ao substituir a função membro `OnPreparePrinting`.|
|[Cvisualização:: GetDocument](#getdocument)|Retorna o documento associado à exibição.|
|[Cvisualização:: IsSelected](#isselected)|Testa se um item de documento está selecionado. Necessário para o suporte a OLE.|
|[Cvisualização:: OnDragEnter](#ondragenter)|Chamado quando um item é arrastado pela primeira vez para a região do tipo "arrastar e soltar" de uma exibição.|
|[Cvisualização:: OnDragLeave](#ondragleave)|Chamado quando um item arrastado deixa a região do tipo "arrastar e soltar" de uma exibição.|
|[Cvisualização:: OnDragOver](#ondragover)|Chamado quando um item é arrastado sobre a região de arrastar e soltar de uma exibição.|
|[Cvisualização:: OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|
|[Cvisualização:: OnDrop](#ondrop)|Chamado quando um item foi Descartado na região do tipo "arrastar e soltar" de uma exibição, manipulador padrão.|
|[Cvisualização:: OnDropEx](#ondropex)|Chamado quando um item foi Descartado na região do tipo "arrastar e soltar" de uma exibição, manipulador primário.|
|[Cvisualização:: OnInitialUpdate](#oninitialupdate)|Chamado depois que uma exibição é anexada pela primeira vez a um documento.|
|[Cvisualização:: OnPrepareDC](#onpreparedc)|Chamado antes que a função de membro `OnDraw` seja chamada para exibição de tela ou a função de membro `OnPrint` é chamada para impressão ou visualização de impressão.|
|[Cvisualização:: OnScroll](#onscroll)|Chamado quando itens OLE são arrastados além das bordas da exibição.|
|[Cvisualização:: OnScrollBy](#onscrollby)|Chamado quando uma exibição que contém itens OLE no local ativo é rolada.|

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Cvisualização:: OnActivateFrame](#onactivateframe)|Chamado quando a janela do quadro que contém a exibição é ativada ou desativada.|
|[Cvisualização:: OnActivateView](#onactivateview)|Chamado quando uma exibição é ativada.|
|[Cvisualização:: OnBeginPrinting](#onbeginprinting)|Chamado quando um trabalho de impressão começa; Substitua para alocar recursos de interface gráfica do dispositivo (GDI).|
|[Cvisualização:: OnDraw](#ondraw)|Chamado para renderizar uma imagem do documento para exibição de tela, impressão ou visualização de impressão. Implementação necessária.|
|[Cvisualização:: OnEndPrinting](#onendprinting)|Chamado quando um trabalho de impressão termina; Substitua para desalocar recursos GDI.|
|[Cvisualização:: OnEndPrintPreview](#onendprintpreview)|Chamado quando o modo de visualização é encerrado.|
|[Cvisualização:: OnPreparePrinting](#onprepareprinting)|Chamado antes de um documento ser impresso ou visualizado; substituir para inicializar a caixa de diálogo Imprimir.|
|[Cvisualização:: OnPrint](#onprint)|Chamado para imprimir ou visualizar uma página do documento.|
|[Cvisualização:: OnUpdate](#onupdate)|Chamado para notificar uma exibição de que seu documento foi modificado.|

## <a name="remarks"></a>Comentários

Uma exibição é anexada a um documento e atua como um intermediário entre o documento e o usuário: a exibição renderiza uma imagem do documento na tela ou impressora e interpreta a entrada do usuário como operações no documento.

Uma exibição é um filho de uma janela de quadro. Mais de uma exibição pode compartilhar uma janela de quadro, como no caso de uma janela separadora. A relação entre uma classe de exibição, uma classe de janela de quadro e uma classe de documento é estabelecida por um objeto de `CDocTemplate`. Quando o usuário abre uma nova janela ou divide uma existente, a estrutura constrói uma nova exibição e a anexa ao documento.

Um modo de exibição pode ser anexado a apenas um documento, mas um documento pode ter várias exibições anexadas a ele de uma só vez — por exemplo, se o documento for exibido em uma janela de Splitter ou em várias janelas filhas em um aplicativo MDI (interface de vários documentos). Seu aplicativo pode dar suporte a diferentes tipos de exibições para um determinado tipo de documento; por exemplo, um programa de processamento de palavras pode fornecer uma exibição de texto completa de um documento e um modo de exibição de estrutura de tópicos que mostra apenas os títulos de seção. Esses tipos diferentes de modos de exibição podem ser colocados em janelas de quadros separadas ou em painéis separados de uma única janela de quadro se você usar uma janela separadora.

Uma exibição pode ser responsável por lidar com vários tipos diferentes de entrada, como entrada de teclado, entrada de mouse ou entrada por meio de arrastar e soltar, bem como comandos de menus, barras de ferramentas ou barras de rolagem. Uma exibição recebe comandos encaminhados por sua janela do quadro. Se a exibição não tratar de um determinado comando, ela encaminhará o comando para seu documento associado. Como todos os destinos de comando, uma exibição manipula mensagens por meio de um mapa de mensagens.

A exibição é responsável por exibir e modificar os dados do documento, mas não para armazená-los. O documento fornece a exibição com os detalhes necessários sobre seus dados. Você pode permitir que a exibição acesse os membros de dados do documento diretamente ou pode fornecer funções de membro na classe de documento para que a classe de exibição chame.

Quando os dados de um documento são alterados, a exibição responsável pelas alterações normalmente chama a função [CDocument:: UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) para o documento, que notifica todas as outras exibições chamando a função membro `OnUpdate` para cada. A implementação padrão de `OnUpdate` invalida a área inteira do cliente da exibição. Você pode substituí-lo para invalidar apenas as regiões da área do cliente que são mapeadas para as partes modificadas do documento.

Para usar `CView`, derive uma classe dela e implemente a função de membro `OnDraw` para executar a exibição de tela. Você também pode usar `OnDraw` para executar a visualização de impressão e impressão. A estrutura manipula o loop de impressão para imprimir e visualizar o documento.

Uma exibição manipula mensagens de barra de rolagem com as funções de membro [CWnd:: OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd:: OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) . Você pode implementar a manipulação de mensagens da barra de rolagem nessas funções ou pode usar a classe derivada `CView` [CScrollView](../../mfc/reference/cscrollview-class.md) para lidar com a rolagem para você.

Além de `CScrollView`, o biblioteca MFC fornece nove outras classes derivadas de `CView`:

- [CCtrlView](../../mfc/reference/cctrlview-class.md), uma exibição que permite o uso da arquitetura de exibição de documentos com controles de árvore, lista e edição rica.

- [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md), uma exibição que exibe registros de banco de dados em controles de caixa de diálogo.

- [CEditView](../../mfc/reference/ceditview-class.md), uma exibição que fornece um editor de texto de várias linhas simples. Você pode usar um objeto `CEditView` como um controle em uma caixa de diálogo, bem como uma exibição em um documento.

- [CFormView](../../mfc/reference/cformview-class.md), uma exibição rolável que contém controles de caixa de diálogo e é baseada em um recurso de modelo de diálogo.

- [CListView](../../mfc/reference/clistview-class.md), uma exibição que permite o uso da arquitetura de exibição de documento com controles de lista.

- [CRecordView](../../mfc/reference/crecordview-class.md), uma exibição que exibe registros de banco de dados em controles de caixa de diálogo.

- [CRichEditView](../../mfc/reference/cricheditview-class.md), uma exibição que permite o uso da arquitetura de exibição de documentos com controles de edição avançados.

- [CScrollView](../../mfc/reference/cscrollview-class.md), uma exibição que fornece automaticamente suporte à rolagem.

- [CTreeView](../../mfc/reference/ctreeview-class.md), uma exibição que permite o uso da arquitetura de exibição de documento com controles de árvore.

A classe `CView` também tem uma classe de implementação derivada chamada `CPreviewView`, que é usada pela estrutura para executar a visualização de impressão. Essa classe fornece suporte para os recursos exclusivos da janela de visualização de impressão, como uma barra de ferramentas, visualização de página única ou dupla e zoom, ou seja, ampliando a imagem visualizada. Você não precisa chamar nem substituir nenhuma das funções de membro de `CPreviewView`, a menos que queira implementar sua própria interface para visualização de impressão (por exemplo, se você quiser dar suporte à edição no modo de visualização de impressão). Para obter mais informações sobre como usar `CView`, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [impressão](../../mfc/printing.md). Além disso, consulte a [Observação técnica 30](../../mfc/tn030-customizing-printing-and-print-preview.md) para obter mais detalhes sobre como personalizar a visualização de impressão.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cview"></a>Cvisualização:: Cvisualização

Constrói um objeto `CView`.

```
CView();
```

### <a name="remarks"></a>Comentários

A estrutura chama o Construtor quando uma nova janela de quadro é criada ou uma janela é dividida. Substitua a função de membro [OnInitialUpdate](#oninitialupdate) para inicializar a exibição depois que o documento for anexado.

##  <a name="doprepareprinting"></a>Cvisualização::D oPreparePrinting

Chame essa função de sua substituição de [OnPreparePrinting](#onprepareprinting) para invocar a caixa de diálogo Imprimir e criar um contexto de dispositivo de impressora.

```
BOOL DoPreparePrinting(CPrintInfo* pInfo);
```

### <a name="parameters"></a>parâmetros

*pInfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a visualização de impressão ou impressão puder ser iniciada; 0 se a operação tiver sido cancelada.

### <a name="remarks"></a>Comentários

O comportamento dessa função depende se ela está sendo chamada para impressão ou visualização de impressão (especificada pelo membro `m_bPreview` do parâmetro *pInfo* ). Se um arquivo estiver sendo impresso, essa função invocará a caixa de diálogo Imprimir, usando os valores na estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) para a qual *pInfo* aponta; Depois que o usuário fechar a caixa de diálogo, a função cria um contexto de dispositivo de impressora com base nas configurações especificadas pelo usuário na caixa de diálogo e retorna esse contexto de dispositivo por meio do parâmetro *pInfo* . Esse contexto de dispositivo é usado para imprimir o documento.

Se um arquivo estiver sendo visualizado, essa função criará um contexto de dispositivo de impressora usando as configurações de impressora atuais; Este contexto de dispositivo é usado para simular a impressora durante a visualização.

##  <a name="getdocument"></a>Cvisualização:: GetDocument

Chame essa função para obter um ponteiro para o documento da exibição.

```
CDocument* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CDocument](../../mfc/reference/cdocument-class.md) associado à exibição. NULL se a exibição não estiver anexada a um documento.

### <a name="remarks"></a>Comentários

Isso permite que você chame as funções de membro do documento.

##  <a name="isselected"></a>Cvisualização:: IsSelected

Chamado pelo Framework para verificar se o item de documento especificado está selecionado.

```
virtual BOOL IsSelected(const CObject* pDocItem) const;
```

### <a name="parameters"></a>parâmetros

*pDocItem*<br/>
Aponta para o item de documento que está sendo testado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item de documento especificado for selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função retorna FALSE. Substitua essa função se você estiver implementando a seleção usando objetos [CDocItem](../../mfc/reference/cdocitem-class.md) . Você deve substituir essa função se a exibição contiver itens OLE.

##  <a name="onactivateframe"></a>Cvisualização:: OnActivateFrame

Chamado pelo Framework quando a janela do quadro que contém a exibição é ativada ou desativada.

```
virtual void OnActivateFrame(
    UINT nState,
    CFrameWnd* pFrameWnd);
```

### <a name="parameters"></a>parâmetros

*nState*<br/>
Especifica se a janela do quadro está sendo ativada ou desativada. Pode ser um dos seguintes valores:

- WA_INACTIVE a janela do quadro está sendo desativada.

- WA_ACTIVE a janela do quadro está sendo ativada por meio de algum método que não seja um clique do mouse (por exemplo, usando a interface do teclado para selecionar a janela).

- WA_CLICKACTIVE a janela do quadro está sendo ativada por um clique do mouse

*pFrameWnd*<br/>
Ponteiro para a janela do quadro a ser ativada.

### <a name="remarks"></a>Comentários

Substitua essa função de membro se você quiser executar processamento especial quando a janela do quadro associada à exibição for ativada ou desativada. Por exemplo, [CFormView](../../mfc/reference/cformview-class.md) executa essa substituição quando salva e restaura o controle que tem o foco.

##  <a name="onactivateview"></a>Cvisualização:: OnActivateView

Chamado pelo Framework quando uma exibição é ativada ou desativada.

```
virtual void OnActivateView(
    BOOL bActivate,
    CView* pActivateView,
    CView* pDeactiveView);
```

### <a name="parameters"></a>parâmetros

*bActivate*<br/>
Indica se a exibição está sendo ativada ou desativada.

*pActivateView*<br/>
Aponta para o objeto de exibição que está sendo ativado.

*pDeactiveView*<br/>
Aponta para o objeto de exibição que está sendo desativado.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função define o foco para a exibição que está sendo ativada. Substitua essa função se desejar executar processamento especial quando uma exibição for ativada ou desativada. Por exemplo, se você quiser fornecer indicações visuais especiais que diferenciem o modo de exibição ativo das exibições inativas, examine o parâmetro *bActivate* e atualize a aparência da exibição de acordo.

Os parâmetros *pActivateView* e *pDeactiveView* apontam para a mesma exibição se a janela do quadro principal do aplicativo é ativada sem alteração no modo de exibição ativo — por exemplo, se o foco estiver sendo transferido de outro aplicativo para este, em vez de um modo de exibição para outro dentro do aplicativo ou ao alternar entre janelas filhas MDI. Isso permite que uma exibição reperceba sua paleta, se necessário.

Esses parâmetros diferem quando [CFrameWnd:: SetActiveView](../../mfc/reference/cframewnd-class.md#setactiveview) é chamado com uma exibição diferente da [CFrameWnd:: GetActiveView](../../mfc/reference/cframewnd-class.md#getactiveview) retornaria. Isso acontece com mais frequência com janelas de divisão.

##  <a name="onbeginprinting"></a>Cvisualização:: OnBeginPrinting

Chamado pelo Framework no início de um trabalho de impressão ou visualização de impressão, depois que `OnPreparePrinting` foi chamado.

```
virtual void OnBeginPrinting(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo de impressora.

*pInfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para alocar recursos GDI, como canetas ou fontes, necessárias especificamente para impressão. Selecione os objetos GDI no contexto do dispositivo de dentro da função de membro [OnPrint](#onprint) para cada página que os usa. Se você estiver usando o mesmo objeto de exibição para executar a exibição de tela e a impressão, use variáveis separadas para os recursos de GDI necessários para cada exibição; Isso permite que você atualize a tela durante a impressão.

Você também pode usar essa função para executar inicializações que dependem de propriedades do contexto do dispositivo de impressora. Por exemplo, o número de páginas necessárias para imprimir o documento pode depender de configurações que o usuário especificou na caixa de diálogo Imprimir (como comprimento da página). Nessa situação, não é possível especificar o comprimento do documento na função membro [OnPreparePrinting](#onprepareprinting) , onde você faria normalmente isso; Você deve aguardar até que o contexto do dispositivo de impressora tenha sido criado com base nas configurações da caixa de diálogo. [OnBeginPrinting](#onbeginprinting) é a primeira função substituível que fornece acesso ao objeto [CDC](../../mfc/reference/cdc-class.md) que representa o contexto do dispositivo de impressora, para que você possa definir o tamanho do documento a partir dessa função. Observe que, se o tamanho do documento não for especificado por esse tempo, uma barra de rolagem não será exibida durante a visualização de impressão.

##  <a name="ondragenter"></a>Cvisualização:: OnDragEnter

Chamado pelo Framework quando o mouse entra pela primeira vez na região sem rolagem da janela soltar destino.

```
virtual DROPEFFECT OnDragEnter(
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que está sendo arrastado para a área de soltar da exibição.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número dos seguintes: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*empresas*<br/>
A posição atual do mouse em relação à área do cliente da exibição.

### <a name="return-value"></a>Valor retornado

Um valor do tipo enumerado DROPEFFECT, que indica o tipo de descarte que ocorreria se o usuário removesse o objeto nessa posição. O tipo de drop geralmente depende do estado de chave atual indicado por *dwKeyState*. Um mapeamento padrão de KeyState para valores DROPEFFECT é:

- DROPEFFECT_NONE o objeto de dados não pode ser descartado nesta janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT cria uma ligação entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL Cria uma cópia do objeto Descartado.

- DROPEFFECT_MOVE para MK_ALT cria uma cópia do objeto descartado e exclui o objeto original. Normalmente, esse é o efeito de soltar padrão, quando o modo de exibição pode aceitar este objeto de dados.

Para obter mais informações, consulte o exemplo conceitos avançados do MFC [OCLIENT](../../overview/visual-cpp-samples.md).

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar DROPEFFECT_NONE.

Substitua essa função para se preparar para chamadas futuras para a função de membro [OnDragOver](#ondragover) . Todos os dados necessários do objeto de dados devem ser recuperados neste momento para uso posterior na função membro `OnDragOver`. O modo de exibição também deve ser atualizado neste momento para fornecer aos comentários visuais do usuário. Para obter mais informações, consulte o artigo [arrastar e soltar de OLE: implementar um destino de soltura](../../mfc/drag-and-drop-ole.md#implement-a-drop-target).

##  <a name="ondragleave"></a>Cvisualização:: OnDragLeave

Chamado pelo Framework durante uma operação de arrastar quando o mouse é movido para fora da área de destino válida para essa janela.

```
virtual void OnDragLeave();
```

### <a name="remarks"></a>Comentários

Substitua essa função se a exibição atual precisar limpar as ações executadas durante chamadas [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) , como remover qualquer comentário do usuário visual enquanto o objeto foi arrastado e descartado.

##  <a name="ondragover"></a>Cvisualização:: OnDragOver

Chamado pelo Framework durante uma operação de arrastar quando o mouse é movido sobre a janela soltar destino.

```
virtual DROPEFFECT OnDragOver(
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que está sendo arrastado sobre o destino de soltura.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número dos seguintes: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*empresas*<br/>
A posição atual do mouse relativa à área de exibição do cliente.

### <a name="return-value"></a>Valor retornado

Um valor do tipo enumerado DROPEFFECT, que indica o tipo de descarte que ocorreria se o usuário removesse o objeto nessa posição. O tipo de descarte geralmente depende do estado de chave atual, conforme indicado por *dwKeyState*. Um mapeamento padrão de KeyState para valores DROPEFFECT é:

- DROPEFFECT_NONE o objeto de dados não pode ser descartado nesta janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT cria uma ligação entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL Cria uma cópia do objeto Descartado.

- DROPEFFECT_MOVE para MK_ALT cria uma cópia do objeto descartado e exclui o objeto original. Normalmente, esse é o efeito de soltar padrão, quando o modo de exibição pode aceitar o objeto de dados.

Para obter mais informações, consulte o exemplo conceitos avançados do MFC [OCLIENT](../../overview/visual-cpp-samples.md).

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar DROPEFFECT_NONE.

Substitua essa função para fornecer aos comentários visuais do usuário durante a operação de arrastar. Como essa função é chamada continuamente, qualquer código contido nela deve ser otimizado o máximo possível. Para obter mais informações, consulte o artigo [arrastar e soltar de OLE: implementar um destino de soltura](../../mfc/drag-and-drop-ole.md#implement-a-drop-target).

##  <a name="ondragscroll"></a>Cvisualização:: OnDragScroll

Chamado pelo Framework antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o ponto está na região de rolagem.

```
virtual DROPEFFECT OnDragScroll(
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número dos seguintes: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*empresas*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor retornado

Um valor do tipo enumerado DROPEFFECT, que indica o tipo de descarte que ocorreria se o usuário removesse o objeto nessa posição. O tipo de drop geralmente depende do estado de chave atual indicado por *dwKeyState*. Um mapeamento padrão de KeyState para valores DROPEFFECT é:

- DROPEFFECT_NONE o objeto de dados não pode ser descartado nesta janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT cria uma ligação entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL Cria uma cópia do objeto Descartado.

- DROPEFFECT_MOVE para MK_ALT cria uma cópia do objeto descartado e exclui o objeto original.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo na exibição de destino.

Para obter mais informações, consulte o exemplo conceitos avançados do MFC [OCLIENT](../../overview/visual-cpp-samples.md).

### <a name="remarks"></a>Comentários

Substitua essa função quando desejar fornecer um comportamento especial para esse evento. A implementação padrão rola automaticamente o Windows quando o cursor é arrastado para a região de rolagem padrão dentro da borda de cada janela. Para obter mais informações, consulte o artigo [arrastar e soltar de OLE: implementar um destino de soltura](../../mfc/drag-and-drop-ole.md#implement-a-drop-target).

##  <a name="ondraw"></a>Cvisualização:: OnDraw

Chamado pelo Framework para renderizar uma imagem do documento.

```
virtual void OnDraw(CDC* pDC) = 0;
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar uma imagem do documento.

### <a name="remarks"></a>Comentários

A estrutura chama essa função para executar a exibição de tela, impressão e visualização de impressão e passa um contexto de dispositivo diferente em cada caso. Não há implementação padrão.

Você deve substituir essa função para exibir a exibição do documento. Você pode fazer chamadas GDI (interface gráfica do dispositivo) usando o objeto [CDC](../../mfc/reference/cdc-class.md) apontado pelo parâmetro *PDC* . Você pode selecionar recursos GDI, como canetas ou fontes, no contexto do dispositivo antes de desenhar e, em seguida, desselecioná-los posteriormente. Geralmente, seu código de desenho pode ser independente do dispositivo; ou seja, ele não exige informações sobre o tipo de dispositivo que está exibindo a imagem.

Para otimizar o desenho, chame a função membro [RectVisible](../../mfc/reference/cdc-class.md#rectvisible) do contexto do dispositivo para descobrir se um determinado retângulo será desenhado. Se você precisar distinguir entre a exibição de tela normal e a impressão, chame a função de membro [IsPrinting](../../mfc/reference/cdc-class.md#isprinting) do contexto do dispositivo.

##  <a name="ondrop"></a>Cvisualização:: OnDrop

Chamado pelo Framework quando o usuário libera um objeto de dados em um destino de soltura válido.

```
virtual BOOL OnDrop(
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

' pDataObject * aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que é Descartado para o destino de soltura.

*dropEffect*<br/>
O efeito de soltar que o usuário solicitou.

- DROPEFFECT_COPY Cria uma cópia do objeto de dados que está sendo Descartado.

- DROPEFFECT_MOVE Move o objeto de dados para o local atual do mouse.

- DROPEFFECT_LINK cria um vínculo entre um objeto de dados e seu servidor.

*empresas*<br/>
A posição atual do mouse relativa à área de exibição do cliente.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o descarte tiver sido bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada e retorna FALSE.

Substitua essa função para implementar o efeito de um depósito OLE na área do cliente da exibição. O objeto de dados pode ser examinado por meio de *pDataObject* para os formatos de dados da área de transferência e os dados descartados no ponto especificado.

> [!NOTE]
>  A estrutura não chamará essa função se houver uma substituição para [OnDropEx](#ondropex) nessa classe de exibição.

##  <a name="ondropex"></a>Cvisualização:: OnDropEx

Chamado pelo Framework quando o usuário libera um objeto de dados em um destino de soltura válido.

```
virtual DROPEFFECT OnDropEx(
    COleDataObject* pDataObject,
    DROPEFFECT dropDefault,
    DROPEFFECT dropList,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que é Descartado para o destino de soltar.

*dropDefault*<br/>
O efeito que o usuário escolheu para a operação de soltar padrão com base no estado de chave atual. Pode ser DROPEFFECT_NONE. Os efeitos de soltar são discutidos na seção comentários.

*lista suspensa*<br/>
Uma lista dos efeitos de soltar aos quais a fonte de soltar dá suporte. Os valores de queda de efeito podem ser combinados usando a **&#124;** operação OR () de OR bit. Os efeitos de soltar são discutidos na seção comentários.

*empresas*<br/>
A posição atual do mouse relativa à área de exibição do cliente.

### <a name="return-value"></a>Valor retornado

O efeito de soltar que resultou da tentativa de soltar no local especificado por *ponto*. Deve ser um dos valores indicados por *dropEffectList*. Os efeitos de soltar são discutidos na seção comentários.

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar um valor fictício (-1) para indicar que a estrutura deve chamar o manipulador [OnDrop](#ondrop) .

Substitua essa função para implementar o efeito de arrastar e soltar com botão direito do mouse. Arrastar e soltar com botão direito do mouse normalmente exibe um menu de opções quando o botão direito do mouse é liberado.

A substituição de `OnDropEx` deve consultar o botão direito do mouse. Você pode chamar [GetKeyState](/windows/win32/api/winuser/nf-winuser-getkeystate) ou armazenar o estado correto do botão do mouse no manipulador de [OnDragEnter](#ondragenter) .

- Se o botão direito do mouse estiver inativo, sua substituição deverá exibir um menu pop-up que oferece o suporte a drop Effects pela fonte drop.

   - Examine a *lista suspensa* para determinar os efeitos descartados suportados pela fonte de soltar. Habilite apenas essas ações no menu pop-up.

   - Use [SetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-setmenudefaultitem) para definir a ação padrão com base em *DropDefault*.

   - Por fim, execute a ação indicada pela seleção do usuário no menu pop-up.

- Se o botão direito do mouse não estiver inativo, sua substituição deverá processá-lo como uma solicitação de descarte padrão. Use o efeito de soltar especificado em *DropDefault*. Como alternativa, sua substituição pode retornar o valor fictício (-1) para indicar que `OnDrop` tratará dessa operação de remoção.

Use *pDataObject* para examinar o `COleDataObject` para o formato de dados da área de transferência e os dados descartados no ponto especificado.

Drop Effects descreve a ação associada a uma operação DROP. Consulte a seguinte lista de efeitos suspensos:

- DROPEFFECT_NONE uma queda não seria permitida.

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo no destino.

Para obter mais informações sobre como definir o comando de menu padrão, consulte [SetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-setmenudefaultitem) no SDK do Windows e [CMenu:: GetSafeHmenu](../../mfc/reference/cmenu-class.md#getsafehmenu) neste volume.

##  <a name="onendprinting"></a>Cvisualização:: OnEndPrinting

Chamado pelo Framework depois que um documento é impresso ou visualizado.

```
virtual void OnEndPrinting(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo de impressora.

*pInfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para liberar os recursos de GDI alocados na função membro [OnBeginPrinting](#onbeginprinting) .

##  <a name="onendprintpreview"></a>Cvisualização:: OnEndPrintPreview

Chamado pelo Framework quando o usuário sai do modo de visualização de impressão.

```
virtual void OnEndPrintPreview(
    CDC* pDC,
    CPrintInfo* pInfo,
    POINT point,
    CPreviewView* pView);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo de impressora.

*pInfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

*empresas*<br/>
Especifica o ponto na página que foi exibida pela última vez no modo de visualização.

*pView*<br/>
Aponta para o objeto de exibição usado para visualização.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama a função membro [OnEndPrinting](#onendprinting) e restaura a janela do quadro principal para o estado em que estava antes do início da visualização de impressão. Substitua essa função para executar processamento especial quando o modo de visualização for encerrado. Por exemplo, se você quiser manter a posição do usuário no documento ao alternar do modo de visualização para o modo de exibição normal, poderá rolar para a posição descrita pelo parâmetro *Point* e o membro `m_nCurPage` da estrutura de `CPrintInfo` para a qual o parâmetro *pInfo* aponta.

Sempre chame a versão da classe base do `OnEndPrintPreview` da sua substituição, normalmente no final da função.

##  <a name="oninitialupdate"></a>Cvisualização:: OnInitialUpdate

Chamado pelo Framework depois que a exibição é anexada primeiro ao documento, mas antes de a exibição ser inicialmente exibida.

```
virtual void OnInitialUpdate();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama a função de membro [OnUpdate](#onupdate) sem informações de dica (isto é, usando os valores padrão de 0 para o parâmetro *lHint* e NULL para o parâmetro *pHint* ). Substitua essa função para executar uma inicialização única que exija informações sobre o documento. Por exemplo, se seu aplicativo tiver documentos de tamanho fixo, você poderá usar essa função para inicializar os limites de rolagem de uma exibição com base no tamanho do documento. Se seu aplicativo der suporte a documentos de tamanho variável, use [OnUpdate](#onupdate) para atualizar os limites de rolagem toda vez que o documento for alterado.

##  <a name="onpreparedc"></a>Cvisualização:: OnPrepareDC

Chamado pelo Framework antes que a função de membro [OnDraw](#ondraw) seja chamada para exibição de tela e antes que a função de membro [OnPrint](#onprint) seja chamada para cada página durante a impressão ou visualização de impressão.

```
virtual void OnPrepareDC(
    CDC* pDC,
    CPrintInfo* pInfo = NULL);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar uma imagem do documento.

*pInfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual se `OnPrepareDC` estiver sendo chamado para impressão ou visualização de impressão; o membro `m_nCurPage` especifica a página a ser impressa. Esse parâmetro será nulo se `OnPrepareDC` estiver sendo chamado para exibição de tela.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não fará nada se a função for chamada para exibição de tela. No entanto, essa função é substituída em classes derivadas, como [CScrollView](../../mfc/reference/cscrollview-class.md), para ajustar os atributos do contexto do dispositivo; Consequentemente, você deve sempre chamar a implementação da classe base no início da sua substituição.

Se a função for chamada para impressão, a implementação padrão examinará as informações de página armazenadas no parâmetro *pInfo* . Se o comprimento do documento não tiver sido especificado, `OnPrepareDC` assumirá que o documento é uma página longa e interromperá o loop de impressão depois que uma página for impressa. A função interrompe o loop de impressão definindo o membro `m_bContinuePrinting` da estrutura como FALSE.

Substitua `OnPrepareDC` por qualquer um dos seguintes motivos:

- Para ajustar os atributos do contexto do dispositivo conforme necessário para a página especificada. Por exemplo, se você precisar definir o modo de mapeamento ou outras características do contexto do dispositivo, faça isso nessa função.

- Para executar a paginação do tempo de impressão. Normalmente, você especifica o comprimento do documento quando a impressão começa, usando a função de membro [OnPreparePrinting](#onprepareprinting) . No entanto, se você não sabe antecipadamente por quanto tempo o documento é (por exemplo, ao imprimir um número indeterminado de registros de um banco de dados), substitua `OnPrepareDC` para testar o fim do documento enquanto ele está sendo impresso. Quando não houver mais do documento a ser impresso, defina o membro de `m_bContinuePrinting` da estrutura de `CPrintInfo` como FALSE.

- Para enviar códigos de escape para a impressora de acordo com a página. Para enviar códigos de escape de `OnPrepareDC`, chame a função membro `Escape` do parâmetro *PDC* .

Chame a versão da classe base do `OnPrepareDC` no início da sua substituição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#183](../../mfc/codesnippet/cpp/cview-class_1.cpp)]

##  <a name="onprepareprinting"></a>Cvisualização:: OnPreparePrinting

Chamado pelo Framework antes de um documento ser impresso ou visualizado.

```
virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
```

### <a name="parameters"></a>parâmetros

*pInfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="return-value"></a>Valor retornado

Diferente de zero para iniciar a impressão; 0 se o trabalho de impressão tiver sido cancelado.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada.

Você deve substituir essa função para habilitar a visualização de impressão e impressão. Chame a função de membro [DoPreparePrinting](#doprepareprinting) , passando-a para o parâmetro *pInfo* e, em seguida, retorne seu valor de retorno; `DoPreparePrinting` exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo de impressora. Se você quiser inicializar a caixa de diálogo Imprimir com valores diferentes dos padrões, atribua valores aos membros de *pInfo*. Por exemplo, se você souber o comprimento do documento, passe o valor para a função membro [SetMaxPage](../../mfc/reference/cprintinfo-structure.md#setmaxpage) de *pInfo* antes de chamar `DoPreparePrinting`. Esse valor é exibido na caixa para: na parte de intervalo da caixa de diálogo Imprimir.

`DoPreparePrinting` não exibe a caixa de diálogo Imprimir para um trabalho de visualização. Se você quiser ignorar a caixa de diálogo Imprimir para um trabalho de impressão, verifique se o membro `m_bPreview` de *pInfo* é false e defina-o como true antes de passá-lo para `DoPreparePrinting`; redefina-a como FALSE posteriormente.

Se você precisar executar inicializações que exigem acesso ao objeto `CDC` que representa o contexto do dispositivo de impressora (por exemplo, se você precisar saber o tamanho da página antes de especificar o comprimento do documento), substitua a função membro `OnBeginPrinting`.

Se você quiser definir o valor do `m_nNumPreviewPages` ou `m_strPageDesc` membros do parâmetro *pInfo* , faça isso depois de chamar `DoPreparePrinting`. A função membro `DoPreparePrinting` define `m_nNumPreviewPages` para o valor encontrado no aplicativo. Arquivo INI e define `m_strPageDesc` para o valor padrão.

### <a name="example"></a>Exemplo

  Substitua `OnPreparePrinting` e chame `DoPreparePrinting` da substituição para que a estrutura exiba uma caixa de diálogo de impressão e crie um DC de impressora para você.

[!code-cpp[NVC_MFCDocView#184](../../mfc/codesnippet/cpp/cview-class_2.cpp)]

Se você souber quantas páginas o documento contém, defina a página máximo em `OnPreparePrinting` antes de chamar `DoPreparePrinting`. A estrutura exibirá o número máximo de páginas na caixa "para" da caixa de diálogo Imprimir.

[!code-cpp[NVC_MFCDocView#185](../../mfc/codesnippet/cpp/cview-class_3.cpp)]

##  <a name="onprint"></a>Cvisualização:: OnPrint

Chamado pelo Framework para imprimir ou visualizar uma página do documento.

```
virtual void OnPrint(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo de impressora.

*pInfo*<br/>
Aponta para uma estrutura de `CPrintInfo` que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

Para cada página sendo impressa, a estrutura chama essa função imediatamente após chamar a função de membro [OnPrepareDC](#onpreparedc) . A página que está sendo impressa é especificada pelo membro de `m_nCurPage` da estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) para a qual o *pInfo* aponta. A implementação padrão chama a função de membro [OnDraw](#ondraw) e a passa para o contexto do dispositivo de impressora.

Substitua essa função por qualquer um dos seguintes motivos:

- Para permitir a impressão de documentos com multipáginas. Renderizar apenas a parte do documento que corresponde à página que está sendo impressa no momento. Se estiver usando `OnDraw` para executar a renderização, você poderá ajustar a origem do visor para que apenas a parte apropriada do documento seja impressa.

- Para fazer com que a imagem impressa pareça diferente da imagem da tela (ou seja, se seu aplicativo não for WYSIWYG). Em vez de passar o contexto do dispositivo de impressora para `OnDraw`, use o contexto do dispositivo para renderizar uma imagem usando atributos não mostrados na tela.

   Se você precisar de recursos GDI para impressão que você não usa para exibição de tela, selecione-os no contexto do dispositivo antes de desenhar e desmarque-os posteriormente. Esses recursos GDI devem ser alocados em [OnBeginPrinting](#onbeginprinting) e liberados em [OnEndPrinting](#onendprinting).

- Para implementar cabeçalhos ou rodapés. Você ainda pode usar `OnDraw` para fazer a renderização restringindo a área em que ela pode ser impressa.

Observe que o membro `m_rectDraw` do parâmetro *pInfo* descreve a área imprimível da página em unidades lógicas.

Não chame `OnPrepareDC` em sua substituição de `OnPrint`; a estrutura chama `OnPrepareDC` automaticamente antes de chamar `OnPrint`.

### <a name="example"></a>Exemplo

Este é um esqueleto para uma função de `OnPrint` substituída:

[!code-cpp[NVC_MFCDocView#186](../../mfc/codesnippet/cpp/cview-class_4.cpp)]

Para obter outro exemplo, consulte [CRichEditView::P rintinsiderect](../../mfc/reference/cricheditview-class.md#printinsiderect).

##  <a name="onscroll"></a>Cvisualização:: OnScroll

Chamado pelo Framework para determinar se a rolagem é possível.

```
virtual BOOL OnScroll(
    UINT nScrollCode,
    UINT nPos,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>parâmetros

*nScrollCode*<br/>
Um código de barra de rolagem que indica a solicitação de rolagem do usuário. Esse parâmetro é composto por duas partes: um byte de ordem inferior, que determina o tipo de rolagem que ocorre horizontalmente e um byte de ordem superior, que determina o tipo de rolagem que ocorre verticalmente:

- SB_BOTTOM Rola para a parte inferior.

- SB_LINEDOWN rola uma linha para baixo.

- SB_LINEUP rola uma linha para cima.

- SB_PAGEDOWN rola uma página para baixo.

- SB_PAGEUP Rola uma página para cima.

- SB_THUMBTRACK arrasta a caixa de rolagem para a posição especificada. A posição atual é especificada em *nPos*.

- SB_TOP rola para a parte superior.

*nPos*<br/>
Contém a posição da caixa de rolagem atual se o código de barra de rolagem for SB_THUMBTRACK; caso contrário, não será usado. Dependendo do intervalo de rolagem inicial, *nPos* pode ser negativo e deve ser convertido em um **int** , se necessário.

*bDoScroll*<br/>
Determina se você deve realmente fazer a ação de rolagem especificada. Se for TRUE, a rolagem deve ocorrer; Se for FALSE, a rolagem não deverá ocorrer.

### <a name="return-value"></a>Valor retornado

Se *bDoScroll* for true e a exibição for realmente rolada, retorne diferente de zero; caso contrário, 0. Se *bDoScroll* for false, retorne o valor que você teria retornado se *bDoScroll* fosse verdadeiro, mesmo que você não faça realmente a rolagem.

### <a name="remarks"></a>Comentários

Em um caso, essa função é chamada pelo Framework com *bDoScroll* definido como true quando a exibição recebe uma mensagem de ScrollBar. Nesse caso, você deve realmente rolar a exibição. No outro caso, essa função é chamada com *bDoScroll* definido como false quando um item OLE é inicialmente arrastado para a região de rolagem automática de um destino de soltar antes de a rolagem realmente ocorrer. Nesse caso, você não deve realmente rolar a exibição.

##  <a name="onscrollby"></a>Cvisualização:: OnScrollBy

Chamado pelo Framework quando o usuário exibe uma área além da exibição atual do documento, arrastando um item OLE para as bordas atuais da exibição ou manipulando as barras de rolagem vertical ou horizontal.

```
virtual BOOL OnScrollBy(
    CSize sizeScroll,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>parâmetros

*sizeScroll*<br/>
Número de pixels rolados horizontal e verticalmente.

*bDoScroll*<br/>
Determina se a rolagem da exibição ocorre. Se for TRUE, a rolagem ocorrerá; Se for FALSE, a rolagem não ocorrerá.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a exibição puder ser rolada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Em classes derivadas, esse método verifica se a exibição é rolável na direção que o usuário solicitou e, em seguida, atualiza a nova região, se necessário. Essa função é chamada automaticamente por [CWnd:: OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd:: OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) para executar a solicitação de rolagem real.

A implementação padrão desse método não altera a exibição, mas se não for chamada, a exibição não rolará em uma classe derivada de `CScrollView`.

Se a largura ou a altura do documento exceder 32767 pixels, a rolagem anterior a 32767 falhará porque `OnScrollBy` é chamado com um argumento *sizeScroll* inválido.

##  <a name="onupdate"></a>Cvisualização:: OnUpdate

Chamado pelo Framework após a modificação do documento da exibição; Essa função é chamada por [CDocument:: UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) e permite que a exibição Atualize sua exibição para refletir essas modificações.

```
virtual void OnUpdate(
    CView* pSender,
    LPARAM lHint,
    CObject* pHint);
```

### <a name="parameters"></a>parâmetros

*pSender*<br/>
Aponta para a exibição que modificou o documento, ou NULL se todas as exibições forem atualizadas.

*lHint*<br/>
Contém informações sobre as modificações.

*pHint*<br/>
Aponta para um objeto que armazena informações sobre as modificações.

### <a name="remarks"></a>Comentários

Ele também é chamado pela implementação padrão de [OnInitialUpdate](#oninitialupdate). A implementação padrão invalida toda a área do cliente, marcando-a para pintura quando a próxima mensagem de WM_PAINT for recebida. Substitua essa função se desejar atualizar somente as regiões que são mapeadas para as partes modificadas do documento. Para fazer isso, você deve passar informações sobre as modificações usando os parâmetros de dica.

Para usar *lHint*, defina valores de dica especiais, normalmente um bitmask ou um tipo enumerado, e faça com que o documento passe um desses valores. Para usar *pHint*, derive uma classe Hint de [CObject](../../mfc/reference/cobject-class.md) e faça com que o documento passe um ponteiro para um objeto Hint; ao substituir `OnUpdate`, use a função de membro [CObject:: IsKindOf](../../mfc/reference/cobject-class.md#iskindof) para determinar o tipo de tempo de execução do objeto de dica.

Normalmente, você não deve executar nenhum desenho diretamente do `OnUpdate`. Em vez disso, determine o retângulo que descreve, em coordenadas do dispositivo, a área que requer atualização; Passe este retângulo para [CWnd:: InvalidateRect](../../mfc/reference/cwnd-class.md#invalidaterect). Isso faz com que a pintura ocorra na próxima vez que uma mensagem de [WM_PAINT](/windows/win32/gdi/wm-paint) for recebida.

Se *lHint* for 0 e *pHint* for NULL, o documento enviará uma notificação de atualização genérica. Se uma exibição receber uma notificação de atualização genérica ou se não puder decodificar as dicas, ela deverá invalidar a área inteira do cliente.

## <a name="see-also"></a>Confira também

[Exemplo de MDIDOCVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)
