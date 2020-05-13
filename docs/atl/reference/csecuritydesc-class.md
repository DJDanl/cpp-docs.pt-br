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
ms.openlocfilehash: 926e4e0a795982479188d90ed866bf5e2584c187
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330964"
---
# <a name="csecuritydesc-class"></a>Classe CSecurityDesc

Esta aula é um `SECURITY_DESCRIPTOR` invólucro para a estrutura.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CSecurityDesc::FromString](#fromstring)|Converte um descritor de segurança em formato de string em um descritor de segurança funcional válido.|
|[CSecurityDesc::GetControl](#getcontrol)|Recupera informações de controle do descritor de segurança.|
|[CSecurityDesc::GetDacl](#getdacl)|Recupera informações da lista de controle de acesso discricionária (DACL) do descritor de segurança.|
|[CSecurityDesc::GetGroup](#getgroup)|Recupera as informações do grupo principal do descritor de segurança.|
|[CSecurityDesc::GetOwner](#getowner)|Recupera o informaton do proprietário do descritor de segurança.|
|[CSecurityDesc::GetPSECURITY_DESCRIPTOR](#getpsecurity_descriptor)|Devolve um ponteiro `SECURITY_DESCRIPTOR` para a estrutura.|
|[CSecurityDesc::GetSacl](#getsacl)|Recupera informações da Lista de Controle de Acesso do Sistema (SACL) do descritor de segurança.|
|[CSecurityDesc::IsDaclAutoHered](#isdaclautoinherited)|Determina se o DACL está configurado para suportar a propagação automática.|
|[CSecurityDesc::IsDaclDefaulted](#isdacldefaulted)|Determina se o descritor de segurança está configurado com um DACL padrão.|
|[CSecurityDesc::IsDaclPresent](#isdaclpresent)|Determina se o descritor de segurança contém um DACL.|
|[CSecurityDesc::IsDaclProtected](#isdaclprotected)|Determina se o DACL está configurado para evitar modificações.|
|[CSecurityDesc::IsGroupDefaulted](#isgroupdefaulted)|Determina se o identificador de segurança de grupo (SID) do descritor de segurança foi definido por padrão.|
|[CSecurityDesc::IsOwnerDefaulted](#isownerdefaulted)|Determina se o SID do proprietário do descritor de segurança foi definido por padrão.|
|[CSecurityDesc::IsSaclAutoInherited](#issaclautoinherited)|Determina se o SACL está configurado para suportar a propagação automática.|
|[CSecurityDesc::IsSaclDefaulted](#issacldefaulted)|Determina se o descritor de segurança está configurado com um SACL padrão.|
|[CSecurityDesc::IsSaclPresent](#issaclpresent)|Determina se o descritor de segurança contém um SACL.|
|[CSecurityDesc::IsSaclProtected](#issaclprotected)|Determina se o SACL está configurado para evitar modificações.|
|[CSecurityDesc::IsSelfRelative](#isselfrelative)|Determina se o descritor de segurança está em formato auto-relativo.|
|[CSecurityDesc::MakeAbsolute](#makeabsolute)|Chame este método para converter o descritor de segurança em formato absoluto.|
|[CSecurityDesc::MakeSelfRelative](#makeselfrelative)|Chame este método para converter o descritor de segurança em formato auto-relativo.|
|[CSecurityDesc::SetControl](#setcontrol)|Define os bits de controle de um descritor de segurança.|
|[CSecurityDesc::SetDacl](#setdacl)|Define informações em um DACL. Se um DACL já estiver presente no descritor de segurança, ele será substituído.|
|[CSecurityDesc::SetGroup](#setgroup)|Define as informações do grupo principal de um descritor de segurança de formato absoluto, substituindo quaisquer informações de grupo primária já presentes.|
|[CSecurityDesc::SetOwner](#setowner)|Define as informações do proprietário de um descritor de segurança de formato absoluto, substituindo qualquer informação do proprietário já presente.|
|[CSecurityDesc::SetSacl](#setsacl)|Define informações em um SACL. Se um SACL já estiver presente no descritor de segurança, ele será substituído.|
|[CSecurityDesc::ToString](#tostring)|Converte um descritor de segurança em um formato de string.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityDesc::operador const SECURITY_DESCRIPTOR *](#operator_const_security_descriptor__star)|Devolve um ponteiro `SECURITY_DESCRIPTOR` para a estrutura.|
|[CSecurityDesc::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

A `SECURITY_DESCRIPTOR` estrutura contém as informações de segurança associadas a um objeto. Os aplicativos usam essa estrutura para definir e consultar o status de segurança de um objeto. Consulte também [AtlGetSecurityDescriptor](security-global-functions.md#atlgetsecuritydescriptor).

Os aplicativos não `SECURITY_DESCRIPTOR` devem modificar a estrutura diretamente e, em vez disso, devem usar os métodos de classe fornecidos.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="csecuritydesccsecuritydesc"></a><a name="csecuritydesc"></a>CSecurityDesc::CSecurityDesc

O construtor.

```
CSecurityDesc() throw();
CSecurityDesc(const CSecurityDesc& rhs) throw(... );
CSecurityDesc(const SECURITY_DESCRIPTOR& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
O `CSecurityDesc` objeto `SECURITY_DESCRIPTOR` ou estrutura para `CSecurityDesc` atribuir ao novo objeto.

### <a name="remarks"></a>Comentários

O `CSecurityDesc` objeto pode ser criado `SECURITY_DESCRIPTOR` opcionalmente usando uma `CSecurityDesc` estrutura ou um objeto previamente definido.

## <a name="csecuritydesccsecuritydesc"></a><a name="dtor"></a>CSecurityDesc::~CSecurityDesc

O destruidor.

```
virtual ~CSecurityDesc() throw();
```

### <a name="remarks"></a>Comentários

O destruidor libera todos os recursos alocados.

## <a name="csecuritydescfromstring"></a><a name="fromstring"></a>CSecurityDesc::FromString

Converte um descritor de segurança em formato de string em um descritor de segurança funcional válido.

```
bool FromString(LPCTSTR pstr) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Ponteiro para uma seqüência de seqüência de terminadas nula que contém o [descritor de segurança em formato de string](/windows/win32/SecAuthZ/security-descriptor-string-format) a ser convertido.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro no sucesso. Abre uma exceção no fracasso.

### <a name="remarks"></a>Comentários

A seqüência de string pode ser criada usando [CSecurityDesc::ToString](#tostring). A conversão do descritor de segurança em uma string facilita a armazenamento e a transmissão.

Este método chama [ConvertStringSecurityDescriptorToSecurityDescriptor](/windows/win32/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptorw).

## <a name="csecuritydescgetcontrol"></a><a name="getcontrol"></a>CSecurityDesc::GetControl

Recupera informações de controle do descritor de segurança.

```
bool GetControl(SECURITY_DESCRIPTOR_CONTROL* psdc) const throw();
```

### <a name="parameters"></a>Parâmetros

*psdc*<br/>
Ponteiro para `SECURITY_DESCRIPTOR_CONTROL` uma estrutura que recebe as informações de controle do descritor de segurança.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso se falhar.

### <a name="remarks"></a>Comentários

Este método chama [GetSecurityDescriptorControl](/windows/win32/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol).

## <a name="csecuritydescgetdacl"></a><a name="getdacl"></a>CSecurityDesc::GetDacl

Recupera informações da lista de controle de acesso discricionária (DACL) do descritor de segurança.

```
bool GetDacl(
    CDacl* pDacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDacl*<br/>
Ponteiro para `CDacl` uma estrutura na qual armazenar uma cópia do DACL do descritor de segurança. Se existir uma ACL discricionária, o método define *pDacl* para o endereço da ACL discricionária do descritor de segurança. Se uma ACL discricionária não existir, nenhum valor será armazenado.

*pbPresente*<br/>
Ponteiro para um valor que indique a presença de uma ACL discricionária no descritor de segurança especificado. Se o descritor de segurança contiver uma ACL discricionária, este parâmetro será definido como verdadeiro. Se o descritor de segurança não contiver uma ACL discricionária, este parâmetro será definido como falso.

*pbDefaulted*<br/>
Ponteiro para uma bandeira definida para o `SECURITY_DESCRIPTOR_CONTROL` valor da bandeira SE_DACL_DEFAULTED na estrutura se houver uma ACL discricionária para o descritor de segurança. Se essa bandeira for verdadeira, a ACL discricionária foi recuperada por um mecanismo padrão; se falsa, a ACL discricionária foi explicitamente especificada por um usuário.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso se falhar.

## <a name="csecuritydescgetgroup"></a><a name="getgroup"></a>CSecurityDesc::GetGroup

Recupera as informações do grupo principal do descritor de segurança.

```
bool GetGroup(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psid*<br/>
Pointer para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenado no CDacl.

*pbDefaulted*<br/>
Ponteiro para uma bandeira definida para o `SECURITY_DESCRIPTOR_CONTROL` valor da bandeira SE_GROUP_DEFAULTED na estrutura quando o método retornar.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso se falhar.

## <a name="csecuritydescgetowner"></a><a name="getowner"></a>CSecurityDesc::GetOwner

Recupera o informaton do proprietário do descritor de segurança.

```
bool GetOwner(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psid*<br/>
Pointer para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenado no CDacl.

*pbDefaulted*<br/>
Ponteiro para uma bandeira definida para o `SECURITY_DESCRIPTOR_CONTROL` valor da bandeira SE_OWNER_DEFAULTED na estrutura quando o método retornar.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso se falhar.

## <a name="csecuritydescgetpsecurity_descriptor"></a><a name="getpsecurity_descriptor"></a>CSecurityDesc::GetPSECURITY_DESCRIPTOR

Devolve um ponteiro `SECURITY_DESCRIPTOR` para a estrutura.

```
const SECURITY_DESCRIPTOR* GetPSECURITY_DESCRIPTOR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a estrutura [SECURITY_DESCRIPTOR.](/windows/win32/api/winnt/ns-winnt-security_descriptor)

## <a name="csecuritydescgetsacl"></a><a name="getsacl"></a>CSecurityDesc::GetSacl

Recupera informações da Lista de Controle de Acesso do Sistema (SACL) do descritor de segurança.

```
bool GetSacl(
    CSacl* pSacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSacl*<br/>
Ponteiro para `CSacl` uma estrutura na qual armazenar uma cópia do SACL do descritor de segurança. Se existir uma ACL do sistema, o método define *pSacl* para o endereço da ACL do sistema do descritor de segurança. Se uma ACL do sistema não existir, nenhum valor será armazenado.

*pbPresente*<br/>
Ponteiro para um sinalizador o método define para indicar a presença de um ACL do sistema no descritor de segurança especificado. Se o descritor de segurança contiver um ACL do sistema, este parâmetro será definido como verdadeiro. Se o descritor de segurança não contiver uma ACL do sistema, este parâmetro será definido como falso.

*pbDefaulted*<br/>
Ponteiro para um sinalizador definido para o `SECURITY_DESCRIPTOR_CONTROL` valor da bandeira SE_SACL_DEFAULTED na estrutura se existir um ACL do sistema para o descritor de segurança.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso se falhar.

## <a name="csecuritydescisdaclautoinherited"></a><a name="isdaclautoinherited"></a>CSecurityDesc::IsDaclAutoHered

Determina se a lista de controle de acesso discricionário (DACL) está configurada para suportar a propagação automática.

```
bool IsDaclAutoInherited() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna-se verdadeiro se o descritor de segurança contiver um DACL configurado para suportar a propagação automática de entradas hereditárias de controle de acesso (ACEs) a objetos-filho existentes. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O sistema define essa parte quando executa o algoritmo de herança automática para o objeto e seus objetos infantis existentes.

## <a name="csecuritydescisdacldefaulted"></a><a name="isdacldefaulted"></a>CSecurityDesc::IsDaclDefaulted

Determina se o descritor de segurança está configurado com uma lista de controle de acesso discricionária padrão (DACL).

```
bool IsDaclDefaulted() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o descritor de segurança contiver um DACL padrão, falso de outra forma.

### <a name="remarks"></a>Comentários

Essa bandeira pode afetar a forma como o sistema trata o DACL, com relação à herança ace (access-control entry). Por exemplo, se o criador de um objeto não especificar um DACL, o objeto receberá o DACL padrão do token de acesso do criador. O sistema ignora esta bandeira se a bandeira SE_DACL_PRESENT não estiver definida.

Este sinalizador é usado para determinar como o DACL final no objeto deve ser calculado e não é armazenado fisicamente no controle do descritor de segurança do objeto securável.

Para definir este sinalizador, use o método [CSecurityDesc::SetDacl.](#setdacl)

## <a name="csecuritydescisdaclpresent"></a><a name="isdaclpresent"></a>CSecurityDesc::IsDaclPresent

Determina se o descritor de segurança contém uma lista de controle de acesso discricionária (DACL).

```
bool IsDaclPresent() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o descritor de segurança contiver um DACL, falso de outra forma.

### <a name="remarks"></a>Comentários

Se esta bandeira não estiver definida ou se esta bandeira estiver definida e o DACL for NULA, o descritor de segurança permite acesso total a todos.

Este sinalizador é usado para conter as informações de segurança especificadas por um chamador até que o descritor de segurança esteja associado a um objeto securável. Uma vez que o descritor de segurança esteja associado a um objeto securável, a bandeira SE_DACL_PRESENT é sempre definida no controle do descritor de segurança.

Para definir este sinalizador, use o método [CSecurityDesc::SetDacl.](#setdacl)

## <a name="csecuritydescisdaclprotected"></a><a name="isdaclprotected"></a>CSecurityDesc::IsDaclProtected

Determina se a lista de controle de acesso discricionário (DACL) está configurada para evitar modificações.

```
bool IsDaclProtected() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna-se verdadeiro se o DACL estiver configurado para evitar que o descritor de segurança seja modificado por entradas hereditárias de controle de acesso (ACEs). Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir este sinalizador, use o método [CSecurityDesc::SetDacl.](#setdacl)

Este método suporta a propagação automática de ACEs hereditárias.

## <a name="csecuritydescisgroupdefaulted"></a><a name="isgroupdefaulted"></a>CSecurityDesc::IsGroupDefaulted

Determina se o identificador de segurança de grupo (SID) do descritor de segurança foi definido por padrão.

```
bool IsGroupDefaulted() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se um mecanismo padrão, em vez do provedor original do descritor de segurança, fornecer o SID do descritor de segurança. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc::SetGroup.](#setgroup)

## <a name="csecuritydescisownerdefaulted"></a><a name="isownerdefaulted"></a>CSecurityDesc::IsOwnerDefaulted

Determina se o identificador de segurança do descritor de segurança (SID) foi definido por padrão.

```
bool IsOwnerDefaulted() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se um mecanismo padrão, em vez do provedor original do descritor de segurança, fornecer o SID proprietário do descritor de segurança. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir esse sinalizador, use o método [CSecurityDesc::SetOwner.](#setowner)

## <a name="csecuritydescissaclautoinherited"></a><a name="issaclautoinherited"></a>CSecurityDesc::IsSaclAutoInherited

Determina se a lista de controle de acesso do sistema (SACL) está configurada para suportar a propagação automática.

```
bool IsSaclAutoInherited() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna-se verdadeiro se o descritor de segurança contiver um SACL configurado para suportar a propagação automática de entradas hereditárias de controle de acesso (ACEs) a objetos-filho existentes. Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O sistema define essa parte quando executa o algoritmo de herança automática para o objeto e seus objetos infantis existentes.

## <a name="csecuritydescissacldefaulted"></a><a name="issacldefaulted"></a>CSecurityDesc::IsSaclDefaulted

Determina se o descritor de segurança está configurado com uma lista padrão de controle de acesso ao sistema (SACL).

```
bool IsSaclDefaulted() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o descritor de segurança contiver um SACL padrão, falso de outra forma.

### <a name="remarks"></a>Comentários

Essa bandeira pode afetar a forma como o sistema trata o SACL, com relação à herança ace (access-control entry). O sistema ignora esta bandeira se a bandeira SE_SACL_PRESENT não estiver definida.

Para definir este sinalizador, use o método [CSecurityDesc::SetSacl.](#setsacl)

## <a name="csecuritydescissaclpresent"></a><a name="issaclpresent"></a>CSecurityDesc::IsSaclPresent

Determina se o descritor de segurança contém uma lista de controle de acesso do sistema (SACL).

```
bool IsSaclPresent() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o descritor de segurança contiver um SACL, falso de outra forma.

### <a name="remarks"></a>Comentários

Para definir este sinalizador, use o método [CSecurityDesc::SetSacl.](#setsacl)

## <a name="csecuritydescissaclprotected"></a><a name="issaclprotected"></a>CSecurityDesc::IsSaclProtected

Determina se a lista de controle de acesso do sistema (SACL) está configurada para evitar modificações.

```
bool IsSaclProtected() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna-se verdadeiro se o SACL estiver configurado para evitar que o descritor de segurança seja modificado por entradas hereditárias de controle de acesso (ACEs). Caso contrário, retornará false.

### <a name="remarks"></a>Comentários

Para definir este sinalizador, use o método [CSecurityDesc::SetSacl.](#setsacl)

Este método suporta a propagação automática de ACEs hereditárias.

## <a name="csecuritydescisselfrelative"></a><a name="isselfrelative"></a>CSecurityDesc::IsSelfRelative

Determina se o descritor de segurança está em formato auto-relativo.

```
bool IsSelfRelative() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o descritor de segurança estiver em formato auto-relativo com todas as informações de segurança em um bloco de memória contíguo. Retorna falso se o descritor de segurança estiver em formato absoluto. Para obter mais informações, consulte [Descritores de segurança absoluta e auto-relativo](/windows/win32/SecAuthZ/absolute-and-self-relative-security-descriptors).

## <a name="csecuritydescmakeabsolute"></a><a name="makeabsolute"></a>CSecurityDesc::MakeAbsolute

Chame este método para converter o descritor de segurança em formato absoluto.

```
bool MakeAbsolute() throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso de outra forma.

### <a name="remarks"></a>Comentários

Um descritor de segurança em formato absoluto contém ponteiros para as informações que ele contém, em vez da informação em si. Um descritor de segurança em formato auto-relativo contém as informações em um bloco de memória contíguo. Em um descritor de segurança `SECURITY_DESCRIPTOR` auto-relativo, uma estrutura sempre inicia as informações, mas os outros componentes do descritor de segurança podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança auto-relativo são identificados por deslocamentos desde o início do descritor de segurança. Este formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [Descritores de segurança absoluta e auto-relativo](/windows/win32/SecAuthZ/absolute-and-self-relative-security-descriptors).

## <a name="csecuritydescmakeselfrelative"></a><a name="makeselfrelative"></a>CSecurityDesc::MakeSelfRelative

Chame este método para converter o descritor de segurança em formato auto-relativo.

```
bool MakeSelfRelative() throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o método for bem sucedido, falso de outra forma.

### <a name="remarks"></a>Comentários

Um descritor de segurança em formato absoluto contém ponteiros para as informações que ele contém, em vez de conter as informações em si. Um descritor de segurança em formato auto-relativo contém as informações em um bloco de memória contíguo. Em um descritor de segurança `SECURITY_DESCRIPTOR` auto-relativo, uma estrutura sempre inicia as informações, mas os outros componentes do descritor de segurança podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança são identificados por deslocamentos desde o início do descritor de segurança. Este formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [Descritores de segurança absoluta e auto-relativo](/windows/win32/SecAuthZ/absolute-and-self-relative-security-descriptors).

## <a name="csecuritydescoperator-"></a><a name="operator_eq"></a>CSecurityDesc::operador =

Operador de atribuição.

```
CSecurityDesc& operator= (const SECURITY_DESCRIPTOR& rhs) throw(...);
CSecurityDesc& operator= (const CSecurityDesc& rhs) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rhs*<br/>
A `SECURITY_DESCRIPTOR` estrutura `CSecurityDesc` ou objeto para `CSecurityDesc` atribuir ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna o `CSecurityDesc` objeto atualizado.

## <a name="csecuritydescoperator-const-security_descriptor-"></a><a name="operator_const_security_descriptor__star"></a>CSecurityDesc::operador const SECURITY_DESCRIPTOR *

Lança um valor para um `SECURITY_DESCRIPTOR` ponteiro para a estrutura.

```
operator const SECURITY_DESCRIPTOR *() const throw();
```

## <a name="csecuritydescsetcontrol"></a><a name="setcontrol"></a>CSecurityDesc::SetControl

Define os bits de controle de um descritor de segurança.

```
bool SetControl(
    SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,
    SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet) throw();
```

### <a name="parameters"></a>Parâmetros

*ControlBitsOfInterest*<br/>
Uma máscara SECURITY_DESCRIPTOR_CONTROL que indica os bits de controle a serem definidos. Para obter uma lista dos sinalizadores que podem ser definidos, consulte [SetSecurityDescriptorControl](/windows/win32/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorcontrol).

*ControlBitsToSet*<br/>
Uma máscara SECURITY_DESCRIPTOR_CONTROL que indica os novos valores para os bits de controle especificados pela máscara *ControlBitsOfInterest.* Este parâmetro pode ser uma combinação dos sinalizadores listados para o parâmetro *ControlBitsOfInterest.*

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Este método chama [SetSecurityDescriptorControl](/windows/win32/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorcontrol).

## <a name="csecuritydescsetdacl"></a><a name="setdacl"></a>CSecurityDesc::SetDacl

Define as informações em uma lista de controle de acesso discricionária (DACL). Se um DACL já estiver presente no descritor de segurança, ele será substituído.

```
inline void SetDacl(
    bool bPresent = true,
    bool bDefaulted = false) throw(...);

inline void SetDacl(
    const CDacl& Dacl,
    bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Dacl*<br/>
Referência a `CDacl` um objeto especificando o DACL para o descritor de segurança. Este parâmetro não deve ser NULO. Para definir um DACL NULO no descritor de segurança, a primeira forma do método deve ser usada com *bPresente* definido como falso.

*bPresente*<br/>
Especifica uma bandeira indicando a presença de um DACL no descritor de segurança. Se esse parâmetro for verdadeiro, o método `SECURITY_DESCRIPTOR_CONTROL` define a SE_DACL_PRESENT bandeira na estrutura e usa os valores nos parâmetros *Dacl* e *bDefaulted.* Se for falso, o método limpa o SE_DACL_PRESENT bandeira e *bDefaulted* é ignorado.

*bDefaulted*<br/>
Especifica uma bandeira indicando a origem do DACL. Se esta bandeira for verdadeira, o DACL foi recuperado por algum mecanismo padrão. Se for falso, o DACL foi explicitamente especificado por um usuário. O método armazena esse valor na `SECURITY_DESCRIPTOR_CONTROL` bandeira SE_DACL_DEFAULTED da estrutura. Se este parâmetro não for especificado, a bandeira SE_DACL_DEFAULTED será liberada.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Há uma diferença importante entre um DACL vazio e um DACL inexistente. Quando um DACL está vazio, ele não contém entradas de controle de acesso e nenhum direito de acesso foi explicitamente concedido. Como resultado, o acesso ao objeto é implicitamente negado. Quando um objeto não tem DACL, por outro lado, nenhuma proteção é atribuída ao objeto, e qualquer solicitação de acesso é concedida.

## <a name="csecuritydescsetgroup"></a><a name="setgroup"></a>CSecurityDesc::SetGroup

Define as informações do grupo principal de um descritor de segurança de formato absoluto, substituindo quaisquer informações de grupo primária já presentes.

```
bool SetGroup(const CSid& Sid, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Sid*<br/>
Referência a um objeto [CSid](../../atl/reference/csid-class.md) para o novo grupo principal do descritor de segurança. Este parâmetro não deve ser NULO. Um descritor de segurança pode ser marcado como não ter um DACL ou um SACL, mas deve ter um grupo e um proprietário, mesmo que estes sejam o SID NULO (que é um SID embutido com um significado especial).

*bDefaulted*<br/>
Indica se as informações do grupo principal foram derivadas de um mecanismo padrão. Se esse valor for verdadeiro, são informações padrão, e o método `SECURITY_DESCRIPTOR_CONTROL` armazena esse valor como a SE_GROUP_DEFAULTED bandeira na estrutura. Se este parâmetro for zero, a bandeira SE_GROUP_DEFAULTED é limpa.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

## <a name="csecuritydescsetowner"></a><a name="setowner"></a>CSecurityDesc::SetOwner

Define as informações do proprietário de um descritor de segurança de formato absoluto. Ele substitui qualquer informação do proprietário já presente.

```
bool SetOwner(const CSid& Sid, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Sid*<br/>
O objeto [CSid](../../atl/reference/csid-class.md) para o novo proprietário principal do descritor de segurança. Este parâmetro não deve ser NULO.

*bDefaulted*<br/>
Indica se as informações do proprietário são derivadas de um mecanismo padrão. Se esse valor for verdadeiro, é informação padrão. O método armazena esse valor como `SECURITY_DESCRIPTOR_CONTROL` a bandeira SE_OWNER_DEFAULTED na estrutura. Se este parâmetro for zero, a bandeira SE_OWNER_DEFAULTED é limpa.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

## <a name="csecuritydescsetsacl"></a><a name="setsacl"></a>CSecurityDesc::SetSacl

Define informações em uma lista de controle de acesso do sistema (SACL). Se um SACL já estiver presente no descritor de segurança, ele será substituído.

```
bool SetSacl(const CSacl& Sacl, bool bDefaulted = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Sacl*<br/>
Ponteiro para `CSacl` um objeto especificando o SACL para o descritor de segurança. Este parâmetro não deve ser NULO e deve ser um objeto CSacl. Ao contrário dos DACLs, não há diferença entre NULL e um SACL vazio, pois os objetos SACL não especificam direitos de acesso, apenas informações de auditoria.

*bDefaulted*<br/>
Especifica uma bandeira indicando a origem do SACL. Se esta bandeira for verdadeira, a SACL foi recuperada por algum mecanismo padrão. Se for falso, o SACL foi explicitamente especificado por um usuário. O método armazena esse valor na `SECURITY_DESCRIPTOR_CONTROL` bandeira SE_SACL_DEFAULTED da estrutura. Se este parâmetro não for especificado, a bandeira SE_SACL_DEFAULTED será limpa.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

## <a name="csecuritydesctostring"></a><a name="tostring"></a>CSecurityDesc::ToString

Converte um descritor de segurança em um formato de string.

```
bool ToString(
    CString* pstr, SECURITY_INFORMATION si = OWNER_SECURITY_INFORMATION |
    GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION |
    SACL_SECURITY_INFORMATION) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Ponteiro para uma seqüência de seqüência de terminadas nula que receberá o [descritor de segurança em formato de string](/windows/win32/SecAuthZ/security-descriptor-string-format).

*si*<br/>
Especifica uma combinação de SECURITY_INFORMATION bits para indicar os componentes do descritor de segurança a serem incluemos na seqüência de saída.

### <a name="return-value"></a>Valor retornado

Retorna true em caso de êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Uma vez que o descritor de segurança esteja em formato de string, ele pode ser armazenado ou transmitido mais facilmente. Use `CSecurityDesc::FromString` o método para converter a seqüência de volta em um descritor de segurança.

O parâmetro *si* pode conter as seguintes bandeiras SECURITY_INFORMATION:

|Valor|Significado|
|-----------|-------------|
|OWNER_SECURITY_INFORMATION|Inclua o dono.|
|GROUP_SECURITY_INFORMATION|Inclua o grupo principal.|
|DACL_SECURITY_INFORMATION|Inclua o DACL.|
|SACL_SECURITY_INFORMATION|Inclua o SACL.|

Se o DACL for NULL e a SE_DACL_PRESENT bit de controle for definida no descritor de segurança de entrada, o método falhará.

Se o DACL for NULL e a broca de controle de SE_DACL_PRESENT não estiver definida no descritor de segurança de entrada, a seqüência de descritores de segurança resultante não terá um componente D: . Consulte [o formato de string do descritor de segurança](/windows/win32/SecAuthZ/security-descriptor-string-format) para obter mais detalhes.

Este método chama [ConvertStringSecurityDescriptorToSecurityDescriptor](/windows/win32/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptorw).

## <a name="see-also"></a>Confira também

[Amostra de segurança](../../overview/visual-cpp-samples.md)<br/>
[Security_descriptor](/windows/win32/api/winnt/ns-winnt-security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
