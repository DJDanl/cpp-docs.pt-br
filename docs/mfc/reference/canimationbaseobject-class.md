---
title: Classe CAnimationBaseObject
ms.date: 03/27/2019
f1_keywords:
- CAnimationBaseObject
- AFXANIMATIONCONTROLLER/CAnimationBaseObject
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::CAnimationBaseObject
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::ApplyTransitions
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::ClearTransitions
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::ContainsVariable
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::CreateTransitions
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::DetachFromController
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::EnableIntegerValueChangedEvent
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::EnableValueChangedEvent
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::GetAutodestroyTransitions
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::GetGroupID
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::GetObjectID
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::GetUserData
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::SetAutodestroyTransitions
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::SetID
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::SetUserData
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::SetParentAnimationObjects
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::m_bAutodestroyTransitions
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::m_dwUserData
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::m_nGroupID
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::m_nObjectID
- AFXANIMATIONCONTROLLER/CAnimationBaseObject::m_pParentController
helpviewer_keywords:
- CAnimationBaseObject [MFC], CAnimationBaseObject
- CAnimationBaseObject [MFC], ApplyTransitions
- CAnimationBaseObject [MFC], ClearTransitions
- CAnimationBaseObject [MFC], ContainsVariable
- CAnimationBaseObject [MFC], CreateTransitions
- CAnimationBaseObject [MFC], DetachFromController
- CAnimationBaseObject [MFC], EnableIntegerValueChangedEvent
- CAnimationBaseObject [MFC], EnableValueChangedEvent
- CAnimationBaseObject [MFC], GetAutodestroyTransitions
- CAnimationBaseObject [MFC], GetGroupID
- CAnimationBaseObject [MFC], GetObjectID
- CAnimationBaseObject [MFC], GetUserData
- CAnimationBaseObject [MFC], SetAutodestroyTransitions
- CAnimationBaseObject [MFC], SetID
- CAnimationBaseObject [MFC], SetUserData
- CAnimationBaseObject [MFC], GetAnimationVariableList
- CAnimationBaseObject [MFC], SetParentAnimationObjects
- CAnimationBaseObject [MFC], m_bAutodestroyTransitions
- CAnimationBaseObject [MFC], m_dwUserData
- CAnimationBaseObject [MFC], m_nGroupID
- CAnimationBaseObject [MFC], m_nObjectID
- CAnimationBaseObject [MFC], m_pParentController
ms.assetid: 76b25917-940e-4eba-940f-31d270702603
ms.openlocfilehash: 1874ddfdd26b8dd371e32f7e68ea8f668c47d8e1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750216"
---
# <a name="canimationbaseobject-class"></a>Classe CAnimationBaseObject

A classe base para todos os objetos de animação.

## <a name="syntax"></a>Sintaxe

