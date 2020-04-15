---
title: Classe COleLinksDialog
ms.date: 11/04/2016
f1_keywords:
- COleLinksDialog
- AFXODLGS/COleLinksDialog
- AFXODLGS/COleLinksDialog::COleLinksDialog
- AFXODLGS/COleLinksDialog::DoModal
- AFXODLGS/COleLinksDialog::m_el
helpviewer_keywords:
- COleLinksDialog [MFC], COleLinksDialog
- COleLinksDialog [MFC], DoModal
- COleLinksDialog [MFC], m_el
ms.assetid: fb2eb638-2809-46db-ac74-392a732affc7
ms.openlocfilehash: f120678c822749c8f27c3c56c95fcdd54647aca3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374926"
---
# <a name="colelinksdialog-class"></a>Classe COleLinksDialog

Usado para a caixa de diálogo OLE Edit Links.

## <a name="syntax"></a>Sintaxe

```
class COleLinksDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinksDiálogo::COleLinksDiálogo](#colelinksdialog)|Constrói um objeto `COleLinksDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinksDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE Edit Links.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinksDiálogo::m_el](#m_el)|Uma estrutura do tipo OLEUIEDITLINKS que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto `COleLinksDialog` de classe quando quiser chamar essa caixa de diálogo. Depois `COleLinksDialog` que um objeto for construído, você pode usar a estrutura [m_el](#m_el) para inicializar os valores ou estados de controles na caixa de diálogo. A `m_el` estrutura é do tipo OLEUIEDITLINKS. Para obter mais informações sobre como usar esta classe de diálogo, consulte a função [membro DoModal.](#domodal)

> [!NOTE]
> O código de contêiner gerado pelo Assistente do aplicativo usa essa classe.

Para obter mais informações, consulte a estrutura [OLEUIEDITLINKS](/windows/win32/api/oledlg/ns-oledlg-oleuieditlinksw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas do OLE, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COleLinksDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="colelinksdialogdomodal"></a><a name="domodal"></a>COleLinksDialog::DoModal

Exibe a caixa de diálogo OLE Edit Links.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for `COleDialog::GetLastError` devolvido, ligue para a função do membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIEditLinks](/windows/win32/api/oledlg/nf-oledlg-oleuieditlinksw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_el,](#m_el) você deve fazê-lo antes de chamar, mas depois que o objeto de diálogo for construído.

## <a name="colelinksdialogcolelinksdialog"></a><a name="colelinksdialog"></a>COleLinksDiálogo::COleLinksDiálogo

Constrói um objeto `COleLinksDialog`.

```
COleLinksDialog (
    COleDocument* pDoc,
    CView* pView,
    DWORD dwFlags = 0,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Aponta para o documento OLE que contém os links a serem editados.

*pVer*<br/>
Aponta para a visão atual no *pDoc*.

*dwFlags*<br/>
Sinalizador de criação, que contém 0 ou ELF_SHOWHELP para especificar se o botão Ajuda será exibido quando a caixa de diálogo for exibida.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Esta função constrói `COleLinksDialog` apenas um objeto. Para exibir a caixa de diálogo, ligue para a função [DoModal.](#domodal)

## <a name="colelinksdialogm_el"></a><a name="m_el"></a>COleLinksDiálogo::m_el

Estrutura do tipo OLEUIEDITLINKS usado para controlar o comportamento da caixa de diálogo Editar links.

```
OLEUIEDITLINKS m_el;
```

### <a name="remarks"></a>Comentários

Os membros desta estrutura podem ser modificados diretamente ou através de funções de membros.

Para obter mais informações, consulte a estrutura [OLEUIEDITLINKS](/windows/win32/api/oledlg/ns-oledlg-oleuieditlinksw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
