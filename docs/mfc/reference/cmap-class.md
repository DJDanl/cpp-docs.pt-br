---
title: Classe CMap
ms.date: 11/04/2016
f1_keywords:
- CMap
- AFXTEMPL/CMap
- AFXTEMPL/CMap::CPair
- AFXTEMPL/CMap::CMap
- AFXTEMPL/CMap::GetCount
- AFXTEMPL/CMap::GetHashTableSize
- AFXTEMPL/CMap::GetNextAssoc
- AFXTEMPL/CMap::GetSize
- AFXTEMPL/CMap::GetStartPosition
- AFXTEMPL/CMap::InitHashTable
- AFXTEMPL/CMap::IsEmpty
- AFXTEMPL/CMap::Lookup
- AFXTEMPL/CMap::PGetFirstAssoc
- AFXTEMPL/CMap::PGetNextAssoc
- AFXTEMPL/CMap::PLookup
- AFXTEMPL/CMap::RemoveAll
- AFXTEMPL/CMap::RemoveKey
- AFXTEMPL/CMap::SetAt
helpviewer_keywords:
- CMap [MFC], CPair
- CMap [MFC], CMap
- CMap [MFC], GetCount
- CMap [MFC], GetHashTableSize
- CMap [MFC], GetNextAssoc
- CMap [MFC], GetSize
- CMap [MFC], GetStartPosition
- CMap [MFC], InitHashTable
- CMap [MFC], IsEmpty
- CMap [MFC], Lookup
- CMap [MFC], PGetFirstAssoc
- CMap [MFC], PGetNextAssoc
- CMap [MFC], PLookup
- CMap [MFC], RemoveAll
- CMap [MFC], RemoveKey
- CMap [MFC], SetAt
ms.assetid: 640a45ab-0993-4def-97ec-42cc78eb10b9
ms.openlocfilehash: 9a3c92a0a8c3d40e4cc3d289cc0221ff7cdb2e11
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370091"
---
# <a name="cmap-class"></a>Classe CMap

Uma classe de coleção de dicionários que mapeia chaves exclusivas para valores.

## <a name="syntax"></a>Sintaxe

```
template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>class CMap : public CObject
```

#### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Classe do objeto usado como chave para o mapa.

*Arg_key*<br/>
Tipo de dados utilizado para *argumentos-CHAVE;* geralmente uma referência a *KEY*.

*Valor*<br/>
Classe do objeto armazenado no mapa.

*Arg_value*<br/>
Tipo de dados utilizado para argumentos *DE VALOR;* geralmente uma referência ao *VALOR*.

## <a name="members"></a>Membros

### <a name="public-structures"></a>Estruturas Públicas

