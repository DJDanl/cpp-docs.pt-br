---
title: Classe CA2WEX
ms.date: 11/04/2016
f1_keywords:
- CA2WEX
- ATLCONV/ATL::CA2WEX
- ATLCONV/ATL::CA2WEX::CA2WEX
- ATLCONV/ATL::CA2WEX::m_psz
- ATLCONV/ATL::CA2WEX::m_szBuffer
helpviewer_keywords:
- CA2WEX class
ms.assetid: 317d9ffb-e84f-47e8-beda-57e28fb19124
ms.openlocfilehash: c9123e163ca828fa71fe217e46537ceb18e6f549
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319122"
---
# <a name="ca2wex-class"></a>Classe CA2WEX

Esta classe é usada pelas macros de conversão de strings CA2TEX, CA2CTEX, CT2WEX e CT2CWEX, e pelo typedef CA2W.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <int t_nBufferLength = 128>
class CA2WEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é de 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2WEX::CA2WEX](#ca2wex)|O construtor.|
|[CA2WEX::~CA2WEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2WEX::operador LPWSTR](#operator_lpwstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2WEX::m_psz](#m_psz)|O membro de dados que armazena a seqüência de origem.|
|[CA2WEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a seqüência convertida.|

## <a name="remarks"></a>Comentários

A menos que seja necessária funcionalidade extra, use CA2TEX, CA2CTEX, CT2WEX, CT2CWEX ou CA2W em seu código.

Esta classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe alocará memória usando **malloc,** liberando a memória quando o objeto sai do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis nas versões anteriores do ATL, essa classe é segura de usar em loops e que não transbordará a pilha.

Se a classe tentar alocar memória no monte `AtlThrow` e falhar, ela chamará com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão ATL e macros usam a página de código ANSI do segmento atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.

As seguintes macros são baseadas nesta classe:

- Ca2tex

- Ca2ctex

- CT2WEX

- CT2CWEX

O tipo de digitação a seguir é baseado nesta classe:

- CA2W

Para uma discussão sobre essas macros de conversão de texto, consulte Macros de [conversão de strings ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de [conversão de strings ATL e MFC](string-conversion-macros.md) para um exemplo de uso dessas macros de conversão de strings.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlconv.h

## <a name="ca2wexca2wex"></a><a name="ca2wex"></a>CA2WEX::CA2WEX

O construtor.

```
CA2WEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2WEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A seqüência de texto a ser convertida.

*nCodePage*<br/>
A página de código usada para realizar a conversão. Consulte a discussão do parâmetro de página de código para a função Windows SDK [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar) para obter mais detalhes.

### <a name="remarks"></a>Comentários

Aloca o buffer usado no processo de tradução.

## <a name="ca2wexca2wex"></a><a name="dtor"></a>CA2WEX::~CA2WEX

O destruidor.

```
~CA2WEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="ca2wexm_psz"></a><a name="m_psz"></a>CA2WEX::m_psz

O membro de dados que armazena a seqüência de origem.

```
LPWSTR m_psz;
```

## <a name="ca2wexm_szbuffer"></a><a name="m_szbuffer"></a>CA2WEX::m_szBuffer

O buffer estático, usado para armazenar a seqüência convertida.

```
wchar_t m_szBuffer[t_nBufferLength];
```

## <a name="ca2wexoperator-lpwstr"></a><a name="operator_lpwstr"></a>CA2WEX::operador LPWSTR

Operador de conversão.

```
operator LPWSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a seqüência de texto como tipo LPWSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
