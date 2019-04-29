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
ms.openlocfilehash: 88389d4fe913a31fce43e3c8cc95605f99701695
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62261189"
---
# <a name="ca2caex-class"></a>Classe CA2CAEX

Essa classe é usada em macros de conversão de cadeia de caracteres CA2CTEX CT2CAEX e typedef CA2CA.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<int t_nBufferLength = 128>
class CA2CAEX
```

#### <a name="parameters"></a>Parâmetros

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
|[CA2CAEX::Operator LPCSTR](#operator_lpcstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2CAEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade adicional for necessária, use CA2CTEX, CT2CAEX ou CA2CA em seu próprio código.

Essa classe é seguro usar em loops e não estouram a pilha. Por padrão, as macros e classes de conversão ATL usam a página de código ANSI dos threads atuais para a conversão.

As macros a seguir se baseiam nessa classe:

- CA2CTEX

- CT2CAEX

O typedef seguir baseia-se nessa classe:

- CA2CA

Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Ver [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atlconv. h

##  <a name="ca2caex"></a>  CA2CAEX::CA2CAEX

O construtor.

```
CA2CAEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2CAEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de caracteres de texto a ser convertido.

*nCodePage*<br/>
Não usado nessa classe.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

##  <a name="dtor"></a>  CA2CAEX::~CA2CAEX

O destruidor.

```
~CA2CAEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

##  <a name="m_psz"></a>  CA2CAEX::m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```
LPCSTR m_psz;
```

##  <a name="operator_lpcstr"></a>  CA2CAEX::Operator LPCSTR

Operador de conversão.

```
operator LPCSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a cadeia de caracteres de texto como o tipo LPCSTR.

## <a name="see-also"></a>Consulte também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
