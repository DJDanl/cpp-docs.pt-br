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
ms.openlocfilehash: 58f9efb19988be8487ec87ce0c63d90ee1a97911
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58769830"
---
# <a name="cmap-class"></a>Classe CMap

Uma classe de coleção de dicionário que mapeia chaves exclusivas para valores.

## <a name="syntax"></a>Sintaxe

```
template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>class CMap : public CObject
```

#### <a name="parameters"></a>Parâmetros

*KEY*<br/>
Classe do objeto usado como a chave para o mapa.

*ARG_KEY*<br/>
Tipo de dados usado para *chave* argumentos; geralmente, uma referência a *chave*.

*VALUE*<br/>
Classe do objeto armazenado no mapa.

*ARG_VALUE*<br/>
Tipo de dados usado para *valor* argumentos; geralmente, uma referência a *valor*.

## <a name="members"></a>Membros

### <a name="public-structures"></a>Estruturas públicas

|Nome|Descrição|
|----------|-----------------|
|[CMap::CPair](#cpair)|Uma estrutura aninhada que contém um valor de chave e o valor do objeto associado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMap::CMap](#cmap)|Constrói uma coleção que mapeia chaves para valores.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMap::GetCount](#getcount)|Retorna o número de elementos neste mapa.|
|[CMap::GetHashTableSize](#gethashtablesize)|Retorna o número de elementos na tabela de hash.|
|[CMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento para a iteração.|
|[CMap::GetSize](#getsize)|Retorna o número de elementos neste mapa.|
|[CMap::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMap::InitHashTable](#inithashtable)|Inicializa a tabela de hash e especifica seu tamanho.|
|[CMap::IsEmpty](#isempty)|Testa a condição de mapa vazio (sem elementos).|
|[CMap::Lookup](#lookup)|Procura o valor mapeado para uma determinada chave.|
|[CMap::PGetFirstAssoc](#pgetfirstassoc)|Retorna um ponteiro para o primeiro elemento.|
|[CMap::PGetNextAssoc](#pgetnextassoc)|Obtém um ponteiro para o próximo elemento para a iteração.|
|[CMap::PLookup](#plookup)|Retorna um ponteiro para uma chave cujo valor corresponde ao valor especificado.|
|[CMap::RemoveAll](#removeall)|Remove todos os elementos a partir desse mapa.|
|[CMap::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[CMap::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente, se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMap::operator \[ \]](#operator_at)|Insere um elemento no mapa — substituição do operador para `SetAt`.|

## <a name="remarks"></a>Comentários

Depois de você ter inserido um par chave-valor (elemento) no mapa, você pode recuperar com eficiência ou excluir o par usando a chave para acessá-lo. Você também pode iterar sobre todos os elementos no mapa.

Uma variável do tipo de que posição é usada para acesso alternativo para entradas. Você pode usar uma posição para uma entrada de "lembrar" e iterar o mapa. Você pode pensar que essa iteração é sequencial pelo valor de chave; não é. A sequência de elementos recuperados é indeterminada.

Determinadas funções de membro dessa chamada de classe auxiliar global de funções que devem ser personalizadas para a maioria dos usos do `CMap` classe. Ver [auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção de Macros e globais a **referência da MFC**.

`CMap` substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para dar suporte à serialização e despejo de seus elementos. Se um mapa é armazenado em um arquivo morto usando `Serialize`, cada elemento do mapa é serializado por vez. A implementação padrão da `SerializeElements` função auxiliar faz uma gravação de bit a bit. Para obter informações sobre a serialização de itens de coleta de ponteiro é derivada de `CObject` ou outros tipos definidos pelo usuário, consulte [como: Fazer uma coleção fortemente tipada](../../mfc/how-to-make-a-type-safe-collection.md).

Se você precisar de um despejo de diagnóstico dos elementos individuais no mapa (as chaves e valores), você deve definir a profundidade do contexto de despejo para 1 ou maior.

Quando um `CMap` objeto é excluído, ou quando seus elementos são removidos, as chaves e valores são removidos.

Derivação de classe de mapa é semelhante à derivação de lista. Consulte o artigo [coleções](../../mfc/collections.md) para obter uma ilustração da derivação de uma classe de lista de finalidade especial.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

##  <a name="cmap"></a>  CMap::CMap

Constrói um mapa vazio.

```
CMap(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*nBlockSize*<br/>
Especifica a granularidade de alocação de memória para estender o mapa.

### <a name="remarks"></a>Comentários

À medida que cresce o mapa, a memória é alocada em unidades de *nBlockSize* entradas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#56](../../mfc/codesnippet/cpp/cmap-class_1.cpp)]

##  <a name="cpair"></a>  CMap::CPair

Contém um valor de chave e o valor do objeto associado.

### <a name="remarks"></a>Comentários

Essa é uma estrutura aninhada dentro da classe [CMap](../../mfc/reference/cmap-class.md).

A estrutura é composta de dois campos:

- `key` O valor real do tipo de chave.

- `value` O valor do objeto associado.

Ele é usado para armazenar os valores de retorno [CMap::PLookup](#plookup), [CMap::PGetFirstAssoc](#pgetfirstassoc), e [CMap::PGetNextAssoc](#pgetnextassoc).

### <a name="example"></a>Exemplo

Para obter um exemplo de uso, consulte o exemplo para [CMap::PLookup](#plookup).

##  <a name="getcount"></a>  CMap::GetCount

Recupera o número de elementos no mapa.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::Lookup](#lookup).

##  <a name="gethashtablesize"></a>  CMap::GetHashTableSize

Determina o número de elementos na tabela de hash para o mapa.

```
UINT GetHashTableSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos na tabela de hash.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#57](../../mfc/codesnippet/cpp/cmap-class_2.cpp)]

##  <a name="getnextassoc"></a>  CMap::GetNextAssoc

Recupera o elemento de mapa na `rNextPosition`, em seguida, atualiza `rNextPosition` para referir-se para o próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rNextPosition,
    KEY& rKey,
    VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*rNextPosition*<br/>
Especifica uma referência a um valor de posição retornado por uma anterior `GetNextAssoc` ou `GetStartPosition` chamar.

*KEY*<br/>
Parâmetro de modelo especificando o tipo de chave do mapa.

*rKey*<br/>
Especifica a chave retornada do elemento de dados recuperado.

*VALUE*<br/>
Parâmetro de modelo que especifica o tipo de valor do mapa.

*rValue*<br/>
Especifica o valor retornado do elemento de dados recuperado.

### <a name="remarks"></a>Comentários

Essa função é mais útil para iterar por meio de todos os elementos no mapa. Observe que a sequência de posição não é necessariamente o mesmo que a sequência de valor de chave.

Se o elemento recuperado é o último no mapa, em seguida, o novo valor de *rNextPosition* é definido como NULL.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::SetAt](#setat).

##  <a name="getsize"></a>  CMap::GetSize

Retorna o número de elementos do mapa.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens no mapa.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos no mapa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#58](../../mfc/codesnippet/cpp/cmap-class_3.cpp)]

##  <a name="getstartposition"></a>  CMap::GetStartPosition

Inicia uma iteração de mapa, retornando um valor de posição que pode ser passado para um `GetNextAssoc` chamar.

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de posição que indica uma posição inicial para iterar o mapa; ou nulo se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" tem nenhum significado especial.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::SetAt](#setat).

##  <a name="inithashtable"></a>  CMap::InitHashTable

Inicializa a tabela de hash.

```
void InitHashTable(UINT hashSize, BOOL  bAllocNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*hashSize*<br/>
Número de entradas na tabela de hash.

*bAllocNow*<br/>
Se for TRUE, aloca a tabela de hash na inicialização; Caso contrário, a tabela é alocada quando necessário.

### <a name="remarks"></a>Comentários

Para obter melhor desempenho, o tamanho da tabela de hash deve ser um número primo. Para minimizar colisões, deve ser o tamanho aproximadamente 20 por cento maior do que o maior conjunto de dados previsto.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::Lookup](#lookup).

##  <a name="isempty"></a>  CMap::IsEmpty

Determina se o mapa estiver vazio.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se este mapa não contiver elementos; Caso contrário, 0.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::RemoveAll](#removeall).

##  <a name="lookup"></a>  CMap::Lookup

Procura o valor mapeado para uma determinada chave.

```
BOOL Lookup(ARG_KEY key, VALUE& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*ARG_KEY*<br/>
Especifica o tipo de parâmetro do modelo de *chave* valor.

*key*<br/>
Especifica a chave que identifica o elemento a ser pesquisado.

*VALUE*<br/>
Especifica o tipo do valor a ser pesquisado.

*rValue*<br/>
Recebe o valor pesquisado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o elemento foi encontrado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

`Lookup` usa um algoritmo de hash para localizar rapidamente o elemento do mapa com uma chave que corresponde exatamente a chave especificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#58](../../mfc/codesnippet/cpp/cmap-class_3.cpp)]

##  <a name="operator_at"></a>  [CMap::operator]

Um substituto conveniente para o `SetAt` função de membro.

```
VALUE& operator[](arg_key key);
```

### <a name="parameters"></a>Parâmetros

*VALUE*<br/>
Parâmetro de modelo que especifica o tipo do valor do mapa.

*ARG_KEY*<br/>
Especifica o tipo do valor de chave de parâmetro de modelo.

*key*<br/>
A chave usada para recuperar o valor do mapa.

### <a name="remarks"></a>Comentários

Portanto, ele pode ser usado apenas no lado esquerdo de uma instrução de atribuição (um l-value). Se não houver nenhum elemento do mapa com a chave especificada, um novo elemento é criado.

Não há nenhum "direita" (r-Value) equivalente ao operador porque não há uma possibilidade de que uma chave não pode ser encontrada no mapa. Use o `Lookup` a função de membro para a recuperação do elemento.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::Lookup](#lookup).

##  <a name="pgetfirstassoc"></a>  CMap::PGetFirstAssoc

Retorna a primeira entrada de objeto de mapa.

```
const CPair* PGetFirstAssoc() const;
CPair* PGetFirstAssoc();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a primeira entrada no mapa; ver [CMap::CPair](#cpair). Se o mapa não contém nenhuma entrada, o valor é NULL.

### <a name="remarks"></a>Comentários

Chame essa função para retornar um ponteiro do primeiro elemento no objeto de mapa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#59](../../mfc/codesnippet/cpp/cmap-class_4.cpp)]

##  <a name="pgetnextassoc"></a>  CMap::PGetNextAssoc

Recupera o elemento de mapa apontado por *pAssocRec*.

```
const CPair *PGetNextAssoc(const CPair* pAssocRet) const;

CPair *PGetNextAssoc(const CPair* pAssocRet);
```

### <a name="parameters"></a>Parâmetros

*pAssocRet*<br/>
Aponta para uma entrada de mapa retornada por uma anterior [PGetNextAssoc](#pgetnextassoc) ou [CMap::PGetFirstAssoc](#pgetfirstassoc) chamar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a próxima entrada no mapa; ver [CMap::CPair](#cpair). Se o elemento é o último no mapa, o valor é NULL.

### <a name="remarks"></a>Comentários

Chame esse método para iterar em todos os elementos no mapa. Recuperar o primeiro elemento com uma chamada para `PGetFirstAssoc` e, em seguida, iterar o mapa com as chamadas sucessivas para `PGetNextAssoc`.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::PGetFirstAssoc](#pgetfirstassoc).

##  <a name="plookup"></a>  CMap::PLookup

Localiza o valor mapeado para uma determinada chave.

```
const CPair* PLookup(ARG_KEY key) const;
CPair* PLookup(ARG_KEY key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave para o elemento a ser procurado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma estrutura de chave; ver [CMap::CPair](#cpair). Se nenhuma correspondência for encontrada, `CMap::PLookup` retorna NULL.

### <a name="remarks"></a>Comentários

Chame esse método para pesquisar um elemento do mapa com uma chave que corresponde exatamente a chave especificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#60](../../mfc/codesnippet/cpp/cmap-class_5.cpp)]

##  <a name="removeall"></a>  CMap::RemoveAll

Remove todos os valores a partir desse mapa chamando a função auxiliar global `DestructElements`.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

A função funciona corretamente se o mapa já estiver vazio.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#61](../../mfc/codesnippet/cpp/cmap-class_6.cpp)]

##  <a name="removekey"></a>  CMap::RemoveKey

Procura a entrada de mapa que corresponde à chave fornecida; em seguida, se a chave for encontrada, remove a entrada.

```
BOOL RemoveKey(ARG_KEY key);
```

### <a name="parameters"></a>Parâmetros

*ARG_KEY*<br/>
Especifica o tipo da chave de parâmetro de modelo.

*key*<br/>
A chave para o elemento a ser removido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a entrada tiver sido encontrada e removida com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O `DestructElements` função auxiliar é usada para remover a entrada.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMap::SetAt](#setat).

##  <a name="setat"></a>  CMap::SetAt

O principal meio inserir um elemento em um mapa.

```
void SetAt(ARG_KEY key, ARG_VALUE newValue);
```

### <a name="parameters"></a>Parâmetros

*ARG_KEY*<br/>
Especifica o tipo de parâmetro do modelo de *chave* parâmetro.

*key*<br/>
Especifica a chave do novo elemento.

*ARG_VALUE*<br/>
Especifica o tipo de parâmetro do modelo de *newValue* parâmetro.

*newValue*<br/>
Especifica o valor do novo elemento.

### <a name="remarks"></a>Comentários

Em primeiro lugar, a chave é pesquisada. Se a chave for encontrada, então, o valor correspondente é alterado; Caso contrário, é criado um novo par chave-valor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#62](../../mfc/codesnippet/cpp/cmap-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC COLETAR](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