|Nome|Descrição|
|----------|-----------------|
|[CMap::CPair](#cpair)|Uma estrutura aninhada contendo um valor-chave e o valor do objeto associado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMap::CMap](#cmap)|Constrói uma coleção que mapeia as chaves dos valores.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMap::GetCount](#getcount)|Retorna o número de elementos neste mapa.|
|[CMap::GetHashTableSize](#gethashtablesize)|Retorna o número de elementos na tabela hash.|
|[CMap::GetNextAssoc](#getnextassoc)|Recebe o próximo elemento para iteração.|
|[CMap::GetSize](#getsize)|Retorna o número de elementos neste mapa.|
|[cmap::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMap::InitHashTable](#inithashtable)|Inicializa a tabela hash e especifica seu tamanho.|
|[cmap::IsEmpty](#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMap::Lookup](#lookup)|Olha o valor mapeado para uma determinada chave.|
|[CMap::PGetFirstAssoc](#pgetfirstassoc)|Retorna um ponteiro para o primeiro elemento.|
|[CMap::PGetNextAssoc](#pgetnextassoc)|Recebe um ponteiro para o próximo elemento para iteração.|
|[CMap::PLookup](#plookup)|Retorna um ponteiro para uma chave cujo valor corresponde ao valor especificado.|
|[CMap::RemoveAll](#removeall)|Remove todos os elementos deste mapa.|
|[cmap::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[cmap::Setat](#setat)|Insere um elemento no mapa; substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMap::operador \[\]](#operator_at)|Insere um elemento no mapa `SetAt`— substituição do operador para .|

## <a name="remarks"></a>Comentários

Depois de inserir um par de valor-chave (elemento) no mapa, você pode recuperar ou excluir eficientemente o par usando a chave para acessá-lo. Você também pode iterar sobre todos os elementos do mapa.

Uma variável do tipo POSIÇÃO é usada para acesso alternativo às entradas. Você pode usar uma POSIÇÃO para "lembrar" uma entrada e iterar através do mapa. Você pode pensar que essa iteração é sequencial por valor-chave; não é. A seqüência de elementos recuperados é indeterminada.

Certas funções de membros desta classe chamam funções de ajudante global `CMap` que devem ser personalizadas para a maioria dos usos da classe. Consulte [Os ajudantes de classe de coleta](../../mfc/reference/collection-class-helpers.md) na seção Macros e Globals da referência **MFC**.

`CMap`substitui [cObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para suportar serialização e dumping de seus elementos. Se um mapa for armazenado `Serialize`em um arquivo usando, cada elemento do mapa será serializado por sua vez. A implementação `SerializeElements` padrão da função auxiliar faz uma gravação um pouco mais. Para obter informações sobre serialização de itens `CObject` de coleta de ponteiros derivados ou de outros tipos definidos pelo usuário, consulte [Como: Fazer uma Coleção de Tipo seguro](../../mfc/how-to-make-a-type-safe-collection.md).

Se você precisar de um despejo diagnóstico dos elementos individuais no mapa (as chaves e valores), você deve definir a profundidade do contexto de despejo para 1 ou mais.

Quando `CMap` um objeto é excluído ou quando seus elementos são removidos, as chaves e valores são removidos.

A derivação da classe de mapa é semelhante à derivação de lista. Consulte o artigo [Coleções](../../mfc/collections.md) para obter uma ilustração da derivação de uma classe de lista de propósito especial.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

## <a name="cmapcmap"></a><a name="cmap"></a>CMap::CMap

Constrói um mapa vazio.

```
CMap(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
Especifica a granularidade de alocação de memória para estender o mapa.

### <a name="remarks"></a>Comentários

À medida que o mapa cresce, a memória é alocada em unidades de entradas *nBlockSize.*

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#56](../../mfc/codesnippet/cpp/cmap-class_1.cpp)]

## <a name="cmapcpair"></a><a name="cpair"></a>CMap::CPair

Contém um valor-chave e o valor do objeto associado.

### <a name="remarks"></a>Comentários

Esta é uma estrutura aninhada dentro da classe [CMap](../../mfc/reference/cmap-class.md).

A estrutura é composta por dois campos:

- `key`O valor real do tipo chave.

- `value`O valor do objeto associado.

Ele é usado para armazenar os valores de retorno de [CMap::PLookup,](#plookup) [CMap::PGetFirstAssoc](#pgetfirstassoc)e [CMap::PGetNextAssoc](#pgetnextassoc).

### <a name="example"></a>Exemplo

Para um exemplo de uso, consulte o exemplo de [CMap::PLookup](#plookup).

## <a name="cmapgetcount"></a><a name="getcount"></a>CMap::GetCount

Recupera o número de elementos no mapa.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::Lookup](#lookup).

## <a name="cmapgethashtablesize"></a><a name="gethashtablesize"></a>CMap::GetHashTableSize

Determina o número de elementos na tabela hash para o mapa.

```
UINT GetHashTableSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos na tabela hash.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#57](../../mfc/codesnippet/cpp/cmap-class_2.cpp)]

## <a name="cmapgetnextassoc"></a><a name="getnextassoc"></a>CMap::GetNextAssoc

Recupera o elemento `rNextPosition`mapa em `rNextPosition` , em seguida, atualiza-se para se referir ao próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rNextPosition,
    KEY& rKey,
    VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*Rnextposition*<br/>
Especifica uma referência a um valor DE `GetNextAssoc` `GetStartPosition` POSIÇÃO retornado por uma chamada anterior ou chamada.

*Chave*<br/>
Parâmetro de modelo especificando o tipo da chave do mapa.

*Rkey*<br/>
Especifica a chave devolvida do elemento recuperado.

*Valor*<br/>
Parâmetro de modelo especificando o tipo de valor do mapa.

*Rvalue*<br/>
Especifica o valor retornado do elemento recuperado.

### <a name="remarks"></a>Comentários

Esta função é mais útil para iterar através de todos os elementos do mapa. Observe que a seqüência de posição não é necessariamente a mesma da seqüência de valor-chave.

Se o elemento recuperado for o último no mapa, então o novo valor de *rNextPosition* será definido como NULL.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::SetAt](#setat).

## <a name="cmapgetsize"></a><a name="getsize"></a>CMap::GetSize

Retorna o número de elementos do mapa.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no mapa.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de elementos no mapa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#58](../../mfc/codesnippet/cpp/cmap-class_3.cpp)]

## <a name="cmapgetstartposition"></a><a name="getstartposition"></a>cmap::GetStartPosition

Inicia uma iteração de mapa retornando um valor `GetNextAssoc` DE POSIÇÃO que pode ser passado para uma chamada.

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que indique uma posição inicial para iterar o mapa; ou NULO se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; portanto, o "primeiro elemento no mapa" não tem significado especial.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::SetAt](#setat).

## <a name="cmapinithashtable"></a><a name="inithashtable"></a>CMap::InitHashTable

Inicializa a tabela hash.

```
void InitHashTable(UINT hashSize, BOOL  bAllocNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Hashsize*<br/>
Número de entradas na tabela hash.

*bAllocNow*<br/>
Se TRUE, alocaa a tabela hash após a inicialização; caso contrário, a tabela é alocada quando necessário.

### <a name="remarks"></a>Comentários

Para o melhor desempenho, o tamanho da tabela hash deve ser um número primo. Para minimizar as colisões, o tamanho deve ser cerca de 20% maior do que o maior conjunto de dados previsto.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::Lookup](#lookup).

## <a name="cmapisempty"></a><a name="isempty"></a>cmap::IsEmpty

Determina se o mapa está vazio.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se este mapa não contiver elementos; caso contrário, 0.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::RemoveAll](#removeall).

## <a name="cmaplookup"></a><a name="lookup"></a>CMap::Lookup

Olha o valor mapeado para uma determinada chave.

```
BOOL Lookup(ARG_KEY key, VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*Arg_key*<br/>
Parâmetro de modelo especificando o tipo do *valor-chave.*

*Chave*<br/>
Especifica a chave que identifica o elemento a ser examinado.

*Valor*<br/>
Especifica o tipo do valor a ser analisado.

*Rvalue*<br/>
Recebe o valor de análise.

### <a name="return-value"></a>Valor retornado

Não zero se o elemento foi encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Lookup`usa um algoritmo de hashing para encontrar rapidamente o elemento do mapa com uma chave que corresponde exatamente à chave dada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#58](../../mfc/codesnippet/cpp/cmap-class_3.cpp)]

## <a name="cmapoperator--"></a><a name="operator_at"></a>CMap::operador [ ]

Um substituto conveniente `SetAt` para a função do membro.

```
VALUE& operator[](arg_key key);
```

### <a name="parameters"></a>Parâmetros

*Valor*<br/>
Parâmetro de modelo especificando o tipo do valor do mapa.

*Arg_key*<br/>
Parâmetro de modelo especificando o tipo do valor-chave.

*Chave*<br/>
A chave usada para recuperar o valor do mapa.

### <a name="remarks"></a>Comentários

Assim, ele só pode ser usado no lado esquerdo de uma declaração de atribuição (um valor l). Se não houver nenhum elemento de mapa com a chave especificada, então um novo elemento será criado.

Não há "lado direito" (valor r) equivalente a este operador porque existe a possibilidade de que uma chave não possa ser encontrada no mapa. Use `Lookup` a função membro para recuperação de elementos.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::Lookup](#lookup).

## <a name="cmappgetfirstassoc"></a><a name="pgetfirstassoc"></a>CMap::PGetFirstAssoc

Retorna a primeira entrada do objeto do mapa.

```
const CPair* PGetFirstAssoc() const;
CPair* PGetFirstAssoc();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a primeira entrada no mapa; consulte [CMap::CPair](#cpair). Se o mapa não contiver entradas, o valor será NULA.

### <a name="remarks"></a>Comentários

Chame esta função para retornar um ponteiro o primeiro elemento no objeto do mapa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#59](../../mfc/codesnippet/cpp/cmap-class_4.cpp)]

## <a name="cmappgetnextassoc"></a><a name="pgetnextassoc"></a>CMap::PGetNextAssoc

Recupera o elemento mapa apontado por *pAssocRec*.

```
const CPair *PGetNextAssoc(const CPair* pAssocRet) const;

CPair *PGetNextAssoc(const CPair* pAssocRet);
```

### <a name="parameters"></a>Parâmetros

*pAssocRet*<br/>
Aponta para uma entrada de mapa retornada por um [PGetNextAssoc](#pgetnextassoc) anterior ou [CMap::PGetFirstAssoc](#pgetfirstassoc) call.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a próxima entrada no mapa; consulte [CMap::CPair](#cpair). Se o elemento for o último no mapa, o valor é NULO.

### <a name="remarks"></a>Comentários

Chame este método para iterar através de todos os elementos do mapa. Recupere o primeiro elemento `PGetFirstAssoc` com uma chamada e, em `PGetNextAssoc`seguida, iterar através do mapa com chamadas sucessivas para .

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::PGetFirstAssoc](#pgetfirstassoc).

## <a name="cmapplookup"></a><a name="plookup"></a>CMap::PLookup

Encontra o valor mapeado em uma determinada chave.

```
const CPair* PLookup(ARG_KEY key) const;
CPair* PLookup(ARG_KEY key);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Chave para o elemento a ser pesquisado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura-chave; consulte [CMap::CPair](#cpair). Se nenhuma correspondência `CMap::PLookup` for encontrada, retorna NULL.

### <a name="remarks"></a>Comentários

Chame este método para procurar um elemento de mapa com uma chave que corresponda exatamente à chave dada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#60](../../mfc/codesnippet/cpp/cmap-class_5.cpp)]

## <a name="cmapremoveall"></a><a name="removeall"></a>CMap::RemoveAll

Remove todos os valores deste mapa chamando `DestructElements`a função de ajudante global .

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

A função funciona corretamente se o mapa já estiver vazio.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#61](../../mfc/codesnippet/cpp/cmap-class_6.cpp)]

## <a name="cmapremovekey"></a><a name="removekey"></a>cmap::RemoveKey

Procura a entrada do mapa correspondente à chave fornecida; em seguida, se a chave for encontrada, removerá a entrada.

```
BOOL RemoveKey(ARG_KEY key);
```

### <a name="parameters"></a>Parâmetros

*Arg_key*<br/>
Parâmetro de modelo especificando o tipo da chave.

*Chave*<br/>
Chave para que o elemento seja removido.

### <a name="return-value"></a>Valor retornado

Não zero se a entrada foi encontrada e removida com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `DestructElements` função auxiliar é usada para remover a entrada.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::SetAt](#setat).

## <a name="cmapsetat"></a><a name="setat"></a>cmap::Setat

O principal significa inserir um elemento em um mapa.

```
void SetAt(ARG_KEY key, ARG_VALUE newValue);
```

### <a name="parameters"></a>Parâmetros

*Arg_key*<br/>
Parâmetro de modelo especificando o tipo do parâmetro *da chave.*

*Chave*<br/>
Especifica a chave do novo elemento.

*Arg_value*<br/>
Parâmetro de modelo especificando o tipo do parâmetro *newValue.*

*newValue*<br/>
Especifica o valor do novo elemento.

### <a name="remarks"></a>Comentários

Primeiro, a chave é examinada para cima. Se a chave for encontrada, o valor correspondente será alterado; caso contrário, um novo par de valor de chave é criado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#62](../../mfc/codesnippet/cpp/cmap-class_7.cpp)]

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
