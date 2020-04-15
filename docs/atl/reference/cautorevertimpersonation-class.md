---
title: Classe cautorevertrepresentação
ms.date: 11/04/2016
f1_keywords:
- CAutoRevertImpersonation
- ATLSECURITY/ATL::CAutoRevertImpersonation
- ATLSECURITY/ATL::CAutoRevertImpersonation::CAutoRevertImpersonation
- ATLSECURITY/ATL::CAutoRevertImpersonation::Attach
- ATLSECURITY/ATL::CAutoRevertImpersonation::Detach
- ATLSECURITY/ATL::CAutoRevertImpersonation::GetAccessToken
helpviewer_keywords:
- CAutoRevertImpersonation class
ms.assetid: 43732849-1940-4bd4-9d52-7a5698bb8838
ms.openlocfilehash: 813b6f0dd33bdfa85476b816086217a7892f4476
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318785"
---
# <a name="cautorevertimpersonation-class"></a>Classe cautorevertrepresentação

Essa classe reverte objetos [CAccessToken](../../atl/reference/caccesstoken-class.md) para um estado não personificado quando ele sai do escopo.

## <a name="syntax"></a>Sintaxe

```
class CAutoRevertImpersonation
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoRevertImpersonation::CAutoRevertImpersonation](#cautorevertimpersonation)|Constrói um `CAutoRevertImpersonation` objeto|
|[CAutoRevertPersonificação::~CAutoRevertPersonificação](#dtor)|Destrói o objeto e reverte a representação de tokens de acesso.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoRevertPersonificação::Anexar](#attach)|Automatiza a reversão de personificação de um token de acesso.|
|[CAutoRevertImpersonation::Detach](#detach)|Cancela a reversão automática da representação.|
|[CAutoRevertPersonificação::GetAccessToken](#getaccesstoken)|Recupera a corrente de token de acesso associada a este objeto.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/win32/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou segmento e é alocado para cada usuário conectado a um sistema Windows NT ou Windows 2000. Esses tokens de acesso `CAccessToken` podem ser representados com a classe.

Às vezes é necessário se passar por tokens de acesso. Esta classe é fornecida como uma conveniência, mas não realiza a personificação de tokens de acesso; ele só executa a reversão automática para um estado não personificado. Isso porque a personificação do acesso ao token pode ser realizada de várias maneiras diferentes.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="cautorevertimpersonationattach"></a><a name="attach"></a>CAutoRevertPersonificação::Anexar

Automatiza a reversão de personificação de um token de acesso.

```
void Attach(const CAccessToken* pAT) throw();
```

### <a name="parameters"></a>Parâmetros

*Pat*<br/>
O endereço do objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) a ser revertido automaticamente

### <a name="remarks"></a>Comentários

Este método só deve ser usado se o objeto [CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) foi criado com um ponteiro NULL, `CAccessToken` ou se O [Desapego](#detach) foi chamado anteriormente. Para casos simples, não é necessário usar este método.

## <a name="cautorevertimpersonationcautorevertimpersonation"></a><a name="cautorevertimpersonation"></a>CAutoRevertImpersonation::CAutoRevertImpersonation

Constrói um objeto `CAutoRevertImpersonation`.

```
CAutoRevertImpersonation(const CAccessToken* pAT) throw();
```

### <a name="parameters"></a>Parâmetros

*Pat*<br/>
O endereço do objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) a ser revertido automaticamente.

### <a name="remarks"></a>Comentários

A representação real do token de acesso deve ser realizada separadamente `CAutoRevertImpersonation` e preferencialmente antes da criação de um objeto. Esta representação será revertida automaticamente quando `CAutoRevertImpersonation` o objeto sair do escopo.

## <a name="cautorevertimpersonationcautorevertimpersonation"></a><a name="dtor"></a>CAutoRevertPersonificação::~CAutoRevertPersonificação

Destrói o objeto e reverte a representação de tokens de acesso.

```
~CAutoRevertImpersonation() throw();
```

### <a name="remarks"></a>Comentários

Reverte qualquer representação atualmente em vigor para o objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) fornecido na construção ou através do método [Attach.](#attach) Se `CAccessToken` não estiver associado, o destruidor não tem efeito.

## <a name="cautorevertimpersonationdetach"></a><a name="detach"></a>CAutoRevertImpersonation::Detach

Cancela a reversão automática da representação.

```
const CAccessToken* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md)anteriormente associado ou NULL se não existir associação.

### <a name="remarks"></a>Comentários

Chamar **Desapego** impede que o `CAutoRevertImpersonation` objeto reverta qualquer representação atualmente em vigor para o objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) associado a este objeto. `CAutoRevertImpersonation`em seguida, pode ser destruído sem efeito `CAccessToken` ou reassociado ao mesmo ou outro objeto usando [Attach](#attach).

## <a name="cautorevertimpersonationgetaccesstoken"></a><a name="getaccesstoken"></a>CAutoRevertPersonificação::GetAccessToken

Recupera a corrente de token de acesso associada a este objeto.

```
const CAccessToken* GetAccessToken() throw();
```

### <a name="return-value"></a>Valor retornado

O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md)anteriormente associado ou NULL se não existir associação.

### <a name="remarks"></a>Comentários

Se este método for chamado para os propósitos que incluem `CAccessToken` a reversão de uma representação do objeto, o método [Despaspele](#detach) deve ser usado em vez disso.

## <a name="see-also"></a>Confira também

[Amostra de ATLSecurity](../../overview/visual-cpp-samples.md)<br/>
[Tokens de acesso](/windows/win32/SecAuthZ/access-tokens)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
