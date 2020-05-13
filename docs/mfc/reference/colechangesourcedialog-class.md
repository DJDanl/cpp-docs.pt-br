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
ms.openlocfilehash: 78da0a495de6ea951deab984550756a2d6f3e2bd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321868"
---
# <a name="colechangesourcedialog-class"></a>Classe COleChangeSourceDialog

Usado para a caixa de diálogo OLE Change Source.

## <a name="syntax"></a>Sintaxe

```
class COleChangeSourceDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeSourceDiálogo:COleChangeSourceDiálogo](#colechangesourcedialog)|Constrói um objeto `COleChangeSourceDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeSourceDialog::DoModal](#domodal)|Exibe a caixa de diálogo Alteração OLE.|
|[COleChangeSourceDiálogo::GetDisplayName](#getdisplayname)|Obtém o nome completo de exibição da fonte.|
|[COleChangeSourceDiálogo::GetFileName](#getfilename)|Obtém o nome do arquivo do nome de origem.|
|[COleChangeSourceDialog::GetFromPrefix](#getfromprefix)|Obtém o prefixo da fonte anterior.|
|[COleChangeSourceDiálogo::GetItemName](#getitemname)|Obtém o nome do item do nome de origem.|
|[COleChangeSourceDialog::GetToPrefix](#gettoprefix)|Obtém o prefixo da nova fonte|
|[COleChangeSourceDiálogo:IsValidSource](#isvalidsource)|Indica se a fonte é válida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeSourceDiálogo::m_cs](#m_cs)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto `COleChangeSourceDialog` de classe quando quiser chamar essa caixa de diálogo. Depois `COleChangeSourceDialog` que um objeto for construído, você pode usar a estrutura [m_cs](#m_cs) para inicializar os valores ou estados de controles na caixa de diálogo. A `m_cs` estrutura é do tipo [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew). Para obter mais informações sobre como usar esta classe de diálogo, consulte a função [membro DoModal.](#domodal)

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) no Windows SDK.

Para obter mais informações sobre caixas de diálogo específicas da OLE, consulte o artigo [Caixas de Diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COleChangeSourceDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="colechangesourcedialogcolechangesourcedialog"></a><a name="colechangesourcedialog"></a>COleChangeSourceDiálogo:COleChangeSourceDiálogo

Esta função constrói `COleChangeSourceDialog` um objeto.

```
explicit COleChangeSourceDialog(
    COleClientItem* pItem,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Ponteiro para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) vinculado cuja fonte deve ser atualizada.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, ligue para a função [DoModal.](#domodal)

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) e a função [OleUIChangeSource](/windows/win32/api/oledlg/nf-oledlg-oleuichangesourcew) no Windows SDK.

## <a name="colechangesourcedialogdomodal"></a><a name="domodal"></a>COleChangeSourceDialog::DoModal

Chame esta função para exibir a caixa de diálogo Fonte de alteração do OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for retornado, ligue para a função de membro [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIChangeSource](/windows/win32/api/oledlg/nf-oledlg-oleuichangesourcew) no Windows SDK.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_cs,](#m_cs) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode chamar funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo. Os seguintes nomes de lista funções típicas de consulta:

- [GetFileName](#getfilename)

- [Getdisplayname](#getdisplayname)

- [GetItemName](#getitemname)

## <a name="colechangesourcedialoggetdisplayname"></a><a name="getdisplayname"></a>COleChangeSourceDiálogo::GetDisplayName

Chame esta função para recuperar o nome de exibição completo para o item cliente vinculado.

```
CString GetDisplayName();
```

### <a name="return-value"></a>Valor retornado

O nome de exibição de origem completo (apelido) para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.

## <a name="colechangesourcedialoggetfilename"></a><a name="getfilename"></a>COleChangeSourceDiálogo::GetFileName

Chame esta função para recuperar a parte de nome do arquivo do nome de exibição para o item cliente vinculado.

```
CString GetFileName();
```

### <a name="return-value"></a>Valor retornado

A parte de apelido do arquivo do nome de exibição de origem para [coleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.

### <a name="remarks"></a>Comentários

O apelido do arquivo juntamente com o nome do item dá o nome completo de exibição.

## <a name="colechangesourcedialoggetfromprefix"></a><a name="getfromprefix"></a>COleChangeSourceDialog::GetFromPrefix

Ligue para esta função para obter a seqüência de prefixo anterior para a fonte.

```
CString GetFromPrefix();
```

### <a name="return-value"></a>Valor retornado

A seqüência de prefixo anterior da fonte.

### <a name="remarks"></a>Comentários

Ligue para esta função somente depois que [o DoModal](#domodal) retornar o IDOK.

Esse valor vem `lpszFrom` diretamente do membro da estrutura [OLEUICHANGESOURCE.](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew)

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) no Windows SDK.

## <a name="colechangesourcedialoggetitemname"></a><a name="getitemname"></a>COleChangeSourceDiálogo::GetItemName

Chame esta função para recuperar a parte de nome do item do nome de exibição para o item cliente vinculado.

```
CString GetItemName();
```

### <a name="return-value"></a>Valor retornado

A parte de nome do nome de exibição do item do nome de exibição de origem para [coleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.

### <a name="remarks"></a>Comentários

O apelido do arquivo juntamente com o nome do item dá o nome completo de exibição.

## <a name="colechangesourcedialoggettoprefix"></a><a name="gettoprefix"></a>COleChangeSourceDialog::GetToPrefix

Chame esta função para obter a nova seqüência de prefixo para a fonte.

```
CString GetToPrefix();
```

### <a name="return-value"></a>Valor retornado

A nova seqüência de prefixo da fonte.

### <a name="remarks"></a>Comentários

Ligue para esta função somente depois que [o DoModal](#domodal) retornar o IDOK.

Esse valor vem `lpszTo` diretamente do membro da estrutura [OLEUICHANGESOURCE.](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew)

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) no Windows SDK.

## <a name="colechangesourcedialogm_cs"></a><a name="m_cs"></a>COleChangeSourceDiálogo::m_cs

Este membro de dados é uma estrutura do tipo [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew).

```
OLEUICHANGESOURCE m_cs;
```

### <a name="remarks"></a>Comentários

`OLEUICHANGESOURCE`é usado para controlar o comportamento da caixa de diálogo OLE Change Source. Os membros desta estrutura podem ser modificados diretamente.

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) no Windows SDK.

## <a name="colechangesourcedialogisvalidsource"></a><a name="isvalidsource"></a>COleChangeSourceDiálogo:IsValidSource

Ligue para esta função para determinar se a nova fonte é válida.

```
BOOL IsValidSource();
```

### <a name="return-value"></a>Valor retornado

Não zero se a nova fonte for válida, caso contrário 0.

### <a name="remarks"></a>Comentários

Ligue para esta função somente depois que [o DoModal](#domodal) retornar o IDOK.

Para obter mais informações, consulte a estrutura [OLEUICHANGESOURCE](/windows/win32/api/oledlg/ns-oledlg-oleuichangesourcew) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
