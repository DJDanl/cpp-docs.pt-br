---
title: Classe CDataPathProperty
ms.date: 11/04/2016
f1_keywords:
- CDataPathProperty
- AFXCTL/CDataPathProperty
- AFXCTL/CDataPathProperty::CDataPathProperty
- AFXCTL/CDataPathProperty::GetControl
- AFXCTL/CDataPathProperty::GetPath
- AFXCTL/CDataPathProperty::Open
- AFXCTL/CDataPathProperty::ResetData
- AFXCTL/CDataPathProperty::SetControl
- AFXCTL/CDataPathProperty::SetPath
helpviewer_keywords:
- CDataPathProperty [MFC], CDataPathProperty
- CDataPathProperty [MFC], GetControl
- CDataPathProperty [MFC], GetPath
- CDataPathProperty [MFC], Open
- CDataPathProperty [MFC], ResetData
- CDataPathProperty [MFC], SetControl
- CDataPathProperty [MFC], SetPath
ms.assetid: 1f96efdb-54e4-460b-862c-eba5d4103488
ms.openlocfilehash: 479f5d47d9cff72d36dbd25e434182af1ba01ef4
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754658"
---
# <a name="cdatapathproperty-class"></a>Classe CDataPathProperty

Implementa uma propriedade de controle OLE que pode ser carregada de forma assíncrona.

## <a name="syntax"></a>Sintaxe

