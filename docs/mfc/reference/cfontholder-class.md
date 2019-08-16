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
ms.openlocfilehash: 04de8141469f82bdd1fbb6adc1bae94d6026324c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506439"
---
# <a name="cfontholder-class"></a>Classe CFontHolder

Implementa a propriedade Font de stock e encapsula a funcionalidade de um objeto de fonte do Windows `IFont` e a interface.

## <a name="syntax"></a>Sintaxe

```
class CFontHolder
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontHolder::CFontHolder](#cfontholder)|Constrói um objeto `CFontHolder`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontHolder::GetDisplayString](#getdisplaystring)|Recupera a cadeia de caracteres exibida no navegador de propriedades de um contêiner.|
|[CFontHolder::GetFontDispatch](#getfontdispatch)|Retorna a interface da `IDispatch` fonte.|
|[CFontHolder::GetFontHandle](#getfonthandle)|Retorna um identificador para uma fonte do Windows.|
|[CFontHolder::InitializeFont](#initializefont)|Inicializa um `CFontHolder` objeto.|
|[CFontHolder::QueryTextMetrics](#querytextmetrics)|Recupera informações para a fonte relacionada.|
|[CFontHolder::ReleaseFont](#releasefont)|Desconecta o `CFontHolder` objeto `IFont` das interfaces e `IFontNotification` .|
|[CFontHolder::Select](#select)|Seleciona um recurso de fonte em um contexto de dispositivo.|
|[CFontHolder::SetFont](#setfont)|Conecta o `CFontHolder` objeto a uma `IFont` interface.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontHolder::m_pFont](#m_pfont)|Um ponteiro para a `CFontHolder` interface do `IFont` objeto.|

## <a name="remarks"></a>Comentários

`CFontHolder`Não tem uma classe base.

Use essa classe para implementar propriedades de fonte personalizadas para seu controle. Para obter informações sobre como criar essas propriedades, consulte [o artigo controles ActiveX: Usando fontes](../../mfc/mfc-activex-controls-using-fonts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CFontHolder`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="cfontholder"></a>  CFontHolder::CFontHolder

Constrói um objeto `CFontHolder`.

```
explicit CFontHolder(LPPROPERTYNOTIFYSINK pNotify);
```

### <a name="parameters"></a>Parâmetros

*pNotify*<br/>
Ponteiro para a interface da `IPropertyNotifySink` fonte.

### <a name="remarks"></a>Comentários

Você deve chamar `InitializeFont` para inicializar o objeto resultante antes de usá-lo.

##  <a name="getdisplaystring"></a>  CFontHolder::GetDisplayString

Recupera uma cadeia de caracteres que pode ser exibida no navegador de propriedades de um contêiner.

```
BOOL GetDisplayString(CString& strValue);
```

### <a name="parameters"></a>Parâmetros

*strValue*<br/>
Referência ao [CString](../../atl-mfc-shared/reference/cstringt-class.md) que deve conter a cadeia de caracteres de exibição.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a cadeia de caracteres for recuperada com êxito; caso contrário, 0.

##  <a name="getfontdispatch"></a>  CFontHolder::GetFontDispatch

Chame essa função para recuperar um ponteiro para a interface de expedição da fonte.

```
LPFONTDISP GetFontDispatch();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a `CFontHolder` interface do `IFontDisp` objeto. Observe que a função que chama `GetFontDispatch` deve chamar `IUnknown::Release` neste ponteiro de interface quando feito com ele.

### <a name="remarks"></a>Comentários

Chame `InitializeFont` antes de `GetFontDispatch`chamar.

##  <a name="getfonthandle"></a>  CFontHolder::GetFontHandle

Chame essa função para obter um identificador para uma fonte do Windows.

```
HFONT GetFontHandle();

HFONT GetFontHandle(
    long cyLogical,
    long cyHimetric);
```

### <a name="parameters"></a>Parâmetros

*cyLogical*<br/>
Altura, em unidades lógicas, do retângulo no qual o controle é desenhado.

*cyHimetric*<br/>
Altura, em unidades MM_HIMETRIC, do controle.

### <a name="return-value"></a>Valor de retorno

Um identificador para o objeto de fonte; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A proporção de *cyLogical* e *cyHimetric* é usada para calcular o tamanho de exibição adequado, em unidades lógicas, para o tamanho de ponto da fonte expresso em unidades MM_HIMETRIC:

Tamanho de exibição = ( *cyLogical* / *cyHimetric*) X tamanho da fonte

A versão sem parâmetros retorna um identificador para uma fonte dimensionada corretamente para a tela.

##  <a name="initializefont"></a>  CFontHolder::InitializeFont

Inicializa um `CFontHolder` objeto.

```
void InitializeFont(
    const FONTDESC* pFontDesc = NULL,
    LPDISPATCH pFontDispAmbient = NULL);
```

### <a name="parameters"></a>Parâmetros

*pFontDesc*<br/>
Ponteiro para uma estrutura de descrição de fonte ( [FONTDESC](/windows/win32/api/olectl/ns-olectl-fontdesc)) que especifica as características da fonte.

*pFontDispAmbient*<br/>
Ponteiro para a propriedade de fonte de ambiente do contêiner.

### <a name="remarks"></a>Comentários

Se *pFontDispAmbient* não for nulo, o `CFontHolder` objeto será conectado a `IFont` um clone da interface usada pela propriedade de fonte de ambiente do contêiner.

Se *pFontDispAmbient* for NULL, um novo objeto Font será criado a partir da descrição da fonte apontada por *pFontDesc* ou, se *pFontDesc* for NULL, de uma descrição padrão.

Chame essa função depois de construir um `CFontHolder` objeto.

##  <a name="m_pfont"></a>  CFontHolder::m_pFont

Um ponteiro para a `CFontHolder` interface do `IFont` objeto.

```
LPFONT m_pFont;
```

##  <a name="querytextmetrics"></a>  CFontHolder::QueryTextMetrics

Recupera informações sobre a fonte física representada pelo `CFontHolder` objeto.

```
void QueryTextMetrics(LPTEXTMETRIC lptm);
```

### <a name="parameters"></a>Parâmetros

*lptm*<br/>
Um ponteiro para uma estrutura [TEXTMETRIC](/windows/win32/api/wingdi/ns-wingdi-textmetricw) que receberá as informações.

##  <a name="releasefont"></a>  CFontHolder::ReleaseFont

Essa função desconecta o `CFontHolder` objeto de sua `IFont` interface.

```
void ReleaseFont();
```

##  <a name="select"></a>  CFontHolder::Select

Chame essa função para selecionar a fonte do seu controle no contexto do dispositivo especificado.

```
CFont* Select(
    CDC* pDC,
    long cyLogical,
    long cyHimetric);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Contexto do dispositivo no qual a fonte está selecionada.

*cyLogical*<br/>
Altura, em unidades lógicas, do retângulo no qual o controle é desenhado.

*cyHimetric*<br/>
Altura, em unidades MM_HIMETRIC, do controle.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a fonte que está sendo substituída.

### <a name="remarks"></a>Comentários

Consulte [GetFontHandle](#getfonthandle) para obter uma discussão dos parâmetros *cyLogical* e *cyHimetric* .

##  <a name="setfont"></a>  CFontHolder::SetFont

Libera qualquer fonte existente e conecta o `CFontHolder` objeto a uma `IFont` interface.

```
void SetFont(LPFONT pNewFont);
```

### <a name="parameters"></a>Parâmetros

*pNewFont*<br/>
Ponteiro para a nova `IFont` interface.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPropExchange](../../mfc/reference/cpropexchange-class.md)
