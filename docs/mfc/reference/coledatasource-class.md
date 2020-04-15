---
title: Classe COleDataSource
ms.date: 11/04/2016
f1_keywords:
- COleDataSource
- AFXOLE/COleDataSource
- AFXOLE/COleDataSource::COleDataSource
- AFXOLE/COleDataSource::CacheData
- AFXOLE/COleDataSource::CacheGlobalData
- AFXOLE/COleDataSource::DelayRenderData
- AFXOLE/COleDataSource::DelayRenderFileData
- AFXOLE/COleDataSource::DelaySetData
- AFXOLE/COleDataSource::DoDragDrop
- AFXOLE/COleDataSource::Empty
- AFXOLE/COleDataSource::FlushClipboard
- AFXOLE/COleDataSource::GetClipboardOwner
- AFXOLE/COleDataSource::OnRenderData
- AFXOLE/COleDataSource::OnRenderFileData
- AFXOLE/COleDataSource::OnRenderGlobalData
- AFXOLE/COleDataSource::OnSetData
- AFXOLE/COleDataSource::SetClipboard
helpviewer_keywords:
- COleDataSource [MFC], COleDataSource
- COleDataSource [MFC], CacheData
- COleDataSource [MFC], CacheGlobalData
- COleDataSource [MFC], DelayRenderData
- COleDataSource [MFC], DelayRenderFileData
- COleDataSource [MFC], DelaySetData
- COleDataSource [MFC], DoDragDrop
- COleDataSource [MFC], Empty
- COleDataSource [MFC], FlushClipboard
- COleDataSource [MFC], GetClipboardOwner
- COleDataSource [MFC], OnRenderData
- COleDataSource [MFC], OnRenderFileData
- COleDataSource [MFC], OnRenderGlobalData
- COleDataSource [MFC], OnSetData
- COleDataSource [MFC], SetClipboard
ms.assetid: 02c8ee7d-8e10-4463-8613-bb2a0305ca69
ms.openlocfilehash: fcf9505a7792aea6807e37f05cd1cb1aaad55830
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366113"
---
# <a name="coledatasource-class"></a>Classe COleDataSource

Funciona como um cache no qual um aplicativo coloca os dados que oferecerá durante operações de transferência de dados, como área de transferência ou operações de arrastar e soltar.

## <a name="syntax"></a>Sintaxe

