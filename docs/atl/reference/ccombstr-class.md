---
title: Classe CComBSTR
ms.date: 11/04/2016
f1_keywords:
- CComBSTR
- ATLBASE/ATL::CComBSTR
- ATLBASE/ATL::CComBSTR::CComBSTR
- ATLBASE/ATL::CComBSTR::Append
- ATLBASE/ATL::CComBSTR::AppendBSTR
- ATLBASE/ATL::CComBSTR::AppendBytes
- ATLBASE/ATL::CComBSTR::ArrayToBSTR
- ATLBASE/ATL::CComBSTR::AssignBSTR
- ATLBASE/ATL::CComBSTR::Attach
- ATLBASE/ATL::CComBSTR::BSTRToArray
- ATLBASE/ATL::CComBSTR::ByteLength
- ATLBASE/ATL::CComBSTR::Copy
- ATLBASE/ATL::CComBSTR::CopyTo
- ATLBASE/ATL::CComBSTR::Detach
- ATLBASE/ATL::CComBSTR::Empty
- ATLBASE/ATL::CComBSTR::Length
- ATLBASE/ATL::CComBSTR::LoadString
- ATLBASE/ATL::CComBSTR::ReadFromStream
- ATLBASE/ATL::CComBSTR::ToLower
- ATLBASE/ATL::CComBSTR::ToUpper
- ATLBASE/ATL::CComBSTR::WriteToStream
- ATLBASE/ATL::CComBSTR::m_str
helpviewer_keywords:
- BSTRs, wrapper
- CComBSTR class
- CComBSTR
ms.assetid: 8fea1879-a05e-47a5-a803-8dec60eaa534
ms.openlocfilehash: dd45c2ff9b43148e0fe27ebd410a2390a4d12ce2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497551"
---
# <a name="ccombstr-class"></a>Classe CComBSTR

Esta classe é um wrapper para os s [BSTR](/previous-versions/windows/desktop/automat/bstr).

## <a name="syntax"></a>Sintaxe

