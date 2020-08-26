---
title: Classe CBaseTabbedPane
ms.date: 11/04/2016
f1_keywords:
- CBaseTabbedPane
- AFXBASETABBEDPANE/CBaseTabbedPane
- AFXBASETABBEDPANE/CBaseTabbedPane::AddTab
- AFXBASETABBEDPANE/CBaseTabbedPane::AllowDestroyEmptyTabbedPane
- AFXBASETABBEDPANE/CBaseTabbedPane::ApplyRestoredTabInfo
- AFXBASETABBEDPANE/CBaseTabbedPane::CanFloat
- AFXBASETABBEDPANE/CBaseTabbedPane::CanSetCaptionTextToTabName
- AFXBASETABBEDPANE/CBaseTabbedPane::ConvertToTabbedDocument
- AFXBASETABBEDPANE/CBaseTabbedPane::DetachPane
- AFXBASETABBEDPANE/CBaseTabbedPane::EnableSetCaptionTextToTabName
- AFXBASETABBEDPANE/CBaseTabbedPane::FillDefaultTabsOrderArray
- AFXBASETABBEDPANE/CBaseTabbedPane::FindBarByTabNumber
- AFXBASETABBEDPANE/CBaseTabbedPane::FindPaneByID
- AFXBASETABBEDPANE/CBaseTabbedPane::FloatTab
- AFXBASETABBEDPANE/CBaseTabbedPane::GetDefaultTabsOrder
- AFXBASETABBEDPANE/CBaseTabbedPane::GetFirstVisibleTab
- AFXBASETABBEDPANE/CBaseTabbedPane::GetMinSize
- AFXBASETABBEDPANE/CBaseTabbedPane::GetPaneIcon
- AFXBASETABBEDPANE/CBaseTabbedPane::GetPaneList
- AFXBASETABBEDPANE/CBaseTabbedPane::GetTabArea
- AFXBASETABBEDPANE/CBaseTabbedPane::GetTabsNum
- AFXBASETABBEDPANE/CBaseTabbedPane::GetUnderlyingWindow
- AFXBASETABBEDPANE/CBaseTabbedPane::GetVisibleTabsNum
- AFXBASETABBEDPANE/CBaseTabbedPane::HasAutoHideMode
- AFXBASETABBEDPANE/CBaseTabbedPane::IsHideSingleTab
- AFXBASETABBEDPANE/CBaseTabbedPane::RecalcLayout
- AFXBASETABBEDPANE/CBaseTabbedPane::RemovePane
- AFXBASETABBEDPANE/CBaseTabbedPane::SetAutoDestroy
- AFXBASETABBEDPANE/CBaseTabbedPane::SetAutoHideMode
- AFXBASETABBEDPANE/CBaseTabbedPane::ShowTab
helpviewer_keywords:
- CBaseTabbedPane [MFC], AddTab
- CBaseTabbedPane [MFC], AllowDestroyEmptyTabbedPane
- CBaseTabbedPane [MFC], ApplyRestoredTabInfo
- CBaseTabbedPane [MFC], CanFloat
- CBaseTabbedPane [MFC], CanSetCaptionTextToTabName
- CBaseTabbedPane [MFC], ConvertToTabbedDocument
- CBaseTabbedPane [MFC], DetachPane
- CBaseTabbedPane [MFC], EnableSetCaptionTextToTabName
- CBaseTabbedPane [MFC], FillDefaultTabsOrderArray
- CBaseTabbedPane [MFC], FindBarByTabNumber
- CBaseTabbedPane [MFC], FindPaneByID
- CBaseTabbedPane [MFC], FloatTab
- CBaseTabbedPane [MFC], GetDefaultTabsOrder
- CBaseTabbedPane [MFC], GetFirstVisibleTab
- CBaseTabbedPane [MFC], GetMinSize
- CBaseTabbedPane [MFC], GetPaneIcon
- CBaseTabbedPane [MFC], GetPaneList
- CBaseTabbedPane [MFC], GetTabArea
- CBaseTabbedPane [MFC], GetTabsNum
- CBaseTabbedPane [MFC], GetUnderlyingWindow
- CBaseTabbedPane [MFC], GetVisibleTabsNum
- CBaseTabbedPane [MFC], HasAutoHideMode
- CBaseTabbedPane [MFC], IsHideSingleTab
- CBaseTabbedPane [MFC], RecalcLayout
- CBaseTabbedPane [MFC], RemovePane
- CBaseTabbedPane [MFC], SetAutoDestroy
- CBaseTabbedPane [MFC], SetAutoHideMode
- CBaseTabbedPane [MFC], ShowTab
ms.assetid: f22c0080-5b29-4a0a-8f74-8f0a4cd2dbcf
ms.openlocfilehash: 21f2821392d2b9e71837997f5a9a10ab80ba073f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838666"
---
# <a name="cbasetabbedpane-class"></a>Classe CBaseTabbedPane

