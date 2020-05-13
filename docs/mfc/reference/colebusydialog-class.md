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
ms.openlocfilehash: 5be42463c08cacd83de84900fb4d98771774e897
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364249"
---
# <a name="colebusydialog-class"></a>Classe COleBusyDialog

Usado para as caixas de diálogo OLE Server Not Responding ou Server Busy.

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
|[COleBusyDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE Server Busy.|
|[COleBusyDialog::GetSelectionType](#getselectiontype)|Determina a escolha feita na caixa de diálogo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleBusyDialog::m_bz](#m_bz)|Estrutura do tipo OLEUIBUSY que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto `COleBusyDialog` de classe quando quiser chamar essas caixas de diálogo. Depois `COleBusyDialog` que um objeto for construído, você pode usar a estrutura [m_bz](#m_bz) para inicializar os valores ou estados de controles na caixa de diálogo. A `m_bz` estrutura é do tipo OLEUIBUSY. Para obter mais informações sobre como usar esta classe de diálogo, consulte a função [membro DoModal.](#domodal)

> [!NOTE]
> O código de contêiner gerado pelo Assistente do aplicativo usa essa classe.

Para obter mais informações, consulte a estrutura [OLEUIBUSY](/windows/win32/api/oledlg/ns-oledlg-oleuibusyw) no Windows SDK.

Para obter mais informações sobre caixas de diálogo específicas do OLE, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COleBusyDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="colebusydialogcolebusydialog"></a><a name="colebusydialog"></a>COleBusyDialog::COleBusyDialog

Esta função só `COleBusyDialog` constrói um objeto.

```
explicit COleBusyDialog(
    HTASK htaskBusy,
    BOOL bNotResponding = FALSE,
    DWORD dwFlags = 0,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*htaskOcupado*<br/>
Manuseie a tarefa do servidor que está ocupada.

*bNotResponding*<br/>
Se 'TRUE', chame a caixa de diálogo Não Responder em vez da caixa de diálogo Servidor Ocupado. A redação na caixa de diálogo Não Responder é ligeiramente diferente da redação na caixa de diálogo Servidor Ocupado e o botão Cancelar está desativado.

*dwFlags*<br/>
Bandeira de criação. Pode conter zero ou mais dos seguintes valores combinados com o operador bitwise-OR:

- BZ_DISABLECANCELBUTTON Desative o botão Cancelar ao ligar para a caixa de diálogo.

- BZ_DISABLESWITCHTOBUTTON Desabilite o botão '''''''Desativao', ao ligar para a caixa de diálogo.

- BZ_DISABLERETRYBUTTON Desative o botão 'Retente' ao ligar para a caixa de diálogo.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, ligue para [DoModal](#domodal).

Para obter mais informações, consulte a estrutura [OLEUIBUSY](/windows/win32/api/oledlg/ns-oledlg-oleuibusyw) no Windows SDK.

## <a name="colebusydialogdomodal"></a><a name="domodal"></a>COleBusyDialog::DoModal

Chame esta função para exibir a caixa de diálogo OLE Server Busy ou Server Not Respond.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for `COleDialog::GetLastError` devolvido, ligue para a função do membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIBusy](/windows/win32/api/oledlg/nf-oledlg-oleuibusyw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_bz,](#m_bz) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode ligar para outras funções de membro para recuperar as configurações ou informações que foram inseridas pelo usuário na caixa de diálogo.

## <a name="colebusydialoggetselectiontype"></a><a name="getselectiontype"></a>COleBusyDialog::GetSelectionType

Chame esta função para obter o tipo de seleção escolhido pelo usuário na caixa de diálogo Servidor Ocupado.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor retornado

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores do tipo `Selection` de retorno são especificados `COleBusyDialog` pelo tipo de enumeração declarado na classe.

```
enum Selection {
    switchTo,
    retry,
    callUnblocked
    };
```

Breves descrições desses valores seguem:

- `COleBusyDialog::switchTo`O botão Para o botão foi pressionado.

- `COleBusyDialog::retry`Botão de repetição foi pressionado.

- `COleBusyDialog::callUnblocked`A chamada para ativar o servidor está agora desbloqueada.

## <a name="colebusydialogm_bz"></a><a name="m_bz"></a>COleBusyDialog::m_bz

Estrutura do tipo OLEUIBUSY usado para controlar o comportamento da caixa de diálogo Servidor Ocupado.

```
OLEUIBUSY m_bz;
```

### <a name="remarks"></a>Comentários

Os membros desta estrutura podem ser modificados diretamente ou através de funções de membros.

Para obter mais informações, consulte a estrutura [OLEUIBUSY](/windows/win32/api/oledlg/ns-oledlg-oleuibusyw) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
