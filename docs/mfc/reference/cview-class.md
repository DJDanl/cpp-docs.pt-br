---
title: Classe CView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- views [C++], view classes
- multiple views
- CView class
- document/view architecture
- input, and view class
- MDI [C++], view windows
- print preview, view windows
- windows [C++], views
- child windows, views
- frame windows [C++], views
- user input [C++], interpreting through view class
ms.assetid: 9cff3c56-7564-416b-b9a4-71a9254ed755
caps.latest.revision: 25
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: ce5100a9ee4a1c20df04f79f0c8cd645ae3afce7
ms.lasthandoff: 02/25/2017

---
# <a name="cview-class"></a>Classe CView
Fornece a funcionalidade básica para as classes de exibição definida pelo usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CView : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CView::CView](#cview)|Constrói um objeto `CView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CView::DoPreparePrinting](#doprepareprinting)|Exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo de impressora; chamar ao substituir o `OnPreparePrinting` função de membro.|  
|[CView::GetDocument](#getdocument)|Retorna o documento associado com o modo de exibição.|  
|[CView::IsSelected](#isselected)|Testa se um item de documento é selecionado. Necessário para suporte OLE.|  
|[CView::OnDragEnter](#ondragenter)|Chamado quando um item é arrastado primeiro para a área de arrastar e soltar de uma exibição.|  
|[CView::OnDragLeave](#ondragleave)|Chamado quando um item arrastado deixa a região de arrastar e soltar de uma exibição.|  
|[CView::OnDragOver](#ondragover)|Chamado quando um item é arrastado para a região de arrastar e soltar de uma exibição.|  
|[CView::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|  
|[CView::OnDrop](#ondrop)|Chamado quando um item foi descartado para a área de arrastar e soltar de uma exibição, o manipulador padrão.|  
|[CView::OnDropEx](#ondropex)|Chamado quando um item foi descartado para a área de arrastar e soltar de uma exibição, o manipulador primário.|  
|[Cview:: Oninitialupdate](#oninitialupdate)|Chamado depois que uma exibição primeiro é anexada a um documento.|  
|[CView::OnPrepareDC](#onpreparedc)|Chamado antes do `OnDraw` função de membro é chamada para exibição na tela ou `OnPrint` função de membro é chamada para impressão ou visualização de impressão.|  
|[CView::OnScroll](#onscroll)|Chamado quando os itens OLE são arrastados além das bordas do modo de exibição.|  
|[CView::OnScrollBy](#onscrollby)|Chamado quando uma exibição que contém itens OLE ativos no local é rolada.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CView::OnActivateFrame](#onactivateframe)|Chamado quando a janela do quadro que contém a exibição é ativada ou desativada.|  
|[CView::OnActivateView](#onactivateview)|Chamado quando uma exibição é ativada.|  
|[CView::OnBeginPrinting](#onbeginprinting)|Chamado quando um trabalho de impressão começa; Substitua para alocar recursos GDI (interface) do dispositivo de gráficos.|  
|[CView::OnDraw](#ondraw)|Chamado para processar uma imagem do documento para visualização de impressão, impressão ou exibição na tela. Implementação necessários.|  
|[CView::OnEndPrinting](#onendprinting)|Chamado quando um trabalho de impressão termina; substituição é para desalocar os recursos GDI.|  
|[CView::OnEndPrintPreview](#onendprintpreview)|Chamado quando o modo de visualização.|  
|[CView::OnPreparePrinting](#onprepareprinting)|Chamado antes que um documento é impresso ou visualizado; Substitua para inicializar a caixa de diálogo Imprimir.|  
|[CView::OnPrint](#onprint)|Chamado para imprimir ou visualizar uma página do documento.|  
|[CView::OnUpdate](#onupdate)|Chamado para notificar um modo de exibição que o documento foi modificado.|  
  
## <a name="remarks"></a>Comentários  
 Um modo de exibição é anexado a um documento e atua como um intermediário entre o documento e o usuário: a exibição renderiza uma imagem do documento na tela ou impressora e interpreta a entrada do usuário como operações ao documento.  
  
 Um modo de exibição é um filho de uma janela de quadro. Mais de uma exibição pode compartilhar uma janela de quadro, como no caso de uma janela separadora. A relação entre uma classe de exibição, uma classe de janela de quadro e uma classe de documento é estabelecida por um `CDocTemplate` objeto. Quando o usuário abre uma nova janela ou divide um existente um, o framework cria uma nova exibição e anexa ao documento.  
  
 Um modo de exibição pode ser anexado a um documento, mas um documento pode ter várias exibições anexadas ao mesmo tempo — por exemplo, se o documento é exibido em uma janela separadora ou em várias janelas filho em um aplicativo de interface MDI vários documentos. Seu aplicativo pode dar suporte a diferentes tipos de modos de exibição para um determinado tipo de documento; Por exemplo, um programa de processamento de texto pode fornecer um modo de exibição de texto completo de um documento e uma exibição de estrutura de tópicos que mostra os títulos de seção. Esses diferentes tipos de modos de exibição podem ser colocados em janelas de quadro separado ou em painéis separados de uma janela de quadro único se você usar uma janela separadora.  
  
 Uma exibição pode ser responsável por gerenciar vários tipos diferentes de entrada, como entrada de teclado, entrada de mouse ou entrada via arrastar-e-soltar, bem como os comandos de menus, barras de ferramentas ou barras de rolagem. Um modo de exibição recebe comandos encaminhados por sua janela de quadro. Se o modo de exibição não manipular um determinado comando, ele encaminha o comando para o documento associado. Como todos os destinos de comando, uma exibição manipula mensagens por meio de um mapa de mensagem.  
  
 A exibição é responsável para exibir e modificar os dados do documento, mas não para armazená-lo. O documento fornece a exibição com os detalhes necessários sobre seus dados. Você pode permitir que o acesso de modo de exibição diretamente membros de dados do documento, ou você pode fornecer funções de membro na classe de documento para a classe de modo a chamada.  
  
 Quando os dados do documento é alterado, o responsável para que as alterações de modo de exibição normalmente chama o [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) função para o documento, que notifica de todas as outras exibições chamando o `OnUpdate` a função de membro para cada. A implementação padrão de `OnUpdate` invalida toda área do cliente da exibição. Você pode substituí-la para invalidar apenas essas regiões da área do cliente que são mapeados para as partes de modificação do documento.  
  
 Usar `CView`, derive uma classe dele e implementar o `OnDraw` a função de membro para executar a exibição da tela. Você também pode usar `OnDraw` para executar a impressão e visualização de impressão. A estrutura lida com o loop de impressão para impressão e visualização do documento.  
  
 Um modo de exibição manipula mensagens da barra de rolagem com o [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) funções de membro. Você pode implementar o tratamento nessas funções de mensagens da barra de rolagem, ou você pode usar o `CView` classe derivada [CScrollView](../../mfc/reference/cscrollview-class.md) para tratar a rolagem para você.  
  
 Além dos `CScrollView`, a biblioteca Microsoft Foundation Class fornece nove outras classes derivadas de `CView`:  
  
- [CCtrlView](../../mfc/reference/cctrlview-class.md), um modo de exibição que permite o uso de documentos - exibir controles de edição de arquitetura com árvore, lista e avançada.  
  
- [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md), um modo de exibição que exibe registros de banco de dados em controles de caixa de diálogo.  
  
- [CEditView](../../mfc/reference/ceditview-class.md), um modo de exibição que fornece um editor de texto simples de várias linhas. Você pode usar uma `CEditView` objeto como um controle em uma caixa de diálogo, bem como uma exibição em um documento.  
  
- [CFormView](../../mfc/reference/cformview-class.md), uma exibição rolável que contém controles de caixa de diálogo e baseia-se em um recurso de modelo de caixa de diálogo.  
  
- [CListView](../../mfc/reference/clistview-class.md), um modo de exibição que permite o uso de documentos - arquitetura de exibição com controles de lista.  
  
- [CRecordView](../../mfc/reference/crecordview-class.md), um modo de exibição que exibe registros de banco de dados em controles de caixa de diálogo.  
  
- [CRichEditView](../../mfc/reference/cricheditview-class.md), um modo de exibição que permite o uso de documentos - exibir controles de edição de arquitetura com avançada.  
  
- [CScrollView](../../mfc/reference/cscrollview-class.md), um modo de exibição que fornece suporte a rolagem automaticamente.  
  
- [CTreeView](../../mfc/reference/ctreeview-class.md), um modo de exibição que permite o uso de documentos - arquitetura de exibição com controles de árvore.  
  
 O `CView` classe também tem uma classe de implementação derivada chamada **CPreviewView**, que é usado pelo framework para executar a visualização de impressão. Esta classe oferece suporte para os recursos exclusivos para a janela de visualização de impressão, como uma barra de ferramentas, visualização de página única ou dupla e zoom, que é, aumentando a imagem visualizada. Você não precisa chamar ou substituir qualquer **CPreviewView**de funções de membro, a menos que você queira implementar sua própria interface de visualização de impressão (por exemplo, se desejar oferecer suporte à edição no modo de visualização de impressão). Para obter mais informações sobre como usar o `CView`, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [impressão](../../mfc/printing.md). Além disso, consulte [técnico 30 Observação](../../mfc/tn030-customizing-printing-and-print-preview.md) para obter mais detalhes sobre como personalizar a visualização de impressão.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cview"></a>CView::CView  
 Constrói um objeto `CView`.  
  
```  
CView();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama o construtor quando é criada uma nova janela de quadro ou uma janela é dividida. Substituir o [OnInitialUpdate](#oninitialupdate) a função de membro para inicializar a exibição depois que o documento é anexado.  
  
##  <a name="doprepareprinting"></a>CView::DoPreparePrinting  
 Chame essa função de sua substituição do [OnPreparePrinting](#onprepareprinting) para invocar a caixa de diálogo de impressão e criar um contexto de dispositivo da impressora.  
  
```  
BOOL DoPreparePrinting(CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se pode começar a impressão ou visualização de impressão; 0 se a operação foi cancelada.  
  
### <a name="remarks"></a>Comentários  
 Comportamento da função depende se ele está sendo chamado para impressão ou visualização de impressão (especificado pelo **m_bPreview** membro o `pInfo` parâmetro). Se um arquivo for impresso, essa função invoca a caixa de diálogo de impressão, usando os valores no [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura `pInfo` pontos; depois que o usuário fechou a caixa de diálogo, a função cria um contexto de dispositivo de impressão com base nas configurações do usuário especificado na caixa de diálogo e retorna esse contexto de dispositivo por meio de `pInfo` parâmetro. Esse contexto de dispositivo é usado para imprimir o documento.  
  
 Se um arquivo está sendo visualizado, essa função cria um contexto de dispositivo de impressão usando as configurações de impressora atuais; Esse contexto de dispositivo é usado para simular a impressora durante a visualização.  
  
##  <a name="getdocument"></a>CView::GetDocument  
 Chame essa função para obter um ponteiro para o documento da exibição.  
  
```  
CDocument* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CDocument](../../mfc/reference/cdocument-class.md) objeto associado com o modo de exibição. **NULO** se o modo de exibição não está anexado a um documento.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que você chame funções de membro do documento.  
  
##  <a name="isselected"></a>CView::IsSelected  
 Chamado pela estrutura para verificar se o item de documento especificado é selecionado.  
  
```  
virtual BOOL IsSelected(const CObject* pDocItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDocItem`  
 Aponta para o item de documento que está sendo testado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item de documento especificado está selecionado. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Retorna a implementação padrão dessa função **FALSE**. Substituir essa função se você estiver implementando seleção usando [CDocItem](../../mfc/reference/cdocitem-class.md) objetos. Você deve substituir essa função se sua exibição contiver itens OLE.  
  
##  <a name="onactivateframe"></a>CView::OnActivateFrame  
 Chamado pela estrutura quando a janela do quadro que contém a exibição é ativada ou desativada.  
  
```  
virtual void OnActivateFrame(
    UINT nState,  
    CFrameWnd* pFrameWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nState`  
 Especifica se a janela do quadro está sendo ativada ou desativada. Ele pode ser um dos seguintes valores:  
  
- **WA_INACTIVE** a janela do quadro está sendo desativada.  
  
- **WA_ACTIVE** a janela do quadro está sendo ativada através de algum método diferente de um clique do mouse (por exemplo, pelo uso da interface do teclado para selecionar a janela).  
  
- **WA_CLICKACTIVE** a janela do quadro que está sendo ativada por um clique do mouse  
  
 `pFrameWnd`  
 Ponteiro para a janela do quadro que deve ser ativado.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função de membro para executar um processamento especial quando a janela do quadro associada com o modo de exibição é ativada ou desativada. Por exemplo, [CFormView](../../mfc/reference/cformview-class.md) executa essa substituição quando salva e restaura o controle que tem o foco.  
  
##  <a name="onactivateview"></a>CView::OnActivateView  
 Chamado pela estrutura quando uma exibição é ativada ou desativada.  
  
```  
virtual void OnActivateView(
    BOOL bActivate,  
    CView* pActivateView,  
    CView* pDeactiveView);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bActivate`  
 Indica se o modo de exibição está sendo ativada ou desativada.  
  
 `pActivateView`  
 Aponta para o objeto de exibição que está sendo ativado.  
  
 `pDeactiveView`  
 Aponta para o objeto de exibição que está sendo desativada.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função define o foco para o modo de exibição que está sendo ativado. Substitua essa função se você quiser executar um processamento especial quando uma exibição é ativada ou desativada. Por exemplo, se você quiser fornecer dicas visuais especial que distinguem o modo ativo os modos de exibição inativos, você examinaria o `bActivate` parâmetro e atualize a aparência do modo de exibição adequadamente.  
  
 O `pActivateView` e `pDeactiveView` parâmetros apontam para a mesma exibição se a janela do quadro principal do aplicativo é ativada sem alterações no modo ativo — por exemplo, se o foco estiver sendo transferido do outro aplicativo a esse, em vez de uma exibição para outra dentro do aplicativo ou ao alternar entre janelas filho MDI. Isso permite que um modo de exibição novamente perceber a paleta, se necessário.  
  
 Esses parâmetros são diferentes quando [CFrameWnd::SetActiveView](../../mfc/reference/cframewnd-class.md#setactiveview) é chamado com um modo de exibição diferente do que [CFrameWnd::GetActiveView](../../mfc/reference/cframewnd-class.md#getactiveview) retornaria. Isso geralmente acontece com janelas separadoras.  
  
##  <a name="onbeginprinting"></a>CView::OnBeginPrinting  
 Chamado pela estrutura no início de um trabalho de impressão ou visualização de impressão, após `OnPreparePrinting` foi chamado.  
  
```  
virtual void OnBeginPrinting(
    CDC* pDC,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo da impressora.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua essa função para alocar qualquer GDI recursos, como fontes, ou canetas necessários especificamente para impressão. Selecione os objetos GDI no contexto de dispositivo de dentro do [OnPrint](#onprint) função de membro para cada página que os utiliza. Se você estiver usando o mesmo objeto de exibição para executar a exibição de tela e de impressão, use variáveis separadas para os recursos GDI necessários para cada monitor. Isso permite que você atualize a tela durante a impressão.  
  
 Você também pode usar esta função para executar inicializações dependem das propriedades do contexto de dispositivo da impressora. Por exemplo, o número de páginas necessárias para imprimir o documento pode depender de configurações que o usuário especificado na caixa de diálogo Imprimir (como comprimento da página). Nessa situação, você não pode especificar o tamanho do documento no [OnPreparePrinting](#onprepareprinting) função de membro, onde você normalmente faria isso; você deve aguardar até que o contexto de dispositivo da impressora foi criado com base nas configurações de caixa de diálogo. [OnBeginPrinting](#onbeginprinting) é a primeira função substituível que fornece acesso para o [CDC](../../mfc/reference/cdc-class.md) objeto que representa o contexto de dispositivo da impressora, você pode definir o tamanho do documento por essa função. Observe que, se o tamanho do documento não é especificado por esse tempo, uma barra de rolagem não é exibida durante a visualização de impressão.  
  
##  <a name="ondragenter"></a>CView::OnDragEnter  
 Chamado pela estrutura quando o mouse entra primeiro a região não rolagem da janela de destino de soltar.  
  
```  
virtual DROPEFFECT OnDragEnter(
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para a [COleDataObject](../../mfc/reference/coledataobject-class.md) sendo arrastado para a área para soltar do modo de exibição.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 A atual posição do mouse com relação à área do cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor a partir de `DROPEFFECT` enumeração de tipo, que indica o tipo de depósito que ocorreria se o usuário removido o objeto nessa posição. O tipo de soltar normalmente depende do estado atual da chave indicado pelo `dwKeyState`. Um mapeamento padrão de estados-chave para `DROPEFFECT` valores é:  
  
- `DROPEFFECT_NONE`O objeto de dados não pode ser descartado nessa janela.  
  
- `DROPEFFECT_LINK`para **MK_CONTROL | MK_SHIFT** cria um vínculo entre o objeto e seu servidor.  
  
- `DROPEFFECT_COPY`para **MK_CONTROL** cria uma cópia do objeto descartada.  
  
- `DROPEFFECT_MOVE`para **MK_ALT** cria uma cópia do objeto solto e excluir o objeto original. Isso normalmente é o efeito de soltar padrão, quando o modo de exibição pode aceitar esse objeto de dados.  
  
 Para obter mais informações, consulte o exemplo de conceitos avançados do MFC [OCLIENT](../../visual-cpp-samples.md).  
  
### <a name="remarks"></a>Comentários  
 Implementação padrão é não fazer nada e retornar `DROPEFFECT_NONE`.  
  
 Substituir essa função para se preparar para as chamadas subsequentes a [OnDragOver](#ondragover) função de membro. Todos os dados necessários do objeto de dados devem ser recuperados no momento para uso posterior no `OnDragOver` função de membro. O modo de exibição também deve ser atualizado no momento para dar ao usuário feedback visual. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).  
  
##  <a name="ondragleave"></a>CView::OnDragLeave  
 Chamado pela estrutura durante uma operação de arrastar quando o mouse é movido para fora da área de soltar válidas para essa janela.  
  
```  
virtual void OnDragLeave();
```  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função se a exibição atual precisa limpar as ações executadas durante a [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) chamadas, como a remoção de qualquer feedback visual do usuário enquanto o objeto foi arrastado e solto.  
  
##  <a name="ondragover"></a>CView::OnDragOver  
 Chamado pela estrutura durante uma operação de arrastar quando o mouse é movido sobre a janela de destino de soltar.  
  
```  
virtual DROPEFFECT OnDragOver(
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para a [COleDataObject](../../mfc/reference/coledataobject-class.md) que está sendo arrastado sobre o destino.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 A posição atual do mouse com relação à área de cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor a partir de `DROPEFFECT` enumeração de tipo, que indica o tipo de depósito que ocorreria se o usuário removido o objeto nessa posição. O tipo de soltar geralmente depende do estado atual da chave conforme indicado pelo `dwKeyState`. Um mapeamento padrão de estados-chave para `DROPEFFECT` valores é:  
  
- `DROPEFFECT_NONE`O objeto de dados não pode ser descartado nessa janela.  
  
- `DROPEFFECT_LINK`para **MK_CONTROL | MK_SHIFT** cria um vínculo entre o objeto e seu servidor.  
  
- `DROPEFFECT_COPY`para **MK_CONTROL** cria uma cópia do objeto descartada.  
  
- `DROPEFFECT_MOVE`para **MK_ALT** cria uma cópia do objeto solto e excluir o objeto original. Isso normalmente é o efeito de soltar padrão, quando o modo de exibição pode aceitar o objeto de dados.  
  
 Para obter mais informações, consulte o exemplo de conceitos avançados do MFC [OCLIENT](../../visual-cpp-samples.md).  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão é não fazer nada e retornar `DROPEFFECT_NONE`.  
  
 Substitua essa função para conceder ao usuário feedback visual durante a operação de arrastar. Como essa função é chamada continuamente, qualquer código contido nele deve ser otimizado tanto quanto possível. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).  
  
##  <a name="ondragscroll"></a>CView::OnDragScroll  
 Chamado pela estrutura antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o ponto está na região de rolagem.  
  
```  
virtual DROPEFFECT OnDragScroll(
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 Contém o local do cursor, em pixels, em relação à tela.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor a partir de `DROPEFFECT` enumeração de tipo, que indica o tipo de depósito que ocorreria se o usuário removido o objeto nessa posição. O tipo de soltar normalmente depende do estado atual da chave indicado pelo `dwKeyState`. Um mapeamento padrão de estados-chave para `DROPEFFECT` valores é:  
  
- `DROPEFFECT_NONE`O objeto de dados não pode ser descartado nessa janela.  
  
- `DROPEFFECT_LINK`para **MK_CONTROL | MK_SHIFT** cria um vínculo entre o objeto e seu servidor.  
  
- `DROPEFFECT_COPY`para **MK_CONTROL** cria uma cópia do objeto descartada.  
  
- `DROPEFFECT_MOVE`para **MK_ALT** cria uma cópia do objeto solto e excluir o objeto original.  
  
- `DROPEFFECT_SCROLL`Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no modo de exibição de destino.  
  
 Para obter mais informações, consulte o exemplo de conceitos avançados do MFC [OCLIENT](../../visual-cpp-samples.md).  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função quando quiser fornecer um comportamento especial para esse evento. A implementação padrão rola automaticamente o windows quando o cursor é arrastado para a área de rolagem padrão dentro da borda de cada janela. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).  
  
##  <a name="ondraw"></a>CView::OnDraw  
 Chamado pela estrutura para processar uma imagem do documento.  
  
```  
virtual void OnDraw(CDC* pDC) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para processar uma imagem do documento.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função para executar a exibição de tela, impressão e visualização de impressão e passa um contexto de dispositivo diferente em cada caso. Não há nenhuma implementação padrão.  
  
 Você deve substituir essa função para exibir o modo de exibição do documento. Você pode fazer chamadas GDI (interface) do dispositivo gráfico usando o [CDC](../../mfc/reference/cdc-class.md) objeto apontado pelo `pDC` parâmetro. Você pode selecionar os recursos GDI, como fontes, ou canetas no contexto de dispositivo antes de desenho e desmarcá-los posteriormente. Muitas vezes seu código de desenho pode ser independente de dispositivo; ou seja, ele não exige informações sobre o tipo de dispositivo está exibindo a imagem.  
  
 Para otimizar o desenho, chame o [RectVisible](../../mfc/reference/cdc-class.md#rectvisible) a função de membro do contexto do dispositivo para descobrir se um determinado retângulo será desenhado. Se você precisa distinguir entre a exibição de tela normal e impressão, chame o [IsPrinting](../../mfc/reference/cdc-class.md#isprinting) a função de membro do contexto do dispositivo.  
  
##  <a name="ondrop"></a>CView::OnDrop  
 Chamado pela estrutura quando o usuário libera um objeto de dados em um destino válido.  
  
```  
virtual BOOL OnDrop(
    COleDataObject* pDataObject,  
    DROPEFFECT dropEffect,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para a [COleDataObject](../../mfc/reference/coledataobject-class.md) que é inserida no destino de soltar.  
  
 `dropEffect`  
 O efeito de soltar o usuário solicitou.  
  
- `DROPEFFECT_COPY`Cria uma cópia do objeto de dados que está sendo descartada.  
  
- `DROPEFFECT_MOVE`Move o objeto de dados para o local atual do mouse.  
  
- `DROPEFFECT_LINK`Cria um vínculo entre um objeto de dados e seu servidor.  
  
 `point`  
 A posição atual do mouse com relação à área de cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o depósito foi bem sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada e retorna **FALSE**.  
  
 Substitua essa função para implementar o efeito de soltar um OLE para a área do cliente do modo de exibição. O objeto de dados pode ser examinado por meio de `pDataObject` para dados da área de transferência de dados e formatos descartado no ponto especificado.  
  
> [!NOTE]
>  A estrutura não chamar essa função se houver uma substituição para [OnDropEx](#ondropex) nessa classe de exibição.  
  
##  <a name="ondropex"></a>CView::OnDropEx  
 Chamado pela estrutura quando o usuário libera um objeto de dados em um destino válido.  
  
```  
virtual DROPEFFECT OnDropEx(
    COleDataObject* pDataObject,  
    DROPEFFECT dropDefault,  
    DROPEFFECT dropList,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para a [COleDataObject](../../mfc/reference/coledataobject-class.md) que é inserida no destino de soltar.  
  
 `dropDefault`  
 O efeito que o usuário escolheu para a operação de soltar padrão com base no estado da chave atual. Pode ser `DROPEFFECT_NONE`. Efeitos de soltar são discutidos na seção comentários.  
  
 `dropList`  
 Uma lista dos efeitos soltar que ofereça suporte a origem de soltar. Valores de efeito de posicionamento podem ser combinados usando o OR bit a bit ( **|**) operação. Efeitos de soltar são discutidos na seção comentários.  
  
 `point`  
 A posição atual do mouse com relação à área de cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito de soltar que resultaram na tentativa de descarte no local especificado por `point`. Isso deve ser um dos valores indicados por *dropEffectList*. Efeitos de soltar são discutidos na seção comentários.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão é não fazer nada e retornar um valor fictício (-1) para indicar que a estrutura deve chamar o [OnDrop](#ondrop) manipulador.  
  
 Substitua essa função para implementar o efeito de um botão direito do mouse arrastar e soltar. Botão direito do mouse arrastar e soltar normalmente exibe um menu de opções quando o botão direito do mouse é liberado.  
  
 Sua substituição do `OnDropEx` deve consultar o botão direito do mouse. Você pode chamar [GetKeyState](http://msdn.microsoft.com/library/windows/desktop/ms646301) ou armazenar o estado do botão direito do mouse no seu [OnDragEnter](#ondragenter) manipulador.  
  
-   Se o botão direito do mouse estiver inativo, sua substituição deve exibir um menu pop-up que oferece que suportam os efeitos de soltar, a origem de soltar.  
  
    -   Examine `dropList` para determinar os efeitos de soltar compatíveis com a origem de soltar. Habilite apenas essas ações no menu pop-up.  
  
    -   Use [SetMenuDefaultItem](http://msdn.microsoft.com/library/windows/desktop/ms647996) para definir a ação padrão com base em `dropDefault`.  
  
    -   Por fim, execute a ação indicada pela seleção de usuário no menu pop-up.  
  
-   Se o botão direito do mouse não está inativo, sua substituição deve processar isso como uma solicitação de recebimento padrão. Use o efeito de soltar especificado em `dropDefault`. Como alternativa, sua substituição pode retornar o valor fictício (-1) para indicar que `OnDrop` tratará a operação de soltar.  
  
 Use `pDataObject` para examinar o `COleDataObject` para dados da área de transferência de dados e formato descartado no ponto especificado.  
  
 Efeitos de soltar descrevem a ação associada a uma operação de soltar. Consulte a lista a seguir de soltar efeitos:  
  
- `DROPEFFECT_NONE`Uma lista não seria permitida.  
  
- `DROPEFFECT_COPY`Uma operação de cópia seria realizada.  
  
- `DROPEFFECT_MOVE`Uma operação de movimentação seria realizada.  
  
- `DROPEFFECT_LINK`Seria possível estabelecer um vínculo de dados eliminados para os dados originais.  
  
- `DROPEFFECT_SCROLL`Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.  
  
 Para obter mais informações sobre como configurar o comando de menu padrão, consulte [SetMenuDefaultItem](http://msdn.microsoft.com/library/windows/desktop/ms647996) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] e [CMenu::GetSafeHmenu](../../mfc/reference/cmenu-class.md#getsafehmenu) neste volume.  
  
##  <a name="onendprinting"></a>CView::OnEndPrinting  
 Chamado pela estrutura depois que um documento foi impresso ou visualizado.  
  
```  
virtual void OnEndPrinting(
    CDC* pDC,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo da impressora.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substituir essa função para liberar quaisquer recursos GDI alocada no [OnBeginPrinting](#onbeginprinting) função de membro.  
  
##  <a name="onendprintpreview"></a>CView::OnEndPrintPreview  
 Chamado pela estrutura quando o usuário sai do modo de visualização de impressão.  
  
```  
virtual void OnEndPrintPreview(
    CDC* pDC,  
    CPrintInfo* pInfo,  
    POINT point,  
    CPreviewView* pView);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo da impressora.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
 `point`  
 Especifica o ponto na página que foi exibida no modo de visualização.  
  
 `pView`  
 Aponta para o objeto de exibição usado para visualização.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama o [OnEndPrinting](#onendprinting) função de membro e restaura a janela do quadro principal para o estado em que estava antes da visualização de impressão começou. Substitua essa função para executar um processamento especial quando o modo de visualização é encerrado. Por exemplo, se você quiser manter a posição do usuário no documento quando alternar do modo de visualização para o modo de exibição normal, você pode rolar para a posição descrita pelo `point` parâmetro e o `m_nCurPage` membro do `CPrintInfo` estrutura que o `pInfo` parâmetro aponta para.  
  
 Sempre chamar a versão da classe base de `OnEndPrintPreview` de sua substituição, geralmente no final da função.  
  
##  <a name="oninitialupdate"></a>Cview:: Oninitialupdate  
 Chamado pela estrutura depois que o modo de exibição é anexado ao documento pela primeira vez, mas antes que o modo de exibição é exibido inicialmente.  
  
```  
virtual void OnInitialUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama o [OnUpdate](#onupdate) a função de membro sem informações de dica (ou seja, usando os valores padrão de 0 para o `lHint` parâmetro e **nulo** para o `pHint` parâmetro). Substitua essa função para executar qualquer inicialização única que exige informações sobre o documento. Por exemplo, se seu aplicativo tiver documentos de tamanho fixo, você pode usar essa função para inicializar os limites de rolagem da exibição com base no tamanho do documento. Se o aplicativo suportar documentos de tamanho variável, use [OnUpdate](#onupdate) atualizar a rolagem limita sempre que as alterações do documento.  
  
##  <a name="onpreparedc"></a>CView::OnPrepareDC  
 Chamado pela estrutura antes do [OnDraw](#ondraw) função de membro é chamada para exibição na tela e antes do [OnPrint](#onprint) função de membro é chamada para cada página durante a visualização de impressão ou impressa.  
  
```  
virtual void OnPrepareDC(
    CDC* pDC,  
    CPrintInfo* pInfo = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para processar uma imagem do documento.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual se `OnPrepareDC` está sendo chamado para impressão ou visualização de impressão; o `m_nCurPage` membro Especifica a página prestes a ser impresso. Esse parâmetro é **nulo** se `OnPrepareDC` está sendo chamado para exibição na tela.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada se a função é chamada para exibição na tela. No entanto, essa função é substituída nas classes derivadas, como [CScrollView](../../mfc/reference/cscrollview-class.md)para ajustar os atributos do contexto do dispositivo; Consequentemente, você sempre deve chamar a implementação da classe base no início de sua substituição.  
  
 Se a função é chamada para impressão, a implementação padrão examina as informações da página armazenadas no `pInfo` parâmetro. Se o tamanho do documento não foi especificado, `OnPrepareDC` pressupõe que o documento ao longo de uma página e interrompe o loop de impressão depois que uma página foi impresso. A função para o loop de impressão, definindo o `m_bContinuePrinting` membro da estrutura para **FALSE**.  
  
 Substituir `OnPrepareDC` para qualquer um dos seguintes motivos:  
  
-   Para ajustar os atributos do contexto do dispositivo conforme necessário para a página especificada. Por exemplo, se você precisa definir o modo de mapeamento ou outras características do contexto do dispositivo, fazer isso nessa função.  
  
-   Para realizar a paginação de tempo de impressão. Normalmente você especificar o tamanho do documento quando começa a impressão, usando o [OnPreparePrinting](#onprepareprinting) função de membro. No entanto, se você não souber com antecedência quanto tempo o documento é (por exemplo, ao imprimir um número indeterminado de registros de um banco de dados), substituir `OnPrepareDC` para testar o final do documento enquanto ele estiver sendo impressa. Quando há não mais do documento a ser impresso, defina o `m_bContinuePrinting` membro o `CPrintInfo` estrutura a **FALSE**.  
  
-   Para enviar os códigos de escape para a impressora em uma base por página. Para enviar os códigos de escape de `OnPrepareDC`, chame o **Escape** função de membro a `pDC` parâmetro.  
  
 Chame a versão da classe base de `OnPrepareDC` no início de sua substituição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#183;](../../mfc/codesnippet/cpp/cview-class_1.cpp)]  
  
##  <a name="onprepareprinting"></a>CView::OnPreparePrinting  
 Chamado pela estrutura antes que um documento é impresso ou visualizado.  
  
```  
virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero para iniciar a impressão. 0 se o trabalho de impressão foi cancelado.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada.  
  
 Você deve substituir essa função para habilitar a impressão e visualização de impressão. Chamar o [DoPreparePrinting](#doprepareprinting) função de membro, passando a ele o `pInfo` parâmetro e, em seguida, retornar seu valor de retorno; `DoPreparePrinting` exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo da impressora. Se você deseja inicializar a caixa de diálogo de impressão com valores diferentes de padrões, atribuir valores aos membros do `pInfo`. Por exemplo, se você souber o tamanho do documento, passar o valor para o [SetMaxPage](../../mfc/reference/cprintinfo-structure.md#setmaxpage) função de membro `pInfo` antes de chamar `DoPreparePrinting`. Esse valor é exibido no campo para: caixa na parte do intervalo da caixa de diálogo Imprimir.  
  
 `DoPreparePrinting`não exibe a caixa de diálogo de impressão de um trabalho de visualização. Se você quiser ignorar a caixa de diálogo de impressão para um trabalho de impressão, verifique se o **m_bPreview** membro do `pInfo` é **FALSE** e defina-o como **TRUE** antes de passá-lo para `DoPreparePrinting`; redefini-la para **FALSE** posteriormente.  
  
 Se você precisa executar inicializações que exigem acesso ao `CDC` substituir do objeto que representa o contexto de dispositivo da impressora (por exemplo, se você precisa saber o tamanho de página antes de especificar o tamanho do documento), o `OnBeginPrinting` função de membro.  
  
 Se você quiser definir o valor da **m_nNumPreviewPages** ou **m_strPageDesc** membros o `pInfo` parâmetro, fazê-lo depois de chamar `DoPreparePrinting`. O `DoPreparePrinting` conjuntos de função de membro **m_nNumPreviewPages** para o valor localizado do aplicativo. Arquivo INI e define **m_strPageDesc** para seu valor padrão.  
  
### <a name="example"></a>Exemplo  
  Substituir `OnPreparePrinting` e chamar `DoPreparePrinting` de substituição de forma que o framework exibirá uma caixa de diálogo de impressão e criar um controlador de domínio de impressora para você.  
  
 [!code-cpp[NVC_MFCDocView&#184;](../../mfc/codesnippet/cpp/cview-class_2.cpp)]  
  
 Se você souber quantas páginas que contém o documento, defina a página máximo `OnPreparePrinting` antes de chamar `DoPreparePrinting`. O framework exibirá o número máximo de páginas na caixa "para" da caixa de diálogo Imprimir.  
  
 [!code-cpp[NVC_MFCDocView&#185;](../../mfc/codesnippet/cpp/cview-class_3.cpp)]  
  
##  <a name="onprint"></a>CView::OnPrint  
 Chamado pela estrutura para imprimir ou visualizar uma página do documento.  
  
```  
virtual void OnPrint(
    CDC* pDC,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo da impressora.  
  
 `pInfo`  
 Aponta para um `CPrintInfo` estrutura que descreve o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 Para cada página seja impressa, a estrutura chama essa função imediatamente após chamar o [OnPrepareDC](#onpreparedc) função de membro. A página a ser impressa é especificada pelo `m_nCurPage` membro do [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura `pInfo` aponta para. A implementação padrão chama o [OnDraw](#ondraw) função de membro e passa o contexto de dispositivo da impressora.  
  
 Substitua essa função para qualquer um dos seguintes motivos:  
  
-   Para permitir a impressão de documentos de várias páginas. Renderizar apenas a parte do documento que corresponde à página sendo impressa. Se você estiver usando `OnDraw` para executar o processamento, você pode ajustar a origem do visor para que apenas a parte apropriada do documento seja impresso.  
  
-   Para fazer com que a imagem impressa uma aparência diferente da imagem da tela (ou seja, se seu aplicativo não for WYSIWYG). Em vez de passar a impressora contexto de dispositivo `OnDraw`, use o contexto de dispositivo para renderizar uma imagem usando atributos não são mostrados na tela.  
  
     Se você precisar de recursos GDI para impressão que não são usadas para exibição na tela, selecione-as no contexto de dispositivo antes de desenho e desmarcá-los posteriormente. Esses recursos GDI devem ser alocados no [OnBeginPrinting](#onbeginprinting) e lançada em [OnEndPrinting](#onendprinting).  
  
-   Para implementar cabeçalhos ou rodapés de páginas. Você ainda pode usar `OnDraw` para fazer o processamento, restringindo a área de impressão nos.  
  
 Observe que o **m_rectDraw** membro o `pInfo` parâmetro descreve a área imprimível da página em unidades lógicas.  
  
 Não chame `OnPrepareDC` em seu substituto do `OnPrint`; o framework chama `OnPrepareDC` automaticamente antes de chamar `OnPrint`.  
  
### <a name="example"></a>Exemplo  
 A seguir está um esqueleto para um substituída `OnPrint` função:  
  
 [!code-cpp[NVC_MFCDocView&#186;](../../mfc/codesnippet/cpp/cview-class_4.cpp)]  
  
 Outro exemplo, consulte [CRichEditView::PrintInsideRect](../../mfc/reference/cricheditview-class.md#printinsiderect).  
  
##  <a name="onscroll"></a>CView::OnScroll  
 Chamado pela estrutura para determinar se a rolagem é possível.  
  
```  
virtual BOOL OnScroll(
    UINT nScrollCode,  
    UINT nPos,  
    BOOL bDoScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nScrollCode`  
 Um código de barras de rolagem que indica o usuário da solicitação de rolagem. Esse parâmetro é composto de duas partes: um byte de ordem inferior, que determina o tipo de rolagem horizontalmente ocorrendo, e um byte de ordem superior, que determina o tipo de rolagem vertical ocorrendo:  
  
- **SB_BOTTOM** rola para baixo.  
  
- **SB_LINEDOWN** Rola uma linha para baixo.  
  
- **SB_LINEUP** Rola uma linha para cima.  
  
- **SB_PAGEDOWN** Rola uma página para baixo.  
  
- **SB_PAGEUP** Rola uma página para cima.  
  
- **SB_THUMBTRACK** caixa de rolagem de obstáculos à posição especificada. A posição atual é especificada no `nPos`.  
  
- **SB_TOP** rolar para cima.  
  
 `nPos`  
 Contém a posição atual da caixa de rolagem, se o código de barra de rolagem é **SB_THUMBTRACK**; caso contrário, ele não é usado. Dependendo do período inicial de rolagem, `nPos` pode ser negativo e deve ser convertido em um `int` se necessário.  
  
 `bDoScroll`  
 Determina se, na verdade, você deve fazer a ação especificada de rolagem. Se **verdadeiro,** e rolagem deve ocorrer; se **FALSE**, e rolagem não deve ocorrer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se `bDoScroll` é **TRUE** e realmente foi rolada para o modo de exibição, em seguida, retornar zero; caso contrário 0. Se `bDoScroll` é **FALSE**, em seguida, retornar o valor que você poderia ter retornado se `bDoScroll` foram **TRUE**, mesmo que você realmente não fazer a rolagem.  
  
### <a name="remarks"></a>Comentários  
 Em um caso essa função é chamada pela estrutura com `bDoScroll` definida como **TRUE** quando o modo de exibição recebe uma mensagem de barra de rolagem. Nesse caso, você realmente deve rolar a exibição. No caso dessa função é chamada com `bDoScroll` definida como **FALSE** quando um item OLE inicialmente é arrastado para a região de rolagem automática de um destino antes de rolagem ocorre. Nesse caso, você deve realmente rola o modo de exibição.  
  
##  <a name="onscrollby"></a>CView::OnScrollBy  
 Chamado pela estrutura quando o usuário exibe uma área além a exibição atual do documento, arrastando um item OLE em bordas atual da exibição ou manipulando as barras de rolagem verticais ou horizontais.  
  
```  
virtual BOOL OnScrollBy(
    CSize sizeScroll,  
    BOOL bDoScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `sizeScroll`  
 Número de pixels rolado horizontalmente e verticalmente.  
  
 `bDoScroll`  
 Determina se a rolagem da exibição ocorrerá. Se **verdadeiro,** e rolagem ocorre; se **FALSE**, e rolagem não ocorrerá.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o modo de exibição foi capaz de ser rolado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Em classes derivadas esse método verifica se a exibição é rolável na direção em que o usuário solicitado e, em seguida, atualiza a nova região, se necessário. Essa função é chamada automaticamente pelo [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) para executar a solicitação real de rolagem.  
  
 A implementação padrão desse método não altera o modo de exibição, mas se não for chamado, o modo de exibição não rolará em um `CScrollView`-classe derivada.  
  
 Se a altura ou largura do documento exceder 32767 pixels, rolagem após 32767 falhará porque `OnScrollBy` é chamado com um inválido `sizeScroll` argumento.  
  
##  <a name="onupdate"></a>CView::OnUpdate  
 Chamado pela estrutura depois que o documento da exibição foi modificado; Essa função é chamada pelo [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) e permite que o modo de exibição atualizar sua exibição para refletir essas modificações.  
  
```  
virtual void OnUpdate(
    CView* pSender,  
    LPARAM lHint,  
    CObject* pHint);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSender`  
 Aponta para o modo de exibição que modificou o documento, ou **nulo** se todas as exibições serão atualizados.  
  
 `lHint`  
 Contém informações sobre as modificações.  
  
 `pHint`  
 Aponta para um objeto de armazenamento de informações sobre as modificações.  
  
### <a name="remarks"></a>Comentários  
 Ele também é chamado pela implementação padrão de [OnInitialUpdate](#oninitialupdate). A implementação padrão invalida toda a área cliente, marcando-o para pintura quando o próximo `WM_PAINT` mensagem é recebida. Substitua essa função se você deseja atualizar apenas as regiões que mapeiam para as partes modificadas do documento. Para fazer isso, você deve passar informações sobre as modificações usando os parâmetros de dica.  
  
 Para usar `lHint`, definir valores de Dica especial, normalmente um bitmask ou um tipo enumerado e tem o documento passar um destes valores. Usar `pHint`, derive uma classe de dica de [CObject](../../mfc/reference/cobject-class.md) e fazer com que o documento passar um ponteiro para um objeto de dica; ao substituir `OnUpdate`, use o [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) a função de membro para determinar o tipo de tempo de execução do objeto dica.  
  
 Normalmente você não deve executar qualquer desenho diretamente do `OnUpdate`. Em vez disso, determinar o retângulo descrever, nas coordenadas do dispositivo, a área que requer a atualização. passar esse rectangle [CWnd::InvalidateRect](../../mfc/reference/cwnd-class.md#invalidaterect). Isso faz com que a pintura ocorra na próxima vez que um [WM_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) mensagem é recebida.  
  
 Se `lHint` é 0 e `pHint` é **nulo**, o documento foi enviada uma notificação de atualização genérico. Se um modo de exibição recebe uma notificação de atualização genérico, ou se ele não é possível decodificar as dicas, ele deve invalidar sua área inteira do cliente.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)

