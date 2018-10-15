---
title: Classe CSize | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSize
- ATLTYPES/ATL::CSize
- ATLTYPES/ATL::CSize::CSize
dev_langs:
- C++
helpviewer_keywords:
- SIZE
- dimensions, MFC
- dimensions
- CSize class
ms.assetid: fb2cf85a-0bc1-46f8-892b-309c108b52ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ca548fec9a70a04b0bdb9a5169021fc43f149eb
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328528"
---
# <a name="csize-class"></a>Classe CSize

Semelhante do Windows [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura, que implementa uma coordenada ou posição relativa.

## <a name="syntax"></a>Sintaxe

```
class CSize : public tagSIZE 
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSize::CSize](#csize)|Constrói um objeto `CSize`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSize::operator-](#operator_-)|Subtrai dois tamanhos.|
|[CSize::operator! =](#operator_neq)|Verifica a desigualdade entre `CSize` e um tamanho.|
|[CSize::operator +](#operator_add)|Adiciona dois tamanhos.|
|[+ CSize::operator =](#operator_add_eq)|Adiciona um tamanho para `CSize`.|
|[CSize::operator =](#operator_-_eq)|Subtrai um tamanho de `CSize`.|
|[CSize::operator = =](#operator_eq_eq)|Verifica a igualdade entre `CSize` e um tamanho.|

## <a name="remarks"></a>Comentários

Essa classe é derivada de `SIZE` estrutura. Isso significa que você pode passar uma `CSize` em um parâmetro que chama uma `SIZE` e que os membros de dados de `SIZE` estrutura são membros de dados acessíveis de `CSize`.

O `cx` e `cy` membros `SIZE` (e `CSize`) são públicos. Além disso, `CSize` implementa as funções de membro para manipular o `SIZE` estrutura.

> [!NOTE]
>  Para obter mais informações sobre classes de utilitário de compartilhados (como `CSize`), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagSIZE`

`CSize`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltypes. h

##  <a name="csize"></a>  CSize::CSize

Constrói um objeto `CSize`.

```
CSize() throw();
CSize( int initCX, int initCY) throw();
CSize( SIZE initSize) throw();
CSize( POINT initPt) throw();
CSize( DWORD dwSize) throw(); 
```

### <a name="parameters"></a>Parâmetros

*initCX*  
Define o `cx` membro para o `CSize`.

*initCY*  
Define o `cy` membro para o `CSize`.

*initSize*  
[TAMANHO](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou `CSize` objeto usado para inicializar `CSize`.

*initPt*  
[PONTO](../../mfc/reference/point-structure.md) estrutura ou `CPoint` objeto usado para inicializar `CSize`.

*dwSize*  
DWORD é usado para inicializar `CSize`. A palavra de ordem inferior é o `cx` membro e a palavra de ordem superior é o `cy` membro.

### <a name="remarks"></a>Comentários

Se nenhum argumento for fornecido, `cx` e `cy` são inicializados em zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#97](../../atl-mfc-shared/codesnippet/cpp/csize-class_1.cpp)]

##  <a name="operator_eq_eq"></a>  CSize::operator = =

Verificações de igualdade entre dois tamanhos.

``` 
BOOL operator==(SIZE size) const throw(); 
```

### <a name="remarks"></a>Comentários

Retorna diferente de zero se os tamanhos forem iguais, otherwize 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#98](../../atl-mfc-shared/codesnippet/cpp/csize-class_2.cpp)]

##  <a name="operator_neq"></a>  CSize::operator! =

Verifica a desigualdade entre dois tamanhos.

``` 
BOOL operator!=(SIZE size) const throw(); 
```

### <a name="remarks"></a>Comentários

Retorna não zero se os tamanhos não forem iguais, caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#99](../../atl-mfc-shared/codesnippet/cpp/csize-class_3.cpp)]

##  <a name="operator_add_eq"></a>  + CSize::operator =

Adiciona um tamanho a este `CSize`.

``` 
void operator+=(SIZE size) throw(); 
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#100](../../atl-mfc-shared/codesnippet/cpp/csize-class_4.cpp)]

##  <a name="operator_-_eq"></a>  CSize::operator =

Subtrai um tamanho deste `CSize`.

``` 
void operator-=(SIZE size) throw(); 
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#101](../../atl-mfc-shared/codesnippet/cpp/csize-class_5.cpp)]

##  <a name="operator_add"></a>  CSize::operator +

Esses operadores adicionar isso `CSize` valor para o valor do parâmetro.

``` 
CSize operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw(); 
```

### <a name="remarks"></a>Comentários

Consulte as descrições dos operadores individuais a seguir:

- **operador + (** `size` **)** essa operação adiciona duas `CSize` valores.

- **operador + (** `point` **)** essa operação deslocamentos (se move) um [ponto](https://msdn.microsoft.com/library/windows/desktop/dd162805) (ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md)) valor por este `CSize` valor. O **cx** e **cy** membros deste `CSize` valor são adicionados à **x** e **y** membros de dados a **ponto**  valor. Ele é análogo à versão do [CPoint::operator +](../../atl-mfc-shared/reference/cpoint-class.md#operator_add) que usa um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.

- **operador + (** `lpRect` **)** essa operação deslocamentos (se move) um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) (ou [CRect](../../atl-mfc-shared/reference/crect-class.md)) valor por este `CSize` valor. O **cx** e **cy** membros deste `CSize` valor são adicionados para o **esquerdo**, **superior**, **direita**, e **inferior** membros de dados a `RECT` valor. Ele é análogo à versão do [CRect::operator +](../../atl-mfc-shared/reference/crect-class.md#operator_add) que usa um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#102](../../atl-mfc-shared/codesnippet/cpp/csize-class_6.cpp)]

##  <a name="operator_-"></a>  CSize::operator-

As três primeiras desses operadores subtrair isso `CSize` valor para o valor do parâmetro.

``` 
CSize operator-(SIZE size) const throw();
CPoint operator-(POINT point) const throw();
CRect operator-(const RECT* lpRect) const throw();
CSize operator-() const throw(); 
```

### <a name="remarks"></a>Comentários

O quarto operador, o operador unário menos, altera o sinal do `CSize` valor. Consulte as descrições dos operadores individuais a seguir:

- **operador-(** `size` **)** essa operação subtrai dois `CSize` valores.

- **operador-(** `point` **)** essa operação deslocamentos (se move) um [ponto](https://msdn.microsoft.com/library/windows/desktop/dd162805) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) valor segundo o inverso de aditivo isso `CSize` valor. O **cx** e **cy** isso `CSize` valor são subtraídos do **x** e **y** membros de dados a **ponto**  valor. Ele é análogo à versão do [CPoint::operator -](../../atl-mfc-shared/reference/cpoint-class.md#operator_-) que usa um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.

- **operador-(** `lpRect` **)** essa operação deslocamentos (se move) um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) valor segundo o inverso de aditivo isso `CSize` valor. O **cx** e **cy** membros deste `CSize` valor são subtraídos do **esquerdo**, **superior**, **direita**, e **inferior** membros de dados a `RECT` valor. Ele é análogo à versão do [CRect::operator -](../../atl-mfc-shared/reference/crect-class.md#operator_-) que usa um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.

- **operador-()** essa operação retorna o inverso de aditivo isso `CSize` valor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#103](../../atl-mfc-shared/codesnippet/cpp/csize-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDI](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)<br/>
[Classe CPoint](../../atl-mfc-shared/reference/cpoint-class.md)

