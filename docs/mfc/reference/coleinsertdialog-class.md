---
title: Classe COleInsertDialog
ms.date: 11/04/2016
f1_keywords:
- COleInsertDialog
- AFXODLGS/COleInsertDialog
- AFXODLGS/COleInsertDialog::COleInsertDialog
- AFXODLGS/COleInsertDialog::CreateItem
- AFXODLGS/COleInsertDialog::DoModal
- AFXODLGS/COleInsertDialog::GetClassID
- AFXODLGS/COleInsertDialog::GetDrawAspect
- AFXODLGS/COleInsertDialog::GetIconicMetafile
- AFXODLGS/COleInsertDialog::GetPathName
- AFXODLGS/COleInsertDialog::GetSelectionType
- AFXODLGS/COleInsertDialog::m_io
helpviewer_keywords:
- COleInsertDialog [MFC], COleInsertDialog
- COleInsertDialog [MFC], CreateItem
- COleInsertDialog [MFC], DoModal
- COleInsertDialog [MFC], GetClassID
- COleInsertDialog [MFC], GetDrawAspect
- COleInsertDialog [MFC], GetIconicMetafile
- COleInsertDialog [MFC], GetPathName
- COleInsertDialog [MFC], GetSelectionType
- COleInsertDialog [MFC], m_io
ms.assetid: a9ec610b-abde-431e-bd01-c40159a66dbb
ms.openlocfilehash: b5de4ff5daa80e1d8727444a4cfd275597e18c08
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374966"
---
# <a name="coleinsertdialog-class"></a>Classe COleInsertDialog

Usado para a caixa de diálogo Inserir objeto OLE.

## <a name="syntax"></a>Sintaxe

