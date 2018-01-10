---
title: Classe CView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
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
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 843417508fc43f99b0027873988746d03a7863cd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CView::DoPreparePrinting](#doprepareprinting)|Exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo de impressora; chamar ao substituir o `OnPreparePrinting` função de membro.|  
|[CView::GetDocument](#getdocument)|Retorna o documento associado com o modo de exibição.|  
|[CView::IsSelected](#isselected)|Testa se um item do documento é selecionado. Necessário para suporte OLE.|  
|[CView::OnDragEnter](#ondragenter)|Chamado quando um item é arrastado primeiro para a área de arrastar e soltar de uma exibição.|  
|[CView::OnDragLeave](#ondragleave)|Chamado quando um item arrastado deixa a região de arrastar e soltar de uma exibição.|  
|[CView::OnDragOver](#ondragover)|Chamado quando um item é arrastado sobre a região de arrastar e soltar de uma exibição.|  
|[CView::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|  
|[CView::OnDrop](#ondrop)|Chamado quando um item foi descartado para a área de arrastar e soltar de uma exibição, o manipulador padrão.|  
|[CView::OnDropEx](#ondropex)|Chamado quando um item foi descartado para a área de arrastar e soltar de uma exibição, o manipulador primário.|  
|[CView::OnInitialUpdate](#oninitialupdate)|Chamado depois que uma exibição é anexada primeiro a um documento.|  
|[CView::OnPrepareDC](#onpreparedc)|Chamado antes do `OnDraw` função de membro é chamada para a exibição de tela ou `OnPrint` função de membro é chamada para visualização de impressão ou impressão.|  
|[CView::OnScroll](#onscroll)|Chamado quando o OLE itens são arrastados além das bordas do modo de exibição.|  
|[CView::OnScrollBy](#onscrollby)|Chamado quando uma exibição que contém itens OLE no local ativos é rolada.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CView::OnActivateFrame](#onactivateframe)|Chamado quando a janela do quadro que contém a exibição é ativada ou desativada.|  
|[CView::OnActivateView](#onactivateview)|Chamado quando uma exibição é ativada.|  
|[CView::OnBeginPrinting](#onbeginprinting)|Chamado quando um trabalho de impressão começa; Substitua para alocar recursos de interface (GDI) do dispositivo de gráficos.|  
|[CView::OnDraw](#ondraw)|Chamado para processar uma imagem do documento para tela, imprimir ou visualizar impressão. Implementação do necessário.|  
|[CView::OnEndPrinting](#onendprinting)|Chamado quando um trabalho de impressão termina; substituição para desalocar recursos GDI.|  
|[CView::OnEndPrintPreview](#onendprintpreview)|Chamado quando o modo de visualização é encerrado.|  
|[CView::OnPreparePrinting](#onprepareprinting)|Chamado antes de um documento é impresso ou visualizado; substituição para inicializar a caixa de diálogo Imprimir.|  
|[CView::OnPrint](#onprint)|Chamado para imprimir ou visualizar uma página do documento.|  
|[CView::OnUpdate](#onupdate)|Chamado para notificar um modo de exibição que seu documento foi modificado.|  
  
## <a name="remarks"></a>Comentários  
 Um modo de exibição é anexado a um documento e atua como um intermediário entre o documento e o usuário: a exibição renderiza uma imagem do documento na tela ou impressora e interpreta a entrada do usuário como operações após o documento.  
  
 Uma exibição é um filho de uma janela do quadro. Mais de uma exibição pode compartilhar uma janela do quadro, como no caso de uma janela separadora. A relação entre uma classe de exibição, uma classe de janela do quadro e uma classe de documento é estabelecida por um `CDocTemplate` objeto. Quando o usuário abre uma nova janela ou divide uma existente uma, a estrutura constrói uma nova exibição e a anexa ao documento.  
  
 Um modo de exibição pode ser anexado a apenas um documento, mas um documento pode ter várias exibições anexadas a ele vez — por exemplo, se o documento é exibido em uma janela separadora ou em várias janelas filho em um aplicativo de interface MDI vários documentos. Seu aplicativo pode dar suporte a diferentes tipos de modos de exibição para um determinado tipo de documento; Por exemplo, um programa de processamento de texto pode fornecer um modo de exibição de texto completo de um documento e uma exibição de estrutura de tópicos que mostra somente os cabeçalhos de seção. Esses tipos diferentes de modos de exibição podem ser colocados em janelas de quadro separado ou em painéis separados de uma janela do quadro única se você usar uma janela separadora.  
  
 Um modo de exibição pode ser responsável por manipular vários tipos diferentes de entrada, como a entrada do teclado, mouse de entrada ou entrada via arrastar-e-soltar, bem como os comandos de menus, barras de ferramentas ou barras de rolagem. Um modo de exibição recebe comandos encaminhados por sua janela do quadro. Se o modo de exibição não lidar com um determinado comando, ele encaminha o comando para o documento associado. Como todos os destinos de comando, uma exibição controla as mensagens por meio de um mapa de mensagem.  
  
 O modo de exibição é responsável para exibir e modificar os dados do documento, mas não para fazê-lo. O documento fornece a exibição com os detalhes necessários sobre seus dados. Você pode deixar o acesso de modo de exibição diretamente membros de dados do documento, ou você pode fornecer funções de membro da classe do documento para a classe de exibição chamar.  
  
 Quando dados do documento é alterado, o responsável para que as alterações de modo de exibição normalmente chama o [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) função para o documento, que notifica sobre todos os outros modos de exibição chamando o `OnUpdate` a função de membro para cada. A implementação padrão de `OnUpdate` invalida a área de cliente inteiro do modo de exibição. Você pode substituí-la para invalidar apenas essas regiões da área do cliente que são mapeados para as partes de modificação do documento.  
  
 Para usar `CView`, derive uma classe dele e implementar o `OnDraw` a função de membro para executar a exibição de tela. Você também pode usar `OnDraw` para executar a impressão e visualização de impressão. O framework controla o loop de impressão para impressão e visualização do documento.  
  
 Um modo de exibição manipula mensagens da barra de rolagem com o [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) funções de membro. Você pode implementar essas funções de tratamento de mensagem de barra de rolagem, ou você pode usar o `CView` classe derivada [CScrollView](../../mfc/reference/cscrollview-class.md) para tratar a rolagem para você.  
  
 Além disso `CScrollView`, a biblioteca Microsoft Foundation Class fornece nove outras classes derivadas de `CView`:  
  
- [CCtrlView](../../mfc/reference/cctrlview-class.md), uma exibição que permite o uso do documento - exibir controles de edição de arquitetura com árvore, lista e avançada.  
  
- [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md), uma exibição que mostra os registros do banco de dados em controles de caixa de diálogo.  
  
- [CEditView](../../mfc/reference/ceditview-class.md), uma exibição que fornece um editor de texto simples de várias linhas. Você pode usar uma `CEditView` objeto como um controle em uma caixa de diálogo, bem como uma exibição em um documento.  
  
- [CFormView](../../mfc/reference/cformview-class.md), uma exibição rolável que contém os controles de caixa de diálogo e baseia-se em um recurso de modelo de caixa de diálogo.  
  
- [CListView](../../mfc/reference/clistview-class.md), uma exibição que permite o uso do documento - arquitetura de exibição com controles de lista.  
  
- [CRecordView](../../mfc/reference/crecordview-class.md), uma exibição que mostra os registros do banco de dados em controles de caixa de diálogo.  
  
- [CRichEditView](../../mfc/reference/cricheditview-class.md), uma exibição que permite o uso do documento - exibir controles de edição de arquitetura com avançada.  
  
- [CScrollView](../../mfc/reference/cscrollview-class.md), um modo de exibição automaticamente oferece suporte a rolagem.  
  
- [CTreeView](../../mfc/reference/ctreeview-class.md), uma exibição que permite o uso do documento - arquitetura de exibição com controles de árvore.  
  
 O `CView` classe também tem uma classe de implementação derivada chamada **CPreviewView**, que é usada pelo framework para executar a visualização de impressão. Esta classe oferece suporte os recursos exclusivos para a janela de visualização de impressão, como uma barra de ferramentas, visualização de página única ou dupla, e zoom, que é, aumentando a imagem visualizada. Você não precisa chamar ou substituir qualquer **CPreviewView**de funções de membro, a menos que você deseja implementar sua própria interface para a visualização de impressão (por exemplo, se você deseja oferecer suporte à edição no modo de visualização de impressão). Para obter mais informações sobre como usar `CView`, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e [impressão](../../mfc/printing.md). Além disso, consulte [30 de observação técnica](../../mfc/tn030-customizing-printing-and-print-preview.md) para obter mais detalhes sobre como personalizar a visualização de impressão.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cview"></a>CView::CView  
 Constrói um objeto `CView`.  
  
```  
CView();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama o construtor quando uma nova janela do quadro é criada ou uma janela é dividida. Substituir o [OnInitialUpdate](#oninitialupdate) função de membro para inicializar a exibição depois que o documento está anexado.  
  
##  <a name="doprepareprinting"></a>CView::DoPreparePrinting  
 Chamar essa função de sua substituição de [OnPreparePrinting](#onprepareprinting) para invocar a caixa de diálogo de impressão e criar um contexto de dispositivo de impressora.  
  
```  
BOOL DoPreparePrinting(CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se pode começar a visualização de impressão ou impressão; 0 se a operação foi cancelada.  
  
### <a name="remarks"></a>Comentários  
 Comportamento desta função depende se ele está sendo chamado para visualização de impressão ou impressão (especificado pelo **m_bPreview** membro o `pInfo` parâmetro). Se um arquivo está sendo impressa, esta função chama a caixa de diálogo de impressão, usando os valores no [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que `pInfo` aponta para; depois que o usuário tenha fechado a caixa de diálogo, a função cria um contexto de dispositivo de impressora com base nas configurações do usuário especificado na caixa de diálogo e retorna este contexto de dispositivo por meio de `pInfo` parâmetro. Este contexto de dispositivo é usado para imprimir o documento.  
  
 Se um arquivo está sendo visualizado, esta função cria um contexto de dispositivo de impressora usando as configurações atuais de impressora; Este contexto de dispositivo é usado para simular a impressora durante a visualização.  
  
##  <a name="getdocument"></a>CView::GetDocument  
 Chame essa função para obter um ponteiro para o documento do modo de exibição.  
  
```  
CDocument* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CDocument](../../mfc/reference/cdocument-class.md) objeto associado com o modo de exibição. **NULO** se o modo de exibição não está anexado a um documento.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que você possa chamar funções de membro do documento.  
  
##  <a name="isselected"></a>CView::IsSelected  
 Chamado pelo framework para verificar se o item do documento especificado é selecionado.  
  
```  
virtual BOOL IsSelected(const CObject* pDocItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDocItem`  
 Aponta para o item do documento que está sendo testado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item do documento especificado está selecionado. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Retorna a implementação padrão dessa função **FALSE**. Substituir essa função se você estiver implementando seleção usando [CDocItem](../../mfc/reference/cdocitem-class.md) objetos. Você deve substituir essa função se o modo de exibição contém itens OLE.  
  
##  <a name="onactivateframe"></a>CView::OnActivateFrame  
 Chamado pelo framework quando a janela do quadro que contém a exibição é ativada ou desativada.  
  
```  
virtual void OnActivateFrame(
    UINT nState,  
    CFrameWnd* pFrameWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nState`  
 Especifica se a janela do quadro está sendo ativada ou desativada. Pode ser um dos seguintes valores:  
  
- **WA_INACTIVE** a janela do quadro está sendo desativada.  
  
- **WA_ACTIVE** a janela do quadro está sendo ativada através de algum método diferente de um clique do mouse (por exemplo, usando a interface do teclado para selecionar a janela).  
  
- **WA_CLICKACTIVE** a janela do quadro está sendo ativada pelo clique do mouse  
  
 `pFrameWnd`  
 Ponteiro para a janela do quadro que deve ser ativado.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função de membro, se você quiser executar um processamento especial quando a janela do quadro associada com a exibição é ativada ou desativada. Por exemplo, [CFormView](../../mfc/reference/cformview-class.md) executa essa substituição quando ele salva e restaura o controle que tem foco.  
  
##  <a name="onactivateview"></a>CView::OnActivateView  
 Chamado pelo framework quando uma exibição é ativada ou desativada.  
  
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
 A implementação padrão dessa função define o foco para o modo de exibição que está sendo ativado. Substitua essa função se você deseja executar um processamento especial quando uma exibição é ativada ou desativada. Por exemplo, se você quiser fornecem indicações visuais especiais que distinguem o modo de exibição ativo os modos de exibição inativos, você seria examinar o `bActivate` parâmetro e atualize a aparência do modo de exibição adequadamente.  
  
 O `pActivateView` e `pDeactiveView` parâmetros apontam para a mesma exibição se a janela do quadro principal do aplicativo é ativada sem alterações no modo ativo — por exemplo, se o foco está sendo transferido do outro aplicativo para este, em vez de um Exibir para outro dentro do aplicativo ou ao alternar entre janelas filho MDI. Isso permite que uma exibição perceber novamente sua paleta, se necessário.  
  
 Esses parâmetros são diferentes quando [CFrameWnd::SetActiveView](../../mfc/reference/cframewnd-class.md#setactiveview) é chamado com um modo de exibição que é diferente da que [CFrameWnd::GetActiveView](../../mfc/reference/cframewnd-class.md#getactiveview) retornaria. Isso geralmente acontece com janelas separadoras.  
  
##  <a name="onbeginprinting"></a>CView::OnBeginPrinting  
 Chamado pelo framework no início de um trabalho de visualização de impressão ou impressão após `OnPreparePrinting` foi chamado.  
  
```  
virtual void OnBeginPrinting(
    CDC* pDC,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo de impressora.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua essa função para alocar qualquer GDI recursos, como canetas ou fontes, necessários especificamente para impressão. Selecione os objetos GDI no contexto de dispositivo de dentro do [OnPrint](#onprint) função de membro para cada página que usa. Se você estiver usando o mesmo objeto de exibição para executar a exibição de tela e de impressão, use variáveis separadas para os recursos GDI necessários para cada exibição; Isso permite que você atualize a tela durante a impressão.  
  
 Você também pode usar esta função para executar inicializações dependem das propriedades do contexto do dispositivo de impressora. Por exemplo, o número de páginas necessário para imprimir o documento pode depender de configurações que o usuário especificado na caixa de diálogo de impressão (como comprimento da página). Em tal situação, você não pode especificar o tamanho do documento no [OnPreparePrinting](#onprepareprinting) função de membro, em que você normalmente faria isso; você deve aguardar até que o contexto de dispositivo de impressora foi criado com base nas configurações de caixa de diálogo. [OnBeginPrinting](#onbeginprinting) é a primeira função substituível que fornece acesso para o [CDC](../../mfc/reference/cdc-class.md) objeto que representa o contexto de dispositivo de impressora, você pode definir o tamanho do documento de sua função. Observe que, se o tamanho do documento não é especificado por esse tempo, uma barra de rolagem não é exibida durante a visualização de impressão.  
  
##  <a name="ondragenter"></a>CView::OnDragEnter  
 Chamado pelo framework quando o mouse entra primeiro a região não rolagem da janela de destino de soltar.  
  
```  
virtual DROPEFFECT OnDragEnter(
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) sendo arrastado para a área para soltar do modo de exibição.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 A atual posição do mouse relativas à área do cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor da `DROPEFFECT` enumerados tipo, que indica o tipo de soltar que ocorreria se o usuário removido o objeto nesta posição. O tipo de soltar normalmente depende do estado atual da chave indicado pelo `dwKeyState`. Um mapeamento padrão de estados-chave para `DROPEFFECT` valores é:  
  
- `DROPEFFECT_NONE`O objeto de dados não pode ser descartado nesta janela.  
  
- `DROPEFFECT_LINK`para **MK_CONTROL &#124; MK_SHIFT** cria um vínculo entre o objeto e seu servidor.  
  
- `DROPEFFECT_COPY`para **MK_CONTROL** cria uma cópia do objeto descartada.  
  
- `DROPEFFECT_MOVE`para **MK_ALT** cria uma cópia do objeto descartada e excluir o objeto original. Isso normalmente é o efeito de soltar padrão, quando o modo de exibição pode aceitar esse objeto de dados.  
  
 Para obter mais informações, consulte o exemplo de conceitos avançados do MFC [OCLIENT](../../visual-cpp-samples.md).  
  
### <a name="remarks"></a>Comentários  
 Implementação padrão é não fazer nada e retornar `DROPEFFECT_NONE`.  
  
 Substituir esta função para preparar para chamadas futuras para o [OnDragOver](#ondragover) função de membro. Todos os dados necessários do objeto de dados devem ser recuperados no momento para usar posteriormente no `OnDragOver` função de membro. O modo de exibição também deve ser atualizado no momento para fornecer os comentários visuais de usuário. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).  
  
##  <a name="ondragleave"></a>CView::OnDragLeave  
 Chamado pelo framework durante uma operação de arrastar quando o mouse é movido para fora da área de soltar válido nessa janela.  
  
```  
virtual void OnDragLeave();
```  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função se o modo de exibição atual precisa limpar quaisquer ações executadas durante a [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) chamadas, como a remoção de qualquer feedback visual do usuário enquanto o objeto foi arrastado e solto .  
  
##  <a name="ondragover"></a>CView::OnDragOver  
 Chamado pelo framework durante uma operação de arrastar quando o mouse é movido sobre a janela de destino de soltar.  
  
```  
virtual DROPEFFECT OnDragOver(
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) sendo arrastado sobre o destino.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 A posição atual do mouse relativas à área do cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor da `DROPEFFECT` enumerados tipo, que indica o tipo de soltar que ocorreria se o usuário removido o objeto nesta posição. O tipo de soltar geralmente depende do estado atual da chave conforme indicado pelo `dwKeyState`. Um mapeamento padrão de estados-chave para `DROPEFFECT` valores é:  
  
- `DROPEFFECT_NONE`O objeto de dados não pode ser descartado nesta janela.  
  
- `DROPEFFECT_LINK`para **MK_CONTROL &#124; MK_SHIFT** cria um vínculo entre o objeto e seu servidor.  
  
- `DROPEFFECT_COPY`para **MK_CONTROL** cria uma cópia do objeto descartada.  
  
- `DROPEFFECT_MOVE`para **MK_ALT** cria uma cópia do objeto descartada e excluir o objeto original. Isso normalmente é o efeito de soltar padrão, quando o modo de exibição pode aceitar o objeto de dados.  
  
 Para obter mais informações, consulte o exemplo de conceitos avançados do MFC [OCLIENT](../../visual-cpp-samples.md).  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão é não fazer nada e retornar `DROPEFFECT_NONE`.  
  
 Substitua essa função para fornecer os comentários visuais do usuário durante a operação de arrastar. Como essa função é chamada continuamente, qualquer código contido nele deve ser otimizado tanto quanto possível. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).  
  
##  <a name="ondragscroll"></a>CView::OnDragScroll  
 Chamado pelo framework antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o ponto está em uma região de rolagem.  
  
```  
virtual DROPEFFECT OnDragScroll(
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 Contém o local do cursor, em pixels, em relação à tela.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor da `DROPEFFECT` enumerados tipo, que indica o tipo de soltar que ocorreria se o usuário removido o objeto nesta posição. O tipo de soltar normalmente depende do estado atual da chave indicado pelo `dwKeyState`. Um mapeamento padrão de estados-chave para `DROPEFFECT` valores é:  
  
- `DROPEFFECT_NONE`O objeto de dados não pode ser descartado nesta janela.  
  
- `DROPEFFECT_LINK`para **MK_CONTROL &#124; MK_SHIFT** cria um vínculo entre o objeto e seu servidor.  
  
- `DROPEFFECT_COPY`para **MK_CONTROL** cria uma cópia do objeto descartada.  
  
- `DROPEFFECT_MOVE`para **MK_ALT** cria uma cópia do objeto descartada e excluir o objeto original.  
  
- `DROPEFFECT_SCROLL`Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no modo de exibição de destino.  
  
 Para obter mais informações, consulte o exemplo de conceitos avançados do MFC [OCLIENT](../../visual-cpp-samples.md).  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função quando desejar fornecer um comportamento especial para esse evento. A implementação padrão rola automaticamente o windows quando o cursor é arrastado para a região de rolagem padrão dentro da borda de cada janela. Para obter mais informações, consulte o artigo [arrastar e soltar: Implementando um destino de soltar](../../mfc/drag-and-drop-implementing-a-drop-target.md).  
  
##  <a name="ondraw"></a>CView::OnDraw  
 Chamado pelo framework para processar uma imagem do documento.  
  
```  
virtual void OnDraw(CDC* pDC) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para processar uma imagem do documento.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função para executar a exibição de tela, impressão e visualização de impressão e passar um contexto de dispositivo diferentes em cada caso. Não há nenhuma implementação padrão.  
  
 Você deve substituir essa função para exibir o modo de exibição do documento. Você pode fazer chamadas GDI (interface) do dispositivo gráfico usando o [CDC](../../mfc/reference/cdc-class.md) objeto apontada pelo `pDC` parâmetro. Você pode selecionar recursos GDI, como canetas ou fontes, no contexto do dispositivo antes do desenho e, em seguida, desmarque-las posteriormente. Geralmente o código de desenho pode ser independente de dispositivo; ou seja, que não exige informações sobre o tipo de dispositivo está exibindo a imagem.  
  
 Para otimizar o desenho, chame o [RectVisible](../../mfc/reference/cdc-class.md#rectvisible) a função de membro do contexto do dispositivo para descobrir se um determinado retângulo será desenhado. Se você precisar distinguir entre a exibição de tela normal e impressão, chame o [IsPrinting](../../mfc/reference/cdc-class.md#isprinting) a função de membro do contexto do dispositivo.  
  
##  <a name="ondrop"></a>CView::OnDrop  
 Chamado pelo framework quando o usuário libera um objeto de dados em um destino válido.  
  
```  
virtual BOOL OnDrop(
    COleDataObject* pDataObject,  
    DROPEFFECT dropEffect,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que é inserida no destino de soltar.  
  
 `dropEffect`  
 O efeito de remover o usuário solicitou.  
  
- `DROPEFFECT_COPY`Cria uma cópia do objeto de dados que está sendo descartado.  
  
- `DROPEFFECT_MOVE`Move o objeto de dados para o local atual do mouse.  
  
- `DROPEFFECT_LINK`Cria um vínculo entre um objeto de dados e seu servidor.  
  
 `point`  
 A posição atual do mouse relativas à área do cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o descarte foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada e retorna **FALSE**.  
  
 Substitua essa função para implementar o efeito de um drop OLE para a área cliente do modo de exibição. O objeto de dados pode ser examinado por meio de `pDataObject` para dados de área de transferência de dados e formatos descartado no ponto especificado.  
  
> [!NOTE]
>  A estrutura não chamar essa função se houver uma substituição para [OnDropEx](#ondropex) nessa classe de exibição.  
  
##  <a name="ondropex"></a>CView::OnDropEx  
 Chamado pelo framework quando o usuário libera um objeto de dados em um destino válido.  
  
```  
virtual DROPEFFECT OnDropEx(
    COleDataObject* pDataObject,  
    DROPEFFECT dropDefault,  
    DROPEFFECT dropList,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) que é inserida no destino de soltar.  
  
 `dropDefault`  
 O efeito que o usuário escolheu para a operação de soltar padrão com base no estado atual da chave. Pode ser `DROPEFFECT_NONE`. Efeitos de soltar são discutidos na seção comentários.  
  
 `dropList`  
 Uma lista dos efeitos drop que oferece suporte a origem de soltar. Soltar efeito valores podem ser combinados usando o OR bit a bit ( **&#124;**) operação. Efeitos de soltar são discutidos na seção comentários.  
  
 `point`  
 A posição atual do mouse relativas à área do cliente do modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito de soltar que resultaram da tentativa de descarte no local especificado por `point`. Isso deve ser um dos valores indicados por *dropEffectList*. Efeitos de soltar são discutidos na seção comentários.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão é não fazer nada e retornar um valor fictício (-1) para indicar que a estrutura deve chamar o [OnDrop](#ondrop) manipulador.  
  
 Substitua essa função para implementar o efeito de um arraste do botão direito do mouse e drop. Botão direito do mouse arrastar e soltar normalmente exibe um menu de opções quando o botão direito do mouse é liberado.  
  
 A substituição de `OnDropEx` devem consultar o botão direito do mouse. Você pode chamar [GetKeyState](http://msdn.microsoft.com/library/windows/desktop/ms646301) ou armazenar o estado do botão direito do mouse do seu [OnDragEnter](#ondragenter) manipulador.  
  
-   Se o botão direito do mouse estiver inativo, sua substituição deve exibir um menu pop-up que oferece que suportam os efeitos de soltar pela fonte de descarte.  
  
    -   Examine `dropList` para determinar os efeitos de soltar suportados pela fonte de descarte. Habilite somente essas ações no menu pop-up.  
  
    -   Use [SetMenuDefaultItem](http://msdn.microsoft.com/library/windows/desktop/ms647996) para definir a ação padrão com base em `dropDefault`.  
  
    -   Finalmente, conforme indicado pela seleção do usuário no menu pop-up.  
  
-   Se o botão direito do mouse não está inativo, sua substituição deve processar essa como uma solicitação de lista padrão. Use o efeito de soltar especificado em `dropDefault`. Como alternativa, sua substituição pode retornar o valor fictício (-1) para indicar que `OnDrop` tratará essa operação drop.  
  
 Use `pDataObject` para examinar o `COleDataObject` para dados de área de transferência de dados e formato descartado no ponto especificado.  
  
 Efeitos de soltar descrevem a ação associada a uma operação de soltar. Consulte a seguinte lista de soltar efeitos:  
  
- `DROPEFFECT_NONE`Um descarte não será permitido.  
  
- `DROPEFFECT_COPY`Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE`Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK`Um link de dados descartados para os dados originais seja estabelecido.  
  
- `DROPEFFECT_SCROLL`Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.  
  
 Para obter mais informações sobre como configurar o comando de menu padrão, consulte [SetMenuDefaultItem](http://msdn.microsoft.com/library/windows/desktop/ms647996) no SDK do Windows e [CMenu::GetSafeHmenu](../../mfc/reference/cmenu-class.md#getsafehmenu) nesse volume.  
  
##  <a name="onendprinting"></a>CView::OnEndPrinting  
 Chamado pelo framework depois que um documento foi impresso ou visualizado.  
  
```  
virtual void OnEndPrinting(
    CDC* pDC,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo de impressora.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substituir esta função para liberar quaisquer recursos GDI alocada no [OnBeginPrinting](#onbeginprinting) função de membro.  
  
##  <a name="onendprintpreview"></a>CView::OnEndPrintPreview  
 Chamado pelo framework quando o usuário sai do modo de visualização de impressão.  
  
```  
virtual void OnEndPrintPreview(
    CDC* pDC,  
    CPrintInfo* pInfo,  
    POINT point,  
    CPreviewView* pView);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo de impressora.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
 `point`  
 Especifica o ponto na página de última foi exibida no modo de visualização.  
  
 `pView`  
 Aponta para o objeto de exibição usado para visualização.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão Esta função chama o [OnEndPrinting](#onendprinting) função de membro e restaura a janela do quadro principal para o estado em que estava antes da visualização de impressão começou. Substitua esta função para executar um processamento especial quando o modo de visualização é encerrado. Por exemplo, se você quiser manter a posição do usuário no documento ao alternar do modo de visualização para modo de exibição normal, você pode rolar para a posição descrita pelo `point` parâmetro e o `m_nCurPage` membro o `CPrintInfo` estrutura que o `pInfo` parâmetro aponta para.  
  
 Sempre chamar a versão da classe base de `OnEndPrintPreview` de sua substituição, normalmente no final da função.  
  
##  <a name="oninitialupdate"></a>CView::OnInitialUpdate  
 Chamado pelo framework depois que a exibição é anexado ao documento pela primeira vez, mas antes do modo de exibição é exibido inicialmente.  
  
```  
virtual void OnInitialUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão Esta função chama o [OnUpdate](#onupdate) a função de membro sem informações de dica (ou seja, usando os valores padrão de 0 para o `lHint` parâmetro e **nulo** para o `pHint` parâmetro). Substitua esta função para executar qualquer inicialização única que exige informações sobre o documento. Por exemplo, se seu aplicativo tiver documentos de tamanho fixo, você pode usar essa função para inicializar os limites de rolagem do modo de exibição com base no tamanho do documento. Se seu aplicativo dá suporte a documentos de tamanho variável, use [OnUpdate](#onupdate) atualizar a rolagem limita toda vez que as alterações de documento.  
  
##  <a name="onpreparedc"></a>CView::OnPrepareDC  
 Chamado pelo framework antes do [OnDraw](#ondraw) função de membro é chamada para a exibição de tela e antes do [OnPrint](#onprint) função de membro é chamada para cada página durante a visualização de impressão ou impressão.  
  
```  
virtual void OnPrepareDC(
    CDC* pDC,  
    CPrintInfo* pInfo = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para processar uma imagem do documento.  
  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual se `OnPrepareDC` está sendo chamado para a visualização de impressão ou impressão; o `m_nCurPage` membro Especifica a página prestes a ser impresso. Esse parâmetro é **nulo** se `OnPrepareDC` está sendo chamado para exibição na tela.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não fará nada se a função é chamada para exibição na tela. No entanto, essa função é substituída nas classes derivadas, como [CScrollView](../../mfc/reference/cscrollview-class.md)para ajustar os atributos do contexto do dispositivo; portanto, você sempre deve chamar a implementação da classe base no início de sua substituição.  
  
 Se a função é chamada para impressão, a implementação padrão examina as informações da página armazenadas no `pInfo` parâmetro. Se o tamanho do documento não foi especificado, `OnPrepareDC` supõe que o documento ao longo de uma página e o loop de impressão é interrompida depois que uma página foi impresso. A função para o loop de impressão, definindo o `m_bContinuePrinting` membro da estrutura para **FALSE**.  
  
 Substituir `OnPrepareDC` para qualquer um dos seguintes motivos:  
  
-   Para ajustar os atributos do contexto do dispositivo conforme necessário para a página especificada. Por exemplo, se você precisar definir o modo de mapeamento ou outras características do contexto do dispositivo, fazer isso nesta função.  
  
-   Para realizar a paginação de tempo de impressão. Normalmente você especificar o tamanho do documento quando começa a impressão, usando o [OnPreparePrinting](#onprepareprinting) função de membro. No entanto, se você não souber com antecedência quanto tempo o documento (por exemplo, ao imprimir um número indeterminado de registros de um banco de dados), substituir `OnPrepareDC` para testar o fim do documento enquanto ele está sendo impressa. Quando há não mais do documento a ser impresso, defina o `m_bContinuePrinting` membro o `CPrintInfo` estrutura para **FALSE**.  
  
-   Para enviar os códigos de escape para a impressora em uma base de página por página. Para enviar os códigos de escape de `OnPrepareDC`, chame o **Escape** função de membro a `pDC` parâmetro.  
  
 Chamar a classe base versão `OnPrepareDC` no início de sua substituição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#183](../../mfc/codesnippet/cpp/cview-class_1.cpp)]  
  
##  <a name="onprepareprinting"></a>CView::OnPreparePrinting  
 Chamado pelo framework antes de um documento é impresso ou visualizado.  
  
```  
virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInfo`  
 Aponta para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que descreve o trabalho de impressão atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero para começar a impressão. 0 se o trabalho de impressão foi cancelado.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não fará nada.  
  
 Você deve substituir essa função para habilitar a impressão e visualização de impressão. Chamar o [DoPreparePrinting](#doprepareprinting) função de membro, passando o `pInfo` parâmetro e, em seguida, retornar o valor de retorno; `DoPreparePrinting` exibe a caixa de diálogo de impressão e cria um contexto de dispositivo de impressora. Se você deseja inicializar a caixa de diálogo de impressão com valores diferentes de padrões, atribuir valores para os membros do `pInfo`. Por exemplo, se você souber o tamanho do documento, passe o valor para o [SetMaxPage](../../mfc/reference/cprintinfo-structure.md#setmaxpage) função membro de `pInfo` antes de chamar `DoPreparePrinting`. Esse valor é exibido no campo para: caixa na parte do intervalo da caixa de diálogo Imprimir.  
  
 `DoPreparePrinting`Não exibir a caixa de diálogo de impressão de um trabalho de visualização. Se você quiser ignorar a caixa de diálogo de impressão para um trabalho de impressão, verifique se o **m_bPreview** membro `pInfo` é **FALSE** e, em seguida, defina-o como **TRUE** antes de passá-lo para `DoPreparePrinting`; redefini-lo para **FALSE** posteriormente.  
  
 Se você precisa executar inicializações que necessitam de acesso para o `CDC` substituir do objeto que representa o contexto de dispositivo de impressora (por exemplo, se você precisa saber o tamanho de página antes de especificar o tamanho do documento), o `OnBeginPrinting` membro função.  
  
 Se você deseja definir o valor da **m_nNumPreviewPages** ou **m_strPageDesc** membros a `pInfo` parâmetro, fazê-lo depois de chamar `DoPreparePrinting`. O `DoPreparePrinting` conjuntos de funções de membro **m_nNumPreviewPages** para o valor localizado do aplicativo. O arquivo INI e define **m_strPageDesc** para seu valor padrão.  
  
### <a name="example"></a>Exemplo  
  Substituir `OnPreparePrinting` e chame `DoPreparePrinting` de substituição de forma que a estrutura exibirá uma caixa de diálogo de impressão e criar uma controlador de domínio de impressora para você.  
  
 [!code-cpp[NVC_MFCDocView#184](../../mfc/codesnippet/cpp/cview-class_2.cpp)]  
  
 Se você souber o documento contém o número de páginas, definir o máximo da página `OnPreparePrinting` antes de chamar `DoPreparePrinting`. A estrutura exibirá o número máximo de página na caixa "para" da caixa de diálogo Imprimir.  
  
 [!code-cpp[NVC_MFCDocView#185](../../mfc/codesnippet/cpp/cview-class_3.cpp)]  
  
##  <a name="onprint"></a>CView::OnPrint  
 Chamado pelo framework para imprimir ou visualizar uma página do documento.  
  
```  
virtual void OnPrint(
    CDC* pDC,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo de impressora.  
  
 `pInfo`  
 Aponta para um `CPrintInfo` estrutura que descreve o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 Para cada página seja impressa, o framework chama esta função imediatamente depois de chamar o [OnPrepareDC](#onpreparedc) função de membro. A página seja impressa é especificada pelo `m_nCurPage` membro o [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) estrutura que `pInfo` aponta para. A implementação padrão chama o [OnDraw](#ondraw) função de membro e passa o contexto de dispositivo de impressora.  
  
 Substitua essa função para qualquer um dos seguintes motivos:  
  
-   Para permitir a impressão de documentos de várias páginas. Processa somente a parte do documento que corresponde à página que está sendo impressa no momento. Se você estiver usando `OnDraw` para executar o processamento, você pode ajustar a origem do visor para que apenas a parte apropriada do documento será impresso.  
  
-   Para fazer com que a imagem impressa uma aparência diferente da imagem da tela (ou seja, se seu aplicativo não for WYSIWYG). Em vez de passar a impressora contexto de dispositivo `OnDraw`, use o contexto de dispositivo para processar uma imagem usando atributos não são mostrados na tela.  
  
     Se você precisar de recursos GDI para impressão não for usado para a exibição de tela, selecioná-los no contexto do dispositivo antes do desenho e desmarcá-los posteriormente. Esses recursos GDI devem ser alocados no [OnBeginPrinting](#onbeginprinting) e lançado em [OnEndPrinting](#onendprinting).  
  
-   Para implementar cabeçalhos ou rodapés de páginas. Você ainda pode usar `OnDraw` para fazer o processamento, restringindo a área de impressão nos.  
  
 Observe que o **m_rectDraw** membro o `pInfo` parâmetro descreve da área de impressão da página em unidades lógicas.  
  
 Não chame `OnPrepareDC` em sua substituição de `OnPrint`; o framework chama `OnPrepareDC` automaticamente antes de chamar `OnPrint`.  
  
### <a name="example"></a>Exemplo  
 A seguir está um esqueleto para um substituído `OnPrint` função:  
  
 [!code-cpp[NVC_MFCDocView#186](../../mfc/codesnippet/cpp/cview-class_4.cpp)]  
  
 Outro exemplo, consulte [CRichEditView::PrintInsideRect](../../mfc/reference/cricheditview-class.md#printinsiderect).  
  
##  <a name="onscroll"></a>CView::OnScroll  
 Chamado pelo framework para determinar se a rolagem é possível.  
  
```  
virtual BOOL OnScroll(
    UINT nScrollCode,  
    UINT nPos,  
    BOOL bDoScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nScrollCode`  
 Um código de barras de rolagem que indica o usuário da solicitação de rolagem. Esse parâmetro é composto de duas partes: um byte de ordem inferior, que determina o tipo de rolagem horizontal ocorrer, e um byte de ordem superior, que determina o tipo de rolagem vertical ocorrendo:  
  
- **SB_BOTTOM** rola para baixo.  
  
- **SB_LINEDOWN** Rola uma linha para baixo.  
  
- **SB_LINEUP** Rola uma linha para cima.  
  
- **SB_PAGEDOWN** Rola uma página para baixo.  
  
- **SB_PAGEUP** Rola uma página para cima.  
  
- **SB_THUMBTRACK** arrasta a caixa de rolagem à posição especificada. A posição atual é especificada em `nPos`.  
  
- **SB_TOP** rolar para cima.  
  
 `nPos`  
 Contém a posição atual da caixa de rolagem, se o código de barras de rolagem é **SB_THUMBTRACK**; caso contrário, ele não é usado. Dependendo do período inicial de rolagem, `nPos` pode ser negativo e deve ser convertido em um `int` se necessário.  
  
 `bDoScroll`  
 Determina se, na verdade, você deve fazer a ação especificada de rolagem. Se **verdadeiro,** e rolagem deve ocorrer; se **FALSE**, e a rolagem não deve ocorrer.  
  
### <a name="return-value"></a>Valor de retorno  
 Se `bDoScroll` é **TRUE** e o modo de exibição foi realmente rolado, em seguida, retornar zero; caso contrário 0. Se `bDoScroll` é **FALSE**, em seguida, retornar o valor que você poderia ter retornado se `bDoScroll` foram **TRUE**, mesmo que você, na verdade, não faça a rolagem.  
  
### <a name="remarks"></a>Comentários  
 Em um caso essa função é chamada pelo framework com `bDoScroll` definida como **TRUE** quando o modo de exibição recebe uma mensagem de barra de rolagem. Nesse caso, você deve rolar, na verdade, o modo de exibição. No caso desta função é chamada com `bDoScroll` definida como **FALSE** quando um item OLE inicialmente é arrastado para a região de rolagem automática de um destino antes de rolagem realmente ocorre. Nesse caso, você deve realmente rola o modo de exibição.  
  
##  <a name="onscrollby"></a>CView::OnScrollBy  
 Chamado pelo framework quando o usuário exibe uma área além a exibição atual do documento, arrastando um item OLE em bordas atual da exibição ou manipulando as barras de rolagem verticais ou horizontais.  
  
```  
virtual BOOL OnScrollBy(
    CSize sizeScroll,  
    BOOL bDoScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `sizeScroll`  
 O número de pixels rolado horizontalmente e verticalmente.  
  
 `bDoScroll`  
 Determina se a rolagem da exibição ocorrerá. Se **verdadeiro,** e rolagem ocorre; se **FALSE**, e a rolagem não ocorrerá.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o modo de exibição foi capaz de ser rolado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Em classes derivadas esse método verifica se a exibição é rolável na direção em que o usuário solicitado e, em seguida, atualiza a nova região, se necessário. Essa função é chamada automaticamente por [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll) para executar a solicitação real de rolagem.  
  
 A implementação padrão desse método não altera o modo de exibição, mas se não for chamado, o modo de exibição não rolará em um `CScrollView`-classe derivada.  
  
 Se a altura ou largura de documento excede 32767 pixels, rolando após 32767 falhará porque `OnScrollBy` é chamado com um inválido `sizeScroll` argumento.  
  
##  <a name="onupdate"></a>CView::OnUpdate  
 Chamado pelo framework depois que o documento do modo de exibição foi modificado; Essa função é chamada [CDocument::UpdateAllViews](../../mfc/reference/cdocument-class.md#updateallviews) e permite que o modo de exibição atualizar sua exibição para refletir essas modificações.  
  
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
 Aponta para um objeto que armazena informações sobre as modificações.  
  
### <a name="remarks"></a>Comentários  
 Ele também é chamado pela implementação padrão de [OnInitialUpdate](#oninitialupdate). A implementação padrão invalida toda a área cliente, marcá-lo para pintura quando a próxima `WM_PAINT` mensagem é recebida. Substitua essa função se desejar atualizar apenas as regiões que mapeiam para as partes de modificação do documento. Para fazer isso, você deve transmitir informações sobre as modificações usando os parâmetros de dica.  
  
 Para usar `lHint`, definir valores de Dica especial, normalmente uma máscara de bits ou um tipo enumerado, e tem o documento passa um destes valores. Para usar `pHint`, derive uma classe de dica de [CObject](../../mfc/reference/cobject-class.md) e fazer com que o documento transmitir um ponteiro para um objeto de dica; ao substituir `OnUpdate`, use o [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) a função de membro para Determine o tipo de tempo de execução do objeto de dica.  
  
 Normalmente você não deverá efetuar qualquer desenho diretamente do `OnUpdate`. Em vez disso, determinar o retângulo que descreve, nas coordenadas do dispositivo, a área que requer a atualização. passar esse retângulo para [CWnd::InvalidateRect](../../mfc/reference/cwnd-class.md#invalidaterect). Isso faz com que a pintura ocorra na próxima vez que um [WM_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) mensagem é recebida.  
  
 Se `lHint` é 0 e `pHint` é **nulo**, o documento foi enviada uma notificação de atualização genérico. Se uma exibição recebe uma notificação de atualização genérico, ou se ele não é possível decodificar as dicas, ele deve invalidar sua área cliente inteira.  
  
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
