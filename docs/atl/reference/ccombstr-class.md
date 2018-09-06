---
title: Classe CComBSTR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- BSTRs, wrapper
- CComBSTR class
- CComBSTR
ms.assetid: 8fea1879-a05e-47a5-a803-8dec60eaa534
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 54677e573f36fca65cc46dc5207e8812e4fa4fa6
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43752924"
---
# <a name="ccombstr-class"></a>Classe CComBSTR

Essa classe é um wrapper de BSTRs.

## <a name="syntax"></a>Sintaxe

```
class CComBSTR
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::CComBSTR](#ccombstr)|O construtor.|
|[CComBSTR:: ~ CComBSTR](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::Append](#append)|Acrescenta uma cadeia de caracteres para `m_str`.|
|[CComBSTR::AppendBSTR](#appendbstr)|Acrescenta um BSTR ao `m_str`.|
|[CComBSTR::AppendBytes](#appendbytes)|Acrescenta um número especificado de bytes a serem `m_str`.|
|[CComBSTR::ArrayToBSTR](#arraytobstr)|Cria um BSTR a partir do primeiro caractere de cada elemento em safearray e anexa-o para o `CComBSTR` objeto.|
|[CComBSTR::AssignBSTR](#assignbstr)|Atribui um BSTR ao `m_str`.|
|[CComBSTR::Attach](#attach)|Anexa um BSTR para o `CComBSTR` objeto.|
|[CComBSTR::BSTRToArray](#bstrtoarray)|Cria um safearray unidimensional baseado em zero, onde cada elemento da matriz é um caractere da `CComBSTR` objeto.|
|[CComBSTR::ByteLength](#bytelength)|Retorna o comprimento do `m_str` em bytes.|
|[CComBSTR::Copy](#copy)|Retorna uma cópia do `m_str`.|
|[CComBSTR::CopyTo](#copyto)|Retorna uma cópia do `m_str` por meio de um **[out]** parâmetro|
|[CComBSTR::Detach](#detach)|Desanexa `m_str` do `CComBSTR` objeto.|
|[CComBSTR::Empty](#empty)|Libera `m_str`.|
|[CComBSTR::Length](#length)|Retorna o comprimento do `m_str`.|
|[CComBSTR::LoadString](#loadstring)|Carrega um recurso de cadeia de caracteres.|
|[CComBSTR::ReadFromStream](#readfromstream)|Carrega um objeto BSTR de um fluxo.|
|[CComBSTR::ToLower](#tolower)|Converte a cadeia de caracteres em minúsculas.|
|[CComBSTR::ToUpper](#toupper)|Converte a cadeia de caracteres em maiusculas.|
|[CComBSTR::WriteToStream](#writetostream)|Salva `m_str` em um fluxo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::operator BSTR](#operator_bstr)|Converte um `CComBSTR` objeto para um BSTR.|
|[CComBSTR::operator!](#operator_not)|Retorna TRUE ou FALSE, dependendo se `m_str`é NULL.|
|[CComBSTR::operator! =](#operator_neq)|Compara um `CComBSTR` com uma cadeia de caracteres.|
|[CComBSTR::operator &](#operator_amp)|Retorna o endereço do `m_str`.|
|[+ CComBSTR::operator =](#operator_add_eq)|Acrescenta um `CComBSTR` ao objeto.|
|[CComBSTR::operator <](#operator_lt)|Compara um `CComBSTR` com uma cadeia de caracteres.|
|[CComBSTR::operator =](#operator_eq)|Atribui um valor para `m_str`.|
|[CComBSTR::operator = =](#operator_eq_eq)|Compara um `CComBSTR` com uma cadeia de caracteres.|
|[CComBSTR::operator >](#operator_gt)|Compara um `CComBSTR` com uma cadeia de caracteres.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::m_str](#m_str)|Contém o BSTR associado com o `CComBSTR` objeto.|

## <a name="remarks"></a>Comentários

O `CComBSTR` classe é um wrapper para BSTRs, que são cadeias de caracteres com tamanho prefixado. O comprimento é armazenado como um número inteiro no local da memória que precede os dados na cadeia de caracteres.

Um [BSTR](/previous-versions/windows/desktop/automat/bstr) é terminada em nulo após o último contado de caractere, mas também pode conter caracteres nulos inseridos na cadeia de caracteres. O comprimento da cadeia de caracteres é determinado pela contagem de caracteres, não o primeiro caractere nulo.

> [!NOTE]
>  O `CComBSTR` classe fornece um número de membros (construtores, operadores de atribuição e operadores de comparação) que usam cadeias de caracteres ANSI ou Unicode como argumentos. As versões ANSI essas funções são menos eficientes do que seus equivalentes Unicode como cadeias de caracteres Unicode temporárias geralmente são criadas internamente. Para maior eficiência, use as versões Unicode sempre que possível.

> [!NOTE]
>  Devido ao comportamento de pesquisa aprimorada implementado no Visual Studio .NET, como código `bstr = L"String2" + bstr;`, que pode ter sido compilado em versões anteriores, em vez disso, devem ser implementados como `bstr = CStringW(L"String2") + bstr`.

Para obter uma lista de cuidados ao usar `CComBSTR`, consulte [Programando com CComBSTR](../../atl/programming-with-ccombstr-atl.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="append"></a>  CComBSTR::Append

Acrescenta uma *lpsz* ou o membro BSTR *1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3* para [m_str](#m_str).

```
HRESULT Append(const CComBSTR& bstrSrc) throw();
HRESULT Append(wchar_t ch) throw();
HRESULT Append(char ch) throw();
HRESULT Append(LPCOLESTR lpsz) throw();
HRESULT Append(LPCSTR lpsz) throw();
HRESULT Append(LPCOLESTR lpsz, int nLen) throw();
```

### <a name="parameters"></a>Parâmetros

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*  
[in] Um `CComBSTR` objeto a ser acrescentado.

*ch*  
[in] Um caractere a ser acrescentado.

*lpsz*  
[in] Uma cadeia de caracteres terminada em zero para acrescentar. Você pode passar uma cadeia de caracteres Unicode por meio da cadeia de caracteres ANSI por meio da versão LPCSTR ou a sobrecarga LPCOLESTR.

*nLen*  
[in] O número de caracteres a partir *lpsz* para acrescentar.

### <a name="return-value"></a>Valor de retorno

S_OK no êxito ou qualquer valor padrão de erro HRESULT.

### <a name="remarks"></a>Comentários

Uma cadeia de caracteres ANSI será convertida em Unicode antes que está sendo acrescentado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#32](../../atl/codesnippet/cpp/ccombstr-class_1.cpp)]

##  <a name="appendbstr"></a>  CComBSTR::AppendBSTR

Acrescenta o BSTR especificado para [m_str](#m_str).

```
HRESULT AppendBSTR(BSTR p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*  
[in] Um BSTR para acrescentar.

### <a name="return-value"></a>Valor de retorno

S_OK no êxito ou qualquer valor padrão de erro HRESULT.

### <a name="remarks"></a>Comentários

Não passe uma cadeia de caracteres largos comum para esse método. O compilador não pode capturar o erro e ocorrerão erros de tempo de execução.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#33](../../atl/codesnippet/cpp/ccombstr-class_2.cpp)]

##  <a name="appendbytes"></a>  CComBSTR::AppendBytes

Acrescenta o número especificado de bytes a serem [m_str](#m_str) sem conversão.

```
HRESULT AppendBytes(const char* lpsz, int nLen) throw();
```

### <a name="parameters"></a>Parâmetros

*lpsz*  
[in] Um ponteiro para uma matriz de bytes a ser acrescentado.

*p*  
[in] O número de bytes a ser acrescentado.

### <a name="return-value"></a>Valor de retorno

S_OK no êxito ou qualquer valor padrão de erro HRESULT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#34](../../atl/codesnippet/cpp/ccombstr-class_3.cpp)]

##  <a name="arraytobstr"></a>  CComBSTR::ArrayToBSTR

Libera qualquer cadeia de caracteres existente, mantida na `CComBSTR` do objeto, em seguida, cria um BSTR a partir do primeiro caractere de cada elemento em safearray e anexa-o para o `CComBSTR` objeto.

```
HRESULT ArrayToBSTR(const SAFEARRAY* pSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*pSrc*  
[in] O safearray que contém os elementos usados para criar a cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

S_OK no êxito ou qualquer valor padrão de erro HRESULT.

##  <a name="assignbstr"></a>  CComBSTR::AssignBSTR

Atribui um BSTR ao [m_str](#m_str).

```
HRESULT AssignBSTR(const BSTR bstrSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*  
[in] Um BSTR para atribuir a atual `CComBSTR` objeto.

### <a name="return-value"></a>Valor de retorno

S_OK no êxito ou qualquer valor padrão de erro HRESULT.

##  <a name="attach"></a>  CComBSTR::Attach

Anexa um BSTR para o `CComBSTR` objeto, definindo o [m_str](#m_str) membro *src*.

```
void Attach(BSTR src) throw();
```

### <a name="parameters"></a>Parâmetros

*src*  
[in] O BSTR para anexar ao objeto.

### <a name="remarks"></a>Comentários

Não passe uma cadeia de caracteres largos comum para esse método. O compilador não pode capturar o erro e ocorrerão erros de tempo de execução.

> [!NOTE]
>  Esse método declarará se `m_str` não for nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]

##  <a name="bstrtoarray"></a>  CComBSTR::BSTRToArray

Cria um safearray unidimensional baseado em zero, onde cada elemento da matriz é um caractere da `CComBSTR` objeto.

```
HRESULT BSTRToArray(LPSAFEARRAY* ppArray) throw();
```

### <a name="parameters"></a>Parâmetros

*ppArray*  
[out] O ponteiro para o safearray usado para armazenar os resultados da função.

### <a name="return-value"></a>Valor de retorno

S_OK no êxito ou qualquer valor padrão de erro HRESULT.

##  <a name="bytelength"></a>  CComBSTR::ByteLength

Retorna o número de bytes em `m_str`, exceto o caractere nulo de terminação.

```
unsigned int ByteLength() const throw();
```

### <a name="return-value"></a>Valor de retorno

O comprimento do [m_str](#m_str) membro em bytes.

### <a name="remarks"></a>Comentários

Retorna 0 se `m_str` é NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#36](../../atl/codesnippet/cpp/ccombstr-class_5.cpp)]

##  <a name="ccombstr"></a>  CComBSTR::CComBSTR

O construtor. Construtor padrão define o [m_str](#m_str) membro como NULL.

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

*nSize*  
[in] O número de caracteres a serem copiados da *sz* ou o tamanho inicial em caracteres para o `CComBSTR`.

*SZ*  
[in] Uma cadeia de caracteres a serem copiados. A versão Unicode Especifica um LPCOLESTR; a versão ANSI Especifica um LPCSTR.

*pSrc*  
[in] Uma cadeia de caracteres a serem copiados. A versão Unicode Especifica um LPCOLESTR; a versão ANSI Especifica um LPCSTR.

*src*  
[in] Um `CComBSTR` objeto.

*guid*  
[in] Uma referência a um `GUID` estrutura.

### <a name="remarks"></a>Comentários

Os conjuntos de construtor de cópia `m_str` para uma cópia do membro do BSTR *src*. O `REFGUID` construtor converte o GUID em uma cadeia de caracteres usando `StringFromGUID2` e armazena o resultado.

O outro conjunto de construtores `m_str` para uma cópia da cadeia de caracteres especificada. Se você passar um valor *nSize*, então somente *nSize* caracteres serão copiados, seguido por um caractere nulo de terminação.

`CComBSTR` dá suporte à semântica de movimentação. Você pode usar o construtor de movimentação (o construtor que usa uma referência de rvalue (`&&`) para criar um novo objeto que usa os mesmos dados subjacentes, como o antigo objeto você passar como um argumento, sem a sobrecarga de copiar o objeto.

O destruidor libera a cadeia de caracteres apontada por `m_str`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#37](../../atl/codesnippet/cpp/ccombstr-class_6.cpp)]

##  <a name="dtor"></a>  CComBSTR:: ~ CComBSTR

O destruidor.

```
~CComBSTR();
```

### <a name="remarks"></a>Comentários

O destruidor libera a cadeia de caracteres apontada por `m_str`.

##  <a name="copy"></a>  CComBSTR::Copy

Aloca e retorna uma cópia do `m_str`.

```
BSTR Copy() const throw();
```

### <a name="return-value"></a>Valor de retorno

Uma cópia do [m_str](#m_str) membro. Se `m_str` for NULL, retornará NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#38](../../atl/codesnippet/cpp/ccombstr-class_7.cpp)]

##  <a name="copyto"></a>  CComBSTR::CopyTo

Aloca e retorna uma cópia do [m_str](#m_str) por meio do parâmetro.

```
HRESULT CopyTo(BSTR* pbstr) throw();

HRESULT CopyTo(VARIANT* pvarDest) throw();
```

### <a name="parameters"></a>Parâmetros

*pbstr*  
[out] O endereço do BSTR no qual retornar a cadeia de caracteres alocada por esse método.

*pvarDest*  
[out] O endereço de uma VARIANTE no qual retornar a cadeia de caracteres alocada por esse método.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT que indica o êxito ou falha da cópia.

### <a name="remarks"></a>Comentários

Depois de chamar esse método, a VARIANTE apontada por *pvarDest* será do tipo VT_BSTR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#39](../../atl/codesnippet/cpp/ccombstr-class_8.cpp)]

##  <a name="detach"></a>  CComBSTR::Detach

Desanexa [m_str](#m_str) da `CComBSTR` objeto e define `m_str` como NULL.

```
BSTR Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

O BSTR associado com o `CComBSTR` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#40](../../atl/codesnippet/cpp/ccombstr-class_9.cpp)]

##  <a name="empty"></a>  CComBSTR::Empty

Libera os [m_str](#m_str) membro.

```
void Empty() throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#41](../../atl/codesnippet/cpp/ccombstr-class_10.cpp)]

##  <a name="length"></a>  CComBSTR::Length

Retorna o número de caracteres em `m_str`, exceto o caractere nulo de terminação.

```
unsigned int Length() const throw();
```

### <a name="return-value"></a>Valor de retorno

O comprimento do [m_str](#m_str) membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#42](../../atl/codesnippet/cpp/ccombstr-class_11.cpp)]

##  <a name="loadstring"></a>  CComBSTR::LoadString

Carrega um recurso de cadeia de caracteres especificado por *nID* e o armazena no objeto.

```
bool LoadString(HINSTANCE hInst, UINT nID) throw();
bool LoadString(UINT nID) throw();
```

### <a name="parameters"></a>Parâmetros

Ver [LoadString](/windows/desktop/api/winuser/nf-winuser-loadstringa) no Windows SDK.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a cadeia de caracteres é carregada com êxito; Caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

A primeira função carrega o recurso do módulo identificado por você por meio de *hInst* parâmetro. A segunda função carrega o recurso do módulo de recursos associado com o [CComModule](../../atl/reference/ccommodule-class.md)-derivados do objeto usado neste projeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#43](../../atl/codesnippet/cpp/ccombstr-class_12.cpp)]

##  <a name="m_str"></a>  CComBSTR::m_str

Contém o BSTR associado com o `CComBSTR` objeto.

```
BSTR m_str;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#49](../../atl/codesnippet/cpp/ccombstr-class_13.cpp)]

##  <a name="operator_bstr"></a>  CComBSTR::operator BSTR

Converte um `CComBSTR` objeto para um BSTR.

```  
operator BSTR() const throw();
```

### <a name="remarks"></a>Comentários

Permite que você passe `CComBSTR` objetos para funções que têm **[BSTR in]** parâmetros.

### <a name="example"></a>Exemplo

Veja o exemplo de [CComBSTR::m_str](#m_str).

##  <a name="operator_not"></a>  CComBSTR::operator!

Verifica se a cadeia de caracteres BSTR é NULL.

```
bool operator!() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o [m_str](#m_str) membro for NULL; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este operador só verifica para um valor NULL, não para uma cadeia de caracteres vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]

##  <a name="operator_neq"></a>  CComBSTR::operator! =

Retorna a lógica oposta [operador = =](#operator_eq_eq).

```
bool operator!= (const CComBSTR& bstrSrc) const throw();
bool operator!= (LPCOLESTR pszSrc) const;
bool operator!= (LPCSTR pszSrc) const;
bool operator!= (int nNull) const throw();
```

### <a name="parameters"></a>Parâmetros

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*  
[in] Um `CComBSTR` objeto.

*pszSrc*  
[in] Uma cadeia de caracteres terminada em zero.

*nNull*  
[in] Deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o item que está sendo comparado não for igual ao `CComBSTR` objeto; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

`CComBSTR`s são comparados textualmente no contexto de localidade padrão do usuário. O operador de comparação final apenas compara a cadeia de caracteres contida em relação a NULL.

##  <a name="operator_amp"></a>  CComBSTR::operator &amp;

Retorna o endereço do BSTR armazenado em do [m_str](#m_str) membro.

```
BSTR* operator&() throw();
```

### <a name="remarks"></a>Comentários

`CComBstr operator &` tem uma declaração especial associados a ele para ajudar a identificar vazamentos de memória. O programa declarará quando o `m_str` membro é inicializado. Essa asserção foi criada para identificar situações em que um programador usa o `& operator` para atribuir um novo valor para `m_str` membro sem liberando a primeira alocação de `m_str`. Se `m_str` for igual a NULL, o programa presume que m_str não foi alocado ainda. Nesse caso, o programa não declara.

Essa asserção não está habilitada por padrão. Defina ATL_CCOMBSTR_ADDRESS_OF_ASSERT para habilitar essa asserção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#46](../../atl/codesnippet/cpp/ccombstr-class_14.cpp)]

[!code-cpp[NVC_ATL_Utilities#47](../../atl/codesnippet/cpp/ccombstr-class_15.cpp)]

##  <a name="operator_add_eq"></a>  + CComBSTR::operator =

Acrescenta uma cadeia de caracteres para o `CComBSTR` objeto.

```
CComBSTR& operator+= (const CComBSTR& bstrSrc);  
CComBSTR& operator+= (const LPCOLESTR pszSrc);
```

### <a name="parameters"></a>Parâmetros

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*  
[in] Um `CComBSTR` objeto a ser acrescentado.

*pszSrc*  
[in] Uma cadeia terminada em zero para acrescentar.

### <a name="remarks"></a>Comentários

`CComBSTR`s são comparados textualmente no contexto de localidade padrão do usuário. A comparação LPCOLESTR é feita usando `memcmp` nos dados brutos de cada cadeia de caracteres. A comparação LPCSTR é realizada da mesma forma depois que um Unicode temporário copiar de *pszSrc* foi criado. O operador de comparação final apenas compara a cadeia de caracteres contida em relação a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#48](../../atl/codesnippet/cpp/ccombstr-class_16.cpp)]

##  <a name="operator_lt"></a>  CComBSTR::operator &lt;

Compara um `CComBSTR` com uma cadeia de caracteres.

```
bool operator<(const CComBSTR& bstrSrc) const throw();
bool operator<(LPCOLESTR pszSrc) const throw();
bool operator<(LPCSTR pszSrc) const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o item que estão sendo comparado for menor do que o `CComBSTR` objeto; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

A comparação é realizada usando a localidade do usuário padrão.

##  <a name="operator_eq"></a>  CComBSTR::operator =

Conjuntos de [m_str](#m_str) membro a uma cópia do *pSrc* ou para uma cópia do membro do BSTR *src*. O operador de atribuição de movimentação move `src` sem copiá-lo.

```
CComBSTR& operator= (const CComBSTR& src);  
CComBSTR& operator= (LPCOLESTR pSrc);  
CComBSTR& operator= (LPCSTR pSrc);
CComBSTR& operator= (CComBSTR&& src) throw(); // (Visual Studio 2017)
```

### <a name="remarks"></a>Comentários

O *pSrc* parâmetro especifica o um LPCOLESTR para versões Unicode ou LPCSTR para versões ANSI.

### <a name="example"></a>Exemplo

Veja o exemplo de [CComBSTR::Copy](#copy).

##  <a name="operator_eq_eq"></a>  CComBSTR::operator = =

Compara um `CComBSTR` com uma cadeia de caracteres. `CComBSTR`s são comparados textualmente no contexto de localidade padrão do usuário.

```
bool operator== (const CComBSTR& bstrSrc) const throw();
bool operator== (LPCOLESTR pszSrc) const;
bool operator== (LPCSTR pszSrc) const;
bool operator== (int nNull) const throw();
```

### <a name="parameters"></a>Parâmetros

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*  
[in] Um `CComBSTR` objeto.

*pszSrc*  
[in] Uma cadeia de caracteres terminada em zero.

*nNull*  
[in] Deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o item que está sendo comparado é igual ao `CComBSTR` objeto; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

O operador de comparação final apenas compara a cadeia de caracteres contida em relação a NULL.

##  <a name="operator_gt"></a>  CComBSTR::operator &gt;

Compara um `CComBSTR` com uma cadeia de caracteres.

```
bool operator>(const CComBSTR& bstrSrc) const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o item que estão sendo comparado for maior que o `CComBSTR` objeto; caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

A comparação é realizada usando a localidade do usuário padrão.

##  <a name="readfromstream"></a>  CComBSTR::ReadFromStream

Define o [m_str](#m_str) membro para o BSTR contido em um fluxo especificado.

```
HRESULT ReadFromStream(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*  
[in] Um ponteiro para o [IStream](/windows/desktop/api/objidl/nn-objidl-istream) interface no fluxo que contém os dados.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

`ReadToStream` requer o conteúdo do fluxo da posição atual para ser compatível com o formato de dados gravado por uma chamada para [WriteToStream](#writetostream).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#44](../../atl/codesnippet/cpp/ccombstr-class_17.cpp)]

##  <a name="tolower"></a>  CComBSTR::ToLower

Converte a cadeia de caracteres contida em minúsculas.

```
HRESULT ToLower() throw();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Consulte `CharLowerBuff` para obter mais informações sobre como a conversão é executada.

##  <a name="toupper"></a>  CComBSTR::ToUpper

Converte a cadeia de caracteres contida em maiusculas.

```
HRESULT ToUpper() throw();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Consulte `CharUpperBuff` para obter mais informações sobre como a conversão é executada.

##  <a name="writetostream"></a>  CComBSTR::WriteToStream

Salva o [m_str](#m_str) membro em um fluxo.

```
HRESULT WriteToStream(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*  
[in] Um ponteiro para o [IStream](/windows/desktop/api/objidl/nn-objidl-istream) interface em um fluxo.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Você pode recriar um BSTR do conteúdo de fluxo usando o [ReadFromStream](#readfromstream) função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#45](../../atl/codesnippet/cpp/ccombstr-class_18.cpp)]

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)   
[ATL e Macros de conversão de cadeia de caracteres MFC](string-conversion-macros.md)
