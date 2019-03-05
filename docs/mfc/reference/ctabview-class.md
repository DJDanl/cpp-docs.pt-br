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
ms.openlocfilehash: 5ac62d04c38dbddda90d2f33a9c14c9c131fcd9c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326589"
---
# <a name="ctabview-class"></a>Classe CTabView

O `CTabView` classe simplifica o uso da classe de controle de guia ( [CMFCTabCtrl](../../mfc/reference/ctabview-class.md)) em aplicativos que usam a arquitetura de documento/exibição do MFC.

## <a name="syntax"></a>Sintaxe

```
class CTabbedView : public CView
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTabView::AddView](#addview)|Adiciona um novo modo de exibição para o controle de guia.|
|[CTabView::FindTab](#findtab)|Retorna o índice da exibição especificada no controle guia.|
|[CTabView::GetActiveView](#getactiveview)|Retorna um ponteiro para a exibição ativa no momento|
|[CTabView::GetTabControl](#gettabcontrol)|Retorna uma referência para o controle de guia associado com o modo de exibição.|
|[CTabView::RemoveView](#removeview)|Remove a exibição do controle guia.|
|[CTabView::SetActiveView](#setactiveview)|Ativa um modo de exibição.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CTabView::IsScrollBar](#isscrollbar)|Chamado pelo framework durante a criação de um modo de exibição de guia para determinar se o modo de exibição da guia tem uma barra de rolagem horizontal compartilhado.|
|[CTabView::OnActivateView](#onactivateview)|Chamado pelo framework quando o modo de exibição de guia é feito ativo ou inativo.|

## <a name="remarks"></a>Comentários

Essa classe facilita a colocar uma exibição com guias em um aplicativo de documento/exibição. `CTabView` é um `CView`-derivado da classe que contém um embedded `CMFCTabCtrl` objeto. `CTabView` manipula todas as mensagens necessárias para dar suporte a `CMFCTabCtrl` objeto. Simplesmente derive uma classe de `CTabView` e conectá-lo ao seu aplicativo e, em seguida, adicione `CView`-as classes derivadas usando o `AddView` método. O controle de guia exibirá esses modos de exibição como guias.

Por exemplo, você pode ter um documento que pode ser representado de formas diferentes: como uma planilha, um gráfico, um formulário editável e assim por diante. Você pode criar exibições individuais, os dados de desenho, conforme necessário, inseri-los em seu `CTabView`-objeto derivado e tê-las com guias sem qualquer codificação adicional.

[Exemplo de TabbedView: Aplicativo de exibição com guias MFC](../../visual-cpp-samples.md) ilustra o uso de `CTabView`.

## <a name="example"></a>Exemplo

A exemplo a seguir mostra como `CTabView` é usada no exemplo TabbedView.

[!code-cpp[NVC_MFC_TabbedView#1](../../mfc/reference/codesnippet/cpp/ctabview-class_1.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxTabView.h

##  <a name="addview"></a>  CTabView::AddView

Adiciona um modo de exibição para o controle de guia.

```
int AddView(
    CRuntimeClass* pViewClass,
    const CString& strViewLabel,
    int iIndex=-1,
    CCreateContext* pContext=NULL);
```

### <a name="parameters"></a>Parâmetros

*pViewClass*<br/>
[in] Um ponteiro para uma classe de tempo de execução do modo de exibição inserida.

*strViewLabel*<br/>
[in] Especifica o texto da guia.

*iIndex*<br/>
[in] Especifica a posição de base zero no qual inserir o modo de exibição. Se a posição é -1, que a nova guia é inserida no final.

*pContext*<br/>
[in] Um ponteiro para o `CCreateContext` do modo de exibição.

### <a name="return-value"></a>Valor de retorno

Um índice de exibição se esse método for bem-sucedido. Otherwise, -1.

### <a name="remarks"></a>Comentários

Chame essa função para adicionar um modo de exibição para o controle de guia que está inserido em um quadro.

##  <a name="findtab"></a>  CTabView::FindTab

Retorna o índice da exibição especificada no controle guia.

```
int FindTab(HWND hWndView) const;
```

### <a name="parameters"></a>Parâmetros

*hWndView*<br/>
[in] O identificador da exibição.

### <a name="return-value"></a>Valor de retorno

O índice da exibição se ela for encontrada; Caso contrário, -1.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o índice de uma exibição que tem um identificador especificado.

##  <a name="getactiveview"></a>  CTabView::GetActiveView

Retorna um ponteiro para a exibição ativa no momento.

```
CView* GetActiveView() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para o modo de exibição ativo, ou nulo se não houver nenhum modo de exibição ativo.

### <a name="remarks"></a>Comentários

##  <a name="gettabcontrol"></a>  CTabView::GetTabControl

Retorna uma referência para o controle de guia associado com o modo de exibição.

```
DECLARE_DYNCREATE CMFCTabCtrl& GetTabControl();
```

### <a name="return-value"></a>Valor de retorno

Uma referência para o controle de guia associado com o modo de exibição.

##  <a name="isscrollbar"></a>  CTabView::IsScrollBar

Chamado pelo framework durante a criação de um modo de exibição de guia para determinar se o modo de exibição da guia tem uma barra de rolagem horizontal compartilhado.

```
virtual BOOL IsScrollBar() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o modo de exibição de guia deve ser criado junto com uma barra de rolagem compartilhado. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O framework chama esse método quando um *CTabView* objeto está sendo criado.

Substituir a *IsScrollBar* método em um *CTabView*-classe derivada e retornar TRUE, se você quiser criar uma exibição que tem uma barra de rolagem horizontal compartilhado.

##  <a name="onactivateview"></a>  CTabView::OnActivateView

Chamado pelo framework quando o modo de exibição de guia é feito ativo ou inativo.

```
virtual void OnActivateView(CView* view);
```

### <a name="parameters"></a>Parâmetros

*modo de exibição*<br/>
[in] Um ponteiro para o modo de exibição.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Substitua este método em um `CTabView`-derivado da classe para processar essa notificação.

##  <a name="removeview"></a>  CTabView::RemoveView

Remove a exibição do controle guia.

```
BOOL RemoveView(int iTabNum);
```

### <a name="parameters"></a>Parâmetros

*iTabNum*<br/>
[in] O índice da exibição a ser removida.

### <a name="return-value"></a>Valor de retorno

O índice da exibição removido se esse método for bem-sucedido. Caso contrário,-1.

### <a name="remarks"></a>Comentários

##  <a name="setactiveview"></a>  CTabView::SetActiveView

Ativa um modo de exibição.

```
BOOL SetActiveView(int iTabNum);
```

### <a name="parameters"></a>Parâmetros

*iTabNum*<br/>
[in] O índice baseado em zero da exibição de guia.

### <a name="return-value"></a>Valor de retorno

TRUE se o modo de exibição especificado tiver sido feito ativo, FALSO se o índice da exibição é inválido.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [CMFCTabCtrl::SetActiveTab](../../mfc/reference/cmfctabctrl-class.md#setactivetab).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[CMFCTabCtrl](../../mfc/reference/ctabview-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)
