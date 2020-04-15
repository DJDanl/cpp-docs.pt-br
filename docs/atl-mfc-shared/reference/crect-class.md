---
title: Classe CRect
ms.date: 11/06/2018
f1_keywords:
- CRect
- ATLTYPES/ATL::CRect
- ATLTYPES/ATL::CRect::CRect
- ATLTYPES/ATL::CRect::BottomRight
- ATLTYPES/ATL::CRect::CenterPoint
- ATLTYPES/ATL::CRect::CopyRect
- ATLTYPES/ATL::CRect::DeflateRect
- ATLTYPES/ATL::CRect::EqualRect
- ATLTYPES/ATL::CRect::Height
- ATLTYPES/ATL::CRect::InflateRect
- ATLTYPES/ATL::CRect::IntersectRect
- ATLTYPES/ATL::CRect::IsRectEmpty
- ATLTYPES/ATL::CRect::IsRectNull
- ATLTYPES/ATL::CRect::MoveToX
- ATLTYPES/ATL::CRect::MoveToXY
- ATLTYPES/ATL::CRect::MoveToY
- ATLTYPES/ATL::CRect::NormalizeRect
- ATLTYPES/ATL::CRect::OffsetRect
- ATLTYPES/ATL::CRect::PtInRect
- ATLTYPES/ATL::CRect::SetRect
- ATLTYPES/ATL::CRect::SetRectEmpty
- ATLTYPES/ATL::CRect::Size
- ATLTYPES/ATL::CRect::SubtractRect
- ATLTYPES/ATL::CRect::TopLeft
- ATLTYPES/ATL::CRect::UnionRect
- ATLTYPES/ATL::CRect::Width
helpviewer_keywords:
- LPCRECT data type
- CRect class
- LPRECT operator
- RECT structure
ms.assetid: dee4e752-15d6-4db4-b68f-1ad65b2ed6ca
ms.openlocfilehash: c59ed587e2c8e51f5c08a026a7ee0b9d0af25168
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317713"
---
# <a name="crect-class"></a>Classe CRect

Semelhante a uma estrutura do Windows [RECT.](/windows/win32/api/windef/ns-windef-rect)

## <a name="syntax"></a>Sintaxe

```
class CRect : public tagRECT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRect::CRect](#crect)|Constrói um objeto `CRect`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRect::BottomRight](#bottomright)|Retorna o ponto inferior `CRect`direito de .|
|[CRect::CenterPoint](#centerpoint)|Retorna o ponto `CRect`central de .|
|[CRect::CopyRect](#copyrect)|Copia as dimensões de um `CRect`retângulo de origem para .|
|[CRect::DeflateRect](#deflaterect)|Diminui a largura e `CRect`a altura de .|
|[CRect::EqualRect](#equalrect)|Determina se `CRect` é igual ao retângulo dado.|
|[CRect::Altura](#height)|Calcula a `CRect`altura de .|
|[CRect::InflateRect](#inflaterect)|Aumenta a largura `CRect`e a altura de .|
|[CRect::IntersectRect](#intersectrect)|Conjuntos `CRect` iguais à intersecção de dois retângulos.|
|[CRect::IsRectEmpty](#isrectempty)|Determina se `CRect` está vazio. `CRect`está vazia se a largura e/ou altura for em 0.|
|[CRect::IsRectNull](#isrectnull)|Determina se `top`as `bottom` `left`variáveis `right` de membro e membro são todas iguais a 0.|
|[CRect::MoveToX](#movetox)|Move-se `CRect` para a coordenada x especificada.|
|[CRect::MoveToXY](#movetoxy)|Move-se `CRect` para as coordenadas x e y especificadas.|
|[CRect::MoveToY](#movetoy)|Move-se `CRect` para a coordenada y especificada.|
|[CRect::NormalizeRect](#normalizerect)|Padroniza a altura e `CRect`a largura de .|
|[CRect::OffsetRect](#offsetrect)|Movimentos `CRect` pelas compensações especificadas.|
|[CRect::PtInRect](#ptinrect)|Determina se o ponto especificado está dentro `CRect`.|
|[CRect::SetRect](#setrect)|Define as dimensões de `CRect`.|
|[CRect::SetRectEmpty](#setrectempty)|Define `CRect` um retângulo vazio (todas as coordenadas iguais a 0).|
|[CRect::Tamanho](#size)|Calcula o `CRect`tamanho de .|
|[CRect::SubtractRect](#subtractrect)|Subtrai um retângulo do outro.|
|[CRect::TopLeft](#topleft)|Retorna o ponto superior `CRect`esquerdo de .|
|[CRect::UnionRect](#unionrect)|Conjuntos `CRect` iguais à união de dois retângulos.|
|[CRect::Largura](#width)|Calcula a `CRect`largura de .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRect::operador -](#operator_-)|Subtrai as compensações `CRect` dadas `CRect` ou esvazia `CRect`e retorna o resultante .|
|[CRect::operador LPCRECT](#operator_lpcrect)|Converte um `CRect` em um `LPCRECT`.|
|[CRect::operador LPRECT](#operator_lprect)|Converte um `CRect` em um `LPRECT`.|
|[CRect::operador !=](#operator_neq)|Determina se `CRect` não é igual a um retângulo.|
|[CRect::operador&amp;](#operator_amp)|Cria a `CRect` intersecção e um retângulo e retorna o resultado `CRect`.|
|[CRect::operador&amp;=](#operator_amp_eq)|Conjuntos `CRect` iguais à `CRect` intersecção e um retângulo.|
|[CRect::operador &#124;](#operator_or)|Cria a `CRect` união e um retângulo `CRect`e retorna o resultado.|
|[CRect::&#124;do operador =](#operator_or_eq)|Conjuntos `CRect` iguais à `CRect` união e um retângulo.|
|[CRect::operador +](#operator_add)|Adiciona as compensações `CRect` dadas `CRect` ou infla `CRect`e retorna o resultado .|
|[CRect::operador +=](#operator_add_eq)|Adiciona as compensações `CRect` especificadas `CRect`a ou infla.|
|[CRect::operador =](#operator_eq)|Copia as dimensões de um `CRect`retângulo para .|
|[CRect::operador -=](#operator_-_eq)|Subtrai as compensações especificadas ou esvazia `CRect` `CRect`.|
|[CRect::operador ==](#operator_eq_eq)|Determina se `CRect` é igual a um retângulo.|

## <a name="remarks"></a>Comentários

`CRect`também inclui funções de `CRect` membro `RECT` para manipular objetos e estruturas do Windows.

Um `CRect` objeto pode ser passado como um `RECT` parâmetro `LPCRECT`de `LPRECT` função onde quer que uma estrutura, ou pode ser passado.

> [!NOTE]
> Esta classe é derivada da `tagRECT` estrutura. (O `tagRECT` nome é um nome menos usado `RECT` para a estrutura.) Isso significa que os`left` `top`membros `right`de `bottom`dados `RECT` ( , , `CRect`e ) da estrutura são membros de dados acessíveis de .

A `CRect` contém variáveis de membro que definem os pontos superior esquerdo e inferior direito de um retângulo.

Ao especificar `CRect`um , você deve ter cuidado para construí-lo para que ele seja normalizado - em outras palavras, de tal forma que o valor da coordenada esquerda é menor que o direito e o topo é menor que o inferior. Por exemplo, um canto superior esquerdo (10,10) e inferior direito de (20,20) define um retângulo normalizado, mas um canto superior esquerdo de (20,20) e inferior direito de (10,10) define um retângulo não normalizado. Se o retângulo não for `CRect` normalizado, muitas funções de membro podem retornar resultados incorretos. (Consulte [CRect::NormalizeRect](#normalizerect) para uma lista dessas funções.) Antes de chamar uma função que requer retângulos normalizados, você pode `NormalizeRect` normalizar retângulos não normalizados chamando a função.

Tenha cuidado ao `CRect` manipular um com as funções de membro [CDC::DPtoLP](../../mfc/reference/cdc-class.md#dptolp) e [CDC:::LPtoDP.](../../mfc/reference/cdc-class.md#lptodp) Se o modo de mapeamento de um contexto de exibição `MM_LOENGLISH`é `CDC::DPtoLP` tal `CRect` que a extensão y é negativa, como em , então transformará o de modo que seu topo seja maior que o inferior. Funções como `Height` `Size` e, em seguida, retornarão valores negativos para a altura da transformação, `CRect`e o retângulo não será normalizado.

Ao utilizar `CRect` operadores sobrecarregados, o primeiro `CRect`operand deve ser um ; o segundo pode ser uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou um objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagRECT`

