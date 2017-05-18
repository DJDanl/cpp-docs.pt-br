---
title: Classe CAtlMap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlMap
- ATLCOLL/ATL::CAtlMap
- ATLCOLL/ATL::CAtlMap::KINARGTYPE
- ATLCOLL/ATL::CAtlMap::KOUTARGTYPE
- ATLCOLL/ATL::CAtlMap::VINARGTYPE
- ATLCOLL/ATL::CAtlMap::VOUTARGTYPE
- ATLCOLL/ATL::CPair::m_key
- ATLCOLL/ATL::CPair::m_value
- ATLCOLL/ATL::CAtlMap::CAtlMap
- ATLCOLL/ATL::CAtlMap::AssertValid
- ATLCOLL/ATL::CAtlMap::DisableAutoRehash
- ATLCOLL/ATL::CAtlMap::EnableAutoRehash
- ATLCOLL/ATL::CAtlMap::GetAt
- ATLCOLL/ATL::CAtlMap::GetCount
- ATLCOLL/ATL::CAtlMap::GetHashTableSize
- ATLCOLL/ATL::CAtlMap::GetKeyAt
- ATLCOLL/ATL::CAtlMap::GetNext
- ATLCOLL/ATL::CAtlMap::GetNextAssoc
- ATLCOLL/ATL::CAtlMap::GetNextKey
- ATLCOLL/ATL::CAtlMap::GetNextValue
- ATLCOLL/ATL::CAtlMap::GetStartPosition
- ATLCOLL/ATL::CAtlMap::GetValueAt
- ATLCOLL/ATL::CAtlMap::InitHashTable
- ATLCOLL/ATL::CAtlMap::IsEmpty
- ATLCOLL/ATL::CAtlMap::Lookup
- ATLCOLL/ATL::CAtlMap::Rehash
- ATLCOLL/ATL::CAtlMap::RemoveAll
- ATLCOLL/ATL::CAtlMap::RemoveAtPos
- ATLCOLL/ATL::CAtlMap::RemoveKey
- ATLCOLL/ATL::CAtlMap::SetAt
- ATLCOLL/ATL::CAtlMap::SetOptimalLoad
- ATLCOLL/ATL::CAtlMap::SetValueAt
dev_langs:
- C++
helpviewer_keywords:
- CAtlMap class
ms.assetid: 5e2fe028-8e6d-4686-93df-1433d2080ec3
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 3730827a56c47497db2fd8324f54c7ba88a584d6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="catlmap-class"></a>Classe CAtlMap
Essa classe fornece métodos para criar e gerenciar um objeto de mapa.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename K,
          typename V, 
          class KTraits = CElementTraits<K>, 
          class VTraits = CElementTraits<V>>
