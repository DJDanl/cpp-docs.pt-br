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
ms.openlocfilehash: 6cdc0ed6bfa4765817de8b7628f339db5e7e5bf5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369631"
---
# <a name="colechangeicondialog-class"></a>Classe COleChangeIconDialog

Usado para a caixa de diálogo Ícone de alteração do OLE.

## <a name="syntax"></a>Sintaxe

```
class COleChangeIconDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeIconDiálogo::COleChangeIconDiálogo](#colechangeicondialog)|Constrói um objeto `COleChangeIconDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeIconDiálogo::DoChangeIcon](#dochangeicon)|Executa a alteração especificada na caixa de diálogo.|
|[COleChangeIconDiálogo::DoModal](#domodal)|Exibe a caixa de diálogo Ícone de alteração OLE 2.|
|[COleChangeIconDiálogo::GetIconicMetafile](#geticonicmetafile)|Obtém uma alça para o metaarquivo associado à forma icônica deste item.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleChangeIconDiálogo::m_ci](#m_ci)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto `COleChangeIconDialog` de classe quando quiser chamar essa caixa de diálogo. Depois `COleChangeIconDialog` que um objeto for construído, você pode usar a estrutura [m_ci](#m_ci) para inicializar os valores ou estados de controles na caixa de diálogo. A `m_ci` estrutura é do tipo OLEUICHANGEICON. Para obter mais informações sobre como usar esta classe de diálogo, consulte a função [membro DoModal.](#domodal)

Para obter mais informações, consulte a estrutura [OLEUICHANGEICON](/windows/win32/api/oledlg/ns-oledlg-oleuichangeiconw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas da OLE, consulte o artigo [Caixas de Diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COleChangeIconDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="colechangeicondialogcolechangeicondialog"></a><a name="colechangeicondialog"></a>COleChangeIconDiálogo::COleChangeIconDiálogo

Esta função constrói `COleChangeIconDialog` apenas um objeto.

```
explicit COleChangeIconDialog(
    COleClientItem* pItem,
    DWORD dwFlags = CIF_SELECTCURRENT,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Aponta para o item a ser convertido.

*dwFlags*<br/>
Sinalizador de criação, que contém qualquer número dos seguintes valores combinados usando o bitwise ou operador:

- CIF_SELECTCURRENT Especifica que o botão de rádio Corrente será selecionado inicialmente quando a caixa de diálogo for chamada. Esse é o padrão.

- CIF_SELECTDEFAULT Especifica que o botão de rádio Padrão será selecionado inicialmente quando a caixa de diálogo for chamada.

- CIF_SELECTFROMFILE Especifica que o botão de rádio De arquivo será selecionado inicialmente quando a caixa de diálogo for chamada.

- CIF_SHOWHELP Especifica que o botão Ajuda será exibido quando a caixa de diálogo for chamada.

- CIF_USEICONEXE Especifica que o ícone deve ser extraído do `szIconExe` executável especificado no campo de [m_ci](#m_ci) em vez de recuperado do tipo. Isso é útil para incorporar ou vincular a arquivos não-OLE.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, ligue para a função [DoModal.](#domodal)

Para obter mais informações, consulte a estrutura [OLEUICHANGEICON](/windows/win32/api/oledlg/ns-oledlg-oleuichangeiconw) no SDK do Windows.

## <a name="colechangeicondialogdochangeicon"></a><a name="dochangeicon"></a>COleChangeIconDiálogo::DoChangeIcon

Chame esta função para alterar o ícone representando o item para o selecionado na caixa de diálogo após o [Retorno do DoModal](#domodal) IDOK.

```
BOOL DoChangeIcon(COleClientItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Aponta para o item cujo ícone está mudando.

### <a name="return-value"></a>Valor retornado

Não zero se a mudança for bem sucedida; caso contrário, 0.

## <a name="colechangeicondialogdomodal"></a><a name="domodal"></a>COleChangeIconDiálogo::DoModal

Chame esta função para exibir a caixa de diálogo Ícone de alteração do OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for `COleDialog::GetLastError` devolvido, ligue para a função do membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIChangeIcon](/windows/win32/api/oledlg/nf-oledlg-oleuichangeiconw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_ci,](#m_ci) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode ligar para outras funções de membro para recuperar as configurações ou informações que foram inseridas pelo usuário na caixa de diálogo.

## <a name="colechangeicondialoggeticonicmetafile"></a><a name="geticonicmetafile"></a>COleChangeIconDiálogo::GetIconicMetafile

Chame esta função para obter uma alça para o metaarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor retornado

A alça para o metaarquivo contendo o aspecto icônico do novo ícone, se a caixa de diálogo foi descartada escolhendo **OK**; caso contrário, o ícone como era antes da exibição da caixa de diálogo.

## <a name="colechangeicondialogm_ci"></a><a name="m_ci"></a>COleChangeIconDiálogo::m_ci

Estrutura do tipo OLEUICHANGEICON usado para controlar o comportamento da caixa de diálogo Alterar ícone.

```
OLEUICHANGEICON m_ci;
```

### <a name="remarks"></a>Comentários

Os membros desta estrutura podem ser modificados diretamente ou através de funções de membros.

Para obter mais informações, consulte a estrutura [OLEUICHANGEICON](/windows/win32/api/oledlg/ns-oledlg-oleuichangeiconw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
