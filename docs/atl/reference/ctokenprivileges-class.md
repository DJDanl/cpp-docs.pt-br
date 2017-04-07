---
title: Classe de CTokenPrivileges | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTokenPrivileges
- ATLSECURITY/ATL::CTokenPrivileges
- ATLSECURITY/ATL::CTokenPrivileges::CTokenPrivileges
- ATLSECURITY/ATL::CTokenPrivileges::Add
- ATLSECURITY/ATL::CTokenPrivileges::Delete
- ATLSECURITY/ATL::CTokenPrivileges::DeleteAll
- ATLSECURITY/ATL::CTokenPrivileges::GetCount
- ATLSECURITY/ATL::CTokenPrivileges::GetDisplayNames
- ATLSECURITY/ATL::CTokenPrivileges::GetLength
- ATLSECURITY/ATL::CTokenPrivileges::GetLuidsAndAttributes
- ATLSECURITY/ATL::CTokenPrivileges::GetNamesAndAttributes
- ATLSECURITY/ATL::CTokenPrivileges::GetPTOKEN_PRIVILEGES
- ATLSECURITY/ATL::CTokenPrivileges::LookupPrivilege
dev_langs:
- C++
helpviewer_keywords:
- CTokenPrivileges class
ms.assetid: 89590105-f001-4014-870d-142926091231
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
ms.openlocfilehash: 4d732dbf27c2155ffb98ca59b140d01ea92458e0
ms.lasthandoff: 02/25/2017