`CRect`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes.h

## <a name="crectbottomright"></a><a name="bottomright"></a>CRect::BottomRight

As coordenadas são retornadas como uma referência a `CRect`um objeto [CPoint](cpoint-class.md) que está contido em .

```
CPoint& BottomRight() throw();
const CPoint& BottomRight() const throw();
```

### <a name="return-value"></a>Valor retornado

As coordenadas do canto inferior direito do retângulo.

### <a name="remarks"></a>Comentários

Você pode usar esta função para obter ou definir o canto inferior direito do retângulo. Defina o canto usando esta função no lado esquerdo do operador de atribuição.

### <a name="example"></a>Exemplo

```cpp
// use BottomRight() to retrieve the bottom
// right POINT
CRect rect(210, 150, 350, 900);
CPoint ptDown;

ptDown = rect.BottomRight();

// ptDown is now set to (350, 900)
ASSERT(ptDown == CPoint(350, 900));

// or, use BottomRight() to set the bottom
// right POINT
CRect rect2(10, 10, 350, 350);
CPoint ptLow(180, 180);

CRect rect2(10, 10, 350, 350);
CPoint ptLow(180, 180);
rect2.BottomRight() = ptLow;

// rect2 is now (10, 10, 180, 180)
ASSERT(rect2 == CRect(10, 10, 180, 180));
```

## <a name="crectcenterpoint"></a><a name="centerpoint"></a>CRect::CenterPoint

Calcula o ponto `CRect` central de adicionando os valores esquerdo e direito e dividindo por dois, adicionando os valores superior e inferior e dividindo por dois.

```
CPoint CenterPoint() const throw();
```

### <a name="return-value"></a>Valor retornado

Um `CPoint` objeto que é `CRect`o ponto central de .

### <a name="example"></a>Exemplo

```cpp
// Code from this OnPaint() implementation can be pasted into your own application
// to draw lines that would look like a letter "Y" within your dialog.
void CMyDlg::OnPaint()
{
    CPaintDC dc(this);

    // device context for painting

    // get the size and position of the client area of
    // your window

    CRect rect;
    GetClientRect(&rect);

    // Move the current pen to the top left of the window. We call the
    // TopLeft() member of CRect here and it returns a CPoint object we
    // pass to the override of CDC::MoveTo() that accepts a CPoint.

    dc.MoveTo(rect.TopLeft());

    // Draw a line from the top left to the center of the window.
    // CenterPoint() gives us the middle point of the window as a
    // CPoint, and since CDC::LineTo() has an override that accepts a
    // CPoint, we can just pass it along.

    dc.LineTo(rect.CenterPoint());

    // Now, draw a line to the top right of the window. There's no
    // CRect member which returns a CPoint for the top right of the
    // window, so we'll reference the CPoint members directly and call
    // the CDC::LineTo() override which takes two integers.

    dc.LineTo(rect.right, rect.top);

    // The top part of the "Y" is drawn. Now, we'll draw the stem. We
    // start from the center point.

    dc.MoveTo(rect.CenterPoint());

    // and then draw to the middle of the bottom edge of the window.
    // We'll get the x-coordinate from the x member of the CPOINT
    // returned by CenterPoint(), and the y value comes directly from
    // the rect.

    dc.LineTo(rect.CenterPoint().x, rect.bottom);
}
```

