---
title: Classe COleDataObject
ms.date: 11/04/2016
f1_keywords:
- COleDataObject
- AFXOLE/COleDataObject
- AFXOLE/COleDataObject::COleDataObject
- AFXOLE/COleDataObject::Attach
- AFXOLE/COleDataObject::AttachClipboard
- AFXOLE/COleDataObject::BeginEnumFormats
- AFXOLE/COleDataObject::Detach
- AFXOLE/COleDataObject::GetData
- AFXOLE/COleDataObject::GetFileData
- AFXOLE/COleDataObject::GetGlobalData
- AFXOLE/COleDataObject::GetNextFormat
- AFXOLE/COleDataObject::IsDataAvailable
- AFXOLE/COleDataObject::Release
helpviewer_keywords:
- COleDataObject [MFC], COleDataObject
- COleDataObject [MFC], Attach
- COleDataObject [MFC], AttachClipboard
- COleDataObject [MFC], BeginEnumFormats
- COleDataObject [MFC], Detach
- COleDataObject [MFC], GetData
- COleDataObject [MFC], GetFileData
- COleDataObject [MFC], GetGlobalData
- COleDataObject [MFC], GetNextFormat
- COleDataObject [MFC], IsDataAvailable
- COleDataObject [MFC], Release
ms.assetid: d1cc84be-2e1c-4bb3-a8a0-565eb08aaa34
ms.openlocfilehash: 5e1545a033ab482e838fbc944b0ca9b3e543d651
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366126"
---
# <a name="coledataobject-class"></a>Classe COleDataObject

Usado em transferências de dados para recuperar dados em vários formatos da Área de Transferência, através de arrastar e soltar, ou de um item OLE incorporado.

## <a name="syntax"></a>Sintaxe

```
class COleDataObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDataObject::COleDataObject](#coledataobject)|Constrói um objeto `COleDataObject`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDataObject::Anexar](#attach)|Anexa o objeto de dados OLE especificado ao `COleDataObject`.|
|[COleDataObject::AttachClipboard](#attachclipboard)|Anexa o objeto de dados que está na área de transferência.|
|[COleDataObject::BeginEnumFormats](#beginenumformats)|Prepara-se para `GetNextFormat` uma ou mais chamadas subseqüentes.|
|[COleDataObject::Detach](#detach)|Destaca o objeto `IDataObject` associado.|
|[COleDataObject::GetData](#getdata)|Copia dados do objeto de dados OLE anexado em um formato especificado.|
|[COleDataObject::GetFileData](#getfiledata)|Copia dados do objeto de dados `CFile` OLE anexado em um ponteiro no formato especificado.|
|[COleDataObject::GetGlobalData](#getglobaldata)|Copia dados do objeto de dados `HGLOBAL` OLE anexado em um no formato especificado.|
|[COleDataObject::GetNextFormat](#getnextformat)|Retorna o próximo formato de dados disponível.|
|[COleDataObject::IsDataAvailable](#isdataavailable)|Verifica se os dados estão disponíveis em um formato especificado.|
|[COleDataObject::Liberação](#release)|Destaca-se e libera `IDataObject` o objeto associado.|

## <a name="remarks"></a>Comentários

`COleDataObject`não tem uma classe base.

Esses tipos de transferências de dados incluem uma fonte e um destino. A fonte de dados é implementada como um objeto da classe [COleDataSource.](../../mfc/reference/coledatasource-class.md) Sempre que um aplicativo de destino tiver dados descartados ou for solicitado a realizar `COleDataObject` uma operação de colar da Área de Transferência, um objeto da classe deve ser criado.

Essa classe permite determinar se os dados existem em um formato especificado. Você também pode enumerar os formatos de dados disponíveis ou verificar se um determinado formato está disponível e, em seguida, recuperar os dados no formato preferido. A recuperação de objetos pode ser realizada de várias maneiras diferentes, incluindo o uso de um [CFile,](../../mfc/reference/cfile-class.md)um HGLOBAL ou uma `STGMEDIUM` estrutura.

Para obter mais informações, consulte a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no SDK do Windows.

Para obter mais informações sobre o uso de objetos de dados em seu aplicativo, consulte o artigo [Data Objects and Data Sources (OLE)](../../mfc/data-objects-and-data-sources-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleDataObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coledataobjectattach"></a><a name="attach"></a>COleDataObject::Anexar

Chame esta função `COleDataObject` para associar o objeto a um objeto de dados OLE.

```
void Attach(
    LPDATAOBJECT lpDataObject,
    BOOL bAutoRelease = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpDataObject*<br/>
Aponta para um objeto de dados OLE.

*bVersão automática*<br/>
VERDADE se o objeto de dados `COleDataObject` OLE deve ser liberado quando o objeto é destruído; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) no Windows SDK.

