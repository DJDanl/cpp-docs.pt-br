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
ms.openlocfilehash: 5cd573590bc1adb303e0b4c5cd600b9fa6c685b2
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127849"
---
# <a name="coledatasource-class"></a>Classe COleDataSource

Atua como um cache no qual um aplicativo coloca os dados que ele oferecerá durante as operações de transferência de dados, como operações de área de transferência ou arrastar e soltar.

## <a name="syntax"></a>Sintaxe

```
class COleDataSource : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[COleDataSource:: COleDataSource](#coledatasource)|Constrói um objeto `COleDataSource`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[COleDataSource:: CacheData](#cachedata)|Oferece dados em um formato especificado usando uma estrutura de `STGMEDIUM`.|
|[COleDataSource:: CacheGlobalData](#cacheglobaldata)|Oferece dados em um formato especificado usando um HGLOBAL.|
|[COleDataSource::D elayRenderData](#delayrenderdata)|Oferece dados em um formato especificado usando a renderização atrasada.|
|[COleDataSource::D elayRenderFileData](#delayrenderfiledata)|Oferece dados em um formato especificado em um ponteiro `CFile`.|
|[COleDataSource::D elaySetData](#delaysetdata)|Chamado para cada formato com suporte no `OnSetData`.|
|[COleDataSource::D oDragDrop](#dodragdrop)|Executa operações de arrastar e soltar com uma fonte de dados.|
|[COleDataSource:: Empty](#empty)|Esvazia o `COleDataSource` objeto de dados.|
|[COleDataSource:: FlushClipboard](#flushclipboard)|Renderiza todos os dados para a área de transferência.|
|[COleDataSource:: GetClipboardOwner](#getclipboardowner)|Verifica se os dados colocados na área de transferência ainda estão lá.|
|[COleDataSource:: OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|
|[COleDataSource:: OnRenderFileData](#onrenderfiledata)|Recupera dados em um `CFile` como parte da renderização atrasada.|
|[COleDataSource:: OnRenderGlobalData](#onrenderglobaldata)|Recupera dados em um HGLOBAL como parte da renderização atrasada.|
|[COleDataSource:: OnSetData](#onsetdata)|Chamado para substituir os dados no objeto `COleDataSource`.|
|[COleDataSource:: SetClipboard](#setclipboard)|Coloca um objeto `COleDataSource` na área de transferência.|

## <a name="remarks"></a>Comentários

Você pode criar fontes de dados OLE diretamente. Como alternativa, as classes [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [COleServerItem](../../mfc/reference/coleserveritem-class.md) criam fontes de dados OLE em resposta às suas `CopyToClipboard` e `DoDragDrop` funções de membro. Consulte [COleServerItem:: CopyToClipboard](../../mfc/reference/coleserveritem-class.md#copytoclipboard) para obter uma breve descrição. Substitua a função membro `OnGetClipboardData` do item de cliente ou da classe de item de servidor para adicionar mais formatos de área de transferência aos dados na fonte de dados OLE criada para a função de membro `CopyToClipboard` ou `DoDragDrop`.

Sempre que desejar preparar dados para uma transferência, você deve criar um objeto dessa classe e preenchê-lo com seus dados usando o método mais apropriado para seus dados. A maneira como ele é inserido em uma fonte de dados é diretamente afetada pelo fato de os dados serem fornecidos imediatamente (renderização imediata) ou sob demanda (renderização atrasada). Para cada formato de área de transferência no qual você está fornecendo dados, passando o formato de área de transferência a ser usado (e uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) opcional), chame [DelayRenderData](#delayrenderdata).

Para obter mais informações sobre fontes de dados e transferência de dados, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md). Além disso, os [Tópicos da área de transferência](../../mfc/clipboard.md) do artigo descrevem o mecanismo da área de transferência OLE.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleDataSource`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxole. h

##  <a name="cachedata"></a>COleDataSource:: CacheData

Chame essa função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void CacheData(
    CLIPFORMAT cfFormat,
    LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato da área de transferência no qual os dados serão oferecidos. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpStgMedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que contém os dados no formato especificado.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão oferecidos. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na estrutura de `FORMATETC`.

### <a name="remarks"></a>Comentários

Você deve fornecer os dados, pois essa função o fornece usando a renderização imediata. Os dados são armazenados em cache até que sejam necessários.

Forneça os dados usando uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) . Você também pode usar a função de membro `CacheGlobalData` se a quantidade de dados que você está fornecendo for pequena o suficiente para ser transferida com eficiência usando um HGLOBAL.

