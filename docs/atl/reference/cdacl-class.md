---
title: Classe CDacl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CDacl
- CDacl
- ATL.CDacl
dev_langs:
- C++
helpviewer_keywords:
- CDacl class
ms.assetid: 2dc76616-6362-4967-b6cf-e2d39ca37ddd
caps.latest.revision: 23
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
ms.openlocfilehash: bb418919c26e3c0054a151b859cdf3f31c5d73a8
ms.lasthandoff: 02/25/2017

---
# <a name="cdacl-class"></a>Classe CDacl
Essa classe é um wrapper para uma estrutura DACL (lista de controle de acesso discricionário).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CDacl : public CAcl
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDacl::CDacl](#cdacl)|O construtor.|  
|[CDacl:: ~ CDacl](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDacl::AddAllowedAce](#addallowedace)|Adiciona uma permitidos ACE (entrada de controle de acesso) para o `CDacl` objeto.|  
|[CDacl::AddDeniedAce](#adddeniedace)|Adiciona uma ACE negada para o `CDacl` objeto.|  
|[CDacl::GetAceCount](#getacecount)|Retorna o número de ACEs (entradas de controle de acesso) de `CDacl` objeto.|  
|[CDacl::RemoveAce](#removeace)|Remove uma ACE específica (entrada de controle de acesso) de `CDacl` objeto.|  
|[CDacl::RemoveAllAces](#removeallaces)|Remove todas as ACEs contidas a `CDacl` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDacl::operator =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 Descritor de segurança de um objeto pode conter uma DACL. Uma DACL contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Se uma DACL está vazia (ou seja, ele contém zero ACEs), nenhum acesso é concedido explicitamente, portanto o acesso é negado implicitamente. No entanto, se o descritor de segurança de um objeto não tiver uma DACL, o objeto é desprotegido e todos têm acesso completo.  
  
 Para recuperar DACL um objeto, você deve ser o proprietário do objeto ou ter acesso READ_CONTROL ao objeto. Para alterar a DACL de um objeto, você deve ter acesso WRITE_DAC ao objeto.  
  
 Use os métodos da classe fornecidos para criar, adicionar, remover e excluir as ACEs do `CDacl` objeto. Consulte também [AtlGetDacl](http://msdn.microsoft.com/library/a0973648-0d46-4c1a-914f-bda861fe5d19) e [AtlSetDacl](http://msdn.microsoft.com/library/eb88ccb6-1f1b-444d-b0c9-8d5cd0dd6c0b).  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAcl](../../atl/reference/cacl-class.md)  
  
 `CDacl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="a-nameaddallowedacea--cdacladdallowedace"></a><a name="addallowedace"></a>CDacl::AddAllowedAce  
 Adiciona uma permitidos ACE (entrada de controle de acesso) para o `CDacl` objeto.  
  
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
 A [CSid](../../atl/reference/csid-class.md) objeto.  
  
 `AccessMask`  
 Especifica a máscara de direitos de acesso seja permitido especificado `CSid` objeto.  
  
 `AceFlags`  
 Um conjunto de sinalizadores de bit que controlam a herança de ACE.  
  
 `pObjectType`  
 O tipo de objeto.  
  
 `pInheritedObjectType`  
 O tipo de objeto herdado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a ACE é adicionada para o `CDacl` objeto, **false** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Este método adiciona uma ACE que permite acessar o `CDacl` objeto.  
  
> [!NOTE]
>  A segunda forma de `AddAllowedAce` só está disponível no Windows 2000 e versões posteriores.  
  
 Consulte [ACE_HEADER](http://msdn.microsoft.com/library/windows/desktop/aa374919) para obter uma descrição de vários sinalizadores que podem ser definidas a `AceFlags` parâmetro.  
  
##  <a name="a-nameadddeniedacea--cdacladddeniedace"></a><a name="adddeniedace"></a>CDacl::AddDeniedAce  
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
 Retorna **true** se a ACE é adicionada para o `CDacl` objeto, **false** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um `CDacl` objeto contém zero ou mais ACEs (entradas de controle de acesso) que identificam os usuários e grupos que podem acessar o objeto. Este método adiciona uma ACE que nega o acesso para o `CDacl` objeto.  
  
> [!NOTE]
>  A segunda forma de `AddDeniedAce` só está disponível no Windows 2000 e versões posteriores.  
  
 Consulte [ACE_HEADER](http://msdn.microsoft.com/library/windows/desktop/aa374919) para obter uma descrição de vários sinalizadores que podem ser definidas a `AceFlags` parâmetro.  
  
##  <a name="a-namecdacla--cdaclcdacl"></a><a name="cdacl"></a>CDacl::CDacl  
 O construtor.  
  
```
CDacl (const ACL& rhs) throw(...);  
CDacl () throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 Existente **ACL** estrutura (lista de controle de acesso).  
  
### <a name="remarks"></a>Comentários  
 O `CDacl` objeto pode ser criado se desejar usar um existente **ACL** estrutura. É importante observar que somente uma DACL (lista de controle de acesso discricionário), e não uma SACL (lista de controle de acesso do sistema), devem ser passados como esse parâmetro. Em compilações de depuração, passar uma SACL causará uma declaração. Em compilações de versão, passar uma SACL fará com que as ACEs (entradas de controle de acesso) na ACL sejam ignorados e nenhum erro ocorrerá.  
  
##  <a name="a-namedtora--cdaclcdacl"></a><a name="dtor"></a>CDacl:: ~ CDacl  
 O destruidor.  
  
```
~CDacl () throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos adquiridos pelo objeto, incluindo todas as ACEs (entradas de controle de acesso) usando [CDacl::RemoveAllAces](#removeallaces).  
  
##  <a name="a-namegetacecounta--cdaclgetacecount"></a><a name="getacecount"></a>CDacl::GetAceCount  
 Retorna o número de ACEs (entradas de controle de acesso) de `CDacl` objeto.  
  
```
UINT GetAceCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de ACEs contidas a `CDacl` objeto.  
  
##  <a name="a-nameoperatoreqa--cdacloperator-"></a><a name="operator_eq"></a>CDacl::operator =  
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
 Certifique-se de que você passe uma DACL (lista de controle de acesso discricionário) para essa função. Passando uma SACL (lista de controle de acesso do sistema) para essa função causará uma declaração em compilações de depuração, mas não fará com que nenhum erro em compilações de versão.  
  
##  <a name="a-nameremoveacea--cdaclremoveace"></a><a name="removeace"></a>CDacl::RemoveAce  
 Remove uma ACE específica (entrada de controle de acesso) de `CDacl` objeto.  
  
```
void RemoveAce(UINT nIndex) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice para a entrada ACE para remover.  
  
### <a name="remarks"></a>Comentários  
 Esse método é derivado de [CAtlArray::RemoveAt](../../atl/reference/catlarray-class.md#removeat).  
  
##  <a name="a-nameremoveallacesa--cdaclremoveallaces"></a><a name="removeallaces"></a>CDacl::RemoveAllAces  
 Remove todas as ACEs (entradas de controle de acesso) contidas no `CDacl` objeto.  
  
```
void RemoveAllAces() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Remove todos os **ACE** estrutura (entrada de controle de acesso) (se houver) no `CDacl` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de segurança](../../visual-cpp-samples.md)   
 [Classe CAcl](../../atl/reference/cacl-class.md)   
 [ACLs](http://msdn.microsoft.com/library/windows/desktop/aa374872)   
 [ACEs](http://msdn.microsoft.com/library/windows/desktop/aa374868)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)

