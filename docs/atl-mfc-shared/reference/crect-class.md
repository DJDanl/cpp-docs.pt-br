---
title: Classe CRect | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRect
dev_langs:
- C++
helpviewer_keywords:
- LPCRECT data type
- CRect class
- LPRECT operator
- RECT structure
ms.assetid: dee4e752-15d6-4db4-b68f-1ad65b2ed6ca
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: fa528d300c546bfdeaab55ff88735efcaf8533a5
ms.lasthandoff: 02/25/2017

---
# <a name="crect-class"></a>Classe CRect
Semelhante a um Windows [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRect : public tagRECT  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::CRect](#crect)|Constrói um objeto `CRect`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::BottomRight](#bottomright)|Retorna o ponto de canto direito inferior do `CRect`.|  
|[CRect::CenterPoint](#centerpoint)|Retorna o PontoCentral de `CRect`.|  
|[CRect::CopyRect](#copyrect)|Copia as dimensões de um retângulo de origem para `CRect`.|  
|[CRect::DeflateRect](#deflaterect)|Reduz a largura e altura de `CRect`.|  
|[CRect::EqualRect](#equalrect)|Determina se `CRect` é igual ao retângulo determinado.|  
|[CRect::Height](#height)|Calcula a altura de `CRect`.|  
|[CRect::InflateRect](#inflaterect)|Aumenta a largura e altura de `CRect`.|  
|[CRect::IntersectRect](#intersectrect)|Conjuntos de `CRect` igual a interseção de dois retângulos.|  
|[CRect::IsRectEmpty](#isrectempty)|Determina se `CRect` está vazia. `CRect`está vazio se a altura e/ou largura forem 0.|  
|[CRect::IsRectNull](#isrectnull)|Determina se o **superior**, **inferior**, **esquerda**, e **direita** variáveis de membros são todos iguais a 0.|  
|[CRect::MoveToX](#movetox)|Move `CRect` para a coordenada x especificada.|  
|[CRect::MoveToXY](#movetoxy)|Move `CRect` para coordenadas x e y especificadas.|  
|[CRect::MoveToY](#movetoy)|Move `CRect` para a coordenada y especificada.|  
|[CRect::NormalizeRect](#normalizerect)|Padroniza a altura e largura do `CRect`.|  
|[CRect::OffsetRect](#offsetrect)|Move `CRect` pelos deslocamentos especificados.|  
|[CRect::PtInRect](#ptinrect)|Determina se o ponto especificado está em `CRect`.|  
|[CRect::SetRect](#setrect)|Define as dimensões de `CRect`.|  
|[CRect::SetRectEmpty](#setrectempty)|Conjuntos de `CRect` um retângulo vazio (todas as coordenadas igual a 0).|  
|[CRect::Size](#size)|Calcula o tamanho da `CRect`.|  
|[CRect::SubtractRect](#subtractrect)|Subtrai um retângulo de outro.|  
|[CRect::TopLeft](#topleft)|Retorna o ponto do canto superior esquerdo do `CRect`.|  
|[CRect::UnionRect](#unionrect)|Conjuntos de `CRect` igual a união de dois retângulos.|  
|[CRect::Width](#width)|Calcula a largura do `CRect`.|  
  
### <a name="public-operators"></a>Operadores públicos    
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::operator-](#operator_-)|Subtrai os deslocamentos determinados de `CRect` ou esvaziamento `CRect` e retorna resultante `CRect`.|  
|[CRect::operator LPCRECT](#operator_lpcrect)|Converte um `CRect` para um **LPCRECT**.|  
|[CRect::operator LPRECT](#operator_lprect)|Converte um `CRect` para um `LPRECT`.|  
|[CRect::operator! =](#operator_neq)|Determina se `CRect` não é igual a um retângulo.|  
|[CRect::operator&amp;](#operator_amp)|Cria a interseção de `CRect` e um retângulo e retorna resultante `CRect`.|  
|[CRect::operator&amp;=](#operator_amp_eq)|Conjuntos de `CRect` igual a interseção de `CRect` e um retângulo.|  
|[CRect::operator |](#operator_or)|Cria a união de `CRect` e um retângulo e retorna resultante `CRect`.|  
|[CRect::operator |=](#operator_or_eq)|Conjuntos de `CRect` igual a união de `CRect` e um retângulo.|  
|[CRect::operator +](#operator_add)|Adiciona os deslocamentos determinados para `CRect` ou inflar `CRect` e retorna resultante `CRect`.|  
|[+ = CRect::operator](#operator_add_eq)|Adiciona os deslocamentos especificados para `CRect` ou inflar `CRect`.|  
|[CRect::operator =](#operator_eq)|Copia as dimensões de um retângulo para `CRect`.|  
|[CRect::operator =](#operator_-_eq)|Subtrai os deslocamentos especificados de `CRect` ou esvaziamento `CRect`.|  
|[CRect::operator = =](#operator_eq_eq)|Determina se `CRect` é igual a um retângulo.|  
  
## <a name="remarks"></a>Comentários  
 `CRect`também inclui funções de membro para manipular `CRect` objetos e Windows `RECT` estruturas.  
  
 A `CRect` objeto pode ser passado como um parâmetro de função sempre que um `RECT` estrutura, **LPCRECT**, ou `LPRECT` pode ser passado.  
  
> [!NOTE]
>  Essa classe é derivada do **tagRECT** estrutura. (O nome **tagRECT** é um nome menor usados para o `RECT` estrutura.) Isso significa que os membros de dados (**esquerda**, **superior**, **direita**, e **inferior**) do `RECT` estrutura são membros de dados acessíveis de `CRect`.  
  
 A `CRect` contém variáveis de membro que definem os pontos superior esquerda e direita de um retângulo.  
  
 Ao especificar um `CRect`, você deve ter cuidado para construí-la para que ele é normalizado — em outras palavras, que o valor da coordenada esquerda é inferior à direita e a parte superior é menor que a parte inferior. Por exemplo, um superior esquerda do (10,10) e inferior direita da (20,20) define um retângulo normalizado, mas um superior esquerda do (20,20) e inferior direita da (10,10) define um retângulo não normalizado. Se o retângulo não normalizado, muitos `CRect` funções de membro podem retornar resultados incorretos. (Consulte [CRect::NormalizeRect](#normalizerect) para obter uma lista dessas funções.) Antes de chamar uma função que requer normalizados retângulos, você pode normalizar retângulos não normalizado chamando o `NormalizeRect` função.  
  
 Tenha cuidado ao manipular um `CRect` com o [CDC::DPtoLP](../../mfc/reference/cdc-class.md#dptolp) e [CDC::LPtoDP](../../mfc/reference/cdc-class.md#lptodp) funções de membro. Se o modo de mapeamento de um contexto de exibição é que a extensão de y for negativa, como em `MM_LOENGLISH`, em seguida, `CDC::DPtoLP` transformará o `CRect` para que a parte superior é maior que a parte inferior. Funções como **altura** e **tamanho** retornará valores negativos para a altura da transformado `CRect`, e o retângulo estará não normalizado.  

  
 Quando uso sobrecarregado `CRect` operadores, o primeiro operando deve ser um `CRect`; o segundo pode ser um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um `CRect` objeto.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagRECT`  
  
 `CRect`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltypes. h  
  
##  <a name="a-namebottomrighta--crectbottomright"></a><a name="bottomright"></a>CRect::BottomRight  
 As coordenadas são retornadas como uma referência a um [CPoint](cpoint-class.md) contido no objeto `CRect`.  
  
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
  
##  <a name="a-namecenterpointa--crectcenterpoint"></a><a name="centerpoint"></a>CRect::CenterPoint 
 Calcula o PontoCentral de `CRect` , adicionando os valores de esquerda e direito e dividindo por dois e adicionando os valores superior e inferior e dividindo por dois.  
  
```  
CPoint CenterPoint() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A `CPoint` objeto PontoCentral de `CRect`.  
  
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
  
##  <a name="a-namecopyrecta--crectcopyrect"></a><a name="copyrect"></a>CRect::CopyRect  
 Copia o `lpSrcRect` retângulo em `CRect`.  
  
```  
void CopyRect(LPCRECT lpSrcRect) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSrcRect`  
 Aponta para a [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto a ser copiado.  
  
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

  
##  <a name="a-namecrecta--crectcrect"></a><a name="crect"></a>CRect::CRect  
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
  
 `lpSrcRect`  
 Aponta para a `RECT` estrutura com as coordenadas para `CRect`.  
  
 `point`  
 Especifica o ponto de origem para o retângulo para ser criada. Corresponde ao canto superior esquerdo.  
  
 `size`  
 Especifica o deslocamento do canto superior esquerdo para o canto inferior direito do retângulo para ser criada.  
  
 *topLeft*  
 Especifica a posição do canto superior esquerdo do `CRect`.  
  
 *bottomRight*  
 Especifica a posição do canto direito inferior do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum argumento for fornecido, **esquerda**, **superior**, **direita**, e **inferior** membros não são inicializados.  
  
 O `CRect`(**RECT const < /**) e `CRect`(**LPCRECT**) construtores realizar uma [CopyRect](#copyrect). Construtores de inicializam as variáveis de membro do objeto diretamente.  
  
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
  
##  <a name="a-namedeflaterecta--crectdeflaterect"></a><a name="deflaterect"></a>CRect::DeflateRect  
 `DeflateRect`esvazia `CRect` movendo suas laterais em direção ao centro.  
  
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
  
 `size`  
 A [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](csize-class.md) que especifica o número de unidades para deflate `CRect`. O `cx` valor Especifica o número de unidades para deflate à esquerda e à direita e o `cy` valor Especifica o número de unidades para deflate nas partes superior e inferior.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` que especifica o número de unidades para deflate cada lado.  
  
 *l*  
 Especifica o número de unidades de deflate à esquerda do `CRect`.  
  
 *t*  
 Especifica o número de unidades de deflate parte superior do `CRect`.  
  
 *r*  
 Especifica o número de unidades de deflate à direita do `CRect`.  
  
 *b*  
 Especifica o número de unidades de deflate parte inferior da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Para fazer isso, `DeflateRect` adiciona unidades à esquerda e superior e subtrai unidades a parte inferior e direita. Os parâmetros de `DeflateRect` são assinados valores; valores positivos deflate `CRect` e valores negativos aumentar a ele.  
  
 As primeiras duas sobrecargas deflate dois pares de lados opostos `CRect` para que sua largura total será diminuída em duas vezes *x* (ou `cx`) e sua altura total será diminuída em duas vezes *y* (ou `cy`). As duas sobrecargas deflate cada lado da `CRect` independentemente dos outros.  
  
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
  
##  <a name="a-nameequalrecta--crectequalrect"></a><a name="equalrect"></a>CRect::EqualRect  
 Determina se `CRect` é igual ao retângulo determinado.  
  
```  
BOOL EqualRect(LPCRECT lpRect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém as coordenadas do canto superior esquerdo e inferior direito de um retângulo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os dois retângulos têm o mesmo superior, esquerda, inferior e direita valores; Caso contrário, 0.  
  
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

##  <a name="a-nameheighta--crectheight"></a><a name="height"></a>CRect::Height  
 Calcula a altura de `CRect` subtraindo o valor superior do valor inferior.  
  
```  
int Height() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O valor resultante pode ser negativo.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar o retângulo antes de chamar essa função.  
  
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

  
##  <a name="a-nameinflaterecta--crectinflaterect"></a><a name="inflaterect"></a>CRect::InflateRect  
 `InflateRect`inflar `CRect` movendo suas laterais para fora do seu centro.  
  
```  
void InflateRect(int x, int y) throw();
void InflateRect(SIZE size) throw();
void InflateRect(LPCRECT lpRect) throw();
void InflateRect(int l, int t, int r,  int b) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para aumentar à esquerda e à direita do `CRect`.  
  
 *y*  
 Especifica o número de unidades para aumentar a parte superior e inferior de `CRect`.  
  
 `size`  
 A [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](csize-class.md) que especifica o número de unidades para aumentar `CRect`. O `cx` valor Especifica o número de unidades para aumentar os lados esquerdo e direito e `cy` valor Especifica o número de unidades para aumentar a parte superior e inferior.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` que especifica o número de unidades para aumentar cada lado.  
  
 *l*  
 Especifica o número de unidades para aumentar o lado esquerdo da `CRect`.  
  
 *t*  
 Especifica o número de unidades para aumentar a parte superior do `CRect`.  
  
 *r*  
 Especifica o número de unidades para aumentar o lado direito da `CRect`.  
  
 *b*  
 Especifica o número de unidades para aumentar a parte inferior da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Para fazer isso, `InflateRect` subtrai unidades de left e top e adiciona as unidades para a direita e inferior. Os parâmetros de `InflateRect` são assinados valores; aumentar valores positivos `CRect` e valores negativos deflate-lo.  
  
 As primeiras duas sobrecargas inflar dois pares de lados opostos `CRect` para que sua largura total é aumentada em duas vezes *x* (ou `cx`) e sua altura total é aumentada em duas vezes *y* (ou `cy`). As duas sobrecargas aumentar cada lado da `CRect` independentemente dos outros.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(0, 0, 300, 300);
 rect.InflateRect(50, 200);

 // rect is now (-50, -200, 350, 500)
 ASSERT(rect == CRect(-50, -200, 350, 500));  
```
  
##  <a name="a-nameintersectrecta--crectintersectrect"></a><a name="intersectrect"></a>CRect::IntersectRect  
 Faz uma `CRect` igual a interseção de dois retângulos existentes.  
  
```  
BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect1`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém um retângulo de origem.  
  
 `lpRect2`  
 Aponta para um `RECT` estrutura ou `CRect` objeto que contém um retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a interseção não está vazia; 0 se a interseção está vazia.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contido em dois retângulos existentes.  
  
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
  
##  <a name="a-nameisrectemptya--crectisrectempty"></a><a name="isrectempty"></a>CRect::IsRectEmpty  
 Determina se `CRect` está vazia.  
  
```  
BOOL IsRectEmpty() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `CRect` está vazia; 0 se `CRect` não está vazio.  
  
### <a name="remarks"></a>Comentários  
 Um retângulo é vazia se a altura e/ou largura forem 0 ou negativo. É diferente de `IsRectNull`, que determina se todas as coordenadas do retângulo são zero.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar o retângulo antes de chamar essa função.  
  
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

  
##  <a name="a-nameisrectnulla--crectisrectnull"></a><a name="isrectnull"></a>CRect::IsRectNull  
 Determina se a parte superior, esquerda, inferior e para a direita os valores de `CRect` são todos iguais a 0.  
  
```  
BOOL IsRectNull() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `CRect`da parte superior, esquerda, inferior e valores corretos são todos iguais a 0; caso contrário, 0.  
  
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
  
##  <a name="a-namemovetoxa--crectmovetox"></a><a name="movetox"></a>CRect::MoveToX  
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
  
##  <a name="a-namemovetoxya--crectmovetoxy"></a><a name="movetoxy"></a>CRect::MoveToXY  
 Chame essa função para mover o retângulo para a absoluta coordenadas x e y-especificada.  
  
```  
void MoveToXY(int x, int y) throw();
void MoveToXY(POINT point) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A absoluta coordenada x para o canto superior esquerdo do retângulo.  
  
 *y*  
 A absoluta coordenada y do canto superior esquerdo do retângulo.  
  
 `point`  
 A **ponto** estrutura especificando o absoluto canto superior esquerdo do retângulo.  
  
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

  
##  <a name="a-namemovetoya--crectmovetoy"></a><a name="movetoy"></a>CRect::MoveToY  
 Chame essa função para mover o retângulo para a absoluta coordenada y especificada por *y*.  
  
```  
void MoveToY(int y) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *y*  
 A absoluta coordenada y do canto superior esquerdo do retângulo.  
  
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

  
##  <a name="a-namenormalizerecta--crectnormalizerect"></a><a name="normalizerect"></a>CRect::NormalizeRect  
 Normaliza `CRect` para que a altura e a largura são positivos.  
  
```  
void NormalizeRect() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O retângulo é normalizado para posicionar o quarto quadrante, que o Windows normalmente usa para coordenadas. `NormalizeRect`compara os valores superior e inferior e troca se início for maior que a parte inferior. Da mesma forma, ele troca os valores de esquerda e direito, se a esquerda for maior que o direito. Essa função é útil ao lidar com modos diferentes de mapeamento e invertido retângulos.  
  
> [!NOTE]
>  O seguinte `CRect` funções de membro requerem retângulos normalizados para funcionar corretamente: [altura](#height), [largura](#width), [tamanho](#size), [IsRectEmpty](#isrectempty), [PtInRect](#ptinrect), [EqualRect](#equalrect), [UnionRect](#unionrect), [IntersectRect](#intersectrect), [SubtractRect](#subtractrect), [operador = =](#operator_eq_eq), [operador! =](#operator_neq), [operador |](#operator_or), [operador | =](#operator_or_eq), [operador < /](#operator_amp), e [operador < / =](#operator_amp_eq).  
  
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
  
##  <a name="a-nameoffsetrecta--crectoffsetrect"></a><a name="offsetrect"></a>CRect::OffsetRect  
 Move `CRect` pelos deslocamentos especificados.  
  
```  
void OffsetRect(int x, int y) throw();
void OffsetRect(POINT point) throw();
void OffsetRect(SIZE size) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a quantidade para mover para a esquerda ou direita. Ele deve ser negativo para mover para a esquerda.  
  
 *y*  
 Especifica a quantidade de mover para cima ou para baixo. Ele deve ser negativo para mover para cima.  
  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto especificando ambas as dimensões pela qual mover.  
  
 `size`  
 Contém uma [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto especificando ambas as dimensões pela qual mover.  
  
### <a name="remarks"></a>Comentários  
 Move `CRect` *x* unidades no eixo e *y* unidades no eixo y. O *x* e *y* os parâmetros são valores assinados, então `CRect` podem ser movidos para a esquerda ou para a direita e para cima ou para baixo.  
  
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

  
##  <a name="a-nameoperatorlpcrecta--crectoperator-lpcrect-converts-a-crect-to-an-lpcrectmfcreferencedata-types-mfcmd"></a><a name="operator_lpcrect"></a>CRect::operator LPCRECT converte uma `CRect` para um [LPCRECT](../../mfc/reference/data-types-mfc.md).  

  
```  
operator LPCRECT() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando você usa essa função, você não precisa address-of (**&**) operador. Esse operador será usado automaticamente quando você passa um `CRect` objeto para uma função que espera uma **LPCRECT**.  
  

##  <a name="a-nameoperatorlprecta--crectoperator-lprect"></a><a name="operator_lprect"></a>CRect::operator LPRECT  
 Converte um `CRect` para um [LPRECT](../../mfc/reference/data-types-mfc.md).  

  
```
operator LPRECT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando você usa essa função, você não precisa address-of (**&**) operador. Esse operador será usado automaticamente quando você passa um `CRect` objeto para uma função que espera um `LPRECT`.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::operator LPCRECT](#operator_lpcrect).  
  
##  <a name="a-nameoperatoreqa--crectoperator-"></a><a name="operator_eq"></a>CRect::operator =  
 Atribui *srcRect* para `CRect`.  
  
```  
void operator=(const RECT& srcRect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *srcRect*  
 Refere-se a um retângulo de origem. Can be a [RECT](../../mfc/reference/rect-structure1.md) or `CRect`.  
  
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

  
##  <a name="a-nameoperatoreqeqa--crectoperator-"></a><a name="operator_eq_eq"></a>CRect::operator = =  
 Determina se `rect` é igual a `CRect` comparando as coordenadas dos seus cantos superior esquerdo e inferior direito.  
  
```  
BOOL operator==(const RECT& rect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Refere-se a um retângulo de origem. Can be a [RECT](../../mfc/reference/rect-structure1.md) or `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se iguais; Caso contrário, 0.  
  
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

  
##  <a name="a-nameoperatorneqa--crectoperator-"></a><a name="operator_neq"></a>CRect::operator! =  
 Determina se `rect` não é igual a `CRect` comparando as coordenadas dos seus cantos superior esquerdo e inferior direito.  
  
```  
BOOL operator!=(const RECT& rect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Refere-se a um retângulo de origem. Can be a [RECT](../../mfc/reference/rect-structure1.md) or `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se não iguais; Caso contrário, 0.  
  
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
  
##  <a name="a-nameoperatoraddeqa--crectoperator-"></a><a name="operator_add_eq"></a>+ = CRect::operator  
 As primeiras duas sobrecargas mover `CRect` pelos deslocamentos especificados.  
  
```  
void operator+=(POINT point) throw();
void operator+=(SIZE size) throw();
void operator+=(LPCRECT lpRect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 A [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `size`  
 A [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para aumentar cada lado da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) valores forem adicionados a `CRect`.  
  
 O terceiro sobrecarregamento infla `CRect` pelo número de unidades especificado em cada membro do parâmetro.  
  
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
  
##  <a name="a-nameoperator-eqa--crectoperator--"></a><a name="operator_-_eq"></a>CRect::operator =  
 As primeiras duas sobrecargas mover `CRect` pelos deslocamentos especificados.  
  
```  
void operator-=(POINT point) throw();
void operator-=(SIZE size) throw();
void operator-=(LPCRECT lpRect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 A [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `size`  
 A [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para deflate cada lado da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) valores são subtraídos do `CRect`.  
  
 O terceiro sobrecarregamento esvaziamento `CRect` pelo número de unidades especificado em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#deflaterect).  
  
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
  
##  <a name="a-nameoperatorampeqa--crectoperator-amp"></a><a name="operator_amp_eq"></a>CRect::operator&amp;=  
 Conjuntos de `CRect` igual a interseção de `CRect` e `rect`.  
  
```  
void operator&=(const RECT& rect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Contém uma [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contidos em dois retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::IntersectRect](#intersectrect).  
  
##  <a name="a-nameoperatororeqa--crectoperator-124"></a><a name="operator_or_eq"></a>CRect::operator | =  
 Conjuntos de `CRect` igual a união de `CRect` e `rect`.  
  
```  
void operator|=(const RECT& rect) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Contém uma `CRect` ou [RECT](../../mfc/reference/rect-structure1.md).  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém dois retângulos de origem.  
  
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

  
##  <a name="a-nameoperatoradda--crectoperator-"></a><a name="operator_add"></a>CRect::operator +  
 As primeiras duas sobrecargas retornam um `CRect` objeto que é igual a `CRect` substituídos pelos deslocamentos especificados.  
  
```  
CRect operator+(POINT point) const throw();
CRect operator+(LPCRECT lpRect) const throw();
CRect operator+(SIZE size) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 A [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `size`  
 A [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](csize-class.md) objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para aumentar cada lado do valor de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRect` resultante da movimentação ou aumentando `CRect` pelo número de unidades especificadas no parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) parâmetros são adicionados ao `CRect`da posição.  
  
 A terceira sobrecarga retorna um novo `CRect` que é igual a `CRect` inflado pelo número de unidades especificado em cada membro do parâmetro.  
  
### <a name="example"></a>Exemplo  
```cpp  
   CRect   rect1(100, 235, 200, 335);
   CPoint pt(35, 65);
   CRect   rect2;

   rect2 = rect1 + pt;
   CRect   rectResult(135, 300, 235, 400);
   ASSERT(rectResult == rect2);   
```

  
##  <a name="a-nameoperator-a--crectoperator--"></a><a name="operator_-"></a>CRect::operator-  
 As primeiras duas sobrecargas retornam um `CRect` objeto que é igual a `CRect` substituídos pelos deslocamentos especificados.  
  
```  
CRect operator-(POINT point) const throw();
CRect operator-(SIZE size) const throw();
CRect operator-(LPCRECT lpRect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 A [ponto](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `size`  
 A [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou `CSize` objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para deflate cada lado do valor de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRect` resultante da movimentação ou deflating `CRect` pelo número de unidades especificadas no parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) parâmetros são subtraídos do `CRect`da posição.  
  
 A terceira sobrecarga retorna um novo `CRect` que é igual a `CRect` desinflada pelo número de unidades especificado em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#deflaterect), não [SubtractRect](#subtractrect).  
  
### <a name="example"></a>Exemplo  
```cpp  
   CRect   rect1(100, 235, 200, 335);
   CPoint pt(35, 65);
   CRect   rect2;

   rect2 = rect1 - pt;
   CRect   rectResult(65, 170, 165, 270);
   ASSERT(rect2 == rectResult);   
```

  
##  <a name="a-nameoperatorampa--crectoperator-amp"></a><a name="operator_amp"></a>CRect::operator&amp;  
 Retorna um `CRect` que é a interseção de `CRect` e *rect2*.  
  
```  
CRect operator&(const RECT& rect2) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *rect2*  
 Contém uma [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 A `CRect` que é a interseção de `CRect` e *rect2*.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contidos em dois retângulos.  
  
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

  
##  <a name="a-nameoperatorora--crectoperator-124"></a><a name="operator_or"></a>CRect::operator |  
 Retorna um `CRect` que é a união de `CRect` e *rect2*.  
  
```   
CRect operator|(const RECT& 
rect2) const throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *rect2*  
 Contém uma [RECT](../../mfc/reference/rect-structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 A `CRect` que é a união de `CRect` e *rect2*.  
  
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

  
##  <a name="a-nameptinrecta--crectptinrect"></a><a name="ptinrect"></a>CRect::PtInRect  
 Determina se o ponto especificado está em `CRect`.  
  
```   
BOOL PtInRect(POINT point) const throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](cpoint-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto está dentro de `CRect`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um ponto está dentro de `CRect` se ele está no lado esquerdo ou superior ou em todos os quatro lados. Um ponto no lado direito ou inferior estiver fora `CRect`.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar o retângulo antes de chamar essa função.  
  
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
  
##  <a name="a-namesetrecta--crectsetrect"></a><a name="setrect"></a>CRect::SetRect  
 Define as dimensões de `CRect` para as coordenadas especificadas.  
  
```   
void SetRect(int x1, int y1, int x2, int y2) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo.  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo.  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito.  
  
 `y2`  
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

  
##  <a name="a-namesetrectemptya--crectsetrectempty"></a><a name="setrectempty"></a>CRect::SetRectEmpty  
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
  
##  <a name="a-namesizea--crectsize"></a><a name="size"></a>CRect::SIZE 
 O `cx` e `cy` membros do valor de retorno contém a altura e largura do `CRect`.  
  
```  
CSize Size() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize](csize-class.md) que contém o tamanho do objeto `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A altura ou largura pode ser negativa.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar o retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
```cpp  
 CRect rect(10, 10, 50, 50);
 CSize sz = rect.Size();
 ASSERT(sz.cx == 40 && sz.cy == 40);  
```

##  <a name="a-namesubtractrecta--crectsubtractrect"></a><a name="subtractrect"></a>CRect::SubtractRect  
 Faz com que as dimensões do **CRect** igual a subtração de `lpRectSrc2` de `lpRectSrc1`.  
  
```  
BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRectSrc1`  
 Aponta para a [RECT](../../mfc/reference/rect-structure1.md) estrutura ou `CRect` da qual um retângulo é subtraído do objeto.  
  
 `lpRectSrc2`  
 Aponta para a `RECT` estrutura ou `CRect` objeto a ser subtraído do retângulo apontada para o `lpRectSrc1` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A subtração é o menor retângulo que contém todos os pontos de `lpRectScr1` que não estão na interseção de `lpRectScr1` e *lpRectScr2*.  
  
 O retângulo especificado por `lpRectSrc1` será alterado se o retângulo especificado por `lpRectSrc2` completamente não se sobreponha o retângulo especificado por *lpRectSrc1* em pelo menos um da x - ou y-direções.  
  
 Por exemplo, se `lpRectSrc1` foram (10,10, 100,100) e `lpRectSrc2` foram (50,50, 150,150), o retângulo apontada por `lpRectSrc1` seria inalterado quando a função é retornada. Se `lpRectSrc1` foram (10,10, 100,100) e `lpRectSrc2` foram (50,10, 150,150), no entanto, o retângulo apontada por `lpRectSrc1` conteria as coordenadas (10,10, 50,100) quando a função é retornada.  
  
 `SubtractRect`não é o mesmo que [operador -](#operator_-) nem [operador-=](#operator_-_eq). Nenhum desses operadores nunca chama `SubtractRect`.  
  
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
  
##  <a name="a-nametoplefta--crecttopleft"></a><a name="topleft"></a>CRect::TopLeft  
 As coordenadas são retornadas como uma referência a um [CPoint](cpoint-class.md) contido no objeto `CRect`.  
  
```  
CPoint& TopLeft() throw();
const CPoint& TopLeft() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas do canto superior esquerdo do retângulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função para obter ou definir o canto superior esquerdo do retângulo. Defina o canto usando essa função no lado esquerdo do operador de atribuição.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::CenterPoint](#centerpoint).  
  
##  <a name="a-nameunionrecta--crectunionrect"></a><a name="unionrect"></a>CRect::UnionRect  
 Faz com que as dimensões de `CRect` igual a união dos retângulos dois fonte.  
  
```  
BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect1`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) ou `CRect` que contém um retângulo de origem.  
  
 `lpRect2`  
 Aponta para um `RECT` ou `CRect` que contém um retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a união não está vazia. 0 se a união está vazia.  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém dois retângulos de origem.  
  
 O Windows ignora as dimensões de um retângulo vazio; ou seja, um retângulo que não tenha altura ou tem sem largura.  
  
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
 
##  <a name="a-namewidtha--crectwidth"></a><a name="width"></a>CRect::Width  
 Calcula a largura do `CRect` subtraindo o valor à esquerda do valor à direita.  
  
```  
int Width() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A largura pode ser negativa.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#normalizerect) normalizar o retângulo antes de chamar essa função.  
  
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



