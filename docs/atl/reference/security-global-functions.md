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
ms.openlocfilehash: 682d44aa80f5d6de521223dfd67db2813cb6738c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326028"
---
# <a name="security-global-functions"></a>Funções globais de segurança

Essas funções fornecem suporte para modificar objetos SID e ACL.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

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

**Cabeçalho:** atlsecurity.h

## <a name="atlgetdacl"></a><a name="atlgetdacl"></a>AtlGetDacl

Chame essa função para recuperar as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlGetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CDacl* pDacl) throw();
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto para recuperar as informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*pDacl*<br/>
Ponteiro para um objeto DACL que conterá as informações de segurança recuperadas.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se *hObject* ou *pDacl* forem inválidos.

## <a name="atlsetdacl"></a><a name="atlsetdacl"></a>AtlSetDacl

Chame essa função para definir as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlSetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CDacl& rDacl,
    DWORD dwInheritanceFlowControl = 0) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto para que defina informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*rDacl*<br/>
O DACL contendo as novas informações de segurança.

*dwInheritanceFlowControl*<br/>
O controle do fluxo de herança. Este valor pode ser 0 (o padrão), PROTECTED_DACL_SECURITY_INFORMATION ou UNPROTECTED_DACL_SECURITY_INFORMATION.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se *hObject* for inválido ou se *dwHerFlowControl* não for um dos três valores permitidos.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlgetgroupsid"></a><a name="atlgetgroupsid"></a>AtlGetGroupSid

Chame essa função para recuperar o SID (identificador de segurança) do grupo de um objeto.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlGetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto a partir do qual recuperar informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*Psid*<br/>
Ponteiro para `CSid` um objeto que conterá as novas informações de segurança.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlsetgroupsid"></a><a name="atlsetgroupsid"></a>AtlSetGroupSid

Chame essa função para definir o SID (identificador de segurança) do grupo de um objeto.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlSetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto para que defina informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*rSid*<br/>
O `CSid` objeto contendo as novas informações de segurança.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlgetownersid"></a><a name="atlgetownersid"></a>AtlGetOwnerSid

Chame essa função para recuperar o SID (identificador de segurança) do proprietário de um objeto.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlGetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto a partir do qual recuperar informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*Psid*<br/>
Ponteiro para `CSid` um objeto que conterá as novas informações de segurança.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlsetownersid"></a><a name="atlsetownersid"></a>AtlSetOwnerSid

Chame essa função para definir o SID (identificador de segurança) do proprietário de um objeto.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlSetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto para que defina informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*rSid*<br/>
O `CSid` objeto contendo as novas informações de segurança.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlgetsacl"></a><a name="atlgetsacl"></a>AtlGetSacl

Chame essa função para recuperar as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlGetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSacl* pSacl,
    bool bRequestNeededPrivileges = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto a partir do qual recuperar as informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*pSacl*<br/>
Ponteiro para um objeto SACL que conterá as informações de segurança recuperadas.

*bRequestNeededPrivileges*<br/>
Se for verdade, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Se `AtlGetSacl` for para ser chamado muitas vezes em muitos objetos diferentes, será mais eficiente habilitar o privilégio SE_SECURITY_NAME uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como falso.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlsetsacl"></a><a name="atlsetsacl"></a>AtlSetSacl

Chame essa função para definir as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
inline bool AtlSetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSacl& rSacl,
    DWORD dwInheritanceFlowControl = 0,
    bool bRequestNeededPrivileges = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Manuseie o objeto para que defina informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject.*

*rSacl*<br/>
A SACL contém as novas informações de segurança.

*dwInheritanceFlowControl*<br/>
O controle do fluxo de herança. Este valor pode ser 0 (o padrão), PROTECTED_SACL_SECURITY_INFORMATION ou UNPROTECTED_SACL_SECURITY_INFORMATION.

*bRequestNeededPrivileges*<br/>
Se for verdade, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se *hObject* for inválido ou se *dwHerFlowControl* não for um dos três valores permitidos.

Se `AtlSetSacl` for para ser chamado muitas vezes em muitos objetos diferentes, será mais eficiente habilitar o privilégio SE_SECURITY_NAME uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como falso.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="atlgetsecuritydescriptor"></a><a name="atlgetsecuritydescriptor"></a>AtlGetSecurityDescriptor

Chame essa função para recuperar o descritor de segurança de determinado objeto.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

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
Pointer para uma seqüência de seqüência de terminadas nula que especifica o nome do objeto a partir do qual recuperar informações de segurança.

*Objecttype*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *pszObjectName.*

*pSecurityDescriptor*<br/>
O objeto que recebe o descritor de segurança solicitado.

*requestedInfo*<br/>
Um conjunto de [SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) bit somas que indicam o tipo de informações de segurança a serem recuperadas. Este parâmetro pode ser uma combinação dos seguintes valores.

*bRequestNeededPrivileges*<br/>
Se for verdade, a função tentará habilitar o privilégio SE_SECURITY_NAME e restaurá-lo após a conclusão.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Se `AtlGetSecurityDescriptor` for para ser chamado muitas vezes em muitos objetos diferentes, será mais eficiente habilitar o privilégio SE_SECURITY_NAME uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como falso.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
