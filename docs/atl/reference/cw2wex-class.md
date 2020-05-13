---
title: Classe CW2WEX
ms.date: 11/04/2016
f1_keywords:
- CW2WEX
- ATLCONV/ATL::CW2WEX
- ATLCONV/ATL::CW2WEX::CW2WEX
- ATLCONV/ATL::CW2WEX::m_psz
- ATLCONV/ATL::CW2WEX::m_szBuffer
helpviewer_keywords:
- CW2WEX class
ms.assetid: 46262e56-e0d2-41fe-855b-0b67ecc8fcd7
ms.openlocfilehash: b116775a595f9fb3612d46e19526cf1396f85002
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330343"
---
# <a name="cw2wex-class"></a>Classe CW2WEX

Esta classe é usada pelas macros de conversão de strings CW2TEX e CT2WEX, e pelo typedef CW2W.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <int t_nBufferLength = 128>
class CW2WEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é de 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2WEX::CW2WEX](#cw2wex)|O construtor.|
|[CW2WEX::~CW2WEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2WEX::operador LPWSTR](#operator_lpwstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2WEX::m_psz](#m_psz)|O membro de dados que armazena a seqüência de origem.|
|[CW2WEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a seqüência convertida.|

## <a name="remarks"></a>Comentários

A menos que seja necessária funcionalidade extra, use CW2TEX, CT2WEX ou CW2W em seu código.

Esta classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe alocará memória usando **malloc,** liberando a memória quando o objeto sai do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis nas versões anteriores do ATL, essa classe é segura de usar em loops e que não transbordará a pilha.

Se a classe tentar alocar memória no monte `AtlThrow` e falhar, ela chamará com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão ATL e macros usam a página de código ANSI do segmento atual para a conversão.

As seguintes macros são baseadas nesta classe:

- Cw2tex

- CT2WEX

O tipo de digitação a seguir é baseado nesta classe:

- CW2W

Para uma discussão sobre essas macros de conversão de texto, consulte Macros de [conversão de strings ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de [conversão de strings ATL e MFC](string-conversion-macros.md) para um exemplo de uso dessas macros de conversão de strings.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlconv.h

## <a name="cw2wexcw2wex"></a><a name="cw2wex"></a>CW2WEX::CW2WEX

O construtor.

```
CW2WEX(LPCWSTR psz, UINT nCodePage) throw(...);
CW2WEX( LPCWSTR  psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A seqüência de texto a ser convertida.

*nCodePage*<br/>
A página de código. Não usado nesta aula.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

## <a name="cw2wexcw2wex"></a><a name="dtor"></a>CW2WEX::~CW2WEX

O destruidor.

```
~CW2WEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="cw2wexm_psz"></a><a name="m_psz"></a>CW2WEX::m_psz

O membro de dados que armazena a seqüência de origem.

```
LPWSTR m_psz;
```

## <a name="cw2wexm_szbuffer"></a><a name="m_szbuffer"></a>CW2WEX::m_szBuffer

O buffer estático, usado para armazenar a seqüência convertida.

```
wchar_t m_szBuffer[t_nBufferLength];
```

## <a name="cw2wexoperator-lpwstr"></a><a name="operator_lpwstr"></a>CW2WEX::operador LPWSTR

Operador de elenco.

```
operator LPWSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a seqüência de texto como tipo LPWSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
