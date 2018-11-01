---
title: Classe CAnimationVariable
ms.date: 11/04/2016
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
ms.openlocfilehash: 1ad14060c7607698cd647ae34fb35b6ea3ae547c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50559556"
---
# <a name="canimationvariable-class"></a>Classe CAnimationVariable

Representa uma variável de animação.

## <a name="syntax"></a>Sintaxe

```
class CAnimationVariable;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::CAnimationVariable](#canimationvariable)|Constrói um objeto de variável de animação.|
|[CAnimationVariable:: ~ CAnimationVariable](#canimationvariable__~canimationvariable)|O destruidor. Chamado quando um objeto CAnimationVariable está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::AddTransition](#addtransition)|Adiciona uma transição.|
|[CAnimationVariable::ApplyTransitions](#applytransitions)|Adiciona as transições da lista interna para executar o storyboard.|
|[CAnimationVariable::ClearTransitions](#cleartransitions)|Limpa as transições.|
|[CAnimationVariable::Create](#create)|Cria o subjacente objeto COM variável de animação.|
|[CAnimationVariable::CreateTransitions](#createtransitions)|Cria todas as transições a serem aplicadas a essa variável de animação.|
|[CAnimationVariable::EnableIntegerValueChangedEvent](#enableintegervaluechangedevent)|Habilita ou desabilita o evento IntegerValueChanged.|
|[CAnimationVariable::EnableValueChangedEvent](#enablevaluechangedevent)|Habilita ou desabilita o evento ValueChanged.|
|[CAnimationVariable::GetDefaultValue](#getdefaultvalue)|Retorna o valor padrão.|
|[CAnimationVariable::GetParentAnimationObject](#getparentanimationobject)|Retorna o pai no objeto de animação.|
|[CAnimationVariable::GetValue](#getvalue)|Sobrecarregado. Retorna o valor atual da variável de animação.|
|[CAnimationVariable::GetVariable](#getvariable)|Retorna um ponteiro para objeto COM IUIAnimationVariable.|
|[CAnimationVariable::SetDefaultValue](#setdefaultvalue)|Define o valor padrão e libera o objeto COM IUIAnimationVariable.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::SetParentAnimationObject](#setparentanimationobject)|Define a relação entre uma variável de animação e um objeto de animação.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::m_bAutodestroyTransitions](#m_bautodestroytransitions)|Especifica se os objetos relacionados de transição devem ser excluídos.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::m_dblDefaultValue](#m_dbldefaultvalue)|Especifica o valor padrão, que é propagado para IUIAnimationVariable.|
|[CAnimationVariable::m_lstTransitions](#m_lsttransitions)|Contém uma lista de transições que animar essa variável de animação.|
|[CAnimationVariable::m_pParentObject](#m_pparentobject)|Um ponteiro para um objeto de animação que encapsula a essa variável de animação.|
|[CAnimationVariable::m_variable](#m_variable)|Armazena um ponteiro para objeto COM IUIAnimationVariable. NULL se o objeto COM ainda não foi criado, ou se a falha na criação.|

## <a name="remarks"></a>Comentários

A classe CAnimationVariable encapsula o objeto COM IUIAnimationVariable. Ele também contém uma lista de transições a serem aplicadas à variável de animação em um storyboard. Objetos CAnimationVariable são inseridos para objetos de animação, que podem representar em um aplicativo de um valor animado, ponto, tamanho, cor e retângulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAnimationVariable`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="_dtorcanimationvariable"></a>  CAnimationVariable:: ~ CAnimationVariable

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
Um ponteiro para uma transição para adicionar.

### <a name="remarks"></a>Comentários

Esse método é chamado para adicionar uma transição para a lista interna de transições a serem aplicadas à variável de animação. Essa lista deve ser limpo quando uma animação foi agendada.

##  <a name="applytransitions"></a>  CAnimationVariable::ApplyTransitions

Adiciona as transições da lista interna para executar o storyboard.

