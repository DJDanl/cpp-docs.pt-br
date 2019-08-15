---
title: Classe CComSafeArray
ms.date: 05/06/2019
f1_keywords:
- CComSafeArray
- ATLSAFE/ATL::CComSafeArray
- ATLSAFE/ATL::CComSafeArray::CComSafeArray
- ATLSAFE/ATL::CComSafeArray::Add
- ATLSAFE/ATL::CComSafeArray::Attach
- ATLSAFE/ATL::CComSafeArray::CopyFrom
- ATLSAFE/ATL::CComSafeArray::CopyTo
- ATLSAFE/ATL::CComSafeArray::Create
- ATLSAFE/ATL::CComSafeArray::Destroy
- ATLSAFE/ATL::CComSafeArray::Detach
- ATLSAFE/ATL::CComSafeArray::GetAt
- ATLSAFE/ATL::CComSafeArray::GetCount
- ATLSAFE/ATL::CComSafeArray::GetDimensions
- ATLSAFE/ATL::CComSafeArray::GetLowerBound
- ATLSAFE/ATL::CComSafeArray::GetSafeArrayPtr
- ATLSAFE/ATL::CComSafeArray::GetType
- ATLSAFE/ATL::CComSafeArray::GetUpperBound
- ATLSAFE/ATL::CComSafeArray::IsSizable
- ATLSAFE/ATL::CComSafeArray::MultiDimGetAt
- ATLSAFE/ATL::CComSafeArray::MultiDimSetAt
- ATLSAFE/ATL::CComSafeArray::Resize
- ATLSAFE/ATL::CComSafeArray::SetAt
- ATLSAFE/ATL::CComSafeArray::m_psa
helpviewer_keywords:
- CComSafeArray class
ms.assetid: ee349aef-33db-4c85-bd08-5d86a3c9d53a
ms.openlocfilehash: 36750990dc62d5b24cf1107ac8a2724df787a47d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496990"
---
# <a name="ccomsafearray-class"></a>Classe CComSafeArray

Essa classe é um wrapper para a `SAFEARRAY` estrutura.

## <a name="syntax"></a>Sintaxe

