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
ms.openlocfilehash: f82dbf7dce2e14bf760bb76d23d23f667797ee0f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418856"
---
# <a name="carray-class"></a>Classe CArray

Oferece suporte a matrizes como matrizes C, mas pode reduzir e aumentar dinamicamente conforme necessário.

## <a name="syntax"></a>Sintaxe

```
template <class TYPE, class ARG_TYPE = const TYPE&>
class CArray : public CObject
```

#### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de objetos armazenados na matriz. *Type* é um parâmetro que é retornado por `CArray`.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo de argumento que é usado para acessar objetos armazenados na matriz. Geralmente, uma referência ao *tipo*. *ARG_TYPE* é um parâmetro que é passado para `CArray`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArray::CArray](#carray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArray:: Adicionar](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CArray:: Append](#append)|Acrescenta outra matriz à matriz; aumenta a matriz, se necessário|
|[CArray:: copiar](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CArray::FreeExtra](#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CArray::GetAt](#getat)|Retorna o valor a um determinado índice.|
|[CArray:: GetCount](#getcount)|Obtém o número de elementos nesta matriz.|
|[CArray:: GetData](#getdata)|Permite acesso aos elementos na matriz. Pode ser NULL.|
|[CArray::GetSize](#getsize)|Obtém o número de elementos nesta matriz.|
|[CArray::GetUpperBound](#getupperbound)|Retorna o maior índice válido.|
|[CArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CArray:: IsEmpty](#isempty)|Determina se a matriz está vazia.|
|[CArray:: RemoveAll](#removeall)|Remove todos os elementos dessa matriz.|
|[CArray:: RemoveAt](#removeat)|Remove um elemento a um índice específico.|
|[CArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CArray:: SetSize](#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[operator&#91;&#93;](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Os índices de matrizes sempre começam na posição 0. Você pode decidir se deseja corrigir o limite superior ou habilitar a matriz para expandir ao adicionar elementos após o limite atual. A memória é alocada de forma contígua para o limite superior, mesmo que alguns elementos sejam nulos.

> [!NOTE]
>  A maioria dos métodos que redimensionam um objeto `CArray` ou adicionam elementos a ele usam [memcpy_s](../../c-runtime-library/reference/memcpy-s-wmemcpy-s.md) para mover elementos. Isso é um problema porque `memcpy_s` não é compatível com nenhum objeto que exija que o Construtor seja chamado. Se os itens na `CArray` não forem compatíveis com `memcpy_s`, você deverá criar uma nova `CArray` do tamanho apropriado. Em seguida, você deve usar [CArray:: Copy](#copy) e [CArray:: SetAt](#setat) para popular a nova matriz porque esses métodos usam um operador de atribuição em vez de `memcpy_s`.

Assim como acontece com uma matriz C, o tempo de acesso para um `CArray` elemento indexado é constante e é independente do tamanho da matriz.

> [!TIP]
>  Antes de usar uma matriz, use [SetSize](#setsize) para estabelecer seu tamanho e alocar memória para ele. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de um despejo de elementos individuais em uma matriz, deverá definir a profundidade do objeto [CDumpContext](../../mfc/reference/cdumpcontext-class.md) como 1 ou maior.

Determinadas funções de membro dessa classe chamam funções auxiliares globais que devem ser personalizadas para a maioria dos usos da classe `CArray`. Consulte o tópico [auxiliares de classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção macros e globais do MFC.

A derivação de classe de matriz é como derivação de lista.

Para obter mais informações sobre como usar `CArray`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl. h

##  <a name="add"></a>CArray:: Adicionar

Adiciona um novo elemento ao final de uma matriz, aumentando a matriz em 1.

```
INT_PTR Add(ARG_TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo de argumentos que referenciam elementos nesta matriz.

*newElement*<br/>
O elemento a ser adicionado a esta matriz.

### <a name="return-value"></a>Valor retornado

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Se [SetSize](#setsize) tiver sido usado com um valor `nGrowBy` maior que 1, a memória extra poderá ser alocada. No entanto, o limite superior aumentará apenas em 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#22](../../mfc/codesnippet/cpp/carray-class_1.cpp)]

##  <a name="append"></a>CArray:: Append

Chame essa função de membro para adicionar o conteúdo de uma matriz ao final de outra.

```
INT_PTR Append(const CArray& src);
```

### <a name="parameters"></a>parâmetros

*src*<br/>
Origem dos elementos a serem acrescentados a uma matriz.

### <a name="return-value"></a>Valor retornado

O índice do primeiro elemento acrescentado.

### <a name="remarks"></a>Comentários

As matrizes devem ser do mesmo tipo.

Se necessário, `Append` pode alocar memória extra para acomodar os elementos acrescentados à matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#23](../../mfc/codesnippet/cpp/carray-class_2.cpp)]

##  <a name="carray"></a>CArray::CArray

Constrói uma matriz vazia.

```
CArray();
```

### <a name="remarks"></a>Comentários

A matriz aumenta um elemento por vez.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#24](../../mfc/codesnippet/cpp/carray-class_3.cpp)]

##  <a name="copy"></a>CArray:: copiar

Use essa função de membro para copiar os elementos de uma matriz para outra.

```
void Copy(const CArray& src);
```

### <a name="parameters"></a>parâmetros

*src*<br/>
Origem dos elementos a serem copiados para uma matriz.

### <a name="remarks"></a>Comentários

Chame essa função de membro para substituir os elementos de uma matriz pelos elementos de outra matriz.

`Copy` não libera memória; no entanto, se necessário, `Copy` pode alocar memória extra para acomodar os elementos copiados para a matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#25](../../mfc/codesnippet/cpp/carray-class_4.cpp)]

##  <a name="elementat"></a>CArray::ElementAt

Retorna uma referência temporária para o elemento especificado dentro da matriz.

```
TYPE& ElementAt(INT_PTR nIndex);
const TYPE& ElementAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).

### <a name="return-value"></a>Valor retornado

Uma referência a um elemento de matriz.

### <a name="remarks"></a>Comentários

Ele é usado para implementar o operador de atribuição do lado esquerdo para matrizes.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [GetSize](#getsize).

##  <a name="freeextra"></a>CArray::FreeExtra

Libera qualquer memória extra que foi alocada enquanto a matriz foi expandida.

```
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Essa função não tem efeito sobre o tamanho ou limite superior da matriz.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [GetData](#getdata).

##  <a name="getat"></a>CArray::GetAt

Retorna o elemento de matriz no índice especificado.

```
TYPE& GetAt(INT_PTR nIndex);
const TYPE& GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo dos elementos da matriz.

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).

### <a name="return-value"></a>Valor retornado

O elemento de matriz atualmente neste índice.

### <a name="remarks"></a>Comentários

Passar um valor negativo ou um valor maior que o valor retornado por `GetUpperBound` resultará em uma asserção com falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#26](../../mfc/codesnippet/cpp/carray-class_5.cpp)]

##  <a name="getcount"></a>CArray:: GetCount

Retorna o número de elementos da matriz.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens na matriz.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos na matriz. Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice. Chamar esse método irá gerar o mesmo resultado que o método [CArray:: GetSize](#getsize) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#27](../../mfc/codesnippet/cpp/carray-class_6.cpp)]

##  <a name="getdata"></a>CArray:: GetData

Use essa função de membro para obter acesso direto aos elementos em uma matriz.

```
const TYPE* GetData() const;
TYPE* GetData();
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo dos elementos da matriz.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um elemento de matriz.

### <a name="remarks"></a>Comentários

Se nenhum elemento estiver disponível, `GetData` retornará um valor nulo.

Embora o acesso direto aos elementos de uma matriz possa ajudá-lo a trabalhar mais rapidamente, tome cuidado ao chamar `GetData`; todos os erros que você fizer afetam diretamente os elementos da matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#28](../../mfc/codesnippet/cpp/carray-class_7.cpp)]

##  <a name="getsize"></a>CArray::GetSize

Retorna o tamanho da matriz.

```
INT_PTR GetSize() const;
```

### <a name="remarks"></a>Comentários

Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice. Chamar esse método irá gerar o mesmo resultado que o método [CArray:: GetCount](#getcount) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#29](../../mfc/codesnippet/cpp/carray-class_8.cpp)]

##  <a name="getupperbound"></a>CArray::GetUpperBound

Retorna o limite superior atual desta matriz.

```
INT_PTR GetUpperBound() const;
```

### <a name="remarks"></a>Comentários

Como os índices de matriz são baseados em zero, essa função retorna um valor 1 menor que `GetSize`.

A condição `GetUpperBound( )` =-1 indica que a matriz não contém elementos.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CArray:: GetAt](#getat).

##  <a name="insertat"></a>CArray::InsertAt

A primeira versão do `InsertAt` insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz.

```
void InsertAt(
    INT_PTR nIndex,
    ARG_TYPE newElement,
    INT_PTR nCount = 1);

void InsertAt(
    INT_PTR nStartIndex,
    CArray* pNewArray);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por `GetUpperBound`.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos nesta matriz.

*newElement*<br/>
O elemento a ser colocado nesta matriz.

*nCount*<br/>
O número de vezes que esse elemento deve ser inserido (o padrão é 1).

*nStartIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por [GetUpperBound](#getupperbound).

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a esta matriz.

### <a name="remarks"></a>Comentários

No processo, ele muda (incrementando o índice) para o elemento existente nesse índice e muda todos os elementos acima dele para cima.

A segunda versão insere todos os elementos de outra coleção de `CArray`, começando na posição *nStartIndex* .

A função `SetAt`, por outro lado, substitui um elemento de matriz especificado e não altera os elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#30](../../mfc/codesnippet/cpp/carray-class_9.cpp)]

##  <a name="isempty"></a>CArray:: IsEmpty

Determina se a matriz está vazia.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a matriz não contiver nenhum elemento; caso contrário, 0.

##  <a name="operator_at"></a>CArray:: Operator \[\]

Esses operadores de subscritor são um substituto conveniente para as funções [SetAt](#setat) e [GetAt](#getat) .

```
TYPE& operator[](int_ptr nindex);
const TYPE& operator[](int_ptr nindex) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos nesta matriz.

*nIndex*<br/>
Índice do elemento a ser acessado.

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não são **const**, pode ser usado na direita (r-value) ou na esquerda (l-Value) de uma instrução de atribuição. O segundo, chamado para matrizes **const** , pode ser usado somente à direita.

A versão de depuração da biblioteca é declarada se o subscrito (no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#34](../../mfc/codesnippet/cpp/carray-class_10.cpp)]

##  <a name="relocateelements"></a>CArray::RelocateElements

Realoca os dados para um novo buffer quando a matriz deve aumentar ou diminuir.

```
template<class TYPE, class ARG_TYPE>
AFX_INLINE void CArray<TYPE, ARG_TYPE>::RelocateElements(
    TYPE* pNewData,
    const TYPE* pData,
    INT_PTR nCount);
```

### <a name="parameters"></a>parâmetros

*pNewData*<br/>
Um novo buffer para a matriz de elementos.

*pData*<br/>
A matriz antiga de elementos.

*nCount*<br/>
Número de elementos na matriz antiga.

### <a name="remarks"></a>Comentários

*pNewData* é sempre grande o suficiente para manter todos os elementos *pData* .

A implementação [CArray](../../mfc/reference/carray-class.md) usa esse método para copiar os dados antigos para um novo buffer quando a matriz deve aumentar ou diminuir (quando [SetSize](#setsize) ou [FreeExtra](#freeextra) são chamados). A implementação padrão apenas copia os dados.

Para matrizes nas quais um elemento contém um ponteiro para um de seus próprios membros ou outra estrutura contém um ponteiro para um dos elementos da matriz, os ponteiros não são atualizados em cópia simples. Nesse caso, você pode corrigir ponteiros implementando uma especialização de `RelocateElements` com os tipos relevantes. Você também é responsável pela cópia de dados.

##  <a name="removeall"></a>CArray:: RemoveAll

Remove todos os elementos dessa matriz.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Se a matriz já estiver vazia, a função ainda funcionará.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#31](../../mfc/codesnippet/cpp/carray-class_11.cpp)]

##  <a name="removeat"></a>CArray:: RemoveAt

Remove um ou mais elementos que começam em um índice especificado em uma matriz.

```
void RemoveAt(
    INT_PTR nIndex,
    INT_PTR nCount = 1);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).

*nCount*<br/>
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

No processo, ele muda para baixo todos os elementos acima dos elemento (s) removidos. Ele diminui o limite superior da matriz, mas não libera memória.

Se você tentar remover mais elementos do que os contidos na matriz acima do ponto de remoção, a versão de depuração da biblioteca será declarada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#32](../../mfc/codesnippet/cpp/carray-class_12.cpp)]

##  <a name="setat"></a>CArray::SetAt

Define o elemento de matriz no índice especificado.

```
void SetAt(INT_PTR nIndex, ARG_TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo de argumentos usados para referenciar elementos de matriz.

*newElement*<br/>
O novo valor do elemento a ser armazenado na posição especificada.

### <a name="remarks"></a>Comentários

`SetAt` não fará com que a matriz cresça. Use [SetAtGrow](#setatgrow) se você quiser que a matriz cresça automaticamente.

Você deve garantir que o valor do índice representa uma posição válida na matriz. Se estiver fora dos limites, a versão de depuração da biblioteca será declarada.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [GetAt](#getat).

##  <a name="setatgrow"></a>CArray::SetAtGrow

Define o elemento de matriz no índice especificado.

```
void SetAtGrow(INT_PTR nIndex, ARG_TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice de inteiro maior ou igual a 0.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos na matriz.

*newElement*<br/>
O elemento a ser adicionado a esta matriz. Um valor nulo é permitido.

### <a name="remarks"></a>Comentários

A matriz aumenta automaticamente, se necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#33](../../mfc/codesnippet/cpp/carray-class_13.cpp)]

##  <a name="setsize"></a>CArray:: SetSize

Estabelece o tamanho de uma matriz vazia ou existente; aloca memória, se necessário.

```
void SetSize(
    INT_PTR nNewSize,
    INT_PTR nGrowBy = -1);
```

### <a name="parameters"></a>parâmetros

*nNewSize*<br/>
O novo tamanho da matriz (número de elementos). Deve ser maior ou igual a 0.

*nGrowBy*<br/>
O número mínimo de Slots de elemento a serem alocados se um aumento de tamanho for necessário.

### <a name="remarks"></a>Comentários

Se o novo tamanho for menor do que o tamanho antigo, a matriz será truncada e toda a memória não utilizada será liberada.

Use essa função para definir o tamanho da sua matriz antes de começar a usar a matriz. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

O parâmetro *nGrowBy* afeta a alocação de memória interna enquanto a matriz está crescendo. Seu uso nunca afeta o tamanho da matriz conforme relatado por [GetSize](#getsize) e [GetUpperBound](#getupperbound). Se o valor padrão for usado, o MFC alocará a memória de uma maneira calculada para evitar a fragmentação da memória e otimizar a eficiência para a maioria dos casos.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [GetData](#getdata).

## <a name="see-also"></a>Confira também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)<br/>
[Auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md)
