---
title: Classe COleChangeIconDialog
ms.date: 11/04/2016
f1_keywords:
- COleChangeIconDialog
- AFXODLGS/COleChangeIconDialog
- AFXODLGS/COleChangeIconDialog::COleChangeIconDialog
- AFXODLGS/COleChangeIconDialog::DoChangeIcon
- AFXODLGS/COleChangeIconDialog::DoModal
- AFXODLGS/COleChangeIconDialog::GetIconicMetafile
- AFXODLGS/COleChangeIconDialog::m_ci
helpviewer_keywords:
- COleChangeIconDialog [MFC], COleChangeIconDialog
- COleChangeIconDialog [MFC], DoChangeIcon
- COleChangeIconDialog [MFC], DoModal
- COleChangeIconDialog [MFC], GetIconicMetafile
- COleChangeIconDialog [MFC], m_ci
ms.assetid: 8d6e131b-ddbb-4dff-a432-f239efda8e3d
ms.openlocfilehash: 4cbf1137a15a9f86a6377980526e6d188f4d0a69
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504776"
---
# <a name="colechangeicondialog-class"></a>Classe COleChangeIconDialog

Usado para a caixa de diálogo ícone de alteração OLE.

## <a name="syntax"></a>Sintaxe

```
class COleChangeIconDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeIconDialog::COleChangeIconDialog](#colechangeicondialog)|Constrói um objeto `COleChangeIconDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeIconDialog::DoChangeIcon](#dochangeicon)|Executa a alteração especificada na caixa de diálogo.|
|[COleChangeIconDialog::DoModal](#domodal)|Exibe a caixa de diálogo ícone de alteração OLE 2.|
|[COleChangeIconDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeIconDialog::m_ci](#m_ci)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto da classe `COleChangeIconDialog` quando desejar chamar essa caixa de diálogo. Depois que `COleChangeIconDialog` um objeto tiver sido construído, você poderá usar a estrutura [m_ci](#m_ci) para inicializar os valores ou os Estados dos controles na caixa de diálogo. A `m_ci` estrutura é do tipo OLEUICHANGEICON. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a função membro [DoModal](#domodal) .

Para obter mais informações, consulte a estrutura [OLEUICHANGEICON](/windows/win32/api/oledlg/ns-oledlg-oleuichangeiconw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleChangeIconDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="colechangeicondialog"></a>  COleChangeIconDialog::COleChangeIconDialog

Essa função constrói apenas um `COleChangeIconDialog` objeto.

```
explicit COleChangeIconDialog(
    COleClientItem* pItem,
    DWORD dwFlags = CIF_SELECTCURRENT,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Aponta para o item a ser convertido.

*dwFlags*<br/>
Sinalizador de criação, que contém qualquer número dos seguintes valores combinados usando o operador OR bit-a-or:

- CIF_SELECTCURRENT especifica que o botão de opção atual será selecionado inicialmente quando a caixa de diálogo for chamada. Esse é o padrão.

- CIF_SELECTDEFAULT especifica que o botão de opção padrão será selecionado inicialmente quando a caixa de diálogo for chamada.

- CIF_SELECTFROMFILE especifica que o botão de opção do arquivo será selecionado inicialmente quando a caixa de diálogo for chamada.

- CIF_SHOWHELP especifica que o botão ajuda será exibido quando a caixa de diálogo for chamada.

- CIF_USEICONEXE Especifica que o ícone deve ser extraído do executável especificado no `szIconExe` campo [m_ci](#m_ci) em vez de ser recuperado do tipo. Isso é útil para inserir ou vincular a arquivos não OLE.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do `CWnd`tipo) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, chame a função [DoModal](#domodal) .

Para obter mais informações, consulte a estrutura [OLEUICHANGEICON](/windows/win32/api/oledlg/ns-oledlg-oleuichangeiconw) no SDK do Windows.

##  <a name="dochangeicon"></a>  COleChangeIconDialog::DoChangeIcon

Chame essa função para alterar o ícone que representa o item para aquele selecionado na caixa de diálogo depois que [DoModal](#domodal) retornar IDOK.

```
BOOL DoChangeIcon(COleClientItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Aponta para o item cujo ícone está sendo alterado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a alteração for bem-sucedida; caso contrário, 0.

##  <a name="domodal"></a>  COleChangeIconDialog::DoModal

Chame essa função para exibir a caixa de diálogo ícone de alteração OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a `COleDialog::GetLastError` função de membro para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUICHANGEICON](/windows/win32/api/oledlg/nf-oledlg-oleuichangeiconw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo membros da estrutura [m_ci](#m_ci) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

##  <a name="geticonicmetafile"></a>  COleChangeIconDialog::GetIconicMetafile

Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador para o metarquivo que contém o aspecto icônico do novo ícone, se a caixa de diálogo foi ignorada escolhendo **OK**; caso contrário, o ícone como era antes da exibição da caixa de diálogo.

##  <a name="m_ci"></a>  COleChangeIconDialog::m_ci

Estrutura do tipo OLEUICHANGEICON usada para controlar o comportamento da caixa de diálogo Alterar ícone.

```
OLEUICHANGEICON m_ci;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.

Para obter mais informações, consulte a estrutura [OLEUICHANGEICON](/windows/win32/api/oledlg/ns-oledlg-oleuichangeiconw) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
