---
title: Classe COleBusyDialog
ms.date: 11/04/2016
f1_keywords:
- COleBusyDialog
- AFXODLGS/COleBusyDialog
- AFXODLGS/COleBusyDialog::COleBusyDialog
- AFXODLGS/COleBusyDialog::DoModal
- AFXODLGS/COleBusyDialog::GetSelectionType
- AFXODLGS/COleBusyDialog::m_bz
helpviewer_keywords:
- COleBusyDialog [MFC], COleBusyDialog
- COleBusyDialog [MFC], DoModal
- COleBusyDialog [MFC], GetSelectionType
- COleBusyDialog [MFC], m_bz
ms.assetid: c881a532-9672-4c41-b51b-5ce4a7246a6b
ms.openlocfilehash: aa3f0d85bcbf34d325125187b22b38c4da01fb43
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504400"
---
# <a name="colebusydialog-class"></a>Classe COleBusyDialog

Usado para as caixas de diálogo servidor OLE não respondendo ou servidor ocupado.

## <a name="syntax"></a>Sintaxe

```
class COleBusyDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleBusyDialog::COleBusyDialog](#colebusydialog)|Constrói um objeto `COleBusyDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleBusyDialog::DoModal](#domodal)|Exibe a caixa de diálogo servidor OLE ocupado.|
|[COleBusyDialog::GetSelectionType](#getselectiontype)|Determina a escolha feita na caixa de diálogo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleBusyDialog::m_bz](#m_bz)|Estrutura do tipo OLEUIBUSY que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto da classe `COleBusyDialog` quando desejar chamar essas caixas de diálogo. Depois que `COleBusyDialog` um objeto tiver sido construído, você poderá usar a estrutura [m_bz](#m_bz) para inicializar os valores ou os Estados dos controles na caixa de diálogo. A `m_bz` estrutura é do tipo OLEUIBUSY. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a função membro [DoModal](#domodal) .

> [!NOTE]
>  O assistente de aplicativo-código de contêiner gerado usa essa classe.

Para obter mais informações, consulte a estrutura [OLEUIBUSY](/windows/win32/api/oledlg/ns-oledlg-oleuibusyw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleBusyDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="colebusydialog"></a>  COleBusyDialog::COleBusyDialog

Essa função constrói apenas um `COleBusyDialog` objeto.

```
explicit COleBusyDialog(
    HTASK htaskBusy,
    BOOL bNotResponding = FALSE,
    DWORD dwFlags = 0,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*htaskBusy*<br/>
Identificador para a tarefa do servidor ocupada.

*bNotResponding*<br/>
Se verdadeiro, chame a caixa de diálogo não responde em vez da caixa de diálogo servidor ocupado. As palavras na caixa de diálogo não respondendo são um pouco diferentes das palavras na caixa de diálogo servidor ocupado e o botão Cancelar é desabilitado.

*dwFlags*<br/>
Sinalizador de criação. Pode conter zero ou mais dos seguintes valores combinados com o operador OR bit-a-OR:

- BZ_DISABLECANCELBUTTON desabilitar o botão Cancelar ao chamar a caixa de diálogo.

- BZ_DISABLESWITCHTOBUTTON desabilite o botão Alternar para ao chamar a caixa de diálogo.

- BZ_DISABLERETRYBUTTON desabilite o botão de repetição ao chamar a caixa de diálogo.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do `CWnd`tipo) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai do objeto Dialog será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, chame [DoModal](#domodal).

Para obter mais informações, consulte a estrutura [OLEUIBUSY](/windows/win32/api/oledlg/ns-oledlg-oleuibusyw) no SDK do Windows.

##  <a name="domodal"></a>  COleBusyDialog::DoModal

Chame essa função para exibir a caixa de diálogo servidor OLE ocupado ou servidor não respondendo.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a `COleDialog::GetLastError` função de membro para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUIBUSY](/windows/win32/api/oledlg/nf-oledlg-oleuibusyw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo membros da estrutura [m_bz](#m_bz) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

##  <a name="getselectiontype"></a>  COleBusyDialog::GetSelectionType

Chame essa função para obter o tipo de seleção escolhido pelo usuário na caixa de diálogo servidor ocupado.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor de retorno

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores de tipo de retorno são especificados `Selection` pelo tipo de enumeração declarado `COleBusyDialog` na classe.

```
enum Selection {
    switchTo,
    retry,
    callUnblocked
    };
```

As breves descrições desses valores são as seguintes:

- `COleBusyDialog::switchTo`Botão Alternar para foi pressionado.

- `COleBusyDialog::retry`O botão de repetição foi pressionado.

- `COleBusyDialog::callUnblocked`A chamada para ativar o servidor agora está desbloqueada.

##  <a name="m_bz"></a>  COleBusyDialog::m_bz

Estrutura do tipo OLEUIBUSY usada para controlar o comportamento da caixa de diálogo servidor ocupado.

```
OLEUIBUSY m_bz;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.

Para obter mais informações, consulte a estrutura [OLEUIBUSY](/windows/win32/api/oledlg/ns-oledlg-oleuibusyw) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