```
class CDataPathProperty : public CAsyncMonikerFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataPathPropriedade::CDataPathProperty](#cdatapathproperty)|Constrói um objeto `CDataPathProperty`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataPathProperty::GetControl](#getcontrol)|Recupera o controle OLE assíncrono associado ao `CDataPathProperty` objeto.|
|[CDataPathProperty::getpath](#getpath)|Recupera o nome do caminho da propriedade.|
|[CDataPathProperty::Abrir](#open)|Inicia o carregamento da propriedade assíncrona para o controle ActiveX (OLE) associado.|
|[CDataPathProperty::Redefinirdados](#resetdata)|Chamadas `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner que as propriedades de controle mudaram.|
|[CDataPathProperty::SetControl](#setcontrol)|Define o controle ActiveX (OLE) assíncrono associado à propriedade.|
|[CDataPathProperty::SetPath](#setpath)|Define o nome do caminho da propriedade.|

## <a name="remarks"></a>Comentários

As propriedades assíncronas são carregadas após a iniciação síncrona.

A `CDataPathProperty` classe é `CAysncMonikerFile`derivada de . Para implementar propriedades assíncronas em seus controles `CDataPathProperty`OLE, obtenha uma classe e anule [onDataAvailable](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable).

Para obter mais informações sobre como usar apelidos assíncronos e controles ActiveX em aplicativos da Internet, consulte os seguintes artigos:

- [Primeiros passos da Internet: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

- [Primeiros Passos da Internet: Apelidos Assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Colestreamfile](../../mfc/reference/colestreamfile-class.md)

[Cmonikerfile](../../mfc/reference/cmonikerfile-class.md)

[Casyncmonikerfile](../../mfc/reference/casyncmonikerfile-class.md)

`CDataPathProperty`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="cdatapathpropertycdatapathproperty"></a><a name="cdatapathproperty"></a>CDataPathPropriedade::CDataPathProperty

Constrói um objeto `CDataPathProperty`.

```
CDataPathProperty(COleControl* pControl = NULL);
CDataPathProperty(LPCTSTR lpszPath, COleControl* pControl = NULL);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
Um ponteiro para o objeto de controle `CDataPathProperty` OLE a ser associado a este objeto.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, foi usado para criar um apelido assíncrono que faz referência à localização absoluta real da propriedade. `CDataPathProperty`usa URLs, não nomes de arquivos. Se você `CDataPathProperty` quiser um objeto para `file://` um arquivo, prepare-se para o caminho.

### <a name="remarks"></a>Comentários

O `COleControl` objeto apontado pelo *pControl* é usado e recuperado por `Open` classes derivadas. Se *o pControl* for NULL, o controle usado deve `Open` ser definido com `SetControl`. Se *lpszPath* for NULL, você pode `Open` passar no `SetPath`caminho ou defini-lo com .

## <a name="cdatapathpropertygetcontrol"></a><a name="getcontrol"></a>CDataPathProperty::GetControl

Ligue para esta função `COleControl` de membro `CDataPathProperty` para recuperar o objeto associado ao objeto.

```
COleControl* GetControl();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o controle `CDataPathProperty` OLE associado ao objeto. NULL se não o controle está associado.

## <a name="cdatapathpropertygetpath"></a><a name="getpath"></a>CDataPathProperty::getpath

Chame esta função de membro para `CDataPathProperty` recuperar o caminho, definido `Open`quando o objeto foi construído `SetPath` ou especificado em , ou especificado em uma chamada anterior para a função membro.

```
CString GetPath() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o nome do caminho para a propriedade em si. Pode estar vazio se nenhum caminho foi especificado.

## <a name="cdatapathpropertyopen"></a><a name="open"></a>CDataPathProperty::Abrir

Ligue para esta função de membro para iniciar o carregamento da propriedade assíncrona para o controle associado.

```
virtual BOOL Open(
    COleControl* pControl,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszPath,
    COleControl* pControl,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszPath,
    CFileException* pError = NULL);

virtual BOOL Open(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
Um ponteiro para o objeto de controle `CDataPathProperty` OLE a ser associado a este objeto.

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, será definido para a causa.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, foi usado para criar um apelido assíncrono que faz referência à localização absoluta real da propriedade. `CDataPathProperty`usa URLs, não nomes de arquivos. Se você `CDataPathProperty` quiser um objeto para `file://` um arquivo, prepare-se para o caminho.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A função tenta `IBindHost` obter a interface a partir do controle.

Antes `Open` de chamar sem um caminho, o valor para o caminho da propriedade deve ser definido. Isso pode ser feito quando o objeto é `SetPath` construído, ou chamando a função do membro.

Antes `Open` de ligar sem controle, um controle ActiveX (anteriormente conhecido como controle OLE) pode ser associado ao objeto. Isso pode ser feito quando o objeto `SetControl`é construído, ou por chamada .

Todas as sobrecargas de [CAsyncMonikerFile::Open](../../mfc/reference/casyncmonikerfile-class.md#open) também estão disponíveis a partir de `CDataPathProperty`.

## <a name="cdatapathpropertyresetdata"></a><a name="resetdata"></a>CDataPathProperty::Redefinirdados

Ligue para esta `CAsyncMonikerFile::OnDataAvailable` função para que o contêiner notifique que as propriedades de controle foram alteradas, e todas as informações carregadas assíncronamente não são mais úteis.

```
virtual void ResetData();
```

### <a name="remarks"></a>Comentários

A abertura deve ser reiniciada. Classes derivadas podem substituir essa função para diferentes padrões.

## <a name="cdatapathpropertysetcontrol"></a><a name="setcontrol"></a>CDataPathProperty::SetControl

Chame esta função de membro para associar um `CDataPathProperty` controle OLE assíncrono com o objeto.

```cpp
void SetControl(COleControl* pControl);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
Um ponteiro para o controle oLE assíncrono a ser associado com a propriedade.

## <a name="cdatapathpropertysetpath"></a><a name="setpath"></a>CDataPathProperty::SetPath

Chame esta função de membro para definir o nome de caminho da propriedade.

```cpp
void SetPath(LPCTSTR lpszPath);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
Um caminho, que pode ser absoluto ou relativo, para a propriedade ser carregada assíncronamente. `CDataPathProperty`usa URLs, não nomes de arquivos. Se você `CDataPathProperty` quiser um objeto para `file://` um arquivo, prepare-se para o caminho.

## <a name="see-also"></a>Confira também

[Imagem de amostra mfc](../../overview/visual-cpp-samples.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
