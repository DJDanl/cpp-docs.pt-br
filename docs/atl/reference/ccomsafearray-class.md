---
title: Classe CComSafeARRAY
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
ms.openlocfilehash: d1e72d364858ea31541d574ed77bdc8ccca7d748
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327397"
---
# <a name="ccomsafearray-class"></a>Classe CComSafeARRAY

Esta aula é um `SAFEARRAY` invólucro para a estrutura.

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
|[CComSafeArray::Adicionar](#add)|Adiciona um ou mais `SAFEARRAY` elementos, `CComSafeArray`ou uma estrutura, a um .|
|[CComSafeArray::Anexar](#attach)|Anexa uma `SAFEARRAY` estrutura `CComSafeArray` a um objeto.|
|[CComSafeArray::CopyFrom](#copyfrom)|Copia o conteúdo `SAFEARRAY` de `CComSafeArray` uma estrutura para dentro do objeto.|
|[CComSafeArray::CopyTo](#copyto)|Cria uma cópia do objeto `CComSafeArray`.|
|[CComSafeArray::Criar](#create)|Cria um objeto `CComSafeArray`.|
|[CComSafeArray::Destroy](#destroy)|Destrói um objeto `CComSafeArray`.|
|[CComSafeArray::Detach](#detach)|Destaca um `SAFEARRAY` de `CComSafeArray` um objeto.|
|[CcomSafeArray::getat](#getat)|Recupera um único elemento de uma matriz unidimensional.|
|[CComSafeArray::GetCount](#getcount)|Retorna o número de elementos na matriz.|
|[CComSafeArray::GetDimensions](#getdimensions)|Retorna o número de dimensões na matriz.|
|[CComSafeArray::getLowerBound](#getlowerbound)|Retorna o limite inferior para uma determinada dimensão da matriz.|
|[CComSafeArray::GetSafeArrayPtr](#getsafearrayptr)|Retorna o endereço `m_psa` do membro de dados.|
|[CComSafeArray::GetType](#gettype)|Retorna o tipo de dados armazenados na matriz.|
|[CComSafeArray::getupperbound](#getupperbound)|Retorna o limite superior para qualquer dimensão da matriz.|
|[CComSafeArray::IsSizable](#issizable)|Testa `CComSafeArray` se um objeto pode ser redimensionado.|
|[CcomSafeArray::Multidimgetat](#multidimgetat)|Recupera um único elemento de uma matriz multidimensional.|
|[CcomSafeArray::Multidimsetat](#multidimsetat)|Define o valor de um elemento em uma matriz multidimensional.|
|[CComSafeArray::Redimensionar](#resize)|Redimensiona `CComSafeArray` um objeto.|
|[CComSafeArray::setat](#setat)|Define o valor de um elemento em uma matriz unidimensional.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeArray::operador LPSAFEARRAY](#operator_lpsafearray)|Lança um valor `SAFEARRAY` para um ponteiro.|
|[CComSafeArray::operador\[\]](ccomsafearray-class.md#operator_at)|Recupera um elemento da matriz.|
|[CComSafeArray::operador =](#operator_eq)|Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeArray::m_psa](#m_psa)|Este membro de dados `SAFEARRAY` detém o endereço da estrutura.|

## <a name="remarks"></a>Comentários

`CComSafeArray`fornece um invólucro para a classe [SAFEARRAY Data Type,](/windows/win32/api/oaidl/ns-oaidl-safearray) tornando-se uma questão simples para criar e gerenciar matrizes únicas e multidimensionais de quase qualquer um dos tipos suportados pela VARIANT.

`CComSafeArray`simplifica a passagem de matrizes entre processos e, além disso, fornece segurança extra verificando valores de índice de matriz escancar em limites superiores e inferiores.

O limite inferior `CComSafeArray` de um pode começar a qualquer valor definido pelo usuário; no entanto, as matrizes que são acessadas através de C++ devem usar um limite inferior de 0. Outras linguagens, como o Visual Basic, podem usar outros valores delimitadores (por exemplo, -10 a 10).

Use [CComSafeArray::Create](#create) para `CComSafeArray` criar um objeto e [CComSafeArray::Destroy](#destroy) para excluí-lo.

A `CComSafeArray` pode conter o seguinte subconjunto de tipos de dados VARIANT:

|Vartype|Descrição|
|-------------|-----------------|
|VT_I1|char|
|VT_I2|short|
|VT_I4|INT|
|VT_I4|long|
|VT_I8|Longlong|
|VT_UI1|byte|
|VT_UI2|ushort|
|VT_UI4|uint|
|VT_UI4|ulong|
|VT_UI8|Ulonglong|
|VT_R4|FLOAT|
|VT_R8|double|
|VT_DECIMAL|ponteiro decimal|
|VT_VARIANT|ponteiro variante|
|VT_CY|tipo de dados Currency|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsafe.h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#75](../../atl/codesnippet/cpp/ccomsafearray-class_1.cpp)]

## <a name="ccomsafearrayadd"></a><a name="add"></a>CComSafeArray::Adicionar

Adiciona um ou mais `SAFEARRAY` elementos, `CComSafeArray`ou uma estrutura, a um .

```
HRESULT Add(const SAFEARRAY* psaSrc);
HRESULT Add(ULONG ulCount, const T* pT, BOOL bCopy = TRUE);
HRESULT Add(const T& t, BOOL bCopy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*psaSrc*<br/>
Um ponteiro para um objeto `SAFEARRAY`.

*ulCount*<br/>
O número de objetos a serem adicionados à matriz.

*pT*<br/>
Um ponteiro para um ou mais objetos a serem adicionados à matriz.

*t*<br/>
Uma referência ao objeto a ser adicionado à matriz.

*Bcopy*<br/>
Indica se uma cópia dos dados deve ser criada. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Os novos objetos são anexados ao `SAFEARRAY` final do objeto existente. A adição de `SAFEARRAY` um objeto a um objeto multidimensional não é suportada. Ao adicionar uma matriz de objetos existente, ambas as matrizes devem conter elementos do mesmo tipo.

O sinalizador *bCopy* é levado em conta quando elementos do tipo BSTR ou VARIANT são adicionados a uma matriz. O valor padrão de TRUE garante que uma nova cópia seja feita dos dados quando o elemento é adicionado à matriz.

## <a name="ccomsafearrayattach"></a><a name="attach"></a>CComSafeArray::Anexar

Anexa uma `SAFEARRAY` estrutura `CComSafeArray` a um objeto.

```
HRESULT Attach(const SAFEARRAY* psaSrc);
```

### <a name="parameters"></a>Parâmetros

*psaSrc*<br/>
Um ponteiro `SAFEARRAY` para a estrutura.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Anexa uma `SAFEARRAY` estrutura `CComSafeArray` a um objeto, `CComSafeArray` disponibilizando os métodos existentes.

## <a name="ccomsafearrayccomsafearray"></a><a name="ccomsafearray"></a>CComSafeArray::CComSafeArray

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

*Limite*<br/>
Uma estrutura `SAFEARRAYBOUND`.

*ulCount*<br/>
O número de elementos na matriz.

*LLBound*<br/>
O valor de limite mais baixo; ou seja, o índice do primeiro elemento na matriz.

*pBound*<br/>
Um ponteiro `SAFEARRAYBOUND` para uma estrutura.

*uDims*<br/>
A contagem de dimensões na matriz.

*saSrc*<br/>
Uma referência `SAFEARRAY` a `CComSafeArray` uma estrutura ou objeto. Em ambos os casos, o construtor usa essa referência para fazer uma cópia da matriz, de modo que a matriz não é referenciada após a construção.

*psaSrc*<br/>
Um ponteiro `SAFEARRAY` para uma estrutura. O construtor usa este endereço para fazer uma cópia da matriz, de modo que a matriz não é referenciada após a construção.

### <a name="remarks"></a>Comentários

Cria um objeto `CComSafeArray`.

## <a name="ccomsafearrayccomsafearray"></a><a name="dtor"></a>CComSafeArray::~CComSafeArray

O destruidor.

```
~CComSafeArray() throw()
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="ccomsafearraycopyfrom"></a><a name="copyfrom"></a>CComSafeArray::CopyFrom

Copia o conteúdo `SAFEARRAY` de `CComSafeArray` uma estrutura para dentro do objeto.

```
HRESULT CopyFrom(LPSAFEARRAY* ppArray);
```

### <a name="parameters"></a>Parâmetros

*ppArray*<br/>
Ponteiro para `SAFEARRAY` copiar.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método copia o `SAFEARRAY` conteúdo `CComSafeArray` de a no objeto atual. Os conteúdos existentes da matriz são substituídos.

## <a name="ccomsafearraycopyto"></a><a name="copyto"></a>CComSafeArray::CopyTo

Cria uma cópia do objeto `CComSafeArray`.

```
HRESULT CopyTo(LPSAFEARRAY* ppArray);
```

### <a name="parameters"></a>Parâmetros

*ppArray*<br/>
Um ponteiro para um local no `SAFEARRAY`qual criar o novo .

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método copia o `CComSafeArray` conteúdo `SAFEARRAY` de um objeto em uma estrutura.

## <a name="ccomsafearraycreate"></a><a name="create"></a>CComSafeArray::Criar

Cria um `CComSafeArray`.

```
HRESULT Create(const SAFEARRAYBOUND* pBound, UINT uDims = 1);
HRESULT Create(ULONG ulCount = 0, LONG lLBound = 0);
```

### <a name="parameters"></a>Parâmetros

*pBound*<br/>
Um ponteiro para um objeto `SAFEARRAYBOUND`.

*uDims*<br/>
O número de dimensões na matriz.

*ulCount*<br/>
O número de elementos na matriz.

*LLBound*<br/>
O valor de limite mais baixo; ou seja, o índice do primeiro elemento na matriz.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Um `CComSafeArray` objeto pode ser criado `SAFEARRAYBOUND` a partir de uma estrutura existente e do número de dimensões, ou especificando o número de elementos na matriz e no limite inferior. Se a matriz for acessada a partir de C++, o limite inferior deve ser 0. Outras línguas podem permitir outros valores para o limite inferior (por exemplo, o Visual Basic suporta matrizes com elementos com um intervalo como -10 a 10).

## <a name="ccomsafearraydestroy"></a><a name="destroy"></a>CComSafeArray::Destroy

Destrói um objeto `CComSafeArray`.

```
HRESULT Destroy();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Destrói um objeto `CComSafeArray` existente e todos os dados que ele contém.

## <a name="ccomsafearraydetach"></a><a name="detach"></a>CComSafeArray::Detach

Destaca um `SAFEARRAY` de `CComSafeArray` um objeto.

```
LPSAFEARRAY Detach();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `SAFEARRAY` para um objeto.

### <a name="remarks"></a>Comentários

Este método desprende `SAFEARRAY` o `CComSafeArray` objeto do objeto.

## <a name="ccomsafearraygetat"></a><a name="getat"></a>CcomSafeArray::getat

Recupera um único elemento de uma matriz unidimensional.

```
T& GetAt(LONG lIndex) const;
```

### <a name="parameters"></a>Parâmetros

*Lindex*<br/>
O número de índice do valor na matriz para retornar.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao elemento de matriz necessário.

## <a name="ccomsafearraygetcount"></a><a name="getcount"></a>CComSafeArray::GetCount

Retorna o número de elementos na matriz.

```
ULONG GetCount(UINT uDim = 0) const;
```

### <a name="parameters"></a>Parâmetros

*uDim*<br/>
A dimensão da matriz.

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos na matriz.

### <a name="remarks"></a>Comentários

Quando usado com uma matriz multidimensional, este método retornará o número de elementos apenas em uma dimensão específica.

## <a name="ccomsafearraygetdimensions"></a><a name="getdimensions"></a>CComSafeArray::GetDimensions

Retorna o número de dimensões na matriz.

```
UINT GetDimensions() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de dimensões na matriz.

## <a name="ccomsafearraygetlowerbound"></a><a name="getlowerbound"></a>CComSafeArray::getLowerBound

Retorna o limite inferior para uma determinada dimensão da matriz.

```
LONG GetLowerBound(UINT uDim = 0) const;
```

### <a name="parameters"></a>Parâmetros

*uDim*<br/>
A dimensão da matriz para a qual obter o limite inferior. Se omitido, o padrão é 0.

### <a name="return-value"></a>Valor retornado

Retorna o limite inferior.

### <a name="remarks"></a>Comentários

Se o limite inferior for 0, isso indica uma matriz semelhante a C cujo primeiro elemento é o elemento número 0. No caso de um erro, por exemplo, um argumento `AtlThrow` de dimensão inválida, este método é chamada com um HRESULT descrevendo o erro.

## <a name="ccomsafearraygetsafearrayptr"></a><a name="getsafearrayptr"></a>CComSafeArray::GetSafeArrayPtr

Retorna o endereço `m_psa` do membro de dados.

```
LPSAFEARRAY* GetSafeArrayPtr() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o membro de dados [CComSafeArray::m_psa.](#m_psa)

## <a name="ccomsafearraygettype"></a><a name="gettype"></a>CComSafeArray::GetType

Retorna o tipo de dados armazenados na matriz.

```
VARTYPE GetType() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o tipo de dados armazenados na matriz, que pode ser qualquer um dos seguintes tipos:

|Vartype|Descrição|
|-------------|-----------------|
|VT_I1|char|
|VT_I2|short|
|VT_I4|INT|
|VT_I4|long|
|VT_I8|Longlong|
|VT_UI1|byte|
|VT_UI2|ushort|
|VT_UI4|uint|
|VT_UI4|ulong|
|VT_UI8|Ulonglong|
|VT_R4|FLOAT|
|VT_R8|double|
|VT_DECIMAL|ponteiro decimal|
|VT_VARIANT|ponteiro variante|
|VT_CY|tipo de dados Currency|

## <a name="ccomsafearraygetupperbound"></a><a name="getupperbound"></a>CComSafeArray::getupperbound

Retorna o limite superior para qualquer dimensão da matriz.

```
LONG GetUpperBound(UINT uDim = 0) const;
```

### <a name="parameters"></a>Parâmetros

*uDim*<br/>
A dimensão da matriz para a qual obter o limite superior. Se omitido, o padrão é 0.

### <a name="return-value"></a>Valor retornado

Retorna o limite superior. Esse valor é inclusivo, o índice máximo válido para esta dimensão.

### <a name="remarks"></a>Comentários

No caso de um erro, por exemplo, um argumento `AtlThrow` de dimensão inválida, este método é chamada com um HRESULT descrevendo o erro.

## <a name="ccomsafearrayissizable"></a><a name="issizable"></a>CComSafeArray::IsSizable

Testa `CComSafeArray` se um objeto pode ser redimensionado.

```
bool IsSizable() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE `CComSafeArray` se o pode ser redimensionado, FALSO se não puder.

## <a name="ccomsafearraym_psa"></a><a name="m_psa"></a>CComSafeArray::m_psa

Mantém o `SAFEARRAY` endereço da estrutura acessada.

```
LPSAFEARRAY m_psa;
```

## <a name="ccomsafearraymultidimgetat"></a><a name="multidimgetat"></a>CcomSafeArray::Multidimgetat

Recupera um único elemento de uma matriz multidimensional.

```
HRESULT MultiDimGetAt(const LONG* alIndex, T& t);
```

### <a name="parameters"></a>Parâmetros

*alIndex*<br/>
Ponteiro para um vetor de índices para cada dimensão na matriz. A dimensão mais à `alIndex[0]`esquerda (mais significativa) é .

*t*<br/>
Uma referência aos dados retornou.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="ccomsafearraymultidimsetat"></a><a name="multidimsetat"></a>CcomSafeArray::Multidimsetat

Define o valor de um elemento em uma matriz multidimensional.

```
HRESULT MultiDimSetAt(const LONG* alIndex, const T& t);
```

### <a name="parameters"></a>Parâmetros

*alIndex*<br/>
Ponteiro para um vetor de índices para cada dimensão na matriz. A dimensão mais à `alIndex`direita (menos significativa) é [0].

*T*<br/>
Especifica o valor do novo elemento.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta é uma versão multidimensional do [CComSafeArray::SetAt](#setat).

## <a name="ccomsafearrayoperator-"></a><a name="operator_at"></a>CComSafeArray::operador\[\]

Recupera um elemento da matriz.

```
T& operator[](long lindex) const;
T& operator[]int nindex) const;
```

### <a name="parameters"></a>Parâmetros

*LIndex, nIndex*<br/>
O número de índice do elemento necessário na matriz.

### <a name="return-value"></a>Valor retornado

Retorna o elemento de matriz apropriado.

### <a name="remarks"></a>Comentários

Executa uma função semelhante ao [CComSafeArray::GetAt,](#getat)no entanto, este operador só funciona com arrays unidimensionais.

## <a name="ccomsafearrayoperator-"></a><a name="operator_eq"></a>CComSafeArray::operador =

Operador de atribuição.

```
ATL::CComSafeArray<T>& operator=(const ATL::CComSafeArray& saSrc);
ATL::CComSafeArray<T>& operator=(const SAFEARRAY* psaSrc);
```

### <a name="parameters"></a>Parâmetros

*saSrc*<br/>
Uma referência a um objeto `CComSafeArray`.

*psaSrc*<br/>
Um ponteiro para um objeto `SAFEARRAY`.

### <a name="return-value"></a>Valor retornado

Retorna o tipo de dados armazenados na matriz.

## <a name="ccomsafearrayoperator-lpsafearray"></a><a name="operator_lpsafearray"></a>CComSafeArray::operador LPSAFEARRAY

Lança um valor `SAFEARRAY` para um ponteiro.

```
operator LPSAFEARRAY() const;
```

### <a name="return-value"></a>Valor retornado

Lança um valor `SAFEARRAY` para um ponteiro.

## <a name="ccomsafearrayresize"></a><a name="resize"></a>CComSafeArray::Redimensionar

Redimensiona `CComSafeArray` um objeto.

```
HRESULT Resize(const SAFEARRAYBOUND* pBound);
HRESULT Resize(ULONG ulCount, LONG lLBound = 0);
```

### <a name="parameters"></a>Parâmetros

*pBound*<br/>
Um ponteiro `SAFEARRAYBOUND` para uma estrutura que contém informações sobre o número de elementos e o limite inferior de uma matriz.

*ulCount*<br/>
O número solicitado de objetos na matriz redimensionada.

*LLBound*<br/>
O limite inferior.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método só redimensiona a dimensão mais certa. Ele não redimensionará as `IsResizable` matrizes que retornam como FALSE.

## <a name="ccomsafearraysetat"></a><a name="setat"></a>CComSafeArray::setat

Define o valor de um elemento em uma matriz unidimensional.

```
HRESULT SetAt(LONG lIndex, const T& t, BOOL bCopy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lindex*<br/>
O número de índice do elemento matriz a definir.

*t*<br/>
O novo valor do elemento especificado.

*Bcopy*<br/>
Indica se uma cópia dos dados deve ser criada. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

O sinalizador *bCopy* é levado em conta quando elementos do tipo BSTR ou VARIANT são adicionados a uma matriz. O valor padrão de TRUE garante que uma nova cópia seja feita dos dados quando o elemento é adicionado à matriz.

## <a name="see-also"></a>Confira também

[Tipo de dados SAFEARRAY](/windows/win32/api/oaidl/ns-oaidl-safearray)<br/>
[CComSafeArray::Criar](#create)<br/>
[CComSafeArray::Destroy](#destroy)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
