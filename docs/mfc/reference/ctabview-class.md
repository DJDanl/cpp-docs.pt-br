---
title: Classe CTabView
ms.date: 11/04/2016
f1_keywords:
- CTabView
- AFXTABVIEW/CTabView
- AFXTABVIEW/CTabView::AddView
- AFXTABVIEW/CTabView::FindTab
- AFXTABVIEW/CTabView::GetActiveView
- AFXTABVIEW/CTabView::GetTabControl
- AFXTABVIEW/CTabView::RemoveView
- AFXTABVIEW/CTabView::SetActiveView
- AFXTABVIEW/CTabView::IsScrollBar
- AFXTABVIEW/CTabView::OnActivateView
helpviewer_keywords:
- CTabView [MFC], AddView
- CTabView [MFC], FindTab
- CTabView [MFC], GetActiveView
- CTabView [MFC], GetTabControl
- CTabView [MFC], RemoveView
- CTabView [MFC], SetActiveView
- CTabView [MFC], IsScrollBar
- CTabView [MFC], OnActivateView
ms.assetid: 8e6ecd9d-d28d-432b-8ec8-0446f0204d52
ms.openlocfilehash: ad30cbbf5de195708d2d357a76c38b661d095c2f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365916"
---
# <a name="ctabview-class"></a>Classe CTabView

A `CTabView` classe simplifica o uso da classe de controle de guias [(CMFCTabCtrl)](../../mfc/reference/ctabview-class.md)em aplicativos que usam a arquitetura de documentos/exibição do MFC.

## <a name="syntax"></a>Sintaxe

```
class CTabbedView : public CView
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CtabView::AddView](#addview)|Adiciona uma nova visão ao controle da guia.|
|[CtabView::Findtab](#findtab)|Retorna o índice da exibição especificada no controle da guia.|
|[Ctabview::GetActiveView](#getactiveview)|Retorna um ponteiro para a exibição ativa atualmente|
|[CtabView::GetTabControl](#gettabcontrol)|Retorna uma referência ao controle de guia associado à exibição.|
|[CtabView::RemoveView](#removeview)|Remove a exibição do controle da guia.|
|[CtabView::SetActiveView](#setactiveview)|Faz uma visão ativa.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CtabView::IsScrollBar](#isscrollbar)|Chamado pela estrutura ao criar uma exibição de guia para determinar se a exibição da guia tem uma barra de rolagem horizontal compartilhada.|
|[CtabView::OnActivateView](#onactivateview)|Chamado pelo framework quando a exibição da guia é feita ativa ou inativa.|

## <a name="remarks"></a>Comentários

Esta classe facilita a colocação de uma exibição com guias em um aplicativo de documento/exibição. `CTabView`é `CView`uma classe derivada que `CMFCTabCtrl` contém um objeto incorporado. `CTabView`lida com todas as mensagens necessárias para suportar o `CMFCTabCtrl` objeto. Basta derivar `CTabView` uma classe e conectá-la à sua aplicação e, em seguida, adicionar `CView`classes derivadas usando o `AddView` método. O controle de guias exibirá essas exibições como guias.

Por exemplo, você pode ter um documento que pode ser representado de diferentes maneiras: como uma planilha, um gráfico, um formulário editável e assim por diante. Você pode criar visualizações individuais desenhando os `CTabView`dados conforme necessário, inseri-los em seu objeto derivado e tê-los guiados sem qualquer codificação adicional.

[Amostra de TabbedView: O aplicativo de exibição com guias MFC](../../overview/visual-cpp-samples.md) ilustra o uso de `CTabView`.

## <a name="example"></a>Exemplo

O exemplo a `CTabView` seguir mostra como é usado na amostra TabbedView.

[!code-cpp[NVC_MFC_TabbedView#1](../../mfc/reference/codesnippet/cpp/ctabview-class_1.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxTabView.h

## <a name="ctabviewaddview"></a><a name="addview"></a>CtabView::AddView

Adiciona uma visão ao controle da guia.

```
int AddView(
    CRuntimeClass* pViewClass,
    const CString& strViewLabel,
    int iIndex=-1,
    CCreateContext* pContext=NULL);
