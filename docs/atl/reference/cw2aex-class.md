---
title: Classe CW2AEX
ms.date: 11/04/2016
f1_keywords:
- CW2AEX
- ATLCONV/ATL::CW2AEX
- ATLCONV/ATL::CW2AEX::CW2AEX
- ATLCONV/ATL::CW2AEX::m_psz
- ATLCONV/ATL::CW2AEX::m_szBuffer
helpviewer_keywords:
- CW2AEX class
ms.assetid: 44dc2cf5-dd30-440b-a9b9-b21b43f49843
ms.openlocfilehash: 849cbe5c26d7c7af7a8925a26057b5777554471d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330449"
---
# <a name="cw2aex-class"></a>Classe CW2AEX

Esta classe é usada pelas macros de conversão de strings CT2AEX, CW2TEX, CW2CTEX e CT2CAEX, e pelo typedef CW2A.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<int t_nBufferLength = 128>
class CW2AEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é de 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2AEX::CW2AEX](#cw2aex)|O construtor.|
|[CW2AEX::~CW2AEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2AEX::operador LPSTR](#operator_lpstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2AEX::m_psz](#m_psz)|O membro de dados que armazena a seqüência de origem.|
|[CW2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a seqüência convertida.|

## <a name="remarks"></a>Comentários

A menos que seja necessária funcionalidade extra, use CT2AEX, CW2TEX, CW2CTEX, CT2CAEX ou CW2A em seu código.

Esta classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe alocará memória usando **malloc,** liberando a memória quando o objeto sai do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis nas versões anteriores do ATL, essa classe é segura de usar em loops e que não transbordará a pilha.

Se a classe tentar alocar memória no monte `AtlThrow` e falhar, ela chamará com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão ATL e macros usam a página de código ANSI do segmento atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.

As seguintes macros são baseadas nesta classe:

- Ct2aex

- Cw2tex

- Cw2ctex

- Ct2caexe

O tipo de digitação a seguir é baseado nesta classe:

- CW2A

Para uma discussão sobre essas macros de conversão de texto, consulte Macros de [conversão de strings ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de [conversão de strings ATL e MFC](string-conversion-macros.md) para um exemplo de uso dessas macros de conversão de strings.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlconv.h

## <a name="cw2aexcw2aex"></a><a name="cw2aex"></a>CW2AEX::CW2AEX

O construtor.

```
CW2AEX(LPCWSTR psz, UINT nCodePage) throw(...);
CW2AEX(LPCWSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A seqüência de texto a ser convertida.

*nCodePage*<br/>
A página de código usada para realizar a conversão. Consulte a discussão do parâmetro de página de código para a função Windows SDK [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar) para obter mais detalhes.

### <a name="remarks"></a>Comentários

Aloca o buffer usado no processo de tradução.

## <a name="cw2aexcw2aex"></a><a name="dtor"></a>CW2AEX::~CW2AEX

O destruidor.

```
~CW2AEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="cw2aexm_psz"></a><a name="m_psz"></a>CW2AEX::m_psz

O membro de dados que armazena a seqüência de origem.

```
LPSTR m_psz;
```

## <a name="cw2aexm_szbuffer"></a><a name="m_szbuffer"></a>CW2AEX::m_szBuffer

O buffer estático, usado para armazenar a seqüência convertida.

```
char m_szBuffer[t_nBufferLength];
```

## <a name="cw2aexoperator-lpstr"></a><a name="operator_lpstr"></a>CW2AEX::operador LPSTR

Operador de conversão.

```
operator LPSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a seqüência de texto como tipo LPSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
