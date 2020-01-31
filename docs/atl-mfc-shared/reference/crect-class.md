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
ms.openlocfilehash: 13f86c411cca98f5817d1b3b2d9162ae8af8b734
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821363"
---
# <a name="crect-class"></a>Classe CRect

Semelhante a uma estrutura de [Rect](/windows/win32/api/windef/ns-windef-rect) do Windows.

## <a name="syntax"></a>Sintaxe

```
class CRect : public tagRECT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Name|Descrição|
|----------|-----------------|
|[CRect::CRect](#crect)|Constrói um objeto `CRect`.|

### <a name="public-methods"></a>Métodos Públicos

|Name|Descrição|
|----------|-----------------|
|[CRect::BottomRight](#bottomright)|Retorna o ponto inferior direito de `CRect`.|
|[CRect::CenterPoint](#centerpoint)|Retorna o centerpoint de `CRect`.|
|[CRect::CopyRect](#copyrect)|Copia as dimensões de um retângulo de origem para `CRect`.|
|[CRect::DeflateRect](#deflaterect)|Diminui a largura e a altura de `CRect`.|
|[CRect::EqualRect](#equalrect)|Determina se `CRect` é igual ao retângulo fornecido.|
|[CRect::Height](#height)|Calcula a altura de `CRect`.|
|[CRect::InflateRect](#inflaterect)|Aumenta a largura e a altura de `CRect`.|
|[CRect::IntersectRect](#intersectrect)|Define `CRect` igual à interseção de dois retângulos.|
|[CRect::IsRectEmpty](#isrectempty)|Determina se `CRect` está vazia. `CRect` estará vazio se a largura e/ou altura forem 0.|
|[CRect::IsRectNull](#isrectnull)|Determina se as variáveis de membro `top`, `bottom`, `left`e `right` são todas iguais a 0.|
|[CRect::MoveToX](#movetox)|Move `CRect` para a coordenada x especificada.|
|[CRect::MoveToXY](#movetoxy)|Move `CRect` para as coordenadas x e y especificadas.|
|[CRect::MoveToY](#movetoy)|Move `CRect` para a coordenada y especificada.|
|[CRect::NormalizeRect](#normalizerect)|Padroniza a altura e a largura de `CRect`.|
|[CRect::OffsetRect](#offsetrect)|Move `CRect` pelos deslocamentos especificados.|
|[CRect::PtInRect](#ptinrect)|Determina se o ponto especificado está dentro de `CRect`.|
|[CRect::SetRect](#setrect)|Define as dimensões de `CRect`.|
|[CRect::SetRectEmpty](#setrectempty)|Define `CRect` como um retângulo vazio (todas as coordenadas são iguais a 0).|
|[CRect:: tamanho](#size)|Calcula o tamanho de `CRect`.|
|[CRect::SubtractRect](#subtractrect)|Subtrai um retângulo de outro.|
|[CRect::TopLeft](#topleft)|Retorna o ponto superior esquerdo de `CRect`.|
|[CRect::UnionRect](#unionrect)|Define `CRect` igual à União de dois retângulos.|
|[CRect::Width](#width)|Calcula a largura de `CRect`.|

### <a name="public-operators"></a>Operadores públicos

|Name|Descrição|
|----------|-----------------|
|[Operador CRect:: Operator](#operator_-)|Subtrai os deslocamentos fornecidos de `CRect` ou desflate `CRect` e retorna o `CRect`resultante.|
|[Operador CRect:: Operator LPCRECT](#operator_lpcrect)|Converte um `CRect` em um `LPCRECT`.|
|[Operador CRect:: Operator LPRECT](#operator_lprect)|Converte um `CRect` em um `LPRECT`.|
|[CRect:: Operator! =](#operator_neq)|Determina se `CRect` não é igual a um retângulo.|
|[Operador CRect:: Operator &amp;](#operator_amp)|Cria a interseção de `CRect` e um retângulo e retorna o `CRect`resultante.|
|[CRect:: Operator &amp;=](#operator_amp_eq)|Define `CRect` igual à interseção de `CRect` e um retângulo.|
|[Operador CRect::&#124;](#operator_or)|Cria a União de `CRect` e um retângulo e retorna o `CRect`resultante.|
|[CRect:: Operator &#124;=](#operator_or_eq)|Define `CRect` igual à União de `CRect` e um retângulo.|
|[CRect:: Operator +](#operator_add)|Adiciona os deslocamentos fornecidos a `CRect` ou a `CRect`s e retorna o `CRect`resultante.|
|[CRect:: Operator + =](#operator_add_eq)|Adiciona os deslocamentos especificados a `CRect` ou a `CRect`inplanas.|
|[CRect:: Operator =](#operator_eq)|Copia as dimensões de um retângulo para `CRect`.|
|[CRect:: Operator-=](#operator_-_eq)|Subtrai os deslocamentos especificados de `CRect` ou desflate `CRect`.|
|[CRect:: Operator = =](#operator_eq_eq)|Determina se `CRect` é igual a um retângulo.|

## <a name="remarks"></a>Comentários

`CRect` também inclui funções de membro para manipular objetos `CRect` e estruturas de `RECT` do Windows.

Um objeto `CRect` pode ser passado como um parâmetro de função sempre que uma estrutura `RECT`, `LPCRECT`ou `LPRECT` pode ser passada.

> [!NOTE]
> Essa classe é derivada da estrutura de `tagRECT`. (O nome `tagRECT` é um nome usado com menos frequência para a estrutura de `RECT`.) Isso significa que os membros de dados (`left`, `top`, `right`e `bottom`) da estrutura de `RECT` são membros de dados acessíveis de `CRect`.

Uma `CRect` contém variáveis de membro que definem os pontos superior esquerdo e inferior direito de um retângulo.

Ao especificar um `CRect`, você deve ter cuidado para construí-lo para que ele seja normalizado — em outras palavras, de modo que o valor da coordenada à esquerda seja menor do que o direito e o topo seja menor que o inferior. Por exemplo, uma parte superior esquerda de (10, 10) e inferior direita de (20, 20) define um retângulo normalizado, mas uma parte superior esquerda de (20, 20) e inferior direita de (10, 10) define um retângulo não normalizado. Se o retângulo não for normalizado, muitas `CRect` funções membro poderão retornar resultados incorretos. (Consulte [CRect:: NormalizeRect](#normalizerect) para obter uma lista dessas funções.) Antes de chamar uma função que requer retângulos normalizados, você pode normalizar retângulos não normalizados chamando a função `NormalizeRect`.

Tome cuidado ao manipular um `CRect` com as funções de membro [CDC::D ptolp](../../mfc/reference/cdc-class.md#dptolp) e [CDC:: LPtoDP](../../mfc/reference/cdc-class.md#lptodp) . Se o modo de mapeamento de um contexto de exibição for de tal forma que a extensão y seja negativa, como em `MM_LOENGLISH`, `CDC::DPtoLP` transformará a `CRect` para que sua parte superior seja maior que a parte inferior. Funções como `Height` e `Size` retornarão valores negativos para a altura da `CRect`transformada e o retângulo será não normalizado.

Ao usar operadores de `CRect` sobrecarregados, o primeiro operando deve ser um `CRect`; o segundo pode ser uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou um objeto `CRect`.

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

`tagRECT`

`CRect`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** atltypes. h

##  <a name="bottomright"></a>  CRect::BottomRight

As coordenadas são retornadas como uma referência a um objeto [CPoint](cpoint-class.md) que está contido em `CRect`.

```
CPoint& BottomRight() throw();
const CPoint& BottomRight() const throw();
```

### <a name="return-value"></a>Valor de retorno

As coordenadas do canto inferior direito do retângulo.

### <a name="remarks"></a>Comentários

Você pode usar essa função para obter ou definir o canto inferior direito do retângulo. Defina o canto usando essa função no lado esquerdo do operador de atribuição.

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

##  <a name="centerpoint"></a>  CRect::CenterPoint

Calcula o centerpoint de `CRect` adicionando os valores esquerdo e direito e dividindo por dois e adicionando os valores superior e inferior e dividindo por dois.

```
CPoint CenterPoint() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um objeto `CPoint` que é o centerpoint de `CRect`.

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