```
class COleDataSource : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDataFonte::COleDataSource](#coledatasource)|Constrói um objeto `COleDataSource`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDataFonte::CacheData](#cachedata)|Oferece dados em um formato `STGMEDIUM` especificado usando uma estrutura.|
|[COleDataFonte::CacheGlobalData](#cacheglobaldata)|Oferece dados em um formato especificado usando um HGLOBAL.|
|[COleDataFonte::DelayRenderData](#delayrenderdata)|Oferece dados em um formato especificado usando renderização atrasada.|
|[COleDataFonte::DelayRenderFileData](#delayrenderfiledata)|Oferece dados em um formato `CFile` especificado em um ponteiro.|
|[COleDataFonte::DelaySetData](#delaysetdata)|Chamado para todos os formatos que são suportados em `OnSetData`.|
|[COleDataFonte::DoDragDrop](#dodragdrop)|Realiza operações de arrastar e soltar com uma fonte de dados.|
|[COleDataFonte::Vazio](#empty)|Esvazia `COleDataSource` o objeto de dados.|
|[COleDataFonte::FlushClipboard](#flushclipboard)|Presta todos os dados à Área de Transferência.|
|[COleDataFonte::GetClipboardOwner](#getclipboardowner)|Verifica se os dados colocados na área de transferência ainda estão lá.|
|[COleDataFonte::OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|
|[COleDataFonte::OnRenderFileData](#onrenderfiledata)|Recupera dados em `CFile` uma parte da renderização atrasada.|
|[COleDataFonte::OnRenderGlobalData](#onrenderglobaldata)|Recupera dados em um HGLOBAL como parte da renderização atrasada.|
|[COleDataFonte::OnSetData](#onsetdata)|Chamado para substituir os `COleDataSource` dados no objeto.|
|[COleDataFonte::SetClipboard](#setclipboard)|Coloca um `COleDataSource` objeto na área de transferência.|

## <a name="remarks"></a>Comentários

Você pode criar fontes de dados OLE diretamente. Alternativamente, as classes [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [COleServerItem](../../mfc/reference/coleserveritem-class.md) criam fontes `CopyToClipboard` `DoDragDrop` de dados OLE em resposta às suas funções e aos membros. Consulte [COleServerItem::CopyToClipboard](../../mfc/reference/coleserveritem-class.md#copytoclipboard) para obter uma breve descrição. Substituir a `OnGetClipboardData` função de membro da classe de item ou item do servidor do cliente para adicionar `CopyToClipboard` `DoDragDrop` formatos adicionais de área de transferência aos dados na fonte de dados OLE criada para a função ou membro.

Sempre que você quiser preparar dados para uma transferência, você deve criar um objeto desta classe e preenchê-los com seus dados usando o método mais apropriado para seus dados. A forma como ele é inserido em uma fonte de dados é diretamente afetada por se os dados são fornecidos imediatamente (renderização imediata) ou sob demanda (renderização atrasada). Para cada formato de área de transferência em que você está fornecendo dados passando o formato de área de transferência para ser usado (e uma estrutura [formatetc](/windows/win32/api/objidl/ns-objidl-formatetc) opcional), chame [DelayRenderData](#delayrenderdata).

Para obter mais informações sobre fontes de dados e transferência de dados, consulte o artigo [Data Objects and Data Sources (OLE)](../../mfc/data-objects-and-data-sources-ole.md). Além disso, o artigo [Tópicos da Área de Transferência](../../mfc/clipboard.md) descreve o mecanismo de área de transferência OLE.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleDataSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coledatasourcecachedata"></a><a name="cachedata"></a>COleDataFonte::CacheData

Chame esta função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void CacheData(
    CLIPFORMAT cfFormat,
    LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato de área de transferência em que os dados devem ser oferecidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpstgmedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) contendo os dados no formato especificado.

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser oferecidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="remarks"></a>Comentários

Você deve fornecer os dados, porque esta função fornece-os usando renderização imediata. Os dados são armazenados em cache até que seja necessário.

Forneça os dados usando uma estrutura [STGMEDIUM.](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) Você também pode `CacheGlobalData` usar a função de membro se a quantidade de dados que você está fornecendo for pequena o suficiente para ser transferida eficientemente usando um HGLOBAL.

Após a `CacheData` chamada `ptd` para `lpFormatEtc` o membro e o conteúdo do *lpStgMedium* são de propriedade do objeto de dados, não pelo chamador.

Para usar a renderização atrasada, ligue para a função [membro DelayRenderData](#delayrenderdata) ou [DelayRenderFileData.](#delayrenderfiledata) Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte as estruturas [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledatasourcecacheglobaldata"></a><a name="cacheglobaldata"></a>COleDataFonte::CacheGlobalData

Chame esta função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void CacheGlobalData(
    CLIPFORMAT cfFormat,
    HGLOBAL hGlobal,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato de área de transferência em que os dados devem ser oferecidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Hglobal*<br/>
Manuseie o bloco de memória global que contém os dados no formato especificado.

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser oferecidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="remarks"></a>Comentários

Esta função fornece os dados usando renderização imediata, portanto, você deve fornecer os dados ao chamar a função; os dados são armazenados em cache até que seja necessário. Use `CacheData` a função de membro se você estiver fornecendo uma grande quantidade de dados ou se você precisar de um meio de armazenamento estruturado.

Para usar a renderização atrasada, ligue para a função [membro DelayRenderData](#delayrenderdata) ou [DelayRenderFileData.](#delayrenderfiledata) Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledatasourcecoledatasource"></a><a name="coledatasource"></a>COleDataFonte::COleDataSource

Constrói um objeto `COleDataSource`.

```
COleDataSource();
```

## <a name="coledatasourcedelayrenderdata"></a><a name="delayrenderdata"></a>COleDataFonte::DelayRenderData

Chame esta função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void DelayRenderData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato de área de transferência em que os dados devem ser oferecidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser oferecidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="remarks"></a>Comentários

Esta função fornece os dados usando renderização atrasada, de modo que os dados não são fornecidos imediatamente. A função [onRenderData](#onrenderdata) ou [onRenderGlobalData](#onrenderglobaldata) é chamada para solicitar os dados.

Use esta função se você não for `CFile` fornecer seus dados através de um objeto. Se você for fornecer os `CFile` dados através de um objeto, chame a função membro [DelayRenderFileData.](#delayrenderfiledata) Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para usar renderização imediata, ligue para a função de membro [CacheData](#cachedata) ou [CacheGlobalData.](#cacheglobaldata)

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledatasourcedelayrenderfiledata"></a><a name="delayrenderfiledata"></a>COleDataFonte::DelayRenderFileData

Chame esta função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void DelayRenderFileData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato de área de transferência em que os dados devem ser oferecidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser oferecidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="remarks"></a>Comentários

Esta função fornece os dados usando renderização atrasada, de modo que os dados não são fornecidos imediatamente. A função [membro OnRenderFileData](#onrenderfiledata) é chamada para solicitar os dados.

Use esta função se você `CFile` estiver indo para usar um objeto para fornecer os dados. Se você não for `CFile` usar um objeto, chame a função [membro DelayRenderData.](#delayrenderdata) Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para usar renderização imediata, ligue para a função de membro [CacheData](#cachedata) ou [CacheGlobalData.](#cacheglobaldata)

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledatasourcedelaysetdata"></a><a name="delaysetdata"></a>COleDataFonte::DelaySetData

Ligue para esta função para suportar a alteração do conteúdo da fonte de dados.

```
void DelaySetData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato de área de transferência no qual os dados devem ser colocados. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser substituídos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="remarks"></a>Comentários

