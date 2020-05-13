---
title: Classe CView
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
ms.openlocfilehash: 763e36b0736ce588e7e2aded25e50347f9e0ca70
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373196"
---
# <a name="cview-class"></a>Classe CView

Fornece a funcionalidade básica para classes de exibição definidas pelo usuário.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CView : public CWnd
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CView::CView](#cview)|Constrói um objeto `CView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CView::DoPreparePrinting](#doprepareprinting)|Exibe a caixa de diálogo Imprimir e cria o contexto do dispositivo da impressora; chamar ao sobrepor a função membro. `OnPreparePrinting`|
|[CView::GetDocument](#getdocument)|Retorna o documento associado à exibição.|
|[cview::isSelected](#isselected)|Testa se um item do documento é selecionado. Necessário para suporte ao OLE.|
|[CView::OnDragEnter](#ondragenter)|Chamado quando um item é arrastado pela primeira vez para a região de arrastar e soltar de uma vista.|
|[CView::OnDragLeave](#ondragleave)|Chamado quando um item arrastado deixa a região de arrastar e soltar de uma vista.|
|[CView::OnDragover](#ondragover)|Chamado quando um item é arrastado sobre a região de arrastar e soltar de uma vista.|
|[CView::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região do pergaminho da janela.|
|[CView::OnDrop](#ondrop)|Chamado quando um item foi lançado na região de arrastar e soltar de uma exibição, manipulador padrão.|
|[CView::OnDropEx](#ondropex)|Chamado quando um item foi lançado na região de arrastar e soltar de uma exibição, manipulador primário.|
|[CView::OnInitialUpdate](#oninitialupdate)|Chamado após uma exibição é anexado pela primeira vez a um documento.|
|[CView::OnPrepareDC](#onpreparedc)|Chamado antes `OnDraw` que a função do `OnPrint` membro seja chamada para exibição de tela ou a função do membro é chamada para impressão ou visualização de impressão.|
|[CView::OnScroll](#onscroll)|Chamado quando os itens OLE são arrastados para além das bordas da vista.|
|[CView::OnScrollby](#onscrollby)|Chamado quando uma exibição contendo itens OLE ativos no local é rolada.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CView::OnActivateFrame](#onactivateframe)|Chamada quando a janela do quadro contendo a visualização é ativada ou desativada.|
|[CView::OnActivateView](#onactivateview)|Chamado quando uma vista é ativada.|
|[Cview::OnBeginPrinting](#onbeginprinting)|Chamado quando um trabalho de impressão começa; substituir para alocar recursos de interface de dispositivo gráfico (GDI).|
|[CView::OnDraw](#ondraw)|Chamado para renderizar uma imagem do documento para exibição de tela, impressão ou visualização de impressão. Implementação necessária.|
|[CView::OnEndPrinting](#onendprinting)|Chamado quando um trabalho de impressão termina; substituir para desalocar recursos GDI.|
|[CView::OnendPrintPreview](#onendprintpreview)|Chamado quando o modo de visualização é saído.|
|[CView::OnPreparePrinting](#onprepareprinting)|Chamado antes de um documento ser impresso ou visualizado; substituir para inicializar a caixa de diálogo Imprimir.|
|[CView::OnPrint](#onprint)|Chamado para imprimir ou visualizar uma página do documento.|
|[CView::OnUpdate](#onupdate)|Chamado para notificar uma visão de que seu documento foi modificado.|

## <a name="remarks"></a>Comentários

Uma visualização é anexada a um documento e atua como um intermediário entre o documento e o usuário: a visualização renderiza uma imagem do documento na tela ou impressora e interpreta a entrada do usuário como operações no documento.

Uma vista é uma criança de uma janela de quadro. Mais de uma vista pode compartilhar uma janela de quadro, como no caso de uma janela de divisor. A relação entre uma classe de exibição, uma classe de `CDocTemplate` janela de quadro e uma classe de documento é estabelecida por um objeto. Quando o usuário abre uma nova janela ou divide uma já existente, a estrutura constrói uma nova visão e a anexa ao documento.

Uma exibição pode ser anexada a apenas um documento, mas um documento pode ter várias visualizações anexadas a ele ao mesmo tempo — por exemplo, se o documento for exibido em uma janela de divisor ou em várias janelas de crianças em um aplicativo de interface de documento múltiplo (MDI). Seu aplicativo pode suportar diferentes tipos de visualizações para um determinado tipo de documento; por exemplo, um programa de processamento de texto pode fornecer uma exibição completa de texto de um documento e uma exibição de contorno que mostra apenas os títulos da seção. Esses diferentes tipos de visualizações podem ser colocados em janelas separadas ou em painéis separados de uma única janela de quadro se você usar uma janela divisora.

Uma exibição pode ser responsável por lidar com vários tipos diferentes de entrada, como entrada de teclado, entrada do mouse ou entrada via arrastar e soltar, bem como comandos de menus, barras de ferramentas ou barras de rolagem. Uma vista recebe comandos encaminhados pela janela do quadro. Se a exibição não manusear um determinado comando, ela encaminha o comando para o documento associado. Como todos os alvos de comando, uma exibição lida com mensagens através de um mapa de mensagem.

A exibição e modificação dos dados do documento é responsável por exibir e modificar os dados do documento, mas não por armazená-los. O documento fornece a visão com os detalhes necessários sobre seus dados. Você pode permitir que a exibição acesse diretamente os membros de dados do documento, ou você pode fornecer funções de membro na classe de documentos para a classe de exibição chamar.

Quando os dados de um documento são alterados, a exibição responsável pelas alterações normalmente chama a função [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) para o documento, que notifica todas as outras exibições chamando a `OnUpdate` função de membro para cada uma. A implementação `OnUpdate` padrão de invalida toda a área de cliente da view. Você pode substituí-lo para invalidar apenas as regiões da área cliente que mapeiam as partes modificadas do documento.

Para `CView`usar, obtenha uma classe `OnDraw` a partir dele e implemente a função de membro para executar a exibição da tela. Você também `OnDraw` pode usar para realizar a impressão e a visualização de impressão. A estrutura lida com o loop de impressão para impressão e visualização do documento.

Uma exibição lida com mensagens de barra de rolagem com as funções [cwnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll.](../../mfc/reference/cwnd-class.md#onvscroll) Você pode implementar o manuseio de mensagens de barra `CView` de rolagem nessas funções ou pode usar o [CScrollView](../../mfc/reference/cscrollview-class.md) da classe derivada para lidar com a rolagem para você.

Além `CScrollView`disso, a Biblioteca de Classes da `CView`Microsoft Foundation fornece outras nove classes derivadas de :

- [CCtrlView](../../mfc/reference/cctrlview-class.md), uma exibição que permite o uso de documentos - exibir arquitetura com controles de edição de árvore, lista e ricos.

- [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md), uma exibição que exibe registros de banco de dados em controles de caixa de diálogo.

- [CEditView](../../mfc/reference/ceditview-class.md), uma exibição que fornece um simples editor de texto multilinha. Você pode `CEditView` usar um objeto como um controle em uma caixa de diálogo, bem como uma exibição em um documento.

- [CFormView](../../mfc/reference/cformview-class.md), uma exibição rolável que contém controles de caixa de diálogo e é baseada em um recurso de modelo de diálogo.

- [CListView](../../mfc/reference/clistview-class.md), uma exibição que permite o uso de documentos - exibir arquitetura com controles de lista.

- [CRecordView](../../mfc/reference/crecordview-class.md), uma exibição que exibe registros de banco de dados em controles de caixa de diálogo.

- [CRichEditView](../../mfc/reference/cricheditview-class.md), uma exibição que permite o uso de documentos - visualizar arquitetura com controles de edição ricos.

- [CScrollView](../../mfc/reference/cscrollview-class.md), uma exibição que fornece automaticamente suporte de rolagem.

- [CTreeView](../../mfc/reference/ctreeview-class.md), uma exibição que permite o uso de documentos - visualizar arquitetura com controles de árvores.

A `CView` classe também tem uma `CPreviewView`classe de implementação derivada chamada , que é usada pela framework para realizar visualização de impressão. Essa classe fornece suporte para os recursos exclusivos da janela de visualização de impressão, como uma barra de ferramentas, visualização de uma ou duas páginas e zoom, ou seja, ampliando a imagem visualizada. Você não precisa ligar ou substituir `CPreviewView`nenhuma das funções de membro, a menos que você queira implementar sua própria interface para visualização de impressão (por exemplo, se você quiser suportar a edição no modo de visualização de impressão). Para obter mais `CView`informações sobre como usar, consulte [Document/View Architecture](../../mfc/document-view-architecture.md) and [Printing](../../mfc/printing.md). Além disso, consulte [nota técnica 30](../../mfc/tn030-customizing-printing-and-print-preview.md) para obter mais detalhes sobre a personalização da visualização de impressão.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cviewcview"></a><a name="cview"></a>CView::CView

Constrói um objeto `CView`.

```
CView();
```

### <a name="remarks"></a>Comentários

A estrutura chama o construtor quando uma nova janela de quadro é criada ou uma janela é dividida. Anular a função de membro [OnInitialUpdate](#oninitialupdate) para inicializar a exibição depois que o documento for anexado.

## <a name="cviewdoprepareprinting"></a><a name="doprepareprinting"></a>CView::DoPreparePrinting

Chame esta função a partir de sua substituição de [OnPreparePrinting](#onprepareprinting) para invocar a caixa de diálogo Imprimir e criar um contexto de dispositivo de impressora.

```
BOOL DoPreparePrinting(CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*Pinfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="return-value"></a>Valor retornado

Não zero se a impressão ou a visualização de impressão puderem começar; 0 se a operação foi cancelada.

### <a name="remarks"></a>Comentários

O comportamento dessa função depende se ela está sendo chamada para impressão `m_bPreview` ou visualização de impressão (especificada pelo membro do parâmetro *pInfo).* Se um arquivo estiver sendo impresso, essa função invoca a caixa de diálogo Imprimir, usando os valores na estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que *o pInfo* aponta; depois que o usuário fecha a caixa de diálogo, a função cria um contexto de dispositivo de impressora com base nas configurações especificadas pelo usuário na caixa de diálogo e retorna este contexto do dispositivo através do parâmetro *pInfo.* Este contexto do dispositivo é usado para imprimir o documento.

Se um arquivo estiver sendo visualizado, essa função criará um contexto de dispositivo de impressora usando as configurações atuais da impressora; este contexto do dispositivo é usado para simular a impressora durante a visualização.

## <a name="cviewgetdocument"></a><a name="getdocument"></a>CView::GetDocument

Chame esta função para obter um ponteiro para o documento da exibição.

```
CDocument* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CDocument](../../mfc/reference/cdocument-class.md) associado à exibição. NULL se a exibição não estiver anexada a um documento.

### <a name="remarks"></a>Comentários

Isso permite que você ligue para as funções de membro do documento.

## <a name="cviewisselected"></a><a name="isselected"></a>cview::isSelected

Chamado pela estrutura para verificar se o item do documento especificado está selecionado.

```
virtual BOOL IsSelected(const CObject* pDocItem) const;
```

### <a name="parameters"></a>Parâmetros

*pDocItem*<br/>
Aponta para o item do documento que está sendo testado.

### <a name="return-value"></a>Valor retornado

Não zero se o item do documento especificado for selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão desta função retorna FALSE. Anular esta função se você estiver implementando a seleção usando objetos [CDocItem.](../../mfc/reference/cdocitem-class.md) Você deve substituir esta função se sua exibição contiver itens OLE.

## <a name="cviewonactivateframe"></a><a name="onactivateframe"></a>CView::OnActivateFrame

Chamado pela estrutura quando a janela do quadro que contém a exibição é ativada ou desativada.

```
virtual void OnActivateFrame(
    UINT nState,
    CFrameWnd* pFrameWnd);
```

### <a name="parameters"></a>Parâmetros

*Nstate*<br/>
Especifica se a janela do quadro está sendo ativada ou desativada. Pode ser um dos seguintes valores:

- WA_INACTIVE A janela do quadro está sendo desativada.

- WA_ACTIVE A janela do quadro está sendo ativada através de algum método que não seja um clique do mouse (por exemplo, usando a interface do teclado para selecionar a janela).

- WA_CLICKACTIVE A janela do quadro está sendo ativada por um clique do mouse

*pFrameWnd*<br/>
Ponteiro para a janela do quadro que deve ser ativado.

### <a name="remarks"></a>Comentários

Anular esta função de membro se você quiser realizar um processamento especial quando a janela do quadro associada à exibição estiver ativada ou desativada. Por exemplo, [o CFormView](../../mfc/reference/cformview-class.md) executa essa substituição quando salva e restaura o controle que tem foco.

## <a name="cviewonactivateview"></a><a name="onactivateview"></a>CView::OnActivateView

Chamado pela estrutura quando uma exibição é ativada ou desativada.

```
virtual void OnActivateView(
    BOOL bActivate,
    CView* pActivateView,
    CView* pDeactiveView);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Indica se a visão está sendo ativada ou desativada.

*pActivateView*<br/>
Aponta para o objeto de exibição que está sendo ativado.

*pDeactiveView*<br/>
Aponta para o objeto de exibição que está sendo desativado.

### <a name="remarks"></a>Comentários

A implementação padrão desta função define o foco para a exibição que está sendo ativada. Anular esta função se você quiser realizar um processamento especial quando uma exibição é ativada ou desativada. Por exemplo, se você quiser fornecer pistas visuais especiais que distinguem a exibição ativa das exibições inativas, você examinará o parâmetro *bActivate* e atualizará a aparência da exibição de acordo.

Os parâmetros *pActivateView* e *pDeactiveView* apontam para a mesma exibição se a janela principal do quadro do aplicativo estiver ativada sem alteração na exibição ativa — por exemplo, se o foco está sendo transferido de outro aplicativo para este, em vez de de uma exibição para outra dentro do aplicativo ou ao alternar entre janelas de crianças MDI. Isso permite que uma visão rerealize sua paleta, se necessário.

Esses parâmetros diferem quando [CFrameWnd::SetActiveView](../../mfc/reference/cframewnd-class.md#setactiveview) é chamado com uma exibição diferente do que [O CFrameWnd::GetActiveView](../../mfc/reference/cframewnd-class.md#getactiveview) retornaria. Isso acontece na maioria das vezes com janelas de divisor.

## <a name="cviewonbeginprinting"></a><a name="onbeginprinting"></a>Cview::OnBeginPrinting

Chamado pelo framework no início de um trabalho `OnPreparePrinting` de visualização de impressão ou impressão, depois de ter sido chamado.

```
virtual void OnBeginPrinting(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo da impressora.

*Pinfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada. Substituir esta função para alocar quaisquer recursos GDI, como canetas ou fontes, necessários especificamente para impressão. Selecione os objetos GDI no contexto do dispositivo a partir da função [membro OnPrint](#onprint) para cada página que os use. Se você estiver usando o mesmo objeto de exibição para executar a exibição e a impressão da tela, use variáveis separadas para os recursos GDI necessários para cada exibição; isso permite que você atualize a tela durante a impressão.

Você também pode usar essa função para executar inicializações que dependem das propriedades do contexto do dispositivo da impressora. Por exemplo, o número de páginas necessárias para imprimir o documento pode depender das configurações especificadas pelo usuário na caixa de diálogo Imprimir (como comprimento da página). Em tal situação, você não pode especificar o comprimento do documento na função membro [OnPreparePrinting,](#onprepareprinting) onde você normalmente o faria; você deve esperar até que o contexto do dispositivo da impressora tenha sido criado com base nas configurações da caixa de diálogo. [OnBeginPrinting](#onbeginprinting) é a primeira função superridable que lhe dá acesso ao objeto [CDC](../../mfc/reference/cdc-class.md) que representa o contexto do dispositivo da impressora, para que você possa definir o comprimento do documento a partir desta função. Observe que se o comprimento do documento não for especificado por esse tempo, uma barra de rolagem não será exibida durante a visualização de impressão.

## <a name="cviewondragenter"></a><a name="ondragenter"></a>CView::OnDragEnter

Chamado pela estrutura quando o mouse entra pela primeira vez na região de não rolagem da janela de destino de queda.

```
virtual DROPEFFECT OnDragEnter(
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pdataobject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) sendo arrastado para a área de queda da exibição.

*Dwkeystate*<br/>
Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*Ponto*<br/>
A posição atual do mouse em relação à área cliente da exibição.

### <a name="return-value"></a>Valor retornado

Um valor do tipo enumerado DROPEFFECT, que indica o tipo de queda que ocorreria se o usuário soltasse o objeto nesta posição. O tipo de queda geralmente depende do estado-chave atual indicado por *dwKeyState*. Um mapeamento padrão de estados-chave para valores DROPEFFECT é:

- DROPEFFECT_NONEO objeto de dados não pode ser descartado nesta janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT Cria uma vinculação entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL Cria uma cópia do objeto descartado.

- DROPEFFECT_MOVE para MK_ALT Cria uma cópia do objeto descartado e exclui o objeto original. Este é tipicamente o efeito de queda padrão, quando a exibição pode aceitar esse objeto de dados.

Para obter mais informações, consulte a amostra [OCLIENT](../../overview/visual-cpp-samples.md)do MFC Advanced Concepts .

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar DROPEFFECT_NONE.

Anular essa função para se preparar para chamadas futuras para a função de membro [OnDragOver.](#ondragover) Todos os dados necessários do objeto de dados devem `OnDragOver` ser recuperados neste momento para uso posterior na função membro. A visão também deve ser atualizada neste momento para dar ao usuário feedback visual. Para obter mais informações, consulte o artigo [OLE arrastar e soltar: Implementar uma meta de queda](../../mfc/drag-and-drop-ole.md#implement-a-drop-target).

## <a name="cviewondragleave"></a><a name="ondragleave"></a>CView::OnDragLeave

Chamado pela estrutura durante uma operação de arrasto quando o mouse é movido para fora da área de queda válida para essa janela.

```
virtual void OnDragLeave();
```

### <a name="remarks"></a>Comentários

Anular essa função se a exibição atual precisar limpar quaisquer ações tomadas durante as chamadas [OnDragEnter](#ondragenter) ou [OnDragOver,](#ondragover) como remover qualquer feedback visual do usuário enquanto o objeto foi arrastado e descartado.

## <a name="cviewondragover"></a><a name="ondragover"></a>CView::OnDragover

Chamado pela estrutura durante uma operação de arrasto quando o mouse é movido sobre a janela de destino de queda.

```
virtual DROPEFFECT OnDragOver(
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pdataobject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) sendo arrastado sobre o alvo de queda.

*Dwkeystate*<br/>
Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*Ponto*<br/>
A posição atual do mouse em relação à área do cliente de exibição.

### <a name="return-value"></a>Valor retornado

Um valor do tipo enumerado DROPEFFECT, que indica o tipo de queda que ocorreria se o usuário soltasse o objeto nesta posição. O tipo de queda muitas vezes depende do estado-chave atual, conforme indicado por *dwKeyState*. Um mapeamento padrão de estados-chave para valores DROPEFFECT é:

- DROPEFFECT_NONEO objeto de dados não pode ser descartado nesta janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT Cria uma vinculação entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL Cria uma cópia do objeto descartado.

- DROPEFFECT_MOVE para MK_ALT Cria uma cópia do objeto descartado e exclui o objeto original. Este é tipicamente o efeito de queda padrão, quando a exibição pode aceitar o objeto de dados.

Para obter mais informações, consulte a amostra [OCLIENT](../../overview/visual-cpp-samples.md)do MFC Advanced Concepts .

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar DROPEFFECT_NONE.

Anular esta função para dar ao usuário feedback visual durante a operação de arrasto. Uma vez que esta função é chamada continuamente, qualquer código contido nela deve ser otimizado tanto quanto possível. Para obter mais informações, consulte o artigo [OLE arrastar e soltar: Implementar uma meta de queda](../../mfc/drag-and-drop-ole.md#implement-a-drop-target).

## <a name="cviewondragscroll"></a><a name="ondragscroll"></a>CView::OnDragScroll

Chamado pela estrutura antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o ponto está na região de rolagem.

```
virtual DROPEFFECT OnDragScroll(
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Dwkeystate*<br/>
Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*Ponto*<br/>
Contém a localização do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor retornado

Um valor do tipo enumerado DROPEFFECT, que indica o tipo de queda que ocorreria se o usuário soltasse o objeto nesta posição. O tipo de queda geralmente depende do estado-chave atual indicado por *dwKeyState*. Um mapeamento padrão de estados-chave para valores DROPEFFECT é:

- DROPEFFECT_NONEO objeto de dados não pode ser descartado nesta janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT Cria uma vinculação entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL Cria uma cópia do objeto descartado.

- DROPEFFECT_MOVE para MK_ALT Cria uma cópia do objeto descartado e exclui o objeto original.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo na exibição de destino.

Para obter mais informações, consulte a amostra [OCLIENT](../../overview/visual-cpp-samples.md)do MFC Advanced Concepts .

### <a name="remarks"></a>Comentários

Anular esta função quando você quiser fornecer um comportamento especial para este evento. A implementação padrão rola automaticamente janelas quando o cursor é arrastado para a região de rolagem padrão dentro da borda de cada janela. Para obter mais informações, consulte o artigo [OLE arrastar e soltar: Implementar uma meta de queda](../../mfc/drag-and-drop-ole.md#implement-a-drop-target).

## <a name="cviewondraw"></a><a name="ondraw"></a>CView::OnDraw

Chamado pela estrutura para renderizar uma imagem do documento.

```
virtual void OnDraw(CDC* pDC) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar uma imagem do documento.

### <a name="remarks"></a>Comentários

A estrutura chama essa função para executar a exibição de tela, impressão e visualização de impressão, e passa um contexto de dispositivo diferente em cada caso. Não há implementação padrão.

Você deve substituir esta função para exibir sua visão do documento. Você pode fazer chamadas de interface de dispositivo gráfico (GDI) usando o objeto [CDC](../../mfc/reference/cdc-class.md) apontado pelo parâmetro *pDC.* Você pode selecionar recursos GDI, como canetas ou fontes, no contexto do dispositivo antes de desenhar e, em seguida, desmarcá-los posteriormente. Muitas vezes seu código de desenho pode ser independente de dispositivos; ou seja, não requer informações sobre que tipo de dispositivo está exibindo a imagem.

Para otimizar o desenho, ligue para a função de membro [RectVisible](../../mfc/reference/cdc-class.md#rectvisible) do contexto do dispositivo para descobrir se um determinado retângulo será desenhado. Se você precisar distinguir entre exibição de tela normal e impressão, chame a função membro [IsPrinting](../../mfc/reference/cdc-class.md#isprinting) do contexto do dispositivo.

## <a name="cviewondrop"></a><a name="ondrop"></a>CView::OnDrop

Chamado pela estrutura quando o usuário libera um objeto de dados sobre um alvo de queda válido.

```
virtual BOOL OnDrop(
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

'pDataObject* aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que é lançado no alvo de queda.

*Dropeffect*<br/>
O efeito de queda que o usuário solicitou.

- DROPEFFECT_COPY Cria uma cópia do objeto de dados que está sendo descartado.

- DROPEFFECT_MOVE Move o objeto de dados para a localização atual do mouse.

- DROPEFFECT_LINK Cria um link entre um objeto de dados e seu servidor.

*Ponto*<br/>
A posição atual do mouse em relação à área do cliente de exibição.

### <a name="return-value"></a>Valor retornado

Não zero se a queda foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada e retorna FALSE.

Anular essa função para implementar o efeito de uma queda de OLE na área cliente da exibição. O objeto de dados pode ser examinado via *pDataObject* para formatos de dados da Área de Transferência e dados descartados no ponto especificado.

> [!NOTE]
> A estrutura não chama essa função se houver uma substituição do [OnDropEx](#ondropex) nesta classe de exibição.

## <a name="cviewondropex"></a><a name="ondropex"></a>CView::OnDropEx

Chamado pela estrutura quando o usuário libera um objeto de dados sobre um alvo de queda válido.

```
virtual DROPEFFECT OnDropEx(
    COleDataObject* pDataObject,
    DROPEFFECT dropDefault,
    DROPEFFECT dropList,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pdataobject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que é lançado no alvo de queda.

*Dropdefault*<br/>
O efeito que o usuário escolheu para a operação de queda padrão com base no estado-chave atual. Pode ser DROPEFFECT_NONE. Os efeitos de queda são discutidos na seção Observações.

*lista de gotas*<br/>
Uma lista dos efeitos de queda que a fonte de queda suporta. Os valores de efeito de queda podem ser combinados usando a operação bitwise OR **(&#124;). ** Os efeitos de queda são discutidos na seção Observações.

*Ponto*<br/>
A posição atual do mouse em relação à área do cliente de exibição.

### <a name="return-value"></a>Valor retornado

O efeito de queda resultante da tentativa de queda no local especificado por *ponto*. Este deve ser um dos valores indicados pelo *dropEffectList*. Os efeitos de queda são discutidos na seção Observações.

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e devolver um valor manequim ( -1 ) para indicar que o framework deve chamar o manipulador [do OnDrop.](#ondrop)

Anular esta função para implementar o efeito de um arrasto e queda do botão do mouse direito. O arrastar e soltar o botão direito do mouse normalmente exibe um menu de opções quando o botão direito do mouse é liberado.

Sua substituição `OnDropEx` de deve consultar o botão de mouse direito. Você pode ligar para [getkeystate](/windows/win32/api/winuser/nf-winuser-getkeystate) ou armazenar o estado certo do botão do mouse a partir do manipulador [OnDragEnter.](#ondragenter)

- Se o botão direito do mouse estiver desligado, sua substituição deve exibir um menu pop-up que oferece o suporte aos efeitos de gota pela fonte de gota.

  - Examine *a lista de gotas* para determinar os efeitos de queda suportados pela fonte de queda. Habilite apenas essas ações no menu pop-up.

  - Use [SetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-setmenudefaultitem) para definir a ação padrão com base em *dropDefault*.

  - Por fim, tome a ação indicada pela seleção do usuário a partir do menu popup.

- Se o botão do mouse direito não estiver desligado, sua substituição deve processá-lo como uma solicitação de queda padrão. Use o efeito de queda especificado no *dropDefault*. Alternativamente, sua substituição pode retornar o valor do manequim (-1) para indicar que `OnDrop` irá lidar com esta operação de queda.

Use *pDataObject* para `COleDataObject` examinar o formato de dados da Área de Transferência e os dados descartados no ponto especificado.

Os efeitos de gota descrevem a ação associada a uma operação de queda. Veja a lista a seguir de efeitos de queda:

- DROPEFFECT_NONE uma gota não seria permitida.

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo no alvo.

Para obter mais informações sobre a definição do comando de menu padrão, consulte [SetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-setmenudefaultitem) no SDK do Windows e [No Menu::GetSafeHmenu](../../mfc/reference/cmenu-class.md#getsafehmenu) neste volume.

## <a name="cviewonendprinting"></a><a name="onendprinting"></a>CView::OnEndPrinting

Chamado pelo framework depois que um documento foi impresso ou visualizado.

```
virtual void OnEndPrinting(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo da impressora.

*Pinfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada. Anular esta função para liberar quaisquer recursos GDI que você alocou na função de membro [OnBeginPrinting.](#onbeginprinting)

## <a name="cviewonendprintpreview"></a><a name="onendprintpreview"></a>CView::OnendPrintPreview

Chamado pela estrutura quando o usuário sai do modo de visualização de impressão.

```
virtual void OnEndPrintPreview(
    CDC* pDC,
    CPrintInfo* pInfo,
    POINT point,
    CPreviewView* pView);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo da impressora.

*Pinfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

*Ponto*<br/>
Especifica o ponto na página que foi exibido pela última vez no modo de visualização.

*pVer*<br/>
Aponta para o objeto de exibição usado para visualização.

### <a name="remarks"></a>Comentários

A implementação padrão desta função chama a função de membro [OnEndPrinting](#onendprinting) e restaura a janela do quadro principal para o estado em que estava antes da visualização de impressão começar. Substituir esta função para executar processamento especial quando o modo de visualização é encerrado. Por exemplo, se você quiser manter a posição do usuário no documento ao mudar do modo de visualização para o `m_nCurPage` modo `CPrintInfo` de exibição normal, você pode rolar para a posição descrita pelo parâmetro de *ponto* e o membro da estrutura que o parâmetro *pInfo* aponta.

Sempre chame a versão `OnEndPrintPreview` de classe base de sua substituição, normalmente no final da função.

## <a name="cviewoninitialupdate"></a><a name="oninitialupdate"></a>CView::OnInitialUpdate

Chamado pelo framework após a exibição é anexado primeiro ao documento, mas antes que a exibição seja exibida inicialmente.

```
virtual void OnInitialUpdate();
```

### <a name="remarks"></a>Comentários

A implementação padrão desta função chama a função de membro [OnUpdate](#onupdate) sem informações de dica (isto é, usando os valores padrão de 0 para o parâmetro *lHint* e NULL para o parâmetro *pHint).* Anular essa função para executar qualquer inicialização única que exija informações sobre o documento. Por exemplo, se o aplicativo tiver documentos de tamanho fixo, você pode usar essa função para inicializar os limites de rolagem de uma exibição com base no tamanho do documento. Se o aplicativo tiver suporte a documentos de tamanho variável, use [OnUpdate](#onupdate) para atualizar os limites de rolagem sempre que o documento for alterado.

## <a name="cviewonpreparedc"></a><a name="onpreparedc"></a>CView::OnPrepareDC

Chamado pela estrutura antes que a função de membro [OnDraw](#ondraw) seja chamada para exibição de tela e antes que a função do membro [OnPrint](#onprint) seja chamada para cada página durante a impressão ou visualização de impressão.

```
virtual void OnPrepareDC(
    CDC* pDC,
    CPrintInfo* pInfo = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar uma imagem do documento.

*Pinfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve `OnPrepareDC` o trabalho de impressão atual se estiver sendo chamado para impressão ou visualização de impressão; o `m_nCurPage` membro especifica a página prestes a ser impressa. Este parâmetro é `OnPrepareDC` NULO se estiver sendo chamado para exibição de tela.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada se a função for chamada para exibição de tela. No entanto, essa função é substituída em classes derivadas, como [CScrollView,](../../mfc/reference/cscrollview-class.md)para ajustar atributos do contexto do dispositivo; consequentemente, você deve sempre chamar a implementação da classe base no início de sua substituição.

Se a função for chamada para impressão, a implementação padrão examinará as informações da página armazenadas no parâmetro *pInfo.* Se o comprimento do documento não `OnPrepareDC` tiver sido especificado, assume que o documento tem uma página de duração e pára o loop de impressão depois que uma página foi impressa. A função interrompe o ciclo `m_bContinuePrinting` de impressão definindo o membro da estrutura como FALSO.

Anular `OnPrepareDC` por qualquer uma das seguintes razões:

- Para ajustar atributos do contexto do dispositivo conforme necessário para a página especificada. Por exemplo, se você precisar definir o modo de mapeamento ou outras características do contexto do dispositivo, faça-o nesta função.

- Para executar a paginação em tempo de impressão. Normalmente você especifica o comprimento do documento quando a impressão começa, usando a função [membro OnPreparePrinting.](#onprepareprinting) No entanto, se você não souber com antecedência quanto tempo o documento é (por exemplo, ao imprimir um número indeterminado de registros de um banco de dados), anular `OnPrepareDC` para testar o final do documento enquanto ele está sendo impresso. Quando não houver mais o documento a ser `m_bContinuePrinting` impresso, `CPrintInfo` defina o membro da estrutura como FALSO.

- Para enviar códigos de fuga para a impressora página por página. Para enviar códigos `OnPrepareDC`de `Escape` fuga de , ligue para a função membro do parâmetro *pDC.*

Ligue para a `OnPrepareDC` versão da classe base no início da sua substituição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#183](../../mfc/codesnippet/cpp/cview-class_1.cpp)]

## <a name="cviewonprepareprinting"></a><a name="onprepareprinting"></a>CView::OnPreparePrinting

Chamado pelo framework antes de um documento ser impresso ou visualizado.

```
virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*Pinfo*<br/>
Aponta para uma estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho de impressão atual.

### <a name="return-value"></a>Valor retornado

Não zero para começar a imprimir; 0 se o trabalho de impressão foi cancelado.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada.

Você deve substituir esta função para permitir a impressão e a visualização de impressão. Ligue para a função de membro [DoPreparePrinting,](#doprepareprinting) passando-a pelo parâmetro *pInfo* e, em seguida, retorne seu valor de retorno; `DoPreparePrinting` exibe a caixa de diálogo Imprimir e cria um contexto do dispositivo da impressora. Se você quiser inicializar a caixa de diálogo Imprimir com valores diferentes dos padrões, atribua valores aos membros do *pInfo*. Por exemplo, se você souber o comprimento do documento, passe o valor para `DoPreparePrinting`a função de membro [SetMaxPage](../../mfc/reference/cprintinfo-structure.md#setmaxpage) do *pInfo* antes de ligar . Este valor é exibido na caixa To: na parte 'Intervalo' da caixa de diálogo Imprimir.

`DoPreparePrinting`não exibe a caixa de diálogo Imprimir para um trabalho de visualização. Se você quiser ignorar a caixa de diálogo Imprimir `m_bPreview` para um trabalho de impressão, verifique se `DoPreparePrinting`o membro do *pInfo* é FALSE e, em seguida, defina-o como TRUE antes de passá-la para ; redefini-lo para FALSE depois.

Se você precisar executar inicializações que `CDC` requerem acesso ao objeto que representa o contexto do dispositivo da impressora (por exemplo, `OnBeginPrinting` se você precisar saber o tamanho da página antes de especificar o comprimento do documento), anular á função do membro.

Se você quiser definir o `m_nNumPreviewPages` `m_strPageDesc` valor dos ou membros do parâmetro *pInfo,* faça-o após a chamada `DoPreparePrinting`. A `DoPreparePrinting` função `m_nNumPreviewPages` do membro define o valor encontrado no aplicativo . Arquivo INI `m_strPageDesc` e define para o seu valor padrão.

### <a name="example"></a>Exemplo

  Anular `OnPreparePrinting` e `DoPreparePrinting` chamar a partir da substituição para que a estrutura exiba uma caixa de diálogo Imprimir e crie uma DC da impressora para você.

[!code-cpp[NVC_MFCDocView#184](../../mfc/codesnippet/cpp/cview-class_2.cpp)]

Se você souber quantas páginas o documento contém, defina a página máxima antes de `OnPreparePrinting` ligar `DoPreparePrinting`. O framework exibirá o número máximo da página na caixa "to" da caixa de diálogo Imprimir.

[!code-cpp[NVC_MFCDocView#185](../../mfc/codesnippet/cpp/cview-class_3.cpp)]

## <a name="cviewonprint"></a><a name="onprint"></a>CView::OnPrint

Chamado pelo framework para imprimir ou visualizar uma página do documento.

```
virtual void OnPrint(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo da impressora.

*Pinfo*<br/>
Aponta para `CPrintInfo` uma estrutura que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

Para cada página que está sendo impressa, o framework chama essa função imediatamente após chamar a função de membro [OnPrepareDC.](#onpreparedc) A página que está sendo `m_nCurPage` impressa é especificada pelo membro da estrutura [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que *o pInfo* aponta. A implementação padrão chama a função de membro [OnDraw](#ondraw) e passa-a pelo contexto do dispositivo da impressora.

Anular esta função por qualquer uma das seguintes razões:

- Para permitir a impressão de documentos de várias páginas. Renderize apenas a parte do documento que corresponde à página que está sendo impressa. Se você estiver `OnDraw` usando para executar a renderização, você pode ajustar a origem da porta de exibição para que apenas a parte apropriada do documento seja impressa.

- Para fazer a imagem impressa parecer diferente da imagem da tela (isto é, se sua aplicação não for WYSIWYG). Em vez de passar `OnDraw`o contexto do dispositivo da impressora para, use o contexto do dispositivo para renderizar uma imagem usando atributos não mostrados na tela.

   Se você precisar de recursos GDI para impressão que você não usa para exibição de tela, selecione-os no contexto do dispositivo antes de desenhar e desmarque-os posteriormente. Esses recursos GDI devem ser alocados no [OnBeginPrinting](#onbeginprinting) e liberados no [OnEndPrinting](#onendprinting).

- Para implementar cabeçalhos ou rodapés. Você ainda `OnDraw` pode usar para fazer a renderização restringindo a área em que ela pode imprimir.

Observe que `m_rectDraw` o membro do parâmetro *pInfo* descreve a área imprimível da página em unidades lógicas.

Não chame `OnPrepareDC` em sua `OnPrint`substituição de; o framework `OnPrepareDC` chama automaticamente `OnPrint`antes de chamar .

### <a name="example"></a>Exemplo

O seguinte é um esqueleto `OnPrint` para uma função substituída:

[!code-cpp[NVC_MFCDocView#186](../../mfc/codesnippet/cpp/cview-class_4.cpp)]

Para outro exemplo, consulte [CRichEditView::PrintInsideRect](../../mfc/reference/cricheditview-class.md#printinsiderect).

## <a name="cviewonscroll"></a><a name="onscroll"></a>CView::OnScroll

Chamado pela estrutura para determinar se a rolagem é possível.

```
virtual BOOL OnScroll(
    UINT nScrollCode,
    UINT nPos,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nScrollCode*<br/>
Um código de barra de rolagem que indica a solicitação de rolagem do usuário. Este parâmetro é composto de duas partes: um byte de baixa ordem, que determina o tipo de rolagem que ocorre horizontalmente, e um byte de alta ordem, que determina o tipo de rolagem que ocorre verticalmente:

- SB_BOTTOM Rola para baixo.

- SB_LINEDOWN rola uma linha para baixo.

- SB_LINEUP rola uma linha.

- SB_PAGEDOWN Rola uma página abaixo.

- SB_PAGEUP Rola uma página para cima.

- SB_THUMBTRACK Arraste a caixa de rolagem para a posição especificada. A posição atual é especificada em *nPos*.

- SB_TOP Rola até o topo.

*Npos*<br/>
Contém a posição atual da caixa de rolagem se o código de barra de rolagem estiver SB_THUMBTRACK; caso contrário, não é usado. Dependendo do intervalo inicial de rolagem, *os nPos* podem ser negativos e devem ser lançados para um **int,** se necessário.

*Bdoscroll*<br/>
Determina se você deve realmente fazer a ação de rolagem especificada. Se TRUE, então a rolagem deve ocorrer; se FALSE, então a rolagem não deve ocorrer.

### <a name="return-value"></a>Valor retornado

Se *bDoScroll* for TRUE e a exibição for realmente rolada, então retorne não zero; caso contrário, 0. Se *bDoScroll* for FALSE, então retorne o valor que você teria retornado se *bDoScroll* fosse VERDADEIRO, mesmo que você realmente não faça a rolagem.

### <a name="remarks"></a>Comentários

Em um caso, essa função é chamada pela estrutura com *bDoScroll* definido como TRUE quando a exibição recebe uma mensagem de barra de rolagem. Neste caso, você deve realmente rolar a exibição. No outro caso, esta função é chamada com *bDoScroll* definido como FALSE quando um item OLE é inicialmente arrastado para a região de rolagem automática de um alvo de queda antes que a rolagem realmente ocorra. Neste caso, você não deve realmente rolar a exibição.

## <a name="cviewonscrollby"></a><a name="onscrollby"></a>CView::OnScrollby

Chamado pela estrutura quando o usuário visualiza uma área além da visão atual do documento, seja arrastando um item OLE contra as bordas atuais da exibição ou manipulando as barras de rolagem verticais ou horizontais.

```
virtual BOOL OnScrollBy(
    CSize sizeScroll,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Sizescroll*<br/>
Número de pixels rolados horizontal e verticalmente.

*Bdoscroll*<br/>
Determina se a rolagem da exibição ocorre. Se TRUE, então a rolagem ocorre; se FALSE, então a rolagem não ocorre.

### <a name="return-value"></a>Valor retornado

Não zero se a exibição foi capaz de ser rolada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Nas classes derivadas, este método verifica se a exibição é rolável na direção solicitada pelo usuário e, em seguida, atualiza a nova região, se necessário. Esta função é automaticamente chamada por [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) para executar a solicitação de rolagem real.

A implementação padrão deste método não altera a exibição, mas se não `CScrollView`for chamada, a exibição não será rolada em uma classe derivada.

Se a largura ou altura do documento exceder 32767 pixels, a `OnScrollBy` rolagem após 32767 falhará porque é chamada com um argumento de tamanho inválido. *sizeScroll*

## <a name="cviewonupdate"></a><a name="onupdate"></a>CView::OnUpdate

Chamado pelo quadro após a modificação do documento da exibição; esta função é chamada por [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) e permite que a exibição atualize seu display para refletir essas modificações.

```
virtual void OnUpdate(
    CView* pSender,
    LPARAM lHint,
    CObject* pHint);
```

### <a name="parameters"></a>Parâmetros

*Psender*<br/>
Aponta para a visão que modificou o documento, ou NULL se todas as visualizações forem atualizadas.

*Lhint*<br/>
Contém informações sobre as modificações.

*Phint*<br/>
Aponta para um objeto que armazena informações sobre as modificações.

### <a name="remarks"></a>Comentários

Também é chamado pela implementação padrão do [OnInitialUpdate](#oninitialupdate). A implementação padrão invalida toda a área do cliente, marcando-a para pintura quando a próxima mensagem de WM_PAINT for recebida. Anular essa função se você quiser atualizar apenas as regiões que mapeiam as partes modificadas do documento. Para fazer isso, você deve passar informações sobre as modificações usando os parâmetros de dica.

Para usar *lHint,* defina valores especiais de dica, tipicamente uma máscara de bit ou um tipo enumerado, e que o documento passe um desses valores. Para usar *pHint,* obtenha uma classe de dicas do [CObject](../../mfc/reference/cobject-class.md) e tenha o documento passar um ponteiro para um objeto de dica; ao sobrepor, `OnUpdate`use a função [cObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) membro para determinar o tipo de tempo de execução do objeto de dica.

Normalmente, você não deve `OnUpdate`realizar nenhum desenho diretamente de . Em vez disso, determine o retângulo descrevendo, em coordenadas do dispositivo, a área que requer atualização; passar este retângulo para [CWnd::InvalidRect](../../mfc/reference/cwnd-class.md#invalidaterect). Isso faz com que a pintura ocorra na próxima vez que uma [mensagem de WM_PAINT](/windows/win32/gdi/wm-paint) for recebida.

Se *lHint* for 0 e *pHint* for NULL, o documento enviou uma notificação de atualização genérica. Se uma exibição receber uma notificação de atualização genérica ou se não puder decodificar as dicas, ela deve invalidar toda a sua área cliente.

## <a name="see-also"></a>Confira também

[MFC Amostra MDIDOCVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)
