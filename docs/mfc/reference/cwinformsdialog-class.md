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
ms.openlocfilehash: 3772033df59e065cedca61012cd479c812cf5b66
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367435"
---
# <a name="cwinformsdialog-class"></a>Classe CWinFormsDialog

Um invólucro para uma classe de diálogo MFC que hospeda um controle de usuário do Windows Forms.

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
|[cwinformsdiálogo::CwinFormsDialog](#cwinformsdialog)|Constrói um objeto `CWinFormsDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cwinformsdiálogo::GetControl](#getcontrol)|Recupera uma referência ao controle de usuário do Windows Forms.|
|[cwinformsDiálogo::GetControlHandle](#getcontrolhandle)|Recupera uma alça de janela para o controle de usuário do Windows Forms.|
|[CWinFormsDiálogo::OnInitDialog](#oninitdialog)|Inicializa a caixa de diálogo MFC criando e hospedando um controle de usuário do Windows Forms nela.|

### <a name="public-operators"></a>Operadores públicos

|Nome||
|----------|-|
|[CWinFormsDiálogo::operador -&gt;](#operator_-_gt)|Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.|
|[CWinFormsDiálogo:operador TManagedControl^](#operator-tmanagedcontrol-hat)|Lança um tipo como referência a um controle de usuário do Windows Forms.|

## <a name="remarks"></a>Comentários

`CWinFormsDialog`é um invólucro para uma classe de diálogo MFC [(CDialog)](../../mfc/reference/cdialog-class.md)que hospeda um controle de usuário do Windows Forms. Isso permite a exibição de controles .NET Framework em uma caixa de diálogo MFC modal ou modeless.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um Controle de Usuário do Formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) e [hospedando um Controle de Usuário do Formulário Windows como uma caixa de diálogo MFC](../../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

## <a name="cwinformsdialogcwinformsdialog"></a><a name="cwinformsdialog"></a>cwinformsdiálogo::CwinFormsDialog

Constrói um objeto `CWinFormsDialog`.

```
CWinFormsDialog(UINT nIDTemplate = IDD);
```

### <a name="parameters"></a>Parâmetros

*Nidtemplate*<br/>
Contém o ID de um recurso de modelo de caixa de diálogo. Use o editor de diálogo para criar o modelo de diálogo e armazená-lo no arquivo de script de recurso do aplicativo. Para obter mais informações sobre modelos de diálogo, consulte [CDialog Class](../../mfc/reference/cdialog-class.md).

## <a name="cwinformsdialoggetcontrol"></a><a name="getcontrol"></a>cwinformsdiálogo::GetControl

Recupera uma referência ao controle de usuário do Windows Forms.

```
inline TManagedControl^ GetControl() const;
```

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao controle Formulários do Windows na caixa de diálogo MFC.

## <a name="cwinformsdialoggetcontrolhandle"></a><a name="getcontrolhandle"></a>cwinformsDiálogo::GetControlHandle

Recupera uma alça de janela para o controle de usuário do Windows Forms.

```
inline HWND GetControlHandle() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça de janela para o controle de usuário do Windows Forms.

## <a name="cwinformsdialogoninitdialog"></a><a name="oninitdialog"></a>CWinFormsDiálogo::OnInitDialog

Inicializa a caixa de diálogo MFC criando e hospedando um controle de usuário do Windows Forms nela.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

Um valor booleano que especifica se o aplicativo definiu o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retornar não zero, o Windows definirá o foco de entrada para o primeiro controle na caixa de diálogo. Este método só pode retornar 0 se o aplicativo definir explicitamente o foco de entrada para um dos controles na caixa de diálogo.

### <a name="remarks"></a>Comentários

Quando a caixa de diálogo MFC é criada (usando o método [Criar,](../../mfc/reference/cdialog-class.md#create) [Criar Indireto](../../mfc/reference/cdialog-class.md#createindirect)ou [DoModal](../../mfc/reference/cdialog-class.md#domodal) herdado do [CDialog),](../../mfc/reference/cdialog-class.md)uma mensagem WM_INITDIALOG é enviada e esse método é chamado. Ele cria uma instância de um controle do Windows Forms na caixa de diálogo e ajusta o tamanho da caixa de diálogo para acomodar o tamanho do controle do usuário. Em seguida, ele hospeda o novo controle na caixa de diálogo MFC.

Anular essa função de membro se você precisar executar um processamento especial quando a caixa de diálogo for inicializada. Para obter mais informações sobre o uso deste método, consulte [CDialog::OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog).

## <a name="cwinformsdialogoperator--gt"></a><a name="operator_-_gt"></a>CWinFormsDiálogo::operador -&gt;

Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.

```
inline TManagedControl^  operator->() const throw();
```

### <a name="remarks"></a>Comentários

Este operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.

Para obter informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="cwinformsdialogoperator-tmanagedcontrol"></a><a name="operator-tmanagedcontrol-hat"></a>CWinFormsDiálogo:operador TManagedControl^

Lança um tipo como referência a um controle de usuário do Windows Forms.

```
inline operator TManagedControl^() const throw();
```

### <a name="remarks"></a>Comentários

Este operador lança um tipo como uma referência a um controle do Windows Forms. Ele é usado `CWinFormsDialog<TManagedControl>` para passar uma caixa de diálogo para funções que aceitam um ponteiro para um objeto de controle do usuário do Windows Forms.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