Estende a funcionalidade da [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md) para dar suporte à criação de janelas com guias.

## <a name="syntax"></a>Sintaxe

```
class CBaseTabbedPane : public CDockablePane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CBaseTabbedPane::CBaseTabbedPane`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBaseTabbedPane::AddTab](#addtab)|Adiciona uma nova guia a um painel com guias.|
|[CBaseTabbedPane::AllowDestroyEmptyTabbedPane](#allowdestroyemptytabbedpane)|Especifica se um painel com guias vazio pode ser destruído.|
|[CBaseTabbedPane::ApplyRestoredTabInfo](#applyrestoredtabinfo)|Aplica as configurações de guia, que são carregadas do registro, em um painel com guias.|
|[CBaseTabbedPane:: CanFloat](#canfloat)|Determina se o painel pode flutuar. (Substitui [CBasePane:: CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).)|
|[CBaseTabbedPane::CanSetCaptionTextToTabName](#cansetcaptiontexttotabname)|Determina se a legenda do painel com guias deve exibir o mesmo texto da guia ativa.|
|[CBaseTabbedPane::ConvertToTabbedDocument](#converttotabbeddocument)|(Substitui [CDockablePane:: ConvertToTabbedDocument](../../mfc/reference/cdockablepane-class.md#converttotabbeddocument).)|
|[CBaseTabbedPane::D etachPane](#detachpane)|Converte um ou mais painéis encaixáveis em documentos com guias MDI.|
|[CBaseTabbedPane::EnableSetCaptionTextToTabName](#enablesetcaptiontexttotabname)|Habilita ou desabilita a capacidade do painel com guias sincronizar o texto da legenda com o texto do rótulo na guia ativa.|
|[CBaseTabbedPane::FillDefaultTabsOrderArray](#filldefaulttabsorderarray)|Restaura a ordem de Tabulação interna para um estado padrão.|
|[CBaseTabbedPane::FindBarByTabNumber](#findbarbytabnumber)|Retorna um painel que reside em uma guia quando a guia é identificada por um índice de tabulação baseado em zero.|
|[CBaseTabbedPane::FindPaneByID](#findpanebyid)|Retorna um painel que é identificado pela ID do painel.|
|[CBaseTabbedPane::FloatTab](#floattab)|Flutua um painel, mas somente se o painel residir atualmente em uma guia desanexável.|
|[CBaseTabbedPane::GetDefaultTabsOrder](#getdefaulttabsorder)|Retorna a ordem padrão das guias no painel.|
|[CBaseTabbedPane::GetFirstVisibleTab](#getfirstvisibletab)|Recupera um ponteiro para a primeira guia exibida.|
|[CBaseTabbedPane:: getminize](#getminsize)|Recupera o tamanho mínimo permitido para o painel. (Substitui [CPane:: Getminize](../../mfc/reference/cpane-class.md#getminsize).)|
|[CBaseTabbedPane::GetPaneIcon](#getpaneicon)|Retorna um identificador para o ícone do painel. (Substitui [CBasePane:: GetPaneIcon](../../mfc/reference/cbasepane-class.md#getpaneicon).)|
|[CBaseTabbedPane:: getpanelista](#getpanelist)|Retorna uma lista de painéis contidos no painel com guias.|
|[CBaseTabbedPane::GetTabArea](#gettabarea)|Retorna os retângulos delimitadores para as áreas da guia superior e inferior.|
|[CBaseTabbedPane::GetTabsNum](#gettabsnum)|Retorna a contagem de guias em uma janela de guia.|
|[CBaseTabbedPane::GetUnderlyingWindow](#getunderlyingwindow)|Obtém a janela de guia subjacente (encapsulado).|
|[CBaseTabbedPane::GetVisibleTabsNum](#getvisibletabsnum)|Retorna a contagem de guias exibidas.|
|[CBaseTabbedPane::HasAutoHideMode](#hasautohidemode)|Determina se o painel com guias pode ser alternado para o modo ocultar automaticamente.|
|[CBaseTabbedPane::IsHideSingleTab](#ishidesingletab)|Determina se o painel com guias ficará oculto se apenas uma guia for exibida.|
|`CBaseTabbedPane::LoadSiblingPaneIDs`|Usado internamente durante a serialização.|
|[CBaseTabbedPane::RecalcLayout](#recalclayout)|Recalcula as informações de layout do painel. (Substitui [CPane:: RecalcLayout](../../mfc/reference/cpane-class.md#recalclayout).)|
|[CBaseTabbedPane::RemovePane](#removepane)|Remove um painel do painel com guias.|
|`CBaseTabbedPane::SaveSiblingBarIDs`|Usado internamente durante a serialização.|
|`CBaseTabbedPane::Serialize`|(Substitui [CDockablePane:: Serialize](cdockablepane-class.md).)|
|`CBaseTabbedPane::SerializeTabWindow`|Usado internamente durante a serialização.|
|[CBaseTabbedPane::SetAutoDestroy](#setautodestroy)|Determina se a barra de controle com guias será destruída automaticamente.|
|[CBaseTabbedPane:: autoocultarmode](#setautohidemode)|Alterna o painel de encaixe entre o modo exibido e ocultado automaticamente. (Substitui [CDockablePane:: autoocultarmode](../../mfc/reference/cdockablepane-class.md#setautohidemode).)|
|[CBaseTabbedPane::ShowTab](#showtab)|Mostra ou oculta uma guia.|

## <a name="remarks"></a>Comentários

Esta classe é uma classe abstrata e não pode ser instanciada. Ele implementa os serviços que são comuns a todos os tipos de painéis com guias.

Atualmente, a biblioteca inclui duas classes de painel com guias derivadas: [classe CTabbedPane](../../mfc/reference/ctabbedpane-class.md) e [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).

Um `CBaseTabbedPane` objeto encapsula um ponteiro para um objeto da [Classe CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md) . A [Classe CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md) então se torna uma janela filho do painel com guias.

Para obter mais informações sobre como criar painéis com guias, consulte [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md), [classe CTabbedPane](../../mfc/reference/ctabbedpane-class.md)e [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CDockablePane](../../mfc/reference/cdockablepane-class.md)

`CBaseTabbedPane`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxBaseTabbedPane. h

## <a name="cbasetabbedpaneaddtab"></a><a name="addtab"></a> CBaseTabbedPane::AddTab

Adiciona uma nova guia a um painel com guias.

```
virtual BOOL AddTab(
    CWnd* pNewBar,
    BOOL bVisible = TRUE,
    BOOL bSetActive = TRUE,
    BOOL bDetachable = TRUE);
```

### <a name="parameters"></a>parâmetros

*pNewBar*<br/>
[entrada, saída] Um ponteiro para o painel a ser adicionado. Esse ponteiro pode se tornar inválido depois que você chamar esse método. Para obter mais informações, consulte a seção Comentários.

*bVisible*<br/>
no TRUE para tornar a guia visível; caso contrário, FALSE.

*bSetActive*<br/>
no TRUE para tornar a guia ativa. caso contrário, FALSE.

*bDetachable*<br/>
no TRUE para tornar a guia desanexável; caso contrário, FALSE.

### <a name="return-value"></a>Valor Retornado

TRUE se o painel foi adicionado com êxito como uma guia e não foi destruído no processo. FALSE se o painel que está sendo adicionado for um objeto do tipo `CBaseTabbedPane` . Para obter mais informações, consulte a seção Comentários.

### <a name="remarks"></a>Comentários

Chame esse método para adicionar um painel como uma nova guia em um painel com guias. Se *pNewBar* apontar para um objeto do tipo `CBaseTabbedPane` , todas as suas guias serão copiadas no painel com guias e, em seguida, *pNewBar* será destruído. Portanto, *pNewBar* se torna um ponteiro inválido e não deve ser usado.

## <a name="cbasetabbedpaneallowdestroyemptytabbedpane"></a><a name="allowdestroyemptytabbedpane"></a> CBaseTabbedPane::AllowDestroyEmptyTabbedPane

Especifica se um painel com guias vazio pode ser destruído.

```
virtual BOOL AllowDestroyEmptyTabbedPane() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se um painel com guias vazio puder ser destruído; caso contrário, FALSE. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Se um painel com guias vazio não tiver permissão para ser destruído, a estrutura ocultará o painel em vez disso.

## <a name="cbasetabbedpaneapplyrestoredtabinfo"></a><a name="applyrestoredtabinfo"></a> CBaseTabbedPane::ApplyRestoredTabInfo

Carrega as configurações da guia do registro e as aplica a um painel com guias.

```
virtual void ApplyRestoredTabInfo(BOOL bUseTabIndexes = FALSE);
```

### <a name="parameters"></a>parâmetros

*bUseTabIndexes*<br/>
no Esse parâmetro é usado internamente pela estrutura.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework quando recarrega as informações de estado de encaixe do registro. O método obtém informações sobre a ordem de tabulação e os nomes de guias para um painel com guias.

## <a name="cbasetabbedpanecanfloat"></a><a name="canfloat"></a> CBaseTabbedPane:: CanFloat

Especifica se o painel com guias pode flutuar.

```
virtual BOOL CanFloat() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se o painel puder flutuar; caso contrário, FALSE.

## <a name="cbasetabbedpanecansetcaptiontexttotabname"></a><a name="cansetcaptiontexttotabname"></a> CBaseTabbedPane::CanSetCaptionTextToTabName

Determina se a legenda do painel com guias deve exibir o mesmo texto da guia ativa.

```
virtual BOOL CanSetCaptionTextToTabName() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se o texto da legenda do painel com guias for definido como o texto da guia ativa; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O método é usado para determinar se o texto exibido na legenda do painel com guias duplica o rótulo da guia ativa. Você pode habilitar ou desabilitar essa funcionalidade chamando [CBaseTabbedPane:: EnableSetCaptionTextToTabName](#enablesetcaptiontexttotabname).

## <a name="cbasetabbedpaneconverttotabbeddocument"></a><a name="converttotabbeddocument"></a> CBaseTabbedPane::ConvertToTabbedDocument

Converte um ou mais painéis encaixáveis em documentos com guias MDI.

```
virtual void ConvertToTabbedDocument(BOOL bActiveTabOnly = TRUE);
```

### <a name="parameters"></a>parâmetros

*bActiveTabOnly*<br/>
no Ao converter um painel com guias, especifique TRUE para converter somente a guia ativa. Especifique FALSE para converter todas as guias no painel.

## <a name="cbasetabbedpanedetachpane"></a><a name="detachpane"></a> CBaseTabbedPane::D etachPane

Desanexa um painel do painel com guias.

```
virtual BOOL DetachPane(
    CWnd* pBar,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>parâmetros

*pBar*<br/>
no Ponteiro para o painel a ser desanexado.

*bHide*<br/>
no Parâmetro booliano que especifica se a estrutura oculta o painel depois que ele é desanexado.

### <a name="return-value"></a>Valor Retornado

TRUE se a estrutura desanexar o painel com êxito; FALSE se *pBar* for nulo ou se referir a um painel que não esteja no painel com guias.

### <a name="remarks"></a>Comentários

A estrutura flutua o painel desanexado, se possível. Para obter mais informações, consulte [CBasePane:: CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).

## <a name="cbasetabbedpaneenablesetcaptiontexttotabname"></a><a name="enablesetcaptiontexttotabname"></a> CBaseTabbedPane::EnableSetCaptionTextToTabName

Habilita ou desabilita a capacidade do painel com guias sincronizar o texto da legenda com o texto do rótulo na guia ativa.

```
virtual void EnableSetCaptionTextToTabName(BOOL bEnable);
```

### <a name="parameters"></a>parâmetros

*bEnable*<br/>
no TRUE para sincronizar a legenda do painel com guias com a legenda da guia ativa; caso contrário, FALSE.

## <a name="cbasetabbedpanefilldefaulttabsorderarray"></a><a name="filldefaulttabsorderarray"></a> CBaseTabbedPane::FillDefaultTabsOrderArray

Restaura a ordem de Tabulação interna para um estado padrão.

```cpp
void FillDefaultTabsOrderArray();
```

### <a name="remarks"></a>Comentários

Esse método é chamado quando a estrutura restaura uma barra do Outlook para um estado inicial.

## <a name="cbasetabbedpanefindpanebyid"></a><a name="findpanebyid"></a> CBaseTabbedPane::FindPaneByID

Retorna um painel identificado pela ID do painel.

```
virtual CWnd* FindPaneByID(UINT uBarID);
```

### <a name="parameters"></a>parâmetros

*uBarID*<br/>
no Especifica a ID do painel a ser localizado.

### <a name="return-value"></a>Valor Retornado

Um ponteiro para o painel se ele foi encontrado; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse método compara todas as guias no painel e retorna aquela com a ID especificada pelo parâmetro *uBarID* .

## <a name="cbasetabbedpanefindbarbytabnumber"></a><a name="findbarbytabnumber"></a> CBaseTabbedPane::FindBarByTabNumber

Retorna um painel que reside em uma guia.

```
virtual CWnd* FindBarByTabNumber(
    int nTabNum,
    BOOL bGetWrappedBar = FALSE);
```

### <a name="parameters"></a>parâmetros

*nTabNum*<br/>
no Especifica o índice de base zero da guia a ser recuperada.

*bGetWrappedBar*<br/>
no TRUE para retornar a janela subjacente (encapsulada) do painel em vez do próprio painel; caso contrário, FALSE. Isso se aplica somente a painéis derivados de [CDockablePaneAdapter](../../mfc/reference/cdockablepaneadapter-class.md).

### <a name="return-value"></a>Valor Retornado

Se o painel for encontrado, um ponteiro válido para o painel que está sendo pesquisado será retornado; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o painel que reside na guia especificada pelo parâmetro *nTabNum* .

## <a name="cbasetabbedpanefloattab"></a><a name="floattab"></a> CBaseTabbedPane::FloatTab

Flutua um painel, mas somente se o painel residir atualmente em uma guia desanexável.

```
virtual BOOL FloatTab(
    CWnd* pBar,
    int nTabID,
    AFX_DOCK_METHOD dockMethod,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>parâmetros

*pBar*<br/>
[entrada, saída] Um ponteiro para o painel a flutuar.

*nTabID*<br/>
no Especifica o índice de base zero da guia a ser flutuante.

*dockMethod*<br/>
no Especifica o método a ser usado para tornar o painel flutuante. Para obter mais informações, consulte a seção Comentários.

*bHide*<br/>
no TRUE para ocultar o painel antes de flutuante; caso contrário, FALSE.

### <a name="return-value"></a>Valor Retornado

TRUE se o painel flutuar; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame esse método para flutuar um painel que reside atualmente em uma guia desanexável.

Se você quiser desanexar um painel programaticamente, especifique DM_SHOW para o parâmetro *dockMethod* . Se você quiser flutuar o painel na mesma posição em que ele foi flutuado anteriormente, especifique DM_DBL_CLICK como o parâmetro *dockMethod* .

## <a name="cbasetabbedpanegetdefaulttabsorder"></a><a name="getdefaulttabsorder"></a> CBaseTabbedPane::GetDefaultTabsOrder

Retorna a ordem padrão das guias no painel.

```
const CArray<int,int>& GetDefaultTabsOrder();
```

### <a name="return-value"></a>Valor Retornado

Um `CArray` objeto que especifica a ordem padrão das guias no painel.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando uma barra do Outlook é redefinida para um estado inicial.

## <a name="cbasetabbedpanegetfirstvisibletab"></a><a name="getfirstvisibletab"></a> CBaseTabbedPane::GetFirstVisibleTab

Recupera um ponteiro para a primeira guia exibida.

```
virtual CWnd* GetFirstVisibleTab(int& iTabNum);
```

### <a name="parameters"></a>parâmetros

*iTabNum*<br/>
no Uma referência a um inteiro. Esse método grava o índice de base zero da primeira guia exibida para esse parâmetro ou-1 se nenhuma guia exibida for encontrada.

### <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, um ponteiro para a primeira guia exibida; caso contrário, NULL.

## <a name="cbasetabbedpanegetminsize"></a><a name="getminsize"></a> CBaseTabbedPane:: getminize

Recupera o tamanho mínimo permitido para o painel.

```
virtual void GetMinSize(CSize& size) const;
```

### <a name="parameters"></a>parâmetros

*size*<br/>
fora Um `CSize` objeto que é preenchido com o tamanho mínimo permitido.

### <a name="remarks"></a>Comentários

Se a manipulação consistente de tamanhos mínimos de painéis estiver ativa ( [CPane:: m_bHandleMinSize](../../mfc/reference/cpane-class.md#m_bhandleminsize)), o *tamanho* será preenchido com o tamanho mínimo permitido para a guia ativa. caso contrário, o *tamanho* será preenchido com o valor de retorno de [CPane:: GetMinSize](../../mfc/reference/cpane-class.md#getminsize).

## <a name="cbasetabbedpanegetpaneicon"></a><a name="getpaneicon"></a> CBaseTabbedPane::GetPaneIcon

Recupera o tamanho mínimo permitido para o painel.

```
virtual void GetMinSize(CSize& size) const;
```

### <a name="parameters"></a>parâmetros

*size*<br/>
fora Um `CSize` objeto que é preenchido com o tamanho mínimo permitido.

### <a name="remarks"></a>Comentários

Se a manipulação consistente de tamanhos mínimos de painéis estiver ativa ( [CPane:: m_bHandleMinSize](../../mfc/reference/cpane-class.md#m_bhandleminsize)), o *tamanho* será preenchido com o tamanho mínimo permitido para a guia ativa. caso contrário, o *tamanho* será preenchido com o valor de retorno de [CPane:: GetMinSize](../../mfc/reference/cpane-class.md#getminsize).

## <a name="cbasetabbedpanegetpanelist"></a><a name="getpanelist"></a> CBaseTabbedPane:: getpanelista

Retorna uma lista de painéis contidos no painel com guias.

```
virtual void GetPaneList(
    CObList& lst,
    CRuntimeClass* pRTCFilter = NULL);
```

### <a name="parameters"></a>parâmetros

*ficheiro*<br/>
fora Um `CObList` que é preenchido com os painéis contidos no painel com guias.

*pRTCFilter*<br/>
no Se não for NULL, a lista retornada conterá apenas painéis que são da classe de tempo de execução especificada.

## <a name="cbasetabbedpanegettabarea"></a><a name="gettabarea"></a> CBaseTabbedPane::GetTabArea

Retorna os retângulos delimitadores para as áreas da guia superior e inferior.

```
virtual void GetTabArea(
    CRect& rectTabAreaTop,
    CRect& rectTabAreaBottom) const = 0;
```

### <a name="parameters"></a>parâmetros

*rectTabAreaTop*<br/>
fora Recebe as coordenadas de tela da área da guia superior.

*rectTabAreaBottom*<br/>
fora Recebe as coordenadas de tela da área de guia inferior.

### <a name="remarks"></a>Comentários

Chame esse método para determinar os retângulos delimitadores, em coordenadas de tela, para as áreas de guias superior e inferior.

## <a name="cbasetabbedpanegettabsnum"></a><a name="gettabsnum"></a> CBaseTabbedPane::GetTabsNum

Retorna a contagem de guias em uma janela de guia.

```
virtual int GetTabsNum() const;
```

### <a name="return-value"></a>Valor Retornado

O número de guias no painel com guias.

## <a name="cbasetabbedpanegetunderlyingwindow"></a><a name="getunderlyingwindow"></a> CBaseTabbedPane::GetUnderlyingWindow

Obtém a janela de guia subjacente (encapsulado).

```
virtual CMFCBaseTabCtrl* GetUnderlyingWindow();
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para a janela de guia subjacente.

## <a name="cbasetabbedpanegetvisibletabsnum"></a><a name="getvisibletabsnum"></a> CBaseTabbedPane::GetVisibleTabsNum

Retorna a contagem de guias visíveis.

```
virtual int GetVisibleTabsNum() const;
```

### <a name="return-value"></a>Valor Retornado

O número de guias visíveis, que será maior ou igual a zero.

### <a name="remarks"></a>Comentários

Chame esse método para determinar o número de guias visíveis no painel com guias.

## <a name="cbasetabbedpanehasautohidemode"></a><a name="hasautohidemode"></a> CBaseTabbedPane::HasAutoHideMode

Determina se o painel com guias pode ser alternado para o modo de AutoOcultar.

```
virtual BOOL HasAutoHideMode() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se o painel puder ser alternado para o modo de AutoOcultar; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o modo de AutoOcultar estiver desabilitado, nenhum botão de PIN será exibido na legenda do painel com guias.

## <a name="cbasetabbedpaneishidesingletab"></a><a name="ishidesingletab"></a> CBaseTabbedPane::IsHideSingleTab

Determina se o painel com guias ficará oculto se apenas uma guia for exibida.

```
virtual BOOL IsHideSingleTab() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se a janela da guia não for exibida quando houver apenas uma guia visível; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o painel não for exibido porque apenas uma guia está aberta, você poderá chamar esse método para determinar se o painel com guias está funcionando corretamente.

## <a name="cbasetabbedpaneremovepane"></a><a name="removepane"></a> CBaseTabbedPane::RemovePane

Remove um painel do painel com guias.

```
virtual BOOL RemovePane(CWnd* pBar);
```

### <a name="parameters"></a>parâmetros

*pBar*<br/>
[entrada, saída] Um ponteiro para o painel a ser removido do painel com guias.

### <a name="return-value"></a>Valor Retornado

TRUE se o painel tiver sido removido com êxito do painel com guias e se o painel com guias ainda for válido. FALSE se o último painel tiver sido removido do painel com guias e o painel com guias estiver prestes a ser destruído. Se o valor de retorno for FALSE, não use mais o painel com guias.

### <a name="remarks"></a>Comentários

Chame esse método para remover o painel especificado pelo parâmetro *pBar* do painel com guias.

## <a name="cbasetabbedpanesetautodestroy"></a><a name="setautodestroy"></a> CBaseTabbedPane::SetAutoDestroy

Determina se a barra de controle com guias será destruída automaticamente.

```cpp
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>parâmetros

*bAutoDestroy*<br/>
no TRUE se o painel com guias tiver sido criado dinamicamente e você não estiver controlando seu tempo de vida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Defina o modo de destruição automática como verdadeiro se você criar um painel com guias dinamicamente e se não estiver controlando seu tempo de vida. Se o modo de destruição automática for TRUE, o painel com guias será destruído automaticamente pela estrutura.

## <a name="cbasetabbedpaneshowtab"></a><a name="showtab"></a> CBaseTabbedPane::ShowTab

Mostra ou oculta uma guia.

```
virtual BOOL ShowTab(
    CWnd* pBar,
    BOOL bShow,
    BOOL bDelay,
    BOOL bActivate);
```

### <a name="parameters"></a>parâmetros

*pBar*<br/>
no Um ponteiro para o painel a ser mostrado ou ocultado.

*bShow*<br/>
no TRUE para mostrar o painel; FALSE para ocultar o painel.

*bDelay*<br/>
no TRUE para atrasar o ajuste do layout da guia; caso contrário, FALSE.

*bActivate*<br/>
no TRUE para tornar a guia ativa. caso contrário, FALSE.

### <a name="return-value"></a>Valor Retornado

TRUE se a guia foi exibida ou ocultada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando você chama esse método, um painel é mostrado ou oculto, dependendo do valor do parâmetro *bShow* . Se você ocultar uma guia e ela for a última guia visível na janela de guia subjacente, o painel com guias ficará oculto. Se você mostrar uma guia quando não havia nenhuma Tabulação visível, o painel com guias será mostrado.

## <a name="cbasetabbedpanerecalclayout"></a><a name="recalclayout"></a> CBaseTabbedPane::RecalcLayout

Recalcula as informações de layout do painel.

```
virtual void RecalcLayout();
```

### <a name="remarks"></a>Comentários

Se o painel estiver flutuando, esse método notificará a estrutura para redimensionar o painel para o tamanho atual do mini-quadro.

Se o painel estiver encaixado, esse método não fará nada.

## <a name="cbasetabbedpanesetautohidemode"></a><a name="setautohidemode"></a> CBaseTabbedPane:: autoocultarmode

Define o modo ocultar automaticamente para painéis desanexados no painel com guias.

```
virtual CMFCAutoHideToolBar* SetAutoHideMode(
    BOOL bMode,
    DWORD dwAlignment,
    CMFCAutoHideToolBar* pCurrAutoHideBar = NULL,
    BOOL bUseTimer = TRUE);
```

### <a name="parameters"></a>parâmetros

*bMode*<br/>
no TRUE para habilitar o modo de ocultar automaticamente; FALSE para habilitar o modo de encaixe regular.

*dwAlignment*<br/>
no Especifica o alinhamento do painel de ocultar automaticamente a ser criado. Para obter uma lista de valores possíveis, consulte [CPane:: MoveByAlignment](../../mfc/reference/cpane-class.md#movebyalignment).

*pCurrAutoHideBar*<br/>
[entrada, saída] Um ponteiro para a barra de ferramentas de ocultação automática atual. Pode ser NULL.

*bUseTimer*<br/>
no Especifica se o efeito de ocultar automaticamente deve ser usado quando o usuário alterna o painel para ocultar automaticamente o modo ou para ocultar o painel imediatamente.

### <a name="return-value"></a>Valor Retornado

Um ponteiro para a barra de ferramentas de ocultar automaticamente que é criada ao alternar para o modo ocultar automaticamente, ou NULL se nenhuma barra de ferramentas for criada.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando um usuário escolhe o botão de fixação para alternar o painel com guias para ocultar o modo automaticamente ou para o modo de encaixe regular.

O modo ocultar automaticamente é definido para cada painel desanexado no painel com guias. Os painéis que não são desanexados são ignorados. Para obter mais informações, consulte [CMFCBaseTabCtrl:: EnableTabDetach](../../mfc/reference/cmfcbasetabctrl-class.md#enabletabdetach).

Chame esse método para alternar um painel com guias para ocultar automaticamente o modo de forma programática. O painel deve ser encaixado na janela do quadro principal ( [CDockablePane:: GetDefaultPaneDivider](../../mfc/reference/cdockablepane-class.md#getdefaultpanedivider) deve retornar um ponteiro válido para o [CPaneDivider](../../mfc/reference/cpanedivider-class.md)).

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)
