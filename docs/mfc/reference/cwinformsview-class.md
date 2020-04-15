---
title: Classe CWinFormsView
ms.date: 11/04/2016
f1_keywords:
- CWinFormsView
- AFXWINFORMS/CWinFormsView
- AFXWINFORMS/CWinFormsView::CWinFormsView
- AFXWINFORMS/CWinFormsView::GetControl
helpviewer_keywords:
- CWinFormsView [MFC], CWinFormsView
- CWinFormsView [MFC], GetControl
ms.assetid: d597e397-6529-469b-88f5-7f65a6b9e895
ms.openlocfilehash: 6eb6b9e385e9dbc96eb3b62ffb80909e54569e97
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369600"
---
# <a name="cwinformsview-class"></a>Classe CWinFormsView

Fornece funcionalidade genérica para hospedagem de um controle do Windows Forms como uma exibição de MFC.

## <a name="syntax"></a>Sintaxe

```
class CWinFormsView : public CView;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CwinFormsView::CWinFormsView](#cwinformsview)|Constrói um objeto `CWinFormsView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsView::GetControl](#getcontrol)|Recupera um ponteiro para o controle do Windows Forms.|

### <a name="public-operators"></a>Operadores públicos

|Nome||
|----------|-|
|[CWinFormsView::controle do operador^](#operator_control)|Lança um tipo como ponteiro para um controle do Windows Forms.|

## <a name="remarks"></a>Comentários

O MFC `CWinFormsView` usa a classe para hospedar um controle .NET Framework Windows Forms dentro de uma exibição de MFC. O controle é uma criança da visão nativa e ocupa toda a área cliente da vista do MFC. O resultado é `CFormView` semelhante a uma exibição, permitindo que você aproveite o designer do Windows Forms e execute o tempo para criar visualizações ricas baseadas em formulários.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

> [!NOTE]
> A integração do MFC Windows Forms funciona apenas em projetos que se conectam dinamicamente com o MFC (projetos nos quais o AFXDLL é definido).

> [!NOTE]
> O CWinFormsView não suporta a janela do divisor MFC [(CSplitterWnd Class).](../../mfc/reference/csplitterwnd-class.md) Atualmente, apenas o controle do Splitter do Windows Forms é suportado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

## <a name="cwinformsviewcwinformsview"></a><a name="cwinformsview"></a>CwinFormsView::CWinFormsView

Constrói um objeto `CWinFormsView`.

```
CWinFormsView(System::Type^ pManagedViewType);
```

### <a name="parameters"></a>Parâmetros

*pManagedViewType*<br/>
Um ponteiro para o tipo de dados do controle de usuário do Windows Forms.

### <a name="example"></a>Exemplo

No exemplo a `CUserView` seguir, a `CWinFormsView` classe herda `UserControl1` e `CWinFormsView` passa o tipo de para o construtor. `UserControl1`é um controle personalizado em ControlLibrary1.dll.

[!code-cpp[NVC_MFC_Managed#1](../../mfc/reference/codesnippet/cpp/cwinformsview-class_1.h)]

[!code-cpp[NVC_MFC_Managed#2](../../mfc/reference/codesnippet/cpp/cwinformsview-class_2.cpp)]

## <a name="cwinformsviewgetcontrol"></a><a name="getcontrol"></a>CWinFormsView::GetControl

Recupera um ponteiro para o controle do Windows Forms.

```
System::Windows::Forms::Control^ GetControl() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `System.Windows.Forms.Control`.

### <a name="remarks"></a>Comentários

Para um exemplo de como usar o Windows Forms, consulte [Usando um Controle de Usuário do Formulário Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="cwinformsviewoperator-control"></a><a name="operator_control"></a>CWinFormsView::controle do operador^

Lança um tipo como ponteiro para um controle do Windows Forms.

```
operator System::Windows::Forms::Control^() const;
```

### <a name="remarks"></a>Comentários

Este operador permite que `CWinFormsView` você passe uma visualização para funções <xref:System.Windows.Forms.Control>que aceitam um ponteiro para um controle do windows Forms do tipo .

### <a name="example"></a>Exemplo

  Consulte [CwinFormsView::GetControl](#getcontrol).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md)<br/>
[Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
