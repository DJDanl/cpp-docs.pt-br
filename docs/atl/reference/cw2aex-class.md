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
ms.openlocfilehash: 4dda1cb9e54c44f7940475660bc629192b9ead61
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496262"
---
# <a name="cw2aex-class"></a>Classe CW2AEX

Essa classe é usada pelas macros de conversão de cadeia de caracteres CT2AEX, CW2TEX, CW2CTEX e CT2CAEX, e o typedef CW2A.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<int t_nBufferLength = 128>
class CW2AEX
```

#### <a name="parameters"></a>Parâmetros

*t_nBufferLength*<br/>
O tamanho do buffer usado no processo de tradução. O comprimento padrão é 128 bytes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2AEX::CW2AEX](#cw2aex)|O construtor.|
|[CW2AEX::~CW2AEX](#dtor)|O destruidor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[LPSTR do CW2AEX:: Operator](#operator_lpstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2AEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|
|[CW2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade extra seja necessária, use CT2AEX, CW2TEX, CW2CTEX, CT2CAEX ou CW2A em seu código.

Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para se ajustar ao buffer estático, a classe alocará memória usando **malloc**, liberando a memória quando o objeto sair do escopo. Isso garante que, ao contrário das macros de conversão de texto disponíveis em versões anteriores do ATL, essa classe seja segura para uso em loops e que ela não ultrapasse a pilha.

Se a classe tentar alocar memória no heap e falhar, ela chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.

Por padrão, as classes de conversão de ATL e macros usam a página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor para a classe.

As macros a seguir se baseiam nesta classe:

- CT2AEX

- CW2TEX

- CW2CTEX

- CT2CAEX

O seguinte typedef se baseia nesta classe:

- CW2A

Para obter uma discussão sobre essas macros de conversão de texto, veja [macros de conversão de cadeias de caracteres ATL e MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Consulte macros de conversão de cadeias de [caracteres ATL e MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AtlConv. h

##  <a name="cw2aex"></a>  CW2AEX::CW2AEX

O construtor.

```
CW2AEX(LPCWSTR psz, UINT nCodePage) throw(...);
CW2AEX(LPCWSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de texto a ser convertida.

*nCodePage*<br/>
A página de código usada para executar a conversão. Consulte a discussão de parâmetro de página de código para a função SDK do Windows [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar) para obter mais detalhes.

### <a name="remarks"></a>Comentários

Aloca o buffer usado no processo de tradução.

##  <a name="dtor"></a>  CW2AEX::~CW2AEX

O destruidor.

```
~CW2AEX() throw();
```

### <a name="remarks"></a>Comentários

Libera o buffer alocado.

##  <a name="m_psz"></a>  CW2AEX::m_psz

O membro de dados que armazena a cadeia de caracteres de origem.

```
LPSTR m_psz;
```

##  <a name="m_szbuffer"></a>  CW2AEX::m_szBuffer

O buffer estático, usado para armazenar a cadeia de caracteres convertida.

```
char m_szBuffer[t_nBufferLength];
```

##  <a name="operator_lpstr"></a>LPSTR do CW2AEX:: Operator

Operador de conversão.

```
operator LPSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a cadeia de texto como o tipo LPSTR.

## <a name="see-also"></a>Consulte também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
