---
title: Classe CWinFormsDialog
ms.date: 11/04/2016
f1_keywords:
- CWinFormsDialog
- AFXWINFORMS/CWinFormsDialog
- AFXWINFORMS/CWinFormsDialog::CWinFormsDialog
- AFXWINFORMS/CWinFormsDialog::GetControl
- AFXWINFORMS/CWinFormsDialog::GetControlHandle
- AFXWINFORMS/CWinFormsDialog::OnInitDialog
helpviewer_keywords:
- CWinFormsDialog [MFC], CWinFormsDialog
- CWinFormsDialog [MFC], GetControl
- CWinFormsDialog [MFC], GetControlHandle
- CWinFormsDialog [MFC], OnInitDialog
ms.assetid: e3cec000-a578-448e-b06a-8af256312f61
ms.openlocfilehash: 3baa9f99a5a1ecefc0ad9bc9f0c56f0f67dc2e80
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50573480"
---
# <a name="cwinformsdialog-class"></a>Classe CWinFormsDialog

Um wrapper para uma classe de caixa de diálogo do MFC que hospeda um controle de usuário do Windows Forms.

## <a name="syntax"></a>Sintaxe

```
template <typename TManagedControl>
class CWinFormsDialog :
    public CDialog
```

#### <a name="parameters"></a>Parâmetros

*TManagedControl*<br/>
O controle de usuário do .NET Framework a ser exibido no aplicativo MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsDialog::CWinFormsDialog](#cwinformsdialog)|Constrói um objeto `CWinFormsDialog`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsDialog::GetControl](#getcontrol)|Recupera uma referência ao controle de usuário do Windows Forms.|
|[CWinFormsDialog::GetControlHandle](#getcontrolhandle)|Recupera um identificador de janela para o controle de usuário do Windows Forms.|
|[CWinFormsDialog::OnInitDialog](#oninitdialog)|Inicializa a caixa de diálogo do MFC, criando e hospedando um controle de usuário do Windows Forms nele.|

### <a name="public-operators"></a>Operadores públicos

|Nome||
|----------|-|
|[CWinFormsDialog::operator-&gt;](#operator_-_gt)|Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.|
|[CWinFormsDialog::operator TManagedControl ^](#operator_tmanagedcontrol)|Converte um tipo como uma referência a um controle de usuário do Windows Forms.|

## <a name="remarks"></a>Comentários

`CWinFormsDialog` é um wrapper para uma classe de caixa de diálogo do MFC ( [CDialog](../../mfc/reference/cdialog-class.md)) que hospeda um controle de usuário do Windows Forms. Isso permite que a exibição de controles do .NET Framework em uma caixa de diálogo modal ou sem-modo do MFC.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) e [hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

##  <a name="cwinformsdialog"></a>  CWinFormsDialog::CWinFormsDialog

Constrói um objeto `CWinFormsDialog`.

```
CWinFormsDialog(UINT nIDTemplate = IDD);
```

### <a name="parameters"></a>Parâmetros

*nIDTemplate*<br/>
Contém a ID de um recurso de modelo de caixa de diálogo. Use o editor de caixa de diálogo para criar o modelo de caixa de diálogo e armazená-lo no arquivo de script de recurso do aplicativo. Para obter mais informações sobre modelos de caixa de diálogo, consulte [classe CDialog](../../mfc/reference/cdialog-class.md).

##  <a name="getcontrol"></a>  CWinFormsDialog::GetControl

Recupera uma referência ao controle de usuário do Windows Forms.

```
inline TManagedControl^ GetControl() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao controle de formulários do Windows na caixa de diálogo MFC.

##  <a name="getcontrolhandle"></a>  CWinFormsDialog::GetControlHandle

Recupera um identificador de janela para o controle de usuário do Windows Forms.

```
inline HWND GetControlHandle() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador de janela para o controle de usuário do Windows Forms.

##  <a name="oninitdialog"></a>  CWinFormsDialog::OnInitDialog

Inicializa a caixa de diálogo do MFC, criando e hospedando um controle de usuário do Windows Forms nele.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

Um valor booliano que especifica se o aplicativo tiver definido o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retorna diferente de zero, Windows define o foco de entrada para o primeiro controle na caixa de diálogo. Esse método pode retornar 0 somente se o aplicativo tiver definido explicitamente o foco de entrada para um dos controles na caixa de diálogo.

### <a name="remarks"></a>Comentários

Quando a caixa de diálogo do MFC é criada (usando o [Create](../../mfc/reference/cdialog-class.md#create), [CreateIndirect](../../mfc/reference/cdialog-class.md#createindirect), ou [DoModal](../../mfc/reference/cdialog-class.md#domodal) método herdado do [CDialog](../../mfc/reference/cdialog-class.md)), um WM _ INITDIALOG mensagem é enviada, e esse método é chamado. Ele cria uma instância de um controle de formulários do Windows na caixa de diálogo e ajusta o tamanho da caixa de diálogo para acomodar o tamanho do controle de usuário. Em seguida, ele hospeda o novo controle na caixa de diálogo MFC.

Substitua essa função membro, se você precisar realizar processamento especial quando a caixa de diálogo é inicializada. Para obter mais informações sobre como usar esse método, consulte [CDialog::OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog).

##  <a name="operator_-_gt"></a>  CWinFormsDialog::operator-&gt;

Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.

```
inline TManagedControl^  operator->() const throw();
```

### <a name="remarks"></a>Comentários

Esse operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.

Para obter informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="operator_tmanagedcontrol_xor"></a>  CWinFormsDialog::operator TManagedControl ^

Converte um tipo como uma referência a um controle de usuário do Windows Forms.

```
inline operator TManagedControl^() const throw();
```

### <a name="remarks"></a>Comentários

Este operador converte um tipo como uma referência a um controle Windows Forms. Ele é usado para passar um `CWinFormsDialog<TManagedControl>` caixa de diálogo para funções que aceitam um ponteiro para um objeto de controle de usuário do Windows Forms.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