```
class CComBSTR
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::CComBSTR](#ccombstr)|O construtor.|
|[CComBSTR::~CComBSTR](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR:: Append](#append)|Acrescenta uma cadeia de caracteres `m_str`a.|
|[CComBSTR::AppendBSTR](#appendbstr)|Anexa um BSTR a `m_str`.|
|[CComBSTR::AppendBytes](#appendbytes)|Anexa um número especificado de bytes a `m_str`.|
|[CComBSTR::ArrayToBSTR](#arraytobstr)|Cria um BSTR a partir do primeiro caractere de cada elemento em SafeArray e anexa-o ao `CComBSTR` objeto.|
|[CComBSTR::AssignBSTR](#assignbstr)|Atribui um BSTR a `m_str`.|
|[CComBSTR::Attach](#attach)|Anexa um BSTR ao `CComBSTR` objeto.|
|[CComBSTR::BSTRToArray](#bstrtoarray)|Cria um SafeArray unidimensional de base zero, onde cada elemento da matriz é um caractere do `CComBSTR` objeto.|
|[CComBSTR::ByteLength](#bytelength)|Retorna o comprimento de `m_str` em bytes.|
|[CComBSTR::Copy](#copy)|Retorna uma cópia de `m_str`.|
|[CComBSTR::CopyTo](#copyto)|Retorna uma cópia de `m_str` por meio de um parâmetro **[out]**|
|[CComBSTR::Detach](#detach)|`m_str` Desanexa`CComBSTR` do objeto.|
|[CComBSTR::Empty](#empty)|Liberações `m_str`.|
|[CComBSTR::Length](#length)|Retorna o comprimento de `m_str`.|
|[CComBSTR::LoadString](#loadstring)|Carrega um recurso de cadeia de caracteres.|
|[CComBSTR::ReadFromStream](#readfromstream)|Carrega um objeto BSTR de um fluxo.|
|[CComBSTR::ToLower](#tolower)|Converte a cadeia de caracteres em minúsculas.|
|[CComBSTR::ToUpper](#toupper)|Converte a cadeia de caracteres em maiúsculas.|
|[CComBSTR::WriteToStream](#writetostream)|Salva `m_str` em um fluxo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CComBSTR:: Operator](#operator_bstr)|Converte um `CComBSTR` objeto em um BSTR.|
|[CComBSTR:: Operator!](#operator_not)|Retorna true ou false, dependendo se `m_str`for NULL.|
|[CComBSTR:: Operator! =](#operator_neq)|Compara um `CComBSTR` com uma cadeia de caracteres.|
|[Operador CComBSTR:: operator &](#operator_amp)|Retorna o endereço de `m_str`.|
|[CComBSTR:: Operator + =](#operator_add_eq)|Anexa um `CComBSTR` ao objeto.|
|[Operador CComBSTR:: Operator <](#operator_lt)|Compara um `CComBSTR` com uma cadeia de caracteres.|
|[CComBSTR:: Operator =](#operator_eq)|Atribui um valor a `m_str`.|
|[CComBSTR:: Operator = =](#operator_eq_eq)|Compara um `CComBSTR` com uma cadeia de caracteres.|
|[Operador CComBSTR:: operator >](#operator_gt)|Compara um `CComBSTR` com uma cadeia de caracteres.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::m_str](#m_str)|Contém o BSTR associado `CComBSTR` ao objeto.|

## <a name="remarks"></a>Comentários

A `CComBSTR` classe é um wrapper para BSTRs, que são cadeias de caracteres com prefixo de comprimento. O comprimento é armazenado como um inteiro no local da memória que precede os dados na cadeia de caracteres.

Um [BSTR](/previous-versions/windows/desktop/automat/bstr) é finalizado com NULL Após o último caractere contado, mas também pode conter caracteres nulos inseridos na cadeia de caracteres. O comprimento da cadeia de caracteres é determinado pela contagem de caracteres, não pelo primeiro caractere nulo.

> [!NOTE]
>  A `CComBSTR` classe fornece vários membros (construtores, operadores de atribuição e operadores de comparação) que usam cadeias de caracteres ANSI ou Unicode como argumentos. As versões ANSI dessas funções são menos eficientes do que suas contrapartes Unicode porque as cadeias de caracteres Unicode temporárias geralmente são criadas internamente. Para obter eficiência, use as versões Unicode sempre que possível.

> [!NOTE]
>  Devido ao comportamento de pesquisa aprimorado implementado no Visual Studio .net, o código `bstr = L"String2" + bstr;`como, que pode ter sido compilado em versões anteriores, deve ser implementado `bstr = CStringW(L"String2") + bstr`como.

Para obter uma lista de precauções ao usar `CComBSTR`o, consulte [programação com CComBSTR](../../atl/programming-with-ccombstr-atl.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="append"></a>CComBSTR:: Append

Acrescenta *lpsz* ou o membro BSTR de *bstrSrc* a [m_str](#m_str).

```
HRESULT Append(const CComBSTR& bstrSrc) throw();
HRESULT Append(wchar_t ch) throw();
HRESULT Append(char ch) throw();
HRESULT Append(LPCOLESTR lpsz) throw();
HRESULT Append(LPCSTR lpsz) throw();
HRESULT Append(LPCOLESTR lpsz, int nLen) throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
no Um `CComBSTR` objeto a ser acrescentado.

*ch*<br/>
no Um caractere a ser acrescentado.

*lpsz*<br/>
no Uma cadeia de caracteres terminada em zero para acrescentar. Você pode passar uma cadeia de caracteres Unicode por meio da sobrecarga LPCOLESTR ou de uma cadeia de caracteres ANSI por meio da versão LPCSTR.

*nLen*<br/>
no O número de caracteres de *lpsz* a serem acrescentados.

### <a name="return-value"></a>Valor de retorno

S_OK em caso de êxito ou qualquer valor de erro HRESULT padrão.

### <a name="remarks"></a>Comentários

Uma cadeia de caracteres ANSI será convertida em Unicode antes de ser acrescentada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#32](../../atl/codesnippet/cpp/ccombstr-class_1.cpp)]

##  <a name="appendbstr"></a>  CComBSTR::AppendBSTR