```
void ApplyTransitions(
    CAnimationController* pController,
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDependOnKeyframes);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador de animação do pai.

*pStoryboard*<br/>
Um ponteiro para criar um storyboard.

*bDependOnKeyframes*<br/>
TRUE se este método deve adicionar as transições que dependem de quadros-chave.

### <a name="remarks"></a>Comentários

Esse método adiciona as transições da lista interna para executar o storyboard. Ele é chamado do código de nível superior várias vezes para adicionar as transições que não dependem de quadros-chave e adicionar as transições que dependem de quadros-chave. Se a variável de animação objeto COM subjacente não tiver sido criada, esse método cria neste estágio.

##  <a name="canimationvariable"></a>  CAnimationVariable::CAnimationVariable

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
Especifica se esse método deve excluir objetos de transição.

### <a name="remarks"></a>Comentários

Esse método Remove todas as transições da lista interna de transições. Se bAutodestroy for TRUE, ou m_bAutodestroyTransitions for TRUE, as transições são excluídas. Caso contrário, o chamador deverá desalocar os objetos de transição.

##  <a name="create"></a>  CAnimationVariable::Create

Cria o subjacente objeto COM variável de animação.

```
virtual BOOL Create(IUIAnimationManager* pManager);
```

### <a name="parameters"></a>Parâmetros

*pManager*<br/>
Um ponteiro para o Gerenciador de animação.

### <a name="return-value"></a>Valor de retorno

TRUE se a variável de animação foi criada com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método cria a variável de animação subjacente objeto COM e define seu valor padrão.

##  <a name="createtransitions"></a>  CAnimationVariable::CreateTransitions

Cria todas as transições a serem aplicadas a essa variável de animação.

```
BOOL CreateTransitions(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pLibrary*<br/>
Um ponteiro para um [IUIAnimationTransitionLibrary interface](/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor de retorno

TRUE se as transições foram criadas com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método é chamado pelo framework quando ele precisa criar transições que foram adicionadas à lista interna da variável de transições.

##  <a name="enableintegervaluechangedevent"></a>  CAnimationVariable::EnableIntegerValueChangedEvent

Habilita ou desabilita o evento IntegerValueChanged.

```
void EnableIntegerValueChangedEvent (
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador de pai.

*bAtivar*<br/>
TRUE – habilitar eventos, FALSE - desabilitar eventos.

### <a name="remarks"></a>Comentários

Quando o evento ValueChanged é habilitado, o framework chama o método virtual CAnimationController::OnAnimationIntegerValueChanged. Você precisa substituí-la em uma classe derivada de CAnimationController para processar este evento. Esse método é chamado sempre que o valor inteiro da variável de animação é alterado.

##  <a name="enablevaluechangedevent"></a>  CAnimationVariable::EnableValueChangedEvent

Habilita ou desabilita o evento ValueChanged.

```
void EnableValueChangedEvent (
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador de pai.

*bAtivar*<br/>
TRUE – habilitar eventos, FALSE - desabilitar eventos.

### <a name="remarks"></a>Comentários

Quando o evento ValueChanged é habilitado, o framework chama o método virtual CAnimationController::OnAnimationValueChanged. Você precisa substituí-la em uma classe derivada de CAnimationController para processar este evento. Esse método é chamado sempre que o valor da variável de animação é alterado.

##  <a name="getdefaultvalue"></a>  CAnimationVariable::GetDefaultValue

Retorna o valor padrão.

```
DOUBLE GetDefaultValue() const;
```

### <a name="return-value"></a>Valor de retorno

O valor padrão.

### <a name="remarks"></a>Comentários

Use essa função para obter o valor padrão da variável de animação. O valor padrão pode ser definido no construtor ou método SetDefaultValue.

##  <a name="getparentanimationobject"></a>  CAnimationVariable::GetParentAnimationObject

Retorna o pai no objeto de animação.

```
CAnimationBaseObject* GetParentAnimationObject();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto de animação do pai, se a relação foi estabelecida, caso contrário, nulo.

### <a name="remarks"></a>Comentários

Esse método pode ser chamado para recuperar um ponteiro para um objeto de animação do pai (um contêiner).

##  <a name="getvalue"></a>  CAnimationVariable::GetValue

Retorna o valor atual da variável de animação.

```
HRESULT GetValue(DOUBLE& dblValue);
HRESULT GetValue(INT32& nValue);
```

### <a name="parameters"></a>Parâmetros

*dblValue*<br/>
O valor atual da variável de animação.

*Nvalor*<br/>
O valor atual da variável de animação.

### <a name="return-value"></a>Valor de retorno

S_OK se o valor foi obtido com êxito ou a variável de animação subjacente não tiver sido criado. Caso contrário, código de erro HRESULT.

### <a name="remarks"></a>Comentários

Esse método pode ser chamado para recuperar o valor atual da variável de animação. Se o objeto COM subjacente não tiver sido criado, dblValue conterá um valor padrão, quando a função retorna.

##  <a name="getvariable"></a>  CAnimationVariable::GetVariable

Retorna um ponteiro para objeto COM IUIAnimationVariable.

```
IUIAnimationVariable* GetVariable();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para o objeto COM IUIAnimationVariable ou nulo se a variável de animação não tiver sido criado ou não pode ser criado.

### <a name="remarks"></a>Comentários

Use esta função para acessar o objeto COM IUIAnimationVariable subjacente e chamar seus métodos diretamente, se necessário.

##  <a name="m_bautodestroytransitions"></a>  CAnimationVariable::m_bAutodestroyTransitions

Especifica se os objetos relacionados de transição devem ser excluídos.

```
BOOL m_bAutodestroyTransitions;
```

### <a name="remarks"></a>Comentários

Defina esse valor como True para forçar a exclusão de objetos de transição quando eles estão sendo removidos da lista interna de transições. Se esse valor for FALSE, as transições devem ser excluídas chamando o aplicativo. A lista de transições sempre é limpo depois que uma animação foi agendada. O valor padrão é FALSE.

##  <a name="m_dbldefaultvalue"></a>  CAnimationVariable::m_dblDefaultValue

Especifica o valor padrão, que é propagado para IUIAnimationVariable.

```
DOUBLE m_dblDefaultValue;
```

##  <a name="m_lsttransitions"></a>  CAnimationVariable::m_lstTransitions

Contém uma lista de transições que animar essa variável de animação.

```
CObList m_lstTransitions;
```

##  <a name="m_pparentobject"></a>  CAnimationVariable::m_pParentObject

Um ponteiro para um objeto de animação que encapsula a essa variável de animação.

```
CAnimationBaseObject* m_pParentObject;
```

##  <a name="m_variable"></a>  CAnimationVariable::m_variable

Armazena um ponteiro para objeto COM IUIAnimationVariable. NULL se o objeto COM ainda não foi criado, ou se a falha na criação.

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

Use esse método para redefinir o valor padrão. Esse método libera o objeto COM IUIAnimationVariable interno, portanto quando a variável de animação é recriado, o objeto COM subjacente obtém o novo valor padrão. O valor padrão é retornado pelo GetValue se o objeto COM que representa a variável de animação não for criado, ou se a variável não ter sido animada.

##  <a name="setparentanimationobject"></a>  CAnimationVariable::SetParentAnimationObject

Define a relação entre uma variável de animação e um objeto de animação.

```
void SetParentAnimationObject(CAnimationBaseObject* pParentObject);
```

### <a name="parameters"></a>Parâmetros

*pParentObject*<br/>
Um ponteiro para um objeto de animação que contém essa variável.

### <a name="remarks"></a>Comentários

Esse método é chamado internamente para estabelecer uma relação um para um entre uma variável de animação e um objeto de animação que encapsula a ele.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