Após a chamada para `CacheData` o membro `ptd` de `lpFormatEtc` e o conteúdo de *lpStgMedium* pertencem ao objeto de dados, não pelo chamador.

Para usar a renderização atrasada, chame a função de membro [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) . Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte as estruturas [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

##  <a name="cacheglobaldata"></a>COleDataSource:: CacheGlobalData

Chame essa função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void CacheGlobalData(
    CLIPFORMAT cfFormat,
    HGLOBAL hGlobal,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato da área de transferência no qual os dados serão oferecidos. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*hGlobal*<br/>
Identificador para o bloco de memória global que contém os dados no formato especificado.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão oferecidos. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na estrutura de `FORMATETC`.

### <a name="remarks"></a>Comentários

Essa função fornece os dados usando a renderização imediata, portanto, você deve fornecer os dados ao chamar a função; os dados são armazenados em cache até que sejam necessários. Use a função de membro `CacheData` se você estiver fornecendo uma grande quantidade de dados ou se precisar de um meio de armazenamento estruturado.

Para usar a renderização atrasada, chame a função de membro [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) . Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

##  <a name="coledatasource"></a>COleDataSource:: COleDataSource

Constrói um objeto `COleDataSource`.

```
COleDataSource();
```

##  <a name="delayrenderdata"></a>COleDataSource::D elayRenderData

Chame essa função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void DelayRenderData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato da área de transferência no qual os dados serão oferecidos. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão oferecidos. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na estrutura de `FORMATETC`.

### <a name="remarks"></a>Comentários

Essa função fornece os dados usando a renderização atrasada, portanto, os dados não são fornecidos imediatamente. A função de membro [OnRenderData](#onrenderdata) ou [OnRenderGlobalData](#onrenderglobaldata) é chamada para solicitar os dados.

Use essa função se não for fornecer seus dados por meio de um objeto `CFile`. Se você for fornecer os dados por meio de um objeto `CFile`, chame a função membro [DelayRenderFileData](#delayrenderfiledata) . Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para usar a renderização imediata, chame a função de membro [CacheData](#cachedata) ou [CacheGlobalData](#cacheglobaldata) .

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

##  <a name="delayrenderfiledata"></a>COleDataSource::D elayRenderFileData

Chame essa função para especificar um formato no qual os dados são oferecidos durante as operações de transferência de dados.

```
void DelayRenderFileData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato da área de transferência no qual os dados serão oferecidos. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão oferecidos. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na estrutura de `FORMATETC`.

### <a name="remarks"></a>Comentários

Essa função fornece os dados usando a renderização atrasada, portanto, os dados não são fornecidos imediatamente. A função de membro [OnRenderFileData](#onrenderfiledata) é chamada para solicitar os dados.

Use essa função se você pretende usar um objeto `CFile` para fornecer os dados. Se você não for usar um objeto `CFile`, chame a função membro [DelayRenderData](#delayrenderdata) . Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para usar a renderização imediata, chame a função de membro [CacheData](#cachedata) ou [CacheGlobalData](#cacheglobaldata) .

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

##  <a name="delaysetdata"></a>COleDataSource::D elaySetData

Chame essa função para dar suporte à alteração do conteúdo da fonte de dados.

```
void DelaySetData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato da área de transferência no qual os dados serão colocados. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão substituídos. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na estrutura de `FORMATETC`.

### <a name="remarks"></a>Comentários

[OnSetData](#onsetdata) será chamado pela estrutura quando isso acontecer. Isso só é usado quando a estrutura retorna a fonte de dados de [COleServerItem:: Getdataname](../../mfc/reference/coleserveritem-class.md#getdatasource). Se `DelaySetData` não for chamado, sua função `OnSetData` nunca será chamada. `DelaySetData` deve ser chamado para cada área de transferência ou formato de `FORMATETC` ao qual você dá suporte.

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

##  <a name="dodragdrop"></a>COleDataSource::D oDragDrop

Chame a função de membro `DoDragDrop` para executar uma operação de arrastar e soltar para essa fonte de dados, normalmente em um manipulador [CWnd:: OnLButtonDown](../../mfc/reference/cwnd-class.md#onlbuttondown) .

```
DROPEFFECT DoDragDrop(
    DWORD dwEffects = DROPEFFECT_COPY|DROPEFFECT_MOVE|DROPEFFECT_LINK,
    LPCRECT lpRectStartDrag = NULL,
    COleDropSource* pDropSource = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwEffects*<br/>
Operações de arrastar e soltar que são permitidas nesta fonte de dados. Pode ser um ou mais dos seguintes:

- DROPEFFECT_COPY uma operação de cópia pode ser executada.

- DROPEFFECT_MOVE uma operação de movimentação pode ser executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais pode ser estabelecido.

- DROPEFFECT_SCROLL Indica que pode ocorrer uma operação de rolagem de arrastar.

*lpRectStartDrag*<br/>
Ponteiro para o retângulo que define onde o arrastar realmente começa. Para obter mais informações, consulte a seção Comentários a seguir.

*pDropSource*<br/>
Aponta para uma fonte de soltar. Se for NULL, uma implementação padrão de [COleDropSource](../../mfc/reference/coledropsource-class.md) será usada.

### <a name="return-value"></a>Valor retornado

Ignorar efeito gerado pela operação de arrastar e soltar; caso contrário DROPEFFECT_NONE se a operação nunca for iniciada porque o usuário liberou o botão do mouse antes de sair do retângulo fornecido.

### <a name="remarks"></a>Comentários

A operação de arrastar e soltar não é iniciada imediatamente. Ele aguarda até que o cursor do mouse saia do retângulo especificado por *lpRectStartDrag* ou até que um número especificado de milissegundos tenha passado. Se *lpRectStartDrag* for NULL, o tamanho do retângulo será um pixel.

O tempo de atraso é especificado por uma configuração de chave do registro. Você pode alterar o tempo de atraso chamando [CWinApp:: WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp:: WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, será usado um valor padrão de 200 milissegundos. O tempo de atraso de arrastar é armazenado da seguinte maneira:

- O tempo de atraso de arrastar do Windows NT é armazenado em HKEY_LOCAL_MACHINE \SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.

- O tempo de espera de arrastar do Windows 3. x é armazenado no WIN. INI, na seção [Windows}.

- O tempo de atraso de arrasto do Windows 95/98 é armazenado em uma versão armazenada em cache do WIN. Personalizado.

Para obter mais informações sobre como as informações de atraso de arrastar são armazenadas no registro ou no. Arquivo INI, consulte [WriteProfileString](/windows/win32/api/winbase/nf-winbase-writeprofilestringw) no SDK do Windows.

Para obter mais informações, consulte o artigo [arrastar e soltar de OLE](../../mfc/drag-and-drop-ole.md).

##  <a name="empty"></a>COleDataSource:: Empty

Chame essa função para esvaziar o `COleDataSource` objeto de dados.

```
void Empty();
```

### <a name="remarks"></a>Comentários

Os formatos de renderização em cache e de atraso são esvaziados para que possam ser reutilizados.

Para obter mais informações, consulte [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) no SDK do Windows.

##  <a name="flushclipboard"></a>COleDataSource:: FlushClipboard

Renderiza dados que estão na área de transferência e, em seguida, permite colar dados da área de transferência depois que o aplicativo é desligado.

```
static void PASCAL FlushClipboard();
```

### <a name="remarks"></a>Comentários

Use [SetClipboard](#setclipboard) para colocar dados na área de transferência.

##  <a name="getclipboardowner"></a>COleDataSource:: GetClipboardOwner

Determina se os dados na área de transferência foram alterados desde que a [SetClipboard](#setclipboard) foi chamada pela última vez e, em caso afirmativo, identifica o proprietário atual.

```
static COleDataSource* PASCAL GetClipboardOwner();
```

### <a name="return-value"></a>Valor retornado

A fonte de dados atualmente na área de transferência ou NULL se não houver nada na área de transferência ou se a área de transferência não pertencer ao aplicativo de chamada.

##  <a name="onrenderdata"></a>COleDataSource:: OnRenderData

Chamado pelo Framework para recuperar dados no formato especificado.

```
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>Parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*lpStgMedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) na qual os dados serão retornados.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um colocado anteriormente no objeto `COleDataSource` usando a função de membro [DelayRenderData](#delayrenderdata) ou [DelayRenderFileData](#delayrenderfiledata) para a renderização atrasada. A implementação padrão dessa função chamará [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata) se o meio de armazenamento fornecido for um arquivo ou uma memória, respectivamente. Se nenhum desses formatos for fornecido, a implementação padrão retornará 0 e não fará nada. Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Se *lpStgMedium*-> *TYMED* for TYMED_NULL, a `STGMEDIUM` deverá ser alocada e preenchida conforme especificado por *lpFormatEtc-> tymed*. Se não for TYMED_NULL, a `STGMEDIUM` deverá ser preenchida no local com os dados.

Esse é um substituível avançado. Substitua essa função para fornecer seus dados no formato solicitado e médio. Dependendo de seus dados, talvez você queira substituir uma das outras versões dessa função. Se os dados forem pequenos e forem corrigidos, substitua `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou forem de tamanho variável, substitua `OnRenderFileData`.

Para obter mais informações, consulte as estruturas [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) , o tipo de enumeração [TYMED](/windows/win32/api/objidl/ne-objidl-tymed) e [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) na SDK do Windows.

##  <a name="onrenderfiledata"></a>COleDataSource:: OnRenderFileData

Chamado pelo Framework para recuperar dados no formato especificado quando o meio de armazenamento especificado é um arquivo.

```
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,
    CFile* pFile);
```

### <a name="parameters"></a>Parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*pFile*<br/>
Aponta [para um objeto de](../../mfc/reference/cfile-class.md) retratação no qual os dados serão renderizados.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um colocado anteriormente no objeto `COleDataSource` usando a função membro [DelayRenderData](#delayrenderdata) para a renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.

Esse é um substituível avançado. Substitua essa função para fornecer seus dados no formato solicitado e médio. Dependendo de seus dados, talvez você queira substituir uma das outras versões dessa função. Se você quiser manipular várias mídias de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou forem de tamanho variável, substitua `OnRenderFileData`. Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) na SDK do Windows.

##  <a name="onrenderglobaldata"></a>COleDataSource:: OnRenderGlobalData

Chamado pelo Framework para recuperar dados no formato especificado quando a mídia de armazenamento especificada é a memória global.

```
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,
    HGLOBAL* phGlobal);
```

### <a name="parameters"></a>Parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*phGlobal*<br/>
Aponta para um identificador para a memória global na qual os dados serão retornados. Se um ainda não tiver sido alocado, esse parâmetro poderá ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um colocado anteriormente no objeto `COleDataSource` usando a função membro [DelayRenderData](#delayrenderdata) para a renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.

Se *phGlobal* for NULL, um novo HGLOBAL deverá ser alocado e retornado em *phGlobal*. Caso contrário, o HGLOBAL especificado por *phGlobal* deve ser preenchido com os dados. A quantidade de dados colocados em HGLOBAL não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.

Esse é um substituível avançado. Substitua essa função para fornecer seus dados no formato solicitado e médio. Dependendo de seus dados, talvez você queira substituir uma das outras versões dessa função. Se você quiser manipular várias mídias de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou forem de tamanho variável, substitua [OnRenderFileData](#onrenderfiledata). Para obter mais informações sobre o processamento atrasado conforme manipulado pelo MFC, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).

Para obter mais informações, consulte a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) na SDK do Windows.

##  <a name="onsetdata"></a>COleDataSource:: OnSetData

Chamado pelo Framework para definir ou substituir os dados no objeto `COleDataSource` no formato especificado.

```
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium,
    BOOL bRelease);
```

### <a name="parameters"></a>Parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual os dados estão sendo substituídos.

*lpStgMedium*<br/>
Aponta para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que contém os dados que substituirão o conteúdo atual do objeto `COleDataSource`.

*bRelease*<br/>
Indica quem tem a propriedade do meio de armazenamento depois de concluir a chamada de função. O chamador decide quem é responsável por liberar os recursos alocados em nome do meio de armazenamento. O chamador faz isso definindo *bRelease*. Se *bRelease* for diferente de zero, a fonte de dados assumirá a propriedade, liberando a mídia quando terminar de usá-la. Quando *bRelease* é 0, o chamador retém a propriedade e a fonte de dados pode usar a mídia de armazenamento somente pela duração da chamada.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A fonte de dados não assume a propriedade dos dados até que ele seja obtido com êxito. Ou seja, ela não assumirá a propriedade se `OnSetData` retornar 0. Se a fonte de dados assumir a propriedade, ela liberará o meio de armazenamento chamando a função [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) .

A implementação padrão não faz nada. Substitua essa função para substituir os dados no formato especificado. Esse é um substituível avançado.

Para obter mais informações, consulte as estruturas [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e as funções [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) e [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) no SDK do Windows.

##  <a name="setclipboard"></a>COleDataSource:: SetClipboard

Coloca os dados contidos no objeto `COleDataSource` na área de transferência depois de chamar uma das seguintes funções: [CacheData](#cachedata), [CacheGlobalData](#cacheglobaldata), [DelayRenderData](#delayrenderdata)ou [DelayRenderFileData](#delayrenderfiledata).

```
void SetClipboard();
```

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDataObject](../../mfc/reference/coledataobject-class.md)
