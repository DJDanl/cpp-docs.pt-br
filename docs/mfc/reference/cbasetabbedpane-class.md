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
ms.openlocfilehash: b3ae0d69c385ba89cf75d682ce12c6f1f4e5112f
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752977"
---
# <a name="cbasetabbedpane-class"></a>Classe CBaseTabbedPane

Amplia a funcionalidade da [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md) para suportar a criação de janelas com guias.

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
|[CBaseTabbedPane::AddTab](#addtab)|Adiciona uma nova guia a um painel com abas.|
|[CBaseTabbedPane::PermitirDestroyDestroyEmptyTabbedPane](#allowdestroyemptytabbedpane)|Especifica se um painel vazio pode ser destruído.|
|[CBaseTabbedPane::ApplyRestoredTabInfo](#applyrestoredtabinfo)|Aplica as configurações da guia, que são carregadas do registro, em um painel com guias.|
|[CBaseTabbedPane::CanFloat](#canfloat)|Determina se o painel pode flutuar. (Substitui [cbasepane::CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).)|
|[CBaseTabbedPane:CanSetCaptionTextToTabName](#cansetcaptiontexttotabname)|Determina se a legenda do painel com guias deve exibir o mesmo texto da guia ativa.|
|[CBaseTabbedPane::ConvertTo'TbedDocument](#converttotabbeddocument)|(Substitui [cdockablepane:convertTo'TabbedDocument](../../mfc/reference/cdockablepane-class.md#converttotabbeddocument).)|
|[CBaseTabbedPane::DetachPane](#detachpane)|Converte um ou mais painéis ancoráveis em documentos com guias MDI.|
|[CBaseTabbedPane:EnableSetCaptionTextTo'sOnome](#enablesetcaptiontexttotabname)|Ativa ou desativa a capacidade do painel de guias de sincronizar o texto da legenda com o texto do rótulo na guia ativa.|
|[CBaseTabbedPane::FillDefaultTabsOrderArray](#filldefaulttabsorderarray)|Restaura a ordem de guia interna em um estado padrão.|
|[cbasetabbedpane::FindBarByTabNumber](#findbarbytabnumber)|Retorna um painel que reside em uma guia quando a guia é identificada por um índice de guia baseado em zero.|
|||
|[CBaseTabbedPane::FindPaneByID](#findpanebyid)|Retorna um painel que é identificado pelo painel ID.|
|[CBaseTabbedPane::FloatTab](#floattab)|Flutua um painel, mas apenas se o painel reside atualmente em uma guia destacável.|
|[CBaseTabbedPane::GetDefaultTabsOrder](#getdefaulttabsorder)|Retorna a ordem padrão de guias no painel.|
|[CBaseTabbedPane::GetFirstVisibleTab](#getfirstvisibletab)|Recupera um ponteiro para a primeira guia exibida.|
|[CBaseTabbedPane::GetMinSize](#getminsize)|Recupera o tamanho mínimo permitido para o painel. (Substitui [cpane::GetMinSize](../../mfc/reference/cpane-class.md#getminsize).)|
|[CBaseTabbedPane::GetPaneIcon](#getpaneicon)|Retorna uma alça para o ícone do painel. (Substitui [cbasepane::GetPaneIcon](../../mfc/reference/cbasepane-class.md#getpaneicon).)|
|[CBaseTabbedPane::GetPaneList](#getpanelist)|Retorna uma lista de painéis que estão contidos no painel de guias.|
|[CBaseTabbedPane::GetTabArea](#gettabarea)|Retorna os retângulos delimitadores para as áreas de guia superior e inferior.|
|[CBaseTabbedPane::GetTabsNum](#gettabsnum)|Retorna a contagem de guias em uma janela de guia.|
|[CBaseTabbedPane::GetUnderlyingWindow](#getunderlyingwindow)|Obtém a janela de guia subjacente (embrulhada).|
|[CBaseTabbedPane::GetVisibleTabsNum](#getvisibletabsnum)|Retorna a contagem de guias exibidas.|
|[CBaseTabbedPane::HasAutoHideMode](#hasautohidemode)|Determina se o painel com guias pode ser comutado para o modo de ocultação automática.|
|[cbasetabbedpane::IsHideSingleTab](#ishidesingletab)|Determina se o painel com guias está oculto se apenas uma guia for exibida.|
|`CBaseTabbedPane::LoadSiblingPaneIDs`|Usado internamente durante a serialização.|
|[CBaseTabbedPane::RecalcLayout](#recalclayout)|Recalcula as informações de layout para o painel. (Substitui [cpane::RecalcLayout](../../mfc/reference/cpane-class.md#recalclayout).)|
|[CBaseTabbedPane::RemovePane](#removepane)|Remove um painel do painel de abas.|
|`CBaseTabbedPane::SaveSiblingBarIDs`|Usado internamente durante a serialização.|
|`CBaseTabbedPane::Serialize`|(Substitui [cdockablepane::Serialize](cdockablepane-class.md).)|
|`CBaseTabbedPane::SerializeTabWindow`|Usado internamente durante a serialização.|
|[CBaseTabbedPane::SetAutoDestroy](#setautodestroy)|Determina se a barra de controle com guias será destruída automaticamente.|
|[CBaseTabbedPane::SetAuto'SM](#setautohidemode)|Alterna o painel de acoplamento entre o modo exibido e o modo de ocultação automática. (Substitui [cdockablepane::SetAutoHideMode](../../mfc/reference/cdockablepane-class.md#setautohidemode).)|
|[CBaseTabbedPane::ShowTab](#showtab)|Mostra ou esconde uma guia.|

## <a name="remarks"></a>Comentários

Esta aula é uma classe abstrata e não pode ser instanciada. Implementa os serviços que são comuns a todos os tipos de painéis com guias.

Atualmente, a biblioteca inclui duas classes de painel com guias derivadas: [CTabbedPane Class](../../mfc/reference/ctabbedpane-class.md) e [CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md).

Um `CBaseTabbedPane` objeto envolve um ponteiro para um objeto [CMFCBaseTabCtrl Class.](../../mfc/reference/cmfcbasetabctrl-class.md) [CMFCBaseTabCtrl Class](../../mfc/reference/cmfcbasetabctrl-class.md) torna-se então uma janela filho do painel de guias.

Para obter mais informações sobre como criar painéis com guias, consulte [CDockablePane Class,](../../mfc/reference/cdockablepane-class.md) [CTabbedPane Class](../../mfc/reference/ctabbedpane-class.md)e [CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[Cdockablepane](../../mfc/reference/cdockablepane-class.md)

`CBaseTabbedPane`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxBaseTabbedPane.h

## <a name="cbasetabbedpaneaddtab"></a><a name="addtab"></a>CBaseTabbedPane::AddTab

Adiciona uma nova guia a um painel com abas.

```
virtual BOOL AddTab(
    CWnd* pNewBar,
    BOOL bVisible = TRUE,
    BOOL bSetActive = TRUE,
    BOOL bDetachable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pnewbar*<br/>
[dentro, fora] Um ponteiro para o painel para adicionar. Este ponteiro pode se tornar inválido depois que você chamar este método. Para obter mais informações, consulte a seção Comentários.

*bVisible*<br/>
[em] TRUE para tornar a guia visível; caso contrário, FALSE.

*bSetActive*<br/>
[em] TRUE para fazer a guia ativa da guia; caso contrário, FALSE.

*bDetachable*<br/>
[em] TRUE para tornar a guia destacável; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel foi adicionado com sucesso como uma guia e não foi destruído no processo. FALSO se o painel a ser `CBaseTabbedPane`adicionado for um objeto de tipo . Para obter mais informações, consulte a seção Comentários.

### <a name="remarks"></a>Comentários

Chame este método para adicionar um painel como uma nova guia em um painel com guias. Se *pNewBar* aponta para `CBaseTabbedPane`um objeto de tipo, todas as guias são copiadas para o painel de guias e, em seguida, *pNewBar* é destruído. Assim, *pNewBar* torna-se um ponteiro inválido e não deve ser usado.

## <a name="cbasetabbedpaneallowdestroyemptytabbedpane"></a><a name="allowdestroyemptytabbedpane"></a>CBaseTabbedPane::PermitirDestroyDestroyEmptyTabbedPane

Especifica se um painel vazio pode ser destruído.

```
virtual BOOL AllowDestroyEmptyTabbedPane() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se um painel de abas vazio pode ser destruído; caso contrário, FALSE. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Se um painel de abas vazio não for permitido ser destruído, a estrutura oculta o painel em vez disso.

## <a name="cbasetabbedpaneapplyrestoredtabinfo"></a><a name="applyrestoredtabinfo"></a>CBaseTabbedPane::ApplyRestoredTabInfo

Carrega as configurações da guia do registro e aplica-as em um painel com guias.

```
virtual void ApplyRestoredTabInfo(BOOL bUseTabIndexes = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bUseTabIndexes*<br/>
[em] Este parâmetro é usado internamente pelo framework.

### <a name="remarks"></a>Comentários

Esse método é chamado pela estrutura quando recarrega as informações do estado de acoplamento do registro. O método obtém informações sobre ordem de guia e nomes de guias para um painel com guias.

## <a name="cbasetabbedpanecanfloat"></a><a name="canfloat"></a>CBaseTabbedPane::CanFloat

Especifica se o painel com abas pode flutuar.

```
virtual BOOL CanFloat() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se o painel pode flutuar; caso contrário, FALSE.

## <a name="cbasetabbedpanecansetcaptiontexttotabname"></a><a name="cansetcaptiontexttotabname"></a>CBaseTabbedPane:CanSetCaptionTextToTabName

Determina se a legenda do painel com guias deve exibir o mesmo texto da guia ativa.

```
virtual BOOL CanSetCaptionTextToTabName() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se o texto da legenda do painel com guias estiver definido para o texto da guia ativa; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O método é usado para determinar se o texto exibido na legenda do painel de guias duplica o rótulo da guia ativa. Você pode ativar ou desativar essa funcionalidade chamando [CBaseTabbedPane::EnableSetCaptionCaptionTextToTabName](#enablesetcaptiontexttotabname).

## <a name="cbasetabbedpaneconverttotabbeddocument"></a><a name="converttotabbeddocument"></a>CBaseTabbedPane::ConvertTo'TbedDocument

Converte um ou mais painéis ancoráveis em documentos com guias MDI.

```
virtual void ConvertToTabbedDocument(BOOL bActiveTabOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bActiveTabOnly*<br/>
[em] Ao converter um painel com guias, especifique TRUE para converter apenas a guia ativa. Especifique FALSO para converter todas as guias no painel.

## <a name="cbasetabbedpanedetachpane"></a><a name="detachpane"></a>CBaseTabbedPane::DetachPane

Destaca um painel do painel de abas.

```
virtual BOOL DetachPane(
    CWnd* pBar,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Pointer para o painel para soltar.

*bOcultar*<br/>
[em] Parâmetro booleano que especifica se a estrutura esconde o painel depois que ele é separado.

### <a name="return-value"></a>Valor retornado

VERDADE se a estrutura desprender com sucesso o painel; FALSE se *pBar* é NULL ou refere-se a um painel que não está no painel de abas.

### <a name="remarks"></a>Comentários

A estrutura flutua o painel destacado, se possível. Para obter mais informações, consulte [CBasePane::CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).

## <a name="cbasetabbedpaneenablesetcaptiontexttotabname"></a><a name="enablesetcaptiontexttotabname"></a>CBaseTabbedPane:EnableSetCaptionTextTo'sOnome

Ativa ou desativa a capacidade do painel de guias de sincronizar o texto da legenda com o texto do rótulo na guia ativa.

```
virtual void EnableSetCaptionTextToTabName(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para sincronizar a legenda do painel com a legenda ativa da guia; caso contrário, FALSE.

## <a name="cbasetabbedpanefilldefaulttabsorderarray"></a><a name="filldefaulttabsorderarray"></a>CBaseTabbedPane::FillDefaultTabsOrderArray

Restaura a ordem de guia interna em um estado padrão.

```cpp
void FillDefaultTabsOrderArray();
```

### <a name="remarks"></a>Comentários

Esse método é chamado quando a estrutura restaura uma barra do Outlook para um estado inicial.

## <a name="cbasetabbedpanefindpanebyid"></a><a name="findpanebyid"></a>CBaseTabbedPane::FindPaneByID

Devolve um painel identificado pelo painel ID.

```
virtual CWnd* FindPaneByID(UINT uBarID);
```

### <a name="parameters"></a>Parâmetros

*uBarID*<br/>
[em] Especifica o ID do painel para encontrar.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o painel se ele foi encontrado; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este método compara todas as guias no painel e retorna a com o ID especificado pelo parâmetro *uBarID.*

## <a name="cbasetabbedpanefindbarbytabnumber"></a><a name="findbarbytabnumber"></a>cbasetabbedpane::FindBarByTabNumber

Retorna um painel que reside em uma guia.

```
virtual CWnd* FindBarByTabNumber(
    int nTabNum,
    BOOL bGetWrappedBar = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nTabNum*<br/>
[em] Especifica o índice baseado em zero da guia a ser recuperado.

*bGetWrappedBar*<br/>
[em] TRUE para devolver a janela subjacente (embrulhada) do painel em vez do painel em si; caso contrário, FALSO. Isso só se aplica a painéis derivados de [CDockablePaneAdapter](../../mfc/reference/cdockablepaneadapter-class.md).

### <a name="return-value"></a>Valor retornado

Se o painel for encontrado, um ponteiro válido para o painel que está sendo pesquisado é devolvido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o painel que reside na guia especificada pelo parâmetro *nTabNum.*

## <a name="cbasetabbedpanefloattab"></a><a name="floattab"></a>CBaseTabbedPane::FloatTab

Flutua um painel, mas apenas se o painel reside atualmente em uma guia destacável.

```
virtual BOOL FloatTab(
    CWnd* pBar,
    int nTabID,
    AFX_DOCK_METHOD dockMethod,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[dentro, fora] Um ponteiro para o painel para flutuar.

*nTabID*<br/>
[em] Especifica o índice baseado em zero da guia para flutuar.

*Dockmethod*<br/>
[em] Especifica o método a ser usado para fazer o painel flutuar. Para obter mais informações, consulte a seção Comentários.

*bOcultar*<br/>
[em] VERDADE para esconder o painel antes de flutuar; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel flutuou; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame este método para flutuar um painel que atualmente reside em uma guia destacável.

Se você quiser desprender um painel programáticamente, especifique DM_SHOW para o parâmetro *dockMethod.* Se você quiser flutuar o painel na mesma posição onde ele flutuou anteriormente, especifique DM_DBL_CLICK como o parâmetro *dockMethod.*

## <a name="cbasetabbedpanegetdefaulttabsorder"></a><a name="getdefaulttabsorder"></a>CBaseTabbedPane::GetDefaultTabsOrder

Retorna a ordem padrão de guias no painel.

```
const CArray<int,int>& GetDefaultTabsOrder();
```

### <a name="return-value"></a>Valor retornado

Um `CArray` objeto que especifica a ordem padrão das guias no painel.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando uma barra do Outlook é redefinida para um estado inicial.

## <a name="cbasetabbedpanegetfirstvisibletab"></a><a name="getfirstvisibletab"></a>CBaseTabbedPane::GetFirstVisibleTab

Recupera um ponteiro para a primeira guia exibida.

```
virtual CWnd* GetFirstVisibleTab(int& iTabNum);
```

### <a name="parameters"></a>Parâmetros

*iTabNum*<br/>
[em] Uma referência a um inteiro. Este método grava o índice baseado em zero da primeira guia exibida para este parâmetro, ou -1 se nenhuma guia exibida for encontrada.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a primeira guia exibida; caso contrário, NULL.

## <a name="cbasetabbedpanegetminsize"></a><a name="getminsize"></a>CBaseTabbedPane::GetMinSize

Recupera o tamanho mínimo permitido para o painel.

```
virtual void GetMinSize(CSize& size) const;
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
[fora] Um `CSize` objeto que está preenchido com o tamanho mínimo permitido.

### <a name="remarks"></a>Comentários

Se o manuseio consistente dos tamanhos mínimos do painel estiver ativo [(CPane:m_bHandleMinSize),](../../mfc/reference/cpane-class.md#m_bhandleminsize)o *tamanho* será preenchido com o tamanho mínimo permitido para a guia ativa. Caso contrário, o *tamanho* será preenchido com o valor de retorno de [CPane::GetMinSize](../../mfc/reference/cpane-class.md#getminsize).

## <a name="cbasetabbedpanegetpaneicon"></a><a name="getpaneicon"></a>CBaseTabbedPane::GetPaneIcon

Recupera o tamanho mínimo permitido para o painel.

```
virtual void GetMinSize(CSize& size) const;
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
[fora] Um `CSize` objeto que está preenchido com o tamanho mínimo permitido.

### <a name="remarks"></a>Comentários

Se o manuseio consistente dos tamanhos mínimos do painel estiver ativo [(CPane:m_bHandleMinSize),](../../mfc/reference/cpane-class.md#m_bhandleminsize)o *tamanho* será preenchido com o tamanho mínimo permitido para a guia ativa. Caso contrário, o *tamanho* será preenchido com o valor de retorno de [CPane::GetMinSize](../../mfc/reference/cpane-class.md#getminsize).

## <a name="cbasetabbedpanegetpanelist"></a><a name="getpanelist"></a>CBaseTabbedPane::GetPaneList

Retorna uma lista de painéis que estão contidos no painel de guias.

```
virtual void GetPaneList(
    CObList& lst,
    CRuntimeClass* pRTCFilter = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lst*<br/>
[fora] Um `CObList` que é preenchido com os painéis que estão contidos no painel de abas.

*pRTCFilter*<br/>
[em] Se não for NULL, a lista retornada contém apenas painéis da classe de tempo de execução especificada.

## <a name="cbasetabbedpanegettabarea"></a><a name="gettabarea"></a>CBaseTabbedPane::GetTabArea

Retorna os retângulos delimitadores para as áreas de guia superior e inferior.

```
virtual void GetTabArea(
    CRect& rectTabAreaTop,
    CRect& rectTabAreaBottom) const = 0;
```

### <a name="parameters"></a>Parâmetros

*rectTabAreaTop*<br/>
[fora] Recebe as coordenadas de tela da área superior da guia.

*rectTabAreaBottom*<br/>
[fora] Recebe as coordenadas de tela da área inferior da guia.

### <a name="remarks"></a>Comentários

Chame este método para determinar os retângulos delimitadores, nas coordenadas da tela, para as áreas de guia superior e inferior.

## <a name="cbasetabbedpanegettabsnum"></a><a name="gettabsnum"></a>CBaseTabbedPane::GetTabsNum

Retorna a contagem de guias em uma janela de guia.

```
virtual int GetTabsNum() const;
```

### <a name="return-value"></a>Valor retornado

O número de abas no painel de abas.

## <a name="cbasetabbedpanegetunderlyingwindow"></a><a name="getunderlyingwindow"></a>CBaseTabbedPane::GetUnderlyingWindow

Obtém a janela de guia subjacente (embrulhada).

```
virtual CMFCBaseTabCtrl* GetUnderlyingWindow();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela de guia subjacente.

## <a name="cbasetabbedpanegetvisibletabsnum"></a><a name="getvisibletabsnum"></a>CBaseTabbedPane::GetVisibleTabsNum

Retorna a contagem de abas visíveis.

```
virtual int GetVisibleTabsNum() const;
```

### <a name="return-value"></a>Valor retornado

O número de abas visíveis, que será maior ou igual a zero.

### <a name="remarks"></a>Comentários

Chame este método para determinar o número de abas visíveis no painel com guias.

## <a name="cbasetabbedpanehasautohidemode"></a><a name="hasautohidemode"></a>CBaseTabbedPane::HasAutoHideMode

Determina se o painel com guias pode ser comutado para o modo de ocultação automática.

```
virtual BOOL HasAutoHideMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o painel puder ser comutado para o modo de ocultação automática; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o modo de ocultação automática estiver desativado, nenhum botão de pino será exibido na legenda do painel com guias.

## <a name="cbasetabbedpaneishidesingletab"></a><a name="ishidesingletab"></a>cbasetabbedpane::IsHideSingleTab

Determina se o painel com guias está oculto se apenas uma guia for exibida.

```
virtual BOOL IsHideSingleTab() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a janela da guia não for mostrada quando houver apenas uma guia visível; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o painel não for exibido porque apenas uma guia está aberta, você pode chamar este método para determinar se o painel com guias está funcionando corretamente.

## <a name="cbasetabbedpaneremovepane"></a><a name="removepane"></a>CBaseTabbedPane::RemovePane

Remove um painel do painel de abas.

```
virtual BOOL RemovePane(CWnd* pBar);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[dentro, fora] Um ponteiro para o painel para remover do painel de abas.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel foi removido com sucesso do painel com guias e se o painel de abas ainda estiver válido. FALSE se o último painel foi removido do painel de abas e o painel de abas está prestes a ser destruído. Se o valor de devolução for FALSO, não use mais o painel com guias.

### <a name="remarks"></a>Comentários

Chame este método para remover o painel especificado pelo parâmetro *pBar* do painel de guias.

## <a name="cbasetabbedpanesetautodestroy"></a><a name="setautodestroy"></a>CBaseTabbedPane::SetAutoDestroy

Determina se a barra de controle com guias será destruída automaticamente.

```cpp
void SetAutoDestroy(BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoDestroy*<br/>
[em] VERDADE se o painel de abas foi criado dinamicamente e você não está controlando sua vida útil; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Defina o modo de destruição automática como TRUE se você criar um painel com guias dinamicamente e se você não estiver controlando sua vida útil. Se o modo de destruição automática for TRUE, o painel com guias será destruído automaticamente pela estrutura.

## <a name="cbasetabbedpaneshowtab"></a><a name="showtab"></a>CBaseTabbedPane::ShowTab

Mostra ou esconde uma guia.

```
virtual BOOL ShowTab(
    CWnd* pBar,
    BOOL bShow,
    BOOL bDelay,
    BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para o painel para mostrar ou esconder.

*Bshow*<br/>
[em] VERDADE para mostrar o painel; FALSO para esconder o painel.

*bAtraso*<br/>
[em] TRUE para atrasar o ajuste do layout da guia; caso contrário, FALSE.

*bAtivar*<br/>
[em] TRUE para fazer a guia ativa da guia; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se a guia foi mostrada ou ocultacom sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando você chama esse método, um painel é mostrado ou oculto, dependendo do valor do parâmetro *bShow.* Se você ocultar uma guia e ela for a última aba visível na janela da guia subjacente, o painel com abas está oculto. Se você mostrar uma guia quando anteriormente não havia abas visíveis, o painel com guias será mostrado.

## <a name="cbasetabbedpanerecalclayout"></a><a name="recalclayout"></a>CBaseTabbedPane::RecalcLayout

Recalcula as informações de layout para o painel.

```
virtual void RecalcLayout();
```

### <a name="remarks"></a>Comentários

Se o painel estiver flutuando, este método notifica a estrutura para redimensionar o painel para o tamanho atual do miniquadro.

Se o painel está ancorado, este método não faz nada.

## <a name="cbasetabbedpanesetautohidemode"></a><a name="setautohidemode"></a>CBaseTabbedPane::SetAuto'SM

Define o modo de ocultação automática para painéis destacáveis no painel de abas.

```
virtual CMFCAutoHideToolBar* SetAutoHideMode(
    BOOL bMode,
    DWORD dwAlignment,
    CMFCAutoHideToolBar* pCurrAutoHideBar = NULL,
    BOOL bUseTimer = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bMode*<br/>
[em] TRUE para ativar o modo de ocultação automática; FALSE para habilitar o modo de acoplamento regular.

*Dwalignment*<br/>
[em] Especifica o alinhamento do painel de ocultação automática a ser criado. Para obter uma lista de valores possíveis, consulte [CPane::MoveByAlignment](../../mfc/reference/cpane-class.md#movebyalignment).

*pCurrAutoHideBar*<br/>
[dentro, fora] Um ponteiro para a barra de ferramentas de ocultação automática atual. Pode ser NULL.

*bUseTimer*<br/>
[em] Especifica se deve usar o efeito de ocultação automática quando o usuário alterna o painel para o modo de ocultação automática ou para ocultar o painel imediatamente.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a barra de ferramentas de ocultação automática que é criada ao mudar para o modo de ocultação automática ou NULL se nenhuma barra de ferramentas for criada.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando um usuário escolhe o botão de pino para mudar o painel de guias para o modo de ocultação automática ou para o modo de acoplamento regular.

O modo de ocultação automática está definido para cada painel destacável no painel de abas. Painéis que não são destacáveis são ignorados. Para obter mais informações, consulte [CMFCBaseTabCtrl::EnableTabDetach](../../mfc/reference/cmfcbasetabctrl-class.md#enabletabdetach).

Chame este método para alternar um painel com guias para ocultar automaticamente o modo de ocultação programática. O painel deve ser encaixado na janela principal do quadro [(CDockablePane::GetDefaultPaneDivider](../../mfc/reference/cdockablepane-class.md#getdefaultpanedivider) deve retornar um ponteiro válido para o [CPaneDivider](../../mfc/reference/cpanedivider-class.md)).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)
