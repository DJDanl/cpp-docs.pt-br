---
title: Classe CDacl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CDacl
- ATLSECURITY/ATL::CDacl
- ATLSECURITY/ATL::CDacl::CDacl
- ATLSECURITY/ATL::CDacl::AddAllowedAce
- ATLSECURITY/ATL::CDacl::AddDeniedAce
- ATLSECURITY/ATL::CDacl::GetAceCount
- ATLSECURITY/ATL::CDacl::RemoveAce
- ATLSECURITY/ATL::CDacl::RemoveAllAces
dev_langs:
- C++
helpviewer_keywords:
- CDacl class
ms.assetid: 2dc76616-6362-4967-b6cf-e2d39ca37ddd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2724eebd218cea2795d483351ef91b34c9f1bf39
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32364764"
---
# <a name="cdacl-class"></a>Classe CDacl
Essa classe é um wrapper para uma estrutura DACL (lista de controle de acesso discricionário).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CDacl : public CAcl
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDacl::CDacl](#cdacl)|O construtor.|  
|[CDacl:: ~ CDacl](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDacl::AddAllowedAce](#addallowedace)|Adiciona um permitido ACE (entrada de controle de acesso) para o `CDacl` objeto.|  
|[CDacl::AddDeniedAce](#adddeniedace)|Adiciona uma ACE negada para o `CDacl` objeto.|  
|[CDacl::GetAceCount](#getacecount)|Retorna o número de ACEs (entradas de controle de acesso) de `CDacl` objeto.|  
|[CDacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) de `CDacl` objeto.|  
|[CDacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas o `CDacl` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDacl::operator =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 Descritor de segurança de um objeto pode conter uma DACL. Uma DACL contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Se uma DACL está vazia (ou seja, ele contém zero ACEs), nenhum acesso é concedido explicitamente, para que o acesso é negado implicitamente. No entanto, se o descritor de segurança de um objeto não tiver uma DACL, o objeto é desprotegido e todos têm acesso completo.  
  
 Para recuperar a DACL de um objeto, você deve ser o proprietário do objeto ou READ_CONTROL acessem o objeto. Para alterar a DACL de um objeto, você deve ter acesso WRITE_DAC ao objeto.  
  
 Use os métodos da classe fornecidos para criar, adicionar, remover e excluir as ACEs do `CDacl` objeto. Consulte também [AtlGetDacl](security-global-functions.md#atlgetdacl) e [AtlSetDacl](security-global-functions.md#atlsetdacl).  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no SDK do Windows.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAcl](../../atl/reference/cacl-class.md)  
  
 `CDacl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
##  <a name="addallowedace"></a>  CDacl::AddAllowedAce  
 Adiciona um permitido ACE (entrada de controle de acesso) para o `CDacl` objeto.  
  
```
bool AddAllowedAce(  
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags = 0) throw(...);

bool AddAllowedAce(  
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags,
    const GUID* pObjectType,
    const GUID* pInheritedObjectType) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 Um [CSid](../../atl/reference/csid-class.md) objeto.  
  
 `AccessMask`  
 Especifica a máscara de direitos de acesso a serem permitidos especificado `CSid` objeto.  
  
 `AceFlags`  
 Um conjunto de sinalizadores de bit que controlam a herança de ACE.  
  
 `pObjectType`  
 O tipo de objeto.  
  
 `pInheritedObjectType`  
 O tipo de objeto herdado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a ACE é adicionada a `CDacl` objeto, **false** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Este método adiciona uma ACE que permite acessar o `CDacl` objeto.  
  
 Consulte [ACE_HEADER](http://msdn.microsoft.com/library/windows/desktop/aa374919) para obter uma descrição dos vários sinalizadores que pode ser definida no `AceFlags` parâmetro.  
  
##  <a name="adddeniedace"></a>  CDacl::AddDeniedAce  
 Adiciona uma negado ACE (entrada de controle de acesso) para o `CDacl` objeto.  
  
```
bool AddDeniedAce(  
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags = 0) throw(...);

bool AddDeniedAce(
    const CSid& rSid,
    ACCESS_MASK AccessMask,
    BYTE AceFlags,
    const GUID* pObjectType,
    const GUID* pInheritedObjectType) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 Um objeto `CSid`.  
  
 `AccessMask`  
 Especifica a máscara de direitos de acesso ser negado especificado `CSid` objeto.  
  
 `AceFlags`  
 Um conjunto de sinalizadores de bit que controlam a herança de ACE. O padrão é 0 na primeira forma do método.  
  
 `pObjectType`  
 O tipo de objeto.  
  
 `pInheritedObjectType`  
 O tipo de objeto herdado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a ACE é adicionada a `CDacl` objeto, **false** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Este método adiciona uma ACE que nega o acesso para o `CDacl` objeto.  
  
 Consulte [ACE_HEADER](http://msdn.microsoft.com/library/windows/desktop/aa374919) para obter uma descrição dos vários sinalizadores que pode ser definida no `AceFlags` parâmetro.  
  
##  <a name="cdacl"></a>  CDacl::CDacl  
 O construtor.  
  
```
CDacl (const ACL& rhs) throw(...);  
CDacl () throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 Um existente **ACL** estrutura (lista de controle de acesso).  
  
### <a name="remarks"></a>Comentários  
 O `CDacl` objeto pode ser opcionalmente criado usando uma existente **ACL** estrutura. É importante observar que somente uma DACL (lista de controle de acesso discricionário), e não um SACL (lista de controle de acesso do sistema), devem ser passados como esse parâmetro. Em compilações de depuração, passar um SACL fará com que uma declaração. Nas compilações de lançamento, passar um SACL fará com que as ACEs (entradas de controle de acesso) na ACL a ser ignorado e nenhum erro ocorrerá.  
  
##  <a name="dtor"></a>  CDacl::~CDacl  
 O destruidor.  
  
```
~CDacl () throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as ACEs (entradas de controle de acesso) usando [CDacl::RemoveAllAces](#removeallaces).  
  
##  <a name="getacecount"></a>  CDacl::GetAceCount  
 Retorna o número de ACEs (entradas de controle de acesso) de `CDacl` objeto.  
  
```
UINT GetAceCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de ACEs contidas o `CDacl` objeto.  
  
##  <a name="operator_eq"></a>  CDacl::operator =  
 Operador de atribuição.  
  
```
CDacl& operator= (const ACL& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 A ACL (lista de controle de acesso) para atribuir o objeto existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a atualização `CDacl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que você passe uma DACL (lista de controle de acesso discricionário) para esta função. Passando um SACL (lista de controle de acesso do sistema) para esta função causará uma declaração em compilações de depuração, mas não fará com que nenhum erro nas compilações de lançamento.  
  
##  <a name="removeace"></a>  CDacl::RemoveAce  
 Remove uma ACE específica (entrada de controle de acesso) de `CDacl` objeto.  
  
```
void RemoveAce(UINT nIndex) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice para a entrada ACE a remover.  
  
### <a name="remarks"></a>Comentários  
 Esse método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).  
  
##  <a name="removeallaces"></a>  CDacl::RemoveAllAces  
 Remove todas as ACEs (entradas de controle de acesso) contidas no `CDacl` objeto.  
  
```
void RemoveAllAces() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Remove cada **ACE** estrutura (entrada de controle de acesso) (se houver) no `CDacl` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de segurança](../../visual-cpp-samples.md)   
 [Classe CAcl](../../atl/reference/cacl-class.md)   
 [ACLs](http://msdn.microsoft.com/library/windows/desktop/aa374872)   
 [ACEs](http://msdn.microsoft.com/library/windows/desktop/aa374868)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)
