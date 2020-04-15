---
title: Classe Cstringt
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
ms.openlocfilehash: 90f63b474f509b4d1a15ad6fe11bda61c343f483
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317595"
---
# <a name="cstringt-class"></a>Classe Cstringt

Esta classe representa `CStringT` um objeto.

## <a name="syntax"></a>Sintaxe

```
template<typename BaseType, class StringTraits>
class CStringT :
    public CSimpleStringT<BaseType,
        _CSTRING_IMPL_::_MFCDLLTraitsCheck<BaseType, StringTraits>::c_bIsMFCDLLTraits>
```

#### <a name="parameters"></a>Parâmetros

*BaseType*<br/>
O tipo de caractere da classe de cordas. Um dos seguintes pode ser feito:

- **char** (para strings de caracteres ANSI).

- **wchar_t** (para strings de caracteres Unicode).

- TCHAR (para as seqüências de caracteres ANSI e Unicode).

*StringTraits*<br/>
Determina se a classe de string precisa de suporte à biblioteca C Run-Time (CRT) e onde os recursos de string estão localizados. Um dos seguintes pode ser feito:

- &#124; &#124; ** > >** **&#124;** &#124; wchar_t **<** **&#124;** **wchar_t<**

   A classe requer suporte crt e procura por strings de recursos no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).

- de wchar_t< de &#124; de &#124; &#124; **char** T ** > >CHAR,**< Do **&#124;** &#124; wchar_t **MT** **TCHAR, ChTraitsOS< wchar_t**

   A classe não requer suporte crt e procura por strings de recursos no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).

- **StrTraitMFC< wchar_t** &#124; **char** &#124; **TCHAR, ChTraitsCRT< wchar_t wchar_t** **&#124; char** &#124; **TCHAR > >**

   A classe requer suporte a CRT e procura por strings de recursos usando o algoritmo de pesquisa Padrão Do MFC.

