---
title: Classe CAnimationBaseObject | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxanimationcontroller/CAnimationBaseObject
- CAnimationBaseObject
dev_langs:
- C++
helpviewer_keywords:
- CAnimationBaseObject class
ms.assetid: 76b25917-940e-4eba-940f-31d270702603
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: c714c78b7017ed314b30f64df4bfceb587226c15
ms.lasthandoff: 02/25/2017

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
|[CAnimationBaseObject:: ~ CAnimationBaseObject](#canimationbaseobject__~canimationbaseobject)|O destruidor. Chamado quando um objeto de animação está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationBaseObject::ApplyTransitions](#applytransitions)|Adiciona as transições ao storyboard com variável de animação encapsulado.|  
|[CAnimationBaseObject::ClearTransitions](#cleartransitions)|Remove todas as transições relacionadas.|  
|[CAnimationBaseObject::ContainsVariable](#containsvariable)|Determina se um objeto de animação contém uma variável de animação específico.|  
|[CAnimationBaseObject::CreateTransitions](#createtransitions)|Cria as transições associadas com um objeto de animação.|  
|[CAnimationBaseObject::DetachFromController](#detachfromcontroller)|Desconecta um objeto de animação do controlador de animação do pai.|  
|[CAnimationBaseObject::EnableIntegerValueChangedEvent](#enableintegervaluechangedevent)|Define o manipulador de eventos alterado do valor de inteiro.|  
|[CAnimationBaseObject::EnableValueChangedEvent](#enablevaluechangedevent)|Define o manipulador de eventos de valor alterado.|  
|[CAnimationBaseObject::GetAutodestroyTransitions](#getautodestroytransitions)|Informa se a transição relacionada são destruídos automaticamente.|  
|[CAnimationBaseObject::GetGroupID](#getgroupid)|Retorna a ID do grupo atual.|  
|[CAnimationBaseObject::GetObjectID](#getobjectid)|Retorna a ID do objeto atual.|  
|[CAnimationBaseObject::GetUserData](#getuserdata)|Retorna dados definidos pelo usuário.|  
|[CAnimationBaseObject::SetAutodestroyTransitions](#setautodestroytransitions)|Define um sinalizador que classifica automaticamente destruir transições.|  
|[CAnimationBaseObject::SetID](#setid)|Define novas IDs.|  
|[CAnimationBaseObject::SetUserData](#setuserdata)|Define os dados definidos pelo usuário.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationBaseObject::GetAnimationVariableList](#getanimationvariablelist)|Coleta ponteiros para variáveis de animação independente.|  
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
 Essa classe implementa os métodos básicos para todos os objetos de animação. Um objeto de animação pode representar um valor, o ponto, o tamanho, o retângulo ou a cor em um aplicativo, bem como qualquer entidade personalizada. Objetos de animação são armazenados nos grupos de animação (consulte CAnimationGroup). Cada grupo pode ser animado separadamente e pode ser tratado como um análogo do storyboard. Um objeto de animação encapsula uma ou mais animação variáveis (consulte CAnimationVariable), dependendo de sua representação lógica. Por exemplo, CAnimationRect contém quatro variáveis de animação - uma variável para cada lado do retângulo. Cada classe de objeto de animação expõe um método sobrecarregado AddTransition, que deve ser usado para aplicar transições a animação encapsulado variáveis. Um objeto de animação pode ser identificado pelo ID de objeto (opcionalmente) e por ID de grupo. Uma ID de grupo é necessária para colocar um objeto de animação para o grupo correto, mas se uma ID de grupo não for especificada, um objeto é colocado no grupo padrão com ID 0. Se você chamar SetID com GroupID diferente, um objeto de animação será movido para outro grupo (um novo grupo é criado se necessário).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CAnimationBaseObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-namedtorcanimationbaseobjecta--canimationbaseobjectcanimationbaseobject"></a><a name="_dtorcanimationbaseobject"></a>CAnimationBaseObject:: ~ CAnimationBaseObject  
 O destruidor. Chamado quando um objeto de animação está sendo destruído.  
  
```  
virtual ~CAnimationBaseObject();
```  
  
##  <a name="a-nameapplytransitionsa--canimationbaseobjectapplytransitions"></a><a name="applytransitions"></a>CAnimationBaseObject::ApplyTransitions  
 Adiciona as transições ao storyboard com variável de animação encapsulado.  
  
```  
virtual BOOL ApplyTransitions(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDependOnKeyframes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDependOnKeyframes`  
 Com falso, este método adiciona apenas as transições que não dependem de quadros-chave.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se as transições foram adicionados com êxito.  
  
### <a name="remarks"></a>Comentários  
 Adiciona as transições relacionadas, que foram adicionadas com AddTransition (métodos sobrecarregados em classes derivadas), para executar o storyboard.  
  
##  <a name="a-namecanimationbaseobjecta--canimationbaseobjectcanimationbaseobject"></a><a name="canimationbaseobject"></a>CAnimationBaseObject::CAnimationBaseObject  
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
 Especifica a ID do objeto.  
  
 `dwUserData`  
 Definido pelo usuário dados, que podem ser associados ao objeto de animação e recuperados posteriormente em tempo de execução.  
  
### <a name="remarks"></a>Comentários  
 Constrói um objeto de animação e atribui a ID de objeto padrão (0) e a ID de grupo (0).  
  
##  <a name="a-namecleartransitionsa--canimationbaseobjectcleartransitions"></a><a name="cleartransitions"></a>CAnimationBaseObject::ClearTransitions  
 Remove todas as transições relacionadas.  
  
```  
virtual void ClearTransitions(BOOL bAutodestroy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAutodestroy`  
 Especifica se deve destruir objetos automaticamente ou apenas removê-los da lista relacionada.  
  
### <a name="remarks"></a>Comentários  
 Remove todas relacionadas transições e destrói-los se o sinalizador bAutodestroy ou m_bAutodestroyTransitions for verdadeiro. Transições devem ser destruídas automaticamente somente se eles não são alocados na pilha. Se os sinalizadores acima forem FALSE, transições apenas são removidas da lista interna de transições relacionadas.  
  
##  <a name="a-namecontainsvariablea--canimationbaseobjectcontainsvariable"></a><a name="containsvariable"></a>CAnimationBaseObject::ContainsVariable  
 Determina se um objeto de animação contém uma variável de animação específico.  
  
```  
virtual BOOL ContainsVariable(IUIAnimationVariable* pVariable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pVariable`  
 Um ponteiro para a variável de animação.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a variável de animação estiver contida no objeto de animação; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser usado para determinar se uma variável de animação especificada pela pVariable está contida dentro de um objeto de animação. Um objeto de animação, dependendo de seu tipo, pode conter várias variáveis de animação. Por exemplo, CAnimationColor contém três variáveis para cada componente de cor (vermelho, verde e azul). Quando um valor da variável de animação for alterado, a API de animação do Windows envia eventos ValueChanged ou IntegerValueChanged (se habilitado) e o parâmetro desse evento é um ponteiro para a interface IUIAnimationVariable da variável de animação. Este método ajuda a obter um ponteiro para a animação de um ponteiro para o objeto COM contido.  
  
##  <a name="a-namecreatetransitionsa--canimationbaseobjectcreatetransitions"></a><a name="createtransitions"></a>CAnimationBaseObject::CreateTransitions  
 Cria as transições associadas com um objeto de animação.  
  
```  
BOOL CreateTransitions();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se transições foram criadas com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Executa um loop pela lista de variáveis de animação encapsulado em um objeto derivado de animação e cria transições associadas a cada variável de animação.  
  
##  <a name="a-namedetachfromcontrollera--canimationbaseobjectdetachfromcontroller"></a><a name="detachfromcontroller"></a>CAnimationBaseObject::DetachFromController  
 Desconecta um objeto de animação do controlador de animação do pai.  
  
```  
void DetachFromController();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado internamente.  
  
##  <a name="a-nameenableintegervaluechangedeventa--canimationbaseobjectenableintegervaluechangedevent"></a><a name="enableintegervaluechangedevent"></a>CAnimationBaseObject::EnableIntegerValueChangedEvent  
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
 Se o manipulador de evento alterado do valor de inteiro é habilitado, você pode manipular esse evento no método CAnimationController::OnAnimationIntegerValueChanged, que deve ser substituído em uma classe derivada de CAnimationController. Esse método é chamado sempre que o valor de inteiro de animação foi alterado.  
  
##  <a name="a-nameenablevaluechangedeventa--canimationbaseobjectenablevaluechangedevent"></a><a name="enablevaluechangedevent"></a>CAnimationBaseObject::EnableValueChangedEvent  
 Define o manipulador de eventos de valor alterado.  
  
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
 Se o manipulador de eventos de valor alterado estiver habilitado, você pode manipular esse evento no método CAnimationController::OnAnimationValueChanged, que deve ser substituído em uma classe derivada de CAnimationController. Esse método é chamado sempre que o valor de animação foi alterado.  
  
##  <a name="a-namegetanimationvariablelista--canimationbaseobjectgetanimationvariablelist"></a><a name="getanimationvariablelist"></a>CAnimationBaseObject::GetAnimationVariableList  
 Coleta ponteiros para variáveis de animação independente.  
  
```  
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*, 
    CAnimationVariable*>& lst) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lst`  
 Uma lista que deve ser preenchida com variáveis de animação contidos em um objeto de animação.  
  
### <a name="remarks"></a>Comentários  
 Isso é um método virtual puro que deve ser substituído em uma classe derivada. Um objeto de animação, dependendo de seu tipo, contém uma ou mais variáveis de animação. Por exemplo, CAnimationPoint contém duas variáveis, para coordenadas X e Y respectivamente. A classe base CAnimationBaseObject implementa alguns métodos genéricos, que atuam em uma lista de variáveis de animação: ApplyTransitions, ClearTransitions, EnableValueChangedEvent, EnableIntegerValueChangedEvent. Esses métodos chamada GetAnimationVariableList, que é preenchido em uma classe derivada com variáveis de animação real contidas em um objeto de animação específico, e em seguida, um loop através da lista e executam as ações necessárias. Se você criar um objeto de animação personalizada, você deve adicionar a lst todas as variáveis de animação contidas nesse objeto.  
  
##  <a name="a-namegetautodestroytransitionsa--canimationbaseobjectgetautodestroytransitions"></a><a name="getautodestroytransitions"></a>CAnimationBaseObject::GetAutodestroyTransitions  
 Informa se a transição relacionada são destruídos automaticamente.  
  
```  
BOOL GetAutodestroyTransitions() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se TRUE, transições relacionadas são destruídas automaticamente. Se FALSE, objetos de transição devem ser desalocados chamando o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse sinalizador é TRUE. Defina esse sinalizador apenas se você alocado transição na pilha e/ou transições devem ser desalocadas pelo aplicativo de chamada.  
  
##  <a name="a-namegetgroupida--canimationbaseobjectgetgroupid"></a><a name="getgroupid"></a>CAnimationBaseObject::GetGroupID  
 Retorna a ID do grupo atual.  
  
```  
UINT32 GetGroupID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 ID do grupo atual.  
  
### <a name="remarks"></a>Comentários  
 Use este método para recuperar a ID do grupo. Ele está 0 se a ID do grupo não tiver sido definida explicitamente no construtor ou com SetID.  
  
##  <a name="a-namegetobjectida--canimationbaseobjectgetobjectid"></a><a name="getobjectid"></a>CAnimationBaseObject::GetObjectID  
 Retorna a ID do objeto atual.  
  
```  
UINT32 GetObjectID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 ID do objeto atual.  
  
### <a name="remarks"></a>Comentários  
 Use este método para recuperar a ID do objeto. Ele está 0 se a ID do objeto não tiver sido definida explicitamente no construtor ou com SetID.  
  
##  <a name="a-namegetuserdataa--canimationbaseobjectgetuserdata"></a><a name="getuserdata"></a>CAnimationBaseObject::GetUserData  
 Retorna dados definidos pelo usuário.  
  
```  
DWORD GetUserData() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de dados personalizados.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar os dados personalizados em tempo de execução. O valor retornado será 0 se ela não foi explicitamente inicializada no construtor ou com SetUserData.  
  
##  <a name="a-namembautodestroytransitionsa--canimationbaseobjectmbautodestroytransitions"></a><a name="m_bautodestroytransitions"></a>CAnimationBaseObject::m_bAutodestroyTransitions  
 Especifica se as transições relacionadas devem ser destruídas automaticamente.  
  
```  
BOOL m_bAutodestroyTransitions;  
```  
  
##  <a name="a-namemdwuserdataa--canimationbaseobjectmdwuserdata"></a><a name="m_dwuserdata"></a>CAnimationBaseObject::m_dwUserData  
 Armazena dados definidos pelo usuário.  
  
```  
DWORD m_dwUserData;  
```  
  
##  <a name="a-namemngroupida--canimationbaseobjectmngroupid"></a><a name="m_ngroupid"></a>CAnimationBaseObject::m_nGroupID  
 Especifica a ID do grupo do objeto de animação.  
  
```  
UINT32 m_nGroupID;  
```  
  
##  <a name="a-namemnobjectida--canimationbaseobjectmnobjectid"></a><a name="m_nobjectid"></a>CAnimationBaseObject::m_nObjectID  
 Especifica a ID de objeto do objeto de animação.  
  
```  
UINT32 m_nObjectID;  
```  
  
##  <a name="a-namempparentcontrollera--canimationbaseobjectmpparentcontroller"></a><a name="m_pparentcontroller"></a>CAnimationBaseObject::m_pParentController  
 Um ponteiro para o controlador de animação do pai.  
  
```  
CAnimationController* m_pParentController;  
```  
  
##  <a name="a-namesetautodestroytransitionsa--canimationbaseobjectsetautodestroytransitions"></a><a name="setautodestroytransitions"></a>CAnimationBaseObject::SetAutodestroyTransitions  
 Define um sinalizador que classifica automaticamente destruir transições.  
  
```  
void SetAutodestroyTransitions(BOOL bValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bValue`  
 Especifica o auto destruir o sinalizador.  
  
### <a name="remarks"></a>Comentários  
 Defina esse sinalizador apenas se você tiver atribuído objetos usando o operador novo. Se por algum motivo transição objetos são alocados na pilha, destruir o auto sinalizador deve ser FALSE. Por padrão, esse sinalizador é TRUE.  
  
##  <a name="a-namesetida--canimationbaseobjectsetid"></a><a name="setid"></a>CAnimationBaseObject::SetID  
 Define novas IDs.  
  
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
 Permite alterar a ID do objeto e a ID do grupo. Se a nova ID de grupo for diferente da ID do atual, um objeto de animação é movido para outro grupo (um novo grupo será criado, se necessário).  
  
##  <a name="a-namesetparentanimationobjectsa--canimationbaseobjectsetparentanimationobjects"></a><a name="setparentanimationobjects"></a>CAnimationBaseObject::SetParentAnimationObjects  
 Estabelece a relação entre as variáveis de animação, contidos em um objeto de animação e seus contêineres.  
  
```  
virtual void SetParentAnimationObjects();
```  
  
### <a name="remarks"></a>Comentários  
 Isso é um auxiliar que pode ser usado para estabelecer uma relação entre as variáveis de animação, contidos em um objeto de animação e seus contêineres. Ele faz um loop sobre variáveis de animação e define um ponteiro voltar a um objeto de animação pai para cada variável de animação. Na implementação atual que a relação real é estabelecida na CAnimationBaseObject::ApplyTransitions, portanto back ponteiros não estão definidos até que você chame CAnimationGroup::Animate. Saber a relação pode ser útil quando você precisa obter uma animação pai e eventos de processamento do objeto de CAnimationVariable (use CAnimationVariable::GetParentAnimationObject).  
  
##  <a name="a-namesetuserdataa--canimationbaseobjectsetuserdata"></a><a name="setuserdata"></a>CAnimationBaseObject::SetUserData  
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

