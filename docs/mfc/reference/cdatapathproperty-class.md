---
title: Classe CDataPathProperty | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CDataPathProperty [MFC], CDataPathProperty
- CDataPathProperty [MFC], GetControl
- CDataPathProperty [MFC], GetPath
- CDataPathProperty [MFC], Open
- CDataPathProperty [MFC], ResetData
- CDataPathProperty [MFC], SetControl
- CDataPathProperty [MFC], SetPath
ms.assetid: 1f96efdb-54e4-460b-862c-eba5d4103488
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f61f62c62a73963fa790795cd5153c5103c3a61f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385112"
---
# <a name="cdatapathproperty-class"></a>Classe CDataPathProperty

Implementa uma controle OLE propriedade que pode ser carregada de forma assíncrona.

## <a name="syntax"></a>Sintaxe

```
class CDataPathProperty : public CAsyncMonikerFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataPathProperty::CDataPathProperty](#cdatapathproperty)|Constrói um objeto `CDataPathProperty`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataPathProperty::GetControl](#getcontrol)|Recupera o controle OLE assíncrono associado com o `CDataPathProperty` objeto.|
|[CDataPathProperty::GetPath](#getpath)|Recupera o nome do caminho da propriedade.|
|[CDataPathProperty::Open](#open)|Inicia o carregamento da propriedade assíncrona para o controle ActiveX (OLE) associado.|
|[CDataPathProperty::ResetData](#resetdata)|Chamadas `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner que as propriedades de controle foram alteradas.|
|[CDataPathProperty::SetControl](#setcontrol)|Define o controle ActiveX (OLE) assíncrona associado à propriedade.|
|[CDataPathProperty::SetPath](#setpath)|Define o nome do caminho da propriedade.|

## <a name="remarks"></a>Comentários

Propriedades assíncronas são carregadas após a inicialização síncrona.

A classe `CDataPathProperty` é derivado de `CAysncMonikerFile`. Para implementar propriedades assíncronas em seus controles OLE, derive uma classe de `CDataPathProperty`e substituir [OnDataAvailable](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable).

Para obter mais informações sobre como usar controles ActiveX e monikers assíncronos em aplicativos da Internet, consulte os seguintes artigos:

- [Internet primeiras etapas: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

- [Internet primeiras etapas: Monikers assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[COleStreamFile](../../mfc/reference/colestreamfile-class.md)

[CMonikerFile](../../mfc/reference/cmonikerfile-class.md)

[CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)

`CDataPathProperty`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="cdatapathproperty"></a>  CDataPathProperty::CDataPathProperty

Constrói um objeto `CDataPathProperty`.

```
CDataPathProperty(COleControl* pControl = NULL);
CDataPathProperty(LPCTSTR lpszPath, COleControl* pControl = NULL);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
Um ponteiro para o objeto de controle OLE a ser associado a este `CDataPathProperty` objeto.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, usado para criar um moniker assíncrono que referencia o local absoluto real da propriedade. `CDataPathProperty` usa URLs, não os nomes de arquivo. Se você quiser que um `CDataPathProperty` para um arquivo de objeto, preceda `file://` ao caminho.

### <a name="remarks"></a>Comentários

O `COleControl` objeto apontado por *pControl* é usado pelo `Open` e recuperados pelas classes derivadas. Se *pControl* for NULL, o controle usado com `Open` deve ser definido com `SetControl`. Se *lpszPath* for NULL, você pode passar o caminho por meio `Open` ou defini-lo com `SetPath`.

##  <a name="getcontrol"></a>  CDataPathProperty::GetControl

Chame essa função de membro para recuperar o `COleControl` objeto associado com o `CDataPathProperty` objeto.

```
COleControl* GetControl();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o controle OLE associado a `CDataPathProperty` objeto. NULL se não controle está associado.

##  <a name="getpath"></a>  CDataPathProperty::GetPath

Chame essa função de membro para recuperar o caminho, defina quando o `CDataPathProperty` objeto foi construído ou especificado no `Open`, ou especificados em uma chamada anterior para o `SetPath` função de membro.

```
CString GetPath() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o nome do caminho para a propriedade em si. Pode estar vazio se nenhum caminho tiver sido especificado.

##  <a name="open"></a>  CDataPathProperty::Open

Chame essa função de membro para iniciar o carregamento da propriedade assíncrona para o controle associado.

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
Um ponteiro para o objeto de controle OLE a ser associado a este `CDataPathProperty` objeto.

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, será definido como a causa.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, usado para criar um moniker assíncrono que referencia o local absoluto real da propriedade. `CDataPathProperty` usa URLs, não os nomes de arquivo. Se você quiser que um `CDataPathProperty` para um arquivo de objeto, preceda `file://` ao caminho.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A função tenta obter o `IBindHost` interface do controle.

Antes de chamar `Open` sem um caminho, o valor para o caminho da propriedade deve ser definido. Isso pode ser feito quando o objeto é construído, ou chamando o `SetPath` função de membro.

Antes de chamar `Open` sem um controle, um controle ActiveX (anteriormente conhecido como um controle OLE) pode ser associado ao objeto. Isso pode ser feito quando o objeto é construído, ou chamando `SetControl`.

Todas as sobrecargas do [CAsyncMonikerFile::Open](../../mfc/reference/casyncmonikerfile-class.md#open) também estão disponíveis no `CDataPathProperty`.

##  <a name="resetdata"></a>  CDataPathProperty::ResetData

Chame essa função para obter `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner que as propriedades do controle foram alterados e todas as informações carregadas de forma assíncrona não são mais útil.

```
virtual void ResetData();
```

### <a name="remarks"></a>Comentários

Abertura deve ser reiniciada. Classes derivadas podem substituir essa função para diferentes padrões.

##  <a name="setcontrol"></a>  CDataPathProperty::SetControl

Chame essa função de membro para associar um controle OLE assíncrono com o `CDataPathProperty` objeto.

```
void SetControl(COleControl* pControl);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
Um ponteiro para a assíncrona de controle OLE a ser associado com a propriedade.

##  <a name="setpath"></a>  CDataPathProperty::SetPath

Chame essa função de membro para definir o nome do caminho da propriedade.

```
void SetPath(LPCTSTR lpszPath);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
Um caminho, que pode ser absoluto ou relativo para a propriedade que está sendo carregada de forma assíncrona. `CDataPathProperty` usa URLs, não os nomes de arquivo. Se você quiser que um `CDataPathProperty` para um arquivo de objeto, preceda `file://` ao caminho.

## <a name="see-also"></a>Consulte também

[Imagem de exemplo do MFC](../../visual-cpp-samples.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
