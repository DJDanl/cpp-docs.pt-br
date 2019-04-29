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
ms.openlocfilehash: aadaa64a936aee867766dfc0f7a6e190c9691ca6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62277962"
---
# <a name="csecuritydesc-class"></a>Classe CSecurityDesc

Essa classe é um wrapper para o `SECURITY_DESCRIPTOR` estrutura.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CSecurityDesc::FromString](#fromstring)|Converte um descritor de segurança do formato de cadeia de caracteres em um descritor de segurança válido e funcional.|
|[CSecurityDesc::GetControl](#getcontrol)|Recupera informações do descritor de segurança de controle.|
|[CSecurityDesc::GetDacl](#getdacl)|Recupera informações do controle de acesso discricionário (DACL) de lista do descritor de segurança.|
|[CSecurityDesc::GetGroup](#getgroup)|Recupera as informações de grupo primário do descritor de segurança.|
|[CSecurityDesc::GetOwner](#getowner)|Recupera informações do proprietário do descritor de segurança.|
|[CSecurityDesc::GetPSECURITY_DESCRIPTOR](#getpsecurity_descriptor)|Retorna um ponteiro para o `SECURITY_DESCRIPTOR` estrutura.|
|[CSecurityDesc::GetSacl](#getsacl)|Recupera informações de SACL (lista) de controle de acesso do sistema do descritor de segurança.|
|[CSecurityDesc::IsDaclAutoInherited](#isdaclautoinherited)|Determina se a DACL está configurada para dar suporte à propagação automática.|
|[CSecurityDesc::IsDaclDefaulted](#isdacldefaulted)|Determina se o descritor de segurança é configurado com uma DACL padrão.|
|[CSecurityDesc::IsDaclPresent](#isdaclpresent)|Determina se o descritor de segurança conterá uma DACL.|
|[CSecurityDesc::IsDaclProtected](#isdaclprotected)|Determina se a DACL estiver configurada para evitar modificações.|
|[CSecurityDesc::IsGroupDefaulted](#isgroupdefaulted)|Determina se o identificador de segurança de grupo do descritor de segurança (SID) foi definida por padrão.|
|[CSecurityDesc::IsOwnerDefaulted](#isownerdefaulted)|Determina se o proprietário do descritor de segurança SID foi definido por padrão.|
|[CSecurityDesc::IsSaclAutoInherited](#issaclautoinherited)|Determina se a SACL for configurada para dar suporte a propagação automática.|
|[CSecurityDesc::IsSaclDefaulted](#issacldefaulted)|Determina se o descritor de segurança é configurado com um padrão SACL.|
|[CSecurityDesc::IsSaclPresent](#issaclpresent)|Determina se o descritor de segurança conterá uma SACL.|
|[CSecurityDesc::IsSaclProtected](#issaclprotected)|Determina se a SACL for configurada para evitar modificações.|
|[CSecurityDesc::IsSelfRelative](#isselfrelative)|Determina se o descritor de segurança no formato autorrelativo.|
|[CSecurityDesc::MakeAbsolute](#makeabsolute)|Chame esse método para converter o descritor de segurança em formato absoluto.|
|[CSecurityDesc::MakeSelfRelative](#makeselfrelative)|Chame esse método para converter o descritor de segurança em formato autorrelativo.|
|[CSecurityDesc::SetControl](#setcontrol)|Define os bits de controle de um descritor de segurança.|
|[CSecurityDesc::SetDacl](#setdacl)|Define as informações em uma DACL. Se já houver uma DACL no descritor de segurança, ele será substituído.|
|[CSecurityDesc::SetGroup](#setgroup)|Define as informações de grupo primário de um descritor de segurança do formato absoluto, substituindo quaisquer informações de grupo primário já está presentes.|
|[CSecurityDesc::SetOwner](#setowner)|Define as informações do proprietário de um descritor de segurança do formato absoluto, substituindo quaisquer informações sobre o proprietário já está presente.|
|[CSecurityDesc::SetSacl](#setsacl)|Define as informações em uma SACL. Se já houver uma SACL no descritor de segurança, ele será substituído.|
|[CSecurityDesc::ToString](#tostring)|Converte um descritor de segurança em um formato de cadeia de caracteres.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityDesc::operator SECURITY_DESCRIPTOR de const *](#operator_const_security_descriptor__star)|Retorna um ponteiro para o `SECURITY_DESCRIPTOR` estrutura.|
|[CSecurityDesc::operator =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

O `SECURITY_DESCRIPTOR` estrutura contém as informações de segurança associadas ao objeto. Aplicativos usam essa estrutura para definir e consultar o status de segurança de um objeto. Consulte também [AtlGetSecurityDescriptor](security-global-functions.md#atlgetsecuritydescriptor).

Aplicativos não devem modificar o `SECURITY_DESCRIPTOR` estrutura diretamente e, em vez disso, deve usar os métodos da classe fornecidos.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="csecuritydesc"></a>  CSecurityDesc::CSecurityDesc

O construtor.

```
CSecurityDesc() throw();
CSecurityDesc(const CSecurityDesc& rhs) throw(... );
CSecurityDesc(const SECURITY_DESCRIPTOR& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CSecurityDesc` objeto ou `SECURITY_DESCRIPTOR` estrutura para atribuir ao novo `CSecurityDesc` objeto.

### <a name="remarks"></a>Comentários

O `CSecurityDesc` objeto opcionalmente pode ser criado usando um `SECURITY_DESCRIPTOR` estrutura ou definida anteriormente `CSecurityDesc` objeto.

##  <a name="dtor"></a>  CSecurityDesc::~CSecurityDesc

O destruidor.

```
virtual ~CSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

##  <a name="fromstring"></a>  CSecurityDesc::FromString

Converte um descritor de segurança do formato de cadeia de caracteres em um descritor de segurança válido e funcional.

```
bool FromString(LPCTSTR pstr) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o [descritor de segurança do formato de cadeia de caracteres](/windows/desktop/SecAuthZ/security-descriptor-string-format) a ser convertido.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de sucesso. Gera uma exceção em caso de falha.

### <a name="remarks"></a>Comentários

A cadeia de caracteres pode ser criada usando [CSecurityDesc::ToString](#tostring). Converter o descritor de segurança em uma cadeia de caracteres torna mais fácil armazenar e transmitir.

Este método chama [ConvertStringSecurityDescriptorToSecurityDescriptor](/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora).

##  <a name="getcontrol"></a>  CSecurityDesc::GetControl

Recupera informações do descritor de segurança de controle.

```
bool GetControl(SECURITY_DESCRIPTOR_CONTROL* psdc) const throw();
```

### <a name="parameters"></a>Parâmetros

*psdc*<br/>
Ponteiro para um `SECURITY_DESCRIPTOR_CONTROL` estrutura que recebe informações de controle do descritor de segurança.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false se ele falhar.

### <a name="remarks"></a>Comentários

Este método chama [GetSecurityDescriptorControl](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol).

##  <a name="getdacl"></a>  CSecurityDesc::GetDacl

Recupera informações do controle de acesso discricionário (DACL) de lista do descritor de segurança.

```
bool GetDacl(
    CDacl* pDacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDacl*<br/>
Ponteiro para um `CDacl` estrutura na qual armazenar uma cópia da DACL do descritor de segurança. Se uma ACL discricionária existir, o método define *pDacl* para o endereço de ACL discricionário do descritor de segurança. Se uma ACL discricionária não existir, nenhum valor é armazenado.

*pbPresent*<br/>
Ponteiro para um valor que indica a presença de uma ACL discricionária no descritor de segurança especificado. Se o descritor de segurança contém uma ACL discricionária, esse parâmetro for definido como true. Se o descritor de segurança não contém uma ACL discricionária, esse parâmetro é definido como false.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_DACL_DEFAULTED no `SECURITY_DESCRIPTOR_CONTROL` estrutura se uma ACL discricionária existe para o descritor de segurança. Se esse sinalizador for true, a ACL discricionária foi recuperada por um mecanismo padrão; Se for false, a ACL discricionária foi explicitamente especificada por um usuário.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false se ele falhar.

##  <a name="getgroup"></a>  CSecurityDesc::GetGroup

Recupera as informações de grupo primário do descritor de segurança.

```
bool GetGroup(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenada em do CDacl.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_GROUP_DEFAULTED no `SECURITY_DESCRIPTOR_CONTROL` estrutura quando o método retorna.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false se ele falhar.

##  <a name="getowner"></a>  CSecurityDesc::GetOwner

Recupera informações do proprietário do descritor de segurança.

```
bool GetOwner(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenada em do CDacl.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_OWNER_DEFAULTED no `SECURITY_DESCRIPTOR_CONTROL` estrutura quando o método retorna.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false se ele falhar.

##  <a name="getpsecurity_descriptor"></a>  CSecurityDesc::GetPSECURITY_DESCRIPTOR

Retorna um ponteiro para o `SECURITY_DESCRIPTOR` estrutura.

```
const SECURITY_DESCRIPTOR* GetPSECURITY_DESCRIPTOR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o [SECURITY_DESCRIPTOR](/windows/desktop/api/winnt/ns-winnt-_security_descriptor) estrutura.

##  <a name="getsacl"></a>  CSecurityDesc::GetSacl

Recupera informações de SACL (lista) de controle de acesso do sistema do descritor de segurança.

```
bool GetSacl(
    CSacl* pSacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSacl*<br/>
Ponteiro para um `CSacl` estrutura na qual armazenar uma cópia da SACL do descritor de segurança. Se não houver uma ACL de sistema, o método define *pSacl* para o endereço do sistema do descritor de segurança ACL. Se um sistema de ACL não existir, nenhum valor é armazenado.

*pbPresent*<br/>
Define um ponteiro para um sinalizador, o método para indicar a presença de um sistema de ACL no descritor de segurança especificado. Se o descritor de segurança contém um sistema de ACL, esse parâmetro for definido como true. Se o descritor de segurança não contém um sistema de ACL, esse parâmetro é definido como false.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido como o valor do sinalizador SE_SACL_DEFAULTED no `SECURITY_DESCRIPTOR_CONTROL` estrutura se não houver uma ACL de sistema para o descritor de segurança.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false se ele falhar.

##  <a name="isdaclautoinherited"></a>  CSecurityDesc::IsDaclAutoInherited

Determina se a lista de controle de acesso discricionário (DACL) está configurada para dar suporte à propagação automática.

```
bool IsDaclAutoInherited() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança conterá uma DACL que está configurada para dar suporte à propagação automática de entradas de controle de acesso herdadas (ACEs) para objetos filho existentes. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O sistema define esse bit quando ele executa o algoritmo de herança automática para o objeto e seus objetos filho existente.

##  <a name="isdacldefaulted"></a>  CSecurityDesc::IsDaclDefaulted

Determina se o descritor de segurança é configurado com uma lista de padrão controle de acesso discricionário (DACL).

```
bool IsDaclDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança conterá uma DACL, padrão false caso contrário.

### <a name="remarks"></a>Comentários

Este sinalizador pode afetar como o sistema trata a DACL, diz respeito à herança do ACE (entrada) de controle de acesso. Por exemplo, se o criador de um objeto não especificar uma DACL, o objeto recebe a DACL padrão do token de acesso do criador. O sistema ignora esse sinalizador se o sinalizador SE_DACL_PRESENT não está definido.

Este sinalizador é usado para determinar como a DACL no objeto final deve ser calculada e não é armazenado fisicamente no controle do descritor de segurança do objeto protegível.

Para definir esse sinalizador, use o [CSecurityDesc::SetDacl](#setdacl) método.

##  <a name="isdaclpresent"></a>  CSecurityDesc::IsDaclPresent

Determina se o descritor de segurança contém uma lista de controle de acesso discricionário (DACL).

```
bool IsDaclPresent() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança conterá uma DACL, false caso contrário.

### <a name="remarks"></a>Comentários

Se este sinalizador não for definido, ou se esse sinalizador estiver definido e a DACL for NULL, o descritor de segurança permite acesso completo a todos.

Este sinalizador é usado para armazenar as informações de segurança especificadas por um chamador até que o descritor de segurança esteja associado um objeto protegível. Depois que o descritor de segurança estiver associado um objeto protegível, o sinalizador SE_DACL_PRESENT é sempre definido no controle do descritor de segurança.

Para definir esse sinalizador, use o [CSecurityDesc::SetDacl](#setdacl) método.

##  <a name="isdaclprotected"></a>  CSecurityDesc::IsDaclProtected

Determina se a lista de controle de acesso discricionário (DACL) estiver configurada para evitar modificações.

```
bool IsDaclProtected() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a DACL estiver configurada para impedir que o descritor de segurança que está sendo modificado por entradas de controle de acesso herdadas (ACEs). Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o [CSecurityDesc::SetDacl](#setdacl) método.

Esse método dá suporte à propagação automática das ACEs herdáveis.

##  <a name="isgroupdefaulted"></a>  CSecurityDesc::IsGroupDefaulted

Determina se o identificador de segurança de grupo do descritor de segurança (SID) foi definida por padrão.

```
bool IsGroupDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se um mecanismo padrão, em vez do provedor original do descritor de segurança, fornecido o descritor de segurança SID do grupo. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o [CSecurityDesc::SetGroup](#setgroup) método.

##  <a name="isownerdefaulted"></a>  CSecurityDesc::IsOwnerDefaulted

Determina se o identificador de segurança do proprietário do descritor de segurança (SID) foi definida por padrão.

```
bool IsOwnerDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se um mecanismo padrão, em vez do provedor original do descritor de segurança, fornecido o SID de proprietário do descritor de segurança. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o [CSecurityDesc::SetOwner](#setowner) método.

##  <a name="issaclautoinherited"></a>  CSecurityDesc::IsSaclAutoInherited

Determina se a lista de controle de acesso do sistema (SACL) está configurada para dar suporte à propagação automática.

```
bool IsSaclAutoInherited() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança contém uma SACL que está configurada para dar suporte à propagação automática de entradas de controle de acesso herdadas (ACEs) para objetos filho existentes. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O sistema define esse bit quando ele executa o algoritmo de herança automática para o objeto e seus objetos filho existente.

##  <a name="issacldefaulted"></a>  CSecurityDesc::IsSaclDefaulted

Determina se o descritor de segurança é configurado com uma lista de controle de acesso de sistema (SACL) padrão.

```
bool IsSaclDefaulted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança conterá uma SACL, padrão false caso contrário.

### <a name="remarks"></a>Comentários

Este sinalizador pode afetar como o sistema trata a SACL, diz respeito à herança do ACE (entrada) de controle de acesso. O sistema ignora esse sinalizador se o sinalizador SE_SACL_PRESENT não está definido.

Para definir esse sinalizador, use o [CSecurityDesc::SetSacl](#setsacl) método.

##  <a name="issaclpresent"></a>  CSecurityDesc::IsSaclPresent

Determina se o descritor de segurança contém uma lista de controle de acesso do sistema (SACL).

```
bool IsSaclPresent() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança conterá uma SACL, false caso contrário.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o [CSecurityDesc::SetSacl](#setsacl) método.

##  <a name="issaclprotected"></a>  CSecurityDesc::IsSaclProtected

Determina se a lista de controle de acesso do sistema (SACL) estiver configurada para evitar modificações.

```
bool IsSaclProtected() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a SACL for configurada para impedir que o descritor de segurança que está sendo modificado por entradas de controle de acesso herdadas (ACEs). Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o [CSecurityDesc::SetSacl](#setsacl) método.

Esse método dá suporte à propagação automática das ACEs herdáveis.

##  <a name="isselfrelative"></a>  CSecurityDesc::IsSelfRelative

Determina se o descritor de segurança no formato autorrelativo.

```
bool IsSelfRelative() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o descritor de segurança está no formato autorrelativo com todas as informações de segurança em um bloco contíguo de memória. Retornará false se o descritor de segurança está no formato absoluto. Para obter mais informações, consulte [Absolute e descritores de segurança Self-Relative](/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##  <a name="makeabsolute"></a>  CSecurityDesc::MakeAbsolute

Chame esse método para converter o descritor de segurança em formato absoluto.

```
bool MakeAbsolute() throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false caso contrário.

### <a name="remarks"></a>Comentários

Um descritor de segurança no formato absoluto contém ponteiros para as informações que ele contém, em vez das próprias informações. Um descritor de segurança no formato autorrelativo contém as informações em um bloco contíguo de memória. Em um descritor de segurança autorrelativo um `SECURITY_DESCRIPTOR` as informações de estrutura sempre é iniciado, mas o descritor de segurança do que outros componentes podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança autorrelativo são identificados por deslocamentos desde o início do descritor de segurança. Esse formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [Absolute e descritores de segurança Self-Relative](/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##  <a name="makeselfrelative"></a>  CSecurityDesc::MakeSelfRelative

Chame esse método para converter o descritor de segurança em formato autorrelativo.

```
bool MakeSelfRelative() throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o método tiver êxito, false caso contrário.

### <a name="remarks"></a>Comentários

Um descritor de segurança no formato absoluto contém ponteiros para as informações que ele contém, em vez de que contém as informações em si. Um descritor de segurança no formato autorrelativo contém as informações em um bloco contíguo de memória. Em um descritor de segurança autorrelativo um `SECURITY_DESCRIPTOR` as informações de estrutura sempre é iniciado, mas o descritor de segurança do que outros componentes podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança são identificados por deslocamentos desde o início do descritor de segurança. Esse formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [Absolute e descritores de segurança Self-Relative](/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##  <a name="operator_eq"></a>  CSecurityDesc::operator =

Operador de atribuição.

```
CSecurityDesc& operator= (const SECURITY_DESCRIPTOR& rhs) throw(...);
CSecurityDesc& operator= (const CSecurityDesc& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `SECURITY_DESCRIPTOR` estrutura ou `CSecurityDesc` objeto para atribuir ao `CSecurityDesc` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CSecurityDesc` objeto.

##  <a name="operator_const_security_descriptor__star"></a>  CSecurityDesc::operator SECURITY_DESCRIPTOR de const *

Converte um valor para um ponteiro para o `SECURITY_DESCRIPTOR` estrutura.

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
Uma máscara SECURITY_DESCRIPTOR_CONTROL que indica os bits de controle para definir. Para obter uma lista dos sinalizadores que podem ser definidas, consulte [SetSecurityDescriptorControl](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorcontrol).

*ControlBitsToSet*<br/>
Uma máscara SECURITY_DESCRIPTOR_CONTROL que indica os novos valores para os bits de controle especificados pela *ControlBitsOfInterest* máscara. Esse parâmetro pode ser uma combinação de sinalizadores listados para o *ControlBitsOfInterest* parâmetro.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Este método chama [SetSecurityDescriptorControl](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorcontrol).

##  <a name="setdacl"></a>  CSecurityDesc::SetDacl

Define as informações em uma lista de controle de acesso discricionário (DACL). Se já houver uma DACL no descritor de segurança, ele será substituído.

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
Referência a um `CDacl` objeto que especifica a DACL para o descritor de segurança. Esse parâmetro não deve ser NULL. Para definir uma DACL NULL no descritor de segurança, o primeiro formulário do método deve ser usado com *bPresent* definido como false.

*bPresent*<br/>
Especifica um sinalizador que indica a presença de uma DACL no descritor de segurança. Se esse parâmetro for true, o método define o sinalizador SE_DACL_PRESENT na `SECURITY_DESCRIPTOR_CONTROL` estruturar e usa os valores a *Dacl* e *bDefaulted* parâmetros. Se for false, o método limpa o sinalizador SE_DACL_PRESENT, e *bDefaulted* será ignorado.

*bDefaulted*<br/>
Especifica um sinalizador que indica a origem da DACL. Se esse sinalizador for true, a DACL foram obtida por algum mecanismo padrão. Se for false, a DACL foi especificada explicitamente por um usuário. O método armazena esse valor no sinalizador SE_DACL_DEFAULTED o `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro não for especificado, o sinalizador SE_DACL_DEFAULTED está desmarcado.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Há uma diferença importante entre vazio e uma DACL não existente. Quando uma DACL está vazia, ele contém sem entradas de controle de acesso e sem direitos de acesso foi concedidos explicitamente. Como resultado, o acesso ao objeto é negado implicitamente. Quando um objeto não tem nenhum DACL, por outro lado, sem a proteção é atribuída ao objeto e qualquer solicitação de acesso é concedida.

##  <a name="setgroup"></a>  CSecurityDesc::SetGroup

Define as informações de grupo primário de um descritor de segurança do formato absoluto, substituindo quaisquer informações de grupo primário já está presentes.

```
bool SetGroup(const CSid& Sid, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*SID*<br/>
Referência a um [CSid](../../atl/reference/csid-class.md) objeto para o grupo primário do novo do descritor de segurança. Esse parâmetro não deve ser NULL. Um descritor de segurança pode ser marcado como não tendo uma DACL ou uma SACL, mas ele deve ter um grupo e um proprietário, mesmo essas são o SID nulo (que é um SID interno com um significado especial).

*bDefaulted*<br/>
Indica se as informações de grupo primário foi derivadas de um mecanismo padrão. Se esse valor for true, ele é informações padrão e o método armazena esse valor como o sinalizador SE_GROUP_DEFAULTED no `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro for zero, o sinalizador SE_GROUP_DEFAULTED está desmarcado.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

##  <a name="setowner"></a>  CSecurityDesc::SetOwner

Define as informações do proprietário de um descritor de segurança do formato absoluto. Ele substitui qualquer informação de proprietário já está presente.

```
bool SetOwner(const CSid& Sid, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*SID*<br/>
O [CSid](../../atl/reference/csid-class.md) objeto para o novo proprietário do principal do descritor de segurança. Esse parâmetro não deve ser NULL.

*bDefaulted*<br/>
Indica se as informações do proprietário são derivadas de um mecanismo padrão. Se esse valor for true, ele é informações padrão. O método armazena esse valor como o sinalizador SE_OWNER_DEFAULTED no `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro for zero, o sinalizador SE_OWNER_DEFAULTED está desmarcado.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

##  <a name="setsacl"></a>  CSecurityDesc::SetSacl

Define as informações em uma lista de controle de acesso do sistema (SACL). Se já houver uma SACL no descritor de segurança, ele será substituído.

```
bool SetSacl(const CSacl& Sacl, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*SACL*<br/>
Ponteiro para um `CSacl` objeto que especifica a SACL para o descritor de segurança. Esse parâmetro não deve ser NULL e deve ser um objeto CSacl. Ao contrário de DACLs, não há nenhuma diferença entre NULL e uma SACL vazia, como objetos SACL não especificam os direitos de acesso, apenas informações de auditoria.

*bDefaulted*<br/>
Especifica um sinalizador que indica a origem da SACL. Se esse sinalizador for true, a SACL foram obtida por algum mecanismo padrão. Se for false, a SACL foi especificada explicitamente por um usuário. O método armazena esse valor no sinalizador SE_SACL_DEFAULTED o `SECURITY_DESCRIPTOR_CONTROL` estrutura. Se esse parâmetro não for especificado, o sinalizador SE_SACL_DEFAULTED está desmarcado.

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
Ponteiro para uma cadeia de caracteres terminada em nulo que recebe o [descritor de segurança do formato de cadeia de caracteres](/windows/desktop/SecAuthZ/security-descriptor-string-format).

*si*<br/>
Especifica uma combinação de sinalizadores de bit SECURITY_INFORMATION para indicar os componentes do descritor de segurança para incluir na cadeia de saída.

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Depois que o descritor de segurança está no formato de cadeia de caracteres, ele pode mais facilmente ser armazenado ou transmitido. Use o `CSecurityDesc::FromString` método para converter a cadeia de caracteres de volta em um descritor de segurança.

O *si* parâmetro pode conter os seguintes sinalizadores SECURITY_INFORMATION:

|Valor|Significado|
|-----------|-------------|
|OWNER_SECURITY_INFORMATION|Inclua o proprietário.|
|GROUP_SECURITY_INFORMATION|Inclui o grupo primário.|
|DACL_SECURITY_INFORMATION|Inclua a DACL.|
|SACL_SECURITY_INFORMATION|Inclua a SACL.|

Se a DACL for NULL e o bit de controle SE_DACL_PRESENT é definido no descritor de segurança de entrada, o método falhará.

Se a DACL for NULL e o bit de controle SE_DACL_PRESENT não está definido no descritor de segurança de entrada, a cadeia de caracteres de descritor de segurança resultante não tem um componente de d:. Ver [formato de cadeia de caracteres do descritor de segurança](/windows/desktop/SecAuthZ/security-descriptor-string-format) para obter mais detalhes.

Este método chama [ConvertStringSecurityDescriptorToSecurityDescriptor](/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora).

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[SECURITY_DESCRIPTOR](/windows/desktop/api/winnt/ns-winnt-_security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
