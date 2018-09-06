---
title: Classe CPoint | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPoint
- ATLTYPES/ATL::CPoint
- ATLTYPES/ATL::CPoint::CPoint
- ATLTYPES/ATL::CPoint::Offset
dev_langs:
- C++
helpviewer_keywords:
- LPPOINT structure
- POINT structure
- CPoint class
ms.assetid: a6d4db93-35cc-444d-9221-c3e160f6edaa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bc0506d5b4f264a2bdbecf30a7732c93c927bf18
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43767976"
---
# <a name="cpoint-class"></a>Classe CPoint

Semelhante do Windows `POINT` estrutura.

## <a name="syntax"></a>Sintaxe

```
class CPoint : public tagPOINT 
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPoint::CPoint](#cpoint)|Constrói um `CPoint`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPoint::Offset](#offset)|Adiciona os valores para o `x` e `y` os membros a `CPoint`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPoint::operator-](#operator_-)|Retorna a diferença entre um `CPoint` e um tamanho ou a negação de um ponto ou a diferença de tamanho entre dois pontos ou o deslocamento por um tamanho negativo.|
|[CPoint::operator! =](#operator_neq)|Verifica a desigualdade entre dois pontos.|
|[CPoint::operator +](#operator_add)|Retorna a soma de uma `CPoint` e um tamanho ou um ponto, ou um `CRect` deslocado em um tamanho.|
|[+ CPoint::operator =](#operator_add_eq)|Desloca `CPoint` adicionando um tamanho ou ponto.|
|[CPoint::operator =](#operator_-_eq)|Desloca `CPoint` subtraindo-se um tamanho ou ponto.|
|[CPoint::operator = =](#operator_eq_eq)|Verificações de igualdade entre dois pontos.|

## <a name="remarks"></a>Comentários

Ele também inclui funções de membro para manipular `CPoint` e [ponto](../../mfc/reference/point-structure1.md) estruturas.

Um `CPoint` objeto pode ser usado onde quer que um `POINT` estrutura é usada. Os operadores dessa classe que interagem com um "tamanho" aceitam qualquer um [CSize](../../atl-mfc-shared/reference/csize-class.md) objetos ou [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estruturas, desde que os dois são intercambiáveis.

> [!NOTE]
>  Essa classe é derivada de `tagPOINT` estrutura. (O nome `tagPOINT` é um nome menos usado para o `POINT` estrutura.) Isso significa que os membros de dados do `POINT` estrutura de `x` e `y`, são membros de dados acessíveis de `CPoint`.

> [!NOTE]
>  Para obter mais informações sobre classes de utilitário de compartilhados (como `CPoint`), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagPOINT`

`CPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes. h

##  <a name="cpoint"></a>  CPoint::CPoint

Constrói um objeto `CPoint`.

```
CPoint() throw();
CPoint(int initX, int initY) throw();
CPoint(POINT initPt) throw();
CPoint(SIZE initSize) throw();
CPoint(LPARAM dwPoint) throw();
```

### <a name="parameters"></a>Parâmetros

*initX*  
Especifica o valor do membro `x` de `CPoint`.

*initY*  
Especifica o valor do membro `y` de `CPoint`.

*initPt*  
[PONTO](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` que especifica os valores usados para inicializar `CPoint`.

