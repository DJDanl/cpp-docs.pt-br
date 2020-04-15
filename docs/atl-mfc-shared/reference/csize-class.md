---
title: Classe CSize
ms.date: 10/18/2018
f1_keywords:
- CSize
- ATLTYPES/ATL::CSize
- ATLTYPES/ATL::CSize::CSize
helpviewer_keywords:
- SIZE
- dimensions, MFC
- dimensions
- CSize class
ms.assetid: fb2cf85a-0bc1-46f8-892b-309c108b52ae
ms.openlocfilehash: 6d1b82e3f60428e3a778709dc69de983a7f886bf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317668"
---
# <a name="csize-class"></a>Classe CSize

Semelhante à estrutura do Windows [SIZE,](/windows/win32/api/windef/ns-windef-size) que implementa uma coordenada ou posição relativa.

## <a name="syntax"></a>Sintaxe

```
class CSize : public tagSIZE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[tamanho c::CSize](#csize)|Constrói um objeto `CSize`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSize::operador -](#operator_-)|Subtrai dois tamanhos.|
|[CSize::operador !=](#operator_neq)|Verifica a desigualdade `CSize` entre e um tamanho.|
|[Tamanho c::operador +](#operator_add)|Adiciona dois tamanhos.|
|[Tamanho c::operador +=](#operator_add_eq)|Adiciona um `CSize`tamanho a .|
|[CSize::operador -=](#operator_-_eq)|Subtrai um tamanho `CSize`de .|
|[Tamanho c::operador ==](#operator_eq_eq)|Verifica a igualdade `CSize` entre e um tamanho.|

## <a name="remarks"></a>Comentários

Esta classe é derivada da `SIZE` estrutura. Isso significa que `CSize` você pode passar um `SIZE` parâmetro que exige a `SIZE` e que os `CSize`membros de dados da estrutura são membros de dados acessíveis de .

Os `cx` `cy` membros `SIZE` e `CSize`membros (e ) são públicos. Além disso, `CSize` implementa funções `SIZE` de membros para manipular a estrutura.

> [!NOTE]
> Para obter mais informações sobre `CSize`classes de utilidade compartilhadas (like), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagSIZE`

`CSize`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes.h

## <a name="csizecsize"></a><a name="csize"></a>tamanho c::CSize

Constrói um objeto `CSize`.

```
CSize() throw();
CSize( int initCX, int initCY) throw();
CSize( SIZE initSize) throw();
CSize( POINT initPt) throw();
CSize( DWORD dwSize) throw();
```

### <a name="parameters"></a>Parâmetros

*initCX*<br/>
Define `cx` o membro `CSize`para o .

*initCY*<br/>
Define `cy` o membro `CSize`para o .

*initSize*<br/>
[ESTRUTURA](/windows/win32/api/windef/ns-windef-size) DE `CSize` TAMANHO ou `CSize`objeto usado para inicializar .

*initPt*<br/>
[Estrutura](/windows/win32/api/windef/ns-windef-point) point `CPoint` ou objeto `CSize`usado para inicializar .

*Dwsize*<br/>
DWORD usado para `CSize`inicializar . A palavra de baixa `cx` ordem é o membro `cy` e a palavra de alta ordem é o membro.

### <a name="remarks"></a>Comentários

Se nenhum argumento for `cx` `cy` dado, e for inicializado a zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#97](../../atl-mfc-shared/codesnippet/cpp/csize-class_1.cpp)]

## <a name="csizeoperator-"></a><a name="operator_eq_eq"></a>Tamanho c::operador ==

Verifica a igualdade entre dois tamanhos.

```
BOOL operator==(SIZE size) const throw();
```

### <a name="remarks"></a>Comentários

Retorna não zero se os tamanhos forem iguais, caso contrário 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#98](../../atl-mfc-shared/codesnippet/cpp/csize-class_2.cpp)]

## <a name="csizeoperator-"></a><a name="operator_neq"></a>CSize::operador !=

Verifica a desigualdade entre dois tamanhos.

```
BOOL operator!=(SIZE size) const throw();
```

### <a name="remarks"></a>Comentários

Retorna não zero se os tamanhos não forem iguais, caso contrário 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#99](../../atl-mfc-shared/codesnippet/cpp/csize-class_3.cpp)]

