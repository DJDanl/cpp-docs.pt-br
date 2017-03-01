---
title: Classe COccManager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COccManager
dev_langs:
- C++
helpviewer_keywords:
- custom controls [MFC], sites
- COccManager class
- CNoTrackObject class
- ActiveX control containers [C++], control site
ms.assetid: 7d47aeed-d1ab-48e3-b4cf-d429718e370a
caps.latest.revision: 20
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
ms.openlocfilehash: 14a75c491a7061d921d6c0c250c6224f4e7d2f04
ms.lasthandoff: 02/25/2017

---
# <a name="coccmanager-class"></a>Classe COccManager
Gerencia vários sites de controle personalizado. implementado por `COleControlContainer` e `COleControlSite` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COccManager : public CNoTrackObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COccManager::CreateContainer](#createcontainer)|Cria um **COleContainer** objeto.|  
|[COccManager::CreateDlgControls](#createdlgcontrols)|Cria controles ActiveX, hospedados pelo associado `COleContainer` objeto.|  
|[COccManager::CreateSite](#createsite)|Cria um objeto `COleClientSite`.|  
|[COccManager::GetDefBtnCode](#getdefbtncode)|Recupera o código do botão padrão.|  
|[COccManager::IsDialogMessage](#isdialogmessage)|Determina o destino de uma mensagem de caixa de diálogo.|  
|[COccManager::IsLabelControl](#islabelcontrol)|Determina se o controle especificado é um controle de rótulo.|  
|[COccManager::IsMatchingMnemonic](#ismatchingmnemonic)|Determina se o mnemônico atual corresponde à mnemônico do controle especificado.|  
|[COccManager::OnEvent](#onevent)|Tentativas de lidar com o evento especificado.|  
|[COccManager::PostCreateDialog](#postcreatedialog)|Libera os recursos alocados durante a criação da caixa de diálogo.|  
|[COccManager::PreCreateDialog](#precreatedialog)|Processa um modelo de caixa de diálogo para controles ActiveX.|  
|[COccManager::SetDefaultButton](#setdefaultbutton)|Alterna o estado padrão do controle especificado.|  
|[COccManager::SplitDialogTemplate](#splitdialogtemplate)|Separa os controles ActiveX existentes de controles comuns do modelo de caixa de diálogo especificada.|  
  
## <a name="remarks"></a>Comentários  
 A classe base, **CNoTrackObject**, é uma classe base não documentada (localizada em AFXTLS. H). Projetado para uso pela estrutura MFC, classes derivadas do **CNoTrackObject** classe são isentos de detecção de vazamento de memória. Não é recomendável que você derivar diretamente de **CNoTrackObject**.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CNoTrackObject`  
  
 `COccManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxocc.h  
  
##  <a name="a-namecreatecontainera--coccmanagercreatecontainer"></a><a name="createcontainer"></a>COccManager::CreateContainer  
 Chamado pela estrutura para criar um contêiner de controle.  
  
```  
virtual COleControlContainer* CreateContainer(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para o objeto de janela associado ao contêiner de site personalizadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o contêiner recém-criado; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como criar sites personalizados, consulte [COleControlContainer::AttachControlSite](../../mfc/reference/colecontrolcontainer-class.md#attachcontrolsite).  
  
##  <a name="a-namecreatedlgcontrolsa--coccmanagercreatedlgcontrols"></a><a name="createdlgcontrols"></a>COccManager::CreateDlgControls  
 Chame essa função para criar controles ActiveX especificados pelo `pOccDialogInfo` parâmetro.  
  
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
  
 `lpszResourceName`  
 O nome do recurso que está sendo criado.  
  
 `pOccDialogInfo`  
 Um ponteiro para o modelo de caixa de diálogo usado para criar o objeto de caixa de diálogo.  
  
 `lpResource`  
 Um ponteiro para um recurso.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle foi criado com êxito; Caso contrário, zero.  
  
##  <a name="a-namecreatesitea--coccmanagercreatesite"></a><a name="createsite"></a>COccManager::CreateSite  
 Chamado pela estrutura para criar um site de controle, hospedado pelo contêiner apontado por `pCtrlCont`.  
  
```  
virtual COleControlSite* CreateSite(COleControlContainer* pCtrlCont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCtrlCont`  
 Um ponteiro para o contêiner de controle hospedando o novo site do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o site de controle recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para criar um controle personalizado do site, usando seu [COleControlSite](../../mfc/reference/colecontrolsite-class.md)-classe derivada.  
  
 Cada contêiner de controle pode hospedar vários sites. Crie sites adicionais com várias chamadas para `CreateSite`.  
  
##  <a name="a-namegetdefbtncodea--coccmanagergetdefbtncode"></a><a name="getdefbtncode"></a>COccManager::GetDefBtnCode  
 Chame essa função para determinar se o controle é um botão de ação padrão.  
  
```  
static DWORD AFX_CDECL GetDefBtnCode(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 O objeto de janela que contém o controle de botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
- **DLGC_DEFPUSHBUTTON** controle é o botão padrão na caixa de diálogo.  
  
- **DLGC_UNDEFPUSHBUTTON** controle não é o botão padrão na caixa de diálogo.  
  
- **0** controle não é um botão.  
  
##  <a name="a-nameisdialogmessagea--coccmanagerisdialogmessage"></a><a name="isdialogmessage"></a>COccManager::IsDialogMessage  
 Chamado pela estrutura para determinar se uma mensagem destina-se a caixa de diálogo especificada e, se for, processa a mensagem.  
  
```  
virtual BOOL IsDialogMessage(
    CWnd* pWndDlg,  
    LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndDlg*  
 Um ponteiro para a caixa de diálogo de destino pretendido da mensagem.  
  
 `lpMsg`  
 Um ponteiro para um `MSG` estrutura que contém a mensagem a ser verificada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é processada; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão do `IsDialogMessage` é verificar se há mensagens de teclado e convertê-los em seleções para a caixa de diálogo correspondente. Por exemplo, a tecla TAB, quando pressionadas, seleciona o próximo controle ou grupo de controles.  
  
 Substitua essa função para fornecer um comportamento personalizado para mensagens enviadas para a caixa de diálogo especificada.  
  
##  <a name="a-nameislabelcontrola--coccmanagerislabelcontrol"></a><a name="islabelcontrol"></a>COccManager::IsLabelControl  
 Chame essa função para determinar se o controle especificado é um controle de rótulo.  
  
```  
static BOOL AFX_CDECL IsLabelControl(CWnd* pWnd);  
static BOOL AFX_CDECL IsLabelControl(COleControlSiteOrWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para a janela que contém o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle é um rótulo; Caso contrário, zero  
  
### <a name="remarks"></a>Comentários  
 Um controle label é aquele que atua como um rótulo para qualquer controle vem a seguir na ordem.  
  
##  <a name="a-nameismatchingmnemonica--coccmanagerismatchingmnemonic"></a><a name="ismatchingmnemonic"></a>COccManager::IsMatchingMnemonic  
 Chame essa função para determinar se o atual mnemônico corresponde que representado pelo controle.  
  
```  
static BOOL AFX_CDECL IsMatchingMnemonic(
    CWnd* pWnd,  
    LPMSG lpMsg);

 
static BOOL AFX_CDECL IsMatchingMnemonic(
    COleControlSiteOrWnd* pWnd,  
    LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para a janela que contém o controle.  
  
 `lpMsg`  
 Um ponteiro para a mensagem que contém o mnemônico para corresponder.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o mnemônico coincide com o controle; Caso contrário, zero  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameoneventa--coccmanageronevent"></a><a name="onevent"></a>COccManager::OnEvent  
 Chamado pela estrutura para manipular o evento especificado.  
  
```  
virtual BOOL OnEvent(
    CCmdTarget* pCmdTarget,  
    UINT idCtrl,  
    AFX_EVENT* pEvent,  
    AFX_CMDHANDLERINFO* pHandlerInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pCmdTarget*  
 Um ponteiro para o `CCmdTarget` tentar manipular o evento de objeto  
  
 `idCtrl`  
 A ID de recurso do controle.  
  
 `pEvent`  
 O evento sendo manipulado.  
  
 `pHandlerInfo`  
 Se não **nulo**, `OnEvent` preenche o **pTarget** e **pmf** membros a **AFX_CMDHANDLERINFO** estrutura em vez de distribuir o comando. Normalmente, esse parâmetro deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o evento foi tratado, caso contrário zero.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar o processo de manipulação de eventos padrão.  
  
##  <a name="a-nameprecreatedialoga--coccmanagerprecreatedialog"></a><a name="precreatedialog"></a>COccManager::PreCreateDialog  
 Chamado pela estrutura para processar um modelo de caixa de diálogo para controles ActiveX antes de criar a caixa de diálogo real.  
  
```  
virtual const DLGTEMPLATE* PreCreateDialog(
    _AFX_OCC_DIALOG_INFO* pOccDialogInfo,  
    const DLGTEMPLATE* pOrigTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOccDialogInfo`  
 Um **_AFX_OCC_DIALOG_INFO** estrutura que contém informações sobre o modelo de caixa de diálogo e os controles ActiveX hospedados pela caixa de diálogo.  
  
 *pOrigTemplate*  
 Um ponteiro para o modelo de caixa de diálogo a ser usado na criação de caixa de diálogo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma estrutura de modelo de caixa de diálogo usada para criar a caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão faz uma chamada para `SplitDialogTemplate`, determinando se há qualquer ActiveX controles presente e, em seguida, retorna o modelo de caixa de diálogo resultante.  
  
 Substitua essa função para personalizar o processo de criação de uma caixa de diálogo Hospedando controles ActiveX.  
  
##  <a name="a-namepostcreatedialoga--coccmanagerpostcreatedialog"></a><a name="postcreatedialog"></a>COccManager::PostCreateDialog  
 Chamado pela estrutura para liberar a memória alocada para o modelo de caixa de diálogo.  
  
```  
virtual void PostCreateDialog(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOccDialogInfo`  
 Um **_AFX_OCC_DIALOG_INFO** estrutura que contém informações sobre o modelo de caixa de diálogo e os controles ActiveX hospedados pela caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Esta memória foi alocada por uma chamada para `SplitDialogTemplate`e foi usado para todos os controles ActiveX hospedados na caixa de diálogo.  
  
 Substitua essa função para personalizar o processo de limpeza de todos os recursos usados pelo objeto de caixa de diálogo.  
  
##  <a name="a-namesetdefaultbuttona--coccmanagersetdefaultbutton"></a><a name="setdefaultbutton"></a>COccManager::SetDefaultButton  
 Chame essa função para definir o controle como o botão padrão.  
  
```  
static void AFX_CDECL SetDefaultButton(
    CWnd* pWnd,  
    BOOL bDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para a janela que contém o controle.  
  
 `bDefault`  
 Diferente de zero se o controle deve se tornar o botão padrão; Caso contrário, zero.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O controle deve ter o **OLEMISC_ACTSLIKEBUTTON** conjunto de bits de status. Para obter mais informações sobre **OLEMISC** sinalizadores, consulte o [OLEMISC](http://msdn.microsoft.com/library/windows/desktop/ms678497) tópico o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesplitdialogtemplatea--coccmanagersplitdialogtemplate"></a><a name="splitdialogtemplate"></a>COccManager::SplitDialogTemplate  
 Chamado pela estrutura para dividir os controles ActiveX em controles de caixa de diálogo comuns.  
  
```  
virtual DLGTEMPLATE* SplitDialogTemplate(
    const DLGTEMPLATE* pTemplate,  
    DLGITEMTEMPLATE** ppOleDlgItems);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTemplate`  
 Um ponteiro para o modelo de caixa de diálogo a ser examinada.  
  
 `ppOleDlgItems`  
 Uma lista de ponteiros para itens de caixa de diálogo que são controles ActiveX.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma estrutura de modelo de caixa de diálogo que contém somente os controles ActiveX não. Se os controles ActiveX não estiverem presentes, **nulo** é retornado.  
  
### <a name="remarks"></a>Comentários  
 Se todos os controles ActiveX forem encontrados, o modelo é analisado e um novo modelo, que contém somente os controles ActiveX não, é criado. Todos os controles ActiveX encontrados durante esse processo são adicionados ao `ppOleDlgItems`.  
  
 Se não houver nenhum controle ActiveX no modelo, **nulo** é retornado *.*  
  
> [!NOTE]
>  Memória alocada para o novo modelo for liberado no `PostCreateDialog` função.  
  
 Substitua essa função para personalizar esse processo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)   
 [Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)

