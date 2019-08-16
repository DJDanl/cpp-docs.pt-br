---
title: Classe COleChangeSourceDialog
ms.date: 11/04/2016
f1_keywords:
- COleChangeSourceDialog
- AFXODLGS/COleChangeSourceDialog
- AFXODLGS/COleChangeSourceDialog::COleChangeSourceDialog
- AFXODLGS/COleChangeSourceDialog::DoModal
- AFXODLGS/COleChangeSourceDialog::GetDisplayName
- AFXODLGS/COleChangeSourceDialog::GetFileName
- AFXODLGS/COleChangeSourceDialog::GetFromPrefix
- AFXODLGS/COleChangeSourceDialog::GetItemName
- AFXODLGS/COleChangeSourceDialog::GetToPrefix
- AFXODLGS/COleChangeSourceDialog::IsValidSource
- AFXODLGS/COleChangeSourceDialog::m_cs
helpviewer_keywords:
- COleChangeSourceDialog [MFC], COleChangeSourceDialog
- COleChangeSourceDialog [MFC], DoModal
- COleChangeSourceDialog [MFC], GetDisplayName
- COleChangeSourceDialog [MFC], GetFileName
- COleChangeSourceDialog [MFC], GetFromPrefix
- COleChangeSourceDialog [MFC], GetItemName
- COleChangeSourceDialog [MFC], GetToPrefix
- COleChangeSourceDialog [MFC], IsValidSource
- COleChangeSourceDialog [MFC], m_cs
ms.assetid: d0e08be7-21ef-45e1-97af-fe27d99e3bac
ms.openlocfilehash: 239d7eed89796f414a7665b203ca50fafec51277
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504393"
---
# <a name="colechangesourcedialog-class"></a>Classe COleChangeSourceDialog

Usado para a caixa de diálogo origem de alteração de OLE.

## <a name="syntax"></a>Sintaxe

```
class COleChangeSourceDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeSourceDialog::COleChangeSourceDialog](#colechangesourcedialog)|Constrói um objeto `COleChangeSourceDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeSourceDialog::DoModal](#domodal)|Exibe a caixa de diálogo fonte de alteração OLE.|
|[COleChangeSourceDialog::GetDisplayName](#getdisplayname)|Obtém o nome de exibição de origem completo.|
|[COleChangeSourceDialog::GetFileName](#getfilename)|Obtém o FileName do nome de origem.|
|[COleChangeSourceDialog::GetFromPrefix](#getfromprefix)|Obtém o prefixo da origem anterior.|
|[COleChangeSourceDialog::GetItemName](#getitemname)|Obtém o nome do item do nome de origem.|
|[COleChangeSourceDialog::GetToPrefix](#gettoprefix)|Obtém o prefixo da nova fonte|
|[COleChangeSourceDialog::IsValidSource](#isvalidsource)|Indica se a origem é válida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeSourceDialog::m_cs](#m_cs)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto da classe `COleChangeSourceDialog` quando desejar chamar essa caixa de diálogo. Depois que `COleChangeSourceDialog` um objeto tiver sido construído, você poderá usar a estrutura [m_cs](#m_cs) para inicializar os valores ou os Estados dos controles na caixa de diálogo. A `m_cs` estrutura é do tipo [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew). Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a função membro [DoModal](#domodal) .

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) em SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleChangeSourceDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="colechangesourcedialog"></a>  COleChangeSourceDialog::COleChangeSourceDialog

Essa função constrói um `COleChangeSourceDialog` objeto.

```
explicit COleChangeSourceDialog(
    COleClientItem* pItem,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Ponteiro para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) vinculado cuja origem deve ser atualizada.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do `CWnd`tipo) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, chame a função [DoModal](#domodal) .

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) e a função [OLEUICHANGESOURCE](/windows/win32/api/oledlg/nf-oledlg-oleuichangesourcew) em SDK do Windows.

##  <a name="domodal"></a>  COleChangeSourceDialog::DoModal

Chame essa função para exibir a caixa de diálogo fonte de alteração OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a função de membro [COleDialog:: GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUICHANGESOURCE](/windows/win32/api/oledlg/nf-oledlg-oleuichangesourcew) em SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo membros da estrutura [m_cs](#m_cs) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar funções de membro para recuperar configurações inseridas pelo usuário ou informações da caixa de diálogo. A lista a seguir nomeia funções de consulta típicas:

- [GetFileName](#getfilename)

- [GetDisplayName](#getdisplayname)

- [GetItemName](#getitemname)

##  <a name="getdisplayname"></a>  COleChangeSourceDialog::GetDisplayName

Chame essa função para recuperar o nome de exibição completo do item do cliente vinculado.

```
CString GetDisplayName();
```

### <a name="return-value"></a>Valor de retorno

O nome de exibição de origem completo (moniker) para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.

##  <a name="getfilename"></a>  COleChangeSourceDialog::GetFileName

Chame essa função para recuperar a parte do moniker do arquivo do nome de exibição do item do cliente vinculado.

```
CString GetFileName();
```

### <a name="return-value"></a>Valor de retorno

A parte do moniker do arquivo do nome de exibição da origem para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.

### <a name="remarks"></a>Comentários

O moniker do arquivo junto com o item moniker fornece o nome de exibição completo.

##  <a name="getfromprefix"></a>  COleChangeSourceDialog::GetFromPrefix

Chame essa função para obter a cadeia de caracteres de prefixo anterior para a origem.

```
CString GetFromPrefix();
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres de prefixo anterior da origem.

### <a name="remarks"></a>Comentários

Chame essa função somente depois que [DoModal](#domodal) retornar IDOK.

Esse valor vem diretamente do `lpszFrom` membro da estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) .

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) em SDK do Windows.

##  <a name="getitemname"></a>  COleChangeSourceDialog::GetItemName

Chame essa função para recuperar a parte do moniker do item do nome de exibição do item do cliente vinculado.

```
CString GetItemName();
```

### <a name="return-value"></a>Valor de retorno

A parte do moniker do item do nome de exibição da origem para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.

### <a name="remarks"></a>Comentários

O moniker do arquivo junto com o item moniker fornece o nome de exibição completo.

##  <a name="gettoprefix"></a>  COleChangeSourceDialog::GetToPrefix

Chame essa função para obter a nova cadeia de caracteres de prefixo para a origem.

```
CString GetToPrefix();
```

### <a name="return-value"></a>Valor de retorno

A nova cadeia de caracteres de prefixo da origem.

### <a name="remarks"></a>Comentários

Chame essa função somente depois que [DoModal](#domodal) retornar IDOK.

Esse valor vem diretamente do `lpszTo` membro da estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) .

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) em SDK do Windows.

##  <a name="m_cs"></a>  COleChangeSourceDialog::m_cs

Este membro de dados é uma estrutura do tipo [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew).

```
OLEUICHANGESOURCE m_cs;
```

### <a name="remarks"></a>Comentários

`OLEUICHANGESOURCE`é usado para controlar o comportamento da caixa de diálogo origem de alteração de OLE. Os membros dessa estrutura podem ser modificados diretamente.

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) em SDK do Windows.

##  <a name="isvalidsource"></a>  COleChangeSourceDialog::IsValidSource

Chame essa função para determinar se a nova fonte é válida.

```
BOOL IsValidSource();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a nova fonte for válida, caso contrário 0.

### <a name="remarks"></a>Comentários

Chame essa função somente depois que [DoModal](#domodal) retornar IDOK.

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) em SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