class CAtlMap
```  
  
#### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo de elemento de chave.  
  
 V  
 O tipo de elemento de valor.  
  
 `KTraits`  
 O código usado para copiar ou mover elementos-chave. Consulte [CElementTraits classe](../../atl/reference/celementtraits-class.md) para obter mais detalhes.  
  
 `VTraits`  
 O código usado para copiar ou mover elementos de valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlMap::KINARGTYPE](#kinargtype)|Tipo usado quando uma chave é passada como um argumento de entrada|  
|[CAtlMap::KOUTARGTYPE](#koutargtype)|Tipo usado quando uma chave é retornada como um argumento de saída.|  
|[CAtlMap::VINARGTYPE](#vinargtype)|Tipo usado quando um valor é passado como um argumento de entrada.|  
|[CAtlMap::VOUTARGTYPE](#voutargtype)|Tipo usado quando um valor é passado como um argumento de saída.|  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe CAtlMap::CPair](#cpair_class)|Uma classe que contém os elementos de chave e valor.|  

  
### <a name="cpair-data-members"></a>Membros de dados CPair  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPair::m_key](#m_key)|O membro de dados armazenando um elemento-chave.|  
|[CPair::m_value](#m_value)|O membro de dados armazenando o elemento de valor.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlMap::CAtlMap](#catlmap)|O construtor.|  
|[CAtlMap:: ~ CAtlMap](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlMap::AssertValid](#assertvalid)|Chamar esse método para fazer com que uma declaração se o `CAtlMap` não é válido.|  
|[CAtlMap::DisableAutoRehash](#disableautorehash)|Chame esse método para desabilitar automática refazendo o hash do `CAtlMap` objeto.|  
|[CAtlMap::EnableAutoRehash](#enableautorehash)|Chame esse método para habilitar automática refazendo o hash do `CAtlMap` objeto.|  
|[CAtlMap::GetAt](#getat)|Chame esse método para retornar o elemento em uma posição especificada no mapa.|  
|[CAtlMap::GetCount](#getcount)|Chame esse método para recuperar o número de elementos no mapa.|  
|[CAtlMap::GetHashTableSize](#gethashtablesize)|Chame esse método para determinar o número de compartimentos na tabela de hash do mapa.|  
|[CAtlMap::GetKeyAt](#getkeyat)|Chame esse método para recuperar a chave armazenada na posição especificada no `CAtlMap` objeto.|  
|[CAtlMap::GetNext](#getnext)|Chame esse método para obter um ponteiro para o próximo elemento par armazenado na `CAtlMap` objeto.|  
|[CAtlMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento de iteração.|  
|[CAtlMap::GetNextKey](#getnextkey)|Chame esse método para recuperar a próxima chave do `CAtlMap` objeto.|  
|[CAtlMap::GetNextValue](#getnextvalue)|Chame esse método para obter o próximo valor de `CAtlMap` objeto.|  
|[CAtlMap::GetStartPosition](#getstartposition)|Chame esse método para iniciar uma iteração de mapa.|  
|[CAtlMap::GetValueAt](#getvalueat)|Chame esse método para recuperar o valor armazenado em uma determinada posição de `CAtlMap` objeto.|  
|[CAtlMap::InitHashTable](#inithashtable)|Chame esse método para inicializar a tabela de hash.|  
|[CAtlMap::IsEmpty](#isempty)|Chame esse método para testar um objeto vazio do mapa.|  
|[CAtlMap::Lookup](#lookup)|Chamar esse método para pesquisar chaves ou valores de `CAtlMap` objeto.|  
|[CAtlMap::Rehash](#rehash)|Chame este método para rehash o `CAtlMap` objeto.|  
|[CAtlMap::RemoveAll](#removeall)|Chame esse método para remover todos os elementos do `CAtlMap` objeto.|  
|[CAtlMap::RemoveAtPos](#removeatpos)|Chame esse método para remover o elemento na posição especificada no `CAtlMap` objeto.|  
|[CAtlMap::RemoveKey](#removekey)|Chame esse método para remover um elemento de `CAtlMap` objeto, dado a chave.|  
|[CAtlMap::SetAt](#setat)|Chame esse método para inserir um par de elemento no mapa.|  
|[CAtlMap::SetOptimalLoad](#setoptimalload)|Chamar esse método para definir a carga ideal do `CAtlMap` objeto.|  
|[CAtlMap::SetValueAt](#setvalueat)|Chame esse método para alterar o valor armazenado em uma determinada posição de `CAtlMap` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlMap::operator\[\]](catlmap-class.md#operator_at)|Substitui ou adiciona um novo elemento para o `CAtlMap`.|  

  
## <a name="remarks"></a>Comentários  
 `CAtlMap`fornece suporte para uma matriz de mapeamento de qualquer tipo de dado, gerenciando uma matriz não ordenada de elementos-chave e seus valores associados. Elementos (consistindo em uma chave e um valor) são armazenados usando um algoritmo de hash, permitindo que uma grande quantidade de dados a serem armazenados e recuperados com eficiência.  
  
 O `KTraits` e `VTraits` parâmetros são classes de características que contêm qualquer código complementar necessário para copiar ou mover elementos.  
  
 Uma alternativa para `CAtlMap` é oferecida pelo [CRBMap](../../atl/reference/crbmap-class.md) classe. `CRBMap`também armazena os pares chave/valor, mas apresenta características de desempenho diferentes. O tempo necessário para inserir um item, pesquisar uma chave ou excluir uma chave de um `CRBMap` provém da ordem de *log(n)*, onde *n* é o número de elementos. Para `CAtlMap`, todas essas operações normalmente demoram constante, embora os cenários mais desfavoráveis podem ser ordem *n*. Portanto, em um caso típico, `CAtlMap` é mais rápido.  
  
 A outra diferença entre `CRBMap` e `CAtlMap` se torna aparente quando iterar através dos elementos armazenados. Em um `CRBMap`, os elementos são visitados em uma ordem classificada. Em um `CAtlMap`, os elementos não são classificados e nenhuma ordem pode ser inferida.  
  
 Quando um pequeno número de elementos precisa ser armazenados, considere o uso de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe em vez disso.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="assertvalid"></a>CAtlMap::AssertValid  
 Chamar esse método para fazer com que uma declaração se o `CAtlMap` objeto não é válido.  
  
```
void AssertValid() const;
```  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, esse método fará com que uma declaração se o `CAtlMap` objeto não é válido.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="catlmap"></a>CAtlMap::CAtlMap  
 O construtor.  
  
```
CAtlMap(
    UINT nBins = 17,
    float fOptimalLoad = 0.75f,
    float fLoThreshold = 0.25f,
    float fHiThreshold = 2.25f,
    UINT nBlockSize = 10) throw ();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBins`  
 O número de compartimentos fornece ponteiros para os elementos armazenados. Consulte comentários mais adiante neste tópico para obter uma explicação de compartimentos.  
  
 `fOptimalLoad`  
 A taxa de carga ideal.  
  
 `fLoThreshold`  
 O limite inferior para a taxa de carga.  
  
 `fHiThreshold`  
 O limite superior para a taxa de carga.  
  
 `nBlockSize`  
 O tamanho do bloco.  
  
### <a name="remarks"></a>Comentários  
 `CAtlMap`todos os seus elementos armazenados faz referência ao primeiro criar um índice usando um algoritmo de hash na chave. Esse índice faz referência a um "bin" que contém um ponteiro para os elementos armazenados. Se o agrupamento já está em uso, uma lista vinculada é criada para acessar os elementos subsequentes. Como percorrer uma lista é menor que acessar diretamente o elemento correto, e então a estrutura do mapa precisa equilibrar os requisitos de armazenamento em relação ao desempenho. Os parâmetros padrão foram escolhidos para oferecer bons resultados na maioria dos casos.  
  
 A taxa de carga é a proporção do número de compartimentos para o número de elementos armazenados no objeto de mapa. Quando a estrutura do mapa é recalculada, o *fOptimalLoad* o valor do parâmetro será usado para calcular o número de compartimentos necessárias. Esse valor pode ser alterado usando o [CAtlMap::SetOptimalLoad](#setoptimalload) método.  
  
 O `fLoThreshold` parâmetro é o menor valor que a taxa de carga pode atingir antes `CAtlMap` recalculará o tamanho ideal do mapa.  
  
 O `fHiThreshold` parâmetro é o valor superior a taxa de carga pode atingir antes do `CAtlMap` objeto recalculará o tamanho ideal do mapa.  
  
 Esse processo de recálculo (conhecido como refazendo o hash) é habilitado por padrão. Se você quiser desabilitar esse processo, talvez ao inserir uma grande quantidade de dados ao mesmo tempo, chamada de [CAtlMap::DisableAutoRehash](#disableautorehash) método. Reativá-la com o [CAtlMap::EnableAutoRehash](#enableautorehash) método.  
  
 O `nBlockSize` parâmetro é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos maiores de bloco reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.  
  
 Antes de todos os dados podem ser armazenados, é necessário inicializar a tabela de hash com uma chamada para [CAtlMap::InitHashTable](#inithashtable).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#72;](../../atl/codesnippet/cpp/catlmap-class_1.cpp)]  
  
##  <a name="dtor"></a>CAtlMap:: ~ CAtlMap  
 O destruidor.  
  
```
~CAtlMap() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="cpair_class"></a>Classe CAtlMap::CPair  
 Uma classe que contém os elementos de chave e valor.  
  
