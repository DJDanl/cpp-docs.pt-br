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
ms.openlocfilehash: 327ffc40a9b7e41004bc5aac7ecc320076de537f
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565812"
---
# <a name="cstringt-class"></a>Classe CStringT

Essa classe representa um `CStringT` objeto.

## <a name="syntax"></a>Sintaxe

```
template<typename BaseType, class StringTraits>
class CStringT :
    public CSimpleStringT<BaseType,
        _CSTRING_IMPL_::_MFCDLLTraitsCheck<BaseType, StringTraits>::c_bIsMFCDLLTraits>
```

#### <a name="parameters"></a>Parâmetros

*BaseType*<br/>
O tipo de caractere da classe string. Pode ser uma das seguintes opções:

- **char** (para cadeias de caracteres ANSI).

- **wchar_t** (para cadeias de caracteres Unicode).

- TCHAR (para cadeias de caracteres ANSI e Unicode).

*StringTraits*<br/>
Determina se a classe de cadeia de caracteres precisa de suporte de biblioteca de tempo de execução C (CRT) e onde os recursos de cadeia de caracteres estão localizados. Pode ser uma das seguintes opções:

- **StrTraitATL< wchar_t** &#124; **char** &#124; **TCHAR, ChTraitsCRT< wchar_t** &#124; **char** &#124; **TCHAR > >**

   A classe requer suporte de CRT e procura cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).

- **StrTraitATL< wchar_t** &#124; **char** &#124; **TCHAR, ChTraitsOS< wchar_t** &#124; **char** &#124; **TCHAR > >**

   A classe não requer suporte de CRT e procura cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).

- **StrTraitMFC< wchar_t** &#124; **char** &#124; **TCHAR, ChTraitsCRT< wchar_t** &#124; **char** &#124; **TCHAR > >**

   A classe requer suporte de CRT e procura cadeias de caracteres de recurso usando o algoritmo de pesquisa padrão do MFC.