```
class CAnimationBaseObject : public CObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationBaseObject::CAnimationBaseObject](#canimationbaseobject)|Sobrecarregado. Constrói um objeto de animação.|
|[CAnimationBaseObject::~CAnimationBaseObject](#_dtorcanimationbaseobject)|O destruidor. Chamado quando um objeto de animação está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationBaseObject::ApplyTransitions](#applytransitions)|Adiciona transições ao storyboard com variável de animação encapsulada.|
|[CAnimationBaseObject::ClearTransitions](#cleartransitions)|Remove todas as transições relacionadas.|
|[CAnimationBaseObject::Contémvariável](#containsvariable)|Determina se um objeto de animação contém uma determinada variável de animação.|
|[CAnimationBaseObject::CreateTransitions](#createtransitions)|Cria transições associadas a um objeto de animação.|
|[CAnimationBaseObject::DetachFromController](#detachfromcontroller)|Destaca um objeto de animação do controlador de animação pai.|
|[CAnimationBaseObject::AtivarIntegerValueChangedEvent](#enableintegervaluechangedevent)|Configura o manipulador de eventos Integer Value Changed.|
|[CAnimationBaseObject::Ativaralteraralteraçãodetempo](#enablevaluechangedevent)|Configura o manipulador de eventos Alterado de valor.|
|[CAnimationBaseObject::GetAutodestroyTransitions](#getautodestroytransitions)|Diz se a transição relacionada é destruída automaticamente.|
|[CAnimationBaseObject::getGroupID](#getgroupid)|Retorna o ID do grupo atual.|
|[CAnimationBaseObject::GetObjectID](#getobjectid)|Retorna o ID do objeto atual.|
|[CAnimationBaseObject::getUserData](#getuserdata)|Retorna dados definidos pelo usuário.|
|[CAnimationBaseObject::SetAutodestroyTransitions](#setautodestroytransitions)|Define uma bandeira para destruir automaticamente as transições.|
|[CAnimationBaseObject::SetID](#setid)|Define novas ids.|
|[CAnimationBaseObject::SetUserData](#setuserdata)|Define dados definidos pelo usuário.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationBaseObject::getAnimationVariableList](#getanimationvariablelist)|Coleta ponteiros para variáveis de animação contidas.|
|[CAnimationBaseObject::SetParentAnimationObjeto](#setparentanimationobjects)|Estabelece relação entre variáveis de animação, contidas em um objeto de animação, e seu contêiner.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationBaseObject::m_bAutodestroyTransitions](#m_bautodestroytransitions)|Especifica se as transições relacionadas devem ser automaticamente destruídas.|
|[CAnimationBaseObject::m_dwUserData](#m_dwuserdata)|Armazena dados definidos pelo usuário.|
|[CAnimationBaseObject::m_nGroupID](#m_ngroupid)|Especifica o ID de grupo do objeto de animação.|
|[CAnimationBaseObject::m_nObjectID](#m_nobjectid)|Especifica o ID do objeto de exibição.|
|[CAnimationBaseObject::m_pParentController](#m_pparentcontroller)|Um ponteiro para o controlador de animação pai.|

## <a name="remarks"></a>Comentários

Esta classe implementa métodos básicos para todos os objetos de animação. Um objeto de animação pode representar um valor, ponto, tamanho, retângulo ou cor em um aplicativo, bem como qualquer entidade personalizada. Os objetos de animação são armazenados em grupos de animação (veja CAnimationGroup). Cada grupo pode ser animado separadamente e pode ser tratado como um análogo de storyboard. Um objeto de animação encapsula uma ou mais variáveis de animação (ver CAnimationVariable), dependendo de sua representação lógica. Por exemplo, CAnimationRect contém quatro variáveis de animação - uma variável para cada lado do retângulo. Cada classe de objeto de animação expõe o método AddTransition sobrecarregado, que deve ser usado para aplicar transições a variáveis de animação encapsuladas. Um objeto de animação pode ser identificado por ID de objeto (opcionalmente) e por ID de grupo. Um ID de grupo é necessário para colocar um objeto de animação para o grupo correto, mas se um ID de grupo não for especificado, um objeto será colocado no grupo padrão com ID 0. Se você chamar SetID com groupID diferente, um objeto de animação será movido para outro grupo (um novo grupo será criado se necessário).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CAnimationBaseObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationbaseobjectcanimationbaseobject"></a><a name="_dtorcanimationbaseobject"></a>CAnimationBaseObject::~CAnimationBaseObject

O destruidor. Chamado quando um objeto de animação está sendo destruído.

```
virtual ~CAnimationBaseObject();
```

## <a name="canimationbaseobjectapplytransitions"></a><a name="applytransitions"></a>CAnimationBaseObject::ApplyTransitions

Adiciona transições ao storyboard com variável de animação encapsulada.

```
virtual BOOL ApplyTransitions(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDependOnKeyframes);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um storyboard.

*bDependOnkeyframes*<br/>
Quando FALSE, este método adiciona apenas as transições que não dependem de quadros-chave.

### <a name="return-value"></a>Valor retornado

VERDADE se transições foram adicionadas com sucesso.

### <a name="remarks"></a>Comentários

Adiciona transições relacionadas, que foram adicionadas com AddTransition (métodos sobrecarregados em classes derivadas), ao storyboard.

## <a name="canimationbaseobjectcanimationbaseobject"></a><a name="canimationbaseobject"></a>CAnimationBaseObject::CAnimationBaseObject

