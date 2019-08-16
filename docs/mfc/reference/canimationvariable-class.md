---
title: Classe CAnimationVariable
ms.date: 03/27/2019
f1_keywords:
- CAnimationVariable
- AFXANIMATIONCONTROLLER/CAnimationVariable
- AFXANIMATIONCONTROLLER/CAnimationVariable::CAnimationVariable
- AFXANIMATIONCONTROLLER/CAnimationVariable::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationVariable::ApplyTransitions
- AFXANIMATIONCONTROLLER/CAnimationVariable::ClearTransitions
- AFXANIMATIONCONTROLLER/CAnimationVariable::Create
- AFXANIMATIONCONTROLLER/CAnimationVariable::CreateTransitions
- AFXANIMATIONCONTROLLER/CAnimationVariable::EnableIntegerValueChangedEvent
- AFXANIMATIONCONTROLLER/CAnimationVariable::EnableValueChangedEvent
- AFXANIMATIONCONTROLLER/CAnimationVariable::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationVariable::GetParentAnimationObject
- AFXANIMATIONCONTROLLER/CAnimationVariable::GetValue
- AFXANIMATIONCONTROLLER/CAnimationVariable::GetVariable
- AFXANIMATIONCONTROLLER/CAnimationVariable::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationVariable::SetParentAnimationObject
- AFXANIMATIONCONTROLLER/CAnimationVariable::m_bAutodestroyTransitions
- AFXANIMATIONCONTROLLER/CAnimationVariable::m_dblDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationVariable::m_lstTransitions
- AFXANIMATIONCONTROLLER/CAnimationVariable::m_pParentObject
- AFXANIMATIONCONTROLLER/CAnimationVariable::m_variable
helpviewer_keywords:
- CAnimationVariable [MFC], CAnimationVariable
- CAnimationVariable [MFC], AddTransition
- CAnimationVariable [MFC], ApplyTransitions
- CAnimationVariable [MFC], ClearTransitions
- CAnimationVariable [MFC], Create
- CAnimationVariable [MFC], CreateTransitions
- CAnimationVariable [MFC], EnableIntegerValueChangedEvent
- CAnimationVariable [MFC], EnableValueChangedEvent
- CAnimationVariable [MFC], GetDefaultValue
- CAnimationVariable [MFC], GetParentAnimationObject
- CAnimationVariable [MFC], GetValue
- CAnimationVariable [MFC], GetVariable
- CAnimationVariable [MFC], SetDefaultValue
- CAnimationVariable [MFC], SetParentAnimationObject
- CAnimationVariable [MFC], m_bAutodestroyTransitions
- CAnimationVariable [MFC], m_dblDefaultValue
- CAnimationVariable [MFC], m_lstTransitions
- CAnimationVariable [MFC], m_pParentObject
- CAnimationVariable [MFC], m_variable
ms.assetid: 506e697e-31a8-4033-a27e-292f4d7b42d9
ms.openlocfilehash: b6767ed42d66aff467ef36bd2a7b5234ad181ced
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507539"
---
# <a name="canimationvariable-class"></a>Classe CAnimationVariable

Representa uma variável de animação.

## <a name="syntax"></a>Sintaxe

