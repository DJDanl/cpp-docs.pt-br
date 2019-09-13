---
title: Classe CPoint
ms.date: 11/04/2016
f1_keywords:
- CPoint
- ATLTYPES/ATL::CPoint
- ATLTYPES/ATL::CPoint::CPoint
- ATLTYPES/ATL::CPoint::Offset
helpviewer_keywords:
- LPPOINT structure
- POINT structure
- CPoint class
ms.assetid: a6d4db93-35cc-444d-9221-c3e160f6edaa
ms.openlocfilehash: b7c13ef8b9656c5c2fa6a90fefca0d9babbe1c84
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491222"
---
# <a name="cpoint-class"></a>Classe CPoint

Semelhante à estrutura do `POINT` Windows.

## <a name="syntax"></a>Sintaxe

```
class CPoint : public tagPOINT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPoint::CPoint](#cpoint)|Constrói um `CPoint`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPoint::Offset](#offset)|Adiciona valores aos `x` Membros e `y` do. `CPoint`|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CPoint:: Operator](#operator_-)|Retorna a diferença de um `CPoint` tamanho, ou a negação de um ponto, ou a diferença de tamanho entre dois pontos ou o deslocamento por um tamanho negativo.|
|[CPoint:: Operator! =](#operator_neq)|Verifica se há desigualdade entre dois pontos.|
|[CPoint:: Operator +](#operator_add)|Retorna a soma de um `CPoint` e um tamanho ou ponto ou um `CRect` deslocamento por um tamanho.|
|[CPoint:: Operator + =](#operator_add_eq)|`CPoint` Deslocamentos adicionando um tamanho ou um ponto.|
|[CPoint:: Operator-=](#operator_-_eq)|`CPoint` Deslocamentos subtraindo um tamanho ou ponto.|
|[CPoint:: Operator = =](#operator_eq_eq)|Verifica a igualdade entre dois pontos.|

## <a name="remarks"></a>Comentários

Ele também inclui funções de membro para `CPoint` manipular [e](/windows/win32/api/windef/ns-windef-point) estruturar estruturas.

Um `CPoint` objeto pode ser usado sempre que `POINT` uma estrutura é usada. Os operadores dessa classe que interagem com um "tamanho" aceitam objetos [CSize](../../atl-mfc-shared/reference/csize-class.md) ou estruturas de [tamanho](/windows/win32/api/windef/ns-windef-size) , pois os dois são intercambiáveis.

> [!NOTE]
>  Essa classe é derivada da `tagPOINT` estrutura. (O nome `tagPOINT` é um nome usado com menos frequência para `POINT` a estrutura.) Isso significa que os membros de dados da `POINT` `x` estrutura e `y`, são membros de dados acessíveis do `CPoint`.

> [!NOTE]
>  Para obter mais informações sobre classes de utilitário compartilhado `CPoint`(como), consulte [classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagPOINT`

`CPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes. h

##  <a name="cpoint"></a>CPoint::CPoint

Constrói um objeto `CPoint`.

```
CPoint() throw();
CPoint(int initX, int initY) throw();
CPoint(POINT initPt) throw();
CPoint(SIZE initSize) throw();
CPoint(LPARAM dwPoint) throw();
```

### <a name="parameters"></a>Parâmetros

*initX*<br/>
Especifica o valor do membro `x` de `CPoint`.

*initY*<br/>
Especifica o valor do membro `y` de `CPoint`.

*initPt*<br/>
Estrutura [de ponto](/windows/win32/api/windef/ns-windef-point) ou `CPoint` que especifica os valores usados para inicializar `CPoint`.

*initSize*<br/>
Estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica os valores usados para `CPoint`inicializar.

*dwPoint*<br/>
Define o `x` membro para a palavra de ordem inferior de *dwPoint* e o `y` membro para a palavra de ordem superior de *dwPoint*.

### <a name="remarks"></a>Comentários

Se nenhum argumento for fornecido, os membros `x` e `y` serão definidos como 0.

### <a name="example"></a>Exemplo

```cpp
CPoint   ptTopLeft(0, 0);
// works from a POINT, too

POINT   ptHere;
ptHere.x = 35;
ptHere.y = 95;

CPoint   ptMFCHere(ptHere);

// works from a SIZE
SIZE   sHowBig;
sHowBig.cx = 300;
sHowBig.cy = 10;

CPoint ptMFCBig(sHowBig);
// or from a DWORD

DWORD   dwSize;
dwSize = MAKELONG(35, 95);

