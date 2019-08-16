---
title: Classe CSecurityAttributes
ms.date: 11/04/2016
f1_keywords:
- CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes::CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes::Set
helpviewer_keywords:
- CSecurityAttributes class
ms.assetid: a094880c-52e1-4a28-97ff-752d5869908e
ms.openlocfilehash: ebffbea120101a77450a5e8da3cdb6e34723e7be
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496495"
---
# <a name="csecurityattributes-class"></a>Classe CSecurityAttributes

Essa classe é um wrapper fino para a estrutura de atributos de segurança.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CSecurityAttributes : public SECURITY_ATTRIBUTES
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityAttributes::CSecurityAttributes](#csecurityattributes)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSecurityAttributes::Set](#set)|Chame esse método para definir os atributos do `CSecurityAttributes` objeto.|

## <a name="remarks"></a>Comentários

A `SECURITY_ATTRIBUTES` estrutura contém um [descritor de segurança](/windows/win32/api/winnt/ns-winnt-security_descriptor) usado para a criação de um objeto e especifica se o identificador recuperado por meio da especificação dessa estrutura é herdável.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SECURITY_ATTRIBUTES`

`CSecurityAttributes`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="csecurityattributes"></a>  CSecurityAttributes::CSecurityAttributes

O construtor.

```
CSecurityAttributes() throw();
explicit CSecurityAttributes(const CSecurityDesc& rSecurityDescriptor, bool bInheritsHandle = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSecurityDescriptor*<br/>
Referência a um descritor de segurança.

*bInheritsHandle*<br/>
Especifica se o identificador retornado é herdado quando um novo processo é criado. Se esse membro for true, o novo processo herdará o identificador.

##  <a name="set"></a>CSecurityAttributes:: Set

Chame esse método para definir os atributos do `CSecurityAttributes` objeto.

```
void Set(const CSecurityDesc& rSecurityDescriptor, bool bInheritHandle = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSecurityDescriptor*<br/>
Referência a um descritor de segurança.

*bInheritHandle*<br/>
Especifica se o identificador retornado é herdado quando um novo processo é criado. Se esse membro for true, o novo processo herdará o identificador.

### <a name="remarks"></a>Comentários

Esse método é usado pelo construtor para inicializar o `CSecurityAttributes` objeto.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\))<br/>
[descritor de segurança](/windows/win32/api/winnt/ns-winnt-security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
