---
title: Classe CStringT
ms.date: 03/27/2019
f1_keywords:
- CStringT
- ATLSTR/ATL::CStringT
- ATLSTR/ATL::CStringT::CStringT
- ATLSTR/ATL::CStringT::AllocSysString
- ATLSTR/ATL::CStringT::AnsiToOem
- ATLSTR/ATL::CStringT::AppendFormat
- ATLSTR/ATL::CStringT::Collate
- ATLSTR/ATL::CStringT::CollateNoCase
- ATLSTR/ATL::CStringT::Compare
- ATLSTR/ATL::CStringT::CompareNoCase
- ATLSTR/ATL::CStringT::Delete
- ATLSTR/ATL::CStringT::Find
- ATLSTR/ATL::CStringT::FindOneOf
- ATLSTR/ATL::CStringT::Format
- ATLSTR/ATL::CStringT::FormatMessage
- ATLSTR/ATL::CStringT::FormatMessageV
- ATLSTR/ATL::CStringT::FormatV
- ATLSTR/ATL::CStringT::GetEnvironmentVariable
- ATLSTR/ATL::CStringT::Insert
- ATLSTR/ATL::CStringT::Left
- ATLSTR/ATL::CStringT::LoadString
- ATLSTR/ATL::CStringT::MakeLower
- ATLSTR/ATL::CStringT::MakeReverse
- ATLSTR/ATL::CStringT::MakeUpper
- ATLSTR/ATL::CStringT::Mid
- ATLSTR/ATL::CStringT::OemToAnsi
- ATLSTR/ATL::CStringT::Remove
- ATLSTR/ATL::CStringT::Replace
- ATLSTR/ATL::CStringT::ReverseFind
- ATLSTR/ATL::CStringT::Right
- ATLSTR/ATL::CStringT::SetSysString
- ATLSTR/ATL::CStringT::SpanExcluding
- ATLSTR/ATL::CStringT::SpanIncluding
- ATLSTR/ATL::CStringT::Tokenize
- ATLSTR/ATL::CStringT::Trim
- ATLSTR/ATL::CStringT::TrimLeft
- ATLSTR/ATL::CStringT::TrimRight
- CSTRINGT/CStringT
- CSTRINGT/CStringT::CStringT
- CSTRINGT/CStringT::AllocSysString
- CSTRINGT/CStringT::AnsiToOem
- CSTRINGT/CStringT::AppendFormat
- CSTRINGT/CStringT::Collate
- CSTRINGT/CStringT::CollateNoCase
- CSTRINGT/CStringT::Compare
- CSTRINGT/CStringT::CompareNoCase
- CSTRINGT/CStringT::Delete
- CSTRINGT/CStringT::Find
- CSTRINGT/CStringT::FindOneOf
- CSTRINGT/CStringT::Format
- CSTRINGT/CStringT::FormatMessage
- CSTRINGT/CStringT::FormatMessageV
- CSTRINGT/CStringT::FormatV
- CSTRINGT/CStringT::GetEnvironmentVariable
- CSTRINGT/CStringT::Insert
- CSTRINGT/CStringT::Left
- CSTRINGT/CStringT::LoadString
- CSTRINGT/CStringT::MakeLower
- CSTRINGT/CStringT::MakeReverse
- CSTRINGT/CStringT::MakeUpper
- CSTRINGT/CStringT::Mid
- CSTRINGT/CStringT::OemToAnsi
- CSTRINGT/CStringT::Remove
- CSTRINGT/CStringT::Replace
- CSTRINGT/CStringT::ReverseFind
- CSTRINGT/CStringT::Right
- CSTRINGT/CStringT::SetSysString
- CSTRINGT/CStringT::SpanExcluding
- CSTRINGT/CStringT::SpanIncluding
- CSTRINGT/CStringT::Tokenize
- CSTRINGT/CStringT::Trim
- CSTRINGT/CStringT::TrimLeft
- CSTRINGT/CStringT::TrimRight
helpviewer_keywords:
- strings [C++], in ATL
- shared classes, CStringT
- CStringT class
ms.assetid: 7cacc59c-425f-40f1-8f5b-6db921318ec9
ms.openlocfilehash: a411ed54a73a0dee49ebbd9ccacbd7c6f8e69ca5
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418205"
---
# <a name="cstringt-class"></a>Classe CStringT

Essa classe representa um objeto `CStringT`.

## <a name="syntax"></a>Sintaxe

```
template<typename BaseType, class StringTraits>
class CStringT :
    public CSimpleStringT<BaseType,
        _CSTRING_IMPL_::_MFCDLLTraitsCheck<BaseType, StringTraits>::c_bIsMFCDLLTraits>
```

#### <a name="parameters"></a>parâmetros

*BaseType*<br/>
O tipo de caractere da classe de cadeia de caracteres. Um dos seguintes pode ser feito:

- **Char** (para cadeias de caracteres ANSI).

- **wchar_t** (para cadeias de caracteres Unicode).

- TCHAR (para cadeias de caracteres ANSI e Unicode).

*StringTraits*<br/>
Determina se a classe de cadeia de caracteres precisa de suporte a biblioteca CRT (tempo de execução) e onde os recursos de cadeia de caracteres estão localizados. Um dos seguintes pode ser feito:

- **StrTraitATL < wchar_t** &#124; **Char** &#124; **TCHAR, ChTraitsCRT < wchar_t** &#124; **Char** &#124; **TCHAR > >**

   A classe requer suporte a CRT e procura cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).

- **StrTraitATL < wchar_t** &#124; **Char** &#124; **TCHAR, ChTraitsOS < wchar_t** &#124; **Char** &#124; **TCHAR > >**

   A classe não requer suporte a CRT e procura cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).

- **StrTraitMFC < wchar_t** &#124; **Char** &#124; **TCHAR, ChTraitsCRT < wchar_t** &#124; **Char** &#124; **TCHAR > >**

   A classe requer suporte a CRT e procura cadeias de caracteres de recurso usando o algoritmo de pesquisa padrão do MFC.

