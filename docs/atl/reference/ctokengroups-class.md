---
title: Classe CTokenGroups | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CTokenGroups
- ATL.CTokenGroups
- CTokenGroups
dev_langs:
- C++
helpviewer_keywords:
- CTokenGroups class
ms.assetid: 2ab08076-4b08-4487-bc70-ec6dee304190
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
ms.openlocfilehash: 41b93e1c0a2e55013e280023a7f47610d38ddc10
ms.lasthandoff: 02/25/2017

---
# <a name="ctokengroups-class"></a>Classe CTokenGroups
Essa classe é um wrapper para o **TOKEN_GROUPS** estrutura.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CTokenGroups
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTokenGroups::CTokenGroups](#ctokengroups)|O construtor.|  
|[CTokenGroups:: ~ CTokenGroups](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTokenGroups::Add](#add)|Adiciona um `CSid` ou existentes **TOKEN_GROUPS** estrutura para o `CTokenGroups` objeto.|  
|[CTokenGroups::Delete](#delete)|Exclui um `CSid` e seus atributos associados a partir de `CTokenGroups` objeto.|  
|[CTokenGroups::DeleteAll](#deleteall)|Exclui todos os `CSid` objetos e seus atributos associados a partir de `CTokenGroups` objeto.|  
|[CTokenGroups::GetCount](#getcount)|Retorna o número de `CSid` objetos e atributos associados contidos a **CTokenGroups** objeto.|  
|[CTokenGroups::GetLength](#getlength)|Retorna o tamanho do `CTokenGroups` objeto.|  
|[CTokenGroups::GetPTOKEN_GROUPS](#getptoken_groups)|Recupera um ponteiro para o **TOKEN_GROUPS** estrutura.|  
|[CTokenGroups::GetSidsAndAttributes](#getsidsandattributes)|Recupera o `CSid` objetos e atributos de `CTokenGroups` objeto.|  
|[CTokenGroups::LookupSid](#lookupsid)|Recupera os atributos associados com um `CSid` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[TOKEN_GROUPS const CTokenGroups::operator *](#operator_const_token_groups__star)|Conversões de `CTokenGroups` objeto em um ponteiro para o **TOKEN_GROUPS** estrutura.|  
|[CTokenGroups::operator =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 Um [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou thread e alocado para cada usuário conectado em um sistema Windows NT ou Windows 2000.  
  
 O **CTokenGroups** classe é um wrapper para o [TOKEN_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) estrutura, que contém informações sobre os identificadores de segurança (SIDs) do grupo em um token de acesso.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="a-nameadda--ctokengroupsadd"></a><a name="add"></a>CTokenGroups::Add  
 Adiciona um `CSid` ou existentes **TOKEN_GROUPS** estrutura para o `CTokenGroups` objeto.  
  
```
void Add(const CSid& rSid, DWORD dwAttributes) throw(... );  
void Add(const TOKEN_GROUPS& rTokenGroups) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 A [CSid](../../atl/reference/csid-class.md) objeto.  
  
 `dwAttributes`  
 Os atributos para associar o `CSid` objeto.  
  
 *rTokenGroups*  
 A [TOKEN_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Esses métodos de adicionam um ou mais `CSid` objetos e seus atributos associados para o `CTokenGroups` objeto.  
  
##  <a name="a-namectokengroupsa--ctokengroupsctokengroups"></a><a name="ctokengroups"></a>CTokenGroups::CTokenGroups  
 O construtor.  
  
```
CTokenGroups() throw();
CTokenGroups(const CTokenGroups& rhs) throw(... );  
CTokenGroups(const TOKEN_GROUPS& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O `CTokenGroups` objeto ou [TOKEN_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) estrutura com a qual construir o `CTokenGroups` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CTokenGroups` objeto opcionalmente pode ser criado usando um **TOKEN_GROUPS** estrutura ou definido anteriormente `CTokenGroups` objeto.  
  
##  <a name="a-namedtora--ctokengroupsctokengroups"></a><a name="dtor"></a>CTokenGroups:: ~ CTokenGroups  
 O destruidor.  
  
```
virtual ~CTokenGroups() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos alocados.  
  
##  <a name="a-namedeletea--ctokengroupsdelete"></a><a name="delete"></a>CTokenGroups::Delete  
 Exclui um `CSid` e seus atributos associados a partir de `CTokenGroups` objeto.  
  
```
bool Delete(const CSid& rSid) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 O [CSid](../../atl/reference/csid-class.md) objeto para o qual o identificador de segurança (SID) e os atributos devem ser removidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o `CSid` for removido, FALSO caso contrário.  
  
##  <a name="a-namedeletealla--ctokengroupsdeleteall"></a><a name="deleteall"></a>CTokenGroups::DeleteAll  
 Exclui todos os `CSid` objetos e seus atributos associados a partir de `CTokenGroups` objeto.  
  
```
void DeleteAll() throw();
```  
  
##  <a name="a-namegetcounta--ctokengroupsgetcount"></a><a name="getcount"></a>CTokenGroups::GetCount  
 Retorna o número de `CSid` objetos contidos no `CTokenGroups`.  
  
```
UINT GetCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de [CSid](../../atl/reference/csid-class.md) objetos e seus atributos associados contidos a `CTokenGroups` objeto.  
  
##  <a name="a-namegetlengtha--ctokengroupsgetlength"></a><a name="getlength"></a>CTokenGroups::GetLength  
 Retorna o tamanho do **CTokenGroup** objeto.  
  
```
UINT GetLength() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna o tamanho total do **CTokenGroup** objeto, em bytes.  
  
##  <a name="a-namegetptokengroupsa--ctokengroupsgetptokengroups"></a><a name="getptoken_groups"></a>CTokenGroups::GetPTOKEN_GROUPS  
 Recupera um ponteiro para o **TOKEN_GROUPS** estrutura.  
  
```
const TOKEN_GROUPS* GetPTOKEN_GROUPS() const throw(...);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Recupera um ponteiro para o [TOKEN_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) estrutura pertencentes ao `CTokenGroups` objeto de token de acesso.  
  
##  <a name="a-namegetsidsandattributesa--ctokengroupsgetsidsandattributes"></a><a name="getsidsandattributes"></a>CTokenGroups::GetSidsAndAttributes  
 Recupera o `CSid` atributos que pertencem a objetos e (opcionalmente) o `CTokenGroups` objeto.  
  
```
void GetSidsAndAttributes(
    CSid::CSidArray* pSids,
    CAtlArray<DWORD>* pAttributes = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSids`  
 Ponteiro para uma matriz de [CSid](../../atl/reference/csid-class.md) objetos.  
  
 `pAttributes`  
 Ponteiro para uma matriz de DWORDs. Se esse parâmetro for omitido ou nulo, os atributos não são recuperados.  
  
### <a name="remarks"></a>Comentários  
 Este método irá enumerar todos os `CSid` objetos contidos no `CTokenGroups` do objeto e colocá-los e (opcionalmente) os sinalizadores de atributo em objetos de matriz.  
  
##  <a name="a-namelookupsida--ctokengroupslookupsid"></a><a name="lookupsid"></a>CTokenGroups::LookupSid  
 Recupera os atributos associados com um `CSid` objeto.  
  
```
bool LookupSid(  
    const CSid& rSid,
    DWORD* pdwAttributes = NULL) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 O [CSid](../../atl/reference/csid-class.md) objeto.  
  
 `pdwAttributes`  
 Ponteiro para uma DWORD que aceitará o `CSid` atributo do objeto. Se omitido ou nulo, o atributo não será recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se a `CSid` for encontrada, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Definindo `pdwAttributes` para NULL fornece uma maneira de confirmar a existência da `CSid` sem acessar o atributo. Observe que esse método não deve ser usado para verificar os direitos de acesso que podem ocorrer resultados incorretos no Windows 2000. Os aplicativos devem usar o [CAccessToken::CheckTokenMembership](../../atl/reference/caccesstoken-class.md#checktokenmembership) método.  
  
##  <a name="a-nameoperatoreqa--ctokengroupsoperator-"></a><a name="operator_eq"></a>CTokenGroups::operator =  
 Operador de atribuição.  
  
```
CTokenGroups& operator= (const TOKEN_GROUPS& rhs) throw(...);  
CTokenGroups& operator= (const CTokenGroups& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O `CTokenGroups` objeto ou [TOKEN_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) estrutura para atribuir ao `CTokenGroups` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CTokenGroups` objeto.  
  
##  <a name="a-nameoperatorconsttokengroupsstara--ctokengroupsoperator-const-tokengroups-"></a><a name="operator_const_token_groups__star"></a>TOKEN_GROUPS const CTokenGroups::operator *  
 Converte um valor para um ponteiro para o **TOKEN_GROUPS** estrutura.  
  
```  
operator const TOKEN_GROUPS *() const throw(...);
```  
  
### <a name="remarks"></a>Comentários  
 Converte um valor para um ponteiro para o [TOKEN_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) estrutura.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de segurança](../../visual-cpp-samples.md)   
 [Classe CSid](../../atl/reference/csid-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)

