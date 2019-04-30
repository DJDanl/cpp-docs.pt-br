---
title: Classe CAnimationRect
ms.date: 11/04/2016
f1_keywords:
- CAnimationRect
- AFXANIMATIONCONTROLLER/CAnimationRect
- AFXANIMATIONCONTROLLER/CAnimationRect::CAnimationRect
- AFXANIMATIONCONTROLLER/CAnimationRect::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationRect::GetBottom
- AFXANIMATIONCONTROLLER/CAnimationRect::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationRect::GetLeft
- AFXANIMATIONCONTROLLER/CAnimationRect::GetRight
- AFXANIMATIONCONTROLLER/CAnimationRect::GetTop
- AFXANIMATIONCONTROLLER/CAnimationRect::GetValue
- AFXANIMATIONCONTROLLER/CAnimationRect::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationRect::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationRect::m_bFixedSize
- AFXANIMATIONCONTROLLER/CAnimationRect::m_bottomValue
- AFXANIMATIONCONTROLLER/CAnimationRect::m_leftValue
- AFXANIMATIONCONTROLLER/CAnimationRect::m_rightValue
- AFXANIMATIONCONTROLLER/CAnimationRect::m_szInitial
- AFXANIMATIONCONTROLLER/CAnimationRect::m_topValue
helpviewer_keywords:
- CAnimationRect [MFC], CAnimationRect
- CAnimationRect [MFC], AddTransition
- CAnimationRect [MFC], GetBottom
- CAnimationRect [MFC], GetDefaultValue
- CAnimationRect [MFC], GetLeft
- CAnimationRect [MFC], GetRight
- CAnimationRect [MFC], GetTop
- CAnimationRect [MFC], GetValue
- CAnimationRect [MFC], SetDefaultValue
- CAnimationRect [MFC], GetAnimationVariableList
- CAnimationRect [MFC], m_bFixedSize
- CAnimationRect [MFC], m_bottomValue
- CAnimationRect [MFC], m_leftValue
- CAnimationRect [MFC], m_rightValue
- CAnimationRect [MFC], m_szInitial
- CAnimationRect [MFC], m_topValue
ms.assetid: 0294156d-241e-4a57-92b2-31234fe557d6
ms.openlocfilehash: 84c4cf92894a9ece2021417445c9d7ab94ee6bdf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62378160"
---
# <a name="canimationrect-class"></a>Classe CAnimationRect

Implementa a funcionalidade de um retângulo cujos lados podem ser animados.

## <a name="syntax"></a>Sintaxe

```
class CAnimationRect : public CAnimationBaseObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::CAnimationRect](#canimationrect)|Sobrecarregado. Constrói um objeto rect de animação.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::AddTransition](#addtransition)|Adiciona as transições para coordenadas esquerda, superior, direita e inferior.|
|[CAnimationRect::GetBottom](#getbottom)|Fornece acesso ao CAnimationVariable que representa a coordenada inferior.|
|[CAnimationRect::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para os limites do retângulo.|
|[CAnimationRect::GetLeft](#getleft)|Fornece acesso ao CAnimationVariable que representa a coordenada esquerda.|
|[CAnimationRect::GetRight](#getright)|Fornece acesso ao CAnimationVariable que representa a coordenada direita.|
|[CAnimationRect::GetTop](#gettop)|Fornece acesso ao CAnimationVariable que representa a coordenada superior.|
|[CAnimationRect::GetValue](#getvalue)|Retorna o valor atual.|
|[CAnimationRect::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulado em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::operator RECT](#operator_rect)|Converte um CAnimationRect Rect.|
|[CAnimationRect::operator=](#operator_eq)|Atribui rect a CAnimationRect.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::m_bFixedSize](#m_bfixedsize)|Especifica se o retângulo tem tamanho fixo.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::m_bottomValue](#m_bottomvalue)|Associado a variável de animação encapsulada que representa a parte inferior do retângulo de animação.|
|[CAnimationRect::m_leftValue](#m_leftvalue)|A variável de animação encapsulado representando esquerda limite do retângulo de animação.|
|[CAnimationRect::m_rightValue](#m_rightvalue)|A variável de animação encapsulada que representa o direito de limite do retângulo de animação.|
|[CAnimationRect::m_szInitial](#m_szinitial)|Especifica o tamanho inicial do retângulo de animação.|
|[CAnimationRect::m_topValue](#m_topvalue)|Associado a variável de animação encapsulada que representa a parte superior do retângulo de animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationRect encapsula quatro objetos CAnimationVariable e pode representar em aplicativos de um retângulo. Para usar essa classe no aplicativo, basta instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado à esquerda, direita coordenadas superior e inferior.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationRect`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="addtransition"></a>  CAnimationRect::AddTransition

