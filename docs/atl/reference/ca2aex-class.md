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
ms.openlocfilehash: dfd8967d21005d83b38eeae36cfc147051d7beaf
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168521"
---
# <a name="ca2aex-class"></a>Classe CA2AEX

Essa classe é usada pelas macros de conversão de cadeia de Caracteres CA2TEX e CT2AEX, e o typedef CA2A.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <int t_nBufferLength = 128>
class CA2AEX
```

### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX::CA2AEX](#ca2aex)|O construtor.|
|[CA2AEX:: ~ CA2AEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[LPSTR do CA2AEX:: Operator](#operator_lpstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX:: m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|
|[CA2AEX:: m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade extra seja necessária, use CA2TEX, CT2AEX ou CA2A em seu próprio código.

Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para se ajustar ao buffer estático, a classe alocará memória usando **malloc**, liberando a memória quando o objeto sair do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis em versões anteriores do ATL, essa classe seja segura para uso em loops e que ela não ultrapasse a pilha.

Se a classe tentar alocar memória no heap e falhar, ela chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão de ATL e macros usam a página de código ANSI do thread atual para a conversão.

As macros a seguir se baseiam nesta classe:

- CA2TEX

- CT2AEX

O seguinte typedef se baseia nesta classe:

- CA2A

Para obter uma discussão sobre essas macros de conversão de texto, veja [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AtlConv. h

## <a name="ca2aexca2aex"></a><a name="ca2aex"></a>CA2AEX::CA2AEX

O construtor.

```cpp
CA2AEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2AEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de texto a ser convertida.

*nCodePage*<br/>
Não usado nesta classe.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

## <a name="ca2aexca2aex"></a><a name="dtor"></a>CA2AEX:: ~ CA2AEX

O destruidor.

```cpp
~CA2AEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="ca2aexm_psz"></a><a name="m_psz"></a>CA2AEX:: m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```cpp
LPSTR m_psz;
```

## <a name="ca2aexm_szbuffer"></a><a name="m_szbuffer"></a>CA2AEX:: m_szBuffer

O buffer estático, usado para armazenar a cadeia de caracteres convertida.

```cpp
char m_szBuffer[ t_nBufferLength];
```

## <a name="ca2aexoperator-lpstr"></a><a name="operator_lpstr"></a>LPSTR do CA2AEX:: Operator

Operador de conversão.

```cpp
operator LPSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a cadeia de texto como o tipo LPSTR.

## <a name="see-also"></a>Confira também

[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
