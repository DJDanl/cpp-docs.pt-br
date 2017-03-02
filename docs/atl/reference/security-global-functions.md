---
title: "Funções globais de segurança | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- SIDs [C++], modifying SID objects
- ACL object global functions
- security IDs [C++]
ms.assetid: 6a584bfe-16b7-47f4-8439-9c789c41567a
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 368da76305910a0948eb386990a4bcdb84e61396
ms.lasthandoff: 02/25/2017

---
# <a name="security-global-functions"></a>Funções globais de segurança
Essas funções fornecem suporte para modificar objetos de SID e a ACL.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlGetDacl](#atlgetdacl)|Chame essa função para recuperar as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.|  
|[AtlSetDacl](#atlsetdacl)|Chame essa função para definir as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.|  
|[AtlGetGroupSid](#atlgetgroupsid)|Chame essa função para recuperar o SID (identificador de segurança) do grupo de um objeto.|  
|[AtlSetGroupSid](#atlsetgroupsid)|Chame essa função para definir o SID (identificador de segurança) do grupo de um objeto.|  
|[AtlGetOwnerSid](#atlgetownersid)|Chame essa função para recuperar o SID (identificador de segurança) do proprietário de um objeto.|  
|[AtlSetOwnerSid](#atlsetownersid)|Chame essa função para definir o SID (identificador de segurança) do proprietário de um objeto.|  
|[AtlGetSacl](#atlgetsacl)|Chame essa função para recuperar as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.|  
|[AtlSetSacl](#atlsetsacl)|Chame essa função para definir as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.|  
|[AtlGetSecurityDescriptor](#atlgetsecuritydescriptor)|Chame essa função para recuperar o descritor de segurança de determinado objeto.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlgetdacla--atlgetdacl"></a><a name="atlgetdacl"></a>AtlGetDacl  
 Chame essa função para recuperar as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlGetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CDacl* pDacl) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto que deseja recuperar as informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `pDacl`  
 Ponteiro para um objeto DACL que conterá as informações de segurança recuperados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, asserção ocorrerá um erro se `hObject` ou `pDacl` inválido *.*  

v

##  <a name="a-nameatlsetdacla--atlsetdacl"></a><a name="atlsetdacl"></a>AtlSetDacl  
 Chame essa função para definir as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlSetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CDacl& rDacl,
    DWORD dwInheritanceFlowControl = 0) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto para o qual definir informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `rDacl`  
 A DACL com as novas informações de segurança.  
  
 `dwInheritanceFlowControl`  
 O controle de fluxo da herança. Esse valor pode ser 0 (o padrão), PROTECTED_DACL_SECURITY_INFORMATION ou UNPROTECTED_DACL_SECURITY_INFORMATION.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, um erro de asserção ocorrerá se `hObject` é inválido, ou se `dwInheritanceFlowControl` não é um dos três valores permitidos.  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlgetgroupsida--atlgetgroupsid"></a><a name="atlgetgroupsid"></a>AtlGetGroupSid  
 Chame essa função para recuperar o SID (identificador de segurança) do grupo de um objeto.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlGetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto do qual recuperar informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `pSid`  
 Ponteiro para uma `CSid` objeto que irá conter as novas informações de segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlsetgroupsida--atlsetgroupsid"></a><a name="atlsetgroupsid"></a>AtlSetGroupSid  
 Chame essa função para definir o SID (identificador de segurança) do grupo de um objeto.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlSetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto para o qual definir informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `rSid`  
 O `CSid` objeto que contém as novas informações de segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlgetownersida--atlgetownersid"></a><a name="atlgetownersid"></a>AtlGetOwnerSid  
 Chame essa função para recuperar o SID (identificador de segurança) do proprietário de um objeto.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlGetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto do qual recuperar informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `pSid`  
 Ponteiro para uma `CSid` objeto que irá conter as novas informações de segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlsetownersida--atlsetownersid"></a><a name="atlsetownersid"></a>AtlSetOwnerSid  
 Chame essa função para definir o SID (identificador de segurança) do proprietário de um objeto.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlSetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto para o qual definir informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `rSid`  
 O `CSid` objeto que contém as novas informações de segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlgetsacla--atlgetsacl"></a><a name="atlgetsacl"></a>AtlGetSacl  
 Chame essa função para recuperar as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlGetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSacl* pSacl,
    bool bRequestNeededPrivileges = true) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto do qual recuperar as informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 `pSacl`  
 Ponteiro para um objeto SACL que conterá as informações de segurança recuperados.  
  
 `bRequestNeededPrivileges`  
 Se verdadeiro, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se `AtlGetSacl` deve ser chamado várias vezes em vários objetos diferentes, será mais eficiente para habilitar o privilégio SE_SECURITY_NAME uma vez antes de chamar a função, com `bRequestNeededPrivileges` definido como false.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlsetsacla--atlsetsacl"></a><a name="atlsetsacl"></a>AtlSetSacl  
 Chame essa função para definir as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlSetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSacl& rSacl,
    DWORD dwInheritanceFlowControl = 0,
    bool bRequestNeededPrivileges = true) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Identificador para o objeto para o qual definir informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo `hObject` parâmetro.  
  
 *rSacl*  
 A SACL contendo as novas informações de segurança.  
  
 `dwInheritanceFlowControl`  
 O controle de fluxo da herança. Esse valor pode ser 0 (o padrão), PROTECTED_SACL_SECURITY_INFORMATION ou UNPROTECTED_SACL_SECURITY_INFORMATION.  
  
 `bRequestNeededPrivileges`  
 Se verdadeiro, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, um erro de asserção ocorrerá se `hObject` é inválido, ou se `dwInheritanceFlowControl` não é um dos três valores permitidos.  
  
 Se `AtlSetSacl` deve ser chamado várias vezes em vários objetos diferentes, será mais eficiente para habilitar o privilégio SE_SECURITY_NAME uma vez antes de chamar a função, com `bRequestNeededPrivileges` definido como false.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameatlgetsecuritydescriptora--atlgetsecuritydescriptor"></a><a name="atlgetsecuritydescriptor"></a>AtlGetSecurityDescriptor  
 Chame essa função para recuperar o descritor de segurança de determinado objeto.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
inline bool AtlGetSecurityDescriptor(
    LPCTSTR pszObjectName,
    SE_OBJECT_TYPE ObjectType,
    CSecurityDesc* pSecurityDescriptor,
    SECURITY_INFORMATION requestedInfo = OWNER_SECURITY_INFORMATION |
    GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION |
    SACL_SECURITY_INFORMATION,
 bool bRequestNeededPrivileges = true) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszObjectName*  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do objeto do qual recuperar informações de segurança.  
  
 `ObjectType`  
 Especifica um valor a partir de [SE_OBJECT_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379593) enumeração que indica o tipo de objeto identificado pelo *pszObjectName* parâmetro.  
  
 *pSecurityDescriptor*  
 O objeto que recebe o descritor de segurança solicitado.  
  
 *requestedInfo*  
 Um conjunto de [SECURITY_INFORMATION](http://msdn.microsoft.com/library/windows/desktop/aa379573) bit sinalizadores que indicam o tipo de informações de segurança para recuperar. Esse parâmetro pode ser uma combinação dos valores a seguir.  
  
 `bRequestNeededPrivileges`  
 Se verdadeiro, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se `AtlGetSecurityDescriptor` deve ser chamado várias vezes em vários objetos diferentes, será mais eficiente para habilitar o privilégio SE_SECURITY_NAME uma vez antes de chamar a função, com `bRequestNeededPrivileges` definido como false.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h 
   
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