```
class COleInsertDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleInsertDialog::COleInsertInsertDialog](#coleinsertdialog)|Constrói um objeto `COleInsertDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleInsertDialog::CreateItem](#createitem)|Cria o item selecionado na caixa de diálogo.|
|[COleInsertDialog::DoModal](#domodal)|Exibe a caixa de diálogo Inserir objeto OLE.|
|[COleInsertDialog::GetClassID](#getclassid)|Obtém o CLSID associado ao item escolhido.|
|[COleInsertDialog::GetDrawAspect](#getdrawaspect)|Informa se deve desenhar o item como um ícone.|
|[COleInsertDialog::GetIconicMetafile](#geticonicmetafile)|Obtém uma alça para o metaarquivo associado à forma icônica deste item.|
|[COleInsertDialog::GetPathName](#getpathname)|Obtém o caminho completo para o arquivo escolhido na caixa de diálogo.|
|[COleInsertDialog::GetSelectionType](#getselectiontype)|Obtém o tipo de objeto selecionado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleInsertDialog::m_io](#m_io)|Uma estrutura do tipo OLEUIINSERTOBJECT que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto `COleInsertDialog` de classe quando quiser chamar essa caixa de diálogo. Depois `COleInsertDialog` que um objeto for construído, você pode usar a estrutura [m_io](#m_io) para inicializar os valores ou estados de controles na caixa de diálogo. A `m_io` estrutura é do tipo OLEUIINSERTOBJECT. Para obter mais informações sobre como usar esta classe de diálogo, consulte a função [membro DoModal.](#domodal)

> [!NOTE]
> O código de contêiner gerado pelo Assistente do aplicativo usa essa classe.

Para obter mais informações, consulte a estrutura [OLEUIINSERTOBJECT](/windows/win32/api/oledlg/ns-oledlg-oleuiinsertobjectw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas do OLE, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COleInsertDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="coleinsertdialogcoleinsertdialog"></a><a name="coleinsertdialog"></a>COleInsertDialog::COleInsertInsertDialog

Esta função constrói `COleInsertDialog` apenas um objeto.

```
COleInsertDialog (
    DWORD dwFlags = IOF_SELECTCREATENEW,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Sinalizador de criação que contém qualquer número dos seguintes valores a serem combinados usando o operador bitwise-OR:

- IOF_SHOWHELP Especifica que o botão Ajuda será exibido quando a caixa de diálogo for chamada.

- IOF_SELECTCREATENEW Especifica que o botão Criar novo será selecionado inicialmente quando a caixa de diálogo for chamada. Este é o padrão e não pode ser usado com IOF_SELECTCREATEFROMFILE.

- IOF_SELECTCREATEFROMFILE Especifica que o botão Criar do arquivo será selecionado inicialmente quando a caixa de diálogo for chamada. Não pode ser usado com IOF_SELECTCREATENEW.

- IOF_CHECKLINK Especifica que a caixa de seleção Link será verificada inicialmente quando a caixa de diálogo for chamada.

- IOF_DISABLELINK Especifica que a caixa de seleção Link será desativada quando a caixa de diálogo for chamada.

- IOF_CHECKDISPLAYASICON Especifica que a caixa de seleção Exibir como ícone será verificada inicialmente, o ícone atual será exibido e o botão Alterar ícone será ativado quando a caixa de diálogo for chamada.

- IOF_VERIFYSERVERSEXIST Especifica que a caixa de diálogo deve validar as classes que adiciona à caixa de lista, garantindo que os servidores especificados no banco de dados de registro existam antes da caixa de diálogo ser exibida. A configuração deste sinalizador pode prejudicar significativamente o desempenho.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai do objeto de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, ligue para a função [DoModal.](#domodal)

## <a name="coleinsertdialogcreateitem"></a><a name="createitem"></a>COleInsertDialog::CreateItem

Chame esta função para criar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md) somente se [o DoModal](#domodal) retornar o IDOK.

```
BOOL CreateItem(COleClientItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Aponta para o item a ser criado.

### <a name="return-value"></a>Valor retornado

Não zero se o item foi criado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve `COleClientItem` alocar o objeto antes de chamar esta função.

## <a name="coleinsertdialogdomodal"></a><a name="domodal"></a>COleInsertDialog::DoModal

Chame esta função para exibir a caixa de diálogo Inserir objeto OLE.

```
virtual INT_PTR
    DoModal();

INT_PTR
    DoModal(DWORD  dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um dos seguintes valores:

`COleInsertDialog::DocObjectsOnly`insere apenas DocObjects.

`COleInsertDialog::ControlsOnly`insere apenas controles ActiveX.

Zero insere nem um DocObject nem um controle ActiveX. Este valor resulta na mesma implementação do primeiro protótipo listado acima.

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for retornado, ligue para a função de membro [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIInsertObject](/windows/win32/api/oledlg/nf-oledlg-oleuiinsertobjectw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_io,](#m_io) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode ligar para outras funções de membro para recuperar as configurações ou a entrada de informações na caixa de diálogo pelo usuário.

## <a name="coleinsertdialoggetclassid"></a><a name="getclassid"></a>COleInsertDialog::GetClassID

Chame esta função para obter o CLSID associado ao item selecionado somente se `COleInsertDialog::createNewItem`o [DoModal](#domodal) retornar iDOK e o tipo de seleção for .

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o CLSID associado ao item selecionado.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [a tecla CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

## <a name="coleinsertdialoggetdrawaspect"></a><a name="getdrawaspect"></a>COleInsertDialog::GetDrawAspect

Chame esta função para determinar se o usuário escolheu exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor retornado

O método necessário para renderizar o objeto.

- DVASPECT_CONTENT Retornado se a caixa de seleção Exibir como ícone não foi verificada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi verificada.

### <a name="remarks"></a>Comentários

Ligue para esta função somente se [o DoModal](#domodal) retornar o IDOK.

Para obter mais informações sobre o aspecto do desenho, consulte a estrutura de dados [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

## <a name="coleinsertdialoggeticonicmetafile"></a><a name="geticonicmetafile"></a>COleInsertDialog::GetIconicMetafile

Chame esta função para obter uma alça para o metaarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor retornado

A alça para o metaarquivo contendo o aspecto icônico do item selecionado, se a caixa de seleção Exibir como ícone foi verificada quando a caixa de diálogo foi rejeitada escolhendo **OK**; caso contrário, NULL.

## <a name="coleinsertdialoggetpathname"></a><a name="getpathname"></a>COleInsertDialog::GetPathName

Chame esta função para obter o caminho completo do arquivo selecionado somente se o `COleInsertDialog::createNewItem` [DoModal](#domodal) retornar o IDOK e o tipo de seleção não for .

```
CString GetPathName() const;
```

### <a name="return-value"></a>Valor retornado

O caminho completo para o arquivo selecionado na caixa de diálogo. Se o tipo `createNewItem`de seleção `CString` for, esta função retorna um modo de liberação sem sentido ou causa uma afirmação no modo de depuração.

## <a name="coleinsertdialoggetselectiontype"></a><a name="getselectiontype"></a>COleInsertDialog::GetSelectionType

Chame esta função para obter o tipo de seleção escolhido quando a caixa de diálogo Inserir objeto foi descartada escolhendo **OK**.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor retornado

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores do tipo `Selection` de retorno são especificados `COleInsertDialog` pelo tipo de enumeração declarado na classe.

```
enum Selection {
    createNewItem,
    insertFromFile,
    linkToFile
    };
```

Breves descrições desses valores seguem:

- `COleInsertDialog::createNewItem`O botão criar novo foi selecionado.

- `COleInsertDialog::insertFromFile`O botão de rádio Criar do arquivo foi selecionado e a caixa de seleção Link não foi verificada.

- `COleInsertDialog::linkToFile`O botão de rádio Criar do arquivo foi selecionado e a caixa de seleção Link foi verificada.

## <a name="coleinsertdialogm_io"></a><a name="m_io"></a>COleInsertDialog::m_io

Estrutura do tipo OLEUIINSERTOBJECT usado para controlar o comportamento da caixa de diálogo Inserir objeto.

```
OLEUIINSERTOBJECT m_io;
```

### <a name="remarks"></a>Comentários

Os membros desta estrutura podem ser modificados diretamente ou através de funções de membros.

Para obter mais informações, consulte a estrutura [OLEUIINSERTOBJECT](/windows/win32/api/oledlg/ns-oledlg-oleuiinsertobjectw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
