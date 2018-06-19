---
title: Classe CMFCToolBarDateTimeCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCToolBarDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::CanBeStretched
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::CopyFrom
- AFXTOOLBARDATETIMECTRL/CMFCToolBarButton::ExportToMenuButton
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetByCmd
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetHwnd
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetTime
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetTimeAll
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::HaveHotBorder
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::NotifyCommand
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnAddToCustomizePage
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnChangeParentWnd
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnClick
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnCtlColor
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnMove
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnShow
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnUpdateToolTip
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::SetTime
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::SetTimeAll
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarDateTimeCtrl [MFC], CMFCToolBarDateTimeCtrl
- CMFCToolBarDateTimeCtrl [MFC], CanBeStretched
- CMFCToolBarDateTimeCtrl [MFC], CopyFrom
- CMFCToolBarButton [MFC], ExportToMenuButton
- CMFCToolBarDateTimeCtrl [MFC], GetByCmd
- CMFCToolBarDateTimeCtrl [MFC], GetDateTimeCtrl
- CMFCToolBarDateTimeCtrl [MFC], GetHwnd
- CMFCToolBarDateTimeCtrl [MFC], GetTime
- CMFCToolBarDateTimeCtrl [MFC], GetTimeAll
- CMFCToolBarDateTimeCtrl [MFC], HaveHotBorder
- CMFCToolBarDateTimeCtrl [MFC], NotifyCommand
- CMFCToolBarDateTimeCtrl [MFC], OnAddToCustomizePage
- CMFCToolBarDateTimeCtrl [MFC], OnChangeParentWnd
- CMFCToolBarDateTimeCtrl [MFC], OnClick
- CMFCToolBarDateTimeCtrl [MFC], OnCtlColor
- CMFCToolBarDateTimeCtrl [MFC], OnGlobalFontsChanged
- CMFCToolBarDateTimeCtrl [MFC], OnMove
- CMFCToolBarDateTimeCtrl [MFC], OnShow
- CMFCToolBarDateTimeCtrl [MFC], OnUpdateToolTip
- CMFCToolBarDateTimeCtrl [MFC], SetTime
- CMFCToolBarDateTimeCtrl [MFC], SetTimeAll
ms.assetid: a3853cb9-8ebc-444f-a1e4-9cf905e24c18
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 340f9f698d63587b7a3812d5922d8963c87751ee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33376786"
---
# <a name="cmfctoolbardatetimectrl-class"></a>Classe CMFCToolBarDateTimeCtrl
Um botão de barra de ferramentas que contém um controle de seletor de data e hora.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarDateTimeCtrl : public CMFCToolBarButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl](#cmfctoolbardatetimectrl)|Constrói um objeto `CMFCToolBarDateTimeCtrl`.|  
|`CMFCToolBarDateTimeCtrl::~CMFCToolBarDateTimeCtrl`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarDateTimeCtrl::CanBeStretched](#canbestretched)|Especifica se um usuário pode ampliar o botão durante a personalização. (Substitui [CMFCToolBarButton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|  
|[CMFCToolBarDateTimeCtrl::CopyFrom](#copyfrom)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|  
|`CMFCToolBarDateTimeCtrl::DuplicateData`|Reservado para uso futuro.|  
|[CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu.|  
|`CMFCToolBarDateTimeCtrl::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CMFCToolBarDateTimeCtrl::GetByCmd](#getbycmd)|Recupera o primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que possui a ID de comando especificado.|  
|[CMFCToolBarDateTimeCtrl::GetDateTimeCtrl](#getdatetimectrl)|Retorna um ponteiro para o controle de seletor de data e hora.|  
|[CMFCToolBarDateTimeCtrl::GetHwnd](#gethwnd)|Recupera o identificador de janela que está associado com o botão da barra de ferramentas. (Substitui [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|  
|`CMFCToolBarDateTimeCtrl::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCToolBarDateTimeCtrl::GetTime](#gettime)|Obtém o tempo selecionado de um controle de seletor de data e hora e o coloca em um especificado [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura.|  
|[CMFCToolBarDateTimeCtrl::GetTimeAll](#gettimeall)|Retorna o tempo selecionado com o botão de controle de seletor de tempo que tem uma ID de comando especificado.|  
|[CMFCToolBarDateTimeCtrl::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário seleciona o botão. (Substitui [CMFCToolBarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|  
|[CMFCToolBarDateTimeCtrl::NotifyCommand](#notifycommand)|Especifica se o botão processa o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem. (Substitui [CMFCToolBarButton::NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|  
|[CMFCToolBarDateTimeCtrl::OnAddToCustomizePage](#onaddtocustomizepage)|Chamado pelo framework quando o botão é adicionado a um **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|  
|`CMFCToolBarDateTimeCtrl::OnCalculateSize`|Chamado pelo framework para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|  
|[CMFCToolBarDateTimeCtrl::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|  
|[CMFCToolBarDateTimeCtrl::OnClick](#onclick)|Chamado pelo framework quando o usuário clica no controle. (Substitui [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|  
|[CMFCToolBarDateTimeCtrl::OnCtlColor](#onctlcolor)|Chamado pelo framework quando a barra de ferramentas do pai manipula um `WM_CTLCOLOR` mensagem. (Substitui [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|  
|`CMFCToolBarDateTimeCtrl::OnDraw`|Chamado pelo framework para desenhar o botão usando as opções e estilos especificados. (Substitui [CMFCToolBarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|  
|`CMFCToolBarDateTimeCtrl::OnDrawOnCustomizeList`|Chamado pelo framework para desenhar o botão no **comandos** painel do **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|  
|[CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo framework quando a fonte global foi alterada. (Substitui [CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|  
|[CMFCToolBarDateTimeCtrl::OnMove](#onmove)|Chamado pelo framework quando move a barra de ferramentas do pai. (Substitui [CMFCToolBarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|  
|[CMFCToolBarDateTimeCtrl::OnShow](#onshow)|Chamado pelo framework quando o botão ficará visível ou invisível. (Substitui [CMFCToolBarButton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|  
|`CMFCToolBarDateTimeCtrl::OnSize`|Chamado pelo framework quando a barra de ferramentas do pai altera seu tamanho ou posição e essa alteração faz com que o botão Alterar o tamanho. (Substitui [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|  
|[CMFCToolBarDateTimeCtrl::OnUpdateToolTip](#onupdatetooltip)|Chamado pelo framework quando a barra de ferramentas do pai atualiza seu texto de dica de ferramenta. (Substitui [CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|  
|`CMFCToolBarDateTimeCtrl::Serialize`|Lê esse objeto de um arquivo ou grava em um arquivo (substitui [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|  
|`CMFCToolBarDateTimeCtrl::SetStyle`|Define o estilo do botão de barra de ferramentas. (Substitui [CMFCToolBarButton::SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|  
|[CMFCToolBarDateTimeCtrl::SetTime](#settime)|Define a data e hora em que o controle de seletor de tempo.|  
|[CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall)|Define a data e hora em todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificado.|  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de como usar um controle de seletor de data e hora, consulte o projeto de exemplo ToolbarDateTimePicker. Para obter informações sobre como adicionar botões de controle em barras de ferramentas, consulte [passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarDateTimeCtrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbardatetimectrl.h  
  
##  <a name="canbestretched"></a>  CMFCToolBarDateTimeCtrl::CanBeStretched  
 Especifica se um usuário pode ampliar o botão durante a personalização.  
  
```  
virtual BOOL CanBeStretched() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Este método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a estrutura não permite ao usuário para alongar um botão de barra de ferramentas durante a personalização. Este método estende a implementação da classe base ( [CMFCToolBarButton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)), permitindo que o usuário Alongar um botão de barra de ferramentas de data e hora durante a personalização.  
  
##  <a name="cmfctoolbardatetimectrl"></a>  CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl  
 Cria e inicializa um [CMFCToolBarDateTimeCtrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md) objeto.  
  
```  
CMFCToolBarDateTimeCtrl(
    UINT uiID,  
    int iImage,  
    DWORD dwStyle=0,  
    int iWidth=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 A ID do controle.  
  
 [in] `iImage`  
 O índice da imagem da barra de ferramentas `CMFCToolBarImages` objeto.  
  
 [in] `dwStyle`  
 O estilo do `CMFCToolBarDateTimeCtrlImpl` janela que é criada quando um usuário clica no botão.  
  
 [in] `iWidth`  
 A largura do controle, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Este objeto é inicializado para a data do sistema e a hora. O estilo da janela de interno `CMFCToolBarDateTimeCtrlImpl` objeto inclui o `dwStyle` parâmetro e o `WS_CHILD` e `WS_VISIBLE` estilos. Você não pode alterar esses estilos usando `CMFCToolBarDateTimeCtrl::SetStyle`. Use `SetStyle` para alterar o estilo do `CMFCToolBarDateTimeCtrl` controle.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCToolBarDateTimeCtrl` classe. Este trecho de código é parte do [exemplo de seletor de tempo de data da barra de ferramentas](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_ToolbarDateTimePicker#1](../../mfc/reference/codesnippet/cpp/cmfctoolbardatetimectrl-class_1.cpp)]  
  
##  <a name="copyfrom"></a>  CMFCToolBarDateTimeCtrl::CopyFrom  
 Copia as propriedades de outro botão da barra de ferramentas para o botão atual.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Uma referência para o botão de origem da qual copiar.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para copiar outro botão da barra de ferramentas para este botão de barra de ferramentas. `src` deve ser do tipo `CMFCToolBarDateTimeCtrl`.  
  
##  <a name="exporttomenubutton"></a>  CMFCToolBarDateTimeCtrl::ExportToMenuButton  
 Copia o texto do botão da barra de ferramentas para um menu.  
  
```  
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `menuButton`  
 Uma referência para o botão de menu de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Este método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base ( [CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)) ao carregar o recurso de cadeia de caracteres que está associado com a ID de comando do controle. Para obter mais informações sobre os recursos de cadeia de caracteres, consulte [CStringT::LoadString](../../atl-mfc-shared/reference/cstringt-class.md#loadstring).  
  
##  <a name="getbycmd"></a>  CMFCToolBarDateTimeCtrl::GetByCmd  
 Recupera o primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que possui a ID de comando especificado.  
  
```  
static CMFCToolBarDateTimeCtrl* __stdcall GetByCmd(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID do botão de comando para recuperar.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem a ID de comando especificado, ou `NULL` se nenhum `CMFCToolBarDateTimeCtrl` objetos têm a ID de comando especificado.  
  
### <a name="remarks"></a>Comentários  
 Esse método de utilitário compartilhados é usado pelos métodos como [CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall) e [CMFCToolBarDateTimeCtrl::GetTimeAll](#gettimeall) para definir ou obter a hora e data de todas as instâncias do tempo controle de seletor que têm uma ID de comando especificado.  
  
##  <a name="getdatetimectrl"></a>  CMFCToolBarDateTimeCtrl::GetDateTimeCtrl  
 Retorna um ponteiro para o controle de seletor de data e hora.  
  
```  
CDateTimeCtrl* GetDateTimeCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para controle de seletor de data e hora. ou `NULL` se o controle não existe.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCToolBarDateTimeCtrl` classe inicializa o `m_pWndDateTime` membro de dados quando você insere um `CMFCToolBarDateTimeCtrl` objeto em uma barra de ferramentas.  
  
##  <a name="gethwnd"></a>  CMFCToolBarDateTimeCtrl::GetHwnd  
 Recupera o identificador de janela que está associado com o botão da barra de ferramentas.  
  
```  
virtual HWND GetHwnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de janela que está associado com o botão de barra de ferramentas de data e hora.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui o [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd) método.  
  
##  <a name="gettime"></a>  CMFCToolBarDateTimeCtrl::GetTime  
 Obtém o tempo selecionado do controle seletor de hora e data associada e o coloca em um especificado [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura  
  
```  
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `[out] timeDest`  
 Na primeira sobrecarga, uma [COleDateTime classe](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que receberá as informações de hora do sistema. Na segunda sobrecarga, uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que receberá as informações de hora do sistema.  
  
 `[out] pTimeDest`  
 Um ponteiro para o [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura para receber as informações de hora do sistema. Não deve ser `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira sobrecarga, diferente de zero se a hora é gravada com êxito o [COleDateTime classe](../../atl-mfc-shared/reference/coledatetime-class.md) objeto; caso contrário, 0. As sobrecargas de segunda e terceira, o valor de retorno é um `DWORD` que é igual ao que foi definido no membro Dwfrag o [NMDATETIMECHANGE](http://msdn.microsoft.com/library/windows/desktop/bb761730) estrutura.  
  
### <a name="remarks"></a>Comentários  
 O método define o [NMDATETIMECHANGE](http://msdn.microsoft.com/library/windows/desktop/bb761730) estrutura dwFlags de membro para indicar se o seletor de data e hora é definido como uma data e hora. Se o valor for igual a GDT_NONE, o controle é definido como `no date` status e usa o estilo DTS_SHOWNONE. Se o valor retornado é igual a GDT_VALID, a hora do sistema com êxito é armazenada no local de destino.  
  
##  <a name="gettimeall"></a>  CMFCToolBarDateTimeCtrl::GetTimeAll  
 Retorna a hora selecionada pelo usuário com o botão de controle de seletor de tempo que tem uma ID de comando especificado.  
  
```  
static BOOL GetTimeAll(
    UINT uiCmd,  
    COleDateTime& timeDest);

static DWORD GetTimeAll(
    UINT uiCmd,  
    CTime& timeDest);

static DWORD GetTimeAll(
    UINT uiCmd,  
    LPSYSTEMTIME pTimeDest);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] uiCmd`  
 Especifica a ID de comando de. de um botão barra de ferramentas  
  
 `[out] timeDest`  
 Na primeira sobrecarga, uma [COleDateTime classe](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que receberá as informações de hora do sistema. Na segunda sobrecarga, uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que receberá as informações de hora do sistema.  
  
 `[out] pTimeDest`  
 Um ponteiro para o [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura para receber as informações de hora do sistema. Não deve ser `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a estrutura não é possível localizar um botão de barra de ferramentas que corresponde à ID de comando `uiCmd`, o valor de retorno é zero na primeira sobrecarga e GDT_NONE em outras sobrecargas. Se o botão de barra de ferramentas for encontrado, o valor de retorno é o mesmo que o valor de retorno de uma chamada para [CMFCToolBarDateTimeCtrl::GetTime](#gettime) no botão. Retorno de um valor de zero ou GDT_NONE pode ocorrer quando o botão for encontrado, o que indica que a chamada para `GetTime` não retornou uma data válida por algum outro motivo.  
  
### <a name="remarks"></a>Comentários  
 Esse método procura um botão de barra de ferramentas que tem a ID de comando especificado e chama [CMFCToolBarDateTimeCtrl::GetTime](#gettime) método em que o botão.  
  
##  <a name="havehotborder"></a>  CMFCToolBarDateTimeCtrl::HaveHotBorder  
 Determina se uma borda do botão é exibida quando um usuário seleciona o botão.  
  
```  
virtual BOOL HaveHotBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um botão exibir sua borda quando selecionada. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna um valor diferente de zero se o controle está visível.  
  
##  <a name="notifycommand"></a>  CMFCToolBarDateTimeCtrl::NotifyCommand  
 Especifica se o botão processa o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem.  
  
```  
virtual BOOL NotifyCommand(int iNotifyCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iNotifyCode`  
 A mensagem de notificação que está associada com o comando.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o botão processa o `WM_COMMAND` mensagem, ou `FALSE` para indicar que a mensagem deve ser tratada pela barra de ferramentas do pai.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele está prestes a enviar um [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem para a janela pai.  
  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)) processando o [DTN_DATETIMECHANGE](http://msdn.microsoft.com/library/windows/desktop/bb761737) notificação. Ele atualiza o status de tempo interna e atualiza a propriedade de tempo de todos os `CMFCToolBarDateTimeCtrl` objetos com a mesma ID de comando  
  
##  <a name="onaddtocustomizepage"></a>  CMFCToolBarDateTimeCtrl::OnAddToCustomizePage  
 Chamado pelo framework quando o botão é adicionado a um **personalizar** caixa de diálogo.  
  
```  
virtual void OnAddToCustomizePage();
```  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base, [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage), por copiar as propriedades da primeira data e a hora de controle em qualquer barra de ferramentas que tem a mesma ID de comando como este objeto. Esse método não fará nada se nenhuma barra de ferramentas tem um controle de data e hora que tem a mesma ID de comando como este objeto.  
  
 Para obter mais informações sobre o **personalizar** caixa de diálogo, consulte [CMFCToolBarsCustomizeDialog classe](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).  
  
##  <a name="onchangeparentwnd"></a>  CMFCToolBarDateTimeCtrl::OnChangeParentWnd  
 Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Nova janela pai.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base ( [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)) recriando interno `CMFCToolBarDateTimeCtrlImpl` objeto.  
  
##  <a name="onclick"></a>  CMFCToolBarDateTimeCtrl::OnClick  
 Chamado pelo framework quando o usuário clica no controle.  
  
```  
virtual BOOL OnClick(
    CWnd* pWnd,  
    BOOL bDelay = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Não utilizado.  
  
 [in] `bDelay`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão processa a mensagem de clique; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base, [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), retornando um valor diferente de zero se interno `CMFCToolBarDateTimeCtrlImpl` objeto está visível.  
  
##  <a name="onctlcolor"></a>  CMFCToolBarDateTimeCtrl::OnCtlColor  
 Chamado pelo framework quando a barra de ferramentas do pai manipula um `WM_CTLCOLOR` mensagem.  
  
```  
virtual HBRUSH OnCtlColor(
    CDC* pDC,  
    UINT nCtlColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `nCtlColor`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o pincel global que usa a estrutura para pintar o plano de fundo do botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base, [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor), ao definir o texto e em segundo plano cores do contexto do dispositivo fornecido ao texto global e cores de plano de fundo, respectivamente.  
  
 Para obter mais informações sobre as opções globais que estão disponíveis para seu aplicativo, consulte [estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).  
  
##  <a name="onglobalfontschanged"></a>  CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged  
 Chamado pelo framework quando a fonte global foi alterada.  
  
```  
virtual void OnGlobalFontsChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle da fonte global.  
  
 Para obter mais informações sobre as opções globais que estão disponíveis para seu aplicativo, consulte [estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).  
  
##  <a name="onmove"></a>  CMFCToolBarDateTimeCtrl::OnMove  
 Chamado pelo framework quando move a barra de ferramentas do pai.  
  
```  
virtual void OnMove();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe padrão ( [CMFCToolBarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)) ao atualizar a posição da interno `CMFCToolBarDateTimeCtrlImpl` objeto.  
  
##  <a name="onshow"></a>  CMFCToolBarDateTimeCtrl::OnShow  
 Chamado pelo framework quando o botão ficará visível ou invisível.  
  
```  
virtual void OnShow(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Especifica se o botão é visível. Se esse parâmetro for `TRUE`, o botão é visível. Caso contrário, o botão não estiver visível.  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)), exibindo o botão se `bShow` é `TRUE`. Caso contrário, esse método oculta o botão.  
  
##  <a name="onsize"></a>  CMFCToolBarDateTimeCtrl::OnSize  
 Chamado pelo framework quando a barra de ferramentas do pai altera seu tamanho ou posição e essa alteração faz com que o botão Alterar o tamanho.  
  
```  
virtual void OnSize(int iSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iSize`  
 A nova largura do botão, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe padrão ( [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize)) atualizando o tamanho e posição de interno `CMFCToolBarDateTimeCtrlImpl` objeto.  
  
##  <a name="onupdatetooltip"></a>  CMFCToolBarDateTimeCtrl::OnUpdateToolTip  
 Chamado pelo framework quando a barra de ferramentas do pai atualiza seu texto de dica de ferramenta.  
  
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
 O índice de base zero do botão na coleção de botão pai.  
  
 [in] `wndToolTip`  
 O controle que exibe o texto de dica de ferramenta.  
  
 [out] `str`  
 Um `CString` objeto que recebe o texto de dica de ferramenta atualizada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método atualiza o texto de dica de ferramenta. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)), exibindo o texto de dica de ferramenta que está associado com o botão. Se o botão não estiver encaixado horizontalmente, esse método não fará nada e retornará `FALSE`.  
  
##  <a name="settime"></a>  CMFCToolBarDateTimeCtrl::SetTime  
 Define a data e hora em que o controle de seletor de tempo.  
  
```  
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* timeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] timeNew`  
 Na primeira versão, uma referência a um [COleDateTime classe](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a hora em que o controle será definido. Na segunda versão, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora em que o controle será definido.  
  
 `[in] pTimeNew`  
 Um ponteiro para o [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a hora em que o controle será definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Define o tempo em um controle de seletor de data e hora chamando [CDateTimeCtrl::SetTime](../../mfc/reference/cdatetimectrl-class.md#settime).  
  
##  <a name="settimeall"></a>  CMFCToolBarDateTimeCtrl::SetTimeAll  
 Define a data e hora em todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificado.  
  
```  
static BOOL SetTimeAll(
    UINT uiCmd,  
    const COleDateTime& timeNew);

static BOOL SetTimeAll(
    UINT uiCmd,  
    const CTime* pTimeNew);

static BOOL SetTimeAll(
    UINT uiCmd,  
    LPSYSTEMTIME pTimeNew=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] uiCmd`  
 Especifica a ID de comando de. de um botão barra de ferramentas  
  
 `[in] timeNew`  
 Na primeira versão, uma [COleDateTime classe](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a hora em que o controle será definido. Na segunda versão, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora em que o controle será definido.  
  
 `[in] pTimeNew`  
 Um ponteiro para o [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a hora em que o controle será definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Procura um botão de barra de ferramentas com a ID de comando especificado e define o tempo em um controle de seletor de data e hora chamando [CMFCToolBarDateTimeCtrl::SetTime](#settime).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)