```
template <typename T, VARTYPE _vartype = _ATL_AutomationType<T>::type>
class CComSafeArray
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na matriz.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeArray::CComSafeArray](#ccomsafearray)|O construtor.|
|[CComSafeArray::~CComSafeArray](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeArray::Add](#add)|Adiciona um ou mais elementos, ou uma `SAFEARRAY` estrutura, a um `CComSafeArray`.|
|[CComSafeArray::Attach](#attach)|Anexa uma `SAFEARRAY` estrutura a um `CComSafeArray` objeto.|
|[CComSafeArray::CopyFrom](#copyfrom)|Copia o conteúdo de uma `SAFEARRAY` estrutura para o `CComSafeArray` objeto.|
|[CComSafeArray::CopyTo](#copyto)|Cria uma cópia do objeto `CComSafeArray`.|
|[CComSafeArray::Create](#create)|Cria um objeto `CComSafeArray`.|
|[CComSafeArray::Destroy](#destroy)|Destrói um objeto `CComSafeArray`.|
|[CComSafeArray::Detach](#detach)|Desanexa um `SAFEARRAY` de um `CComSafeArray` objeto.|
|[CComSafeArray::GetAt](#getat)|Recupera um único elemento de uma matriz unidimensional.|
|[CComSafeArray::GetCount](#getcount)|Retorna o número de elementos na matriz.|
|[CComSafeArray::GetDimensions](#getdimensions)|Retorna o número de dimensões na matriz.|
|[CComSafeArray::GetLowerBound](#getlowerbound)|Retorna o limite inferior de uma determinada dimensão da matriz.|
|[CComSafeArray::GetSafeArrayPtr](#getsafearrayptr)|Retorna o endereço do membro `m_psa` de dados.|
|[CComSafeArray::GetType](#gettype)|Retorna o tipo de dados armazenados na matriz.|
|[CComSafeArray::GetUpperBound](#getupperbound)|Retorna o limite superior de qualquer dimensão da matriz.|
|[CComSafeArray::IsSizable](#issizable)|Testa se um `CComSafeArray` objeto pode ser redimensionado.|
|[CComSafeArray::MultiDimGetAt](#multidimgetat)|Recupera um único elemento de uma matriz multidimensional.|
|[CComSafeArray::MultiDimSetAt](#multidimsetat)|Define o valor de um elemento em uma matriz multidimensional.|
|[CComSafeArray::Resize](#resize)|Redimensiona um `CComSafeArray` objeto.|
|[CComSafeArray::SetAt](#setat)|Define o valor de um elemento em uma matriz unidimensional.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CComSafeArray:: Operator LPSAFEARRAY](#operator_lpsafearray)|Converte um valor em um `SAFEARRAY` ponteiro.|
|[CComSafeArray::operator\[\]](ccomsafearray-class.md#operator_at)|Recupera um elemento da matriz.|
|[CComSafeArray:: Operator =](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeArray::m_psa](#m_psa)|Esse membro de dados contém o endereço da `SAFEARRAY` estrutura.|

## <a name="remarks"></a>Comentários

`CComSafeArray`fornece um wrapper para a classe de [tipo de dados SafeArray](/windows/win32/api/oaidl/ns-oaidl-tagsafearray) , tornando simples a criação e o gerenciamento de matrizes únicas e multidimensionais de quase qualquer um dos tipos com suporte de variante.

`CComSafeArray`simplifica a passagem de matrizes entre processos e, além disso, fornece segurança extra verificando valores de índice de matriz em relação aos limites superior e inferior.

O limite inferior de um `CComSafeArray` pode iniciar em qualquer valor definido pelo usuário; no entanto, as matrizes C++ que são acessadas por meio do devem usar um limite inferior de 0. Outras linguagens como Visual Basic podem usar outros valores delimitadores (por exemplo,-10 a 10).

Use [CComSafeArray:: Create](#create) para criar um `CComSafeArray` objeto e [CComSafeArray::D estroy](#destroy) para excluí-lo.

Um `CComSafeArray` pode conter o seguinte subconjunto de tipos de dados variantes:

|VARTYPE|Descrição|
|-------------|-----------------|
|VT_I1|char|
|VT_I2|short|
|VT_I4|int|
|VT_I4|long|
|VT_I8|longlong|
|VT_UI1|byte|
|VT_UI2|ushort|
|VT_UI4|uint|
|VT_UI4|ulong|
|VT_UI8|ulonglong|
|VT_R4|float|
|VT_R8|double|
|VT_DECIMAL|ponteiro decimal|
|VT_VARIANT|ponteiro de variante|
|VT_CY|tipo de dados Currency|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsafe. h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#75](../../atl/codesnippet/cpp/ccomsafearray-class_1.cpp)]

##  <a name="add"></a>  CComSafeArray::Add

Adiciona um ou mais elementos, ou uma `SAFEARRAY` estrutura, a um `CComSafeArray`.

```
HRESULT Add(const SAFEARRAY* psaSrc);
HRESULT Add(ULONG ulCount, const T* pT, BOOL bCopy = TRUE);
HRESULT Add(const T& t, BOOL bCopy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*psaSrc*<br/>
Um ponteiro para um `SAFEARRAY` objeto.

*ulCount*<br/>
O número de objetos a serem adicionados à matriz.

*pT*<br/>
Um ponteiro para um ou mais objetos a serem adicionados à matriz.

*t*<br/>
Uma referência ao objeto a ser adicionado à matriz.

*bCopy*<br/>
Indica se uma cópia dos dados deve ser criada. O valor padrão é TRUE.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Os novos objetos são anexados ao final do objeto existente `SAFEARRAY` . Não há suporte para a adição de um `SAFEARRAY` objeto a um objeto multidimensional. Ao adicionar uma matriz existente de objetos, ambas as matrizes devem conter elementos do mesmo tipo.

O sinalizador *bcopy* é levado em conta quando elementos do tipo BSTR ou Variant são adicionados a uma matriz. O valor padrão de TRUE garante que uma nova cópia seja feita dos dados quando o elemento for adicionado à matriz.

##  <a name="attach"></a>CComSafeArray:: Attach

Anexa uma `SAFEARRAY` estrutura a um `CComSafeArray` objeto.

```
HRESULT Attach(const SAFEARRAY* psaSrc);
```

### <a name="parameters"></a>Parâmetros

*psaSrc*<br/>
Um ponteiro para a `SAFEARRAY` estrutura.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Anexa uma `SAFEARRAY` estrutura a um `CComSafeArray` objeto, tornando os métodos existentes `CComSafeArray` disponíveis.

##  <a name="ccomsafearray"></a>  CComSafeArray::CComSafeArray

O construtor.

```
CComSafeArray();
CComSafeArray(const SAFEARRAYBOUND& bound);
CComSafeArray(ULONG  ulCount, LONG lLBound = 0);
CComSafeArray(const SAFEARRAYBOUND* pBound, UINT uDims = 1);
CComSafeArray(const CComSafeArray& saSrc);
CComSafeArray(const SAFEARRAY& saSrc);
CComSafeArray(const SAFEARRAY* psaSrc);
```

### <a name="parameters"></a>Parâmetros

*bound*<br/>
Uma estrutura `SAFEARRAYBOUND`.

*ulCount*<br/>
O número de elementos na matriz.

*lLBound*<br/>
O valor de limite inferior; ou seja, o índice do primeiro elemento na matriz.

*pBound*<br/>
Um ponteiro para uma `SAFEARRAYBOUND` estrutura.

*uDims*<br/>
A contagem de dimensões na matriz.

*saSrc*<br/>
Uma referência a uma `SAFEARRAY` estrutura ou `CComSafeArray` a um objeto. Em ambos os casos, o construtor usa essa referência para fazer uma cópia da matriz, portanto, a matriz não é referenciada após a construção.

*psaSrc*<br/>
Um ponteiro para uma `SAFEARRAY` estrutura. O construtor usa esse endereço para fazer uma cópia da matriz, portanto, a matriz não é referenciada após a construção.

### <a name="remarks"></a>Comentários

Cria um objeto `CComSafeArray`.

##  <a name="dtor"></a>  CComSafeArray::~CComSafeArray

O destruidor.

```
~CComSafeArray() throw()
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="copyfrom"></a>  CComSafeArray::CopyFrom

Copia o conteúdo de uma `SAFEARRAY` estrutura para o `CComSafeArray` objeto.

```
HRESULT CopyFrom(LPSAFEARRAY* ppArray);
```

### <a name="parameters"></a>Parâmetros

*ppArray*<br/>
Ponteiro para o `SAFEARRAY` a ser copiado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método copia o conteúdo de um `SAFEARRAY` para o objeto `CComSafeArray` atual. O conteúdo existente da matriz é substituído.

##  <a name="copyto"></a>CComSafeArray:: CopyTo

Cria uma cópia do objeto `CComSafeArray`.

```
HRESULT CopyTo(LPSAFEARRAY* ppArray);
```

### <a name="parameters"></a>Parâmetros

*ppArray*<br/>
Um ponteiro para um local no qual criar o novo `SAFEARRAY`.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método copia o conteúdo de um `CComSafeArray` objeto em uma `SAFEARRAY` estrutura.

##  <a name="create"></a>  CComSafeArray::Create

Cria um `CComSafeArray`.

```
HRESULT Create(const SAFEARRAYBOUND* pBound, UINT uDims = 1);
HRESULT Create(ULONG ulCount = 0, LONG lLBound = 0);
```

### <a name="parameters"></a>Parâmetros

*pBound*<br/>
Um ponteiro para um `SAFEARRAYBOUND` objeto.

*uDims*<br/>
O número de dimensões na matriz.

*ulCount*<br/>
O número de elementos na matriz.

*lLBound*<br/>
O valor de limite inferior; ou seja, o índice do primeiro elemento na matriz.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Um `CComSafeArray` objeto pode ser criado a partir de `SAFEARRAYBOUND` uma estrutura existente e o número de dimensões, ou especificando o número de elementos na matriz e o limite inferior. Se a matriz a ser acessada C++, o limite inferior deve ser 0. Outras linguagens podem permitir outros valores para o limite inferior (por exemplo, Visual Basic dá suporte a matrizes com elementos com um intervalo como-10 a 10).

##  <a name="destroy"></a>  CComSafeArray::Destroy

Destrói um objeto `CComSafeArray`.

```
HRESULT Destroy();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Destrói um objeto existente `CComSafeArray` e todos os dados que ele contém.

##  <a name="detach"></a>  CComSafeArray::Detach

Desanexa um `SAFEARRAY` de um `CComSafeArray` objeto.

```
LPSAFEARRAY Detach();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para um `SAFEARRAY` objeto.

### <a name="remarks"></a>Comentários

Esse método desanexa o `SAFEARRAY` objeto `CComSafeArray` do objeto.

##  <a name="getat"></a>  CComSafeArray::GetAt

Recupera um único elemento de uma matriz unidimensional.

```
T& GetAt(LONG lIndex) const;
```

### <a name="parameters"></a>Parâmetros

*lIndex*<br/>
O número de índice do valor na matriz a ser retornado.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para o elemento de matriz necessário.

##  <a name="getcount"></a>  CComSafeArray::GetCount

Retorna o número de elementos na matriz.

```
ULONG GetCount(UINT uDim = 0) const;
```

### <a name="parameters"></a>Parâmetros

*uDim*<br/>
A dimensão da matriz.

### <a name="return-value"></a>Valor de retorno

Retorna o número de elementos na matriz.

### <a name="remarks"></a>Comentários

Quando usado com uma matriz multidimensional, esse método retornará o número de elementos somente em uma dimensão específica.

##  <a name="getdimensions"></a>  CComSafeArray::GetDimensions

Retorna o número de dimensões na matriz.

```
UINT GetDimensions() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de dimensões na matriz.

##  <a name="getlowerbound"></a>  CComSafeArray::GetLowerBound

Retorna o limite inferior de uma determinada dimensão da matriz.

```
LONG GetLowerBound(UINT uDim = 0) const;
```

### <a name="parameters"></a>Parâmetros

*uDim*<br/>
A dimensão de matriz para a qual obter o limite inferior. Se omitido, o padrão será 0.

### <a name="return-value"></a>Valor de retorno

Retorna o limite inferior.

### <a name="remarks"></a>Comentários

Se o limite inferior for 0, isso indica uma matriz do tipo C cujo primeiro elemento é o número de elemento 0. No caso de um erro, por exemplo, um argumento de dimensão inválido, esse método chama `AtlThrow` um HRESULT que descreve o erro.

##  <a name="getsafearrayptr"></a>  CComSafeArray::GetSafeArrayPtr

Retorna o endereço do membro `m_psa` de dados.

```
LPSAFEARRAY* GetSafeArrayPtr() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o membro de dados [CComSafeArray:: m_psa](#m_psa) .

##  <a name="gettype"></a>  CComSafeArray::GetType

Retorna o tipo de dados armazenados na matriz.

```
VARTYPE GetType() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o tipo de dados armazenados na matriz, que pode ser qualquer um dos seguintes tipos:

|VARTYPE|Descrição|
|-------------|-----------------|
|VT_I1|char|
|VT_I2|short|
|VT_I4|int|
|VT_I4|long|
|VT_I8|longlong|
|VT_UI1|byte|
|VT_UI2|ushort|
|VT_UI4|uint|
|VT_UI4|ulong|
|VT_UI8|ulonglong|
|VT_R4|float|
|VT_R8|double|
|VT_DECIMAL|ponteiro decimal|
|VT_VARIANT|ponteiro de variante|
|VT_CY|tipo de dados Currency|

##  <a name="getupperbound"></a>  CComSafeArray::GetUpperBound

Retorna o limite superior de qualquer dimensão da matriz.

```
LONG GetUpperBound(UINT uDim = 0) const;
```

### <a name="parameters"></a>Parâmetros

*uDim*<br/>
A dimensão de matriz para a qual obter o limite superior. Se omitido, o padrão será 0.

### <a name="return-value"></a>Valor de retorno

Retorna o limite superior. Esse valor é inclusivo, o índice válido máximo para essa dimensão.

### <a name="remarks"></a>Comentários

No caso de um erro, por exemplo, um argumento de dimensão inválido, esse método chama `AtlThrow` um HRESULT que descreve o erro.

##  <a name="issizable"></a>CComSafeArray:: isdimensionável

Testa se um `CComSafeArray` objeto pode ser redimensionado.

```
bool IsSizable() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o `CComSafeArray` puder ser redimensionado, false se não puder.

##  <a name="m_psa"></a>  CComSafeArray::m_psa

Mantém o endereço da `SAFEARRAY` estrutura acessada.

```
LPSAFEARRAY m_psa;
```

##  <a name="multidimgetat"></a>  CComSafeArray::MultiDimGetAt

Recupera um único elemento de uma matriz multidimensional.

```
HRESULT MultiDimGetAt(const LONG* alIndex, T& t);
```

### <a name="parameters"></a>Parâmetros

*alIndex*<br/>
Ponteiro para um vetor de índices para cada dimensão na matriz. A dimensão mais à esquerda (mais significativa `alIndex[0]`) é.

*t*<br/>
Uma referência aos dados retornados.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="multidimsetat"></a>  CComSafeArray::MultiDimSetAt

Define o valor de um elemento em uma matriz multidimensional.

```
HRESULT MultiDimSetAt(const LONG* alIndex, const T& t);
```

### <a name="parameters"></a>Parâmetros

*alIndex*<br/>
Ponteiro para um vetor de índices para cada dimensão na matriz. A dimensão mais à direita (menos significativa `alIndex`) é [0].

*T*<br/>
Especifica o valor do novo elemento.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esta é uma versão multidimensional de [CComSafeArray:: SetAt](#setat).

##  <a name="operator_at"></a>Operador CComSafeArray::\[\]

Recupera um elemento da matriz.

```
T& operator[](long lindex) const;
T& operator[]int nindex) const;
```

### <a name="parameters"></a>Parâmetros

*lIndex, nIndex*<br/>
O número de índice do elemento necessário na matriz.

### <a name="return-value"></a>Valor de retorno

Retorna o elemento de matriz apropriado.

### <a name="remarks"></a>Comentários

Executa uma função semelhante a [CComSafeArray:: GetAt](#getat), mas esse operador só funciona com matrizes unidimensionais.

##  <a name="operator_eq"></a>  CComSafeArray::operator =

Operador de atribuição.

```
ATL::CComSafeArray<T>& operator=(const ATL::CComSafeArray& saSrc);
ATL::CComSafeArray<T>& operator=(const SAFEARRAY* psaSrc);
```

### <a name="parameters"></a>Parâmetros

*saSrc*<br/>
Uma referência a um objeto `CComSafeArray`.

*psaSrc*<br/>
Um ponteiro para um `SAFEARRAY` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o tipo de dados armazenados na matriz.

##  <a name="operator_lpsafearray"></a>Operador CComSafeArray:: Operator LPSAFEARRAY

Converte um valor em um `SAFEARRAY` ponteiro.

```
operator LPSAFEARRAY() const;
```

### <a name="return-value"></a>Valor de retorno

Converte um valor em um `SAFEARRAY` ponteiro.

##  <a name="resize"></a>  CComSafeArray::Resize

Redimensiona um `CComSafeArray` objeto.

```
HRESULT Resize(const SAFEARRAYBOUND* pBound);
HRESULT Resize(ULONG ulCount, LONG lLBound = 0);
```

### <a name="parameters"></a>Parâmetros

*pBound*<br/>
Um ponteiro para uma `SAFEARRAYBOUND` estrutura que contém informações sobre o número de elementos e o limite inferior de uma matriz.

*ulCount*<br/>
O número solicitado de objetos na matriz redimensionada.

*lLBound*<br/>
O limite inferior.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método redimensiona apenas a dimensão mais à direita. Ele não redimensionará as matrizes que retornam `IsResizable` como false.

##  <a name="setat"></a>  CComSafeArray::SetAt

Define o valor de um elemento em uma matriz unidimensional.

```
HRESULT SetAt(LONG lIndex, const T& t, BOOL bCopy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lIndex*<br/>
O número de índice do elemento de matriz a ser definido.

*t*<br/>
O novo valor do elemento especificado.

*bCopy*<br/>
Indica se uma cópia dos dados deve ser criada. O valor padrão é TRUE.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O sinalizador *bcopy* é levado em conta quando elementos do tipo BSTR ou Variant são adicionados a uma matriz. O valor padrão de TRUE garante que uma nova cópia seja feita dos dados quando o elemento for adicionado à matriz.

## <a name="see-also"></a>Consulte também

[Tipo de dados SAFEARRAY](/windows/win32/api/oaidl/ns-oaidl-tagsafearray)<br/>
[CComSafeArray::Create](#create)<br/>
[CComSafeArray::Destroy](#destroy)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
