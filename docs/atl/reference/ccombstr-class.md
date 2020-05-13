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
ms.openlocfilehash: c1448a5638b263a87403edf0baca170f0f952e26
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748142"
---
# <a name="ccombstr-class"></a>Classe CComBSTR

Esta classe é um invólucro para [BSTR](/previous-versions/windows/desktop/automat/bstr)s.

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
|[CComBSTR::Apêndice](#append)|Anexa uma seqüência para `m_str`.|
|[CComBSTR::Apêndice](#appendbstr)|Anexa um BSTR `m_str`para .|
|[CComBSTR::Apêndices](#appendbytes)|Anexa um número especificado de `m_str`bytes para .|
|[CComBSTR::ArrayToBSTR](#arraytobstr)|Cria um BSTR a partir do primeiro caractere de cada `CComBSTR` elemento no safearray e o anexa ao objeto.|
|[CComBSTR::AtribuirBSTR](#assignbstr)|Atribui um BSTR `m_str`a .|
|[CComBSTR::Anexar](#attach)|Anexa um BSTR `CComBSTR` ao objeto.|
|[CComBSTR::BSTRTOARRAY](#bstrtoarray)|Cria um safearray unidimensional baseado em zero, onde cada elemento `CComBSTR` da matriz é um caractere do objeto.|
|[CComBSTR::ByteLength](#bytelength)|Retorna o `m_str` comprimento de bytes.|
|[CComBSTR::Cópia](#copy)|Devolve uma `m_str`cópia de .|
|[CComBSTR::CopyTo](#copyto)|Retorna uma `m_str` cópia de através de um parâmetro **[out]**|
|[CComBSTR::Detach](#detach)|Se `m_str` desprende `CComBSTR` do objeto.|
|[CComBSTR::Vazio](#empty)|`m_str`Grátis.|
|[CComBSTR::Comprimento](#length)|Retorna o `m_str`comprimento de .|
|[CComBSTR::LoadString](#loadstring)|Carrega um recurso de seqüência.|
|[CComBSTR::ReadFromStream](#readfromstream)|Carrega um objeto BSTR de um fluxo.|
|[CComBSTR::ToLower](#tolower)|Converte a string em minúsculas.|
|[CComBSTR::Toupper](#toupper)|Converte a string em maiúsculas.|
|[CComBSTR::WriteToStream](#writetostream)|Economiza `m_str` em um córrego.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::operador BSTR](#operator_bstr)|Lança um `CComBSTR` objeto para um BSTR.|
|[CComBSTR::operador !](#operator_not)|Retorna TRUE ou FALSE, `m_str`dependendo se é NULO.|
|[CComBSTR::operador !=](#operator_neq)|Compara `CComBSTR` a com uma corda.|
|[CComBSTR::&do operador](#operator_amp)|Retorna o `m_str`endereço de .|
|[CComBSTR::operador +=](#operator_add_eq)|Anexa um `CComBSTR` ao objeto.|
|[CComBSTR::<do operador](#operator_lt)|Compara `CComBSTR` a com uma corda.|
|[CComBSTR::operador =](#operator_eq)|Atribui um valor `m_str`a .|
|[CComBSTR::operador ==](#operator_eq_eq)|Compara `CComBSTR` a com uma corda.|
|[CComBSTR::>do operador](#operator_gt)|Compara `CComBSTR` a com uma corda.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComBSTR::m_str](#m_str)|Contém o BSTR `CComBSTR` associado ao objeto.|

## <a name="remarks"></a>Comentários

A `CComBSTR` classe é um invólucro para BSTRs, que são cordas prefixadas de comprimento. O comprimento é armazenado como um inteiro no local de memória que precede os dados na seqüência.

Um [BSTR](/previous-versions/windows/desktop/automat/bstr) é nulo após o último caractere contado, mas também pode conter caracteres nulos incorporados dentro da seqüência. O comprimento da seqüência é determinado pela contagem de caracteres, não pelo primeiro caractere nulo.

> [!NOTE]
> A `CComBSTR` classe fornece um número de membros (construtores, operadores de atribuição e operadores de comparação) que tomam as seqüências ANSI ou Unicode como argumentos. As versões ANSI dessas funções são menos eficientes do que suas contrapartes Unicode porque as seqüências Unicode temporárias são frequentemente criadas internamente. Para obter eficiência, use as versões Unicode sempre que possível.

> [!NOTE]
> Devido ao melhor comportamento de procuração implementado no Visual `bstr = L"String2" + bstr;`Studio .NET, código como , que pode `bstr = CStringW(L"String2") + bstr`ter compilado em versões anteriores, deve ser implementado como .

Para obter uma lista `CComBSTR`de cuidados ao usar, consulte [Programação com CComBSTR](../../atl/programming-with-ccombstr-atl.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccombstrappend"></a><a name="append"></a>CComBSTR::Apêndice

Anexa-se *ao lpsz* ou ao membro BSTR do *bstrSrc* para [m_str](#m_str).

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
[em] Um `CComBSTR` objeto para anexar.

*Ch*<br/>
[em] Um personagem a anexar.

*Lpsz*<br/>
[em] Uma seqüência de caracteres com término zero para anexar. Você pode passar uma seqüência unicode através da sobrecarga LPCOLESTR ou de uma seqüência ANSI através da versão LPCSTR.

*nLen*<br/>
[em] O número de caracteres de *lpsz* para anexar.

### <a name="return-value"></a>Valor retornado

S_OK no sucesso ou em qualquer valor de erro HRESULT padrão.

### <a name="remarks"></a>Comentários

Uma seqüência ANSI será convertida em Unicode antes de ser anexada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#32](../../atl/codesnippet/cpp/ccombstr-class_1.cpp)]

## <a name="ccombstrappendbstr"></a><a name="appendbstr"></a>CComBSTR::Apêndice

Anexa o BSTR especificado para [m_str](#m_str).

```
HRESULT AppendBSTR(BSTR p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Um BSTR para anexar.

### <a name="return-value"></a>Valor retornado

S_OK no sucesso ou em qualquer valor de erro HRESULT padrão.

### <a name="remarks"></a>Comentários

Não passe uma seqüência de caracteres largos ordinária para este método. O compilador não pode captar o erro e erros de tempo de execução ocorrerão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#33](../../atl/codesnippet/cpp/ccombstr-class_2.cpp)]

## <a name="ccombstrappendbytes"></a><a name="appendbytes"></a>CComBSTR::Apêndices

Anexa o número especificado de bytes para [m_str](#m_str) sem conversão.

```
HRESULT AppendBytes(const char* lpsz, int nLen) throw();
```

### <a name="parameters"></a>Parâmetros

*Lpsz*<br/>
[em] Um ponteiro para uma matriz de bytes para anexar.

*P*<br/>
[em] O número de bytes a anexar.

### <a name="return-value"></a>Valor retornado

S_OK no sucesso ou em qualquer valor de erro HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#34](../../atl/codesnippet/cpp/ccombstr-class_3.cpp)]

## <a name="ccombstrarraytobstr"></a><a name="arraytobstr"></a>CComBSTR::ArrayToBSTR

Libera qualquer string existente mantida `CComBSTR` no objeto, em seguida, cria um BSTR a partir do `CComBSTR` primeiro caractere de cada elemento no safearray e anexa-o ao objeto.

```
HRESULT ArrayToBSTR(const SAFEARRAY* pSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*Psrc*<br/>
[em] O safearray contendo os elementos usados para criar a seqüência.

### <a name="return-value"></a>Valor retornado

S_OK no sucesso ou em qualquer valor de erro HRESULT padrão.

## <a name="ccombstrassignbstr"></a><a name="assignbstr"></a>CComBSTR::AtribuirBSTR

Atribui um BSTR ao [m_str](#m_str).

```
HRESULT AssignBSTR(const BSTR bstrSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
[em] Um BSTR para atribuir `CComBSTR` ao objeto atual.

### <a name="return-value"></a>Valor retornado

S_OK no sucesso ou em qualquer valor de erro HRESULT padrão.

## <a name="ccombstrattach"></a><a name="attach"></a>CComBSTR::Anexar

Anexa um BSTR `CComBSTR` ao objeto definindo o [membro m_str](#m_str) para *src*.

```cpp
void Attach(BSTR src) throw();
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] O BSTR para anexar ao objeto.

### <a name="remarks"></a>Comentários

Não passe uma seqüência de caracteres largos ordinária para este método. O compilador não pode captar o erro e erros de tempo de execução ocorrerão.

> [!NOTE]
> Este método afirmará se `m_str` não for NULO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]

## <a name="ccombstrbstrtoarray"></a><a name="bstrtoarray"></a>CComBSTR::BSTRTOARRAY

Cria um safearray unidimensional baseado em zero, onde cada elemento `CComBSTR` da matriz é um caractere do objeto.

```
HRESULT BSTRToArray(LPSAFEARRAY* ppArray) throw();
```

### <a name="parameters"></a>Parâmetros

*ppArray*<br/>
[fora] O ponteiro para o safearray usado para conter os resultados da função.

### <a name="return-value"></a>Valor retornado

S_OK no sucesso ou em qualquer valor de erro HRESULT padrão.

## <a name="ccombstrbytelength"></a><a name="bytelength"></a>CComBSTR::ByteLength

Retorna o número de `m_str`bytes em , excluindo o caractere nulo final.

```
unsigned int ByteLength() const throw();
```

### <a name="return-value"></a>Valor retornado

O comprimento do [m_str](#m_str) membro em bytes.

### <a name="remarks"></a>Comentários

Retorna 0 `m_str` se for NULO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#36](../../atl/codesnippet/cpp/ccombstr-class_5.cpp)]

## <a name="ccombstrccombstr"></a><a name="ccombstr"></a>CComBSTR::CComBSTR

O construtor. O construtor padrão define o [membro m_str](#m_str) como NULA.

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

*Nsize*<br/>
[em] O número de caracteres a copiar de *sz* ou o tamanho inicial em caracteres para o `CComBSTR`.

*Sz*<br/>
[em] Uma corda para copiar. A versão Unicode especifica um LPCOLESTR; a versão ANSI especifica um LPCSTR.

*Psrc*<br/>
[em] Uma corda para copiar. A versão Unicode especifica um LPCOLESTR; a versão ANSI especifica um LPCSTR.

*src*<br/>
[em] Um `CComBSTR` objeto.

*guid*<br/>
[em] Uma referência `GUID` a uma estrutura.

### <a name="remarks"></a>Comentários

O construtor de `m_str` cópias define para uma cópia do membro BSTR do *src*. O `REFGUID` construtor converte o GUID `StringFromGUID2` em uma string usando e armazena o resultado.

Os outros construtores `m_str` definiram uma cópia da seqüência especificada. Se você passar um valor para *nSize,* então apenas caracteres *nSize* serão copiados, seguidos por um caractere nulo final.

`CComBSTR`suporta semântica de movimento. Você pode usar o construtor move (o construtor que`&&`leva uma referência de valor ( ) para criar um novo objeto que usa os mesmos dados subjacentes que o objeto antigo que você passa como argumento, sem a sobrecarga de copiar o objeto.

O destruidor libera a corda apontada por `m_str`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#37](../../atl/codesnippet/cpp/ccombstr-class_6.cpp)]

## <a name="ccombstrccombstr"></a><a name="dtor"></a>CComBSTR::~CComBSTR

O destruidor.

```
~CComBSTR();
```

### <a name="remarks"></a>Comentários

O destruidor libera a corda apontada por `m_str`.

## <a name="ccombstrcopy"></a><a name="copy"></a>CComBSTR::Cópia

Aloca e devolve uma `m_str`cópia de .

```
BSTR Copy() const throw();
```

### <a name="return-value"></a>Valor retornado

Uma cópia do membro [m_str.](#m_str) Se `m_str` for NULO, retorna NULO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#38](../../atl/codesnippet/cpp/ccombstr-class_7.cpp)]

## <a name="ccombstrcopyto"></a><a name="copyto"></a>CComBSTR::CopyTo

Aloca e devolve uma cópia de [m_str](#m_str) através do parâmetro.

```
HRESULT CopyTo(BSTR* pbstr) throw();

HRESULT CopyTo(VARIANT* pvarDest) throw();
```

### <a name="parameters"></a>Parâmetros

*Pbstr*<br/>
[fora] O endereço de um BSTR no qual retornar a string alocada por este método.

*pvarDest*<br/>
[fora] O endereço de uma VARIANT para retornar a seqüência alocada por este método.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão indicando o sucesso ou falha da cópia.

### <a name="remarks"></a>Comentários

Depois de chamar este método, a VARIANT apontada por *pvarDest* será do tipo VT_BSTR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#39](../../atl/codesnippet/cpp/ccombstr-class_8.cpp)]

## <a name="ccombstrdetach"></a><a name="detach"></a>CComBSTR::Detach

Destaca [m_str](#m_str) do `CComBSTR` objeto e `m_str` define para NULL.

```
BSTR Detach() throw();
```

### <a name="return-value"></a>Valor retornado

O BSTR associado `CComBSTR` ao objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#40](../../atl/codesnippet/cpp/ccombstr-class_9.cpp)]

## <a name="ccombstrempty"></a><a name="empty"></a>CComBSTR::Vazio

Libera o [membro m_str.](#m_str)

```cpp
void Empty() throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#41](../../atl/codesnippet/cpp/ccombstr-class_10.cpp)]

## <a name="ccombstrlength"></a><a name="length"></a>CComBSTR::Comprimento

Retorna o número `m_str`de caracteres em , excluindo o caractere nulo terminando.

```
unsigned int Length() const throw();
```

### <a name="return-value"></a>Valor retornado

O comprimento do [membro m_str.](#m_str)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#42](../../atl/codesnippet/cpp/ccombstr-class_11.cpp)]

## <a name="ccombstrloadstring"></a><a name="loadstring"></a>CComBSTR::LoadString

Carrega um recurso de string especificado por *nID* e armazena-o neste objeto.

```
bool LoadString(HINSTANCE hInst, UINT nID) throw();
bool LoadString(UINT nID) throw();
```

### <a name="parameters"></a>Parâmetros

Consulte [LoadString](/windows/win32/api/winuser/nf-winuser-loadstringw) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a seqüência for carregada com sucesso; caso contrário, retorna FALSO.

### <a name="remarks"></a>Comentários

A primeira função carrega o recurso do módulo identificado por você através do parâmetro *hInst.* A segunda função carrega o recurso do módulo de recursos associado ao objeto derivado do [CComModule](../../atl/reference/ccommodule-class.md)usado neste projeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#43](../../atl/codesnippet/cpp/ccombstr-class_12.cpp)]

## <a name="ccombstrm_str"></a><a name="m_str"></a>CComBSTR::m_str

Contém o BSTR `CComBSTR` associado ao objeto.

```
BSTR m_str;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#49](../../atl/codesnippet/cpp/ccombstr-class_13.cpp)]

## <a name="ccombstroperator-bstr"></a><a name="operator_bstr"></a>CComBSTR::operador BSTR

Lança um `CComBSTR` objeto para um BSTR.

```
operator BSTR() const throw();
```

### <a name="remarks"></a>Comentários

Permite que `CComBSTR` você passe objetos para funções que tenham [in] parâmetros **BSTR.**

### <a name="example"></a>Exemplo

Veja o exemplo de [CComBSTR::m_str](#m_str).

## <a name="ccombstroperator-"></a><a name="operator_not"></a>CComBSTR::operador !

Verifica se a seqüência BSTR é NULL.

```
bool operator!() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o membro [m_str](#m_str) for NULO; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este operador só verifica um valor NULL, não para uma seqüência vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#35](../../atl/codesnippet/cpp/ccombstr-class_4.cpp)]

## <a name="ccombstroperator-"></a><a name="operator_neq"></a>CComBSTR::operador !=

Retorna o oposto lógico do [operador ==](#operator_eq_eq).

```
bool operator!= (const CComBSTR& bstrSrc) const throw();
bool operator!= (LPCOLESTR pszSrc) const;
bool operator!= (LPCSTR pszSrc) const;
bool operator!= (int nNull) const throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
[em] Um `CComBSTR` objeto.

*pszSrc*<br/>
[em] Uma seqüência de zero terminada.

*nNull*<br/>
[em] Deve ser NULO.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item a `CComBSTR` ser comparado não for igual ao objeto; caso contrário, retorna FALSO.

### <a name="remarks"></a>Comentários

`CComBSTR`s são comparados texuticamente no contexto da localidade padrão do usuário. O operador de comparação final apenas compara a string contida com NULL.

## <a name="ccombstroperator-amp"></a><a name="operator_amp"></a>CComBSTR::operador&amp;

Retorna o endereço do BSTR armazenado no [membro m_str.](#m_str)

```
BSTR* operator&() throw();
```

### <a name="remarks"></a>Comentários

`CComBstr operator &`tem uma afirmação especial associada a ele para ajudar a identificar vazamentos de memória. O programa afirmará `m_str` quando o membro for inicializado. Essa afirmação foi criada para identificar situações em que um programador usa o `& operator` para atribuir um novo valor ao `m_str` membro sem liberar a primeira alocação de `m_str`. Se `m_str` é igual a NULL, o programa assume que m_str ainda não foi alocado. Neste caso, o programa não vai afirmar.

Essa afirmação não é habilitada por padrão. Defina ATL_CCOMBSTR_ADDRESS_OF_ASSERT para permitir essa afirmação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#46](../../atl/codesnippet/cpp/ccombstr-class_14.cpp)]

[!code-cpp[NVC_ATL_Utilities#47](../../atl/codesnippet/cpp/ccombstr-class_15.cpp)]

## <a name="ccombstroperator-"></a><a name="operator_add_eq"></a>CComBSTR::operador +=

Anexa uma corda `CComBSTR` ao objeto.

```
CComBSTR& operator+= (const CComBSTR& bstrSrc);
CComBSTR& operator+= (const LPCOLESTR pszSrc);
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
[em] Um `CComBSTR` objeto para anexar.

*pszSrc*<br/>
[em] Uma seqüência de zero terminada para anexar.

### <a name="remarks"></a>Comentários

`CComBSTR`s são comparados texuticamente no contexto da localidade padrão do usuário. A comparação LPCOLESTR `memcmp` é feita usando os dados brutos em cada string. A comparação LPCSTR é realizada da mesma forma que uma cópia Unicode temporária do *pszSrc* foi criada. O operador de comparação final apenas compara a string contida com NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#48](../../atl/codesnippet/cpp/ccombstr-class_16.cpp)]

## <a name="ccombstroperator-lt"></a><a name="operator_lt"></a>CComBSTR::operador&lt;

Compara `CComBSTR` a com uma corda.

```
bool operator<(const CComBSTR& bstrSrc) const throw();
bool operator<(LPCOLESTR pszSrc) const throw();
bool operator<(LPCSTR pszSrc) const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item a `CComBSTR` ser comparado for menor que o objeto; caso contrário, retorna FALSO.

### <a name="remarks"></a>Comentários

A comparação é realizada usando a localização padrão do usuário.

## <a name="ccombstroperator-"></a><a name="operator_eq"></a>CComBSTR::operador =

Define o membro [m_str](#m_str) para uma cópia do *pSrc* ou para uma cópia do membro BSTR do *src*. O operador de `src` atribuição de movimento se move sem copiá-lo.

```
CComBSTR& operator= (const CComBSTR& src);
CComBSTR& operator= (LPCOLESTR pSrc);
CComBSTR& operator= (LPCSTR pSrc);
CComBSTR& operator= (CComBSTR&& src) throw(); // (Visual Studio 2017)
```

### <a name="remarks"></a>Comentários

O parâmetro *pSrc* especifica um LPCOLESTR para versões Unicode ou LPCSTR para versões ANSI.

### <a name="example"></a>Exemplo

Veja o exemplo de [CComBSTR::Copy](#copy).

## <a name="ccombstroperator-"></a><a name="operator_eq_eq"></a>CComBSTR::operador ==

Compara `CComBSTR` a com uma corda. `CComBSTR`s são comparados texuticamente no contexto da localidade padrão do usuário.

```
bool operator== (const CComBSTR& bstrSrc) const throw();
bool operator== (LPCOLESTR pszSrc) const;
bool operator== (LPCSTR pszSrc) const;
bool operator== (int nNull) const throw();
```

### <a name="parameters"></a>Parâmetros

*bstrSrc*<br/>
[em] Um `CComBSTR` objeto.

*pszSrc*<br/>
[em] Uma seqüência de zero terminada.

*nNull*<br/>
[em] Deve ser NULO.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item a `CComBSTR` ser comparado for igual ao objeto; caso contrário, retorna FALSO.

### <a name="remarks"></a>Comentários

O operador de comparação final apenas compara a string contida com NULL.

## <a name="ccombstroperator-gt"></a><a name="operator_gt"></a>CComBSTR::operador&gt;

Compara `CComBSTR` a com uma corda.

```
bool operator>(const CComBSTR& bstrSrc) const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item a `CComBSTR` ser comparado for maior que o objeto; caso contrário, retorna FALSO.

### <a name="remarks"></a>Comentários

A comparação é realizada usando a localização padrão do usuário.

## <a name="ccombstrreadfromstream"></a><a name="readfromstream"></a>CComBSTR::ReadFromStream

Define o [membro m_str](#m_str) para o BSTR contido no fluxo especificado.

```
HRESULT ReadFromStream(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[em] Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) no fluxo que contém os dados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`ReadToStream`requer que o conteúdo do fluxo na posição atual seja compatível com o formato de dados gravado por uma chamada para [WriteToStream](#writetostream).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#44](../../atl/codesnippet/cpp/ccombstr-class_17.cpp)]

## <a name="ccombstrtolower"></a><a name="tolower"></a>CComBSTR::ToLower

Converte a seqüência contida em minúscula.

```
HRESULT ToLower() throw();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulte `CharLowerBuff` para obter mais informações sobre como a conversão é realizada.

## <a name="ccombstrtoupper"></a><a name="toupper"></a>CComBSTR::Toupper

Converte a seqüência contida em maiúsculas.

```
HRESULT ToUpper() throw();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulte `CharUpperBuff` para obter mais informações sobre como a conversão é realizada.

## <a name="ccombstrwritetostream"></a><a name="writetostream"></a>CComBSTR::WriteToStream

Salva o [membro m_str](#m_str) em um fluxo.

```
HRESULT WriteToStream(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[em] Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) em um fluxo.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode recriar um BSTR a partir do conteúdo do fluxo usando a função [ReadFromStream.](#readfromstream)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#45](../../atl/codesnippet/cpp/ccombstr-class_18.cpp)]

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Macros de conversão de strings ATL e MFC](string-conversion-macros.md)
