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
ms.openlocfilehash: 51cc4732ee8ad5f954e5bd758484cec74cf00fe6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377045"
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
|[CAnimationVariable::CAnimationVariable](#canimationvariable)|Constrói um objeto variável de animação.|
|[CAnimationVariable::~CAnimationVariable](#_dtorcanimationvariable)|O destruidor. Chamado quando um objeto CAnimationVariable está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::AddTransition](#addtransition)|Adiciona uma transição.|
|[CAnimationVariable::Aplicartransições](#applytransitions)|Adiciona transições da lista interna para storyboard.|
|[CAnimationVariable::ClearTransitions](#cleartransitions)|Limpa transições.|
|[CAnimationVariable::Criar](#create)|Cria o objeto COM variável de animação subjacente.|
|[CAnimationVariable::CreateTransitions](#createtransitions)|Cria todas as transições a serem aplicadas a esta variável de animação.|
|[CAnimationVariable::AtivarIntegerValueChangedEvent](#enableintegervaluechangedevent)|Ativa ou desativa o evento IntegerValueChanged.|
|[CAnimationVariable::Ativaralterarvaloralteron](#enablevaluechangedevent)|Ativa ou desativa o evento ValueChanged.|
|[CAnimationVariable::GetDefaultValue](#getdefaultvalue)|Retorna o valor padrão.|
|[cAnimationvariable::getParentAnimationObject](#getparentanimationobject)|Retorna o objeto de animação pai.|
|[CAnimationVariable::GetValue](#getvalue)|Sobrecarregado. Retorna o valor atual da variável animação.|
|[CAnimationVariable::GetVariable](#getvariable)|Retorna um ponteiro para o objeto IUIAnimationVariable COM.|
|[CAnimationVariable::SetDefaultValue](#setdefaultvalue)|Define o valor padrão e libera o objeto IUIAnimationVariable COM.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::SetParentAnimationObject](#setparentanimationobject)|Define a relação entre uma variável de animação e um objeto de animação.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::m_bAutodestroyTransitions](#m_bautodestroytransitions)|Especifica se objetos de transição relacionados devem ser excluídos.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariable::m_dblDefaultValue](#m_dbldefaultvalue)|Especifica o valor padrão, que é propagado para IUIAnimationVariable.|
|[CAnimationVariable::m_lstTransitions](#m_lsttransitions)|Contém uma lista de transições que animam essa variável de animação.|
|[CAnimationVariable::m_pParentObject](#m_pparentobject)|Um ponteiro para um objeto de animação que encapsula essa variável de animação.|
|[CAnimationVariable::m_variable](#m_variable)|Armazena um ponteiro para o objeto IUIAnimationVariable COM. NULL se o objeto COM ainda não foi criado ou se a criação falhou.|

## <a name="remarks"></a>Comentários

A classe CAnimationVariable encapsula o objeto IUIAnimationVariable COM. Ele também contém uma lista de transições a serem aplicadas à variável animação em um storyboard. Os objetos CAnimationVariable são incorporados a objetos de animação, que podem representar em um aplicativo um valor animado, ponto, tamanho, cor e retângulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAnimationVariable`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationvariablecanimationvariable"></a><a name="_dtorcanimationvariable"></a>CAnimationVariable::~CAnimationVariable

O destruidor. Chamado quando um objeto CAnimationVariable está sendo destruído.

```
virtual ~CAnimationVariable();
```

## <a name="canimationvariableaddtransition"></a><a name="addtransition"></a>CAnimationVariable::AddTransition

Adiciona uma transição.

```
void AddTransition(CBaseTransition* pTransition);
```

### <a name="parameters"></a>Parâmetros

*pTransição*<br/>
Um ponteiro para uma transição para adicionar.

### <a name="remarks"></a>Comentários

Este método é chamado para adicionar uma transição à lista interna de transições a serem aplicadas à variável animação. Esta lista deve ser limpa quando uma animação foi agendada.

## <a name="canimationvariableapplytransitions"></a><a name="applytransitions"></a>CAnimationVariable::Aplicartransições

Adiciona transições da lista interna para storyboard.

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

*bDependOnkeyframes*<br/>
TRUE, se este método deve adicionar transições que dependem de quadros-chave.

### <a name="remarks"></a>Comentários

Este método adiciona transições da lista interna para storyboard. Ele é chamado do código de nível superior várias vezes para adicionar transições que não dependem de quadros-chave e adicionar transições que dependem de quadros-chave. Se o objeto COM variável de animação subjacente não tiver sido criado, este método o criará nesta fase.

## <a name="canimationvariablecanimationvariable"></a><a name="canimationvariable"></a>CAnimationVariable::CAnimationVariable

Constrói um objeto variável de animação.

```
CAnimationVariable(DOUBLE dblDefaultValue = 0.0);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o valor padrão.

### <a name="remarks"></a>Comentários

Constrói um objeto variável de animação e define seu valor padrão. Um valor padrão é usado quando uma variável não é animada ou não pode ser animada.

## <a name="canimationvariablecleartransitions"></a><a name="cleartransitions"></a>CAnimationVariable::ClearTransitions

Limpa transições.

```
void ClearTransitions(BOOL bAutodestroy);
```

### <a name="parameters"></a>Parâmetros

*bAutodestroy*<br/>
Especifica se esse método deve excluir objetos de transição.

### <a name="remarks"></a>Comentários

Este método remove todas as transições da lista interna de transições. Se bAutodestroy for TRUE, ou m_bAutodestroyTransitions for TRUE, então as transições serão excluídas. Caso contrário, o chamador deve desalocar os objetos de transição.

## <a name="canimationvariablecreate"></a><a name="create"></a>CAnimationVariable::Criar

Cria o objeto COM variável de animação subjacente.

```
virtual BOOL Create(IUIAnimationManager* pManager);
```

### <a name="parameters"></a>Parâmetros

*pManager*<br/>
Um ponteiro para o gerenciador de animação.

### <a name="return-value"></a>Valor retornado

TRUE se a variável de animação foi criada com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método cria o objeto COM variável de animação subjacente e define seu valor padrão.

## <a name="canimationvariablecreatetransitions"></a><a name="createtransitions"></a>CAnimationVariable::CreateTransitions

Cria todas as transições a serem aplicadas a esta variável de animação.

```
BOOL CreateTransitions(
    IUIAnimationTransitionLibrary* pLibrary,
    IUIAnimationTransitionFactory* \*not used*\);
```

### <a name="parameters"></a>Parâmetros

*pBiblioteca*<br/>
Um ponteiro para uma [interface IUIAnimationTransitionLibrary](/windows/win32/api/uianimation/nn-uianimation-iuianimationtransitionlibrary), que define uma biblioteca de transições padrão.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se as transições foram criadas com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo framework quando precisa criar transições que foram adicionadas à lista interna de transições da variável.

## <a name="canimationvariableenableintegervaluechangedevent"></a><a name="enableintegervaluechangedevent"></a>CAnimationVariable::AtivarIntegerValueChangedEvent

Ativa ou desativa o evento IntegerValueChanged.

```
void EnableIntegerValueChangedEvent (
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador pai.

*Benable*<br/>
TRUE - ativar evento, FALSO - desativar evento.

### <a name="remarks"></a>Comentários

Quando o evento ValueChanged está ativado, a estrutura chama o método virtual CAnimationController::OnAnimationIntegerValueChanged. Você precisa substituí-lo em uma classe derivada do CAnimationController para processar este evento. Este método é chamado toda vez que o valor inteiro da variável animação é alterado.

## <a name="canimationvariableenablevaluechangedevent"></a><a name="enablevaluechangedevent"></a>CAnimationVariable::Ativaralterarvaloralteron

Ativa ou desativa o evento ValueChanged.

```
void EnableValueChangedEvent (
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para o controlador pai.

*Benable*<br/>
TRUE - ativar evento, FALSO - desativar evento.

### <a name="remarks"></a>Comentários

Quando o evento ValueChanged está ativado, a estrutura chama o método virtual CAnimationController::OnAnimationValueChanged. Você precisa substituí-lo em uma classe derivada do CAnimationController para processar este evento. Este método é chamado toda vez que o valor da variável animação é alterado.

## <a name="canimationvariablegetdefaultvalue"></a><a name="getdefaultvalue"></a>CAnimationVariable::GetDefaultValue

Retorna o valor padrão.

```
DOUBLE GetDefaultValue() const;
```

### <a name="return-value"></a>Valor retornado

O valor padrão.

### <a name="remarks"></a>Comentários

Use esta função para obter o valor padrão da variável animação. O valor padrão pode ser definido no construtor ou pelo método SetDefaultValue.

## <a name="canimationvariablegetparentanimationobject"></a><a name="getparentanimationobject"></a>cAnimationvariable::getParentAnimationObject

Retorna o objeto de animação pai.

```
CAnimationBaseObject* GetParentAnimationObject();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para objeto de animação pai, se a relação foi estabelecida, caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este método pode ser chamado para recuperar um ponteiro para um objeto de animação pai (um recipiente).

## <a name="canimationvariablegetvalue"></a><a name="getvalue"></a>CAnimationVariable::GetValue

Retorna o valor atual da variável animação.

```
HRESULT GetValue(DOUBLE& dblValue);
HRESULT GetValue(INT32& nValue);
```

### <a name="parameters"></a>Parâmetros

*dblValue*<br/>
O valor atual da variável animação.

*Nvalue*<br/>
O valor atual da variável animação.

### <a name="return-value"></a>Valor retornado

S_OK se o valor foi obtido com sucesso, ou a variável de animação subjacente não foi criada. Caso contrário, código de erro HRESULT.

### <a name="remarks"></a>Comentários

Este método pode ser chamado para recuperar o valor atual da variável animação. Se o objeto COM subjacente não tiver sido criado, o dblValue conterá um valor padrão, quando a função retornar.

## <a name="canimationvariablegetvariable"></a><a name="getvariable"></a>CAnimationVariable::GetVariable

Retorna um ponteiro para o objeto IUIAnimationVariable COM.

```
IUIAnimationVariable* GetVariable();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para o objeto IUIAnimationVariable COM ou NULL se a variável de animação não foi criada ou não pode ser criada.

### <a name="remarks"></a>Comentários

Use esta função para acessar o objeto IUIAnimationVariable COM subjacente e chamar seus métodos diretamente se necessário.

## <a name="canimationvariablem_bautodestroytransitions"></a><a name="m_bautodestroytransitions"></a>CAnimationVariable::m_bAutodestroyTransitions

Especifica se objetos de transição relacionados devem ser excluídos.

```
BOOL m_bAutodestroyTransitions;
```

### <a name="remarks"></a>Comentários

Defina esse valor como TRUE para forçar a exclusão de objetos de transição quando eles estiverem sendo removidos da lista interna de transições. Se esse valor for FALSO, as transições devem ser excluídas pelo aplicativo de chamada. A lista de transições é sempre limpa depois que uma animação foi agendada. O valor padrão é FALSE.

## <a name="canimationvariablem_dbldefaultvalue"></a><a name="m_dbldefaultvalue"></a>CAnimationVariable::m_dblDefaultValue

Especifica o valor padrão, que é propagado para IUIAnimationVariable.

```
DOUBLE m_dblDefaultValue;
```

## <a name="canimationvariablem_lsttransitions"></a><a name="m_lsttransitions"></a>CAnimationVariable::m_lstTransitions

Contém uma lista de transições que animam essa variável de animação.

```
CObList m_lstTransitions;
```

## <a name="canimationvariablem_pparentobject"></a><a name="m_pparentobject"></a>CAnimationVariable::m_pParentObject

Um ponteiro para um objeto de animação que encapsula essa variável de animação.

```
CAnimationBaseObject* m_pParentObject;
```

## <a name="canimationvariablem_variable"></a><a name="m_variable"></a>CAnimationVariable::m_variable

Armazena um ponteiro para o objeto IUIAnimationVariable COM. NULL se o objeto COM ainda não foi criado ou se a criação falhou.

```
ATL::CComPtr<IUIAnimationVariable> m_variable;
```

## <a name="canimationvariablesetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationVariable::SetDefaultValue

Define o valor padrão e libera o objeto IUIAnimationVariable COM.

```
void SetDefaultValue(DOUBLE dblDefaultValue);
```

### <a name="parameters"></a>Parâmetros

*dblDefaultValue*<br/>
Especifica o novo valor padrão.

### <a name="remarks"></a>Comentários

Use este método para redefinir o valor padrão. Este método libera o objeto Interno IUIAnimationVariable COM, portanto, quando a variável de animação é recriada, o objeto COM subjacente recebe o novo valor padrão. O valor padrão é devolvido pelo GetValue se o objeto COM representando a variável animação não for criado ou se a variável não tiver sido animada.

## <a name="canimationvariablesetparentanimationobject"></a><a name="setparentanimationobject"></a>CAnimationVariable::SetParentAnimationObject

Define a relação entre uma variável de animação e um objeto de animação.

```
void SetParentAnimationObject(CAnimationBaseObject* pParentObject);
```

### <a name="parameters"></a>Parâmetros

*pParentObject*<br/>
Um ponteiro para um objeto de animação que contém esta variável.

### <a name="remarks"></a>Comentários

Este método é chamado internamente para estabelecer uma relação um-para-um entre uma variável de animação e um objeto de animação que o encapsula.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
