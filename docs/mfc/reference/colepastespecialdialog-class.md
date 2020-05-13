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
ms.openlocfilehash: 47fb421ef9dedcae7f92d33f55988dbbc2ea452d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753820"
---
# <a name="colepastespecialdialog-class"></a>Classe COlePasteSpecialDialog

Usado para a caixa de diálogo Especial Pasta OLE.

## <a name="syntax"></a>Sintaxe

```
class COlePasteSpecialDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePasteSpecialDialog::COlePasteSpecialDialog](#colepastespecialdialog)|Constrói um objeto `COlePasteSpecialDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePasteSpecialDialog::AddFormat](#addformat)|Adiciona formatos personalizados à lista de formatos que seu aplicativo pode colar.|
|[COlePasteSpecialDialog::AddLinkEntry](#addlinkentry)|Adiciona uma nova entrada à lista de formatos de área de transferência suportados.|
|[COlePasteSpecialDialog::AddStandardFormats](#addstandardformats)|Adiciona CF_BITMAP, CF_DIB, CF_METAFILEPICT e opcionalmente CF_LINKSOURCE à lista de formatos que seu aplicativo pode colar.|
|[COlePasteSpecialDialog::CreateItem](#createitem)|Cria o item no documento do contêiner usando o formato especificado.|
|[COlePasteSpecialDialog::DoModal](#domodal)|Exibe a caixa de diálogo Especial Pasta OLE.|
|[COlePasteSpecialDialog::GetDrawAspect](#getdrawaspect)|Informa se deve desenhar o item como um ícone ou não.|
|[COlePasteSpecialDialog::GetIconicMetafile](#geticonicmetafile)|Obtém uma alça para o metaarquivo associado à forma icônica deste item.|
|[COlePasteSpecialDialog::GetPasteIndex](#getpasteindex)|Obtém o índice de opções de colar disponíveis que foi escolhido pelo usuário.|
|[COlePasteSpecialDialog::GetSelectionType](#getselectiontype)|Recebe o tipo de seleção escolhida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePasteSpecialDialog::m_ps](#m_ps)|Uma estrutura do tipo OLEUIPASTESPECIAL que controla a função da caixa de diálogo.|

## <a name="remarks"></a>Comentários

Crie um objeto `COlePasteSpecialDialog` de classe quando quiser chamar essa caixa de diálogo. Depois `COlePasteSpecialDialog` que um objeto for construído, você pode usar as funções de membro [AddFormat](#addformat) e [AddStandardFormats](#addstandardformats) para adicionar formatos de área de transferência à caixa de diálogo. Você também pode usar a estrutura [m_ps](#m_ps) para inicializar os valores ou estados de controles na caixa de diálogo. A `m_ps` estrutura é do tipo OLEUIPASTESPECIAL.

Para obter mais informações, consulte a estrutura [OLEUIPASTESPECIAL](/windows/win32/api/oledlg/ns-oledlg-oleuipastespecialw) no SDK do Windows.

Para obter mais informações sobre caixas de diálogo específicas do OLE, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COlePasteSpecialDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="colepastespecialdialogaddformat"></a><a name="addformat"></a>COlePasteSpecialDialog::AddFormat

Chame esta função para adicionar novos formatos à lista de formatos que seu aplicativo pode suportar em uma operação Colar Especial.

```cpp
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

### <a name="parameters"></a>Parâmetros

*Fmt*<br/>
Referência ao tipo de dados a ser adicionado.

*lpszFormat*<br/>
String que descreve o formato para o usuário.

*lpszResultado*<br/>
String que descreve o resultado se esse formato for escolhido na caixa de diálogo.

*Sinalizadores*<br/>
As diferentes opções de vinculação e incorporação disponíveis para este formato. Esta bandeira é uma combinação um pouco mais de um ou mais dos diferentes valores no tipo enumerado OLEUIPASTEFLAG.

*Cf*<br/>
O formato da área de transferência para adicionar.

*Tymed*<br/>
Os tipos de mídia disponíveis neste formato. Esta é uma combinação um pouco mais de um ou mais dos valores do tipo enumerado TYMED.

*Nformatid*<br/>
O ID da string que identifica este formato. O formato desta seqüência é de duas strings separadas separadas por um caractere '\n'. A primeira seqüência é a mesma que seria passada no parâmetro *lpstrFormat,* e a segunda é a mesma do parâmetro *lpstrResult.*

*bEnableIcon*<br/>
Sinalizador que determina se a caixa de seleção Exibir como ícone está ativada quando esse formato é escolhido na caixa de lista.

*Piscar*<br/>
Sinalizador que determina se o botão de rádio Colar link está ativado quando este formato é escolhido na caixa de lista.

### <a name="remarks"></a>Comentários

Essa função pode ser chamada para adicionar formatos padrão, como CF_TEXT ou CF_TIFF ou formatos personalizados que seu aplicativo registrou no sistema. Para obter mais informações sobre a colagem de objetos de dados em seu aplicativo, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte o tipo de enumeração [TYMED](/windows/win32/api/objidl/ne-objidl-tymed) e a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [o tipo enumerado OLEUIPASTEFLAG](/windows/win32/api/oledlg/ne-oledlg-oleuipasteflag) no Windows SDK.

## <a name="colepastespecialdialogaddlinkentry"></a><a name="addlinkentry"></a>COlePasteSpecialDialog::AddLinkEntry

Adiciona uma nova entrada à lista de formatos de área de transferência suportados.

```
OLEUIPASTEFLAG AddLinkEntry(UINT cf);
```

### <a name="parameters"></a>Parâmetros

*Cf*<br/>
O formato da área de transferência para adicionar.

### <a name="return-value"></a>Valor retornado

Uma [estrutura OLEUIPASTEFLAG](/windows/win32/api/oledlg/ne-oledlg-oleuipasteflag) contendo as informações para a nova entrada de link.

## <a name="colepastespecialdialogaddstandardformats"></a><a name="addstandardformats"></a>COlePasteSpecialDialog::AddStandardFormats

Chame esta função para adicionar os seguintes formatos de área de transferência à lista de formatos que seu aplicativo pode suportar em uma operação Colar Especial:

```cpp
void AddStandardFormats(BOOL bEnableLink = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnableLink*<br/>
Sinalizador que determina se deve adicionar CF_LINKSOURCE à lista de formatos que seu aplicativo pode colar.

### <a name="remarks"></a>Comentários

- CF_BITMAP

- CF_DIB

- Cf_metafilepict

- **"Objeto incorporado"**

- (opcionalmente) **"Fonte de Link"**

Esses formatos são usados para suportar incorporação e vinculação.

## <a name="colepastespecialdialogcolepastespecialdialog"></a><a name="colepastespecialdialog"></a>COlePasteSpecialDialog::COlePasteSpecialDialog

Constrói um objeto `COlePasteSpecialDialog`.

```
COlePasteSpecialDialog(
    DWORD dwFlags = PSF_SELECTPASTE,
    COleDataObject* pDataObject = NULL,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Sinalizador de criação, contém qualquer número dos seguintes sinalizadores combinados usando o operador bitwise-OR:

- PSF_SELECTPASTE Especifica que o botão de rádio Colar será verificado inicialmente quando a caixa de diálogo for chamada. Não pode ser usado em combinação com PSF_SELECTPASTELINK. Esse é o padrão.

- PSF_SELECTPASTELINK Especifica que o botão de rádio Colar link será verificado inicialmente quando a caixa de diálogo for chamada. Não pode ser usado em combinação com PSF_SELECTPASTE.

- PSF_CHECKDISPLAYASICON Especifica que a caixa de seleção Exibir como ícone será verificada inicialmente quando a caixa de diálogo for chamada.

- PSF_SHOWHELP Especifica que o botão Ajuda será exibido quando a caixa de diálogo for chamada.

*Pdataobject*<br/>
Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) para colar. Se esse valor for NULO, ele obtém o `COleDataObject` da Área de Transferência.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Esta função só `COlePasteSpecialDialog` constrói um objeto. Para exibir a caixa de diálogo, ligue para a função [DoModal.](#domodal)

Para obter mais informações, consulte [o tipo enumerado OLEUIPASTEFLAG](/windows/win32/api/oledlg/ne-oledlg-oleuipasteflag) no Windows SDK.

## <a name="colepastespecialdialogcreateitem"></a><a name="createitem"></a>COlePasteSpecialDialog::CreateItem

Cria o novo item escolhido na caixa de diálogo Colar Especial.

```
BOOL CreateItem(COleClientItem* pNewItem);
```

### <a name="parameters"></a>Parâmetros

*pNewItem*<br/>
Aponta para `COleClientItem` um exemplo. Não pode ser NULL.

### <a name="return-value"></a>Valor retornado

Não zero se o item foi criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função só deve ser chamada depois [que o DoModal](#domodal) retornar o IDOK.

## <a name="colepastespecialdialogdomodal"></a><a name="domodal"></a>COlePasteSpecialDialog::DoModal

Exibe a caixa de diálogo Especial Pasta OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for `COleDialog::GetLastError` devolvido, ligue para a função do membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIPasteSpecial](/windows/win32/api/oledlg/nf-oledlg-oleuipastespecialw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_ps,](#m_ps) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode ligar para outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

## <a name="colepastespecialdialoggetdrawaspect"></a><a name="getdrawaspect"></a>COlePasteSpecialDialog::GetDrawAspect

Determina se o usuário escolheu exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor retornado

O método necessário para renderizar o objeto.

- DVASPECT_CONTENT devolvido se a caixa de seleção Exibir como ícone não foi verificada quando a caixa de diálogo foi rejeitada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi marcada quando a caixa de diálogo foi rejeitada.

### <a name="remarks"></a>Comentários

Só ligue para esta função depois que [o DoModal](#domodal) retornar o IDOK.

Para obter mais informações sobre o aspecto do desenho, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

## <a name="colepastespecialdialoggeticonicmetafile"></a><a name="geticonicmetafile"></a>COlePasteSpecialDialog::GetIconicMetafile

Obtém o metaarquivo associado ao item selecionado pelo usuário.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor retornado

A alça para o metaarquivo contendo o aspecto icônico do item selecionado, se a caixa de seleção Exibir como ícone foi selecionada quando a caixa de diálogo foi rejeitada escolhendo **OK**; caso contrário, NULL.

## <a name="colepastespecialdialoggetpasteindex"></a><a name="getpasteindex"></a>COlePasteSpecialDialog::GetPasteIndex

Obtém o valor do índice associado à entrada que o usuário selecionou.

```
int GetPasteIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice na `OLEUIPASTEENTRY` matriz de estruturas que foi selecionada pelo usuário. O formato que corresponde ao índice selecionado deve ser usado na execução da operação de colar.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte a estrutura [OLEUIPASTEENTRY](/windows/win32/api/oledlg/ns-oledlg-oleuipasteentryw) no SDK do Windows.

## <a name="colepastespecialdialoggetselectiontype"></a><a name="getselectiontype"></a>COlePasteSpecialDialog::GetSelectionType

Determina o tipo de seleção feita pelo usuário.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor retornado

Devoluções tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores do tipo `Selection` de retorno são especificados `COlePasteSpecialDialog` pelo tipo de enumeração declarado na classe.

```
enum Selection {
    pasteLink,
    pasteNormal,
    pasteOther,
    pasteStatic
    };
```

Breves desccriptions desses valores seguem:

- `COlePasteSpecialDialog::pasteLink`O botão de rádio Paste Link foi verificado e o formato escolhido era um formato OLE padrão.

- `COlePasteSpecialDialog::pasteNormal`O botão de rádio Pasta foi verificado e o formato escolhido era um formato OLE padrão.

- `COlePasteSpecialDialog::pasteOther`O formato selecionado não é um formato OLE padrão.

- `COlePasteSpecialDialog::pasteStatic`O formato escolhido foi um metaarquivo.

## <a name="colepastespecialdialogm_ps"></a><a name="m_ps"></a>COlePasteSpecialDialog::m_ps

Estrutura do tipo OLEUIPASTESPECIAL usada para controlar o comportamento da caixa de diálogo Colar Especial.

```
OLEUIPASTESPECIAL m_ps;
```

### <a name="remarks"></a>Comentários

Os membros desta estrutura podem ser modificados diretamente ou através de funções de membros.

Para obter mais informações, consulte a estrutura [OLEUIPASTESPECIAL](/windows/win32/api/oledlg/ns-oledlg-oleuipastespecialw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
