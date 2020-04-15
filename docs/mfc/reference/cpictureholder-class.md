---
title: Classe CPictureHolder
ms.date: 11/04/2016
f1_keywords:
- CPictureHolder
- AFXCTL/CPictureHolder
- AFXCTL/CPictureHolder::CPictureHolder
- AFXCTL/CPictureHolder::CreateEmpty
- AFXCTL/CPictureHolder::CreateFromBitmap
- AFXCTL/CPictureHolder::CreateFromIcon
- AFXCTL/CPictureHolder::CreateFromMetafile
- AFXCTL/CPictureHolder::GetDisplayString
- AFXCTL/CPictureHolder::GetPictureDispatch
- AFXCTL/CPictureHolder::GetType
- AFXCTL/CPictureHolder::Render
- AFXCTL/CPictureHolder::SetPictureDispatch
- AFXCTL/CPictureHolder::m_pPict
helpviewer_keywords:
- CPictureHolder [MFC], CPictureHolder
- CPictureHolder [MFC], CreateEmpty
- CPictureHolder [MFC], CreateFromBitmap
- CPictureHolder [MFC], CreateFromIcon
- CPictureHolder [MFC], CreateFromMetafile
- CPictureHolder [MFC], GetDisplayString
- CPictureHolder [MFC], GetPictureDispatch
- CPictureHolder [MFC], GetType
- CPictureHolder [MFC], Render
- CPictureHolder [MFC], SetPictureDispatch
- CPictureHolder [MFC], m_pPict
ms.assetid: a4f59775-704a-41dd-b5bd-2e531c95127a
ms.openlocfilehash: 067ea7238c48f2698d7bfe469e9c4be10129c065
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364047"
---
# <a name="cpictureholder-class"></a>Classe CPictureHolder

Implementa uma propriedade Picture, que permite ao usuário exibir uma imagem em seu controle.

## <a name="syntax"></a>Sintaxe

```
class CPictureHolder
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPictureHolder::CPictureHolder](#cpictureholder)|Constrói um objeto `CPictureHolder`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPictureHolder::CreateEmpty](#createempty)|Cria um objeto `CPictureHolder` vazio.|
|[CPictureHolder::CreateFromBitmap](#createfrombitmap)|Cria `CPictureHolder` um objeto a partir de um bitmap.|
|[CPictureHolder::CreateFromIcon](#createfromicon)|Cria `CPictureHolder` um objeto a partir de um ícone.|
|[CPictureHolder::CreateFromMetafile](#createfrommetafile)|Cria `CPictureHolder` um objeto a partir de um metaarquivo.|
|[CPictureHolder::getDisplayString](#getdisplaystring)|Recupera a seqüência exibida no navegador de propriedade de um contêiner de controle.|
|[CPictureHolder::GetPictureDispatch](#getpicturedispatch)|Retorna `CPictureHolder` a interface `IDispatch` do objeto.|
|[CPictureHolder::getType](#gettype)|Diz se `CPictureHolder` o objeto é um bitmap, um metaarquivo ou um ícone.|
|[CPictureHolder::Renderização](#render)|Torna a imagem.|
|[CPictureHolder::setPictureDispatch](#setpicturedispatch)|Define `CPictureHolder` a interface `IDispatch` do objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPictureHolder::m_pPict](#m_ppict)|Um ponteiro para um objeto de imagem.|

## <a name="remarks"></a>Comentários

`CPictureHolder`não tem uma classe base.

Com a propriedade stock Picture, o desenvolvedor pode especificar um bitmap, ícone ou metaarquivo para exibição.

Para obter informações sobre a criação de propriedades de imagem personalizadas, consulte o artigo [MFC ActiveX Controls: Usando imagens em um controle ActiveX](../../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPictureHolder`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="cpictureholdercpictureholder"></a><a name="cpictureholder"></a>CPictureHolder::CPictureHolder

Constrói um objeto `CPictureHolder`.

```
CPictureHolder();
```

## <a name="cpictureholdercreateempty"></a><a name="createempty"></a>CPictureHolder::CreateEmpty

Cria um `CPictureHolder` objeto vazio e `IPicture` o conecta a uma interface.

```
BOOL CreateEmpty();
```

### <a name="return-value"></a>Valor retornado

Não zero se o objeto for criado com sucesso; caso contrário, 0.

## <a name="cpictureholdercreatefrombitmap"></a><a name="createfrombitmap"></a>CPictureHolder::CreateFromBitmap

Usa um bitmap para inicializar `CPictureHolder`o objeto de imagem em um .

```
BOOL CreateFromBitmap(
    UINT idResource);

BOOL CreateFromBitmap(
    CBitmap* pBitmap,
    CPalette* pPal = NULL,
    BOOL bTransferOwnership = TRUE);

BOOL CreateFromBitmap(
    HBITMAP hbm,
    HPALETTE hpal = NULL,
    BOOL bTransferOwnership = FALSE);
```

### <a name="parameters"></a>Parâmetros

*idResource*<br/>
ID de recursos de um recurso de bitmap.

*Pbitmap*<br/>
Ponteiro para um objeto [CBitmap.](../../mfc/reference/cbitmap-class.md)

*pPal*<br/>
Ponteiro para um objeto [CPalette.](../../mfc/reference/cpalette-class.md)

*Btransferownership*<br/>
Indica se o objeto de imagem tomará posse dos objetos bitmap e paleta.

*Hbm*<br/>
Manuseie o bitmap a partir do qual o `CPictureHolder` objeto é criado.

