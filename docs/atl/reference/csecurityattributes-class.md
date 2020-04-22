---
title: Classe CSecurityAttributeAttributes
ms.date: 11/04/2016
f1_keywords:
- CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes::CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes::Set
helpviewer_keywords:
- CSecurityAttributes class
ms.assetid: a094880c-52e1-4a28-97ff-752d5869908e
ms.openlocfilehash: e0ac813008a028bb233adfb4c7409a0ad62a6b78
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81746496"
---
# <a name="csecurityattributes-class"></a>Classe CSecurityAttributeAttributes

Esta classe é um invólucro fino para a estrutura de atributos de segurança.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CSecurityAttributes::Set](#set)|Chame este método para definir `CSecurityAttributes` os atributos do objeto.|

## <a name="remarks"></a>Comentários

A `SECURITY_ATTRIBUTES` estrutura contém um [descritor de segurança](/windows/win32/api/winnt/ns-winnt-security_descriptor) usado para a criação de um objeto e especifica se a alça recuperada especificando esta estrutura é hereditária.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SECURITY_ATTRIBUTES`

`CSecurityAttributes`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="csecurityattributescsecurityattributes"></a><a name="csecurityattributes"></a>CSecurityAttributes::CSecurityAttributes

O construtor.

```
CSecurityAttributes() throw();
explicit CSecurityAttributes(const CSecurityDesc& rSecurityDescriptor, bool bInheritsHandle = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSecurityDescriptor*<br/>
Referência a um descritor de segurança.

*bInheritsHandle*<br/>
Especifica se a alça retornada é herdada quando um novo processo é criado. Se este membro for verdadeiro, o novo processo herda a alça.

## <a name="csecurityattributesset"></a><a name="set"></a>CSecurityAttributes::Set

Chame este método para definir `CSecurityAttributes` os atributos do objeto.

```cpp
void Set(const CSecurityDesc& rSecurityDescriptor, bool bInheritHandle = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSecurityDescriptor*<br/>
Referência a um descritor de segurança.

*bInheritHandle*<br/>
Especifica se a alça retornada é herdada quando um novo processo é criado. Se este membro for verdadeiro, o novo processo herda a alça.

### <a name="remarks"></a>Comentários

Este método é usado pelo construtor `CSecurityAttributes` para inicializar o objeto.

## <a name="see-also"></a>Confira também

[Amostra de segurança](../../overview/visual-cpp-samples.md)<br/>
[Security_attributes](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\))<br/>
[descritor de segurança](/windows/win32/api/winnt/ns-winnt-security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