```

### <a name="parameters"></a>Parâmetros

*pViewClass*<br/>
[em] Um ponteiro para uma classe de tempo de execução da visualização inserida.

*strViewLabel*<br/>
[em] Especifica o texto da guia.

*Iindex*<br/>
[em] Especifica a posição baseada em zero para inserir a exibição. Se a posição for -1, a nova guia será inserida no final.

*pContext*<br/>
[em] Um ponteiro `CCreateContext` para a vista.

### <a name="return-value"></a>Valor retornado

Um índice de exibição se esse método for bem sucedido. Caso contrário, -1.

### <a name="remarks"></a>Comentários

Chame esta função para adicionar uma exibição ao controle de guia sinuoso em um quadro.

## <a name="ctabviewfindtab"></a><a name="findtab"></a>CtabView::Findtab

Retorna o índice da exibição especificada no controle da guia.

```
int FindTab(HWND hWndView) const;
```

### <a name="parameters"></a>Parâmetros

*hWndView*<br/>
[em] A alça da vista.

### <a name="return-value"></a>Valor retornado

O índice da vista se for encontrada; caso contrário, -1.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar o índice de uma exibição que tenha uma alça especificada.

## <a name="ctabviewgetactiveview"></a><a name="getactiveview"></a>Ctabview::GetActiveView

Retorna um ponteiro à exibição ativa no momento.

```
CView* GetActiveView() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para a exibição ativa ou NULL se não houver exibição ativa.

### <a name="remarks"></a>Comentários

## <a name="ctabviewgettabcontrol"></a><a name="gettabcontrol"></a>CtabView::GetTabControl

Retorna uma referência ao controle de guia associado à exibição.

```
DECLARE_DYNCREATE CMFCTabCtrl& GetTabControl();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao controle da guia associada à exibição.

## <a name="ctabviewisscrollbar"></a><a name="isscrollbar"></a>CtabView::IsScrollBar

Chamado pela estrutura ao criar uma exibição de guia para determinar se a exibição da guia tem uma barra de rolagem horizontal compartilhada.

```
virtual BOOL IsScrollBar() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a exibição da guia for criada em conjunto com uma barra de rolagem compartilhada. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando um objeto *CTabView* está sendo criado.

Substituir o método *IsScrollBar* em uma classe derivada do *CTabView*e retornar TRUE se você quiser criar uma exibição que tenha uma barra de rolagem horizontal compartilhada.

## <a name="ctabviewonactivateview"></a><a name="onactivateview"></a>CtabView::OnActivateView

Chamado pelo framework quando a exibição da guia é feita ativa ou inativa.

```
virtual void OnActivateView(CView* view);
```

### <a name="parameters"></a>Parâmetros

*Ver*<br/>
[em] Um ponteiro para a vista.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Anular este método `CTabView`em uma classe derivada para processar esta notificação.

## <a name="ctabviewremoveview"></a><a name="removeview"></a>CtabView::RemoveView

Remove a exibição do controle da guia.

```
BOOL RemoveView(int iTabNum);
```

### <a name="parameters"></a>Parâmetros

*iTabNum*<br/>
[em] O índice da vista para remover.

### <a name="return-value"></a>Valor retornado

O índice da exibição removida se este método for bem sucedido. Caso contrário , -1.

### <a name="remarks"></a>Comentários

## <a name="ctabviewsetactiveview"></a><a name="setactiveview"></a>CtabView::SetActiveView

Faz uma visão ativa.

```
BOOL SetActiveView(int iTabNum);
```

### <a name="parameters"></a>Parâmetros

*iTabNum*<br/>
[em] O índice baseado em zero da exibição da guia.

### <a name="return-value"></a>Valor retornado

TRUE se a exibição especificada estiver ativa, FALSA se o índice da exibição for inválido.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [CMFCTabCtrl::SetActiveTab](../../mfc/reference/cmfctabctrl-class.md#setactivetab).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Cmfctabctrl](../../mfc/reference/ctabview-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)
