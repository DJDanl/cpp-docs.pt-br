---
title: Classe CMap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c477ee69b8bc8e824aae6df1f74ba97d2825524f
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37039148"
---
# <a name="cmap-class"></a>Classe CMap
Uma classe de coleção de dicionário que mapeia chaves exclusivas para valores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>class CMap : public CObject  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *KEY*  
 Classe do objeto usado como a chave para o mapa.  
  
 *ARG_KEY*  
 Tipo de dados usado para *chave* argumentos; normalmente uma referência a *chave*.  
  
 *VALOR*  
 Classe do objeto armazenado em map.  
  
 *ARG_VALUE*  
 Tipo de dados usado para *valor* argumentos; normalmente uma referência a *valor*.  
  
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
|[CMap::GetCount](#getcount)|Retorna o número de elementos no mapa.|  
|[CMap::GetHashTableSize](#gethashtablesize)|Retorna o número de elementos na tabela de hash.|  
|[CMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento de iteração.|  
|[CMap::GetSize](#getsize)|Retorna o número de elementos no mapa.|  
|[CMap::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|  
|[CMap::InitHashTable](#inithashtable)|Inicializa a tabela de hash e especifica seu tamanho.|  
|[CMap::IsEmpty](#isempty)|Testes para a condição de mapa vazio (nenhum elemento).|  
|[CMap::Lookup](#lookup)|Procura o valor mapeado para uma determinada chave.|  
|[CMap::PGetFirstAssoc](#pgetfirstassoc)|Retorna um ponteiro para o primeiro elemento.|  
|[CMap::PGetNextAssoc](#pgetnextassoc)|Obtém um ponteiro para o próximo elemento de iteração.|  
|[CMap::PLookup](#plookup)|Retorna um ponteiro para uma chave cujo valor corresponde ao valor especificado.|  
|[CMap::RemoveAll](#removeall)|Remove todos os elementos esse mapa.|  
|[CMap::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|  
|[CMap::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente se for encontrada uma chave correspondente.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CMap::operator]](#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt`.|  
  
## <a name="remarks"></a>Comentários  
 Depois que você inseriu um par chave-valor (elemento a) para o mapa, você pode recuperar com eficiência ou excluir o par usando a chave para acessá-lo. Você também pode iterar por todos os elementos no mapa.  
  
 Uma variável do tipo **posição** é usada para acesso alternativo para entradas. Você pode usar um **posição** "lembrar" uma entrada e percorrer o mapa. Você pode achar que essa iteração é sequencial pelo valor de chave; não é. A sequência de elementos recuperados é indeterminada.  
  
 Determinadas funções de membro dessa chamada de classe auxiliar global funções que devem ser personalizadas para a maioria dos usos do `CMap` classe. Consulte [auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção de Macros e globais de `MFC Reference`.  
  
 `CMap` substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para suporte à serialização e despejo de seus elementos. Se um mapa é armazenado em um arquivo morto usando `Serialize`, cada elemento do mapa é serializado por sua vez. A implementação padrão da `SerializeElements` função de auxiliar faz uma gravação de bit a bit. Para obter informações sobre a serialização de itens da coleção de ponteiro derivados da `CObject` ou outros tipos definidos pelo usuário, consulte [como: fazer uma coleção fortemente tipada](../../mfc/how-to-make-a-type-safe-collection.md).  
  
 Se você precisar de um despejo de diagnóstico dos elementos individuais no mapa (as chaves e valores), você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
 Quando um `CMap` objeto é excluído, ou quando seus elementos são removidos, as chaves e valores são removidos.  
  
 Derivação de classe de mapa é semelhante a derivação de lista. Consulte o artigo [coleções](../../mfc/collections.md) para obter uma ilustração de derivação de uma classe especial de lista.  
  
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
 *nBlockSize*  
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
  
- **chave** o valor real do tipo de chave.  
  
- **valor** o valor do objeto associado.  
  
 Ele é usado para armazenar os valores de retorno de [CMap::PLookup](#plookup), [CMap::PGetFirstAssoc](#pgetfirstassoc), e [CMap::PGetNextAssoc](#pgetnextassoc).  
  
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
 Consulte o exemplo para [CMap::Lookup](#lookup).  
  
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
 *rNextPosition*  
 Especifica uma referência a um **posição** valor retornado pelo anterior `GetNextAssoc` ou `GetStartPosition` chamar.  
  
 *KEY*  
 Parâmetro de modelo especificando o tipo de chave do mapa.  
  
 *rKey*  
 Especifica a chave retornada do elemento recuperado.  
  
 *VALOR*  
 Parâmetro de modelo especificando o tipo de valor do mapa.  
  
 *rValue*  
 Especifica o valor retornado do elemento recuperado.  
  
### <a name="remarks"></a>Comentários  
 Essa função é mais útil para iterar através de todos os elementos no mapa. Observe que a sequência de posição não é necessariamente o mesmo que a sequência de valor de chave.  
  
 Se o elemento recuperado é o último no mapa, em seguida, o novo valor de *rNextPosition* é definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::SetAt](#setat).  
  
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
 Inicia uma iteração de mapa, retornando um **posição** valor que pode ser passado para um `GetNextAssoc` chamar.  
  
```  
POSITION GetStartPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que indica uma posição inicial para o mapa; de iteração ou **nulo** se o mapa estiver vazio.  
  
### <a name="remarks"></a>Comentários  
 A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" não tem nenhum significado especial.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::SetAt](#setat).  
  
##  <a name="inithashtable"></a>  CMap::InitHashTable  
 Inicializa a tabela de hash.  
  
```  
void InitHashTable(UINT hashSize, BOOL  bAllocNow = TRUE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *hashSize*  
 Número de entradas na tabela de hash.  
  
 *bAllocNow*  
 Se **TRUE**, aloca a tabela de hash na inicialização; caso contrário, a tabela é alocada quando necessário.  
  
### <a name="remarks"></a>Comentários  
 Para melhor desempenho, o tamanho da tabela de hash deve ser um número primo. Para minimizar colisões, o tamanho deve ser aproximadamente a 20 por cento maior que o maior conjunto de dados esperado.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::Lookup](#lookup).  
  
##  <a name="isempty"></a>  CMap::IsEmpty  
 Determina se o mapa estiver vazio.  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o mapa não contém elementos; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::RemoveAll](#removeall).  
  
##  <a name="lookup"></a>  CMap::Lookup  
 Procura o valor mapeado para uma determinada chave.  
  
```  
BOOL Lookup(ARG_KEY key, VALUE& rValue) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ARG_KEY*  
 Especifica o tipo de parâmetro do modelo de *chave* valor.  
  
 *key*  
 Especifica a chave que identifica o elemento a ser pesquisado.  
  
 *VALOR*  
 Especifica o tipo do valor a ser pesquisado.  
  
 *rValue*  
 Recebe o valor pesquisado-up.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o elemento foi encontrado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `Lookup` usa um algoritmo de hash para localizar rapidamente o elemento do mapa com uma chave que coincide com a chave especificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#58](../../mfc/codesnippet/cpp/cmap-class_3.cpp)]  
  
##  <a name="operator_at"></a>  [CMap::operator]  
 Um substituto conveniente para o `SetAt` função de membro.  
  
```  
VALUE& operator[](arg_key key);
```  
  
### <a name="parameters"></a>Parâmetros  
 *VALOR*  
 Parâmetro de modelo especificando o tipo do valor do mapa.  
  
 *ARG_KEY*  
 Especifica o tipo do valor de chave de parâmetro de modelo.  
  
 *key*  
 A chave usada para recuperar o valor do mapa.  
  
### <a name="remarks"></a>Comentários  
 Assim, ele pode ser usado somente no lado esquerdo de uma instrução de atribuição (um l-value). Se não houver nenhum elemento do mapa com a chave especificada, um novo elemento é criado.  
  
 Não há nenhuma "direita" (r) equivalente ao operador porque há uma possibilidade de que uma chave não pode ser encontrada no mapa. Use o `Lookup` a função de membro para recuperação do elemento.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::Lookup](#lookup).  
  
##  <a name="pgetfirstassoc"></a>  CMap::PGetFirstAssoc  
 Retorna a primeira entrada do objeto de mapa.  
  
```  
const CPair* PGetFirstAssoc() const; 
CPair* PGetFirstAssoc();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a primeira entrada no mapa; consulte [CMap::CPair](#cpair). Se o mapa não contém entradas, o valor será **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar um ponteiro o primeiro elemento no objeto map.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#59](../../mfc/codesnippet/cpp/cmap-class_4.cpp)]  
  
##  <a name="pgetnextassoc"></a>  CMap::PGetNextAssoc  
 Recupera o elemento de mapa apontado pelo *pAssocRec*.  
  
```  
const CPair *PGetNextAssoc(const CPair* pAssocRet) const;  
  
CPair *PGetNextAssoc(const CPair* pAssocRet);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pAssocRet*  
 Aponta para uma entrada de mapa retornada pelo anterior [PGetNextAssoc](#pgetnextassoc) ou [CMap::PGetFirstAssoc](#pgetfirstassoc) chamar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a próxima entrada no mapa; consulte [CMap::CPair](#cpair). Se o elemento é o último no mapa, o valor será **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para iterar por todos os elementos no mapa. Recuperar o primeiro elemento com uma chamada para `PGetFirstAssoc` e, em seguida, percorrer o mapa com as chamadas sucessivas para `PGetNextAssoc`.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::PGetFirstAssoc](#pgetfirstassoc).  
  
##  <a name="plookup"></a>  CMap::PLookup  
 Localiza o valor mapeado para uma determinada chave.  
  
```  
const CPair* PLookup(ARG_KEY key) const;
CPair* PLookup(ARG_KEY key);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *key*  
 Chave do elemento a ser procurado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma estrutura de chave; consulte [CMap::CPair](#cpair). Se nenhuma correspondência for encontrada, `CMap::PLookup` retorna `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para pesquisar um elemento do mapa com uma chave que coincide com a chave especificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#60](../../mfc/codesnippet/cpp/cmap-class_5.cpp)]  
  
##  <a name="removeall"></a>  CMap::RemoveAll  
 Remove todos os valores a partir desse mapa chamando a função auxiliar global **DestructElements**.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 A função funciona corretamente se o mapa já estiver vazio.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#61](../../mfc/codesnippet/cpp/cmap-class_6.cpp)]  
  
##  <a name="removekey"></a>  CMap::RemoveKey  
 Procura a entrada do mapa correspondente à chave fornecida; em seguida, se a chave for encontrada, remove a entrada.  
  
```  
BOOL RemoveKey(ARG_KEY key);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ARG_KEY*  
 Especifica o tipo da chave de parâmetro de modelo.  
  
 *key*  
 Chave do elemento a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a entrada foi encontrada e removida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O **DestructElements** função auxiliar é usada para remover a entrada.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMap::SetAt](#setat).  
  
##  <a name="setat"></a>  CMap::SetAt  
 O principal meio inserir um elemento em um mapa.  
  
```  
void SetAt(ARG_KEY key, ARG_VALUE newValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ARG_KEY*  
 Especifica o tipo de parâmetro do modelo de *chave* parâmetro.  
  
 *key*  
 Especifica a chave do novo elemento.  
  
 *ARG_VALUE*  
 Especifica o tipo de parâmetro do modelo de *newValue* parâmetro.  
  
 *newValue*  
 Especifica o valor do novo elemento.  
  
### <a name="remarks"></a>Comentários  
 Primeiro, a chave é procurada. Se a chave for encontrada, o valor correspondente é alterado; Caso contrário, é criado um novo par chave-valor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#62](../../mfc/codesnippet/cpp/cmap-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)  
