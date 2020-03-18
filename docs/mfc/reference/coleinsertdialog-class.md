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
ms.openlocfilehash: a884f946b60be0567f39477f434db8efe041e393
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421698"
---
# <a name="coleinsertdialog-class"></a>Classe COleInsertDialog

Usado para a caixa de diálogo objeto OLE INSERT.

## <a name="syntax"></a>Sintaxe

```
class COleInsertDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleInsertDialog::COleInsertDialog](#coleinsertdialog)|Constrói um objeto `COleInsertDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleInsertDialog:: CreateItem](#createitem)|Cria o item selecionado na caixa de diálogo.|
|[COleInsertDialog::D oModal](#domodal)|Exibe a caixa de diálogo objeto OLE INSERT.|
|[COleInsertDialog:: GetClassID](#getclassid)|Obtém o CLSID associado ao item escolhido.|
|[COleInsertDialog::GetDrawAspect](#getdrawaspect)|Informa se o item deve ser desenhado como um ícone.|
|[COleInsertDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|
|[COleInsertDialog:: GetPathName](#getpathname)|Obtém o caminho completo para o arquivo escolhido na caixa de diálogo.|
|[COleInsertDialog:: GetSelectionType](#getselectiontype)|Obtém o tipo de objeto selecionado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleInsertDialog:: m_io](#m_io)|Uma estrutura do tipo OLEUIINSERTOBJECT que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto da classe `COleInsertDialog` quando desejar chamar essa caixa de diálogo. Depois que um objeto `COleInsertDialog` tiver sido construído, você poderá usar a estrutura [m_io](#m_io) para inicializar os valores ou os Estados dos controles na caixa de diálogo. A estrutura de `m_io` é do tipo OLEUIINSERTOBJECT. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a função membro [DoModal](#domodal) .

> [!NOTE]
>  O assistente de aplicativo-código de contêiner gerado usa essa classe.

Para obter mais informações, consulte a estrutura [OLEUIINSERTOBJECT](/windows/win32/api/oledlg/ns-oledlg-oleuiinsertobjectw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleInsertDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="coleinsertdialog"></a>COleInsertDialog::COleInsertDialog

Essa função constrói apenas um objeto `COleInsertDialog`.

```
COleInsertDialog (
    DWORD dwFlags = IOF_SELECTCREATENEW,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>parâmetros

*dwFlags*<br/>
Sinalizador de criação que contém qualquer número dos seguintes valores a serem combinados usando o operador OR bit-a-OR:

- IOF_SHOWHELP especifica que o botão ajuda será exibido quando a caixa de diálogo for chamada.

- IOF_SELECTCREATENEW Especifica que o botão de opção Criar novo será selecionado inicialmente quando a caixa de diálogo for chamada. Esse é o padrão e não pode ser usado com IOF_SELECTCREATEFROMFILE.

- IOF_SELECTCREATEFROMFILE especifica que o botão de opção criar do arquivo será selecionado inicialmente quando a caixa de diálogo for chamada. Não pode ser usado com IOF_SELECTCREATENEW.

- IOF_CHECKLINK Especifica que a caixa de seleção de link será marcada inicialmente quando a caixa de diálogo for chamada.

- IOF_DISABLELINK especifica que a caixa de seleção de link será desabilitada quando a caixa de diálogo for chamada.

- IOF_CHECKDISPLAYASICON especifica que a caixa de seleção Exibir como ícone será marcada inicialmente, o ícone atual será exibido e o botão Alterar ícone será habilitado quando a caixa de diálogo for chamada.

- IOF_VERIFYSERVERSEXIST especifica que a caixa de diálogo deve validar as classes que ele adiciona à caixa de listagem, garantindo que os servidores especificados no banco de dados de registro existam antes que a caixa de diálogo seja exibida. Definir esse sinalizador pode prejudicar significativamente o desempenho.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai do objeto Dialog será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, chame a função [DoModal](#domodal) .

##  <a name="createitem"></a>COleInsertDialog:: CreateItem

Chame essa função para criar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md) somente se [DoModal](#domodal) retornar IDOK.

```
BOOL CreateItem(COleClientItem* pItem);
```

### <a name="parameters"></a>parâmetros

*pItem*<br/>
Aponta para o item a ser criado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item foi criado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve alocar o objeto de `COleClientItem` antes de poder chamar essa função.

##  <a name="domodal"></a>COleInsertDialog::D oModal

Chame essa função para exibir a caixa de diálogo objeto OLE INSERT.

```
virtual INT_PTR
    DoModal();

INT_PTR
    DoModal(DWORD  dwFlags);
```

### <a name="parameters"></a>parâmetros

*dwFlags*<br/>
Um dos seguintes valores:

`COleInsertDialog::DocObjectsOnly` insere somente DocObjects.

`COleInsertDialog::ControlsOnly` insere apenas os controles ActiveX.

Zero insere nenhum DocObject nem um controle ActiveX. Esse valor resulta na mesma implementação do primeiro protótipo listado acima.

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a função de membro [COleDialog:: GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUIINSERTOBJECT](/windows/win32/api/oledlg/nf-oledlg-oleuiinsertobjectw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo membros da estrutura de [m_io](#m_io) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar outras funções de membro para recuperar as configurações ou informações de entrada na caixa de diálogo pelo usuário.

##  <a name="getclassid"></a>COleInsertDialog:: GetClassID

Chame essa função para obter o CLSID associado ao item selecionado somente se [DoModal](#domodal) retornar IDOK e o tipo de seleção for `COleInsertDialog::createNewItem`.

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o CLSID associado ao item selecionado.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [chave de CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

##  <a name="getdrawaspect"></a>COleInsertDialog::GetDrawAspect

Chame essa função para determinar se o usuário optou por exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor retornado

O método necessário para processar o objeto.

- DVASPECT_CONTENT retornado se a caixa de seleção Exibir como ícone não tiver sido marcada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi marcada.

### <a name="remarks"></a>Comentários

Chame essa função somente se [DoModal](#domodal) retornar IDOK.

Para obter mais informações sobre o aspecto do desenho, consulte estrutura de dados [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

##  <a name="geticonicmetafile"></a>COleInsertDialog::GetIconicMetafile

Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor retornado

O identificador para o metarquivo que contém o aspecto de icônico do item selecionado, se a caixa de seleção Exibir como ícone foi marcada quando o diálogo foi descartado, escolhendo **OK**; caso contrário, NULL.

##  <a name="getpathname"></a>COleInsertDialog:: GetPathName

Chame essa função para obter o caminho completo do arquivo selecionado somente se [DoModal](#domodal) retornar IDOK e o tipo de seleção não for `COleInsertDialog::createNewItem`.

```
CString GetPathName() const;
```

### <a name="return-value"></a>Valor retornado

O caminho completo para o arquivo selecionado na caixa de diálogo. Se o tipo de seleção for `createNewItem`, essa função retornará um `CString` sem sentido no modo de liberação ou causará uma asserção no modo de depuração.

##  <a name="getselectiontype"></a>COleInsertDialog:: GetSelectionType

Chame essa função para obter o tipo de seleção escolhido quando a caixa de diálogo Inserir objeto foi ignorada escolhendo **OK**.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor retornado

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores de tipo de retorno são especificados pelo tipo de enumeração `Selection` declarado na classe `COleInsertDialog`.

```
enum Selection {
    createNewItem,
    insertFromFile,
    linkToFile
    };
```

As breves descrições desses valores são as seguintes:

- `COleInsertDialog::createNewItem` o botão Criar nova opção foi selecionado.

- `COleInsertDialog::insertFromFile` o botão de opção criar do arquivo foi selecionado e a caixa de seleção do link não foi marcada.

- `COleInsertDialog::linkToFile` o botão de opção criar do arquivo foi selecionado e a caixa de seleção do link foi marcada.

##  <a name="m_io"></a>COleInsertDialog:: m_io

Estrutura do tipo OLEUIINSERTOBJECT usada para controlar o comportamento da caixa de diálogo Inserir objeto.

```
OLEUIINSERTOBJECT m_io;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.

Para obter mais informações, consulte a estrutura [OLEUIINSERTOBJECT](/windows/win32/api/oledlg/ns-oledlg-oleuiinsertobjectw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
