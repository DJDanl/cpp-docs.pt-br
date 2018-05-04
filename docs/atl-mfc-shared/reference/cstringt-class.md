---
title: Classe CStringT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], in ATL
- shared classes, CStringT
- CStringT class
ms.assetid: 7cacc59c-425f-40f1-8f5b-6db921318ec9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f8a66f87b3c4a2c6712a1db93f97361a25b6955
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cstringt-class"></a>Classe CStringT
Essa classe representa um `CStringT` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
template<typename BaseType, class StringTraits>  
class CStringT :   
public CSimpleStringT<BaseType,
                      _CSTRING_IMPL_::_MFCDLLTraitsCheck<BaseType, StringTraits>
                      ::c_bIsMFCDLLTraits>  
 
```  
  
#### <a name="parameters"></a>Parâmetros  
 `BaseType`  
 O tipo de caractere da classe string. Pode ser um dos seguintes:  
  
- `char` (para cadeias de caracteres ANSI).  
  
- `wchar_t` (para cadeias de caracteres Unicode).  
  
- **TCHAR** (para cadeias de caracteres ANSI e Unicode).  
  
 `StringTraits`  
 Determina se a classe de cadeia de caracteres precisa de suporte à biblioteca de tempo de execução do C (CRT) e onde se encontram os recursos de cadeia de caracteres. Pode ser um dos seguintes:  
  
- **StrTraitATL < wchar_t** &#124; `char` &#124; **TCHAR, ChTraitsCRT < wchar_t** &#124; `char` &#124; **TCHAR >>**  
  
     A classe requer suporte do CRT e pesquisas para cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).  
  
- **StrTraitATL < wchar_t** &#124; `char` &#124; **TCHAR, ChTraitsOS < wchar_t** &#124; `char` &#124; **TCHAR >>**  
  
     A classe não requer suporte do CRT e pesquisas para cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` (um membro da classe de módulo do aplicativo).  
  
- **StrTraitMFC < wchar_t** &#124; `char` &#124; **TCHAR, ChTraitsCRT < wchar_t** &#124; `char` &#124; **TCHAR >>**  
  
     A classe requer suporte do CRT e procura por cadeias de caracteres de recurso usando o algoritmo de pesquisa padrão do MFC.  
  