Anexa o BSTR especificado a [m_str](#m_str).

```
HRESULT AppendBSTR(BSTR p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
no Um BSTR para acrescentar.

### <a name="return-value"></a>Valor de retorno

S_OK em caso de êxito ou qualquer valor de erro HRESULT padrão.

### <a name="remarks"></a>Comentários

Não transmita uma cadeia de caracteres larga comum para esse método. O compilador não pode capturar o erro e erros de tempo de execução ocorrerão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#33](../../atl/codesnippet/cpp/ccombstr-class_2.cpp)]

##  <a name="appendbytes"></a>  CComBSTR::AppendBytes

Acrescenta o número especificado de bytes a [m_str](#m_str) sem conversão.

```
HRESULT AppendBytes(const char* lpsz, int nLen) throw();
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
no Um ponteiro para uma matriz de bytes a serem acrescentados.

*p*<br/>
no O número de bytes a acrescentar.

### <a name="return-value"></a>Valor de retorno

S_OK em caso de êxito ou qualquer valor de erro HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#34](../../atl/codesnippet/cpp/ccombstr-class_3.cpp)]

##  <a name="arraytobstr"></a>  CComBSTR::ArrayToBSTR

Libera qualquer cadeia de caracteres existente mantida no `CComBSTR` objeto e, em seguida, cria um BSTR a partir do primeiro caractere de cada elemento em SafeArray e anexa- `CComBSTR` o ao objeto.

```
HRESULT ArrayToBSTR(const SAFEARRAY* pSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*pSrc*<br/>
no O SAFEARRAY que contém os elementos usados para criar a cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

S_OK em caso de êxito ou qualquer valor de erro HRESULT padrão.

##  <a name="assignbstr"></a>  CComBSTR::AssignBSTR

Atribui um BSTR a [m_str](#m_str).

```
HRESULT AssignBSTR(const BSTR bstrSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
no Um BSTR a ser atribuído ao objeto `CComBSTR` atual.

### <a name="return-value"></a>Valor de retorno

S_OK em caso de êxito ou qualquer valor de erro HRESULT padrão.

##  <a name="attach"></a>  CComBSTR::Attach

Anexa um BSTR ao `CComBSTR` objeto definindo o membro [m_str](#m_str) como *src*.

```
void Attach(BSTR src) throw();
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
no O BSTR a ser anexado ao objeto.

### <a name="remarks"></a>Comentários

Não transmita uma cadeia de caracteres larga comum para esse método. O compilador não pode capturar o erro e erros de tempo de execução ocorrerão.

> [!NOTE]
>  Esse método será declarado se `m_str` for não nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]

##  <a name="bstrtoarray"></a>CComBSTR::BSTRToArray

Cria um SafeArray unidimensional de base zero, onde cada elemento da matriz é um caractere do `CComBSTR` objeto.

```
HRESULT BSTRToArray(LPSAFEARRAY* ppArray) throw();
```

### <a name="parameters"></a>Parâmetros

*ppArray*<br/>
fora O ponteiro para o SAFEARRAY usado para manter os resultados da função.

### <a name="return-value"></a>Valor de retorno

S_OK em caso de êxito ou qualquer valor de erro HRESULT padrão.

##  <a name="bytelength"></a>  CComBSTR::ByteLength

Retorna o número de bytes no `m_str`, excluindo o caractere nulo de terminação.

```
unsigned int ByteLength() const throw();
```

### <a name="return-value"></a>Valor de retorno

O comprimento do membro [m_str](#m_str) em bytes.

### <a name="remarks"></a>Comentários

Retornará 0 se `m_str` for nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#36](../../atl/codesnippet/cpp/ccombstr-class_5.cpp)]

##  <a name="ccombstr"></a>  CComBSTR::CComBSTR

O construtor. O construtor padrão define o membro [m_str](#m_str) como nulo.

```
CComBSTR() throw();
CComBSTR(const CComBSTR& src);
CComBSTR(REFGUID  guid);
CComBSTR(int nSize);
CComBSTR(int nSize, LPCOLESTR sz);
CComBSTR(int nSize, LPCSTR sz);
CComBSTR(LPCOLESTR pSrc);
CComBSTR(LPCSTR pSrc);
CComBSTR(CComBSTR&& src) throw(); // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*nSize*<br/>
no O número de caracteres a serem copiados de *sz* ou o tamanho inicial em caracteres `CComBSTR`para o.

*sz*<br/>
no Uma cadeia de caracteres a ser copiada. A versão Unicode especifica um LPCOLESTR; a versão ANSI especifica um LPCSTR.

*pSrc*<br/>
no Uma cadeia de caracteres a ser copiada. A versão Unicode especifica um LPCOLESTR; a versão ANSI especifica um LPCSTR.

*src*<br/>
no Um `CComBSTR` objeto.

*guid*<br/>
no Uma referência a uma `GUID` estrutura.

### <a name="remarks"></a>Comentários

O construtor de cópia `m_str` é definido como uma cópia do membro BSTR de *src*. O `REFGUID` Construtor converte o GUID em uma cadeia de `StringFromGUID2` caracteres usando e armazena o resultado.

Os outros construtores são definidos `m_str` como uma cópia da cadeia de caracteres especificada. Se você passar um valor para *nSize*, somente os caracteres *nSize* serão copiados, seguidos por um caractere nulo de terminação.

`CComBSTR`dá suporte à semântica de movimentação. Você pode usar o Construtor move (o construtor que usa uma referência rvalue (`&&`) para criar um novo objeto que usa os mesmos dados subjacentes que o objeto antigo que você passa como um argumento, sem a sobrecarga de copiar o objeto.

O destruidor libera a cadeia de caracteres apontada `m_str`para by.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#37](../../atl/codesnippet/cpp/ccombstr-class_6.cpp)]

##  <a name="dtor"></a>  CComBSTR::~CComBSTR

O destruidor.

```
~CComBSTR();
```

### <a name="remarks"></a>Comentários

O destruidor libera a cadeia de caracteres apontada `m_str`para by.

##  <a name="copy"></a>CComBSTR:: copiar

Aloca e retorna uma cópia do `m_str`.

```
BSTR Copy() const throw();
```

### <a name="return-value"></a>Valor de retorno

Uma cópia do membro [m_str](#m_str) . Se `m_str` for NULL, retornará NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#38](../../atl/codesnippet/cpp/ccombstr-class_7.cpp)]

##  <a name="copyto"></a>CComBSTR:: CopyTo

Aloca e retorna uma cópia de [m_str](#m_str) por meio do parâmetro.

```
HRESULT CopyTo(BSTR* pbstr) throw();

HRESULT CopyTo(VARIANT* pvarDest) throw();
```

### <a name="parameters"></a>Parâmetros

*pbstr*<br/>
fora O endereço de um BSTR no qual retornar a cadeia de caracteres alocada por este método.

*pvarDest*<br/>
fora O endereço de uma variante na qual retornar a cadeia de caracteres alocada por este método.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão que indica o êxito ou a falha da cópia.

### <a name="remarks"></a>Comentários

Depois de chamar esse método, a variante apontada por *pvarDest* será do tipo VT_BSTR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#39](../../atl/codesnippet/cpp/ccombstr-class_8.cpp)]

##  <a name="detach"></a>  CComBSTR::Detach

Desanexa [m_str](#m_str) do `CComBSTR` objeto e define `m_str` como NULL.

```
BSTR Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

O BSTR associado `CComBSTR` ao objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#40](../../atl/codesnippet/cpp/ccombstr-class_9.cpp)]

##  <a name="empty"></a>CComBSTR:: Empty

Libera o membro [m_str](#m_str) .

```
void Empty() throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#41](../../atl/codesnippet/cpp/ccombstr-class_10.cpp)]

##  <a name="length"></a>  CComBSTR::Length

Retorna o número de caracteres no `m_str`, excluindo o caractere nulo de terminação.

```
unsigned int Length() const throw();
```

### <a name="return-value"></a>Valor de retorno

O comprimento do membro [m_str](#m_str) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#42](../../atl/codesnippet/cpp/ccombstr-class_11.cpp)]

##  <a name="loadstring"></a>CComBSTR:: LoadString

Carrega um recurso de cadeia de caracteres especificado por *NID* e o armazena nesse objeto.

```
bool LoadString(HINSTANCE hInst, UINT nID) throw();
bool LoadString(UINT nID) throw();
```

### <a name="parameters"></a>Parâmetros

Consulte [LoadString](/windows/win32/api/winuser/nf-winuser-loadstringw) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a cadeia de caracteres for carregada com êxito; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

A primeira função carrega o recurso do módulo identificado por você por meio do parâmetro *hinst* . A segunda função carrega o recurso do módulo de recurso associado ao objeto derivado de [CComModule](../../atl/reference/ccommodule-class.md)usado neste projeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#43](../../atl/codesnippet/cpp/ccombstr-class_12.cpp)]

##  <a name="m_str"></a>  CComBSTR::m_str

Contém o BSTR associado `CComBSTR` ao objeto.

```
BSTR m_str;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#49](../../atl/codesnippet/cpp/ccombstr-class_13.cpp)]

##  <a name="operator_bstr"></a>Operador CComBSTR:: Operator

Converte um `CComBSTR` objeto em um BSTR.

```
operator BSTR() const throw();
```

### <a name="remarks"></a>Comentários

Permite que você passe `CComBSTR` objetos para funções que têm parâmetros **BSTR [in]** .

### <a name="example"></a>Exemplo

Consulte o exemplo de [CComBSTR:: m_str](#m_str).

##  <a name="operator_not"></a>CComBSTR:: Operator!

Verifica se a cadeia de caracteres BSTR é nula.

```
bool operator!() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o membro [m_str](#m_str) for nulo; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse operador verifica apenas um valor nulo, não para uma cadeia de caracteres vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]

##  <a name="operator_neq"></a>CComBSTR:: Operator! =

Retorna o oposto lógico de [Operator = =](#operator_eq_eq).

```
bool operator!= (const CComBSTR& bstrSrc) const throw();
bool operator!= (LPCOLESTR pszSrc) const;
bool operator!= (LPCSTR pszSrc) const;
bool operator!= (int nNull) const throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
no Um `CComBSTR` objeto.

*pszSrc*<br/>
no Uma cadeia de caracteres terminada em zero.

*nNull*<br/>
no Deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado não for igual `CComBSTR` ao objeto; caso contrário, retornará false.

### <a name="remarks"></a>Comentários

`CComBSTR`os s são comparados textualmente no contexto da localidade padrão do usuário. O operador de comparação final apenas compara a cadeia de caracteres contida com NULL.

##  <a name="operator_amp"></a>Operador CComBSTR::&amp;

Retorna o endereço do BSTR armazenado no membro [m_str](#m_str) .

```
BSTR* operator&() throw();
```

### <a name="remarks"></a>Comentários

`CComBstr operator &`tem uma asserção especial associada a ela para ajudar a identificar vazamentos de memória. O programa será declarado quando o `m_str` membro for inicializado. Essa asserção foi criada para identificar situações em que um programador usa `& operator` o para atribuir um novo valor `m_str` ao membro sem liberar a primeira alocação de `m_str`. Se `m_str` for igual a NULL, o programa pressupõe que m_str ainda não foi alocado. Nesse caso, o programa não será declarado.

Essa asserção não está habilitada por padrão. Defina ATL_CCOMBSTR_ADDRESS_OF_ASSERT para habilitar esta asserção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#46](../../atl/codesnippet/cpp/ccombstr-class_14.cpp)]

[!code-cpp[NVC_ATL_Utilities#47](../../atl/codesnippet/cpp/ccombstr-class_15.cpp)]

##  <a name="operator_add_eq"></a>CComBSTR:: Operator + =

Anexa uma cadeia de caracteres ao `CComBSTR` objeto.

```
CComBSTR& operator+= (const CComBSTR& bstrSrc);
CComBSTR& operator+= (const LPCOLESTR pszSrc);
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
no Um `CComBSTR` objeto a ser acrescentado.

*pszSrc*<br/>
no Uma cadeia de caracteres terminada em zero a ser acrescentada.

### <a name="remarks"></a>Comentários

`CComBSTR`os s são comparados textualmente no contexto da localidade padrão do usuário. A comparação de LPCOLESTR é feita `memcmp` usando os dados brutos em cada cadeia de caracteres. A comparação de LPCSTR é executada da mesma maneira quando uma cópia Unicode temporária de *pszSrc* foi criada. O operador de comparação final apenas compara a cadeia de caracteres contida com NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#48](../../atl/codesnippet/cpp/ccombstr-class_16.cpp)]

##  <a name="operator_lt"></a>Operador CComBSTR::&lt;

Compara um `CComBSTR` com uma cadeia de caracteres.

```
bool operator<(const CComBSTR& bstrSrc) const throw();
bool operator<(LPCOLESTR pszSrc) const throw();
bool operator<(LPCSTR pszSrc) const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado for menor `CComBSTR` que o objeto; caso contrário, retornará false.

### <a name="remarks"></a>Comentários

A comparação é executada usando a localidade padrão do usuário.

##  <a name="operator_eq"></a>CComBSTR:: Operator =

Define o membro [m_str](#m_str) para uma cópia de *pSrc* ou para uma cópia do membro BSTR de *src*. O operador de atribuição de `src` movimentação se move sem copiá-lo.

```
CComBSTR& operator= (const CComBSTR& src);
CComBSTR& operator= (LPCOLESTR pSrc);
CComBSTR& operator= (LPCSTR pSrc);
CComBSTR& operator= (CComBSTR&& src) throw(); // (Visual Studio 2017)
```

### <a name="remarks"></a>Comentários

O parâmetro *pSrc* especifica um LPCOLESTR para versões Unicode ou LPCSTR para versões ANSI.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CComBSTR:: Copy](#copy).

##  <a name="operator_eq_eq"></a>CComBSTR:: Operator = =

Compara um `CComBSTR` com uma cadeia de caracteres. `CComBSTR`os s são comparados textualmente no contexto da localidade padrão do usuário.

```
bool operator== (const CComBSTR& bstrSrc) const throw();
bool operator== (LPCOLESTR pszSrc) const;
bool operator== (LPCSTR pszSrc) const;
bool operator== (int nNull) const throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
no Um `CComBSTR` objeto.

*pszSrc*<br/>
no Uma cadeia de caracteres terminada em zero.

*nNull*<br/>
no Deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado for igual `CComBSTR` ao objeto; caso contrário, retornará false.

### <a name="remarks"></a>Comentários

O operador de comparação final apenas compara a cadeia de caracteres contida com NULL.

##  <a name="operator_gt"></a>Operador CComBSTR::&gt;

Compara um `CComBSTR` com uma cadeia de caracteres.

```
bool operator>(const CComBSTR& bstrSrc) const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado for maior `CComBSTR` que o objeto; caso contrário, retornará false.

### <a name="remarks"></a>Comentários

A comparação é executada usando a localidade padrão do usuário.

##  <a name="readfromstream"></a>  CComBSTR::ReadFromStream

Define o membro [m_str](#m_str) para o BSTR contido no fluxo especificado.

```
HRESULT ReadFromStream(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
no Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) no fluxo que contém os dados.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`ReadToStream`exige que o conteúdo do fluxo na posição atual seja compatível com o formato de dados gravado por uma chamada para [WriteToStream](#writetostream).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#44](../../atl/codesnippet/cpp/ccombstr-class_17.cpp)]

##  <a name="tolower"></a>CComBSTR:: ToLower

Converte a cadeia de caracteres contida em minúsculas.

```
HRESULT ToLower() throw();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulte `CharLowerBuff` para obter mais informações sobre como a conversão é executada.

##  <a name="toupper"></a>  CComBSTR::ToUpper

Converte a cadeia de caracteres contida em maiúsculas.

```
HRESULT ToUpper() throw();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulte `CharUpperBuff` para obter mais informações sobre como a conversão é executada.

##  <a name="writetostream"></a>  CComBSTR::WriteToStream

Salva o membro [m_str](#m_str) em um fluxo.

```
HRESULT WriteToStream(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
no Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) em um fluxo.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode recriar um BSTR a partir do conteúdo do fluxo usando a função [ReadFromStream](#readfromstream) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#45](../../atl/codesnippet/cpp/ccombstr-class_18.cpp)]

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Macros de conversão de cadeia de caracteres ATL e MFC](string-conversion-macros.md)
