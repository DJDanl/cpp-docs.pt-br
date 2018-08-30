---
title: Classe CRect | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- LPCRECT data type
- CRect class
- LPRECT operator
- RECT structure
ms.assetid: dee4e752-15d6-4db4-b68f-1ad65b2ed6ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3d49b7a96f98c701c2748379ed880267bff3fa5a
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43196642"
---
# <a name="crect-class"></a>Classe CRect
Semelhante a um Windows [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRect : public tagRECT  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::CRect](#crect)|Constrói um objeto `CRect`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::BottomRight](#bottomright)|Retorna o ponto de canto inferior direito da `CRect`.|  
|[CRect::CenterPoint](#centerpoint)|Retorna o PontoCentral de `CRect`.|  
|[CRect::CopyRect](#copyrect)|Copia as dimensões de um retângulo de origem para `CRect`.|  
|[CRect::DeflateRect](#deflaterect)|Diminui a largura e altura de `CRect`.|  
|[CRect::EqualRect](#equalrect)|Determina se `CRect` é igual ao retângulo determinado.|  
|[CRect::Height](#height)|Calcula a altura de `CRect`.|  
|[CRect::InflateRect](#inflaterect)|Aumenta a largura e altura de `CRect`.|  
|[CRect::IntersectRect](#intersectrect)|Conjuntos de `CRect` igual a interseção de dois retângulos.|  
|[CRect::IsRectEmpty](#isrectempty)|Determina se `CRect` está vazio. `CRect` está vazio se a largura e/ou a altura é 0.|  
|[CRect::IsRectNull](#isrectnull)|Determina se o `top`, `bottom`, `left`, e `right` variáveis de membro são todas iguais a 0.|  
|[CRect::MoveToX](#movetox)|Move `CRect` para a coordenada x especificada.|  
|[CRect::MoveToXY](#movetoxy)|Move `CRect` para coordenadas x e y especificadas.|  
|[CRect::MoveToY](#movetoy)|Move `CRect` para a coordenada y especificada.|  
|[CRect::NormalizeRect](#normalizerect)|Padroniza a altura e largura do `CRect`.|  
|[CRect::OffsetRect](#offsetrect)|Move `CRect` por deslocamentos especificados.|  
|[CRect::PtInRect](#ptinrect)|Determina se o ponto especificado está dentro de `CRect`.|  
|[CRect::SetRect](#setrect)|Define as dimensões de `CRect`.|  
|[CRect::SetRectEmpty](#setrectempty)|Conjuntos de `CRect` a um retângulo vazio (todas as coordenadas igual a 0).|  
|[CRect::Size](#size)|Calcula o tamanho de `CRect`.|  
|[CRect::SubtractRect](#subtractrect)|Subtrai um retângulo de outro.|  
|[CRect::TopLeft](#topleft)|Retorna o ponto de canto superior esquerdo do `CRect`.|  
|[CRect::UnionRect](#unionrect)|Conjuntos de `CRect` igual a união de dois retângulos.|  
|[CRect::Width](#width)|Calcula a largura do `CRect`.|  
  
### <a name="public-operators"></a>Operadores públicos    
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::operator-](#operator_-)|Subtrai os deslocamentos de determinado da `CRect` ou esvazia `CRect` e retorna resultante `CRect`.|  
|[CRect::operator LPCRECT](#operator_lpcrect)|Converte um `CRect` em um `LPCRECT`.|  
|[CRect::operator LPRECT](#operator_lprect)|Converte um `CRect` em um `LPRECT`.|  
|[CRect::operator! =](#operator_neq)|Determina se `CRect` não é igual a um retângulo.|  
|[CRect::operator &amp;](#operator_amp)|Cria a interseção de `CRect` e um retângulo e retorna resultante `CRect`.|  
|[CRect::operator &amp;=](#operator_amp_eq)|Conjuntos `CRect` igual a interseção de `CRect` e um retângulo.|  
|[CRect::operator |](#operator_or)|Cria a união de `CRect` e um retângulo e retorna resultante `CRect`.|  
|[CRect::operator |=](#operator_or_eq)|Conjuntos `CRect` igual a união de `CRect` e um retângulo.|  
|[CRect::operator +](#operator_add)|Adiciona os deslocamentos fornecidos para `CRect` ou infla `CRect` e retorna resultante `CRect`.|  
|[+ CRect::operator =](#operator_add_eq)|Adiciona os deslocamentos especificados a `CRect` ou infla `CRect`.|  
|[CRect::operator =](#operator_eq)|Copia as dimensões de um retângulo para `CRect`.|  
|[CRect::operator =](#operator_-_eq)|Subtrai os deslocamentos especificados do `CRect` ou compacta os `CRect`.|  
|[CRect::operator = =](#operator_eq_eq)|Determina se `CRect` é igual a um retângulo.|  
  
## <a name="remarks"></a>Comentários  
 `CRect` também inclui funções de membro para manipular `CRect` objetos e Windows `RECT` estruturas.  
  
 Um `CRect` objeto pode ser passado como um parâmetro de função sempre que um `RECT` estrutura `LPCRECT`, ou `LPRECT` pode ser passado.  
  
> [!NOTE]
>  Essa classe é derivada de `tagRECT` estrutura. (O nome `tagRECT` é um nome menos usados para o `RECT` estrutura.) Isso significa que os membros de dados (`left`, `top`, `right`, e `bottom`) da `RECT` estrutura são membros de dados acessíveis de `CRect`.  
  
 Um `CRect` contém variáveis de membro que definem os pontos superior esquerda e direita de um retângulo.  
  
 Ao especificar um `CRect`, você deve ter cuidado para construí-la para que ele é normalizado — em outras palavras, de modo que o valor da coordenada esquerdo é menor que a direita e a parte superior é menor que a parte inferior. Por exemplo, um superior esquerda do (10,10) e inferior direita da (20,20) define um retângulo normalizado, mas um superior esquerda do (20,20) e inferior direita da (10,10) define um retângulo não normalizado. Se o retângulo não normalizado, muitos `CRect` funções de membro podem retornar resultados incorretos. (Consulte [CRect::NormalizeRect](#normalizerect) para obter uma lista dessas funções.) Antes de chamar uma função que requer retângulos normalizados, você poderá normalizar retângulos não normalizado chamando o `NormalizeRect` função.  
  
 Tenha cuidado ao manipular uma `CRect` com o [CDC::DPtoLP](../../mfc/reference/cdc-class.md#dptolp) e [CDC::LPtoDP](../../mfc/reference/cdc-class.md#lptodp) funções de membro. Se o modo de mapeamento de um contexto de exibição é, de modo que a extensão de y for negativa, como em `MM_LOENGLISH`, em seguida, `CDC::DPtoLP` transformará o `CRect` para que a parte superior é maior que a parte inferior. As funções, como `Height` e `Size` , em seguida, retornará valores negativos para a altura de transformado `CRect`, e o retângulo será não normalizado.  

  
 Quando uso sobrecarregado `CRect` operadores, o primeiro operando deve ser um `CRect`; o segundo pode ser um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um `CRect` objeto.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagRECT`  
  
 `CRect`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltypes. h  
  
##  <a name="bottomright"></a>  CRect::BottomRight  
 As coordenadas são retornadas como uma referência a um [CPoint](cpoint-class.md) objeto está contido em `CRect`.  
  
```  
CPoint& BottomRight() throw();
const CPoint& BottomRight() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas do canto inferior direito do retângulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função para obter ou definir o canto inferior direito do retângulo. Defina o canto, usando essa função no lado esquerdo do operador de atribuição.  
  
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
 Calcula o PontoCentral de `CRect` pela adição de valores left e right e dividindo por dois e adicionando os valores superior e inferior e dividindo por dois.  
  
```  
CPoint CenterPoint() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CPoint` objeto que é o PontoCentral de `CRect`.  
  
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
 *lpSrcRect*  
 Aponta para o [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto a ser copiado.  
  
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
 *l*  
 Especifica a posição esquerda do `CRect`.  
  
 *t*  
 Especifica a parte superior do `CRect`.  
  
 *r*  
 Especifica a posição direita da `CRect`.  
  
 *b*  
 Especifica a parte inferior da `CRect`.  
  
 *srcRect*  
 Refere-se para o [RECT](../../mfc/reference/rect-structure1.md) estrutura com as coordenadas para `CRect`.  
  
 *lpSrcRect*  
 Aponta para o `RECT` estrutura com as coordenadas para `CRect`.  
  
 *ponto*  
 Especifica o ponto de origem para o retângulo a ser construído. Corresponde ao canto superior esquerdo.  
  
 *size*  
 Especifica o deslocamento do canto superior esquerdo para o canto inferior direito do retângulo a ser construído.  
  
 *topLeft*  
 Especifica a posição do canto superior esquerdo do `CRect`.  
  
 *bottomRight*  
 Especifica a posição do canto inferior direito da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum argumento for fornecido, `left`, `top`, `right`, e `bottom` membros não são inicializados.  
  
 O `CRect`(`const RECT&`) e `CRect`(`LPCRECT`) construtores realizar uma [CopyRect](#copyrect). Os outros construtores inicializam as variáveis de membro do objeto diretamente.  
  
### <a name="example"></a>Exemplo  
```cpp  
 // default constructor doesn't initialize!
 CRect rectUnknown;

 // four-integers are left, top, right, and bottom
 CRect rect(0, 0, 100, 50);
 ASSERT(rect.Width() == 100);
 ASSERT(rect.Height() == 50);

 // Initialize from RECT stucture
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
 `DeflateRect` compacta os `CRect` movendo suas laterais em direção ao centro.  
  
```  
void DeflateRect(int x, int y) throw();
void DeflateRect(SIZE size) throw();
void DeflateRect(LPCRECT lpRect) throw();
void DeflateRect(int l, int t, int r, int b) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para deflate à esquerda e à direita do `CRect`.  
  
 *y*  
 Especifica o número de unidades de deflate superior e inferior de `CRect`.  
  
 *size*  
 Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](csize-class.md) que especifica o número de unidades a serem deflate `CRect`. O `cx` valor Especifica o número de unidades para os lados esquerdo e direito de deflate e o `cy` valor Especifica o número de unidades a serem deflate superior e inferior.  
  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` que especifica o número de unidades a serem deflate cada lado.  
  
 *l*  
 Especifica o número de unidades de deflate lado esquerdo do `CRect`.  
  
 *t*  
 Especifica o número de unidades de deflate parte superior do `CRect`.  
  
 *r*  
 Especifica o número de unidades de deflate lado direito da `CRect`.  
  
 *b*  
 Especifica o número de unidades de deflate parte inferior da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Para fazer isso, `DeflateRect` adiciona unidades para a esquerda e superior e subtrai unidades a parte inferior e direita. Os parâmetros da `DeflateRect` são assinados valores; valores positivos deflate `CRect` e valores negativos inflá-lo.  
  
 As duas primeiras sobrecargas deflate ambos os pares de lados opostos `CRect` para que sua largura total é reduzida em duas vezes *x* (ou `cx`) e sua altura total é reduzida em duas vezes *y* ( ou `cy`). As duas sobrecargas deflate cada lado da `CRect` independentemente dos outros.  
  
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
 Determina se `CRect` é igual ao retângulo determinado.  
  
```  
BOOL EqualRect(LPCRECT lpRect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém as coordenadas do canto superior esquerdo e inferior direito de um retângulo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os dois retângulos têm o mesmo superior, esquerda, inferior e os valores corretos; Caso contrário, 0.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
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
 A altura do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O valor resultante pode ser negativo.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(20, 30, 80, 70);
 int nHt = rect.Height();

```cpp  
   CRect rect(20, 30, 80, 70);
int nHt = rect.Height();

   // nHt is now 40
   ASSERT(nHt == 40);   
```

  
##  <a name="inflaterect"></a>  CRect::InflateRect  
 `InflateRect` infla `CRect` movendo suas laterais fora seu centro.  
  
```  
void InflateRect(int x, int y) throw();
void InflateRect(SIZE size) throw();
void InflateRect(LPCRECT lpRect) throw();
void InflateRect(int l, int t, int r,  int b) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para Inflar à esquerda e à direita do `CRect`.  
  
 *y*  
 Especifica o número de unidades para Inflar superior e inferior de `CRect`.  
  
 *size*  
 Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](csize-class.md) que especifica o número de unidades para Inflar `CRect`. O `cx` valor Especifica o número de unidades para inflar os lados esquerdo e direito e o `cy` valor Especifica o número de unidades para Inflar superior e inferior.  
  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` que especifica o número de unidades para Inflar cada lado.  
  
 *l*  
 Especifica o número de unidades para Inflar lado esquerdo do `CRect`.  
  
 *t*  
 Especifica o número de unidades para Inflar parte superior do `CRect`.  
  
 *r*  
 Especifica o número de unidades para Inflar lado direito da `CRect`.  
  
 *b*  
 Especifica o número de unidades para Inflar parte inferior da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Para fazer isso, `InflateRect` subtrai unidades da esquerda e da parte superior e adiciona as unidades para a direita e inferior. Os parâmetros da `InflateRect` são assinados valores; positivo valores inflar `CRect` e valores negativos deflate-lo.  
  
 As duas primeiras sobrecargas inflar ambos os pares de lados opostos `CRect` para que sua largura total é aumentada em duas vezes *x* (ou `cx`) e sua altura total é aumentada em duas vezes *y* ( ou `cy`). As duas sobrecargas inflar cada lado da `CRect` independentemente dos outros.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 300, 300);
 rect.InflateRect(50, 200);

 // rect is now (-50, -200, 350, 500)
 ASSERT(rect == CRect(-50, -200, 350, 500));  
```
  
##  <a name="intersectrect"></a>  CRect::IntersectRect  
 Torna um `CRect` igual a interseção de dois retângulos existentes.  
  
```  
BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect1*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém um retângulo de origem.  
  
 *lpRect2*  
 Aponta para um `RECT` estrutura ou `CRect` objeto que contém um retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a interseção não estiver vazia; 0 se a interseção estiver vazia.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contido em ambos os retângulos existentes.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rectOne(125, 0, 150, 200);
 CRect rectTwo(0, 75, 350,  95);
 CRect rectInter;

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
 Determina se `CRect` está vazio.  
  
```  
BOOL IsRectEmpty() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `CRect` estiver vazio; 0 se `CRect` não está vazio.  
  
### <a name="remarks"></a>Comentários  
 Um retângulo está vazio se a largura e/ou a altura é 0 ou negativo. É diferente de `IsRectNull`, que determina se todas as coordenadas do retângulo são zero.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rectNone(0, 0, 0, 0);
 CRect rectSome(35, 50, 135, 150);

```cpp  
   CRect rectNone(0, 0, 0, 0);
   CRect rectSome(35, 50, 135, 150);
ASSERT(rectNone.IsRectEmpty());
   ASSERT(!rectSome.IsRectEmpty());
CRect rectEmpty(35, 35, 35, 35);
   ASSERT(rectEmpty.IsRectEmpty());   
```

  
##  <a name="isrectnull"></a>  CRect::IsRectNull  
 Determina se a parte superior, esquerda, inferior e valores do botão direito do mouse `CRect` são todas iguais a 0.  
  
```  
BOOL IsRectNull() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `CRect`da parte superior, esquerda, inferior e direita valores são todos iguais a 0; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 É diferente de `IsRectEmpty`, que determina se o retângulo está vazio.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rectNone(0, 0, 0, 0);
 CRect rectSome(35, 50, 135, 150);

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
 Chame essa função para mover o retângulo para a absoluta coordenada x especificada por *x*.  
  
```  
void MoveToX(int x) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A absoluta coordenada x para o canto superior esquerdo do retângulo.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 100, 100);
 rect.MoveToX(10);

```cpp  
   CRect rect(0, 0, 100, 100);
rect.MoveToX(10);

   // rect is now (10, 0, 110, 100);
   ASSERT(rect == CRect(10, 0, 110, 100));   
```
  
##  <a name="movetoxy"></a>  CRect::MoveToXY  
 Chame essa função para mover o retângulo para a absoluta coordenadas x e y-especificadas.  
  
```  
void MoveToXY(int x, int y) throw();
void MoveToXY(POINT point) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A absoluta coordenada x para o canto superior esquerdo do retângulo.  
  
 *y*  
 A absoluta coordenada y para o canto superior esquerdo do retângulo.  
  
 *ponto*  
 Um `POINT` estrutura especificando o absoluto canto superior esquerdo do retângulo.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 100, 100);
 rect.MoveToXY(10, 10);

```cpp  
   CRect rect(0, 0, 100, 100);
   rect.MoveToXY(10, 10);
// rect is now (10, 10, 110, 110);
   ASSERT(rect == CRect(10, 10, 110, 110));   
```

  
##  <a name="movetoy"></a>  CRect::MoveToY  
 Chame essa função para mover o retângulo para a absoluta coordenada y especificada por *y*.  
  
```  
void MoveToY(int y) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *y*  
 A absoluta coordenada y para o canto superior esquerdo do retângulo.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 100, 100);
 rect.MoveToY(10);

```cpp  
   CRect rect(0, 0, 100, 100);
   rect.MoveToY(10);
// rect is now (0, 10, 100, 110);
   ASSERT(rect == CRect(0, 10, 100, 110));   
```

  
##  <a name="normalizerect"></a>  CRect::NormalizeRect  
 Normaliza `CRect` para que a altura e a largura são positivas.  
  
```  
void NormalizeRect() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O retângulo é normalizado para o quarto quadrante posicionamento, que normalmente usa o Windows para as coordenadas. `NormalizeRect` compara os valores superior e inferior e troca-los se a parte superior é maior que a parte inferior. Da mesma forma, ele troca os valores de left e right se esquerda for maior que a direita. Essa função é útil ao lidar com os modos diferentes de mapeamento e invertidos retângulos.  
  
> [!NOTE]
>  O seguinte `CRect` funções de membro exigem retângulos normalizados para funcionar corretamente: [altura](#height), [largura](#width), [tamanho](#size), [ IsRectEmpty](#isrectempty), [PtInRect](#ptinrect), [EqualRect](#equalrect), [UnionRect](#unionrect), [IntersectRect](#intersectrect), [ SubtractRect](#subtractrect), [operador = =](#operator_eq_eq), [operador! =](#operator_neq), [operador &#124; ](#operator_or), [operador &#124;=](#operator_or_eq), [operador &](#operator_amp), e [operador & =](#operator_amp_eq).  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(110, 100, 250, 310);
 CRect rect2(250, 310, 110, 100);

```cpp  
   CRect rect1(110, 100, 250, 310);
   CRect rect2(250, 310, 110, 100);
rect1.NormalizeRect();
   rect2.NormalizeRect();
 ASSERT(rect1 == rect2);  
```
  
##  <a name="offsetrect"></a>  CRect::OffsetRect  
 Move `CRect` por deslocamentos especificados.  
  
```  
void OffsetRect(int x, int y) throw();
void OffsetRect(POINT point) throw();
void OffsetRect(SIZE size) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a quantidade para mover para a esquerda ou direita. Ele deve ser negativo para mover para a esquerda.  
  
 *y*  
 Especifica o valor para mover para cima ou para baixo. Ele deve ser negativo para mover para cima.  
  
 *ponto*  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto especificando ambas as dimensões pela qual mover.  
  
 *size*  
 Contém uma [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto especificando ambas as dimensões pela qual mover.  
  
### <a name="remarks"></a>Comentários  
 Move `CRect` *x* unidades no eixo e *y* unidades no eixo y. O *x* e *y* parâmetros são valores assinados, portanto, `CRect` pode ser movido para a esquerda ou para a direita e para cima ou para baixo.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 35, 35);
 rect.OffsetRect(230, 230);

```cpp  
   CRect rect(0, 0, 35, 35);
   rect.OffsetRect(230, 230);

   // rect is now (230, 230, 265, 265)
   ASSERT(rect == CRect(230, 230, 265, 265));   
```

  
##  <a name="operator_lpcrect"></a>  CRect::operator LPCRECT converte uma `CRect` para um [LPCRECT](../../mfc/reference/data-types-mfc.md).  

  
```  
operator LPCRECT() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando você usa essa função, você não precisa address-of (**&**) operador. Esse operador será usado automaticamente quando você passa um `CRect` objeto para uma função que espera um `LPCRECT`.  
  

##  <a name="operator_lprect"></a>  CRect::operator LPRECT  
 Converte um `CRect` para um [LPRECT](../../mfc/reference/data-types-mfc.md).  

  
```
operator LPRECT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando você usa essa função, você não precisa address-of (**&**) operador. Esse operador será usado automaticamente quando você passa um `CRect` objeto para uma função que espera um `LPRECT`.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::operator LPCRECT](#operator_lpcrect).  
  
##  <a name="operator_eq"></a>  CRect::operator =  
 Atribui *srcRect* para `CRect`.  
  
```  
void operator=(const RECT& srcRect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *srcRect*  
 Refere-se a um retângulo de origem. Pode ser um [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 127, 168);
 CRect rect2;

```cpp  
   CRect rect(0, 0, 127, 168);
   CRect rect2;

   rect2 = rect;
   ASSERT(rect2 == CRect(0, 0, 127, 168));   
```

  
##  <a name="operator_eq_eq"></a>  CRect::operator = =  
 Determina se `rect` é igual a `CRect` comparando as coordenadas de seus cantos superior esquerdo e inferior direito.  
  
```  
BOOL operator==(const RECT& rect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 Refere-se a um retângulo de origem. Pode ser um [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for igual; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(35, 150, 10, 25);
 CRect rect2(35, 150, 10, 25);
 CRect rect3(98, 999,  6,  3);

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

  
##  <a name="operator_neq"></a>  CRect::operator! =  
 Determina se *rect* não é igual a `CRect` comparando as coordenadas de seus cantos superior esquerdo e inferior direito.  
  
```  
BOOL operator!=(const RECT& rect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 Refere-se a um retângulo de origem. Pode ser um [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se não for igual; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(35, 150, 10, 25);
 CRect rect2(35, 150, 10, 25);
 CRect rect3(98, 999,  6,  3);

```cpp  
   CRect rect1(35, 150, 10, 25);
   CRect rect2(35, 150, 10, 25);
   CRect rect3(98, 999, 6, 3);
ASSERT(rect1 != rect3);
 // works just fine against RECTs, as well

 RECT test;
 test.left = 35;
 test.top = 150;
 test.right = 10;
 test.bottom = 25;

 ASSERT(rect3 != test);  
```
  
##  <a name="operator_add_eq"></a>  + CRect::operator =  
 Mover as duas primeiras sobrecargas `CRect` por deslocamentos especificados.  
  
```  
void operator+=(POINT point) throw();
void operator+=(SIZE size) throw();
void operator+=(LPCRECT lpRect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ponto*  
 Um [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 *size*  
 Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para Inflar cada lado da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) valores são adicionados ao `CRect`.  
  
 A terceira sobrecarga infla `CRect` pelo número de unidades especificada em cada membro do parâmetro.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(100, 235, 200, 335);
 CPoint pt(35, 65);
 CRect rect2(135, 300, 235, 400);

```cpp  
   CRect   rect1(100, 235, 200, 335);
   CPoint pt(35, 65);
   CRect   rect2(135, 300, 235, 400);

   rect1 += pt;
   ASSERT(rect1 == rect2);   
```
  
##  <a name="operator_-_eq"></a>  CRect::operator =  
 Mover as duas primeiras sobrecargas `CRect` por deslocamentos especificados.  
  
```  
void operator-=(POINT point) throw();
void operator-=(SIZE size) throw();
void operator-=(LPCRECT lpRect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ponto*  
 Um [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 *size*  
 Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para deflate cada lado da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) valores são subtraídos do `CRect`.  
  
 A terceira sobrecarga compacta os `CRect` pelo número de unidades especificada em cada membro do parâmetro. Observe que essa sobrecarga de funções, como [DeflateRect](#deflaterect).  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(100, 235, 200, 335);
 CPoint pt(35, 65);
 rect1 -= pt;

```cpp  
   CRect   rect1(100, 235, 200, 335);
   CPoint pt(35, 65);

   rect1 -= pt;
   CRect   rectResult(65, 170, 165, 270);
   ASSERT(rect1 == rectResult);   
```
  
##  <a name="operator_amp_eq"></a>  CRect::operator &amp;=  
 Conjuntos `CRect` igual a interseção dos `CRect` e `rect`.  
  
```  
void operator&=(const RECT& rect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 Contém uma [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior que está contido em ambos os retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::IntersectRect](#intersectrect).  
  
##  <a name="operator_or_eq"></a>  CRect::operator &#124;=  
 Conjuntos `CRect` igual a união de `CRect` e `rect`.  
  
```  
void operator|=(const RECT& rect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 Contém uma `CRect` ou [RECT](../../mfc/reference/rect-structure1.md).  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém os dois retângulos do código-fonte.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(100,   0, 200, 300);
 CRect rect2( 0, 100, 300, 200);
 rect1 |= rect2;

```cpp  
   CRect   rect1(100,  0, 200, 300);
   CRect   rect2(0, 100, 300, 200);

   rect1 |= rect2;
   CRect   rectResult(0, 0, 300, 300);
   ASSERT(rectResult == rect1);   
```

  
##  <a name="operator_add"></a>  CRect::operator +  
 As duas primeiras sobrecargas retornam um `CRect` que é igual ao objeto `CRect` deslocado pelos deslocamentos especificados.  
  
```  
CRect operator+(POINT point) const throw();
CRect operator+(LPCRECT lpRect) const throw();
CRect operator+(SIZE size) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ponto*  
 Um [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto que especifica o número de unidades para mover o valor de retorno.  
  
 *size*  
 Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto que especifica o número de unidades para mover o valor de retorno.  
  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para Inflar cada lado do valor de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRect` resultante da movimentação ou inflacionando `CRect` pelo número de unidades especificadas no parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) parâmetros são adicionados ao `CRect`da posição.  
  
 A terceira sobrecarga retorna um novo `CRect` que é igual ao `CRect` inflado pelo número de unidades especificada em cada membro do parâmetro.  
  
### <a name="example"></a>Exemplo  
```cpp  
   CRect   rect1(100, 235, 200, 335);
   CPoint pt(35, 65);
   CRect   rect2;

   rect2 = rect1 + pt;
   CRect   rectResult(135, 300, 235, 400);
   ASSERT(rectResult == rect2);   
```

  
##  <a name="operator_-"></a>  CRect::operator-  
 As duas primeiras sobrecargas retornam um `CRect` que é igual ao objeto `CRect` deslocado pelos deslocamentos especificados.  
  
```  
CRect operator-(POINT point) const throw();
CRect operator-(SIZE size) const throw();
CRect operator-(LPCRECT lpRect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *ponto*  
 Um [ponto](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto que especifica o número de unidades para mover o valor de retorno.  
  
 *size*  
 Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou `CSize` objeto que especifica o número de unidades para mover o valor de retorno.  
  
 *lpRect*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para deflate cada lado do valor de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRect` resultante da movimentação ou deflating `CRect` pelo número de unidades especificadas no parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) parâmetros são subtraídos do `CRect`da posição.  
  
 A terceira sobrecarga retorna um novo `CRect` que é igual ao `CRect` desinflada pelo número de unidades especificada em cada membro do parâmetro. Observe que essa sobrecarga de funções, como [DeflateRect](#deflaterect), e não [SubtractRect](#subtractrect).  
  
### <a name="example"></a>Exemplo  
```cpp  
   CRect   rect1(100, 235, 200, 335);
   CPoint pt(35, 65);
   CRect   rect2;

   rect2 = rect1 - pt;
   CRect   rectResult(65, 170, 165, 270);
   ASSERT(rect2 == rectResult);   
```

  
##  <a name="operator_amp"></a>  CRect::operator &amp;  
 Retorna um `CRect` que é a interseção dos `CRect` e *rect2*.  
  
```  
CRect operator&(const RECT& rect2) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *rect2*  
 Contém uma [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` que é a interseção dos `CRect` e *rect2*.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior que está contido em ambos os retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
   CRect   rect1(100,  0, 200, 300);
   CRect   rect2(0, 100, 300, 200);
   CRect   rect3;

   rect3 = rect1 & rect2;
   CRect   rectResult(100, 100, 200, 200);
   ASSERT(rectResult == rect3);   
```

  
##  <a name="operator_or"></a>  CRect::operator&#124;  
 Retorna um `CRect` que é a união dos `CRect` e *rect2*.  
  
```   
CRect operator|(const RECT& 
rect2) const throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *rect2*  
 Contém uma [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` que é a união dos `CRect` e *rect2*.  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém os dois retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect1(100,   0, 200, 300);
 CRect rect2( 0, 100, 300, 200);
 CRect rect3;

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
 *ponto*  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto está dentro de `CRect`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um ponto está dentro do `CRect` se ele se encontra no lado esquerdo ou superior ou está dentro de todos os quatro lados. Um ponto no lado direita ou inferior está fora do `CRect`.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar retângulo antes de chamar essa função.  
  
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
 *x1*  
 Especifica a coordenada x do canto superior esquerdo.  
  
 *y1*  
 Especifica a coordenada y do canto superior esquerdo.  
  
 *X2*  
 Especifica a coordenada x do canto inferior direito.  
  
 *y2*  
 Especifica a coordenada y do canto inferior direito.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect;
 rect.SetRect(256, 256, 512, 512);

```cpp  
   CRect rect;
   rect.SetRect(256, 256, 512, 512);
   ASSERT(rect == CRect(256, 256, 512, 512));   
```

  
##  <a name="setrectempty"></a>  CRect::SetRectEmpty  
 Torna `CRect` um retângulo nulo definindo todas as coordenadas como zero.  
  
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
 O `cx` e `cy` membros do valor de retorno contém a altura e largura do `CRect`.  
  
```  
CSize Size() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CSize](csize-class.md) que contém o tamanho do objeto `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A altura ou largura pode ser negativa.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(10, 10, 50, 50);
 CSize sz = rect.Size();
 ASSERT(sz.cx == 40 && sz.cy == 40);  
```

##  <a name="subtractrect"></a>  CRect::SubtractRect  
 Faz com que as dimensões dos `CRect` igual a subtração de `lpRectSrc2` de `lpRectSrc1`.  
  
```  
BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRectSrc1*  
 Aponta para o [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto do qual um retângulo deve ser subtraído.  
  
 *lpRectSrc2*  
 Aponta para o `RECT` estrutura ou `CRect` objeto a ser subtraído do retângulo apontado pelo *lpRectSrc1* parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A subtração é o menor retângulo que contém todos os pontos na *lpRectScr1* que não estão na interseção dos *lpRectScr1* e *lpRectScr2*.  
  
 O retângulo especificado por *lpRectSrc1* não será alterado se o retângulo especificado por *lpRectSrc2* completamente não se sobreponha o retângulo especificado por *lpRectSrc1*em pelo menos um das x ou y-orientações.  
  
 Por exemplo, se *lpRectSrc1* foram (10,10, 100,100) e *lpRectSrc2* foram (50,50, 150,150), o retângulo apontado pelo *lpRectSrc1* seria podem ser alterados quando o função retornada. Se *lpRectSrc1* foram (10,10, 100,100) e *lpRectSrc2* foram (50,10, 150,150), no entanto, o retângulo apontado pelo *lpRectSrc1* conteria as coordenadas (10,10, 50,100) quando a função retornada.  
  
 `SubtractRect` não é igual a [operador -](#operator_-) nem [operador-=](#operator_-_eq). Nenhum desses operadores nunca chama `SubtractRect`.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
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
 As coordenadas são retornadas como uma referência a um [CPoint](cpoint-class.md) objeto está contido em `CRect`.  
  
```  
CPoint& TopLeft() throw();
const CPoint& TopLeft() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas do canto superior esquerdo do retângulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função para obter ou definir o canto superior esquerdo do retângulo. Defina o canto, usando essa função no lado esquerdo do operador de atribuição.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::CenterPoint](#centerpoint).  
  
##  <a name="unionrect"></a>  CRect::UnionRect  
 Faz com que as dimensões da `CRect` igual a união dos retângulos duas origens.  
  
```  
BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRect1*  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) ou `CRect` que contém um retângulo de origem.  
  
 *lpRect2*  
 Aponta para um `RECT` ou `CRect` que contém um retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a união não está vazia. 0 se a união está vazia.  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém os dois retângulos do código-fonte.  
  
 Windows ignora as dimensões de um retângulo vazio; ou seja, um retângulo que não tenha altura ou não possui largura.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
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
 Calcula a largura do `CRect` subtraindo o valor à esquerda do valor à direita.  
  
```  
int Width() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A largura pode ser negativa.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  

```cpp  
   CRect rect(20, 30, 80, 70);
int nWid = rect.Width();
   // nWid is now 60
   ASSERT(nWid == 60);   
```
## <a name="see-also"></a>Consulte também  
 [Classe CPoint](cpoint-class.md)   
 [Classe CSize](csize-class.md)   
 [RECT](../../mfc/reference/rect-structure1.md)


