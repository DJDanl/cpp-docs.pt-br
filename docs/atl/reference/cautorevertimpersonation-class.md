---
title: Classe CAutoRevertImpersonation
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
ms.openlocfilehash: f1941bfcd7689ab9d22f5094af0eb833a84dab6b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497679"
---
# <a name="cautorevertimpersonation-class"></a>Classe CAutoRevertImpersonation

Essa classe reverte os objetos [CAccessToken](../../atl/reference/caccesstoken-class.md) para um estado não representando quando ele sai do escopo.

## <a name="syntax"></a>Sintaxe

```
class CAutoRevertImpersonation
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoRevertImpersonation::CAutoRevertImpersonation](#cautorevertimpersonation)|Constrói um `CAutoRevertImpersonation` objeto|
|[CAutoRevertImpersonation:: ~ CAutoRevertImpersonation](#dtor)|Destrói o objeto e reverte a representação do token de acesso.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoRevertImpersonation::Attach](#attach)|Automatiza a reversão de representação de um token de acesso.|
|[CAutoRevertImpersonation::Detach](#detach)|Cancela a reversão de representação automática.|
|[CAutoRevertImpersonation::GetAccessToken](#getaccesstoken)|Recupera o token de acesso atual associado a este objeto.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/win32/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado a um sistema Windows NT ou Windows 2000. Esses tokens de acesso podem ser representados com a `CAccessToken` classe.

Às vezes, é necessário representar tokens de acesso. Essa classe é fornecida como uma conveniência, mas não executa a representação de tokens de acesso; Ele apenas executa a reversão automática para um estado não representado. Isso ocorre porque a representação de acesso ao token pode ser executada de várias maneiras diferentes.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/win32/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="attach"></a>  CAutoRevertImpersonation::Attach

Automatiza a reversão de representação de um token de acesso.

```
void Attach(const CAccessToken* pAT) throw();
```

### <a name="parameters"></a>Parâmetros

*pAT*<br/>
O endereço do objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) a ser revertido automaticamente

### <a name="remarks"></a>Comentários

Esse método só deve ser usado se o objeto [CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) foi criado com um ponteiro `CAccessToken` nulo ou se [Detach](#detach) foi chamado anteriormente. Para casos simples, não é necessário usar esse método.

##  <a name="cautorevertimpersonation"></a>  CAutoRevertImpersonation::CAutoRevertImpersonation

Constrói um objeto `CAutoRevertImpersonation`.

```
CAutoRevertImpersonation(const CAccessToken* pAT) throw();
```

### <a name="parameters"></a>Parâmetros

*pAT*<br/>
O endereço do objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) a ser revertido automaticamente.

### <a name="remarks"></a>Comentários

A representação real do token de acesso deve ser executada separadamente e de preferência antes da criação de um `CAutoRevertImpersonation` objeto. Essa representação será revertida automaticamente quando o `CAutoRevertImpersonation` objeto sair do escopo.

##  <a name="dtor"></a>CAutoRevertImpersonation:: ~ CAutoRevertImpersonation

Destrói o objeto e reverte a representação do token de acesso.

```
~CAutoRevertImpersonation() throw();
```

### <a name="remarks"></a>Comentários

Reverte qualquer representação atualmente em vigor para o objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) fornecido na construção ou por meio do método [Attach](#attach) . Se não `CAccessToken` estiver associado, o destruidor não terá nenhum efeito.

##  <a name="detach"></a>  CAutoRevertImpersonation::Detach

Cancela a reversão de representação automática.

```
const CAccessToken* Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md)anteriormente associado, ou NULL se nenhuma associação existia.

### <a name="remarks"></a>Comentários

Chamar **Detach** impede que `CAutoRevertImpersonation` o objeto reverta qualquer representação atualmente em vigor para o objeto [CAccessToken](../../atl/reference/caccesstoken-class.md) associado a esse objeto. `CAutoRevertImpersonation`pode ser destruído sem efeito ou reassociado ao mesmo ou a outro `CAccessToken` objeto usando [Attach](#attach).

##  <a name="getaccesstoken"></a>  CAutoRevertImpersonation::GetAccessToken

Recupera o token de acesso atual associado a este objeto.

```
const CAccessToken* GetAccessToken() throw();
```

### <a name="return-value"></a>Valor de retorno

O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md)anteriormente associado, ou NULL se nenhuma associação existia.

### <a name="remarks"></a>Comentários

Se esse método for chamado para os fins que incluem a reversão de uma representação do `CAccessToken` objeto, o método [Detach](#detach) deverá ser usado em seu lugar.

## <a name="see-also"></a>Consulte também

[Exemplo de ATLSecurity](../../overview/visual-cpp-samples.md)<br/>
[Tokens de acesso](/windows/win32/SecAuthZ/access-tokens)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
