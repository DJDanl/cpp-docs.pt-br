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
ms.openlocfilehash: e9cb8c452cc3eea32b6eed9bf23fb454344c105d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214081"
---
# <a name="coledataobject-class"></a>Classe COleDataObject

Usado em transferências de dados para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar ou de um item OLE incorporado.

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
|[COleDataObject:: Attach](#attach)|Anexa o objeto de dados OLE especificado ao `COleDataObject` .|
|[COleDataObject::AttachClipboard](#attachclipboard)|Anexa o objeto de dados que está na área de transferência.|
|[COleDataObject::BeginEnumFormats](#beginenumformats)|Prepara para uma ou mais chamadas subsequentes `GetNextFormat` .|
|[COleDataObject::D Etach](#detach)|Desanexa o objeto associado `IDataObject` .|
|[COleDataObject:: GetData](#getdata)|Copia dados do objeto OLE data anexado em um formato especificado.|
|[COleDataObject::GetFileData](#getfiledata)|Copia dados do objeto OLE data anexado em um `CFile` ponteiro no formato especificado.|
|[COleDataObject::GetGlobalData](#getglobaldata)|Copia dados do objeto OLE data anexado em um `HGLOBAL` no formato especificado.|
|[COleDataObject::GetNextFormat](#getnextformat)|Retorna o próximo formato de dados disponível.|
|[COleDataObject::IsDataAvailable](#isdataavailable)|Verifica se os dados estão disponíveis em um formato especificado.|
|[COleDataObject:: versão](#release)|Desanexa e libera o objeto associado `IDataObject` .|

## <a name="remarks"></a>Comentários

`COleDataObject`Não tem uma classe base.

Esses tipos de transferência de dados incluem uma origem e um destino. A fonte de dados é implementada como um objeto da classe [COleDataSource](../../mfc/reference/coledatasource-class.md) . Sempre que um aplicativo de destino tiver dados descartados ou for solicitado a executar uma operação de colagem na área de transferência, um objeto da `COleDataObject` classe deverá ser criado.

Essa classe permite que você determine se os dados existem em um formato especificado. Você também pode enumerar os formatos de dados disponíveis ou verificar se um determinado formato está disponível e, em seguida, recuperar os dados no formato preferencial. A recuperação de objeto pode ser realizada de várias maneiras diferentes, incluindo o uso de um [testcfile](../../mfc/reference/cfile-class.md), um HGLOBAL ou uma `STGMEDIUM` estrutura.

Para obter mais informações, consulte a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no SDK do Windows.

Para obter mais informações sobre como usar objetos de dados em seu aplicativo, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleDataObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

## <a name="coledataobjectattach"></a><a name="attach"></a>COleDataObject:: Attach

Chame essa função para associar o `COleDataObject` objeto a um objeto OLE data.

```cpp
void Attach(
    LPDATAOBJECT lpDataObject,
    BOOL bAutoRelease = TRUE);
```

### <a name="parameters"></a>parâmetros

*lpDataObject*<br/>
Aponta para um objeto de dados OLE.

*bAutoRelease*<br/>
TRUE se o objeto OLE data deve ser liberado quando o `COleDataObject` objeto for destruído; caso contrário, false.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) no SDK do Windows.

## <a name="coledataobjectattachclipboard"></a><a name="attachclipboard"></a>COleDataObject::AttachClipboard

Chame essa função para anexar o objeto de dados que está atualmente na área de transferência ao `COleDataObject` objeto.

```
BOOL AttachClipboard();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Chamar essa função bloqueia a área de transferência até que este objeto de dados seja liberado. O objeto de dados é liberado no destruidor para o `COleDataObject` . Para obter mais informações, consulte [OpenClipboard](/windows/win32/api/winuser/nf-winuser-openclipboard) e [CloseClipboard](/windows/win32/api/winuser/nf-winuser-closeclipboard) na documentação do Win32.

## <a name="coledataobjectbeginenumformats"></a><a name="beginenumformats"></a>COleDataObject::BeginEnumFormats

Chame essa função para se preparar para chamadas subsequentes para `GetNextFormat` para recuperar uma lista de formatos de dados do item.

```cpp
void BeginEnumFormats();
```

### <a name="remarks"></a>Comentários

Após uma chamada para `BeginEnumFormats` , a posição do primeiro formato com suporte por esse objeto de dados é armazenada. As chamadas sucessivas para `GetNextFormat` enumerarão a lista de formatos disponíveis no objeto de dados.

Para verificar a disponibilidade dos dados em um determinado formato, use [COleDataObject:: IsDataAvailable](#isdataavailable).

Para obter mais informações, consulte [IDataObject:: EnumFormatEtc](/windows/win32/api/objidl/nf-objidl-idataobject-enumformatetc) no SDK do Windows.

## <a name="coledataobjectcoledataobject"></a><a name="coledataobject"></a>COleDataObject::COleDataObject

Constrói um objeto `COleDataObject`.

```
COleDataObject();
```

### <a name="remarks"></a>Comentários

Uma chamada para [COleDataObject:: Attach](#attach) ou [COleDataObject:: AttachClipboard](#attachclipboard) deve ser feita antes de chamar outras `COleDataObject` funções.

> [!NOTE]
> Como um dos parâmetros para os manipuladores do tipo "arrastar e soltar" é um ponteiro para um, não há `COleDataObject` necessidade de chamar esse construtor para dar suporte a arrastar e soltar.

## <a name="coledataobjectdetach"></a><a name="detach"></a>COleDataObject::D Etach

Chame essa função para desanexar o `COleDataObject` objeto de seu objeto de dados OLE associado sem liberar o objeto de dados.

```
LPDATAOBJECT Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto OLE data que foi desanexado.

### <a name="remarks"></a>Comentários

## <a name="coledataobjectgetdata"></a><a name="getdata"></a>COleDataObject:: GetData

Chame essa função para recuperar dados do item no formato especificado.

```
BOOL GetData(
    CLIPFORMAT cfFormat,
    LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>parâmetros

*cfFormat*<br/>
O formato no qual os dados serão retornados. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpStgMedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá dados.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão retornados. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na `FORMATETC` estrutura.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata), [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1)e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

## <a name="coledataobjectgetfiledata"></a><a name="getfiledata"></a>COleDataObject::GetFileData

Chame essa função para criar um `CFile` `CFile` objeto ou derivado e recuperar dados no formato especificado em um `CFile` ponteiro.

```
CFile* GetFileData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>parâmetros

*cfFormat*<br/>
O formato no qual os dados serão retornados. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão retornados. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na `FORMATETC` estrutura.

### <a name="return-value"></a>Valor retornado

Ponteiro para o novo `CFile` `CFile` objeto ou derivado que contém os dados, se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Dependendo da média em que os dados são armazenados, o tipo real apontado pelo valor de retorno pode ser `CFile` , `CSharedFile` ou `COleStreamFile` .

> [!NOTE]
> O `CFile` objeto acessado pelo valor de retorno dessa função pertence ao chamador. É responsabilidade do chamador para **`delete`** o `CFile` objeto, fechando o arquivo.

Para obter mais informações, consulte [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

## <a name="coledataobjectgetglobaldata"></a><a name="getglobaldata"></a>COleDataObject::GetGlobalData

Chame essa função para alocar um bloco de memória global e recuperar dados no formato especificado em um HGLOBAL.

```
HGLOBAL GetGlobalData(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>parâmetros

*cfFormat*<br/>
O formato no qual os dados serão retornados. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato no qual os dados serão retornados. Forneça um valor para esse parâmetro se desejar especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na `FORMATETC` estrutura.

### <a name="return-value"></a>Valor retornado

O identificador do bloco de memória global que contém os dados, se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

## <a name="coledataobjectgetnextformat"></a><a name="getnextformat"></a>COleDataObject::GetNextFormat

Chame essa função repetidamente para obter todos os formatos disponíveis para recuperar dados do item.

```
BOOL GetNextFormat(LPFORMATETC lpFormatEtc);
```

### <a name="parameters"></a>parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que recebe as informações de formato quando a chamada de função retorna.

### <a name="return-value"></a>Valor retornado

Diferente de zero se outro formato estiver disponível; caso contrário, 0.

### <a name="remarks"></a>Comentários

Após uma chamada para [COleDataObject:: BeginEnumFormats](#beginenumformats), a posição do primeiro formato com suporte por esse objeto de dados é armazenada. As chamadas sucessivas para `GetNextFormat` enumerarão a lista de formatos disponíveis no objeto de dados. Use essas funções para listar os formatos disponíveis.

Para verificar a disponibilidade de um determinado formato, chame [COleDataObject:: IsDataAvailable](#isdataavailable).

Para obter mais informações, consulte [IEnumXXXX:: Next](/previous-versions/ms695273\(v=vs.85\)) na SDK do Windows.

## <a name="coledataobjectisdataavailable"></a><a name="isdataavailable"></a>COleDataObject::IsDataAvailable

Chame essa função para determinar se um formato específico está disponível para recuperar dados do item OLE.

```
BOOL IsDataAvailable(
    CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc = NULL);
```

### <a name="parameters"></a>parâmetros

*cfFormat*<br/>
O formato de dados da área de transferência a ser usado na estrutura apontada por *lpFormatEtc*. Esse parâmetro pode ser um dos formatos predefinidos da área de transferência ou o valor retornado pela função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) nativa do Windows.

*lpFormatEtc*<br/>
Aponta para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) que descreve o formato desejado. Forneça um valor para esse parâmetro somente se você quiser especificar informações de formato adicionais além do formato de área de transferência especificado por *cfFormat*. Se for NULL, os valores padrão serão usados para os outros campos na `FORMATETC` estrutura.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os dados estiverem disponíveis no formato especificado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil antes `GetData` de chamar, `GetFileData` ou `GetGlobalData` .

Para obter mais informações, consulte [IDataObject:: QueryGetData](/windows/win32/api/objidl/nf-objidl-idataobject-querygetdata) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

Para obter mais informações, consulte [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CRichEditView:: QueryAcceptData](../../mfc/reference/cricheditview-class.md#queryacceptdata).

## <a name="coledataobjectrelease"></a><a name="release"></a>COleDataObject:: versão

Chame essa função para liberar a propriedade do objeto [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) que foi associado anteriormente ao `COleDataObject` objeto.

```cpp
void Release();
```

### <a name="remarks"></a>Comentários

O `IDataObject` foi associado ao `COleDataObject` chamando `Attach` ou `AttachClipboard` explicitamente ou pela estrutura. Se o parâmetro *bAutoRelease* de `Attach` for false, o `IDataObject` objeto não será liberado. Nesse caso, o chamador é responsável por liberar o `IDataObject` chamando [IUnknown:: Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release).

## <a name="see-also"></a>Confira também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDataSource](../../mfc/reference/coledatasource-class.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
