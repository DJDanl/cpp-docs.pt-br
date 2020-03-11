---
title: Classe COlePasteSpecialDialog
ms.date: 11/04/2016
f1_keywords:
- COlePasteSpecialDialog
- AFXODLGS/COlePasteSpecialDialog
- AFXODLGS/COlePasteSpecialDialog::COlePasteSpecialDialog
- AFXODLGS/COlePasteSpecialDialog::AddFormat
- AFXODLGS/COlePasteSpecialDialog::AddLinkEntry
- AFXODLGS/COlePasteSpecialDialog::AddStandardFormats
- AFXODLGS/COlePasteSpecialDialog::CreateItem
- AFXODLGS/COlePasteSpecialDialog::DoModal
- AFXODLGS/COlePasteSpecialDialog::GetDrawAspect
- AFXODLGS/COlePasteSpecialDialog::GetIconicMetafile
- AFXODLGS/COlePasteSpecialDialog::GetPasteIndex
- AFXODLGS/COlePasteSpecialDialog::GetSelectionType
- AFXODLGS/COlePasteSpecialDialog::m_ps
helpviewer_keywords:
- COlePasteSpecialDialog [MFC], COlePasteSpecialDialog
- COlePasteSpecialDialog [MFC], AddFormat
- COlePasteSpecialDialog [MFC], AddLinkEntry
- COlePasteSpecialDialog [MFC], AddStandardFormats
- COlePasteSpecialDialog [MFC], CreateItem
- COlePasteSpecialDialog [MFC], DoModal
- COlePasteSpecialDialog [MFC], GetDrawAspect
- COlePasteSpecialDialog [MFC], GetIconicMetafile
- COlePasteSpecialDialog [MFC], GetPasteIndex
- COlePasteSpecialDialog [MFC], GetSelectionType
- COlePasteSpecialDialog [MFC], m_ps
ms.assetid: 0e82ef9a-9bbe-457e-8240-42c86a0534f7
ms.openlocfilehash: f4174369620f14f2d1ac410aa5d756c75097ad0f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855425"
---
# <a name="colepastespecialdialog-class"></a>Classe COlePasteSpecialDialog

Usado para a caixa de diálogo de colar especial do OLE.

## <a name="syntax"></a>Sintaxe