```
class CPair : public __POSITION
```  
  
### <a name="remarks"></a>Comentários  
 Essa classe é usada pelos métodos [CAtlMap::GetNext](#getnext) e [CAtlMap::Lookup](#lookup) para acessar os elementos de chave e o valor armazenados na estrutura de mapeamento.  
  
##  <a name="disableautorehash"></a>CAtlMap::DisableAutoRehash  
 Chame esse método para desabilitar automática refazendo o hash do `CAtlMap` objeto.  
  
```
void DisableAutoRehash() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando refazendo o hash automático está habilitado (que é o padrão), o número de compartimentos na tabela de hash será recalculado automaticamente se o valor de carga (a proporção do número de compartimentos para o número de elementos armazenados na matriz) excede o valor máximo ou mínimo especificado no momento em que o mapa foi criado.  
  
 `DisableAutoRehash`é mais útil quando um grande número de elementos será adicionado ao mapa de uma só vez. Em vez de disparar o processo rehashing toda vez que os limites são excedidos, é mais eficiente chamar `DisableAutoRehash`, adicione os elementos e, finalmente, chamar [CAtlMap::EnableAutoRehash](#enableautorehash).  
  
##  <a name="enableautorehash"></a>CAtlMap::EnableAutoRehash  
 Chame esse método para habilitar automática refazendo o hash do `CAtlMap` objeto.  
  
```
void EnableAutoRehash() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando refazendo o hash automático está habilitado (que é o padrão), o número de compartimentos na tabela de hash será recalculado automaticamente se o valor de carga (a proporção do número de compartimentos para o número de elementos armazenados na matriz) excede o valor máximo ou mínimo especificado no momento em que o mapa é criado.  
  
 **EnableAutoRefresh** é geralmente usada após uma chamada para [CAtlMap::DisableAutoRehash](#disableautorehash).  
  
##  <a name="getat"></a>CAtlMap::GetAt  
 Chame esse método para retornar o elemento em uma posição especificada no mapa.  
  
```
void GetAt(
    POSITION pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;

CPair* GetAt(POSITION& pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
 `key`  
 Parâmetro de modelo especificando o tipo de chave do mapa.  
  
 *value*  
 Parâmetro de modelo especificando o tipo de valor do mapa.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o atual par de elementos de chave/valor armazenados no mapa.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, um erro de asserção ocorrerá se `pos` é igual a nulo.  
  
##  <a name="getcount"></a>CAtlMap::GetCount  
 Chame esse método para recuperar o número de elementos no mapa.  
  
```
size_t GetCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos no objeto de mapa. Um único elemento é um par chave/valor.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="gethashtablesize"></a>CAtlMap::GetHashTableSize  
 Chame esse método para determinar o número de compartimentos na tabela de hash do mapa.  
  
```
UINT GetHashTableSize() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de compartimentos na tabela de hash. Consulte [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.  
  
##  <a name="getkeyat"></a>CAtlMap::GetKeyAt  
 Chame esse método para recuperar a chave armazenada na posição especificada no `CAtlMap` objeto.  
  
```
const K& GetKeyAt(POSITION pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a chave armazenada na posição especificada no `CAtlMap` objeto.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="getnext"></a>CAtlMap::GetNext  
 Chame esse método para obter um ponteiro para o próximo elemento par armazenado na `CAtlMap` objeto.  
  
```
CPair* GetNext(POSITION& pos) throw();
const CPair* GetNext(POSITION& pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o próximo par de elementos de chave/valor armazenados no mapa. O `pos` posição é atualizado após cada chamada. Se o elemento recuperado é o último no mapa, `pos` é definido como NULL.  
  
##  <a name="getnextassoc"></a>CAtlMap::GetNextAssoc  
 Obtém o próximo elemento de iteração.  
  
```
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
 `key`  
 Parâmetro de modelo especificando o tipo de chave do mapa.  
  
 *value*  
 Parâmetro de modelo especificando o tipo de valor do mapa.  
  
### <a name="remarks"></a>Comentários  
 O `pos` posição é atualizado após cada chamada. Se o elemento recuperado é o último no mapa, `pos` é definido como NULL.  
  
##  <a name="getnextkey"></a>CAtlMap::GetNextKey  
 Chame esse método para recuperar a próxima chave do `CAtlMap` objeto.  
  
```
const K& GetNextKey(POSITION& pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a próxima chave no mapa.  
  
### <a name="remarks"></a>Comentários  
 Atualiza o contador de posição atual, `pos`. Se não existem mais entradas no mapa, o contador de posição é definido como NULL.  
  
##  <a name="getnextvalue"></a>CAtlMap::GetNextValue  
 Chame esse método para obter o próximo valor de `CAtlMap` objeto.  
  
```
V& GetNextValue(POSITION& pos) throw();
const V& GetNextValue(POSITION& pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o próximo valor no mapa.  
  
### <a name="remarks"></a>Comentários  
 Atualiza o contador de posição atual, `pos`. Se não existem mais entradas no mapa, o contador de posição é definido como NULL.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="getstartposition"></a>CAtlMap::GetStartPosition  
 Chame esse método para iniciar uma iteração de mapa.  
  
```
POSITION GetStartPosition() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna que a posição inicial ou nulo será retornado se o mapa estiver vazio.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para iniciar uma iteração de mapa, retornando uma **posição** valor que pode ser passado para o `GetNextAssoc` método.  
  
> [!NOTE]
>  A sequência de iteração não é previsível  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="getvalueat"></a>CAtlMap::GetValueAt  
 Chame esse método para recuperar o valor armazenado em uma determinada posição de `CAtlMap` objeto.  
  
```
V& GetValueAt(POSITION pos) throw();
const V& GetValueAt(POSITION pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o valor armazenado na posição especificada no `CAtlMap` objeto.  
  
##  <a name="inithashtable"></a>CAtlMap::InitHashTable  
 Chame esse método para inicializar a tabela de hash.  
  
```
bool InitHashTable(
    UINT nBins,
    bool bAllocNow = true);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBins`  
 O número de compartimentos usado pela tabela de hash. Consulte [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.  
  
 `bAllocNow`  
 Uma indicação de sinalizador quando a memória deve ser alocada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** na inicialização bem-sucedida, **false** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `InitHashTable`deve ser chamado antes de todos os elementos são armazenados na tabela de hash.  Se esse método não for chamado explicitamente, ele será chamado automaticamente na primeira vez que um elemento é adicionado usando a contagem bin especificada pelo **CAtlMap** construtor.  Caso contrário, o mapa será inicializado usando a nova contagem bin especificada pelo `nBins` parâmetro.  
  
 Se o `bAllocNow` parâmetro for false, a memória exigida pela tabela de hash não será alocada até que o primeiro é necessário. Isso pode ser útil se não tiver certeza se o mapa será usado.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="isempty"></a>CAtlMap::IsEmpty  
 Chame esse método para testar um objeto vazio do mapa.  
  
```
bool IsEmpty() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o mapa estiver vazio, **false** caso contrário.  
  
##  <a name="kinargtype"></a>CAtlMap::KINARGTYPE  
 Tipo usado quando uma chave é passada como um argumento de entrada.  
  
```
typedef KTraits::INARGTYPE KINARGTYPE;
```  
  
##  <a name="koutargtype"></a>CAtlMap::KOUTARGTYPE  
 Tipo usado quando uma chave é retornada como um argumento de saída.  
  
```
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```  
  
##  <a name="lookup"></a>CAtlMap::Lookup  
 Chamar esse método para pesquisar chaves ou valores de `CAtlMap` objeto.  
  
```
bool Lookup(KINARGTYPE key, VOUTARGTYPE value) const;
const CPair* Lookup(KINARGTYPE key) const throw();
CPair* Lookup(KINARGTYPE key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Especifica a chave que identifica o elemento a ser pesquisado.  
  
 *value*  
 Variável que recebe o valor up procurada.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira forma do método retornará true se a chave for encontrada, caso contrário, false. Os formulários de segundo e terceiro retornam um ponteiro para um [CPair](#cpair_class) que pode ser usado como uma posição para chamadas para [CAtlMap::GetNext](#getnext) e assim por diante.  
  
### <a name="remarks"></a>Comentários  
 `Lookup`usa um algoritmo de hash para localizar rapidamente o elemento de mapa contendo uma chave que corresponda exatamente ao determinado parâmetro chave.  
  
##  <a name="operator_at"></a>CAtlMap::operator\[\]  
 Substitui ou adiciona um novo elemento para o `CAtlMap`.  
  
```
V& operator[](kinargtype key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave do elemento para adicionar ou substituir.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o valor associado com a chave especificada.  
  
### <a name="example"></a>Exemplo  
 Se a chave já existir, o elemento é substituído. Se a chave não existir, um novo elemento é adicionado. Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="rehash"></a>CAtlMap::Rehash  
 Chame este método para rehash o `CAtlMap` objeto.  
  
```
void Rehash(UINT nBins = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBins`  
 O novo número de compartimentos para usar na tabela de hash. Consulte [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.  
  
### <a name="remarks"></a>Comentários  
 Se `nBins` é 0, `CAtlMap` calcula um número razoável com base no número de elementos do mapa e a configuração de carga ideal. Normalmente o processo rehashing é automático, mas se [CAtlMap::DisableAutoRehash](#disableautorehash) foi chamado, esse método executará o redimensionamento necessário.  
  
##  <a name="removeall"></a>CAtlMap::RemoveAll  
 Chame esse método para remover todos os elementos do `CAtlMap` objeto.  
  
```
void RemoveAll() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Limpa o `CAtlMap` objeto, liberando a memória usada para armazenar os elementos.  
  
##  <a name="removeatpos"></a>CAtlMap::RemoveAtPos  
 Chame esse método para remover o elemento na posição especificada no `CAtlMap` objeto.  
  
```
void RemoveAtPos(POSITION pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
### <a name="remarks"></a>Comentários  
 Remove o par chave/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A posição é referenciado por `pos` se torna inválido e enquanto a posição de todos os outros elementos no mapa permanece válida, não necessariamente fazem reter a mesma ordem.  
  
##  <a name="removekey"></a>CAtlMap::RemoveKey  
 Chame esse método para remover um elemento de `CAtlMap` objeto, dado a chave.  
  
```
bool RemoveKey(KINARGTYPE key) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave correspondente para o par de elemento que você deseja remover.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a chave for encontrada e removida, **false** em caso de falha.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).  
  
##  <a name="setat"></a>CAtlMap::SetAt  
 Chame esse método para inserir um par de elemento no mapa.  
  
```
POSITION SetAt(
    KINARGTYPE key,
    VINARGTYPE value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 O valor da chave para adicionar ao `CAtlMap` objeto.  
  
 *value*  
 O valor a ser adicionado para o `CAtlMap` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a posição do par chave/valor de elemento no `CAtlMap` objeto.  
  
### <a name="remarks"></a>Comentários  
 `SetAt`substitui um elemento existente, se uma chave correspondente for encontrada. Se a chave não for encontrada, é criado um novo par chave/valor.  
  
##  <a name="setoptimalload"></a>CAtlMap::SetOptimalLoad  
 Chamar esse método para definir a carga ideal do `CAtlMap` objeto.  
  
```
void SetOptimalLoad(
    float fOptimalLoad,
    float fLoThreshold,
    float fHiThreshold,
    bool bRehashNow = false);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fOptimalLoad`  
 A taxa de carga ideal.  
  
 `fLoThreshold`  
 O limite inferior para a taxa de carga.  
  
 `fHiThreshold`  
 O limite superior para a taxa de carga.  
  
 `bRehashNow`  
 Sinalizador que indica se a tabela de hash deve ser recalculada.  
  
### <a name="remarks"></a>Comentários  
 Este método redefine o valor de carga ideal para o `CAtlMap` objeto. Consulte [CAtlMap::CAtlMap](#catlmap) para uma discussão sobre os vários parâmetros. Se `bRehashNow` for true e o número de elementos é fora os valores mínimo e máximo, a tabela de hash é recalculada.  
  
##  <a name="setvalueat"></a>CAtlMap::SetValueAt  
 Chame esse método para alterar o valor armazenado em uma determinada posição de `CAtlMap` objeto.  
  
```
void SetValueAt(
    POSITION pos,
    VINARGTYPE value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).  
  
 *value*  
 O valor a ser adicionado para o `CAtlMap` objeto.  
  
### <a name="remarks"></a>Comentários  
 Altera o elemento de valor armazenado na posição especificada no `CAtlMap` objeto.  
  
##  <a name="vinargtype"></a>CAtlMap::VINARGTYPE  
 Tipo usado quando um valor é passado como um argumento de entrada.  
  
```
typedef VTraits::INARGTYPE VINARGTYPE;
```  
  
##  <a name="voutargtype"></a>CAtlMap::VOUTARGTYPE  
 Tipo usado quando um valor é passado como um argumento de saída.  
  
```
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```  
  
##  <a name="m_key"></a>CAtlMap::CPair::m_key  
 O membro de dados armazenando um elemento-chave.  
  
```
const K m_key;
```    
  
### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo de elemento de chave.  
  
##  <a name="m_value"></a>CAtlMap::CPair::m_value  
 O membro de dados armazenando o elemento de valor.  
  
```
V  m_value;
```    
  
### <a name="parameters"></a>Parâmetros  
 *V*  
 O tipo de elemento de valor.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de letreiro](../../visual-cpp-samples.md)   
 [Exemplo de UpdatePV](../../visual-cpp-samples.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

