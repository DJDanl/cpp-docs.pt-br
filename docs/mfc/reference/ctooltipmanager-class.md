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
ms.openlocfilehash: 37fcf47b7537e89974a61e6c50c41e164d555678
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365083"
---
# <a name="ctooltipmanager-class"></a>Classe CTooltipManager

Mantém informações de tempo de execução sobre dicas de ferramentas. A `CTooltipManager` classe é instanciada uma vez por aplicação.

## <a name="syntax"></a>Sintaxe

```
class CTooltipManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTooltipManager::CreateToolTip](#createtooltip)|Cria um controle de ponta de ferramenta para os tipos de controle do Windows especificados.|
|[CTooltipManager::DeleteToolTip](#deletetooltip)|Exclui um controle de ponta de ferramenta.|
|[CTooltipManager::SetTooltipParams](#settooltipparams)|Personaliza a aparência visual do controle de ponta de ferramenta para os tipos de controle do Windows especificados.|
|[CTooltipManager::SetTooltipText](#settooltiptext)|Define o texto e a descrição para um controle de ponta de ferramenta.|
|[CTooltipManager::Dicas de ferramentas de atualização](#updatetooltips)||

## <a name="remarks"></a>Comentários

Use [cmfctoolTipctrl](../../mfc/reference/cmfctooltipctrl-class.md) `CMFCToolTipInfo`class `CTooltipManager` , e em conjunto para implementar dicas de ferramentas personalizadas em sua aplicação. Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o tópico [CMFCToolTipCtrl Class.](../../mfc/reference/cmfctooltipctrl-class.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ctooltipmanager](../../mfc/reference/ctooltipmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtooltipmanager.h

## <a name="ctooltipmanagercreatetooltip"></a><a name="createtooltip"></a>CTooltipManager::CreateToolTip

Cria um controle de ponta de ferramenta.

```
static BOOL CreateToolTip(
    CToolTipCtrl*& pToolTip,
    CWnd* pWndParent,
    UINT nType);
```

### <a name="parameters"></a>Parâmetros

*ponta de ferramenta*<br/>
[fora] Uma referência a um ponteiro de dica de ferramenta. Ele é definido para apontar para a dica de ferramenta recém-criada quando a função retorna.

*pWndParent*<br/>
[em] Pai da dica de ferramenta.

*nType*<br/>
[em] Tipo da dica de ferramenta.

### <a name="return-value"></a>Valor retornado

Não zero se uma dica de ferramenta foi criada com sucesso.

### <a name="remarks"></a>Comentários

Você deve chamar [CTooltipManager::DeleteToolTip](#deletetooltip) para excluir o controle de ponta de ferramenta que é passado para trás em *pToolTip*.

O [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) define os parâmetros de exibição visual de cada dica de ferramenta que cria com base no tipo de dica de ferramenta *especificada.* Para alterar os parâmetros de um ou mais tipos de ponta de ferramenta, ligue para [CTooltipManager::SetTooltipParams](#settooltipparams).

Os tipos de dicas de ferramentas válidos estão listados na tabela a seguir:

|Tipo de ponta de ferramenta|Categoria de controle|Tipos de exemplo|
|------------------|----------------------|-------------------|
|AFX_TOOLTIP_TYPE_BUTTON|Um botão.|Cmfcbutton|
|AFX_TOOLTIP_TYPE_CAPTIONBAR|Uma barra de legendas.|CMFCCaptionBar|
|AFX_TOOLTIP_TYPE_DEFAULT|Qualquer controle que não se encaixe em outra categoria.|Nenhum.|
|AFX_TOOLTIP_TYPE_DOCKBAR|Um painel ancorável.|Cdockablepane|
|AFX_TOOLTIP_TYPE_EDIT|Uma caixa de texto.|Nenhum.|
|AFX_TOOLTIP_TYPE_MINIFRAME|Um miniquadro.|CPaneFrameWnd|
|AFX_TOOLTIP_TYPE_PLANNER|Um planejador.|Nenhum.|
|AFX_TOOLTIP_TYPE_RIBBON|Uma barra de fita.|CMFCRibbonBar, CMFCRibbonPanelMenuBar|
|AFX_TOOLTIP_TYPE_TAB|Um controle de aba.|Cmfctabctrl|
|AFX_TOOLTIP_TYPE_TOOLBAR|Uma barra de ferramentas.|CMFCToolBar, CMFCPopupMenuBar|
|AFX_TOOLTIP_TYPE_TOOLBOX|Uma caixa de ferramentas.|Nenhum.|

## <a name="ctooltipmanagerdeletetooltip"></a><a name="deletetooltip"></a>CTooltipManager::DeleteToolTip

Exclui um controle de ponta de ferramenta.

```
static void DeleteToolTip(CToolTipCtrl*& pToolTip);
```

### <a name="parameters"></a>Parâmetros

*ponta de ferramenta*<br/>
[dentro, fora] Uma referência a um ponteiro para uma dica de ferramenta a ser destruída.

### <a name="remarks"></a>Comentários

Chame este método para cada [Classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) que foi criada por [CTooltipManager::CreateToolTip](#createtooltip). O controle pai deve chamar `OnDestroy` este método de seu manipulador. Isso é necessário para remover corretamente a ponta da ferramenta da estrutura. Este método define *pToolTip* para NULL antes de retornar.

## <a name="ctooltipmanagersettooltipparams"></a><a name="settooltipparams"></a>CTooltipManager::SetTooltipParams

Personaliza a aparência do controle de ponta de ferramenta para os tipos de controle do Windows especificados.

```
void SetTooltipParams(
    UINT nTypes,
    CRuntimeClass* pRTC=RUNTIME_CLASS(CMFCToolTipCtrl),
    CMFCToolTipInfo* pParams=NULL);