## <a name="coledataobjectattachclipboard"></a><a name="attachclipboard"></a>COleDataObject::AttachClipboard

Chame esta função para anexar o objeto de dados `COleDataObject` que está atualmente na Área de Transferência ao objeto.

```
BOOL AttachClipboard();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Chamar essa função bloqueia a Área de Transferência até que este objeto de dados seja liberado. O objeto de dados é liberado no `COleDataObject`destruidor para o . Para obter mais informações, consulte [OpenClipboard](/windows/win32/api/winuser/nf-winuser-openclipboard) e [CloseClipboard](/windows/win32/api/winuser/nf-winuser-closeclipboard) no documento Win32.

## <a name="coledataobjectbeginenumformats"></a><a name="beginenumformats"></a>COleDataObject::BeginEnumFormats

Chame esta função para preparar `GetNextFormat` para chamadas subseqüentes para recuperar uma lista de formatos de dados do item.

```
void BeginEnumFormats();
```

### <a name="remarks"></a>Comentários

Após uma `BeginEnumFormats`chamada para , a posição do primeiro formato suportado por este objeto de dados é armazenada. As chamadas `GetNextFormat` sucessivas para enumerar a lista de formatos disponíveis no objeto de dados.

Para verificar a disponibilidade de dados em um determinado formato, use [COleDataObject::IsDataAvailable](#isdataavailable).

Para obter mais informações, consulte [IDataObject::EnumFormatEtc](/windows/win32/api/objidl/nf-objidl-idataobject-enumformatetc) no Windows SDK.

## <a name="coledataobjectcoledataobject"></a><a name="coledataobject"></a>COleDataObject::COleDataObject

Constrói um objeto `COleDataObject`.

```
COleDataObject();
```

### <a name="remarks"></a>Comentários

Uma chamada para [COleDataObject::Attach](#attach) ou [COleDataObject::AttachClipboard](#attachclipboard) `COleDataObject` deve ser feita antes de chamar outras funções.

> [!NOTE]
> Uma vez que um dos parâmetros para os manipuladores `COleDataObject`de arrastar e soltar é um ponteiro para um , não há necessidade de chamar este construtor para suportar arrastar e soltar.

## <a name="coledataobjectdetach"></a><a name="detach"></a>COleDataObject::Detach

Chame esta função para `COleDataObject` separar o objeto do objeto de dados OLE associado sem liberar o objeto de dados.

```
LPDATAOBJECT Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de dados OLE que foi destacado.

### <a name="remarks"></a>Comentários

## <a name="coledataobjectgetdata"></a><a name="getdata"></a>COleDataObject::GetData

Chame esta função para recuperar dados do item no formato especificado.

```
BOOL GetData(
    CLIPFORMAT cfFormat,
    LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato em que os dados devem ser devolvidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpstgmedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá dados.

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser devolvidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDataObject::GetData,](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1)e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no Windows SDK.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledataobjectgetfiledata"></a><a name="getfiledata"></a>COleDataObject::GetFileData

Chame esta função `CFile` para `CFile`criar um objeto ou derivado e para `CFile` recuperar dados no formato especificado em um ponteiro.

```
CFile* GetFileData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato em que os dados devem ser devolvidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser devolvidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="return-value"></a>Valor retornado

