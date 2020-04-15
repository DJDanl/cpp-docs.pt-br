---
title: Classe CRgn
ms.date: 11/04/2016
f1_keywords:
- CRgn
- AFXWIN/CRgn
- AFXWIN/CRgn::CRgn
- AFXWIN/CRgn::CombineRgn
- AFXWIN/CRgn::CopyRgn
- AFXWIN/CRgn::CreateEllipticRgn
- AFXWIN/CRgn::CreateEllipticRgnIndirect
- AFXWIN/CRgn::CreateFromData
- AFXWIN/CRgn::CreateFromPath
- AFXWIN/CRgn::CreatePolygonRgn
- AFXWIN/CRgn::CreatePolyPolygonRgn
- AFXWIN/CRgn::CreateRectRgn
- AFXWIN/CRgn::CreateRectRgnIndirect
- AFXWIN/CRgn::CreateRoundRectRgn
- AFXWIN/CRgn::EqualRgn
- AFXWIN/CRgn::FromHandle
- AFXWIN/CRgn::GetRegionData
- AFXWIN/CRgn::GetRgnBox
- AFXWIN/CRgn::OffsetRgn
- AFXWIN/CRgn::PtInRegion
- AFXWIN/CRgn::RectInRegion
- AFXWIN/CRgn::SetRectRgn
helpviewer_keywords:
- CRgn [MFC], CRgn
- CRgn [MFC], CombineRgn
- CRgn [MFC], CopyRgn
- CRgn [MFC], CreateEllipticRgn
- CRgn [MFC], CreateEllipticRgnIndirect
- CRgn [MFC], CreateFromData
- CRgn [MFC], CreateFromPath
- CRgn [MFC], CreatePolygonRgn
- CRgn [MFC], CreatePolyPolygonRgn
- CRgn [MFC], CreateRectRgn
- CRgn [MFC], CreateRectRgnIndirect
- CRgn [MFC], CreateRoundRectRgn
- CRgn [MFC], EqualRgn
- CRgn [MFC], FromHandle
- CRgn [MFC], GetRegionData
- CRgn [MFC], GetRgnBox
- CRgn [MFC], OffsetRgn
- CRgn [MFC], PtInRegion
- CRgn [MFC], RectInRegion
- CRgn [MFC], SetRectRgn
ms.assetid: d904da84-76aa-481e-8780-b09485f49e64
ms.openlocfilehash: 72ab4027880285a3c4cd24d586e163e1e01b98f2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368299"
---
# <a name="crgn-class"></a>Classe CRgn

Encapsula uma região gDI (Windows graphics device interface).

## <a name="syntax"></a>Sintaxe

