---
title: Classe CWinFormsView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CWinFormsView
- AFXWINFORMS/CWinFormsView
- AFXWINFORMS/CWinFormsView::CWinFormsView
- AFXWINFORMS/CWinFormsView::GetControl
dev_langs:
- C++
helpviewer_keywords:
- CWinFormsView [MFC], CWinFormsView
- CWinFormsView [MFC], GetControl
ms.assetid: d597e397-6529-469b-88f5-7f65a6b9e895
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1b4d90f2a7f964d264966d5254d051ebddaf2baa
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46448136"
---
# <a name="cwinformsview-class"></a>Classe CWinFormsView

Fornece funcionalidade genérica para hospedagem de um controle Windows Forms como uma exibição MFC.

## <a name="syntax"></a>Sintaxe

```
class CWinFormsView : public CView;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsView::CWinFormsView](#cwinformsview)|Constrói um objeto `CWinFormsView`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsView::GetControl](#getcontrol)|Recupera um ponteiro para o controle Windows Forms.|

### <a name="public-operators"></a>Operadores públicos

|Nome||
|----------|-|
|[Controle CWinFormsView::operator ^](#operator_control)|Converte um tipo como um ponteiro para um controle dos Windows Forms.|

## <a name="remarks"></a>Comentários

O MFC usa o `CWinFormsView` classe para hospedar um controle Windows Forms do .NET Framework dentro de uma exibição do MFC. O controle é um filho do modo nativo e ocupa toda a área cliente do modo de exibição do MFC. O resultado é semelhante a um `CFormView` exibição, permitindo que você tire proveito do Windows Forms designer e tempo de execução para criar modos de exibição avançados baseado em formulário.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

> [!NOTE]
>  Integração de formulários do Windows MFC funciona apenas em projetos que vincular dinamicamente ao MFC (projetos no qual AFXDLL é definido).

> [!NOTE]
>  CWinFormsView não oferece suporte a janela divisora MFC ( [classe CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)). No momento, somente o Windows Forms divisor controle tem suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

##  <a name="cwinformsview"></a>  CWinFormsView::CWinFormsView

Constrói um objeto `CWinFormsView`.

```
CWinFormsView(System::Type^ pManagedViewType);
```

### <a name="parameters"></a>Parâmetros

*pManagedViewType*<br/>
Um ponteiro para o tipo de dados do controle de usuário do Windows Forms.

### <a name="example"></a>Exemplo

No exemplo a seguir, o `CUserView` herda `CWinFormsView` e passa o tipo de `UserControl1` para o `CWinFormsView` construtor. `UserControl1` é um controle personalizado no ControlLibrary1.dll.

[!code-cpp[NVC_MFC_Managed#1](../../mfc/reference/codesnippet/cpp/cwinformsview-class_1.h)]

[!code-cpp[NVC_MFC_Managed#2](../../mfc/reference/codesnippet/cpp/cwinformsview-class_2.cpp)]

##  <a name="getcontrol"></a>  CWinFormsView::GetControl

Recupera um ponteiro para o controle Windows Forms.

```
System::Windows::Forms::Control^ GetControl() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `System.Windows.Forms.Control` objeto.

### <a name="remarks"></a>Comentários

Para obter um exemplo de como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="operator_control"></a>  Controle CWinFormsView::operator ^

Converte um tipo como um ponteiro para um controle dos Windows Forms.

```
operator System::Windows::Forms::Control^() const;
```

### <a name="remarks"></a>Comentários

Este operador permite que você passe uma `CWinFormsView` modo de exibição para funções que aceitam um ponteiro para um controle Windows Forms, do tipo <xref:System.Windows.Forms.Control>.

### <a name="example"></a>Exemplo

  Ver [CWinFormsView::GetControl](#getcontrol).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md)<br/>
[Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
