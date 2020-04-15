---
title: Classe CA2CAEX
ms.date: 11/04/2016
f1_keywords:
- CA2CAEX
- ATLCONV/ATL::CA2CAEX
- ATLCONV/ATL::CA2CAEX::CA2CAEX
- ATLCONV/ATL::CA2CAEX::m_psz
helpviewer_keywords:
- CA2CAEX class
ms.assetid: 388e7c1d-a144-474c-a182-b15f69a74bd8
ms.openlocfilehash: e6c727993b2907aaa551421a5d2d23e372b68917
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319138"
---
# <a name="ca2caex-class"></a>Classe CA2CAEX

Esta classe é usada pelas macros de conversão de strings CA2CTEX e CT2CAEX, e pelo typedef CA2CA.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<int t_nBufferLength = 128>
class CA2CAEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é de 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2CAEX::CA2CAEX](#ca2caex)|O construtor.|
|[CA2CAEX::~CA2CAEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2CAEX::operador LSTR](#operator_lpcstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2CAEX::m_psz](#m_psz)|O membro de dados que armazena a seqüência de origem.|

## <a name="remarks"></a>Comentários

A menos que seja necessária funcionalidade extra, use CA2CTEX, CT2CAEX ou CA2CA em seu próprio código.

Esta classe é segura para usar em loops e não transbordará a pilha. Por padrão, as macros e classes de conversão ATL usam a página de código ANSI dos threads atuais para a conversão.

As seguintes macros são baseadas nesta classe:

- Ca2ctex

- Ct2caexe

O tipo de digitação a seguir é baseado nesta classe:

- CA2CA

Para uma discussão sobre essas macros de conversão de texto, consulte Macros de [conversão de strings ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de [conversão de strings ATL e MFC](string-conversion-macros.md) para um exemplo de uso dessas macros de conversão de strings.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlconv.h

## <a name="ca2caexca2caex"></a><a name="ca2caex"></a>CA2CAEX::CA2CAEX

O construtor.

```
CA2CAEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2CAEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A seqüência de texto a ser convertida.

*nCodePage*<br/>
Não usado nesta aula.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

## <a name="ca2caexca2caex"></a><a name="dtor"></a>CA2CAEX::~CA2CAEX

O destruidor.

```
~CA2CAEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="ca2caexm_psz"></a><a name="m_psz"></a>CA2CAEX::m_psz

O membro de dados que armazena a seqüência de origem.

```
LPCSTR m_psz;
```

## <a name="ca2caexoperator-lpcstr"></a><a name="operator_lpcstr"></a>CA2CAEX::operador LSTR

Operador de conversão.

```
operator LPCSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a seqüência de texto como tipo LPCSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
