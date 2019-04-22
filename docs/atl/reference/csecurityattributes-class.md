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
ms.openlocfilehash: 66188a2c944379cfae813220937ac1e7e98fb41d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58768335"
---
# <a name="csecurityattributes-class"></a>Classe CSecurityAttributes

Essa classe é um wrapper fino em que a estrutura de atributos de segurança.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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

O `SECURITY_ATTRIBUTES` estrutura contém uma [descritor de segurança](/windows/desktop/api/winnt/ns-winnt-_security_descriptor) usada para a criação de um objeto e especifica se o identificador recuperado especificando essa estrutura é herdável.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SECURITY_ATTRIBUTES`

`CSecurityAttributes`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

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
Especifica se o identificador retornado é herdado quando um novo processo é criado. Se esse membro for true, o novo processo herda o identificador.

##  <a name="set"></a>  CSecurityAttributes::Set

Chame esse método para definir os atributos do `CSecurityAttributes` objeto.

```
void Set(const CSecurityDesc& rSecurityDescriptor, bool bInheritHandle = false) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSecurityDescriptor*<br/>
Referência a um descritor de segurança.

*bInheritHandle*<br/>
Especifica se o identificador retornado é herdado quando um novo processo é criado. Se esse membro for true, o novo processo herda o identificador.

### <a name="remarks"></a>Comentários

Esse método é usado pelo construtor para inicializar o `CSecurityAttributes` objeto.

## <a name="see-also"></a>Consulte também

[Exemplo de segurança](../../overview/visual-cpp-samples.md)<br/>
[SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560)<br/>
[descritor de segurança](/windows/desktop/api/winnt/ns-winnt-_security_descriptor)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Funções globais de segurança](../../atl/reference/security-global-functions.md)
