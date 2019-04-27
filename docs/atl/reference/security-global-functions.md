---
title: Funções globais de segurança
ms.date: 11/04/2016
f1_keywords:
- atlsecurity/ATL::AtlGetDacl
- atlsecurity/ATL::AtlSetDacl
- atlsecurity/ATL::AtlGetGroupSid
- atlsecurity/ATL::AtlSetGroupSid
- atlsecurity/ATL::AtlGetOwnerSid
- atlsecurity/ATL::AtlSetOwnerSid
- atlsecurity/ATL::AtlGetSacl
- atlsecurity/ATL::AtlSetSacl
- atlsecurity/ATL::AtlGetSecurityDescriptor
helpviewer_keywords:
- SIDs [C++], modifying SID objects
- ACL object global functions
- security IDs [C++]
ms.assetid: 6a584bfe-16b7-47f4-8439-9c789c41567a
ms.openlocfilehash: 2c9a6fd31850ed137167b6987ddf2f83f34c64a1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62197236"
---
# <a name="security-global-functions"></a>Funções globais de segurança

Essas funções dão suporte para modificar objetos ACL e SID.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no tempo de execução do Windows.

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

##  <a name="atlgetdacl"></a>  AtlGetDacl

Chame essa função para recuperar as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlGetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CDacl* pDacl) throw();
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto para o qual recuperar as informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*pDacl*<br/>
Ponteiro para um objeto DACL que conterá as informações de segurança recuperados.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se qualquer um dos *hObject* ou *pDacl* é inválido.

##  <a name="atlsetdacl"></a>  AtlSetDacl

Chame essa função para definir as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlSetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CDacl& rDacl,
    DWORD dwInheritanceFlowControl = 0) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*rDacl*<br/>
A DACL que contém as novas informações de segurança.

*dwInheritanceFlowControl*<br/>
O controle de fluxo de herança. Esse valor pode ser 0 (padrão), PROTECTED_DACL_SECURITY_INFORMATION ou UNPROTECTED_DACL_SECURITY_INFORMATION.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se *hObject* é inválido, ou se *dwInheritanceFlowControl* não é um dos três valores permitidos.
### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlgetgroupsid"></a>  AtlGetGroupSid

Chame essa função para recuperar o SID (identificador de segurança) do grupo de um objeto.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlGetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto do qual recuperar informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*pSid*<br/>
Ponteiro para um `CSid` objeto que contém as novas informações de segurança.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlsetgroupsid"></a>  AtlSetGroupSid

Chame essa função para definir o SID (identificador de segurança) do grupo de um objeto.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlSetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*rSid*<br/>
O `CSid` objeto que contém as novas informações de segurança.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlgetownersid"></a>  AtlGetOwnerSid

Chame essa função para recuperar o SID (identificador de segurança) do proprietário de um objeto.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlGetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto do qual recuperar informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*pSid*<br/>
Ponteiro para um `CSid` objeto que contém as novas informações de segurança.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlsetownersid"></a>  AtlSetOwnerSid

Chame essa função para definir o SID (identificador de segurança) do proprietário de um objeto.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlSetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*rSid*<br/>
O `CSid` objeto que contém as novas informações de segurança.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlgetsacl"></a>  AtlGetSacl

Chame essa função para recuperar as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlGetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSacl* pSacl,
    bool bRequestNeededPrivileges = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto do qual recuperar as informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*pSacl*<br/>
Ponteiro para um objeto SACL que conterá as informações de segurança recuperados.

*bRequestNeededPrivileges*<br/>
Se for true, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Se `AtlGetSacl` deve ser chamado várias vezes em vários objetos diferentes, será mais eficiente para habilitar o privilégio SE_SECURITY_NAME, uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlsetsacl"></a>  AtlSetSacl

Chame essa função para definir as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
inline bool AtlSetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSacl& rSacl,
    DWORD dwInheritanceFlowControl = 0,
    bool bRequestNeededPrivileges = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *hObject* parâmetro.

*rSacl*<br/>
A SACL, que contém as novas informações de segurança.

*dwInheritanceFlowControl*<br/>
O controle de fluxo de herança. Esse valor pode ser 0 (padrão), PROTECTED_SACL_SECURITY_INFORMATION ou UNPROTECTED_SACL_SECURITY_INFORMATION.

*bRequestNeededPrivileges*<br/>
Se for true, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se *hObject* é inválido, ou se *dwInheritanceFlowControl* não é um dos três valores permitidos.

Se `AtlSetSacl` deve ser chamado várias vezes em vários objetos diferentes, será mais eficiente para habilitar o privilégio SE_SECURITY_NAME, uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="atlgetsecuritydescriptor"></a>  AtlGetSecurityDescriptor

Chame essa função para recuperar o descritor de segurança de determinado objeto.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

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

*pszObjectName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do objeto do qual recuperar informações de segurança.

*ObjectType*<br/>
Especifica um valor a partir de [SE_OBJECT_TYPE](/windows/desktop/api/accctrl/ne-accctrl-_se_object_type) enumeração que indica o tipo de objeto identificado pelo *pszObjectName* parâmetro.

*pSecurityDescriptor*<br/>
O objeto que recebe o descritor de segurança solicitado.

*requestedInfo*<br/>
Um conjunto de [SECURITY_INFORMATION](/windows/desktop/SecAuthZ/security-information) bit de sinalizadores que indicam o tipo de informação de segurança deve ser recuperado. Esse parâmetro pode ser uma combinação dos valores a seguir.

*bRequestNeededPrivileges*<br/>
Se for true, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Se `AtlGetSecurityDescriptor` deve ser chamado várias vezes em vários objetos diferentes, será mais eficiente para habilitar o privilégio SE_SECURITY_NAME, uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
