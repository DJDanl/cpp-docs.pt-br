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
ms.openlocfilehash: 14ffcbc043d80bfd296bcf52d125d288039f0501
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50509550"
---
# <a name="cpictureholder-class"></a>Classe CPictureHolder

Implementa uma propriedade de imagem, que permite ao usuário exibir uma imagem em seu controle.

## <a name="syntax"></a>Sintaxe

```
class CPictureHolder
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPictureHolder::CPictureHolder](#cpictureholder)|Constrói um objeto `CPictureHolder`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPictureHolder::CreateEmpty](#createempty)|Cria um objeto `CPictureHolder` vazio.|
|[CPictureHolder::CreateFromBitmap](#createfrombitmap)|Cria um `CPictureHolder` objeto a partir de um bitmap.|
|[CPictureHolder::CreateFromIcon](#createfromicon)|Cria um `CPictureHolder` objeto a partir de um ícone.|
|[CPictureHolder::CreateFromMetafile](#createfrommetafile)|Cria um `CPictureHolder` objeto a partir de um metarquivo.|
|[CPictureHolder::GetDisplayString](#getdisplaystring)|Recupera a cadeia de caracteres exibida no navegador de propriedade de um controle do contêiner.|
|[CPictureHolder::GetPictureDispatch](#getpicturedispatch)|Retorna o `CPictureHolder` do objeto `IDispatch` interface.|
|[CPictureHolder::GetType](#gettype)|Informa se o `CPictureHolder` objeto é um bitmap, um metarquivo ou um ícone.|
|[CPictureHolder::Render](#render)|Processa a imagem.|
|[CPictureHolder::SetPictureDispatch](#setpicturedispatch)|Define o `CPictureHolder` do objeto `IDispatch` interface.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPictureHolder::m_pPict](#m_ppict)|Um ponteiro para um objeto de imagem.|

## <a name="remarks"></a>Comentários

`CPictureHolder` não tem uma classe base.

Com a propriedade de imagem de estoque, o desenvolvedor pode especificar um bitmap, ícone ou meta-arquivo para exibição.

Para obter informações sobre a criação de propriedades da imagem personalizada, consulte o artigo [controles ActiveX MFC: usando imagens em um controle ActiveX](../../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPictureHolder`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="cpictureholder"></a>  CPictureHolder::CPictureHolder

Constrói um objeto `CPictureHolder`.

```
CPictureHolder();
```

##  <a name="createempty"></a>  CPictureHolder::CreateEmpty

Cria uma vazia `CPictureHolder` do objeto e a conecta a um `IPicture` interface.

```
BOOL CreateEmpty();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.

##  <a name="createfrombitmap"></a>  CPictureHolder::CreateFromBitmap

Usa um bitmap para inicializar o objeto de imagem em um `CPictureHolder`.

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
ID do recurso de um recurso de bitmap.

*pBitmap*<br/>
Ponteiro para um [CBitmap](../../mfc/reference/cbitmap-class.md) objeto.

*pPal*<br/>
Ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md) objeto.

*bTransferOwnership*<br/>
Indica se o objeto de imagem assumirá a propriedade dos objetos bitmap e paleta.

*hbm*<br/>
Identificador para o bitmap do qual o `CPictureHolder` objeto é criado.

*hpal*<br/>
Identificador para a paleta usada para renderizar o bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bTransferOwnership* for TRUE, o chamador não deve usar o bitmap ou retorna um objeto paleta de qualquer maneira após esta chamada. Se *bTransferOwnership* é FALSE, o chamador é responsável por garantir que os objetos de bitmap e paleta permaneçam válidos pelo tempo de vida do objeto de imagem.

##  <a name="createfromicon"></a>  CPictureHolder::CreateFromIcon

Usa um ícone para inicializar o objeto de imagem em um `CPictureHolder`.

```
BOOL CreateFromIcon(
    UINT idResource);

BOOL CreateFromIcon(
    HICON hIcon,
    BOOL bTransferOwnership = FALSE);
