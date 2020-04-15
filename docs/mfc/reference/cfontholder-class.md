---
title: Classe CFontHolder
ms.date: 11/04/2016
f1_keywords:
- CFontHolder
- AFXCTL/CFontHolder
- AFXCTL/CFontHolder::CFontHolder
- AFXCTL/CFontHolder::GetDisplayString
- AFXCTL/CFontHolder::GetFontDispatch
- AFXCTL/CFontHolder::GetFontHandle
- AFXCTL/CFontHolder::InitializeFont
- AFXCTL/CFontHolder::QueryTextMetrics
- AFXCTL/CFontHolder::ReleaseFont
- AFXCTL/CFontHolder::Select
- AFXCTL/CFontHolder::SetFont
- AFXCTL/CFontHolder::m_pFont
helpviewer_keywords:
- CFontHolder [MFC], CFontHolder
- CFontHolder [MFC], GetDisplayString
- CFontHolder [MFC], GetFontDispatch
- CFontHolder [MFC], GetFontHandle
- CFontHolder [MFC], InitializeFont
- CFontHolder [MFC], QueryTextMetrics
- CFontHolder [MFC], ReleaseFont
- CFontHolder [MFC], Select
- CFontHolder [MFC], SetFont
- CFontHolder [MFC], m_pFont
ms.assetid: 728ab472-0c97-440d-889f-1324c6e1b6b8
ms.openlocfilehash: 6a053f127123a9ca21853189b9458738b217ee2b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373807"
---
# <a name="cfontholder-class"></a>Classe CFontHolder

Implementa a propriedade stock Font e encapsula a funcionalidade de `IFont` um objeto de fonte do Windows e da interface.

## <a name="syntax"></a>Sintaxe

```
class CFontHolder
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[suporte de fonte de c::CFontHolder](#cfontholder)|Constrói um objeto `CFontHolder`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[suporte de fonte de c::getDisplaystring](#getdisplaystring)|Recupera a seqüência exibida no navegador de propriedade de um contêiner.|
|[suporte de fonte de c::getFontDispatch](#getfontdispatch)|Retorna a interface `IDispatch` da fonte.|
|[suporte de fonte de fonte::getfonthandle](#getfonthandle)|Retorna uma alça para uma fonte do Windows.|
|[CFontHolder::InitializeFont](#initializefont)|Inicializa um objeto `CFontHolder`.|
|[CFontHolder::QueryTextMetrics](#querytextmetrics)|Recupera informações para a fonte relacionada.|
|[CFontHolder::Fonte de lançamento](#releasefont)|Desconecta `CFontHolder` o `IFont` objeto `IFontNotification` das interfaces e.|
|[Suporte de fonte de refont::Selecionar](#select)|Seleciona um recurso de fonte em um contexto de dispositivo.|
|[suporte de fonte de fonte de c::setFont](#setfont)|Conecta o `CFontHolder` objeto `IFont` a uma interface.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Suporte de fonte de refonte::m_pFont](#m_pfont)|Um ponteiro `CFontHolder` para a `IFont` interface do objeto.|

## <a name="remarks"></a>Comentários

`CFontHolder`não tem uma classe base.

Use esta classe para implementar propriedades de fonte personalizadas para o seu controle. Para obter informações sobre a criação dessas propriedades, consulte o artigo [ActiveX Controls: Usando Fontes](../../mfc/mfc-activex-controls-using-fonts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CFontHolder`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="cfontholdercfontholder"></a><a name="cfontholder"></a>suporte de fonte de c::CFontHolder

Constrói um objeto `CFontHolder`.

```
explicit CFontHolder(LPPROPERTYNOTIFYSINK pNotify);
```

### <a name="parameters"></a>Parâmetros

*pNotificar*<br/>
Ponteiro para a `IPropertyNotifySink` interface da fonte.

### <a name="remarks"></a>Comentários

Você deve `InitializeFont` ligar para inicializar o objeto resultante antes de usá-lo.

## <a name="cfontholdergetdisplaystring"></a><a name="getdisplaystring"></a>suporte de fonte de c::getDisplaystring

Recupera uma seqüência que pode ser exibida no navegador de propriedade de um contêiner.

```
BOOL GetDisplayString(CString& strValue);
```

### <a name="parameters"></a>Parâmetros