```

### <a name="parameters"></a>Parâmetros

*nTipos*<br/>
[em] Especifica tipos de controle.

*pRTC*<br/>
[em] Classe de tempo de execução de dica de ferramenta personalizada.

*Pparams*<br/>
[em] Parâmetros da dica da ferramenta.

### <a name="remarks"></a>Comentários

Este método define a classe de tempo de execução e os parâmetros iniciais que o [CToolTipManager](../../mfc/reference/ctooltipmanager-class.md) usa quando cria dicas de ferramentas. Quando um controle chama [CTooltipManager::CreateToolTip](#createtooltip) e passa em um tipo de dica de ferramenta que é um dos tipos indicados por *nTypes,* o gerenciador de pontas de ferramenta cria um controle de ponta de ferramenta que é uma instância da classe de tempo de execução especificada pelo *pRTC* e passa os parâmetros especificados pelos *pParams* para a nova dica de ferramenta.

Quando você chama esse método, todos os proprietários de dicas de ferramentas existentes recebem a mensagem AFX_WM_UPDATETOOLTIPS e devem recriar suas dicas de ferramentas usando [CTooltipManager::CreateToolTip](#createtooltip).

*nTipos* podem ser qualquer combinação dos tipos de dicas de ferramentas válidos que [o CTooltipManager::CreateToolTip](#createtooltip) usa, ou pode ser AFX_TOOLTIP_TYPE_ALL. Se você passar AFX_TOOLTIP_TYPE_ALL, todos os tipos de pontas de ferramenta serão afetados.

### <a name="example"></a>Exemplo

O exemplo a seguir `SetTooltipParams` demonstra como `CTooltipManager` usar o método da classe. Este trecho de código faz parte da [amostra Draw Client](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#11](../../mfc/reference/codesnippet/cpp/ctooltipmanager-class_1.cpp)]

## <a name="ctooltipmanagersettooltiptext"></a><a name="settooltiptext"></a>CTooltipManager::SetTooltipText

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

*Pti*<br/>
[em] Um ponteiro para um objeto TOOLINFO.

*ponta de ferramenta*<br/>
[dentro, fora] Um ponteiro para o controle da dica de ferramenta para o qual definir o texto e a descrição.

*nType*<br/>
[em] Especifica o tipo de controle com o qual esta dica de ferramenta está associada.

*strText*<br/>
[em] O texto a ser definido como o texto da dica de ferramenta.

*lpszDescr*<br/>
[em] Um ponteiro para a descrição da dica da ferramenta. Pode ser NULL.

### <a name="remarks"></a>Comentários

O valor do *nType* deve ser o mesmo valor do parâmetro *nType* do [CTooltipManager::CreateToolTip](#createtooltip) quando você criou a dica de ferramenta.

## <a name="ctooltipmanagerupdatetooltips"></a><a name="updatetooltips"></a>CTooltipManager::Dicas de ferramentas de atualização

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
void UpdateTooltips();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)<br/>
[Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)
