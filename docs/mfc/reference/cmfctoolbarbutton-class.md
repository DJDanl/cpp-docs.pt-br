---
title: Classe CMFCToolBarButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolBarButton
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarButton class
ms.assetid: 8a6ecffb-86b0-4f5c-8211-a9146b463efd
caps.latest.revision: 34
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
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: 0139779cd00a514684c20b2c589d96247a532733
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctoolbarbutton-class"></a>Classe CMFCToolBarButton
Fornece a funcionalidade do botão em barras de ferramentas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarButton : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarButton::CMFCToolBarButton](#cmfctoolbarbutton)|Constrói e inicializa um objeto `CMFCToolBarButton`.|  
|`CMFCToolBarButton::~CMFCToolBarButton`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarButton::CanBeDropped](#canbedropped)|Especifica se um usuário pode posicionar um botão em um menu ou barra de ferramentas durante a personalização.|  
|[CMFCToolBarButton::CanBeStored](#canbestored)|Especifica se o botão pode ser armazenado.|  
|[CMFCToolBarButton::CanBeStretched](#canbestretched)|Especifica se um usuário pode aumentar o botão durante a personalização.|  
|[CMFCToolBarButton::CompareWith](#comparewith)|Compara essa instância com fornecidas `CMFCToolBarButton` objeto.|  
|[CMFCToolBarButton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual.|  
|[CMFCToolBarButton::CreateFromOleData](#createfromoledata)|Cria um `CMFCToolBarButton` objeto do fornecidas `COleDataObject` objeto.|  
|`CMFCToolBarButton::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCToolBarButton::EnableWindow](#enablewindow)|Habilita ou desabilita o mouse e teclado.|  
|[CMFCToolBarButton::ExportToMenuButton](#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu.|  
|[CMFCToolBarButton::GetClipboardFormat](#getclipboardformat)|Recupera o formato da área de transferência global para o aplicativo.|  
|[CMFCToolBarButton::GetHwnd](#gethwnd)|Recupera o identificador de janela que está associado com o botão da barra de ferramentas.|  
|[CMFCToolBarButton::GetImage](#getimage)|Recupera o índice da imagem do botão.|  
|[CMFCToolBarButton::GetInvalidateRect](#getinvalidaterect)|Recupera a região da área do cliente do botão que precisa ser redesenhado.|  
|[CMFCToolBarButton::GetParentWnd](#getparentwnd)|Recupera a janela pai do botão.|  
|[CMFCToolBarButton::GetProtectedCommands](#getprotectedcommands)|Recupera a lista de comandos que o usuário não é possível personalizar.|  
|[CMFCToolBarButton::GetTextSize](#gettextsize)|Recupera o tamanho do texto do botão.|  
|[CMFCToolBarButton::HasFocus](#hasfocus)|Determina se o botão tem o foco de entrada atual.|  
|[CMFCToolBarButton::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário seleciona o botão.|  
|[CMFCToolBarButton::IsDrawImage](#isdrawimage)|Determina se uma imagem é exibida no botão.|  
|[CMFCToolBarButton::IsDrawText](#isdrawtext)|Determina se um rótulo de texto é exibido no botão.|  
|[CMFCToolBarButton::IsDroppedDown](#isdroppeddown)|Determina se o botão exibe um submenu.|  
|[CMFCToolBarButton::IsEditable](#iseditable)|Determina se o botão pode ser personalizado.|  
|[CMFCToolBarButton::IsExtraSize](#isextrasize)|Determina se o botão pode ser exibido com uma borda estendida.|  
|[CMFCToolBarButton::IsFirstInGroup](#isfirstingroup)|Determina se o botão está na primeira posição no seu grupo de botões.|  
|[CMFCToolBarButton::IsHidden](#ishidden)|Determina se o botão está oculto.|  
|[CMFCToolBarButton::IsHorizontal](#ishorizontal)|Determina se o botão está localizado em uma barra horizontal.|  
|[CMFCToolBarButton::IsLastInGroup](#islastingroup)|Especifica se o botão está na última posição no seu grupo de botões.|  
|[CMFCToolBarButton::IsLocked](#islocked)|Determina se o botão estiver em uma barra de ferramentas (não personalizável) bloqueada.|  
|[CMFCToolBarButton::IsOwnerOf](#isownerof)|Determina se o botão é o proprietário de um identificador de janela fornecido.|  
|[CMFCToolBarButton::IsVisible](#isvisible)|Determina se o botão de barra de ferramentas está visível.|  
|[CMFCToolBarButton::IsWindowVisible](#iswindowvisible)|Determina se o identificador de janela subjacente do botão é visível.|  
|[CMFCToolBarButton::NotifyCommand](#notifycommand)|Especifica se o botão processa o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem.|  
|[CMFCToolBarButton::OnAddToCustomizePage](#onaddtocustomizepage)|Chamado pela estrutura quando o botão é adicionado a um **personalizar** caixa de diálogo.|  
|[CMFCToolBarButton::OnBeforeDrag](#onbeforedrag)|Especifica se o botão pode ser arrastado.|  
|[CMFCToolBarButton::OnBeforeDrop](#onbeforedrop)|Especifica se um usuário pode soltar o botão na barra de ferramentas de destino.|  
|[CMFCToolBarButton::OnCalculateSize](#oncalculatesize)|Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe.|  
|[CMFCToolBarButton::OnCancelMode](#oncancelmode)|Chamado pela estrutura para lidar com a [WM_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) mensagem.|  
|[CMFCToolBarButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.|  
|[CMFCToolBarButton::OnClick](#onclick)|Chamado pela estrutura quando o usuário clica no botão do mouse.|  
|[CMFCToolBarButton::OnClickUp](#onclickup)|Chamado pela estrutura quando o usuário libera o botão do mouse.|  
|[CMFCToolBarButton::OnContextHelp](#oncontexthelp)|Chamado pela estrutura quando a barra de ferramentas do pai manipula um `WM_HELPHITTEST` mensagem.|  
|[CMFCToolBarButton::OnCtlColor](#onctlcolor)|Chamado pela estrutura quando a barra de ferramentas do pai manipula um `WM_CTLCOLOR` mensagem.|  
|[CMFCToolBarButton::OnCustomizeMenu](#oncustomizemenu)|Permite que o botão Modificar no menu fornecido quando o aplicativo exibe um menu de atalho da barra de ferramentas do pai.|  
|[CMFCToolBarButton::OnDblClk](#ondblclk)|Chamado pela estrutura quando a barra de ferramentas do pai manipula um [WM_LBUTTONDBLCLK](http://msdn.microsoft.com/library/windows/desktop/ms645606) mensagem.|  
|[CMFCToolBarButton::OnDraw](#ondraw)|Chamado pela estrutura para desenhar o botão usando as opções e estilos especificados.|  
|[CMFCToolBarButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pela estrutura para desenhar o botão no **comandos** painel do **personalizar** caixa de diálogo.|  
|[CMFCToolBarButton::OnGetCustomToolTipText](#ongetcustomtooltiptext)|Chamado pela estrutura para recuperar o texto da dica de ferramentas personalizada para o botão.|  
|[CMFCToolBarButton::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pela estrutura quando a fonte global foi alterada.|  
|[CMFCToolBarButton::OnMove](#onmove)|Chamado pela estrutura quando move a barra de ferramentas do pai.|  
|[CMFCToolBarButton::OnShow](#onshow)|Chamado pela estrutura quando o botão ficará visível ou invisível.|  
|[CMFCToolBarButton::OnSize](#onsize)|Chamado pela estrutura quando a barra de ferramentas do pai altera seu tamanho ou posição e essa alteração exige que o botão para alterar o tamanho.|  
|[CMFCToolBarButton::OnToolHitTest](#ontoolhittest)|Chamado pela estrutura quando a barra de ferramentas do pai deve determinar se um ponto está no retângulo delimitador do botão.|  
|[CMFCToolBarButton::OnUpdateToolTip](#onupdatetooltip)|Chamado pela estrutura quando a barra de ferramentas do pai atualiza o texto de dica de ferramenta.|  
|[CMFCToolBarButton::PrepareDrag](#preparedrag)|Chamado pela estrutura quando o botão está prestes a executar uma operação de arrastar e soltar.|  
|[CMFCToolBarButton::Rect](#rect)|Recupera o retângulo delimitador do botão.|  
|[CMFCToolBarButton::ResetImageToDefault](#resetimagetodefault)|Define o valor padrão a imagem que está associada ao botão.|  
|[CMFCToolBarButton::SaveBarState](#savebarstate)|Salva o estado do botão da barra de ferramentas.|  
|[CMFCToolBarButton::Serialize](#serialize)|Lê esse objeto de um arquivo ou grava em um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|  
|[CMFCToolBarButton::SetACCData](#setaccdata)|Preenche o fornecido `CAccessibilityData` objeto com dados de acessibilidade do botão da barra de ferramentas.|  
|[CMFCToolBarButton::SetClipboardFormatName](#setclipboardformatname)|Renomeia o formato da área de transferência global.|  
|[CMFCToolBarButton::SetImage](#setimage)|Define o índice da imagem do botão.|  
|[CMFCToolBarButton::SetProtectedCommands](#setprotectedcommands)|Define a lista de comandos que o usuário não é possível personalizar.|  
|[CMFCToolBarButton::SetRadio](#setradio)|Chamado pela estrutura quando um botão muda seu estado de ativação.|  
|[CMFCToolBarButton::SetRect](#setrect)|Define o retângulo delimitador do botão.|  
|[CMFCToolBarButton::SetStyle](#setstyle)|Define o estilo do botão.|  
|[CMFCToolBarButton::SetVisible](#setvisible)|Especifica se o botão estiver visível.|  
|[CMFCToolBarButton::Show](#show)|Mostra ou oculta o botão.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarButton::m_bImage](#m_bimage)|Especifica se uma imagem é exibida no botão.|  
|[CMFCToolBarButton::m_bText](#m_btext)|Especifica se um rótulo de texto é exibido no botão.|  
|[CMFCToolBarButton::m_bTextBelow](#m_btextbelow)|Especifica se o rótulo de texto é exibido abaixo da imagem do botão.|  
|[CMFCToolBarButton::m_bUserButton](#m_buserbutton)|Especifica se o botão tem uma imagem definida pelo usuário.|  
|[CMFCToolBarButton::m_bWholeText](#m_bwholetext)|Especifica se o botão exibe o rótulo de texto completo, mesmo se não cabe no retângulo delimitador.|  
|[CMFCToolBarButton::m_bWrap](#m_bwrap)|Especifica se o botão ao lado de um separador será colocado na próxima linha.|  
|[CMFCToolBarButton::m_bWrapText](#m_bwraptext)|Especifica se os rótulos de texto de várias linhas estão habilitados.|  
|[CMFCToolBarButton::m_nID](#m_nid)|A ID de comando do botão.|  
|[CMFCToolBarButton::m_nStyle](#m_nstyle)|O estilo do botão.|  
|[CMFCToolBarButton::m_strText](#m_strtext)|O rótulo de texto do botão.|  
  
## <a name="remarks"></a>Comentários  
 Um `CMFCToolbarButton` objeto é um controle que reside em uma barra de ferramentas. Seu comportamento é semelhante a de um botão simples. Você pode atribuir uma imagem e um rótulo de texto a este objeto. Um botão de barra de ferramentas também pode ter uma ID de comando. Quando o usuário clica no botão da barra de ferramentas, a estrutura executará o comando especifica essa ID.  
  
 Normalmente, os botões da barra de ferramentas podem ser personalizados: o usuário pode arrastar botões de uma barra de ferramentas para outro, copiar, colar, excluir e editar rótulos de texto e imagens. Para impedir que o usuário Personalizando a barra de ferramentas, você pode bloquear a barra de ferramentas em uma das duas maneiras. Definir o `bLocked` sinalizador como `TRUE` quando você chama [CMFCToolBar::LoadToolBar](../../mfc/reference/cmfctoolbar-class.md#loadtoolbar), ou adicionar a ID de comando de um botão individual na lista global de comandos protegidos usando o [CMFCToolBarButton::SetProtectedCommands](#setprotectedcommands) método.  
  
 `CMFCToolBarButton`objetos de exibem imagens das coleções globais de imagens da barra de ferramentas do aplicativo. Essas coleções são mantidas pela barra de ferramentas do pai, [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md). Para obter mais informações, consulte [CMFCToolBarImages classe](../../mfc/reference/cmfctoolbarimages-class.md).  
  
 Quando o usuário clica em um botão de barra de ferramentas, sua barra de ferramentas do pai processa a mensagem de mouse e comunica as ações apropriadas para o botão. Se o botão tem uma ID válida, a barra de ferramentas do pai envia o `WM_COMMAND` mensagem para o quadro principal.  
  
 O `CMFCToolBarButton` classe é a classe base para outras classes de botão da barra de ferramentas, como [CMFCToolBarMenuButton classe](../../mfc/reference/cmfctoolbarmenubutton-class.md), [CMFCToolBarEditBoxButton classe](../../mfc/reference/cmfctoolbareditboxbutton-class.md), e [CMFCToolBarComboBoxButton classe](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar um `CMFCToolBarButton` objeto usando vários métodos na `CMFCToolBarButton` classe. O exemplo ilustra como habilitar o mouse e a entrada do teclado, configure o índice da imagem do botão, defina o retângulo delimitador do botão e o botão tornar visível. Este trecho de código é parte do [exemplo de controle guia](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_TabControl n º&1;](../../mfc/reference/codesnippet/cpp/cmfctoolbarbutton-class_1.cpp)]  
[!code-cpp[NVC_MFC_TabControl n º&2;](../../mfc/reference/codesnippet/cpp/cmfctoolbarbutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarbutton.h  
  
##  <a name="a-namecanbedroppeda--cmfctoolbarbuttoncanbedropped"></a><a name="canbedropped"></a>CMFCToolBarButton::CanBeDropped  
 Especifica se um usuário pode posicionar um botão em um menu ou barra de ferramentas durante a personalização.  
  
```  
virtual BOOL CanBeDropped(CMFCToolBar* pToolbar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pToolbar`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, um botão de barra de ferramentas pode ser ignorado em cada personalizável (ou seja, não bloqueada) barra de ferramentas.  
  
 Retorna a implementação padrão desse método `TRUE`. Substituir este método e retornar `FALSE` se você quiser impedir que o usuário reposicionamento de botão.  
  
##  <a name="a-namecanbestoreda--cmfctoolbarbuttoncanbestored"></a><a name="canbestored"></a>CMFCToolBarButton::CanBeStored  
 Determina se o botão pode ser armazenado.  
  
```  
virtual BOOL CanBeStored() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa esse método para determinar se o botão pode participar de uma operação de arrastar e soltar.  
  
 Retorna a implementação padrão `TRUE`. Substitua este método se o botão não pode ser armazenado como parte de uma operação de arrastar e soltar. Para obter mais informações sobre as operações de arrastar e soltar, consulte [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
##  <a name="a-namecanbestretcheda--cmfctoolbarbuttoncanbestretched"></a><a name="canbestretched"></a>CMFCToolBarButton::CanBeStretched  
 Especifica se um usuário pode aumentar o botão durante a personalização.  
  
```  
virtual BOOL CanBeStretched() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado pela estrutura para determinar se o botão pode ser esticado no modo de personalização.  
  
 Retorna a implementação padrão desse método `FALSE`. Substituir este método para retornar `TRUE` para um controle de largura variável, como uma caixa de combinação ou o controle deslizante.  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::SetCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#setcustomizemode).  
  
##  <a name="a-namecmfctoolbarbuttona--cmfctoolbarbuttoncmfctoolbarbutton"></a><a name="cmfctoolbarbutton"></a>CMFCToolBarButton::CMFCToolBarButton  
 Constrói e inicializa um objeto `CMFCToolBarButton`.  
  
```  
CMFCToolBarButton(
    UINT uiID,  
    int iImage,  
    LPCTSTR lpszText=NULL,  
    BOOL bUserButton=FALSE,  
    BOOL bLocked=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 A ID de comando do botão.  
  
 [in] `iImage`  
 O índice da imagem do botão na coleção de imagens.  
  
 [in] `lpszText`  
 O rótulo de texto do botão. Pode ser `NULL`.  
  
 [in] `bUserButton`  
 Um valor booleano que determina se o botão é definido pelo usuário. Se esse parâmetro for `TRUE`, o botão é definido pelo usuário. Caso contrário, a imagem do botão é carregada de um recurso.  
  
 [in] `bLocked`  
 Um valor booleano que determina se o botão pode ser personalizado. Se esse parâmetro for `TRUE`, o botão não pode ser personalizado. Caso contrário, o botão pode ser personalizado.  
  
##  <a name="a-namecomparewitha--cmfctoolbarbuttoncomparewith"></a><a name="comparewith"></a>CMFCToolBarButton::CompareWith  
 Compara essa instância com fornecidas `CMFCToolBarButton` objeto.  
  
```  
virtual BOOL CompareWith(const CMFCToolBarButton& other) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `other`  
 Referência para o objeto a ser comparado com esta instância.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto fornecido é igual ao valor dessa instância; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão determina se a ID do objeto fornecido é igual a ID de comando desta instância. Substitua este método se for necessário realizar processamento adicional para determinar se dois `CMFCToolBarButton` objetos são iguais.  
  
##  <a name="a-namecopyfroma--cmfctoolbarbuttoncopyfrom"></a><a name="copyfrom"></a>CMFCToolBarButton::CopyFrom  
 Copia as propriedades de outro botão de barra de ferramentas para o botão atual.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Uma referência para o botão de origem da qual copiar.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para copiar outro botão da barra de ferramentas para este botão de barra de ferramentas.  
  
##  <a name="a-namecreatefromoledataa--cmfctoolbarbuttoncreatefromoledata"></a><a name="createfromoledata"></a>CMFCToolBarButton::CreateFromOleData  
 Cria um `CMFCToolBarButton` objeto do fornecidas `COleDataObject` objeto.  
  
```  
static CMFCToolBarButton* __stdcall CreateFromOleData(COleDataObject* pDataObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDataObject`  
 Objeto de dados OLE de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Criado `CMFCToolBarButton` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado pelo framework para executar a transferência de dados em vários formatos. Por exemplo, o `CMFCOutlookBarPane::OnDragOver` método usa esse método para executar operações de arrastar e soltar.  
  
##  <a name="a-nameenablewindowa--cmfctoolbarbuttonenablewindow"></a><a name="enablewindow"></a>CMFCToolBarButton::EnableWindow  
 Habilita ou desabilita o mouse e teclado.  
  
```  
virtual void EnableWindow(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Definir esse parâmetro como `TRUE` para habilitar a entrada, ou `FALSE` para desabilitar a entrada.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama o `EnableWindow` função para habilitar ou desabilitar a entrada. Para obter mais informações, consulte [EnableWindow](http://msdn.microsoft.com/library/windows/desktop/ms646291) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameexporttomenubuttona--cmfctoolbarbuttonexporttomenubutton"></a><a name="exporttomenubutton"></a>CMFCToolBarButton::ExportToMenuButton  
 Copia o texto do botão da barra de ferramentas para um menu.  
  
```  
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `menuButton`  
 Uma referência para o botão de menu de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para copiar o texto de um botão da barra de ferramentas para um botão de menu. A implementação padrão copia o rótulo de texto do botão. Se o rótulo de texto estiver vazio, esse método copia o texto de dica de ferramenta do botão.  
  
 Retorna a implementação padrão desse método `TRUE`. Substitua este método se você quiser executar ações adicionais quando o framework converte um objeto que é derivado de [CMFCToolbarButton](../../mfc/reference/cmfctoolbarbutton-class.md) para um botão de menu.  
  
##  <a name="a-namegetclipboardformata--cmfctoolbarbuttongetclipboardformat"></a><a name="getclipboardformat"></a>CMFCToolBarButton::GetClipboardFormat  
 Recupera o formato da área de transferência global para o aplicativo.  
  
```  
static CLIPFORMAT __stdcall GetClipboardFormat();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Global `CLIPFORMAT` valor para o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para recuperar o formato da área de transferência para operações de transferência de dados OLE. Por exemplo, o [CMFCToolBarButton::CreateFromOleData](#createfromoledata) método usa esse método para copiar dados de um objeto fonte de dados OLE.  
  
 Esse método define global `CLIPFORMAT` na primeira vez que esse método é chamado de valor. Todas as chamadas subsequentes a este método retornam esse valor.  
  
 Para permitir operações de arrastar e soltar ocorrer entre aplicativos, chamar o [CMFCToolBarButton::SetClipboardFormatName](#setclipboardformatname) método.  
  
 Para obter mais informações sobre áreas de transferência no MFC, consulte [área de transferência](../../mfc/clipboard.md).  
  
##  <a name="a-namegethwnda--cmfctoolbarbuttongethwnd"></a><a name="gethwnd"></a>CMFCToolBarButton::GetHwnd  
 Recupera o identificador de janela que está associado com o botão da barra de ferramentas.  
  
```  
virtual HWND GetHwnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de janela que está associado com o botão da barra de ferramentas ou `NULL` se o botão de barra de ferramentas não tem nenhum identificador de janela associada.  
  
### <a name="remarks"></a>Comentários  
 Retorna a implementação padrão desse método `NULL`. Substitua este método para retornar o identificador de janela de seu controle específico.  
  
##  <a name="a-namegetimagea--cmfctoolbarbuttongetimage"></a><a name="getimage"></a>CMFCToolBarButton::GetImage  
 Recupera o índice da imagem do botão.  
  
```  
int GetImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da imagem associada a esse botão.  
  
### <a name="remarks"></a>Comentários  
 Se o botão tem uma imagem definida pelo usuário (isto é, se `bUserButton` foi `TRUE` no construtor), o índice retornado especifica uma imagem na coleção de imagens definidas pelo usuário (consulte [CMFCToolBar::GetUserImages](../../mfc/reference/cmfctoolbar-class.md#getuserimages)). Caso contrário, o índice especifica uma imagem na coleção de imagens que são carregados de um arquivo de recurso (consulte [CMFCToolBar::GetImages](../../mfc/reference/cmfctoolbar-class.md#getimages)). Para obter mais informações sobre arquivos de recursos, consulte [trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md).  
  
##  <a name="a-namegetinvalidaterecta--cmfctoolbarbuttongetinvalidaterect"></a><a name="getinvalidaterect"></a>CMFCToolBarButton::GetInvalidateRect  
 Recupera a região da área do cliente do botão que precisa ser redesenhado.  
  
```  
virtual const CRect GetInvalidateRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` objeto que especifica a região que precisa ser redesenhada.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método retorna a área inteira do cliente. Substitua este método se você quiser uma área diferente para ser redesenhado.  
  
##  <a name="a-namegetparentwnda--cmfctoolbarbuttongetparentwnd"></a><a name="getparentwnd"></a>CMFCToolBarButton::GetParentWnd  
 Recupera a janela pai do botão.  
  
```  
CWnd* GetParentWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A janela pai do botão.  
  
##  <a name="a-namegetprotectedcommandsa--cmfctoolbarbuttongetprotectedcommands"></a><a name="getprotectedcommands"></a>CMFCToolBarButton::GetProtectedCommands  
 Recupera a lista de comandos que o usuário não é possível personalizar.  
  
```  
static const CList<UINT,UINT>& GetProtectedCommands();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A lista de comandos protegidos.  
  
### <a name="remarks"></a>Comentários  
 No modo de personalização, o framework desabilita comandos de botão da barra de ferramentas que estão protegidos. O usuário não pode executar o arrastar-e-soltar e editar operações nos botões de barra de ferramentas desativado.  
  
 Use o [CMFCToolBarButton::SetProtectedCommands](#setprotectedcommands) protegido de método para definir a lista de comandos.  
  
##  <a name="a-namegettextsizea--cmfctoolbarbuttongettextsize"></a><a name="gettextsize"></a>CMFCToolBarButton::GetTextSize  
 Recupera o tamanho do texto do botão.  
  
```  
SIZE GetTextSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `SIZE` objeto que contém o tamanho, em pixels, do texto do botão.  
  
##  <a name="a-namehasfocusa--cmfctoolbarbuttonhasfocus"></a><a name="hasfocus"></a>CMFCToolBarButton::HasFocus  
 Determina se o botão tem o foco de entrada atual.  
  
```  
virtual BOOL HasFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão tiver o foco de entrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método retorna zero se o botão tiver o foco de entrada ou é uma janela filho ou descendente da janela que tem o foco de entrada. Você pode substituir essa função para personalizar esse comportamento.  
  
##  <a name="a-namehavehotbordera--cmfctoolbarbuttonhavehotborder"></a><a name="havehotborder"></a>CMFCToolBarButton::HaveHotBorder  
 Determina se uma borda do botão é exibida quando um usuário seleciona o botão.  
  
```  
virtual BOOL HaveHotBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se o botão da barra de ferramentas deve exibir sua borda quando um usuário seleciona-lo.  
  
 Retorna a implementação padrão `TRUE`. Você pode substituir esse método para personalizar esse comportamento.  
  
##  <a name="a-nameisdrawimagea--cmfctoolbarbuttonisdrawimage"></a><a name="isdrawimage"></a>CMFCToolBarButton::IsDrawImage  
 Determina se uma imagem é exibida no botão.  
  
```  
BOOL IsDrawImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma imagem é exibida no botão; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna `FALSE` se o botão de barra de ferramentas não tem nenhuma imagem associada ( [CMFCToolBarButton::GetImage](#getimage) retorna -1) ou se [CMFCToolBarButton::m_bImage](#m_bimage) é definido como `FALSE`.  
  
##  <a name="a-nameisdrawtexta--cmfctoolbarbuttonisdrawtext"></a><a name="isdrawtext"></a>CMFCToolBarButton::IsDrawText  
 Determina se um rótulo de texto é exibido no botão.  
  
```  
BOOL IsDrawText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um rótulo de texto é exibido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna `FALSE` se o botão da barra de ferramentas não tem nenhum rótulo de texto associado ( [CMFCToolBarButton::m_strText](#m_strtext) está vazia) ou [CMFCToolBarButton::m_bText](#m_btext) é definido como `FALSE`.  
  
##  <a name="a-nameisdroppeddowna--cmfctoolbarbuttonisdroppeddown"></a><a name="isdroppeddown"></a>CMFCToolBarButton::IsDroppedDown  
 Determina se o botão exibe um submenu.  
  
```  
virtual BOOL IsDroppedDown() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Retorna a implementação padrão desse método `FALSE`. Substituir este método para retornar `TRUE` se o controle exibe um submenu.  
  
##  <a name="a-nameiseditablea--cmfctoolbarbuttoniseditable"></a><a name="iseditable"></a>CMFCToolBarButton::IsEditable  
 Determina se o botão pode ser personalizado.  
  
```  
virtual BOOL IsEditable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um botão pode ser personalizado pelo usuário. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se o usuário pode personalizar o botão da barra de ferramentas usando arrastar e soltar ou editar operações.  
  
 Retorna a implementação padrão `FALSE` se a ID do botão de comando é um comando padrão (Isso pode ser determinado chamando o `IsStandardCommand` função) ou se o comando ID está na lista de comandos de protegido. Para obter mais informações sobre comandos protegidos, consulte [CMFCToolBarButton::GetProtectedCommands](#getprotectedcommands) e [CMFCToolBarButton::SetProtectedCommands](#setprotectedcommands).  
  
 Substitui esse método para personalizar seu comportamento.  
  
##  <a name="a-nameisextrasizea--cmfctoolbarbuttonisextrasize"></a><a name="isextrasize"></a>CMFCToolBarButton::IsExtraSize  
 Determina se o botão pode ser exibido com uma borda estendida.  
  
```  
virtual BOOL IsExtraSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão da barra de ferramentas pode ser exibido com uma borda estendida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Várias aparências usam tamanho extra para as bordas dos botões de barra de ferramentas (por exemplo, round botões).  
  
 Se o usuário mudar esse botão de uma barra de ferramentas para outra, a estrutura chama o [CMFCToolBarButton::OnChangeParentWnd](#onchangeparentwnd) método. O [CMFCToolBarButton::OnChangeParentWnd](#onchangeparentwnd) método define o sinalizador de tamanho extra para que a nova barra de ferramentas do pai (para obter mais informações, consulte [CMFCToolBar::IsButtonExtraSizeAvailable](../../mfc/reference/cmfctoolbar-class.md#isbuttonextrasizeavailable)).  
  
##  <a name="a-nameisfirstingroupa--cmfctoolbarbuttonisfirstingroup"></a><a name="isfirstingroup"></a>CMFCToolBarButton::IsFirstInGroup  
 Determina se o botão está na primeira posição no seu grupo de botões.  
  
```  
virtual BOOL IsFirstInGroup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão é o primeiro em seu grupo de botão; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método define uma *grupo* como um vizinho conjunto de botões são posicionados na mesma linha e são limitados por separadores ou a borda da barra de ferramentas. Esse método retorna `FALSE` se refere-se no botão da barra de ferramentas para a **personalizar** botão. Para obter mais informações sobre o **personalizar** botão, consulte [CMFCToolBar::GetCustomizeButton](../../mfc/reference/cmfctoolbar-class.md#getcustomizebutton).  
  
 Chamar o [CMFCToolBarButton::IsLastInGroup](#islastingroup) método para determinar se o botão está na última posição no seu grupo de botões.  
  
##  <a name="a-nameishiddena--cmfctoolbarbuttonishidden"></a><a name="ishidden"></a>CMFCToolBarButton::IsHidden  
 Determina se o botão está oculto.  
  
```  
BOOL IsHidden() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão estiver oculto (invisível); Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando a barra de ferramentas do pai é estendida para determinar se o botão de barra de ferramentas está visível.  
  
 Se você definir o botão seja invisível usando o [CMFCToolBarButton::SetVisible](#setvisible) método, use [CMFCToolBarButton::IsVisible](#isvisible) para determinar se o botão de barra de ferramentas está visível.  
  
 Por padrão, todos os botões da barra de ferramentas estão visíveis. Use o [CMFCToolBarButton::Show](#show) método para ocultar ou Mostrar botões da barra de ferramentas.  
  
##  <a name="a-nameishorizontala--cmfctoolbarbuttonishorizontal"></a><a name="ishorizontal"></a>CMFCToolBarButton::IsHorizontal  
 Determina se o botão está localizado em uma barra horizontal.  
  
```  
BOOL IsHorizontal() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um botão de barra de ferramentas está localizado em uma barra horizontal; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar o layout dos botões da barra de ferramentas.  
  
 Esse método retorna o `m_bHorz` membro de dados. O valor padrão da `m_bHorz` é membro de dados `TRUE`; ele é redefinido em cada chamada para o [CMFCToolBarButton::OnDraw](#ondraw) método.  
  
##  <a name="a-nameislastingroupa--cmfctoolbarbuttonislastingroup"></a><a name="islastingroup"></a>CMFCToolBarButton::IsLastInGroup  
 Especifica se o botão está na última posição no seu grupo de botões.  
  
```  
virtual BOOL IsLastInGroup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão é o último no seu grupo de botões; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método define uma *grupo* como um vizinho conjunto de botões que são posicionados na mesma linha e são limitados por separadores ou a borda da barra de ferramentas esse método retorna `FALSE` se o botão da barra de ferramentas não tem nenhuma barra de ferramentas do pai ou no botão da barra de ferramentas se refere ao **personalizar** botão. Para obter mais informações sobre o **personalizar** botão, consulte [CMFCToolBar::GetCustomizeButton](../../mfc/reference/cmfctoolbar-class.md#getcustomizebutton).  
  
 Chamar o [CMFCToolBarButton::IsFirstInGroup](#isfirstingroup) método para determinar se o botão está na primeira posição no seu grupo de botões.  
  
##  <a name="a-nameislockeda--cmfctoolbarbuttonislocked"></a><a name="islocked"></a>CMFCToolBarButton::IsLocked  
 Determina se o botão estiver em uma barra de ferramentas (não personalizável) bloqueada.  
  
```  
BOOL IsLocked() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão estiver em uma barra de ferramentas bloqueada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se o usuário pode personalizar o botão da barra de ferramentas usando arrastar e soltar ou editar operações. Defina o atributo bloqueado na barra de ferramentas pai usando o [CMFCToolBar::LoadToolBar](../../mfc/reference/cmfctoolbar-class.md#loadtoolbar) método. O framework passa o valor desse atributo para o construtor de cada botão da barra de ferramentas ( [CMFCToolbarButton](../../mfc/reference/cmfctoolbarbutton-class.md)) que ele insere a barra de ferramentas do pai.  
  
##  <a name="a-nameisownerofa--cmfctoolbarbuttonisownerof"></a><a name="isownerof"></a>CMFCToolBarButton::IsOwnerOf  
 Determina se o botão é o proprietário de um identificador de janela fornecido.  
  
```  
virtual BOOL IsOwnerOf(HWND hwnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hwnd`  
 Um identificador de janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão é o proprietário de um identificador de janela fornecido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna zero se `hwnd` se refere ao identificador de janela direto ou é um filho do identificador de janela que é associado ao botão. Esse método retornará 0 se `hwnd` é `NULL`.  
  
##  <a name="a-nameisvisiblea--cmfctoolbarbuttonisvisible"></a><a name="isvisible"></a>CMFCToolBarButton::IsVisible  
 Determina se o botão de barra de ferramentas está visível.  
  
```  
BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão da barra de ferramentas está visível; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode mostrar ou ocultar o botão da barra de ferramentas usando o [CMFCToolBarButton::SetVisible](#setvisible) método. Chamar o [CPane::AdjustSizeImmediate](../../mfc/reference/cpane-class.md#adjustsizeimmediate) método na barra de ferramentas pai depois de você chamar [CMFCToolBarButton::SetVisible](#setvisible) para recalcular o layout de uma barra de ferramentas do pai.  
  
##  <a name="a-nameiswindowvisiblea--cmfctoolbarbuttoniswindowvisible"></a><a name="iswindowvisible"></a>CMFCToolBarButton::IsWindowVisible  
 Determina se o identificador de janela subjacente do botão é visível.  
  
```  
virtual BOOL IsWindowVisible();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o identificador de janela subjacente do botão estiver visível; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna zero se o atributo de estilos de identificador de janela subjacente contém o `WS_VISIBLE` estilo. Esse método retorna `FALSE` se o identificador de janela subjacente do botão é `NULL`.  
  
##  <a name="a-namembimagea--cmfctoolbarbuttonmbimage"></a><a name="m_bimage"></a>CMFCToolBarButton::m_bImage  
 Especifica se uma imagem é exibida no botão.  
  
```  
BOOL m_bImage;  
```  
  
### <a name="remarks"></a>Comentários  
 Se este membro de dados é definido como `TRUE`, a estrutura exibe a imagem que está associada com o botão da barra de ferramentas; caso contrário, a estrutura não mostra a imagem. Esse membro afeta o valor de retorno de [CMFCToolBarButton::m_bImage](#m_bimage) método.  
  
##  <a name="a-namembtexta--cmfctoolbarbuttonmbtext"></a><a name="m_btext"></a>CMFCToolBarButton::m_bText  
 Especifica se um rótulo de texto é exibido no botão.  
  
```  
BOOL m_bText;  
```  
  
### <a name="remarks"></a>Comentários  
 Se este membro de dados é definido como `TRUE`, o framework exibe o rótulo de texto do botão da barra de ferramentas; caso contrário, a estrutura não exibe o rótulo de texto. Esse membro afeta o valor de retorno de [CMFCToolBarButton::m_bText](#m_btext) método.  
  
##  <a name="a-namembtextbelowa--cmfctoolbarbuttonmbtextbelow"></a><a name="m_btextbelow"></a>CMFCToolBarButton::m_bTextBelow  
 Especifica se o rótulo de texto é exibido abaixo da imagem do botão.  
  
```  
BOOL m_bTextBelow;  
```  
  
### <a name="remarks"></a>Comentários  
 Se essa variável de membro é definido como `TRUE`, o framework exibe o texto do botão abaixo da imagem. O valor padrão desse membro é `FALSE`.  
  
##  <a name="a-namembuserbuttona--cmfctoolbarbuttonmbuserbutton"></a><a name="m_buserbutton"></a>CMFCToolBarButton::m_bUserButton  
 Especifica se o botão tem uma imagem definida pelo usuário  
  
```  
BOOL m_bUserButton;  
```  
  
### <a name="remarks"></a>Comentários  
 Este membro de dados é definido como `TRUE` quando o botão tem uma imagem definidos pelo usuário associada a ele.  
  
##  <a name="a-namembwholetexta--cmfctoolbarbuttonmbwholetext"></a><a name="m_bwholetext"></a>CMFCToolBarButton::m_bWholeText  
 Especifica se o botão exibe o rótulo de texto completo, mesmo se não cabe no retângulo delimitador.  
  
```  
BOOL m_bWholeText;  
```  
  
### <a name="remarks"></a>Comentários  
 Se este membro de dados é definido como `TRUE`, o framework exibe o rótulo de texto completo aumentando o botão. Caso contrário, o framework trunca e acrescenta uma elipse ( **... **) para o rótulo de texto.  
  
##  <a name="a-namembwrapa--cmfctoolbarbuttonmbwrap"></a><a name="m_bwrap"></a>CMFCToolBarButton::m_bWrap  
 Especifica se o botão ao lado de um separador será colocado na próxima linha.  
  
```  
BOOL m_bWrap;  
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura define esse membro de dados `TRUE` quando o botão da barra de ferramentas não cabe na linha atual ou quando você especificar um layout (por exemplo, um número específico de botões da barra de ferramentas por linha).  
  
 O framework coloca esse botão na próxima linha se este membro de dados é definido como `TRUE` e a barra de ferramentas é horizontalmente encaixado ou flutuante.  
  
 O valor padrão desse membro de dados é `FALSE`.  
  
##  <a name="a-namembwraptexta--cmfctoolbarbuttonmbwraptext"></a><a name="m_bwraptext"></a>CMFCToolBarButton::m_bWrapText  
 Especifica se os rótulos de texto de várias linhas estão habilitados.  
  
```  
AFX_IMPORT_DATA static BOOL m_bWrapText;  
```  
  
### <a name="remarks"></a>Comentários  
 Se essa variável de membro estático é `TRUE`, o framework permite que todas as barras de ferramentas Exibir rótulos de texto de várias linhas em botões da barra de ferramentas.  
  
 O valor padrão desse membro de dados é `FALSE`.  
  
##  <a name="a-namemnida--cmfctoolbarbuttonmnid"></a><a name="m_nid"></a>CMFCToolBarButton::m_nID  
 A ID de comando do botão.  
  
```  
UINT m_nID;  
```  
  
### <a name="remarks"></a>Comentários  
 Uma ID de -1 indica que o botão é um separador. Todos os separadores de botão tem a `TBBS_SEPARATOR` estilo. Consulte [CMFCToolBarButton::m_nStyle](#m_nstyle) para obter mais informações sobre estilos de botão.  
  
##  <a name="a-namemnstylea--cmfctoolbarbuttonmnstyle"></a><a name="m_nstyle"></a>CMFCToolBarButton::m_nStyle  
 O estilo do botão.  
  
```  
UINT m_nStyle;  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para a lista de estilos de botão da barra de ferramentas disponíveis.  
  
##  <a name="a-namemstrtexta--cmfctoolbarbuttonmstrtext"></a><a name="m_strtext"></a>CMFCToolBarButton::m_strText  
 O rótulo de texto do botão.  
  
```  
CString m_strText;  
```  
  
### <a name="remarks"></a>Comentários  
 Este membro de dados contém o rótulo de texto do botão. O rótulo de texto pode estar vazio.  
  
##  <a name="a-namenotifycommanda--cmfctoolbarbuttonnotifycommand"></a><a name="notifycommand"></a>CMFCToolBarButton::NotifyCommand  
 Especifica se o botão processa o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem.  
  
```  
virtual BOOL NotifyCommand(int iNotifyCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iNotifyCode`  
 A mensagem de notificação que é associada ao comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele está prestes a enviar uma [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem para a janela pai.  
  
 Por padrão, esse método retornará `FALSE`. Substituir este método para retornar `TRUE` para processar o `WM_COMMAND` mensagem ou `FALSE` para indicar que a barra de ferramentas do pai deve manipular a mensagem.  
  
##  <a name="a-nameonaddtocustomizepagea--cmfctoolbarbuttononaddtocustomizepage"></a><a name="onaddtocustomizepage"></a>CMFCToolBarButton::OnAddToCustomizePage  
 Chamado pela estrutura quando o botão é adicionado a um **personalizar** caixa de diálogo.  
  
```  
virtual void OnAddToCustomizePage();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitua este método se você quiser executar alguma ação quando o botão é adicionado a um **personalizar** caixa de diálogo.  
  
##  <a name="a-nameonbeforedraga--cmfctoolbarbuttononbeforedrag"></a><a name="onbeforedrag"></a>CMFCToolBarButton::OnBeforeDrag  
 Especifica se o botão pode ser arrastado.  
  
```  
virtual BOOL OnBeforeDrag() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão pode ser arrastado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método antes do usuário começa a arrastar o botão.  
  
 Retorna a implementação padrão desse método `TRUE`. Substituir este método para retornar `FALSE` desabilitar arrastando do botão.  
  
##  <a name="a-nameonbeforedropa--cmfctoolbarbuttononbeforedrop"></a><a name="onbeforedrop"></a>CMFCToolBarButton::OnBeforeDrop  
 Especifica se um usuário pode soltar o botão na barra de ferramentas de destino.  
  
```  
virtual BOOL OnBeforeDrop(CMFCToolBar* pTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTarget`  
 O destino da operação de arrastar e soltar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão pode ser levado na barra de ferramentas de destino fornecido. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método antes do botão é solto em uma barra de ferramentas.  
  
 Retorna a implementação padrão desse método `TRUE`. Substituir este método para retornar `FALSE` para desabilitar a operação de soltar no destino especificado.  
  
##  <a name="a-nameoncalculatesizea--cmfctoolbarbuttononcalculatesize"></a><a name="oncalculatesize"></a>CMFCToolBarButton::OnCalculateSize  
 Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe.  
  
```  
virtual SIZE OnCalculateSize(
    CDC* pDC,  
    const CSize& sizeDefault,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `sizeDefault`  
 O tamanho padrão do botão.  
  
 [in] `bHorz`  
 O estado de encaixe da barra de ferramentas do pai. Esse parâmetro é `TRUE` se a barra de ferramentas está ancorada horizontalmente ou estiver flutuando, ou `FALSE` se a barra de ferramentas é encaixada verticalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `SIZE` estrutura que contém as dimensões do botão, em pixels.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar o tamanho do botão da barra de ferramentas para o contexto de dispositivo especificado e estado de encaixe.  
  
 A implementação padrão considera o estado de encaixe a barra de ferramentas, as posições de imagem e texto (o texto abaixo ou no lado direito da imagem) e os tamanhos de texto e imagem (se eles são exibidos).  
  
 Substitua este método se você desejar fornecer o tamanho de um botão não padrão (por exemplo, um botão de caixa de edição).  
  
##  <a name="a-nameoncancelmodea--cmfctoolbarbuttononcancelmode"></a><a name="oncancelmode"></a>CMFCToolBarButton::OnCancelMode  
 Chamado pela estrutura para lidar com a [WM_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) mensagem.  
  
```  
virtual void OnCancelMode();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitua este método se você quiser manipular o [WM_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) mensagem.  
  
##  <a name="a-nameonchangeparentwnda--cmfctoolbarbuttononchangeparentwnd"></a><a name="onchangeparentwnd"></a>CMFCToolBarButton::OnChangeParentWnd  
 Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 A nova janela pai.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, o botão é inserido em uma barra de ferramentas quando o usuário arrasta-o de uma barra de ferramentas para outra barra de ferramentas.  
  
 A implementação padrão desse método não fará nada.  
  
##  <a name="a-nameonclicka--cmfctoolbarbuttononclick"></a><a name="onclick"></a>CMFCToolBarButton::OnClick  
 Chamado pela estrutura quando o usuário clica no botão do mouse.  
  
```  
virtual BOOL OnClick(
    CWnd* pWnd,  
    BOOL bDelay=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 A janela pai do botão da barra de ferramentas.  
  
 [in] `bDelay`  
 `TRUE`Se a mensagem deve ser tratada com um atraso.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o usuário clica no botão da barra de ferramentas.  
  
 A implementação padrão não faz nada e retorna `FALSE`. Substitua este método para retornar um valor diferente de zero se o botão processa a mensagem de clique.  
  
##  <a name="a-nameonclickupa--cmfctoolbarbuttononclickup"></a><a name="onclickup"></a>CMFCToolBarButton::OnClickUp  
 Chamado pela estrutura quando o usuário libera o botão do mouse.  
  
```  
virtual BOOL OnClickUp();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o usuário libera o botão da barra de ferramentas.  
  
 A implementação padrão não faz nada e retorna `FALSE`. Substitua este método para retornar um valor diferente de zero se o botão processa a mensagem de clique.  
  
##  <a name="a-nameoncontexthelpa--cmfctoolbarbuttononcontexthelp"></a><a name="oncontexthelp"></a>CMFCToolBarButton::OnContextHelp  
 Chamado pela estrutura quando a barra de ferramentas do pai manipula um `WM_HELPHITTEST` mensagem.  
  
```  
virtual BOOL OnContextHelp(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 A janela pai do botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não faz nada e retorna `FALSE`. Substitua este método para retornar um valor diferente de zero se o botão processa a mensagem de Ajuda.  
  
 Para obter mais informações sobre o `WM_HELPHITTEST` de mensagens, consulte [TN028: suporte de ajuda sensível ao contexto](../../mfc/tn028-context-sensitive-help-support.md).  
  
##  <a name="a-nameonctlcolora--cmfctoolbarbuttononctlcolor"></a><a name="onctlcolor"></a>CMFCToolBarButton::OnCtlColor  
 Chamado pela estrutura quando a barra de ferramentas do pai manipula um `WM_CTLCOLOR` mensagem.  
  
```  
virtual HBRUSH OnCtlColor(
    CDC* pDC,  
    UINT nCtlColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `nCtlColor`  
 A notificação de cor específica.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o objeto brush que a estrutura usa para pintar o plano de fundo do botão.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando a barra de ferramentas do pai processa a `WM_CTLCOLOR` mensagem para um botão de barra de ferramentas que contém um controle do Windows. A estrutura não chamar este método se o botão de barra de ferramentas estiver sem janelas.  
  
 O framework chama esse método quando a estrutura da barra de ferramentas está no modo de personalização e o botão de barra de ferramentas é desbloqueado. Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::SetCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#setcustomizemode). Para obter mais informações sobre como bloquear os botões da barra de ferramentas, consulte [CMFCToolBarButton::IsLocked](#islocked).  
  
 A implementação padrão não faz nada e retorna `NULL`.  
  
##  <a name="a-nameoncustomizemenua--cmfctoolbarbuttononcustomizemenu"></a><a name="oncustomizemenu"></a>CMFCToolBarButton::OnCustomizeMenu  
 Permite que o botão Modificar no menu fornecido quando o aplicativo exibe um menu de atalho da barra de ferramentas do pai.  
  
```  
virtual BOOL OnCustomizeMenu(CMenu* pMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenu`  
 Menu para personalizar.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada e retorna `FALSE`. Substitua este método e retornar um valor diferente de zero se você quiser modificar o conteúdo do menu fornecido.  
  
##  <a name="a-nameondblclka--cmfctoolbarbuttonondblclk"></a><a name="ondblclk"></a>CMFCToolBarButton::OnDblClk  
 Chamado pela estrutura quando a barra de ferramentas do pai manipula um [WM_LBUTTONDBLCLK](http://msdn.microsoft.com/library/windows/desktop/ms645606) mensagem.  
  
```  
virtual void OnDblClk(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 -   A janela pai do botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo `CMFCToolBar::OnLButtonDblClk` método quando a barra de ferramentas do pai manipula um [WM_LBUTTONDBLCLK](http://msdn.microsoft.com/library/windows/desktop/ms645606) mensagem.  
  
 A implementação padrão desse método não fará nada.  
  
##  <a name="a-nameondrawa--cmfctoolbarbuttonondraw"></a><a name="ondraw"></a>CMFCToolBarButton::OnDraw  
 Chamado pela estrutura para desenhar o botão usando as opções e estilos especificados.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    const CRect& rect,  
    CMFCToolBarImages* pImages,  
    BOOL bHorz=TRUE,  
    BOOL bCustomizeMode=FALSE,  
    BOOL bHighlight=FALSE,  
    BOOL bDrawBorder=TRUE,  
    BOOL bGrayDisabledButtons=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `rect`  
 O retângulo delimitador do botão.  
  
 [in] `pImages`  
 A coleção de imagens da barra de ferramentas que está associada ao botão.  
  
 [in] `bHorz`  
 O estado de encaixe da barra de ferramentas do pai. Esse parâmetro é `TRUE` quando o botão está ancorado horizontalmente e `FALSE` quando o botão é encaixado verticalmente.  
  
 [in] `bCustomizeMode`  
 Especifica se a barra de ferramentas está no modo de personalização. Esse parâmetro é `TRUE` quando a barra de ferramentas estiver no modo de personalização e `FALSE` quando ela não estiver no modo de personalização.  
  
 [in] `bHighlight`  
 Especifica se o botão é realçado. Esse parâmetro é `TRUE` quando o botão é realçado e `FALSE` quando o botão não esteja realçado.  
  
 [in] `bDrawBorder`  
 Especifica se o botão deve exibir sua borda. Esse parâmetro é `TRUE` quando o botão deve exibir sua borda e `FALSE` quando o botão não deve exibir sua borda.  
  
 [in] `bGrayDisabledButtons`  
 Especifica se deseja sombrear botões desabilitados ou usar a coleção de imagens desabilitado. Esse parâmetro é `TRUE` quando botões desabilitados devem ser sombreado e `FALSE` quando este método deve usar a coleção de imagens desabilitado.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para personalizar o desenho de botão da barra de ferramentas.  
  
##  <a name="a-nameondrawoncustomizelista--cmfctoolbarbuttonondrawoncustomizelist"></a><a name="ondrawoncustomizelist"></a>CMFCToolBarButton::OnDrawOnCustomizeList  
 Chamado pela estrutura para desenhar o botão no **comandos** painel do **personalizar** caixa de diálogo.  
  
```  
virtual int OnDrawOnCustomizeList(
    CDC* pDC,  
    const CRect& rect,  
    BOOL bSelected);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `rect`  
 O retângulo delimitador do botão.  
  
 [in] `bSelected`  
 Especifica se o botão está selecionado. Se esse parâmetro for `TRUE`, o botão é selecionado. Se esse parâmetro for `FALSE`, o botão não estiver selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura, em pixels, do botão no contexto do dispositivo especificado.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela caixa de diálogo de personalização ( **comandos** guia) quando o botão está prestes a exibir próprio na caixa de listagem de desenho proprietário.  
  
 A implementação padrão desse método exibe o rótulo de imagem e texto do botão se estiverem disponíveis. Se o rótulo de texto do botão não estiver disponível, o método exibirá o texto de dica de ferramenta.  
  
 Substitui esse método para executar um desenho personalizado.  
  
##  <a name="a-nameongetcustomtooltiptexta--cmfctoolbarbuttonongetcustomtooltiptext"></a><a name="ongetcustomtooltiptext"></a>CMFCToolBarButton::OnGetCustomToolTipText  
 Chamado pela estrutura para recuperar o texto da dica de ferramentas personalizada para o botão.  
  
```  
virtual BOOL OnGetCustomToolTipText(CString& strToolTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `strToolTip`  
 Um `CString` objeto que recebe o texto da dica de ferramentas personalizada.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele exibe a dica de ferramenta do botão da barra de ferramentas. Se esse método retornar `FALSE`, a estrutura usa uma dica de ferramenta padrão.  
  
 A implementação padrão não faz nada e retorna `FALSE`. Substitua esse método e retornar um valor diferente de zero para fornecer um texto de dica de ferramentas personalizada para o botão da barra de ferramentas.  
  
##  <a name="a-nameonglobalfontschangeda--cmfctoolbarbuttononglobalfontschanged"></a><a name="onglobalfontschanged"></a>CMFCToolBarButton::OnGlobalFontsChanged  
 Chamado pela estrutura quando a fonte global foi alterada.  
  
```  
virtual void OnGlobalFontsChanged();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitua este método para atualizar a fonte que é usada para exibir o texto do botão.  
  
##  <a name="a-nameonmovea--cmfctoolbarbuttononmove"></a><a name="onmove"></a>CMFCToolBarButton::OnMove  
 Chamado pela estrutura quando move a barra de ferramentas do pai.  
  
```  
virtual void OnMove();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitua este método para reposicionar o botão quando move a barra de ferramentas do pai.  
  
##  <a name="a-nameonshowa--cmfctoolbarbuttononshow"></a><a name="onshow"></a>CMFCToolBarButton::OnShow  
 Chamado pela estrutura quando o botão ficará visível ou invisível.  
  
```  
virtual void OnShow(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Especifica se o botão estiver visível. Se esse parâmetro for `TRUE`, o botão ficará visível. Caso contrário, o botão não está visível.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitua este método para atualizar a visibilidade do botão.  
  
##  <a name="a-nameonsizea--cmfctoolbarbuttononsize"></a><a name="onsize"></a>CMFCToolBarButton::OnSize  
 Chamado pela estrutura quando a barra de ferramentas do pai altera seu tamanho ou posição e essa alteração faz com que o botão para alterar o tamanho.  
  
```  
virtual void OnSize(int iSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iSize`  
 A nova largura do botão.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitui esse método para redimensionar o botão quando altera o tamanho ou a posição da barra de ferramentas do pai.  
  
##  <a name="a-nameontoolhittesta--cmfctoolbarbuttonontoolhittest"></a><a name="ontoolhittest"></a>CMFCToolBarButton::OnToolHitTest  
 Chamado pela estrutura quando a barra de ferramentas do pai deve determinar se um ponto está no retângulo delimitador do botão.  
  
```  
virtual BOOL OnToolHitTest(
    const CWnd* pWnd,  
    TOOLINFO* pTI);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 A janela pai do botão. Pode ser `NULL`.  
  
 [in] `pTI`  
 Um `TOOLINFO` estrutura que contém informações sobre uma ferramenta em um controle de dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado de `OnMenuButtonToolHitTest` se o botão pode recuperar um ponteiro para a janela do quadro pai; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método chama um dos métodos a seguir, se a janela pai pode converter para um objeto válido do quadro:  
  
- [CMDIFrameWndEx::OnMenuButtonToolHitTest](../../mfc/reference/cmdiframewndex-class.md#onmenubuttontoolhittest)  
  
- [CFrameWndEx::OnMenuButtonToolHitTest](../../mfc/reference/cframewndex-class.md#onmenubuttontoolhittest)  
  
- [COleIPFrameWndEx::OnMenuButtonToolHitTest](../../mfc/reference/coleipframewndex-class.md#onmenubuttontoolhittest)  
  
##  <a name="a-nameonupdatetooltipa--cmfctoolbarbuttononupdatetooltip"></a><a name="onupdatetooltip"></a>CMFCToolBarButton::OnUpdateToolTip  
 Chamado pela estrutura quando a barra de ferramentas do pai atualiza o texto de dica de ferramenta.  
  
```  
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,  
    int iButtonIndex,  
    CToolTipCtrl& wndToolTip,  
    CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 A janela pai.  
  
 [in] `iButtonIndex`  
 O índice baseado em zero do botão na coleção de botão pai.  
  
 [in] `wndToolTip`  
 O controle que exibe o texto de dica de ferramenta.  
  
 [out] `str`  
 Um `CString` objeto que recebe o texto de dica de ferramenta atualizada.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não faz nada e retorna `FALSE`. Substitua este método para retornar um valor diferente de zero, se você fornecer uma cadeia de caracteres de texto de dica de ferramenta.  
  
##  <a name="a-namepreparedraga--cmfctoolbarbuttonpreparedrag"></a><a name="preparedrag"></a>CMFCToolBarButton::PrepareDrag  
 Chamado pela estrutura quando o botão está prestes a executar uma operação de arrastar e soltar.  
  
```  
virtual BOOL PrepareDrag(COleDataSource& srcItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `srcItem`  
 Um `COleDataSource` objeto que armazena informações de estado sobre a operação de arrastar e soltar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a operação for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para preparar o botão da barra de ferramentas para armazenar seu estado fornecidos `COleDataSource` objeto. Este método armazena seu estado serializando próprio em um arquivo compartilhado e, em seguida, passando esse arquivo para o [COleDataSource::CacheGlobalData](../../mfc/reference/coledatasource-class.md#cacheglobaldata) método. Para obter mais informações sobre a serialização de botão da barra de ferramentas, consulte [CMFCToolBarButton::Serialize](#serialize).  
  
 Esse método não faz nada e retorna `TRUE` se o botão não pode ser armazenado (o [CMFCToolBarButton::CanBeStored](#canbestored) método retorna `FALSE`). Retorna `FALSE` se ocorrer uma exceção durante a serialização de objeto.  
  
 Para obter mais informações sobre as operações de arrastar e soltar OLE, consulte [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
##  <a name="a-namerecta--cmfctoolbarbuttonrect"></a><a name="rect"></a>CMFCToolBarButton::Rect  
 Recupera o retângulo delimitador do botão.  
  
```  
const CRect& Rect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` objeto que contém o retângulo delimitador de um botão.  
  
##  <a name="a-nameresetimagetodefaulta--cmfctoolbarbuttonresetimagetodefault"></a><a name="resetimagetodefault"></a>CMFCToolBarButton::ResetImageToDefault  
 Define o valor padrão a imagem que está associada ao botão.  
  
```  
virtual void ResetImageToDefault();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera a imagem padrão da sua barra de ferramentas do pai usando o [CMFCToolBar::GetDefaultImage](../../mfc/reference/cmfctoolbar-class.md#getdefaultimage) método. Se o botão não tiver nenhuma imagem padrão associado, esse método define o rótulo de texto do botão de acordo com seu recurso de cadeia de caracteres usando o [CStringT::LoadString](../../atl-mfc-shared/reference/cstringt-class.md#loadstring) método. Para obter mais informações sobre os recursos de cadeia de caracteres, consulte [trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md).  
  
 Esse método não fará nada se o botão tem uma imagem definida pelo usuário.  
  
##  <a name="a-namesavebarstatea--cmfctoolbarbuttonsavebarstate"></a><a name="savebarstate"></a>CMFCToolBarButton::SaveBarState  
 Salva o estado do botão da barra de ferramentas.  
  
```  
virtual void SaveBarState();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele cria uma `CMFCToolBarButton` objeto como resultado de uma operação de arrastar e soltar.  
  
 A implementação padrão desse método não fará nada. Substitua este método para salvar o estado do botão da barra de ferramentas em uma fonte de dados externa.  
  
##  <a name="a-nameserializea--cmfctoolbarbuttonserialize"></a><a name="serialize"></a>CMFCToolBarButton::Serialize  
 Lê esse objeto de um arquivo ou grava em um arquivo morto.  
  
```  
virtual void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ar`  
 O `CArchive` objeto do qual ou para a qual serializar.  
  
### <a name="remarks"></a>Comentários  
 Esse método oferece suporte a processos de transferência de dados, como operações de arrastar e soltar ou área de transferência. Ele lê ou grava propriedades do botão, como o ID, o rótulo de texto e a ID da imagem de ou para fornecidas `CArchive` objeto.  
  
 Para obter exemplos de serialização, consulte [serialização: serializando um objeto](../../mfc/serialization-serializing-an-object.md).  
  
##  <a name="a-namesetaccdataa--cmfctoolbarbuttonsetaccdata"></a><a name="setaccdata"></a>CMFCToolBarButton::SetACCData  
 Preenche o fornecido `CAccessibilityData` objeto com dados de acessibilidade do botão da barra de ferramentas.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParent`  
 A janela pai do botão da barra de ferramentas.  
  
 [in] `data`  
 Um `CAccessibilityData` objeto que é preenchido com os dados de acessibilidade do botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Substituir este método para retornar `FALSE` se o botão da barra de ferramentas não fornece dados de acessibilidade.  
  
##  <a name="a-namesetclipboardformatnamea--cmfctoolbarbuttonsetclipboardformatname"></a><a name="setclipboardformatname"></a>CMFCToolBarButton::SetClipboardFormatName  
 Renomeia o formato da área de transferência global.  
  
```  
static void __stdcall SetClipboardFormatName(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O novo nome do formato da área de transferência global. Não pode ser `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Esse método torna possível para operações de arrastar e soltar ocorrer entre vários aplicativos. Cada aplicativo deve fornecer o mesmo nome de formato da área de transferência.  
  
 Você deve chamar esse método antes de chamar o framework [CMFCToolBarButton::GetClipboardFormat](#getclipboardformat).  
  
##  <a name="a-namesetimagea--cmfctoolbarbuttonsetimage"></a><a name="setimage"></a>CMFCToolBarButton::SetImage  
 Define o índice da imagem do botão.  
  
```  
virtual void SetImage(int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iImage`  
 O índice da imagem na coleção de imagens da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Se o botão da barra de ferramentas é um separador, `iImage` refere-se para a nova largura do botão separador.  
  
 Se `iImage` for menor que zero, este método desativa o desenho da imagem e permite que o desenho do rótulo do texto do botão.  
  
##  <a name="a-namesetprotectedcommandsa--cmfctoolbarbuttonsetprotectedcommands"></a><a name="setprotectedcommands"></a>CMFCToolBarButton::SetProtectedCommands  
 Define a lista de comandos que o usuário não é possível personalizar.  
  
```  
static void SetProtectedCommands(const CList<UINT,UINT>& lstCmds);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstCmds`  
 A lista de comandos protegidos.  
  
### <a name="remarks"></a>Comentários  
 No modo de personalização, o framework desabilita comandos de botão da barra de ferramentas que estão protegidos. O usuário não pode executar o arrastar-e-soltar e editar operações nos botões de barra de ferramentas desativado.  
  
 Use o [CMFCToolBarButton::GetProtectedCommands](#getprotectedcommands) protegido de método para recuperar a lista de comandos.  
  
##  <a name="a-namesetradioa--cmfctoolbarbuttonsetradio"></a><a name="setradio"></a>CMFCToolBarButton::SetRadio  
 Chamado pela estrutura quando um botão muda seu estado de ativação.  
  
```  
virtual void SetRadio();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método não fará nada. Substitui esse método para executar uma ação personalizada quando o botão muda seu estado de ativação.  
  
##  <a name="a-namesetrecta--cmfctoolbarbuttonsetrect"></a><a name="setrect"></a>CMFCToolBarButton::SetRect  
 Define o retângulo delimitador do botão.  
  
```  
void SetRect(const CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rect`  
 O novo retângulo delimitador do botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama o [CMFCToolBarButton::OnMove](#onmove) método depois que ele define o novo retângulo delimitador.  
  
##  <a name="a-namesetstylea--cmfctoolbarbuttonsetstyle"></a><a name="setstyle"></a>CMFCToolBarButton::SetStyle  
 Define o estilo do botão.  
  
```  
virtual void SetStyle(UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nStyle`  
 O novo estilo de botão.  
  
### <a name="remarks"></a>Comentários  
 Os conjuntos de implementação padrão de [CMFCToolBarButton::m_nStyle](#m_nstyle) membro de dados para `nStyle`. Substitua este método se você desejar executar processamento adicional para lidar com a alteração no estilo. Consulte [estilos de controle de barra de ferramentas](toolbar-control-styles.md) para obter uma lista de sinalizadores de estilo válido.  
  
##  <a name="a-namesetvisiblea--cmfctoolbarbuttonsetvisible"></a><a name="setvisible"></a>CMFCToolBarButton::SetVisible  
 Especifica se o botão estiver visível.  
  
```  
void SetVisible(BOOL bShow=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Um valor booleano que especifica se deve mostrar ou ocultar o botão. Se esse parâmetro for `TRUE`, o botão é mostrado. Se o parâmetro for `FALSE`, o botão é oculto.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para ocultar ou mostrar um botão específico. Chamar o [CPane::AdjustSizeImmediate](../../mfc/reference/cpane-class.md#adjustsizeimmediate) método depois de chamar esse método.  
  
##  <a name="a-nameshowa--cmfctoolbarbuttonshow"></a><a name="show"></a>CMFCToolBarButton::Show  
 Mostra ou oculta o botão.  
  
```  
void Show(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Um valor booleano que especifica se deve mostrar ou ocultar o botão. Se esse parâmetro for `TRUE`, o botão é mostrado. Se o parâmetro for `FALSE`, o botão é oculto.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para atualizar a visibilidade dos botões da barra de ferramentas quando suas ferramentas pai é redimensionada. O framework chama esse método com `bShow` definida como `FALSE` quando o botão não se encaixa dentro dos limites da barra de ferramentas. O framework chama esse método com `bShow` definida como `TRUE` quando depois de redimensionar o botão novamente se encaixa dentro dos limites da barra de ferramentas.  
  
 Use o [CMFCToolBarButton::SetVisible](#setvisible) método para definir a visibilidade geral do botão.  
  
 Esse método chama o [CMFCToolBarButton::OnShow](#onshow) método depois que ele atualizará o estado de visibilidade do botão.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md)