---
# <a name="ctokenprivileges-class"></a>Classe CTokenPrivileges
Essa classe é um wrapper para o **TOKEN_PRIVILEGES** estrutura.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CTokenPrivileges
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTokenPrivileges::CTokenPrivileges](#ctokenprivileges)|O construtor.|  
|[CTokenPrivileges:: ~ CTokenPrivileges](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTokenPrivileges::Add](#add)|Adiciona um ou mais privilégios para o `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::Delete](#delete)|Exclui um privilégio do `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::DeleteAll](#deleteall)|Exclui todos os privilégios do `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::GetCount](#getcount)|Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::GetDisplayNames](#getdisplaynames)|Recupera exibe nomes para os privilégios contidos a `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::GetLength](#getlength)|Retorna o tamanho do buffer de bytes necessários para manter o **TOKEN_PRIVILEGES** estrutura representada pelo `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::GetLuidsAndAttributes](#getluidsandattributes)|Recupera os identificadores locais exclusivos (LUIDs) e sinalizadores de atributo do `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes)|Recupera os nomes de privilégio e sinalizadores de atributo do `CTokenPrivileges` objeto.|  
|[CTokenPrivileges::GetPTOKEN_PRIVILEGES](#getptoken_privileges)|Retorna um ponteiro para o **TOKEN_PRIVILEGES** estrutura.|  
|[CTokenPrivileges::LookupPrivilege](#lookupprivilege)|Recupera o atributo associado com um nome de privilégio.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[TOKEN_PRIVILEGES const CTokenPrivileges::operator *](#operator_const_token_privileges__star)|Converte um valor para um ponteiro para o **TOKEN_PRIVILEGES** estrutura.|  
|[CTokenPrivileges::operator =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 Um [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou thread e alocado para cada usuário conectado em um sistema Windows NT ou Windows 2000.  
  
 O token de acesso é usado para descrever os vários privilégios de segurança concedidos a cada usuário. Um privilégio consiste em um número de 64 bits, chamado um identificador local exclusivo ( [LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261)) e uma cadeia de caracteres do descritor.  
  
 O `CTokenPrivileges` classe é um wrapper para o [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) estrutura e contém 0 ou mais privilégios. Privilégios podem ser adicionados, excluídos ou consultados usando os métodos de classe fornecida.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="add"></a>CTokenPrivileges::Add  
 Adiciona um ou mais privilégios para o `CTokenPrivileges` objeto de token de acesso.  
  
```
bool Add(LPCTSTR pszPrivilege, bool bEnable) throw(...);  
void Add(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPrivilege`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido em WINNT. Arquivo de cabeçalho H.  
  
 `bEnable`  
 Se for true, o privilégio está ativado. Se for false, o privilégio está desabilitado.  
  
 `rPrivileges`  
 Referência a um [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) estrutura. Os privilégios e atributos são copiados a partir dessa estrutura e adicionados para o `CTokenPrivileges` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro formulário desse método retorna true se os privilégios são adicionadas com êxito, false caso contrário.  
  
##  <a name="ctokenprivileges"></a>CTokenPrivileges::CTokenPrivileges  
 O construtor.  
  
```
CTokenPrivileges() throw();
CTokenPrivileges(const CTokenPrivileges& rhs) throw(... );  
CTokenPrivileges(const TOKEN_PRIVILEGES& rPrivileges) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O `CTokenPrivileges` objeto para atribuir ao novo objeto.  
  
 `rPrivileges`  
 O [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) estrutura para atribuir ao novo `CTokenPrivileges` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CTokenPrivileges` objeto opcionalmente pode ser criado usando um **TOKEN_PRIVILEGES** estrutura ou definido anteriormente `CTokenPrivileges` objeto.  
  
##  <a name="dtor"></a>CTokenPrivileges:: ~ CTokenPrivileges  
 O destruidor.  
  
```
virtual ~CTokenPrivileges() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos alocados.  
  
##  <a name="delete"></a>CTokenPrivileges::Delete  
 Exclui um privilégio do `CTokenPrivileges` objeto de token de acesso.  
  
```
bool Delete(LPCTSTR pszPrivilege) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPrivilege`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido em WINNT. Arquivo de cabeçalho H. Por exemplo, esse parâmetro pode especificar a constante SE_SECURITY_NAME, ou sua cadeia de caracteres correspondente, "SeSecurityPrivilege".  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o privilégio foi excluído com êxito, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Esse método é útil como uma ferramenta para criar tokens restritos no Windows 2000.  
  
##  <a name="deleteall"></a>CTokenPrivileges::DeleteAll  
 Exclui todos os privilégios do `CTokenPrivileges` objeto de token de acesso.  
  
```
void DeleteAll() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Exclui todos os privilégios contidos a `CTokenPrivileges` objeto de token de acesso.  
  
##  <a name="getdisplaynames"></a>CTokenPrivileges::GetDisplayNames  
 Recupera exibe nomes para os privilégios contidos a `CTokenPrivileges` objeto de token de acesso.  
  
```
void GetDisplayNames(CNames* pDisplayNames) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisplayNames`  
 Um ponteiro para uma matriz de objetos `CString`. **CNames** é definido como um typedef: **CTokenPrivileges::CAtlArray\<CString >**.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro `pDisplayNames` é um ponteiro para uma matriz de `CString` objetos que receberão os nomes de exibição correspondentes aos privilégios contidos a `CTokenPrivileges` objeto. Esse método recupera nomes de exibição somente para os privilégios especificados na seção definido privilégios de WINNT. H.  
  
 Esse método recupera um nome de exibição: por exemplo, se o nome do atributo é SE_REMOTE_SHUTDOWN_NAME, o nome de exibição é "Forçar o desligamento de um sistema remoto." Para obter o nome do sistema, use [CTokenPrivileges::GetNamesAndAttributes](#getnamesandattributes).  
  
##  <a name="getcount"></a>CTokenPrivileges::GetCount  
 Retorna o número de entradas de privilégio no `CTokenPrivileges` objeto.  
  
```
UINT GetCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de privilégios contidas a `CTokenPrivileges` objeto.  
  
##  <a name="getlength"></a>CTokenPrivileges::GetLength  
 Retorna o comprimento do `CTokenPrivileges` objeto.  
  
```
UINT GetLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de bytes necessários para armazenar uma **TOKEN_PRIVILEGES** estrutura representada pelo `CTokenPrivileges` objeto, incluindo todas as entradas de privilégio que ele contém.  
  
##  <a name="getluidsandattributes"></a>CTokenPrivileges::GetLuidsAndAttributes  
 Recupera os identificadores locais exclusivos (LUIDs) e sinalizadores de atributo do `CTokenPrivileges` objeto.  
  
```
void GetLuidsAndAttributes(
    CLUIDArray* pPrivileges,
    CAttributes* pAttributes = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPrivileges`  
 Ponteiro para uma matriz de [LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261) objetos. **CLUIDArray** é um typedef definido como **CAtlArray\<LUID > CLUIDArray**.  
  
 `pAttributes`  
 Ponteiro para uma matriz de objetos DWORD. Se esse parâmetro for omitido ou nulo, os atributos não são recuperados. **CAttributes** é um typedef definido como **CAtlArray \<DWORD > CAttributes**.  
  
### <a name="remarks"></a>Comentários  
 Este método irá enumerar todos os privilégios contidos a `CTokenPrivileges` objeto de token de acesso e colocar os LUIDs individuais e (opcionalmente) os sinalizadores de atributo em objetos de matriz.  
  
##  <a name="getnamesandattributes"></a>CTokenPrivileges::GetNamesAndAttributes  
 Recupera os nome e atributo sinalizadores do `CTokenPrivileges` objeto.  
  
```
void GetNamesAndAttributes(
    CNames* pNames,
    CAttributes* pAttributes = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pNames*  
 Ponteiro para uma matriz de `CString` objetos. **CNames** é um typedef definido como **CAtlArray \<CString > CNames**.  
  
 `pAttributes`  
 Ponteiro para uma matriz de objetos DWORD. Se esse parâmetro for omitido ou nulo, os atributos não são recuperados. **CAttributes** é um typedef definido como **CAtlArray \<DWORD > CAttributes**.  
  
### <a name="remarks"></a>Comentários  
 Este método irá enumerar todos os privilégios contidos a `CTokenPrivileges` objeto, colocando o nome e (opcionalmente) os sinalizadores de atributo em objetos de matriz.  
  
 Esse método recupera o nome do atributo, em vez do nome de exibição: por exemplo, se o nome do atributo é SE_REMOTE_SHUTDOWN_NAME, o nome do sistema é "SeRemoteShutdownPrivilege." Para obter o nome de exibição, use o método [CTokenPrivileges::GetDisplayNames](#getdisplaynames).  
  
##  <a name="getptoken_privileges"></a>CTokenPrivileges::GetPTOKEN_PRIVILEGES  
 Retorna um ponteiro para o **TOKEN_PRIVILEGES** estrutura.  
  
```
const TOKEN_PRIVILEGES* GetPTOKEN_PRIVILEGES() const throw(...);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) estrutura.  
  
##  <a name="lookupprivilege"></a>CTokenPrivileges::LookupPrivilege  
 Recupera o atributo associado com um nome de privilégio.  
  
```
bool LookupPrivilege(
    LPCTSTR pszPrivilege,
    DWORD* pdwAttributes = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPrivilege`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do privilégio, conforme definido em WINNT. Arquivo de cabeçalho H. Por exemplo, esse parâmetro pode especificar a constante SE_SECURITY_NAME, ou sua cadeia de caracteres correspondente, "SeSecurityPrivilege".  
  
 `pdwAttributes`  
 Ponteiro para uma variável que recebe os atributos.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o atributo for recuperada com sucesso, FALSO caso contrário.  
  
##  <a name="operator_eq"></a>CTokenPrivileges::operator =  
 Operador de atribuição.  
  
```
CTokenPrivileges& operator= (const TOKEN_PRIVILEGES& rPrivileges) throw(...);  
CTokenPrivileges& operator= (const CTokenPrivileges& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPrivileges`  
 O [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) estrutura para atribuir ao `CTokenPrivileges` objeto.  
  
 `rhs`  
 O `CTokenPrivileges` objeto para atribuir o objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CTokenPrivileges` objeto.  
  
##  <a name="operator_const_token_privileges__star"></a>TOKEN_PRIVILEGES const CTokenPrivileges::operator *  
 Converte um valor para um ponteiro para o **TOKEN_PRIVILEGES** estrutura.  
  
```  
operator const TOKEN_PRIVILEGES *() const throw(...);
```  
  
### <a name="remarks"></a>Comentários  
 Converte um valor para um ponteiro para o [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) estrutura.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de segurança](../../visual-cpp-samples.md)   
 [TOKEN_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630)   
 [LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261)   
 [LUID_AND_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379263)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)