*hpal*<br/>
Manuseie a paleta usada para renderizar o bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bTransferOwnership* for TRUE, o chamador não deve usar o bitmap ou o objeto de paleta de forma alguma após o retorno desta chamada. Se *bTransferOwnership* for FALSE, o chamador é responsável por garantir que os objetos bitmap e paleta permaneçam válidos durante a vida útil do objeto de imagem.

## <a name="cpictureholdercreatefromicon"></a><a name="createfromicon"></a>CPictureHolder::CreateFromIcon

Usa um ícone para inicializar `CPictureHolder`o objeto de imagem em um .

```
BOOL CreateFromIcon(
    UINT idResource);

BOOL CreateFromIcon(
    HICON hIcon,
    BOOL bTransferOwnership = FALSE);
```

### <a name="parameters"></a>Parâmetros

*idResource*<br/>
ID de recursos de um recurso de bitmap.

*Hicon*<br/>
Manuseie o `CPictureHolder` ícone a partir do qual o objeto é criado.

*Btransferownership*<br/>
Indica se o objeto de imagem tomará posse do objeto ícone.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bTransferOwnership* for TRUE, o chamador não deve usar o objeto ícone de forma alguma após o retorno desta chamada. Se *bTransferOwnership* for FALSE, o chamador é responsável por garantir que o objeto de ícone permaneça válido durante a vida útil do objeto de imagem.

## <a name="cpictureholdercreatefrommetafile"></a><a name="createfrommetafile"></a>CPictureHolder::CreateFromMetafile

Usa um metaarquivo para inicializar `CPictureHolder`o objeto de imagem em um .

```
BOOL CreateFromMetafile(
    HMETAFILE hmf,
    int xExt,
    int yExt,
    BOOL bTransferOwnership = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Hmf*<br/>
Manuseie o metaarquivo `CPictureHolder` usado para criar o objeto.

*xExt*<br/>
X extensão da imagem.

*yExt*<br/>
A extensão do quadro.

*Btransferownership*<br/>
Indica se o objeto de imagem tomará posse do objeto metaarquivo.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bTransferOwnership* for TRUE, o chamador não deve usar o objeto metaarquivo de forma alguma após o retorno desta chamada. Se *bTransferOwnership* for FALSE, o chamador é responsável por garantir que o objeto metaarquivo permaneça válido durante a vida útil do objeto de imagem.

## <a name="cpictureholdergetdisplaystring"></a><a name="getdisplaystring"></a>CPictureHolder::getDisplayString

Recupera a seqüência de string exibida no navegador de propriedade de um contêiner.

```
BOOL GetDisplayString(CString& strValue);
```

### <a name="parameters"></a>Parâmetros

*strValue*<br/>
Referência ao [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é para segurar a seqüência de exibição.

### <a name="return-value"></a>Valor retornado

Não zero se a seqüência for recuperada com sucesso; caso contrário, 0.

## <a name="cpictureholdergetpicturedispatch"></a><a name="getpicturedispatch"></a>CPictureHolder::GetPictureDispatch

Esta função retorna um `CPictureHolder` ponteiro `IPictureDisp` para a interface do objeto.

```
LPPICTUREDISP GetPictureDispatch();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CPictureHolder` para a `IPictureDisp` interface do objeto.

### <a name="remarks"></a>Comentários

O chamador `Release` deve chamar este ponteiro quando terminar com ele.

## <a name="cpictureholdergettype"></a><a name="gettype"></a>CPictureHolder::getType

Indica se a imagem é um bitmap, metaarquivo ou ícone.

```
short GetType();
```

### <a name="return-value"></a>Valor retornado

Um valor que indica o tipo da imagem. Os valores possíveis e seus significados são os seguintes:

|Valor|Significado|
|-----------|-------------|
|PICTYPE_UNINITIALIZED|`CPictureHolder`objeto é unitializado.|
|PICTYPE_NONE|`CPictureHolder`objeto está vazio.|
|PICTYPE_BITMAP|A imagem é um bitmap.|
|PICTYPE_METAFILE|A imagem é um meta-arquivo.|
|PICTYPE_ICON|A imagem é um ícone.|

## <a name="cpictureholderm_ppict"></a><a name="m_ppict"></a>CPictureHolder::m_pPict

Um ponteiro `CPictureHolder` para a `IPicture` interface do objeto.

```
LPPICTURE m_pPict;
```

## <a name="cpictureholderrender"></a><a name="render"></a>CPictureHolder::Renderização

Renderiza a imagem no retângulo referenciado por *rcRender*.

```
void Render(
    CDC* pDC,
    const CRect& rcRender,
    const CRect& rcWBounds);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto de exibição no qual a imagem deve ser renderizada.

*rcRender*<br/>
Retângulo no qual a imagem deve ser renderizada.

*rcWBounds*<br/>
Um retângulo representando o retângulo delimitador do objeto que renderiza a imagem. Para um controle, este retângulo é o parâmetro *rcBounds* passado para uma substituição de [COleControl::OnDraw](../../mfc/reference/colecontrol-class.md#ondraw).

## <a name="cpictureholdersetpicturedispatch"></a><a name="setpicturedispatch"></a>CPictureHolder::setPictureDispatch

Conecta o `CPictureHolder` objeto `IPictureDisp` a uma interface.

```
void SetPictureDispatch(LPPICTUREDISP pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Ponteiro para `IPictureDisp` a nova interface.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFontHolder](../../mfc/reference/cfontholder-class.md)