- **StrTraitMFC< wchar_t** &#124; **char** &#124; **TCHAR, ChTraitsOS< wchar_t** &#124; **char** &#124; **TCHAR > >**

   A classe não requer suporte de CRT e procura cadeias de caracteres de recurso usando o algoritmo de pesquisa padrão do MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringT::CStringT](#cstringt)|Constrói um `CStringT` objeto de várias maneiras.|
|[CStringT::~CStringT](#_dtorcstringt)|Destrói um objeto `CStringT`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringT::AllocSysString](#allocsysstring)|Aloca um BSTR do `CStringT` dados.|
|[CStringT::AnsiToOem](#ansitooem)|Faz uma conversão in-loco do conjunto ao conjunto de caracteres OEM de caracteres ANSI.|
|[CStringT::AppendFormat](#appendformat)|Acrescenta dados formatados um existente `CStringT` objeto.|
|[CStringT::Collate](#collate)|Compara duas cadeias de caracteres (maiusculas e minúsculas, usa informações de específica de localidade).|
|[CStringT::CollateNoCase](#collatenocase)|Compara duas cadeias de caracteres (diferencia maiusculas de minúsculas, usa informações de específica de localidade).|
|[CStringT::Compare](#compare)|Compara duas cadeias de caracteres (diferencia maiusculas de minúsculas).|
|[CStringT::CompareNoCase](#comparenocase)|Compara duas cadeias de caracteres (diferencia maiusculas de minúsculas).|
|[CStringT::Delete](#delete)|Exclui um ou mais caracteres de uma cadeia de caracteres.|
|[CStringT::Find](#find)|Localiza um caractere ou uma subcadeia de caracteres dentro de uma cadeia de caracteres maior.|
|[CStringT::FindOneOf](#findoneof)|Localiza o primeiro caractere correspondente de um conjunto.|
|[CStringT::Format](#format)|Formata a cadeia de caracteres como `sprintf` faz.|
|[CStringT::FormatMessage](#formatmessage)|Formata uma cadeia de caracteres de mensagem.|
|[CStringT::FormatMessageV](#formatmessagev)|Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variável.|
|[CStringT::FormatV](#formatv)|Formata a cadeia de caracteres usando uma lista de argumentos de variável.|
|[CStringT::GetEnvironmentVariable](#getenvironmentvariable)|Define a cadeia de caracteres para o valor da variável de ambiente especificado.|
|[CStringT::Insert](#insert)|Insere um único caractere ou uma subcadeia de caracteres no índice especificado na cadeia de caracteres.|
|[CStringT::Left](#left)|Extrai a parte esquerda de uma cadeia de caracteres.|
|[CStringT::LoadString](#loadstring)|Carrega um existente `CStringT` objeto a partir de um recurso do Windows.|
|[CStringT::MakeLower](#makelower)|Converte todos os caracteres na cadeia de caracteres para caracteres minúsculos.|
|[CStringT::MakeReverse](#makereverse)|Inverte a cadeia de caracteres.|
|[CStringT::MakeUpper](#makeupper)|Converte todos os caracteres na cadeia de caracteres para caracteres maiusculos.|
|[CStringT::Mid](#mid)|Extrai a parte do meio de uma cadeia de caracteres.|
|[CStringT::OemToAnsi](#oemtoansi)|Faz uma conversão in-loco, o OEM do conjunto de caracteres para o conjunto de caracteres ANSI.|
|[CStringT::Remove](#remove)|Remove indicado caracteres de uma cadeia de caracteres.|
|[CStringT::Replace](#replace)|Substitui o indicado caracteres com outros caracteres.|
|[CStringT::ReverseFind](#reversefind)|Localiza um caractere dentro de uma cadeia de caracteres maior; partir do final.|
|[CStringT::Right](#right)|Extrai a parte direita de uma cadeia de caracteres.|
|[CStringT::SetSysString](#setsysstring)|Define um objeto BSTR existente com os dados de um `CStringT` objeto.|
|[CStringT::SpanExcluding](#spanexcluding)|Extrai caracteres de cadeia de caracteres, começando com o primeiro caractere que não estão no conjunto de caracteres identificada pelo `pszCharSet`.|
|[CStringT::SpanIncluding](#spanincluding)|Extrai uma subcadeia de caracteres que contém somente os caracteres em um conjunto.|
|[CStringT::Tokenize](#tokenize)|Extrai especificado tokens em uma cadeia de caracteres de destino.|
|[CStringT::Trim](#trim)|Remove todos os caracteres de espaço em branco à esquerda e à direita da cadeia de caracteres.|
|[CStringT::TrimLeft](#trimleft)|Corta os caracteres de espaço em branco à esquerda da cadeia de caracteres.|
|[CStringT::TrimRight](#trimright)|Corta os caracteres de espaço em branco da cadeia de caracteres à direita.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[CStringT::operator =](#operator_eq)|Atribui um novo valor para um `CStringT` objeto.|
|[CStringT::operator +](#operator_add)|Concatena duas cadeias de caracteres ou um caractere e uma cadeia de caracteres.|
|[+ CStringT::operator =](#operator_add_eq)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|
|[CStringT::operator ==](#operator_eq_eq)|Determina se duas cadeias de caracteres são logicamente iguais.|
|[CStringT::operator! =](#operator_neq)|Determina se duas cadeias de caracteres logicamente não são iguais.|
|[CStringT::operator &lt;](#operator_lt)|Determina se a cadeia de caracteres no lado esquerdo do operador é menor que a cadeia de caracteres à direita.|
|[CStringT::operator &gt;](#operator_gt)|Determina se a cadeia de caracteres no lado esquerdo do operador for maior que a cadeia de caracteres à direita.|
|[CStringT::operator &lt;=](#operator_lt_eq)|Determina se a cadeia de caracteres no lado esquerdo do operador é menor ou igual à cadeia de caracteres à direita.|
|[CStringT::operator &gt;=](#operator_gt_eq)|Determina se a cadeia de caracteres no lado esquerdo do operador é maior que ou igual à cadeia de caracteres à direita.|

## <a name="remarks"></a>Comentários

`CStringT` herda de [classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md). Recursos avançados, como a manipulação de caracteres, ordenação e a pesquisa, são implementados por `CStringT`.

> [!NOTE]
> `CStringT` os objetos são capazes de lançar exceções. Isso ocorre quando um `CStringT` objeto é executado sem memória por qualquer motivo.

Um `CStringT` objeto consiste em uma sequência de caracteres de comprimento variável. `CStringT` fornece funções e operadores usando uma sintaxe semelhante do Basic. Concatenação e operadores de comparação, junto com o gerenciamento simplificado de memória, tornam `CStringT` objetos mais fáceis de usar que matrizes de caractere comum.

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm incorporado caracteres nulos, é recomendável. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados não intencionais.

Usando combinações diferentes do `BaseType` e `StringTraits` parâmetros, `CStringT` objetos podem são fornecidos nos seguintes tipos, que são predefinidos pelas bibliotecas de ATL.

Se estiver usando em um aplicativo ATL:

`CString`, `CStringA`, e `CStringW` são exportadas da DLL da MFC (MFC90. DLL), nunca de DLLs do usuário. Isso é feito para evitar `CStringT` do que está sendo definido várias vezes.

> [!NOTE]
>  Se seu código contém a solução alternativa para erros de vinculador que é descrito em [exportando Classes do cadeia de caracteres usando CStringT](../../atl-mfc-shared/exporting-string-classes-using-cstringt.md), você deve remover esse código. Ele não é mais necessário.

Os seguintes tipos de cadeia de caracteres estão disponíveis em aplicativos MFC:

|Tipo de CStringT|Declaração|
|-------------------|-----------------|
|`CStringA`|Um caractere ANSI de tipo cadeia de caracteres com suporte de CRT.|
|`CStringW`|Um caractere Unicode de tipo cadeia de caracteres com suporte de CRT.|
|`CString`|Tipos de caracteres ANSI e Unicode com suporte de CRT.|

Os seguintes tipos de cadeia de caracteres estão disponíveis em projetos onde ATL_CSTRING_NO_CRT é definido:

|Tipo de CStringT|Declaração|
|-------------------|-----------------|
|`CAtlStringA`|Um caractere ANSI de tipo cadeia de caracteres sem suporte para CRT.|
|`CAtlStringW`|Um caractere Unicode de tipo cadeia de caracteres sem suporte para CRT.|
|`CAtlString`|Tipos de caracteres ANSI e Unicode sem suporte para CRT.|

Os seguintes tipos de cadeia de caracteres estão disponíveis em projetos onde ATL_CSTRING_NO_CRT não está definido:

|Tipo de CStringT|Declaração|
|-------------------|-----------------|
|`CAtlStringA`|Um caractere ANSI de tipo cadeia de caracteres com suporte de CRT.|
|`CAtlStringW`|Um caractere Unicode de tipo cadeia de caracteres com suporte de CRT.|
|`CAtlString`|Tipos de caracteres ANSI e Unicode com suporte de CRT.|

`CString` objetos também têm as seguintes características:

- `CStringT` objetos podem aumentar como resultado de operações de concatenação.

- `CStringT` objetos seguem "semântica de valor". Pense em um `CStringT` objeto como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.

- Você pode substituir livremente `CStringT` objetos para `PCXSTR` os argumentos de função.

- Gerenciamento de memória personalizado para os buffers de cadeia de caracteres. Para obter mais informações, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="cstringt-predefined-types"></a>Tipos predefinidos de CStringT

Porque `CStringT` usa um argumento de modelo para definir o tipo de caractere (ambos [wchar_t](../../c-runtime-library/standard-types.md) ou [char](../../c-runtime-library/standard-types.md)) com suporte, os tipos de parâmetro de método podem ser complicados às vezes. Para simplificar esse problema, um conjunto de tipos predefinidos é definido e usado em todo o `CStringT` classe. A tabela a seguir lista os vários tipos:

|Nome|Descrição|
|----------|-----------------|
|`XCHAR`|Um único caractere (qualquer um dos **wchar_t** ou **char**) com o mesmo tipo de caractere como o `CStringT` objeto.|
|`YCHAR`|Um único caractere (qualquer um dos **wchar_t** ou **char**) com o tipo de caractere oposta, como o `CStringT` objeto.|
|`PXSTR`|Um ponteiro para uma cadeia de caracteres (qualquer um dos **wchar_t** ou **char**) com o mesmo tipo de caractere como o `CStringT` objeto.|
|`PYSTR`|Um ponteiro para uma cadeia de caracteres (qualquer um dos **wchar_t** ou **char**) com o tipo de caractere oposta, como o `CStringT` objeto.|
|`PCXSTR`|Um ponteiro para um **const** cadeia de caracteres (ambos **wchar_t** ou **char**) com o mesmo tipo de caractere como o `CStringT` objeto.|
|`PCYSTR`|Um ponteiro para um **const** cadeia de caracteres (ambos **wchar_t** ou **char**) com o tipo de caractere oposta, como o `CStringT` objeto.|

> [!NOTE]
>  Código que usava não documentados métodos de `CString` (como `AssignCopy`) deve ser substituído pelo código que usa os seguintes métodos documentados da `CStringT` (como `GetBuffer` ou `ReleaseBuffer`). Esses métodos são herdados de `CSimpleStringT`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)

`CStringT`

## <a name="requirements"></a>Requisitos

|Cabeçalho|Use para|
|------------|-------------|
|cstringt.h|Objetos de cadeia de caracteres somente do MFC|
|atlstr.h|Objetos de cadeia de caracteres não MFC|

##  <a name="allocsysstring"></a>  CStringT::AllocSysString

Aloca uma cadeia de caracteres compatíveis com a automação do tipo BSTR e copia o conteúdo do `CStringT` objeto nele, incluindo o caractere nulo de terminação.

```
BSTR AllocSysString() const;
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres recém-alocada.

### <a name="remarks"></a>Comentários

Em programas MFC, uma [classe CMemoryException](../../mfc/reference/cmemoryexception-class.md) é lançada se houver memória insuficiente. Em programas ATL, uma [CAtlException](../../atl/reference/catlexception-class.md) é gerada. Essa função normalmente é usada para retornar cadeias de caracteres para a automação.

Normalmente, se essa cadeia de caracteres for passada para uma função COM como [in] parâmetro, em seguida, isso requer que o chamador liberar a cadeia de caracteres. Isso pode ser feito por meio [SysFreeString](/windows/desktop/api/oleauto/nf-oleauto-sysfreestring), conforme descrito no SDK do Windows. Para obter mais informações, consulte [alocando e liberando memória para um BSTR](../../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md).

Para obter mais informações sobre as funções de alocação OLE no Windows, consulte [SysAllocString](/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CStringT::AllocSysString`.

[!code-cpp[NVC_ATLMFC_Utilities#105](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_1.cpp)]

##  <a name="ansitooem"></a>  CStringT::AnsiToOem

Converte todos os caracteres nesse `CStringT` objeto do conjunto ao conjunto de caracteres OEM de caracteres ANSI.

```
void AnsiToOem();
```

### <a name="remarks"></a>Comentários

A função não estará disponível se Unicode estiver definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#106](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_2.cpp)]

##  <a name="appendformat"></a>  CStringT::AppendFormat

Acrescenta dados formatados um existente `CStringT` objeto.

```
void __cdecl AppendFormat(PCXSTR pszFormat, [, argument] ...);
void __cdecl AppendFormat(UINT nFormatID, [, argument] ...);
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
Uma cadeia de caracteres de controle de formato.

*nFormatID*<br/>
O identificador de recurso de cadeia de caracteres que contém a cadeia de caracteres de controle de formato.

*argument*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

Essa função formata e acrescenta uma série de caracteres e valores no `CStringT`. Cada argumento opcional (se houver) é convertido e acrescentado de acordo com a especificação de formato correspondente em *pszFormat* ou do recurso da cadeia de caracteres identificada pelo *nFormatID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#107](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_3.cpp)]

##  <a name="collate"></a>  CStringT::Collate

Compara duas cadeias de caracteres usando a função de texto genérico `_tcscoll`.

```
int Collate(PCXSTR psz) const throw();
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas, < 0, se este `CStringT` objeto é menor que *psz*, ou > 0, se este `CStringT` objeto é maior que *psz*.

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcscoll`, que é definido em TCHAR. H, é mapeado para um `strcoll`, `wcscoll`, ou `_mbscoll`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação diferencia maiusculas de minúsculas das cadeias de caracteres de acordo com a página de código atualmente em uso. Para obter mais informações, consulte [strcoll, wcscoll, mbscoll, strcoll_l, wcscoll_l, _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).

##  <a name="collatenocase"></a>  CStringT::CollateNoCase

Compara duas cadeias de caracteres usando a função de texto genérico `_tcscoll`.

```
int CollateNoCase(PCXSTR psz) const throw();
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas (ignora maiusculas/minúsculas), < 0, se este `CStringT` objeto é menor que *psz* (ignorando maiusculas e minúsculas), ou > 0, se este `CStringT` objeto é maior que *psz* (ignorando maiusculas e minúsculas).

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcscoll`, que é definido em TCHAR. H, é mapeado para um `stricoll`, `wcsicoll`, ou `_mbsicoll`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação diferencia maiusculas de minúsculas das cadeias de caracteres, acordo com a página de código atualmente em uso. Para obter mais informações, consulte [strcoll, wcscoll, mbscoll, strcoll_l, wcscoll_l, _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#109](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_4.cpp)]

##  <a name="compare"></a>  CStringT::Compare

Compara duas cadeias de caracteres (diferencia maiusculas de minúsculas).

```
int Compare(PCXSTR psz) const;
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas, < 0, se este `CStringT` objeto é menor que *psz*, ou > 0, se este `CStringT` objeto é maior que *psz*.

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcscmp`, que é definido em TCHAR. H, é mapeado para um `strcmp`, `wcscmp`, ou `_mbscmp`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação diferencia maiusculas de minúsculas das cadeias de caracteres e não é afetada pela localidade. Para obter mais informações, consulte [strcmp wcscmp, mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md).

Se a cadeia de caracteres contém nulos incorporados, para fins de comparação, a cadeia de caracteres é considerada ser truncado no primeiro caractere nulo inserido.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CStringT::Compare`.

[!code-cpp[NVC_ATLMFC_Utilities#110](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_5.cpp)]

##  <a name="comparenocase"></a>  CStringT::CompareNoCase

Compara duas cadeias de caracteres (diferencia maiusculas de minúsculas).

```
int CompareNoCase(PCXSTR psz) const throw();
```

### <a name="parameters"></a>Parâmetros

*psz*<br/>
A outra cadeia de caracteres usada para comparação.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas (ignorando maiusculas e minúsculas), < 0 se isso `CStringT` objeto é menor que *psz* (ignorando maiusculas e minúsculas), ou > 0 se isso `CStringT` objeto é maior que *psz* (ignorando maiusculas e minúsculas).

### <a name="remarks"></a>Comentários

A função de texto genérico `_tcsicmp`, que é definido em TCHAR. H, é mapeado para um `_stricmp`, `_wcsicmp` ou `_mbsicmp`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação diferencia maiusculas de minúsculas das cadeias de caracteres. A comparação depende o aspecto LC_CTYPE da localidade mas não LC_COLLATE. Para obter mais informações, consulte [stricmp, wcsicmp, mbsicmp, stricmp_l, wcsicmp_l, mbsicmp_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#111](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_6.cpp)]

##  <a name="cstringt"></a>  CStringT::CStringT

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

### <a name="parameters"></a>Parâmetros

*pch*<br/>
Um ponteiro para uma matriz de caracteres de comprimento *nLength*, não terminada em nulo.

*nLength*<br/>
Uma contagem do número de caracteres em *pch*.

*ch*<br/>
Um único caractere.

*pszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiado para isso `CStringT` objeto.

*pStringMgr*<br/>
Um ponteiro para o Gerenciador de memória para o `CStringT` objeto. Para obter mais informações sobre `IAtlStringMgr` e o gerenciamento de memória para `CStringT`, consulte [gerenciamento de memória com CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

*strSrc*<br/>
Um existente `CStringT` o objeto a ser copiado para isso `CStringT` objeto. Para obter mais informações sobre `CThisString` e `CThisSimpleString`, consulte a seção comentários.

*varSrc*<br/>
Um objeto variante a ser copiado para isso `CStringT` objeto.

*BaseType*<br/>
O tipo de caractere da classe string. Pode ser uma das seguintes opções:

**char** (para cadeias de caracteres ANSI).

**wchar_t** (para cadeias de caracteres Unicode).

TCHAR (para cadeias de caracteres ANSI e Unicode).

*bMFCDLL*<br/>
Valor booleano que especifica se o projeto é uma DLL do MFC (TRUE) ou não (FALSE).

*SystemString*<br/>
Deve ser `System::String`, e o projeto deve ser compilado com /clr.

*pString*<br/>
Um identificador para um `CStringT` objeto.

### <a name="remarks"></a>Comentários

Como os construtores copiam os dados de entrada para o novo armazenamento alocado, você deve estar ciente de que as exceções podem resultar de memória. Observe que alguns desses construtores atuam como funções de conversão. Isso permite que você substitua, por exemplo, um LPTSTR onde um `CStringT` objeto é esperado.

- `CStringT`( `LPCSTR` `lpsz` ): Constrói um Unicode `CStringT` de uma cadeia de caracteres ANSI. Você também pode usar esse construtor para carregar um recurso de cadeia de caracteres, conforme mostrado no exemplo a seguir.

- `CStringT(` `LPCWSTR` `lpsz` ): Constrói um `CStringT` de uma cadeia de caracteres Unicode.

- `CStringT`( `const unsigned char*` `psz` ): Permite que você construa uma `CStringT` de um ponteiro **unsigned char**.

> [!NOTE]
>  Defina a macro _CSTRING_DISABLE_NARROW_WIDE_CONVERSION para desativar a conversão implícita de cadeia de caracteres entre cadeias de caracteres ANSI e Unicode. A macro exclui os construtores de compilação que oferecem suporte à conversão.

Observe que o *{1&gt;strsrc* parâmetro pode ser um `CStringT` ou `CThisSimpleString` objeto. Para `CStringT`, use uma das suas instanciações de padrão (`CString`, `CStringA`, ou `CStringW`); para `CThisSimpleString`, use um **isso** ponteiro. `CThisSimpleString` declara uma instância do [classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), que é uma classe de cadeia de caracteres menor com funcionalidade interna menor do que o `CStringT` classe.

O operador de sobrecarga `CSimpleStringT<>&()` constrói uma `CStringT` do objeto de um `CSimpleStringT` declaração.

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm incorporado caracteres nulos, é recomendável. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados não intencionais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#112](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_7.cpp)]

##  <a name="_dtorcstringt"></a>  CStringT::~CStringT

Destrói o `CStringT` objeto.

```
~CStringT() throw();
```

### <a name="remarks"></a>Comentários

Destrói o `CStringT` objeto.

##  <a name="delete"></a>  CStringT::Delete

Exclui um ou mais caracteres de uma cadeia de caracteres começando com o caractere no índice especificado.

```
int Delete(int iIndex, int nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
O índice baseado em zero do primeiro caractere no `CStringT` objeto a ser excluído.

*nCount*<br/>
O número de caracteres a ser removido.

### <a name="return-value"></a>Valor de retorno

O comprimento da cadeia de caracteres alterada.

### <a name="remarks"></a>Comentários

Se *nCount* é maior do que a cadeia de caracteres, o restante da cadeia de caracteres será removida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#113](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_8.cpp)]

```Output
Before: Soccer is best,
    but hockey is quicker!
After: Soccer best,
    but hockey is quicker!
```

##  <a name="find"></a>  CStringT::Find

Procura essa cadeia de caracteres para a primeira correspondência de um caractere ou subcadeia de caracteres.

```
int Find(PCXSTR pszSub, int iStart=0) const throw();
int Find(XCHAR ch, int iStart=0) const throw();
```

### <a name="parameters"></a>Parâmetros

*pszSub*<br/>
Uma subcadeia de caracteres a ser pesquisado.

*iStart*<br/>
O índice do caractere na cadeia de caracteres para iniciar a pesquisa com, ou 0 para começar do zero.

*ch*<br/>
Um único caractere a ser pesquisado.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do primeiro caractere desta `CStringT` objeto que corresponde a subcadeia de caracteres solicitada ou caracteres; -1 se o caractere ou subcadeia de caracteres não for encontrado.

### <a name="remarks"></a>Comentários

A função está sobrecarregada para aceitar os dois caracteres únicos (semelhante à função tempo de execução `strchr`) e cadeias de caracteres (semelhante a `strstr`).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#114](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_9.cpp)]

##  <a name="findoneof"></a>  CStringT::FindOneOf

Procura essa cadeia de caracteres para o primeiro caractere que corresponde a qualquer caractere contido em *pszCharSet*.

```
int FindOneOf(PCXSTR pszCharSet) const throw();
```

### <a name="parameters"></a>Parâmetros

*pszCharSet*<br/>
Cadeia de caracteres que contém os caracteres para correspondência.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do primeiro caractere na cadeia de caracteres que também está na *pszCharSet*; -1 se não houver nenhuma correspondência.

### <a name="remarks"></a>Comentários

Localiza a primeira ocorrência de qualquer um dos caracteres na *pszCharSet*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#115](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_10.cpp)]

##  <a name="format"></a>  CStringT::Format

Grava dados formatados em uma `CStringT` da mesma forma que [sprintf_s](../../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md) formata dados em uma matriz de caracteres de estilo C.

```
void __cdecl Format(UINT nFormatID, [, argument]...);
void __cdecl Format(PCXSTR pszFormat,  [, argument] ...);
```

### <a name="parameters"></a>Parâmetros

*nFormatID*<br/>
O identificador de recurso de cadeia de caracteres que contém a cadeia de caracteres de controle de formato.

*pszFormat*<br/>
Uma cadeia de caracteres de controle de formato.

*argument*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

Essa função formata e armazena uma série de caracteres e valores no `CStringT`. Cada argumento opcional (se houver) é convertido e gerado de acordo com a especificação de formato correspondente em *pszFormat* ou do recurso da cadeia de caracteres identificada pelo *nFormatID*.

A chamada falhará se o próprio objeto de cadeia de caracteres é oferecido como um parâmetro para `Format`. Por exemplo, o código a seguir causará resultados imprevisíveis:

[!code-cpp[NVC_ATLMFC_Utilities#116](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_11.cpp)]

Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#117](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_12.cpp)]

##  <a name="formatmessage"></a>  CStringT::FormatMessage

Formata uma cadeia de caracteres de mensagem.

```
void __cdecl FormatMessage(UINT nFormatID, [, argument]...);
void __cdecl FormatMessage(PCXSTR pszFormat, [, argument]...);
```

### <a name="parameters"></a>Parâmetros

*nFormatID*<br/>
O identificador de recurso de cadeia de caracteres que contém o texto não formatado.

*pszFormat*<br/>
Aponta para a cadeia de caracteres de controle de formato. Ele será examinado em busca de inserções e formatado adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução *printf*-estilo de cadeias de caracteres de formato, exceto que ele permite que os parâmetros a serem inseridos em uma ordem arbitrária.

*argument*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

A função requer uma definição de mensagem como entrada. A definição de mensagem é determinada pela *pszFormat* ou do recurso da cadeia de caracteres identificada pelo *nFormatID*. A função copia o texto da mensagem formatada para o `CStringT` objeto, processamento de um inserido insere sequências, se solicitado.

> [!NOTE]
> `FormatMessage` tenta alocar memória do sistema para a cadeia de caracteres formatada recentemente. Se essa tentativa falhar, uma exceção de memória é gerada automaticamente.

Cada inserção deve ter um parâmetro posterior correspondente a *pszFormat* ou *nFormatID* parâmetro. Dentro do texto da mensagem, várias sequências de escape têm suporte para formatação dinâmica a mensagem. Para obter mais informações, consulte o Windows [FormatMessage](/windows/desktop/api/winbase/nf-winbase-formatmessage) função no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#118](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_13.cpp)]

##  <a name="formatmessagev"></a>  CStringT::FormatMessageV

Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variável.

```
void FormatMessageV(PCXSTR pszFormat, va_list* pArgList);
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
Aponta para a cadeia de caracteres de controle de formato. Ele será examinado em busca de inserções e formatado adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`-estilo de cadeias de caracteres de formato, exceto que ele permite que os parâmetros a serem inseridos em uma ordem arbitrária.

*pArgList*<br/>
Ponteiro para uma lista de argumentos.

### <a name="remarks"></a>Comentários

A função requer uma definição de mensagem como entrada, determinado pelo *pszFormat*. A função copia o texto da mensagem formatada e uma lista de variável de argumentos para o `CStringT` objeto, processamento de um inserido insere sequências, se solicitado.

> [!NOTE]
> `FormatMessageV` chamadas [CStringT::FormatMessage](#formatmessage), que tenta alocar memória do sistema para a cadeia de caracteres formatada recentemente. Se essa tentativa falhar, uma exceção de memória é gerada automaticamente.

Para obter mais informações, consulte o Windows [FormatMessage](/windows/desktop/api/winbase/nf-winbase-formatmessage) função no SDK do Windows.

##  <a name="formatv"></a>  CStringT::FormatV

Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variável.

```
void FormatV(PCXSTR pszFormat, va_list args);
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
Aponta para a cadeia de caracteres de controle de formato. Ele será examinado em busca de inserções e formatado adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`-estilo de cadeias de caracteres de formato, exceto que ele permite que os parâmetros a serem inseridos em uma ordem arbitrária.

*args*<br/>
Ponteiro para uma lista de argumentos.

### <a name="remarks"></a>Comentários

Grava uma cadeia de caracteres formatada e uma lista de variável de argumentos para um `CStringT` cadeia de caracteres da mesma forma que `vsprintf_s` formata dados em uma matriz de caracteres de estilo C.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#119](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_14.cpp)]

[!code-cpp[NVC_ATLMFC_Utilities#120](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_15.cpp)]

##  <a name="getenvironmentvariable"></a>  CStringT::GetEnvironmentVariable

Define a cadeia de caracteres para o valor da variável de ambiente especificado.

```
BOOL GetEnvironmentVariable(PCXSTR pszVar);
```

### <a name="parameters"></a>Parâmetros

*pszVar*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a variável de ambiente.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Recupera o valor da variável especificada do bloco de ambiente do processo de chamada. O valor é na forma de uma cadeia de caracteres terminada em nulo de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#121](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_16.cpp)]

##  <a name="insert"></a>  CStringT::Insert

Insere um único caractere ou uma subcadeia de caracteres no índice especificado na cadeia de caracteres.

```
int Insert(int iIndex, PCXSTR psz);
int Insert(int iIndex, XCHAR ch);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
O índice do caractere antes do qual será realizada a inserção.

*psz*<br/>
Um ponteiro para a subcadeia de caracteres a ser inserido.

*ch*<br/>
O caractere a ser inserido.

### <a name="return-value"></a>Valor de retorno

O comprimento da cadeia de caracteres alterada.

### <a name="remarks"></a>Comentários

O *iIndex* parâmetro identifica o primeiro caractere que será movido para liberar espaço para o caractere ou subcadeia de caracteres. Se *nIndex* for zero, a inserção ocorrerá antes de cadeia de caracteres inteira. Se *nIndex* for maior do que o comprimento da cadeia de caracteres, a função irá concatenar a cadeia de caracteres presente e o novo material fornecido pelo *ch* ou *psz*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#122](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_17.cpp)]

##  <a name="left"></a>  CStringT::Left

Extrai o mais à esquerda *nCount* caracteres deste `CStringT` de objeto e retorna uma cópia da subcadeia de caracteres extraída.

```
CStringT Left(int nCount) const;
```

### <a name="parameters"></a>Parâmetros

*nCount*<br/>
O número de caracteres para extrair desse objeto `CStringT`.

### <a name="return-value"></a>Valor de retorno

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. O objeto `CStringT` retornado pode estar vazio.

### <a name="remarks"></a>Comentários

Se *nCount* excede o comprimento da cadeia de caracteres e, em seguida, a cadeia de caracteres inteira é extraída. `Left` é semelhante à função `Left` básica.

Conjuntos de caracteres multibyte (MBCS), *nCount* trata cada sequência de 8 bits como um caractere, de modo que *nCount* retorna o número de caracteres de vários bytes multiplicados por dois.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#123](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_18.cpp)]

##  <a name="loadstring"></a>  CStringT::LoadString

Lê um recurso de cadeia de caracteres do Windows, identificado por *nID*, em um existente `CStringT` objeto.

```
BOOL LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID);
BOOL LoadString(HINSTANCE hInstance, UINT nID);
BOOL LoadString(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
Um identificador para a instância do módulo.

*nID*<br/>
Uma ID de recurso de cadeia de caracteres de Windows.

*wLanguageID*<br/>
O idioma do recurso de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a carga de recursos foi bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Carrega o recurso de cadeia de caracteres (*nID*) do módulo especificado (*hInstance*) usando o idioma especificado (*wLanguage*).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#124](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_19.cpp)]

##  <a name="makelower"></a>  CStringT::MakeLower

Converte o `CStringT` objeto a ser uma cadeia de caracteres em minúsculas.

```
CStringT& MakeLower();
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres em minúsculas resultante.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#125](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_20.cpp)]

##  <a name="makereverse"></a>  CStringT::MakeReverse

Inverte a ordem dos caracteres no `CStringT` objeto.

```
CStringT& MakeReverse();
```

### <a name="return-value"></a>Valor de retorno

Resultante revertida a cadeia de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#126](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_21.cpp)]

##  <a name="makeupper"></a>  CStringT::MakeUpper

Converte o `CStringT` objeto a ser uma cadeia de caracteres em maiusculas.

```
CStringT& MakeUpper();
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres resultante em maiusculas.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#127](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_22.cpp)]

##  <a name="mid"></a>  CStringT::Mid

Extrai uma subcadeia de caracteres de comprimento *nCount* caracteres deste `CStringT` objeto, começando na posição *iFirst* (baseado em zero).

```
CStringT Mid(int iFirst, int nCount) const;
CStringT Mid(int iFirst) const;
```

### <a name="parameters"></a>Parâmetros

*iFirst*<br/>
O índice baseado em zero do primeiro caractere desta `CStringT` objeto a ser incluído na subcadeia de caracteres extraída.

*nCount*<br/>
O número de caracteres para extrair desse objeto `CStringT`. Se esse parâmetro não for fornecido, o restante da cadeia de caracteres é extraído.

### <a name="return-value"></a>Valor de retorno

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o retornado `CStringT` objeto pode estar vazio.

### <a name="remarks"></a>Comentários

A função retorna uma cópia da subcadeia de caracteres extraída. `Mid` é semelhante à função Mid básico (exceto que os índices em Basic são baseados em um).

Para conjuntos de caracteres multibyte (MBCS), *nCount* refere-se a cada byte de caractere; ou seja, um cliente potencial e trilha de 8 bits em um caractere multibyte são contados como dois caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#128](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_23.cpp)]

##  <a name="oemtoansi"></a>  CStringT::OemToAnsi

Converte todos os caracteres nesse `CStringT` objeto do conjunto ao conjunto de caracteres ANSI de caracteres OEM.

```
void OemToAnsi();
```

### <a name="remarks"></a>Comentários

Essa função não estará disponível se Unicode estiver definido.

### <a name="example"></a>Exemplo

Veja o exemplo de [CStringT::AnsiToOem](#ansitooem).

##  <a name="operator_eq"></a>  CStringT::operator =

Atribui um novo valor para a cadeia de caracteres.

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

### <a name="parameters"></a>Parâmetros

*strSrc*<br/>
Um `CStringT` para atribuir a essa cadeia de caracteres.

*str*<br/>
Uma referência a um objeto `CThisSimpleString`.

*bMFCDLL*<br/>
Um booliano que especifica se o projeto é uma DLL MFC ou não.

*BaseType*<br/>
O tipo de base de cadeia de caracteres.

*var*<br/>
Um objeto variante para atribuir a essa cadeia de caracteres.

*ch*<br/>
Um caractere para atribuir a cadeia de caracteres ANSI ou Unicode.

*pszSrc*<br/>
Um ponteiro para a cadeia de caracteres original que está sendo atribuído.

### <a name="remarks"></a>Comentários

O operador de atribuição aceita outro `CStringT` objeto, um ponteiro de caractere ou um único caractere. Você deve estar ciente que as exceções podem ocorrer sempre que você usa esse operador porque o novo armazenamento pode ser alocado a memória.

Para obter informações sobre `CThisSimpleString`, consulte a seção comentários da [CStringT::CStringT](#cstringt).

> [!NOTE]
> Embora seja possível criar `CStringT` instâncias que contêm incorporado caracteres nulos, é recomendável. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados não intencionais.

##  <a name="operator_add"></a>  CStringT::operator +

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

### <a name="parameters"></a>Parâmetros

*ch1*<br/>
Um caractere a ser concatenada com uma cadeia de caracteres ANSI ou Unicode.

*ch2*<br/>
Um caractere a ser concatenada com uma cadeia de caracteres ANSI ou Unicode.

*str1*<br/>
Um `CStringT` para concatenar com uma cadeia de caracteres ou um caractere.

*str2*<br/>
Um `CStringT` para concatenar com uma cadeia de caracteres ou um caractere.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para concatenar com uma cadeia de caracteres ou um caractere.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres a ser concatenada com uma cadeia de caracteres ou um caractere.

### <a name="remarks"></a>Comentários

Há sete formas de sobrecarga da `CStringT::operator+` função. A primeira versão concatena duas existente `CStringT` objetos. As próximas duas CONCATENAR um `CStringT` objeto e uma cadeia de caracteres terminada em nulo. As próximas duas CONCATENAR um `CStringT` objeto e um caractere ANSI. As duas últimas concatenar um `CStringT` objeto e um caractere Unicode.

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm incorporado caracteres nulos, é recomendável. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados não intencionais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#140](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_24.cpp)]

##  <a name="operator_add_eq"></a>  + CStringT::operator =

Concatena os caracteres até o final da cadeia de caracteres.

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

### <a name="parameters"></a>Parâmetros

*str*<br/>
Uma referência a um objeto `CThisSimpleString`.

*bMFCDLL*<br/>
Um booliano que especifica se o projeto é uma DLL MFC ou não.

*BaseType*<br/>
O tipo de base de cadeia de caracteres.

*var*<br/>
Um objeto variante de concatenar a essa cadeia de caracteres.

*ch*<br/>
Um caractere a ser concatenada com uma cadeia de caracteres ANSI ou Unicode.

*pszSrc*<br/>
Um ponteiro para a cadeia de caracteres original são concatenado.

*strSrc*<br/>
Um `CStringT` de concatenar a essa cadeia de caracteres.

### <a name="remarks"></a>Comentários

O operador aceita outro `CStringT` objeto, um ponteiro de caractere ou um único caractere. Você deve estar ciente que as exceções podem ocorrer sempre que você usa esse operador de concatenação, porque o novo armazenamento pode ser alocado para caracteres adicionados a esta a memória `CStringT` objeto.

Para obter informações sobre `CThisSimpleString`, consulte a seção comentários da [CStringT::CStringT](#cstringt).

> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm incorporado caracteres nulos, é recomendável. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados não intencionais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#141](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_25.cpp)]

##  <a name="operator_eq_eq"></a>  CStringT::operator = =

Determina se duas cadeias de caracteres são iguais logicamente.

```
friend bool operator==(const CStringT& str1, const CStringT& str2) throw();
friend bool operator==(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator==(const CStringT& str1, PCYSTR psz2) throw();
friend bool operator==(const CStringT& str1, XCHAR ch2) throw();
friend bool operator==(PCXSTR psz1, const CStringT& str2) throw();
friend bool operator==(PCYSTR psz1, const CStringT& str2,) throw();
friend bool operator==(XCHAR ch1, const CStringT& str2,) throw();
```

### <a name="parameters"></a>Parâmetros

*ch1*<br/>
Um caractere ANSI ou Unicode para comparação.

*ch2*<br/>
Um caractere ANSI ou Unicode para comparação.

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Testa se uma cadeia de caracteres ou um caractere à esquerda é igual a uma cadeia de caracteres ou um caractere à direita e retorna TRUE ou FALSE de acordo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#142](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_26.cpp)]

##  <a name="operator_neq"></a>  CStringT::operator! =

Determina se duas cadeias de caracteres logicamente não são iguais.

```
friend bool operator!=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator!=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator!=(const CStringT& str1, PCYSTR psz2) throw();
friend bool operator!=(const CStringT& str1, XCHAR ch2) throw();
friend bool operator!=(PCXSTR psz1, const CStringT& str2) throw();
friend bool operator!=(PCYSTR psz1, const CStringT& str2,) throw();
friend bool operator!=(XCHAR ch1, const CStringT& str2,) throw();
```

### <a name="parameters"></a>Parâmetros

*ch1*<br/>
Um caractere a ser concatenada com uma cadeia de caracteres ANSI ou Unicode.

*ch2*<br/>
Um caractere a ser concatenada com uma cadeia de caracteres ANSI ou Unicode.

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Testa se uma cadeia de caracteres ou um caractere à esquerda não é igual a uma cadeia de caracteres ou um caractere à direita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#143](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_27.cpp)]

##  <a name="operator_lt"></a>  CStringT::operator &lt;

Determina se a cadeia de caracteres no lado esquerdo do operador é menor que a cadeia de caracteres à direita.

```
friend bool operator<(const CStringT& str1, const CStringT& str2) throw();
friend bool operator<(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator<(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#144](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_28.cpp)]

##  <a name="operator_gt"></a>  CStringT::operator &gt;

Determina se a cadeia de caracteres no lado esquerdo do operador é maior que a cadeia de caracteres à direita.

```
friend bool operator>(const CStringT& str1, const CStringT& str2) throw();
friend bool operator>(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator>(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#145](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_29.cpp)]

##  <a name="operator_lt_eq"></a>  CStringT::operator &lt;=

Determina se a cadeia de caracteres no lado esquerdo do operador é menor ou igual à cadeia de caracteres à direita.

```
friend bool operator<=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator<=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator<=(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#146](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_30.cpp)]

##  <a name="operator_gt_eq"></a>  CStringT::operator &gt;=

Determina se a cadeia de caracteres no lado esquerdo do operador é maior que ou igual à cadeia de caracteres à direita.

```
friend bool operator>=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator>=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator>=(PCXSTR psz1, const CStringT& str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma cadeia de caracteres para comparação.

*psz2*<br/>
Um ponteiro para uma cadeia de caracteres para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#147](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_31.cpp)]

##  <a name="remove"></a>  CStringT::Remove

Remove todas as instâncias do caractere especificado da cadeia de caracteres.

```
int Remove(XCHAR chRemove);
```

### <a name="parameters"></a>Parâmetros

*chRemove*<br/>
O caractere a ser removido de uma cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

A contagem de caracteres é removida da cadeia de caracteres. Zero se a cadeia de caracteres não for alterada.

### <a name="remarks"></a>Comentários

As comparações do caractere diferenciam maiusculas de minúsculas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#129](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_32.cpp)]

##  <a name="replace"></a>  CStringT::Replace

Há duas versões de `Replace`. A primeira versão substitui um ou mais cópias de uma subcadeia de caracteres usando outra subcadeia de caracteres. Ambas as subcadeias de caracteres são terminada em nulo. A segunda versão substitui uma ou mais cópias de um caractere usando outro caractere. Ambas as versões operam nos dados de caracteres armazenados em `CStringT`.

```
int Replace(PCXSTR pszOld, PCXSTR pszNew);
int Replace(XCHAR chOld, XCHAR chNew);
```

### <a name="parameters"></a>Parâmetros

*pszOld*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo a ser substituído por *pszNew*.

*pszNew*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que substitui *pszOld*.

*chOld*<br/>
O caractere a ser substituído por *chNew*.

*chNew*<br/>
Substituindo o caractere *chOld*.

### <a name="return-value"></a>Valor de retorno

Retorna o número de instâncias substituídos o caractere ou subcadeia de caracteres ou zero se a cadeia de caracteres não for alterada.

### <a name="remarks"></a>Comentários

`Replace` pode alterar o comprimento da cadeia de caracteres porque *pszNew* e *pszOld* não é necessário ter o mesmo comprimento, e várias cópias da subcadeia de caracteres antiga podem ser alteradas para o novo. A função executa uma correspondência diferencia maiusculas de minúsculas.

Exemplos de `CStringT` são instâncias `CString`, `CStringA`, e `CStringW`.

Para `CStringA`, `Replace` funciona com o ANSI ou caracteres de multibyte (MBCS). Para `CStringW`, `Replace` funciona com caracteres largos.

Para `CString`, o tipo de dados de caractere é selecionado em tempo de compilação, com base em se as constantes na tabela a seguir são definidas.

|Constante definida|Tipo de dados de caractere|
|----------------------|-------------------------|
|_UNICODE|Caracteres largos|
|_MBCS|Caracteres multibyte|
|Nem|Caracteres de byte único|
|Ambos|Indefinido|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#200](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_33.cpp)]

##  <a name="reversefind"></a>  CStringT::ReverseFind

Pesquisa isso `CStringT` objeto para a última correspondência de um caractere.

```
int ReverseFind(XCHAR ch) const throw();
```

### <a name="parameters"></a>Parâmetros

*ch*<br/>
O caractere a ser pesquisado.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do último caractere nesse `CStringT` objeto que corresponde ao caractere solicitado ou -1, se o caractere não for encontrado.

### <a name="remarks"></a>Comentários

A função é semelhante à função tempo de execução `strrchr`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#130](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_34.cpp)]

##  <a name="right"></a>  CStringT::Right

Extrai o último (ou seja, mais à direita) *nCount* caracteres deste `CStringT` de objeto e retorna uma cópia da subcadeia de caracteres extraída.

```
CStringT Right(int nCount) const;
```

### <a name="parameters"></a>Parâmetros

*nCount*<br/>
O número de caracteres para extrair desse objeto `CStringT`.

### <a name="return-value"></a>Valor de retorno

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o retornado `CStringT` objeto pode estar vazio.

### <a name="remarks"></a>Comentários

Se *nCount* excede o comprimento da cadeia de caracteres e, em seguida, a cadeia de caracteres inteira é extraída. `Right` é semelhante do Basic `Right` função (exceto que os índices em Basic são baseadas em zero).

Para conjuntos de caracteres multibyte (MBCS), *nCount* refere-se a cada byte de caractere; ou seja, um cliente potencial e trilha de 8 bits em um caractere multibyte são contados como dois caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#131](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_35.cpp)]

##  <a name="setsysstring"></a>  CStringT::SetSysString

Realoca o BSTR apontado por *pbstr* e copia o conteúdo do `CStringT` objeto nele, incluindo o caractere nulo.

```
BSTR SetSysString(BSTR* pbstr) const;
```

### <a name="parameters"></a>Parâmetros

*pbstr*<br/>
Um ponteiro para uma cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

A nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Dependendo do conteúdo do `CStringT` object, o valor do BSTR referenciado pela *pbstr* pode alterar. A função lançará um `CMemoryException` se houver memória insuficiente.

Normalmente, essa função é usada para alterar o valor de cadeias de caracteres passada por referência para a automação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#132](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_36.cpp)]

##  <a name="spanexcluding"></a>  CStringT::SpanExcluding

Extrai caracteres de cadeia de caracteres, começando com o primeiro caractere que não estão no conjunto de caracteres identificada pelo *pszCharSet*.

```
CStringT SpanExcluding(PCXSTR pszCharSet) const;
```

### <a name="parameters"></a>Parâmetros

*pszCharSet*<br/>
Uma cadeia de caracteres é interpretada como um conjunto de caracteres.

### <a name="return-value"></a>Valor de retorno

Uma subcadeia de caracteres que contém os caracteres na cadeia de caracteres que não estão no *pszCharSet*, começando com o primeiro caractere na cadeia de caracteres e terminando com o primeiro caractere encontrado na cadeia de caracteres que também está na *pszCharSet* (ou seja, começando com o primeiro caractere na cadeia de caracteres e até, mas excluindo o primeiro caractere na cadeia de caracteres for encontrada *pszCharSet*). Retorna a cadeia de caracteres inteira se nenhum caractere em *pszCharSet* for encontrado na cadeia de caracteres.

### <a name="remarks"></a>Comentários

`SpanExcluding` extrai e retorna todos os caracteres que precede a primeira ocorrência de um caractere em *pszCharSet* (em outras palavras, o caractere de *pszCharSet* e todos os caracteres subsequentes na cadeia de caracteres, não são retornado). Se nenhum caractere de *pszCharSet* for encontrado na cadeia de caracteres, em seguida, `SpanExcluding` retorna a cadeia de caracteres inteira.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#133](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_37.cpp)]

##  <a name="spanincluding"></a>  CStringT::SpanIncluding

Extrai caracteres de cadeia de caracteres, começando com o primeiro caractere, que estão no conjunto de caracteres identificada pelo *pszCharSet*.

```
CStringT SpanIncluding(PCXSTR pszCharSet) const;
```

### <a name="parameters"></a>Parâmetros

*pszCharSet*<br/>
Uma cadeia de caracteres é interpretada como um conjunto de caracteres.

### <a name="return-value"></a>Valor de retorno

Uma subcadeia de caracteres que contém os caracteres na cadeia de caracteres que estão na *pszCharSet*, começando com o primeiro caractere na cadeia de caracteres e termina quando um caractere for encontrado na cadeia de caracteres que não está na *pszCharSet*. `SpanIncluding` Retorna uma subcadeia de caracteres vazia se não for o primeiro caractere na cadeia de caracteres no conjunto especificado.

### <a name="remarks"></a>Comentários

Se o primeiro caractere da cadeia de caracteres não está no conjunto de caracteres, em seguida, `SpanIncluding` retorna uma cadeia de caracteres vazia. Caso contrário, ela retorna uma sequência de caracteres consecutivos que estão no conjunto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#134](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_38.cpp)]

##  <a name="tokenize"></a>  CStringT::Tokenize

Localiza o próximo token em uma cadeia de caracteres de destino

```
CStringT Tokenize(PCXSTR pszTokens, int& iStart) const;
```

### <a name="parameters"></a>Parâmetros

*pszTokens*<br/>
Uma cadeia de caracteres que contém os delimitadores de token. A ordem desses delimitadores não é importante.

*iStart*<br/>
O índice baseado em zero para iniciar a pesquisa.

### <a name="return-value"></a>Valor de retorno

Um `CStringT` objeto que contém o valor do token atual.

### <a name="remarks"></a>Comentários

O `Tokenize` função localiza o próximo token na cadeia de caracteres de destino. O conjunto de caracteres em *pszTokens* Especifica possíveis delimitadores de token a ser encontrado. Em cada chamada para `Tokenize` a função começa em *iStart*ignora delimitadores à esquerda e retorna um `CStringT` objeto que contém o token atual, o que é uma cadeia de caracteres até o próximo caractere delimitador. O valor de *iStart* é atualizado para ser posição após o caractere delimitador final, ou -1 se o final da cadeia de caracteres foi atingido. Mais tokens podem ser divididos, fora o restante da cadeia de caracteres de destino por uma série de chamadas para `Tokenize`, usando *iStart* para controlar onde na cadeia de caracteres para o próximo token será lido. Quando não houver nenhum token é a função retornará uma cadeia de caracteres vazia e *iStart* será definido como -1.

Ao contrário de CRT criar tokens de funções, como [strtok_s, strtok_s_l, wcstok_s, wcstok_s_l, mbstok_s, mbstok_s_l](../../c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l.md), `Tokenize` não modifica a cadeia de caracteres de destino.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#135](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_39.cpp)]

### <a name="remarks"></a>Comentários

A saída deste exemplo é o seguinte:

```Output
Resulting Token: First
Resulting Token: Second
Resulting Token: Third
```

##  <a name="trim"></a>  CStringT::Trim

Corta à esquerda e os caracteres da cadeia de caracteres à direita.

```
CStringT& Trim(XCHAR chTarget);
CStringT& Trim(PCXSTR pszTargets);
CStringT& Trim();
```

### <a name="parameters"></a>Parâmetros

*chTarget*<br/>
O caractere de destino a serem cortados.

*pszTargets*<br/>
Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todos à direita e ocorrências de caracteres em *pszTarget* serão apagadas do `CStringT` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna a cadeia de caracteres cortada.

### <a name="remarks"></a>Comentários

Remove todas as ocorrências à esquerda e à direita de um dos seguintes:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na cadeia de caracteres especificada por *pszTargets*.

- Espaço em branco.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#136](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_40.cpp)]

### <a name="remarks"></a>Comentários

A saída deste exemplo é o seguinte:

```Output
Before: "******Soccer is best, but liquor is quicker!!!!!"
After : "Soccer is best, but liquor is quicker"
```

##  <a name="trimleft"></a>  CStringT::TrimLeft

Remove os caracteres à esquerda da cadeia de caracteres.

```
CStringT& TrimLeft(XCHAR chTarget);
CStringT& TrimLeft(PCXSTR pszTargets);
CStringT& TrimLeft();
```

### <a name="parameters"></a>Parâmetros

*chTarget*<br/>
O caractere de destino a serem cortados.

*pszTargets*<br/>
Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todas as ocorrências à esquerda de caracteres em *pszTarget* serão apagadas do `CStringT` objeto.

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres cortada resultante.

### <a name="remarks"></a>Comentários

Remove todas as ocorrências à esquerda e à direita de um dos seguintes:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na cadeia de caracteres especificada por *pszTargets*.

- Espaço em branco.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#137](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_41.cpp)]

##  <a name="trimright"></a>  CStringT::TrimRight

Remove os caracteres da cadeia de caracteres à direita.

```
CStringT& TrimRight(XCHAR chTarget);
CStringT& TrimRight(PCXSTR pszTargets);
CStringT& TrimRight();
```

### <a name="parameters"></a>Parâmetros

*chTarget*<br/>
O caractere de destino a serem cortados.

*pszTargets*<br/>
Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todos à direita ocorrências de caracteres em *pszTarget* serão apagadas do `CStringT` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o `CStringT` objeto que contém a cadeia de caracteres cortada.

### <a name="remarks"></a>Comentários

Remove à direita de ocorrências de um dos seguintes:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na cadeia de caracteres especificada por *pszTargets*.

- Espaço em branco.

O `CStringT& TrimRight(XCHAR chTarget)` versão aceita um parâmetro de caractere e remove todas as cópias do caractere de final de `CStringT` dados de cadeia de caracteres. Ele é iniciado a partir do final da cadeia de caracteres e funciona em direção à frente. Ele interrompe quando ele encontra um caractere diferente ou quando `CSTringT` ficar sem dados de caractere.

O `CStringT& TrimRight(PCXSTR pszTargets)` versão aceita uma cadeia de caracteres terminada em nulo que contém todos os caracteres a ser pesquisado. Ele remove todas as cópias desses caracteres no `CStringT` objeto. Ele inicia no final da cadeia de caracteres e funciona em direção à frente. Ele interrompe quando ele encontra um caractere que não está na cadeia de caracteres de destino, ou quando `CStringT` ficar sem dados de caractere. Ele não tenta corresponder a cadeia de caracteres de destino inteira para uma subcadeia de caracteres do final do `CStringT`.

O `CStringT& TrimRight()` versão não requer parâmetros. Organizando quaisquer caracteres de espaço em branco à direita do final do `CStringT` cadeia de caracteres. Caracteres de espaço em branco podem ser quebras de linha, espaços ou tabulações.

-

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#138](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_42.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)<br/>
[Classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)
