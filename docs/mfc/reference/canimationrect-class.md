---
title: Classe CAnimationRect | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3959ae03d40bac93ca6453c254e894b8782f5333
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36957192"
---
# <a name="canimationrect-class"></a>Classe CAnimationRect
Implementa a funcionalidade de um retângulo cujos lados podem ser animados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationRect : public CAnimationBaseObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationRect::CAnimationRect](#canimationrect)|Sobrecarregado. Constrói um objeto rect de animação.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationRect::AddTransition](#addtransition)|Adiciona as transições de coordenadas esquerda, superior, direita e inferior.|  
|[CAnimationRect::GetBottom](#getbottom)|Fornece acesso a CAnimationVariable que representa a coordenada inferior.|  
|[CAnimationRect::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para os limites do retângulo.|  
|[CAnimationRect::GetLeft](#getleft)|Fornece acesso a CAnimationVariable que representa a coordenada esquerda.|  
|[CAnimationRect::GetRight](#getright)|Fornece acesso a CAnimationVariable que representa a coordenada direita.|  
|[CAnimationRect::GetTop](#gettop)|Fornece acesso a CAnimationVariable que representa a coordenada superior.|  
|[CAnimationRect::GetValue](#getvalue)|Retorna o valor atual.|  
|[CAnimationRect::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationRect::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulada em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationRect::operator RECT](#operator_rect)|Converte um CAnimationRect Rect.|  
|[CAnimationRect::operator =](#operator_eq)|Atribui o retângulo para CAnimationRect.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationRect::m_bFixedSize](#m_bfixedsize)|Especifica se o retângulo tem tamanho fixo.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationRect::m_bottomValue](#m_bottomvalue)|Associado a variável de animação encapsulada que representa a parte inferior do retângulo de animação.|  
|[CAnimationRect::m_leftValue](#m_leftvalue)|A variável de animação encapsulada que representa esquerda limite do retângulo de animação.|  
|[CAnimationRect::m_rightValue](#m_rightvalue)|A variável de animação encapsulada que representa o direito de limite do retângulo de animação.|  
|[CAnimationRect::m_szInitial](#m_szinitial)|Especifica o tamanho inicial do retângulo de animação.|  
|[CAnimationRect::m_topValue](#m_topvalue)|Associado a variável de animação encapsulada que representa a parte superior do retângulo de animação.|  
  
## <a name="remarks"></a>Comentários  
 A classe CAnimationRect encapsula quatro objetos CAnimationVariable e pode representar em aplicativos de um retângulo. Para usar essa classe no aplicativo, basta instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado à esquerda, à direita coordenadas superior e inferior.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 `CAnimationRect`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtransition"></a>  CAnimationRect::AddTransition  
 Adiciona as transições de coordenadas esquerda, superior, direita e inferior.  
  
```  
void AddTransition(
    CBaseTransition* pLeftTransition,  
    CBaseTransition* pTopTransition,  
    CBaseTransition* pRightTransition,  
    CBaseTransition* pBottomTransition);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pLeftTransition*  
 Especifica a transição para o lado esquerdo.  
  
 *pTopTransition*  
 Especifica a transição para o lado superior.  
  
 *pRightTransition*  
 Especifica a transição para o lado direito.  
  
 *pBottomTransition*  
 Especifica a transição para o lado inferior.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para adicionar as transições especificadas para a lista interna de transições para ser aplicados a variáveis de animação para cada lados do retângulo. Quando você adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. Transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição para um dos lados do retângulo, é possível passar NULL.  
  
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
 *Rect*  
 Especifica o retângulo padrão.  
  
 *nGroupID*  
 Especifica a ID do grupo.  
  
 *nObjectID*  
 Especifica a ID de objeto.  
  
 *dwUserData*  
 Especifica os dados definidos pelo usuário.  
  
 *pt*  
 Coordenadas do canto superior esquerdo.  
  
 *SZ*  
 Tamanho do retângulo.  
  
 *nLeft*  
 Especifica a coordenada de limite esquerdo.  
  
 *nTop*  
 Especifica a coordenada da parte superior associado.  
  
 *nRight*  
 Especifica a coordenada de limite direito.  
  
 *nBottom*  
 Especifica a coordenada da parte inferior associado.  
  
### <a name="remarks"></a>Comentários  
 O objeto for construído com valores padrão para a esquerda, superior, direita e inferior, ID de objeto e identificação de grupo, que será definido como 0. Eles podem ser alterados posteriormente em tempo de execução usando SetDefaultValue e SetID.  
  
##  <a name="getanimationvariablelist"></a>  CAnimationRect::GetAnimationVariableList  
 Coloca as variáveis de animação encapsulada em uma lista.  
  
```  
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*, 
    CAnimationVariable*>& lst);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lst*  
 Quando a função retornar, contém ponteiros para quatro objetos CAnimationVariable representar coordenadas de retângulo.  
  
##  <a name="getbottom"></a>  CAnimationRect::GetBottom  
 Fornece acesso a CAnimationVariable que representa a coordenada inferior.  
  
```  
CAnimationVariable& GetBottom();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa a coordenada inferior.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada inferior.  
  
##  <a name="getdefaultvalue"></a>  CAnimationRect::GetDefaultValue  
 Retorna os valores padrão para os limites do retângulo.  
  
```  
CRect GetDefaultValue();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de CRect que contém os padrões para a esquerda, direita, superior e inferior.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor padrão, que foi anteriormente definido pelo construtor ou SetDefaultValue.  
  
##  <a name="getleft"></a>  CAnimationRect::GetLeft  
 Fornece acesso a CAnimationVariable que representa a coordenada esquerda.  
  
```  
CAnimationVariable& GetLeft();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa a coordenada esquerda.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada esquerda.  
  
##  <a name="getright"></a>  CAnimationRect::GetRight  
 Fornece acesso a CAnimationVariable que representa a coordenada direita.  
  
```  
CAnimationVariable& GetRight();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa a coordenada direita.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada direita.  
  
##  <a name="gettop"></a>  CAnimationRect::GetTop  
 Fornece acesso a CAnimationVariable que representa a coordenada superior.  
  
```  
CAnimationVariable& GetTop();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa a coordenada superior.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada superior.  
  
##  <a name="getvalue"></a>  CAnimationRect::GetValue  
 Retorna o valor atual.  
  
```  
BOOL GetValue(CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 Saída. Quando este método retorna, contém o valor atual.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o valor atual foi recuperado com êxito. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor atual do retângulo de animação. Se esse método falhar ou subjacente COM objetos para a esquerda, superior, direita e inferior não foram inicializados, rect contém o valor padrão, que foi definida anteriormente no construtor ou por SetDefaultValue.  
  
##  <a name="m_bfixedsize"></a>  CAnimationRect::m_bFixedSize  
 Especifica se o retângulo tem tamanho fixo.  
  
```  
BOOL m_bFixedSize;  
```  
  
### <a name="remarks"></a>Comentários  
 Se esse membro for true, o tamanho do retângulo é fixo e à direita, e valores inferiores são recalculados sempre que o canto superior esquerdo é movido de acordo com o tamanho fixo. Defina esse valor como TRUE para mover facilmente o retângulo ao redor da tela. Nesse caso, transições aplicadas em coordenadas da direita e inferior são ignoradas. O tamanho é armazenado internamente quando você construir o objeto e/ou chame SetDefaultValue. Por padrão, esse membro é definido como FALSE.  
  
##  <a name="m_bottomvalue"></a>  CAnimationRect::m_bottomValue  
 Associado a variável de animação encapsulada que representa a parte inferior do retângulo de animação.  
  
```  
CAnimationVariable m_bottomValue;  
```  
  
##  <a name="m_leftvalue"></a>  CAnimationRect::m_leftValue  
 A variável de animação encapsulada que representa esquerda limite do retângulo de animação.  
  
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
 Esta função chama internamente GetValue. Se falhar GetValue por algum motivo, o retângulo retornado conterá valores padrão para todas as coordenadas do retângulo.  
  
##  <a name="operator_eq"></a>  CAnimationRect::operator =  
 Atribui o retângulo para CAnimationRect.  
  
```  
void operator=(const RECT& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 O novo valor do retângulo de animação.  
  
### <a name="remarks"></a>Comentários  
 É recomendável fazer isso antes do início da animação, porque esse operador chama SetDefaultValue, que recria os objetos COM base para componentes de cor se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
##  <a name="setdefaultvalue"></a>  CAnimationRect::SetDefaultValue  
 Define o valor padrão.  
  
```  
void SetDefaultValue(const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 Especifica os novos valores padrão para a esquerda, superior, direita e inferior.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para definir um valor padrão para o objeto de animação. Esse método atribui valores padrão para os limites do retângulo. Ele também recria os objetos subjacentes se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
