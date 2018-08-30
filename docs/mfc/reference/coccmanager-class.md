---
title: Classe COccManager | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COccManager
- AFXOCC/COccManager
- AFXOCC/COccManager::CreateContainer
- AFXOCC/COccManager::CreateDlgControls
- AFXOCC/COccManager::CreateSite
- AFXOCC/COccManager::GetDefBtnCode
- AFXOCC/COccManager::IsDialogMessage
- AFXOCC/COccManager::IsLabelControl
- AFXOCC/COccManager::IsMatchingMnemonic
- AFXOCC/COccManager::OnEvent
- AFXOCC/COccManager::PostCreateDialog
- AFXOCC/COccManager::PreCreateDialog
- AFXOCC/COccManager::SetDefaultButton
- AFXOCC/COccManager::SplitDialogTemplate
dev_langs:
- C++
helpviewer_keywords:
- COccManager [MFC], CreateContainer
- COccManager [MFC], CreateDlgControls
- COccManager [MFC], CreateSite
- COccManager [MFC], GetDefBtnCode
- COccManager [MFC], IsDialogMessage
- COccManager [MFC], IsLabelControl
- COccManager [MFC], IsMatchingMnemonic
- COccManager [MFC], OnEvent
- COccManager [MFC], PostCreateDialog
- COccManager [MFC], PreCreateDialog
- COccManager [MFC], SetDefaultButton
- COccManager [MFC], SplitDialogTemplate
ms.assetid: 7d47aeed-d1ab-48e3-b4cf-d429718e370a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 627fb8e1ad1341257e3064ee195952c37dd4a481
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43195532"
---
# <a name="coccmanager-class"></a>Classe COccManager
Gerencia vários sites de controle personalizado; implementado pelo `COleControlContainer` e `COleControlSite` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COccManager : public CNoTrackObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COccManager::CreateContainer](#createcontainer)|Cria um objeto `COleContainer`.|  
|[COccManager::CreateDlgControls](#createdlgcontrols)|Cria os controles ActiveX, hospedados pelo associado `COleContainer` objeto.|  
|[COccManager::CreateSite](#createsite)|Cria um objeto `COleClientSite`.|  
|[COccManager::GetDefBtnCode](#getdefbtncode)|Recupera o código do botão padrão.|  
|[COccManager::IsDialogMessage](#isdialogmessage)|Determina o destino de uma mensagem de caixa de diálogo.|  
|[COccManager::IsLabelControl](#islabelcontrol)|Determina se o controle especificado é um controle de rótulo.|  
|[COccManager::IsMatchingMnemonic](#ismatchingmnemonic)|Determina se o mnemônico atual coincide com o mnemônico do controle especificado.|  
|[COccManager::OnEvent](#onevent)|Tenta manipular o evento especificado.|  
|[COccManager::PostCreateDialog](#postcreatedialog)|Libera os recursos alocados durante a criação da caixa de diálogo.|  
|[COccManager::PreCreateDialog](#precreatedialog)|Processa um modelo de caixa de diálogo para controles ActiveX.|  
|[COccManager::SetDefaultButton](#setdefaultbutton)|Alterna o estado padrão do controle especificado.|  
|[COccManager::SplitDialogTemplate](#splitdialogtemplate)|Separa os controles ActiveX existentes dos controles comuns no modelo de caixa de diálogo especificada.|  
  
## <a name="remarks"></a>Comentários  
 A classe base, `CNoTrackObject`, é uma classe base não documentada (localizada em AFXTLS. H). Projetado para uso pela estrutura MFC, as classes derivadas de `CNoTrackObject` classe estão isentos da detecção de vazamento de memória. Não é recomendável que você deriva diretamente de `CNoTrackObject`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CNoTrackObject`  
  
 `COccManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxocc.h  
  
##  <a name="createcontainer"></a>  COccManager::CreateContainer  
 Chamado pelo framework para criar um contêiner de controle.  
  
```  
virtual COleControlContainer* CreateContainer(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Um ponteiro para o objeto de janela associado com o contêiner de site personalizadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o contêiner recém-criado; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como criar sites personalizados, consulte [COleControlContainer::AttachControlSite](../../mfc/reference/colecontrolcontainer-class.md#attachcontrolsite).  
  
##  <a name="createdlgcontrols"></a>  COccManager::CreateDlgControls  
 Chame essa função para criar controles ActiveX especificados pelo *pOccDialogInfo* parâmetro.  
  
```  
virtual BOOL CreateDlgControls(
    CWnd* pWndParent,  
    LPCTSTR lpszResourceName,  
    _AFX_OCC_DIALOG_INFO* pOccDialogInfo);

 
virtual BOOL CreateDlgControls(
    CWnd* pWndParent,  
    void* lpResource,  
    _AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndParent*  
 Um ponteiro para o pai do objeto de caixa de diálogo.  
  
 *lpszResourceName*  
 O nome do recurso que está sendo criado.  
  
 *pOccDialogInfo*  
 Um ponteiro para o modelo de caixa de diálogo usado para criar o objeto de caixa de diálogo.  
  
 *lpResource*  
 Um ponteiro para um recurso.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle foi criado com êxito; Caso contrário, zero.  
  
##  <a name="createsite"></a>  COccManager::CreateSite  
 Chamado pelo framework para criar um site do controle hospedado pelo contêiner apontado por *pCtrlCont*.  
  
```  
virtual COleControlSite* CreateSite(COleControlContainer* pCtrlCont);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pCtrlCont*  
 Um ponteiro para o novo site de controle de hospedagem de contêineres de controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o site de controle recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para criar um controle personalizado do site, usando seu [COleControlSite](../../mfc/reference/colecontrolsite-class.md)-classe derivada.  
  
 Cada contêiner de controle pode hospedar vários sites. Crie sites adicionais com várias chamadas para `CreateSite`.  
  
##  <a name="getdefbtncode"></a>  COccManager::GetDefBtnCode  
 Chame essa função para determinar se o controle é um botão de ação padrão.  
  
```  
static DWORD AFX_CDECL GetDefBtnCode(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 O objeto de janela que contém o controle de botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
- Controle de DLGC_DEFPUSHBUTTON é o botão padrão na caixa de diálogo.  
  
- Controle de DLGC_UNDEFPUSHBUTTON não é o botão padrão na caixa de diálogo.  
  
- **0** controle não é um botão.  
  
##  <a name="isdialogmessage"></a>  COccManager::IsDialogMessage  
 Chamado pelo framework para determinar se uma mensagem destina-se a caixa de diálogo especificado e, se for, processa a mensagem.  
  
```  
virtual BOOL IsDialogMessage(
    CWnd* pWndDlg,  
    LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndDlg*  
 Um ponteiro para a caixa de diálogo de destino pretendido da mensagem.  
  
 *lpMsg*  
 Um ponteiro para um `MSG` estrutura que contém a mensagem a ser verificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é processada; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão do `IsDialogMessage` é verificar se há mensagens de teclado e convertê-los em seleções para a caixa de diálogo correspondente. Por exemplo, a tecla TAB, quando pressionadas, seleciona o próximo controle ou grupo de controles.  
  
 Substitua essa função para fornecer um comportamento personalizado para mensagens enviadas para a caixa de diálogo especificada.  
  
##  <a name="islabelcontrol"></a>  COccManager::IsLabelControl  
 Chame essa função para determinar se o controle especificado é um controle de rótulo.  
  
```  
static BOOL AFX_CDECL IsLabelControl(CWnd* pWnd);  
static BOOL AFX_CDECL IsLabelControl(COleControlSiteOrWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Um ponteiro para a janela que contém o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle for um rótulo; Caso contrário, zero  
  
### <a name="remarks"></a>Comentários  
 Um controle de rótulo é aquele que age como um rótulo para qualquer controle vem a seguir na ordenação.  
  
##  <a name="ismatchingmnemonic"></a>  COccManager::IsMatchingMnemonic  
 Chame essa função para determinar se o mnemônico atual corresponde ao que é representado pelo controle.  
  
```  
static BOOL AFX_CDECL IsMatchingMnemonic(
    CWnd* pWnd,  
    LPMSG lpMsg);

 
static BOOL AFX_CDECL IsMatchingMnemonic(
    COleControlSiteOrWnd* pWnd,  
    LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Um ponteiro para a janela que contém o controle.  
  
 *lpMsg*  
 Um ponteiro para a mensagem que contém o mnemônico deverá corresponder.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o mnemônico corresponde ao controle; Caso contrário, zero  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onevent"></a>  COccManager::OnEvent  
 Chamado pelo framework para manipular o evento especificado.  
  
```  
virtual BOOL OnEvent(
    CCmdTarget* pCmdTarget,  
    UINT idCtrl,  
    AFX_EVENT* pEvent,  
    AFX_CMDHANDLERINFO* pHandlerInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pCmdTarget*  
 Um ponteiro para o `CCmdTarget` tentar tratar o evento de objeto  
  
 *idCtrl*  
 A ID de recurso do controle.  
  
 *pEvent*  
 O evento que está sendo manipulado.  
  
 *pHandlerInfo*  
 Se não for NULL, `OnEvent` preenche o `pTarget` e `pmf` membros o `AFX_CMDHANDLERINFO` estrutura em vez de expedir o comando. Normalmente, esse parâmetro deve ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o evento foi manipulado, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar o processo de manipulação de eventos padrão.  
  
##  <a name="precreatedialog"></a>  COccManager::PreCreateDialog  
 Chamado pelo framework para processar um modelo de caixa de diálogo para controles ActiveX antes de criar a caixa de diálogo real.  
  
```  
virtual const DLGTEMPLATE* PreCreateDialog(
    _AFX_OCC_DIALOG_INFO* pOccDialogInfo,  
    const DLGTEMPLATE* pOrigTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pOccDialogInfo*  
 Um `_AFX_OCC_DIALOG_INFO` estrutura que contém informações sobre o modelo de caixa de diálogo e todos os controles ActiveX hospedados pela caixa de diálogo.  
  
 *pOrigTemplate*  
 Um ponteiro para o modelo de caixa de diálogo a ser usado na criação de caixa de diálogo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma estrutura de modelo de caixa de diálogo usada para criar a caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão faz uma chamada para `SplitDialogTemplate`, determinando se há qualquer ActiveX controles presente e, em seguida, retorna o modelo de caixa de diálogo resultante.  
  
 Substitua essa função para personalizar o processo de criação de uma caixa de diálogo Hospedando controles ActiveX.  
  
##  <a name="postcreatedialog"></a>  COccManager::PostCreateDialog  
 Chamado pelo framework para liberar a memória alocada para o modelo de caixa de diálogo.  
  
```  
virtual void PostCreateDialog(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pOccDialogInfo*  
 Um `_AFX_OCC_DIALOG_INFO` estrutura que contém informações sobre o modelo de caixa de diálogo e todos os controles ActiveX hospedados pela caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Esta memória foi alocado por uma chamada para `SplitDialogTemplate`e foi usado para todos os controles ActiveX hospedados na caixa de diálogo.  
  
 Substitua essa função para personalizar o processo de limpeza de todos os recursos usados pelo objeto de caixa de diálogo.  
  
##  <a name="setdefaultbutton"></a>  COccManager::SetDefaultButton  
 Chame essa função para definir o controle como o botão padrão.  
  
```  
static void AFX_CDECL SetDefaultButton(
    CWnd* pWnd,  
    BOOL bDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Um ponteiro para a janela que contém o controle.  
  
 *bNível padrão*  
 Diferente de zero se o controle deve se tornar o botão padrão; Caso contrário, zero.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O controle deve ter o conjunto de bits de status OLEMISC_ACTSLIKEBUTTON. Para obter mais informações sobre sinalizadores OLEMISC, consulte o [OLEMISC](/windows/desktop/api/oleidl/ne-oleidl-tagolemisc) tópico no SDK do Windows.  
  
##  <a name="splitdialogtemplate"></a>  COccManager::SplitDialogTemplate  
 Chamado pelo framework para dividir os controles ActiveX em controles de caixa de diálogo comuns.  
  
```  
virtual DLGTEMPLATE* SplitDialogTemplate(
    const DLGTEMPLATE* pTemplate,  
    DLGITEMTEMPLATE** ppOleDlgItems);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTemplate*  
 Um ponteiro para o modelo de caixa de diálogo a ser examinado.  
  
 *ppOleDlgItems*  
 Uma lista de ponteiros para os itens de caixa de diálogo que são controles ActiveX.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma estrutura de modelo de caixa de diálogo que contém somente os controles não ActiveX. Se nenhum controle ActiveX estiverem presente, NULL será retornado.  
  
### <a name="remarks"></a>Comentários  
 Se todos os controles ActiveX são encontrados, o modelo é analisado e um novo modelo, que contém somente controles não-ActiveX, é criado. Todos os controles ActiveX encontrados durante esse processo são adicionados ao *ppOleDlgItems*.  
  
 Se não houver nenhum controle ActiveX no modelo, NULL será retornado *.*  
  
> [!NOTE]
>  Memória alocada para o novo modelo é liberado no `PostCreateDialog` função.  
  
 Substitua essa função para personalizar esse processo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)   
 [Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
