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
ms.openlocfilehash: c2a49e3396879e5f1e0864ab5342b57541c6b36c
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865932"
---
# <a name="coccmanager-class"></a>Classe COccManager

Gerencia vários sites de controle personalizado; implementado por objetos `COleControlContainer` e `COleControlSite`.

## <a name="syntax"></a>Sintaxe

```
class COccManager : public CNoTrackObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[COccManager:: CreateContainer](#createcontainer)|Cria um objeto `COleContainer`.|
|[COccManager::CreateDlgControls](#createdlgcontrols)|Cria controles ActiveX, hospedados pelo objeto `COleContainer` associado.|
|[COccManager::](#createsite)|Cria um objeto `COleClientSite`.|
|[COccManager::GetDefBtnCode](#getdefbtncode)|Recupera o código do botão padrão.|
|[COccManager::IsDialogMessage](#isdialogmessage)|Determina o destino de uma mensagem de caixa de diálogo.|
|[COccManager::IsLabelControl](#islabelcontrol)|Determina se o controle especificado é um controle de rótulo.|
|[COccManager::IsMatchingMnemonic](#ismatchingmnemonic)|Determina se o mnemônico atual corresponde ao mnemônico do controle especificado.|
|[COccManager:: OnEvent](#onevent)|Tenta manipular o evento especificado.|
|[COccManager::P ostCreateDialog](#postcreatedialog)|Libera recursos alocados durante a criação do diálogo.|
|[COccManager::P reCreateDialog](#precreatedialog)|Processa um modelo de caixa de diálogo para controles ActiveX.|
|[COccManager::SetDefaultButton](#setdefaultbutton)|Alterna o estado padrão do controle especificado.|
|[COccManager::SplitDialogTemplate](#splitdialogtemplate)|Separa todos os controles ActiveX existentes dos controles comuns no modelo de caixa de diálogo especificado.|

## <a name="remarks"></a>Comentários

A classe base, `CNoTrackObject`, é uma classe base não documentada (localizada em AFXTLS. H). Projetado para ser usado pela estrutura MFC, as classes derivadas da classe `CNoTrackObject` são isentas da detecção de vazamento de memória. Não é recomendável que você derive diretamente do `CNoTrackObject`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CNoTrackObject`

`COccManager`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxocc. h

##  <a name="createcontainer"></a>COccManager:: CreateContainer

Chamado pelo Framework para criar um contêiner de controle.

