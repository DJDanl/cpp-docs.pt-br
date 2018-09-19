---
title: Classe CA2AEX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CA2AEX
- ATLCONV/ATL::CA2AEX
- ATLCONV/ATL::CA2AEX::CA2AEX
- ATLCONV/ATL::CA2AEX::m_psz
- ATLCONV/ATL::CA2AEX::m_szBuffer
dev_langs:
- C++
helpviewer_keywords:
- CA2AEX class
ms.assetid: 57dc65df-d9cf-4a84-99d3-6e031dde3664
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 49e364e2676242ad75f185792faa545bbb90ef1e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46071205"
---
# <a name="ca2aex-class"></a>Classe CA2AEX

Essa classe é usada pelas macros de conversão de cadeia de caracteres CA2TEX CT2AEX e typedef CA2A.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <int t_nBufferLength = 128>
class CA2AEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX::CA2AEX](#ca2aex)|O construtor.|
|[CA2AEX:: ~ CA2AEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX::Operator LPSTR](#operator_lpstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CA2AEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|
|[CA2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade adicional for necessária, use CA2TEX, CT2AEX ou CA2A em seu próprio código.

Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando **malloc**, liberando a memória quando o objeto sai do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores da ATL, essa classe é seguro para ser usado em loops e que ele não estouram a pilha.

Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.

Por padrão, as macros e classes de conversão ATL usam página de código ANSI do thread atual para a conversão.

As macros a seguir se baseiam nessa classe:

- CA2TEX

- CT2AEX

O typedef seguir baseia-se nessa classe:

- CA2A

Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Ver [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atlconv. h

##  <a name="ca2aex"></a>  CA2AEX::CA2AEX

O construtor.

```
CA2AEX(LPCSTR psz, UINT nCodePage) throw(...);
CA2AEX(LPCSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de caracteres de texto a ser convertido.

*nCodePage*<br/>
Não usado nessa classe.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

##  <a name="dtor"></a>  CA2AEX:: ~ CA2AEX

O destruidor.

```
~CA2AEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

##  <a name="m_psz"></a>  CA2AEX::m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```
LPSTR m_psz;
```

##  <a name="m_szbuffer"></a>  CA2AEX::m_szBuffer

O buffer estático, usado para armazenar a cadeia de caracteres convertida.

```
char m_szBuffer[ t_nBufferLength];
```

##  <a name="operator_lpstr"></a>  CA2AEX::Operator LPSTR

Operador de conversão.

```
operator LPSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a cadeia de caracteres de texto enquanto digita LPSTR.

## <a name="see-also"></a>Consulte também

[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)