Adiciona as transições para coordenadas esquerda, superior, direita e inferior.

```
void AddTransition(
    CBaseTransition* pLeftTransition,
    CBaseTransition* pTopTransition,
    CBaseTransition* pRightTransition,
    CBaseTransition* pBottomTransition);
```

### <a name="parameters"></a>Parâmetros

*pLeftTransition*<br/>
Especifica a transição para o lado esquerdo.

*pTopTransition*<br/>
Especifica a transição para o lado superior.

*pRightTransition*<br/>
Especifica a transição para o lado direito.

*pBottomTransition*<br/>
Especifica a transição para o lado inferior.

### <a name="remarks"></a>Comentários

Chame essa função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação para cada lados do retângulo. Ao adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. As transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição para um dos lados do retângulo, é possível passar NULL.

##  <a name="canimationrect"></a>  CAnimationRect::CAnimationRect

Constrói um objeto CAnimationRect.

```
CAnimationRect();

CAnimationRect(
    const CRect& rect,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);

CAnimationRect(
    const CPoint& pt,
    const CSize& sz,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);

CAnimationRect(
    int nLeft,
    int nTop,
    int nRight,
    int nBottom,
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Especifica o retângulo de padrão.

*nGroupID*<br/>
Especifica a ID do grupo.

*nObjectID*<br/>
Especifica a ID de objeto.

*dwUserData*<br/>
Especifica os dados definidos pelo usuário.

*pt*<br/>
Coordenadas do canto superior esquerdo.

*sz*<br/>
Tamanho do retângulo.

*nLeft*<br/>
Especifica a coordenada de limite esquerdo.

*nTop*<br/>
Especifica a coordenada da parte superior associado.

*nRight*<br/>
Especifica a coordenada de limite direito.

*nBottom*<br/>
Especifica a coordenada da parte inferior associado.

### <a name="remarks"></a>Comentários

O objeto é construído com os valores padrão para a esquerda, superior, direita e inferior, ID de objeto e a ID de grupo, que será definido como 0. Eles podem ser alterados posteriormente em tempo de execução usando SetDefaultValue e SetID.

##  <a name="getanimationvariablelist"></a>  CAnimationRect::GetAnimationVariableList

Coloca as variáveis de animação encapsulado em uma lista.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*lst*<br/>
Quando a função retorna, ele contém ponteiros para os quatro objetos CAnimationVariable que representa as coordenadas do retângulo.

##  <a name="getbottom"></a>  CAnimationRect::GetBottom

Fornece acesso ao CAnimationVariable que representa a coordenada inferior.

```
CAnimationVariable& GetBottom();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a coordenada inferior.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada inferior.

##  <a name="getdefaultvalue"></a>  CAnimationRect::GetDefaultValue

Retorna os valores padrão para os limites do retângulo.

```
CRect GetDefaultValue();
```

### <a name="return-value"></a>Valor de retorno

Um valor de CRect contendo os padrões para a esquerda, direita, superior e inferior.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi anteriormente definido pelo construtor ou SetDefaultValue.

##  <a name="getleft"></a>  CAnimationRect::GetLeft

Fornece acesso ao CAnimationVariable que representa a coordenada esquerda.

