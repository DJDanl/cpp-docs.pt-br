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
ms.openlocfilehash: a6ed6062be02fddc111e4eda4d26226b7a7a0c63
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57296079"
---
# <a name="catlexception-class"></a>Classe CAtlException

Essa classe define uma exceção de ATL.

## <a name="syntax"></a>Sintaxe

```
class CAtlException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException::CAtlException](#catlexception)|O construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException::operator HRESULT](#operator_hresult)|Converte o objeto atual em um valor HRESULT.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlException::m_hr](#m_hr)|A variável do tipo HRESULT criado pelo objeto e usado para armazenar a condição de erro.|

## <a name="remarks"></a>Comentários

Um `CAtlException` objeto representa uma condição de exceção relacionada a uma operação de ATL. O `CAtlException` classe inclui um membro de dados públicos que armazena o código de status que indica o motivo da exceção e um operador de conversão que permite que você trate a exceção como se fosse um HRESULT.

Em geral, você chamará `AtlThrow` em vez de criar um `CAtlException` diretamente do objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlexcept.h

##  <a name="catlexception"></a>  CAtlException::CAtlException

O construtor.

```
CAtlException(HRESULT hr) throw();
CAtlException() throw();
```

### <a name="parameters"></a>Parâmetros

*hr*<br/>
O código de erro HRESULT.

##  <a name="operator_hresult"></a>  CAtlException::operator HRESULT

Converte o objeto atual em um valor HRESULT.

```
operator HRESULT() const throw ();
```

##  <a name="m_hr"></a>  CAtlException::m_hr

O membro de dados HRESULT.

```
HRESULT m_hr;
```

### <a name="remarks"></a>Comentários

O membro de dados que armazena a condição de erro. O valor HRESULT é definido pelo construtor, [CAtlException::CAtlException](#catlexception).

## <a name="see-also"></a>Consulte também

[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
