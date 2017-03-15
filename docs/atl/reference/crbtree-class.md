---
title: Classe CRBTree | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CRBTree
- CRBTree
- ATL::CRBTree
dev_langs:
- C++
helpviewer_keywords:
- CRBTree class
ms.assetid: a1b1cb63-38e4-4fc2-bb28-f774d1721760
caps.latest.revision: 18
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 7dec5cc56d28c4574f923fe2cbb952b628e2689f
ms.lasthandoff: 02/25/2017

---
# <a name="crbtree-class"></a>Classe CRBTree
Essa classe fornece métodos para criar e utilizar uma árvore vermelho / preto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename K,
          typename V, 
          class KTraits = CElementTraits<K>, 
          class VTraits = CElementTraits<V>> 
class CRBTree
```  
  
#### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo de elemento de chave.  
  
 *V*  
 O tipo de elemento de valor.  
  
 `KTraits`  
 O código usado para copiar ou mover elementos-chave. Consulte [CElementTraits classe](../../atl/reference/celementtraits-class.md) para obter mais detalhes.  
  
 `VTraits`  
 O código usado para copiar ou mover elementos de valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRBTree::KINARGTYPE](#kinargtype)|Tipo usado quando uma chave é passada como um argumento de entrada.|  
|[CRBTree::KOUTARGTYPE](#koutargtype)|Tipo usado quando uma chave é retornada como um argumento de saída.|  
|[CRBTree::VINARGTYPE](#vinargtype)|Tipo usado quando um valor é passado como um argumento de entrada.|  
|[CRBTree::VOUTARGTYPE](#voutargtype)|Tipo usado quando um valor é passado como um argumento de saída.|  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe CRBTree::CPair](#cpair_class)|Uma classe que contém os elementos de chave e valor.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRBTree:: ~ CRBTree](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRBTree::FindFirstKeyAfter](#findfirstkeyafter)|Chame esse método para localizar a posição do elemento que usa a próxima chave disponível.|  
|[CRBTree::GetAt](#getat)|Chame esse método para obter o elemento na posição especificada na árvore.|  
|[CRBTree::GetCount](#getcount)|Chame esse método para obter o número de elementos na árvore.|  
|[CRBTree::GetHeadPosition](#getheadposition)|Chame esse método para obter o valor da posição do elemento no topo da árvore.|  
|[CRBTree::GetKeyAt](#getkeyat)|Chame esse método para obter a chave de uma determinada posição na árvore.|  
|[CRBTree::GetNext](#getnext)|Chame esse método para obter um ponteiro para um elemento armazenado na `CRBTree` de objeto e avance a posição para o próximo elemento.|  
|[CRBTree::GetNextAssoc](#getnextassoc)|Chame esse método para obter a chave e o valor de um elemento armazenado no mapa e avance a posição para o próximo elemento.|  
|[CRBTree::GetNextKey](#getnextkey)|Chame esse método para obter a chave de um elemento armazenado na árvore e avance a posição para o próximo elemento.|  
|[CRBTree::GetNextValue](#getnextvalue)|Chame esse método para obter o valor de um elemento armazenado na árvore e avance a posição para o próximo elemento.|  
|[CRBTree::GetPrev](#getprev)|Chame esse método para obter um ponteiro para um elemento armazenado na `CRBTree` de objeto e, em seguida, atualize a posição para o elemento anterior.|  
|[CRBTree::GetTailPosition](#gettailposition)|Chame esse método para obter o valor da posição do elemento ao final da árvore.|  
|[CRBTree::GetValueAt](#getvalueat)|Chame esse método para recuperar o valor armazenado em uma determinada posição de `CRBTree` objeto.|  
|[CRBTree::IsEmpty](#isempty)|Chame esse método para testar um objeto vazio de árvore.|  
|[CRBTree::RemoveAll](#removeall)|Chame esse método para remover todos os elementos do **CRBTree** objeto.|  
|[CRBTree::RemoveAt](#removeat)|Chame esse método para remover o elemento na posição especificada no **CRBTree** objeto.|  
|[CRBTree::SetValueAt](#setvalueat)|Chame esse método para alterar o valor armazenado em uma determinada posição de `CRBTree` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma árvore vermelho / preto é uma árvore de pesquisa binária que usa um arquivo extra bit de informações por nó para assegurar que ele permaneça "equilibrado", que é, a altura da árvore não ficar desproporcionalmente grande e afetar o desempenho.  
  
 Essa classe de modelo foi projetada para ser usado por [CRBMap](../../atl/reference/crbmap-class.md) e [CRBMultiMap](../../atl/reference/crbmultimap-class.md). A maior parte dos métodos que compõem essas classes derivadas são fornecidas por `CRBTree`.  
  
 Para obter uma discussão mais completa de várias classes de coleção e seus recursos e características de desempenho, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="a-namecpairclassa--crbtreecpair-class"></a><a name="cpair_class"></a>Classe CRBTree::CPair  
 Uma classe que contém os elementos de chave e valor.  
  
```
class CPair : public __POSITION
```  
  
### <a name="remarks"></a>Comentários  
 Essa classe é usada pelos métodos [CRBTree::GetAt](#getat), [CRBTree::GetNext](#getnext), e [CRBTree::GetPrev](#getprev) para acessar os elementos de chave e o valor armazenados na estrutura de árvore.  
  
 Os membros são os seguintes:  
  
|||  
|-|-|  
|`m_key`|O membro de dados armazenando um elemento-chave.|  
|`m_value`|O membro de dados armazenando o elemento de valor.|  
  
##  <a name="a-namedtora--crbtreecrbtree"></a><a name="dtor"></a>CRBTree:: ~ CRBTree  
 O destruidor.  
  
```
~CRBTree() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados. Chamadas [CRBTree::RemoveAll](#removeall) para excluir todos os elementos.  
  
##  <a name="a-namefindfirstkeyaftera--crbtreefindfirstkeyafter"></a><a name="findfirstkeyafter"></a>CRBTree::FindFirstKeyAfter  
 Chame esse método para localizar a posição do elemento que usa a próxima chave disponível.  
  
```
POSITION FindFirstKeyAfter(KINARGTYPE key) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 Um valor de chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da posição do elemento que usa a próxima chave disponível. Se não houver nenhum elemento mais, NULL será retornado.  
  
### <a name="remarks"></a>Comentários  
 Esse método torna fácil percorrer a árvore sem precisar calcular valores de posição com antecedência.  
  
##  <a name="a-namegetata--crbtreegetat"></a><a name="getat"></a>CRBTree::GetAt  
 Chame esse método para obter o elemento na posição especificada na árvore.  
  
```
CPair* GetAt(POSITION pos) throw();
const CPair* GetAt(POSITION pos) const throw();
void GetAt(POSITION pos, KOUTARGTYPE key, VOUTARGTYPE value) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O valor da posição.  
  
 `key`  
 A variável que recebe a chave.  
  
 *value*  
 A variável que recebe o valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Os primeiros dois formulários retornam um ponteiro para um [CPair](#cpair_class). O terceiro formulário obtém uma chave e um valor para a posição especificada.  
  
### <a name="remarks"></a>Comentários  
 O valor da posição pode ser previamente determinado com uma chamada para um método como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::GetTailPosition](#gettailposition).  
  
 Em compilações de depuração, uma falha de asserção ocorrerá se `pos` é igual a nulo.  
  
##  <a name="a-namegetcounta--crbtreegetcount"></a><a name="getcount"></a>CRBTree::GetCount  
 Chame esse método para obter o número de elementos na árvore.  
  
```
size_t GetCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos (cada par chave/valor é um elemento) armazenados na árvore.  
  
##  <a name="a-namegetheadpositiona--crbtreegetheadposition"></a><a name="getheadposition"></a>CRBTree::GetHeadPosition  
 Chame esse método para obter o valor da posição do elemento no topo da árvore.  
  
```
POSITION GetHeadPosition() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da posição do elemento no topo da árvore.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado por `GetHeadPosition` pode ser usado com métodos como [CRBTree::GetKeyAt](#getkeyat) ou [CRBTree::GetNext](#getnext) para percorrer a árvore e recuperar valores.  
  
##  <a name="a-namegetkeyata--crbtreegetkeyat"></a><a name="getkeyat"></a>CRBTree::GetKeyAt  
 Chame esse método para obter a chave de uma determinada posição na árvore.  
  
```
const K& GetKeyAt(POSITION pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O valor da posição.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a chave armazenada na posição `pos` na árvore.  
  
### <a name="remarks"></a>Comentários  
 Se `pos` não é um valor válido de posição, resultados serão imprevisíveis. Em compilações de depuração, uma falha de asserção ocorrerá se `pos` é igual a nulo.  
  
##  <a name="a-namegetnexta--crbtreegetnext"></a><a name="getnext"></a>CRBTree::GetNext  
 Chame esse método para obter um ponteiro para um elemento armazenado na `CRBTree` de objeto e avance a posição para o próximo elemento.  
  
```
const CPair* GetNext(POSITION& pos) const throw();
CPair* GetNext(POSITION& pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o próximo [CPair](#cpair_class) valor na árvore.  
  
### <a name="remarks"></a>Comentários  
 O `pos` posição é atualizado após cada chamada. Se o elemento recuperado é o último na árvore de `pos` é definido como NULL.  
  
##  <a name="a-namegetnextassoca--crbtreegetnextassoc"></a><a name="getnextassoc"></a>CRBTree::GetNextAssoc  
 Chame esse método para obter a chave e o valor de um elemento armazenado no mapa e avance a posição para o próximo elemento.  
  
```
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
 `key`  
 Parâmetro de modelo especificando o tipo de chave da árvore.  
  
 *value*  
 Parâmetro de modelo especificando o tipo de valor da árvore.  
  
### <a name="remarks"></a>Comentários  
 O `pos` posição é atualizado após cada chamada. Se o elemento recuperado é o último na árvore de `pos` é definido como NULL.  
  
##  <a name="a-namegetnextkeya--crbtreegetnextkey"></a><a name="getnextkey"></a>CRBTree::GetNextKey  
 Chame esse método para obter a chave de um elemento armazenado na árvore e avance a posição para o próximo elemento.  
  
```
const K& GetNextKey(POSITION& pos) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a próxima chave na árvore.  
  
### <a name="remarks"></a>Comentários  
 Atualiza o contador de posição atual, `pos`. Se não existem mais entradas na árvore, o contador de posição é definido como NULL.  
  
##  <a name="a-namegetnextvaluea--crbtreegetnextvalue"></a><a name="getnextvalue"></a>CRBTree::GetNextValue  
 Chame esse método para obter o valor de um elemento armazenado na árvore e avance a posição para o próximo elemento.  
  
```
const V& GetNextValue(POSITION& pos) const throw();
V& GetNextValue(POSITION& pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o valor mais próximo na árvore.  
  
### <a name="remarks"></a>Comentários  
 Atualiza o contador de posição atual, `pos`. Se não existem mais entradas na árvore, o contador de posição é definido como NULL.  
  
##  <a name="a-namegetpreva--crbtreegetprev"></a><a name="getprev"></a>CRBTree::GetPrev  
 Chame esse método para obter um ponteiro para um elemento armazenado na `CRBTree` de objeto e, em seguida, atualize a posição para o elemento anterior.  
  
```
const CPair* GetPrev(POSITION& pos) const throw();
CPair* GetPrev(POSITION& pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a versão anterior [CPair](#cpair_class) valor armazenado na árvore.  
  
### <a name="remarks"></a>Comentários  
 Atualiza o contador de posição atual, `pos`. Se não existem mais entradas na árvore, o contador de posição é definido como NULL.  
  
##  <a name="a-namegettailpositiona--crbtreegettailposition"></a><a name="gettailposition"></a>CRBTree::GetTailPosition  
 Chame esse método para obter o valor da posição do elemento ao final da árvore.  
  
```
POSITION GetTailPosition() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da posição do elemento ao final da árvore.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado por `GetTailPosition` pode ser usado com métodos como [CRBTree::GetKeyAt](#getkeyat) ou [CRBTree::GetPrev](#getprev) para percorrer a árvore e recuperar valores.  
  
##  <a name="a-namegetvalueata--crbtreegetvalueat"></a><a name="getvalueat"></a>CRBTree::GetValueAt  
 Chame esse método para recuperar o valor armazenado em uma determinada posição de `CRBTree` objeto.  
  
```
const V& GetValueAt(POSITION pos) const throw();
V& GetValueAt(POSITION pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o valor armazenado na posição especificada no `CRBTree` objeto.  
  
##  <a name="a-nameisemptya--crbtreeisempty"></a><a name="isempty"></a>CRBTree::IsEmpty  
 Chame esse método para testar um objeto vazio de árvore.  
  
```
bool IsEmpty() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se a árvore estiver vazia, **false** caso contrário.  
  
##  <a name="a-namekinargtypea--crbtreekinargtype"></a><a name="kinargtype"></a>CRBTree::KINARGTYPE  
 Tipo usado quando uma chave é passada como um argumento de entrada.  
  
```
typedef KTraits::INARGTYPE KINARGTYPE;
```  
  
##  <a name="a-namekoutargtypea--crbtreekoutargtype"></a><a name="koutargtype"></a>CRBTree::KOUTARGTYPE  
 Tipo usado quando uma chave é retornada como um argumento de saída.  
  
```
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```  
  
##  <a name="a-nameremovealla--crbtreeremoveall"></a><a name="removeall"></a>CRBTree::RemoveAll  
 Chame esse método para remover todos os elementos do `CRBTree` objeto.  
  
```
void RemoveAll() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Limpa o `CRBTree` objeto, liberando a memória usada para armazenar os elementos.  
  
##  <a name="a-nameremoveata--crbtreeremoveat"></a><a name="removeat"></a>CRBTree::RemoveAt  
 Chame esse método para remover o elemento na posição especificada no **CRBTree** objeto.  
  
```
void RemoveAt(POSITION pos) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
### <a name="remarks"></a>Comentários  
 Remove o par chave/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A posição é referenciado por `pos` se torna inválido e enquanto a posição de todos os outros elementos da árvore permanece válida, não necessariamente fazem reter a mesma ordem.  
  
##  <a name="a-namesetvalueata--crbtreesetvalueat"></a><a name="setvalueat"></a>CRBTree::SetValueAt  
 Chame esse método para alterar o valor armazenado em uma determinada posição de `CRBTree` objeto.  
  
```
void SetValueAt(POSITION pos, VINARGTYPE value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O contador de posição, retornado por uma chamada anterior a métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).  
  
 *value*  
 O valor a ser adicionado para o `CRBTree` objeto.  
  
### <a name="remarks"></a>Comentários  
 Altera o elemento de valor armazenado na posição especificada no `CRBTree` objeto.  
  
##  <a name="a-namevinargtypea--crbtreevinargtype"></a><a name="vinargtype"></a>CRBTree::VINARGTYPE  
 Tipo usado quando um valor é passado como um argumento de entrada.  
  
```
typedef VTraits::INARGTYPE VINARGTYPE;
```  
  
##  <a name="a-namevoutargtypea--crbtreevoutargtype"></a><a name="voutargtype"></a>CRBTree::VOUTARGTYPE  
 Tipo usado quando um valor é passado como um argumento de saída.  
  
```
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