```
class CAnimationVariable;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::CAnimationVariable](#canimationvariable)|Constrói um objeto de variável de animação.|
|[CAnimationVariable:: ~ CAnimationVariable](#_dtorcanimationvariable)|O destruidor. Chamado quando um objeto CAnimationVariable está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::AddTransition](#addtransition)|Adiciona uma transição.|
|[CAnimationVariable::ApplyTransitions](#applytransitions)|Adiciona transições da lista interna ao storyboard.|
|[CAnimationVariable::ClearTransitions](#cleartransitions)|Limpa as transições.|
|[CAnimationVariable:: criar](#create)|Cria o objeto COM da variável de animação subjacente.|
|[CAnimationVariable::CreateTransitions](#createtransitions)|Cria todas as transições a serem aplicadas a esta variável de animação.|
|[CAnimationVariable::EnableIntegerValueChangedEvent](#enableintegervaluechangedevent)|Habilita ou desabilita o evento IntegerValueChanged.|
|[CAnimationVariable::EnableValueChangedEvent](#enablevaluechangedevent)|Habilita ou desabilita o evento ValueChanged.|
|[CAnimationVariable::GetDefaultValue](#getdefaultvalue)|Retorna o valor padrão.|
|[CAnimationVariable::GetParentAnimationObject](#getparentanimationobject)|Retorna o objeto de animação pai.|
|[CAnimationVariable::GetValue](#getvalue)|Sobrecarregado. Retorna o valor atual da variável de animação.|
|[CAnimationVariable::GetVariable](#getvariable)|Retorna um ponteiro para o objeto COM IUIAnimationVariable.|
|[CAnimationVariable::SetDefaultValue](#setdefaultvalue)|Define o valor padrão e libera o objeto COM IUIAnimationVariable.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::SetParentAnimationObject](#setparentanimationobject)|Define a relação entre uma variável de animação e um objeto de animação.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::m_bAutodestroyTransitions](#m_bautodestroytransitions)|Especifica se os objetos de transição relacionados devem ser excluídos.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::m_dblDefaultValue](#m_dbldefaultvalue)|Especifica o valor padrão, que é propagado para IUIAnimationVariable.|
|[CAnimationVariable::m_lstTransitions](#m_lsttransitions)|Contém uma lista de transições que animam esta variável de animação.|
|[CAnimationVariable::m_pParentObject](#m_pparentobject)|Um ponteiro para um objeto de animação que encapsula essa variável de animação.|
|[CAnimationVariable::m_variable](#m_variable)|Armazena um ponteiro para o objeto COM IUIAnimationVariable. NULL se o objeto COM ainda não tiver sido criado ou se a criação falhar.|

## <a name="remarks"></a>Comentários

A classe CAnimationVariable encapsula o objeto COM IUIAnimationVariable. Ele também mantém uma lista de transições a serem aplicadas à variável de animação em um Storyboard. Os objetos CAnimationVariable são inseridos em objetos de animação, que podem representar em um aplicativo um valor animado, um ponto, um tamanho, uma cor e um retângulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAnimationVariable`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller. h

##  <a name="_dtorcanimationvariable"></a>CAnimationVariable:: ~ CAnimationVariable

O destruidor. Chamado quando um objeto CAnimationVariable está sendo destruído.

```
virtual ~CAnimationVariable();
```

##  <a name="addtransition"></a>  CAnimationVariable::AddTransition

Adiciona uma transição.

```
void AddTransition(CBaseTransition* pTransition);
```

### <a name="parameters"></a>Parâmetros

*pTransition*<br/>
Um ponteiro para uma transição a ser adicionada.

### <a name="remarks"></a>Comentários

Esse método é chamado para adicionar uma transição à lista interna de transições a serem aplicadas à variável de animação. Essa lista deve ser limpa quando uma animação é agendada.

##  <a name="applytransitions"></a>  CAnimationVariable::ApplyTransitions

Adiciona transições da lista interna ao storyboard.

```
void ApplyTransitions(
    CAnimationController* pController,
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDependOnKeyframes);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador de animação pai.

*pStoryboard*<br/>
Um ponteiro para storyboard.

*bDependOnKeyframes*<br/>
TRUE, se esse método deve adicionar transições que dependem de quadros-chave.

### <a name="remarks"></a>Comentários

Esse método adiciona transições da lista interna ao storyboard. Ele é chamado a partir do código de nível superior várias vezes para adicionar transições que não dependem de quadros-chave e adicionam transições que dependem de quadros-chave. Se o objeto COM da variável de animação subjacente não tiver sido criado, esse método o criará neste estágio.

##  <a name="canimationvariable"></a>CAnimationVariable::CAnimationVariable

Constrói um objeto de variável de animação.

```
CAnimationVariable(DOUBLE dblDefaultValue = 0.0);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o valor padrão.

