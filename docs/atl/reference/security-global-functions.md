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
ms.openlocfilehash: 0b42fe10ef1de517677b35a9fe54d0c6a04ff748
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834486"
---
# <a name="security-global-functions"></a>Funções globais de segurança

Essas funções fornecem suporte para modificar objetos SID e ACL.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|Nome|Descrição|
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

**Cabeçalho:** ATLSecurity. h

## <a name="atlgetdacl"></a><a name="atlgetdacl"></a> AtlGetDacl

Chame essa função para recuperar as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlGetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CDacl* pDacl) throw();
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto para o qual recuperar as informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*pDacl*<br/>
Ponteiro para um objeto DACL que conterá as informações de segurança recuperadas.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se *hObject* ou *pDacl* for inválido.

## <a name="atlsetdacl"></a><a name="atlsetdacl"></a> AtlSetDacl

Chame essa função para definir as informações da DACL (lista de controle de acesso discricionário) de um objeto especificado.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlSetDacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CDacl& rDacl,
    DWORD dwInheritanceFlowControl = 0) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*rDacl*<br/>
A DACL que contém as novas informações de segurança.

*dwInheritanceFlowControl*<br/>
O controle de fluxo de herança. Esse valor pode ser 0 (o padrão), PROTECTED_DACL_SECURITY_INFORMATION ou UNPROTECTED_DACL_SECURITY_INFORMATION.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se *hObject* for inválido ou se *dwInheritanceFlowControl* não for um dos três valores permitidos.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlgetgroupsid"></a><a name="atlgetgroupsid"></a> AtlGetGroupSid

Chame essa função para recuperar o SID (identificador de segurança) do grupo de um objeto.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlGetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto do qual recuperar informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*pSid*<br/>
Ponteiro para um `CSid` objeto que conterá as novas informações de segurança.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlsetgroupsid"></a><a name="atlsetgroupsid"></a> AtlSetGroupSid

Chame essa função para definir o SID (identificador de segurança) do grupo de um objeto.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlSetGroupSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*rSid*<br/>
O `CSid` objeto que contém as novas informações de segurança.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlgetownersid"></a><a name="atlgetownersid"></a> AtlGetOwnerSid

Chame essa função para recuperar o SID (identificador de segurança) do proprietário de um objeto.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlGetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSid* pSid) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto do qual recuperar informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*pSid*<br/>
Ponteiro para um `CSid` objeto que conterá as novas informações de segurança.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlsetownersid"></a><a name="atlsetownersid"></a> AtlSetOwnerSid

Chame essa função para definir o SID (identificador de segurança) do proprietário de um objeto.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlSetOwnerSid(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSid& rSid) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*rSid*<br/>
O `CSid` objeto que contém as novas informações de segurança.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlgetsacl"></a><a name="atlgetsacl"></a> AtlGetSacl

Chame essa função para recuperar as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlGetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    CSacl* pSacl,
    bool bRequestNeededPrivileges = true) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto do qual recuperar as informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*pSacl*<br/>
Ponteiro para um objeto SACL que conterá as informações de segurança recuperadas.

*bRequestNeededPrivileges*<br/>
Se for true, a função tentará habilitar o privilégio de SE_SECURITY_NAME e restaurá-lo na conclusão.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Se `AtlGetSacl` for chamado muitas vezes em muitos objetos diferentes, será mais eficiente habilitar o privilégio de SE_SECURITY_NAME uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlsetsacl"></a><a name="atlsetsacl"></a> AtlSetSacl

Chame essa função para definir as informações da SACL (lista de controle de acesso do sistema) de um objeto especificado.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
inline bool AtlSetSacl(
    HANDLE hObject,
    SE_OBJECT_TYPE ObjectType,
    const CSacl& rSacl,
    DWORD dwInheritanceFlowControl = 0,
    bool bRequestNeededPrivileges = true) throw(...);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Identificador para o objeto para o qual definir informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *hObject* .

*rSacl*<br/>
A SACL que contém as novas informações de segurança.

*dwInheritanceFlowControl*<br/>
O controle de fluxo de herança. Esse valor pode ser 0 (o padrão), PROTECTED_SACL_SECURITY_INFORMATION ou UNPROTECTED_SACL_SECURITY_INFORMATION.

*bRequestNeededPrivileges*<br/>
Se for true, a função tentará habilitar o privilégio de SE_SECURITY_NAME e restaurá-lo na conclusão.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se *hObject* for inválido ou se *dwInheritanceFlowControl* não for um dos três valores permitidos.

Se `AtlSetSacl` for chamado muitas vezes em muitos objetos diferentes, será mais eficiente habilitar o privilégio de SE_SECURITY_NAME uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="atlgetsecuritydescriptor"></a><a name="atlgetsecuritydescriptor"></a> AtlGetSecurityDescriptor

Chame essa função para recuperar o descritor de segurança de determinado objeto.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

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

### <a name="parameters"></a>parâmetros

*pszObjectName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do objeto do qual recuperar informações de segurança.

*ObjectType*<br/>
Especifica um valor da enumeração [SE_OBJECT_TYPE](/windows/win32/api/accctrl/ne-accctrl-se_object_type) que indica o tipo de objeto identificado pelo parâmetro *pszObjectName* .

*pSecurityDescriptor*<br/>
O objeto que recebe o descritor de segurança solicitado.

*requestedInfo*<br/>
Um conjunto de sinalizadores de bit de [SECURITY_INFORMATION](/windows/win32/SecAuthZ/security-information) que indicam o tipo de informações de segurança a serem recuperadas. Esse parâmetro pode ser uma combinação dos valores a seguir.

*bRequestNeededPrivileges*<br/>
Se for true, a função tentará habilitar o privilégio de SE_SECURITY_NAME e restaurá-lo na conclusão.

### <a name="return-value"></a>Valor Retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Se `AtlGetSecurityDescriptor` for chamado muitas vezes em muitos objetos diferentes, será mais eficiente habilitar o privilégio de SE_SECURITY_NAME uma vez antes de chamar a função, com *bRequestNeededPrivileges* definido como false.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