*strValue*<br/>
Referência ao [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é para segurar a seqüência de exibição.

### <a name="return-value"></a>Valor retornado

Não zero se a seqüência for recuperada com sucesso; caso contrário, 0.

## <a name="cfontholdergetfontdispatch"></a><a name="getfontdispatch"></a>suporte de fonte de c::getFontDispatch

Chame esta função para recuperar um ponteiro na interface de despacho da fonte.

```
LPFONTDISP GetFontDispatch();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CFontHolder` para a `IFontDisp` interface do objeto. Observe que a `GetFontDispatch` função `IUnknown::Release` que chama deve chamar neste ponteiro de interface quando terminar com ele.

### <a name="remarks"></a>Comentários

Ligue `InitializeFont` antes `GetFontDispatch`de ligar.

## <a name="cfontholdergetfonthandle"></a><a name="getfonthandle"></a>suporte de fonte de fonte::getfonthandle

Ligue para esta função para obter uma alça para uma fonte do Windows.

```
HFONT GetFontHandle();

HFONT GetFontHandle(
    long cyLogical,
    long cyHimetric);
```

### <a name="parameters"></a>Parâmetros

*Cylogical*<br/>
Altura, em unidades lógicas, do retângulo em que o controle é desenhado.

*ciaimétrico*<br/>
Altura, em MM_HIMETRIC unidades, do controle.

### <a name="return-value"></a>Valor retornado

Uma alça para o objeto Fonte; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A razão de *cyLogical* e *cyHimetric* é usada para calcular o tamanho adequado do display, em unidades lógicas, para o tamanho do ponto da fonte expresso em MM_HIMETRIC unidades:

Tamanho do display = / *(cyLogical cyHimetric*) X tamanho da fonte *cyLogical*

A versão sem parâmetros retorna uma alça para uma fonte dimensionada corretamente para a tela.

## <a name="cfontholderinitializefont"></a><a name="initializefont"></a>CFontHolder::InitializeFont

Inicializa um objeto `CFontHolder`.

```
void InitializeFont(
    const FONTDESC* pFontDesc = NULL,
    LPDISPATCH pFontDispAmbient = NULL);
```

### <a name="parameters"></a>Parâmetros

*pFontDesc*<br/>
Pointer para uma estrutura de descrição da fonte [(FONTDESC)](/windows/win32/api/olectl/ns-olectl-fontdesc)que especifica as características da fonte.

*Pfontdispambient*<br/>
Ponteiro para a propriedade font ambiente do contêiner.

### <a name="remarks"></a>Comentários

Se *pFontDispAmbient* não for `CFontHolder` NULL, o objeto `IFont` será conectado a um clone da interface usada pela propriedade Font ambiente do contêiner.

Se *pFontDispAmbient* for NULL, um novo objeto Fonte será criado a partir da descrição da fonte apontada por *pFontDesc* ou, se *pFontDesc* for NULL, a partir de uma descrição padrão.

Chame essa função depois `CFontHolder` de construir um objeto.

## <a name="cfontholderm_pfont"></a><a name="m_pfont"></a>Suporte de fonte de refonte::m_pFont

Um ponteiro `CFontHolder` para a `IFont` interface do objeto.

```
LPFONT m_pFont;
```

## <a name="cfontholderquerytextmetrics"></a><a name="querytextmetrics"></a>CFontHolder::QueryTextMetrics

Recupera informações sobre a fonte `CFontHolder` física representada pelo objeto.

```
void QueryTextMetrics(LPTEXTMETRIC lptm);
```

### <a name="parameters"></a>Parâmetros

*Lptm*<br/>
Um ponteiro para uma estrutura [TEXTMETRIC](/windows/win32/api/wingdi/ns-wingdi-textmetricw) que receberá as informações.

## <a name="cfontholderreleasefont"></a><a name="releasefont"></a>CFontHolder::Fonte de lançamento

Esta função desconecta `CFontHolder` `IFont` o objeto de sua interface.

```
void ReleaseFont();
```

## <a name="cfontholderselect"></a><a name="select"></a>Suporte de fonte de refont::Selecionar

Chame esta função para selecionar a fonte do seu controle no contexto do dispositivo especificado.

```
CFont* Select(
    CDC* pDC,
    long cyLogical,
    long cyHimetric);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Contexto do dispositivo no qual a fonte é selecionada.

*Cylogical*<br/>
Altura, em unidades lógicas, do retângulo em que o controle é desenhado.

*ciaimétrico*<br/>
Altura, em MM_HIMETRIC unidades, do controle.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a fonte que está sendo substituído.

### <a name="remarks"></a>Comentários

Consulte [GetFontHandle](#getfonthandle) para uma discussão sobre os *parâmetros cyLogical* e *cyHimetric.*

## <a name="cfontholdersetfont"></a><a name="setfont"></a>suporte de fonte de fonte de c::setFont

Libera qualquer fonte existente e `CFontHolder` conecta o `IFont` objeto a uma interface.

```
void SetFont(LPFONT pNewFont);
```

### <a name="parameters"></a>Parâmetros

*pNewFont*<br/>
Ponteiro para `IFont` a nova interface.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPropExchange](../../mfc/reference/cpropexchange-class.md)
