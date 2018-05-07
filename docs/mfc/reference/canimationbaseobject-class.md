---
title: Classe CAnimationBaseObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: db9f7a66b60d70231628ded5dc096bad702bf088
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="canimationbaseobject-class"></a>Classe CAnimationBaseObject
A classe base para todos os objetos de animação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationBaseObject : public CObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationBaseObject::CAnimationBaseObject](#canimationbaseobject)|Sobrecarregado. Constrói um objeto de animação.|  
|[CAnimationBaseObject:: ~ CAnimationBaseObject](#canimationbaseobject__~canimationbaseobject)|O destruidor. Chamado quando um objeto de animação está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationBaseObject::ApplyTransitions](#applytransitions)|Adiciona as transições para o storyboard com variável de animação encapsulada.|  
|[CAnimationBaseObject::ClearTransitions](#cleartransitions)|Remove todas as transições relacionadas.|  
|[CAnimationBaseObject::ContainsVariable](#containsvariable)|Determina se um objeto de animação contém uma variável específica de animação.|  
|[CAnimationBaseObject::CreateTransitions](#createtransitions)|Cria as transições associadas com um objeto de animação.|  
|[CAnimationBaseObject::DetachFromController](#detachfromcontroller)|Desanexa um objeto de animação do controlador de animação do pai.|  
|[CAnimationBaseObject::EnableIntegerValueChangedEvent](#enableintegervaluechangedevent)|Define o manipulador de eventos alterado do valor de inteiro.|  
|[CAnimationBaseObject::EnableValueChangedEvent](#enablevaluechangedevent)|Define o valor alterado o manipulador de eventos.|  
|[CAnimationBaseObject::GetAutodestroyTransitions](#getautodestroytransitions)|Indica se a transição relacionada serão destruídos automaticamente.|  
|[CAnimationBaseObject::GetGroupID](#getgroupid)|Retorna a ID do grupo atual.|  
|[CAnimationBaseObject::GetObjectID](#getobjectid)|Retorna a ID do objeto atual.|  
|[CAnimationBaseObject::GetUserData](#getuserdata)|Retorna os dados definidos pelo usuário.|  
|[CAnimationBaseObject::SetAutodestroyTransitions](#setautodestroytransitions)|Define um sinalizador que classifica automaticamente destruir transições.|  
|[CAnimationBaseObject::SetID](#setid)|Define as IDs de novo.|  
|[CAnimationBaseObject::SetUserData](#setuserdata)|Define os dados definidos pelo usuário.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationBaseObject::GetAnimationVariableList](#getanimationvariablelist)|Coleta ponteiros para variáveis independentes de animação.|  
|[CAnimationBaseObject::SetParentAnimationObjects](#setparentanimationobjects)|Estabelece a relação entre as variáveis de animação, contidos em um objeto de animação e seus contêineres.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationBaseObject::m_bAutodestroyTransitions](#m_bautodestroytransitions)|Especifica se as transições relacionadas devem ser destruídas automaticamente.|  
|[CAnimationBaseObject::m_dwUserData](#m_dwuserdata)|Armazena dados definidos pelo usuário.|  
|[CAnimationBaseObject::m_nGroupID](#m_ngroupid)|Especifica a ID do grupo do objeto de animação.|  
|[CAnimationBaseObject::m_nObjectID](#m_nobjectid)|Especifica a ID de objeto do objeto de animação.|  
|[CAnimationBaseObject::m_pParentController](#m_pparentcontroller)|Um ponteiro para o controlador de animação do pai.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe implementa os métodos básicos para todos os objetos de animação. Um objeto de animação pode representar um valor, a ponto, o tamanho, o retângulo ou a cor em um aplicativo, bem como qualquer entidade personalizada. Animação são armazenados em grupos de animação (consulte CAnimationGroup). Cada grupo pode ser animado separadamente e pode ser tratado como um análogo de storyboard. Um objeto de animação encapsula uma ou mais animação variáveis (consulte CAnimationVariable), dependendo de sua representação lógica. Por exemplo, CAnimationRect contém quatro variáveis de animação - uma variável para cada lado do retângulo. Cada classe de objeto de animação expõe um método sobrecarregado AddTransition, que deve ser usado para aplicar transições a animação encapsulada variáveis. Um objeto de animação pode ser identificado por ID de objeto (opcionalmente) e por ID de grupo. Uma ID de grupo é necessária para colocar um objeto de animação para o grupo correto, mas se uma ID de grupo não for especificada, um objeto é colocado no grupo padrão com a ID 0. Se você chamar SetID com GroupID diferente, um objeto de animação será movido para outro grupo (um novo grupo é criado se necessário).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CAnimationBaseObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="_dtorcanimationbaseobject"></a>  CAnimationBaseObject:: ~ CAnimationBaseObject  
 O destruidor. Chamado quando um objeto de animação está sendo destruído.  
  
```  
virtual ~CAnimationBaseObject();
```  
  
##  <a name="applytransitions"></a>  CAnimationBaseObject::ApplyTransitions  
 Adiciona as transições para o storyboard com variável de animação encapsulada.  
  
```  
virtual BOOL ApplyTransitions(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDependOnKeyframes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDependOnKeyframes`  
 Com falso, este método adiciona somente as transições que não dependem de quadros-chave.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se transições foram adicionadas com êxito.  
  
### <a name="remarks"></a>Comentários  
 Adiciona as transições relacionadas, que foram adicionadas com AddTransition (métodos sobrecarregados em classes derivadas), para o storyboard.  
  
##  <a name="canimationbaseobject"></a>  CAnimationBaseObject::CAnimationBaseObject  
 Constrói um objeto de animação.  
  
```  
CAnimationBaseObject();

 
CAnimationBaseObject(
    UINT32 nGroupID,  
    UINT32 nObjectID = (UINT32)-1,  
    DWORD dwUserData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `nObjectID`  
 Especifica a ID de objeto.  
  
 `dwUserData`  
 Dados definido pelo usuário, que podem ser associados com o objeto de animação e recuperados posteriormente em tempo de execução.  
  
### <a name="remarks"></a>Comentários  
 Constrói um objeto de animação e atribui a ID de objeto padrão (0) e a ID de grupo (0).  
  
##  <a name="cleartransitions"></a>  CAnimationBaseObject::ClearTransitions  
 Remove todas as transições relacionadas.  
  
```  
virtual void ClearTransitions(BOOL bAutodestroy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAutodestroy`  
 Especifica se deseja destruir os objetos automaticamente, ou apenas removê-los da lista relacionada.  
  
### <a name="remarks"></a>Comentários  
 Remove todas relacionadas transições e destrói-los, se o sinalizador bAutodestroy ou m_bAutodestroyTransitions for TRUE. Transições devem ser destruídas automaticamente somente se eles não estão alocados na pilha. Se os sinalizadores acima forem FALSO, as transições apenas são removidas da lista interna de transições relacionadas.  
  
##  <a name="containsvariable"></a>  CAnimationBaseObject::ContainsVariable  
 Determina se um objeto de animação contém uma variável específica de animação.  
  
```  
virtual BOOL ContainsVariable(IUIAnimationVariable* pVariable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pVariable`  
 Um ponteiro para a variável de animação.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a variável de animação está contida no objeto de animação; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser usado para determinar se uma variável de animação especificada pela pVariable está contida dentro de um objeto de animação. Um objeto de animação, dependendo de seu tipo, pode conter diversas variáveis de animação. Por exemplo, CAnimationColor contém três variáveis para cada componente de cor (vermelho, verde e azul). Quando um valor da variável de animação é alterado, a API de animação do Windows envia eventos ValueChanged ou IntegerValueChanged (se habilitado) e o parâmetro desse evento é um ponteiro para a interface IUIAnimationVariable da variável de animação. Este método ajuda a obter um ponteiro para a animação de um ponteiro para objeto COM contido.  
  
##  <a name="createtransitions"></a>  CAnimationBaseObject::CreateTransitions  
 Cria as transições associadas com um objeto de animação.  
  
```  
BOOL CreateTransitions();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se transições foram criadas com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Executa um loop pela lista de variáveis de animação encapsulado em um objeto derivado de animação e cria as transições associadas a cada variável de animação.  
  
##  <a name="detachfromcontroller"></a>  CAnimationBaseObject::DetachFromController  
 Desanexa um objeto de animação do controlador de animação do pai.  
  
```  
void DetachFromController();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado internamente.  
  
##  <a name="enableintegervaluechangedevent"></a>  CAnimationBaseObject::EnableIntegerValueChangedEvent  
 Define o manipulador de eventos alterado do valor de inteiro.  
  
```  
virtual void EnableIntegerValueChangedEvent(
    CAnimationController* pController,  
    BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pController`  
 Um ponteiro para um controlador de pai.  
  
 `bEnable`  
 Especifica se deseja habilitar ou desabilitar o evento alterado do valor de inteiro.  
  
### <a name="remarks"></a>Comentários  
 Se o manipulador de evento alterado do valor de inteiro estiver habilitado, você pode manipular esse evento no método CAnimationController::OnAnimationIntegerValueChanged, que deve ser substituído em uma classe derivada de CAnimationController. Esse método é chamado sempre que o valor de inteiro de animação é alterado.  
  
##  <a name="enablevaluechangedevent"></a>  CAnimationBaseObject::EnableValueChangedEvent  
 Define o valor alterado o manipulador de eventos.  
  
```  
virtual void EnableValueChangedEvent(
    CAnimationController* pController,  
    BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pController`  
 Um ponteiro para um controlador de pai.  
  
 `bEnable`  
 Especifica se deseja habilitar ou desabilitar o evento alterado do valor.  
  
### <a name="remarks"></a>Comentários  
 Se o manipulador de eventos de valor alterado estiver habilitado, você pode manipular esse evento no método CAnimationController::OnAnimationValueChanged, que deve ser substituído em uma classe derivada de CAnimationController. Esse método é chamado sempre que o valor de animação é alterado.  
  
##  <a name="getanimationvariablelist"></a>  CAnimationBaseObject::GetAnimationVariableList  
 Coleta ponteiros para variáveis independentes de animação.  
  
```  
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*, 
    CAnimationVariable*>& lst) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lst`  
 Uma lista que deve ser preenchida com variáveis de animação contidos em um objeto de animação.  
  
### <a name="remarks"></a>Comentários  
 Este é um método virtual puro que deve ser substituído em uma classe derivada. Um objeto de animação, dependendo de seu tipo, contém uma ou mais variáveis de animação. Por exemplo, CAnimationPoint contém duas variáveis, para coordenadas X e Y respectivamente. A classe base CAnimationBaseObject implementa alguns métodos genéricos, que atuam em uma lista de variáveis de animação: ApplyTransitions, ClearTransitions, EnableValueChangedEvent, EnableIntegerValueChangedEvent. Esses métodos chamar GetAnimationVariableList, que é preenchida em uma classe derivada com variáveis de animação real contidas em um objeto de animação específico, em seguida, loop sobre a lista e executam as ações necessárias. Se você criar um objeto de animação personalizada, você deve adicionar a lst todas as variáveis de animação contidas nesse objeto.  
  
##  <a name="getautodestroytransitions"></a>  CAnimationBaseObject::GetAutodestroyTransitions  
 Indica se a transição relacionada serão destruídos automaticamente.  
  
```  
BOOL GetAutodestroyTransitions() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for TRUE, as transições relacionadas serão destruídas automaticamente. Se for FALSE, objetos de transição devem ser desalocados pelo aplicativo de chamada.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse sinalizador é TRUE. Defina esse sinalizador somente se você alocado transição na pilha de e/ou transições devem ser desalocadas pelo aplicativo de chamada.  
  
##  <a name="getgroupid"></a>  CAnimationBaseObject::GetGroupID  
 Retorna a ID do grupo atual.  
  
```  
UINT32 GetGroupID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 ID do grupo atual.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para recuperar a ID do grupo. Ele 's 0 se a ID do grupo não foi definida explicitamente no construtor ou com SetID.  
  
##  <a name="getobjectid"></a>  CAnimationBaseObject::GetObjectID  
 Retorna a ID do objeto atual.  
  
```  
UINT32 GetObjectID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 ID do objeto atual.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para recuperar a ID de objeto. Ele 's 0 se a ID de objeto não foi definida explicitamente no construtor ou com SetID.  
  
##  <a name="getuserdata"></a>  CAnimationBaseObject::GetUserData  
 Retorna os dados definidos pelo usuário.  
  
```  
DWORD GetUserData() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de dados personalizados.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para recuperar os dados personalizados em tempo de execução. O valor retornado será 0 se ela não foi explicitamente inicializada no construtor ou com SetUserData.  
  
##  <a name="m_bautodestroytransitions"></a>  CAnimationBaseObject::m_bAutodestroyTransitions  
 Especifica se as transições relacionadas devem ser destruídas automaticamente.  
  
```  
BOOL m_bAutodestroyTransitions;  
```  
  
##  <a name="m_dwuserdata"></a>  CAnimationBaseObject::m_dwUserData  
 Armazena dados definidos pelo usuário.  
  
```  
DWORD m_dwUserData;  
```  
  
##  <a name="m_ngroupid"></a>  CAnimationBaseObject::m_nGroupID  
 Especifica a ID do grupo do objeto de animação.  
  
```  
UINT32 m_nGroupID;  
```  
  
##  <a name="m_nobjectid"></a>  CAnimationBaseObject::m_nObjectID  
 Especifica a ID de objeto do objeto de animação.  
  
```  
UINT32 m_nObjectID;  
```  
  
##  <a name="m_pparentcontroller"></a>  CAnimationBaseObject::m_pParentController  
 Um ponteiro para o controlador de animação do pai.  
  
```  
CAnimationController* m_pParentController;  
```  
  
##  <a name="setautodestroytransitions"></a>  CAnimationBaseObject::SetAutodestroyTransitions  
 Define um sinalizador que classifica automaticamente destruir transições.  
  
```  
void SetAutodestroyTransitions(BOOL bValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bValue`  
 Especifica o auto destruir o sinalizador.  
  
### <a name="remarks"></a>Comentários  
 Defina esse sinalizador somente se você tiver atribuído objetos usando o operador novo. Se por algum motivo transição objetos são alocados na pilha, destruir o auto sinalizador deve ser FALSE. Por padrão, esse sinalizador é TRUE.  
  
##  <a name="setid"></a>  CAnimationBaseObject::SetID  
 Define as IDs de novo.  
  
```  
void SetID(
    UINT32 nObjectID,  
    UINT32 nGroupID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nObjectID`  
 Especifica a nova ID de objeto.  
  
 `nGroupID`  
 Especifica a nova ID de grupo.  
  
### <a name="remarks"></a>Comentários  
 Permite alterar a ID do objeto e a ID do grupo. Se a nova ID de grupo é diferente da ID da atual, um objeto de animação é movido para outro grupo (um novo grupo será criado, se necessário).  
  
##  <a name="setparentanimationobjects"></a>  CAnimationBaseObject::SetParentAnimationObjects  
 Estabelece a relação entre as variáveis de animação, contidos em um objeto de animação e seus contêineres.  
  
```  
virtual void SetParentAnimationObjects();
```  
  
### <a name="remarks"></a>Comentários  
 Este é um auxiliar que pode ser usado para estabelecer uma relação entre as variáveis de animação, contidos em um objeto de animação e seus contêineres. Ele executa um loop sobre as variáveis de animação e define um ponteiro voltar a um objeto de animação pai para cada variável de animação. Na implementação atual que a relação real é estabelecida CAnimationBaseObject::ApplyTransitions, portanto ponteiros back não estão definidos até que você chame CAnimationGroup::Animate. Saber a relação pode ser útil quando você processar eventos e da necessidade de obter uma animação do pai do objeto de CAnimationVariable (use CAnimationVariable::GetParentAnimationObject).  
  
##  <a name="setuserdata"></a>  CAnimationBaseObject::SetUserData  
 Define os dados definidos pelo usuário.  
  
```  
void SetUserData (DWORD dwUserData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwUserData`  
 Especifica os dados personalizados.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para associar dados personalizados um objeto de animação. Esses dados podem ser recuperados posteriormente em tempo de execução por GetUserData.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