## <a name="crectcopyrect"></a><a name="copyrect"></a>CRect::CopyRect

Copia `lpSrcRect` o retângulo em `CRect`.

```
void CopyRect(LPCRECT lpSrcRect) throw();
```

### <a name="parameters"></a>Parâmetros

*lpSrcRect*<br/>
Aponta para a estrutura `CRect` [rect](/windows/win32/api/windef/ns-windef-rect) ou objeto a ser copiado.

### <a name="example"></a>Exemplo

```cpp
CRect rectSource(35, 10, 125, 10);
CRect rectDest;

rectDest.CopyRect(&rectSource);

// rectDest is now set to (35, 10, 125, 10)

RECT rectSource2;
rectSource2.left = 0;
rectSource2.top = 0;
rectSource2.bottom = 480;
rectSource2.right = 640;

rectDest.CopyRect(&rectSource2);

// works against RECT structures, too!
// rectDest is now set to (0, 0, 640, 480)
```

## <a name="crectcrect"></a><a name="crect"></a>CRect::CRect

Constrói um objeto `CRect`.

```
CRect() throw();
CRect(int l, int t, int r, int b) throw();
CRect(const RECT& srcRect) throw();
CRect(LPCRECT lpSrcRect) throw();
CRect(POINT point, SIZE size) throw();
CRect(POINT topLeft, POINT bottomRight) throw();
```

### <a name="parameters"></a>Parâmetros

*L*<br/>
Especifica a posição `CRect`esquerda de .

*t*<br/>
Especifica a parte `CRect`superior de .

*r*<br/>
Especifica a posição `CRect`correta de .

*B*<br/>
Especifica a parte `CRect`inferior de .

*Srcrect*<br/>
Refere-se à estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) com `CRect`as coordenadas para .

*lpSrcRect*<br/>
Aponta para `RECT` a estrutura com `CRect`as coordenadas para .

*Ponto*<br/>
Especifica o ponto de origem para o retângulo a ser construído. Corresponde ao canto superior esquerdo.

*Tamanho*<br/>
Especifica o deslocamento do canto superior esquerdo para o canto inferior direito do retângulo a ser construído.

*topLeft*<br/>
Especifica a posição superior `CRect`esquerda de .

*bottomRight*<br/>
Especifica a posição inferior `CRect`direita de .

### <a name="remarks"></a>Comentários

Se não forem `left`dadas `top`argumentos, `right`e `bottom` os membros não forem inicializados.

