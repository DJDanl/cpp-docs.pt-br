---
title: Classe CAtlException
ms.date: 11/04/2016
f1_keywords:
- CAtlException
- ATLEXCEPT/ATL::CAtlException
- ATLEXCEPT/ATL::CAtlException::CAtlException
- ATLEXCEPT/ATL::CAtlException::m_hr
helpviewer_keywords:
- CAtlException class
ms.assetid: 3fd7b041-f70d-4292-b947-0d70781d95a8
ms.openlocfilehash: 6da56e4d6c443520eb6f857624a5923e71a1e580
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319003"
---
# <a name="catlexception-class"></a>Classe CAtlException

Esta classe define uma exceção ATL.

## <a name="syntax"></a>Sintaxe

```
class CAtlException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException::CAtlException](#catlexception)|O construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException::operador HRESULT](#operator_hresult)|Lança o objeto atual para um valor HRESULT.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException::m_hr](#m_hr)|A variável do tipo HRESULT criada pelo objeto e usada para armazenar a condição de erro.|

## <a name="remarks"></a>Comentários

Um `CAtlException` objeto representa uma condição de exceção relacionada a uma operação ATL. A `CAtlException` classe inclui um membro de dados públicos que armazena o código de status indicando o motivo da exceção e um operador de elenco que permite tratar a exceção como se fosse um HRESULT.

Em geral, você `AtlThrow` vai chamar `CAtlException` em vez de criar um objeto diretamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlexcept.h

## <a name="catlexceptioncatlexception"></a><a name="catlexception"></a>CAtlException::CAtlException

O construtor.

```
CAtlException(HRESULT hr) throw();
CAtlException() throw();
```

### <a name="parameters"></a>Parâmetros

*Hr*<br/>
O código de erro HRESULT.

## <a name="catlexceptionoperator-hresult"></a><a name="operator_hresult"></a>CAtlException::operador HRESULT

Lança o objeto atual para um valor HRESULT.

```
operator HRESULT() const throw ();
```

## <a name="catlexceptionm_hr"></a><a name="m_hr"></a>CAtlException::m_hr

O membro de dados HRESULT.

```
HRESULT m_hr;
```

### <a name="remarks"></a>Comentários

O membro de dados que armazena a condição de erro. O valor HRESULT é definido pelo construtor, [CAtlException::CAtlException](#catlexception).

## <a name="see-also"></a>Confira também

[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
