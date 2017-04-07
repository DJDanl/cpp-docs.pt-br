---
title: Classe CSacl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSacl
- ATLSECURITY/ATL::CSacl
- ATLSECURITY/ATL::CSacl::CSacl
- ATLSECURITY/ATL::CSacl::AddAuditAce
- ATLSECURITY/ATL::CSacl::GetAceCount
- ATLSECURITY/ATL::CSacl::RemoveAce
- ATLSECURITY/ATL::CSacl::RemoveAllAces
dev_langs:
- C++
helpviewer_keywords:
- CSacl class
ms.assetid: 8624889b-aebc-4183-9d29-a20f07837f05
caps.latest.revision: 22
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: bd9ef9932938cfe5ec65965b3a40116da7f43b90
ms.lasthandoff: 03/31/2017

---
# <a name="csacl-class"></a>Classe CSacl
Essa classe é um wrapper para uma estrutura SACL (lista de controle de acesso do sistema).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CSacl : public CAcl
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSacl::CSacl](#csacl)|O construtor.|  
|[CSacl:: ~ CSacl](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSacl::AddAuditAce](#addauditace)|Adiciona uma entrada de auditoria de controle de acesso (ACE) para o `CSacl` objeto.|  
|[CSacl::GetAceCount](#getacecount)|Retorna o número de entradas de controle de acesso (ACEs) a `CSacl` objeto.|  
|[CSacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) de **CSacl** objeto.|  
|[CSacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas o `CSacl` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSacl::operator =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 A SACL contém entradas de controle de acesso (ACEs) que especificam os tipos de tentativas de acesso que geram registros de auditoria no log de eventos de segurança do controlador de domínio. Observe que um SACL gera entradas de log somente no controlador de domínio em que ocorreu a tentativa de acesso, não em cada controlador de domínio que contém uma réplica do objeto.  
  
 Para definir ou recuperar SACL no descritor de segurança de um objeto, o privilégio SE_SECURITY_NAME deve ser habilitado no token de acesso do thread solicitante. O grupo Administradores tem esse privilégio concedido por padrão, e ele pode ser concedido a outros usuários ou grupos. Ter o privilégio concedido não é tudo o que é necessário: antes da operação definida pelo privilégio pode ser executada, o privilégio deve ser habilitado no token de acesso de segurança para ter efeito. O modelo permite privilégios para ser habilitado apenas para operações específicas do sistema e, em seguida, desabilitada quando eles não são mais necessários. Consulte [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl) para obter exemplos de como habilitar SE_SECURITY_NAME.  
  
 Use os métodos da classe fornecidos para adicionar, remover, criar e excluir as ACEs do **SACL** objeto. Consulte também [AtlGetSacl](security-global-functions.md#atlgetsacl) e [AtlSetSacl](security-global-functions.md#atlsetsacl).  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAcl](../../atl/reference/cacl-class.md)  
  
 `CSacl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
##  <a name="addauditace"></a>CSacl::AddAuditAce  
 Adiciona uma entrada de auditoria de controle de acesso (ACE) para o `CSacl` objeto.  
  
```
bool AddAuditAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    bool bSuccess,
    bool bFailure,
    BYTE AceFlags = 0) throw(...);

bool AddAuditAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    bool bSuccess,
    bool bFailure,
    BYTE AceFlags,
    const GUID* pObjectType,
    const GUID* pInheritedObjectType) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 O [CSid](../../atl/reference/csid-class.md) objeto.  
  
 `AccessMask`  
 Especifica a máscara de direitos de acesso a serem auditados especificado `CSid` objeto.  
  
 `bSuccess`  
 Especifica se as tentativas de acesso permitido a ser auditado. Defina esse sinalizador para verdadeiro para habilitar a auditoria; Caso contrário, defina-o como false.  
  
 *bFailure*  
 Especifica se as tentativas de acesso negado a serem auditados. Defina esse sinalizador para verdadeiro para habilitar a auditoria; Caso contrário, defina-o como false.  
  
 `AceFlags`  
 Um conjunto de sinalizadores de bit que controlam a herança de ACE.  
  
 `pObjectType`  
 O tipo de objeto.  
  
 `pInheritedObjectType`  
 O tipo de objeto herdado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a ACE é adicionada a `CSacl` objeto, **false** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um `CSacl` objeto contém entradas de controle de acesso (ACEs) que especificam os tipos de tentativas de acesso que geram registros de auditoria no log de eventos de segurança. Este método adiciona essa ACE para o `CSacl` objeto. A segunda forma de `AddAuditAce` só está disponível no Windows 2000 e posterior.  
  
 Consulte [ACE_HEADER](http://msdn.microsoft.com/library/windows/desktop/aa374919) para obter uma descrição dos vários sinalizadores que pode ser definida no `AceFlags` parâmetro.  
  
##  <a name="csacl"></a>CSacl::CSacl  
 O construtor.  
  
```
CSacl() throw();
CSacl(const ACL& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 Um existente **ACL** estrutura (lista de controle de acesso).  
  
### <a name="remarks"></a>Comentários  
 O `CSacl` objeto pode ser opcionalmente criado usando uma existente **ACL** estrutura. Certifique-se de que esse parâmetro é uma lista de controle de acesso do sistema (SACL) e não uma lista de controle de acesso discricionário (DACL). Em compilações de depuração, se uma DACL é fornecida uma asserção ocorrerá. Em compilações de versão, todas as entradas de uma DACL são ignoradas.  
  
##  <a name="dtor"></a>CSacl:: ~ CSacl  
 O destruidor.  
  
```
~CSacl() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as entradas de controle de acesso (ACEs).  
  
##  <a name="getacecount"></a>CSacl::GetAceCount  
 Retorna o número de entradas de controle de acesso (ACEs) a `CSacl` objeto.  
  
```
UINT GetAceCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de ACEs contidas o `CSacl` objeto.  
  
##  <a name="operator_eq"></a>CSacl::operator =  
 Operador de atribuição.  
  
```
CSacl& operator=(const ACL& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O **ACL** (lista de controle de acesso) para atribuir o objeto existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a atualização `CSacl` objeto. Certifique-se de que o **ACL** parâmetro é, na verdade, uma controle de acesso lista sistema (SACL) e não uma lista de controle de acesso discricionário (DACL). Em compilações de depuração, ocorrerá uma asserção e nas compilações de lançamento do **ACL** parâmetro será ignorado.  
  
##  <a name="removeace"></a>CSacl::RemoveAce  
 Remove uma ACE específica (entrada de controle de acesso) de **CSacl** objeto.  
  
```
void RemoveAce(UINT nIndex) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice para a entrada ACE a remover.  
  
### <a name="remarks"></a>Comentários  
 Esse método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).  
  
##  <a name="removeallaces"></a>CSacl::RemoveAllAces  
 Remove todas as entradas de controle de acesso (ACEs) contidas no `CSacl` objeto.  
  
```
void RemoveAllAces() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Remove cada **ACE** estrutura (se houver) no `CSacl` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAcl](../../atl/reference/cacl-class.md)   
 [ACLs](http://msdn.microsoft.com/library/windows/desktop/aa374872)   
 [ACEs](http://msdn.microsoft.com/library/windows/desktop/aa374868)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)