- **StrTraitMFC < wchar_t** &#124; **Char** &#124; **TCHAR, ChTraitsOS < wchar_t** &#124; **Char** &#124; **TCHAR > >**

   A classe não requer suporte a CRT e procura cadeias de caracteres de recurso usando o algoritmo de pesquisa padrão do MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CStringT::CStringT](#cstringt)|Constrói um objeto `CStringT` de várias maneiras.|
|[CStringT:: ~ CStringT](#_dtorcstringt)|Destrói um objeto `CStringT`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CStringT::AllocSysString](#allocsysstring)|Aloca um BSTR a partir de `CStringT` dados.|
|[CStringT::AnsiToOem](#ansitooem)|Faz uma conversão in-loco do conjunto de caracteres ANSI no conjunto de caracteres OEM.|
|[CStringT::AppendFormat](#appendformat)|Anexa dados formatados a um objeto de `CStringT` existente.|
|[CStringT:: COLLATE](#collate)|Compara duas cadeias de caracteres (diferencia maiúsculas de minúsculas, usa informações específicas de localidade).|
|[CStringT::CollateNoCase](#collatenocase)|Compara duas cadeias de caracteres (não diferencia maiúsculas de minúsculas, usa informações específicas de localidade).|
|[CStringT:: Compare](#compare)|Compara duas cadeias de caracteres (diferencia maiúsculas de minúsculas).|
|[CStringT::CompareNoCase](#comparenocase)|Compara duas cadeias de caracteres (não diferencia maiúsculas de minúsculas).|
|[CStringT::D excluir](#delete)|Exclui um caractere ou caracteres de uma cadeia de caracteres.|
|[CStringT:: find](#find)|Localiza um caractere ou uma subcadeia de caracteres dentro de uma cadeia de caracteres maior.|
|[CStringT::FindOneOf](#findoneof)|Localiza o primeiro caractere correspondente de um conjunto.|
|[CStringT:: Format](#format)|Formata a cadeia de caracteres como `sprintf`.|
|[CStringT:: FormatMessage](#formatmessage)|Formata uma cadeia de caracteres de mensagem.|
|[CStringT::FormatMessageV](#formatmessagev)|Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variáveis.|
|[CStringT::FormatV](#formatv)|Formata a cadeia de caracteres usando uma lista variável de argumentos.|
|[CStringT:: GetEnvironmentVariable](#getenvironmentvariable)|Define a cadeia de caracteres para o valor da variável de ambiente especificada.|
|[CStringT:: Insert](#insert)|Insere um único caractere ou uma subcadeia de caracteres no índice especificado dentro da cadeia de caracteres.|
|[CStringT:: esquerda](#left)|Extrai a parte esquerda de uma cadeia de caracteres.|
|[CStringT:: LoadString](#loadstring)|Carrega um objeto `CStringT` existente de um recurso do Windows.|
|[CStringT::MakeLower](#makelower)|Converte todos os caracteres nesta cadeia de caracteres em minúsculas.|
|[CStringT::MakeReverse](#makereverse)|Inverte a cadeia de caracteres.|
|[CStringT::MakeUpper](#makeupper)|Converte todos os caracteres nesta cadeia de caracteres em letras maiúsculas.|
|[CStringT:: mid](#mid)|Extrai a parte intermediária de uma cadeia de caracteres.|
|[CStringT::OemToAnsi](#oemtoansi)|Faz uma conversão in-loco do conjunto de caracteres OEM para o conjunto de caracteres ANSI.|
|[CStringT:: Remove](#remove)|Remove os caracteres indicados de uma cadeia de caracteres.|
|[CStringT:: Replace](#replace)|Substitui os caracteres indicados por outros caracteres.|
|[CStringT::ReverseFind](#reversefind)|Localiza um caractere dentro de uma cadeia de caracteres maior; inicia a partir do final.|
|[CStringT:: direita](#right)|Extrai a parte direita de uma cadeia de caracteres.|
|[CStringT::SetSysString](#setsysstring)|Define um objeto BSTR existente com dados de um objeto `CStringT`.|
|[CStringT::SpanExcluding](#spanexcluding)|Extrai caracteres da cadeia de caracteres, começando com o primeiro caractere, que não estão no conjunto de caracteres identificado por `pszCharSet`.|
|[CStringT::SpanIncluding](#spanincluding)|Extrai uma subcadeia de caracteres que contém apenas os caracteres em um conjunto.|
|[CStringT:: Tokenize](#tokenize)|Extrai os tokens especificados em uma cadeia de caracteres de destino.|
|[CStringT:: Trim](#trim)|Corta todos os caracteres de espaço em branco à esquerda e à direita da cadeia de caracteres.|
|[CStringT::TrimLeft](#trimleft)|Corta os caracteres de espaço em branco à esquerda da cadeia de caracteres.|
|[CStringT:: TrimRight](#trimright)|Corta os caracteres de espaço em branco à direita da cadeia de caracteres.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[CStringT:: Operator =](#operator_eq)|Atribui um novo valor a um objeto `CStringT`.|
|[CStringT:: Operator +](#operator_add)|Concatena duas cadeias de caracteres ou um caractere e uma cadeia de caracteres.|
|[CStringT:: Operator + =](#operator_add_eq)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|
|[CStringT:: Operator = =](#operator_eq_eq)|Determina se duas cadeias de caracteres são logicamente iguais.|
|[CStringT:: Operator! =](#operator_neq)|Determina se duas cadeias de caracteres são logicamente diferentes.|
|[Operador CStringT:: Operator &lt;](#operator_lt)|Determina se a cadeia de caracteres no lado esquerdo do operador é menor que a cadeia de caracteres no lado direito.|
|[Operador CStringT:: Operator &gt;](#operator_gt)|Determina se a cadeia de caracteres no lado esquerdo do operador é maior que a cadeia de caracteres no lado direito.|
|[CStringT:: Operator &lt;=](#operator_lt_eq)|Determina se a cadeia de caracteres no lado esquerdo do operador é menor ou igual à cadeia de caracteres no lado direito.|
|[CStringT:: Operator &gt;=](#operator_gt_eq)|Determina se a cadeia de caracteres no lado esquerdo do operador é maior ou igual à cadeia de caracteres no lado direito.|

## <a name="remarks"></a>Comentários

`CStringT` herda da [classe CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md). Recursos avançados, como manipulação de caracteres, ordenação e pesquisa, são implementados por `CStringT`.

> [!NOTE]
> `CStringT` objetos são capazes de lançar exceções. Isso ocorre quando um objeto de `CStringT` fica sem memória por qualquer motivo.

Um objeto `CStringT` consiste em uma sequência de caracteres de comprimento variável. `CStringT` fornece funções e operadores usando sintaxe semelhante à do Basic. Operadores de comparação e concatenação, juntamente com o gerenciamento de memória simplificado, tornam `CStringT` objetos mais fáceis de usar do que as matrizes de caracteres comuns.

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm caracteres nulos inseridos, é recomendável em relação a ela. A chamada de métodos e operadores em objetos `CStringT` que contêm caracteres nulos inseridos pode produzir resultados não pretendidos.

Usando combinações diferentes dos parâmetros `BaseType` e `StringTraits`, `CStringT` objetos podem vir nos seguintes tipos, que foram predefinidos pelas bibliotecas do ATL.

Se estiver usando em um aplicativo ATL:

`CString`, `CStringA`e `CStringW` são exportados da DLL do MFC (MFC90. DLL), nunca de DLLs de usuário. Isso é feito para impedir que `CStringT` sejam definidas de várias vezes.

> [!NOTE]
>  Se o seu código contiver a solução alternativa para erros do vinculador que é descrito em [exportando classes de cadeia de caracteres usando CStringT](../../atl-mfc-shared/exporting-string-classes-using-cstringt.md), você deve remover esse código. Ele não é mais necessário.

Os seguintes tipos de cadeia de caracteres estão disponíveis em aplicativos baseados em MFC:

|Tipo de CStringT|Declaração|
|-------------------|-----------------|
|`CStringA`|Uma cadeia de caracteres de tipo de caractere ANSI com suporte a CRT.|
|`CStringW`|Uma cadeia de caracteres de tipo de caractere Unicode com suporte a CRT.|
|`CString`|Tipos de caracteres ANSI e Unicode com suporte a CRT.|

Os tipos de cadeia de caracteres a seguir estão disponíveis em projetos em que ATL_CSTRING_NO_CRT é definido:

|Tipo de CStringT|Declaração|
|-------------------|-----------------|
|`CAtlStringA`|Uma cadeia de caracteres de tipo de caractere ANSI sem suporte a CRT.|
|`CAtlStringW`|Uma cadeia de caracteres de tipo de caractere Unicode sem suporte a CRT.|
|`CAtlString`|Tipos de caracteres ANSI e Unicode sem suporte a CRT.|

Os tipos de cadeia de caracteres a seguir estão disponíveis em projetos em que ATL_CSTRING_NO_CRT não está definido:

|Tipo de CStringT|Declaração|
|-------------------|-----------------|
|`CAtlStringA`|Uma cadeia de caracteres de tipo de caractere ANSI com suporte a CRT.|
|`CAtlStringW`|Uma cadeia de caracteres de tipo de caractere Unicode com suporte a CRT.|
|`CAtlString`|Tipos de caracteres ANSI e Unicode com suporte a CRT.|

`CString` objetos também têm as seguintes características:

- `CStringT` objetos podem crescer como resultado de operações de concatenação.

- os objetos `CStringT` seguem "semântica de valor". Imagine um objeto `CStringT` como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.

- Você pode substituir livremente `CStringT` objetos para `PCXSTR` argumentos de função.

- Gerenciamento de memória personalizado para buffers de cadeia de caracteres. Para obter mais informações, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="cstringt-predefined-types"></a>CStringT tipos predefinidos

Como `CStringT` usa um argumento de modelo para definir o tipo de caractere ( [wchar_t](../../c-runtime-library/standard-types.md) ou [Char](../../c-runtime-library/standard-types.md)) com suporte, os tipos de parâmetro de método podem ser complicados às vezes. Para simplificar esse problema, um conjunto de tipos predefinidos é definido e usado em toda a classe `CStringT`. A tabela a seguir lista os vários tipos:

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`XCHAR`|Um único caractere ( **wchar_t** ou **Char**) com o mesmo tipo de caractere que o objeto `CStringT`.|
|`YCHAR`|Um único caractere ( **wchar_t** ou **Char**) com o tipo de caractere oposto como o objeto `CStringT`.|
|`PXSTR`|Um ponteiro para uma cadeia de caracteres ( **wchar_t** ou **Char**) com o mesmo tipo de caractere que o objeto `CStringT`.|
|`PYSTR`|Um ponteiro para uma cadeia de caracteres ( **wchar_t** ou **Char**) com o tipo de caractere oposto como o objeto `CStringT`.|
|`PCXSTR`|Um ponteiro para uma cadeia de caracteres **const** ( **wchar_t** ou **Char**) com o mesmo tipo de caractere que o objeto `CStringT`.|
|`PCYSTR`|Um ponteiro para uma cadeia de caracteres **const** ( **wchar_t** ou **Char**) com o tipo de caractere oposto como o objeto `CStringT`.|

> [!NOTE]
>  O código que usei anteriormente métodos não documentados de `CString` (como `AssignCopy`) deve ser substituído pelo código que usa os seguintes métodos documentados de `CStringT` (como `GetBuffer` ou `ReleaseBuffer`). Esses métodos são herdados de `CSimpleStringT`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)

`CStringT`

## <a name="requirements"></a>Requisitos

|Cabeçalho|Usar para|
|------------|-------------|
|cstringt.h|Objetos de cadeia de caracteres somente MFC|
|atlstr.h|Objetos de cadeia de caracteres não MFC|

##  <a name="allocsysstring"></a>CStringT::AllocSysString

Aloca uma cadeia de caracteres compatível com a automação do tipo BSTR e copia o conteúdo do `CStringT` objeto nele, incluindo o caractere nulo de terminação.

```
BSTR AllocSysString() const;
```

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres alocada recentemente.

### <a name="remarks"></a>Comentários

Em programas MFC, uma [classe CMemoryException](../../mfc/reference/cmemoryexception-class.md) é lançada se houver memória insuficiente. Em programas ATL, um [CAtlException](../../atl/reference/catlexception-class.md) é lançado. Essa função normalmente é usada para retornar cadeias de caracteres para automação.

Normalmente, se essa cadeia de caracteres for passada para uma função COM como um parâmetro [in], isso exigirá que o chamador libere a cadeia de caracteres. Isso pode ser feito usando [SysFreeString](/windows/win32/api/oleauto/nf-oleauto-sysfreestring), conforme descrito na SDK do Windows. Para obter mais informações, consulte [alocando e liberando memória para um BSTR](../../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md).

Para obter mais informações sobre funções de alocação OLE no Windows, consulte [SysAllocString](/windows/win32/api/oleauto/nf-oleauto-sysallocstring) no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CStringT::AllocSysString`.

[!code-cpp[NVC_ATLMFC_Utilities#105](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_1.cpp)]

##  <a name="ansitooem"></a>CStringT::AnsiToOem

Converte todos os caracteres neste `CStringT` objeto do conjunto de caracteres ANSI para o conjunto de caracteres OEM.

```
void AnsiToOem();
```

### <a name="remarks"></a>Comentários

A função não estará disponível se _UNICODE for definida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#106](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_2.cpp)]

##  <a name="appendformat"></a>CStringT::AppendFormat

Anexa dados formatados a um objeto de `CStringT` existente.

```
void __cdecl AppendFormat(PCXSTR pszFormat, [, argument] ...);
void __cdecl AppendFormat(UINT nFormatID, [, argument] ...);
```

### <a name="parameters"></a>parâmetros

*pszFormat*<br/>
Uma cadeia de caracteres de controle de formato.

*nFormatID*<br/>
O identificador de recurso de cadeia de caracteres que contém a cadeia de caracteres de controle de formato.

*argument*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

Essa função formata e acrescenta uma série de caracteres e valores no `CStringT`. Cada argumento opcional (se houver) é convertido e acrescentado de acordo com a especificação de formato correspondente em *pszFormat* ou do recurso de cadeia de caracteres identificado por *nFormatID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#107](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_3.cpp)]

##  <a name="collate"></a>CStringT:: COLLATE

Compara duas cadeias de caracteres usando a função de texto genérico `_tcscoll`.

```
int Collate(PCXSTR psz) const throw();
```

### <a name="parameters"></a>parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as cadeias de caracteres forem idênticas, < 0 se esse objeto `CStringT` for menor que *psz*ou > 0 se esse objeto `CStringT` for maior que *psz*.

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcscoll`, que é definida em TCHAR. H, mapeia para `strcoll`, `wcscoll`ou `_mbscoll`, dependendo do conjunto de caracteres definido no momento da compilação. Cada função executa uma comparação de maiúsculas e minúsculas das cadeias de caracteres de acordo com a página de código em uso no momento. Para obter mais informações, consulte [strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).

##  <a name="collatenocase"></a>CStringT::CollateNoCase

Compara duas cadeias de caracteres usando a função de texto genérico `_tcscoll`.

```
int CollateNoCase(PCXSTR psz) const throw();
```

### <a name="parameters"></a>parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as cadeias de caracteres forem idênticas (ignorando maiúsculas e minúsculas), < 0 se esse objeto `CStringT` for menor que *psz* (ignorando maiúsculas/minúsculas) ou > 0 se esse objeto `CStringT` for maior que *psz* (ignorando maiúsculas/minúsculas)

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcscoll`, que é definida em TCHAR. H, mapeia para `stricoll`, `wcsicoll`ou `_mbsicoll`, dependendo do conjunto de caracteres definido no momento da compilação. Cada função executa uma comparação que não diferencia maiúsculas de minúsculas das cadeias de caracteres, de acordo com a página de código em uso no momento. Para obter mais informações, consulte [strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#109](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_4.cpp)]

##  <a name="compare"></a>CStringT:: Compare

Compara duas cadeias de caracteres (diferencia maiúsculas de minúsculas).

```
int Compare(PCXSTR psz) const;
```

### <a name="parameters"></a>parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as cadeias de caracteres forem idênticas, < 0 se esse objeto `CStringT` for menor que *psz*ou > 0 se esse objeto `CStringT` for maior que *psz*.

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcscmp`, que é definida em TCHAR. H, mapeia para `strcmp`, `wcscmp`ou `_mbscmp`, dependendo do conjunto de caracteres definido no momento da compilação. Cada função executa uma comparação de maiúsculas e minúsculas das cadeias de caracteres e não é afetada pela localidade. Para obter mais informações, consulte [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md).

Se a cadeia de caracteres contiver nulos incorporados, para fins de comparação, a cadeia de caracteres será considerada truncada no primeiro caractere nulo inserido.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CStringT::Compare`.

[!code-cpp[NVC_ATLMFC_Utilities#110](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_5.cpp)]

##  <a name="comparenocase"></a>CStringT::CompareNoCase

Compara duas cadeias de caracteres (não diferencia maiúsculas de minúsculas).

```
int CompareNoCase(PCXSTR psz) const throw();
```

### <a name="parameters"></a>parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as cadeias de caracteres forem idênticas (ignorando maiúsculas e minúsculas), < 0 se esse objeto `CStringT` for menor que *psz* (ignorando maiúsculas/minúsculas) ou > 0 se esse objeto `CStringT` for maior que *psz* (ignorando maiúsculas/minúsculas)

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcsicmp`, que é definida em TCHAR. H, mapeia para `_stricmp`, `_wcsicmp` ou `_mbsicmp`, dependendo do conjunto de caracteres definido no momento da compilação. Cada função executa uma comparação que não diferencia maiúsculas de minúsculas das cadeias de caracteres. A comparação depende do aspecto LC_CTYPE da localidade, mas não LC_COLLATE. Para obter mais informações, consulte [_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#111](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_6.cpp)]

##  <a name="cstringt"></a>CStringT::CStringT

Constrói um objeto `CStringT`.

```
CStringT() throw() :
    CThisSimpleString(StringTraits::GetDefaultManager());

explicit CStringT(IAtlStringMgr* pStringMgr) throw() :
    CThisSimpleString( pStringMgr);

CStringT(const VARIANT& varSrc);

CStringT(const VARIANT& varSrc, IAtlStringMgr* pStringMgr);

CStringT(const CStringT& strSrc) :
    CThisSimpleString( strSrc);

operator CSimpleStringT<
                    BaseType,
                    !_CSTRING_IMPL_::_MFCDLLTraitsCheck<BaseType, StringTraits>
                    :: c_bIsMFCDLLTraits> &()

template <bool bMFCDLL>
CStringT(const CSimpleStringT<BaseType, bMFCDLL>& strSrc) :
    CThisSimpleString( strSrc);

template <class SystemString>
CStringT(SystemString^ pString) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CStringT(const XCHAR* pszSrc) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CSTRING_EXPLICIT CStringT(const YCHAR* pszSrc) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CStringT(LPCSTR pszSrc, IAtlStringMgr* pStringMgr) :
    CThisSimpleString( pStringMgr);

CStringT(LPCWSTR pszSrc, IAtlStringMgr* pStringMgr) :
    CThisSimpleString( pStringMgr);

CSTRING_EXPLICIT CStringT(const unsigned char* pszSrc) :
    CThisSimpleString( StringTraits::GetDefaultManager());

/*CSTRING_EXPLICIT*/ CStringT(char* pszSrc) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CSTRING_EXPLICIT CStringT(unsigned char* pszSrc) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CSTRING_EXPLICIT CStringT(wchar_t* pszSrc) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CStringT(const unsigned char* pszSrc, IAtlStringMgr* pStringMgr) :
    CThisSimpleString( pStringMgr);

CSTRING_EXPLICIT CStringT(char ch, int nLength = 1) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CSTRING_EXPLICIT CStringT(wchar_t ch, int nLength = 1) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CStringT(const XCHAR* pch, int nLength) :
    CThisSimpleString( pch, nLength, StringTraits::GetDefaultManager());

CStringT(const YCHAR* pch, int nLength) :
    CThisSimpleString( StringTraits::GetDefaultManager());

CStringT(const XCHAR* pch, int nLength, AtlStringMgr* pStringMgr) :
    CThisSimpleString( pch, nLength, pStringMgr);

CStringT(const YCHAR* pch, int nLength, IAtlStringMgr* pStringMgr) :
    CThisSimpleString( pStringMgr);
```

### <a name="parameters"></a>parâmetros

*PCH*<br/>
Um ponteiro para uma matriz de caracteres de comprimento *nLength*, não terminada em nulo.

*nLength*<br/>
Uma contagem do número de caracteres em *PCH*.

*CH*<br/>
Um único caractere.

*pszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiada para este `CStringT` objeto.

*pStringMgr*<br/>
Um ponteiro para o Gerenciador de memória para o objeto `CStringT`. Para obter mais informações sobre `IAtlStringMgr` e gerenciamento de memória para `CStringT`, consulte [Gerenciamento de memória com CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

*strSrc*<br/>
Um objeto de `CStringT` existente a ser copiado para este objeto `CStringT`. Para obter mais informações sobre `CThisString` e `CThisSimpleString`, consulte a seção comentários.

*varSrc*<br/>
Um objeto Variant a ser copiado para este `CStringT` objeto.

*BaseType*<br/>
O tipo de caractere da classe de cadeia de caracteres. Um dos seguintes pode ser feito:

**Char** (para cadeias de caracteres ANSI).

**wchar_t** (para cadeias de caracteres Unicode).

TCHAR (para cadeias de caracteres ANSI e Unicode).

*bMFCDLL*<br/>
Booliano que especifica se o projeto é uma DLL do MFC (TRUE) ou não (FALSE).

*Sistema*<br/>
Deve ser `System::String`e o projeto deve ser compilado com/CLR.

*pString*<br/>
Um identificador para um objeto de `CStringT`.

### <a name="remarks"></a>Comentários

Como os construtores copiam os dados de entrada para um novo armazenamento alocado, você deve estar ciente de que as exceções de memória podem resultar. Observe que alguns desses construtores atuam como funções de conversão. Isso permite que você substitua, por exemplo, um LPTSTR em que um objeto `CStringT` é esperado.

- `CStringT`(`LPCSTR` `lpsz`): constrói um `CStringT` Unicode a partir de uma cadeia de caracteres ANSI. Você também pode usar esse construtor para carregar um recurso de cadeia de caracteres, conforme mostrado no exemplo abaixo.

- `CStringT(` `LPCWSTR` `lpsz`): constrói um `CStringT` de uma cadeia de caracteres Unicode.

- `CStringT`(`const unsigned char*` `psz`): permite que você construa um `CStringT` de um ponteiro para um **caractere não assinado**.

> [!NOTE]
>  Defina a macro _CSTRING_DISABLE_NARROW_WIDE_CONVERSION para desativar a conversão de cadeia de caracteres implícita entre as cadeias ANSI e Unicode. A macro é excluída dos construtores de compilação que dão suporte à conversão.

Observe que o parâmetro *strSrc* pode ser um objeto `CStringT` ou `CThisSimpleString`. Por `CStringT`, use uma de suas instanciações padrão (`CString`, `CStringA`ou `CStringW`); para `CThisSimpleString`, **use um ponteiro** . `CThisSimpleString` declara uma instância da [classe CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), que é uma classe de cadeia de caracteres menor com funcionalidade menos interna do que a classe `CStringT`.

O operador Overload `CSimpleStringT<>&()` constrói um objeto `CStringT` de uma declaração `CSimpleStringT`.

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm caracteres nulos inseridos, é recomendável em relação a ela. A chamada de métodos e operadores em objetos `CStringT` que contêm caracteres nulos inseridos pode produzir resultados não pretendidos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#112](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_7.cpp)]

##  <a name="_dtorcstringt"></a>CStringT:: ~ CStringT

Destrói o objeto `CStringT`.

```
~CStringT() throw();
```

### <a name="remarks"></a>Comentários

Destrói o objeto `CStringT`.

##  <a name="delete"></a>CStringT::D excluir

Exclui um caractere ou caracteres de uma cadeia de caracteres começando com o caractere no índice fornecido.

```
int Delete(int iIndex, int nCount = 1);
```

### <a name="parameters"></a>parâmetros

*iIndex*<br/>
O índice de base zero do primeiro caractere no objeto `CStringT` a ser excluído.

*nCount*<br/>
O número de caracteres a serem removidos.

### <a name="return-value"></a>Valor retornado

O comprimento da cadeia de caracteres alterada.

### <a name="remarks"></a>Comentários

Se *nCount* for maior que a cadeia de caracteres, o restante da cadeia de caracteres será removido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#113](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_8.cpp)]

```Output
Before: Soccer is best,
    but hockey is quicker!
After: Soccer best,
    but hockey is quicker!
```

##  <a name="find"></a>CStringT:: find

Pesquisa essa cadeia de caracteres para a primeira correspondência de um caractere ou Subcadeia de caracteres.

```
int Find(PCXSTR pszSub, int iStart=0) const throw();
int Find(XCHAR ch, int iStart=0) const throw();
```

### <a name="parameters"></a>parâmetros

*pszSub*<br/>
Uma subcadeia de caracteres a ser pesquisada.

*isniciar*<br/>
O índice do caractere na cadeia de caracteres para começar a pesquisa com ou 0 para começar desde o início.

*CH*<br/>
Um único caractere a ser pesquisado.

### <a name="return-value"></a>Valor retornado

O índice de base zero do primeiro caractere neste `CStringT` objeto que corresponde à Subcadeia ou aos caracteres solicitados; -1 se a subcadeia de caracteres ou o caractere não for encontrado.

### <a name="remarks"></a>Comentários

A função é sobrecarregada para aceitar os dois caracteres únicos (semelhantes à função de tempo de execução `strchr`) e cadeias (semelhante a `strstr`).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#114](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_9.cpp)]

##  <a name="findoneof"></a>CStringT::FindOneOf

Pesquisa essa cadeia de caracteres para o primeiro caractere que corresponde a qualquer caractere contido em *pszCharSet*.

```
int FindOneOf(PCXSTR pszCharSet) const throw();
```

### <a name="parameters"></a>parâmetros

*pszCharSet*<br/>
Cadeia que contém caracteres para correspondência.

### <a name="return-value"></a>Valor retornado

O índice de base zero do primeiro caractere nesta cadeia de caracteres que também está em *pszCharSet*; -1 se não houver nenhuma correspondência.

### <a name="remarks"></a>Comentários

Localiza a primeira ocorrência de qualquer um dos caracteres em *pszCharSet*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#115](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_10.cpp)]

##  <a name="format"></a>CStringT:: Format

Grava dados formatados em um `CStringT` da mesma maneira que [sprintf_s](../../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md) formata dados em uma matriz de caracteres em estilo C.

```
void __cdecl Format(UINT nFormatID, [, argument]...);
void __cdecl Format(PCXSTR pszFormat,  [, argument] ...);
```

### <a name="parameters"></a>parâmetros

*nFormatID*<br/>
O identificador de recurso de cadeia de caracteres que contém a cadeia de caracteres de controle de formato.

*pszFormat*<br/>
Uma cadeia de caracteres de controle de formato.

*argument*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

Essa função formata e armazena uma série de caracteres e valores no `CStringT`. Cada argumento opcional (se houver) é convertido e apresentado de acordo com a especificação de formato correspondente em *pszFormat* ou do recurso de cadeia de caracteres identificado por *nFormatID*.

A chamada falhará se o próprio objeto de cadeia de caracteres for oferecido como um parâmetro para `Format`. Por exemplo, o código a seguir causará resultados imprevisíveis:

[!code-cpp[NVC_ATLMFC_Utilities#116](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_11.cpp)]

Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#117](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_12.cpp)]

##  <a name="formatmessage"></a>CStringT:: FormatMessage

Formata uma cadeia de caracteres de mensagem.

```
void __cdecl FormatMessage(UINT nFormatID, [, argument]...);
void __cdecl FormatMessage(PCXSTR pszFormat, [, argument]...);
```

### <a name="parameters"></a>parâmetros

*nFormatID*<br/>
O identificador de recurso de cadeia de caracteres que contém o texto da mensagem não formatada.

*pszFormat*<br/>
Aponta para a cadeia de caracteres de controle de formato. Ela será verificada em busca de inserções e formatadas adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução do formato estilo *printf*, exceto pelo fato de permitir que os parâmetros sejam inseridos em uma ordem arbitrária.

*argument*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

A função requer uma definição de mensagem como entrada. A definição de mensagem é determinada por *pszFormat* ou do recurso de cadeia de caracteres identificado por *nFormatID*. A função copia o texto da mensagem formatada para o objeto `CStringT`, processando as sequências inseridas inseridas, se solicitado.

> [!NOTE]
> `FormatMessage` tenta alocar memória do sistema para a cadeia de caracteres formatada recentemente. Se essa tentativa falhar, uma exceção de memória será gerada automaticamente.

Cada inserção deve ter um parâmetro correspondente após o parâmetro *pszFormat* ou *nFormatID* . Dentro do texto da mensagem, há suporte para várias sequências de escape para a formatação dinâmica da mensagem. Para obter mais informações, consulte a função [FormatMessage](/windows/win32/api/winbase/nf-winbase-formatmessage) do Windows no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#118](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_13.cpp)]

##  <a name="formatmessagev"></a>CStringT::FormatMessageV

Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variáveis.

```
void FormatMessageV(PCXSTR pszFormat, va_list* pArgList);
```

### <a name="parameters"></a>parâmetros

*pszFormat*<br/>
Aponta para a cadeia de caracteres de controle de formato. Ela será verificada em busca de inserções e formatadas adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`cadeias de caracteres de formato de estilo, exceto pelo fato de que os parâmetros a serem inseridos em uma ordem arbitrária.

*pArgList*<br/>
Ponteiro para uma lista de argumentos.

### <a name="remarks"></a>Comentários

A função requer uma definição de mensagem como entrada, determinada por *pszFormat*. A função copia o texto da mensagem formatada e uma lista variável de argumentos para o objeto `CStringT`, processando as sequências inseridas inseridas, se solicitado.

> [!NOTE]
> `FormatMessageV` chama [CStringT:: FormatMessage](#formatmessage), que tenta alocar a memória do sistema para a cadeia de caracteres formatada recentemente. Se essa tentativa falhar, uma exceção de memória será gerada automaticamente.

Para obter mais informações, consulte a função [FormatMessage](/windows/win32/api/winbase/nf-winbase-formatmessage) do Windows no SDK do Windows.

##  <a name="formatv"></a>CStringT::FormatV

Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variáveis.

```
void FormatV(PCXSTR pszFormat, va_list args);
```

### <a name="parameters"></a>parâmetros

*pszFormat*<br/>
Aponta para a cadeia de caracteres de controle de formato. Ela será verificada em busca de inserções e formatadas adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`cadeias de caracteres de formato de estilo, exceto pelo fato de que os parâmetros a serem inseridos em uma ordem arbitrária.

*args*<br/>
Ponteiro para uma lista de argumentos.

### <a name="remarks"></a>Comentários

Grava uma cadeia de caracteres formatada e uma lista variável de argumentos para uma cadeia de caracteres `CStringT` da mesma maneira que `vsprintf_s` formata dados em uma matriz de caracteres em estilo C.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#119](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_14.cpp)]

[!code-cpp[NVC_ATLMFC_Utilities#120](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_15.cpp)]

##  <a name="getenvironmentvariable"></a>CStringT:: GetEnvironmentVariable

Define a cadeia de caracteres para o valor da variável de ambiente especificada.

```
BOOL GetEnvironmentVariable(PCXSTR pszVar);
```

### <a name="parameters"></a>parâmetros

*pszVar*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a variável de ambiente.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Recupera o valor da variável especificada do bloco de ambiente do processo de chamada. O valor está na forma de uma cadeia de caracteres terminada em nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#121](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_16.cpp)]

##  <a name="insert"></a>CStringT:: Insert

Insere um único caractere ou uma subcadeia de caracteres no índice especificado dentro da cadeia de caracteres.

```
int Insert(int iIndex, PCXSTR psz);
int Insert(int iIndex, XCHAR ch);
```

### <a name="parameters"></a>parâmetros

*iIndex*<br/>
O índice do caractere antes do qual a inserção ocorrerá.

*psz*<br/>
Um ponteiro para a subcadeia de caracteres a ser inserida.

*CH*<br/>
O caractere a ser inserido.

### <a name="return-value"></a>Valor retornado

O comprimento da cadeia de caracteres alterada.

### <a name="remarks"></a>Comentários

O parâmetro *iIndex* identifica o primeiro caractere que será movido para liberar espaço para o caractere ou a subcadeia de caracteres. Se *nIndex* for zero, a inserção ocorrerá antes da cadeia de caracteres inteira. Se *nIndex* for maior que o comprimento da cadeia de caracteres, a função concatenará a cadeia de caracteres atual e o novo material fornecido por *ch* ou *psz*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#122](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_17.cpp)]

##  <a name="left"></a>CStringT:: esquerda

Extrai os caracteres *nCount* mais à esquerda desse objeto `CStringT` e retorna uma cópia da subcadeia de caracteres extraída.

```
CStringT Left(int nCount) const;
```

### <a name="parameters"></a>parâmetros

*nCount*<br/>
O número de caracteres para extrair desse objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. O objeto `CStringT` retornado pode estar vazio.

### <a name="remarks"></a>Comentários

Se *nCount* exceder o comprimento da cadeia de caracteres, a cadeia de caracteres inteira será extraída. `Left` é semelhante à função `Left` básica.

Para os conjuntos de caracteres de vários bytes (MBCS), *nCount* trata cada sequência de 8 bits como um caractere, de modo que *nCount* retorna o número de caracteres de byte múltiplo multiplicado por dois.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#123](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_18.cpp)]

##  <a name="loadstring"></a>CStringT:: LoadString

Lê um recurso de cadeia de caracteres do Windows, identificado por *NID*, em um objeto `CStringT` existente.

```
BOOL LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID);
BOOL LoadString(HINSTANCE hInstance, UINT nID);
BOOL LoadString(UINT nID);
```

### <a name="parameters"></a>parâmetros

*hInstance*<br/>
Um identificador para a instância do módulo.

*nID*<br/>
Uma ID de recurso de cadeia de caracteres do Windows.

*wLanguageID*<br/>
O idioma do recurso de cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o carregamento do recurso tiver sido bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Carrega o recurso de cadeia de caracteres (*NID*) do módulo especificado (*HINSTANCE*) usando o idioma especificado (*wLanguage*).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#124](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_19.cpp)]

##  <a name="makelower"></a>CStringT::MakeLower

Converte o objeto `CStringT` em uma cadeia de caracteres minúsculas.

```
CStringT& MakeLower();
```

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres minúsculas resultante.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#125](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_20.cpp)]

##  <a name="makereverse"></a>CStringT::MakeReverse

Reverte a ordem dos caracteres no objeto `CStringT`.

```
CStringT& MakeReverse();
```

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres inversa resultante.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#126](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_21.cpp)]

##  <a name="makeupper"></a>CStringT::MakeUpper

Converte o objeto `CStringT` em uma cadeia de caracteres maiúsculo.

```
CStringT& MakeUpper();
```

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres em maiúscula resultante.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#127](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_22.cpp)]

##  <a name="mid"></a>CStringT:: mid

Extrai uma subcadeia de caracteres de comprimento *nCount* a partir deste `CStringT` objeto, começando na posição *iFirst* (baseado em zero).

```
CStringT Mid(int iFirst, int nCount) const;
CStringT Mid(int iFirst) const;
```

### <a name="parameters"></a>parâmetros

*iFirst*<br/>
O índice de base zero do primeiro caractere neste `CStringT` objeto a ser incluído na Subcadeia de caracteres extraída.

*nCount*<br/>
O número de caracteres para extrair desse objeto `CStringT`. Se esse parâmetro não for fornecido, o restante da cadeia de caracteres será extraído.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o objeto `CStringT` retornado pode estar vazio.

### <a name="remarks"></a>Comentários

A função retorna uma cópia da subcadeia de caracteres extraída. `Mid` é semelhante à função mid básica (exceto que os índices em básico são baseados em um).

Para os conjuntos de caracteres multibyte (MBCS), *nCount* se refere a cada caractere de 8 bits; ou seja, um byte de Lead e trilha em um caractere multibyte são contados como dois caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#128](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_23.cpp)]

##  <a name="oemtoansi"></a>CStringT::OemToAnsi

Converte todos os caracteres neste `CStringT` objeto do conjunto de caracteres OEM para o conjunto de caracteres ANSI.

```
void OemToAnsi();
```

### <a name="remarks"></a>Comentários

Essa função não estará disponível se _UNICODE estiver definida.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CStringT:: AnsiToOem](#ansitooem).

##  <a name="operator_eq"></a>CStringT:: Operator =

Atribui um novo valor à cadeia de caracteres.

```
CStringT& operator=(const CStringT& strSrc);

template<bool bMFCDLL>
CStringT& operator=(const CSimpleStringT<BaseType, bMFCDLL>& str);

CStringT& operator=(PCXSTR pszSrc);
CStringT& operator=(PCYSTR pszSrc);
CStringT& operator=(const unsigned char* pszSrc);
CStringT& operator=(XCHAR ch);
CStringT& operator=(YCHAR ch);
CStringT& operator=(const VARIANT& var);
```

### <a name="parameters"></a>parâmetros

*strSrc*<br/>
Uma `CStringT` para atribuir a essa cadeia de caracteres.

*str*<br/>
Uma referência a um objeto `CThisSimpleString`.

*bMFCDLL*<br/>
Um booliano que especifica se o projeto é uma DLL MFC ou não.

*BaseType*<br/>
O tipo de base da cadeia de caracteres.

*var*<br/>
Um objeto Variant a ser atribuído a esta cadeia de caracteres.

*CH*<br/>
Um caractere ANSI ou Unicode para atribuir à cadeia de caracteres.

*pszSrc*<br/>
Um ponteiro para a cadeia de caracteres original que está sendo atribuída.

### <a name="remarks"></a>Comentários

O operador de atribuição aceita outro objeto de `CStringT`, um ponteiro de caractere ou um único caractere. Você deve estar ciente de que as exceções de memória podem ocorrer sempre que você usar esse operador porque um novo armazenamento pode ser alocado.

Para obter informações sobre `CThisSimpleString`, consulte a seção comentários de [CStringT:: CStringT](#cstringt).

> [!NOTE]
> Embora seja possível criar `CStringT` instâncias que contêm caracteres nulos inseridos, é recomendável em relação a ela. A chamada de métodos e operadores em objetos `CStringT` que contêm caracteres nulos inseridos pode produzir resultados não pretendidos.

##  <a name="operator_add"></a>CStringT:: Operator +

Concatena duas cadeias de caracteres ou um caractere e uma cadeia de caracteres.

```
friend CStringT operator+(const CStringT& str1, const CStringT& str2);
friend CStringT operator+(const CStringT& str1, PCXSTR psz2);
friend CStringT operator+(PCXSTR psz1, const CStringT& str2,);
friend CStringT operator+(char ch1, const CStringT& str2,);
friend CStringT operator+(const CStringT& str1, char ch2);
friend CStringT operator+(const CStringT& str1, wchar_t ch2);
friend CStringT operator+(wchar_t ch1, const CStringT& str2,);
```

### <a name="parameters"></a>parâmetros

*ch1*<br/>
Um caractere ANSI ou Unicode para concatenar com uma cadeia de caracteres.

*ch2*<br/>
Um caractere ANSI ou Unicode para concatenar com uma cadeia de caracteres.

*str1*<br/>
Um `CStringT` para concatenar com uma cadeia de caracteres ou um caractere.

*str2*<br/>
Um `CStringT` para concatenar com uma cadeia de caracteres ou um caractere.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para concatenar com uma cadeia de caracteres ou um caractere.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres para concatenar com uma cadeia de caracteres ou caractere.

### <a name="remarks"></a>Comentários

Há sete formas de sobrecarga da função `CStringT::operator+`. A primeira versão concatena dois objetos de `CStringT` existentes. As duas próximas concatenam um objeto `CStringT` e uma cadeia de caracteres terminada em nulo. As duas próximas concatenam um objeto `CStringT` e um caractere ANSI. Os dois últimos concatenam um objeto `CStringT` e um caractere Unicode.

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm caracteres nulos inseridos, é recomendável em relação a ela. A chamada de métodos e operadores em objetos `CStringT` que contêm caracteres nulos inseridos pode produzir resultados não pretendidos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#140](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_24.cpp)]

##  <a name="operator_add_eq"></a>CStringT:: Operator + =

Concatena caracteres no final da cadeia de caracteres.

```
CStringT& operator+=(const CThisSimpleString& str);

template<bool bMFCDLL>
CStringT& operator+=(const const CSimpleStringT<BaseType, bMFCDLL>& str);

template<int t_nSize>
CStringT& operator+=(const CStaticString<XCHAR, t_nSize>& strSrc);
CStringT& operator+=(PCXSTR pszSrc);
CStringT& operator+=(PCYSTR pszSrc);
CStringT& operator+=(char ch);
CStringT& operator+=(unsigned char ch);
CStringT& operator+=(wchar_t ch);
CStringT& operator+=(const VARIANT& var);
```

### <a name="parameters"></a>parâmetros

*str*<br/>
Uma referência a um objeto `CThisSimpleString`.

*bMFCDLL*<br/>
Um booliano que especifica se o projeto é uma DLL MFC ou não.

*BaseType*<br/>
O tipo de base da cadeia de caracteres.

*var*<br/>
Um objeto Variant para concatenar a esta cadeia de caracteres.

*CH*<br/>
Um caractere ANSI ou Unicode para concatenar com uma cadeia de caracteres.

*pszSrc*<br/>
Um ponteiro para a cadeia de caracteres original que está sendo concatenada.

*strSrc*<br/>
Um `CStringT` para concatenar a esta cadeia de caracteres.

### <a name="remarks"></a>Comentários

O operador aceita outro objeto `CStringT`, um ponteiro de caractere ou um único caractere. Você deve estar ciente de que as exceções de memória podem ocorrer sempre que você usar esse operador de concatenação porque um novo armazenamento pode ser alocado para caracteres adicionados a esse objeto de `CStringT`.

Para obter informações sobre `CThisSimpleString`, consulte a seção comentários de [CStringT:: CStringT](#cstringt).

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm caracteres nulos inseridos, é recomendável em relação a ela. A chamada de métodos e operadores em objetos `CStringT` que contêm caracteres nulos inseridos pode produzir resultados não pretendidos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#141](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_25.cpp)]

##  <a name="operator_eq_eq"></a>CStringT:: Operator = =

Determina se duas cadeias de caracteres são logicamente iguais.

```
friend bool operator==(const CStringT& str1, const CStringT& str2) throw();
friend bool operator==(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator==(const CStringT& str1, PCYSTR psz2) throw();
friend bool operator==(const CStringT& str1, XCHAR ch2) throw();
friend bool operator==(PCXSTR psz1, const CStringT& str2) throw();
friend bool operator==(PCYSTR psz1, const CStringT& str2,) throw();
friend bool operator==(XCHAR ch1, const CStringT& str2,) throw();
```

### <a name="parameters"></a>parâmetros

*ch1*<br/>
Um caractere ANSI ou Unicode para comparação.

*ch2*<br/>
Um caractere ANSI ou Unicode para comparação.

*str1*<br/>
Uma `CStringT` para comparação.

*str2*<br/>
Uma `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Testa se uma cadeia de caracteres ou caractere no lado esquerdo é igual a uma cadeia de caracteres ou caractere no lado direito e retorna TRUE ou FALSE de acordo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#142](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_26.cpp)]

##  <a name="operator_neq"></a>CStringT:: Operator! =

Determina se duas cadeias de caracteres são logicamente diferentes.

```
friend bool operator!=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator!=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator!=(const CStringT& str1, PCYSTR psz2) throw();
friend bool operator!=(const CStringT& str1, XCHAR ch2) throw();
friend bool operator!=(PCXSTR psz1, const CStringT& str2) throw();
friend bool operator!=(PCYSTR psz1, const CStringT& str2,) throw();
friend bool operator!=(XCHAR ch1, const CStringT& str2,) throw();
```

### <a name="parameters"></a>parâmetros

*ch1*<br/>
Um caractere ANSI ou Unicode para concatenar com uma cadeia de caracteres.

*ch2*<br/>
Um caractere ANSI ou Unicode para concatenar com uma cadeia de caracteres.

*str1*<br/>
Uma `CStringT` para comparação.

*str2*<br/>
Uma `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Testa se uma cadeia de caracteres ou um caractere no lado esquerdo não é igual a uma cadeia de caracteres ou caractere no lado direito.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#143](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_27.cpp)]

##  <a name="operator_lt"></a>Operador CStringT:: Operator &lt;

Determina se a cadeia de caracteres no lado esquerdo do operador é menor que a cadeia de caracteres no lado direito.

```
friend bool operator<(const CStringT& str1, const CStringT& str2) throw();
friend bool operator<(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator<(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>parâmetros

*str1*<br/>
Uma `CStringT` para comparação.

*str2*<br/>
Uma `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Uma comparação de lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#144](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_28.cpp)]

##  <a name="operator_gt"></a>Operador CStringT:: Operator &gt;

Determina se a cadeia de caracteres no lado esquerdo do operador é maior que a cadeia de caracteres no lado direito.

```
friend bool operator>(const CStringT& str1, const CStringT& str2) throw();
friend bool operator>(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator>(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>parâmetros

*str1*<br/>
Uma `CStringT` para comparação.

*str2*<br/>
Uma `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Uma comparação de lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#145](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_29.cpp)]

##  <a name="operator_lt_eq"></a>CStringT:: Operator &lt;=

Determina se a cadeia de caracteres no lado esquerdo do operador é menor ou igual à cadeia de caracteres no lado direito.

```
friend bool operator<=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator<=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator<=(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>parâmetros

*str1*<br/>
Uma `CStringT` para comparação.

*str2*<br/>
Uma `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Uma comparação de lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#146](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_30.cpp)]

##  <a name="operator_gt_eq"></a>CStringT:: Operator &gt;=

Determina se a cadeia de caracteres no lado esquerdo do operador é maior ou igual à cadeia de caracteres no lado direito.

```
friend bool operator>=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator>=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator>=(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>parâmetros

*str1*<br/>
Uma `CStringT` para comparação.

*str2*<br/>
Uma `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres para comparação.

### <a name="remarks"></a>Comentários

Uma comparação de lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#147](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_31.cpp)]

##  <a name="remove"></a>CStringT:: Remove

Remove todas as instâncias do caractere especificado da cadeia de caracteres.

```
int Remove(XCHAR chRemove);
```

### <a name="parameters"></a>parâmetros

*chRemove*<br/>
O caractere a ser removido de uma cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

A contagem de caracteres removidos da cadeia de caracteres. Zero se a cadeia de caracteres não for alterada.

### <a name="remarks"></a>Comentários

As comparações do caractere diferenciam maiúsculas de minúsculas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#129](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_32.cpp)]

##  <a name="replace"></a>CStringT:: Replace

Há duas versões do `Replace`. A primeira versão substitui uma ou mais cópias de uma subcadeia de caracteres usando outra subcadeia de caracteres. Ambas as subcadeias são terminadas em nulo. A segunda versão substitui uma ou mais cópias de um caractere usando outro caractere. Ambas as versões operam nos dados de caracteres armazenados no `CStringT`.

```
int Replace(PCXSTR pszOld, PCXSTR pszNew);
int Replace(XCHAR chOld, XCHAR chNew);
```

### <a name="parameters"></a>parâmetros

*pszOld*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo a ser substituído por *pszNew*.

*pszNew*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que substitui *pszOld*.

*chOld*<br/>
O caractere a ser substituído por *chNew*.

*chNew*<br/>
O caractere que substitui *chOld*.

### <a name="return-value"></a>Valor retornado

Retorna o número de instâncias substituídas do caractere ou Subcadeia de caracteres, ou zero se a cadeia de caracteres não for alterada.

### <a name="remarks"></a>Comentários

`Replace` pode alterar o tamanho da cadeia de caracteres porque *pszNew* e *pszOld* não precisam ter o mesmo comprimento e várias cópias da subcadeia de caracteres antiga podem ser alteradas para a nova. A função executa uma correspondência que diferencia maiúsculas de minúsculas.

Exemplos de instâncias de `CStringT` são `CString`, `CStringA`e `CStringW`.

Por `CStringA`, o `Replace` funciona com caracteres ANSI ou multibyte (MBCS). Por `CStringW`, `Replace` funciona com caracteres largos.

Por `CString`, o tipo de dados de caractere é selecionado no momento da compilação, com base em se as constantes na tabela a seguir estão definidas.

|Constante definida|Tipo de dados character|
|----------------------|-------------------------|
|_UNICODE|Caracteres largos|
|_MBCS|Caracteres de byte múltiplo|
|Nenhum|Caracteres de byte único|
|Ambos|Indefinido|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#200](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_33.cpp)]

##  <a name="reversefind"></a>CStringT::ReverseFind

Pesquisa esse objeto `CStringT` para a última correspondência de um caractere.

```
int ReverseFind(XCHAR ch) const throw();
```

### <a name="parameters"></a>parâmetros

*CH*<br/>
O caractere a ser pesquisado.

### <a name="return-value"></a>Valor retornado

O índice de base zero do último caractere neste `CStringT` objeto que corresponde ao caractere solicitado, ou-1 se o caractere não for encontrado.

### <a name="remarks"></a>Comentários

A função é semelhante à função de tempo de execução `strrchr`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#130](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_34.cpp)]

##  <a name="right"></a>CStringT:: direita

Extrai os últimos (ou seja, os caracteres mais à direita) *nCount* do objeto `CStringT` e retorna uma cópia da subcadeia de caracteres extraída.

```
CStringT Right(int nCount) const;
```

### <a name="parameters"></a>parâmetros

*nCount*<br/>
O número de caracteres para extrair desse objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o objeto `CStringT` retornado pode estar vazio.

### <a name="remarks"></a>Comentários

Se *nCount* exceder o comprimento da cadeia de caracteres, a cadeia de caracteres inteira será extraída. `Right` é semelhante à função básica `Right` (exceto que os índices em básico são baseados em zero).

Para os conjuntos de caracteres multibyte (MBCS), *nCount* se refere a cada caractere de 8 bits; ou seja, um byte de Lead e trilha em um caractere multibyte são contados como dois caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#131](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_35.cpp)]

##  <a name="setsysstring"></a>CStringT::SetSysString

Realoca o BSTR apontado por *pbstr* e copia o conteúdo do objeto `CStringT` nele, incluindo o caractere nulo.

```
BSTR SetSysString(BSTR* pbstr) const;
```

### <a name="parameters"></a>parâmetros

*pbstr*<br/>
Um ponteiro para uma cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

A nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Dependendo do conteúdo do objeto `CStringT`, o valor do BSTR referenciado por *pbstr* pode ser alterado. A função gera um `CMemoryException` se houver memória insuficiente.

Essa função normalmente é usada para alterar o valor de cadeias de caracteres passadas por referência para automação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#132](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_36.cpp)]

##  <a name="spanexcluding"></a>CStringT::SpanExcluding

Extrai caracteres da cadeia de caracteres, começando com o primeiro caractere, que não estão no conjunto de caracteres identificado por *pszCharSet*.

```
CStringT SpanExcluding(PCXSTR pszCharSet) const;
```

### <a name="parameters"></a>parâmetros

*pszCharSet*<br/>
Uma cadeia de caracteres interpretada como um conjunto de caracteres.

### <a name="return-value"></a>Valor retornado

Uma Subcadeia que contém caracteres na cadeia de caracteres que não estão em *pszCharSet*, começando com o primeiro caractere na cadeia de caracteres e terminando com o primeiro caractere encontrado na cadeia de caracteres que também está em *pszCharSet* (ou seja, começando com o primeiro caractere na cadeia de caracteres e até, mas excluindo o primeiro caractere na cadeia de caracteres que é encontrada *pszCharSet*). Ele retornará a cadeia de caracteres inteira se nenhum caractere em *pszCharSet* for encontrado na cadeia de caracteres.

### <a name="remarks"></a>Comentários

`SpanExcluding` extrai e retorna todos os caracteres que antecedem a primeira ocorrência de um caractere de *pszCharSet* (em outras palavras, o caractere de *pszCharSet* e todos os caracteres que o seguem na cadeia de caracteres não são retornados). Se nenhum caractere de *pszCharSet* for encontrado na cadeia de caracteres, `SpanExcluding` retornará a cadeia de caracteres inteira.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#133](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_37.cpp)]

##  <a name="spanincluding"></a>CStringT::SpanIncluding

Extrai caracteres da cadeia de caracteres, começando com o primeiro caractere, que estão no conjunto de caracteres identificado por *pszCharSet*.

```
CStringT SpanIncluding(PCXSTR pszCharSet) const;
```

### <a name="parameters"></a>parâmetros

*pszCharSet*<br/>
Uma cadeia de caracteres interpretada como um conjunto de caracteres.

### <a name="return-value"></a>Valor retornado

Uma Subcadeia que contém caracteres na cadeia de caracteres que estão em *pszCharSet*, começando com o primeiro caractere na cadeia de caracteres e terminando quando um caractere é encontrado na cadeia de caracteres que não está em *pszCharSet*. `SpanIncluding` retornará uma subcadeia de caracteres vazia se o primeiro caractere na cadeia de caracteres não estiver no conjunto especificado.

### <a name="remarks"></a>Comentários

Se o primeiro caractere da cadeia de caracteres não estiver no conjunto de caracteres, `SpanIncluding` retornará uma cadeia de caracteres vazia. Caso contrário, ele retorna uma sequência de caracteres consecutivos que estão no conjunto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#134](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_38.cpp)]

##  <a name="tokenize"></a>CStringT:: Tokenize

Localiza o próximo token em uma cadeia de caracteres de destino

```
CStringT Tokenize(PCXSTR pszTokens, int& iStart) const;
```

### <a name="parameters"></a>parâmetros

*pszTokens*<br/>
Uma cadeia de caracteres que contém delimitadores de token. A ordem desses delimitadores não é importante.

*isniciar*<br/>
O índice de base zero para iniciar a pesquisa.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém o valor do token atual.

### <a name="remarks"></a>Comentários

A função `Tokenize` localiza o próximo token na cadeia de caracteres de destino. O conjunto de caracteres em *pszTokens* Especifica possíveis delimitadores do token a ser encontrado. Em cada chamada para `Tokenize` a função começa em *isniciar*, ignora os delimitadores à esquerda e retorna um objeto `CStringT` contendo o token atual, que é a cadeia de caracteres até o próximo caractere delimitador. O valor de *isniciar* é atualizado para ser a posição após o caractere delimitador final ou-1 se o final da cadeia de caracteres foi atingido. Mais tokens podem ser divididos do restante da cadeia de caracteres de destino por uma série de chamadas para `Tokenize`, usando *isniciar* para controlar onde na cadeia de caracteres o próximo token será lido. Quando não houver mais tokens, a função retornará uma cadeia de caracteres vazia e *isniciar* será definido como-1.

Ao contrário das funções de token do CRT [, como strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s,](../../c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l.md)_mbstok_s_l, `Tokenize` não modifica a cadeia de caracteres de destino.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#135](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_39.cpp)]

### <a name="remarks"></a>Comentários

A saída deste exemplo é a seguinte:

```Output
Resulting Token: First
Resulting Token: Second
Resulting Token: Third
```

##  <a name="trim"></a>CStringT:: Trim

Corta os caracteres à esquerda e à direita da cadeia de caracteres.

```
CStringT& Trim(XCHAR chTarget);
CStringT& Trim(PCXSTR pszTargets);
CStringT& Trim();
```

### <a name="parameters"></a>parâmetros

*chTarget*<br/>
O caractere de destino a ser cortado.

*pszTargets*<br/>
Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todas as ocorrências à esquerda e à direita de caracteres em *pszTarget* serão aparadas do objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

Retorna a cadeia de caracteres cortada.

### <a name="remarks"></a>Comentários

Remove todas as ocorrências à esquerda e à direita de uma das seguintes opções:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na cadeia de caracteres especificada por *pszTargets*.

- Diferente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#136](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_40.cpp)]

### <a name="remarks"></a>Comentários

A saída deste exemplo é a seguinte:

```Output
Before: "******Soccer is best, but liquor is quicker!!!!!"
After : "Soccer is best, but liquor is quicker"
```

##  <a name="trimleft"></a>CStringT::TrimLeft

Corta os caracteres à esquerda da cadeia de caracteres.

```
CStringT& TrimLeft(XCHAR chTarget);
CStringT& TrimLeft(PCXSTR pszTargets);
CStringT& TrimLeft();
```

### <a name="parameters"></a>parâmetros

*chTarget*<br/>
O caractere de destino a ser cortado.

*pszTargets*<br/>
Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todas as principais ocorrências de caracteres em *pszTarget* serão aparadas do objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres cortada resultante.

### <a name="remarks"></a>Comentários

Remove todas as ocorrências à esquerda e à direita de uma das seguintes opções:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na cadeia de caracteres especificada por *pszTargets*.

- Diferente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#137](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_41.cpp)]

##  <a name="trimright"></a>CStringT:: TrimRight

Corta os caracteres à direita da cadeia de caracteres.

```
CStringT& TrimRight(XCHAR chTarget);
CStringT& TrimRight(PCXSTR pszTargets);
CStringT& TrimRight();
```

### <a name="parameters"></a>parâmetros

*chTarget*<br/>
O caractere de destino a ser cortado.

*pszTargets*<br/>
Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todas as ocorrências à direita de caracteres em *pszTarget* serão aparadas do objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

Retorna o objeto `CStringT` que contém a cadeia de caracteres cortada.

### <a name="remarks"></a>Comentários

Remove ocorrências à direita de um dos seguintes:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na cadeia de caracteres especificada por *pszTargets*.

- Diferente.

A versão `CStringT& TrimRight(XCHAR chTarget)` aceita um parâmetro de caractere e remove todas as cópias desse caractere do final de `CStringT` dados de cadeia de caracteres. Ele começa no final da cadeia de caracteres e funciona em direção à frente. Ele para quando encontra um caractere diferente ou quando `CSTringT` é executado sem dados de caractere.

A versão `CStringT& TrimRight(PCXSTR pszTargets)` aceita uma cadeia de caracteres terminada em nulo que contém todos os caracteres diferentes a serem pesquisados. Ele remove todas as cópias desses caracteres no objeto `CStringT`. Ele começa no final da cadeia de caracteres e funciona em direção à frente. Ele para quando encontra um caractere que não está na cadeia de caracteres de destino ou quando `CStringT` se esgotar os dados de caractere. Ele não tenta corresponder a cadeia de caracteres de destino inteira a uma subcadeia de caracteres no final de `CStringT`.

A versão `CStringT& TrimRight()` não requer parâmetros. Ele apara os caracteres de espaço em branco à direita do final da cadeia de caracteres de `CStringT`. Os caracteres de espaço em branco podem ser quebras de linha, espaços ou guias.

-

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#138](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_42.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)<br/>
[Classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)
