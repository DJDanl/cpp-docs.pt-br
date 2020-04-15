---
title: Classe CArray
ms.date: 11/04/2016
f1_keywords:
- CArray
- AFXTEMPL/CArray
- AFXTEMPL/CArray::CArray
- AFXTEMPL/CArray::Add
- AFXTEMPL/CArray::Append
- AFXTEMPL/CArray::Copy
- AFXTEMPL/CArray::ElementAt
- AFXTEMPL/CArray::FreeExtra
- AFXTEMPL/CArray::GetAt
- AFXTEMPL/CArray::GetCount
- AFXTEMPL/CArray::GetData
- AFXTEMPL/CArray::GetSize
- AFXTEMPL/CArray::GetUpperBound
- AFXTEMPL/CArray::InsertAt
- AFXTEMPL/CArray::IsEmpty
- AFXTEMPL/CArray::RemoveAll
- AFXTEMPL/CArray::RemoveAt
- AFXTEMPL/CArray::SetAt
- AFXTEMPL/CArray::SetAtGrow
- AFXTEMPL/CArray::SetSize
helpviewer_keywords:
- CArray [MFC], CArray
- CArray [MFC], Add
- CArray [MFC], Append
- CArray [MFC], Copy
- CArray [MFC], ElementAt
- CArray [MFC], FreeExtra
- CArray [MFC], GetAt
- CArray [MFC], GetCount
- CArray [MFC], GetData
- CArray [MFC], GetSize
- CArray [MFC], GetUpperBound
- CArray [MFC], InsertAt
- CArray [MFC], IsEmpty
- CArray [MFC], RemoveAll
- CArray [MFC], RemoveAt
- CArray [MFC], SetAt
- CArray [MFC], SetAtGrow
- CArray [MFC], SetSize
ms.assetid: fead8b00-4cfd-4625-ad0e-251df62ba92f
ms.openlocfilehash: 2c520a732edf54ebb36c07728ceb19791b351143
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377019"
---
# <a name="carray-class"></a>Classe CArray

Suporta matrizes que são como matrizes C, mas podem reduzir dinamicamente e crescer conforme necessário.

## <a name="syntax"></a>Sintaxe

```
template <class TYPE, class ARG_TYPE = const TYPE&>
class CArray : public CObject
```

#### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo que especifica o tipo de objetos armazenados na matriz. *TYPE* é um parâmetro que `CArray`é devolvido por .

