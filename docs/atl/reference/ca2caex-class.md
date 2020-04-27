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
ms.openlocfilehash: 505c1e369bc5949fea291a2172c16d5e52c75567
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168508"
---
# <a name="ca2caex-class"></a>Classe CA2CAEX

Essa classe é usada pelas macros de conversão de cadeia de caracteres CA2CTEX e CT2CAEX, e o typedef CA2CA.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template<int t_nBufferLength = 128>
class CA2CAEX
```

### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2CAEX::CA2CAEX](#ca2caex)|O construtor.|
|[CA2CAEX:: ~ CA2CAEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CA2CAEX:: Operator LPCSTR](#operator_lpcstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2CAEX:: m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade extra seja necessária, use CA2CTEX, CT2CAEX ou CA2CA em seu próprio código.

Essa classe é segura para uso em loops e não estoura a pilha. Por padrão, as macros e classes de conversão ATL usam a página de código ANSI dos threads atuais para a conversão.

As macros a seguir se baseiam nesta classe:

- CA2CTEX

- CT2CAEX

O seguinte typedef se baseia nesta classe:

- CA2CA

Para obter uma discussão sobre essas macros de conversão de texto, veja [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AtlConv. h

## <a name="ca2caexca2caex"></a><a name="ca2caex"></a>CA2CAEX::CA2CAEX

O construtor.

```cpp
CA2CAEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2CAEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de texto a ser convertida.

*nCodePage*<br/>
Não usado nesta classe.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

## <a name="ca2caexca2caex"></a><a name="dtor"></a>CA2CAEX:: ~ CA2CAEX

O destruidor.

```cpp
~CA2CAEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

## <a name="ca2caexm_psz"></a><a name="m_psz"></a>CA2CAEX:: m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```cpp
LPCSTR m_psz;
```

## <a name="ca2caexoperator-lpcstr"></a><a name="operator_lpcstr"></a>Operador CA2CAEX:: Operator LPCSTR

Operador de conversão.

```cpp
operator LPCSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a cadeia de texto como o tipo LPCSTR.

## <a name="see-also"></a>Confira também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