- **StrTraitMFC < wchar_t** &#124; `char` &#124; **TCHAR, ChTraitsOS < wchar_t** &#124; `char` &#124; **TCHAR >>**  
  
     A classe não requer suporte do CRT e procura por cadeias de caracteres de recurso usando o algoritmo de pesquisa padrão do MFC.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringT::CStringT](#cstringt)|Constrói uma `CStringT` objeto de várias maneiras.|  
|[CStringT:: ~ CStringT](#_dtorcstringt)|Destrói um objeto `CStringT`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringT::AllocSysString](#allocsysstring)|Aloca um `BSTR` de `CStringT` dados.|  
|[CStringT::AnsiToOem](#ansitooem)|Faz uma conversão in-loco do conjunto de caracteres ANSI para o conjunto de caracteres OEM.|  
|[CStringT::AppendFormat](#appendformat)|Acrescenta dados formatados um existente `CStringT` objeto.|  
|[CStringT::Collate](#collate)|Compara duas cadeias de caracteres (maiusculas e minúsculas, usa informações de específicas de localidade).|  
|[CStringT::CollateNoCase](#collatenocase)|Compara duas cadeias de caracteres (diferencia maiusculas de minúsculas, usa informações de específicas de localidade).|  
|[CStringT::Compare](#compare)|Compara duas cadeias de caracteres (com distinção entre maiusculas e minúsculas).|  
|[CStringT::CompareNoCase](#comparenocase)|Compara duas cadeias de caracteres (não diferencia maiusculas de minúsculas).|  
|[CStringT::Delete](#delete)|Exclui um ou mais caracteres de uma cadeia de caracteres.|  
|[CStringT::Find](#find)|Localiza um caractere ou uma subcadeia de caracteres dentro de uma cadeia de caracteres maior.|  
|[CStringT::FindOneOf](#findoneof)|Localiza o primeiro caractere correspondente de um conjunto.|  
|[CStringT::Format](#format)|Formatos de cadeia de caracteres como `sprintf` does.|  
|[CStringT::FormatMessage](#formatmessage)|Formata uma cadeia de caracteres de mensagem.|  
|[CStringT::FormatMessageV](#formatmessagev)|Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variável.|  
|[CStringT::FormatV](#formatv)|Formatos de cadeia de caracteres usando uma lista de argumentos de variável.|  
|[CStringT::GetEnvironmentVariable](#getenvironmentvariable)|Define a cadeia de caracteres para o valor da variável de ambiente especificado.|  
|[CStringT::Insert](#insert)|Insere um único caractere ou uma subcadeia de caracteres no índice especificado na cadeia de caracteres.|  
|[CStringT::Left](#left)|Extrai a parte esquerda de uma cadeia de caracteres.|  
|[CStringT::LoadString](#loadstring)|Carrega um existente `CStringT` objeto a partir de um recurso do Windows.|  
|[CStringT::MakeLower](#makelower)|Converte todos os caracteres na cadeia de caracteres para caracteres minúsculos.|  
|[CStringT::MakeReverse](#makereverse)|Inverte a cadeia de caracteres.|  
|[CStringT::MakeUpper](#makeupper)|Converte todos os caracteres na cadeia de caracteres para caracteres maiusculos.|  
|[CStringT::Mid](#mid)|Extrai a parte do meio de uma cadeia de caracteres.|  
|[CStringT::OemToAnsi](#oemtoansi)|Faz uma conversão in-loco do conjunto para o conjunto de caracteres ANSI de caracteres OEM.|  
|[CStringT::Remove](#remove)|Remove indicado caracteres de uma cadeia de caracteres.|  
|[CStringT::Replace](#replace)|Substitui o indicado caracteres com outros caracteres.|  
|[CStringT::ReverseFind](#reversefind)|Localiza um caractere dentro de uma cadeia de caracteres maior; partir do final.|  
|[CStringT::Right](#right)|Extrai a parte direita de uma cadeia de caracteres.|  
|[CStringT::SetSysString](#setsysstring)|Define uma existente `BSTR` objeto com dados de um `CStringT` objeto.|  
|[CStringT::SpanExcluding](#spanexcluding)|Extrai os caracteres de cadeia de caracteres, começando com o primeiro caractere que não estão no conjunto de caracteres identificada pelo `pszCharSet`.|  
|[CStringT::SpanIncluding](#spanincluding)|Extrai uma subcadeia de caracteres que contém apenas os caracteres em um conjunto.|  
|[CStringT::Tokenize](#tokenize)|Extrai especificado tokens em uma cadeia de caracteres de destino.|  
|[CStringT::Trim](#trim)|Remove todos os caracteres de espaço em branco à esquerda e à direita da cadeia de caracteres.|  
|[CStringT::TrimLeft](#trimleft)|Corta os caracteres de espaço em branco da cadeia de.|  
|[CStringT::TrimRight](#trimright)|Corta caracteres de espaço em branco na cadeia de caracteres à direita.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](#operator_eq)|Atribui um novo valor para uma `CStringT` objeto.|  
|[CStringT::operator +](#operator_add)|Concatena duas cadeias de caracteres ou um caractere e uma cadeia de caracteres.|  
|[+ CStringT::operator =](#operator_add_eq)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|  
|[CStringT::operator = =](#operator_eq_eq)|Determina se duas cadeias de caracteres são logicamente iguais.|  
|[CStringT::operator! =](#operator_neq)|Determina se duas cadeias de caracteres logicamente não são iguais.|  
|[CStringT::operator &lt;](#operator_lt)|Determina se a cadeia de caracteres à esquerda do operador é menor que a cadeia de caracteres à direita.|  
|[CStringT::operator &gt;](#operator_gt)|Determina se a cadeia de caracteres à esquerda do operador é maior que a cadeia de caracteres à direita.|  
|[CStringT::operator &lt;=](#operator_lt_eq)|Determina se a cadeia de caracteres à esquerda do operador é menor ou igual à cadeia de caracteres à direita.|  
|[CStringT::operator &gt;=](#operator_gt_eq)|Determina se a cadeia de caracteres à esquerda do operador é maior que ou igual à cadeia de caracteres à direita.|  
  
## <a name="remarks"></a>Comentários  
 `CStringT` herda de [CSimpleStringT classe](../../atl-mfc-shared/reference/csimplestringt-class.md). Recursos avançados, como a manipulação de caracteres, ordenação e pesquisa, são implementados por `CStringT`.  
  
> [!NOTE]
> `CStringT` objetos são capazes de gerar exceções. Isso ocorre quando uma `CStringT` objeto é executado sem memória por qualquer motivo.  
  
 Um `CStringT` objeto consiste em uma sequência de caracteres de comprimento variável. `CStringT` fornece funções e operadores usando uma sintaxe semelhante do Basic. Concatenação e operadores de comparação, gerenciamento de memória simplificado, verifique `CStringT` objetos mais fácil de usar que matrizes de caracteres comum.  
  
> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm inseridos caracteres nulos, é recomendável em relação a ela. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados inesperados.  
  
 Usando combinações diferentes de `BaseType` e `StringTraits` parâmetros, `CStringT` objetos pode chegar nos seguintes tipos, que é predefinido pelas bibliotecas do ATL.  
  
 Se estiver usando em um aplicativo ATL:  
  
 `CString`, `CStringA`, e `CStringW` são exportados a DLL do MFC (MFC90. DLL), nunca a partir de DLLs do usuário. Isso é feito para evitar `CStringT` do que está sendo definido várias vezes.  
  
> [!NOTE]
>  Se o seu código contém a solução alternativa para erros de vinculador descrito [Linking Errors When You Import CString-Derived Classes "(Q309801)](https://support.microsoft.com/help/309801/you-may-receive-an-lnk2019-error-message-when-you-build-a-visual-c-200), você deve remover esse código. Ele não é mais necessário.  
  
 Os tipos de cadeia de caracteres a seguir estão disponíveis em aplicativos MFC:  
  
|Tipo de CStringT|Declaração|  
|-------------------|-----------------|  
|`CStringA`|Um caractere ANSI tipo cadeia de caracteres com suporte do CRT.|  
|`CStringW`|Um caractere Unicode de tipo cadeia de caracteres com suporte do CRT.|  
|`CString`|Tipos de caracteres ANSI e Unicode com suporte do CRT.|  
  
 A seguinte cadeia de tipos estão disponíveis em projetos onde **ATL_CSTRING_NO_CRT** está definido:  
  
|Tipo de CStringT|Declaração|  
|-------------------|-----------------|  
|**CAtlStringA**|Um caractere ANSI tipo cadeia de caracteres sem suporte do CRT.|  
|**CAtlStringW**|Um caractere Unicode de tipo cadeia de caracteres sem suporte do CRT.|  
|**CAtlString**|Tipos de caracteres ANSI e Unicode sem suporte do CRT.|  
  
 A seguinte cadeia de tipos estão disponíveis em projetos onde **ATL_CSTRING_NO_CRT** não está definido:  
  
|Tipo de CStringT|Declaração|  
|-------------------|-----------------|  
|**CAtlStringA**|Um caractere ANSI tipo cadeia de caracteres com suporte do CRT.|  
|**CAtlStringW**|Um caractere Unicode de tipo cadeia de caracteres com suporte do CRT.|  
|**CAtlString**|Tipos de caracteres ANSI e Unicode com suporte do CRT.|  
  
 `CString` objetos também têm as seguintes características:  
  
- `CStringT` objetos podem crescer como resultado de operações de concatenação.  
  
- `CStringT` objetos seguem "semântica de valor". Imagine um `CStringT` objeto como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.  
  
-   Você pode substituir livremente `CStringT` objetos para `PCXSTR` argumentos de função.  
  
-   Gerenciamento de memória personalizados para buffers de cadeia de caracteres. Para obter mais informações, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
## <a name="cstringt-predefined-types"></a>CStringT predefinidos de tipos  
 Porque `CStringT` usa um argumento de template para definir o tipo de caractere (ou [wchar_t](../../c-runtime-library/standard-types.md) ou [char](../../c-runtime-library/standard-types.md)) com suporte, tipos de parâmetro do método podem ser complicados às vezes. Para simplificar esse problema, um conjunto de tipos predefinidos é definido e usado em todo o `CStringT` classe. A tabela a seguir lista os vários tipos:  
  
|Nome|Descrição|  
|----------|-----------------|  
|`XCHAR`|Um único caractere (o `wchar_t` ou `char`) com o mesmo tipo de caractere como o `CStringT` objeto.|  
|**YCHAR**|Um único caractere (o `wchar_t` ou `char`) com o tipo de caractere oposta a `CStringT` objeto.|  
|`PXSTR`|Um ponteiro para uma cadeia de caracteres (o `wchar_t` ou `char`) com o mesmo tipo de caractere como o `CStringT` objeto.|  
|**PYSTR**|Um ponteiro para uma cadeia de caracteres (o `wchar_t` ou `char`) com o tipo de caractere oposta a `CStringT` objeto.|  
|`PCXSTR`|Um ponteiro para um **const** cadeia de caracteres (o `wchar_t` ou `char`) com o mesmo tipo de caractere como o `CStringT` objeto.|  
|**PCYSTR**|Um ponteiro para um **const** cadeia de caracteres (o `wchar_t` ou `char`) com o tipo de caractere oposta a `CStringT` objeto.|  
  
> [!NOTE]
>  Código que usou anteriormente não documentados métodos de `CString` (como **AssignCopy**) deve ser substituído pelo código que usa os seguintes métodos documentados do `CStringT` (como `GetBuffer` ou `ReleaseBuffer`). Esses métodos são herdados de `CSimpleStringT`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)  
  
 `CStringT`  
  
## <a name="requirements"></a>Requisitos  
  
|Cabeçalho|Use para|  
|------------|-------------|  
|cstringt.h|Objetos de cadeia de caracteres somente do MFC|  
|atlstr.h|Objetos de cadeia de caracteres não-MFC|  
  
##  <a name="allocsysstring"></a>  CStringT::AllocSysString  
 Aloca uma cadeia de caracteres compatíveis com a automação do tipo `BSTR` e copia o conteúdo do `CStringT` objeto, incluindo o caractere null de terminação.  
  
```  
BSTR AllocSysString() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres alocada recentemente.  
  
### <a name="remarks"></a>Comentários  
 Em programas MFC, um [CMemoryException classe](../../mfc/reference/cmemoryexception-class.md) será lançada se existe memória suficiente. Em programas ATL, um [CAtlException](../../atl/reference/catlexception-class.md) é gerada. Essa função é normalmente usada para retornar cadeias de caracteres para automação.  
  

 Normalmente, se essa cadeia de caracteres é passada para uma função COM como um parâmetro, e isso exige que o chamador liberar a cadeia de caracteres. Isso pode ser feito usando [SysFreeString](https://msdn.microsoft.com/library/windows/desktop/ms221481.aspx), conforme descrito no SDK do Windows. Para obter mais informações, consulte [Allocating e liberando memória para um BSTR](../../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md).  
  
 Para obter mais informações sobre funções de alocação OLE no Windows, consulte [SysAllocString](https://msdn.microsoft.com/library/windows/desktop/ms221458.aspx) no SDK do Windows.  

  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CStringT::AllocSysString`.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#105](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_1.cpp)]  
  
##  <a name="ansitooem"></a>  CStringT::AnsiToOem  
 Converte todos os caracteres neste `CStringT` objeto do conjunto para o conjunto de caracteres OEM de caracteres ANSI.  
  
```  
void AnsiToOem();
```  
  
### <a name="remarks"></a>Comentários  
 A função não está disponível se `_UNICODE` está definido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#106](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_2.cpp)]  
  
##  <a name="appendformat"></a>  CStringT::AppendFormat  
 Acrescenta dados formatados um existente `CStringT` objeto.  
  
```  
void __cdecl AppendFormat(PCXSTR pszFormat, [, argument] ...);
void __cdecl AppendFormat(UINT nFormatID, [, argument] ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszFormat`  
 Uma cadeia de caracteres de controle de formato.  
  
 `nFormatID`  
 O identificador do recurso de cadeia de caracteres que contém a cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
### <a name="remarks"></a>Comentários  
 Essa função formata e acrescenta uma série de caracteres e valores de `CStringT`. Cada argumento opcional (se houver) é convertido e anexado de acordo com a especificação de formato correspondente em `pszFormat` ou do recurso de cadeia de caracteres identificada pelo `nFormatID`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#107](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_3.cpp)]  
  
##  <a name="collate"></a>  CStringT::Collate  
 Compara duas cadeias de caracteres usando a função de texto genérico `_tcscoll`.  
  
```  
int Collate(PCXSTR psz) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A outra cadeia de caracteres usada para comparação.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres forem idênticas, < 0 se isso `CStringT` objeto é menor que `psz`, ou > 0 se isso `CStringT` objeto é maior que `psz`.  
  
### <a name="remarks"></a>Comentários  
 A função de texto genérico `_tcscoll`, que é definido em TCHAR. H, mapeia para o `strcoll`, `wcscoll`, ou `_mbscoll`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação diferencia maiusculas de minúsculas das cadeias de caracteres de acordo com a página de código atualmente em uso. Para obter mais informações, consulte [strcoll, wcscoll, mbscoll, strcoll_l, wcscoll_l, _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).  
  
##  <a name="collatenocase"></a>  CStringT::CollateNoCase  
 Compara duas cadeias de caracteres usando a função de texto genérico `_tcscoll`.  
  
```  
int CollateNoCase(PCXSTR psz) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A outra cadeia de caracteres usada para comparação.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres são idênticas (ignora maiusculas/minúsculas), < 0 se isso `CStringT` objeto é menor que `psz` (ignorando maiusculas e minúsculas), ou > 0 se isso `CStringT` objeto é maior do que `psz` (ignorando maiusculas e minúsculas).  
  
### <a name="remarks"></a>Comentários  
 A função de texto genérico `_tcscoll`, que é definido em TCHAR. H, mapeia para o `stricoll`, `wcsicoll`, ou `_mbsicoll`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação de maiusculas e minúsculas de cadeias de caracteres, de acordo com a página de código em uso no momento. Para obter mais informações, consulte [strcoll, wcscoll, mbscoll, strcoll_l, wcscoll_l, _mbscoll_l](../../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#109](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_4.cpp)]  
  
##  <a name="compare"></a>  CStringT::Compare  
 Compara duas cadeias de caracteres (com distinção entre maiusculas e minúsculas).  
  
```  
int Compare(PCXSTR psz) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A outra cadeia de caracteres usada para comparação.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres forem idênticas, < 0 se isso `CStringT` objeto é menor que `psz`, ou > 0 se isso `CStringT` objeto é maior que `psz`.  
  
### <a name="remarks"></a>Comentários  
 A função de texto genérico `_tcscmp`, que é definido em TCHAR. H, mapeia para o `strcmp`, `wcscmp`, ou `_mbscmp`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação diferencia maiusculas de minúsculas das cadeias de caracteres e não é afetada pela localidade. Para obter mais informações, consulte [strcmp wcscmp, mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md).  
  
 Se a cadeia de caracteres contém nulos inseridos, para fins de comparação de cadeia de caracteres é considerada seja truncado no primeiro caractere nulo inserido.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CStringT::Compare`.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#110](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_5.cpp)]  
  
##  <a name="comparenocase"></a>  CStringT::CompareNoCase  
 Compara duas cadeias de caracteres (não diferencia maiusculas de minúsculas).  
  
```  
int CompareNoCase(PCXSTR psz) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `psz`  
 A outra cadeia de caracteres usada para comparação.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres são idênticas (ignorando maiusculas e minúsculas), < 0 se isso `CStringT` objeto é menor que `psz` (ignorando maiusculas e minúsculas), ou > 0 se isso `CStringT` objeto é maior do que `psz` (ignorando maiusculas e minúsculas).  
  
### <a name="remarks"></a>Comentários  
 A função de texto genérico `_tcsicmp`, que é definido em TCHAR. H, mapeia para o `_stricmp`, `_wcsicmp` ou `_mbsicmp`, dependendo do conjunto de caracteres que é definido em tempo de compilação. Cada função executa uma comparação das cadeias de caracteres de maiusculas e minúsculas. A comparação depende de `LC_CTYPE` aspecto da localidade, mas não `LC_COLLATE`. Para obter mais informações, consulte [stricmp, wcsicmp, mbsicmp, stricmp_l, wcsicmp_l, mbsicmp_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md).  
  
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
 `pch`  
 Um ponteiro para uma matriz de caracteres de comprimento `nLength`, não terminada em nulo.  
  
 `nLength`  
 Uma contagem do número de caracteres em `pch`.  
  
 `ch`  
 Um único caractere.  
  
 `pszSrc`  
 Uma cadeia de caracteres terminada em nulo a serem copiados nisso `CStringT` objeto.  
  
 `pStringMgr`  
 Um ponteiro para o Gerenciador de memória para o `CStringT` objeto. Para obter mais informações sobre `IAtlStringMgr` e gerenciamento de memória para `CStringT`, consulte [gerenciamento de memória com CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
 `strSrc`  
 Um existente `CStringT` objeto sejam copiados para este `CStringT` objeto. Para obter mais informações sobre `CThisString` e `CThisSimpleString`, consulte a seção comentários.  
  
 `varSrc`  
 Um objeto variante sejam copiados para este `CStringT` objeto.  
  
 `BaseType`  
 O tipo de caractere da classe string. Pode ser um dos seguintes:  
  
 `char` (para cadeias de caracteres ANSI).  
  
 `wchar_t` (para cadeias de caracteres Unicode).  
  
 `TCHAR` (ANSI e Unicode cadeias de caracteres).  
  
 `bMFCDLL`  
 Valor booleano que especifica se o projeto é uma DLL do MFC (TRUE) ou não (FALSE).  
  
 `SystemString`  
 Deve ser `System::String`, e o projeto deve ser compilado com /clr.  
  
 `pString`  
 Um identificador para um `CStringT` objeto.  
  
### <a name="remarks"></a>Comentários  
 Porque os construtores copiar os dados de entrada para o novo armazenamento alocado, você deve estar ciente que as exceções podem resultar de memória. Observe que alguns desses construtores atuam como funções de conversão. Isso permite a substituição, por exemplo, um `LPTSTR` onde um `CStringT` objeto é esperado.  
  
- `CStringT`( `LPCSTR` `lpsz` ): Constrói um Unicode `CStringT` de uma cadeia de caracteres ANSI. Você também pode usar esse construtor para carregar um recurso de cadeia de caracteres, conforme mostrado no exemplo a seguir.  
  
- `CStringT(` `LPCWSTR` `lpsz` ): Constrói um `CStringT` de uma cadeia de caracteres Unicode.  
  
- `CStringT`( `const unsigned char*` `psz` ): Permite que você construa uma `CStringT` de um ponteiro para `unsigned char`.  
  
> [!NOTE]
>  Definir o **_CSTRING_DISABLE_NARROW_WIDE_CONVERSION** macro para desativar a conversão implícita de cadeia de caracteres entre [!INCLUDE[vcpransi](../../atl-mfc-shared/reference/includes/vcpransi_md.md)] e [!INCLUDE[TLA#tla_unicode](../../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)] cadeias de caracteres. Exclui a macro de construtores de compilação que oferecem suporte à conversão.  
  
 Observe que o `strSrc` parâmetro pode ser um `CStringT` ou `CThisSimpleString` objeto. Para `CStringT`, use um dos seus instanciações padrão ( `CString`, `CStringA`, ou `CStringW`); para `CThisSimpleString`, use um `this` ponteiro. `CThisSimpleString` declara uma instância do [CSimpleStringT classe](../../atl-mfc-shared/reference/csimplestringt-class.md), que é uma classe menor de cadeia de caracteres com menos funcionalidade que o `CStringT` classe.  
  
 O operador de sobrecarga `CSimpleStringT<>&()` constrói um `CStringT` de objeto um `CSimpleStringT` declaração.  
  
> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm inseridos caracteres nulos, é recomendável em relação a ela. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados inesperados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#112](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_7.cpp)]  
  
##  <a name="_dtorcstringt"></a>  CStringT:: ~ CStringT  
 Destrói a `CStringT` objeto.  
  
```  
~CStringT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Destrói a `CStringT` objeto.  
  
##  <a name="delete"></a>  CStringT::Delete  
 Exclui um ou mais caracteres de uma cadeia de caracteres começando com o caractere no índice especificado.  
  
```  
int Delete(int iIndex, int nCount = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iIndex`  
 O índice de base zero do primeiro caractere a `CStringT` objeto a ser excluído.  
  
 `nCount`  
 O número de caracteres a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres alterado.  
  
### <a name="remarks"></a>Comentários  
 Se `nCount` é maior do que a cadeia de caracteres, o restante da cadeia de caracteres será removida.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#113](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_8.cpp)]  
  
```Output  
Before: Soccer is best,
    but hockey is quicker!  
After: Soccer best,
    but hockey is quicker!  
```  
  
##  <a name="find"></a>  CStringT::Find  
 Procura essa cadeia de caracteres da primeira correspondência de um caractere ou uma subcadeia de caracteres.  
  
```  
int Find(PCXSTR pszSub, int iStart=0) const throw();
int Find(XCHAR ch, int iStart=0) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszSub`  
 Uma subcadeia de caracteres a ser pesquisado.  
  
 `iStart`  
 O índice do caractere na cadeia de caracteres para iniciar a pesquisa com, ou 0 para desde o início.  
  
 `ch`  
 Um único caractere a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do primeiro caractere na `CStringT` objeto que corresponda a subcadeia de caracteres solicitada ou caracteres; -1 se a subcadeia de caracteres ou o caractere não for encontrado.  
  
### <a name="remarks"></a>Comentários  
 A função está sobrecarregada para aceitar os dois caracteres únicos (semelhante à função tempo de execução `strchr`) e cadeias de caracteres (como `strstr`).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#114](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_9.cpp)]  
  
##  <a name="findoneof"></a>  CStringT::FindOneOf  
 Procura essa cadeia de caracteres para o primeiro caractere que corresponde a qualquer caractere contido em `pszCharSet`.  
  
```  
int FindOneOf(PCXSTR pszCharSet) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszCharSet`  
 Cadeia de caracteres que contém caracteres para correspondência.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do primeiro caractere na cadeia de caracteres que também está na `pszCharSet`; -1 se não houver nenhuma correspondência.  
  
### <a name="remarks"></a>Comentários  
 Localiza a primeira ocorrência de qualquer um dos caracteres na `pszCharSet`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#115](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_10.cpp)]  
  
##  <a name="format"></a>  CStringT::Format  
 Gravações formatado dados para um `CStringT` da mesma forma que [sprintf_s](../../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md) formata dados em uma matriz de caracteres de estilo C.  
  
```  
void __cdecl Format(UINT nFormatID, [, argument]...);
void __cdecl Format(PCXSTR pszFormat,  [, argument] ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFormatID`  
 O identificador do recurso de cadeia de caracteres que contém a cadeia de caracteres de controle de formato.  
  
 `pszFormat`  
 Uma cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
### <a name="remarks"></a>Comentários  
 Essa função formata e armazena uma série de caracteres e valores de `CStringT`. Cada argumento opcional (se houver) é convertido e de saída de acordo com a especificação de formato correspondente em `pszFormat` ou do recurso de cadeia de caracteres identificada pelo `nFormatID`.  
  
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
 `nFormatID`  
 O identificador de recurso de cadeia de caracteres que contém o texto sem formatação.  
  
 `pszFormat`  
 Aponta para a cadeia de caracteres de controle de formato. Ele será examinado em busca de inserções e formatado adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`-estilo de cadeias de caracteres de formato, exceto que ele permite que os parâmetros a serem inseridos em uma ordem arbitrária.  
  
 `argument`  
 Argumentos opcionais.  
  
### <a name="remarks"></a>Comentários  
 A função requer uma definição de mensagem como entrada. A definição de mensagem é determinada pelo `pszFormat` ou do recurso de cadeia de caracteres identificada pelo `nFormatID`. A função copia o texto de mensagem formatada para o `CStringT` objeto, o processamento de um inserido insere sequências se solicitado.  
  
> [!NOTE]
> `FormatMessage` tenta alocar memória do sistema para a cadeia de caracteres formatada recentemente. Se essa tentativa falhar, uma exceção de memória é gerada automaticamente.  
  
 Cada inserção deve ter um parâmetro posterior correspondente a `pszFormat` ou `nFormatID` parâmetro. Dentro do texto da mensagem, várias sequências de escape têm suporte para formatação dinamicamente a mensagem. Para obter mais informações, consulte o Windows [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351) função no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#118](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_13.cpp)]  
  
##  <a name="formatmessagev"></a>  CStringT::FormatMessageV  
 Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variável.  
  
```  
void FormatMessageV(PCXSTR pszFormat, va_list* pArgList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszFormat`  
 Aponta para a cadeia de caracteres de controle de formato. Ele será examinado em busca de inserções e formatado adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`-estilo de cadeias de caracteres de formato, exceto que ele permite que os parâmetros a serem inseridos em uma ordem arbitrária.  
  
 `pArgList`  
 Ponteiro para uma lista de argumentos.  
  
### <a name="remarks"></a>Comentários  
 A função requer uma definição de mensagem como entrada, determinado pelo `pszFormat`. A função copia o texto da mensagem formatado e uma lista de variável de argumentos para o `CStringT` objeto, o processamento de um inserido insere sequências se solicitado.  
  
> [!NOTE]
> `FormatMessageV` chamadas [CStringT::FormatMessage](#formatmessage), que tenta alocar memória do sistema para a cadeia de caracteres formatada recentemente. Se essa tentativa falhar, uma exceção de memória é gerada automaticamente.  
  
 Para obter mais informações, consulte o Windows [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351) função no SDK do Windows.  
  
##  <a name="formatv"></a>  CStringT::FormatV  
 Formata uma cadeia de caracteres de mensagem usando uma lista de argumentos variável.  
  
```  
void FormatV(PCXSTR pszFormat, va_list args);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszFormat`  
 Aponta para a cadeia de caracteres de controle de formato. Ele será examinado em busca de inserções e formatado adequadamente. A cadeia de caracteres de formato é semelhante à função de tempo de execução `printf`-estilo de cadeias de caracteres de formato, exceto que ele permite que os parâmetros a serem inseridos em uma ordem arbitrária.  
  
 `args`  
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
 `pszVar`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a variável de ambiente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Recupera o valor da variável especificada do bloco de ambiente do processo de chamada. O valor está na forma de uma cadeia de caracteres terminada em nulo de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#121](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_16.cpp)]  
  
##  <a name="insert"></a>  CStringT::Insert  
 Insere um único caractere ou uma subcadeia de caracteres no índice especificado na cadeia de caracteres.  
  
```  
int Insert(int iIndex, PCXSTR psz);
int Insert(int iIndex, XCHAR ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iIndex`  
 O índice do caractere antes do qual será realizada a inserção.  
  
 `psz`  
 Um ponteiro para a subcadeia de caracteres a ser inserido.  
  
 `ch`  
 O caractere a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres alterado.  
  
### <a name="remarks"></a>Comentários  
 O `iIndex` parâmetro identifica o primeiro caractere que será movido para liberar espaço para o caractere ou uma subcadeia de caracteres. Se `nIndex` for zero, a inserção ocorrerá antes que a cadeia de caracteres inteira. Se `nIndex` é maior do que o comprimento da cadeia de caracteres, a função será concatenar a cadeia de caracteres presente e o novo material fornecido pelo `ch` ou `psz`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#122](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_17.cpp)]  
  
##  <a name="left"></a>  CStringT::Left  
 Extrai os caracteres `nCount` do lado extremo esquerdo desse objeto `CStringT` e retorna uma cópia da subcadeia de caracteres extraída.  
  
```  
CStringT Left(int nCount) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCount`  
 O número de caracteres para extrair desse objeto `CStringT`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. O objeto `CStringT` retornado pode estar vazio.  
  
### <a name="remarks"></a>Comentários  
 Se `nCount` exceder o comprimento da cadeia de caracteres, a cadeia de caracteres inteira será extraída. `Left` é semelhante à função `Left` básica.  
  
 Para conjuntos de caracteres de vários bytes (MBCS), `nCount` trata cada sequência de 8 bits como um caractere para que `nCount` retorne o número de caracteres de vários bytes multiplicados por dois.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#123](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_18.cpp)]  
  
##  <a name="loadstring"></a>  CStringT::LoadString  
 Lê um recurso de cadeia de caracteres do Windows, identificado por `nID`, em um existente `CStringT` objeto.  
  
```  
BOOL LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID);
BOOL LoadString(HINSTANCE hInstance, UINT nID);
BOOL LoadString(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 Um identificador para a instância do módulo.  
  
 `nID`  
 Uma ID de recurso de cadeia de caracteres de Windows.  
  
 `wLanguageID`  
 O idioma do recurso de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a carga de recursos foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Carrega o recurso de cadeia de caracteres ( `nID`) do módulo especificado ( `hInstance`) usando o idioma especificado ( `wLanguage`).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#124](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_19.cpp)]  
  
##  <a name="makelower"></a>  CStringT::MakeLower  
 Converte o `CStringT` objeto para uma cadeia de caracteres em minúsculas.  
  
```  
CStringT& MakeLower();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres minúscula resultante.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#125](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_20.cpp)]  
  
##  <a name="makereverse"></a>  CStringT::MakeReverse  
 Inverte a ordem dos caracteres a `CStringT` objeto.  
  
```  
CStringT& MakeReverse();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Resultante revertida a cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#126](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_21.cpp)]  
  
##  <a name="makeupper"></a>  CStringT::MakeUpper  
 Converte o `CStringT` objeto para uma cadeia de caracteres em maiusculas.  
  
```  
CStringT& MakeUpper();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres maiuscula resultante.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#127](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_22.cpp)]  
  
##  <a name="mid"></a>  CStringT::Mid  
 Extrai uma subcadeia de caracteres de comprimento `nCount` caracteres neste `CStringT` objeto, começando na posição `iFirst` (com base em zero).  
  
```  
CStringT Mid(int iFirst, int nCount) const;
CStringT Mid(int iFirst) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `iFirst`  
 O índice de base zero do primeiro caractere na `CStringT` objeto a ser incluído na subcadeia de caracteres extraída.  
  
 `nCount`  
 O número de caracteres para extrair desse objeto `CStringT`. Se esse parâmetro não for fornecido, o restante da cadeia de caracteres é extraído.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o retornado `CStringT` objeto pode estar vazio.  
  
### <a name="remarks"></a>Comentários  
 A função retorna uma cópia da subcadeia de caracteres extraída. `Mid` é semelhante à função Mid básica (exceto que os índices em Basic são baseados em um).  
  
 Para conjuntos de caracteres multibyte (MBCS) `nCount` refere-se a cada byte de caractere; ou seja, um cliente potencial e trilha de 8 bits em um caractere multibyte são contados como dois caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#128](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_23.cpp)]  
  
##  <a name="oemtoansi"></a>  CStringT::OemToAnsi  
 Converte todos os caracteres neste `CStringT` objeto do conjunto para o conjunto de caracteres ANSI de caracteres OEM.  
  
```  
void OemToAnsi();
```  
  
### <a name="remarks"></a>Comentários  
 Esta função não está disponível se `_UNICODE` está definido.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CStringT::AnsiToOem](#ansitooem).  
  
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
 `ch1`  
 Um caractere para concatenar com uma cadeia de caracteres ANSI ou Unicode.  
  
 `ch2`  
 Um caractere para concatenar com uma cadeia de caracteres ANSI ou Unicode.  
  
 `str1`  
 Um `CStringT` para concatenar com uma cadeia de caracteres ou um caractere.  
  
 `str2`  
 Um `CStringT` para concatenar com uma cadeia de caracteres ou um caractere.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para concatenar com uma cadeia de caracteres ou um caractere.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres para concatenação com uma cadeia de caracteres ou um caractere.  
  
### <a name="remarks"></a>Comentários  
 Há sete formas de sobrecarga do `CStringT::operator+` função. A primeira versão concatena dois existente `CStringT` objetos. As próximas duas concatenar uma `CStringT` objeto e uma cadeia de caracteres terminada em nulo. As próximas duas concatenar uma `CStringT` objeto e um caractere ANSI. Os dois últimos concatenar uma `CStringT` objeto e um caractere Unicode.  
  
> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm inseridos caracteres nulos, é recomendável em relação a ela. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados inesperados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#140](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_24.cpp)]  
  
##  <a name="operator_add_eq"></a>  + CStringT::operator =  
 Concatena caracteres ao final da cadeia de caracteres.  
  
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
 STR  
 Uma referência a um objeto `CThisSimpleString`.  
  
 `bMFCDLL`  
 Um booliano que especifica se o projeto é uma DLL MFC ou não.  
  
 `BaseType`  
 O tipo de base de cadeia de caracteres.  
  
 `var`  
 Um objeto variante de concatenar a essa cadeia de caracteres.  
  
 `ch`  
 Um caractere para concatenar com uma cadeia de caracteres ANSI ou Unicode.  
  
 `pszSrc`  
 Um ponteiro para a cadeia de caracteres original são concatenado.  
  
 `strSrc`  
 Um `CStringT` de concatenar a essa cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 O operador aceita outro `CStringT` objeto, um ponteiro de caractere ou um único caractere. Você deve estar ciente de que a memória exceções podem ocorrer sempre que você usar esse operador de concatenação porque o novo armazenamento pode ser alocado para caracteres adicionados a este `CStringT` objeto.  
  
 Para obter informações sobre `CThisSimpleString`, consulte a seção de comentários de [CStringT::CStringT](#cstringt).  
  
> [!NOTE]
>  Embora seja possível criar `CStringT` instâncias que contêm inseridos caracteres nulos, é recomendável em relação a ela. Chamando métodos e operadores em `CStringT` objetos que contêm caracteres nulos inseridos podem produzir resultados inesperados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#141](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_25.cpp)]  
  
##  <a name="operator_eq_eq"></a>  CStringT::operator = =  
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
  
### <a name="parameters"></a>Parâmetros  
 `ch1`  
 Um caractere ANSI ou Unicode para comparação.  
  
 `ch2`  
 Um caractere ANSI ou Unicode para comparação.  
  
 `str1`  
 Um `CStringT` para comparação.  
  
 `str2`  
 Um `CStringT` para comparação.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
### <a name="remarks"></a>Comentários  
 Testa se uma cadeia de caracteres ou um caractere à esquerda é igual a uma cadeia de caracteres ou um caractere à direita e retorna TRUE ou FALSE adequadamente.  
  
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
 `ch1`  
 Um caractere para concatenar com uma cadeia de caracteres ANSI ou Unicode.  
  
 `ch2`  
 Um caractere para concatenar com uma cadeia de caracteres ANSI ou Unicode.  
  
 `str1`  
 Um `CStringT` para comparação.  
  
 `str2`  
 Um `CStringT` para comparação.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
### <a name="remarks"></a>Comentários  
 Testa se uma cadeia de caracteres ou um caractere à esquerda não é igual a uma cadeia de caracteres ou um caractere à direita.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#143](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_27.cpp)]  
  
##  <a name="operator_lt"></a>  CStringT::operator &lt;  
 Determina se a cadeia de caracteres à esquerda do operador é menor do que a cadeia de caracteres à direita.  
  
```  
friend bool operator<(const CStringT& str1, const CStringT& str2) throw();
friend bool operator<(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator<(PCXSTR psz1, const CStringT& str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 Um `CStringT` para comparação.  
  
 `str2`  
 Um `CStringT` para comparação.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
### <a name="remarks"></a>Comentários  
 Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:  
  
-   Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.  
  
-   Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.  
  
-   Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#144](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_28.cpp)]  
  
##  <a name="operator_gt"></a>  CStringT::operator &gt;  
 Determina se a cadeia de caracteres à esquerda do operador é maior do que a cadeia de caracteres à direita.  
  
```  
friend bool operator>(const CStringT& str1, const CStringT& str2) throw();
friend bool operator>(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator>(PCXSTR psz1, const CStringT& str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 Um `CStringT` para comparação.  
  
 `str2`  
 Um `CStringT` para comparação.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
### <a name="remarks"></a>Comentários  
 Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:  
  
-   Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.  
  
-   Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.  
  
-   Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#145](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_29.cpp)]  
  
##  <a name="operator_lt_eq"></a>  CStringT::operator &lt;=  
 Determina se a cadeia de caracteres à esquerda do operador é menor ou igual à cadeia de caracteres à direita.  
  
```  
friend bool operator<=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator<=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator<=(PCXSTR psz1, const CStringT& str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 Um `CStringT` para comparação.  
  
 `str2`  
 Um `CStringT` para comparação.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo para comparação.  
  
### <a name="remarks"></a>Comentários  
 Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:  
  
-   Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.  
  
-   Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.  
  
-   Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#146](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_30.cpp)]  
  
##  <a name="operator_gt_eq"></a>  CStringT::operator &gt;=  
 Determina se a cadeia de caracteres à esquerda do operador é maior que ou igual à cadeia de caracteres à direita.  
  
```  
friend bool operator>=(const CStringT& str1, const CStringT& str2) throw();
friend bool operator>=(const CStringT& str1, PCXSTR psz2) throw();
friend bool operator>=(PCXSTR psz1, const CStringT& str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 Um `CStringT` para comparação.  
  
 `str2`  
 Um `CStringT` para comparação.  
  
 `psz1`  
 Um ponteiro para uma cadeia de caracteres para comparação.  
  
 `psz2`  
 Um ponteiro para uma cadeia de caracteres para comparação.  
  
### <a name="remarks"></a>Comentários  
 Uma comparação lexicográfica entre cadeias de caracteres, caractere por caractere até:  
  
-   Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.  
  
-   Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.  
  
-   Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#147](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_31.cpp)]  
  
##  <a name="remove"></a>  CStringT::Remove  
 Remove todas as ocorrências do caractere especificado da cadeia de caracteres.  
  
```  
int Remove(XCHAR chRemove);
```  
  
### <a name="parameters"></a>Parâmetros  
 `chRemove`  
 O caractere a ser removido de uma cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de caracteres removidas da cadeia de caracteres. Zero se a cadeia de caracteres não for alterada.  
  
### <a name="remarks"></a>Comentários  
 Comparações de cadeias de caractere diferenciam maiusculas de minúsculas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#129](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_32.cpp)]  
  
##  <a name="replace"></a>  CStringT::Replace  
 Há duas versões do `Replace`. A primeira versão substitui uma ou mais cópias de uma subcadeia de caracteres usando outra subcadeia de caracteres. Ambas as subcadeias de caracteres são terminada em nulo. A segunda versão substitui uma ou mais cópias de um caractere usando outro caractere. Ambas as versões operam nos dados de caracteres armazenados em `CStringT`.  
  
```  
int Replace(PCXSTR pszOld, PCXSTR pszNew);
int Replace(XCHAR chOld, XCHAR chNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszOld`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo a ser substituído por `pszNew`.  
  
 `pszNew`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que substitui `pszOld`.  
  
 `chOld`  
 O caractere a ser substituído por `chNew`.  
  
 `chNew`  
 O caractere substituindo `chOld`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de instâncias substituídos do zero, o caractere ou subcadeia de caracteres se a cadeia de caracteres não for alterada.  
  
### <a name="remarks"></a>Comentários  
 `Replace` pode alterar o comprimento da cadeia de caracteres porque `pszNew` e `pszOld` não precisam ter o mesmo comprimento e várias cópias da subcadeia de caracteres antiga podem ser alteradas para o novo. A função executa uma correspondência diferencia maiusculas de minúsculas.  
  
 Exemplos de `CStringT` instâncias são `CString`, `CStringA`, e `CStringW`.  
  
 Para `CStringA`, `Replace` funciona com ANSI ou em caracteres multibyte (MBCS). Para `CStringW`, `Replace` funciona com caracteres largos.  
  
 Para `CString`, o tipo de dados de caractere é selecionado em tempo de compilação, com base em se as constantes na tabela a seguir são definidas.  
  
|Constante definida|Tipo de dados de caractere|  
|----------------------|-------------------------|  
|`_UNICODE`|Caracteres largos|  
|`_MBCS`|Caracteres multibyte|  
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
 `ch`  
 O caractere a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do último caractere na `CStringT` objeto que coincide com o caractere solicitado, ou -1 se o caractere não for encontrado.  
  
### <a name="remarks"></a>Comentários  
 A função é semelhante à função tempo de execução `strrchr`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#130](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_34.cpp)]  
  
##  <a name="right"></a>  CStringT::Right  
 Extrai o último (ou seja, mais à direita) `nCount` caracteres neste `CStringT` de objeto e retorna uma cópia da subcadeia de caracteres extraída.  
  
```  
CStringT Right(int nCount) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCount`  
 O número de caracteres para extrair desse objeto `CStringT`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto `CStringT` que contém uma cópia do intervalo especificado de caracteres. Observe que o retornado `CStringT` objeto pode ser vazio.  
  
### <a name="remarks"></a>Comentários  
 Se `nCount` exceder o comprimento da cadeia de caracteres, a cadeia de caracteres inteira será extraída. `Right` é semelhante à básica `Right` função (exceto que os índices em Basic são baseadas em zero).  
  
 Para conjuntos de caracteres multibyte (MBCS) `nCount` refere-se a cada byte de caractere; ou seja, um cliente potencial e trilha de 8 bits em um caractere multibyte são contados como dois caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#131](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_35.cpp)]  
  
##  <a name="setsysstring"></a>  CStringT::SetSysString  
 Realoca a `BSTR` apontada pelo `pbstr` e copia o conteúdo do `CStringT` objeto, incluindo o `NULL` caracteres.  
  
```  
BSTR SetSysString(BSTR* pbstr) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbstr`  
 Um ponteiro para uma cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 A nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Dependendo do conteúdo do `CStringT` objeto, o valor da `BSTR` referenciado pelo `pbstr` pode alterar. A função gera uma `CMemoryException` se houver memória insuficiente.  
  
 Essa função é normalmente usada para alterar o valor de cadeias de caracteres passada por referência para automação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#132](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_36.cpp)]  
  
##  <a name="spanexcluding"></a>  CStringT::SpanExcluding  
 Extrai os caracteres de cadeia de caracteres, começando com o primeiro caractere que não estão no conjunto de caracteres identificada pelo `pszCharSet`.  
  
```  
CStringT SpanExcluding(PCXSTR pszCharSet) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszCharSet`  
 Uma cadeia de caracteres é interpretada como um conjunto de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma subcadeia de caracteres que contém os caracteres na cadeia de caracteres que não estão no `pszCharSet`, começando com o primeiro caractere na cadeia de caracteres e terminando com o primeiro caractere encontrado na cadeia de caracteres que também está na `pszCharSet` (ou seja, começando com o primeiro caractere no cadeia de caracteres e mas exceto o primeiro caractere na cadeia de caracteres que é encontrado `pszCharSet`). Retorna a cadeia de caracteres inteira se nenhum caractere em `pszCharSet` for encontrado na cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 `SpanExcluding` extrai e retorna todos os caracteres que precede a primeira ocorrência de um caractere de `pszCharSet` (em outras palavras, o caractere de `pszCharSet` e todos os caracteres a seguir na cadeia de caracteres, não são retornadas). Se nenhum caractere de `pszCharSet` for encontrado na cadeia de caracteres, em seguida, `SpanExcluding` retorna a cadeia de caracteres inteira.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#133](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_37.cpp)]  
  
##  <a name="spanincluding"></a>  CStringT::SpanIncluding  
 Extrai os caracteres de cadeia de caracteres, começando com o primeiro caractere, que estão no conjunto de caracteres identificada pelo `pszCharSet`.  
  
```  
CStringT SpanIncluding(PCXSTR pszCharSet) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszCharSet`  
 Uma cadeia de caracteres é interpretada como um conjunto de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma subcadeia de caracteres que contém os caracteres na cadeia de caracteres que estão em `pszCharSet`, começando com o primeiro caractere na cadeia de caracteres e terminando quando for encontrado um caractere na cadeia de caracteres que não está em `pszCharSet`. `SpanIncluding` Retorna uma subcadeia de caracteres vazia se o primeiro caractere na cadeia de caracteres não está no conjunto especificado.  
  
### <a name="remarks"></a>Comentários  
 Se o primeiro caractere da cadeia de caracteres não está no conjunto de caracteres, em seguida, `SpanIncluding` retorna uma cadeia de caracteres vazia. Caso contrário, ele retorna uma cadeia de caracteres consecutivos que estão no conjunto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#134](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_38.cpp)]  
  
##  <a name="tokenize"></a>  CStringT::Tokenize  
 Localiza o próximo token em uma cadeia de caracteres de destino  
  
```  
CStringT Tokenize(PCXSTR pszTokens, int& iStart) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszTokens`  
 Uma cadeia de caracteres que contém os delimitadores de token. A ordem desses delimitadores não é importante.  
  
 `iStart`  
 O índice com base em zero para iniciar a pesquisa.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CStringT` objeto que contém o valor do token atual.  
  
### <a name="remarks"></a>Comentários  
 O `Tokenize` função localiza o próximo token na cadeia de caracteres de destino. O conjunto de caracteres em `pszTokens` Especifica possíveis delimitadores de token a ser localizado. Em cada chamada para `Tokenize` inicia a função em `iStart`, ignora delimitadores à esquerda e retorna um `CStringT` objeto que contém o token atual, que é uma cadeia de caracteres até o próximo caractere delimitador. O valor de `iStart` é atualizada para ser a posição após o caractere delimitador de término ou -1 se o final da cadeia de caracteres foi atingido. Tokens mais podem ser divididas fora o restante da cadeia de caracteres de destino por uma série de chamadas para `Tokenize`usando `iStart` para controlar onde na cadeia de caracteres é o próximo token a ser lido. Quando não houver nenhum token é a função retornará uma cadeia de caracteres vazia e `iStart` será definido como -1.  
  
 Ao contrário do CRT indexar funções como [strtok_s, strtok_s_l, wcstok_s, wcstok_s_l, mbstok_s, mbstok_s_l](../../c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l.md), `Tokenize` não modifica a cadeia de caracteres de destino.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#135](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_39.cpp)]  
  
### <a name="remarks"></a>Comentários  
 A saída deste exemplo é o seguinte:  
  
 `Resulting Token: First`  
  
 `Resulting Token: Second`  
  
 `Resulting Token: Third`  
  
##  <a name="trim"></a>  CStringT::Trim  
 Corta à esquerda e à direita a cadeia de caracteres.  
  
```  
CStringT& Trim(XCHAR chTarget);
CStringT& Trim(PCXSTR pszTargets);
CStringT& Trim();
```  
  
### <a name="parameters"></a>Parâmetros  
 `chTarget`  
 O caractere de destino a serem cortados.  
  
 `pszTargets`  
 Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todos os esquerda e à direita ocorrências de caracteres em `pszTarget` serão apagadas do `CStringT` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a cadeia de caracteres cortada.  
  
### <a name="remarks"></a>Comentários  
 Remove todas as ocorrências de esquerda e à direita de um dos seguintes:  
  
-   O caractere especificado pelo `chTarget.`  
  
-   Todos os caracteres encontrados na cadeia de caracteres especificada pelo `pszTargets.`  
  
-   Espaço em branco.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#136](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_40.cpp)]  
  
### <a name="remarks"></a>Comentários  
 A saída deste exemplo é o seguinte:  
  
 `Before: "******Soccer is best, but liquor is quicker!!!!!"`  
  
 `After : "Soccer is best, but liquor is quicker"`  
  
##  <a name="trimleft"></a>  CStringT::TrimLeft  
 Corta caracteres à esquerda da cadeia de caracteres.  
  
```  
CStringT& TrimLeft(XCHAR chTarget);
CStringT& TrimLeft(PCXSTR pszTargets);
CStringT& TrimLeft();
```  
  
### <a name="parameters"></a>Parâmetros  
 `chTarget`  
 O caractere de destino a serem cortados.  
  
 `pszTargets`  
 Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todas as ocorrências à esquerda de caracteres em `pszTarget` serão apagadas do `CStringT` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres resultante cortada.  
  
### <a name="remarks"></a>Comentários  
 Remove todas as ocorrências de esquerda e à direita de um dos seguintes:  
  
-   O caractere especificado pelo `chTarget.`  
  
-   Todos os caracteres encontrados na cadeia de caracteres especificada pelo `pszTargets.`  
  
-   Espaço em branco.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#137](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_41.cpp)]  
  
##  <a name="trimright"></a>  CStringT::TrimRight  
 Corta caracteres da cadeia de caracteres à direita.  
  
```  
CStringT& TrimRight(XCHAR chTarget);
CStringT& TrimRight(PCXSTR pszTargets);
CStringT& TrimRight();
```  
  
### <a name="parameters"></a>Parâmetros  
 `chTarget`  
 O caractere de destino a serem cortados.  
  
 `pszTargets`  
 Um ponteiro para uma cadeia de caracteres que contém os caracteres de destino a serem cortados. Todos os à direita ocorrências de caracteres em `pszTarget` serão apagadas do `CStringT` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o `CStringT` objeto que contém a cadeia de caracteres cortada.  
  
### <a name="remarks"></a>Comentários  
 Remove à direita de ocorrências de um dos seguintes:  
  
-   O caractere especificado pelo `chTarget.`  
  
-   Todos os caracteres encontrados na cadeia de caracteres especificada pelo `pszTargets.`  
  
-   Espaço em branco.  
  
 O `CStringT& TrimRight(XCHAR chTarget)` versão aceita um parâmetro de caractere e remove todas as cópias do caractere de final de `CStringT` dados de cadeia de caracteres. Ele inicia no final da cadeia de caracteres e funciona em direção à frente. Ele será interrompido quando encontra um caractere diferente ou `CSTringT` ficar sem dados de caractere.  
  
 O `CStringT& TrimRight(PCXSTR pszTargets)` versão aceita uma cadeia de caracteres terminada em nulo que contém todos os caracteres a ser pesquisado. Remove todas as cópias desses caracteres no `CStringT` objeto. Ele inicia no final da cadeia de caracteres e funciona em direção à frente. Ele será interrompido quando encontra um caractere que não está na cadeia de caracteres de destino ou quando `CStringT` ficar sem dados de caractere. Ele não tenta corresponder a cadeia de caracteres de destino inteira para uma subcadeia de caracteres do final de `CStringT`.  
  
 O `CStringT& TrimRight()` versão não requer parâmetros. Organizando qualquer caractere de espaço em branco à direita do final do `CStringT` cadeia de caracteres. Caracteres de espaço em branco podem ser guias, espaços ou quebras de linha.  
  
-  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#138](../../atl-mfc-shared/codesnippet/cpp/cstringt-class_42.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)   
 [Classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)


