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
ms.openlocfilehash: 89cb8ddcdd42643f52f755516e8845109163c57a
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418688"
---
# <a name="cdatapathproperty-class"></a>Classe CDataPathProperty

Implementa uma propriedade de controle OLE que pode ser carregada de forma assíncrona.

## <a name="syntax"></a>Sintaxe

```
class CDataPathProperty : public CAsyncMonikerFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDataPathProperty::CDataPathProperty](#cdatapathproperty)|Constrói um objeto `CDataPathProperty`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDataPathProperty:: GetControl](#getcontrol)|Recupera o controle OLE assíncrono associado ao objeto `CDataPathProperty`.|
|[CDataPathProperty:: GetPath](#getpath)|Recupera o nome do caminho da propriedade.|
|[CDataPathProperty:: abrir](#open)|Inicia o carregamento da propriedade assíncrona para o controle ActiveX (OLE) associado.|
|[CDataPathProperty:: ResetData](#resetdata)|Chama `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner de que as propriedades de controle foram alteradas.|
|[CDataPathProperty:: SetControl](#setcontrol)|Define o controle assíncrono do ActiveX (OLE) associado à propriedade.|
|[CDataPathProperty:: SetPath](#setpath)|Define o nome do caminho da propriedade.|

## <a name="remarks"></a>Comentários

As propriedades assíncronas são carregadas após a inicialização síncrona.

A classe `CDataPathProperty` é derivada de `CAysncMonikerFile`. Para implementar propriedades assíncronas nos controles OLE, derive uma classe de `CDataPathProperty`e substitua [OnDataAvailable](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable).

Para obter mais informações sobre como usar monikers assíncronos e controles ActiveX em aplicativos de Internet, consulte os seguintes artigos:

- [Primeiras etapas da Internet: controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

- [Primeiras etapas da Internet: monikers assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[OLE](../../mfc/reference/cfile-class.md)

[COleStreamFile](../../mfc/reference/colestreamfile-class.md)

[CMonikerFile](../../mfc/reference/cmonikerfile-class.md)

[CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)

`CDataPathProperty`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="cdatapathproperty"></a>CDataPathProperty::CDataPathProperty

Constrói um objeto `CDataPathProperty`.

```
CDataPathProperty(COleControl* pControl = NULL);
CDataPathProperty(LPCTSTR lpszPath, COleControl* pControl = NULL);
```

### <a name="parameters"></a>parâmetros

*pControl*<br/>
Um ponteiro para o objeto de controle OLE a ser associado a este objeto de `CDataPathProperty`.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, usado para criar um moniker assíncrono que faz referência ao local absoluto real da propriedade. `CDataPathProperty` usa URLs, não nomes de File. Se você quiser um objeto `CDataPathProperty` para um arquivo, preceda `file://` ao caminho.

### <a name="remarks"></a>Comentários

O objeto `COleControl` apontado por *pControl* é usado pelo `Open` e recuperado por classes derivadas. Se *pControl* for NULL, o controle usado com `Open` deverá ser definido com `SetControl`. Se *lpszPath* for nulo, você poderá passar o caminho por `Open` ou defini-lo com `SetPath`.

##  <a name="getcontrol"></a>CDataPathProperty:: GetControl

Chame essa função de membro para recuperar o objeto de `COleControl` associado ao objeto `CDataPathProperty`.

```
COleControl* GetControl();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o controle OLE associado ao objeto `CDataPathProperty`. NULL se o controle não estiver associado.

##  <a name="getpath"></a>CDataPathProperty:: GetPath

Chame essa função de membro para recuperar o caminho, definido quando o objeto `CDataPathProperty` foi construído ou especificado em `Open`ou especificado em uma chamada anterior à função membro `SetPath`.

```
CString GetPath() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o nome de caminho para a propriedade em si. Pode ficar vazio se nenhum caminho tiver sido especificado.

##  <a name="open"></a>CDataPathProperty:: abrir

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

### <a name="parameters"></a>parâmetros

*pControl*<br/>
Um ponteiro para o objeto de controle OLE a ser associado a este objeto de `CDataPathProperty`.

*pError*<br/>
Um ponteiro para uma exceção de arquivo. No caso de um erro, será definido como a causa.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, usado para criar um moniker assíncrono que faz referência ao local absoluto real da propriedade. `CDataPathProperty` usa URLs, não nomes de File. Se você quiser um objeto `CDataPathProperty` para um arquivo, preceda `file://` ao caminho.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A função tenta obter a interface de `IBindHost` do controle.

Antes de chamar `Open` sem um caminho, o valor do caminho da propriedade deve ser definido. Isso pode ser feito quando o objeto é construído ou chamando a função membro `SetPath`.

Antes de chamar `Open` sem um controle, um controle ActiveX (anteriormente conhecido como um controle OLE) pode ser associado ao objeto. Isso pode ser feito quando o objeto é construído ou chamando `SetControl`.

Todas as sobrecargas de [CAsyncMonikerFile:: Open](../../mfc/reference/casyncmonikerfile-class.md#open) também estão disponíveis em `CDataPathProperty`.

##  <a name="resetdata"></a>CDataPathProperty:: ResetData

Chame essa função para obter `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner de que as propriedades do controle foram alteradas e todas as informações carregadas de forma assíncrona não são mais úteis.

```
virtual void ResetData();
```

### <a name="remarks"></a>Comentários

A abertura deve ser reiniciada. As classes derivadas podem substituir essa função por padrões diferentes.

##  <a name="setcontrol"></a>CDataPathProperty:: SetControl

Chame essa função de membro para associar um controle OLE assíncrono ao objeto `CDataPathProperty`.

```
void SetControl(COleControl* pControl);
```

### <a name="parameters"></a>parâmetros

*pControl*<br/>
Um ponteiro para o controle OLE assíncrono a ser associado à propriedade.

##  <a name="setpath"></a>CDataPathProperty:: SetPath

Chame essa função de membro para definir o nome do caminho da propriedade.

```
void SetPath(LPCTSTR lpszPath);
```

### <a name="parameters"></a>parâmetros

*lpszPath*<br/>
Um caminho, que pode ser absoluto ou relativo, para a propriedade que está sendo carregada de forma assíncrona. `CDataPathProperty` usa URLs, não nomes de File. Se você quiser um objeto `CDataPathProperty` para um arquivo, preceda `file://` ao caminho.

## <a name="see-also"></a>Confira também

[Imagem de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