```
class CRgn : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRgn::CRgn](#crgn)|Constrói um objeto `CRgn`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRgn::CombineRgn](#combinergn)|Define `CRgn` um objeto de modo que seja equivalente `CRgn` à união de dois objetos especificados.|
|[CRgn::CopyRgn](#copyrgn)|Define `CRgn` um objeto de modo que seja `CRgn` uma cópia de um objeto especificado.|
|[CRgn::CreateEllipticRgn](#createellipticrgn)|Inicializa um `CRgn` objeto com uma região elíptica.|
|[CRgn::CreateEllipticRgnIndirect](#createellipticrgnindirect)|Inicializa um `CRgn` objeto com uma região elíptica definida por uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect)|
|[CRgn::CreateFromData](#createfromdata)|Cria uma região a partir da determinada região e dados de transformação.|
|[CRgn::CreateFromPath](#createfrompath)|Cria uma região a partir do caminho selecionado no determinado contexto do dispositivo.|
|[CRgn::CreatePolygonRgn](#createpolygonrgn)|Inicializa um `CRgn` objeto com uma região poligonal. O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice para o primeiro.|
|[CRgn::CreatePolyPolygonRgn](#createpolypolygonrgn)|Inicializa um `CRgn` objeto com uma região que consiste em uma série de polígonos fechados. Os polígonos podem ser desarticulados, ou podem se sobrepor.|
|[CRgn::CreateRectRgn](#createrectrgn)|Inicializa um `CRgn` objeto com uma região retangular.|
|[CRgn::CreateRectRgnIndirect](#createrectrgnindirect)|Inicializa um `CRgn` objeto com uma região retangular definida por uma tructura [RECT.](/windows/win32/api/windef/ns-windef-rect)|
|[CRgn::CreateRoundRectRgn](#createroundrectrgn)|Inicializa um `CRgn` objeto com uma região retangular com cantos arredondados.|
|[CRgn::EqualRgn](#equalrgn)|Verifica `CRgn` dois objetos para determinar se são equivalentes.|
|[CRgn::FromHandle](#fromhandle)|Retorna um ponteiro `CRgn` para um objeto quando dado uma alça a uma região do Windows.|
|[CRgn::GetRegionData](#getregiondata)|Preenche o buffer especificado com dados descrevendo a determinada região.|
|[CRgn::GetRgnBox](#getrgnbox)|Recupera as coordenadas do retângulo delimitador de um `CRgn` objeto.|
|[CRgn::OffsetRgn](#offsetrgn)|Move `CRgn` um objeto pelas compensações especificadas.|
|[CRgn::PtInRegion](#ptinregion)|Determina se um ponto especificado está na região.|
|[CRgn::RectInRegion](#rectinregion)|Determina se qualquer parte de um retângulo especificado está dentro dos limites da região.|
|[CRgn::SetRectRgn](#setrectrgn)|Define `CRgn` o objeto para a região retangular especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRgn::operador HRGN](#operator_hrgn)|Retorna a alça do `CRgn` Windows contida no objeto.|

## <a name="remarks"></a>Comentários

Uma região é uma área elíptica ou poligonal dentro de uma janela. Para usar regiões, você usa as `CRgn` funções de classe membro `CDC`com as funções de recorte definidas como membros de classe .

As funções `CRgn` do membro de criar, alterar e recuperar informações sobre o objeto da região para o qual são chamados.

Para obter mais `CRgn`informações sobre como usar, consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cgdiobject](../../mfc/reference/cgdiobject-class.md)

`CRgn`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="crgncombinergn"></a><a name="combinergn"></a>CRgn::CombineRgn

Cria uma nova região de GDI combinando duas regiões existentes.

```
int CombineRgn(
    CRgn* pRgn1,
    CRgn* pRgn2,
    int nCombineMode);
```

### <a name="parameters"></a>Parâmetros

*pRgn1*<br/>
Identifica uma região existente.

*pRgn2*<br/>
Identifica uma região existente.

*nCombineMode*<br/>
Especifica a operação a ser realizada ao combinar as duas regiões de origem. Pode ser qualquer um dos seguintes valores:

- RGN_AND Utiliza áreas sobrepostas de ambas as regiões (cruzamento).

- RGN_COPY Cria uma cópia da região 1 (identificada por *pRgn1*).

- RGN_DIFF Cria uma região constituída pelas áreas da região 1 (identificadas por *pRgn1*) que não fazem parte da região 2 (identificada por *pRgn2*).

- RGN_OR Combina ambas as regiões em sua totalidade (união).

- RGN_XOR Combina ambas as regiões, mas remove áreas sobrepostas.

### <a name="return-value"></a>Valor retornado

Especifica o tipo da região resultante. Pode ser um dos seguintes valores:

- REGIÃO COMPLEXA Nova região tem fronteiras sobrepostas.

- ERRO Nenhuma nova região criada.

- NULLREGION Nova região está vazia.

- REGIÃO SIMPLES A nova região não tem fronteiras sobrepostas.

### <a name="remarks"></a>Comentários

As regiões são combinadas conforme especificado por *nCombineMode*.

As duas regiões especificadas são combinadas e a alça `CRgn` da região resultante é armazenada no objeto. Assim, qualquer região armazenada `CRgn` no objeto é substituída pela região combinada.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Use [copyRgn](#copyrgn) para simplesmente copiar uma região para outra região.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#144](../../mfc/codesnippet/cpp/crgn-class_1.cpp)]

## <a name="crgncopyrgn"></a><a name="copyrgn"></a>CRgn::CopyRgn

Copia a região definida por *pRgnSrc* no `CRgn` objeto.

```
int CopyRgn(CRgn* pRgnSrc);
```

### <a name="parameters"></a>Parâmetros

*pRgnSrc*<br/>
Identifica uma região existente.

### <a name="return-value"></a>Valor retornado

Especifica o tipo da região resultante. Pode ser um dos seguintes valores:

- REGIÃO COMPLEXA Nova região tem fronteiras sobrepostas.

- ERRO Nenhuma nova região criada.

- NULLREGION Nova região está vazia.

- REGIÃO SIMPLES A nova região não tem fronteiras sobrepostas.

### <a name="remarks"></a>Comentários

A nova região substitui a região `CRgn` anteriormente armazenada no objeto. Esta função é um caso especial da função membro [CombineRgn.](#combinergn)

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRgn::CreateEllipticRgn](#createellipticrgn).

## <a name="crgncreateellipticrgn"></a><a name="createellipticrgn"></a>CRgn::CreateEllipticRgn

Cria uma região elíptica.

```
BOOL CreateEllipticRgn(
    int x1,
    int y1,
    int x2,
    int y2);