*Arg_type*<br/>
Parâmetro de modelo que especifica o tipo de argumento usado para acessar objetos armazenados na matriz. Muitas vezes uma referência a *TYPE*. *ARG_TYPE* é um parâmetro que `CArray`é passado para .

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CArray::CArray](#carray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CArray::Adicionar](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CArray::Apêndice](#append)|Anexa outra matriz à matriz; cresce a matriz, se necessário|
|[CArray::Cópia](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[carray::elementat](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CArray::FreeExtra](#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[Carray::getat](#getat)|Retorna o valor a um determinado índice.|
|[CArray::GetCount](#getcount)|Obtém o número de elementos nesta matriz.|
|[CArray::GetData](#getdata)|Permite acesso aos elementos na matriz. Pode ser NULL.|
|[CArray::GetSize](#getsize)|Obtém o número de elementos nesta matriz.|
|[Carray::GetupperBound](#getupperbound)|Retorna o maior índice válido.|
|[carray::insertat](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CArray::IsEmpty](#isempty)|Determina se a matriz está vazia.|
|[CArray::RemoveAll](#removeall)|Remove todos os elementos dessa matriz.|
|[Carray::removeat](#removeat)|Remove um elemento a um índice específico.|
|[Carray::Setat](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[Carray::Setatgrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CArray::SetSize](#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator&#91;&#93;](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Os índices de matriz sempre começam na posição 0. Você pode decidir se deve corrigir o limite superior ou habilitar a matriz para expandir quando você adicionar elementos além do limite atual. A memória é atribuída contíguamente ao limite superior, mesmo que alguns elementos sejam nulos.

> [!NOTE]
> A maioria dos métodos que redimensionam um `CArray` objeto ou adicionam elementos a ele usam [memcpy_s](../../c-runtime-library/reference/memcpy-s-wmemcpy-s.md) para mover elementos. Isso é um `memcpy_s` problema porque não é compatível com nenhum objeto que exija que o construtor seja chamado. Se os itens no `CArray` , não `memcpy_s`são compatíveis `CArray` com , você deve criar um novo do tamanho apropriado. Em seguida, você deve usar [CArray::Copy](#copy) e [CArray::SetAt](#setat) para preencher a `memcpy_s`nova matriz porque esses métodos usam um operador de atribuição em vez de .

Como em uma matriz C, `CArray` o tempo de acesso para um elemento indexado é constante e é independente do tamanho da matriz.

> [!TIP]
> Antes de usar uma matriz, use [SetSize](#setsize) para estabelecer seu tamanho e alocar memória para ele. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de um despejo de elementos individuais em uma matriz, você deve definir a profundidade do objeto [CDumpContext](../../mfc/reference/cdumpcontext-class.md) como 1 ou maior.

Certas funções de membros desta classe chamam funções de ajudante global `CArray` que devem ser personalizadas para a maioria dos usos da classe. Consulte o tópico [Collection Class Helpers](../../mfc/reference/collection-class-helpers.md) na seção MFC Macros and Globals.

Derivação de classe de matriz é como derivação de lista.

Para obter mais informações `CArray`sobre como usar, consulte o artigo [Coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

## <a name="carrayadd"></a><a name="add"></a>CArray::Adicionar

Adiciona um novo elemento ao final de uma matriz, aumentando a matriz em 1.

```
INT_PTR Add(ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo de argumentos que referenciam elementos nesta matriz.

*Newelement*<br/>
O elemento a ser adicionado a esta matriz.

### <a name="return-value"></a>Valor retornado

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Se [SetSize](#setsize) tiver sido `nGrowBy` usado com um valor maior que 1, então a memória extra pode ser alocada. No entanto, o limite superior aumentará apenas 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#22](../../mfc/codesnippet/cpp/carray-class_1.cpp)]

## <a name="carrayappend"></a><a name="append"></a>CArray::Apêndice

Chame esta função de membro para adicionar o conteúdo de uma matriz ao final de outra.

```
INT_PTR Append(const CArray& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Fonte dos elementos a serem anexados a uma matriz.

### <a name="return-value"></a>Valor retornado

O índice do primeiro elemento anexado.

### <a name="remarks"></a>Comentários

As matrizes devem ser do mesmo tipo.

Se necessário, `Append` pode alocar memória extra para acomodar os elementos anexados à matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#23](../../mfc/codesnippet/cpp/carray-class_2.cpp)]

## <a name="carraycarray"></a><a name="carray"></a>CArray::CArray

Constrói uma matriz vazia.

```
CArray();
```

### <a name="remarks"></a>Comentários

A matriz cresce um elemento de cada vez.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#24](../../mfc/codesnippet/cpp/carray-class_3.cpp)]

## <a name="carraycopy"></a><a name="copy"></a>CArray::Cópia

Use esta função de membro para copiar os elementos de uma matriz para outra.

```
void Copy(const CArray& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Fonte dos elementos a serem copiados para uma matriz.

### <a name="remarks"></a>Comentários

Chame esta função de membro para substituir os elementos de uma matriz com os elementos de outra matriz.

`Copy`não libera a memória; no entanto, `Copy` se necessário, pode alocar memória extra para acomodar os elementos copiados para a matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#25](../../mfc/codesnippet/cpp/carray-class_4.cpp)]

## <a name="carrayelementat"></a><a name="elementat"></a>carray::elementat

Retorna uma referência temporária ao elemento especificado dentro da matriz.

```
TYPE& ElementAt(INT_PTR nIndex);
const TYPE& ElementAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual ao valor devolvido por [GetUpperBound](#getupperbound).

### <a name="return-value"></a>Valor retornado

Uma referência a um elemento de matriz.

### <a name="remarks"></a>Comentários

Ele é usado para implementar o operador de atribuição do lado esquerdo para matrizes.

### <a name="example"></a>Exemplo

  Veja o exemplo de [GetSize](#getsize).

## <a name="carrayfreeextra"></a><a name="freeextra"></a>CArray::FreeExtra

Libera qualquer memória extra que foi alocada enquanto a matriz foi cultivada.

```
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Esta função não tem efeito sobre o tamanho ou o limite superior da matriz.

### <a name="example"></a>Exemplo

  Veja o exemplo de [GetData](#getdata).

## <a name="carraygetat"></a><a name="getat"></a>Carray::getat

Retorna o elemento matriz no índice especificado.

```
TYPE& GetAt(INT_PTR nIndex);
const TYPE& GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos da matriz.

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual ao valor devolvido por [GetUpperBound](#getupperbound).

### <a name="return-value"></a>Valor retornado

O elemento matriz atualmente neste índice.

### <a name="remarks"></a>Comentários

A aprovação de um valor negativo ou `GetUpperBound` um valor maior do que o valor devolvido resultará em uma afirmação falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#26](../../mfc/codesnippet/cpp/carray-class_5.cpp)]

## <a name="carraygetcount"></a><a name="getcount"></a>CArray::GetCount

Retorna o número de elementos de matriz.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens na matriz.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de elementos na matriz. Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice. Chamar este método gerará o mesmo resultado que o método [CArray::GetSize.](#getsize)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#27](../../mfc/codesnippet/cpp/carray-class_6.cpp)]

## <a name="carraygetdata"></a><a name="getdata"></a>CArray::GetData

Use esta função de membro para obter acesso direto aos elementos em uma matriz.

```
const TYPE* GetData() const;
TYPE* GetData();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos da matriz.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um elemento de matriz.

### <a name="remarks"></a>Comentários

Se não houver `GetData` elementos disponíveis, retorna um valor nulo.

Embora o acesso direto aos elementos de uma matriz possa `GetData`ajudá-lo a trabalhar mais rapidamente, tenha cuidado ao ligar; quaisquer erros que você comete afetam diretamente os elementos de sua matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#28](../../mfc/codesnippet/cpp/carray-class_7.cpp)]

## <a name="carraygetsize"></a><a name="getsize"></a>CArray::GetSize

Retorna o tamanho da matriz.

```
INT_PTR GetSize() const;
```

### <a name="remarks"></a>Comentários

Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice. Chamar este método gerará o mesmo resultado que o método [CArray::GetCount.](#getcount)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#29](../../mfc/codesnippet/cpp/carray-class_8.cpp)]

## <a name="carraygetupperbound"></a><a name="getupperbound"></a>Carray::GetupperBound

Retorna o limite superior atual desta matriz.

```
INT_PTR GetUpperBound() const;
```

### <a name="remarks"></a>Comentários

Como os índices de matriz são baseados em `GetSize`zero, essa função retorna um valor 1 menor que .

A `GetUpperBound( )` condição = -1 indica que a matriz não contém elementos.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArray::GetAt](#getat).

## <a name="carrayinsertat"></a><a name="insertat"></a>carray::insertat

A primeira `InsertAt` versão de insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz.

```
void InsertAt(
    INT_PTR nIndex,
    ARG_TYPE newElement,
    INT_PTR nCount = 1);

void InsertAt(
    INT_PTR nStartIndex,
    CArray* pNewArray);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro que pode ser maior do `GetUpperBound`que o valor devolvido por .

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo de elementos nesta matriz.

*Newelement*<br/>
O elemento a ser colocado nesta matriz.

*Ncount*<br/>
O número de vezes que este elemento deve ser inserido (padrão para 1).

*Nstartindex*<br/>
Um índice inteiro que pode ser maior do que o valor devolvido pelo [GetUpperBound](#getupperbound).

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a esta matriz.

### <a name="remarks"></a>Comentários

No processo, ele muda (incrementando o índice) o elemento existente neste índice, e muda todos os elementos acima dele.

A segunda versão insere `CArray` todos os elementos de outra coleção, começando na posição *nStartIndex.*

A `SetAt` função, em contraste, substitui um elemento de matriz especificado e não desloca nenhum elemento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#30](../../mfc/codesnippet/cpp/carray-class_9.cpp)]

## <a name="carrayisempty"></a><a name="isempty"></a>CArray::IsEmpty

Determina se a matriz está vazia.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a matriz não contiver elementos; caso contrário, 0.

## <a name="carrayoperator-"></a><a name="operator_at"></a>CArray::operador\[\]

Esses operadores de subscritos são um substituto conveniente para as funções [SetAt](#setat) e [GetAt.](#getat)

```
TYPE& operator[](int_ptr nindex);
const TYPE& operator[](int_ptr nindex) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos nesta matriz.

*nIndex*<br/>
Índice do elemento a ser acessado.

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não são **const,** pode ser usado tanto à direita (r-valor) quanto à esquerda (l-valor) de uma declaração de atribuição. O segundo, chamado para **matrizes const,** pode ser usado apenas à direita.

A versão Debug da biblioteca afirma se o subscrito (no lado esquerdo ou direito de uma declaração de atribuição) estiver fora dos limites.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#34](../../mfc/codesnippet/cpp/carray-class_10.cpp)]

## <a name="carrayrelocateelements"></a><a name="relocateelements"></a>CArray::Realocar elementos

Realoca os dados para um novo buffer quando a matriz deve crescer ou encolher.

```
template<class TYPE, class ARG_TYPE>
AFX_INLINE void CArray<TYPE, ARG_TYPE>::RelocateElements(
    TYPE* pNewData,
    const TYPE* pData,
    INT_PTR nCount);
```

### <a name="parameters"></a>Parâmetros

*pNewData*<br/>
Um novo buffer para a matriz de elementos.

*Pdata*<br/>
A velha matriz de elementos.

*Ncount*<br/>
Número de elementos na matriz antiga.

### <a name="remarks"></a>Comentários

*pNewData* é sempre grande o suficiente para manter todos os elementos *pData.*

A implementação [do CArray](../../mfc/reference/carray-class.md) usa esse método para copiar os dados antigos para um novo buffer quando a matriz deve crescer ou encolher (quando [setSize](#setsize) ou [FreeExtra](#freeextra) são chamados). A implementação padrão apenas copia os dados.

Para matrizes nas quais um elemento contém um ponteiro para um de seus próprios membros, ou outra estrutura contém um ponteiro para um dos elementos da matriz, os ponteiros não são atualizados em cópia simples. Neste caso, você pode corrigir ponteiros implementando uma especialização `RelocateElements` com os tipos relevantes. Você também é responsável pela cópia de dados.

## <a name="carrayremoveall"></a><a name="removeall"></a>CArray::RemoveAll

Remove todos os elementos dessa matriz.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Se a matriz já estiver vazia, a função ainda funciona.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#31](../../mfc/codesnippet/cpp/carray-class_11.cpp)]

## <a name="carrayremoveat"></a><a name="removeat"></a>Carray::removeat

Remove um ou mais elementos a partir de um índice especificado em uma matriz.

```
void RemoveAt(
    INT_PTR nIndex,
    INT_PTR nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual ao valor devolvido por [GetUpperBound](#getupperbound).

*Ncount*<br/>
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

No processo, ele desloca todos os elementos acima dos elementos removidos. Ele decreta o limite superior da matriz, mas não libera a memória.

Se você tentar remover mais elementos do que estão contidos na matriz acima do ponto de remoção, então a versão Debug da biblioteca afirma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#32](../../mfc/codesnippet/cpp/carray-class_12.cpp)]

## <a name="carraysetat"></a><a name="setat"></a>Carray::Setat

Define o elemento matriz no índice especificado.

```
void SetAt(INT_PTR nIndex, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual ao valor devolvido por [GetUpperBound](#getupperbound).

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo de argumentos usados para referenciar elementos da matriz.

*Newelement*<br/>
O novo valor do elemento a ser armazenado na posição especificada.

### <a name="remarks"></a>Comentários

`SetAt`não fará com que a matriz cresça. Use [SetAtGrow](#setatgrow) se quiser que a matriz cresça automaticamente.

Você deve garantir que o valor do índice represente uma posição válida na matriz. Se estiver fora dos limites, então a versão Debug da biblioteca afirma.

### <a name="example"></a>Exemplo

  Veja o exemplo de [GetAt](#getat).

## <a name="carraysetatgrow"></a><a name="setatgrow"></a>Carray::Setatgrow

Define o elemento matriz no índice especificado.

```
void SetAtGrow(INT_PTR nIndex, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0.

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo de elementos na matriz.

*Newelement*<br/>
O elemento a ser adicionado a esta matriz. Um valor NULA é permitido.

### <a name="remarks"></a>Comentários

A matriz cresce automaticamente se necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#33](../../mfc/codesnippet/cpp/carray-class_13.cpp)]

## <a name="carraysetsize"></a><a name="setsize"></a>CArray::SetSize

Estabelece o tamanho de uma matriz vazia ou existente; aloca a memória, se necessário.

```
void SetSize(
    INT_PTR nNewSize,
    INT_PTR nGrowBy = -1);
```

### <a name="parameters"></a>Parâmetros

*nNewSize*<br/>
O novo tamanho da matriz (número de elementos). Deve ser maior ou igual a 0.

*nGrowBy*<br/>
O número mínimo de slots de elemento para alocar se for necessário um aumento de tamanho.

### <a name="remarks"></a>Comentários

Se o novo tamanho for menor do que o tamanho antigo, então a matriz é truncada e toda a memória não utilizada é liberada.

Use esta função para definir o tamanho da matriz antes de começar a usar a matriz. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

O parâmetro *nGrowBy* afeta a alocação de memória interna enquanto a matriz está crescendo. Seu uso nunca afeta o tamanho da matriz, como relatado por [GetSize](#getsize) e [GetUpperBound](#getupperbound). Se o valor padrão for usado, o MFC alocará a memória de uma forma calculada para evitar a fragmentação da memória e otimizar a eficiência para a maioria dos casos.

### <a name="example"></a>Exemplo

  Veja o exemplo de [GetData](#getdata).

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)<br/>
[Auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md)
