---
title: Classe CSecurityDesc
ms.date: 11/04/2016
f1_keywords:
- CSecurityDesc
- ATLSECURITY/ATL::CSecurityDesc
- ATLSECURITY/ATL::CSecurityDesc::CSecurityDesc
- ATLSECURITY/ATL::CSecurityDesc::FromString
- ATLSECURITY/ATL::CSecurityDesc::GetControl
- ATLSECURITY/ATL::CSecurityDesc::GetDacl
- ATLSECURITY/ATL::CSecurityDesc::GetGroup
- ATLSECURITY/ATL::CSecurityDesc::GetOwner
- ATLSECURITY/ATL::CSecurityDesc::GetPSECURITY_DESCRIPTOR
- ATLSECURITY/ATL::CSecurityDesc::GetSacl
- ATLSECURITY/ATL::CSecurityDesc::IsDaclAutoInherited
- ATLSECURITY/ATL::CSecurityDesc::IsDaclDefaulted
- ATLSECURITY/ATL::CSecurityDesc::IsDaclPresent
- ATLSECURITY/ATL::CSecurityDesc::IsDaclProtected
- ATLSECURITY/ATL::CSecurityDesc::IsGroupDefaulted
- ATLSECURITY/ATL::CSecurityDesc::IsOwnerDefaulted
- ATLSECURITY/ATL::CSecurityDesc::IsSaclAutoInherited
- ATLSECURITY/ATL::CSecurityDesc::IsSaclDefaulted
- ATLSECURITY/ATL::CSecurityDesc::IsSaclPresent
- ATLSECURITY/ATL::CSecurityDesc::IsSaclProtected
- ATLSECURITY/ATL::CSecurityDesc::IsSelfRelative
- ATLSECURITY/ATL::CSecurityDesc::MakeAbsolute
- ATLSECURITY/ATL::CSecurityDesc::MakeSelfRelative
- ATLSECURITY/ATL::CSecurityDesc::SetControl
- ATLSECURITY/ATL::CSecurityDesc::SetDacl
- ATLSECURITY/ATL::CSecurityDesc::SetGroup
- ATLSECURITY/ATL::CSecurityDesc::SetOwner
- ATLSECURITY/ATL::CSecurityDesc::SetSacl
- ATLSECURITY/ATL::CSecurityDesc::ToString
helpviewer_keywords:
- CSecurityDesc class
ms.assetid: 3767a327-378f-4690-ba40-4d9f6a1f5ee4
ms.openlocfilehash: a9e0eb01608edf29f99209dffc932630ad08807a
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915707"
---
# <a name="csecuritydesc-class"></a>Classe CSecurityDesc

