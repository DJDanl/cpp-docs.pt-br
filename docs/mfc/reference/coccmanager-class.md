---
title: Classe COccManager
ms.date: 11/04/2016
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
ms.openlocfilehash: 5637a4709e90bb14caff3fe4e396487e62e213e1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360358"
---
# <a name="coccmanager-class"></a>Classe COccManager

Gerencia vários sites de controle personalizados; implementado `COleControlContainer` por `COleControlSite` e objetos.

## <a name="syntax"></a>Sintaxe

```
class COccManager : public CNoTrackObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COccManager::CreateContainer](#createcontainer)|Cria um objeto `COleContainer`.|
|[COccManager::CreateDlgControls](#createdlgcontrols)|Cria controles ActiveX, hospedados `COleContainer` pelo objeto associado.|
|[COccManager::CreateSite](#createsite)|Cria um objeto `COleClientSite`.|
|[COccManager::GetDefBtnCode](#getdefbtncode)|Recupera o código do botão padrão.|
|[COccManager::IsDialogMessage](#isdialogmessage)|Determina o alvo de uma mensagem de diálogo.|
|[COccManager::IsLabelControl](#islabelcontrol)|Determina se o controle especificado é um controle de rótulo.|
|[COccManager::IsMatchingMnemonic](#ismatchingmnemonic)|Determina se o mnemônico atual corresponde ao mnemônico do controle especificado.|
|[COccManager::OnEvent](#onevent)|Tentativas de lidar com o evento especificado.|
|[COccManager::PostCreateDialog](#postcreatedialog)|Libera recursos alocados durante a criação do diálogo.|
|[COccManager::PreCriarDiálogo](#precreatedialog)|Processa um modelo de diálogo para controles ActiveX.|
|[COccManager::SetDefaultButton](#setdefaultbutton)|Alterna o estado padrão do controle especificado.|
|[COccManager::SplitDialogTemplate](#splitdialogtemplate)|Separa todos os controles ActiveX existentes dos controles comuns no modelo de diálogo especificado.|

## <a name="remarks"></a>Comentários

A classe `CNoTrackObject`base, é uma classe base não documentada (localizada em AFXTLS. H). Projetadas para uso pela estrutura MFC, `CNoTrackObject` as classes derivadas da classe estão isentas da detecção de vazamento de memória. Não é recomendável que você `CNoTrackObject`deriva diretamente de .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CNoTrackObject`

`COccManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxocc.h

## <a name="coccmanagercreatecontainer"></a><a name="createcontainer"></a>COccManager::CreateContainer

Chamado pela estrutura para criar um recipiente de controle.

```
virtual COleControlContainer* CreateContainer(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para o objeto da janela associado ao contêiner do site personalizado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o recipiente recém-criado; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a criação de sites personalizados, consulte [COleControlContainer::AttachControlSite](../../mfc/reference/colecontrolcontainer-class.md#attachcontrolsite).

## <a name="coccmanagercreatedlgcontrols"></a><a name="createdlgcontrols"></a>COccManager::CreateDlgControls

Chame esta função para criar controles ActiveX especificados pelo parâmetro *pOccDialogInfo.*

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

*pWndParent*<br/>
Um ponteiro para o pai do objeto de diálogo.

*Lpszresourcename*<br/>
O nome do recurso que está sendo criado.

*pOccDialogInfo*<br/>
Um ponteiro para o modelo de diálogo usado para criar o objeto de diálogo.

*lpResource*<br/>
Um ponteiro para um recurso.

### <a name="return-value"></a>Valor retornado

Não zero se o controle foi criado com sucesso; caso contrário, zero.

## <a name="coccmanagercreatesite"></a><a name="createsite"></a>COccManager::CreateSite

Chamado pela estrutura para criar um local de controle, hospedado pelo contêiner apontado por *pCtrlCont*.

```
virtual COleControlSite* CreateSite(COleControlContainer* pCtrlCont);
```

### <a name="parameters"></a>Parâmetros

*pCtrlCont*<br/>
Um ponteiro para o contêiner de controle que hospeda o novo local de controle.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o site de controle recém-criado.

### <a name="remarks"></a>Comentários

Substituir essa função para criar um site de controle personalizado, usando sua classe derivada do [COleControlSite.](../../mfc/reference/colecontrolsite-class.md)

Cada contêiner de controle pode hospedar vários locais. Crie sites adicionais `CreateSite`com várias chamadas para .

## <a name="coccmanagergetdefbtncode"></a><a name="getdefbtncode"></a>COccManager::GetDefBtnCode

Ligue para esta função para determinar se o controle é um botão padrão.

```
static DWORD AFX_CDECL GetDefBtnCode(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
O objeto da janela que contém o controle do botão.

### <a name="return-value"></a>Valor retornado

Um dos seguintes valores:

- DLGC_DEFPUSHBUTTON Control é o botão padrão na caixa de diálogo.

- DLGC_UNDEFPUSHBUTTON Control não é o botão padrão na caixa de diálogo.

- **0** O controle não é um botão.

## <a name="coccmanagerisdialogmessage"></a><a name="isdialogmessage"></a>COccManager::IsDialogMessage

Chamado pela estrutura para determinar se uma mensagem é destinada à caixa de diálogo especificada e, se for, processa a mensagem.

```
virtual BOOL IsDialogMessage(
    CWnd* pWndDlg,
    LPMSG lpMsg);
```

### <a name="parameters"></a>Parâmetros

*pWndDlg*<br/>
Um ponteiro para a caixa de diálogo de destino pretendida da mensagem.

*Lpmsg*<br/>
Um ponteiro `MSG` para uma estrutura que contém a mensagem a ser verificada.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem for processada; caso contrário, zero.

### <a name="remarks"></a>Comentários

O comportamento `IsDialogMessage` padrão é verificar as mensagens do teclado e convertê-las em seleções para a caixa de diálogo correspondente. Por exemplo, a tecla TAB, quando pressionada, seleciona o próximo controle ou grupo de controles.

Substituir essa função para fornecer comportamento personalizado para mensagens enviadas para a caixa de diálogo especificada.

## <a name="coccmanagerislabelcontrol"></a><a name="islabelcontrol"></a>COccManager::IsLabelControl

Ligue para esta função para determinar se o controle especificado é um controle de rótulo.

```
static BOOL AFX_CDECL IsLabelControl(CWnd* pWnd);
static BOOL AFX_CDECL IsLabelControl(COleControlSiteOrWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para a janela contendo o controle.

### <a name="return-value"></a>Valor retornado

Não zero se o controle for uma etiqueta; caso contrário, zero

### <a name="remarks"></a>Comentários

Um controle de rótulo é aquele que age como um rótulo para qualquer controle que esteja próximo na encomenda.

## <a name="coccmanagerismatchingmnemonic"></a><a name="ismatchingmnemonic"></a>COccManager::IsMatchingMnemonic

Chame esta função para determinar se o mnemônico atual corresponde ao representado pelo controle.

```
static BOOL AFX_CDECL IsMatchingMnemonic(
    CWnd* pWnd,
    LPMSG lpMsg);

static BOOL AFX_CDECL IsMatchingMnemonic(
    COleControlSiteOrWnd* pWnd,
    LPMSG lpMsg);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para a janela contendo o controle.

*Lpmsg*<br/>
Um ponteiro para a mensagem contendo o mnemônico para combinar.

### <a name="return-value"></a>Valor retornado

Não zero se o mnemônico corresponder ao controle; caso contrário, zero

### <a name="remarks"></a>Comentários

## <a name="coccmanageronevent"></a><a name="onevent"></a>COccManager::OnEvent

Chamado pela estrutura para lidar com o evento especificado.

```
virtual BOOL OnEvent(
    CCmdTarget* pCmdTarget,
    UINT idCtrl,
    AFX_EVENT* pEvent,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>Parâmetros

*pCmdTarget*<br/>
Um ponteiro `CCmdTarget` para o objeto que tenta lidar com o evento

*idCtrl*<br/>
A id de recursos do controle.

*pEvent*<br/>
O evento está sendo tratado.

*pHandlerInfo*<br/>
Se não `OnEvent` NULA, `pTarget` preenche `pmf` os `AFX_CMDHANDLERINFO` membros da estrutura em vez de despachar o comando. Normalmente, este parâmetro deve ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se o evento foi tratado, caso contrário zero.

### <a name="remarks"></a>Comentários

Substituir esta função para personalizar o processo padrão de manipulação de eventos.

## <a name="coccmanagerprecreatedialog"></a><a name="precreatedialog"></a>COccManager::PreCriarDiálogo

Chamado pela estrutura para processar um modelo de diálogo para controles ActiveX antes de criar a caixa de diálogo real.

```
virtual const DLGTEMPLATE* PreCreateDialog(
    _AFX_OCC_DIALOG_INFO* pOccDialogInfo,
    const DLGTEMPLATE* pOrigTemplate);
```

### <a name="parameters"></a>Parâmetros

*pOccDialogInfo*<br/>
Uma `_AFX_OCC_DIALOG_INFO` estrutura contendo informações sobre o modelo de diálogo e quaisquer controles ActiveX hospedados pela caixa de diálogo.

*modelo pOrig*<br/>
Um ponteiro para o modelo de diálogo a ser usado na criação da caixa de diálogo.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de modelo de diálogo usado para criar a caixa de diálogo.

### <a name="remarks"></a>Comentários

O comportamento padrão faz `SplitDialogTemplate`uma chamada para determinar se há algum controle ActiveX presente e, em seguida, retorna o modelo de diálogo resultante.

Substituir essa função para personalizar o processo de criação de uma caixa de diálogo que hospeda controles ActiveX.

## <a name="coccmanagerpostcreatedialog"></a><a name="postcreatedialog"></a>COccManager::PostCreateDialog

Chamado pelo framework para liberar memória alocada para o modelo de diálogo.

```
virtual void PostCreateDialog(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```

### <a name="parameters"></a>Parâmetros

*pOccDialogInfo*<br/>
Uma `_AFX_OCC_DIALOG_INFO` estrutura contendo informações sobre o modelo de diálogo e quaisquer controles ActiveX hospedados pela caixa de diálogo.

### <a name="remarks"></a>Comentários

Esta memória foi alocada `SplitDialogTemplate`por uma chamada para , e foi usada para quaisquer controles ActiveX hospedados na caixa de diálogo.

Substituir esta função para personalizar o processo de limpeza de todos os recursos usados pelo objeto caixa de diálogo.

## <a name="coccmanagersetdefaultbutton"></a><a name="setdefaultbutton"></a>COccManager::SetDefaultButton

Chame esta função para definir o controle como o botão padrão.

```
static void AFX_CDECL SetDefaultButton(
    CWnd* pWnd,
    BOOL bDefault);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para a janela contendo o controle.

*bDefault*<br/>
Não zero se o controle se tornar o botão padrão; caso contrário, zero.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
> O controle deve ter o OLEMISC_ACTSLIKEBUTTON bit de status definido. Para obter mais informações sobre os sinalizadores OLEMISC, consulte o tópico [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) no SDK do Windows.

## <a name="coccmanagersplitdialogtemplate"></a><a name="splitdialogtemplate"></a>COccManager::SplitDialogTemplate

Chamado pela estrutura para dividir os controles ActiveX dos controles comuns de diálogo.

```
virtual DLGTEMPLATE* SplitDialogTemplate(
    const DLGTEMPLATE* pTemplate,
    DLGITEMTEMPLATE** ppOleDlgItems);
```

### <a name="parameters"></a>Parâmetros

*pTemplate*<br/>
Um ponteiro para o modelo de diálogo a ser examinado.

*ppOleDlgItems*<br/>
Uma lista de ponteiros para itens da caixa de diálogo que são controles ActiveX.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de modelo de diálogo contendo apenas controles não-ActiveX. Se não houver controles ActiveX, NULL será devolvido.

### <a name="remarks"></a>Comentários

Se algum controle ActiveX for encontrado, o modelo será analisado e um novo modelo, contendo apenas controles não-ActiveX, será criado. Todos os controles ActiveX encontrados durante esse processo são adicionados a *ppOleDlgItems*.

Se não houver controles ActiveX no modelo, NULL será devolvido *.*

> [!NOTE]
> A memória alocada para o `PostCreateDialog` novo modelo é liberada na função.

Anular esta função para personalizar este processo.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)<br/>
[Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