Os `CRect``const RECT&`construtores `CRect``LPCRECT`( ) e ( ) realizam um [CopyRect](#copyrect). Os outros construtores inicializam diretamente as variáveis membros do objeto.

### <a name="example"></a>Exemplo

```cpp
// default constructor doesn't initialize!
CRect rectUnknown;

// four-integers are left, top, right, and bottom
CRect rect(0, 0, 100, 50);
ASSERT(rect.Width() == 100);
ASSERT(rect.Height() == 50);

// Initialize from RECT structure
RECT sdkRect;
sdkRect.left = 0;
sdkRect.top = 0;
sdkRect.right = 100;
sdkRect.bottom = 50;

CRect rect2(sdkRect);
// by reference
CRect rect3(&sdkRect);

// by address
ASSERT(rect2 == rect);
ASSERT(rect3 == rect);

// from a point and a size
CPoint pt(0, 0);
CSize sz(100, 50);
CRect rect4(pt, sz);
ASSERT(rect4 == rect2);

// from two points
CPoint ptBottomRight(100, 50);
CRect rect5(pt, ptBottomRight);
ASSERT(rect5 == rect4);
```

## <a name="crectdeflaterect"></a><a name="deflaterect"></a>CRect::DeflateRect

`DeflateRect``CRect` esvazia movendo seus lados em direção ao seu centro.

```
void DeflateRect(int x, int y) throw();
void DeflateRect(SIZE size) throw();
void DeflateRect(LPCRECT lpRect) throw();
void DeflateRect(int l, int t, int r, int b) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o número de unidades para desinflar os lados esquerdo e direito de `CRect`.

*Y*<br/>
Especifica o número de unidades para desinflar a parte superior e inferior de `CRect`.

*Tamanho*<br/>
[Um TAMANHO](/windows/win32/api/windef/ns-windef-size) ou [Tamanho](csize-class.md) que especifica o `CRect`número de unidades para desinflar . O `cx` valor especifica o número de unidades para desinflar os lados esquerdo e direito e o `cy` valor especifica o número de unidades para desinflar a parte superior e inferior.

*Lprect*<br/>
Aponta para uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou que especifica o número de unidades para esvaziar cada lado.

*L*<br/>
Especifica o número de unidades para `CRect`desinflar o lado esquerdo de .

*t*<br/>
Especifica o número de unidades para `CRect`esvaziar a parte superior da .

*r*<br/>
Especifica o número de unidades para `CRect`desinflar o lado direito de .

*B*<br/>
Especifica o número de unidades para `CRect`esvaziar a parte inferior de .

### <a name="remarks"></a>Comentários

Para isso, `DeflateRect` adiciona unidades à esquerda e superior e subtrai unidades da direita e da parte inferior. Os parâmetros são `DeflateRect` valores assinados; valores `CRect` positivos desinflam e valores negativos inflam.

As duas primeiras sobrecargas esvaziam ambos `CRect` os pares de lados opostos de `cx`modo que sua largura total seja diminuída em duas vezes *x* (ou ) e sua altura total seja diminuída em duas vezes *y* (ou `cy`). As outras duas sobrecargas `CRect` esvaziam cada lado independente mente dos outros.

### <a name="example"></a>Exemplo

```cpp
CRect rect(10, 10, 50, 50);
rect.DeflateRect(1, 2);
ASSERT(rect.left == 11 && rect.right == 49);
ASSERT(rect.top == 12 && rect.bottom == 48);

CRect rect2(10, 10, 50, 50);
CRect rectDeflate(1, 2, 3, 4);
rect2.DeflateRect(&rectDeflate);
ASSERT(rect2.left == 11 && rect2.right == 47);
ASSERT(rect2.top == 12 && rect2.bottom == 46);
```

## <a name="crectequalrect"></a><a name="equalrect"></a>CRect::EqualRect

Determina se `CRect` é igual ao retângulo dado.

```
BOOL EqualRect(LPCRECT lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para uma estrutura `CRect` [rect](/windows/win32/api/windef/ns-windef-rect) ou objeto que contenha as coordenadas do canto superior esquerdo e inferior direito de um retângulo.

### <a name="return-value"></a>Valor retornado

Não zero se os dois retângulos tiverem os mesmos valores superior, esquerdo, inferior e direito; caso contrário, 0.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect1(35, 150, 10, 25);
CRect rect2(35, 150, 10, 25);
CRect rect3(98, 999, 6, 3);
ASSERT(rect1.EqualRect(rect2));
ASSERT(!rect1.EqualRect(rect3));
// works just fine against RECTs, as well

RECT test;
test.left = 35;
test.top = 150;
test.right = 10;
test.bottom = 25;

ASSERT(rect1.EqualRect(&test));
```

## <a name="crectheight"></a><a name="height"></a>CRect::Altura

Calcula a `CRect` altura de subtraindo o valor superior do valor inferior.

```
int Height() const throw();
```

### <a name="return-value"></a>Valor retornado

A altura `CRect`de .

### <a name="remarks"></a>Comentários

O valor resultante pode ser negativo.

> [!NOTE]
> O retângulo deve ser normalizado ou esta função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(20, 30, 80, 70);
int nHt = rect.Height();

// nHt is now 40
ASSERT(nHt == 40);
```

## <a name="crectinflaterect"></a><a name="inflaterect"></a>CRect::InflateRect

`InflateRect`infla `CRect` movendo seus lados para longe de seu centro.

```
void InflateRect(int x, int y) throw();
void InflateRect(SIZE size) throw();
void InflateRect(LPCRECT lpRect) throw();
void InflateRect(int l, int t, int r,  int b) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o número de unidades para inflar `CRect`os lados esquerdo e direito de .

*Y*<br/>
Especifica o número de unidades para inflar a parte superior e inferior de `CRect`.

*Tamanho*<br/>
[Um TAMANHO](/windows/win32/api/windef/ns-windef-size) ou [Tamanho](csize-class.md) que especifica o `CRect`número de unidades para inflar . O `cx` valor especifica o número de unidades para inflar os lados esquerdo e direito e o `cy` valor especifica o número de unidades para inflar a parte superior e inferior.

*Lprect*<br/>
Aponta para uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou que especifica o número de unidades para inflar cada lado.

*L*<br/>
Especifica o número de unidades para `CRect`inflar o lado esquerdo de .

*t*<br/>
Especifica o número de unidades para `CRect`inflar a parte superior de .

*r*<br/>
Especifica o número de unidades para `CRect`inflar o lado direito de .

*B*<br/>
Especifica o número de unidades para `CRect`inflar a parte inferior de .

### <a name="remarks"></a>Comentários

Para isso, `InflateRect` subtrai unidades da esquerda e de cima e adiciona unidades à direita e à parte inferior. Os parâmetros são `InflateRect` valores assinados; valores `CRect` positivos inflam e valores negativos o esvaziam.

As duas primeiras sobrecargas inflam ambos `CRect` os pares de lados opostos de `cx`modo que sua largura total é aumentada `cy`em duas vezes *x* (ou ) e sua altura total é aumentada em duas vezes *y* (ou ). As outras duas sobrecargas `CRect` inflam cada lado independente mente dos outros.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 300, 300);
rect.InflateRect(50, 200);

// rect is now (-50, -200, 350, 500)
ASSERT(rect == CRect(-50, -200, 350, 500));
```

## <a name="crectintersectrect"></a><a name="intersectrect"></a>CRect::IntersectRect

Faz `CRect` igual à intersecção de dois retângulos existentes.

```
BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();
```

### <a name="parameters"></a>Parâmetros

*lpRect1*<br/>
Aponta para uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto que contenha um retângulo de origem.

*lpRect2*<br/>
Aponta para `RECT` uma `CRect` estrutura ou objeto que contém um retângulo de origem.

### <a name="return-value"></a>Valor retornado

Não zero se a intersecção não estiver vazia; 0 se o cruzamento estiver vazio.

### <a name="remarks"></a>Comentários

A intersecção é o maior retângulo contido em ambos os retângulos existentes.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rectOne(125,  0, 150, 200);
CRect rectTwo(0, 75, 350, 95);
CRect rectInter;

rectInter.IntersectRect(rectOne, rectTwo);
ASSERT(rectInter == CRect(125, 75, 150, 95));
// operator &= can do the same task:

CRect rectInter2 = rectOne;
rectInter2 &= rectTwo;
ASSERT(rectInter2 == CRect(125, 75, 150, 95));
```

## <a name="crectisrectempty"></a><a name="isrectempty"></a>CRect::IsRectEmpty

Determina se `CRect` está vazio.

```
BOOL IsRectEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Não zero `CRect` se estiver vazio; 0 `CRect` se não estiver vazio.

### <a name="remarks"></a>Comentários

Um retângulo está vazio se a largura e/ou altura forem 0 ou negativas. Difere de `IsRectNull`, o que determina se todas as coordenadas do retângulo são zero.

> [!NOTE]
> O retângulo deve ser normalizado ou esta função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rectNone(0, 0, 0, 0);
CRect rectSome(35, 50, 135, 150);
ASSERT(rectNone.IsRectEmpty());
ASSERT(!rectSome.IsRectEmpty());
CRect rectEmpty(35, 35, 35, 35);
ASSERT(rectEmpty.IsRectEmpty());
```

## <a name="crectisrectnull"></a><a name="isrectnull"></a>CRect::IsRectNull

Determina se os valores superior, esquerdo, `CRect` inferior e direito são todos iguais a 0.

```
BOOL IsRectNull() const throw();
```

### <a name="return-value"></a>Valor retornado

Valores `CRect`não zero se 'for superior, esquerdo, inferior e direito são todos iguais a 0; caso contrário, 0.

### <a name="remarks"></a>Comentários

Difere de `IsRectEmpty`, o que determina se o retângulo está vazio.

### <a name="example"></a>Exemplo

```cpp
CRect rectNone(0, 0, 0, 0);
CRect rectSome(35, 50, 135, 150);
ASSERT(rectNone.IsRectNull());
ASSERT(!rectSome.IsRectNull());
// note that null means _all_ zeros

CRect rectNotNull(0, 0, 35, 50);
ASSERT(!rectNotNull.IsRectNull());
```

## <a name="crectmovetox"></a><a name="movetox"></a>CRect::MoveToX

Chame esta função para mover o retângulo para a coordenada x absoluta especificada por *x*.

```
void MoveToX(int x) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x absoluta para o canto superior esquerdo do retângulo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 100, 100);
rect.MoveToX(10);

// rect is now (10, 0, 110, 100);
ASSERT(rect == CRect(10, 0, 110, 100));
```

## <a name="crectmovetoxy"></a><a name="movetoxy"></a>CRect::MoveToXY

Chame esta função para mover o retângulo para as coordenadas x e y absolutas especificadas.

```
void MoveToXY(int x, int y) throw();
void MoveToXY(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x absoluta para o canto superior esquerdo do retângulo.

*Y*<br/>
A coordenada absoluta para o canto superior esquerdo do retângulo.

*Ponto*<br/>
Uma `POINT` estrutura especificando o canto superior esquerdo absoluto do retângulo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 100, 100);
rect.MoveToXY(10, 10);
// rect is now (10, 10, 110, 110);
ASSERT(rect == CRect(10, 10, 110, 110));
```

## <a name="crectmovetoy"></a><a name="movetoy"></a>CRect::MoveToY

Chame esta função para mover o retângulo para a coordenada y absoluta especificada por *y*.

```
void MoveToY(int y) throw();
```

### <a name="parameters"></a>Parâmetros

*Y*<br/>
A coordenada absoluta para o canto superior esquerdo do retângulo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 100, 100);
rect.MoveToY(10);
// rect is now (0, 10, 100, 110);
ASSERT(rect == CRect(0, 10, 100, 110));
```

## <a name="crectnormalizerect"></a><a name="normalizerect"></a>CRect::NormalizeRect

Normaliza `CRect` de modo que tanto a altura quanto a largura sejam positivas.

```
void NormalizeRect() throw();
```

### <a name="remarks"></a>Comentários

O retângulo é normalizado para o posicionamento do quarto quadrante, que o Windows normalmente usa para coordenadas. `NormalizeRect`compara os valores superior e inferior, e os troca se a parte superior for maior que a inferior. Da mesma forma, ele troca os valores esquerdo e direito se a esquerda for maior que a direita. Esta função é útil ao lidar com diferentes modos de mapeamento e retângulos invertidos.

> [!NOTE]
> As `CRect` seguintes funções de membro requerem retângulos normalizados para funcionar corretamente: [Altura,](#height) [largura,](#width) [tamanho,](#size) [isretovazio,](#isrectempty) [ptInRect,](#ptinrect) [EqualRect,](#equalrect) [UnionRect,](#unionrect) [IntersectRect,](#intersectrect) [SubtractRect,](#subtractrect) [operador ==](#operator_eq_eq), [operador !=](#operator_neq), [operador &#124;](#operator_or), operador &#124;[=](#operator_or_eq), [operador &](#operator_amp)e operador &[= .](#operator_amp_eq)

### <a name="example"></a>Exemplo

```cpp
CRect rect1(110, 100, 250, 310);
CRect rect2(250, 310, 110, 100);
rect1.NormalizeRect();
rect2.NormalizeRect();
ASSERT(rect1 == rect2);
```

## <a name="crectoffsetrect"></a><a name="offsetrect"></a>CRect::OffsetRect

Movimentos `CRect` pelas compensações especificadas.

```
void OffsetRect(int x, int y) throw();
void OffsetRect(POINT point) throw();
void OffsetRect(SIZE size) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica a quantidade para mover-se para a esquerda ou para a direita. Deve ser negativo mover-se para a esquerda.

*Y*<br/>
Especifica a quantidade para mover para cima ou para baixo. Deve ser negativo para subir.

*Ponto*<br/>
Contém uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint](cpoint-class.md) especificando ambas as dimensões pelas quais se mover.

*Tamanho*<br/>
Contém uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize](csize-class.md) especificando ambas as dimensões pelas quais se mover.

### <a name="remarks"></a>Comentários

Move `CRect` *x* unidades ao longo do eixo x e *unidades y* ao longo do eixo y. Os parâmetros *x* e *y* `CRect` são valores assinados, por isso podem ser movidos para a esquerda ou para a direita e para cima ou para baixo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 35, 35);
rect.OffsetRect(230, 230);

// rect is now (230, 230, 265, 265)
ASSERT(rect == CRect(230, 230, 265, 265));
```

## <a name="crectoperator-lpcrect-converts-a-crect-to-an-lpcrect"></a><a name="operator_lpcrect"></a>CRect::operator LPCRECT Converts a `CRect` to an [LPCRECT](../../mfc/reference/data-types-mfc.md).

```
operator LPCRECT() const throw();
```

### <a name="remarks"></a>Comentários

Quando você usa esta função, você não precisa**&** do operador de endereço de ( ) Este operador será usado automaticamente quando `CRect` você passar um `LPCRECT`objeto para uma função que espera um .

## <a name="crectoperator-lprect"></a><a name="operator_lprect"></a>CRect::operador LPRECT

Converts a `CRect` to an [LPRECT](../../mfc/reference/data-types-mfc.md).

```
operator LPRECT() throw();
```

### <a name="remarks"></a>Comentários

Quando você usa esta função, você não precisa**&** do operador de endereço de ( ) Este operador será usado automaticamente quando `CRect` você passar um `LPRECT`objeto para uma função que espera um .

### <a name="example"></a>Exemplo

Consulte o exemplo de [CRect::operador LPCRECT](#operator_lpcrect).

## <a name="crectoperator-"></a><a name="operator_eq"></a>CRect::operador =

Atribui *srcRect* `CRect`a .

```
void operator=(const RECT& srcRect) throw();
```

### <a name="parameters"></a>Parâmetros

*Srcrect*<br/>
Refere-se a um retângulo de origem. Pode ser um `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou .

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 127, 168);
CRect rect2;

rect2 = rect;
ASSERT(rect2 == CRect(0, 0, 127, 168));
```

## <a name="crectoperator-"></a><a name="operator_eq_eq"></a>CRect::operador ==

Determina se `rect` é `CRect` igual a comparar as coordenadas dos cantos superior esquerdo e inferior direito.

```
BOOL operator==(const RECT& rect) const throw();
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Refere-se a um retângulo de origem. Pode ser um `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou .

### <a name="return-value"></a>Valor retornado

Não zero se igual; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect1(35, 150, 10, 25);
CRect rect2(35, 150, 10, 25);
CRect rect3(98, 999, 6, 3);
ASSERT(rect1 == rect2);
// works just fine against RECTs, as well

RECT test;
test.left = 35;
test.top = 150;
test.right = 10;
test.bottom = 25;

ASSERT(rect1 == test);
```

## <a name="crectoperator-"></a><a name="operator_neq"></a>CRect::operador !=

Determina se *o reto* `CRect` não é igual a comparar as coordenadas dos cantos superior-esquerdo e inferior direito.

```
BOOL operator!=(const RECT& rect) const throw();
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Refere-se a um retângulo de origem. Pode ser um `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou .

### <a name="return-value"></a>Valor retornado

Não zero se não for igual; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect1(35, 150, 10, 25);
CRect rect2(35, 150, 10, 25);
CRect rect3(98, 999,  6,  3);
ASSERT(rect1 != rect3);
// works just fine against RECTs, as well

RECT test;
test.left = 35;
test.top = 150;
test.right = 10;
test.bottom = 25;

ASSERT(rect3 != test);
```

## <a name="crectoperator-"></a><a name="operator_add_eq"></a>CRect::operador +=

As duas primeiras `CRect` sobrecargas se movem pelas compensações especificadas.

```
void operator+=(POINT point) throw();
void operator+=(SIZE size) throw();
void operator+=(LPCRECT lpRect) throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint](cpoint-class.md) que especifica o número de unidades para mover o retângulo.

*Tamanho*<br/>
Uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize](csize-class.md) que especifica o número de unidades para mover o retângulo.

*Lprect*<br/>
Aponta para uma estrutura `CRect` ou objeto [RECT](/windows/win32/api/windef/ns-windef-rect) que contenha `CRect`o número de unidades para inflar cada lado de .

### <a name="remarks"></a>Comentários

Os valores *x* *y* e y `cx` `cy`(ou) do `CRect`parâmetro são adicionados a .

A terceira sobrecarga `CRect` infla pelo número de unidades especificadas em cada membro do parâmetro.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint  pt(35, 65);
CRect   rect2(135, 300, 235, 400);

rect1 += pt;
ASSERT(rect1 == rect2);
```

## <a name="crectoperator--"></a><a name="operator_-_eq"></a>CRect::operador -=

As duas primeiras `CRect` sobrecargas se movem pelas compensações especificadas.

```
void operator-=(POINT point) throw();
void operator-=(SIZE size) throw();
void operator-=(LPCRECT lpRect) throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint](cpoint-class.md) que especifica o número de unidades para mover o retângulo.

*Tamanho*<br/>
Uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize](csize-class.md) que especifica o número de unidades para mover o retângulo.

*Lprect*<br/>
Aponta para uma estrutura `CRect` ou objeto [RECT](/windows/win32/api/windef/ns-windef-rect) que contém `CRect`o número de unidades para esvaziar cada lado de .

### <a name="remarks"></a>Comentários

Os valores *x* *y* e y `cx` `cy`(ou) do parâmetro `CRect`são subtraídos de .

A terceira sobrecarga `CRect` desinfla pelo número de unidades especificadas em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#deflaterect).

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint pt(35, 65);

rect1 -= pt;
CRect   rectResult(65, 170, 165, 270);
ASSERT(rect1 == rectResult);
```

## <a name="crectoperator-amp"></a><a name="operator_amp_eq"></a>CRect::operador&amp;=

Conjuntos `CRect` iguais ao `CRect` `rect`cruzamento de e .

```
void operator&=(const RECT& rect) throw();
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Contém um [RECT](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="remarks"></a>Comentários

A intersecção é o maior retângulo que está contido em ambos os retângulos.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

Veja o exemplo [de CRect::IntersectRect](#intersectrect).

## <a name="crectoperator-124"></a><a name="operator_or_eq"></a>CRect::&#124;do operador =

Conjuntos `CRect` iguais à `CRect` `rect`união de e .

```
void operator|=(const RECT& rect) throw();
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Contém `CRect` um ou [RECT](/windows/win32/api/windef/ns-windef-rect).

### <a name="remarks"></a>Comentários

A união é o menor retângulo que contém ambos os retângulos de origem.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);

rect1 |= rect2;
CRect   rectResult(0, 0, 300, 300);
ASSERT(rectResult == rect1);
```

## <a name="crectoperator-"></a><a name="operator_add"></a>CRect::operador +

As duas primeiras sobrecargas retornam `CRect` um `CRect` objeto que é igual a deslocado pelas compensações especificadas.

```
CRect operator+(POINT point) const throw();
CRect operator+(LPCRECT lpRect) const throw();
CRect operator+(SIZE size) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint](cpoint-class.md) que especifica o número de unidades para mover o valor de retorno.

*Tamanho*<br/>
Uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize](csize-class.md) que especifica o número de unidades para mover o valor de retorno.