##  <a name="copyrect"></a>  CRect::CopyRect

Copia o `lpSrcRect` retângulo em `CRect`.

```
void CopyRect(LPCRECT lpSrcRect) throw();
```

### <a name="parameters"></a>Parâmetros

*lpSrcRect*<br/>
Aponta para a estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect` objeto a ser copiado.

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

##  <a name="crect"></a>  CRect::CRect

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

*l*<br/>
Especifica a posição esquerda de `CRect`.

*t*<br/>
Especifica a parte superior de `CRect`.

*r*<br/>
Especifica a posição correta de `CRect`.

*b*<br/>
Especifica a parte inferior do `CRect`.

*srcRect*<br/>
Refere-se à estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) com as coordenadas de `CRect`.

*lpSrcRect*<br/>
Aponta para a estrutura de `RECT` com as coordenadas de `CRect`.

*point*<br/>
Especifica o ponto de origem para o retângulo a ser construído. Corresponde ao canto superior esquerdo.

*size*<br/>
Especifica o deslocamento do canto superior esquerdo para o canto inferior direito do retângulo a ser construído.

*topLeft*<br/>
Especifica a posição superior esquerda de `CRect`.

*bottomRight*<br/>
Especifica a posição inferior direita de `CRect`.

### <a name="remarks"></a>Comentários

Se nenhum argumento for fornecido, os membros `left`, `top`, `right`e `bottom` não serão inicializados.

Os construtores `CRect`(`const RECT&`) e `CRect`(`LPCRECT`) executam um [CopyRect](#copyrect). Os outros construtores inicializam as variáveis de membro do objeto diretamente.

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

##  <a name="deflaterect"></a>  CRect::DeflateRect

`DeflateRect` desflate `CRect` movendo seus lados para o seu centro.

```
void DeflateRect(int x, int y) throw();
void DeflateRect(SIZE size) throw();
void DeflateRect(LPCRECT lpRect) throw();
void DeflateRect(int l, int t, int r, int b) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o número de unidades para desinflar os lados esquerdo e direito de `CRect`.

