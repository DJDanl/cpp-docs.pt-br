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
ms.openlocfilehash: f09d9b2f46233cf356f5ade8a5b90e08a213d276
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168196"
---
# <a name="catlexception-class"></a>Classe CAtlException

Essa classe define uma exceção ATL.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CAtlException:: operador HRESULT](#operator_hresult)|Converte o objeto atual em um valor HRESULT.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException:: m_hr](#m_hr)|A variável do tipo HRESULT criada pelo objeto e usada para armazenar a condição de erro.|

## <a name="remarks"></a>Comentários

Um `CAtlException` objeto representa uma condição de exceção relacionada a uma operação de ATL. A `CAtlException` classe inclui um membro de dados público que armazena o código de status indicando o motivo da exceção e um operador de conversão que permite tratar a exceção como se fosse um HRESULT.

Em geral, você chamará `AtlThrow` em vez de criar `CAtlException` um objeto diretamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlexcept. h

## <a name="catlexceptioncatlexception"></a><a name="catlexception"></a>CAtlException::CAtlException

O construtor.

```cpp
CAtlException(HRESULT hr) throw();
CAtlException() throw();
```

### <a name="parameters"></a>Parâmetros

*Human*<br/>
O código de erro HRESULT.

## <a name="catlexceptionoperator-hresult"></a><a name="operator_hresult"></a>CAtlException:: operador HRESULT

Converte o objeto atual em um valor HRESULT.

```cpp
operator HRESULT() const throw ();
```

## <a name="catlexceptionm_hr"></a><a name="m_hr"></a>CAtlException:: m_hr

O membro de dados HRESULT.

```cpp
HRESULT m_hr;
```

### <a name="remarks"></a>Comentários

O membro de dados que armazena a condição de erro. O valor HRESULT é definido pelo construtor, [CAtlException:: CAtlException](#catlexception).

## <a name="see-also"></a>Confira também

[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