Ponteiro para `CFile` o `CFile`objeto novo ou derivado que contém os dados se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Dependendo do meio em que os dados são armazenados, o `CFile` `CSharedFile`tipo `COleStreamFile`real apontado pelo valor de retorno pode ser, ou .

> [!NOTE]
> O `CFile` objeto acessado pelo valor de devolução desta função é de propriedade do chamador. É responsabilidade do chamador **delete** excluir `CFile` o objeto, fechando assim o arquivo.

Para obter mais informações, consulte [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no Windows SDK.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledataobjectgetglobaldata"></a><a name="getglobaldata"></a>COleDataObject::GetGlobalData

Chame essa função para alocar um bloco de memória global e para recuperar dados no formato especificado em um HGLOBAL.

```
HGLOBAL GetGlobalData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato em que os dados devem ser devolvidos. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato em que os dados devem ser devolvidos. Forneça um valor para este parâmetro se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="return-value"></a>Valor retornado

A alça do bloco de memória global que contém os dados se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no Windows SDK.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

## <a name="coledataobjectgetnextformat"></a><a name="getnextformat"></a>COleDataObject::GetNextFormat

Ligue para esta função repetidamente para obter todos os formatos disponíveis para recuperar dados do item.

```
BOOL GetNextFormat(LPFORMATETC lpFormatEtc);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que recebe as informações de formato quando a chamada de função retorna.

### <a name="return-value"></a>Valor retornado

Não zero se outro formato estiver disponível; caso contrário, 0.

### <a name="remarks"></a>Comentários

Após uma chamada para [COleDataObject::BeginEnumFormats](#beginenumformats), a posição do primeiro formato suportado por este objeto de dados é armazenada. As chamadas `GetNextFormat` sucessivas para enumerar a lista de formatos disponíveis no objeto de dados. Use essas funções para listar os formatos disponíveis.

Para verificar a disponibilidade de um determinado formato, ligue para [COleDataObject::IsDataAvailable](#isdataavailable).

Para obter mais informações, consulte [IEnumXXXX::Próximo](/previous-versions//ms695273\(v=vs.85\)) no SDK do Windows.

## <a name="coledataobjectisdataavailable"></a><a name="isdataavailable"></a>COleDataObject::IsDataAvailable

Ligue para esta função para determinar se um determinado formato está disponível para recuperar dados do item OLE.

```
BOOL IsDataAvailable(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Cfformat*<br/>
O formato de dados da área de transferência a ser utilizado na estrutura apontada por *lpFormatEtc*. Este parâmetro pode ser um dos formatos de área de transferência predefinidos ou o valor retornado pela função nativa Windows [RegisterClipboardFormat.](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw)

*Lpformatetc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) descrevendo o formato desejado. Forneça um valor para este parâmetro somente se você quiser especificar informações adicionais de formato além do formato de área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são `FORMATETC` usados para os outros campos da estrutura.

### <a name="return-value"></a>Valor retornado

Não zero se os dados estão disponíveis no formato especificado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é `GetData`útil `GetFileData`antes `GetGlobalData`de chamar, ou .

Para obter mais informações, consulte [IDataObject::QueryGetData](/windows/win32/api/objidl/nf-objidl-idataobject-querygetdata) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no Windows SDK.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no Windows SDK.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::QueryAcceptData](../../mfc/reference/cricheditview-class.md#queryacceptdata).

## <a name="coledataobjectrelease"></a><a name="release"></a>COleDataObject::Liberação

Chame esta função para liberar a propriedade do objeto [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) que estava anteriormente associado ao `COleDataObject` objeto.

```
void Release();
```

### <a name="remarks"></a>Comentários

O `IDataObject` foi associado `COleDataObject` ao `Attach` `AttachClipboard` chamado ou explicitamente ou pelo quadro. Se o *parâmetro bAutoRelease* for `Attach` `IDataObject` FALSE, o objeto não será liberado. Neste caso, o chamador é `IDataObject` responsável por liberar o chamado [IUnknown::Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release).

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDataSource](../../mfc/reference/coledatasource-class.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