```
class COlePasteSpecialDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COlePasteSpecialDialog::COlePasteSpecialDialog](#colepastespecialdialog)|Constrói um objeto `COlePasteSpecialDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COlePasteSpecialDialog:: AddFormat](#addformat)|Adiciona formatos personalizados à lista de formatos que seu aplicativo pode colar.|
|[COlePasteSpecialDialog::AddLinkEntry](#addlinkentry)|Adiciona uma nova entrada à lista de formatos de área de transferência com suporte.|
|[COlePasteSpecialDialog::AddStandardFormats](#addstandardformats)|Adiciona CF_BITMAP, CF_DIB, CF_METAFILEPICT e, opcionalmente, CF_LINKSOURCE à lista de formatos que seu aplicativo pode colar.|
|[COlePasteSpecialDialog:: CreateItem](#createitem)|Cria o item no documento de contêiner usando o formato especificado.|
|[COlePasteSpecialDialog::D oModal](#domodal)|Exibe a caixa de diálogo de colar especial do OLE.|
|[COlePasteSpecialDialog::GetDrawAspect](#getdrawaspect)|Informa se o item deve ser desenhado como um ícone ou não.|
|[COlePasteSpecialDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|
|[COlePasteSpecialDialog::GetPasteIndex](#getpasteindex)|Obtém o índice das opções de colagem disponíveis que foram escolhidas pelo usuário.|
|[COlePasteSpecialDialog:: GetSelectionType](#getselectiontype)|Obtém o tipo de seleção escolhida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COlePasteSpecialDialog:: m_ps](#m_ps)|Uma estrutura do tipo OLEUIPASTESPECIAL que controla a função da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto da classe `COlePasteSpecialDialog` quando desejar chamar essa caixa de diálogo. Depois que um objeto `COlePasteSpecialDialog` tiver sido construído, você poderá usar as funções de membro [AddFormat](#addformat) e [AddStandardFormats](#addstandardformats) para adicionar formatos de área de transferência à caixa de diálogo. Você também pode usar a estrutura [m_ps](#m_ps) para inicializar os valores ou os Estados dos controles na caixa de diálogo. A estrutura de `m_ps` é do tipo OLEUIPASTESPECIAL.

Para obter mais informações, consulte a estrutura [OLEUIPASTESPECIAL](/windows/win32/api/oledlg/ns-oledlg-oleuipastespecialw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COlePasteSpecialDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="addformat"></a>COlePasteSpecialDialog:: AddFormat

Chame essa função para adicionar novos formatos à lista de formatos aos quais seu aplicativo pode dar suporte em uma operação colar especial.

```
void AddFormat(
    const FORMATETC& formatEtc,
    LPTSTR lpszFormat,
    LPTSTR lpszResult,
    DWORD flags);

void AddFormat(
    UINT cf,
    DWORD tymed,
    UINT nFormatID,
    BOOL bEnableIcon,
    BOOL bLink);
```

### <a name="parameters"></a>parâmetros

*fmt*<br/>
Referência ao tipo de dados a ser adicionado.

*lpszFormat*<br/>
Cadeia de caracteres que descreve o formato para o usuário.

*lpszResult*<br/>
Cadeia de caracteres que descreve o resultado se esse formato for escolhido na caixa de diálogo.

*sinalizadores*<br/>
As diferentes opções de vinculação e inserção disponíveis para esse formato. Esse sinalizador é uma combinação de bits de um ou mais valores diferentes no tipo enumerado OLEUIPASTEFLAG.

*CF*<br/>
O formato da área de transferência a ser adicionado.

*tymed*<br/>
Os tipos de mídia disponíveis neste formato. Trata-se de uma combinação de bits de um ou mais valores no tipo enumerado TYMED.

*nFormatID*<br/>
A ID da cadeia de caracteres que identifica esse formato. O formato dessa cadeia de caracteres é duas cadeias de caracteres separadas separadas por um caractere ' \n '. A primeira cadeia de caracteres é a mesma que seria passada no parâmetro *lpstrFormat* e a segunda é a mesma do parâmetro *lpstrResult* .

*bEnableIcon*<br/>
Sinalizador que determina se a caixa de seleção Exibir como ícone é habilitada quando esse formato é escolhido na caixa de listagem.

*Pisca*<br/>
Sinalizador que determina se o botão de opção Colar vínculo está habilitado quando esse formato é escolhido na caixa de listagem.

### <a name="remarks"></a>Comentários

Essa função pode ser chamada para adicionar formatos padrão, como CF_TEXT ou CF_TIFF ou formatos personalizados que seu aplicativo registrou com o sistema. Para obter mais informações sobre como colar objetos de dados em seu aplicativo, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte o tipo de enumeração [TYMED](/windows/win32/api/objidl/ne-objidl-tymed) e a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte o tipo enumerado [OLEUIPASTEFLAG](/windows/win32/api/oledlg/ne-oledlg-oleuipasteflag) no SDK do Windows.

##  <a name="addlinkentry"></a>COlePasteSpecialDialog::AddLinkEntry

Adiciona uma nova entrada à lista de formatos de área de transferência com suporte.

```
OLEUIPASTEFLAG AddLinkEntry(UINT cf);
```

### <a name="parameters"></a>parâmetros

*CF*<br/>
O formato da área de transferência a ser adicionado.

### <a name="return-value"></a>Valor retornado

Uma estrutura [OLEUIPASTEFLAG](/windows/win32/api/oledlg/ne-oledlg-oleuipasteflag) que contém as informações para a nova entrada de link.

##  <a name="addstandardformats"></a>COlePasteSpecialDialog::AddStandardFormats

Chame essa função para adicionar os seguintes formatos de área de transferência à lista de formatos que seu aplicativo pode dar suporte em uma operação colar especial:

```
void AddStandardFormats(BOOL bEnableLink = TRUE);
```

### <a name="parameters"></a>parâmetros

*bEnableLink*<br/>
Sinalizador que determina se é para adicionar CF_LINKSOURCE à lista de formatos que seu aplicativo pode colar.

### <a name="remarks"></a>Comentários

- CF_BITMAP

- CF_DIB

- CF_METAFILEPICT

- **"Objeto incorporado"**

- Opcionalmente **"Origem do link"**

Esses formatos são usados para dar suporte à inserção e vinculação.

##  <a name="colepastespecialdialog"></a>COlePasteSpecialDialog::COlePasteSpecialDialog

Constrói um objeto `COlePasteSpecialDialog`.

```
COlePasteSpecialDialog(
    DWORD dwFlags = PSF_SELECTPASTE,
    COleDataObject* pDataObject = NULL,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>parâmetros

*dwFlags*<br/>
Sinalizador de criação, contém qualquer número dos seguintes sinalizadores combinados usando o operador OR bit-a-OR:

- PSF_SELECTPASTE especifica que o botão de opção colar será verificado inicialmente quando a caixa de diálogo for chamada. Não pode ser usado em combinação com PSF_SELECTPASTELINK. Esse é o padrão.

- PSF_SELECTPASTELINK especifica que o botão de opção Colar vínculo será verificado inicialmente quando a caixa de diálogo for chamada. Não pode ser usado em combinação com PSF_SELECTPASTE.

- PSF_CHECKDISPLAYASICON Especifica que a caixa de seleção Exibir como ícone será marcada inicialmente quando a caixa de diálogo for chamada.

- PSF_SHOWHELP especifica que o botão ajuda será exibido quando a caixa de diálogo for chamada.

*pDataObject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) para colar. Se esse valor for nulo, ele obterá a `COleDataObject` da área de transferência.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Essa função constrói apenas um objeto `COlePasteSpecialDialog`. Para exibir a caixa de diálogo, chame a função [DoModal](#domodal) .

Para obter mais informações, consulte o tipo enumerado [OLEUIPASTEFLAG](/windows/win32/api/oledlg/ne-oledlg-oleuipasteflag) no SDK do Windows.

##  <a name="createitem"></a>COlePasteSpecialDialog:: CreateItem

Cria o novo item que foi escolhido na caixa de diálogo colar especial.

```
BOOL CreateItem(COleClientItem* pNewItem);
```

### <a name="parameters"></a>parâmetros

*pNewItem*<br/>
Aponta para uma instância de `COleClientItem`. Não pode ser NULL.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item foi criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função só deve ser chamada depois que [DoModal](#domodal) retornar IDOK.

##  <a name="domodal"></a>COlePasteSpecialDialog::D oModal

Exibe a caixa de diálogo de colar especial do OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a função de membro `COleDialog::GetLastError` para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUIPASTESPECIAL](/windows/win32/api/oledlg/nf-oledlg-oleuipastespecialw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo membros da estrutura de [m_ps](#m_ps) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar outras funções de membro para recuperar as configurações ou as informações inseridas pelo usuário na caixa de diálogo.

##  <a name="getdrawaspect"></a>COlePasteSpecialDialog::GetDrawAspect

Determina se o usuário optou por exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor retornado

O método necessário para processar o objeto.

- DVASPECT_CONTENT retornado se a caixa de seleção Exibir como ícone não foi marcada quando a caixa de diálogo foi ignorada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi marcada quando a caixa de diálogo foi ignorada.

### <a name="remarks"></a>Comentários

Só chame essa função depois de [DoModal](#domodal) retornar IDOK.

Para obter mais informações sobre o aspecto do desenho, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

##  <a name="geticonicmetafile"></a>COlePasteSpecialDialog::GetIconicMetafile

Obtém o metarquivo associado ao item selecionado pelo usuário.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor retornado

O identificador para o metarquivo que contém o aspecto de icônico do item selecionado, se a caixa de seleção Exibir como ícone foi selecionada quando a caixa de diálogo foi descartada, escolhendo **OK**; caso contrário, NULL.

##  <a name="getpasteindex"></a>COlePasteSpecialDialog::GetPasteIndex

Obtém o valor de índice associado à entrada selecionada pelo usuário.

```
int GetPasteIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice na matriz de estruturas de `OLEUIPASTEENTRY` que foi selecionada pelo usuário. O formato que corresponde ao índice selecionado deve ser usado ao executar a operação de colagem.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte a estrutura [OLEUIPASTEENTRY](/windows/win32/api/oledlg/ns-oledlg-oleuipasteentryw) no SDK do Windows.

##  <a name="getselectiontype"></a>COlePasteSpecialDialog:: GetSelectionType

Determina o tipo de seleção que o usuário fez.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores de tipo de retorno são especificados pelo tipo de enumeração `Selection` declarado na classe `COlePasteSpecialDialog`.

```
enum Selection {
    pasteLink,
    pasteNormal,
    pasteOther,
    pasteStatic
    };
```

A desccriptions resumida desses valores é a seguinte:

- `COlePasteSpecialDialog::pasteLink` o botão de opção Colar vínculo foi marcado e o formato escolhido era um formato OLE padrão.

- `COlePasteSpecialDialog::pasteNormal` o botão de opção colar estava marcado e o formato escolhido era um formato OLE padrão.

- `COlePasteSpecialDialog::pasteOther` o formato selecionado não é um formato OLE padrão.

- `COlePasteSpecialDialog::pasteStatic` o formato escolhido era um metarquivo.

##  <a name="m_ps"></a>COlePasteSpecialDialog:: m_ps

Estrutura do tipo OLEUIPASTESPECIAL usada para controlar o comportamento da caixa de diálogo colar especial.

```
OLEUIPASTESPECIAL m_ps;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.

Para obter mais informações, consulte a estrutura [OLEUIPASTESPECIAL](/windows/win32/api/oledlg/ns-oledlg-oleuipastespecialw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