```

### <a name="parameters"></a>Parâmetros

*idResource*<br/>
ID do recurso de um recurso de bitmap.

*hIcon*<br/>
Identificador para o ícone do qual o `CPictureHolder` objeto é criado.

*bTransferOwnership*<br/>
Indica se o objeto de imagem assumirá a propriedade do objeto ícone.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bTransferOwnership* for TRUE, o chamador não deve usar o objeto de ícone de nenhuma forma depois retorna essa chamada. Se *bTransferOwnership* é FALSE, o chamador é responsável por garantir que o objeto ícone permanece válido para o tempo de vida do objeto de imagem.

##  <a name="createfrommetafile"></a>  CPictureHolder::CreateFromMetafile

Usa um metarquivo para inicializar o objeto de imagem em um `CPictureHolder`.

```
BOOL CreateFromMetafile(
    HMETAFILE hmf,
    int xExt,
    int yExt,
    BOOL bTransferOwnership = FALSE);
```

### <a name="parameters"></a>Parâmetros

*hmf*<br/>
Identificador para o metarquivo usado para criar o `CPictureHolder` objeto.

*xExt*<br/>
X extensão da imagem.

*yExt*<br/>
Extensão de Y da imagem.

*bTransferOwnership*<br/>
Indica se o objeto de imagem assumirá a propriedade do objeto metarquivo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bTransferOwnership* for TRUE, o chamador não deve usar o objeto de metarquivo de qualquer forma depois retorna essa chamada. Se *bTransferOwnership* é FALSE, o chamador é responsável por garantir que o objeto de metarquivo permanece válido para o tempo de vida do objeto de imagem.

##  <a name="getdisplaystring"></a>  CPictureHolder::GetDisplayString

Recupera a cadeia de caracteres que é exibida no navegador de propriedade de um contêiner.

```
BOOL GetDisplayString(CString& strValue);
```

### <a name="parameters"></a>Parâmetros

*strValue*<br/>
Referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é armazenar a cadeia de caracteres de exibição.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a cadeia de caracteres é recuperada com êxito. Caso contrário, 0.

##  <a name="getpicturedispatch"></a>  CPictureHolder::GetPictureDispatch

Essa função retorna um ponteiro para o `CPictureHolder` do objeto `IPictureDisp` interface.

```
LPPICTUREDISP GetPictureDispatch();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CPictureHolder` do objeto `IPictureDisp` interface.

### <a name="remarks"></a>Comentários

O chamador deve chamar `Release` nesse ponteiro quando terminar com ele.

##  <a name="gettype"></a>  CPictureHolder::GetType

Indica se a imagem é um bitmap, metarquivo ou ícone.

```
short GetType();
```

### <a name="return-value"></a>Valor de retorno

Um valor que indica o tipo da imagem. Os valores possíveis e seus significados são da seguinte maneira:

|Valor|Significado|
|-----------|-------------|
|PICTYPE_UNINITIALIZED|`CPictureHolder` objeto é unititialized.|
|PICTYPE_NONE|`CPictureHolder` objeto está vazio.|
|PICTYPE_BITMAP|Figura é um bitmap.|
|PICTYPE_METAFILE|Figura é um metarquivo.|
|PICTYPE_ICON|Figura é um ícone.|

##  <a name="m_ppict"></a>  CPictureHolder::m_pPict

Um ponteiro para o `CPictureHolder` do objeto `IPicture` interface.

```
LPPICTURE m_pPict;
```

##  <a name="render"></a>  CPictureHolder::Render

Renderiza a imagem no retângulo referenciado pelo *rcRender*.

```
void Render(
    CDC* pDC,
    const CRect& rcRender,
    const CRect& rcWBounds);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto de exibição na qual a imagem deve ser renderizado.

*rcRender*<br/>
Retângulo no qual a imagem deve ser renderizada.

*rcWBounds*<br/>
Um retângulo que representa o retângulo delimitador do objeto de renderização de imagem. Para um controle, esse retângulo é o *rcBounds* parâmetro passado para uma substituição do [COleControl::OnDraw](../../mfc/reference/colecontrol-class.md#ondraw).

##  <a name="setpicturedispatch"></a>  CPictureHolder::SetPictureDispatch

Conecta-se a `CPictureHolder` do objeto para um `IPictureDisp` interface.

```
void SetPictureDispatch(LPPICTUREDISP pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
Ponteiro para o novo `IPictureDisp` interface.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFontHolder](../../mfc/reference/cfontholder-class.md)