- **StrTraitMFC< wchar_t** **&#124; char** &#124; **TCHAR, ChTraitsOS< wchar_t** &#124; &#124; wchar_t ** > >** **tchar**

   A classe não requer suporte crt e procura por strings de recursos usando o algoritmo de pesquisa Padrão MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Cstringt::CStringT](#cstringt)|Constrói um `CStringT` objeto de várias maneiras.|
|[Cstringt::~Cstringt](#_dtorcstringt)|Destrói um objeto `CStringT`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringT::AllocSysString](#allocsysstring)|Aloca um BSTR `CStringT` a partir de dados.|
|[CStringT::AnsiToOem](#ansitooem)|Faz uma conversão no lugar do caractere ANSI definido para o conjunto de caracteres OEM.|
|[CStringT::ApêndiceFormato](#appendformat)|Anexa dados formatados a `CStringT` um objeto existente.|
|[CStringT::Collate](#collate)|Compara duas strings (sensível a maiúsculas e minúsculas, usa informações específicas do local).|
|[CstringT::CollateNoCase](#collatenocase)|Compara duas strings (caso insensível, usa informações específicas do local).|
|[Cstringt::Compare](#compare)|Compara duas cordas (sensível ao caso).|
|[Cstringt::ComparenoCase](#comparenocase)|Compara duas cordas (caso insensível).|
|[CStringT::Delete](#delete)|Exclui um caractere ou caracteres de uma seqüência.|
|[Cstringt::Encontrar](#find)|Encontra um caractere ou substring dentro de uma seqüência maior.|
|[Cstringt::Findoneof](#findoneof)|Encontra o primeiro caractere correspondente de um conjunto.|
|[CstringT::Formato](#format)|Formata a `sprintf` seqüência como faz.|
|[CstringT::FormatMessage](#formatmessage)|Formata uma seqüência de mensagens.|
|[CstringT::FormatMessageV](#formatmessagev)|Formata uma seqüência de mensagens usando uma lista de argumentos variáveis.|
|[CstringT::FormatV](#formatv)|Formata a seqüência usando uma lista variável de argumentos.|
|[Cstringt::GetEnvironmentVariable](#getenvironmentvariable)|Define a string para o valor da variável de ambiente especificada.|
|[Cstringt::Inserir](#insert)|Insere um único caractere ou uma substring no índice dado dentro da string.|
|[Cstringt::Esquerda](#left)|Extrai a parte esquerda de uma corda.|
|[CstringT::LoadString](#loadstring)|Carrega um objeto `CStringT` existente a partir de um recurso do Windows.|
|[Cstringt::MakeLower](#makelower)|Converte todos os caracteres nesta seqüência em caracteres minúsculos.|
|[Cstringt::MakeReverse](#makereverse)|Inverte a corda.|
|[Cstringt::Makeupper](#makeupper)|Converte todos os caracteres desta seqüência em caracteres maiúsculos.|
|[Cstringt::Mid](#mid)|Extrai a parte do meio de uma corda.|
|[CstringT::OemToAnsi](#oemtoansi)|Faz uma conversão no lugar do caractere OEM definido para o conjunto de caracteres ANSI.|
|[Cstringt::Remove](#remove)|Remove caracteres indicados de uma seqüência de caracteres.|
|[CstringT:::Substituir](#replace)|Substitui caracteres indicados por outros caracteres.|
|[Cstringt::ReverseFind](#reversefind)|Encontra um caractere dentro de uma seqüência maior; começa a partir do fim.|
|[Cstringt::Direito](#right)|Extrai a parte certa de uma corda.|
|[CStringT::SetSysString](#setsysstring)|Define um objeto BSTR existente `CStringT` com dados de um objeto.|
|[CStringT::SpanExcluding](#spanexcluding)|Extrai caracteres da seqüência, começando pelo primeiro caractere, que `pszCharSet`não estão no conjunto de caracteres identificados por .|
|[Cstringt::SpanIncludingndo](#spanincluding)|Extrai uma substring que contém apenas os caracteres em um conjunto.|
|[CStringT::Tokenize](#tokenize)|Extrai tokens especificados em uma seqüência de metas.|
|[Cstringt::Trim](#trim)|Apara todos os caracteres de espaço branco principais e arrastados da seqüência.|
|[Cstringt::TrimLeft](#trimleft)|Apara os principais caracteres do espaço branco da seqüência.|
|[Cstringt::TrimRight](#trimright)|Apara caracteres de espaço branco da seqüência.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[CStringT::operador =](#operator_eq)|Atribui um novo valor `CStringT` a um objeto.|
|[CStringT::operador +](#operator_add)|Concatena duas cordas ou um caractere e uma corda.|
|[CStringT::operador +=](#operator_add_eq)|Concatena uma nova seqüência até o final de uma seqüência existente.|
|[CStringT::operador ==](#operator_eq_eq)|Determina se duas cordas são logicamente iguais.|
|[CStringT::operador !=](#operator_neq)|Determina se duas cordas logicamente não são iguais.|
|[CStringT::operador&lt;](#operator_lt)|Determina se a corda do lado esquerdo do operador é menor do que a corda do lado direito.|
|[CStringT::operador&gt;](#operator_gt)|Determina se a corda do lado esquerdo do operador é maior do que a corda do lado direito.|
|[CStringT::operador&lt;=](#operator_lt_eq)|Determina se a corda do lado esquerdo do operador é menor ou igual à corda do lado direito.|
|[CStringT::operador&gt;=](#operator_gt_eq)|Determina se a corda do lado esquerdo do operador é maior ou igual à corda do lado direito.|

## <a name="remarks"></a>Comentários

`CStringT`herda da [Classe CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md). Recursos avançados, como manipulação de caracteres, `CStringT`ordenação e pesquisa, são implementados por .

> [!NOTE]
> `CStringT`objetos são capazes de lançar exceções. Isso ocorre `CStringT` quando um objeto fica sem memória por qualquer razão.

Um `CStringT` objeto consiste em uma seqüência de caracteres de comprimento variável. `CStringT`fornece funções e operadores usando sintaxe semelhante à do Basic. Os operadores de concatenação e comparação, `CStringT` juntamente com o gerenciamento simplificado da memória, tornam os objetos mais fáceis de usar do que os arrays de caracteres comuns.

> [!NOTE]
> Embora seja possível `CStringT` criar instâncias que contenham caracteres nulos incorporados, recomendamos contra ele. Métodos de chamada `CStringT` e operadores em objetos que contêm caracteres nulos incorporados podem produzir resultados não intencionais.

Usando diferentes combinações `BaseType` `StringTraits` dos `CStringT` parâmetros e parâmetros, os objetos podem vir nos seguintes tipos, que foram predefinidos pelas bibliotecas ATL.

Se estiver usando em um aplicativo ATL:

`CString`, `CStringA`e `CStringW` são exportados do MFC DLL (MFC90). DLL), nunca de DLLs de usuário. Isso é feito `CStringT` para evitar que se multiplique definido.

> [!NOTE]
> Se o seu código contiver a solução de solução para erros de linker descritos em [Classes de cadeia de exportação usando CStringT,](../../atl-mfc-shared/exporting-string-classes-using-cstringt.md)você deve remover esse código. Ele não é mais necessário.

Os seguintes tipos de string estão disponíveis em aplicativos baseados em MFC:

|Tipo CStringT|Declaração|
|-------------------|-----------------|
|`CStringA`|Uma seqüência de caracteres ANSI com suporte a CRT.|
|`CStringW`|Uma seqüência de tipo de caractere Unicode com suporte a CRT.|
|`CString`|Tanto os tipos de caracteres ANSI quanto Unicode com suporte a CRT.|

Os seguintes tipos de strings estão disponíveis em projetos onde ATL_CSTRING_NO_CRT é definida:

|Tipo CStringT|Declaração|
|-------------------|-----------------|
|`CAtlStringA`|Uma seqüência de caracteres ANSI sem suporte a CRT.|
|`CAtlStringW`|Uma seqüência de tipo de caractere Unicode sem suporte a CRT.|
|`CAtlString`|Tipos de caracteres ANSI e Unicode sem suporte a CRT.|

Os seguintes tipos de strings estão disponíveis em projetos onde ATL_CSTRING_NO_CRT não é definido:

|Tipo CStringT|Declaração|
|-------------------|-----------------|
|`CAtlStringA`|Uma seqüência de caracteres ANSI com suporte a CRT.|
|`CAtlStringW`|Uma seqüência de tipo de caractere Unicode com suporte a CRT.|
|`CAtlString`|Tanto os tipos de caracteres ANSI quanto Unicode com suporte a CRT.|

`CString`os objetos também têm as seguintes características:

- `CStringT`objetos podem crescer como resultado de operações de concatenação.

- `CStringT`objetos seguem "semântica de valor". Pense em `CStringT` um objeto como uma seqüência real, não como um ponteiro para uma string.

- Você pode substituir `CStringT` livremente objetos por `PCXSTR` argumentos de função.

- Gerenciamento de memória personalizado para buffers de strings. Para obter mais informações, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="cstringt-predefined-types"></a>Tipos predefinidos do CStringT

Como `CStringT` usa um argumento de modelo para definir o tipo de caractere [(wchar_t](../../c-runtime-library/standard-types.md) ou [char](../../c-runtime-library/standard-types.md)) suportado, os tipos de parâmetros do método podem ser complicados às vezes. Para simplificar esse problema, um conjunto de tipos `CStringT` predefinidos é definido e usado em toda a classe. A tabela a seguir lista os vários tipos:

|Nome|Descrição|
|----------|-----------------|
|`XCHAR`|Um único caractere **(wchar_t** ou **char**) com `CStringT` o mesmo tipo de caractere do objeto.|
|`YCHAR`|Um único caractere **(wchar_t** ou **char**) com `CStringT` o tipo de caractere oposto como objeto.|
|`PXSTR`|Um ponteiro para uma seqüência de caracteres **(wchar_t** ou **char**) com o mesmo tipo de caractere do `CStringT` objeto.|
|`PYSTR`|Um ponteiro para uma seqüência de caracteres **(wchar_t** ou **char**) com o tipo de caractere oposto como o `CStringT` objeto.|
|`PCXSTR`|Um ponteiro para uma seqüência **de caracteres const** **(wchar_t** ou **char**) com o mesmo tipo de caractere que o `CStringT` objeto.|
|`PCYSTR`|Um ponteiro para uma seqüência **de caracteres const** **(wchar_t** ou **char**) com o tipo de caractere oposto como o `CStringT` objeto.|

> [!NOTE]
> O código que anteriormente usou `CString` métodos `AssignCopy`não documentados de (tais como ) `CStringT` deve ser `GetBuffer` `ReleaseBuffer`substituído por um código que use os seguintes métodos documentados de (como ou ). Esses métodos são `CSimpleStringT`herdados de .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Csimplestringt](../../atl-mfc-shared/reference/csimplestringt-class.md)

`CStringT`

## <a name="requirements"></a>Requisitos

|Cabeçalho|Usar para|
|------------|-------------|
|cstringt.h|Objetos de string somente MFC|
|atlstr.h|Objetos de seqüência não-MFC|

## <a name="cstringtallocsysstring"></a><a name="allocsysstring"></a>CStringT::AllocSysString

Aloca uma seqüência compatível com automação do tipo `CStringT` BSTR e copia o conteúdo do objeto nele, incluindo o caractere nulo de terminação.

```
BSTR AllocSysString() const;
```

### <a name="return-value"></a>Valor retornado

A seqüência recém-alocada.

### <a name="remarks"></a>Comentários

Em programas MFC, uma [classe CMemoryException](../../mfc/reference/cmemoryexception-class.md) é lançada se houver memória insuficiente. Em programas ATL, um [CAtlException](../../atl/reference/catlexception-class.md) é lançado. Esta função é normalmente usada para retornar strings para Automação.

Normalmente, se essa seqüência é passada para uma função COM como um parâmetro [in], então isso requer que o chamador liberte a string. Isso pode ser feito usando [SysFreeString](/windows/win32/api/oleauto/nf-oleauto-sysfreestring), como descrito no Windows SDK. Para obter mais informações, consulte [Alocando e Liberando Memória para um BSTR](../../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md).

Para obter mais informações sobre funções de alocação de OLE no Windows, consulte [SysAllocString](/windows/win32/api/oleauto/nf-oleauto-sysallocstring) no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CStringT::AllocSysString`.

[!code-cpp[NVC_ATLMFC_Utilities#105](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_1.cpp)]

## <a name="cstringtansitooem"></a><a name="ansitooem"></a>CStringT::AnsiToOem

Converte todos os `CStringT` caracteres deste objeto do caractere ANSI definido para o conjunto de caracteres OEM.

```
void AnsiToOem();
```

### <a name="remarks"></a>Comentários

A função não está disponível se _UNICODE for definida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#106](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_2.cpp)]

## <a name="cstringtappendformat"></a><a name="appendformat"></a>CStringT::ApêndiceFormato

Anexa dados formatados a `CStringT` um objeto existente.

```
void __cdecl AppendFormat(PCXSTR pszFormat, [, argument] ...);
void __cdecl AppendFormat(UINT nFormatID, [, argument] ...);
```

### <a name="parameters"></a>Parâmetros

*Pszformat*<br/>
Uma seqüência de controle de formato.

*Nformatid*<br/>
O identificador de recurso string que contém a seqüência de controle de formato.

*Argumento*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

Esta função formata e anexa uma série `CStringT`de caracteres e valores no . Cada argumento opcional (se houver) é convertido e anexado de acordo com a especificação de formato correspondente no *pszFormat* ou a partir do recurso de string identificado por *nFormatID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#107](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_3.cpp)]

## <a name="cstringtcollate"></a><a name="collate"></a>CStringT::Collate

Compara duas strings usando a `_tcscoll`função genérico-texto .

```
int Collate(PCXSTR psz) const throw();
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A outra seqüência usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as strings forem `CStringT` idênticas, < 0 se este `CStringT` objeto for menor que *psz,* ou > 0 se este objeto for maior que *psz*.

### <a name="remarks"></a>Comentários

A função `_tcscoll`de texto genérico, que é definida em TCHAR. H, mapeia para ou, `strcoll` `wcscoll`ou, `_mbscoll`dependendo do conjunto de caracteres definido no tempo de compilação. Cada função realiza uma comparação sensível a maiúsculas e minúsculas das strings de acordo com a página de código atualmente em uso. Para obter mais informações, consulte [strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).

## <a name="cstringtcollatenocase"></a><a name="collatenocase"></a>CstringT::CollateNoCase

Compara duas strings usando a `_tcscoll`função genérico-texto .

```
int CollateNoCase(PCXSTR psz) const throw();
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A outra seqüência usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as strings forem idênticas (ignorando caso), < 0 se `CStringT` este objeto for menor que *psz* (ignorando caso), ou > 0 se este `CStringT` objeto for maior que *psz* (ignorando caso).

### <a name="remarks"></a>Comentários

A função `_tcscoll`de texto genérico, que é definida em TCHAR. H, mapeia para ou, `stricoll` `wcsicoll`ou, `_mbsicoll`dependendo do conjunto de caracteres definido no tempo de compilação. Cada função realiza uma comparação insensível de casos das strings, de acordo com a página de código atualmente em uso. Para obter mais informações, consulte [strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#109](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_4.cpp)]

## <a name="cstringtcompare"></a><a name="compare"></a>Cstringt::Compare

Compara duas cordas (sensível ao caso).

```
int Compare(PCXSTR psz) const;
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A outra seqüência usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as strings forem `CStringT` idênticas, < 0 se este `CStringT` objeto for menor que *psz,* ou > 0 se este objeto for maior que *psz*.

### <a name="remarks"></a>Comentários

A função `_tcscmp`de texto genérico, que é definida em TCHAR. H, mapeia para ou, `strcmp` `wcscmp`ou, `_mbscmp`dependendo do conjunto de caracteres definido no tempo de compilação. Cada função realiza uma comparação sensível a maiúsculas e não é afetada pela localidade. Para obter mais informações, consulte [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md).

Se a seqüência contiver nulos incorporados, para fins de comparação, a seqüência será considerada truncada no primeiro caractere nulo incorporado.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CStringT::Compare`.

[!code-cpp[NVC_ATLMFC_Utilities#110](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_5.cpp)]

## <a name="cstringtcomparenocase"></a><a name="comparenocase"></a>Cstringt::ComparenoCase

Compara duas cordas (caso insensível).

```
int CompareNoCase(PCXSTR psz) const throw();
```

### <a name="parameters"></a>Parâmetros

*Psz*<br/>
A outra seqüência usada para comparação.

### <a name="return-value"></a>Valor retornado

Zero se as strings forem idênticas (ignorando caso), <0 se `CStringT` este objeto for menor que *psz* (ignorando caso), ou >0 se este `CStringT` objeto for maior que *psz* (ignorando caso).

### <a name="remarks"></a>Comentários

A função `_tcsicmp`de texto genérico, que é definida em TCHAR. H, mapeia para ou, `_stricmp` `_wcsicmp` dependendo `_mbsicmp`do conjunto de caracteres definido no tempo de compilação. Cada função realiza uma comparação insensível de casos das strings. A comparação depende do aspecto LC_CTYPE do local, mas não LC_COLLATE. Para mais informações, consulte [_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l.](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#111](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_6.cpp)]

## <a name="cstringtcstringt"></a><a name="cstringt"></a>Cstringt::CStringT

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

*Pch*<br/>
Um ponteiro para uma matriz de caracteres de comprimento *nLength,* não nulo-terminado.

*Nlength*<br/>
Uma contagem do número de caracteres em *pch*.

*Ch*<br/>
Um único personagem.

*pszSrc*<br/>
Uma seqüência de terminadas nula a ser copiada para este `CStringT` objeto.

*pStringMgr*<br/>
Um ponteiro para o `CStringT` gerenciador de memória para o objeto. Para obter `IAtlStringMgr` mais informações `CStringT`sobre e gerenciamento de memória para , consulte [Gerenciamento de memória com CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

*strSrc*<br/>
Um objeto `CStringT` existente a ser `CStringT` copiado para este objeto. Para obter `CThisString` mais `CThisSimpleString`informações sobre e , consulte a seção Observações.

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um objeto variante a `CStringT` ser copiado neste objeto.

*BaseType*<br/>
O tipo de caractere da classe de cordas. Um dos seguintes pode ser feito:

**char** (para strings de caracteres ANSI).

**wchar_t** (para strings de caracteres Unicode).

TCHAR (para as seqüências de caracteres ANSI e Unicode).

*bMFCDLL*<br/>
Boolean o que especifica se o projeto é um DLL MFC (TRUE) ou não (FALSE).

*String SystemString*<br/>
Deve `System::String`ser , e o projeto deve ser compilado com /clr.

*pString*<br/>
Uma alça `CStringT` para um objeto.

### <a name="remarks"></a>Comentários

Como os construtores copiam os dados de entrada em um novo armazenamento alocado, você deve estar ciente de que exceções de memória podem resultar. Observe que alguns desses construtores atuam como funções de conversão. Isso permite que você substitua, por exemplo, um LPTSTR onde um `CStringT` objeto é esperado.

- `CStringT`( `LPCSTR` `lpsz` ): Constrói um `CStringT` Unicode a partir de uma seqüência ANSI. Você também pode usar este construtor para carregar um recurso de string, como mostrado no exemplo abaixo.

- `CStringT(`): Constrói `CStringT` a a partir de uma seqüência unicode. `LPCWSTR` `lpsz`

- `CStringT`( `const unsigned char*` `psz` ): Permite que `CStringT` você construa um de um ponteiro para **char não assinado**.

> [!NOTE]
> Defina a _CSTRING_DISABLE_NARROW_WIDE_CONVERSION macro para desativar a conversão implícita de strings entre as strings ANSI e Unicode. A macro exclui dos construtores de compilação que suportam a conversão.

Observe que o parâmetro *strSrc* `CStringT` pode `CThisSimpleString` ser um ou objeto. Para, `CStringT`use uma de suas instantivas padrão (`CString`, `CStringA`ou `CStringW`); para `CThisSimpleString`, use um **ponteiro deste.** `CThisSimpleString`declara uma instância da [Classe CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), que é uma classe de string `CStringT` menor com menos funcionalidade incorporada do que a classe.

O operador `CSimpleStringT<>&()` de `CStringT` sobrecarga constrói `CSimpleStringT` um objeto a partir de uma declaração.

> [!NOTE]
> Embora seja possível `CStringT` criar instâncias que contenham caracteres nulos incorporados, recomendamos contra ele. Métodos de chamada `CStringT` e operadores em objetos que contêm caracteres nulos incorporados podem produzir resultados não intencionais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#112](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_7.cpp)]

## <a name="cstringtcstringt"></a><a name="_dtorcstringt"></a>Cstringt::~Cstringt

Destrói o `CStringT` objeto.

```
~CStringT() throw();
```

### <a name="remarks"></a>Comentários

Destrói o `CStringT` objeto.

## <a name="cstringtdelete"></a><a name="delete"></a>CStringT::Delete

Exclui um caractere ou caracteres de uma seqüência começando com o caractere no índice dado.

```
int Delete(int iIndex, int nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
O índice baseado em zero do `CStringT` primeiro caractere no objeto a ser excluído.

*Ncount*<br/>
O número de caracteres a serem removidos.

### <a name="return-value"></a>Valor retornado

O comprimento da seqüência alterada.

### <a name="remarks"></a>Comentários

Se *nCount* for maior que a seqüência, o resto da seqüência será removida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#113](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_8.cpp)]

```Output
Before: Soccer is best,
    but hockey is quicker!
After: Soccer best,
    but hockey is quicker!
```

## <a name="cstringtfind"></a><a name="find"></a>Cstringt::Encontrar

Pesquisa esta seqüência para a primeira correspondência de um caractere ou substring.

```
int Find(PCXSTR pszSub, int iStart=0) const throw();
int Find(XCHAR ch, int iStart=0) const throw();
```

### <a name="parameters"></a>Parâmetros

*pszSub*<br/>
Uma subcorda para procurar.

*Istart*<br/>
O índice do caractere na seqüência para iniciar a pesquisa com, ou 0 para começar a partir do início.

*Ch*<br/>
Um único personagem para procurar.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do `CStringT` primeiro caractere neste objeto que corresponde à substringou ou caracteres solicitados; -1 se a substring ou caractere não for encontrado.

### <a name="remarks"></a>Comentários

A função é sobrecarregada para aceitar caracteres únicos (semelhantes à função `strchr` `strstr`tempo de execução) e strings (semelhantes a ).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#114](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_9.cpp)]

## <a name="cstringtfindoneof"></a><a name="findoneof"></a>Cstringt::Findoneof

Pesquisa esta seqüência para o primeiro caractere que corresponde a qualquer caractere contido em *pszCharSet*.

```
int FindOneOf(PCXSTR pszCharSet) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pszcharset*<br/>
String contendo caracteres para correspondência.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do primeiro caractere nesta seqüência que também está no *pszCharSet*; -1 se não houver correspondência.

### <a name="remarks"></a>Comentários

Encontra a primeira ocorrência de qualquer um dos personagens em *pszCharSet*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#115](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_10.cpp)]

## <a name="cstringtformat"></a><a name="format"></a>CstringT::Formato

Grava dados formatados para a mesma `CStringT` forma que [sprintf_s](../../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md) formata dados em uma matriz de caracteres estilo C.

```
void __cdecl Format(UINT nFormatID, [, argument]...);
void __cdecl Format(PCXSTR pszFormat,  [, argument] ...);
```

### <a name="parameters"></a>Parâmetros

*Nformatid*<br/>
O identificador de recurso string que contém a seqüência de controle de formato.

*Pszformat*<br/>
Uma seqüência de controle de formato.

*Argumento*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

Esta função formata e armazena uma série `CStringT`de caracteres e valores no . Cada argumento opcional (se houver) é convertido e desproduzido de acordo com a especificação de formato correspondente no *pszFormat* ou do recurso string identificado por *nFormatID*.

A chamada falhará se o objeto de string `Format`em si for oferecido como parâmetro para . Por exemplo, o seguinte código causará resultados imprevisíveis:

[!code-cpp[NVC_ATLMFC_Utilities#116](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_11.cpp)]

Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#117](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_12.cpp)]

## <a name="cstringtformatmessage"></a><a name="formatmessage"></a>CstringT::FormatMessage

Formata uma seqüência de mensagens.

```
void __cdecl FormatMessage(UINT nFormatID, [, argument]...);
void __cdecl FormatMessage(PCXSTR pszFormat, [, argument]...);
```

### <a name="parameters"></a>Parâmetros

*Nformatid*<br/>
O identificador de recurso de seqüência que contém o texto da mensagem não formatado.

*Pszformat*<br/>
Aponta para a seqüência de controle de formato. Ele será digitalizado para inserções e formatado em conformidade. A seqüência de formato é semelhante às strings de formato *printf*de função de tempo de execução, exceto que permite que os parâmetros sejam inseridos em uma ordem arbitrária.

*Argumento*<br/>
Argumentos opcionais.

### <a name="remarks"></a>Comentários

A função requer uma definição de mensagem como entrada. A definição da mensagem é determinada pelo *pszFormat* ou pelo recurso string identificado por *nFormatID*. A função copia o texto `CStringT` da mensagem formatado para o objeto, processando quaisquer seqüências de inserção incorporadas, se solicitada.

> [!NOTE]
> `FormatMessage`tentativas de alocar a memória do sistema para a seqüência recém-formatada. Se essa tentativa falhar, uma exceção de memória será automaticamente lançada.

Cada inserção deve ter um parâmetro correspondente seguindo o parâmetro *pszFormat* ou *nFormatID.* Dentro do texto da mensagem, várias seqüências de fuga são suportadas para formatar dinamicamente a mensagem. Para obter mais informações, consulte a função Windows [FormatMessage](/windows/win32/api/winbase/nf-winbase-formatmessage) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#118](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_13.cpp)]

## <a name="cstringtformatmessagev"></a><a name="formatmessagev"></a>CstringT::FormatMessageV

Formata uma seqüência de mensagens usando uma lista de argumentos variáveis.

```
void FormatMessageV(PCXSTR pszFormat, va_list* pArgList);
```

### <a name="parameters"></a>Parâmetros

*Pszformat*<br/>
Aponta para a seqüência de controle de formato. Ele será digitalizado para inserções e formatado em conformidade. A seqüência de formato `printf`é semelhante às strings de formato de função de tempo de execução, exceto que permite que os parâmetros sejam inseridos em uma ordem arbitrária.

*pArgList*<br/>
Ponteiro para uma lista de argumentos.

### <a name="remarks"></a>Comentários

A função requer uma definição de mensagem como entrada, determinada pelo *pszFormat*. A função copia o texto da mensagem formatado `CStringT` e uma lista variável de argumentos para o objeto, processando quaisquer seqüências de inserção incorporadas, se solicitada.

> [!NOTE]
> `FormatMessageV`chama [CStringT::FormatMessage](#formatmessage), que tenta alocar a memória do sistema para a seqüência recém-formatada. Se essa tentativa falhar, uma exceção de memória será automaticamente lançada.

Para obter mais informações, consulte a função Windows [FormatMessage](/windows/win32/api/winbase/nf-winbase-formatmessage) no SDK do Windows.

## <a name="cstringtformatv"></a><a name="formatv"></a>CstringT::FormatV

Formata uma seqüência de mensagens usando uma lista de argumentos variáveis.

```
void FormatV(PCXSTR pszFormat, va_list args);
```

### <a name="parameters"></a>Parâmetros

*Pszformat*<br/>
Aponta para a seqüência de controle de formato. Ele será digitalizado para inserções e formatado em conformidade. A seqüência de formato `printf`é semelhante às strings de formato de função de tempo de execução, exceto que permite que os parâmetros sejam inseridos em uma ordem arbitrária.

*Args*<br/>
Ponteiro para uma lista de argumentos.

### <a name="remarks"></a>Comentários

Grava uma seqüência formatada e `CStringT` uma lista variável `vsprintf_s` de argumentos para uma seqüência da mesma forma que formata dados em uma matriz de caracteres estilo C.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#119](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_14.cpp)]

[!code-cpp[NVC_ATLMFC_Utilities#120](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_15.cpp)]

## <a name="cstringtgetenvironmentvariable"></a><a name="getenvironmentvariable"></a>Cstringt::GetEnvironmentVariable

Define a string para o valor da variável de ambiente especificada.

```
BOOL GetEnvironmentVariable(PCXSTR pszVar);
```

### <a name="parameters"></a>Parâmetros

*pszVar*<br/>
Ponteiro para uma seqüência de terminadas nula que especifica a variável de ambiente.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Recupera o valor da variável especificada do bloco de ambiente do processo de chamada. O valor é na forma de uma seqüência de caracteres nulamente encerrada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#121](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_16.cpp)]

## <a name="cstringtinsert"></a><a name="insert"></a>Cstringt::Inserir

Insere um único caractere ou uma substring no índice dado dentro da string.

```
int Insert(int iIndex, PCXSTR psz);
int Insert(int iIndex, XCHAR ch);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
O índice do caractere antes do qual a inserção ocorrerá.

*Psz*<br/>
Um ponteiro para a substring a ser inserida.

*Ch*<br/>
O caráter a ser inserido.

### <a name="return-value"></a>Valor retornado

O comprimento da seqüência alterada.

### <a name="remarks"></a>Comentários

O parâmetro *iIndex* identifica o primeiro caractere que será movido para abrir espaço para o caractere ou substring. Se *nIndex* for zero, a inserção ocorrerá antes de toda a seqüência. Se *nIndex* for maior que o comprimento da seqüência, a função concatenará a seqüência atual e o novo material fornecido por *ch* ou *psz*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#122](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_17.cpp)]

## <a name="cstringtleft"></a><a name="left"></a>Cstringt::Esquerda

Extrai os caracteres *nCount* mais à esquerda deste `CStringT` objeto e retorna uma cópia da substring extraída.

```
CStringT Left(int nCount) const;
```

### <a name="parameters"></a>Parâmetros

*Ncount*<br/>
O número de caracteres para extrair desse objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. O objeto `CStringT` retornado pode estar vazio.

### <a name="remarks"></a>Comentários

Se *nCount* exceder o comprimento da seqüência, então toda a seqüência será extraída. `Left` é semelhante à função `Left` básica.

Para conjuntos de caracteres de vários bytes (MBCS), *nCount* trata cada seqüência de 8 bits como um caractere, de modo que *nCount* retorna o número de caracteres de vários bytes multiplicado por dois.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#123](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_18.cpp)]

## <a name="cstringtloadstring"></a><a name="loadstring"></a>CstringT::LoadString

Lê um recurso de string do Windows, identificado `CStringT` por *nID,* em um objeto existente.

```
BOOL LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID);
BOOL LoadString(HINSTANCE hInstance, UINT nID);
BOOL LoadString(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
Uma alça para a ocorrência do módulo.

*nID*<br/>
Um ID de recurso de seqüência do Windows.

*wLanguageID*<br/>
A linguagem do recurso de string.

### <a name="return-value"></a>Valor retornado

Não zero se a carga de recursos foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Carrega o recurso de string *(nID)* do módulo especificado *(hInstance)* usando o idioma especificado *(wLanguage).*

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#124](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_19.cpp)]

## <a name="cstringtmakelower"></a><a name="makelower"></a>Cstringt::MakeLower

Converte `CStringT` o objeto em uma seqüência minúscula.

```
CStringT& MakeLower();
```

### <a name="return-value"></a>Valor retornado

A seqüência minúscula resultante.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#125](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_20.cpp)]

## <a name="cstringtmakereverse"></a><a name="makereverse"></a>Cstringt::MakeReverse

Inverte a ordem dos `CStringT` caracteres no objeto.

```
CStringT& MakeReverse();
```

### <a name="return-value"></a>Valor retornado

A seqüência invertida resultante.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#126](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_21.cpp)]

## <a name="cstringtmakeupper"></a><a name="makeupper"></a>Cstringt::Makeupper

Converte `CStringT` o objeto em uma seqüência maiúscula.

```
CStringT& MakeUpper();
```

### <a name="return-value"></a>Valor retornado

A seqüência maiúscula resultante.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#127](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_22.cpp)]

## <a name="cstringtmid"></a><a name="mid"></a>Cstringt::Mid

Extrai uma substring de caracteres `CStringT` de comprimento *nCount* deste objeto, começando na posição *iFirst* (baseado em zero).

```
CStringT Mid(int iFirst, int nCount) const;
CStringT Mid(int iFirst) const;
```

### <a name="parameters"></a>Parâmetros

*iFirst*<br/>
O índice baseado em zero do `CStringT` primeiro caractere neste objeto que deve ser incluído na substring extraída.

*Ncount*<br/>
O número de caracteres para extrair desse objeto `CStringT`. Se este parâmetro não for fornecido, então o restante da corda é extraído.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o `CStringT` objeto retornado pode estar vazio.

### <a name="remarks"></a>Comentários

A função retorna uma cópia da substring extraída. `Mid`é semelhante à função Basic Mid (exceto que os índices no Básico são baseados em uma base).

Para conjuntos de caracteres multibytes (MBCS), *nCount* refere-se a cada caractere de 8 bits; ou seja, um byte de chumbo e trilha em um caractere multibyte são contados como dois caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#128](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_23.cpp)]

## <a name="cstringtoemtoansi"></a><a name="oemtoansi"></a>CstringT::OemToAnsi

Converte todos os `CStringT` caracteres deste objeto do caractere OEM definido para o conjunto de caracteres ANSI.

```
void OemToAnsi();
```

### <a name="remarks"></a>Comentários

Esta função não está disponível se _UNICODE for definida.

### <a name="example"></a>Exemplo

Veja o exemplo de [CStringT::AnsiToOem](#ansitooem).

## <a name="cstringtoperator-"></a><a name="operator_eq"></a>CStringT::operador =

Atribui um novo valor à seqüência.

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
A `CStringT` atribuir a esta seqüência.

*Str*<br/>
Uma referência a um objeto `CThisSimpleString`.

*bMFCDLL*<br/>
Um booleano especificando se o projeto é um DLL MFC ou não.

*BaseType*<br/>
O tipo de base de cordas.

*Var*<br/>
Um objeto variante para atribuir a esta seqüência.

*Ch*<br/>
Um caractere ANSI ou Unicode para atribuir à seqüência.

*pszSrc*<br/>
Um ponteiro para a seqüência original sendo atribuído.

### <a name="remarks"></a>Comentários

O operador de `CStringT` atribuição aceita outro objeto, um ponteiro de caracteres ou um único caractere. Você deve estar ciente de que exceções de memória podem ocorrer sempre que você usar este operador porque um novo armazenamento pode ser alocado.

Para obter `CThisSimpleString`informações sobre , consulte a seção Observações de [CStringT::CStringT](#cstringt).

> [!NOTE]
> Embora seja possível `CStringT` criar instâncias que contenham caracteres nulos incorporados, recomendamos contra ele. Métodos de chamada `CStringT` e operadores em objetos que contêm caracteres nulos incorporados podem produzir resultados não intencionais.

## <a name="cstringtoperator-"></a><a name="operator_add"></a>CStringT::operador +

Concatena duas cordas ou um caractere e uma corda.

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
Um caractere ANSI ou Unicode para concatenar com uma seqüência.

*ch2*<br/>
Um caractere ANSI ou Unicode para concatenar com uma seqüência.

*str1*<br/>
A `CStringT` para concatenar com uma seqüência ou personagem.

*str2*<br/>
A `CStringT` para concatenar com uma seqüência ou personagem.

*psz1*<br/>
Um ponteiro para uma seqüência de caracteres com término nula para concatenar com uma seqüência ou caractere.

*psz2*<br/>
Um ponteiro para uma seqüência para concatenar com uma seqüência ou caractere.

### <a name="remarks"></a>Comentários

Há sete formas `CStringT::operator+` de sobrecarga da função. A primeira versão concatena `CStringT` dois objetos existentes. Os dois próximos `CStringT` concatenam um objeto e uma seqüência de terminadas nula. Os dois próximos `CStringT` concatenam um objeto e um caractere ANSI. Os dois últimos concatenam um `CStringT` objeto e um caractere Unicode.

> [!NOTE]
> Embora seja possível `CStringT` criar instâncias que contenham caracteres nulos incorporados, recomendamos contra ele. Métodos de chamada `CStringT` e operadores em objetos que contêm caracteres nulos incorporados podem produzir resultados não intencionais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#140](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_24.cpp)]

## <a name="cstringtoperator-"></a><a name="operator_add_eq"></a>CStringT::operador +=

Concatena caracteres até o final da seqüência.

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

*Str*<br/>
Uma referência a um objeto `CThisSimpleString`.

*bMFCDLL*<br/>
Um booleano especificando se o projeto é um DLL MFC ou não.

*BaseType*<br/>
O tipo de base de cordas.

*Var*<br/>
Um objeto variante para concatenar a esta seqüência.

*Ch*<br/>
Um caractere ANSI ou Unicode para concatenar com uma seqüência.

*pszSrc*<br/>
Um ponteiro para a seqüência original sendo concatenado.

*strSrc*<br/>
Um `CStringT` para concatenar a esta seqüência.

### <a name="remarks"></a>Comentários

O operador aceita `CStringT` outro objeto, um ponteiro de caracteres ou um único caractere. Você deve estar ciente de que exceções de memória podem ocorrer sempre que você usar `CStringT` este operador de concatenação porque um novo armazenamento pode ser alocado para caracteres adicionados a este objeto.

Para obter `CThisSimpleString`informações sobre , consulte a seção Observações de [CStringT::CStringT](#cstringt).

> [!NOTE]
> Embora seja possível `CStringT` criar instâncias que contenham caracteres nulos incorporados, recomendamos contra ele. Métodos de chamada `CStringT` e operadores em objetos que contêm caracteres nulos incorporados podem produzir resultados não intencionais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#141](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_25.cpp)]

## <a name="cstringtoperator-"></a><a name="operator_eq_eq"></a>CStringT::operador ==

Determina se duas cordas são logicamente iguais.

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
Um ponteiro para uma seqüência de terminadas nula para comparação.

*psz2*<br/>
Um ponteiro para uma seqüência de terminadas nula para comparação.

### <a name="remarks"></a>Comentários

Testa se uma seqüência ou caractere no lado esquerdo é igual a uma seqüência ou caractere no lado direito, e retorna TRUE ou FALSE em conformidade.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#142](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_26.cpp)]

## <a name="cstringtoperator-"></a><a name="operator_neq"></a>CStringT::operador !=

Determina se duas cordas logicamente não são iguais.

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
Um caractere ANSI ou Unicode para concatenar com uma seqüência.

*ch2*<br/>
Um caractere ANSI ou Unicode para concatenar com uma seqüência.

*str1*<br/>
Um `CStringT` para comparação.

*str2*<br/>
Um `CStringT` para comparação.

*psz1*<br/>
Um ponteiro para uma seqüência de terminadas nula para comparação.

*psz2*<br/>
Um ponteiro para uma seqüência de terminadas nula para comparação.

### <a name="remarks"></a>Comentários

Teste se uma seqüência ou caractere no lado esquerdo não é igual a uma seqüência ou caractere no lado direito.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#143](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_27.cpp)]

## <a name="cstringtoperator-lt"></a><a name="operator_lt"></a>CStringT::operador&lt;

Determina se a corda do lado esquerdo do operador é menor que a corda do lado direito.

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
Um ponteiro para uma seqüência de terminadas nula para comparação.

*psz2*<br/>
Um ponteiro para uma seqüência de terminadas nula para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cordas, personagem por personagem até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#144](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_28.cpp)]

## <a name="cstringtoperator-gt"></a><a name="operator_gt"></a>CStringT::operador&gt;

Determina se a corda do lado esquerdo do operador é maior do que a corda do lado direito.

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
Um ponteiro para uma seqüência de terminadas nula para comparação.

*psz2*<br/>
Um ponteiro para uma seqüência de terminadas nula para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cordas, personagem por personagem até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#145](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_29.cpp)]

## <a name="cstringtoperator-lt"></a><a name="operator_lt_eq"></a>CStringT::operador&lt;=

Determina se a corda do lado esquerdo do operador é menor ou igual à corda do lado direito.

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
Um ponteiro para uma seqüência de terminadas nula para comparação.

*psz2*<br/>
Um ponteiro para uma seqüência de terminadas nula para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cordas, personagem por personagem até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#146](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_30.cpp)]

## <a name="cstringtoperator-gt"></a><a name="operator_gt_eq"></a>CStringT::operador&gt;=

Determina se a corda do lado esquerdo do operador é maior ou igual à corda do lado direito.

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
Um ponteiro para uma seqüência para comparação.

*psz2*<br/>
Um ponteiro para uma seqüência para comparação.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre cordas, personagem por personagem até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#147](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_31.cpp)]

## <a name="cstringtremove"></a><a name="remove"></a>Cstringt::Remove

Remove todas as instâncias do caractere especificado da seqüência.

```
int Remove(XCHAR chRemove);
```

### <a name="parameters"></a>Parâmetros

*chRemove*<br/>
O caractere a ser removido de uma seqüência.

### <a name="return-value"></a>Valor retornado

A contagem de caracteres removidos da seqüência. Zero se a seqüência não for alterada.

### <a name="remarks"></a>Comentários

Comparações para o personagem são sensíveis a maiúsculas e minúsculas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#129](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_32.cpp)]

## <a name="cstringtreplace"></a><a name="replace"></a>CstringT:::Substituir

Há duas versões de `Replace`. A primeira versão substitui uma ou mais cópias de uma substring usando outra substring. Ambas as substrings são nulas. A segunda versão substitui uma ou mais cópias de um personagem usando outro personagem. Ambas as versões operam `CStringT`nos dados de caracterearmazenados em .

```
int Replace(PCXSTR pszOld, PCXSTR pszNew);
int Replace(XCHAR chOld, XCHAR chNew);
```

### <a name="parameters"></a>Parâmetros

*pszOld*<br/>
Um ponteiro para uma seqüência de terminadas nula a ser substituído por *pszNew*.

*pszNew*<br/>
Um ponteiro para uma seqüência de terminante nulo que substitui *pszOld*.

*chOld*<br/>
O personagem a ser substituído por *chNew*.

*chNew*<br/>
O personagem substituindo *chOld*.

### <a name="return-value"></a>Valor retornado

Retorna o número de instâncias substituídas do caractere ou substring, ou zero se a seqüência não for alterada.

### <a name="remarks"></a>Comentários

`Replace`pode alterar o comprimento da seqüência porque *pszNew* e *pszOld* não têm que ter o mesmo comprimento, e várias cópias da substring antiga podem ser alteradas para a nova. A função executa uma correspondência sensível a maiúsculas e minúsculas.

Exemplos de `CStringT` exemplos `CString` `CStringA`são `CStringW`, e .

Para `CStringA` `Replace` , funciona com caracteres ANSI ou multibyte (MBCS). Para `CStringW` `Replace` , trabalha com caracteres amplos.

Para `CString`, o tipo de dados de caractere é selecionado no momento da compilação, com base em se as constantes na tabela a seguir são definidas.

|Constante definida|Tipo de dados de caracteres|
|----------------------|-------------------------|
|_UNICODE|Caracteres largos|
|_MBCS|Caracteres de vários bytes|
|Nenhum|Caracteres de byte único|
|Ambos|Indefinido|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#200](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_33.cpp)]

## <a name="cstringtreversefind"></a><a name="reversefind"></a>Cstringt::ReverseFind

Pesquisa `CStringT` este objeto para a última partida de um personagem.

```
int ReverseFind(XCHAR ch) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ch*<br/>
O personagem para procurar.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do `CStringT` último caractere neste objeto que corresponde ao caractere solicitado, ou -1 se o caractere não for encontrado.

### <a name="remarks"></a>Comentários

A função é semelhante à `strrchr`função tempo de execução .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#130](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_34.cpp)]

## <a name="cstringtright"></a><a name="right"></a>Cstringt::Direito

Extrai os últimos caracteres *nCount* (ou `CStringT` seja, mais à direita) deste objeto e retorna uma cópia da substringextraída.

```
CStringT Right(int nCount) const;
```

### <a name="parameters"></a>Parâmetros

*Ncount*<br/>
O número de caracteres para extrair desse objeto `CStringT`.

### <a name="return-value"></a>Valor retornado

Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o `CStringT` objeto retornado pode estar vazio.

### <a name="remarks"></a>Comentários

Se *nCount* exceder o comprimento da seqüência, então toda a seqüência será extraída. `Right`é semelhante à `Right` função Basic (exceto que os índices no Básico são baseados em zero).

Para conjuntos de caracteres multibytes (MBCS), *nCount* refere-se a cada caractere de 8 bits; ou seja, um byte de chumbo e trilha em um caractere multibyte são contados como dois caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#131](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_35.cpp)]

## <a name="cstringtsetsysstring"></a><a name="setsysstring"></a>CStringT::SetSysString

Realoca o BSTR apontado por *pbstr* e copia `CStringT` o conteúdo do objeto nele, incluindo o caractere NULL.

```
BSTR SetSysString(BSTR* pbstr) const;
```

### <a name="parameters"></a>Parâmetros

*Pbstr*<br/>
Um ponteiro para uma seqüência de caracteres.

### <a name="return-value"></a>Valor retornado

A nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Dependendo do conteúdo `CStringT` do objeto, o valor do BSTR referenciado pelo *pbstr* pode mudar. A função `CMemoryException` lança uma memória se insuficiente existe.

Esta função é normalmente usada para alterar o valor das strings passadas por referência para Automação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#132](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_36.cpp)]

## <a name="cstringtspanexcluding"></a><a name="spanexcluding"></a>CStringT::SpanExcluding

Extrai caracteres da seqüência, começando pelo primeiro caractere, que não estão no conjunto de caracteres identificados por *pszCharSet*.

```
CStringT SpanExcluding(PCXSTR pszCharSet) const;
```

### <a name="parameters"></a>Parâmetros

*Pszcharset*<br/>
Uma seqüência interpretada como um conjunto de caracteres.

### <a name="return-value"></a>Valor retornado

Uma substring que contém caracteres na seqüência que não estão no *pszCharSet*, começando com o primeiro caractere na seqüência e terminando com o primeiro caractere encontrado na seqüência que também está em *pszCharSet* (ou seja, começando com o primeiro caractere na seqüência e até, mas excluindo o primeiro caractere na seqüência que é encontrado *pszCharSet*). Ele retorna toda a seqüência se nenhum caractere em *pszCharSet for* encontrado na seqüência.

### <a name="remarks"></a>Comentários

`SpanExcluding`extrai e retorna todos os caracteres que precedem a primeira ocorrência de um personagem de *pszCharSet* (em outras palavras, o personagem de *pszCharSet* e todos os caracteres que o seguem na seqüência, não são devolvidos). Se nenhum caractere de *pszCharSet* for `SpanExcluding` encontrado na seqüência, então retorne toda a seqüência.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#133](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_37.cpp)]

## <a name="cstringtspanincluding"></a><a name="spanincluding"></a>Cstringt::SpanIncludingndo

Extrai caracteres da seqüência, começando pelo primeiro caractere, que estão no conjunto de caracteres identificados por *pszCharSet*.

```
CStringT SpanIncluding(PCXSTR pszCharSet) const;
```

### <a name="parameters"></a>Parâmetros

*Pszcharset*<br/>
Uma seqüência interpretada como um conjunto de caracteres.

### <a name="return-value"></a>Valor retornado

Uma substring que contém caracteres na seqüência que estão em *pszCharSet*, começando com o primeiro caractere na seqüência e terminando quando um caractere é encontrado na seqüência que não está em *pszCharSet*. `SpanIncluding`retorna uma substring vazia se o primeiro caractere da seqüência não estiver no conjunto especificado.

### <a name="remarks"></a>Comentários

Se o primeiro caractere da seqüência não `SpanIncluding` estiver no conjunto de caracteres, então retorna uma seqüência vazia. Caso contrário, ele retorna uma sequência de caracteres consecutivos que estão no conjunto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#134](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_38.cpp)]

## <a name="cstringttokenize"></a><a name="tokenize"></a>CStringT::Tokenize

Encontra o próximo token em uma seqüência de destino

```
CStringT Tokenize(PCXSTR pszTokens, int& iStart) const;
```

### <a name="parameters"></a>Parâmetros

*pszTokens*<br/>
Uma seqüência contendo delimitadores de tokens. A ordem desses delimitadores não é importante.

*Istart*<br/>
O índice baseado em zero para iniciar a pesquisa.

### <a name="return-value"></a>Valor retornado

Um `CStringT` objeto contendo o valor de token atual.

### <a name="remarks"></a>Comentários

A `Tokenize` função encontra o próximo token na seqüência de destino. O conjunto de caracteres em *pszTokens* especifica possíveis delimitadores do token a ser encontrado. Em cada `Tokenize` chamada para a função começa no *iStart,* pula `CStringT` os principais delimitadores e retorna um objeto contendo o token atual, que é a seqüência de caracteres até o próximo caractere delimitador. O valor do *iStart* é atualizado para ser a posição seguinte ao caractere delimitador final, ou -1 se o final da string foi atingido. Mais tokens podem ser quebrados do restante da seqüência de destino por uma série de chamadas para `Tokenize`, usando *iStart* para manter o controle de onde na seqüência o próximo token deve ser lido. Quando não houver mais tokens, a função retornará uma seqüência de string vazia e *o iStart* será definido como -1.

Ao contrário do TOKENto crt funções como [strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l](../../c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l.md), `Tokenize` não modifica a seqüência de destino.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#135](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_39.cpp)]

### <a name="remarks"></a>Comentários

A saída deste exemplo é a seguinte:

```Output
Resulting Token: First
Resulting Token: Second
Resulting Token: Third
```

## <a name="cstringttrim"></a><a name="trim"></a>Cstringt::Trim

Apara caracteres principais e arrastando da seqüência.

```
CStringT& Trim(XCHAR chTarget);
CStringT& Trim(PCXSTR pszTargets);
CStringT& Trim();
```

### <a name="parameters"></a>Parâmetros

*chTarget*<br/>
O personagem alvo a ser aparado.

*pszTargets*<br/>
Um ponteiro para uma seqüência contendo os caracteres-alvo a serem aparados. Todas as ocorrências principais e de soviantes `CStringT` de caracteres *no pszTarget* serão aparadas do objeto.

### <a name="return-value"></a>Valor retornado

Devolve a corda aparada.

### <a name="remarks"></a>Comentários

Remove todas as ocorrências principais e de sossecção de uma das seguintes ocorrências:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na seqüência especificado por *pszTargets*.

- Whitespace.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#136](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_40.cpp)]

### <a name="remarks"></a>Comentários

A saída deste exemplo é a seguinte:

```Output
Before: "******Soccer is best, but liquor is quicker!!!!!"
After : "Soccer is best, but liquor is quicker"
```

## <a name="cstringttrimleft"></a><a name="trimleft"></a>Cstringt::TrimLeft

Apara os caracteres principais da seqüência.

```
CStringT& TrimLeft(XCHAR chTarget);
CStringT& TrimLeft(PCXSTR pszTargets);
CStringT& TrimLeft();
```

### <a name="parameters"></a>Parâmetros

*chTarget*<br/>
O personagem alvo a ser aparado.

*pszTargets*<br/>
Um ponteiro para uma seqüência contendo os caracteres-alvo a serem aparados. Todas as principais ocorrências de caracteres no `CStringT` *pszTarget* serão aparadas do objeto.

### <a name="return-value"></a>Valor retornado

A seqüência aparada resultante.

### <a name="remarks"></a>Comentários

Remove todas as ocorrências principais e de sossecção de uma das seguintes ocorrências:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na seqüência especificado por *pszTargets*.

- Whitespace.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#137](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_41.cpp)]

## <a name="cstringttrimright"></a><a name="trimright"></a>Cstringt::TrimRight

Apara caracteres de arrasto da seqüência.

```
CStringT& TrimRight(XCHAR chTarget);
CStringT& TrimRight(PCXSTR pszTargets);
CStringT& TrimRight();
```

### <a name="parameters"></a>Parâmetros

*chTarget*<br/>
O personagem alvo a ser aparado.

*pszTargets*<br/>
Um ponteiro para uma seqüência contendo os caracteres-alvo a serem aparados. Todas as ocorrências de personagens em *pszTarget* serão aparadas do `CStringT` objeto.

### <a name="return-value"></a>Valor retornado

Retorna `CStringT` o objeto que contém a corda aparada.

### <a name="remarks"></a>Comentários

Remove ocorrências de uma das seguintes ocorrências:

- O caractere especificado por *chTarget*.

- Todos os caracteres encontrados na seqüência especificado por *pszTargets*.

- Whitespace.

A `CStringT& TrimRight(XCHAR chTarget)` versão aceita um parâmetro de caractere e remove todas `CStringT` as cópias desse caractere do final dos dados de seqüência. Começa a partir do final da corda e trabalha em direção à frente. Ele pára quando encontra um `CSTringT` caractere diferente ou quando fica sem dados de caracteres.

A `CStringT& TrimRight(PCXSTR pszTargets)` versão aceita uma seqüência de caracteres com término nulo que contém todos os diferentes caracteres para procurar. Ele remove todas as cópias `CStringT` desses caracteres no objeto. Começa no final da corda e trabalha em direção à frente. Ele pára quando encontra um caractere que não está `CStringT` na seqüência de destino, ou quando fica sem dados de caracteres. Ele não tenta combinar toda a seqüência de `CStringT`alvo com uma substring no final de .

A `CStringT& TrimRight()` versão não requer parâmetros. Ele apara qualquer caractere de espaço branco `CStringT` do final da seqüência. Os caracteres whitespace podem ser quebras de linha, espaços ou guias.

-

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#138](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_42.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)<br/>
[Classe CsimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)