Constrói um objeto de animação.

```
CAnimationBaseObject();

CAnimationBaseObject(
    UINT32 nGroupID,
    UINT32 nObjectID = (UINT32)-1,
    DWORD dwUserData = 0);
```

### <a name="parameters"></a>Parâmetros

*nGroupID*<br/>
Especifica o ID do grupo.

*nObjectID*<br/>
Especifica o ID do objeto.

*dwUserData*<br/>
Dados definidos pelo usuário, que podem ser associados ao objeto de animação e recuperados posteriormente em tempo de execução.

### <a name="remarks"></a>Comentários

Constrói um objeto de animação e atribui o ID do objeto padrão (0) e o ID do grupo (0).

## <a name="canimationbaseobjectcleartransitions"></a><a name="cleartransitions"></a>CAnimationBaseObject::ClearTransitions

Remove todas as transições relacionadas.

```
virtual void ClearTransitions(BOOL bAutodestroy);
```

### <a name="parameters"></a>Parâmetros

*bAutodestroy*<br/>
Especifica se deve destruir objetos de transição automaticamente ou apenas removê-los da lista relacionada.

### <a name="remarks"></a>Comentários

Remove todas as transições relacionadas e as destrói se bAutodestroy ou m_bAutodestroyTransitions bandeira for TRUE. As transições devem ser destruídas automaticamente somente se não estiverem alocadas na pilha. Se as bandeiras acima forem FALSAs, as transições serão removidas da lista interna de transições relacionadas.

## <a name="canimationbaseobjectcontainsvariable"></a><a name="containsvariable"></a>CAnimationBaseObject::Contémvariável

Determina se um objeto de animação contém uma determinada variável de animação.

```
virtual BOOL ContainsVariable(IUIAnimationVariable* pVariable);
```

### <a name="parameters"></a>Parâmetros

*pVariable*<br/>
Um ponteiro para a variável animação.

### <a name="return-value"></a>Valor retornado

TRUE se a variável de animação estiver contida no objeto de animação; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método pode ser usado para determinar se uma variável de animação especificada por pVariable está contida dentro de um objeto de animação. Um objeto de animação, dependendo do seu tipo, pode conter várias variáveis de animação. Por exemplo, CAnimationColor contém três variáveis, uma para cada componente de cor (vermelho, verde e azul). Quando um valor de variável de animação foi alterado, a API do Windows Animation envia eventos ValueChanged ou IntegerValueChanged (se ativado), e o parâmetro deste evento é um ponteiro para interface IUIAnimationVariable da variável animação. Este método ajuda a obter um ponteiro para animação de um ponteiro para conter objeto COM.

## <a name="canimationbaseobjectcreatetransitions"></a><a name="createtransitions"></a>CAnimationBaseObject::CreateTransitions

Cria transições associadas a um objeto de animação.

```
BOOL CreateTransitions();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se as transições foram criadas com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Loops sobre a lista de variáveis de animação encapsuladas em um objeto de animação derivado e cria transições associadas a cada variável de animação.

## <a name="canimationbaseobjectdetachfromcontroller"></a><a name="detachfromcontroller"></a>CAnimationBaseObject::DetachFromController

Destaca um objeto de animação do controlador de animação pai.

```cpp
void DetachFromController();
```

### <a name="remarks"></a>Comentários

Este método é usado internamente.

## <a name="canimationbaseobjectenableintegervaluechangedevent"></a><a name="enableintegervaluechangedevent"></a>CAnimationBaseObject::AtivarIntegerValueChangedEvent

Configura o manipulador de eventos Integer Value Changed.

```
virtual void EnableIntegerValueChangedEvent(
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para um controlador pai.

*Benable*<br/>
Especifica se habilita ou desativa o evento Integer Value Changed.

### <a name="remarks"></a>Comentários

Se o manipulador de evento Integer Value Changed estiver ativado, você poderá lidar com esse evento no método CAnimationController::OnAnimationIntegerValueChanged, que deve ser substituído em uma classe derivada do CAnimationController. Este método é chamado cada vez que o valor inteiro de animação é alterado.

## <a name="canimationbaseobjectenablevaluechangedevent"></a><a name="enablevaluechangedevent"></a>CAnimationBaseObject::Ativaralteraralteraçãodetempo

Configura o manipulador de eventos Alterado de valor.

```
virtual void EnableValueChangedEvent(
    CAnimationController* pController,
    BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*pController*<br/>
Um ponteiro para um controlador pai.

*Benable*<br/>
Especifica se habilita ou desativa o evento Alterado de valor.

### <a name="remarks"></a>Comentários

Se o manipulador de evento Alterado de valor estiver habilitado, você poderá lidar com esse evento no método CAnimationController::OnAnimationValueChanged, que deve ser substituído em uma classe derivada do CAnimationController. Este método é chamado cada vez que o valor da animação é alterado.

## <a name="canimationbaseobjectgetanimationvariablelist"></a><a name="getanimationvariablelist"></a>CAnimationBaseObject::getAnimationVariableList

Coleta ponteiros para variáveis de animação contidas.

```
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*,
    CAnimationVariable*>& list) = 0;
