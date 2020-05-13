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
ms.openlocfilehash: 273ea2b548d35722ebf937d2db2b589fef5e69fa
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81755130"
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
|[CAnimationRect::CAnimationRect](#canimationrect)|Sobrecarregado. Constrói um objeto de rect de animação.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::AddTransition](#addtransition)|Adiciona transições para as coordenadas esquerda, superior, direita e inferior.|
|[CAnimationRect::GetBottom](#getbottom)|Fornece acesso ao CAnimationVariable representando a coordenada inferior.|
|[CAnimationRect:GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para os limites do retângulo.|
|[CAnimationRect::GetLeft](#getleft)|Fornece acesso ao CAnimationVariable representando a coordenada esquerda.|
|[CAnimationRect::GetRight](#getright)|Fornece acesso ao CAnimationVariable representando a coordenada direita.|
|[CAnimationRect::GetTop](#gettop)|Fornece acesso ao CAnimationVariable representando a coordenação superior.|
|[CAnimationRect::GetValue](#getvalue)|Retorna o valor atual.|
|[CAnimationRect:SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect:GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsuladas em uma lista. (Substitui [cAnimationBaseObject:GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::operador RECT](#operator_rect)|Converte um CAnimationRect em RECT.|
|[CAnimationRect::operador=](#operator_eq)|Atribui-se rect a CAnimationRect.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::m_bFixedSize](#m_bfixedsize)|Especifica se o retângulo tem tamanho fixo.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationRect::m_bottomValue](#m_bottomvalue)|A variável de animação encapsulada que representa o limite inferior do retângulo de animação.|
|[CAnimationRect::m_leftValue](#m_leftvalue)|A variável de animação encapsulada que representa o limite esquerdo do retângulo de animação.|
|[CAnimationRect::m_rightValue](#m_rightvalue)|A variável de animação encapsulada que representa o limite direito do retângulo de animação.|
|[CAnimationRect::m_szInitial](#m_szinitial)|Especifica o tamanho inicial do retângulo de animação.|
|[CAnimationRect::m_topValue](#m_topvalue)|A variável de animação encapsulada que representa o limite superior do retângulo de animação.|

## <a name="remarks"></a>Comentários

A classe CAnimationRect encapsula quatro objetos CAnimationVariable e pode representar em aplicações um retângulo. Para usar esta classe no aplicativo, basta instanciar um objeto desta classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicada às coordenadas esquerda, direita superior e inferior.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)

`CAnimationRect`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationrectaddtransition"></a><a name="addtransition"></a>CAnimationRect::AddTransition

Adiciona transições para as coordenadas esquerda, superior, direita e inferior.

```cpp
void AddTransition(
    CBaseTransition* pLeftTransition,
    CBaseTransition* pTopTransition,
    CBaseTransition* pRightTransition,
    CBaseTransition* pBottomTransition);
```

### <a name="parameters"></a>Parâmetros

*pLeftTransition*<br/>
Especifica transição para o lado esquerdo.

*pTopTransition*<br/>
Especifica transição para o lado superior.

*pRightTransition*<br/>
Especifica transição para o lado direito.

*pBottomTransition*<br/>
Especifica transição para o lado inferior.

### <a name="remarks"></a>Comentários

Chame esta função para adicionar as transições especificadas à lista interna de transições a serem aplicadas às variáveis de animação para cada lado retângulo. Quando você adiciona transições, elas não são aplicadas imediatamente e armazenadas em uma lista interna. Transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisar aplicar uma transição para um dos lados do retângulo, você pode passar NULL.

## <a name="canimationrectcanimationrect"></a><a name="canimationrect"></a>CAnimationRect::CAnimationRect

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

*Rect*<br/>
Especifica o retângulo padrão.

*nGroupID*<br/>
Especifica o ID do grupo.

*nObjectID*<br/>
Especifica o ID do objeto.

*dwUserData*<br/>
Especifica dados definidos pelo usuário.

*pt*<br/>
Coordenada do canto superior esquerdo.

*Sz*<br/>
Tamanho do retângulo.

*nEsquerda*<br/>
Especifica a coordenada do limite esquerdo.

*Ntop*<br/>
Especifica a coordenada do limite superior.

*nDireito*<br/>
Especifica a coordenada do limite direito.

*nBottom*<br/>
Especifica a coordenada do limite inferior.

### <a name="remarks"></a>Comentários

O objeto é construído com valores padrão para esquerda, superior, direita e inferior, ID do objeto e ID do grupo, que será definido como 0. Eles podem ser alterados mais tarde em tempo de execução usando SetDefaultValue e SetID.

## <a name="canimationrectgetanimationvariablelist"></a><a name="getanimationvariablelist"></a>CAnimationRect:GetAnimationVariableList

Coloca as variáveis de animação encapsuladas em uma lista.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& lst);
```

### <a name="parameters"></a>Parâmetros

*Lst*<br/>
Quando a função retorna, ela contém ponteiros para quatro objetos CAnimationVariable representando coordenadas do retângulo.

## <a name="canimationrectgetbottom"></a><a name="getbottom"></a>CAnimationRect::GetBottom

Fornece acesso ao CAnimationVariable representando a coordenada inferior.

```
CAnimationVariable& GetBottom();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando a coordenada inferior.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando a coordenada inferior.

## <a name="canimationrectgetdefaultvalue"></a><a name="getdefaultvalue"></a>CAnimationRect:GetDefaultValue

Retorna os valores padrão para os limites do retângulo.

```
CRect GetDefaultValue();
```

### <a name="return-value"></a>Valor retornado

Um valor CRect contendo padrões para esquerda, direita, parte superior e inferior.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar o valor padrão, que foi definido anteriormente pelo construtor ou setDefaultValue.

## <a name="canimationrectgetleft"></a><a name="getleft"></a>CAnimationRect::GetLeft

Fornece acesso ao CAnimationVariable representando a coordenada esquerda.

```
CAnimationVariable& GetLeft();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando a coordenada esquerda.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando a coordenada esquerda.

## <a name="canimationrectgetright"></a><a name="getright"></a>CAnimationRect::GetRight

Fornece acesso ao CAnimationVariable representando a coordenada direita.

```
CAnimationVariable& GetRight();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando a coordenada direita.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando a coordenada certa.

## <a name="canimationrectgettop"></a><a name="gettop"></a>CAnimationRect::GetTop

Fornece acesso ao CAnimationVariable representando a coordenação superior.

```
CAnimationVariable& GetTop();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao CAnimationVariable encapsulado representando a coordenação superior.

### <a name="remarks"></a>Comentários

Você pode chamar este método para obter acesso direto ao CAnimationVariable subjacente representando a coordenada superior.

## <a name="canimationrectgetvalue"></a><a name="getvalue"></a>CAnimationRect::GetValue

Retorna o valor atual.

```
BOOL GetValue(CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Saída. Contém o valor atual quando este método retorna.

### <a name="return-value"></a>Valor retornado

TRUE, se o valor atual foi recuperado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar o valor atual do retângulo de animação. Se este método falhar ou os objetos COM subjacentes para a esquerda, superior, direita e inferior não tiverem sido inicializados, o rect contém o valor padrão, que foi previamente definido no construtor ou no SetDefaultValue.

## <a name="canimationrectm_bfixedsize"></a><a name="m_bfixedsize"></a>CAnimationRect::m_bFixedSize

Especifica se o retângulo tem tamanho fixo.

```
BOOL m_bFixedSize;
```

### <a name="remarks"></a>Comentários

Se este membro for verdadeiro, então o tamanho do retângulo é fixo e os valores direito e inferior são recalculados cada vez que o canto superior esquerdo é movido de acordo com o tamanho fixo. Defina esse valor como TRUE para mover facilmente o retângulo ao redor da tela. Neste caso, as transições aplicadas às coordenadas direita e inferior são ignoradas. O tamanho é armazenado internamente quando você constrói o objeto e/ou chama SetDefaultValue. Por padrão, este membro é definido como FALSE.

## <a name="canimationrectm_bottomvalue"></a><a name="m_bottomvalue"></a>CAnimationRect::m_bottomValue

A variável de animação encapsulada que representa o limite inferior do retângulo de animação.

```
CAnimationVariable m_bottomValue;
```

## <a name="canimationrectm_leftvalue"></a><a name="m_leftvalue"></a>CAnimationRect::m_leftValue

A variável de animação encapsulada que representa o limite esquerdo do retângulo de animação.

```
CAnimationVariable m_leftValue;
```

## <a name="canimationrectm_rightvalue"></a><a name="m_rightvalue"></a>CAnimationRect::m_rightValue

A variável de animação encapsulada que representa o limite direito do retângulo de animação.

```
CAnimationVariable m_rightValue;
```

## <a name="canimationrectm_szinitial"></a><a name="m_szinitial"></a>CAnimationRect::m_szInitial

Especifica o tamanho inicial do retângulo de animação.

```
CSize m_szInitial;
```

## <a name="canimationrectm_topvalue"></a><a name="m_topvalue"></a>CAnimationRect::m_topValue

A variável de animação encapsulada que representa o limite superior do retângulo de animação.

```
CAnimationVariable m_topValue;
```

## <a name="canimationrectoperator-rect"></a><a name="operator_rect"></a>CAnimationRect::operador RECT

Converte um CAnimationRect em RECT.

```
operator RECT();
```

### <a name="return-value"></a>Valor retornado

Valor atual do retângulo de animação como RECT.

### <a name="remarks"></a>Comentários

Esta função chama internamente GetValue. Se o GetValue por algum motivo falhar, o RECT retornado conterá valores padrão para todas as coordenadas retângulo.

## <a name="canimationrectoperator"></a><a name="operator_eq"></a>CAnimationRect::operador=

Atribui-se rect a CAnimationRect.

```cpp
void operator=(const RECT& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
O novo valor do retângulo de animação.

### <a name="remarks"></a>Comentários

Recomenda-se fazer isso antes do início da animação, porque este operador chama SetDefaultValue, que recria os objetos COM subjacentes para componentes de cor se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="canimationrectsetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationRect:SetDefaultValue

Define o valor padrão.

```cpp
void SetDefaultValue(const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Especifica novos valores padrão para esquerda, superior, direita e inferior.

### <a name="remarks"></a>Comentários

Use esta função para definir um valor padrão para objeto de animação. Esses métodos atribuem valores padrão aos limites do retângulo. Ele também recria objetos COM subjacentes se eles tiverem sido criados. Se você inscreveu esse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisará reativar esses eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
