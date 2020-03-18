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
ms.openlocfilehash: f4a5e6b88527dad8606092ccebd4899bba5181f6
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420858"
---
# <a name="cwinformsview-class"></a>Classe CWinFormsView

Fornece funcionalidade genérica para hospedagem de um controle de Windows Forms como uma exibição do MFC.

## <a name="syntax"></a>Sintaxe

```
class CWinFormsView : public CView;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CWinFormsView::CWinFormsView](#cwinformsview)|Constrói um objeto `CWinFormsView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CWinFormsView:: GetControl](#getcontrol)|Recupera um ponteiro para o controle de Windows Forms.|

### <a name="public-operators"></a>Operadores públicos

|Nome||
|----------|-|
|[Controle CWinFormsView:: Operator ^](#operator_control)|Converte um tipo como um ponteiro para um controle Windows Forms.|

## <a name="remarks"></a>Comentários

O MFC usa a classe `CWinFormsView` para hospedar um .NET Framework controle de Windows Forms dentro de uma exibição do MFC. O controle é um filho da exibição nativa e ocupa toda a área do cliente da exibição do MFC. O resultado é semelhante a uma exibição de `CFormView`, permitindo que você aproveite o designer de Windows Forms e o tempo de execução para criar exibições baseadas em formulário sofisticadas.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

> [!NOTE]
>  A integração do MFC Windows Forms funciona apenas em projetos que vinculam dinamicamente com o MFC (projetos nos quais o AFXDLL é definido).

> [!NOTE]
>  CWinFormsView não dá suporte à janela divisor do MFC ( [classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)). Atualmente, há suporte apenas para o controle divisor Windows Forms.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms. h

##  <a name="cwinformsview"></a>CWinFormsView::CWinFormsView

Constrói um objeto `CWinFormsView`.

```
CWinFormsView(System::Type^ pManagedViewType);
```

### <a name="parameters"></a>parâmetros

*pManagedViewType*<br/>
Um ponteiro para o tipo de dados do controle de usuário Windows Forms.

### <a name="example"></a>Exemplo

No exemplo a seguir, a classe `CUserView` herda de `CWinFormsView` e passa o tipo de `UserControl1` para o Construtor `CWinFormsView`. `UserControl1` é um controle personalizado do ControlLibrary1. dll.

[!code-cpp[NVC_MFC_Managed#1](../../mfc/reference/codesnippet/cpp/cwinformsview-class_1.h)]

[!code-cpp[NVC_MFC_Managed#2](../../mfc/reference/codesnippet/cpp/cwinformsview-class_2.cpp)]

##  <a name="getcontrol"></a>CWinFormsView:: GetControl

Recupera um ponteiro para o controle de Windows Forms.

```
System::Windows::Forms::Control^ GetControl() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `System.Windows.Forms.Control`.

### <a name="remarks"></a>Comentários

Para obter um exemplo de como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="operator_control"></a>Controle CWinFormsView:: Operator ^

Converte um tipo como um ponteiro para um controle Windows Forms.

```
operator System::Windows::Forms::Control^() const;
```

### <a name="remarks"></a>Comentários

Esse operador permite passar uma exibição de `CWinFormsView` para funções que aceitam um ponteiro para um controle de Windows Forms do tipo <xref:System.Windows.Forms.Control>.

### <a name="example"></a>Exemplo

  Consulte [CWinFormsView:: GetControl](#getcontrol).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md)<br/>
[Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