```

### <a name="parameters"></a>Parâmetros

*list*<br/>
Uma lista que deve ser preenchida com variáveis de animação contidas em um objeto de animação.

### <a name="remarks"></a>Comentários

Este método virtual puro deve ser substituído em uma classe derivada. Um objeto de animação, dependendo do seu tipo, contém uma ou mais variáveis de animação. Por exemplo, CAnimationPoint contém duas variáveis, para coordenadas X e Y, respectivamente. A classe base CAnimationBaseObject implementa alguns métodos genéricos, que atuam em uma lista de variáveis de animação: ApplyTransitions, ClearTransitions, EnableValueChangedEvent, EnableIntegerValueChangedEvent. Esses métodos chamam GetAnimationVariableList, que é preenchido em uma classe derivada com variáveis de animação reais contidas em um determinado objeto de animação, em seguida, loop sobre a lista e executar as ações necessárias. Se você criar um objeto de animação personalizado, você deve adicionar para *listar* todas as variáveis de animação contidas nesse objeto.

## <a name="canimationbaseobjectgetautodestroytransitions"></a><a name="getautodestroytransitions"></a>CAnimationBaseObject::GetAutodestroyTransitions

Diz se a transição relacionada é destruída automaticamente.

```
BOOL GetAutodestroyTransitions() const;
```

### <a name="return-value"></a>Valor retornado

Se TRUE, transições relacionadas são destruídas automaticamente; se FALSO, objetos de transição devem ser desalocados por aplicativo de chamada.

### <a name="remarks"></a>Comentários

Por padrão, este sinalizador é VERDADEIRO. Defina este sinalizador somente se você alocar transição na pilha e/ou transições deve ser desalocado pelo aplicativo de chamada.

## <a name="canimationbaseobjectgetgroupid"></a><a name="getgroupid"></a>CAnimationBaseObject::getGroupID

Retorna o ID do grupo atual.

```
UINT32 GetGroupID() const;
```

### <a name="return-value"></a>Valor retornado

ID do grupo atual.

### <a name="remarks"></a>Comentários

Use este método para recuperar o ID do grupo. É 0 se o ID do grupo não tiver sido definido explicitamente na construtora ou com SetID.

## <a name="canimationbaseobjectgetobjectid"></a><a name="getobjectid"></a>CAnimationBaseObject::GetObjectID

Retorna o ID do objeto atual.

```
UINT32 GetObjectID() const;
```

### <a name="return-value"></a>Valor retornado

ID de objeto atual.

### <a name="remarks"></a>Comentários

Use este método para recuperar o ID do objeto. É 0 se o Object ID não tiver sido definido explicitamente no construtor ou com setID.

## <a name="canimationbaseobjectgetuserdata"></a><a name="getuserdata"></a>CAnimationBaseObject::getUserData

Retorna dados definidos pelo usuário.

```
DWORD GetUserData() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de dados personalizados.

### <a name="remarks"></a>Comentários

Chame este método para recuperar os dados personalizados em tempo de execução. O valor retornado será 0 se não for explicitamente inicializado na construtora ou com SetUserData.

