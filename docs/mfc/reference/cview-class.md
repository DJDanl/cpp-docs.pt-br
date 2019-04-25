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
ms.openlocfilehash: 06c6d4dff28399f3d8e6ac7f46d9ed751850036f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62323327"
---
# <a name="cview-class"></a>Classe CView

Fornece a funcionalidade básica para classes de exibição definida pelo usuário.

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
|[CView::DoPreparePrinting](#doprepareprinting)|Exibe a caixa de diálogo Imprimir e cria o contexto de dispositivo de impressora; chamar ao substituir o `OnPreparePrinting` função de membro.|
|[CView::GetDocument](#getdocument)|Retorna o documento associado com o modo de exibição.|
|[CView::IsSelected](#isselected)|Testa se um item de documento é selecionado. Necessário para suporte ao OLE.|
|[CView::OnDragEnter](#ondragenter)|Chamado quando um item pela primeira vez é arrastado para a região de arrastar e soltar de um modo de exibição.|
|[CView::OnDragLeave](#ondragleave)|Chamado quando um item arrastado deixa a região de arrastar e soltar de um modo de exibição.|
|[CView::OnDragOver](#ondragover)|Chamado quando um item é arrastado sobre a região de arrastar e soltar de um modo de exibição.|
|[CView::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|
|[CView::OnDrop](#ondrop)|Chamado quando um item foi descartado para a área de arrastar e soltar de uma exibição, o manipulador padrão.|
|[CView::OnDropEx](#ondropex)|Chamado quando um item foi descartado para a área de arrastar e soltar de uma exibição, o manipulador primário.|
|[CView::OnInitialUpdate](#oninitialupdate)|Chamado depois que uma exibição é anexada primeiro a um documento.|
|[CView::OnPrepareDC](#onpreparedc)|Chamado antes do `OnDraw` função de membro é chamada para exibição na tela ou o `OnPrint` função membro é chamada para impressão ou visualização de impressão.|
|[CView::OnScroll](#onscroll)|Chamado quando os itens OLE são arrastados além das bordas do modo de exibição.|
|[CView::OnScrollBy](#onscrollby)|Chamado quando uma exibição que contém itens OLE do Active Directory no local é rolada.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CView::OnActivateFrame](#onactivateframe)|Chamado quando a janela do quadro que contém a exibição é ativada ou desativada.|
|[CView::OnActivateView](#onactivateview)|Chamado quando uma exibição é ativada.|
|[CView::OnBeginPrinting](#onbeginprinting)|Chamado quando um trabalho de impressão começa; Substitua para alocar recursos de interface (GDI) do dispositivo de gráficos.|
|[CView::OnDraw](#ondraw)|Chamado para processar uma imagem do documento para visualização de impressão, impressão ou exibição na tela. Implementação necessários.|
|[CView::OnEndPrinting](#onendprinting)|Chamado quando um trabalho de impressão termina; substituição de desalocar recursos GDI.|
|[CView::OnEndPrintPreview](#onendprintpreview)|Chamado quando o modo de visualização é encerrado.|
|[CView::OnPreparePrinting](#onprepareprinting)|Chamado antes que um documento é impresso ou visualizado; substituição para inicializar a caixa de diálogo Imprimir.|
|[CView::OnPrint](#onprint)|Chamado para imprimir ou visualizar uma página do documento.|
|[CView::OnUpdate](#onupdate)|Chamado para notificar um modo de exibição que seu documento foi modificado.|

## <a name="remarks"></a>Comentários

Um modo de exibição é anexado a um documento e atua como um intermediário entre o documento e o usuário: a exibição renderiza uma imagem do documento na tela ou impressora e interpreta a entrada do usuário como operações após o documento.

Uma exibição é um filho de uma janela do quadro. Mais de uma exibição pode compartilhar uma janela do quadro, como no caso de uma janela separadora. A relação entre uma classe de exibição, uma classe de janela de quadro e uma classe de documento é estabelecida por um `CDocTemplate` objeto. Quando o usuário abre uma nova janela ou divide um existente um, o framework constrói uma nova exibição e a anexa ao documento.

Um modo de exibição pode ser anexado a apenas um documento, mas um documento pode ter várias exibições anexadas a ele ao mesmo tempo — por exemplo, se o documento é exibido em uma janela separadora ou em várias janelas filho em um aplicativo de interface MDI vários documentos. Seu aplicativo pode dar suporte a diferentes tipos de modos de exibição para um tipo de documento fornecido; Por exemplo, um programa de processamento de texto pode fornecer uma exibição de texto completo de um documento e uma exibição de estrutura de tópicos que mostra apenas os títulos de seção. Esses diferentes tipos de modos de exibição podem ser colocados em janelas com moldura separado ou em painéis separados de uma janela de quadro único se você usar uma janela separadora.

Um modo de exibição pode ser responsável por manipular vários tipos diferentes de entrada, como a entrada do teclado, a entrada de mouse ou entrada via arrastar e soltar, bem como os comandos de menus, barras de ferramentas ou barras de rolagem. Um modo de exibição recebe comandos encaminhados por sua janela de quadro. Se o modo de exibição não manipular um determinado comando, ele encaminha o comando para o seu documento associado. Como todos os destinos de comando, uma exibição lida com mensagens por meio de um mapa de mensagem.

O modo de exibição é responsável para exibir e modificar os dados do documento, mas não para armazená-los. O documento fornece a exibição com os detalhes necessários sobre seus dados. Você pode permitir que o acesso de modo de exibição diretamente os membros de dados do documento, ou você pode fornecer funções de membro na classe de documento para a classe de exibição chamar.

Quando os dados de um documento for alterado, o modo de exibição responsável para que as alterações normalmente chama o [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) função para o documento, que notifica todos os outros modos de exibição chamando o `OnUpdate` a função de membro para cada. A implementação padrão de `OnUpdate` invalida a área de cliente inteira da exibição. Você pode substituí-la para invalidar somente essas regiões da área de cliente que são mapeados para as partes modificadas do documento.

Para usar `CView`, derive uma classe dele e implementar o `OnDraw` a função de membro para executar a exibição de tela. Você também pode usar `OnDraw` para executar a impressão e visualização de impressão. A estrutura manipula o loop de impressão para impressão e visualização do documento.

Um modo de exibição de mensagens da barra de rolagem com lida com o [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) funções de membro. Você pode implementar essas funções de tratamento de mensagem de barra de rolagem, ou você pode usar o `CView` classe derivada [CScrollView](../../mfc/reference/cscrollview-class.md) para lidar com rolagem para você.

Além disso `CScrollView`, a biblioteca Microsoft Foundation Class fornece nove outras classes derivadas de `CView`:

- [CCtrlView](../../mfc/reference/cctrlview-class.md), uma exibição que permite o uso de documento – exibição de controles de edição de arquitetura com árvore, lista e avançada.

- [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md), uma exibição que mostra registros de banco de dados em controles de caixa de diálogo.

- [CEditView](../../mfc/reference/ceditview-class.md), uma exibição que fornece um editor de texto de várias linhas simples. Você pode usar um `CEditView` objeto como um controle em uma caixa de diálogo, bem como uma exibição em um documento.

- [CFormView](../../mfc/reference/cformview-class.md), uma exibição rolável que contém os controles de caixa de diálogo e baseia-se em um recurso de modelo de caixa de diálogo.

- [CListView](../../mfc/reference/clistview-class.md), uma exibição que permite o uso do documento - arquitetura de exibição com controles de lista.

- [CRecordView](../../mfc/reference/crecordview-class.md), uma exibição que mostra registros de banco de dados em controles de caixa de diálogo.

- [CRichEditView](../../mfc/reference/cricheditview-class.md), uma exibição que permite o uso de documento – arquitetura com rica de controles de edição de exibição.

- [CScrollView](../../mfc/reference/cscrollview-class.md), uma exibição que fornece automaticamente o suporte a rolagem.

- [CTreeView](../../mfc/reference/ctreeview-class.md), uma exibição que permite o uso do documento - arquitetura de exibição com controles de árvore.

O `CView` classe também tem uma classe de implementação derivada chamada `CPreviewView`, que é usado pelo framework para executar a visualização de impressão. Essa classe fornece suporte para os recursos exclusivos para a janela de visualização de impressão, como uma barra de ferramentas, visualização de página única ou dupla e zoom, que é, aumentando a imagem visualizada. Você não precisa chamar ou substituir qualquer um dos `CPreviewView`de funções de membro, a menos que você deseja implementar sua própria interface para visualização de impressão (por exemplo, se você deseja dar suporte à edição no modo de visualização de impressão). Para obter mais informações sobre como usar `CView`, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [imprimindo](../../mfc/printing.md). Além disso, consulte [30 de observação técnica](../../mfc/tn030-customizing-printing-and-print-preview.md) para obter mais detalhes sobre como personalizar a visualização de impressão.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cview"></a>  CView::CView

Constrói um objeto `CView`.

```
CView();
```

### <a name="remarks"></a>Comentários

O framework chama o construtor quando uma nova janela do quadro é criada ou uma janela é dividida. Substituir a [OnInitialUpdate](#oninitialupdate) a função de membro para inicializar a exibição depois que o documento é anexado.

##  <a name="doprepareprinting"></a>  CView::DoPreparePrinting

Chame essa função de sua substituição de [OnPreparePrinting](#onprepareprinting) para invocar a caixa de diálogo de impressão e criar um contexto de dispositivo de impressora.

```
BOOL DoPreparePrinting(CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pInfo*<br/>
Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a impressão ou visualização de impressão poderá começar; 0 se a operação foi cancelada.

### <a name="remarks"></a>Comentários

Comportamento dessa função depende se ela está sendo chamada para visualização de impressão ou impressa (especificado pela `m_bPreview` membro do *pInfo* parâmetro). Se um arquivo está sendo impresso, essa função invoca a caixa de diálogo de impressão, usando os valores de [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que *pInfo* aponta para; depois que o usuário tenha fechado a caixa de diálogo, a função cria um contexto de dispositivo de impressora com base nas configurações do usuário especificado na caixa de diálogo e retorna esse contexto de dispositivo por meio de *pInfo* parâmetro. Esse contexto de dispositivo é usado para imprimir o documento.

Se um arquivo está sendo visualizado, essa função cria um contexto de dispositivo de impressora usando as configurações de impressora atuais; Esse contexto de dispositivo é usado para simular a impressora durante a visualização.

##  <a name="getdocument"></a>  CView::GetDocument

Chame essa função para obter um ponteiro para o documento da exibição.

```
CDocument* GetDocument() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [CDocument](../../mfc/reference/cdocument-class.md) objeto associado com o modo de exibição. NULL se o modo de exibição não está anexado a um documento.

### <a name="remarks"></a>Comentários

Isso permite que você chame funções de membro do documento.

##  <a name="isselected"></a>  CView::IsSelected

Chamado pelo framework para verificar se o item de documento especificado é selecionado.

```
virtual BOOL IsSelected(const CObject* pDocItem) const;
```

### <a name="parameters"></a>Parâmetros

*pDocItem*<br/>
Aponta para o item do documento que está sendo testado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o item do documento especificado está selecionado. Caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função retornará FALSE. Substituir essa função se você estiver implementando seleção usando [CDocItem](../../mfc/reference/cdocitem-class.md) objetos. Você deve substituir essa função se sua exibição contiver itens OLE.

##  <a name="onactivateframe"></a>  CView::OnActivateFrame

Chamado pelo framework quando a janela do quadro que contém a exibição é ativada ou desativada.

```
virtual void OnActivateFrame(
    UINT nState,
    CFrameWnd* pFrameWnd);
```

### <a name="parameters"></a>Parâmetros

*nState*<br/>
Especifica se a janela do quadro está sendo ativada ou desativada. Ele pode ser um dos seguintes valores:

- A janela do quadro WA_INACTIVE está sendo desativado.

- WA_ACTIVE a janela do quadro que está sendo ativada por meio de algum método diferente de um mouse clique (por exemplo, ao uso da interface do teclado para selecionar a janela).

- A janela do quadro WA_CLICKACTIVE está sendo ativado por um clique do mouse

*pFrameWnd*<br/>
Ponteiro para a janela do quadro que deve ser ativado.

### <a name="remarks"></a>Comentários

Substitua essa função membro, se você quiser executar o processamento especial quando a janela do quadro associada com o modo de exibição é ativada ou desativada. Por exemplo, [CFormView](../../mfc/reference/cformview-class.md) executa essa substituição, quando ele salva e restaura o controle que tem o foco.

##  <a name="onactivateview"></a>  CView::OnActivateView

Chamado pelo framework quando uma exibição é ativada ou desativada.

```
virtual void OnActivateView(
    BOOL bActivate,
    CView* pActivateView,
    CView* pDeactiveView);
```

### <a name="parameters"></a>Parâmetros

*bActivate*<br/>
Indica se o modo de exibição está sendo ativada ou desativada.

*pActivateView*<br/>
Aponta para o objeto de exibição que está sendo ativado.

*pDeactiveView*<br/>
Aponta para o objeto de exibição que está sendo desativada.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função define o foco para o modo de exibição que está sendo ativado. Substitua essa função se você quiser executar o processamento especial quando uma exibição é ativada ou desativada. Por exemplo, se você quiser fornecer dicas visuais especiais que distinguem o modo ativo das exibições inativas, você examinaria as *bActivate* parâmetro e atualize a aparência da exibição adequadamente.

O *pActivateView* e *pDeactiveView* parâmetros apontam para a mesma exibição se a janela do quadro principal do aplicativo é ativada sem nenhuma alteração no modo de exibição ativo — por exemplo, se o foco está sendo transferido de outro aplicativo a esse, em vez de uma exibição para outro dentro do aplicativo ou ao alternar entre janelas filho MDI. Isso permite que um modo de exibição perceber novamente sua paleta, se necessário.

Esses parâmetros são diferentes quando [CFrameWnd::SetActiveView](../../mfc/reference/cframewnd-class.md#setactiveview) for chamado com um modo de exibição que é diferente da qual [CFrameWnd::GetActiveView](../../mfc/reference/cframewnd-class.md#getactiveview) retornaria. Isso geralmente acontece com janelas separadoras.

##  <a name="onbeginprinting"></a>  CView::OnBeginPrinting

Chamado pelo framework no início de um trabalho de impressão ou visualização de impressão, após `OnPreparePrinting` foi chamado.

```
virtual void OnBeginPrinting(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo de impressora.

*pInfo*<br/>
Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para alocar qualquer GDI os recursos, como fontes, ou de canetas necessários especificamente para impressão. Selecione os objetos GDI no contexto de dispositivo de dentro de [OnPrint](#onprint) função de membro para cada página que os utiliza. Se você estiver usando o mesmo objeto de exibição para executar a exibição de tela e de impressão, use variáveis separadas para os recursos GDI necessários para cada exibição; Isso permite que você atualizar a tela durante a impressão.

Você também pode usar essa função para executar inicializações dependem das propriedades do contexto do dispositivo de impressora. Por exemplo, o número de páginas necessárias para imprimir o documento pode depender de configurações que o usuário especificado na caixa de diálogo de impressão (por exemplo, o tamanho da página). Nessa situação, você não pode especificar o tamanho do documento na [OnPreparePrinting](#onprepareprinting) função de membro, onde você normalmente faria isso; você deve aguardar até que o contexto de dispositivo de impressora foi criado com base nas configurações de caixa de diálogo. [OnBeginPrinting](#onbeginprinting) é a primeira função substituível que fornece acesso para o [CDC](../../mfc/reference/cdc-class.md) objeto que representa o contexto de dispositivo de impressora, você pode definir o tamanho do documento dessa função. Observe que, se o tamanho do documento não for especificado, dessa vez, uma barra de rolagem não é exibida durante a visualização de impressão.

##  <a name="ondragenter"></a>  CView::OnDragEnter

Chamado pelo framework quando o mouse entra pela primeira vez a região da janela de destino de soltar não rolam.

```
virtual DROPEFFECT OnDragEnter(
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que está sendo arrastado para a área de soltar do modo de exibição.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
A atual posição do mouse em relação à área de cliente do modo de exibição.

### <a name="return-value"></a>Valor de retorno

Um valor da DROPEFFECT enumerado tipo, que indica o tipo de soltar que ocorreria se o usuário descartado o objeto nesta posição. O tipo de destino geralmente depende do estado atual da chave indicado por *dwKeyState*. Um mapeamento padrão dos estados-chave para valores DROPEFFECT é:

- DROPEFFECT_NONE o objeto de dados não pode ser descartado nessa janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT cria um vínculo entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL cria uma cópia do objeto solto.

- DROPEFFECT_MOVE para MK_ALT cria uma cópia do objeto solto e excluir o objeto original. Isso normalmente é o efeito de soltar padrão, quando o modo de exibição pode aceitar esse objeto de dados.

Para obter mais informações, consulte o exemplo de conceitos avançados MFC [OCLIENT](../../overview/visual-cpp-samples.md).

### <a name="remarks"></a>Comentários

Implementação padrão é não fazer nada e retornar DROPEFFECT_NONE.

Substituir esta função para preparar para futuras chamadas para o [OnDragOver](#ondragover) função de membro. Todos os dados necessários do objeto de dados devem ser recuperados no momento para uso posterior no `OnDragOver` função de membro. O modo de exibição também deve ser atualizado no momento para fornecer o feedback visual do usuário. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).

##  <a name="ondragleave"></a>  CView::OnDragLeave

Chamado pelo framework durante uma operação de arrastar quando o mouse é movido para fora da área de soltar válido para essa janela.

```
virtual void OnDragLeave();
```

### <a name="remarks"></a>Comentários

Substituir essa função se precisa limpar quaisquer ações executadas durante o modo de exibição atual [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) chamadas, como remover qualquer feedback visual do usuário, enquanto o objeto foi arrastado e solto .

##  <a name="ondragover"></a>  CView::OnDragOver

Chamado pelo framework durante uma operação de arrastar quando o mouse é movido sobre a janela de destino de soltar.

```
virtual DROPEFFECT OnDragOver(
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que está sendo arrastado para o destino de soltar.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
A posição atual do mouse em relação à área de cliente de modo de exibição.

### <a name="return-value"></a>Valor de retorno

Um valor da DROPEFFECT enumerado tipo, que indica o tipo de soltar que ocorreria se o usuário descartado o objeto nesta posição. O tipo de destino geralmente depende do estado atual da chave conforme indicado pela *dwKeyState*. Um mapeamento padrão dos estados-chave para valores DROPEFFECT é:

- DROPEFFECT_NONE o objeto de dados não pode ser descartado nessa janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT cria um vínculo entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL cria uma cópia do objeto solto.

- DROPEFFECT_MOVE para MK_ALT cria uma cópia do objeto solto e excluir o objeto original. Isso normalmente é o efeito de soltar padrão, quando o modo de exibição pode aceitar o objeto de dados.

Para obter mais informações, consulte o exemplo de conceitos avançados MFC [OCLIENT](../../overview/visual-cpp-samples.md).

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar DROPEFFECT_NONE.

Substitua essa função para fornecer o feedback visual do usuário durante a operação de arrastar. Uma vez que essa função é chamada continuamente, qualquer código contido dentro dele deve ser otimizado tanto quanto possível. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).

##  <a name="ondragscroll"></a>  CView::OnDragScroll

Chamado pelo framework antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o ponto está na região de rolagem.

```
virtual DROPEFFECT OnDragScroll(
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

Um valor da DROPEFFECT enumerado tipo, que indica o tipo de soltar que ocorreria se o usuário descartado o objeto nesta posição. O tipo de destino geralmente depende do estado atual da chave indicado por *dwKeyState*. Um mapeamento padrão dos estados-chave para valores DROPEFFECT é:

- DROPEFFECT_NONE o objeto de dados não pode ser descartado nessa janela.

- DROPEFFECT_LINK para MK_CONTROL &#124; MK_SHIFT cria um vínculo entre o objeto e seu servidor.

- DROPEFFECT_COPY para MK_CONTROL cria uma cópia do objeto solto.

- DROPEFFECT_MOVE para MK_ALT cria uma cópia do objeto solto e excluir o objeto original.

- DROPEFFECT_SCROLL indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no modo de exibição de destino.

Para obter mais informações, consulte o exemplo de conceitos avançados MFC [OCLIENT](../../overview/visual-cpp-samples.md).

### <a name="remarks"></a>Comentários

Substitua essa função quando quiser fornecer um comportamento especial para esse evento. A implementação padrão rola automaticamente o windows quando o cursor é arrastado para a região de rolagem padrão dentro da borda de cada janela. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).

##  <a name="ondraw"></a>  CView::OnDraw

Chamado pelo framework para renderizar uma imagem do documento.

```
virtual void OnDraw(CDC* pDC) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo a ser usado para renderizar uma imagem do documento.

### <a name="remarks"></a>Comentários

O framework chama esta função para executar a exibição de tela, impressão e visualização de impressão, e ele passa um contexto de dispositivo diferentes em cada caso. Não há nenhuma implementação padrão.

Você deve substituir essa função para exibir sua visão do documento. Você pode fazer chamadas de interface (GDI) do dispositivo gráfico usando o [CDC](../../mfc/reference/cdc-class.md) objeto apontado pela *pDC* parâmetro. Você pode selecionar os recursos GDI, como canetas ou fontes, no contexto de dispositivo antes do desenho e, em seguida, desmarcá-los posteriormente. Muitas vezes seu código de desenho pode ser independentes de dispositivo; ou seja, ele não requer informações sobre qual tipo de dispositivo que está exibindo a imagem.

Para otimizar o desenho, chame o [RectVisible](../../mfc/reference/cdc-class.md#rectvisible) a função de membro do contexto do dispositivo para descobrir se um retângulo determinado será desenhado. Se você precisar distinguir entre a exibição de tela normal e impressão, chame o [IsPrinting](../../mfc/reference/cdc-class.md#isprinting) a função de membro do contexto do dispositivo.

##  <a name="ondrop"></a>  CView::OnDrop

Chamado pelo framework quando o usuário libera um objeto de dados em um destino válido.

```
virtual BOOL OnDrop(
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

' pDataObject * aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que for solto no destino de soltar.

*dropEffect*<br/>
O efeito que o usuário solicitou.

- DROPEFFECT_COPY cria uma cópia do objeto de dados que está sendo descartada.

- DROPEFFECT_MOVE move o objeto de dados para o local atual do mouse.

- DROPEFFECT_LINK cria um vínculo entre um objeto de dados e seu servidor.

*point*<br/>
A posição atual do mouse em relação à área de cliente de modo de exibição.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação de soltar foi bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada e retornará FALSE.

Substitua essa função para implementar o efeito de soltar um OLE para a área de cliente do modo de exibição. O objeto de dados pode ser examinado por meio *pDataObject* para dados de área de transferência formatos e dados descartados no ponto especificado.

> [!NOTE]
>  A estrutura não chama essa função se houver uma substituição para [OnDropEx](#ondropex) nessa classe de exibição.

##  <a name="ondropex"></a>  CView::OnDropEx

Chamado pelo framework quando o usuário libera um objeto de dados em um destino válido.

```
virtual DROPEFFECT OnDropEx(
    COleDataObject* pDataObject,
    DROPEFFECT dropDefault,
    DROPEFFECT dropList,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que for solto no destino de soltar.

*dropDefault*<br/>
O efeito que o usuário escolheu para a operação de soltar padrão com base no estado atual da chave. Pode ser DROPEFFECT_NONE. Efeitos de soltar são discutidos na seção comentários.

*dropList*<br/>
Uma lista dos efeitos de soltar que ofereça suporte a origem de soltar. Valores de efeito de soltar podem ser combinados usando o OR bit a bit ( **&#124;**) operação. Efeitos de soltar são discutidos na seção comentários.

*point*<br/>
A posição atual do mouse em relação à área de cliente de modo de exibição.

### <a name="return-value"></a>Valor de retorno

O efeito de soltar que resultaram na tentativa de descarte no local especificado por *aponte*. Isso deve ser um dos valores, indicados por *dropEffectList*. Efeitos de soltar são discutidos na seção comentários.

### <a name="remarks"></a>Comentários

A implementação padrão é não fazer nada e retornar um valor fictício (-1) para indicar que a estrutura deve chamar o [OnDrop](#ondrop) manipulador.

Substitua essa função para implementar o efeito de um arraste do botão direito do mouse e drop. Botão direito do mouse arrastar e soltar normalmente exibe um menu de opções quando o botão direito do mouse é liberado.

Sua substituição do `OnDropEx` deve consultar o botão direito do mouse. Você pode chamar [GetKeyState](/windows/desktop/api/winuser/nf-winuser-getkeystate) ou armazenar o estado do botão direito do mouse na sua [OnDragEnter](#ondragenter) manipulador.

- Se o botão direito do mouse estiver inativo, sua substituição deve exibir um menu pop-up que oferece que suportam aos efeitos de soltar, a origem de soltar.

   - Examine *lista suspensa* para determinar os efeitos de soltar compatíveis com a origem de soltar. Habilite apenas essas ações no menu pop-up.

   - Use [SetMenuDefaultItem](/windows/desktop/api/winuser/nf-winuser-setmenudefaultitem) para definir a ação padrão com base em *dropDefault*.

   - Por fim, execute a ação indicada pela seleção de usuário no menu pop-up.

- Se o botão direito do mouse não está inativo, sua substituição deve processar isso como uma solicitação de lista padrão. Use o efeito de soltar especificado na *dropDefault*. Como alternativa, sua substituição pode retornar o valor fictício (-1) para indicar que `OnDrop` tratará a operação de soltar.

Use *pDataObject* para examinar o `COleDataObject` para dados de área de transferência formato e dados descartados no ponto especificado.

Efeitos de soltar descrevem a ação associada a uma operação de soltar. Consulte a seguinte lista de efeitos de soltar:

- DROPEFFECT_NONE uma operação de soltar não teria permissão.

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

- DROPEFFECT_SCROLL indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.

Para obter mais informações sobre como configurar o comando de menu padrão, consulte [SetMenuDefaultItem](/windows/desktop/api/winuser/nf-winuser-setmenudefaultitem) no SDK do Windows e [CMenu::GetSafeHmenu](../../mfc/reference/cmenu-class.md#getsafehmenu) nesse volume.

##  <a name="onendprinting"></a>  CView::OnEndPrinting

Chamado pelo framework depois que um documento foi impresso ou visualizado.

```
virtual void OnEndPrinting(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo de impressora.

*pInfo*<br/>
Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substituir essa função para liberar quaisquer recursos GDI alocada na [OnBeginPrinting](#onbeginprinting) função de membro.

##  <a name="onendprintpreview"></a>  CView::OnEndPrintPreview

Chamado pelo framework quando o usuário sai do modo de visualização de impressão.

```
virtual void OnEndPrintPreview(
    CDC* pDC,
    CPrintInfo* pInfo,
    POINT point,
    CPreviewView* pView);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo de impressora.

*pInfo*<br/>
Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.

*point*<br/>
Especifica o ponto na página que foi exibida pela última vez no modo de visualização.

*pView*<br/>
Aponta para o objeto de exibição usado para visualização.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama o [OnEndPrinting](#onendprinting) função de membro e restaura a janela do quadro principal para o estado em que estava antes da visualização de impressão começou. Substitua esta função para executar um processamento especial quando o modo de visualização é encerrado. Por exemplo, se você quiser manter a posição do usuário no documento ao mudar do modo de visualização para modo de exibição normal, você pode rolar para a posição descrita pelo *aponte* parâmetro e o `m_nCurPage` membro o `CPrintInfo` estrutura que o *pInfo* parâmetro aponta.

Sempre chamar a versão da classe base do `OnEndPrintPreview` de sua substituição, normalmente no final da função.

##  <a name="oninitialupdate"></a>  CView::OnInitialUpdate

Chamado pelo framework depois que o modo de exibição é anexado pela primeira vez no documento, mas antes que o modo de exibição é exibido inicialmente.

```
virtual void OnInitialUpdate();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama o [OnUpdate](#onupdate) função de membro sem informações de dica (ou seja, usando os valores padrão de 0 para o *lHint* parâmetro e NULL para o  *pHint* parâmetro). Substitua esta função para executar qualquer inicialização única que exige informações sobre o documento. Por exemplo, se seu aplicativo tiver tamanho fixo de documentos, você pode usar essa função para inicializar os limites de rolagem do modo de exibição com base no tamanho do documento. Se seu aplicativo dá suporte a documentos de tamanho variável, use [OnUpdate](#onupdate) atualizar a rolagem limita sempre que as alterações de documento.

##  <a name="onpreparedc"></a>  CView::OnPrepareDC

Chamado pelo framework antes do [OnDraw](#ondraw) função de membro é chamada para exibição na tela e antes do [OnPrint](#onprint) função membro é chamada para cada página durante a visualização de impressão ou impressa.

```
virtual void OnPrepareDC(
    CDC* pDC,
    CPrintInfo* pInfo = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo a ser usado para renderizar uma imagem do documento.

*pInfo*<br/>
Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual se `OnPrepareDC` está sendo chamado para impressão ou visualização de impressão; a `m_nCurPage` membro Especifica a página prestes a ser impresso. Esse parâmetro é NULL se `OnPrepareDC` está sendo chamado para exibição na tela.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada se a função é chamada para exibição na tela. No entanto, essa função é substituída em classes derivadas, como [CScrollView](../../mfc/reference/cscrollview-class.md), para ajustar os atributos do contexto do dispositivo; Consequentemente, você sempre deve chamar a implementação da classe base no início de sua substituição.

Se a função é chamada para impressão, a implementação padrão examina as informações de página armazenadas em do *pInfo* parâmetro. Se o tamanho do documento não tiver sido especificado, `OnPrepareDC` pressupõe que o documento ao longo de uma página e interrompe o loop de impressão depois que uma página tiver sido impresso. A função para o loop de impressão, definindo o `m_bContinuePrinting` membro da estrutura como FALSE.

Substituir `OnPrepareDC` para qualquer um dos seguintes motivos:

- Para ajustar os atributos do contexto do dispositivo conforme necessário para a página especificada. Por exemplo, se você precisar definir o modo de mapeamento ou outras características do contexto do dispositivo, fazer isso nessa função.

- Para realizar a paginação de tempo de impressão. Normalmente você especificar o tamanho do documento quando começa a impressão, usando o [OnPreparePrinting](#onprepareprinting) função de membro. No entanto, se você não souber de antemão quanto o documento é (por exemplo, ao imprimir um número indeterminado de registros de um banco de dados), substituir `OnPrepareDC` para testar o final do documento enquanto ele está sendo impressa. Quando há não mais do documento a ser impresso, defina a `m_bContinuePrinting` membro o `CPrintInfo` estrutura como FALSE.

- Para enviar códigos de escape para a impressora em uma base de página por página. Para enviar códigos de escape de `OnPrepareDC`, chame o `Escape` função de membro da *pDC* parâmetro.

Chamar a versão da classe base do `OnPrepareDC` no início de sua substituição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#183](../../mfc/codesnippet/cpp/cview-class_1.cpp)]

##  <a name="onprepareprinting"></a>  CView::OnPreparePrinting

Chamado pelo framework antes de um documento é impresso ou visualizado.

```
virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pInfo*<br/>
Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.

### <a name="return-value"></a>Valor de retorno

Diferente de zero para iniciar a impressão; 0 se o trabalho de impressão foi cancelado.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada.

Você deve substituir essa função para habilitar a impressão e visualização de impressão. Chame o [DoPreparePrinting](#doprepareprinting) função de membro, passando-os *pInfo* parâmetro e, em seguida, retornar seu valor de retorno; `DoPreparePrinting` exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo de impressora. Se você deseja inicializar a caixa de diálogo de impressão com valores diferentes dos padrões, atribuir valores aos membros da *pInfo*. Por exemplo, se você souber o tamanho do documento, passar o valor para o [SetMaxPage](../../mfc/reference/cprintinfo-structure.md#setmaxpage) função de membro *pInfo* antes de chamar `DoPreparePrinting`. Esse valor é exibido no campo para: caixa na parte do intervalo da caixa de diálogo Imprimir.

`DoPreparePrinting` não exibe a caixa de diálogo de impressão para um trabalho de visualização. Se você quiser ignorar a caixa de diálogo de impressão para um trabalho de impressão, verifique se o `m_bPreview` membro *pInfo* for FALSE e, em seguida, defini-lo como verdadeiro antes de passá-lo para `DoPreparePrinting`; redefini-lo posteriormente como FALSE.

Se precisar executar inicializações que exigem acesso para o `CDC` substituir do objeto que representa o contexto de dispositivo de impressora (por exemplo, se você precisa saber o tamanho da página antes de especificar o tamanho do documento), o `OnBeginPrinting` membro função.

Se você quiser definir o valor da `m_nNumPreviewPages` ou `m_strPageDesc` os membros a *pInfo* parâmetro, fazê-lo depois de chamar `DoPreparePrinting`. O `DoPreparePrinting` conjuntos de funções de membro `m_nNumPreviewPages` para o valor encontrado na caixa de diálogo. Arquivo INI e define `m_strPageDesc` para seu valor padrão.

### <a name="example"></a>Exemplo

  Substituir `OnPreparePrinting` e chamar `DoPreparePrinting` de substituição para que o framework exibirá uma caixa de diálogo de impressão e criar uma controlador de domínio de impressora para você.

[!code-cpp[NVC_MFCDocView#184](../../mfc/codesnippet/cpp/cview-class_2.cpp)]

Se você souber o número de páginas contém o documento, defina o máximo da página `OnPreparePrinting` antes de chamar `DoPreparePrinting`. O framework exibirá o número máximo de página na caixa "para" da caixa de diálogo Imprimir.

[!code-cpp[NVC_MFCDocView#185](../../mfc/codesnippet/cpp/cview-class_3.cpp)]

##  <a name="onprint"></a>  CView::OnPrint

Chamado pelo framework para imprimir ou visualizar uma página do documento.

```
virtual void OnPrint(
    CDC* pDC,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo de impressora.

*pInfo*<br/>
Aponta para um `CPrintInfo` estrutura que descreve o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

Para cada página que está sendo impressa, o framework chama esta função imediatamente após a chamada a [OnPrepareDC](#onpreparedc) função de membro. A página que está sendo impressa é especificada pelo `m_nCurPage` membro a [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que *pInfo* aponta para. A implementação padrão chama o [OnDraw](#ondraw) função de membro e passa o contexto de dispositivo de impressora.

Substitua essa função para qualquer um dos seguintes motivos:

- Para permitir a impressão de documentos de várias páginas. Renderizar apenas a parte do documento que corresponde à página que está sendo impressa. Se você estiver usando `OnDraw` para executar a renderização, você pode ajustar a origem do visor para que somente a parte apropriada do documento é impresso.

- Para fazer com que a imagem impressa uma aparência diferente da imagem da tela (ou seja, se seu aplicativo não seja WYSIWYG). Em vez de passar a impressora contexto de dispositivo `OnDraw`, use o contexto de dispositivo para renderizar uma imagem usando os atributos não são mostrados na tela.

   Se você precisar de recursos GDI para impressão que não são usadas para exibição na tela, selecione-as no contexto de dispositivo antes do desenho e desmarcá-los posteriormente. Esses recursos GDI devem ser alocados no [OnBeginPrinting](#onbeginprinting) e lançado em [OnEndPrinting](#onendprinting).

- Para implementar cabeçalhos ou rodapés de páginas. Você ainda pode usar `OnDraw` para fazer o processamento, restringindo a área de impressão nos.

Observe que o `m_rectDraw` membro a *pInfo* parâmetro descreve a área imprimível da página em unidades lógicas.

Não chame `OnPrepareDC` em seu substituto do `OnPrint`; a estrutura chama `OnPrepareDC` automaticamente antes de chamar `OnPrint`.

### <a name="example"></a>Exemplo

A seguir está um esqueleto para um substituído `OnPrint` função:

[!code-cpp[NVC_MFCDocView#186](../../mfc/codesnippet/cpp/cview-class_4.cpp)]

Para obter outro exemplo, consulte [CRichEditView::PrintInsideRect](../../mfc/reference/cricheditview-class.md#printinsiderect).

##  <a name="onscroll"></a>  CView::OnScroll

Chamado pelo framework para determinar se a rolagem é possível.

```
virtual BOOL OnScroll(
    UINT nScrollCode,
    UINT nPos,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nScrollCode*<br/>
Um código de barras de rolagem que indica que o usuário da solicitação de rolagem. Esse parâmetro é composto de duas partes: um byte de ordem inferior, que determina o tipo de rolagem horizontal ocorrendo, e um byte de ordem superior, que determina o tipo de rolagem vertical ocorrendo:

- SB_BOTTOM rola para baixo.

- Uma linha para baixo SB_LINEDOWN rola.

- Uma linha para cima SB_LINEUP rola.

- Uma página para baixo SB_PAGEDOWN rola.

- Uma página para cima SB_PAGEUP rola.

- SB_THUMBTRACK Arrastos Role a caixa para a posição especificada. A posição atual é especificada na *nPos*.

- SB_TOP rola para cima.

*nPos*<br/>
Contém a posição atual da caixa de rolagem, se o código de barras de rolagem é SB_THUMBTRACK; Caso contrário, ele não é usado. Dependendo do período inicial de rolagem, *nPos* pode ser negativo e deve ser convertido em um **int** se necessário.

*bDoScroll*<br/>
Determina se você deve fazer, na verdade, a ação de rolagem especificada. Se for TRUE, então rolando deve ocorrer; Se for FALSE, a rolagem, em seguida, não deve ocorrer.

### <a name="return-value"></a>Valor de retorno

Se *bDoScroll* for verdadeiro e o modo de exibição, na verdade, foi rolado, em seguida, retornar diferente de zero; caso contrário, 0. Se *bDoScroll* é FALSE, em seguida, retorna o valor que você poderia ter retornado se *bDoScroll* fosse verdadeira, mesmo que você realmente não fazer a rolagem.

### <a name="remarks"></a>Comentários

Em um caso essa função é chamada pelo framework com *bDoScroll* definido como TRUE quando o modo de exibição recebe uma mensagem de barra de rolagem. Nesse caso, você deve rolar, na verdade, o modo de exibição. No caso de essa função é chamada com *bDoScroll* definido como FALSE quando um item OLE inicialmente é arrastado para a região de rolagem automática de um destino de soltar antes de rolagem realmente ocorre. Nesse caso, você deve realmente rola a exibição.

##  <a name="onscrollby"></a>  CView::OnScrollBy

Chamado pelo framework quando o usuário exibe uma área além do presente exibição do documento, arrastando um item OLE em bordas de atual da exibição ou manipulando as barras de rolagem verticais ou horizontais.

```
virtual BOOL OnScrollBy(
    CSize sizeScroll,
    BOOL bDoScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*sizeScroll*<br/>
Número de pixels rolada horizontalmente e verticalmente.

*bDoScroll*<br/>
Determina se a rolagem da exibição ocorrerá. Se for TRUE, então rolando ocorre; Se for FALSE, em seguida, a rolagem não ocorrerá.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o modo de exibição foi capaz de ser rolado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Em classes derivadas esse método verifica se a exibição é rolável na direção em que o usuário solicitado e, em seguida, atualiza a nova região, se necessário. Essa função é chamada automaticamente pelo [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) para executar a solicitação real de rolagem.

A implementação padrão desse método não altera o modo de exibição, mas se não for chamado, o modo de exibição não rolará em um `CScrollView`-classe derivada.

Se a largura do documento ou altura excede 32767 pixels, passar 32767 falhará porque `OnScrollBy` é chamado com um inválido *sizeScroll* argumento.

##  <a name="onupdate"></a>  CView::OnUpdate

Chamado pelo framework depois que o documento do modo de exibição tiver sido modificado; Essa função é chamada [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) e permite que o modo de exibição atualizar sua exibição para refletir essas modificações.

```
virtual void OnUpdate(
    CView* pSender,
    LPARAM lHint,
    CObject* pHint);
```

### <a name="parameters"></a>Parâmetros

*pSender*<br/>
Aponta para o modo de exibição que modificou o documento, ou nulo se todas as exibições serão atualizados.

*lHint*<br/>
Contém informações sobre as modificações.

*pHint*<br/>
Aponta para um objeto que armazena informações sobre as modificações.

### <a name="remarks"></a>Comentários

Ele também é chamado pela implementação do padrão de [OnInitialUpdate](#oninitialupdate). A implementação padrão invalida a área de cliente inteira, marcá-lo para pintura quando a próxima mensagem WM_PAINT é recebida. Substitua essa função se você deseja atualizar somente essas regiões que são mapeados para as partes modificadas do documento. Para fazer isso, você deve passar informações sobre as modificações usando os parâmetros de dica.

Para usar *lHint*, definir valores de Dica especial, normalmente uma máscara de bits ou um tipo enumerado e tem o documento a passar um destes valores. Para usar *pHint*, derive uma classe de dica de [CObject](../../mfc/reference/cobject-class.md) e fazer com que o documento passar um ponteiro para um objeto de dica; ao substituir `OnUpdate`, use o [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) função de membro para determinar o tipo de tempo de execução do objeto de dica.

Normalmente você não deve realizar qualquer desenhando diretamente do `OnUpdate`. Em vez disso, determinar o retângulo que descreve, em coordenadas de dispositivo, a área que requer a atualização. passe esse rectangle [CWnd::InvalidateRect](../../mfc/reference/cwnd-class.md#invalidaterect). Isso faz com que a pintura ocorra na próxima vez que um [WM_PAINT](/windows/desktop/gdi/wm-paint) mensagem é recebida.

Se *lHint* é 0 e *pHint* for NULL, o documento enviou uma notificação de atualização genérica. Se um modo de exibição recebe uma notificação de atualização genérica, ou se ele não consegue decodificar as dicas, ele deve invalidar sua área de cliente inteira.

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDIDOCVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)
