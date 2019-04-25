---
title: Classe CTooltipManager
ms.date: 11/04/2016
f1_keywords:
- CTooltipManager
- AFXTOOLTIPMANAGER/CTooltipManager
- AFXTOOLTIPMANAGER/CTooltipManager::CreateToolTip
- AFXTOOLTIPMANAGER/CTooltipManager::DeleteToolTip
- AFXTOOLTIPMANAGER/CTooltipManager::SetTooltipParams
- AFXTOOLTIPMANAGER/CTooltipManager::SetTooltipText
- AFXTOOLTIPMANAGER/CTooltipManager::UpdateTooltips
helpviewer_keywords:
- CTooltipManager [MFC], CreateToolTip
- CTooltipManager [MFC], DeleteToolTip
- CTooltipManager [MFC], SetTooltipParams
- CTooltipManager [MFC], SetTooltipText
- CTooltipManager [MFC], UpdateTooltips
ms.assetid: c71779d7-8b6e-47ef-8500-d4552731fe86
ms.openlocfilehash: e8b88f2722f5a4379276f13c2ef159aa4d120533
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62323746"
---
# <a name="ctooltipmanager-class"></a>Classe CTooltipManager

Mantém informações de tempo de execução sobre dicas de ferramenta. O `CTooltipManager` classe é instanciada uma vez por aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CTooltipManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTooltipManager::CreateToolTip](#createtooltip)|Cria um controle de dica de ferramenta para os tipos de controle do Windows especificados.|
|[CTooltipManager::DeleteToolTip](#deletetooltip)|Exclui um controle de dica de ferramenta.|
|[CTooltipManager::SetTooltipParams](#settooltipparams)|Personaliza a aparência visual do controle de dica de ferramenta para os tipos de controle do Windows especificados.|
|[CTooltipManager::SetTooltipText](#settooltiptext)|Define o texto e a descrição de um controle de dica de ferramenta.|
|[CTooltipManager::UpdateTooltips](#updatetooltips)||

## <a name="remarks"></a>Comentários

Use [classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md), `CMFCToolTipInfo`, e `CTooltipManager` juntos para implementar dicas de ferramenta personalizadas em seu aplicativo. Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o [classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md) tópico.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtooltipmanager.h

##  <a name="createtooltip"></a>  CTooltipManager::CreateToolTip

Cria um controle de dica de ferramenta.

```
static BOOL CreateToolTip(
    CToolTipCtrl*& pToolTip,
    CWnd* pWndParent,
    UINT nType);
```

### <a name="parameters"></a>Parâmetros

*pToolTip*<br/>
[out] Uma referência a um ponteiro de dica de ferramenta. Ele é definido para apontar para a dica de ferramenta criada recentemente quando a função retorna.

*pWndParent*<br/>
[in] Pai da dica de ferramenta.

*nType*<br/>
[in] Tipo de dica de ferramenta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se uma dica de ferramenta foi criada com êxito.

### <a name="remarks"></a>Comentários

Você deve chamar [CTooltipManager::DeleteToolTip](#deletetooltip) para excluir o controle de dica de ferramenta é repassado na *pToolTip*.

O [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) define os parâmetros de exibição visual de cada dica de ferramenta que ele cria com base na dica de ferramenta do tipo que *nType* especifica. Para alterar os parâmetros para um ou mais tipos de dica de ferramenta, chame [CTooltipManager::SetTooltipParams](#settooltipparams).

Tipos de dica de ferramenta válidos estão listados na tabela a seguir:

|Tipo de dica de ferramenta|Categoria de controle|Tipos de exemplo|
|------------------|----------------------|-------------------|
|AFX_TOOLTIP_TYPE_BUTTON|Um botão.|CMFCButton|
|AFX_TOOLTIP_TYPE_CAPTIONBAR|Uma barra de legenda.|CMFCCaptionBar|
|AFX_TOOLTIP_TYPE_DEFAULT|Qualquer controle que não se ajusta a outra categoria.|nenhuma.|
|AFX_TOOLTIP_TYPE_DOCKBAR|Um painel encaixável.|CDockablePane|
|AFX_TOOLTIP_TYPE_EDIT|Uma caixa de texto.|nenhuma.|
|AFX_TOOLTIP_TYPE_MINIFRAME|Um miniquadros.|CPaneFrameWnd|
|AFX_TOOLTIP_TYPE_PLANNER|Um planejamento.|nenhuma.|
|AFX_TOOLTIP_TYPE_RIBBON|Uma barra de faixa de opções.|CMFCRibbonBar, CMFCRibbonPanelMenuBar|
|AFX_TOOLTIP_TYPE_TAB|Um controle guia.|CMFCTabCtrl|
|AFX_TOOLTIP_TYPE_TOOLBAR|Uma barra de ferramentas.|CMFCToolBar, CMFCPopupMenuBar|
|AFX_TOOLTIP_TYPE_TOOLBOX|Uma caixa de ferramentas.|nenhuma.|

##  <a name="deletetooltip"></a>  CTooltipManager::DeleteToolTip

Exclui um controle de dica de ferramenta.

```
static void DeleteToolTip(CToolTipCtrl*& pToolTip);
```

### <a name="parameters"></a>Parâmetros

*pToolTip*<br/>
[no, out] Uma referência a um ponteiro para uma dica de ferramenta a ser destruído.

### <a name="remarks"></a>Comentários

Chame esse método para cada [classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) que foi criado por [CTooltipManager::CreateToolTip](#createtooltip). O controle pai deve chamar esse método de seu `OnDestroy` manipulador. Isso é necessário para remover corretamente a dica de ferramenta do framework. Esse método define *pToolTip* para nulo antes de retornar.

##  <a name="settooltipparams"></a>  CTooltipManager::SetTooltipParams

Personaliza a aparência do controle de dica de ferramenta para os tipos de controle do Windows especificados.

```
void SetTooltipParams(
    UINT nTypes,
    CRuntimeClass* pRTC=RUNTIME_CLASS(CMFCToolTipCtrl),
    CMFCToolTipInfo* pParams=NULL);
```

### <a name="parameters"></a>Parâmetros

*nTypes*<br/>
[in] Especifica os tipos de controle.

*pRTC*<br/>
[in] Classe de tempo de execução de dica de ferramenta personalizada.

*pParams*<br/>
[in] Parâmetros de dica de ferramenta.

### <a name="remarks"></a>Comentários

Esse método define a classe de tempo de execução e os parâmetros iniciais que o [CToolTipManager](../../mfc/reference/ctooltipmanager-class.md) usa quando ele cria as dicas de ferramenta. Quando um controle chama [CTooltipManager::CreateToolTip](#createtooltip) e passa em uma dica de ferramenta tipo que é um dos tipos de indicado pelo *nTypes*, o Gerenciador de dica de ferramenta cria um controle de dica de ferramenta que é uma instância das classe de tempo de execução especificado por *pRTC* e passa os parâmetros especificados pelo *pParams* à nova dica de ferramenta.

Quando você chamar esse método, todos os proprietários existentes de dica de ferramenta a mensagem AFX_WM_UPDATETOOLTIPS e eles devem recriar suas dicas de ferramenta usando [CTooltipManager::CreateToolTip](#createtooltip).

*nTypes* pode ser qualquer combinação de dica de ferramenta válida tipos aos quais [CTooltipManager::CreateToolTip](#createtooltip) usa, ou pode ser AFX_TOOLTIP_TYPE_ALL. Se você passar AFX_TOOLTIP_TYPE_ALL, todos os tipos de dica de ferramenta são afetados.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `SetTooltipParams` método da `CTooltipManager` classe. Este trecho de código é parte do [desenhar o cliente de exemplo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#11](../../mfc/reference/codesnippet/cpp/ctooltipmanager-class_1.cpp)]

##  <a name="settooltiptext"></a>  CTooltipManager::SetTooltipText

Define o texto e a descrição para uma dica de ferramenta.

```
static void SetTooltipText(
    TOOLINFO* pTI,
    CToolTipCtrl* pToolTip,
    UINT nType,
    const CString strText,
    LPCTSTR lpszDescr=NULL);
```

### <a name="parameters"></a>Parâmetros

*pTI*<br/>
[in] Um ponteiro para um objeto TOOLINFO.

*pToolTip*<br/>
[no, out] Um ponteiro para o controle de dica de ferramenta para o qual definir o texto e a descrição.

*nType*<br/>
[in] Especifica o tipo de controle ao qual esta dica de ferramenta está associada.

*strText*<br/>
[in] O texto a ser definido como o texto de dica de ferramenta.

*lpszDescr*<br/>
[in] Um ponteiro para a descrição da dica de ferramenta. Pode ser NULL.

### <a name="remarks"></a>Comentários

O valor de *nType* deve ser o mesmo valor que o *nType* parâmetro do [CTooltipManager::CreateToolTip](#createtooltip) quando criou a dica de ferramenta.

##  <a name="updatetooltips"></a>  CTooltipManager::UpdateTooltips

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
void UpdateTooltips();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)<br/>
[Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)
