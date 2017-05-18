---
title: Classe CSecurityDesc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CSecurityDesc class
ms.assetid: 3767a327-378f-4690-ba40-4d9f6a1f5ee4
caps.latest.revision: 24
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 334081ba67c3b034c4b8170b095fcd77d712dda6
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="csecuritydesc-class"></a>Classe CSecurityDesc
Essa classe é um wrapper para o **SECURITY_DESCRIPTOR** estrutura.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CSecurityDesc
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSecurityDesc::CSecurityDesc](#csecuritydesc)|O construtor.|  
|[CSecurityDesc:: ~ CSecurityDesc](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSecurityDesc::FromString](#fromstring)|Converte um descritor de segurança do formato de cadeia de caracteres em um descritor de segurança válido e funcional.|  
|[CSecurityDesc::GetControl](#getcontrol)|Recupera informações do descritor de segurança de controle.|  
|[CSecurityDesc::GetDacl](#getdacl)|Recupera informações do controle de acesso discricionário (DACL) lista do descritor de segurança.|  
|[CSecurityDesc::GetGroup](#getgroup)|Recupera as informações de grupo primário do descritor de segurança.|  
|[CSecurityDesc::GetOwner](#getowner)|Recupera informações do proprietário do descritor de segurança.|  
|[CSecurityDesc::GetPSECURITY_DESCRIPTOR](#getpsecurity_descriptor)|Retorna um ponteiro para o **SECURITY_DESCRIPTOR** estrutura.|  
|[CSecurityDesc::GetSacl](#getsacl)|Recupera informações de lista (SACL) do sistema de controle de acesso do descritor de segurança.|  
|[CSecurityDesc::IsDaclAutoInherited](#isdaclautoinherited)|Determina se a DACL está configurada para dar suporte a propagação automática.|  
|[CSecurityDesc::IsDaclDefaulted](#isdacldefaulted)|Determina se o descritor de segurança está configurado com uma DACL padrão.|  
|[CSecurityDesc::IsDaclPresent](#isdaclpresent)|Determina se o descritor de segurança contém uma DACL.|  
|[CSecurityDesc::IsDaclProtected](#isdaclprotected)|Determina se a DACL é configurada para evitar modificações.|  
|[CSecurityDesc::IsGroupDefaulted](#isgroupdefaulted)|Determina se o identificador de segurança do grupo do descritor de segurança (SID) foi definido por padrão.|  
|[CSecurityDesc::IsOwnerDefaulted](#isownerdefaulted)|Determina se o proprietário do descritor de segurança SID foi definido por padrão.|  
|[CSecurityDesc::IsSaclAutoInherited](#issaclautoinherited)|Determina se a SACL está configurada para dar suporte a propagação automática.|  
|[CSecurityDesc::IsSaclDefaulted](#issacldefaulted)|Determina se o descritor de segurança está configurado com um padrão SACL.|  
|[CSecurityDesc::IsSaclPresent](#issaclpresent)|Determina se o descritor de segurança contém uma SACL.|  
|[CSecurityDesc::IsSaclProtected](#issaclprotected)|Determina se a SACL estiver configurada para evitar modificações.|  
|[CSecurityDesc::IsSelfRelative](#isselfrelative)|Determina se o descritor de segurança no formato autorrelativo.|  
|[CSecurityDesc::MakeAbsolute](#makeabsolute)|Chame este método para converter o descritor de segurança em formato absoluto.|  
|[CSecurityDesc::MakeSelfRelative](#makeselfrelative)|Chame este método para converter o descritor de segurança no formato auto-relativo.|  
|[CSecurityDesc::SetControl](#setcontrol)|Define os bits de controle de um descritor de segurança.|  
|[CSecurityDesc::SetDacl](#setdacl)|Define as informações em uma DACL. Se uma DACL já está presente no descritor de segurança, ele será substituído.|  
|[CSecurityDesc::SetGroup](#setgroup)|Define as informações de grupo primário de um descritor de segurança do formato absoluto, substituir as informações de grupo primário já está presentes.|  
|[CSecurityDesc::SetOwner](#setowner)|Define as informações de proprietário de um descritor de segurança do formato absoluto, substituir as informações do proprietário já está presentes.|  
|[CSecurityDesc::SetSacl](#setsacl)|Define as informações em um SACL. Se um SACL já está presente no descritor de segurança, ele será substituído.|  
|[CSecurityDesc::ToString](#tostring)|Converte um descritor de segurança em um formato de cadeia de caracteres.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[SECURITY_DESCRIPTOR const CSecurityDesc::operator *](#operator_const_security_descriptor__star)|Retorna um ponteiro para o **SECURITY_DESCRIPTOR** estrutura.|  
|[CSecurityDesc::operator =](#operator_eq)|Operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 O **SECURITY_DESCRIPTOR** estrutura contém as informações de segurança associadas ao objeto. Aplicativos usam essa estrutura para definir e consultar o status de segurança de um objeto. Consulte também [AtlGetSecurityDescriptor](security-global-functions.md#atlgetsecuritydescriptor).  
  
 Aplicativos não devem modificar o **SECURITY_DESCRIPTOR** estrutura diretamente e, em vez disso, deve usar os métodos da classe fornecidos.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
##  <a name="csecuritydesc"></a>CSecurityDesc::CSecurityDesc  
 O construtor.  
  
```
CSecurityDesc() throw();
CSecurityDesc(const CSecurityDesc& rhs) throw(... );  
CSecurityDesc(const SECURITY_DESCRIPTOR& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O `CSecurityDesc` objeto ou **SECURITY_DESCRIPTOR** estrutura para atribuir ao novo `CSecurityDesc` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CSecurityDesc` objeto opcionalmente pode ser criado usando um **SECURITY_DESCRIPTOR** estrutura ou definida anteriormente `CSecurityDesc` objeto.  
  
##  <a name="dtor"></a>CSecurityDesc:: ~ CSecurityDesc  
 O destruidor.  
  
```
virtual ~CSecurityDesc() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O destruidor libera todos os recursos alocados.  
  
##  <a name="fromstring"></a>CSecurityDesc::FromString  
 Converte um descritor de segurança do formato de cadeia de caracteres em um descritor de segurança válido e funcional.  
  
```
bool FromString(LPCTSTR pstr) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstr`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o [descritor de segurança do formato de cadeia de caracteres](http://msdn.microsoft.com/library/windows/desktop/aa379570) a ser convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de sucesso. Gera uma exceção em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres pode ser criada usando [CSecurityDesc::ToString](#tostring). Converter o descritor de segurança em uma cadeia de caracteres torna mais fácil armazenar e transmitir.  
  
 Este método só está disponível com o Windows 2000 e posterior porque chama [ConvertStringSecurityDescriptorToSecurityDescriptor](http://msdn.microsoft.com/library/windows/desktop/aa376401).  
  
##  <a name="getcontrol"></a>CSecurityDesc::GetControl  
 Recupera informações do descritor de segurança de controle.  
  
```
bool GetControl(SECURITY_DESCRIPTOR_CONTROL* psdc) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *psdc*  
 Ponteiro para um **SECURITY_DESCRIPTOR_CONTROL** estrutura que recebe informações de controle do descritor de segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO se ele falhar.  
  
### <a name="remarks"></a>Comentários  
 Esse método só é significativo quando usando o Windows 2000 ou posterior, enquanto ela chama [GetSecurityDescriptorControl](http://msdn.microsoft.com/library/windows/desktop/aa446647).  
  
##  <a name="getdacl"></a>CSecurityDesc::GetDacl  
 Recupera informações do controle de acesso discricionário (DACL) lista do descritor de segurança.  
  
```
bool GetDacl(
    CDacl* pDacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDacl`  
 Ponteiro para um `CDacl` estrutura na qual armazenar uma cópia da DACL do descritor de segurança. Se uma condicional **ACL** existir, o método define `pDacl` para o endereço da segurança descritor do discricionário **ACL**. Se uma condicional **ACL** não existir, nenhum valor é armazenado.  
  
 `pbPresent`  
 Ponteiro para um valor que indica a presença de um discricionário **ACL** no descritor de segurança especificado. Se o descritor de segurança contém uma condicional **ACL**, esse parâmetro for definido como true. Se o descritor de segurança não contiver uma condicional **ACL**, esse parâmetro for definido como false.  
  
 `pbDefaulted`  
 Ponteiro para um sinalizador é definido como o valor do sinalizador SE_DACL_DEFAULTED no **SECURITY_DESCRIPTOR_CONTROL** estrutura se uma condicional **ACL** existe para o descritor de segurança. Se esse sinalizador for true, o discricionário **ACL** foi recuperado por um mecanismo padrão; se for false, o discricionário **ACL** tenha sido explicitamente especificado por um usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO se ele falhar.  
  
##  <a name="getgroup"></a>CSecurityDesc::GetGroup  
 Recupera as informações de grupo primário do descritor de segurança.  
  
```
bool GetGroup(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSid`  
 Ponteiro para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenada no CDacl.  
  
 `pbDefaulted`  
 Ponteiro para um sinalizador é definido como o valor do sinalizador SE_GROUP_DEFAULTED no **SECURITY_DESCRIPTOR_CONTROL** estrutura quando o método retorna.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO se ele falhar.  
  
##  <a name="getowner"></a>CSecurityDesc::GetOwner  
 Recupera informações do proprietário do descritor de segurança.  
  
```
bool GetOwner(
    CSid* pSid,
    bool* pbDefaulted = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSid`  
 Ponteiro para um [CSid](../../atl/reference/csid-class.md) (identificador de segurança) que recebe uma cópia do grupo armazenada no CDacl.  
  
 `pbDefaulted`  
 Ponteiro para um sinalizador é definido como o valor do sinalizador SE_OWNER_DEFAULTED no **SECURITY_DESCRIPTOR_CONTROL** estrutura quando o método retorna.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO se ele falhar.  
  
##  <a name="getpsecurity_descriptor"></a>CSecurityDesc::GetPSECURITY_DESCRIPTOR  
 Retorna um ponteiro para o **SECURITY_DESCRIPTOR** estrutura.  
  
```
const SECURITY_DESCRIPTOR* GetPSECURITY_DESCRIPTOR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o [SECURITY_DESCRIPTOR](http://msdn.microsoft.com/library/windows/desktop/aa379561) estrutura.  
  
##  <a name="getsacl"></a>CSecurityDesc::GetSacl  
 Recupera informações de lista (SACL) do sistema de controle de acesso do descritor de segurança.  
  
```
bool GetSacl(
    CSacl* pSacl,
    bool* pbPresent = NULL,
    bool* pbDefaulted = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSacl`  
 Ponteiro para um `CSacl` estrutura na qual armazenar uma cópia da SACL do descritor de segurança. Se um sistema **ACL** existir, o método define `pSacl` para o endereço do sistema do descritor de segurança **ACL**. Se um sistema **ACL** não existir, nenhum valor é armazenado.  
  
 `pbPresent`  
 Ponteiro para um sinalizador que define o método para indicar a presença de um sistema **ACL** no descritor de segurança especificado. Se o descritor de segurança contém um sistema **ACL**, esse parâmetro for definido como true. Se o descritor de segurança não contém um sistema **ACL**, esse parâmetro for definido como false.  
  
 `pbDefaulted`  
 Ponteiro para um sinalizador é definido como o valor do sinalizador SE_SACL_DEFAULTED no **SECURITY_DESCRIPTOR_CONTROL** estrutura se um sistema **ACL** existe para o descritor de segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO se ele falhar.  
  
##  <a name="isdaclautoinherited"></a>CSecurityDesc::IsDaclAutoInherited  
 Determina se a lista de controle de acesso discricionário (DACL) está configurada para dar suporte a propagação automática.  
  
```
bool IsDaclAutoInherited() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o descritor de segurança contém uma DACL que é configurada para oferecer suporte a propagação automática de entradas herdadas de controle de acesso (ACEs) para objetos filho existentes. Caso contrário, retornará false.  
  
### <a name="remarks"></a>Comentários  
 O sistema define esse bit quando ele executa o algoritmo de herança automática para o objeto e seus objetos filho existente.  
  
##  <a name="isdacldefaulted"></a>CSecurityDesc::IsDaclDefaulted  
 Determina se o descritor de segurança está configurado com uma lista de controle de acesso discricionário (DACL) padrão.  
  
```
bool IsDaclDefaulted() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o descritor de segurança contém uma DACL, padrão FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Esse sinalizador pode afetar como o sistema trata a DACL, em relação a herança do controle de acesso (ACE) de entrada. Por exemplo, se o criador de um objeto não especifica uma DACL, o objeto recebe a DACL padrão de token de acesso do criador. O sistema ignora esse sinalizador, se o sinalizador SE_DACL_PRESENT não está definido.  
  
 Este sinalizador é usado para determinar como a DACL final no objeto deve ser computada e não é armazenado fisicamente no controle do descritor de segurança do objeto protegível.  
  
 Para definir esse sinalizador, use o [CSecurityDesc::SetDacl](#setdacl) método.  
  
##  <a name="isdaclpresent"></a>CSecurityDesc::IsDaclPresent  
 Determina se o descritor de segurança contém uma lista de controle de acesso discricionário (DACL).  
  
```
bool IsDaclPresent() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o descritor de segurança contém uma DACL FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Se este sinalizador não for definido, ou se esse sinalizador é definido e a DACL for NULL, o descritor de segurança permite acesso completo a todos os usuários.  
  
 Este sinalizador é usado para armazenar as informações de segurança especificadas por um chamador até que o descritor de segurança está associado um objeto protegível. Quando o descritor de segurança está associado um objeto seguro, o sinalizador SE_DACL_PRESENT é sempre definido no controle do descritor de segurança.  
  
 Para definir esse sinalizador, use o [CSecurityDesc::SetDacl](#setdacl) método.  
  
##  <a name="isdaclprotected"></a>CSecurityDesc::IsDaclProtected  
 Determina se a lista de controle de acesso discricionário (DACL) é configurada para evitar modificações.  
  
```
bool IsDaclProtected() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a DACL é configurada para impedir que o descritor de segurança que está sendo modificado por entradas de controle de acesso herdáveis (ACEs). Caso contrário, retornará false.  
  
### <a name="remarks"></a>Comentários  
 Para definir esse sinalizador, use o [CSecurityDesc::SetDacl](#setdacl) método.  
  
 Esse método só é significativo para o Windows 2000 ou posterior, pois somente o Windows 2000 dá suporte a propagação automática de ACEs herdáveis.  
  
##  <a name="isgroupdefaulted"></a>CSecurityDesc::IsGroupDefaulted  
 Determina se o identificador de segurança do grupo do descritor de segurança (SID) foi definido por padrão.  
  
```
bool IsGroupDefaulted() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se um mecanismo padrão, em vez do provedor original do descritor de segurança, fornecido o descritor de segurança SID do grupo. Caso contrário, retornará false.  
  
### <a name="remarks"></a>Comentários  
 Para definir esse sinalizador, use o [CSecurityDesc::SetGroup](#setgroup) método.  
  
##  <a name="isownerdefaulted"></a>CSecurityDesc::IsOwnerDefaulted  
 Determina se o identificador de segurança do proprietário do descritor de segurança (SID) foi definido por padrão.  
  
```
bool IsOwnerDefaulted() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se um mecanismo padrão, em vez do provedor original do descritor de segurança, fornecido o SID de proprietário do descritor de segurança. Caso contrário, retornará false.  
  
### <a name="remarks"></a>Comentários  
 Para definir esse sinalizador, use o [CSecurityDesc::SetOwner](#setowner) método.  
  
##  <a name="issaclautoinherited"></a>CSecurityDesc::IsSaclAutoInherited  
 Determina se a lista de controle de acesso do sistema (SACL) está configurada para dar suporte a propagação automática.  
  
```
bool IsSaclAutoInherited() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o descritor de segurança contém uma SACL que é configurada para oferecer suporte a propagação automática de entradas herdadas de controle de acesso (ACEs) para objetos filho existentes. Caso contrário, retornará false.  
  
### <a name="remarks"></a>Comentários  
 O sistema define esse bit quando ele executa o algoritmo de herança automática para o objeto e seus objetos filho existente.  
  
##  <a name="issacldefaulted"></a>CSecurityDesc::IsSaclDefaulted  
 Determina se o descritor de segurança está configurado com uma lista de controle de acesso do sistema (SACL) padrão.  
  
```
bool IsSaclDefaulted() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o descritor de segurança contém um padrão SACL, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Esse sinalizador pode afetar como o sistema trata a SACL, em relação a herança do controle de acesso (ACE) de entrada. O sistema ignora esse sinalizador, se o sinalizador SE_SACL_PRESENT não está definido.  
  
 Para definir esse sinalizador, use o [CSecurityDesc::SetSacl](#setsacl) método.  
  
##  <a name="issaclpresent"></a>CSecurityDesc::IsSaclPresent  
 Determina se o descritor de segurança contém uma lista de controle de acesso do sistema (SACL).  
  
```
bool IsSaclPresent() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o descritor de segurança contém uma SACL FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para definir esse sinalizador, use o [CSecurityDesc::SetSacl](#setsacl) método.  
  
##  <a name="issaclprotected"></a>CSecurityDesc::IsSaclProtected  
 Determina se a lista de controle de acesso do sistema (SACL) está configurada para evitar modificações.  
  
```
bool IsSaclProtected() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a SACL está configurada para impedir que o descritor de segurança que está sendo modificado por entradas de controle de acesso herdáveis (ACEs). Caso contrário, retornará false.  
  
### <a name="remarks"></a>Comentários  
 Para definir esse sinalizador, use o [CSecurityDesc::SetSacl](#setsacl) método.  
  
 Esse método só é significativo para o Windows 2000 ou posterior, pois somente o Windows 2000 dá suporte a propagação automática de ACEs herdáveis.  
  
##  <a name="isselfrelative"></a>CSecurityDesc::IsSelfRelative  
 Determina se o descritor de segurança no formato autorrelativo.  
  
```
bool IsSelfRelative() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o descritor de segurança está no formato auto-relativo com todas as informações de segurança em um bloco contínuo de memória. Retorna falso se o descritor de segurança está no formato absoluto. Para obter mais informações, consulte [Absolute e descritores de segurança Self-Relative](http://msdn.microsoft.com/library/windows/desktop/aa374807).  
  
##  <a name="makeabsolute"></a>CSecurityDesc::MakeAbsolute  
 Chame este método para converter o descritor de segurança em formato absoluto.  
  
```
bool MakeAbsolute() throw(...);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Um descritor de segurança no formato absoluto contém ponteiros para as informações que ele contém, em vez de informações em si. Um descritor de segurança no formato autorrelativo contém as informações em um bloco contínuo de memória. Em um descritor de segurança autorrelativo um **SECURITY_DESCRIPTOR** estrutura sempre inicia as informações, mas o descritor de segurança do que outros componentes podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança autorrelativo são identificados por deslocamentos desde o início do descritor de segurança. Esse formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [Absolute e descritores de segurança Self-Relative](http://msdn.microsoft.com/library/windows/desktop/aa374807).  
  
##  <a name="makeselfrelative"></a>CSecurityDesc::MakeSelfRelative  
 Chame este método para converter o descritor de segurança no formato auto-relativo.  
  
```
bool MakeSelfRelative() throw(...);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o método for bem-sucedido, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Um descritor de segurança no formato absoluto contém ponteiros para as informações que ele contém, em vez de que contém as informações em si. Um descritor de segurança no formato autorrelativo contém as informações em um bloco contínuo de memória. Em um descritor de segurança autorrelativo um **SECURITY_DESCRIPTOR** estrutura sempre inicia as informações, mas o descritor de segurança do que outros componentes podem seguir a estrutura em qualquer ordem. Em vez de usar endereços de memória, os componentes do descritor de segurança são identificados por deslocamentos desde o início do descritor de segurança. Esse formato é útil quando um descritor de segurança deve ser armazenado em um disco ou transmitido por meio de um protocolo de comunicação. Para obter mais informações, consulte [Absolute e descritores de segurança Self-Relative](http://msdn.microsoft.com/library/windows/desktop/aa374807).  
  
##  <a name="operator_eq"></a>CSecurityDesc::operator =  
 Operador de atribuição.  
  
```
CSecurityDesc& operator= (const SECURITY_DESCRIPTOR& rhs) throw(...);  
CSecurityDesc& operator= (const CSecurityDesc& rhs) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rhs`  
 O **SECURITY_DESCRIPTOR** estrutura ou `CSecurityDesc` objeto para atribuir ao `CSecurityDesc` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CSecurityDesc` objeto.  
  
##  <a name="operator_const_security_descriptor__star"></a>SECURITY_DESCRIPTOR const CSecurityDesc::operator *  
 Converte um valor para um ponteiro para o **SECURITY_DESCRIPTOR** estrutura.  
  
```  
operator const SECURITY_DESCRIPTOR *() const throw();
```  
  
##  <a name="setcontrol"></a>CSecurityDesc::SetControl  
 Define os bits de controle de um descritor de segurança.  
  
```
bool SetControl(
    SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest, 
    SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ControlBitsOfInterest`  
 Um **SECURITY_DESCRIPTOR_CONTROL** máscara que indica os bits de controle para definir. Para obter uma lista dos sinalizadores que pode ser definida, consulte [SetSecurityDescriptorControl](http://msdn.microsoft.com/library/windows/desktop/aa379582\(v=vs.85\).aspx).  
  
 `ControlBitsToSet`  
 Uma máscara `SECURITY_DESCRIPTOR_CONTROL` que indica os novos valores para os bits de controle especificados pela máscara `ControlBitsOfInterest`. Esse parâmetro pode ser uma combinação dos sinalizadores listados para o parâmetro `ControlBitsOfInterest`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método está disponível somente no Windows 2000 e posterior, enquanto ela chama [SetSecurityDescriptorControl](http://msdn.microsoft.com/library/windows/desktop/aa379582\(v=vs.85\).aspx).  
  
##  <a name="setdacl"></a>CSecurityDesc::SetDacl  
 Define as informações em uma lista de controle de acesso discricionário (DACL). Se uma DACL já está presente no descritor de segurança, ele será substituído.  
  
```
inline void SetDacl(  
    bool bPresent = true,
    bool bDefaulted = false) throw(...);

inline void SetDacl(  
    const CDacl& Dacl,
    bool bDefaulted = false) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *DACL*  
 Referência a um `CDacl` objeto especificando a DACL para o descritor de segurança. Esse parâmetro não deve ser NULL. Para definir uma DACL NULL no descritor de segurança, o primeiro formulário do método deve ser usado com `bPresent` definido como false.  
  
 `bPresent`  
 Especifica um sinalizador que indica a presença de uma DACL no descritor de segurança. Se esse parâmetro for true, o método define o sinalizador SE_DACL_PRESENT no **SECURITY_DESCRIPTOR_CONTROL** estrutura e usa os valores a *Dacl* e `bDefaulted` parâmetros. Se for false, o método limpa o sinalizador SE_DACL_PRESENT, e `bDefaulted` é ignorado.  
  
 `bDefaulted`  
 Especifica um sinalizador que indica a origem da DACL. Se esse sinalizador for true, a DACL foram obtida por algum mecanismo padrão. Se for false, a DACL foi especificada explicitamente por um usuário. O método armazena esse valor no sinalizador SE_DACL_DEFAULTED o **SECURITY_DESCRIPTOR_CONTROL** estrutura. Se esse parâmetro não for especificado, o sinalizador SE_DACL_DEFAULTED está desmarcado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Há uma diferença importante entre vazio e uma DACL não existe. Quando uma DACL estiver vazia, ele contém sem entradas de controle de acesso e sem direitos de acesso tem sido concedidos explicitamente. Como resultado, o acesso ao objeto é negado implicitamente. Por outro lado, quando um objeto não tiver nenhuma DACL, nenhuma proteção é atribuída ao objeto e qualquer solicitação de acesso é concedida.  
  
##  <a name="setgroup"></a>CSecurityDesc::SetGroup  
 Define as informações de grupo primário de um descritor de segurança do formato absoluto, substituir as informações de grupo primário já está presentes.  
  
```
bool SetGroup(const CSid& Sid, bool bDefaulted = false) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Sid`  
 Referência a um [CSid](../../atl/reference/csid-class.md) objeto para o novo grupo de principal do descritor de segurança. Esse parâmetro não deve ser NULL. Um descritor de segurança pode ser marcado como não tendo uma DACL ou um SACL, mas ele deve ter um grupo e um proprietário, mesmo essas são o SID do nulo (que é um SID interno com um significado especial).  
  
 `bDefaulted`  
 Indica se as informações de grupo primário foi derivadas de um mecanismo padrão. Se o valor for true, é informações padrão e o método armazena esse valor como o sinalizador de SE_GROUP_DEFAULTED o **SECURITY_DESCRIPTOR_CONTROL** estrutura. Se esse parâmetro for zero, o sinalizador SE_GROUP_DEFAULTED está desmarcado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="setowner"></a>CSecurityDesc::SetOwner  
 Define as informações de proprietário de um descritor de segurança do formato absoluto. Ele substitui qualquer informação de proprietário já está presente.  
  
```
bool SetOwner(const CSid& Sid, bool bDefaulted = false) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Sid`  
 O [CSid](../../atl/reference/csid-class.md) objeto para o novo proprietário do principal do descritor de segurança. Esse parâmetro não deve ser NULL.  
  
 `bDefaulted`  
 Indica se as informações do proprietário são derivadas de um mecanismo padrão. Se esse valor for true, é informações padrão. O método armazena esse valor como o sinalizador de SE_OWNER_DEFAULTED o **SECURITY_DESCRIPTOR_CONTROL** estrutura. Se esse parâmetro for zero, o sinalizador SE_OWNER_DEFAULTED está desmarcado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="setsacl"></a>CSecurityDesc::SetSacl  
 Define as informações em uma lista de controle de acesso do sistema (SACL). Se um SACL já está presente no descritor de segurança, ele será substituído.  
  
```
bool SetSacl(const CSacl& Sacl, bool bDefaulted = false) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *SACL*  
 Ponteiro para uma `CSacl` objeto especificando a SACL para o descritor de segurança. Esse parâmetro não deve ser NULL e deve ser um objeto CSacl. Ao contrário de DACLs, não há nenhuma diferença entre NULL e uma SACL vazia, como objetos SACL não especificar os direitos de acesso, apenas informações de auditoria.  
  
 `bDefaulted`  
 Especifica um sinalizador que indica a origem da SACL. Se esse sinalizador for true, a SACL foram obtida por algum mecanismo padrão. Se for false, a SACL foi especificada explicitamente por um usuário. O método armazena esse valor no sinalizador SE_SACL_DEFAULTED o **SECURITY_DESCRIPTOR_CONTROL** estrutura. Se esse parâmetro não for especificado, o sinalizador SE_SACL_DEFAULTED está desmarcado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="tostring"></a>CSecurityDesc::ToString  
 Converte um descritor de segurança em um formato de cadeia de caracteres.  
  
```
bool ToString(
    CString* pstr, SECURITY_INFORMATION si = OWNER_SECURITY_INFORMATION |
    GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION |
    SACL_SECURITY_INFORMATION) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstr`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que receberá o [descritor de segurança do formato de cadeia de caracteres](http://msdn.microsoft.com/library/windows/desktop/aa379570).  
  
 `si`  
 Especifica uma combinação de sinalizadores de bit SECURITY_INFORMATION para indicar os componentes do descritor de segurança para incluir na cadeia de saída.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Depois que o descritor de segurança está no formato de cadeia de caracteres, ele pode mais facilmente ser armazenado ou transmitido. Use o `CSecurityDesc::FromString` método para converter a cadeia de caracteres de volta em um descritor de segurança.  
  
 O `si` parâmetro pode conter os seguintes sinalizadores SECURITY_INFORMATION:  
  
|Valor|Significado|  
|-----------|-------------|  
|OWNER_SECURITY_INFORMATION|Inclua o proprietário.|  
|GROUP_SECURITY_INFORMATION|Inclui o grupo primário.|  
|DACL_SECURITY_INFORMATION|Inclua a DACL.|  
|SACL_SECURITY_INFORMATION|Inclua a SACL.|  
  
 Se a DACL é NULL e o bit de controle SE_DACL_PRESENT é definido no descritor de segurança de entrada, o método falhará.  
  
 Se a DACL é NULL e o bit de controle SE_DACL_PRESENT não está definido no descritor de segurança de entrada, a cadeia de caracteres de descritor de segurança resultante não tem um componente de d:. Consulte [formato de cadeia de caracteres do descritor de segurança](http://msdn.microsoft.com/library/windows/desktop/aa379570) para obter mais detalhes.  
  
 Este método só está disponível com o Windows 2000 e posterior, enquanto ela chama [ConvertStringSecurityDescriptorToSecurityDescriptor](http://msdn.microsoft.com/library/windows/desktop/aa376401).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de segurança](../../visual-cpp-samples.md)   
 [SECURITY_DESCRIPTOR](http://msdn.microsoft.com/library/windows/desktop/aa379561)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)

