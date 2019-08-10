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
ms.openlocfilehash: 66721f34a8ac2b6dac6addcfa04a88b46a37ee60
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68916823"
---
# <a name="crgn-class"></a>Classe CRgn

Encapsula uma região da interface de dispositivo de gráficos do Windows (GDI).

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
|[CRgn::CombineRgn](#combinergn)|Define um `CRgn` objeto para que ele seja equivalente à União de dois objetos especificados `CRgn` .|
|[CRgn::CopyRgn](#copyrgn)|Define um `CRgn` objeto para que ele seja uma cópia de um objeto `CRgn` especificado.|
|[CRgn::CreateEllipticRgn](#createellipticrgn)|Inicializa um `CRgn` objeto com uma região elíptica.|
|[CRgn::CreateEllipticRgnIndirect](#createellipticrgnindirect)|Inicializa um `CRgn` objeto com uma região elíptica definida por uma estrutura [Rect](/windows/desktop/api/windef/ns-windef-tagrect) .|
|[CRgn::CreateFromData](#createfromdata)|Cria uma região a partir da região e dos dados de transformação fornecidos.|
|[CRgn::CreateFromPath](#createfrompath)|Cria uma região a partir do caminho selecionado no contexto de dispositivo fornecido.|
|[CRgn::CreatePolygonRgn](#createpolygonrgn)|Inicializa um `CRgn` objeto com uma região poligonal. O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice para o primeiro.|
|[CRgn::CreatePolyPolygonRgn](#createpolypolygonrgn)|Inicializa um `CRgn` objeto com uma região que consiste em uma série de polígonos fechados. Os polígonos podem ser não contíguos ou podem se sobrepor.|
|[CRgn::CreateRectRgn](#createrectrgn)|Inicializa um `CRgn` objeto com uma região retangular.|
|[CRgn::CreateRectRgnIndirect](#createrectrgnindirect)|Inicializa um `CRgn` objeto com uma região retangular definida por uma estrutura [Rect](/windows/desktop/api/windef/ns-windef-tagrect) .|
|[CRgn::CreateRoundRectRgn](#createroundrectrgn)|Inicializa um `CRgn` objeto com uma região retangular com cantos arredondados.|
|[CRgn::EqualRgn](#equalrgn)|Verifica dois `CRgn` objetos para determinar se eles são equivalentes.|
|[CRgn:: FromHandle](#fromhandle)|Retorna um ponteiro para um `CRgn` objeto quando um identificador é fornecido a uma região do Windows.|
|[CRgn::GetRegionData](#getregiondata)|Preenche o buffer especificado com os dados que descrevem a região especificada.|
|[CRgn::GetRgnBox](#getrgnbox)|Recupera as coordenadas do retângulo delimitador de um `CRgn` objeto.|
|[CRgn::OffsetRgn](#offsetrgn)|Move um `CRgn` objeto pelos deslocamentos especificados.|
|[CRgn::PtInRegion](#ptinregion)|Determina se um ponto especificado está na região.|
|[CRgn::RectInRegion](#rectinregion)|Determina se qualquer parte de um retângulo especificado está dentro dos limites da região.|
|[CRgn::SetRectRgn](#setrectrgn)|Define o `CRgn` objeto para a região retangular especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CRgn:: Operator HRGN](#operator_hrgn)|Retorna o identificador do Windows contido no `CRgn` objeto.|

## <a name="remarks"></a>Comentários

Uma região é uma área elíptica ou poligonal dentro de uma janela. Para usar regiões, você usa as funções de membro da `CRgn` classe com as funções de recorte definidas como membros `CDC`da classe.

As funções de membro `CRgn` de criar, alterar e recuperar informações sobre o objeto de região para o qual elas são chamadas.

Para obter mais informações sobre `CRgn`como usar o, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CRgn`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="combinergn"></a>  CRgn::CombineRgn

Cria uma nova região GDI combinando duas regiões existentes.

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
Especifica a operação a ser executada ao combinar as duas regiões de origem. Pode ser qualquer um dos seguintes valores:

- RGN_AND usa áreas sobrepostas de ambas as regiões (interseção).

- RGN_COPY cria uma cópia da região 1 (identificada por *pRgn1*).

- O RGN_DIFF cria uma região que consiste nas áreas da região 1 (identificadas por *pRgn1*) que não fazem parte da região 2 (identificada por *pRgn2*).

- O RGN_OR Combina ambas as regiões em sua totalidade (Union).

- O RGN_XOR combina as duas regiões, mas remove as áreas sobrepostas.

### <a name="return-value"></a>Valor de retorno

Especifica o tipo da região resultante. Pode ser um dos seguintes valores:

- COMPLEXREGION nova região tem bordas sobrepostas.

- ERRO nenhuma nova região criada.

- NULLREGION nova região está vazia.

- SIMPLEREGION Nova região não tem bordas sobrepostas.

### <a name="remarks"></a>Comentários

As regiões são combinadas conforme especificado por *nCombineMode*.

As duas regiões especificadas são combinadas e o identificador de região resultante é armazenado no `CRgn` objeto. Portanto, qualquer região armazenada no `CRgn` objeto é substituída pela região combinada.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Use [CopyRgn](#copyrgn) para simplesmente copiar uma região em outra região.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#144](../../mfc/codesnippet/cpp/crgn-class_1.cpp)]

##  <a name="copyrgn"></a>  CRgn::CopyRgn

Copia a região definida por *pRgnSrc* no `CRgn` objeto.

```
int CopyRgn(CRgn* pRgnSrc);
```

### <a name="parameters"></a>Parâmetros

*pRgnSrc*<br/>
Identifica uma região existente.

### <a name="return-value"></a>Valor de retorno

Especifica o tipo da região resultante. Pode ser um dos seguintes valores:

- COMPLEXREGION nova região tem bordas sobrepostas.

- ERRO nenhuma nova região criada.

- NULLREGION nova região está vazia.

- SIMPLEREGION Nova região não tem bordas sobrepostas.

### <a name="remarks"></a>Comentários

A nova região substitui a região armazenada anteriormente no `CRgn` objeto. Essa função é um caso especial da função membro [CombineRgn](#combinergn) .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CRgn:: CreateEllipticRgn](#createellipticrgn).

##  <a name="createellipticrgn"></a>  CRgn::CreateEllipticRgn

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
Especifica a coordenada y lógica do canto superior esquerdo do retângulo delimitador da elipse.

*x2*<br/>
Especifica a coordenada x lógica do canto inferior direito do retângulo delimitador da elipse.

*Y2*<br/>
Especifica a coordenada y lógica do canto inferior direito do retângulo delimitador da elipse.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A região é definida pelo retângulo delimitador especificado por *X1*, *Y1*, *X2*e *Y2*. A região é armazenada no `CRgn` objeto.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando terminar de usar uma região criada com a `CreateEllipticRgn` função, um aplicativo deverá selecionar a região fora do contexto do dispositivo e usar a `DeleteObject` função para removê-la.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#145](../../mfc/codesnippet/cpp/crgn-class_2.cpp)]

##  <a name="createellipticrgnindirect"></a>  CRgn::CreateEllipticRgnIndirect

Cria uma região elíptica.

```
BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma `RECT` estrutura ou um `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerdo e inferior direito do retângulo delimitador da elipse.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A região é definida pela estrutura ou pelo objeto apontado por *lpRect* e é armazenada no `CRgn` objeto.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando terminar de usar uma região criada com a `CreateEllipticRgnIndirect` função, um aplicativo deverá selecionar a região fora do contexto do dispositivo e usar a `DeleteObject` função para removê-la.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CRgn:: CreateRectRgnIndirect](#createrectrgnindirect).

##  <a name="createfromdata"></a>  CRgn::CreateFromData

Cria uma região a partir da região e dos dados de transformação fornecidos.

```
BOOL CreateFromData(
    const XFORM* lpXForm,
    int nCount,
    const RGNDATA* pRgnData);
```

### <a name="parameters"></a>Parâmetros

*lpXForm*<br/>
Aponta para uma estrutura de dados [XFORM](/windows/desktop/api/wingdi/ns-wingdi-tagxform) que define a transformação a ser executada na região. Se esse ponteiro for nulo, a transformação de identidade será usada.

*nCount*<br/>
Especifica o número de bytes apontados por *pRgnData*.

*pRgnData*<br/>
Aponta para uma estrutura de dados [RGNDATA](/windows/desktop/api/wingdi/ns-wingdi-rgndata) que contém os dados da região.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo pode recuperar dados para uma região chamando a `CRgn::GetRegionData` função.

##  <a name="createfrompath"></a>  CRgn::CreateFromPath

Cria uma região a partir do caminho selecionado no contexto de dispositivo fornecido.

```
BOOL CreateFromPath(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Identifica um contexto de dispositivo que contém um caminho fechado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O contexto do dispositivo identificado pelo parâmetro *PDC* deve conter um caminho fechado. Depois `CreateFromPath` que o converte um caminho em uma região, o Windows descarta o caminho fechado do contexto do dispositivo.

##  <a name="createpolygonrgn"></a>  CRgn::CreatePolygonRgn

Cria uma região poligonal.

```
BOOL CreatePolygonRgn(
    LPPOINT lpPoints,
    int nCount,
    int nMode);
```

### <a name="parameters"></a>Parâmetros

*lpPoints*<br/>
Aponta para uma matriz de `POINT` estruturas ou uma matriz de `CPoint` objetos. Cada estrutura especifica a coordenada x e a coordenada y de um vértice do polígono. A `POINT` estrutura tem o seguinte formato:

```cpp
typedef struct tagPOINT {
    int x;
    int y;
} POINT;
```

*nCount*<br/>
Especifica o número de `POINT` estruturas ou `CPoint` objetos na matriz apontados por *lpPoints*.

*nMode*<br/>
Especifica o modo de preenchimento para a região. Esse parâmetro pode ser alternativo ou de vento.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice para o primeiro. A região resultante é armazenada no `CRgn` objeto.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando o modo de preenchimento de polígono é alternativo, o sistema preenche a área entre os lados de polígono numerados e ímpares em cada linha de digitalização. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e o quarto lado, e assim por diante.

Quando o modo de preenchimento de polígono estiver enrolando, o sistema usará a direção em que uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado em uma direção no sentido horário ou no sentido anti-horário. Sempre que uma linha imaginária desenhada de uma área fechada para fora de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área será preenchida se a contagem for diferente de zero quando a linha atingir o fora da figura.

Quando um aplicativo termina de usar uma região criada com a `CreatePolygonRgn` função, ele deve selecionar a região fora do contexto do dispositivo e usar a `DeleteObject` função para removê-lo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#146](../../mfc/codesnippet/cpp/crgn-class_3.cpp)]

##  <a name="createpolypolygonrgn"></a>  CRgn::CreatePolyPolygonRgn

Cria uma região que consiste em uma série de polígonos fechados.

```
BOOL CreatePolyPolygonRgn(
    LPPOINT lpPoints,
    LPINT lpPolyCounts,
    int nCount,
    int nPolyFillMode);
```

### <a name="parameters"></a>Parâmetros

*lpPoints*<br/>
Aponta para uma matriz de `POINT` estruturas ou uma matriz de `CPoint` objetos que define os vértices dos polígonos. Cada polígono deve ser fechado explicitamente porque o sistema não os fecha automaticamente. Os polígonos são especificados consecutivamente. A `POINT` estrutura tem o seguinte formato:

```cpp
typedef struct tagPOINT {
    int x;
    int y;
} POINT;
```

*lpPolyCounts*<br/>
Aponta para uma matriz de inteiros. O primeiro inteiro especifica o número de vértices no primeiro polígono na matriz *lpPoints* , o segundo inteiro especifica o número de vértices no segundo polígono e assim por diante.

*nCount*<br/>
Especifica o número total de inteiros na matriz *lpPolyCounts* .

*nPolyFillMode*<br/>
Especifica o modo de preenchimento de polígono. Esse valor pode ser alternativo ou de vento.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A região resultante é armazenada no `CRgn` objeto.

Os polígonos podem ser não contíguos ou podem se sobrepor.

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando o modo de preenchimento de polígono é alternativo, o sistema preenche a área entre os lados de polígono numerados e ímpares em cada linha de digitalização. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e o quarto lado, e assim por diante.

Quando o modo de preenchimento de polígono estiver enrolando, o sistema usará a direção em que uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado em uma direção no sentido horário ou no sentido anti-horário. Sempre que uma linha imaginária desenhada de uma área fechada para fora de uma figura passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área será preenchida se a contagem for diferente de zero quando a linha atingir o fora da figura.

Quando um aplicativo termina de usar uma região criada com a `CreatePolyPolygonRgn` função, ele deve selecionar a região fora do contexto do dispositivo e usar a função de membro [CGdiObject::D eleteobject](../../mfc/reference/cgdiobject-class.md#deleteobject) para removê-lo.

##  <a name="createrectrgn"></a>  CRgn::CreateRectRgn

Cria uma região retangular que é armazenada no `CRgn` objeto.

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
Especifica a coordenada y lógica do canto superior esquerdo da região.

*x2*<br/>
Especifica a coordenada x lógica do canto inferior direito da região.

*Y2*<br/>
Especifica a coordenada y lógica do canto inferior direito da região.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando terminar de usar uma região criada pelo `CreateRectRgn`, um aplicativo deverá usar a função de membro [CGdiObject::D eleteobject](../../mfc/reference/cgdiobject-class.md#deleteobject) para remover a região.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#147](../../mfc/codesnippet/cpp/crgn-class_4.cpp)]

Para obter um exemplo adicional, consulte [CRgn:: CombineRgn](#combinergn).

##  <a name="createrectrgnindirect"></a>  CRgn::CreateRectRgnIndirect

Cria uma região retangular que é armazenada no `CRgn` objeto.

```
BOOL CreateRectRgnIndirect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma `RECT` estrutura ou `CRect` objeto que contém as coordenadas lógicas dos cantos superior esquerdo e inferior direito da região. A `RECT` estrutura tem o seguinte formato:

```cpp
typedef struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
} RECT;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando terminar de usar uma região criada pelo `CreateRectRgnIndirect`, um aplicativo deverá usar a função de membro [CGdiObject::D eleteobject](../../mfc/reference/cgdiobject-class.md#deleteobject) para remover a região.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#148](../../mfc/codesnippet/cpp/crgn-class_5.cpp)]

##  <a name="createroundrectrgn"></a>  CRgn::CreateRoundRectRgn

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
Especifica a coordenada y lógica do canto superior esquerdo da região.

*x2*<br/>
Especifica a coordenada x lógica do canto inferior direito da região.

*Y2*<br/>
Especifica a coordenada y lógica do canto inferior direito da região.

*x3*<br/>
Especifica a largura da elipse usada para criar os cantos arredondados.

*y3*<br/>
Especifica a altura da elipse usada para criar os cantos arredondados.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O tamanho de uma região é limitado a 32.767 por 32.767 unidades lógicas ou 64K de memória, o que for menor.

Quando um aplicativo termina de usar uma região criada com a `CreateRoundRectRgn` função, ele deve selecionar a região fora do contexto do dispositivo e usar a função de membro [CGdiObject::D eleteobject](../../mfc/reference/cgdiobject-class.md#deleteobject) para removê-lo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#149](../../mfc/codesnippet/cpp/crgn-class_6.cpp)]

##  <a name="crgn"></a>  CRgn::CRgn

Constrói um objeto `CRgn`.

```
CRgn();
```

### <a name="remarks"></a>Comentários

O `m_hObject` membro de dados não contém uma região GDI do Windows válida até que o objeto seja inicializado com uma ou mais `CRgn` das outras funções de membro.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CRgn:: CreateRoundRectRgn](#createroundrectrgn).

##  <a name="equalrgn"></a>  CRgn::EqualRgn

Determina se a região fornecida é equivalente à região armazenada no `CRgn` objeto.

```
BOOL EqualRgn(CRgn* pRgn) const;
```

### <a name="parameters"></a>Parâmetros

*pRgn*<br/>
Identifica uma região.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as duas regiões forem equivalentes; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#150](../../mfc/codesnippet/cpp/crgn-class_7.cpp)]

##  <a name="fromhandle"></a>  CRgn::FromHandle

Retorna um ponteiro para um `CRgn` objeto quando um identificador é fornecido a uma região do Windows.

```
static CRgn* PASCAL FromHandle(HRGN hRgn);
```

### <a name="parameters"></a>Parâmetros

*hRgn*<br/>
Especifica um identificador para uma região do Windows.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CRgn` objeto. Se a função não tiver sido bem-sucedida, o valor de retorno será nulo.

### <a name="remarks"></a>Comentários

Se um `CRgn` objeto ainda não estiver anexado ao identificador, um objeto temporário `CRgn` será criado e anexado. Esse objeto `CRgn` temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos gráficos temporários forem excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de uma mensagem de janela.

##  <a name="getregiondata"></a>  CRgn::GetRegionData

Preenche o buffer especificado com os dados que descrevem a região.

```
int GetRegionData(
    LPRGNDATA lpRgnData,
    int nCount) const;
```

### <a name="parameters"></a>Parâmetros

*lpRgnData*<br/>
Aponta para uma estrutura de dados [RGNDATA](/windows/desktop/api/wingdi/ns-wingdi-rgndata) que recebe as informações. Se esse parâmetro for nulo, o valor de retorno conterá o número de bytes necessários para os dados da região.

*nCount*<br/>
Especifica o tamanho, em bytes, do buffer *lpRgnData* .

### <a name="return-value"></a>Valor de retorno

Se a função for bem sucedido e *nCount* especificar um número adequado de bytes, o valor de retorno será sempre *nCount*. Se a função falhar ou se *nCount* especificar menos que o número adequado de bytes, o valor de retorno será 0 (erro).

### <a name="remarks"></a>Comentários

Esses dados incluem as dimensões dos retângulos que compõem a região. Essa função é usada em conjunto com a `CRgn::CreateFromData` função.

##  <a name="getrgnbox"></a>  CRgn::GetRgnBox

Recupera as coordenadas do retângulo delimitador do `CRgn` objeto.

```
int GetRgnBox(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma `RECT` estrutura ou `CRect` objeto para receber as coordenadas do retângulo delimitador. A `RECT` estrutura tem o seguinte formato:

`typedef struct tagRECT {`

`int left;`

`int top;`

`int right;`

`int bottom;`

`} RECT;`

### <a name="return-value"></a>Valor de retorno

Especifica o tipo da região. Pode ser qualquer um dos seguintes valores:

- A região COMPLEXREGION tem bordas sobrepostas.

- A região NULLREGION está vazia.

- O `CRgn` objeto de erro não especifica uma região válida.

- A região SIMPLEREGION não tem bordas sobrepostas.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CRgn:: CreatePolygonRgn](#createpolygonrgn).

##  <a name="offsetrgn"></a>  CRgn::OffsetRgn

Move a região armazenada no `CRgn` objeto pelos deslocamentos especificados.

```
int OffsetRgn(
    int x,
    int y);

int OffsetRgn(POINT point);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o número de unidades a serem movidas para a esquerda ou direita.

*y*<br/>
Especifica o número de unidades a serem movidas para cima ou para baixo.

*point*<br/>
A coordenada x de *ponto* especifica o número de unidades a serem movidas para a esquerda ou direita. A coordenada y de *Point* especifica o número de unidades a serem movidas para cima ou para baixo. O parâmetro *Point* pode ser uma `POINT` estrutura ou um `CPoint` objeto.

### <a name="return-value"></a>Valor de retorno

O tipo da nova região. Pode ser qualquer um dos seguintes valores:

- A região COMPLEXREGION tem bordas sobrepostas.

- O identificador de região de erro não é válido.

- A região NULLREGION está vazia.

- A região SIMPLEREGION não tem bordas sobrepostas.

### <a name="remarks"></a>Comentários

A função move as unidades da região *x* ao longo do eixo x e das unidades *y* ao longo do eixo y.

Os valores de coordenadas de uma região devem ser menores ou iguais a 32.767 e maiores ou iguais a-32.768. Os parâmetros *x* e *y* devem ser cuidadosamente escolhidos para evitar coordenadas de região inválidas.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CRgn:: CreateEllipticRgn](#createellipticrgn).

##  <a name="operator_hrgn"></a>Operador CRgn:: Operator HRGN

Use esse operador para obter o identificador GDI do Windows anexado do `CRgn` objeto.

```
operator HRGN() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um identificador para o objeto GDI do Windows representado `CRgn` pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HRGN.

Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [objetos gráficos](/windows/desktop/gdi/graphic-objects) na SDK do Windows.

##  <a name="ptinregion"></a>  CRgn::PtInRegion

Verifica se o ponto fornecido por *x* e *y* está na região `CRgn` armazenada no objeto.

```
BOOL PtInRegion(
    int x,
    int y) const;

BOOL PtInRegion(POINT point) const;
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica a coordenada x lógica do ponto a ser testado.

*y*<br/>
Especifica a coordenada y lógica do ponto a ser testado.

*point*<br/>
As coordenadas x e y do *ponto* especificam as coordenadas x e y do ponto para testar o valor de. O parâmetro *Point* pode ser uma `POINT` estrutura ou um `CPoint` objeto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o ponto estiver na região; caso contrário, 0.

##  <a name="rectinregion"></a>  CRgn::RectInRegion

Determina se qualquer parte do retângulo especificada por *lpRect* está dentro dos limites da região armazenada no `CRgn` objeto.

```
BOOL RectInRegion(LPCRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma `RECT` estrutura ou `CRect` um objeto. A `RECT` estrutura tem o seguinte formato:

```cpp
typedef struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
} RECT;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se qualquer parte do retângulo especificado estiver dentro dos limites da região; caso contrário, 0.

##  <a name="setrectrgn"></a>  CRgn::SetRectRgn

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

*Y2*<br/>
Especifica a coordenada y do canto inferior direito da região retangular.

*lpRect*<br/>
Especifica a região retangular. Pode ser um ponteiro para uma `RECT` estrutura ou um `CRect` objeto.

### <a name="remarks"></a>Comentários

Ao contrário de [CreateRectRgn](#createrectrgn), no entanto, ele não aloca memória adicional do heap de aplicativo do Windows local. Em vez disso, ele usa o espaço alocado para a região armazenada no `CRgn` objeto. Isso significa que o `CRgn` objeto já deve ter sido inicializado com uma região do Windows válida `SetRectRgn`antes de chamar. Os pontos fornecidos por *X1*, *Y1*, *X2*e *Y2* especificam o tamanho mínimo do espaço alocado.

Use essa função em vez da `CreateRectRgn` função membro para evitar chamadas para o Gerenciador de memória local.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