### <a name="remarks"></a>Comentários

Constrói um objeto de variável de animação e define seu valor padrão. Um valor padrão é usado quando uma variável não é animada ou não pode ser animada.

##  <a name="cleartransitions"></a>  CAnimationVariable::ClearTransitions

Limpa as transições.

```
void ClearTransitions(BOOL bAutodestroy);
```

### <a name="parameters"></a>Parâmetros

*bAutodestroy*<br/>
Especifica se este método deve excluir objetos de transição.

### <a name="remarks"></a>Comentários

Esse método remove todas as transições da lista interna de transições. Se bAutodestroy for TRUE ou m_bAutodestroyTransitions for TRUE, as transições serão excluídas. Caso contrário, o chamador deve desalocar os objetos de transição.

##  <a name="create"></a>CAnimationVariable:: criar

Cria o objeto COM da variável de animação subjacente.

```
virtual BOOL Create(IUIAnimationManager* pManager);
```

### <a name="parameters"></a>Parâmetros

*pManager*<br/>
Um ponteiro para o Gerenciador de animação.

### <a name="return-value"></a>Valor de retorno

TRUE se a variável de animação tiver sido criada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método cria o objeto COM da variável de animação subjacente e define seu valor padrão.

##  <a name="createtransitions"></a>  CAnimationVariable::CreateTransitions

Cria todas as transições a serem aplicadas a esta variável de animação.

