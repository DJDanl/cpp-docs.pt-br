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
ms.openlocfilehash: a710034c5d94a8fb093a2b6a2a52373e2bab2d6d
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168495"
---
# <a name="ca2wex-class"></a>Classe CA2WEX

Essa classe é usada pelas macros de conversão de cadeia de Caracteres CA2TEX, CA2CTEX, CT2WEX e CT2CWEX, e o typedef CA2W.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <int t_nBufferLength = 128>
class CA2WEX
```

### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2WEX::CA2WEX](#ca2wex)|O construtor.|
|[CA2WEX:: ~ CA2WEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[LPWSTR do CA2WEX:: Operator](#operator_lpwstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2WEX:: m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|
|[CA2WEX:: m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade extra seja necessária, use CA2TEX, CA2CTEX, CT2WEX, CT2CWEX ou CA2W em seu código.

Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para se ajustar ao buffer estático, a classe alocará memória usando **malloc**, liberando a memória quando o objeto sair do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis em versões anteriores do ATL, essa classe seja segura para uso em loops e que ela não ultrapasse a pilha.

Se a classe tentar alocar memória no heap e falhar, ela chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão de ATL e macros usam a página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor para a classe.

As macros a seguir se baseiam nesta classe:

- CA2TEX

- CA2CTEX

- CT2WEX

- CT2CWEX

O seguinte typedef se baseia nesta classe:

- CA2W

Para obter uma discussão sobre essas macros de conversão de texto, veja [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AtlConv. h

## <a name="ca2wexca2wex"></a><a name="ca2wex"></a>CA2WEX::CA2WEX

O construtor.

```cpp
CA2WEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2WEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de texto a ser convertida.

*nCodePage*<br/>
A página de código usada para executar a conversão. Consulte a discussão de parâmetro de página de código para a função SDK do Windows [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar) para obter mais detalhes.

### <a name="remarks"></a>Comentários

Aloca o buffer usado no processo de tradução.

## <a name="ca2wexca2wex"></a><a name="dtor"></a>CA2WEX:: ~ CA2WEX

O destruidor.

```cpp
~CA2WEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="ca2wexm_psz"></a><a name="m_psz"></a>CA2WEX:: m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```cpp
LPWSTR m_psz;
```

## <a name="ca2wexm_szbuffer"></a><a name="m_szbuffer"></a>CA2WEX:: m_szBuffer

O buffer estático, usado para armazenar a cadeia de caracteres convertida.

```cpp
wchar_t m_szBuffer[t_nBufferLength];
```

## <a name="ca2wexoperator-lpwstr"></a><a name="operator_lpwstr"></a>LPWSTR do CA2WEX:: Operator

Operador de conversão.

```cpp
operator LPWSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a cadeia de texto como o tipo LPWSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
