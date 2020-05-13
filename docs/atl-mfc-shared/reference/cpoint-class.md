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
ms.openlocfilehash: 331b89ff118f727303e887670960ee6078b01fb1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747089"
---
# <a name="cpoint-class"></a>Classe CPoint

Semelhante à `POINT` estrutura do Windows.

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
|[CPoint::Deslocamento](#offset)|Adiciona valores `x` `y` aos membros `CPoint`e membros do .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPoint::operador -](#operator_-)|Retorna a diferença `CPoint` de a e um tamanho, ou a negação de um ponto, ou a diferença de tamanho entre dois pontos, ou o compensado por um tamanho negativo.|
|[CPoint::operador !=](#operator_neq)|Verifica a desigualdade entre dois pontos.|
|[CPoint::operador +](#operator_add)|Retorna a soma `CPoint` de um e um `CRect` tamanho ou ponto, ou um deslocamento por um tamanho.|
|[CPoint::operador +=](#operator_add_eq)|Compensa `CPoint` adicionando um tamanho ou ponto.|
|[CPoint::operador -=](#operator_-_eq)|Compensa `CPoint` subtraindo um tamanho ou ponto.|
|[CPoint::operador ==](#operator_eq_eq)|Verifica a igualdade entre dois pontos.|

## <a name="remarks"></a>Comentários

Ele também inclui funções `CPoint` de membro para manipular e estruturas [POINT.](/windows/win32/api/windef/ns-windef-point)

Um `CPoint` objeto pode ser `POINT` usado onde uma estrutura é usada. Os operadores desta classe que interagem com um "tamanho" aceitam objetos [CSize](../../atl-mfc-shared/reference/csize-class.md) ou estruturas [SIZE,](/windows/win32/api/windef/ns-windef-size) uma vez que os dois são intercambiáveis.

> [!NOTE]
> Esta classe é derivada da `tagPOINT` estrutura. (O `tagPOINT` nome é um nome menos `POINT` usado para a estrutura.) Isso significa que os `POINT` membros `x` de `y`dados da estrutura, e , são membros de dados acessíveis de `CPoint`.

> [!NOTE]
> Para obter mais informações sobre `CPoint`classes de utilidade compartilhadas (like), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagPOINT`

`CPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes.h

## <a name="cpointcpoint"></a><a name="cpoint"></a>CPoint::CPoint

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

*inity*<br/>
Especifica o valor do membro `y` de `CPoint`.

*initPt*<br/>
[Estrutura](/windows/win32/api/windef/ns-windef-point) POINT `CPoint` ou que especifique `CPoint`os valores usados para inicializar .

*initSize*<br/>
[Estrutura DE TAMANHO](/windows/win32/api/windef/ns-windef-size) ou [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica `CPoint`os valores usados para inicializar .

*dwPoint*<br/>
Define `x` o membro para a palavra de baixa `y` ordem do *dwPoint* e do membro para a palavra de alta ordem do *dwPoint*.

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

## <a name="cpointoffset"></a><a name="offset"></a>CPoint::Deslocamento

Adiciona valores `x` `y` aos membros `CPoint`e membros do .

```cpp
void Offset(int xOffset, int yOffset) throw();
void Offset(POINT point) throw();
void Offset(SIZE size) throw();
```

### <a name="parameters"></a>Parâmetros

*xOffset*<br/>
Especifica o valor para `x` compensar `CPoint`o membro do .

*yOffset*<br/>
Especifica o valor para `y` compensar `CPoint`o membro do .

*Ponto*<br/>
Especifica a quantidade [(POINT](/windows/win32/api/windef/ns-windef-point) `CPoint`ou) `CPoint`para compensar o .

*size*<br/>
Especifica a quantidade [(SIZE](/windows/win32/api/windef/ns-windef-size) ou [CSize)](../../atl-mfc-shared/reference/csize-class.md)para compensar o `CPoint`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#28](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_1.cpp)]

## <a name="cpointoperator-"></a><a name="operator_eq_eq"></a>CPoint::operador ==

Verifica a igualdade entre dois pontos.

```
BOOL operator==(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Contém uma estrutura `CPoint` ou objeto [POINT.](/windows/win32/api/windef/ns-windef-point)

### <a name="return-value"></a>Valor retornado

Não zero se os pontos forem iguais; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#29](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_2.cpp)]

## <a name="cpointoperator-"></a><a name="operator_neq"></a>CPoint::operador !=

Verifica a desigualdade entre dois pontos.

```
BOOL operator!=(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Contém uma estrutura `CPoint` ou objeto [POINT.](/windows/win32/api/windef/ns-windef-point)

### <a name="return-value"></a>Valor retornado

Não zero se os pontos não forem iguais; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#30](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_3.cpp)]

## <a name="cpointoperator-"></a><a name="operator_add_eq"></a>CPoint::operador +=

A primeira sobrecarga adiciona `CPoint`um tamanho ao .

```cpp
void operator+=(SIZE size) throw();
void operator+=(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Contém uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)

*Ponto*<br/>
Contém uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint.](../../atl-mfc-shared/reference/cpoint-class.md)

### <a name="remarks"></a>Comentários

A segunda sobrecarga adiciona `CPoint`um ponto ao .

Em ambos os casos, o `x` acréscimo `cx`é feito adicionando o (ou `x` ) `CPoint` membro do `y` opere direito ao membro do e adicionando o (ou `cy`) membro do opere direito ao `y` membro do `CPoint`.

Por exemplo, `CPoint(5, -7)` adicionar a `CPoint(30, 40)` uma variável `CPoint(35, 33)`que contém alterações da variável para .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#31](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_4.cpp)]

## <a name="cpointoperator--"></a><a name="operator_-_eq"></a>CPoint::operador -=

A primeira sobrecarga subtrai um `CPoint`tamanho do .

```cpp
void operator-=(SIZE size) throw();
void operator-=(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Contém uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)

*Ponto*<br/>
Contém uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint.](../../atl-mfc-shared/reference/cpoint-class.md)

### <a name="remarks"></a>Comentários

A segunda sobrecarga subtrai um `CPoint`ponto do .

Em ambos os casos, a subtração `x` é `cx`feita subtraindo o (ou `x` ) membro `CPoint` do opere `cy`direito do membro e subtraindo `y` o `y` (ou ) membro do opere direito do membro do . `CPoint`

Por exemplo, subtraindo `CPoint(5, -7)` de `CPoint(30, 40)` uma variável `CPoint(25, 47)`que contém altera a variável para .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#32](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_5.cpp)]

## <a name="cpointoperator-"></a><a name="operator_add"></a>CPoint::operador +

Use este operador `CPoint` para `CPoint` `CSize` compensar por um `CRect` ou `CPoint`objeto, ou para compensar um por um .

```
CPoint operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Contém uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)

*Ponto*<br/>
Contém uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint.](../../atl-mfc-shared/reference/cpoint-class.md)

*Lprect*<br/>
Contém um ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto [CRect.](../../atl-mfc-shared/reference/crect-class.md)

### <a name="return-value"></a>Valor retornado

Um `CPoint` que é compensado `CPoint` por um tamanho, um `CRect` que é compensado por um ponto, ou um compensado por um ponto.

### <a name="remarks"></a>Comentários

Por exemplo, usar uma das duas primeiras `CPoint(25, -19)` sobrecargas `CPoint(15, 5)` para `CSize(15, 5)` compensar o `CPoint(40, -14)`ponto por um ponto ou tamanho retorna o valor .

Adicionar um retângulo a um ponto retorna o `x` retângulo após ser compensado pelos valores `y` especificados no ponto. Por exemplo, usando a última sobrecarga `CRect(125, 219, 325, 419)` para compensar `CPoint(25, -19)` `CRect(150, 200, 350, 400)`um retângulo por um ponto de retorno .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#33](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_6.cpp)]

## <a name="cpointoperator--"></a><a name="operator_-"></a>CPoint::operador -

Use uma das duas primeiras sobrecargas `CPoint` `CSize` para `CPoint`subtrair um ou objeto de .

```
CSize operator-(POINT point) const throw();
CPoint operator-(SIZE size) const throw();
CRect operator-(const RECT* lpRect) const throw();
CPoint operator-() const throw();
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
Uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) ou objeto [CPoint.](../../atl-mfc-shared/reference/cpoint-class.md)

*size*<br/>
Uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) ou objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)

*Lprect*<br/>
Um ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect.](../../atl-mfc-shared/reference/crect-class.md)

### <a name="return-value"></a>Valor retornado

Um `CSize` que é a diferença `CPoint` entre dois pontos, um que é `CRect` compensado pela negação de um `CPoint` tamanho, um que é compensado pela negação de um ponto, ou um que é a negação de um ponto.

### <a name="remarks"></a>Comentários

A terceira sobrecarga `CRect` compensa a pela `CPoint`negação de . Por fim, use o operador `CPoint`unary para negar .

Por exemplo, usando a primeira sobrecarga para `CPoint(25, -19)` `CPoint(15, 5)` encontrar `CSize(10, -24)`a diferença entre dois pontos e retornos .

Subtrair um `CSize` `CPoint` faz o mesmo cálculo que `CPoint` acima, `CSize` mas retorna um objeto, não um objeto. Por exemplo, usando a segunda sobrecarga para `CPoint(25, -19)` encontrar `CSize(15, 5)` a `CPoint(10, -24)`diferença entre o ponto e o tamanho retorna .

Subtrair um retângulo de um ponto retorna o retângulo `x` `y` compensado pelos negativos dos valores e valores especificados no ponto. Por exemplo, usando a última sobrecarga `CRect(125, 200, 325, 400)` para compensar `CPoint(25, -19)` `CRect(100, 219, 300, 419)`o retângulo pelos retornos de ponto .

Use o operador unary para negar um ponto. Por exemplo, usando o operador `CPoint(25, -19)` unary com o retorno do ponto `CPoint(-25, 19)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#34](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_7.cpp)]

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Estrutura point](/windows/win32/api/windef/ns-windef-point)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)<br/>
[Classe CSize](../../atl-mfc-shared/reference/csize-class.md)