*Lprect*<br/>
Aponta para uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto que contenha o número de unidades para inflar cada lado do valor de retorno.

### <a name="return-value"></a>Valor retornado

O `CRect` resultado da movimentação `CRect` ou inflação pelo número de unidades especificadas no parâmetro.

### <a name="remarks"></a>Comentários

Os parâmetros *x* *y* e y `cx` `cy`(ou) do `CRect`parâmetro são adicionados à posição do parâmetro.

A terceira sobrecarga `CRect` retorna um `CRect` novo que é igual a inflado pelo número de unidades especificadas em cada membro do parâmetro.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint pt(35, 65);
CRect   rect2;

rect2 = rect1 + pt;
CRect   rectResult(135, 300, 235, 400);
ASSERT(rectResult == rect2);
```

## <a name="crectoperator--"></a><a name="operator_-"></a>CRect::operador -

As duas primeiras sobrecargas retornam `CRect` um `CRect` objeto que é igual a deslocado pelas compensações especificadas.

```
CRect operator-(POINT point) const throw();
CRect operator-(SIZE size) const throw();
CRect operator-(LPCRECT lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Uma [POINT](/windows/win32/api/windef/ns-windef-point) estrutura `CPoint` point ou objeto que especifica o número de unidades para mover o valor de retorno.

*Tamanho*<br/>
Uma [SIZE](/windows/win32/api/windef/ns-windef-size) estrutura `CSize` OU objeto TAMANHO que especifica o número de unidades para mover o valor de retorno.

*Lprect*<br/>
Aponta para uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto que contém o número de unidades para esvaziar cada lado do valor de retorno.

### <a name="return-value"></a>Valor retornado

O `CRect` resultado da movimentação `CRect` ou deflação pelo número de unidades especificadas no parâmetro.

### <a name="remarks"></a>Comentários

Os parâmetros *x* *y* e y `cx` `cy`(ou) do parâmetro `CRect`são subtraídos da posição do parâmetro.

A terceira sobrecarga `CRect` retorna um `CRect` novo que é igual ao deflacionado pelo número de unidades especificadas em cada membro do parâmetro. Observe que esta sobrecarga funciona como [DeflateRect,](#deflaterect)não [SubtractRect](#subtractrect).

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint pt(35, 65);
CRect   rect2;

rect2 = rect1 - pt;
CRect   rectResult(65, 170, 165, 270);
ASSERT(rect2 == rectResult);
```

## <a name="crectoperator-amp"></a><a name="operator_amp"></a>CRect::operador&amp;

Retorna `CRect` a que é `CRect` a intersecção e *rect2*.

```
CRect operator&(const RECT& rect2) const throw();
```

### <a name="parameters"></a>Parâmetros

*rect2*<br/>
Contém um [RECT](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="return-value"></a>Valor retornado

A `CRect` que é `CRect` a intersecção e *rect2*.

### <a name="remarks"></a>Comentários

A intersecção é o maior retângulo que está contido em ambos os retângulos.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);
CRect   rect3;

rect3 = rect1 & rect2;
CRect   rectResult(100, 100, 200, 200);
ASSERT(rectResult == rect3);
```

## <a name="crectoperator-124"></a><a name="operator_or"></a>CRect::&#124; do operador

Retorna `CRect` a que é `CRect` a união e *rect2*.

```
CRect operator|(const RECT&
rect2) const throw();
```

### <a name="parameters"></a>Parâmetros

*rect2*<br/>
Contém um [RECT](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="return-value"></a>Valor retornado

A `CRect` que é `CRect` a união e *rect2*.

### <a name="remarks"></a>Comentários

A união é o menor retângulo que contém os dois retângulos.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);
CRect   rect3;

rect3 = rect1 | rect2;
CRect   rectResult(0, 0, 300, 300);
ASSERT(rectResult == rect3);
```

## <a name="crectptinrect"></a><a name="ptinrect"></a>CRect::PtInRect

Determina se o ponto especificado está dentro `CRect`.

```
BOOL PtInRect(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Contém uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint.](cpoint-class.md)

### <a name="return-value"></a>Valor retornado

Não zero se o `CRect`ponto estiver dentro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um ponto `CRect` está dentro se ele está no lado esquerdo ou superior ou está dentro de todos os quatro lados. Um ponto no lado direito `CRect`ou inferior está do lado de fora.

> [!NOTE]
> O retângulo deve ser normalizado ou esta função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(5, 5, 100, 100);
CPoint pt1(35, 50);
CPoint pt2(125, 298);

// this is true, because pt1 is inside the rectangle
ASSERT(rect.PtInRect(pt1));

// this is NOT true, because pt2 is outside the rectangle
ASSERT(!rect.PtInRect(pt2));

// note that the right and the bottom aren't inside
ASSERT(!rect.PtInRect(CPoint(35, 100)));
ASSERT(!rect.PtInRect(CPoint(100, 98)));

// but the top and the left are inside
ASSERT(rect.PtInRect(CPoint(5, 65)));
ASSERT(rect.PtInRect(CPoint(88, 5)));

// and that PtInRect() works against a POINT, too
POINT pt;
pt.x = 35;
pt.y = 50;
ASSERT(rect.PtInRect(pt));
```

## <a name="crectsetrect"></a><a name="setrect"></a>CRect::SetRect

Define as dimensões das `CRect` coordenadas especificadas.

```
void SetRect(int x1, int y1, int x2, int y2) throw();
```

### <a name="parameters"></a>Parâmetros

*x1*<br/>
Especifica a coordenada x do canto superior esquerdo.

*y1*<br/>
Especifica a coordenada y do canto superior esquerdo.

*x2*<br/>
Especifica a coordenada x do canto inferior direito.

*y2*<br/>
Especifica a coordenada y do canto inferior direito.

### <a name="example"></a>Exemplo

```cpp
CRect rect;
rect.SetRect(256, 256, 512, 512);
ASSERT(rect == CRect(256, 256, 512, 512));
```

## <a name="crectsetrectempty"></a><a name="setrectempty"></a>CRect::SetRectEmpty

Faz `CRect` um retângulo nulo definindo todas as coordenadas para zero.

```
void SetRectEmpty() throw();
```

### <a name="example"></a>Exemplo

```cpp
CRect rect;
rect.SetRectEmpty();

// rect is now (0, 0, 0, 0)
ASSERT(rect.IsRectEmpty());
```

## <a name="crectsize"></a><a name="size"></a>CRect::SIZE

Os `cx` `cy` membros do valor de retorno contêm a altura e a largura de `CRect`.

```
CSize Size() const throw();
```

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](csize-class.md) que `CRect`contém o tamanho de .

### <a name="remarks"></a>Comentários

Ou a altura ou largura podem ser negativas.

> [!NOTE]
> O retângulo deve ser normalizado ou esta função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(10, 10, 50, 50);
CSize sz = rect.Size();
ASSERT(sz.cx == 40 && sz.cy == 40);
```

## <a name="crectsubtractrect"></a><a name="subtractrect"></a>CRect::SubtractRect

Faz com que `CRect` as dimensões do `lpRectSrc2` `lpRectSrc1`igual à subtração de .

```
BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2) throw();
```

### <a name="parameters"></a>Parâmetros

*lpRectSrc1*<br/>
Aponta para a estrutura `CRect` [rect](/windows/win32/api/windef/ns-windef-rect) ou objeto do qual um retângulo deve ser subtraído.

*lpRectSrc2*<br/>
Aponta para `RECT` a `CRect` estrutura ou objeto a ser subtraído do retângulo apontado pelo parâmetro *lpRectSrc1.*

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A subtração é o menor retângulo que contém todos os pontos em *lpRectScr1* que não estão na intersecção de *lpRectScr1* e *lpRectScr2*.

O retângulo especificado por *lpRectSrc1* ficará inalterado se o retângulo especificado por *lpRectSrc2* não se sobrepor completamente ao retângulo especificado por *lpRectSrc1* em pelo menos uma das direções x ou y.

Por exemplo, se *lpRectSrc1* fosse (10,10, 100,100) e *lpRectSrc2* fossem (50,50, 150.150), o retângulo apontado por *lpRectSrc1* ficaria inalterado quando a função retornasse. Se *lpRectSrc1* fosse (10,10, 100,100) e *lpRectSrc2* fossem (50,10, 150.150), no entanto, o retângulo apontado por *lpRectSrc1* conteria as coordenadas (10,10, 50.100) quando a função retornasse.

`SubtractRect`não é o mesmo que [operador -](#operator_-) nem [operador -=](#operator_-_eq). Nenhum desses operadores `SubtractRect`liga.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
RECT   rectOne;
RECT   rectTwo;

rectOne.left = 10;
rectOne.top = 10;
rectOne.bottom = 100;
rectOne.right = 100;

rectTwo.left = 50;
rectTwo.top = 10;
rectTwo.bottom = 150;
rectTwo.right = 150;

CRect   rectDiff;

rectDiff.SubtractRect(&rectOne, &rectTwo);
CRect   rectResult(10, 10, 50, 100);

ASSERT(rectDiff == rectResult);

// works for CRect, too, since there is
// implicit CRect -> LPCRECT conversion

CRect rect1(10, 10, 100, 100);
CRect rect2(50, 10, 150, 150);
CRect rectOut;

rectOut.SubtractRect(rect1, rect2);
ASSERT(rectResult == rectOut);
```

## <a name="crecttopleft"></a><a name="topleft"></a>CRect::TopLeft

As coordenadas são retornadas como uma referência a `CRect`um objeto [CPoint](cpoint-class.md) que está contido em .

```
CPoint& TopLeft() throw();
const CPoint& TopLeft() const throw();
```

### <a name="return-value"></a>Valor retornado

As coordenadas do canto superior esquerdo do retângulo.

### <a name="remarks"></a>Comentários

Você pode usar esta função para obter ou definir o canto superior esquerdo do retângulo. Defina o canto usando esta função no lado esquerdo do operador de atribuição.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRect::CenterPoint](#centerpoint).

## <a name="crectunionrect"></a><a name="unionrect"></a>CRect::UnionRect

Torna as dimensões `CRect` iguais à união dos dois retângulos de origem.

```
BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();
```

### <a name="parameters"></a>Parâmetros

*lpRect1*<br/>
Aponta para um `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou que contenha um retângulo de origem.

*lpRect2*<br/>
Aponta para `RECT` `CRect` um ou que contém um retângulo de origem.

### <a name="return-value"></a>Valor retornado

Não zero se a união não estiver vazia; 0 se o sindicato estiver vazio.

### <a name="remarks"></a>Comentários

A união é o menor retângulo que contém ambos os retângulos de origem.

O Windows ignora as dimensões de um retângulo vazio; ou seja, um retângulo que não tem altura ou não tem largura.

> [!NOTE]
> Ambos os retângulos devem ser normalizados ou esta função pode falhar. Você pode ligar para [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);
CRect   rect3;

rect3.UnionRect(&rect1, &rect2);
CRect   rectResult(0, 0, 300, 300);
ASSERT(rectResult == rect3);
```

## <a name="crectwidth"></a><a name="width"></a>CRect::Largura

Calcula a `CRect` largura de subtraindo o valor esquerdo do valor direito.

```
int Width() const throw();
```

### <a name="return-value"></a>Valor retornado

A largura `CRect`de .

### <a name="remarks"></a>Comentários

A largura pode ser negativa.

> [!NOTE]
> O retângulo deve ser normalizado ou esta função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar esta função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(20, 30, 80, 70);
int nWid = rect.Width();
// nWid is now 60
ASSERT(nWid == 60);
```

## <a name="see-also"></a>Confira também

[Classe CPoint](cpoint-class.md)<br/>
[Classe CSize](csize-class.md)<br/>
[Rect](/windows/win32/api/windef/ns-windef-rect)
