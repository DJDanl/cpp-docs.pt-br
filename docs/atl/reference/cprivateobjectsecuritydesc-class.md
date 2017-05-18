---
title: Classe de CPrivateObjectSecurityDesc | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::ConvertToAutoInherit
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Create
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Get
- ATLSECURITY/ATL::CPrivateObjectSecurityDesc::Set
dev_langs:
- C++
helpviewer_keywords:
- CPrivateObjectSecurityDesc class
ms.assetid: 2c4bbb13-bf99-4833-912a-197f6815bb5d
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 154a4229f8963d3081e6e0518354d17968ee0e20
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cprivateobjectsecuritydesc-class"></a>Classe CPrivateObjectSecurityDesc
Essa classe representa um objeto de descritor de segurança do objeto privado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CPrivateObjectSecurityDesc : public CSecurityDesc
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc](#cprivateobjectsecuritydesc)|O construtor.|  
|[CPrivateObjectSecurityDesc:: ~ CPrivateObjectSecurityDesc](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrivateObjectSecurityDesc::ConvertToAutoInherit](#converttoautoinherit)|Chame esse método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) em um formato que oferece suporte a propagação automática de entradas de controle de acesso herdáveis (ACEs).|  
|[CPrivateObjectSecurityDesc::Create](#create)|Chame esse método para alocar e inicializar um descritor de segurança auto-relativa do objeto privado criados pelo Gerenciador de recursos de chamada.|  
|[CPrivateObjectSecurityDesc::Get](#get)|Chame esse método para recuperar informações do descritor de segurança de um objeto particular.|  
|[CPrivateObjectSecurityDesc::Set](#set)|Chame esse método para modificar o descritor de segurança de um objeto particular.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe derivada de [CSecurityDesc](../../atl/reference/csecuritydesc-class.md), fornece métodos para criar e gerenciar o descritor de segurança de um objeto particular.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CSecurityDesc](../../atl/reference/csecuritydesc-class.md)  
  
 `CPrivateObjectSecurityDesc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="converttoautoinherit"></a>CPrivateObjectSecurityDesc::ConvertToAutoInherit  
 Chame esse método para converter um descritor de segurança e suas listas de controle de acesso (ACLs) em um formato que oferece suporte a propagação automática de entradas de controle de acesso herdáveis (ACEs).  
  
```
bool ConvertToAutoInherit(  
    const CSecurityDesc* pParent,
    GUID* ObjectType,
    bool bIsDirectoryObject,
    PGENERIC_MAPPING GenericMapping) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParent`  
 Ponteiro para uma [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto referenciando o contêiner pai do objeto. Se não houver nenhum contêiner pai, este parâmetro é NULL.  
  
 `ObjectType`  
 Ponteiro para uma **GUID** estrutura que identifica o tipo de objeto associado ao objeto atual. Definir `ObjectType` como NULL se o objeto não tem um GUID.  
  
 `bIsDirectoryObject`  
 Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.  
  
 `GenericMapping`  
 Ponteiro para uma [GENERIC_MAPPING](http://msdn.microsoft.com/library/windows/desktop/aa446633) estrutura que especifica o mapeamento de cada direito genérico para direitos específicos para o objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método tenta determinar se as ACEs no controle de acesso discricionário (DACL) de lista e a lista de controle de acesso do sistema (SACL) do descritor de segurança atual foram herdadas do descritor de segurança do pai. Ele chama o [ConvertToAutoInheritPrivateObjectSecurity](http://msdn.microsoft.com/library/windows/desktop/aa376403) função.  
  
##  <a name="cprivateobjectsecuritydesc"></a>CPrivateObjectSecurityDesc::CPrivateObjectSecurityDesc  
 O construtor.  
  
```
CPrivateObjectSecurityDesc() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o objeto `CPrivateObjectSecurityDesc`.  
  
##  <a name="dtor"></a>CPrivateObjectSecurityDesc:: ~ CPrivateObjectSecurityDesc  
 O destruidor.  
  
```
~CPrivateObjectSecurityDesc() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos alocados e exclui o descritor de segurança do objeto privado.  
  
##  <a name="create"></a>CPrivateObjectSecurityDesc::Create  
 Chame esse método para alocar e inicializar um descritor de segurança auto-relativa do objeto privado criados pelo Gerenciador de recursos de chamada.  
  
```
bool Create(  
    const CSecurityDesc* pParent,
    const CSecurityDesc* pCreator,
    bool bIsDirectoryObject,
    const CAccessToken& Token,
    PGENERIC_MAPPING GenericMapping) throw();

bool Create(  
    const CSecurityDesc* pParent,
    const CSecurityDesc* pCreator,
    GUID* ObjectType,
    bool bIsContainerObject,
    ULONG AutoInheritFlags,
    const CAccessToken& Token,
    PGENERIC_MAPPING GenericMapping) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParent`  
 Ponteiro para uma [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto referenciando o diretório pai no qual um novo objeto é criado. Definido como NULL se não houver nenhuma pasta pai.  
  
 `pCreator`  
 Ponteiro para um descritor de segurança fornecido pelo criador do objeto. Se o criador do objeto não passar informações de segurança para o novo objeto explicitamente, defina este parâmetro como NULL.  
  
 `bIsDirectoryObject`  
 Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.  
  
 `Token`  
 Referência para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto para o processo do cliente em nome do qual o objeto está sendo criado.  
  
 `GenericMapping`  
 Ponteiro para uma [GENERIC_MAPPING](http://msdn.microsoft.com/library/windows/desktop/aa446633) estrutura que especifica o mapeamento de cada direito genérico para direitos específicos para o objeto.  
  
 `ObjectType`  
 Ponteiro para uma **GUID** estrutura que identifica o tipo de objeto associado ao objeto atual. Definir `ObjectType` como NULL se o objeto não tem um GUID.  
  
 *bIsContainerObject*  
 Especifica se o novo objeto pode conter outros objetos. Um valor true indica que o novo objeto é um contêiner. Um valor false indica que o novo objeto não é um contêiner.  
  
 `AutoInheritFlags`  
 Um conjunto de sinalizadores de bit que controlam como as entradas de controle de acesso (ACEs) são herdadas de `pParent`. Consulte [CreatePrivateObjectSecurityEx](http://msdn.microsoft.com/library/windows/desktop/aa446581) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama [CreatePrivateObjectSercurity](http://msdn.microsoft.com/library/windows/desktop/aa376405) ou [CreatePrivateObjectSecurityEx](http://msdn.microsoft.com/library/windows/desktop/aa446581).  
  
 O segundo método, que permite especificar o tipo de objeto GUID do novo objeto ou controlar como as ACEs são herdadas, só está disponível em sistemas que executam o Windows 2000 e versões posteriores.  
  
> [!NOTE]
>  Um descritor de segurança autorrelativo é um descritor de segurança que armazena todas as suas informações de segurança em um bloco contíguo de memória.  
  
##  <a name="get"></a>CPrivateObjectSecurityDesc::Get  
 Chame esse método para recuperar informações do descritor de segurança de um objeto particular.  
  
```
bool Get(  
    SECURITY_INFORMATION si,
    CSecurityDesc* pResult) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `si`  
 Um conjunto de sinalizadores de bit que indicam as partes do descritor de segurança para recuperar. Esse valor pode ser uma combinação da [SECURITY_INFORMATION](http://msdn.microsoft.com/library/windows/desktop/aa379573) sinalizadores de bit.  
  
 `pResult`  
 Ponteiro para uma [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto que recebe uma cópia das informações solicitadas do descritor de segurança especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O descritor de segurança é uma estrutura e dados associados que contém as informações de segurança para um objeto protegível.  
  
##  <a name="operator_eq"></a>CPrivateObjectSecurityDesc::operator =  
 Operador de atribuição.  
  
```
CPrivateObjectSecurityDesc& operator= (const CPrivateObjectSecurityDesc& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O `CPrivateObjectSecurityDesc` objeto para atribuir ao objeto atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CPrivateObjectSecurityDesc` objeto.  
  
##  <a name="set"></a>CPrivateObjectSecurityDesc::Set  
 Chame esse método para modificar o descritor de segurança de um objeto particular.  
  
```
bool Set(  
    SECURITY_INFORMATION si,
    const CSecurityDesc& Modification,
    PGENERIC_MAPPING GenericMapping,
    const CAccessToken& Token) throw();

bool Set(  
    SECURITY_INFORMATION si,
    const CSecurityDesc& Modification,
    ULONG AutoInheritFlags,
    PGENERIC_MAPPING GenericMapping,
    const CAccessToken& Token) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `si`  
 Um conjunto de sinalizadores de bit que indicam as partes do descritor de segurança para definir. Esse valor pode ser uma combinação da [SECURITY_INFORMATION](http://msdn.microsoft.com/library/windows/desktop/aa379573) sinalizadores de bit.  
  
 *Modificação*  
 Ponteiro para uma [CSecurityDesc](../../atl/reference/csecuritydesc-class.md) objeto. As partes desse descritor de segurança indicada pela `si` parâmetro são aplicadas ao descritor de segurança do objeto.  
  
 `GenericMapping`  
 Ponteiro para uma [GENERIC_MAPPING](http://msdn.microsoft.com/library/windows/desktop/aa446633) estrutura que especifica o mapeamento de cada direito genérico para direitos específicos para o objeto.  
  
 `Token`  
 Referência para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto para o processo do cliente em nome do qual o objeto está sendo criado.  
  
 `AutoInheritFlags`  
 Um conjunto de sinalizadores de bit que controlam como as entradas de controle de acesso (ACEs) são herdadas de `pParent`. Consulte [CreatePrivateObjectSecurityEx](http://msdn.microsoft.com/library/windows/desktop/aa446581) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O segundo método, que permite especificar o tipo de objeto GUID do objeto ou controlar como as ACEs são herdadas, só está disponível em sistemas que executam o Windows 2000 e versões posteriores.  
  
## <a name="see-also"></a>Consulte também  
 [SECURITY_DESCRIPTOR](http://msdn.microsoft.com/library/windows/desktop/aa379561)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)   
 [Classe CSecurityDesc](../../atl/reference/csecuritydesc-class.md)