*initSize*  
[TAMANHO](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica os valores usados para inicializar `CPoint`.

*dwPoint*  
Conjuntos a `x` membro para a palavra de ordem baixa *dwPoint* e o `y` membro para a palavra de ordem alta *dwPoint*.

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

Adiciona os valores para o `x` e `y` os membros a `CPoint`.

```
void Offset(int xOffset, int yOffset) throw();
void Offset(POINT point) throw();
void Offset(SIZE size) throw();
```

### <a name="parameters"></a>Parâmetros

*deslocamento x*  
Especifica a quantidade para deslocar o `x` membro o `CPoint`.

*deslocamento y*  
Especifica a quantidade para deslocar o `y` membro o `CPoint`.

*ponto*  
Especifica a quantidade ( [ponto](../../mfc/reference/point-structure1.md) ou `CPoint`) para deslocar o `CPoint`.

*size*  
Especifica a quantidade ( [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](../../atl-mfc-shared/reference/csize-class.md)) para deslocar o `CPoint`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#28](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_1.cpp)]

##  <a name="operator_eq_eq"></a>  CPoint::operator = =

Verificações de igualdade entre dois pontos.

```
BOOL operator==(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*ponto*  
Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os pontos forem iguais; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#29](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_2.cpp)]

##  <a name="operator_neq"></a>  CPoint::operator! =

Verifica a desigualdade entre dois pontos.

```
BOOL operator!=(POINT point) const throw();
```

### <a name="parameters"></a>Parâmetros

*ponto*  
Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os pontos não forem iguais; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#30](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_3.cpp)]

##  <a name="operator_add_eq"></a>  + CPoint::operator =

A primeira sobrecarga adiciona um tamanho para o `CPoint`.

```
void operator+=(SIZE size) throw(); 
void operator+=(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*size*  
Contém uma [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.

*ponto*  
Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.

### <a name="remarks"></a>Comentários

A segunda sobrecarga adiciona um ponto para o `CPoint`.

Em ambos os casos, a adição é feita adicionando o `x` (ou `cx`) membro do operando direito para o `x` membro do `CPoint` e adicionando o `y` (ou `cy`) membro do operando direito para o `y` membro o `CPoint`.

Por exemplo, adicionando `CPoint(5, -7)` a uma variável que contém `CPoint(30, 40)` altera a variável para `CPoint(35, 33)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#31](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_4.cpp)]

##  <a name="operator_-_eq"></a>  CPoint::operator =

A primeira sobrecarga subtrai um tamanho do `CPoint`.

```
void operator-=(SIZE size) throw(); 
void operator-=(POINT point) throw();
```

### <a name="parameters"></a>Parâmetros

*size*  
Contém uma [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.

*ponto*  
Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.

### <a name="remarks"></a>Comentários

A segunda sobrecarga subtrai um ponto do `CPoint`.

Em ambos os casos, a subtração é feita subtraindo-se a `x` (ou `cx`) membro do operando direito da `x` membro do `CPoint` e subtraindo o `y` (ou `cy`) membro de à direita operando do `y` membro o `CPoint`.

Por exemplo, subtrair `CPoint(5, -7)` de uma variável que contém `CPoint(30, 40)` altera a variável para `CPoint(25, 47)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#32](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_5.cpp)]

##  <a name="operator_add"></a>  CPoint::operator +

Use este operador para deslocar `CPoint` por um `CPoint` ou `CSize` objeto, ou para deslocar um `CRect` por uma `CPoint`.

```
CPoint operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw();
```

### <a name="parameters"></a>Parâmetros

*size*  
Contém uma [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.

*ponto*  
Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.

*lpRect*  
Contém um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Um `CPoint` que é deslocado em um tamanho, uma `CPoint` que é deslocado por um ponto ou um `CRect` por um ponto de deslocamento.

### <a name="remarks"></a>Comentários

Por exemplo, usando uma das duas primeiras sobrecargas deslocamento `CPoint(25, -19)` por um ponto `CPoint(15, 5)` ou o tamanho `CSize(15, 5)` retorna o valor `CPoint(40, -14)`.

Adicionar um retângulo para um ponto retorna o retângulo após ser deslocado na `x` e `y` valores especificados no ponto. Por exemplo, usando a última sobrecarga para deslocar um retângulo `CRect(125, 219, 325, 419)` por um ponto `CPoint(25, -19)` retorna `CRect(150, 200, 350, 400)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#33](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_6.cpp)]

##  <a name="operator_-"></a>  CPoint::operator-

Use uma das duas primeiras sobrecargas para subtrair um `CPoint` ou `CSize` do objeto de `CPoint`.

```
CSize operator-(POINT point) const throw();
CPoint operator-(SIZE size) const throw();
CRect operator-(const RECT* lpRect) const throw();
CPoint operator-() const throw();
```

### <a name="parameters"></a>Parâmetros

*ponto*  
Um [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.

*size*  
Um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.

*lpRect*  
Um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Um `CSize` que é a diferença entre dois pontos, um `CPoint` que é deslocado pela negação de tamanho, um `CRect` que é deslocado pela negação de um ponto de ou um `CPoint` que é a negação de um ponto.

### <a name="remarks"></a>Comentários

A terceira sobrecarga deslocamentos de um `CRect` pela negação do `CPoint`. Por fim, use o operador unário para negar `CPoint`.

Por exemplo, usando a primeira sobrecarga para localizar a diferença entre dois pontos `CPoint(25, -19)` e `CPoint(15, 5)` retorna `CSize(10, -24)`.

Subtração de um `CSize` de `CPoint` faz o mesmo cálculo acima, mas retorna um `CPoint` objeto, não um `CSize` objeto. Por exemplo, usando a segunda sobrecarga para localizar a diferença entre o ponto `CPoint(25, -19)` e o tamanho `CSize(15, 5)` retorna `CPoint(10, -24)`.

Subtração de um retângulo de um ponto de retorna o deslocamento de retângulo pelos negativos do `x` e `y` valores especificados no ponto. Por exemplo, usando a última sobrecarga para deslocar o retângulo `CRect(125, 200, 325, 400)` pelo ponto `CPoint(25, -19)` retorna `CRect(100, 219, 300, 419)`.

Use o operador unário para negar a um ponto. Por exemplo, usando o operador unário com o ponto `CPoint(25, -19)` retorna `CPoint(-25, 19)`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#34](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDI](../../visual-cpp-samples.md)   
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
[Estrutura POINT](../../mfc/reference/point-structure1.md)   
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)   
[Classe CSize](../../atl-mfc-shared/reference/csize-class.md)