[O OnSetData](#onsetdata) será chamado pela estrutura quando isso acontecer. Isso só é usado quando a estrutura retorna a fonte de dados do [COleServerItem::GetDataSource](../../mfc/reference/coleserveritem-class.md#getdatasource). Se `DelaySetData` não for `OnSetData` chamado, sua função nunca será chamada. `DelaySetData`deve ser chamado para `FORMATETC` cada área de transferência ou formato que você suporta.

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledatasourcedodragdrop"></a><a name="dodragdrop"></a>COleDataFonte::DoDragDrop

Ligue `DoDragDrop` para a função member para executar uma operação de arrastar e soltar para essa fonte de dados, normalmente em um manipulador [CWnd::OnLButtonDown.](../../mfc/reference/cwnd-class.md#onlbuttondown)

```
DROPEFFECT DoDragDrop(
    DWORD dwEffects = DROPEFFECT_COPY|DROPEFFECT_MOVE|DROPEFFECT_LINK,
    LPCRECT lpRectStartDrag = NULL,
    COleDropSource* pDropSource = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwEffects*<br/>
Operações de arrastar e soltar que são permitidas nesta fonte de dados. Pode ser um ou mais dos seguintes:

- DROPEFFECT_COPY Uma operação de cópia poderia ser realizada.

- DROPEFFECT_MOVE uma operação de movimento poderia ser realizada.

- DROPEFFECT_LINK Um link dos dados descartados para os dados originais poderia ser estabelecido.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrasto pode ocorrer.

*lpRectStartDrag*<br/>
Ponteiro para o retângulo que define onde o arrasto realmente começa. Para obter mais informações, consulte a seção Comentários a seguir.

*pDropSource*<br/>
Aponta para uma fonte de queda. Se NULL, então uma implementação padrão do [COleDropSource](../../mfc/reference/coledropsource-class.md) será usada.

### <a name="return-value"></a>Valor retornado

Efeito de queda gerado pela operação arrastar e soltar; caso contrário, DROPEFFECT_NONE se a operação nunca começar porque o usuário liberou o botão do mouse antes de sair do retângulo fornecido.

### <a name="remarks"></a>Comentários

A operação de arrastar e soltar não começa imediatamente. Ele espera até que o cursor do mouse deixe o retângulo especificado pelo *lpRectStartDrag* ou até que um número especificado de milissegundos tenha passado. Se *lpRectStartDrag* for NULL, o tamanho do retângulo será de um pixel.

O tempo de atraso é especificado por uma configuração de chave de registro. Você pode alterar o tempo de atraso ligando para [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, um valor padrão de 200 milissegundos será usado. O tempo de atraso do arrasto é armazenado da seguinte forma:

- O tempo de atraso do Windows NT Drag é armazenado no HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.

- Windows 3.x O tempo de atraso de arrastar é armazenado no WIN. Arquivo INI, na seção [Windows}.

- Windows 95/98 O tempo de atraso do arrastar é armazenado em uma versão em cache do WIN. Ini.

Para obter mais informações sobre como as informações de atraso de arrasto são armazenadas no registro ou no . Arquivo INI, consulte [WriteProfileString](/windows/win32/api/winbase/nf-winbase-writeprofilestringw) no Windows SDK.

Para obter mais informações, consulte o artigo [OLE arrastar e soltar](../../mfc/drag-and-drop-ole.md).

## <a name="coledatasourceempty"></a><a name="empty"></a>COleDataFonte::Vazio

Chame esta função `COleDataSource` para esvaziar o objeto de dados.

```
void Empty();
```

### <a name="remarks"></a>Comentários

Os formatos de renderização em cache e atraso são esvaziados para que possam ser reutilizados.

Para obter mais informações, consulte [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) no Windows SDK.

## <a name="coledatasourceflushclipboard"></a><a name="flushclipboard"></a>COleDataFonte::FlushClipboard

Renderiza dados que estão na área de transferência e, em seguida, permite que você cole dados da Área de Transferência depois que seu aplicativo é desligado.

```
static void PASCAL FlushClipboard();
```

### <a name="remarks"></a>Comentários

Use [SetClipboard](#setclipboard) para colocar dados na área de transferência.

## <a name="coledatasourcegetclipboardowner"></a><a name="getclipboardowner"></a>COleDataFonte::GetClipboardOwner

Determina se os dados na área de transferência mudaram desde que [setClipboard](#setclipboard) foi chamado pela última vez e, se for o caso, identifica o proprietário atual.

```
static COleDataSource* PASCAL GetClipboardOwner();
```

### <a name="return-value"></a>Valor retornado

A fonte de dados atualmente na Área de Transferência, ou NULL se não houver nada na Área de Transferência ou se a Área de Transferência não for de propriedade do aplicativo de chamada.

## <a name="coledatasourceonrenderdata"></a><a name="onrenderdata"></a>COleDataFonte::OnRenderData

Chamado pela estrutura para recuperar dados no formato especificado.

```
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*Lpstgmedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) na qual os dados devem ser devolvidos.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um `COleDataSource` anteriormente colocado no objeto usando a função de membro [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) para renderização atrasada. A implementação padrão desta função chamará [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata) se o meio de armazenamento fornecido for um arquivo ou memória, respectivamente. Se nenhum desses formatos for fornecido, a implementação padrão retornará 0 e não fará nada. Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Se o*tmed* `STGMEDIUM` *lpStgMedium*-> for TYMED_NULL, o deve ser alocado e preenchido conforme especificado pelo *lpFormatEtc->tymed*. Caso não seja TYMED_NULL, deve `STGMEDIUM` ser preenchido no local com os dados.

Este é um avançado super-rididável. Anular esta função para fornecer seus dados no formato e meio solicitados. Dependendo dos seus dados, você pode querer substituir uma das outras versões desta função. Se seus dados forem pequenos e `OnRenderGlobalData`fixos em tamanho, anular . Se seus dados estão em um arquivo, ou `OnRenderFileData`são de tamanho variável, sobreposição .

Para obter mais informações, consulte as estruturas [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) e [FORMATETC,](/windows/win32/api/objidl/ns-objidl-formatetc) o tipo de enumeração [TYMED](/windows/win32/api/objidl/ne-objidl-tymed) e [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.

## <a name="coledatasourceonrenderfiledata"></a><a name="onrenderfiledata"></a>COleDataFonte::OnRenderFileData

Chamado pela estrutura para recuperar dados no formato especificado quando o meio de armazenamento especificado é um arquivo.

```
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,
    CFile* pFile);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*Pfile*<br/>
Aponta para um objeto [CFile](../../mfc/reference/cfile-class.md) no qual os dados devem ser renderizados.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é aquele `COleDataSource` anteriormente colocado no objeto usando a função [membro DelayRenderData](#delayrenderdata) para renderização atrasada. A implementação padrão desta função simplesmente retorna FALSE.

Este é um avançado super-rididável. Anular esta função para fornecer seus dados no formato e meio solicitados. Dependendo dos seus dados, você pode querer substituir uma das outras versões desta função. Se você quiser lidar com várias mídias de armazenamento, anule [o OnRenderData](#onrenderdata). Se seus dados estão em um arquivo, ou `OnRenderFileData`são de tamanho variável, sobreposição . Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.

## <a name="coledatasourceonrenderglobaldata"></a><a name="onrenderglobaldata"></a>COleDataFonte::OnRenderGlobalData

Chamado pela estrutura para recuperar dados no formato especificado quando o meio de armazenamento especificado é memória global.

```
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,
    HGLOBAL* phGlobal);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*Phglobal*<br/>
Aponta para uma alça para a memória global na qual os dados devem ser devolvidos. Se um ainda não foi alocado, este parâmetro pode ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é aquele `COleDataSource` anteriormente colocado no objeto usando a função [membro DelayRenderData](#delayrenderdata) para renderização atrasada. A implementação padrão desta função simplesmente retorna FALSE.

Se *phGlobal* for NULL, então um novo HGLOBAL deve ser alocado e devolvido em *phGlobal*. Caso contrário, o HGLOBAL especificado pela *phGlobal* deve ser preenchido com os dados. A quantidade de dados colocados no HGLOBAL não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.

Este é um avançado super-rididável. Anular esta função para fornecer seus dados no formato e meio solicitados. Dependendo dos seus dados, você pode querer substituir uma das outras versões desta função. Se você quiser lidar com várias mídias de armazenamento, anule [o OnRenderData](#onrenderdata). Se seus dados estão em um arquivo ou são de tamanho variável, anular [OnRenderFileData](#onrenderfiledata). Para obter mais informações sobre a renderização atrasada como tratada pelo MFC, consulte o artigo [Data Objects and Data Sources: Manipulation](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.

## <a name="coledatasourceonsetdata"></a><a name="onsetdata"></a>COleDataFonte::OnSetData

Chamado pela estrutura para definir ou `COleDataSource` substituir os dados no objeto no formato especificado.

```
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium,
    BOOL bRelease);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato em que os dados estão sendo substituídos.

*Lpstgmedium*<br/>
Aponta para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) contendo os dados que `COleDataSource` substituirão o conteúdo atual do objeto.

*Brelease*<br/>
Indica quem possui a propriedade do meio de armazenamento após concluir a chamada de função. O chamador decide quem é responsável pela liberação dos recursos alocados em nome do meio de armazenamento. O chamador faz isso definindo *bRelease*. Se *bRelease* não for zero, a fonte de dados assumirá a propriedade, liberando o meio quando ele tiver terminado de usá-lo. Quando *bRelease* é 0, o chamador mantém a propriedade e a fonte de dados pode usar o meio de armazenamento apenas durante a duração da chamada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A fonte de dados não se apropria dos dados até que ele os tenha obtido com sucesso. Ou seja, ele não `OnSetData` toma posse se retorna 0. Se a fonte de dados tomar posse, ela libera o meio de armazenamento chamando a função [ReleaseStgMedium.](/windows/win32/api/ole2/nf-ole2-releasestgmedium)

A implementação padrão não faz nada. Substitua esta função para substituir os dados no formato especificado. Este é um avançado super-rididável.

Para obter mais informações, consulte as estruturas [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e as funções [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) e [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.

## <a name="coledatasourcesetclipboard"></a><a name="setclipboard"></a>COleDataFonte::SetClipboard

Coloca os dados `COleDataSource` contidos no objeto na Área de Transferência após a chamada de uma das seguintes funções: [CacheData,](#cachedata) [CacheGlobalData,](#cacheglobaldata) [DelayRenderData](#delayrenderdata)ou [DelayRenderFileData](#delayrenderfiledata).

```
void SetClipboard();
```

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDataObject](../../mfc/reference/coledataobject-class.md)
