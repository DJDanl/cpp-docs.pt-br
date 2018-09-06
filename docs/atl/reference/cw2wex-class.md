---
title: Classe CW2WEX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CW2WEX
- ATLCONV/ATL::CW2WEX
- ATLCONV/ATL::CW2WEX::CW2WEX
- ATLCONV/ATL::CW2WEX::m_psz
- ATLCONV/ATL::CW2WEX::m_szBuffer
dev_langs:
- C++
helpviewer_keywords:
- CW2WEX class
ms.assetid: 46262e56-e0d2-41fe-855b-0b67ecc8fcd7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d888478be18063b00e1e5e8eabead510349584cf
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43752526"
---
# <a name="cw2wex-class"></a>Classe CW2WEX

Essa classe é usada pelas macros de conversão de cadeia de caracteres CW2TEX CT2WEX e typedef CW2W.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <int t_nBufferLength = 128>  
class CW2WEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*  
O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2WEX::CW2WEX](#cw2wex)|O construtor.|
|[CW2WEX:: ~ CW2WEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2WEX::Operator LPWSTR](#operator_lpwstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2WEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|
|[CW2WEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade adicional for necessária, use CW2TEX, CT2WEX ou CW2W em seu código.

Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando **malloc**, liberando a memória quando o objeto sai do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores da ATL, essa classe é seguro para ser usado em loops e que ele não estouram a pilha.

Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.

Por padrão, as macros e classes de conversão ATL usam página de código ANSI do thread atual para a conversão.

As macros a seguir se baseiam nessa classe:

- CW2TEX

- CT2WEX

O typedef seguir baseia-se nessa classe:

- CW2W

Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Ver [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atlconv. h

##  <a name="cw2wex"></a>  CW2WEX::CW2WEX

O construtor.

```
CW2WEX(LPCWSTR psz, UINT nCodePage) throw(...);
CW2WEX( LPCWSTR  psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*  
A cadeia de caracteres de texto a ser convertido.

*nCodePage*  
A página de código. Não usado nessa classe.

### <a name="remarks"></a>Comentários

Cria o buffer necessário para a tradução.

##  <a name="dtor"></a>  CW2WEX:: ~ CW2WEX

O destruidor...

```
~CW2WEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

##  <a name="m_psz"></a>  CW2WEX::m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```
LPWSTR m_psz;
```

##  <a name="m_szbuffer"></a>  CW2WEX::m_szBuffer

O buffer estático, usado para armazenar a cadeia de caracteres convertida.

```
wchar_t m_szBuffer[t_nBufferLength];
```

##  <a name="operator_lpwstr"></a>  CW2WEX::Operator LPWSTR

Operador cast.

```  
operator LPWSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a cadeia de caracteres de texto enquanto digita LPWSTR.

## <a name="see-also"></a>Consulte também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)   
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)   
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
[Classe CW2AEX](../../atl/reference/cw2aex-class.md)   
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