```

### <a name="parameters"></a>Parâmetros

*x1*<br/>
Especifica a coordenada x lógica do canto superior esquerdo do retângulo delimitador da elipse.

*y1*<br/>
Especifica a coordenada lógica y do canto superior esquerdo do retângulo delimitador da elipse.

*x2*<br/>
Especifica a coordenada x lógica do canto inferior direito do retângulo delimitador da elipse.

*y2*<br/>
Especifica a coordenada lógica y do canto inferior direito do retângulo delimitador da elipse.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A região é definida pelo retângulo delimitador especificado por *x1*, *y1*, *x2*e *y2*. A região está `CRgn` armazenada no objeto.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando ele terminar usando uma região `CreateEllipticRgn` criada com a função, um aplicativo deve `DeleteObject` selecionar a região fora do contexto do dispositivo e usar a função para removê-la.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#145](../../mfc/codesnippet/cpp/crgn-class_2.cpp)]

## <a name="crgncreateellipticrgnindirect"></a><a name="createellipticrgnindirect"></a>CRgn::CreateEllipticRgnIndirect

Cria uma região elíptica.

```
BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` uma `CRect` estrutura ou um objeto que contém as coordenadas lógicas dos cantos superior-esquerdo e inferior direito do retângulo delimitador da elipse.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A região é definida pela estrutura ou objeto apontado por `CRgn` *lpRect* e é armazenado no objeto.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando ele terminar usando uma região `CreateEllipticRgnIndirect` criada com a função, um aplicativo deve `DeleteObject` selecionar a região fora do contexto do dispositivo e usar a função para removê-la.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRgn::CreateRectRgnIndirect](#createrectrgnindirect).

## <a name="crgncreatefromdata"></a><a name="createfromdata"></a>CRgn::CreateFromData

Cria uma região a partir da determinada região e dados de transformação.

```
BOOL CreateFromData(
    const XFORM* lpXForm,
    int nCount,
    const RGNDATA* pRgnData);