CPoint ptFromDouble(dwSize);
ASSERT(ptFromDouble == ptMFCHere);
```

##  <a name="offset"></a>  CPoint::Offset

Adiciona valores aos `x` Membros e `y` do. `CPoint`

```
void Offset(int xOffset, int yOffset) throw();
void Offset(POINT point) throw();
void Offset(SIZE size) throw();
```

### <a name="parameters"></a>Parâmetros

*xOffset*<br/>
Especifica o valor para compensar `x` o membro `CPoint`do.

*yOffset*<br/>
Especifica o valor para compensar `y` o membro `CPoint`do.

*point*<br/>
Especifica o valor ( [ponto](/windows/win32/api/windef/ns-windef-point) ou `CPoint`) para deslocar o `CPoint`.

*size*<br/>
Especifica a quantidade ( [tamanho](/windows/win32/api/windef/ns-windef-size) ou [CSize](../../atl-mfc-shared/reference/csize-class.md)) para deslocar o `CPoint`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#28](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_1.cpp)]

##  <a name="operator_eq_eq"></a>CPoint:: Operator = =

Verifica a igualdade entre dois pontos.

```
BOOL operator==(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Contém uma estrutura [de ponto](/windows/win32/api/windef/ns-windef-point) ou um objeto `CPoint`.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os pontos forem iguais; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#29](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_2.cpp)]

##  <a name="operator_neq"></a>CPoint:: Operator! =

Verifica se há desigualdade entre dois pontos.

```
BOOL operator!=(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Contém uma estrutura [de ponto](/windows/win32/api/windef/ns-windef-point) ou um objeto `CPoint`.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os pontos não forem iguais; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#30](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_3.cpp)]

##  <a name="operator_add_eq"></a>CPoint:: Operator + =

A primeira sobrecarga adiciona um tamanho ao `CPoint`.

```
void operator+=(SIZE size) throw();
void operator+=(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Contém uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .

*point*<br/>
Contém um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) .

### <a name="remarks"></a>Comentários

A segunda sobrecarga adiciona um ponto ao `CPoint`.

Em ambos os `x` casos, `x` `y` `cx` aadição`cy`é feita adicionando o membro (ou) do operando à direita para o membro do eadicionandoomembro(ou)dooperandoàdireitaparao`CPoint` `y` membro`CPoint`do.

Por exemplo, adicionar `CPoint(5, -7)` a uma variável que contém `CPoint(30, 40)` altera a variável para `CPoint(35, 33)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#31](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_4.cpp)]

##  <a name="operator_-_eq"></a>CPoint:: Operator-=

A primeira sobrecarga subtrai um tamanho do `CPoint`.

```
void operator-=(SIZE size) throw();
void operator-=(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Contém uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .

*point*<br/>
Contém um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) .

### <a name="remarks"></a>Comentários

A segunda sobrecarga subtrai um ponto do `CPoint`.

Em ambos os casos, `x` a subtração é feita subtraindo o `cx`membro (ou) do operando à direita `CPoint` do `x` membro do e subtraindo o `y` membro (ou `cy`) do lado direito operando do `y` membro `CPoint`do.

Por exemplo, a subtração `CPoint(5, -7)` de uma variável que contém `CPoint(30, 40)` altera a variável `CPoint(25, 47)`para.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#32](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_5.cpp)]

##  <a name="operator_add"></a>CPoint:: Operator +

Use esse operador para deslocar `CPoint` por um `CPoint` objeto `CSize` ou ou para deslocar um `CRect` por um `CPoint`.

```
CPoint operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Contém uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .

*point*<br/>
Contém um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) .

*lpRect*<br/>
Contém um ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) .

### <a name="return-value"></a>Valor de retorno

Um `CPoint` que é deslocado por um tamanho, `CPoint` um que é deslocado por um ponto ou `CRect` um deslocamento por um ponto.

### <a name="remarks"></a>Comentários

Por exemplo, usar uma das duas primeiras sobrecargas `CPoint(25, -19)` para deslocar o ponto por um ponto `CPoint(15, 5)` ou tamanho `CSize(15, 5)` retorna o valor `CPoint(40, -14)`.

A adição de um retângulo a um ponto retorna o retângulo depois de `x` ser deslocado pelos valores e `y` especificados no ponto. Por exemplo, usar a última sobrecarga para deslocar um retângulo `CRect(125, 219, 325, 419)` por um ponto `CPoint(25, -19)` retorna `CRect(150, 200, 350, 400)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#33](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_6.cpp)]

##  <a name="operator_-"></a>Operador CPoint:: Operator

Use uma das duas primeiras sobrecargas para subtrair `CPoint` um `CSize` objeto ou `CPoint`de.

```
CSize operator-(POINT point) const throw();
CPoint operator-(SIZE size) const throw();
CRect operator-(const RECT* lpRect) const throw();
CPoint operator-() const throw();
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
Um objeto de estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) .

*size*<br/>
Uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) ou um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .

*lpRect*<br/>
Um ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) .

### <a name="return-value"></a>Valor de retorno

R `CSize` que é a diferença entre dois pontos, um `CPoint` que é deslocado pela negação de um tamanho, um `CRect` que é deslocado pela negação de um ponto ou um `CPoint` que é a negação de um ponto.

### <a name="remarks"></a>Comentários

A terceira sobrecarga desloca uma `CRect` pela negação de. `CPoint` Por fim, use o operador unário para `CPoint`negar.

Por exemplo, usando a primeira sobrecarga para localizar a diferença entre dois pontos `CPoint(25, -19)` e `CPoint(15, 5)` retorna `CSize(10, -24)`.

A subtração `CSize` de `CPoint` um de faz o mesmo cálculo acima, mas `CPoint` retorna um objeto, `CSize` não um objeto. Por exemplo, usando a segunda sobrecarga para localizar a diferença entre o ponto `CPoint(25, -19)` e o tamanho `CSize(15, 5)` retorna `CPoint(10, -24)`.

Subtrair um retângulo de um ponto retorna o deslocamento de retângulo pelos negativos dos `x` valores e `y` especificados no ponto. Por exemplo, usar a última sobrecarga para deslocar o retângulo `CRect(125, 200, 325, 400)` pelo ponto `CPoint(25, -19)` retorna `CRect(100, 219, 300, 419)`.

Use o operador unário para negar um ponto. Por exemplo, o uso do operador unário com `CPoint(25, -19)` o `CPoint(-25, 19)`ponto retorna.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#34](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Estrutura de ponto](/windows/win32/api/windef/ns-windef-point)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)<br/>
[Classe CSize](../../atl-mfc-shared/reference/csize-class.md)