```
virtual COleControlContainer* CreateContainer(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para o objeto de janela associado ao contêiner de site personalizado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o contêiner recém-criado; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar sites personalizados, consulte [COleControlContainer:: AttachControlSite](../../mfc/reference/colecontrolcontainer-class.md#attachcontrolsite).

##  <a name="createdlgcontrols"></a>COccManager::CreateDlgControls

Chame essa função para criar controles ActiveX especificados pelo parâmetro *pOccDialogInfo* .

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
Um ponteiro para o pai do objeto da caixa de diálogo.

*lpszResourceName*<br/>
O nome do recurso que está sendo criado.

*pOccDialogInfo*<br/>
Um ponteiro para o modelo de caixa de diálogo usado para criar o objeto da caixa de diálogo.

*lpResource*<br/>
Um ponteiro para um recurso.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o controle foi criado com êxito; caso contrário, zero.

##  <a name="createsite"></a>COccManager::

Chamado pelo Framework para criar um site de controle, hospedado pelo contêiner apontado por *pCtrlCont*.

```
virtual COleControlSite* CreateSite(COleControlContainer* pCtrlCont);
```

### <a name="parameters"></a>Parâmetros

*pCtrlCont*<br/>
Um ponteiro para o contêiner de controle que hospeda o novo site de controle.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o site de controle recém-criado.

### <a name="remarks"></a>Comentários

Substitua essa função para criar um site de controle personalizado, usando sua classe derivada de [COleControlSite](../../mfc/reference/colecontrolsite-class.md).

Cada contêiner de controle pode hospedar vários sites. Crie sites adicionais com várias chamadas para `CreateSite`.

##  <a name="getdefbtncode"></a>COccManager::GetDefBtnCode

Chame essa função para determinar se o controle é um botão de ação padrão.

```
static DWORD AFX_CDECL GetDefBtnCode(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
O objeto de janela que contém o controle de botão.

### <a name="return-value"></a>Valor retornado

Um dos seguintes valores:

- DLGC_DEFPUSHBUTTON controle é o botão padrão na caixa de diálogo.

- DLGC_UNDEFPUSHBUTTON controle não é o botão padrão na caixa de diálogo.

- o controle **0** não é um botão.

##  <a name="isdialogmessage"></a>COccManager::IsDialogMessage

Chamado pelo Framework para determinar se uma mensagem é destinada à caixa de diálogo especificada e, se for, processa a mensagem.

```
virtual BOOL IsDialogMessage(
    CWnd* pWndDlg,
    LPMSG lpMsg);
```

### <a name="parameters"></a>Parâmetros

*pWndDlg*<br/>
Um ponteiro para a caixa de diálogo de destino pretendida da mensagem.

*lpMsg*<br/>
Um ponteiro para uma estrutura de `MSG` que contém a mensagem a ser verificada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem for processada; caso contrário, zero.

### <a name="remarks"></a>Comentários

O comportamento padrão de `IsDialogMessage` é verificar as mensagens do teclado e convertê-las em seleções para a caixa de diálogo correspondente. Por exemplo, a tecla TAB, quando pressionada, seleciona o próximo controle ou grupo de controles.

Substitua essa função para fornecer um comportamento personalizado para as mensagens enviadas para a caixa de diálogo especificada.

##  <a name="islabelcontrol"></a>COccManager::IsLabelControl

Chame essa função para determinar se o controle especificado é um controle de rótulo.

```
static BOOL AFX_CDECL IsLabelControl(CWnd* pWnd);
static BOOL AFX_CDECL IsLabelControl(COleControlSiteOrWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para a janela que contém o controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o controle for um rótulo; caso contrário, zero

### <a name="remarks"></a>Comentários

Um controle rótulo é aquele que atua como um rótulo para qualquer controle que esteja em seguida na ordenação.

##  <a name="ismatchingmnemonic"></a>COccManager::IsMatchingMnemonic

Chame essa função para determinar se as correspondências do mnemônico atual são representadas pelo controle.

```
static BOOL AFX_CDECL IsMatchingMnemonic(
    CWnd* pWnd,
    LPMSG lpMsg);

static BOOL AFX_CDECL IsMatchingMnemonic(
    COleControlSiteOrWnd* pWnd,
    LPMSG lpMsg);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para a janela que contém o controle.

*lpMsg*<br/>
Um ponteiro para a mensagem que contém o mnemônico a ser correspondido.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o mnemônico corresponder ao controle; caso contrário, zero

### <a name="remarks"></a>Comentários

##  <a name="onevent"></a>COccManager:: OnEvent

Chamado pelo Framework para manipular o evento especificado.

```
virtual BOOL OnEvent(
    CCmdTarget* pCmdTarget,
    UINT idCtrl,
    AFX_EVENT* pEvent,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>Parâmetros

*pCmdTarget*<br/>
Um ponteiro para o objeto `CCmdTarget` tentando manipular o evento

*idCtrl*<br/>
A ID de recurso do controle.

*pEvent*<br/>
O evento que está sendo manipulado.

*pHandlerInfo*<br/>
Se não for NULL, `OnEvent` preencherá os membros `pTarget` e `pmf` da estrutura de `AFX_CMDHANDLERINFO` em vez de expedir o comando. Normalmente, esse parâmetro deve ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o evento foi manipulado, caso contrário zero.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar o processo de manipulação de eventos padrão.

##  <a name="precreatedialog"></a>COccManager::P reCreateDialog

Chamado pelo Framework para processar um modelo de caixa de diálogo para controles ActiveX antes de criar a caixa de diálogo real.

```
virtual const DLGTEMPLATE* PreCreateDialog(
    _AFX_OCC_DIALOG_INFO* pOccDialogInfo,
    const DLGTEMPLATE* pOrigTemplate);
```

### <a name="parameters"></a>Parâmetros

*pOccDialogInfo*<br/>
Uma estrutura de `_AFX_OCC_DIALOG_INFO` que contém informações sobre o modelo de caixa de diálogo e todos os controles ActiveX hospedados pela caixa de diálogo.

*pOrigTemplate*<br/>
Um ponteiro para o modelo de diálogo a ser usado na criação da caixa de diálogo.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de modelo de caixa de diálogo usada para criar a caixa de diálogo.

### <a name="remarks"></a>Comentários

O comportamento padrão faz uma chamada para `SplitDialogTemplate`, determinando se há algum controle ActiveX presente e, em seguida, retorna o modelo de caixa de diálogo resultante.

Substitua essa função para personalizar o processo de criação de uma caixa de diálogo que hospede controles ActiveX.

##  <a name="postcreatedialog"></a>COccManager::P ostCreateDialog

Chamado pelo Framework para liberar memória alocada para o modelo de caixa de diálogo.

```
virtual void PostCreateDialog(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```

### <a name="parameters"></a>Parâmetros

*pOccDialogInfo*<br/>
Uma estrutura de `_AFX_OCC_DIALOG_INFO` que contém informações sobre o modelo de caixa de diálogo e todos os controles ActiveX hospedados pela caixa de diálogo.

### <a name="remarks"></a>Comentários

Essa memória foi alocada por uma chamada para `SplitDialogTemplate`e foi usada para todos os controles ActiveX hospedados na caixa de diálogo.

Substitua essa função para personalizar o processo de limpeza de todos os recursos usados pelo objeto da caixa de diálogo.

##  <a name="setdefaultbutton"></a>COccManager::SetDefaultButton

Chame essa função para definir o controle como o botão padrão.

```
static void AFX_CDECL SetDefaultButton(
    CWnd* pWnd,
    BOOL bDefault);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para a janela que contém o controle.

*bDefault*<br/>
Diferente de zero se o controle deve se tornar o botão padrão; caso contrário, zero.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  O controle deve ter o conjunto de bits de status OLEMISC_ACTSLIKEBUTTON. Para obter mais informações sobre sinalizadores OLEMISC, consulte o tópico [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) na SDK do Windows.

##  <a name="splitdialogtemplate"></a>COccManager::SplitDialogTemplate

Chamado pelo Framework para dividir os controles ActiveX de controles de diálogo comuns.

```
virtual DLGTEMPLATE* SplitDialogTemplate(
    const DLGTEMPLATE* pTemplate,
    DLGITEMTEMPLATE** ppOleDlgItems);
```

### <a name="parameters"></a>Parâmetros

*pTemplate*<br/>
Um ponteiro para o modelo de caixa de diálogo a ser examinado.

*ppOleDlgItems*<br/>
Uma lista de ponteiros para itens da caixa de diálogo que são controles ActiveX.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de modelo de caixa de diálogo que contém apenas controles não ActiveX. Se nenhum controle ActiveX estiver presente, será retornado nulo.

### <a name="remarks"></a>Comentários

Se todos os controles ActiveX forem encontrados, o modelo será analisado e um novo modelo, contendo apenas controles não ActiveX, será criado. Todos os controles ActiveX encontrados durante esse processo são adicionados ao *ppOleDlgItems*.

Se não houver controles ActiveX no modelo, NULL será retornado *.*

> [!NOTE]
>  A memória alocada para o novo modelo é liberada na função `PostCreateDialog`.

Substitua essa função para personalizar esse processo.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)<br/>
[Classe COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)
