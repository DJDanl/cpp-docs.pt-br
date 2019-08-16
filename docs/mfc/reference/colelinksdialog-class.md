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
ms.openlocfilehash: 911108f9a231b752790abfdf86d1b4042d30b149
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504116"
---
# <a name="colelinksdialog-class"></a>Classe COleLinksDialog

Usado para a caixa de diálogo links OLE Edit.

## <a name="syntax"></a>Sintaxe

```
class COleLinksDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinksDialog::COleLinksDialog](#colelinksdialog)|Constrói um objeto `COleLinksDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinksDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE Edit links.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinksDialog::m_el](#m_el)|Uma estrutura do tipo OLEUIEDITLINKS que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto da classe `COleLinksDialog` quando desejar chamar essa caixa de diálogo. Depois que `COleLinksDialog` um objeto tiver sido construído, você poderá usar a estrutura [m_el](#m_el) para inicializar os valores ou os Estados dos controles na caixa de diálogo. A `m_el` estrutura é do tipo OLEUIEDITLINKS. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a função membro [DoModal](#domodal) .

> [!NOTE]
>  O assistente de aplicativo-código de contêiner gerado usa essa classe.

Para obter mais informações, consulte a estrutura [OLEUIEDITLINKS](/windows/win32/api/oledlg/ns-oledlg-oleuieditlinksw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleLinksDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="domodal"></a>COleLinksDialog::D oModal

Exibe a caixa de diálogo OLE Edit links.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a `COleDialog::GetLastError` função de membro para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUIEDITLINKS](/windows/win32/api/oledlg/nf-oledlg-oleuieditlinksw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo os membros da estrutura [m_el](#m_el) , deverá fazê-lo antes de `DoModal`chamar, mas depois que o objeto da caixa de diálogo for construído.

##  <a name="colelinksdialog"></a>  COleLinksDialog::COleLinksDialog

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

*pView*<br/>
Aponta para a exibição atual em *pDoc*.

*dwFlags*<br/>
Sinalizador de criação, que contém 0 ou ELF_SHOWHELP para especificar se o botão ajuda será exibido quando a caixa de diálogo for exibida.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do `CWnd`tipo) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Essa função constrói apenas um `COleLinksDialog` objeto. Para exibir a caixa de diálogo, chame a função [DoModal](#domodal) .

##  <a name="m_el"></a>  COleLinksDialog::m_el

Estrutura do tipo OLEUIEDITLINKS usada para controlar o comportamento da caixa de diálogo Editar links.

```
OLEUIEDITLINKS m_el;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.

Para obter mais informações, consulte a estrutura [OLEUIEDITLINKS](/windows/win32/api/oledlg/ns-oledlg-oleuieditlinksw) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
