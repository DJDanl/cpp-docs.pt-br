---
title: Classe CW2CWEX
ms.date: 11/04/2016
f1_keywords:
- CW2CWEX
- ATLCONV/ATL::CW2CWEX
- ATLCONV/ATL::CW2CWEX::CW2CWEX
- ATLCONV/ATL::CW2CWEX::m_psz
helpviewer_keywords:
- CW2CWEX class
ms.assetid: d654b22b-05a6-410f-a0ec-9a2cbbb4cca7
ms.openlocfilehash: 07dd0319586054403d8ed0c8efc813b4061e355a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330443"
---
# <a name="cw2cwex-class"></a>Classe CW2CWEX

Esta classe é usada pelas macros de conversão de strings CW2CTEX e CT2CWEX, e pelo typedef CW2W.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<int t_nBufferLength = 128>
class CW2CWEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é de 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2CWEX::CW2CWEX](#cw2cwex)|O construtor.|
|[CW2CWEX:::~CW2CWEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2CWEX::operador LPCWSTR](#operator_lpcwstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2CWEX::m_psz](#m_psz)|O membro de dados que armazena a seqüência de origem.|

## <a name="remarks"></a>Comentários

A menos que seja necessária funcionalidade extra, use CW2CTEX, CT2CWEX ou CW2W em seu código.

Esta classe é segura para usar em loops e não transbordará a pilha. Por padrão, as classes de conversão ATL e macros usam a página de código ANSI do segmento atual para a conversão.

As seguintes macros são baseadas nesta classe:

- Cw2ctex

- CT2CWEX

O tipo de digitação a seguir é baseado nesta classe:

- CW2W

Para uma discussão sobre essas macros de conversão de texto, consulte Macros de [conversão de strings ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de [conversão de strings ATL e MFC](string-conversion-macros.md) para um exemplo de uso dessas macros de conversão de strings.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlconv.h

## <a name="cw2cwexcw2cwex"></a><a name="cw2cwex"></a>CW2CWEX::CW2CWEX

O construtor.

```
CW2CWEX(LPCWSTR psz, UINT nCodePage) throw(...);
CW2CWEX(LPCWSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A seqüência de texto a ser convertida.

*nCodePage*<br/>
A página de código. Não usado nesta aula.

### <a name="remarks"></a>Comentários

Aloca o buffer usado no processo de tradução.

## <a name="cw2cwexcw2cwex"></a><a name="dtor"></a>CW2CWEX:::~CW2CWEX

O destruidor.

```
~CW2CWEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="cw2cwexm_psz"></a><a name="m_psz"></a>CW2CWEX::m_psz

O membro de dados que armazena a seqüência de origem.

```
LPCWSTR m_psz;
```

## <a name="cw2cwexoperator-lpcwstr"></a><a name="operator_lpcwstr"></a>CW2CWEX::operador LPCWSTR

Operador de conversão.

```
operator LPCWSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a seqüência de texto como tipo LPCWSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
