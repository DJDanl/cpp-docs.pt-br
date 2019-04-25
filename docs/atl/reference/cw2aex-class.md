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
ms.openlocfilehash: 97b398dd80bb38b1579458ae0b8b65f082458e23
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62277159"
---
# <a name="cw2aex-class"></a>Classe CW2AEX

Essa classe é usada, as macros de conversão de cadeia de caracteres CT2AEX, CW2TEX, CW2CTEX e CT2CAEX e typedef CW2A.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CW2AEX::Operator LPSTR](#operator_lpstr)|Operador de conversão.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CW2AEX::m_psz](#m_psz)|O membro de dados que armazena a cadeia de caracteres de origem.|
|[CW2AEX::m_szBuffer](#m_szbuffer)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|

## <a name="remarks"></a>Comentários

A menos que a funcionalidade adicional for necessária, use CT2AEX, CW2TEX, CW2CTEX, CT2CAEX ou CW2A em seu código.

Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando **malloc**, liberando a memória quando o objeto sai do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores da ATL, essa classe é seguro para ser usado em loops e que ele não estouram a pilha.

Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de E_OUTOFMEMORY.

Por padrão, as macros e classes de conversão ATL usam página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.

As macros a seguir se baseiam nessa classe:

- CT2AEX

- CW2TEX

- CW2CTEX

- CT2CAEX

O typedef seguir baseia-se nessa classe:

- CW2A

Para uma discussão sobre essas macros de conversão de texto, consulte [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md).

## <a name="example"></a>Exemplo

Ver [ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atlconv. h

##  <a name="cw2aex"></a>  CW2AEX::CW2AEX

O construtor.

```
CW2AEX(LPCWSTR psz, UINT nCodePage) throw(...);
CW2AEX(LPCWSTR psz) throw(...);
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A cadeia de caracteres de texto a ser convertido.

*nCodePage*<br/>
A página de código usada para realizar a conversão. Consulte a discussão de parâmetro de página de código para a função do SDK do Windows [MultiByteToWideChar](/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) para obter mais detalhes.

### <a name="remarks"></a>Comentários

Aloca um buffer usado no processo de tradução.

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

##  <a name="operator_lpstr"></a>  CW2AEX::Operator LPSTR

Operador de conversão.

```
operator LPSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a cadeia de caracteres de texto enquanto digita LPSTR.

## <a name="see-also"></a>Consulte também

[Classe CA2AEX](../../atl/reference/ca2aex-class.md)<br/>
[Classe CA2CAEX](../../atl/reference/ca2caex-class.md)<br/>
[Classe CA2WEX](../../atl/reference/ca2wex-class.md)<br/>
[Classe CW2CWEX](../../atl/reference/cw2cwex-class.md)<br/>
[Classe CW2WEX](../../atl/reference/cw2wex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