*y*<br/>
Especifica o número de unidades para desinflar a parte superior e inferior da `CRect`.

*size*<br/>
Um [tamanho](/windows/win32/api/windef/ns-windef-size) ou [CSize](csize-class.md) que especifica o número de unidades a serem desinfladas `CRect`. O valor de `cx` especifica o número de unidades para desinflar os lados esquerdo e direito e o valor de `cy` especifica o número de unidades para desinflar a parte superior e inferior.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect` que especifica o número de unidades para Desinflar cada lado.

*l*<br/>
Especifica o número de unidades para desinflar o lado esquerdo da `CRect`.

*t*<br/>
Especifica o número de unidades para desinflar a parte superior da `CRect`.

*r*<br/>
Especifica o número de unidades para desinflar o lado direito de `CRect`.

*b*<br/>
Especifica o número de unidades para desinflar a parte inferior da `CRect`.

### <a name="remarks"></a>Comentários

Para fazer isso, `DeflateRect` adiciona unidades à esquerda e à parte superior e subtrai as unidades da direita e da parte inferior. Os parâmetros de `DeflateRect` são valores assinados; valores positivos deflatem `CRect` e valores negativos o inflam.

As duas primeiras sobrecargas Desinflam os dois pares de lados opostos de `CRect` para que sua largura total seja diminuída por duas vezes *x* (ou `cx`) e sua altura total seja reduzida em duas vezes *y* (ou `cy`). As outras duas sobrecargas Desinflam cada lado da `CRect` independentemente das outras.

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

##  <a name="equalrect"></a>  CRect::EqualRect

Determina se `CRect` é igual ao retângulo fornecido.

```
BOOL EqualRect(LPCRECT lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto `CRect`  que contém as coordenadas de canto superior esquerdo e inferior direito de um retângulo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os dois retângulos tiverem os mesmos valores superior, esquerdo, inferior e direito; caso contrário, 0.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

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

##  <a name="height"></a>  CRect::Height

Calcula a altura de `CRect` subtraindo o valor superior do valor inferior.

```
int Height() const throw();
```

### <a name="return-value"></a>Valor de retorno

A altura de `CRect`.

### <a name="remarks"></a>Comentários

O valor resultante pode ser negativo.

> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(20, 30, 80, 70);
int nHt = rect.Height();

// nHt is now 40
ASSERT(nHt == 40);
```

##  <a name="inflaterect"></a>  CRect::InflateRect

`InflateRect` inplana `CRect` movendo seus lados para longe do seu centro.

```
void InflateRect(int x, int y) throw();
void InflateRect(SIZE size) throw();
void InflateRect(LPCRECT lpRect) throw();
void InflateRect(int l, int t, int r,  int b) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o número de unidades para inflar os lados esquerdo e direito de `CRect`.

*y*<br/>
Especifica o número de unidades para inflar a parte superior e inferior de `CRect`.

*size*<br/>
Um [tamanho](/windows/win32/api/windef/ns-windef-size) ou [CSize](csize-class.md) que especifica o número de unidades a serem infladas `CRect`. O valor de `cx` especifica o número de unidades para aumentar os lados esquerdo e direito e o valor de `cy` especifica o número de unidades para inflar a parte superior e inferior.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect` que especifica o número de unidades para inflar cada lado.

*l*<br/>
Especifica o número de unidades para inflar o lado esquerdo de `CRect`.

*t*<br/>
Especifica o número de unidades para inflar a parte superior de `CRect`.

*r*<br/>
Especifica o número de unidades para inflar o lado direito de `CRect`.

*b*<br/>
Especifica o número de unidades para inflar a parte inferior da `CRect`.

### <a name="remarks"></a>Comentários

Para fazer isso, `InflateRect` subtrai as unidades da esquerda e da parte superior e adiciona as unidades à direita e à parte inferior. Os parâmetros de `InflateRect` são valores assinados; os valores positivos inflam `CRect` e valores negativos Desinflam.

As duas primeiras sobrecargas esgotam os dois pares de lados opostos de `CRect` para que sua largura total seja aumentada em duas vezes *x* (ou `cx`) e sua altura total seja aumentada em duas vezes *y* (ou `cy`). As outras duas sobrecargas inflam cada lado da `CRect` independentemente das outras.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 300, 300);
rect.InflateRect(50, 200);

// rect is now (-50, -200, 350, 500)
ASSERT(rect == CRect(-50, -200, 350, 500));
```

##  <a name="intersectrect"></a>  CRect::IntersectRect

Faz uma `CRect` igual à interseção de dois retângulos existentes.

```
BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();
```

### <a name="parameters"></a>Parâmetros

*lpRect1*<br/>
Aponta para uma estrutura de [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto `CRect` que contém um retângulo de origem.

*lpRect2*<br/>
Aponta para uma estrutura de `RECT` ou `CRect` objeto que contém um retângulo de origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a interseção não estiver vazia; 0 se a interseção estiver vazia.

### <a name="remarks"></a>Comentários

A interseção é o maior retângulo contido em ambos os retângulos existentes.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

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

##  <a name="isrectempty"></a>  CRect::IsRectEmpty

Determina se `CRect` está vazia.

```
BOOL IsRectEmpty() const throw();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se `CRect` estiver vazio; 0 se `CRect` não estiver vazia.

### <a name="remarks"></a>Comentários

Um retângulo estará vazio se a largura e/ou altura for 0 ou negativo. Difere de `IsRectNull`, que determina se todas as coordenadas do retângulo são zero.

> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect rectNone(0, 0, 0, 0);
CRect rectSome(35, 50, 135, 150);
ASSERT(rectNone.IsRectEmpty());
ASSERT(!rectSome.IsRectEmpty());
CRect rectEmpty(35, 35, 35, 35);
ASSERT(rectEmpty.IsRectEmpty());
```

##  <a name="isrectnull"></a>  CRect::IsRectNull

Determina se os valores superior, esquerdo, inferior e direito de `CRect` são iguais a 0.

```
BOOL IsRectNull() const throw();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os valores superiores, esquerdo, inferior e direito do `CRect`forem iguais a 0; caso contrário, 0.

### <a name="remarks"></a>Comentários

Difere de `IsRectEmpty`, que determina se o retângulo está vazio.

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

##  <a name="movetox"></a>  CRect::MoveToX

Chame essa função para mover o retângulo para a coordenada x absoluta especificada por *x*.

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

##  <a name="movetoxy"></a>  CRect::MoveToXY

Chame essa função para mover o retângulo para as coordenadas x e y absolutas especificadas.

```
void MoveToXY(int x, int y) throw();
void MoveToXY(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x absoluta para o canto superior esquerdo do retângulo.

*y*<br/>
A coordenada y absoluta para o canto superior esquerdo do retângulo.

*point*<br/>
Uma estrutura de `POINT` especificando o canto superior esquerdo absoluto do retângulo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 100, 100);
rect.MoveToXY(10, 10);
// rect is now (10, 10, 110, 110);
ASSERT(rect == CRect(10, 10, 110, 110));
```

##  <a name="movetoy"></a>  CRect::MoveToY

Chame essa função para mover o retângulo para a coordenada y absoluta especificada por *y*.

```
void MoveToY(int y) throw();
```

### <a name="parameters"></a>Parâmetros

*y*<br/>
A coordenada y absoluta para o canto superior esquerdo do retângulo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 100, 100);
rect.MoveToY(10);
// rect is now (0, 10, 100, 110);
ASSERT(rect == CRect(0, 10, 100, 110));
```

##  <a name="normalizerect"></a>  CRect::NormalizeRect

Normaliza `CRect` para que a altura e a largura sejam positivas.

```
void NormalizeRect() throw();
```

### <a name="remarks"></a>Comentários

O retângulo é normalizado para o posicionamento de quarto quadrante, que o Windows normalmente usa para as coordenadas. `NormalizeRect` compara os valores superior e inferior e os troca se a parte superior for maior que a parte inferior. Da mesma forma, ele troca os valores esquerdo e direito se a esquerda for maior que a direita. Essa função é útil ao lidar com diferentes modos de mapeamento e retângulos invertidos.

> [!NOTE]
> As funções de membro `CRect` a seguir exigem retângulos normalizados para funcionar corretamente: [altura](#height), [largura](#width), [tamanho](#size), [IsRectEmpty](#isrectempty), [PtInRect](#ptinrect), [EqualRect](#equalrect), [UnionRect](#unionrect), [IntersectRect](#intersectrect), [SubtractRect](#subtractrect), [Operator = =](#operator_eq_eq), [Operator! =](#operator_neq), [ &#124;Operator, Operator ](#operator_or) [ &#124;=](#operator_or_eq), [Operator &](#operator_amp)e [Operator & =](#operator_amp_eq).

### <a name="example"></a>Exemplo

```cpp
CRect rect1(110, 100, 250, 310);
CRect rect2(250, 310, 110, 100);
rect1.NormalizeRect();
rect2.NormalizeRect();
ASSERT(rect1 == rect2);
```

##  <a name="offsetrect"></a>  CRect::OffsetRect

Move `CRect` pelos deslocamentos especificados.

```
void OffsetRect(int x, int y) throw();
void OffsetRect(POINT point) throw();
void OffsetRect(SIZE size) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Especifica o valor a ser movido para a esquerda ou para a direita. Ele deve ser negativo para mover para a esquerda.

*y*<br/>
Especifica o valor a ser movido para cima ou para baixo. Ele deve ser negativo para mover para cima.

*point*<br/>
Contém um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](cpoint-class.md) especificando ambas as dimensões pelas quais mover.

*size*<br/>
Contém uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](csize-class.md) especificando ambas as dimensões pelas quais mover.

### <a name="remarks"></a>Comentários

Move `CRect`unidades *x* ao longo do eixo x e das unidades *y* ao longo do eixo y. Os parâmetros *x* e *y* são valores assinados, portanto `CRect` podem ser movidos para a esquerda ou para a direita e para cima ou para baixo.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 35, 35);
rect.OffsetRect(230, 230);

// rect is now (230, 230, 265, 265)
ASSERT(rect == CRect(230, 230, 265, 265));
```

##  <a name="operator_lpcrect"></a>CRect:: Operator LPCRECT converte um `CRect` em um [LPCRECT](../../mfc/reference/data-types-mfc.md).

```
operator LPCRECT() const throw();
```

### <a name="remarks"></a>Comentários

Ao usar essa função, você não precisa do operador de endereço ( **&** ). Esse operador será usado automaticamente quando você passar um objeto `CRect` para uma função que espera uma `LPCRECT`.

##  <a name="operator_lprect"></a>Operador CRect:: Operator LPRECT

Converte um `CRect` em um [lpRect](../../mfc/reference/data-types-mfc.md).

```
operator LPRECT() throw();
```

### <a name="remarks"></a>Comentários

Ao usar essa função, você não precisa do operador de endereço ( **&** ). Esse operador será usado automaticamente quando você passar um objeto `CRect` para uma função que espera uma `LPRECT`.

### <a name="example"></a>Exemplo

Consulte o exemplo para [CRect:: Operator LPCRECT](#operator_lpcrect).

##  <a name="operator_eq"></a>  CRect::operator =

Atribui *srcRect* a `CRect`.

```
void operator=(const RECT& srcRect) throw();
```

### <a name="parameters"></a>Parâmetros

*srcRect*<br/>
Refere-se a um retângulo de origem. Pode ser um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="example"></a>Exemplo

```cpp
CRect rect(0, 0, 127, 168);
CRect rect2;

rect2 = rect;
ASSERT(rect2 == CRect(0, 0, 127, 168));
```

##  <a name="operator_eq_eq"></a>CRect:: Operator = =

Determina se `rect` é igual a `CRect` comparando as coordenadas dos cantos superior esquerdo e inferior direito.

```
BOOL operator==(const RECT& rect) const throw();
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Refere-se a um retângulo de origem. Pode ser um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for igual; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

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

##  <a name="operator_neq"></a>CRect:: Operator! =

Determina se *Rect* não é igual a `CRect` comparando as coordenadas dos cantos superior esquerdo e inferior direito.

```
BOOL operator!=(const RECT& rect) const throw();
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Refere-se a um retângulo de origem. Pode ser um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se não for igual; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

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

##  <a name="operator_add_eq"></a>CRect:: Operator + =

As duas primeiras sobrecargas se movem `CRect` pelos deslocamentos especificados.

```
void operator+=(POINT point) throw();
void operator+=(SIZE size) throw();
void operator+=(LPCRECT lpRect) throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](cpoint-class.md) que especifica o número de unidades para mover o retângulo.

*size*<br/>
Uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](csize-class.md) que especifica o número de unidades para mover o retângulo.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto `CRect` que contém o número de unidades para aumentar cada lado de `CRect`.

### <a name="remarks"></a>Comentários

Os valores *x* e *y* (ou `cx` e `cy`) do parâmetro são adicionados a `CRect`.

A terceira sobrecarga não replana `CRect` pelo número de unidades especificado em cada membro do parâmetro.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint  pt(35, 65);
CRect   rect2(135, 300, 235, 400);

rect1 += pt;
ASSERT(rect1 == rect2);
```

##  <a name="operator_-_eq"></a>CRect:: Operator-=

As duas primeiras sobrecargas se movem `CRect` pelos deslocamentos especificados.

```
void operator-=(POINT point) throw();
void operator-=(SIZE size) throw();
void operator-=(LPCRECT lpRect) throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](cpoint-class.md) que especifica o número de unidades para mover o retângulo.

*size*<br/>
Uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](csize-class.md) que especifica o número de unidades para mover o retângulo.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto `CRect` que contém o número de unidades para Desinflar cada lado de `CRect`.

### <a name="remarks"></a>Comentários

Os valores *x* e *y* (ou `cx` e `cy`) do parâmetro são subtraídos do `CRect`.

A terceira sobrecarga desflate `CRect` pelo número de unidades especificado em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#deflaterect).

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint pt(35, 65);

rect1 -= pt;
CRect   rectResult(65, 170, 165, 270);
ASSERT(rect1 == rectResult);
```

##  <a name="operator_amp_eq"></a>CRect:: Operator &amp;=

Define `CRect` igual à interseção de `CRect` e `rect`.

```
void operator&=(const RECT& rect) throw();
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Contém um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="remarks"></a>Comentários

A interseção é o maior retângulo contido em ambos os retângulos.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CRect:: IntersectRect](#intersectrect).

##  <a name="operator_or_eq"></a>CRect:: Operator &#124;=

Define `CRect` igual à União de `CRect` e `rect`.

```
void operator|=(const RECT& rect) throw();
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Contém um `CRect` ou [Rect](/windows/win32/api/windef/ns-windef-rect).

### <a name="remarks"></a>Comentários

A União é o menor retângulo que contém os dois retângulos de origem.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);

rect1 |= rect2;
CRect   rectResult(0, 0, 300, 300);
ASSERT(rectResult == rect1);
```

##  <a name="operator_add"></a>CRect:: Operator +

As duas primeiras sobrecargas retornam um objeto `CRect` que é igual a `CRect` desalocadas pelos deslocamentos especificados.

```
CRect operator+(POINT point) const throw();
CRect operator+(LPCRECT lpRect) const throw();
CRect operator+(SIZE size) const throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](cpoint-class.md) que especifica o número de unidades para mover o valor de retorno.

*size*<br/>
Uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](csize-class.md) que especifica o número de unidades para mover o valor de retorno.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto `CRect` que contém o número de unidades para aumentar cada lado do valor de retorno.

### <a name="return-value"></a>Valor de retorno

O `CRect` resultante da movimentação ou do reflate `CRect` pelo número de unidades especificado no parâmetro.

### <a name="remarks"></a>Comentários

Os parâmetros *x* e *y* (ou `cx` e `cy`) do parâmetro são adicionados à posição de `CRect`.

A terceira sobrecarga retorna uma nova `CRect` que é igual a `CRect` inplanada pelo número de unidades especificado em cada membro do parâmetro.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint pt(35, 65);
CRect   rect2;

rect2 = rect1 + pt;
CRect   rectResult(135, 300, 235, 400);
ASSERT(rectResult == rect2);
```

##  <a name="operator_-"></a>Operador CRect:: Operator

As duas primeiras sobrecargas retornam um objeto `CRect` que é igual a `CRect` desalocadas pelos deslocamentos especificados.

```
CRect operator-(POINT point) const throw();
CRect operator-(SIZE size) const throw();
CRect operator-(LPCRECT lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Uma estrutura [de ponto](/windows/win32/api/windef/ns-windef-point) ou um objeto `CPoint` que especifica o número de unidades para mover o valor de retorno.

*size*<br/>
Uma estrutura [de tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto `CSize` que especifica o número de unidades para mover o valor de retorno.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto `CRect` que contém o número de unidades para Desinflar cada lado do valor de retorno.

### <a name="return-value"></a>Valor de retorno

O `CRect` resultante da movimentação ou desflatação `CRect` pelo número de unidades especificado no parâmetro.

### <a name="remarks"></a>Comentários

Os parâmetros *x* e *y* (ou `cx` e `cy`) do parâmetro são subtraídos da posição `CRect`.

A terceira sobrecarga retorna um novo `CRect` que é igual a `CRect` desflatado pelo número de unidades especificado em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#deflaterect), não [SubtractRect](#subtractrect).

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100, 235, 200, 335);
CPoint pt(35, 65);
CRect   rect2;

rect2 = rect1 - pt;
CRect   rectResult(65, 170, 165, 270);
ASSERT(rect2 == rectResult);
```

##  <a name="operator_amp"></a>Operador CRect:: Operator &amp;

Retorna um `CRect` que é a interseção de `CRect` e *rect2*.

```
CRect operator&(const RECT& rect2) const throw();
```

### <a name="parameters"></a>Parâmetros

*rect2*<br/>
Contém um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="return-value"></a>Valor de retorno

Uma `CRect` que é a interseção de `CRect` e *rect2*.

### <a name="remarks"></a>Comentários

A interseção é o maior retângulo contido em ambos os retângulos.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);
CRect   rect3;

rect3 = rect1 & rect2;
CRect   rectResult(100, 100, 200, 200);
ASSERT(rectResult == rect3);
```

##  <a name="operator_or"></a>Operador CRect::&#124;

Retorna um `CRect` que é a União de `CRect` e *rect2*.

```
CRect operator|(const RECT&
rect2) const throw();
```

### <a name="parameters"></a>Parâmetros

*rect2*<br/>
Contém um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect`.

### <a name="return-value"></a>Valor de retorno

Uma `CRect` que é a União de `CRect` e *rect2*.

### <a name="remarks"></a>Comentários

A União é o menor retângulo que contém os dois retângulos.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);
CRect   rect3;

rect3 = rect1 | rect2;
CRect   rectResult(0, 0, 300, 300);
ASSERT(rectResult == rect3);
```

##  <a name="ptinrect"></a>  CRect::PtInRect

Determina se o ponto especificado está dentro de `CRect`.

```
BOOL PtInRect(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Contém um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](cpoint-class.md) .

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o ponto estiver dentro de `CRect`; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um ponto está dentro `CRect` se ele está no lado esquerdo ou superior ou está dentro de todos os quatro lados. Um ponto no lado direito ou inferior está fora `CRect`.

> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar essa função.

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

##  <a name="setrect"></a>  CRect::SetRect

Define as dimensões de `CRect` para as coordenadas especificadas.

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

*Y2*<br/>
Especifica a coordenada y do canto inferior direito.

### <a name="example"></a>Exemplo

```cpp
CRect rect;
rect.SetRect(256, 256, 512, 512);
ASSERT(rect == CRect(256, 256, 512, 512));
```

##  <a name="setrectempty"></a>  CRect::SetRectEmpty

Faz `CRect` um retângulo nulo definindo todas as coordenadas como zero.

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

##  <a name="size"></a>  CRect::SIZE

Os membros `cx` e `cy` do valor de retorno contêm a altura e a largura de `CRect`.

```
CSize Size() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um objeto [CSize](csize-class.md) que contém o tamanho de `CRect`.

### <a name="remarks"></a>Comentários

A altura ou a largura pode ser negativa.

> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(10, 10, 50, 50);
CSize sz = rect.Size();
ASSERT(sz.cx == 40 && sz.cy == 40);
```

##  <a name="subtractrect"></a>  CRect::SubtractRect

Torna as dimensões do `CRect` igual à subtração de `lpRectSrc2` de `lpRectSrc1`.

```
BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2) throw();
```

### <a name="parameters"></a>Parâmetros

*lpRectSrc1*<br/>
Aponta para a estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect` objeto do qual um retângulo deve ser subtraído.

*lpRectSrc2*<br/>
Aponta para a estrutura de `RECT` ou `CRect` objeto que deve ser subtraído do retângulo apontado pelo parâmetro *lpRectSrc1* .

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A subtração é o menor retângulo que contém todos os pontos em *lpRectScr1* que não estão na interseção de *lpRectScr1* e *lpRectScr2*.

O retângulo especificado por *lpRectSrc1* não será alterado se o retângulo especificado por *lpRectSrc2* não sobrepor completamente o retângulo especificado por *lpRectSrc1* em pelo menos uma das direções x ou y.

Por exemplo, se *lpRectSrc1* fossem (10, 10, 100.100) e *lpRectSrc2* eram (50, 50, 150.150), o retângulo apontado por *lpRectSrc1* seria inalterado quando a função era retornada. Se *lpRectSrc1* eram (10, 10, 100.100) e *lpRectSrc2* eram (50, 10, 150.150), no entanto, o retângulo apontado por *lpRectSrc1* conteria as coordenadas (10, 10, 50.100) quando a função fosse retornada.

`SubtractRect` não é o mesmo que [Operator-](#operator_-) nem [Operator-=](#operator_-_eq). Nenhum desses operadores nunca chama `SubtractRect`.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

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

##  <a name="topleft"></a>  CRect::TopLeft

As coordenadas são retornadas como uma referência a um objeto [CPoint](cpoint-class.md) que está contido em `CRect`.

```
CPoint& TopLeft() throw();
const CPoint& TopLeft() const throw();
```

### <a name="return-value"></a>Valor de retorno

As coordenadas do canto superior esquerdo do retângulo.

### <a name="remarks"></a>Comentários

Você pode usar essa função para obter ou definir o canto superior esquerdo do retângulo. Defina o canto usando essa função no lado esquerdo do operador de atribuição.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CRect:: CenterPoint](#centerpoint).

##  <a name="unionrect"></a>  CRect::UnionRect

Torna as dimensões de `CRect` iguais à União dos dois retângulos de origem.

```
BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();
```

### <a name="parameters"></a>Parâmetros

*lpRect1*<br/>
Aponta para um [Rect](/windows/win32/api/windef/ns-windef-rect) ou `CRect` que contém um retângulo de origem.

*lpRect2*<br/>
Aponta para um `RECT` ou `CRect` que contém um retângulo de origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a União não estiver vazia; 0 se a União estiver vazia.

### <a name="remarks"></a>Comentários

A União é o menor retângulo que contém os dois retângulos de origem.

O Windows ignora as dimensões de um retângulo vazio; ou seja, um retângulo que não tem altura ou não tem largura.

> [!NOTE]
>  Os dois retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar os retângulos antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect   rect1(100,  0, 200, 300);
CRect   rect2(0, 100, 300, 200);
CRect   rect3;

rect3.UnionRect(&rect1, &rect2);
CRect   rectResult(0, 0, 300, 300);
ASSERT(rectResult == rect3);
```

##  <a name="width"></a>  CRect::Width

Calcula a largura de `CRect` subtraindo o valor esquerdo do valor correto.

```
int Width() const throw();
```

### <a name="return-value"></a>Valor de retorno

A largura de `CRect`.

### <a name="remarks"></a>Comentários

A largura pode ser negativa.

> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) para normalizar o retângulo antes de chamar essa função.

### <a name="example"></a>Exemplo

```cpp
CRect rect(20, 30, 80, 70);
int nWid = rect.Width();
// nWid is now 60
ASSERT(nWid == 60);
```

## <a name="see-also"></a>Veja também

[Classe CPoint](cpoint-class.md)<br/>
[Classe CSize](csize-class.md)<br/>
[RECT](/windows/win32/api/windef/ns-windef-rect)
