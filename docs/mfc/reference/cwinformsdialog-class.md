---
title: Classe CWinFormsDialog
ms.date: 03/27/2019
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
ms.openlocfilehash: a25823982b9276309e99a2a26cef8d6fe2e764bd
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040659"
---
# <a name="cwinformsdialog-class"></a>Classe CWinFormsDialog

Um wrapper para uma classe de diálogo do MFC que hospeda um controle de usuário Windows Forms.

## <a name="syntax"></a>Sintaxe

```
template <typename TManagedControl>
class CWinFormsDialog :
    public CDialog
```

#### <a name="parameters"></a>Parâmetros

*TManagedControl*<br/>
O controle de usuário .NET Framework a ser exibido no aplicativo MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsDialog::CWinFormsDialog](#cwinformsdialog)|Constrói um objeto `CWinFormsDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsDialog:: GetControl](#getcontrol)|Recupera uma referência para o controle de usuário Windows Forms.|
|[CWinFormsDialog::GetControlHandle](#getcontrolhandle)|Recupera um identificador de janela para o controle de usuário Windows Forms.|
|[CWinFormsDialog:: OnInitDialog](#oninitdialog)|Inicializa a caixa de diálogo MFC criando e hospedando um controle de usuário Windows Forms nele.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-|
|[Operador CWinFormsDialog:: Operator&gt;](#operator_-_gt)|Substitui [CWinFormsDialog:: GetControl](#getcontrol) em expressões.|
|[CWinFormsDialog:: Operator TManagedControl ^](#operator-tmanagedcontrol-hat)|Converte um tipo como uma referência a um controle de usuário Windows Forms.|

## <a name="remarks"></a>Comentários

`CWinFormsDialog` é um wrapper para uma classe de caixa de diálogo do MFC ( [CDialog](../../mfc/reference/cdialog-class.md)) que hospeda um controle de usuário Windows Forms. Isso permite a exibição de controles de .NET Framework em uma caixa de diálogo modal ou do MFC sem janela.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) e [hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms. h

## <a name="cwinformsdialogcwinformsdialog"></a><a name="cwinformsdialog"></a> CWinFormsDialog::CWinFormsDialog

Constrói um objeto `CWinFormsDialog`.

```
CWinFormsDialog(UINT nIDTemplate = IDD);
```

### <a name="parameters"></a>Parâmetros

*nIDTemplate*<br/>
Contém a ID de um recurso de modelo de caixa de diálogo. Use o editor de caixa de diálogo para criar o modelo de caixa de diálogo e armazená-lo no arquivo de script de recurso do aplicativo. Para obter mais informações sobre modelos de caixa de diálogo, consulte [classe CDialog](../../mfc/reference/cdialog-class.md).

## <a name="cwinformsdialoggetcontrol"></a><a name="getcontrol"></a> CWinFormsDialog:: GetControl

Recupera uma referência para o controle de usuário Windows Forms.

```
inline TManagedControl^ GetControl() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao controle de Windows Forms na caixa de diálogo MFC.

## <a name="cwinformsdialoggetcontrolhandle"></a><a name="getcontrolhandle"></a> CWinFormsDialog::GetControlHandle

Recupera um identificador de janela para o controle de usuário Windows Forms.

```
inline HWND GetControlHandle() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador de janela para o controle de usuário Windows Forms.

## <a name="cwinformsdialogoninitdialog"></a><a name="oninitdialog"></a> CWinFormsDialog:: OnInitDialog

Inicializa a caixa de diálogo MFC criando e hospedando um controle de usuário Windows Forms nele.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

Um valor booliano que especifica se o aplicativo definiu o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retornar zero, o Windows definirá o foco de entrada para o primeiro controle na caixa de diálogo. Esse método pode retornar 0 somente se o aplicativo tiver definido explicitamente o foco de entrada para um dos controles na caixa de diálogo.

### <a name="remarks"></a>Comentários

Quando a caixa de diálogo MFC é criada (usando o método [CreateIndirect](../../mfc/reference/cdialog-class.md#createindirect) [Create](../../mfc/reference/cdialog-class.md#create), insent ou [DoModal](../../mfc/reference/cdialog-class.md#domodal) herdado de [CDialog](../../mfc/reference/cdialog-class.md)), uma mensagem WM_INITDIALOG é enviada e esse método é chamado. Ele cria uma instância de um controle de Windows Forms na caixa de diálogo e ajusta o tamanho da caixa de diálogo para acomodar o tamanho do controle de usuário. Em seguida, ele hospeda o novo controle na caixa de diálogo MFC.

Substitua essa função de membro se você precisar executar processamento especial quando a caixa de diálogo for inicializada. Para obter mais informações sobre como usar esse método, consulte [CDialog:: OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog).

## <a name="cwinformsdialogoperator--gt"></a><a name="operator_-_gt"></a> Operador CWinFormsDialog:: Operator&gt;

Substitui [CWinFormsDialog:: GetControl](#getcontrol) em expressões.

```
inline TManagedControl^  operator->() const throw();
```

### <a name="remarks"></a>Comentários

Esse operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.

Para obter informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="cwinformsdialogoperator-tmanagedcontrol"></a><a name="operator-tmanagedcontrol-hat"></a> CWinFormsDialog:: Operator TManagedControl ^

Converte um tipo como uma referência a um controle de usuário Windows Forms.

```
inline operator TManagedControl^() const throw();
```

### <a name="remarks"></a>Comentários

Esse operador converte um tipo como uma referência a um controle Windows Forms. Ele é usado para passar uma `CWinFormsDialog<TManagedControl>` caixa de diálogo para funções que aceitam um ponteiro para um objeto de controle de usuário Windows Forms.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