```

### <a name="parameters"></a>Parâmetros

*lpXForm*<br/>
Aponta para uma estrutura [ata XFORM](/windows/win32/api/wingdi/ns-wingdi-xform)que define a transformação a ser realizada na região. Se este ponteiro for NULL, a transformação de identidade será usada.

*Ncount*<br/>
Especifica o número de bytes apontados por *pRgnData*.

*pRgnData*<br/>
Aponta para uma estrutura de dados [RGNDATA](/windows/win32/api/wingdi/ns-wingdi-rgndata) que contém os dados da região.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo pode recuperar dados para `CRgn::GetRegionData` uma região ligando para a função.

## <a name="crgncreatefrompath"></a><a name="createfrompath"></a>CRgn::CreateFromPath

Cria uma região a partir do caminho selecionado no determinado contexto do dispositivo.

```
BOOL CreateFromPath(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Identifica um contexto de dispositivo que contém um caminho fechado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O contexto do dispositivo identificado pelo parâmetro *pDC* deve conter um caminho fechado. Depois `CreateFromPath` de converter um caminho em uma região, o Windows descarta o caminho fechado do contexto do dispositivo.

## <a name="crgncreatepolygonrgn"></a><a name="createpolygonrgn"></a>CRgn::CreatePolygonRgn

Cria uma região poligonal.

```
BOOL CreatePolygonRgn(
    LPPOINT lpPoints,
    int nCount,
    int nMode);
```

### <a name="parameters"></a>Parâmetros

*Lppoints*<br/>
Aponta para uma `POINT` matriz de `CPoint` estruturas ou uma matriz de objetos. Cada estrutura especifica a coordenada x e a coordenada y de um vértice do polígono. A `POINT` estrutura tem a seguinte forma:

```cpp
typedef struct tagPOINT {
    int x;
    int y;
} POINT;
```

*Ncount*<br/>
Especifica o número `POINT` de `CPoint` estruturas ou objetos na matriz apontada por *lpPoints*.

*nMode*<br/>
Especifica o modo de enchimento para a região. Este parâmetro pode ser ALTERNATIVO ou SINUOSO.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice para o primeiro. A região resultante é `CRgn` armazenada no objeto.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando o modo de enchimento do polígono é ALTERNATIVO, o sistema preenche a área entre lados de polígono numerados ímpares e numerados em cada linha de varredura. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e o quarto lado, e assim por diante.

Quando o modo de enchimento do polígono é WINDING, o sistema usa a direção na qual uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado no sentido horário ou no sentido anti-horário. Sempre que uma linha imaginária desenhada de uma área fechada para o exterior de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é decretada. A área é preenchida se a contagem não for zero quando a linha atingir o exterior da figura.

Quando um aplicativo tiver terminado usando `CreatePolygonRgn` uma região criada com a função, ele `DeleteObject` deve selecionar a região fora do contexto do dispositivo e usar a função para removê-la.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#146](../../mfc/codesnippet/cpp/crgn-class_3.cpp)]

## <a name="crgncreatepolypolygonrgn"></a><a name="createpolypolygonrgn"></a>CRgn::CreatePolyPolygonRgn

Cria uma região que consiste em uma série de polígonos fechados.

```
BOOL CreatePolyPolygonRgn(
    LPPOINT lpPoints,
    LPINT lpPolyCounts,
    int nCount,
    int nPolyFillMode);
```

### <a name="parameters"></a>Parâmetros

*Lppoints*<br/>
Aponta para uma `POINT` matriz de `CPoint` estruturas ou uma matriz de objetos que define os vértices dos polígonos. Cada polígono deve ser explicitamente fechado porque o sistema não os fecha automaticamente. Os polígonos são especificados consecutivamente. A `POINT` estrutura tem a seguinte forma:

```cpp
typedef struct tagPOINT {
    int x;
    int y;
} POINT;
```

*lpPolyCounts*<br/>
Aponta para uma matriz de inteiros. O primeiro inteiro especifica o número de vértices no primeiro polígono na matriz *lpPoints,* o segundo inteiro especifica o número de vértices no segundo polígono, e assim por diante.

*Ncount*<br/>
Especifica o número total de inteiros na matriz *lpPolyCounts.*

*nPolyFillMode*<br/>
Especifica o modo de enchimento do polígono. Este valor pode ser ALTERNATIVO ou ENROLAMENTO.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A região resultante é `CRgn` armazenada no objeto.

Os polígonos podem ser desarticulados, ou podem se sobrepor.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando o modo de enchimento do polígono é ALTERNATIVO, o sistema preenche a área entre lados de polígono numerados ímpares e numerados em cada linha de varredura. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e o quarto lado, e assim por diante.

Quando o modo de enchimento do polígono é WINDING, o sistema usa a direção na qual uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado no sentido horário ou no sentido anti-horário. Sempre que uma linha imaginária desenhada de uma área fechada para o exterior de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é decretada. A área é preenchida se a contagem não for zero quando a linha atingir o exterior da figura.

Quando um aplicativo tiver terminado usando `CreatePolyPolygonRgn` uma região criada com a função, ele deve selecionar a região fora do contexto do dispositivo e usar a função membro [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) para removê-la.

## <a name="crgncreaterectrgn"></a><a name="createrectrgn"></a>CRgn::CreateRectRgn

Cria uma região retangular armazenada `CRgn` no objeto.

```
BOOL CreateRectRgn(
    int x1,
    int y1,
    int x2,
    int y2);
```

### <a name="parameters"></a>Parâmetros

*x1*<br/>
Especifica a coordenada x lógica do canto superior esquerdo da região.

*y1*<br/>
Especifica a coordenada lógica y do canto superior esquerdo da região.

*x2*<br/>
Especifica a coordenada x lógica do canto inferior direito da região.

*y2*<br/>
Especifica a coordenada lógica y do canto inferior direito da região.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando ele tiver terminado usando `CreateRectRgn`uma região criada por , um aplicativo deve usar a função de membro [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) para remover a região.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#147](../../mfc/codesnippet/cpp/crgn-class_4.cpp)]

Para obter um exemplo adicional, consulte [CRgn::CombineRgn](#combinergn).

## <a name="crgncreaterectrgnindirect"></a><a name="createrectrgnindirect"></a>CRgn::CreateRectRgnIndirect

Cria uma região retangular armazenada `CRgn` no objeto.

```
BOOL CreateRectRgnIndirect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` uma `CRect` estrutura ou objeto que contém as coordenadas lógicas dos cantos superior esquerdo e inferior direito da região. A `RECT` estrutura tem a seguinte forma:

```cpp
typedef struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
} RECT;
```

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando ele tiver terminado usando `CreateRectRgnIndirect`uma região criada por , um aplicativo deve usar a função de membro [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) para remover a região.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#148](../../mfc/codesnippet/cpp/crgn-class_5.cpp)]

## <a name="crgncreateroundrectrgn"></a><a name="createroundrectrgn"></a>CRgn::CreateRoundRectRgn

Cria uma região retangular com cantos arredondados que são armazenados no `CRgn` objeto.

```
BOOL CreateRoundRectRgn(
    int x1,
    int y1,
    int x2,
    int y2,
    int x3,
    int y3);
```

### <a name="parameters"></a>Parâmetros

*x1*<br/>
Especifica a coordenada x lógica do canto superior esquerdo da região.

*y1*<br/>
Especifica a coordenada lógica y do canto superior esquerdo da região.

*x2*<br/>
Especifica a coordenada x lógica do canto inferior direito da região.

*y2*<br/>
Especifica a coordenada lógica y do canto inferior direito da região.

*x3*<br/>
Especifica a largura da elipse usada para criar os cantos arredondados.

*y3*<br/>
Especifica a altura da elipse usada para criar os cantos arredondados.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando um aplicativo tiver terminado usando `CreateRoundRectRgn` uma região criada com a função, ele deve selecionar a região fora do contexto do dispositivo e usar a função membro [CGDIObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) para removê-la.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#149](../../mfc/codesnippet/cpp/crgn-class_6.cpp)]

## <a name="crgncrgn"></a><a name="crgn"></a>CRgn::CRgn

Constrói um objeto `CRgn`.

```
CRgn();
```

### <a name="remarks"></a>Comentários

O `m_hObject` membro de dados não contém uma região De GDI do Windows `CRgn` válida até que o objeto seja inicializado com uma ou mais das funções do outro membro.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRgn::CreateRoundRectRgn](#createroundrectrgn).

## <a name="crgnequalrgn"></a><a name="equalrgn"></a>CRgn::EqualRgn

Determina se a determinada região é equivalente `CRgn` à região armazenada no objeto.

```
BOOL EqualRgn(CRgn* pRgn) const;
```

### <a name="parameters"></a>Parâmetros

*Prgn*<br/>
Identifica uma região.

### <a name="return-value"></a>Valor retornado

Não zero se as duas regiões forem equivalentes; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#150](../../mfc/codesnippet/cpp/crgn-class_7.cpp)]

## <a name="crgnfromhandle"></a><a name="fromhandle"></a>CRgn::FromHandle

Retorna um ponteiro `CRgn` para um objeto quando dado uma alça a uma região do Windows.

```
static CRgn* PASCAL FromHandle(HRGN hRgn);
```

### <a name="parameters"></a>Parâmetros

*Hrgn*<br/>
Especifica uma alça para uma região do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CRgn`. Se a função não foi bem sucedida, o valor de retorno é NULO.

### <a name="remarks"></a>Comentários

Se `CRgn` um objeto ainda não estiver conectado `CRgn` à alça, um objeto temporário será criado e anexado. Este `CRgn` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos gráficos temporários são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de uma mensagem de janela.

## <a name="crgngetregiondata"></a><a name="getregiondata"></a>CRgn::GetRegionData

Preenche o buffer especificado com dados descrevendo a região.

```
int GetRegionData(
    LPRGNDATA lpRgnData,
    int nCount) const;
```

### <a name="parameters"></a>Parâmetros

*lpRgnData*<br/>
Aponta para uma estrutura de dados [RGNDATA](/windows/win32/api/wingdi/ns-wingdi-rgndata) que recebe as informações. Se esse parâmetro for NULO, o valor de retorno contém o número de bytes necessários para os dados da região.

*Ncount*<br/>
Especifica o tamanho, em bytes, do buffer *lpRgnData.*

### <a name="return-value"></a>Valor retornado

Se a função for bem-sucedida e *nCount* especificar um número adequado de bytes, o valor de retorno será sempre *nCount*. Se a função falhar, ou se *nCount* especificar um número inferior ao adequado de bytes, o valor de retorno será 0 (erro).

### <a name="remarks"></a>Comentários

Esses dados incluem as dimensões dos retângulos que compõem a região. Esta função é usada `CRgn::CreateFromData` em conjunto com a função.

## <a name="crgngetrgnbox"></a><a name="getrgnbox"></a>CRgn::GetRgnBox

Recupera as coordenadas do retângulo delimitador do `CRgn` objeto.

```
int GetRgnBox(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` uma `CRect` estrutura ou objeto para receber as coordenadas do retângulo delimitador. A `RECT` estrutura tem a seguinte forma:

`typedef struct tagRECT {`

`int left;`

`int top;`

`int right;`

`int bottom;`

`} RECT;`

### <a name="return-value"></a>Valor retornado

Especifica o tipo da região. Pode ser qualquer um dos seguintes valores:

- REGIÃO COMPLEXA A região tem fronteiras sobrepostas.

- NULLREGION Região está vazia.

- O `CRgn` objeto ERROR não especifica uma região válida.

- REGIÃO SIMPLES Região não tem fronteiras sobrepostas.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRgn::CreatePolygonRgn](#createpolygonrgn).

## <a name="crgnoffsetrgn"></a><a name="offsetrgn"></a>CRgn::OffsetRgn

Move a região `CRgn` armazenada no objeto pelas compensações especificadas.

```
int OffsetRgn(
    int x,
    int y);

int OffsetRgn(POINT point);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o número de unidades para mover-se para a esquerda ou para a direita.

*Y*<br/>
Especifica o número de unidades para mover para cima ou para baixo.

*Ponto*<br/>
A coordenada x do *ponto* especifica o número de unidades para mover para a esquerda ou para a direita. A coordenada y do *ponto* especifica o número de unidades para mover para cima ou para baixo. O parâmetro de *ponto* `POINT` pode ser `CPoint` uma estrutura ou um objeto.

### <a name="return-value"></a>Valor retornado

O tipo da nova região. Pode ser qualquer um dos seguintes valores:

- REGIÃO COMPLEXA A região tem fronteiras sobrepostas.

- ERRO A alça da região não é válida.

- NULLREGION Região está vazia.

- REGIÃO SIMPLES Região não tem fronteiras sobrepostas.

### <a name="remarks"></a>Comentários

A função move as unidades da região *x* ao longo do eixo x e *unidades y* ao longo do eixo y.

Os valores de coordenadas de uma região devem ser menores ou iguais a 32.767 e maiores ou iguais a -32.768. Os parâmetros *x* e *y* devem ser cuidadosamente escolhidos para evitar coordenadas de região inválidas.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRgn::CreateEllipticRgn](#createellipticrgn).

## <a name="crgnoperator-hrgn"></a><a name="operator_hrgn"></a>CRgn::operador HRGN

Use este operador para obter a alça `CRgn` Windows GDI anexada do objeto.

```
operator HRGN() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, uma alça para `CRgn` o objeto GDI do Windows representado pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este operador é um operador de fundição, que suporta o uso direto de um objeto HRGN.

Para obter mais informações sobre o uso de objetos gráficos, consulte o artigo [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no SDK do Windows.

## <a name="crgnptinregion"></a><a name="ptinregion"></a>CRgn::PtInRegion

Verifica se o ponto dado por *x* e `CRgn` *y* está na região armazenada no objeto.

```
BOOL PtInRegion(
    int x,
    int y) const;

BOOL PtInRegion(POINT point) const;
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica a coordenada x lógica do ponto a ser testado.

*Y*<br/>
Especifica a coordenada lógica y do ponto a ser testado.

*Ponto*<br/>
As coordenadas x e y de *ponto* especificam as coordenadas x e y do ponto para testar o valor de. O parâmetro *de ponto* `POINT` pode ser `CPoint` uma estrutura ou um objeto.

### <a name="return-value"></a>Valor retornado

Não zero se o ponto estiver na região; caso contrário, 0.

## <a name="crgnrectinregion"></a><a name="rectinregion"></a>CRgn::RectInRegion

Determina se qualquer parte do retângulo especificado pelo *lpRect* está dentro `CRgn` dos limites da região armazenada no objeto.

```
BOOL RectInRegion(LPCRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` uma `CRect` estrutura ou objeto. A `RECT` estrutura tem a seguinte forma:

```cpp
typedef struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
} RECT;
```

### <a name="return-value"></a>Valor retornado

Não zero se qualquer parte do retângulo especificado estiver dentro dos limites da região; caso contrário, 0.

## <a name="crgnsetrectrgn"></a><a name="setrectrgn"></a>CRgn::SetRectRgn

Cria uma região retangular.

```
void SetRectRgn(
    int x1,
    int y1,
    int x2,
    int y2);

void SetRectRgn(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*x1*<br/>
Especifica a coordenada x do canto superior esquerdo da região retangular.

*y1*<br/>
Especifica a coordenada y do canto superior esquerdo da região retangular.

*x2*<br/>
Especifica a coordenada x do canto inferior direito da região retangular.

*y2*<br/>
Especifica a coordenada y do canto inferior direito da região retangular.

*Lprect*<br/>
Especifica a região retangular. Pode ser um ponteiro `RECT` para `CRect` uma estrutura ou um objeto.

### <a name="remarks"></a>Comentários

Ao contrário [do CreateRectRgn,](#createrectrgn)no entanto, ele não aloca nenhuma memória adicional do heap de aplicativo local do Windows. Em vez disso, usa o espaço alocado `CRgn` para a região armazenada no objeto. Isso significa `CRgn` que o objeto já deve ter sido `SetRectRgn`inicializado com uma região do Windows válida antes de chamar . Os pontos dados por *x1*, *y1*, *x2*e *y2* especificam o tamanho mínimo do espaço alocado.

Use esta função `CreateRectRgn` em vez da função de membro para evitar chamadas para o gerenciador de memória local.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
