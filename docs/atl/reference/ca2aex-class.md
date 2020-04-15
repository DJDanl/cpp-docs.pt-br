---
title: Classe CA2AEX
ms.date: 11/04/2016
f1_keywords:
- CA2AEX
- ATLCONV/ATL::CA2AEX
- ATLCONV/ATL::CA2AEX::CA2AEX
- ATLCONV/ATL::CA2AEX::m_psz
- ATLCONV/ATL::CA2AEX::m_szBuffer
helpviewer_keywords:
- CA2AEX class
ms.assetid: 57dc65df-d9cf-4a84-99d3-6e031dde3664
ms.openlocfilehash: 4f8b9f91e9bc499523fe3484bc76325e2efb8140
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319175"
---
# <a name="ca2aex-class"></a>Classe CA2AEX

Esta classe é usada pelas macros de conversão de strings CA2TEX e CT2AEX, e pelo typedef CA2A.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <int t_nBufferLength = 128>
class CA2AEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é de 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX::CA2AEX](#ca2aex)|O construtor.|
|[CA2AEX::~CA2AEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX::operador LPSTR](#operator_lpstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX:m_psz](#m_psz)|O membro de dados que armazena a seqüência de origem.|
|[CA2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a seqüência convertida.|

## <a name="remarks"></a>Comentários

A menos que seja necessária funcionalidade extra, use CA2TEX, CT2AEX ou CA2A em seu próprio código.

Esta classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe alocará memória usando **malloc,** liberando a memória quando o objeto sai do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis nas versões anteriores do ATL, essa classe é segura de usar em loops e que não transbordará a pilha.

Se a classe tentar alocar memória no monte `AtlThrow` e falhar, ela chamará com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão ATL e macros usam a página de código ANSI do segmento atual para a conversão.

As seguintes macros são baseadas nesta classe:

- Ca2tex

- Ct2aex

O tipo de digitação a seguir é baseado nesta classe:

- CA2A

Para uma discussão sobre essas macros de conversão de texto, consulte Macros de [conversão de strings ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de [conversão de strings ATL e MFC](string-conversion-macros.md) para um exemplo de uso dessas macros de conversão de strings.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlconv.h

## <a name="ca2aexca2aex"></a><a name="ca2aex"></a>CA2AEX::CA2AEX

O construtor.

```
CA2AEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2AEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A seqüência de texto a ser convertida.

*nCodePage*<br/>
Não usado nesta aula.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

## <a name="ca2aexca2aex"></a><a name="dtor"></a>CA2AEX::~CA2AEX

O destruidor.

```
~CA2AEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="ca2aexm_psz"></a><a name="m_psz"></a>CA2AEX:m_psz

O membro de dados que armazena a seqüência de origem.

```
LPSTR m_psz;
```

## <a name="ca2aexm_szbuffer"></a><a name="m_szbuffer"></a>CA2AEX::m_szBuffer

O buffer estático, usado para armazenar a seqüência convertida.

```
char m_szBuffer[ t_nBufferLength];
```

## <a name="ca2aexoperator-lpstr"></a><a name="operator_lpstr"></a>CA2AEX::operador LPSTR

Operador de conversão.

```
operator LPSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a seqüência de texto como tipo LPSTR.

## <a name="see-also"></a>Confira também

[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