```
CAnimationVariable& GetLeft();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a coordenada esquerda.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada esquerda.

##  <a name="getright"></a>  CAnimationRect::GetRight

Fornece acesso ao CAnimationVariable que representa a coordenada direita.

```
CAnimationVariable& GetRight();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a coordenada direita.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada direita.

##  <a name="gettop"></a>  CAnimationRect::GetTop

Fornece acesso ao CAnimationVariable que representa a coordenada superior.

```
CAnimationVariable& GetTop();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao CAnimationVariable encapsulado, que representa a coordenada superior.

### <a name="remarks"></a>Comentários

Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada superior.

##  <a name="getvalue"></a>  CAnimationRect::GetValue

Retorna o valor atual.

```
BOOL GetValue(CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Saída. Quando este método retorna, contém o valor atual.

### <a name="return-value"></a>Valor de retorno

TRUE se o valor atual foi recuperado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor atual do retângulo de animação. Se esse método falhar ou subjacente COM objetos para a esquerda, superior, direita e inferior não foram inicializados, rect contém o valor padrão, que foi anteriormente definido no construtor ou por SetDefaultValue.

##  <a name="m_bfixedsize"></a>  CAnimationRect::m_bFixedSize

Especifica se o retângulo tem tamanho fixo.

```
BOOL m_bFixedSize;
```

### <a name="remarks"></a>Comentários

Se esse membro for true, em seguida, o tamanho do retângulo é fixo e à direita e valores inferiores serão recalculados sempre que o canto superior esquerdo é movido de acordo com o tamanho fixo. Defina esse valor como TRUE para mover facilmente o retângulo pela tela. Nesse caso, as transições aplicadas às coordenadas da direita e inferior são ignoradas. O tamanho é armazenado internamente quando você construir o objeto e/ou chame SetDefaultValue. Por padrão, esse membro é definido como FALSE.

##  <a name="m_bottomvalue"></a>  CAnimationRect::m_bottomValue

Associado a variável de animação encapsulada que representa a parte inferior do retângulo de animação.

```
CAnimationVariable m_bottomValue;
```

##  <a name="m_leftvalue"></a>  CAnimationRect::m_leftValue

A variável de animação encapsulado representando esquerda limite do retângulo de animação.

```
CAnimationVariable m_leftValue;
```

##  <a name="m_rightvalue"></a>  CAnimationRect::m_rightValue

A variável de animação encapsulada que representa o direito de limite do retângulo de animação.

```
CAnimationVariable m_rightValue;
```

##  <a name="m_szinitial"></a>  CAnimationRect::m_szInitial

Especifica o tamanho inicial do retângulo de animação.

```
CSize m_szInitial;
```

##  <a name="m_topvalue"></a>  CAnimationRect::m_topValue

Associado a variável de animação encapsulada que representa a parte superior do retângulo de animação.

```
CAnimationVariable m_topValue;
```

##  <a name="operator_rect"></a>  CAnimationRect::operator RECT

Converte um CAnimationRect Rect.

```
operator RECT();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do retângulo de animação como Rect.

### <a name="remarks"></a>Comentários

Essa função chama internamente GetValue. Se falhar GetValue por algum motivo, o retângulo retornado conterá valores padrão para todas as coordenadas do retângulo.

##  <a name="operator_eq"></a>  CAnimationRect::operator=

Atribui rect a CAnimationRect.

```
void operator=(const RECT& rect);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
O novo valor do retângulo de animação.

### <a name="remarks"></a>Comentários

É recomendável fazer isso antes do início da animação, pois este operador chama SetDefaultValue, que recria os objetos subjacentes de COM para componentes de cor se eles tiverem sido criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

##  <a name="setdefaultvalue"></a>  CAnimationRect::SetDefaultValue

Define o valor padrão.

```
void SetDefaultValue(const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Especifica novos valores padrão para a esquerda, superior, direita e inferior.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para o objeto de animação. Esse método atribui valores padrão para os limites do retângulo. Ele também recria os objetos subjacentes se eles tiverem sido criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
