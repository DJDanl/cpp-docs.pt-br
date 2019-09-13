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
ms.openlocfilehash: 26bb43355f4dff3f77a905068bea83dd1ceaf79c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491650"
---
# <a name="csize-class"></a>Classe CSize

Semelhante à estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) do Windows, que implementa uma coordenada ou posição relativa.

## <a name="syntax"></a>Sintaxe

```
class CSize : public tagSIZE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSize::CSize](#csize)|Constrói um objeto `CSize`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CSize:: Operator](#operator_-)|Subtrai dois tamanhos.|
|[CSize:: Operator! =](#operator_neq)|Verifica se há desigualdade entre `CSize` e um tamanho.|
|[CSize:: Operator +](#operator_add)|Adiciona dois tamanhos.|
|[CSize:: Operator + =](#operator_add_eq)|Adiciona um tamanho a `CSize`.|
|[CSize:: Operator-=](#operator_-_eq)|Subtrai um tamanho de `CSize`.|
|[CSize:: Operator = =](#operator_eq_eq)|Verifica a igualdade entre `CSize` e um tamanho.|

## <a name="remarks"></a>Comentários

Essa classe é derivada da `SIZE` estrutura. Isso significa que você pode passar `CSize` um em um parâmetro que chama um `SIZE` e que `SIZE` os membros de dados da estrutura são membros de dados acessíveis `CSize`do.

Os `cx` Membros `cy` e de `SIZE` ( e`CSize`) são públicos. Além disso, `CSize` o implementa funções de membro para `SIZE` manipular a estrutura.

> [!NOTE]
> Para obter mais informações sobre classes de utilitário compartilhado `CSize`(como), consulte [classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagSIZE`

`CSize`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes. h

##  <a name="csize"></a>CSize::CSize

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
Define o `cx` membro para o `CSize`.

*initCY*<br/>
Define o `cy` membro para o `CSize`.

*initSize*<br/>
Estrutura [de tamanho](/windows/win32/api/windef/ns-windef-size) ou objeto `CSize` usado para inicializar `CSize`.

*initPt*<br/>
Estrutura [de ponto](/windows/win32/api/windef/ns-windef-point) ou objeto `CPoint` usado para inicializar `CSize`.

*dwSize*<br/>
DWORD usado para inicializar `CSize`. A palavra de ordem inferior é o `cx` membro e a palavra de ordem superior é o `cy` membro.

### <a name="remarks"></a>Comentários

Se nenhum argumento for fornecido `cx` e `cy` for inicializado como zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#97](../../atl-mfc-shared/codesnippet/cpp/csize-class_1.cpp)]

##  <a name="operator_eq_eq"></a>CSize:: Operator = =

Verifica a igualdade entre dois tamanhos.

```
BOOL operator==(SIZE size) const throw();
```

### <a name="remarks"></a>Comentários

Retornará zero se os tamanhos forem iguais, otherwize 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#98](../../atl-mfc-shared/codesnippet/cpp/csize-class_2.cpp)]

##  <a name="operator_neq"></a>CSize:: Operator! =

Verifica se há desigualdade entre dois tamanhos.

```
BOOL operator!=(SIZE size) const throw();
```

### <a name="remarks"></a>Comentários

Retornará zero se os tamanhos não forem iguais, caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#99](../../atl-mfc-shared/codesnippet/cpp/csize-class_3.cpp)]

##  <a name="operator_add_eq"></a>CSize:: Operator + =

Adiciona um tamanho a isso `CSize`.

```
void operator+=(SIZE size) throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#100](../../atl-mfc-shared/codesnippet/cpp/csize-class_4.cpp)]

##  <a name="operator_-_eq"></a>CSize:: Operator-=

Subtrai um tamanho `CSize`deste.

```
void operator-=(SIZE size) throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#101](../../atl-mfc-shared/codesnippet/cpp/csize-class_5.cpp)]

##  <a name="operator_add"></a>CSize:: Operator +

Esses operadores adicionam `CSize` esse valor ao valor do parâmetro.

```
CSize operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw();
```

### <a name="remarks"></a>Comentários

Consulte as seguintes descrições dos operadores individuais:

- **operador + (** *tamanho* **)**

  Esta operação adiciona dois `CSize` valores.

- **operador + (** *ponto* **)**

  Esta operação desloca (move) um valor de [ponto](/previous-versions/dd162805\(v=vs.85\)) (ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md)) por esse `CSize` valor. Os `cx` Membros `cy` e `x` `y` desse valorsão`POINT` adicionados aos membros de dados e do valor. `CSize` É análogo à versão de [CPoint:: Operator +](../../atl-mfc-shared/reference/cpoint-class.md#operator_add) que usa um parâmetro de [tamanho](/windows/win32/api/windef/ns-windef-size) .

- **operator +(** *lpRect* **)**

   Esta operação desloca (move) um valor [Rect](/previous-versions/dd162897\(v=vs.85\)) (ou [CRect](../../atl-mfc-shared/reference/crect-class.md)) por esse `CSize` valor. Os `cx` Membros `cy` e desse `top` `right` `left` `bottom` valor são adicionados aos membros de dados,, e do `RECT` valor. `CSize` É análogo à versão de [CRect:: Operator +](../../atl-mfc-shared/reference/crect-class.md#operator_add) que usa um parâmetro de [tamanho](/windows/win32/api/windef/ns-windef-size) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#102](../../atl-mfc-shared/codesnippet/cpp/csize-class_6.cpp)]

##  <a name="operator_-"></a>Operador CSize:: Operator

Os três primeiros desses operadores subtraim `CSize` esse valor para o valor do parâmetro.

```
CSize operator-(SIZE size) const throw();
CPoint operator-(POINT point) const throw();
CRect operator-(const RECT* lpRect) const throw();
CSize operator-() const throw();
```

### <a name="remarks"></a>Comentários

O quarto operador, o sinal de menos unário, altera o `CSize` sinal do valor. Consulte as seguintes descrições dos operadores individuais:

- **operator -(** *size* **)**

  Esta operação subtrai dois `CSize` valores.

- **operador-(** *ponto* **)**

  Esta operação desloca (move) um valor de [ponto](/previous-versions/dd162805\(v=vs.85\)) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) pelo `CSize` inverso aditivo deste valor. O `cx` e `POINT` `y` `x` desse valor são subtraídos dos membros de dados e do valor. `CSize` `cy` É análogo à versão de [CPoint:: Operator-](../../atl-mfc-shared/reference/cpoint-class.md#operator_-) que usa um parâmetro de [tamanho](/windows/win32/api/windef/ns-windef-size) .

- **operator -(** *lpRect* **)**

  Esta operação desloca (move) um valor [Rect](/previous-versions/dd162897\(v=vs.85\)) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) pelo `CSize` inverso aditivo desse valor. Os `cx` Membros `cy` e desse `top` valorsão`bottom` subtraídos `left`dos membros de dados, `RECT` , e do valor. `right` `CSize` É análogo à versão de [CRect:: Operator-](../../atl-mfc-shared/reference/crect-class.md#operator_-) que usa um parâmetro de [tamanho](/windows/win32/api/windef/ns-windef-size) .

- **operator -()**

  Esta operação retorna o inverso `CSize` aditivo deste valor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#103](../../atl-mfc-shared/codesnippet/cpp/csize-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)<br/>
[Classe CPoint](../../atl-mfc-shared/reference/cpoint-class.md)