Essa classe é um wrapper para a `SECURITY_DESCRIPTOR` estrutura.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CSecurityDesc
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityDesc::CSecurityDesc](#csecuritydesc)|O construtor.|
|[CSecurityDesc::~CSecurityDesc](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityDesc::FromString](#fromstring)|Converte um descritor de segurança de formato de cadeia de caracteres em um descritor de segurança funcional válido.|
|[CSecurityDesc::GetControl](#getcontrol)|Recupera informações de controle do descritor de segurança.|
|[CSecurityDesc::GetDacl](#getdacl)|Recupera informações de DACL (lista de controle de acesso discricionário) do descritor de segurança.|
|[CSecurityDesc::GetGroup](#getgroup)|Recupera as informações do grupo primário do descritor de segurança.|
|[CSecurityDesc::GetOwner](#getowner)|Recupera a informatação do proprietário do descritor de segurança.|
|[CSecurityDesc::GetPSECURITY_DESCRIPTOR](#getpsecurity_descriptor)|Retorna um ponteiro para a `SECURITY_DESCRIPTOR` estrutura.|
|[CSecurityDesc::GetSacl](#getsacl)|Recupera informações de SACL (lista de controle de acesso) do sistema do descritor de segurança.|
|[CSecurityDesc::IsDaclAutoInherited](#isdaclautoinherited)|Determina se a DACL está configurada para dar suporte à propagação automática.|
|[CSecurityDesc::IsDaclDefaulted](#isdacldefaulted)|Determina se o descritor de segurança está configurado com uma DACL padrão.|
|[CSecurityDesc::IsDaclPresent](#isdaclpresent)|Determina se o descritor de segurança contém uma DACL.|
|[CSecurityDesc::IsDaclProtected](#isdaclprotected)|Determina se a DACL está configurada para evitar modificações.|
|[CSecurityDesc::IsGroupDefaulted](#isgroupdefaulted)|Determina se o identificador de segurança do grupo (SID) do descritor de segurança foi definido por padrão.|
|[CSecurityDesc::IsOwnerDefaulted](#isownerdefaulted)|Determina se o SID do proprietário do descritor de segurança foi definido por padrão.|
|[CSecurityDesc::IsSaclAutoInherited](#issaclautoinherited)|Determina se a SACL está configurada para dar suporte à propagação automática.|
|[CSecurityDesc::IsSaclDefaulted](#issacldefaulted)|Determina se o descritor de segurança está configurado com uma SACL padrão.|
|[CSecurityDesc::IsSaclPresent](#issaclpresent)|Determina se o descritor de segurança contém uma SACL.|
|[CSecurityDesc::IsSaclProtected](#issaclprotected)|Determina se a SACL está configurada para evitar modificações.|
|[CSecurityDesc::IsSelfRelative](#isselfrelative)|Determina se o descritor de segurança está em um formato auto-relativo.|
|[CSecurityDesc::MakeAbsolute](#makeabsolute)|Chame esse método para converter o descritor de segurança em formato absoluto.|
|[CSecurityDesc::MakeSelfRelative](#makeselfrelative)|Chame esse método para converter o descritor de segurança em formato auto-relativo.|
|[CSecurityDesc::SetControl](#setcontrol)|Define os bits de controle de um descritor de segurança.|
|[CSecurityDesc::SetDacl](#setdacl)|Define informações em uma DACL. Se uma DACL já estiver presente no descritor de segurança, ela será substituída.|
|[CSecurityDesc::SetGroup](#setgroup)|Define as informações do grupo primário de um descritor de segurança de formato absoluto, substituindo todas as informações do grupo primário já presentes.|
|[CSecurityDesc::SetOwner](#setowner)|Define as informações de proprietário de um descritor de segurança de formato absoluto, substituindo todas as informações de proprietário já presentes.|
|[CSecurityDesc::SetSacl](#setsacl)|Define informações em uma SACL. Se uma SACL já estiver presente no descritor de segurança, ela será substituída.|
|[CSecurityDesc::ToString](#tostring)|Converte um descritor de segurança em um formato de cadeia de caracteres.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityDesc:: Operator const SECURITY_DESCRIPTOR *](#operator_const_security_descriptor__star)|Retorna um ponteiro para a `SECURITY_DESCRIPTOR` estrutura.|
|[CSecurityDesc:: Operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

A `SECURITY_DESCRIPTOR` estrutura contém as informações de segurança associadas a um objeto. Os aplicativos usam essa estrutura para definir e consultar o status de segurança de um objeto. Consulte também [AtlGetSecurityDescriptor](security-global-functions.md#atlgetsecuritydescriptor).

Os aplicativos não devem modificar `SECURITY_DESCRIPTOR` a estrutura diretamente e, em vez disso, devem usar os métodos de classe fornecidos.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="csecuritydesc"></a>  CSecurityDesc::CSecurityDesc

O construtor.

```
CSecurityDesc() throw();
CSecurityDesc(const CSecurityDesc& rhs) throw(... );
CSecurityDesc(const SECURITY_DESCRIPTOR& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CSecurityDesc` objeto ou `SECURITY_DESCRIPTOR` a estrutura a ser atribuída ao `CSecurityDesc` novo objeto.

### <a name="remarks"></a>Comentários

O `CSecurityDesc` objeto pode, opcionalmente, ser criado `SECURITY_DESCRIPTOR` usando uma estrutura ou um `CSecurityDesc` objeto definido anteriormente.

##  <a name="dtor"></a>  CSecurityDesc::~CSecurityDesc

O destruidor.

```
virtual ~CSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

##  <a name="fromstring"></a>  CSecurityDesc::FromString

Converte um descritor de segurança de formato de cadeia de caracteres em um descritor de segurança funcional válido.

```
bool FromString(LPCTSTR pstr) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o descritor de [segurança de formato de cadeia de caracteres](/windows/desktop/SecAuthZ/security-descriptor-string-format) a ser convertido.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito. Gera uma exceção em caso de falha.

### <a name="remarks"></a>Comentários

A cadeia de caracteres pode ser criada usando [CSecurityDesc:: ToString](#tostring). Converter o descritor de segurança em uma cadeia de caracteres facilita o armazenamento e a transmissão.

Esse método chama [ConvertStringSecurityDescriptorToSecurityDescriptor](/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora).

##  <a name="getcontrol"></a>  CSecurityDesc::GetControl

Recupera informações de controle do descritor de segurança.

```
bool GetControl(SECURITY_DESCRIPTOR_CONTROL* psdc) const throw();
```

### <a name="parameters"></a>Parâmetros

*psdc*<br/>
Ponteiro para uma `SECURITY_DESCRIPTOR_CONTROL` estrutura que recebe as informações de controle do descritor de segurança.

### <a name="return-value"></a>Valor de retorno

Retornará true se o método tiver êxito; false se falhar.

### <a name="remarks"></a>Comentários

Esse método chama [GetSecurityDescriptorControl](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol).

##  <a name="getdacl"></a>  CSecurityDesc::GetDacl

Recupera informações de DACL (lista de controle de acesso discricionário) do descritor de segurança.

```
bool GetDacl(
    CDacl* pDacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDacl*<br/>
Ponteiro para uma `CDacl` estrutura na qual armazenar uma cópia da DACL do descritor de segurança. Se existir uma ACL condicional, o método definirá *pDacl* para o endereço da ACL discricionária do descritor de segurança. Se uma ACL discricionária não existir, nenhum valor será armazenado.

*pbPresent*<br/>
Ponteiro para um valor que indica a presença de uma ACL condicional no descritor de segurança especificado. Se o descritor de segurança contiver uma ACL condicional, esse parâmetro será definido como true. Se o descritor de segurança não contiver uma ACL condicional, esse parâmetro será definido como false.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_DACL_DEFAULTED na `SECURITY_DESCRIPTOR_CONTROL` estrutura se existir uma ACL condicional para o descritor de segurança. Se esse sinalizador for true, a ACL discricionária foi recuperada por um mecanismo padrão; Se for false, a ACL discricionária foi explicitamente especificada por um usuário.

### <a name="return-value"></a>Valor de retorno

Retornará true se o método tiver êxito; false se falhar.

##  <a name="getgroup"></a>  CSecurityDesc::GetGroup

Recupera as informações do grupo primário do descritor de segurança.

```
bool GetGroup(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenado no CDacl.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_GROUP_DEFAULTED na `SECURITY_DESCRIPTOR_CONTROL` estrutura quando o método retorna.

### <a name="return-value"></a>Valor de retorno

Retornará true se o método tiver êxito; false se falhar.

##  <a name="getowner"></a>  CSecurityDesc::GetOwner

Recupera a informatação do proprietário do descritor de segurança.

```
bool GetOwner(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenado no CDacl.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_OWNER_DEFAULTED na `SECURITY_DESCRIPTOR_CONTROL` estrutura quando o método retorna.

### <a name="return-value"></a>Valor de retorno

Retornará true se o método tiver êxito; false se falhar.

##  <a name="getpsecurity_descriptor"></a>  CSecurityDesc::GetPSECURITY_DESCRIPTOR

Retorna um ponteiro para a `SECURITY_DESCRIPTOR` estrutura.

```
const SECURITY_DESCRIPTOR* GetPSECURITY_DESCRIPTOR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a estrutura [SECURITY_DESCRIPTOR](/windows/desktop/api/winnt/ns-winnt-security_descriptor) .

##  <a name="getsacl"></a>  CSecurityDesc::GetSacl

Recupera informações de SACL (lista de controle de acesso) do sistema do descritor de segurança.

```
bool GetSacl(
    CSacl* pSacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSacl*<br/>
Ponteiro para uma `CSacl` estrutura na qual armazenar uma cópia da SACL do descritor de segurança. Se uma ACL do sistema existir, o método definirá *pSacl* para o endereço da ACL do sistema do descritor de segurança. Se uma ACL do sistema não existir, nenhum valor será armazenado.

*pbPresent*<br/>
Ponteiro para um sinalizador que o método define para indicar a presença de uma ACL do sistema no descritor de segurança especificado. Se o descritor de segurança contiver uma ACL do sistema, esse parâmetro será definido como true. Se o descritor de segurança não contiver uma ACL do sistema, esse parâmetro será definido como false.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_SACL_DEFAULTED na `SECURITY_DESCRIPTOR_CONTROL` estrutura se existir uma ACL do sistema para o descritor de segurança.

### <a name="return-value"></a>Valor de retorno

Retornará true se o método tiver êxito; false se falhar.

##  <a name="isdaclautoinherited"></a>  CSecurityDesc::IsDaclAutoInherited

Determina se a DACL (lista de controle de acesso discricionário) está configurada para dar suporte à propagação automática.

```
bool IsDaclAutoInherited() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contiver uma DACL que está configurada para dar suporte à propagação automática de ACEs (entradas de controle de acesso) herdáveis para objetos filho existentes. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O sistema define esse bit quando ele executa o algoritmo de herança automática para o objeto e seus objetos filho existentes.

##  <a name="isdacldefaulted"></a>  CSecurityDesc::IsDaclDefaulted

Determina se o descritor de segurança está configurado com uma DACL (lista de controle de acesso discricionário) padrão.

```
bool IsDaclDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contiver uma DACL padrão; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse sinalizador pode afetar como o sistema trata a DACL, em relação à herança de ACE (Access-Control entry). Por exemplo, se o criador de um objeto não especificar uma DACL, o objeto receberá a DACL padrão do token de acesso do criador. O sistema ignorará esse sinalizador se o sinalizador SE_DACL_PRESENT não estiver definido.

Esse sinalizador é usado para determinar como a DACL final no objeto deve ser computada e não é armazenada fisicamente no controle do descritor de segurança do objeto protegível.

Para definir esse sinalizador, use o método [CSecurityDesc:: SetDacl](#setdacl) .

##  <a name="isdaclpresent"></a>  CSecurityDesc::IsDaclPresent

Determina se o descritor de segurança contém uma DACL (lista de controle de acesso discricionário).

```
bool IsDaclPresent() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contiver uma DACL; caso contrário, false.

### <a name="remarks"></a>Comentários

Se esse sinalizador não estiver definido ou se esse sinalizador for definido e a DACL for nula, o descritor de segurança permitirá acesso completo a todos.

Esse sinalizador é usado para manter as informações de segurança especificadas por um chamador até que o descritor de segurança seja associado a um objeto protegível. Depois que o descritor de segurança estiver associado a um objeto protegível, o sinalizador SE_DACL_PRESENT será sempre definido no controle descritor de segurança.

Para definir esse sinalizador, use o método [CSecurityDesc:: SetDacl](#setdacl) .

##  <a name="isdaclprotected"></a>  CSecurityDesc::IsDaclProtected

Determina se a DACL (lista de controle de acesso discricionário) está configurada para evitar modificações.

```
bool IsDaclProtected() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se a DACL estiver configurada para impedir que o descritor de segurança seja modificado por ACEs (entradas de controle de acesso) herdáveis. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc:: SetDacl](#setdacl) .

Esse método dá suporte à propagação automática de ACEs herdáveis.

##  <a name="isgroupdefaulted"></a>  CSecurityDesc::IsGroupDefaulted

Determina se o identificador de segurança do grupo (SID) do descritor de segurança foi definido por padrão.

```
bool IsGroupDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna true se um mecanismo padrão, em vez do provedor original do descritor de segurança, forneceu o SID do grupo do descritor de segurança. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc:: SetGroup](#setgroup) .

##  <a name="isownerdefaulted"></a>  CSecurityDesc::IsOwnerDefaulted

Determina se o SID (identificador de segurança) do proprietário do descritor de segurança foi definido por padrão.

```
bool IsOwnerDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna true se um mecanismo padrão, em vez do provedor original do descritor de segurança, forneceu o SID do proprietário do descritor de segurança. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc:: SetOwner](#setowner) .

##  <a name="issaclautoinherited"></a>  CSecurityDesc::IsSaclAutoInherited

Determina se a SACL (lista de controle de acesso) do sistema está configurada para dar suporte à propagação automática.

```
bool IsSaclAutoInherited() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contiver uma SACL configurada para oferecer suporte à propagação automática de ACEs (entradas de controle de acesso) herdáveis para objetos filho existentes. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O sistema define esse bit quando ele executa o algoritmo de herança automática para o objeto e seus objetos filho existentes.

##  <a name="issacldefaulted"></a>  CSecurityDesc::IsSaclDefaulted

Determina se o descritor de segurança está configurado com uma SACL (lista de controle de acesso) do sistema padrão.

```
bool IsSaclDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contiver uma SACL padrão; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse sinalizador pode afetar como o sistema trata a SACL, em relação à herança de ACE (Access-Control entry). O sistema ignorará esse sinalizador se o sinalizador SE_SACL_PRESENT não estiver definido.

Para definir esse sinalizador, use o método [CSecurityDesc:: SetSacl](#setsacl) .

##  <a name="issaclpresent"></a>  CSecurityDesc::IsSaclPresent

Determina se o descritor de segurança contém uma SACL (lista de controle de acesso do sistema).

```
bool IsSaclPresent() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contiver uma SACL; caso contrário, false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc:: SetSacl](#setsacl) .

##  <a name="issaclprotected"></a>  CSecurityDesc::IsSaclProtected

Determina se a SACL (lista de controle de acesso) do sistema está configurada para evitar modificações.

```
bool IsSaclProtected() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se a SACL estiver configurada para impedir que o descritor de segurança seja modificado por ACEs (entradas de controle de acesso) herdáveis. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc:: SetSacl](#setsacl) .

Esse método dá suporte à propagação automática de ACEs herdáveis.

##  <a name="isselfrelative"></a>  CSecurityDesc::IsSelfRelative

Determina se o descritor de segurança está em um formato auto-relativo.

```
bool IsSelfRelative() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança estiver em um formato auto-relativo com todas as informações de segurança em um bloco contíguo de memória. Retornará false se o descritor de segurança estiver no formato absoluto. Para obter mais informações, consulte [descritores de segurança absolutos e autônomos](/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##  <a name="makeabsolute"></a>  CSecurityDesc::MakeAbsolute

Chame esse método para converter o descritor de segurança em formato absoluto.

```
bool MakeAbsolute() throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna true se o método tiver sucesso; caso contrário, false.

### <a name="remarks"></a>Comentários

Um descritor de segurança no formato absoluto contém ponteiros para as informações que ele contém, em vez das informações em si. Um descritor de segurança em formato auto-relativo contém as informações em um bloco contíguo de memória. Em um descritor de segurança auto-relativo, uma `SECURITY_DESCRIPTOR` estrutura sempre inicia as informações, mas os outros componentes do descritor de segurança podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança auto-relativo são identificados por deslocamentos do início do descritor de segurança. Esse formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [descritores de segurança absolutos e autônomos](/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##  <a name="makeselfrelative"></a>  CSecurityDesc::MakeSelfRelative

Chame esse método para converter o descritor de segurança em formato auto-relativo.

```
bool MakeSelfRelative() throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna true se o método tiver sucesso; caso contrário, false.

### <a name="remarks"></a>Comentários

Um descritor de segurança no formato absoluto contém ponteiros para as informações que ele contém, em vez de conter as informações em si. Um descritor de segurança em formato auto-relativo contém as informações em um bloco contíguo de memória. Em um descritor de segurança auto-relativo, uma `SECURITY_DESCRIPTOR` estrutura sempre inicia as informações, mas os outros componentes do descritor de segurança podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança são identificados por deslocamentos do início do descritor de segurança. Esse formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [descritores de segurança absolutos e autônomos](/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##  <a name="operator_eq"></a>CSecurityDesc:: Operator =

Operador de atribuição.

```
CSecurityDesc& operator= (const SECURITY_DESCRIPTOR& rhs) throw(...);
CSecurityDesc& operator= (const CSecurityDesc& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `SECURITY_DESCRIPTOR` estrutura ou `CSecurityDesc` o`CSecurityDesc` objeto a ser atribuído ao objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CSecurityDesc` atualizado.

##  <a name="operator_const_security_descriptor__star"></a>CSecurityDesc:: Operator const SECURITY_DESCRIPTOR *

Converte um valor em um ponteiro para a `SECURITY_DESCRIPTOR` estrutura.

```
operator const SECURITY_DESCRIPTOR *() const throw();
```

##  <a name="setcontrol"></a>  CSecurityDesc::SetControl

Define os bits de controle de um descritor de segurança.

```
bool SetControl(
    SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,
    SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet) throw();
```

### <a name="parameters"></a>Parâmetros

*ControlBitsOfInterest*<br/>
Uma máscara SECURITY_DESCRIPTOR_CONTROL que indica os bits de controle a serem definidos. Para obter uma lista dos sinalizadores que podem ser definidos, consulte [SetSecurityDescriptorControl](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorcontrol).

*ControlBitsToSet*<br/>
Uma máscara SECURITY_DESCRIPTOR_CONTROL que indica os novos valores para os bits de controle especificados pela máscara *ControlBitsOfInterest* . Esse parâmetro pode ser uma combinação dos sinalizadores listados para o parâmetro *ControlBitsOfInterest* .

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Esse método chama [SetSecurityDescriptorControl](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorcontrol).

##  <a name="setdacl"></a>  CSecurityDesc::SetDacl

Define informações em uma DACL (lista de controle de acesso discricionário). Se uma DACL já estiver presente no descritor de segurança, ela será substituída.

```
inline void SetDacl(
    bool bPresent = true,
    bool bDefaulted = false) throw(...);

inline void SetDacl(
    const CDacl& Dacl,
    bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*DACL*<br/>
Referência a um `CDacl` objeto que especifica a DACL do descritor de segurança. Esse parâmetro não deve ser nulo. Para definir uma DACL nula no descritor de segurança, a primeira forma do método deve ser usada com *bPresent* definido como false.

*bPresent*<br/>
Especifica um sinalizador que indica a presença de uma DACL no descritor de segurança. Se esse parâmetro for true, o método definirá o sinalizador SE_DACL_PRESENT na `SECURITY_DESCRIPTOR_CONTROL` estrutura e usará os valores nos parâmetros *DACL* e *bDefaulted* . Se for false, o método limpará o sinalizador SE_DACL_PRESENT e *bDefaulted* será ignorado.

*bDefaulted*<br/>
Especifica um sinalizador que indica a origem da DACL. Se esse sinalizador for true, a DACL será recuperada por algum mecanismo padrão. Se for false, a DACL foi especificada explicitamente por um usuário. O método armazena esse valor no sinalizador SE_DACL_DEFAULTED da `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro não for especificado, o sinalizador SE_DACL_DEFAULTED será limpo.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Há uma diferença importante entre uma DACL vazia e inexistente. Quando uma DACL está vazia, ela não contém entradas de controle de acesso e nenhum direito de acesso foi concedido explicitamente. Como resultado, o acesso ao objeto é negado implicitamente. Quando um objeto não tem nenhuma DACL, por outro lado, nenhuma proteção é atribuída ao objeto e qualquer solicitação de acesso é concedida.

##  <a name="setgroup"></a>  CSecurityDesc::SetGroup

Define as informações do grupo primário de um descritor de segurança de formato absoluto, substituindo todas as informações do grupo primário já presentes.

```
bool SetGroup(const CSid& Sid, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*SIDs*<br/>
Referência a um objeto [CSid](../../atl/reference/csid-class.md) para o novo grupo primário do descritor de segurança. Esse parâmetro não deve ser nulo. Um descritor de segurança pode ser marcado como não tendo uma DACL ou uma SACL, mas deve ter um grupo e um proprietário, até mesmo ele é o SID nulo (que é um SID interno com um significado especial).

*bDefaulted*<br/>
Indica se as informações do grupo primário foram derivadas de um mecanismo padrão. Se esse valor for true, ele será informações padrão e o método armazenará esse valor como o sinalizador SE_GROUP_DEFAULTED na `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro for zero, o sinalizador SE_GROUP_DEFAULTED será limpo.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

##  <a name="setowner"></a>  CSecurityDesc::SetOwner

Define as informações de proprietário de um descritor de segurança de formato absoluto. Ele substitui todas as informações de proprietário já presentes.

```
bool SetOwner(const CSid& Sid, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*SIDs*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) do novo proprietário principal do descritor de segurança. Esse parâmetro não deve ser nulo.

*bDefaulted*<br/>
Indica se as informações do proprietário são derivadas de um mecanismo padrão. Se esse valor for true, ele será informações padrão. O método armazena esse valor como o sinalizador SE_OWNER_DEFAULTED na `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro for zero, o sinalizador SE_OWNER_DEFAULTED será limpo.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

##  <a name="setsacl"></a>  CSecurityDesc::SetSacl

Define informações em uma SACL (lista de controle de acesso) do sistema. Se uma SACL já estiver presente no descritor de segurança, ela será substituída.

```
bool SetSacl(const CSacl& Sacl, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Right*<br/>
Ponteiro para um `CSacl` objeto que especifica a SACL do descritor de segurança. Esse parâmetro não deve ser nulo e deve ser um objeto CSacl. Ao contrário de DACLs, não há nenhuma diferença entre NULL e uma SACL vazia, pois os objetos SACL não especificam direitos de acesso, apenas informações de auditoria.

*bDefaulted*<br/>
Especifica um sinalizador que indica a origem da SACL. Se esse sinalizador for true, a SACL será recuperada por algum mecanismo padrão. Se for false, a SACL foi especificada explicitamente por um usuário. O método armazena esse valor no sinalizador SE_SACL_DEFAULTED da `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro não for especificado, o sinalizador SE_SACL_DEFAULTED será limpo.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

##  <a name="tostring"></a>  CSecurityDesc::ToString

Converte um descritor de segurança em um formato de cadeia de caracteres.

```
bool ToString(
    CString* pstr, SECURITY_INFORMATION si = OWNER_SECURITY_INFORMATION |
    GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION |
    SACL_SECURITY_INFORMATION) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que receberá o descritor de [segurança de formato de cadeia de caracteres](/windows/desktop/SecAuthZ/security-descriptor-string-format).

*si*<br/>
Especifica uma combinação de sinalizadores de bit SECURITY_INFORMATION para indicar os componentes do descritor de segurança a serem incluídos na cadeia de caracteres de saída.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Depois que o descritor de segurança estiver no formato de cadeia de caracteres, ele poderá ser armazenado ou transmitido mais facilmente. Use o `CSecurityDesc::FromString` método para converter a cadeia de caracteres de volta em um descritor de segurança.

O parâmetro *si* pode conter os seguintes sinalizadores SECURITY_INFORMATION:

|Valor|Significado|
|-----------|-------------|
|OWNER_SECURITY_INFORMATION|Inclua o proprietário.|
|GROUP_SECURITY_INFORMATION|Inclua o grupo primário.|
|DACL_SECURITY_INFORMATION|Inclua a DACL.|
|SACL_SECURITY_INFORMATION|Inclua a SACL.|

Se a DACL for nula e o bit de controle SE_DACL_PRESENT estiver definido no descritor de segurança de entrada, o método falhará.

Se a DACL for nula e o bit de controle SE_DACL_PRESENT não estiver definido no descritor de segurança de entrada, a cadeia de caracteres do descritor de segurança resultante não terá um componente D:. Consulte [formato de cadeia de caracteres](/windows/desktop/SecAuthZ/security-descriptor-string-format) do descritor de segurança para obter mais detalhes.

Esse método chama [ConvertStringSecurityDescriptorToSecurityDescriptor](/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora).

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[SECURITY_DESCRIPTOR](/windows/desktop/api/winnt/ns-winnt-security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