## <a name="canimationbaseobjectm_bautodestroytransitions"></a><a name="m_bautodestroytransitions"></a>CAnimationBaseObject::m_bAutodestroyTransitions

Especifica se as transições relacionadas devem ser automaticamente destruídas.

```
BOOL m_bAutodestroyTransitions;
```

## <a name="canimationbaseobjectm_dwuserdata"></a><a name="m_dwuserdata"></a>CAnimationBaseObject::m_dwUserData

Armazena dados definidos pelo usuário.

```
DWORD m_dwUserData;
```

## <a name="canimationbaseobjectm_ngroupid"></a><a name="m_ngroupid"></a>CAnimationBaseObject::m_nGroupID

Especifica o ID de grupo do objeto de animação.

```
UINT32 m_nGroupID;
```

## <a name="canimationbaseobjectm_nobjectid"></a><a name="m_nobjectid"></a>CAnimationBaseObject::m_nObjectID

Especifica o ID do objeto de exibição.

```
UINT32 m_nObjectID;
```

## <a name="canimationbaseobjectm_pparentcontroller"></a><a name="m_pparentcontroller"></a>CAnimationBaseObject::m_pParentController

Um ponteiro para o controlador de animação pai.

```
CAnimationController* m_pParentController;
```

## <a name="canimationbaseobjectsetautodestroytransitions"></a><a name="setautodestroytransitions"></a>CAnimationBaseObject::SetAutodestroyTransitions

Define uma bandeira para destruir automaticamente as transições.

```cpp
void SetAutodestroyTransitions(BOOL bValue);
```

### <a name="parameters"></a>Parâmetros

*bValue*<br/>
Especifica o sinalizador de destruição automática.

### <a name="remarks"></a>Comentários

Defina este sinalizador somente se você alocar objetos de transição usando o operador novo. Se por algum motivo objetos de transição estiverem alocados na pilha, a bandeira de destruição automática deve ser FALSA. Por padrão, este sinalizador é VERDADEIRO.

## <a name="canimationbaseobjectsetid"></a><a name="setid"></a>CAnimationBaseObject::SetID

Define novas ids.

```cpp
void SetID(
    UINT32 nObjectID,
    UINT32 nGroupID = 0);
```

### <a name="parameters"></a>Parâmetros

*nObjectID*<br/>
Especifica novo ID de objeto.

*nGroupID*<br/>
Especifica o novo ID de grupo.

### <a name="remarks"></a>Comentários

Permite alterar o ID do objeto e o ID do grupo. Se o novo ID do grupo difere do ID atual, um objeto de animação será movido para outro grupo (um novo grupo será criado, se necessário).

## <a name="canimationbaseobjectsetparentanimationobjects"></a><a name="setparentanimationobjects"></a>CAnimationBaseObject::SetParentAnimationObjeto

Estabelece relação entre variáveis de animação, contidas em um objeto de animação, e seu contêiner.

```
virtual void SetParentAnimationObjects();
```

### <a name="remarks"></a>Comentários

Este ajudante pode ser usado para estabelecer uma relação entre variáveis de animação contidas em um objeto de animação e seu contêiner. Ele faz loop saque sobre variáveis de animação e define um ponteiro de volta para um objeto de animação pai para cada variável de animação. Na implementação atual, o relacionamento real é estabelecido em CAnimationBaseObject::ApplyTransitions, portanto, os ponteiros traseiros não são definidos até que você chame CAnimationGroup::Animate. Conhecer o relacionamento pode ser útil ao processar eventos e precisa obter um objeto de animação pai da CAnimationVariable. Use CAnimationVariable::GetParentAnimationObject.

## <a name="canimationbaseobjectsetuserdata"></a><a name="setuserdata"></a>CAnimationBaseObject::SetUserData

Define dados definidos pelo usuário.

```cpp
void SetUserData (DWORD dwUserData);
```

### <a name="parameters"></a>Parâmetros

*dwUserData*<br/>
Especifica os dados personalizados.

### <a name="remarks"></a>Comentários

Use este método para associar um dado personalizado a um objeto de animação. Esses dados podem ser recuperados posteriormente em tempo de execução pelo GetUserData.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