```
BOOL CreateTransitions(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se as transições foram criadas com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework quando precisa criar transições que foram adicionadas à lista interna de transições da variável.

##  <a name="enableintegervaluechangedevent"></a>  CAnimationVariable::EnableIntegerValueChangedEvent

Habilita ou desabilita o evento IntegerValueChanged.

```
void EnableIntegerValueChangedEvent (
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador pai.

*bEnable*<br/>
TRUE – habilitar evento, falso-desabilitar evento.

### <a name="remarks"></a>Comentários

Quando o evento ValueChanged é habilitado, a estrutura chama o método virtual CAnimationController:: OnAnimationIntegerValueChanged. Você precisa substituí-lo em uma classe derivada de CAnimationController para processar esse evento. Esse método é chamado toda vez que o valor inteiro da variável de animação é alterado.

##  <a name="enablevaluechangedevent"></a>CAnimationVariable::EnableValueChangedEvent

Habilita ou desabilita o evento ValueChanged.

```
void EnableValueChangedEvent (
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador pai.

*bEnable*<br/>
TRUE – habilitar evento, falso-desabilitar evento.

### <a name="remarks"></a>Comentários

Quando o evento ValueChanged é habilitado, a estrutura chama o método virtual CAnimationController:: OnAnimationValueChanged. Você precisa substituí-lo em uma classe derivada de CAnimationController para processar esse evento. Esse método é chamado toda vez que o valor da variável de animação é alterado.

##  <a name="getdefaultvalue"></a>  CAnimationVariable::GetDefaultValue

Retorna o valor padrão.

```
DOUBLE GetDefaultValue() const;
```

### <a name="return-value"></a>Valor de retorno

O valor padrão.

### <a name="remarks"></a>Comentários

Use essa função para obter o valor padrão da variável de animação. O valor padrão pode ser definido no construtor ou pelo método setpadrãovalue.

##  <a name="getparentanimationobject"></a>  CAnimationVariable::GetParentAnimationObject

Retorna o objeto de animação pai.

```
CAnimationBaseObject* GetParentAnimationObject();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para objeto de animação pai, se relationship tiver sido estabelecida, caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse método pode ser chamado para recuperar um ponteiro para um objeto de animação pai (um contêiner).

##  <a name="getvalue"></a>  CAnimationVariable::GetValue

Retorna o valor atual da variável de animação.

```
HRESULT GetValue(DOUBLE& dblValue);
HRESULT GetValue(INT32& nValue);
```

### <a name="parameters"></a>Parâmetros

*dblValue*<br/>
O valor atual da variável de animação.

*nValue*<br/>
O valor atual da variável de animação.

### <a name="return-value"></a>Valor de retorno

S_OK se o valor foi obtido com êxito ou se a variável de animação subjacente não foi criada. Caso contrário, o código de erro HRESULT.

### <a name="remarks"></a>Comentários

Esse método pode ser chamado para recuperar o valor atual da variável de animação. Se o objeto COM subjacente não tiver sido criado, o dblValue conterá um valor padrão, quando a função retornar.

##  <a name="getvariable"></a>  CAnimationVariable::GetVariable

Retorna um ponteiro para o objeto COM IUIAnimationVariable.

```
IUIAnimationVariable* GetVariable();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para o objeto COM IUIAnimationVariable ou NULL se a variável de animação não tiver sido criada ou não puder ser criada.

### <a name="remarks"></a>Comentários

Use essa função para acessar o objeto COM IUIAnimationVariable subjacente e chamar seus métodos diretamente, se necessário.

##  <a name="m_bautodestroytransitions"></a>  CAnimationVariable::m_bAutodestroyTransitions

Especifica se os objetos de transição relacionados devem ser excluídos.

```
BOOL m_bAutodestroyTransitions;
```

### <a name="remarks"></a>Comentários

Defina esse valor como TRUE para forçar a exclusão de objetos de transição quando eles estiverem sendo removidos da lista interna de transições. Se esse valor for falso, as transições deverão ser excluídas chamando o aplicativo. A lista de transições sempre é apagada depois que uma animação é agendada. O valor padrão é FALSE.

##  <a name="m_dbldefaultvalue"></a>  CAnimationVariable::m_dblDefaultValue

Especifica o valor padrão, que é propagado para IUIAnimationVariable.

```
DOUBLE m_dblDefaultValue;
```

##  <a name="m_lsttransitions"></a>  CAnimationVariable::m_lstTransitions

Contém uma lista de transições que animam esta variável de animação.

```
CObList m_lstTransitions;
```

##  <a name="m_pparentobject"></a>  CAnimationVariable::m_pParentObject

Um ponteiro para um objeto de animação que encapsula essa variável de animação.

```
CAnimationBaseObject* m_pParentObject;
```

##  <a name="m_variable"></a>  CAnimationVariable::m_variable

Armazena um ponteiro para o objeto COM IUIAnimationVariable. NULL se o objeto COM ainda não tiver sido criado ou se a criação falhar.

```
ATL::CComPtr<IUIAnimationVariable> m_variable;
```

##  <a name="setdefaultvalue"></a>  CAnimationVariable::SetDefaultValue

Define o valor padrão e libera o objeto COM IUIAnimationVariable.

```
void SetDefaultValue(DOUBLE dblDefaultValue);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o novo valor padrão.

### <a name="remarks"></a>Comentários

Use este método para redefinir o valor padrão. Esse método libera o objeto COM IUIAnimationVariable interno, portanto, quando a variável de animação é recriada, o objeto COM subjacente Obtém o novo valor padrão. O valor padrão será retornado por GetValue se o objeto COM que representa a variável de animação não for criado ou se a variável não tiver sido animada.

##  <a name="setparentanimationobject"></a>  CAnimationVariable::SetParentAnimationObject

Define a relação entre uma variável de animação e um objeto de animação.

```
void SetParentAnimationObject(CAnimationBaseObject* pParentObject);
```

### <a name="parameters"></a>Parâmetros

*pParentObject*<br/>
Um ponteiro para um objeto de animação que contém essa variável.

### <a name="remarks"></a>Comentários

Esse método é chamado internamente para estabelecer uma relação um-para-um entre uma variável de animação e um objeto de animação que a encapsula.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
