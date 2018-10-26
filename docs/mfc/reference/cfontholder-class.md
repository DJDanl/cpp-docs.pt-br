---
title: Classe CFontHolder | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 834d1771513ef7a482afef33c3a1bb5bd3dcb400
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065649"
---
# <a name="cfontholder-class"></a>Classe CFontHolder

Implementa a propriedade de fonte de estoque e encapsula a funcionalidade de um objeto de fonte do Windows e o `IFont` interface.

## <a name="syntax"></a>Sintaxe

```
class CFontHolder
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontHolder::CFontHolder](#cfontholder)|Constrói um objeto `CFontHolder`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontHolder::GetDisplayString](#getdisplaystring)|Recupera a cadeia de caracteres exibida no navegador de propriedade de um contêiner.|
|[CFontHolder::GetFontDispatch](#getfontdispatch)|Retorna a fonte `IDispatch` interface.|
|[CFontHolder::GetFontHandle](#getfonthandle)|Retorna um identificador para uma fonte de Windows.|
|[CFontHolder::InitializeFont](#initializefont)|Inicializa um `CFontHolder` objeto.|
|[CFontHolder::QueryTextMetrics](#querytextmetrics)|Recupera informações para a fonte relacionada.|
|[CFontHolder::ReleaseFont](#releasefont)|Desconecta o `CFontHolder` de objeto de `IFont` e `IFontNotification` interfaces.|
|[CFontHolder::Select](#select)|Seleciona um recurso de fonte em um contexto de dispositivo.|
|[CFontHolder::SetFont](#setfont)|Conecta-se a `CFontHolder` do objeto para um `IFont` interface.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFontHolder::m_pFont](#m_pfont)|Um ponteiro para o `CFontHolder` do objeto `IFont` interface.|

## <a name="remarks"></a>Comentários

`CFontHolder` não tem uma classe base.

Use essa classe para implementar propriedades de fonte personalizado para seu controle. Para obter informações sobre como criar essas propriedades, consulte o artigo [controles ActiveX: usando fontes](../../mfc/mfc-activex-controls-using-fonts.md).

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
Ponteiro para a fonte `IPropertyNotifySink` interface.

### <a name="remarks"></a>Comentários

Você deve chamar `InitializeFont` para inicializar o objeto resultante antes de usá-lo.

##  <a name="getdisplaystring"></a>  CFontHolder::GetDisplayString

Recupera uma cadeia de caracteres que pode ser exibida no navegador de propriedade de um contêiner.

```
BOOL GetDisplayString(CString& strValue);
```

### <a name="parameters"></a>Parâmetros

*strValue*<br/>
Referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é armazenar a cadeia de caracteres de exibição.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a cadeia de caracteres é recuperada com êxito. Caso contrário, 0.

##  <a name="getfontdispatch"></a>  CFontHolder::GetFontDispatch

Chame essa função para recuperar um ponteiro para a interface de expedição da fonte.

```
LPFONTDISP GetFontDispatch();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CFontHolder` do objeto `IFontDisp` interface. Observe que a função que chama `GetFontDispatch` deve chamar `IUnknown::Release` nesse ponteiro de interface quando termina de usá-lo.

### <a name="remarks"></a>Comentários

Chame `InitializeFont` antes de chamar `GetFontDispatch`.

##  <a name="getfonthandle"></a>  CFontHolder::GetFontHandle

Chame essa função para obter um identificador para uma fonte de Windows.

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
Altura, em unidades de MM_HIMETRIC do controle.

### <a name="return-value"></a>Valor de retorno

Um identificador para o objeto de fonte; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

A proporção da *cyLogical* e *cyHimetric* é usada para calcular o tamanho de exibição correta, em unidades lógicas, para o tamanho da fonte ponto expressada em unidades de MM_HIMETRIC:

Exibir tamanho = ( *cyLogical* / *cyHimetric*) X tamanho da fonte

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
Ponteiro para uma estrutura de descrição da fonte ( [FONTDESC](/windows/desktop/api/olectl/ns-olectl-tagfontdesc)) que especifica as características da fonte.

*pFontDispAmbient*<br/>
Ponteiro para a propriedade da fonte de ambiente do contêiner.

### <a name="remarks"></a>Comentários

Se *pFontDispAmbient* não for nulo, o `CFontHolder` objeto está conectado a um clone do `IFont` interface usada pela propriedade da fonte de ambiente do contêiner.

Se *pFontDispAmbient* é nulo, uma nova fonte de objeto é criado a partir da descrição da fonte apontada por *pFontDesc* ou, se *pFontDesc* for NULL, padrão Descrição.

Chame essa função após construir um `CFontHolder` objeto.

##  <a name="m_pfont"></a>  CFontHolder::m_pFont

Um ponteiro para o `CFontHolder` do objeto `IFont` interface.

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
Um ponteiro para um [TEXTMETRIC](/windows/desktop/api/wingdi/ns-wingdi-tagtextmetrica) estrutura que receberá as informações.

##  <a name="releasefont"></a>  CFontHolder::ReleaseFont

Essa função se desconecta o `CFontHolder` do objeto de seu `IFont` interface.

```
void ReleaseFont();
```

##  <a name="select"></a>  CFontHolder::Select

Chame essa função para selecionar a fonte do seu controle no contexto de dispositivo especificado.

```
CFont* Select(
    CDC* pDC,
    long cyLogical,
    long cyHimetric);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Contexto de dispositivo no qual a fonte é selecionada.

*cyLogical*<br/>
Altura, em unidades lógicas, do retângulo no qual o controle é desenhado.

*cyHimetric*<br/>
Altura, em unidades de MM_HIMETRIC do controle.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a fonte que está sendo substituído.

### <a name="remarks"></a>Comentários

Ver [GetFontHandle](#getfonthandle) para uma discussão sobre o *cyLogical* e *cyHimetric* parâmetros.

##  <a name="setfont"></a>  CFontHolder::SetFont

Libera qualquer fonte existente e conecta-se a `CFontHolder` do objeto para um `IFont` interface.

```
void SetFont(LPFONT pNewFont);
```

### <a name="parameters"></a>Parâmetros

*pNewFont*<br/>
Ponteiro para o novo `IFont` interface.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPropExchange](../../mfc/reference/cpropexchange-class.md)
