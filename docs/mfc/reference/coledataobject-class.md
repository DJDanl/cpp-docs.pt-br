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
ms.openlocfilehash: 24d79c684226d57839161946255781c3bdd5a043
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64341700"
---
# <a name="coledataobject-class"></a>Classe COleDataObject

Usado nas transferências de dados para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar, ou de um item OLE inserido.

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
|[COleDataObject::Attach](#attach)|Anexa o objeto de dados OLE especificado para o `COleDataObject`.|
|[COleDataObject::AttachClipboard](#attachclipboard)|Anexa o objeto de dados na área de transferência.|
|[COleDataObject::BeginEnumFormats](#beginenumformats)|Prepara para uma ou mais subsequentes `GetNextFormat` chamadas.|
|[COleDataObject::Detach](#detach)|Desanexa associado `IDataObject` objeto.|
|[COleDataObject::GetData](#getdata)|Copia os dados do objeto de dados OLE anexado em um formato especificado.|
|[COleDataObject::GetFileData](#getfiledata)|Copia os dados do objeto de dados OLE anexado em um `CFile` ponteiro no formato especificado.|
|[COleDataObject::GetGlobalData](#getglobaldata)|Copia os dados do objeto de dados OLE anexado em um `HGLOBAL` no formato especificado.|
|[COleDataObject::GetNextFormat](#getnextformat)|Retorna o próximo formato de dados disponível.|
|[COleDataObject::IsDataAvailable](#isdataavailable)|Verifica se os dados estão disponíveis em um formato especificado.|
|[COleDataObject::Release](#release)|Desanexa e libera associado `IDataObject` objeto.|

## <a name="remarks"></a>Comentários

`COleDataObject` não tem uma classe base.

Esses tipos de transferências de dados incluem uma origem e um destino. A fonte de dados é implementada como um objeto de [COleDataSource](../../mfc/reference/coledatasource-class.md) classe. Sempre que um aplicativo de destino tem dados que foram soltos nele ou será solicitado a executar uma operação de colagem da área de transferência, um objeto do `COleDataObject` classe deve ser criada.

Essa classe permite que você determine se os dados existem em um formato especificado. Você pode também enumere os formatos de dados disponíveis ou verificar se um determinado formato está disponível e, em seguida, recuperar os dados no formato preferencial. Recuperação de objetos pode ser feita de várias maneiras diferentes, incluindo o uso de um [CFile](../../mfc/reference/cfile-class.md), um HGLOBAL ou um `STGMEDIUM` estrutura.

Para obter mais informações, consulte o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura no SDK do Windows.

Para obter mais informações sobre como usar objetos de dados em seu aplicativo, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleDataObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="attach"></a>  COleDataObject::Attach

Chame essa função para associar o `COleDataObject` objeto com um objeto de dados OLE.

```
void Attach(
    LPDATAOBJECT lpDataObject,
    BOOL bAutoRelease = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpDataObject*<br/>
Aponta para um objeto de dados OLE.

*bAutoRelease*<br/>
TRUE se o objeto de dados OLE deve ser liberados quando a `COleDataObject` objeto for destruído; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDataObject](/windows/desktop/api/objidl/nn-objidl-idataobject) no SDK do Windows.

##  <a name="attachclipboard"></a>  COleDataObject::AttachClipboard

Chame essa função para anexar o objeto de dados que está atualmente na área de transferência para o `COleDataObject` objeto.

```
BOOL AttachClipboard();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Chamar essa função bloqueia a área de transferência até que esse objeto de dados seja liberado. O objeto de dados é liberado no destruidor para a `COleDataObject`. Para obter mais informações, consulte [OpenClipboard](/windows/desktop/api/winuser/nf-winuser-openclipboard) e [CloseClipboard](/windows/desktop/api/winuser/nf-winuser-closeclipboard) na documentação do Win32.

##  <a name="beginenumformats"></a>  COleDataObject::BeginEnumFormats

Chame essa função para se preparar para as chamadas subsequentes para `GetNextFormat` para recuperar uma lista de formatos de dados do item.

```
void BeginEnumFormats();
```

### <a name="remarks"></a>Comentários

Após uma chamada para `BeginEnumFormats`, a posição do primeiro formato com suporte neste objeto de dados é armazenada. Chamadas sucessivas para `GetNextFormat` enumerará a lista de formatos disponíveis no objeto de dados.

Para verificar a disponibilidade dos dados em um determinado formato, use [COleDataObject::IsDataAvailable](#isdataavailable).

Para obter mais informações, consulte [IDataObject::EnumFormatEtc](/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc) no SDK do Windows.

##  <a name="coledataobject"></a>  COleDataObject::COleDataObject

Constrói um objeto `COleDataObject`.

```
COleDataObject();
```

### <a name="remarks"></a>Comentários

Uma chamada para [COleDataObject::Attach](#attach) ou [COleDataObject::AttachClipboard](#attachclipboard) devem ser feitas antes de chamar outro `COleDataObject` funções.

> [!NOTE]
>  Uma vez que um dos parâmetros para os manipuladores de arrastar e soltar é um ponteiro para um `COleDataObject`, não é necessário para chamar esse construtor para dar suporte a arrastar e soltar.

##  <a name="detach"></a>  COleDataObject::Detach

Chame essa função para desanexar o `COleDataObject` objeto a partir de seu objeto de dados OLE associado sem liberar o objeto de dados.

```
LPDATAOBJECT Detach();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto de dados OLE que foi desanexado.

### <a name="remarks"></a>Comentários

##  <a name="getdata"></a>  COleDataObject::GetData

Chame essa função para recuperar dados do item de formato especificado.

```
BOOL GetData(
    CLIPFORMAT cfFormat,
    LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato no qual os dados estão a ser retornado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.

*lpStgMedium*<br/>
Aponta para um [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura que receberá os dados.

*lpFormatEtc*<br/>
Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados estão a ser retornado. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata), [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.

##  <a name="getfiledata"></a>  COleDataObject::GetFileData

Chame essa função para criar uma `CFile` ou `CFile`-objeto derivado e para recuperar dados no formato especificado em um `CFile` ponteiro.

```
CFile* GetFileData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato no qual os dados estão a ser retornado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.

*lpFormatEtc*<br/>
Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados estão a ser retornado. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.

### <a name="return-value"></a>Valor de retorno

Ponteiro para o novo `CFile` ou `CFile`-objeto que contém os dados se for bem-sucedido; caso contrário, NULL derivado.

### <a name="remarks"></a>Comentários

Dependendo da mídia dos dados são armazenados no tipo apontado pelo valor de retorno real pode ser `CFile`, `CSharedFile`, ou `COleStreamFile`.

> [!NOTE]
>  O `CFile` objeto acessado pelo valor de retorno dessa função é pertence ao chamador. É responsabilidade do chamador **exclua** o `CFile` objeto, assim, fechando o arquivo.

Para obter mais informações, consulte [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.

##  <a name="getglobaldata"></a>  COleDataObject::GetGlobalData

Chame essa função para alocar um bloco de memória global e para recuperar dados no formato especificado em um HGLOBAL.

```
HGLOBAL GetGlobalData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato no qual os dados estão a ser retornado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.

*lpFormatEtc*<br/>
Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato no qual os dados estão a ser retornado. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.

### <a name="return-value"></a>Valor de retorno

O identificador do bloco de memória global que contém os dados se for bem-sucedido; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.

##  <a name="getnextformat"></a>  COleDataObject::GetNextFormat

Chame essa função repetidamente para obter todos os formatos disponíveis para recuperação de dados do item.

```
BOOL GetNextFormat(LPFORMATETC lpFormatEtc);
```

### <a name="parameters"></a>Parâmetros

*lpFormatEtc*<br/>
Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que recebe as informações de formato, quando a chamada de função retorna.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se outro formato está disponível. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Após uma chamada para [COleDataObject::BeginEnumFormats](#beginenumformats), a posição do primeiro formato com suporte neste objeto de dados é armazenada. Chamadas sucessivas para `GetNextFormat` enumerará a lista de formatos disponíveis no objeto de dados. Use essas funções para listar os formatos disponíveis.

Para verificar a disponibilidade de um determinado formato, chame [COleDataObject::IsDataAvailable](#isdataavailable).

Para obter mais informações, consulte [IEnumXXXX::Next](https://msdn.microsoft.com/library/ms695273.aspx) no SDK do Windows.

##  <a name="isdataavailable"></a>  COleDataObject::IsDataAvailable

Chame essa função para determinar se um determinado formato está disponível para recuperar dados do item OLE.

```
BOOL IsDataAvailable(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>Parâmetros

*cfFormat*<br/>
O formato de dados de área de transferência a ser usado na estrutura apontada por *lpFormatEtc*. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativos [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) função.

*lpFormatEtc*<br/>
Aponta para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura que descreve o formato desejado. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se for NULL, os valores padrão são usados para os outros campos no `FORMATETC` estrutura.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os dados estão disponíveis no formato especificado. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil antes de chamar `GetData`, `GetFileData`, ou `GetGlobalData`.

Para obter mais informações, consulte [IDataObject::QueryGetData](/windows/desktop/api/objidl/nf-objidl-idataobject-querygetdata) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::QueryAcceptData](../../mfc/reference/cricheditview-class.md#queryacceptdata).

##  <a name="release"></a>  COleDataObject::Release

Chame essa função para liberar a propriedade do [IDataObject](/windows/desktop/api/objidl/nn-objidl-idataobject) objeto que foi previamente associado a `COleDataObject` objeto.

```
void Release();
```

### <a name="remarks"></a>Comentários

O `IDataObject` foi associado a `COleDataObject` chamando `Attach` ou `AttachClipboard` explicitamente ou pela estrutura. Se o *bAutoRelease* parâmetro do `Attach` for FALSE, o `IDataObject` objeto não seja liberado. Nesse caso, o chamador é responsável por liberar a `IDataObject` chamando [IUnknown:: Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## <a name="see-also"></a>Consulte também

[Exemplo MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDataSource](../../mfc/reference/coledatasource-class.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