## <a name="csizeoperator-"></a><a name="operator_add_eq"></a>Tamanho c::operador +=

Adiciona um tamanho `CSize`a isso .

```
void operator+=(SIZE size) throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#100](../../atl-mfc-shared/codesnippet/cpp/csize-class_4.cpp)]

## <a name="csizeoperator--"></a><a name="operator_-_eq"></a>CSize::operador -=

Subtrai um tamanho `CSize`disso.

```
void operator-=(SIZE size) throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#101](../../atl-mfc-shared/codesnippet/cpp/csize-class_5.cpp)]

## <a name="csizeoperator-"></a><a name="operator_add"></a>Tamanho c::operador +

Esses operadores `CSize` adicionam esse valor ao valor do parâmetro.

```
CSize operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw();
```

### <a name="remarks"></a>Comentários

Veja as descrições a seguir dos operadores individuais:

- **operador +(tamanho)** *size* **)**

  Esta operação `CSize` adiciona dois valores.

- **operador +(ponto)** *point* **)**

  Esta operação compensa (move) um [valor POINT](/previous-versions/dd162805\(v=vs.85\)) (ou [CPoint)](../../atl-mfc-shared/reference/cpoint-class.md)por este `CSize` valor. Os `cx` `cy` membros deste `CSize` valor são `x` adicionados aos membros e `y` dados do `POINT` valor. Ele é análogo à versão do [CPoint::operator +](../../atl-mfc-shared/reference/cpoint-class.md#operator_add) que leva um parâmetro [SIZE.](/windows/win32/api/windef/ns-windef-size)

- **operador +(** *lpRect* **)**

   Esta operação compensa (move) um valor [RECT](/previous-versions/dd162897\(v=vs.85\)) (ou `CSize` [CRect)](../../atl-mfc-shared/reference/crect-class.md)por este valor. Os `cx` `cy` membros deste `CSize` valor são adicionados `right`aos `bottom` membros `RECT` `left` `top`do valor e dos dados. É análogo à versão de [CRect::operator +](../../atl-mfc-shared/reference/crect-class.md#operator_add) que leva um parâmetro [SIZE.](/windows/win32/api/windef/ns-windef-size)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#102](../../atl-mfc-shared/codesnippet/cpp/csize-class_6.cpp)]

## <a name="csizeoperator--"></a><a name="operator_-"></a>CSize::operador -

Os três primeiros operadores subtraem esse `CSize` valor ao valor do parâmetro.

```
CSize operator-(SIZE size) const throw();
CPoint operator-(POINT point) const throw();
CRect operator-(const RECT* lpRect) const throw();
CSize operator-() const throw();
```

### <a name="remarks"></a>Comentários

O quarto operador, o unary minus, `CSize` muda o sinal do valor. Veja as descrições a seguir dos operadores individuais:

- **operador -(tamanho)** *size* **)**

  Esta operação subtrai `CSize` dois valores.

- **operador -(ponto)** *point* **)**

  Esta operação compensa (move) um valor [POINT](/previous-versions/dd162805\(v=vs.85\)) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) pelo inverso aditivo deste `CSize` valor. O `cx` `cy` e `CSize` deste valor são subtraídos dos `x` membros e `y` dados do `POINT` valor. Ele é análogo à versão do [CPoint::operator -](../../atl-mfc-shared/reference/cpoint-class.md#operator_-) que leva um parâmetro [SIZE.](/windows/win32/api/windef/ns-windef-size)

- operador *-(lpRect)* **)** **operator -(**

  Esta operação compensa (move) um valor [RECT](/previous-versions/dd162897\(v=vs.85\)) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) pelo inverso aditivo deste `CSize` valor. Os `cx` `cy` membros deste `CSize` valor são subtraídos `top` `right`dos `left` `bottom` membros do `RECT` valor e dos dados. É análogo à versão de [CRect::operator -](../../atl-mfc-shared/reference/crect-class.md#operator_-) que leva um parâmetro [SIZE.](/windows/win32/api/windef/ns-windef-size)

- **operador -()**

  Esta operação devolve o aditivo `CSize` inverso deste valor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#103](../../atl-mfc-shared/codesnippet/cpp/csize-class_7.cpp)]

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)<br/>
[Classe CPoint](../../atl-mfc-shared/reference/cpoint-class.md)
