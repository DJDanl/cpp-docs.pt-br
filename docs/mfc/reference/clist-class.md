---
title: Classe CList | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CList
dev_langs:
- C++
helpviewer_keywords:
- lists
- lists, base class for
- CList class
ms.assetid: 6f6273c3-c8f6-47f5-ac2a-0a950379ae5d
caps.latest.revision: 23
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
ms.openlocfilehash: 05d35419f70ab039e6981938c516201b252878d4
ms.lasthandoff: 02/25/2017

---
# <a name="clist-class"></a>Classe CList
Suporta ordenados listas de objetos não exclusivos acessíveis em sequência ou por valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class TYPE, class ARG_TYPE = const TYPE&>  
class CList : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CList::CList](#clist)|Constrói uma lista ordenada vazia.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CList::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o topo da lista (faz um novo cabeçalho).|  
|[CList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) até o final da lista (faz uma nova final).|  
|[CList::Find](#find)|Obtém a posição de um elemento especificado pelo valor de ponteiro.|  
|[CList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|  
|[CList::GetAt](#getat)|Obtém o elemento na posição especificada.|  
|[CList::GetCount](#getcount)|Retorna o número de elementos nesta lista.|  
|[CList::GetHead](#gethead)|Retorna o elemento principal da lista (não pode ser vazio).|  
|[CList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento principal da lista.|  
|[CList::](#getnext)|Obtém o próximo elemento de iteração.|  
|[CList::GetPrev](#getprev)|Obtém o elemento anterior para iteração.|  
|[CList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|  
|[CList::GetTail](#gettail)|Retorna o elemento final da lista (não pode ser vazio).|  
|[CList::GetTailPosition](#gettailposition)|Retorna a posição do elemento final da lista.|  
|[CList::InsertAfter](#insertafter)|Insere um novo elemento após uma determinada posição.|  
|[CList::InsertBefore](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|  
|[CList::IsEmpty](#isempty)|Testa a condição da lista vazia (sem elementos).|  
|[CList::RemoveAll](#removeall)|Remove todos os elementos dessa lista.|  
|[CList::RemoveAt](#removeat)|Remove um elemento dessa lista, especificada pela posição.|  
|[CList::RemoveHead](#removehead)|Remove o elemento do cabeçalho da lista.|  
|[CList::RemoveTail](#removetail)|Remove o elemento final da lista.|  
|[CList::SetAt](#setat)|Define o elemento na posição especificada.|  
  
#### <a name="parameters"></a>Parâmetros  
 `TYPE`  
 Tipo de objeto armazenado na lista.  
  
 `ARG` *_* `TYPE`  
 Tipo usado para fazer referência a objetos armazenados na lista. Pode ser uma referência.  
  
## <a name="remarks"></a>Comentários  
 `CList`listas se comportam como listas duplamente vinculada.  
  
 Uma variável do tipo **posição** é uma chave para a lista. Você pode usar um **posição** variável como um iterador para percorrer uma lista sequencialmente e como um indicador para manter um lugar. Uma posição não é o mesmo que um índice, no entanto.  
  
 Inserção de elemento é muito rápida no início de lista, na parte final e em um conhecido **posição**. Uma pesquisa sequencial é necessária pesquisar um elemento por valor ou índice. Essa pesquisa pode ser lenta se a lista for longa.  
  
 Se você precisar de um despejo de elementos individuais na lista, você deve definir a profundidade do contexto do despejo como 1 ou maior.  
  
 Determinadas funções de membro dessa chamada de classe auxiliar global funções que devem ser personalizadas para a maioria dos usos do `CList` classe. Consulte [auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção "Variáveis globais e Macros".  
  
 Para obter mais informações sobre como usar o `CList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#35;](../../mfc/codesnippet/cpp/clist-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtempl.h  
  
##  <a name="a-nameaddheada--clistaddhead"></a><a name="addhead"></a>CList::AddHead  
 Adiciona um novo elemento ou lista de elementos ao cabeçalho da lista.  
  
```  
POSITION AddHead(ARG_TYPE newElement);  
void AddHead(CList* pNewList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `newElement`  
 O novo elemento.  
  
 `pNewList`  
 Um ponteiro para outro `CList` lista. Os elementos no `pNewList` serão adicionados a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a primeira versão do **posição** valor do elemento recém-inserido.  
  
### <a name="remarks"></a>Comentários  
 A lista pode estar vazia antes da operação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#36;](../../mfc/codesnippet/cpp/clist-class_2.cpp)]  
  
##  <a name="a-nameaddtaila--clistaddtail"></a><a name="addtail"></a>CList::AddTail  
 Adiciona um novo elemento ou lista de elementos até o final dessa lista.  
  
```  
POSITION AddTail(ARG_TYPE newElement);  
void AddTail(CList* pNewList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `newElement`  
 O elemento a ser adicionado a essa lista.  
  
 `pNewList`  
 Um ponteiro para outro `CList` lista. Os elementos no `pNewList` serão adicionados a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a primeira versão do **posição** valor do elemento recém-inserido.  
  
### <a name="remarks"></a>Comentários  
 A lista pode estar vazia antes da operação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#37;](../../mfc/codesnippet/cpp/clist-class_3.cpp)]  
  
##  <a name="a-nameclista--clistclist"></a><a name="clist"></a>CList::CList  
 Constrói uma lista ordenada vazia.  
  
```  
CList(INT_PTR nBlockSize = 10);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 A granularidade de alocação de memória para estender a lista.  
  
### <a name="remarks"></a>Comentários  
 Como a lista aumenta, a memória é alocada em unidades de `nBlockSize` entradas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&38;](../../mfc/codesnippet/cpp/clist-class_4.cpp)]  
  
##  <a name="a-namefinda--clistfind"></a><a name="find"></a>CList::Find  
 Pesquisa a lista sequencialmente para encontrar o primeiro elemento correspondente especificado `searchValue`.  
  
```  
POSITION Find(
    ARG_TYPE searchValue,  
    POSITION startAfter = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `searchValue`  
 O valor a ser encontrado na lista.  
  
 `startAfter`  
 A posição inicial da pesquisa. Se nenhum valor for especificado, a pesquisa começa com o elemento principal.  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se o objeto não foi encontrado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#39;](../../mfc/codesnippet/cpp/clist-class_5.cpp)]  
  
##  <a name="a-namefindindexa--clistfindindex"></a><a name="findindex"></a>CList::FindIndex  
 Usa o valor de `nIndex` como um índice na lista.  
  
```  
POSITION FindIndex(INT_PTR nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice baseado em zero do elemento de lista a ser localizado.  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se `nIndex` for negativo ou muito grande.  
  
### <a name="remarks"></a>Comentários  
 Iniciar uma verificação sequencial do início da lista, parando o *n*º elemento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_6.cpp)]  
  
##  <a name="a-namegetata--clistgetat"></a><a name="getat"></a>CList::GetAt  
 Obtém o elemento da lista na posição especificada.  
  
```  
TYPE& GetAt(POSITION position);  
const TYPE& GetAt(POSITION position) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo de objeto na lista.  
  
 *posição*  
 A posição na lista do elemento a ser obtido.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte a descrição do valor de retorno para `GetHead`.  
  
### <a name="remarks"></a>Comentários  
 `GetAt`Retorna o elemento (ou uma referência ao elemento) associada a uma determinada posição. Não é o mesmo que um índice, e você não pode operar em um **posição** valor por conta própria. Uma variável do tipo **posição** é uma chave para a lista.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se for inválido, a versão de depuração da Microsoft Foundation Class Library declara.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CList::GetHeadPosition](#getheadposition).  
  
##  <a name="a-namegetcounta--clistgetcount"></a><a name="getcount"></a>CList::GetCount  
 Obtém o número de elementos nesta lista.  
  
```  
INT_PTR GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que contém a contagem do elemento.  
  
### <a name="remarks"></a>Comentários  
 Chamar esse método gerará o mesmo resultado que o [CList::GetSize](#getsize) método.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CList::RemoveHead](#removehead).  
  
##  <a name="a-namegetheada--clistgethead"></a><a name="gethead"></a>CList::GetHead  
 Obtém o elemento principal (ou uma referência ao elemento head) desta lista.  
  
```  
const TYPE& GetHead() const;  
  
TYPE& GetHead();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo de objeto na lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista for **const**, `GetHead` retorna uma cópia do elemento no topo da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.  
  
 Se a lista não é **const**, `GetHead` retorna uma referência ao elemento no topo da lista. Isso permite que a função a ser usada em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `GetHead`. Se a lista estiver vazia, a versão de depuração da Microsoft Foundation Class Library declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[41 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_7.cpp)]  
  
##  <a name="a-namegetheadpositiona--clistgetheadposition"></a><a name="getheadposition"></a>CList::GetHeadPosition  
 Obtém a posição do elemento principal desta lista.  
  
```  
POSITION GetHeadPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se a lista está vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&42;](../../mfc/codesnippet/cpp/clist-class_8.cpp)]  
  
##  <a name="a-namegetnexta--clistgetnext"></a><a name="getnext"></a>CList::  
 Obtém o elemento de lista identificado por `rPosition`, em seguida, define `rPosition` para o **posição** valor da próxima entrada na lista.  
  
```  
TYPE& GetNext(POSITION& rPosition);  
const TYPE& GetNext(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
 `rPosition`  
 Uma referência a um **posição** valor retornado por uma anterior `GetNext`, [GetHeadPosition](#getheadposition), ou outra chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista for **const**, `GetNext` retorna uma cópia de um elemento da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.  
  
 Se a lista não é **const**, `GetNext` retorna uma referência a um elemento da lista. Isso permite que a função a ser usada em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetNext` em um loop de iteração direta se estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou **localizar**.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se for inválido, a versão de depuração da Microsoft Foundation Class Library declara.  
  
 Se o elemento recuperado é o último da lista, em seguida, o novo valor de `rPosition` é definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#43;](../../mfc/codesnippet/cpp/clist-class_9.cpp)]  
  
##  <a name="a-namegetpreva--clistgetprev"></a><a name="getprev"></a>CList::GetPrev  
 Obtém o elemento de lista identificado por `rPosition`, em seguida, define `rPosition` para o **posição** valor da entrada anterior na lista.  
  
```  
TYPE& GetPrev(POSITION& rPosition);  
const TYPE& GetPrev(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
 `rPosition`  
 Uma referência a um **posição** valor retornado por uma anterior `GetPrev` ou outra chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista for **const**, `GetPrev` retorna uma cópia do elemento no topo da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.  
  
 Se a lista não é **const**, `GetPrev` retorna uma referência a um elemento da lista. Isso permite que a função a ser usada em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetPrev` em um loop de iteração inversa se estabelecer a posição inicial com uma chamada para `GetTailPosition` ou **localizar**.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se for inválido, a versão de depuração da Microsoft Foundation Class Library declara.  
  
 Se o elemento recuperado for o primeiro na lista, em seguida, o novo valor de `rPosition` é definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#44;](../../mfc/codesnippet/cpp/clist-class_10.cpp)]  
  
##  <a name="a-namegetsizea--clistgetsize"></a><a name="getsize"></a>CList::GetSize  
 Retorna o número de elementos da lista.  
  
```  
INT_PTR GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na lista.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número de elementos na lista.  Chamar esse método gerará o mesmo resultado que o [CList::GetCount](#getcount) método.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[45 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_11.cpp)]  
  
##  <a name="a-namegettaila--clistgettail"></a><a name="gettail"></a>CList::GetTail  
 Obtém o `CObject` ponteiro que representa o elemento final dessa lista.  
  
```  
TYPE& GetTail();  
const TYPE& GetTail() const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte a descrição do valor de retorno para [GetHead](../../mfc/reference/coblist-class.md#gethead).  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `GetTail`. Se a lista estiver vazia, a versão de depuração da Microsoft Foundation Class Library declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[46 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_12.cpp)]  
  
##  <a name="a-namegettailpositiona--clistgettailposition"></a><a name="gettailposition"></a>CList::GetTailPosition  
 Obtém a posição do elemento final dessa lista; **Nulo** se a lista está vazia.  
  
```  
POSITION GetTailPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se a lista está vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[47 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_13.cpp)]  
  
##  <a name="a-nameinsertaftera--clistinsertafter"></a><a name="insertafter"></a>CList::InsertAfter  
 Adiciona um elemento a essa lista depois do elemento na posição especificada.  
  
```  
POSITION InsertAfter(POSITION position, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 *posição*  
 A **posição** valor retornado por uma anterior `GetNext`, `GetPrev`, ou **localizar** chamada de função de membro.  
  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista.  
  
 `newElement`  
 O elemento a ser adicionado a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para recuperação de elemento de iteração ou lista.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[48 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_14.cpp)]  
  
##  <a name="a-nameinsertbeforea--clistinsertbefore"></a><a name="insertbefore"></a>CList::InsertBefore  
 Adiciona um elemento a esta lista antes do elemento na posição especificada.  
  
```  
POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 *posição*  
 A **posição** valor retornado por uma anterior `GetNext`, `GetPrev`, ou **localizar** chamada de função de membro.  
  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `newElement`  
 O elemento a ser adicionado a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para recuperação de elemento de iteração ou lista.  
  
### <a name="remarks"></a>Comentários  
 Se *posição* é **nulo**, o elemento é inserido no topo da lista.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[49 NVC_MFCCollections](../../mfc/codesnippet/cpp/clist-class_15.cpp)]  
  
##  <a name="a-nameisemptya--clistisempty"></a><a name="isempty"></a>CList::IsEmpty  
 Indica se essa lista não contém elementos.  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a lista estiver vazia; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#50;](../../mfc/codesnippet/cpp/clist-class_16.cpp)]  
  
##  <a name="a-nameremovealla--clistremoveall"></a><a name="removeall"></a>CList::RemoveAll  
 Remove todos os elementos da lista e libera a memória associada.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Nenhum erro será gerado se a lista já está vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#51;](../../mfc/codesnippet/cpp/clist-class_17.cpp)]  
  
##  <a name="a-nameremoveata--clistremoveat"></a><a name="removeat"></a>CList::RemoveAt  
 Remove o elemento especificado da lista.  
  
```  
void RemoveAt(POSITION position);
```  
  
### <a name="parameters"></a>Parâmetros  
 *posição*  
 A posição do elemento a ser removido da lista.  
  
### <a name="remarks"></a>Comentários  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se for inválido, a versão de depuração da Microsoft Foundation Class Library declara.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#52;](../../mfc/codesnippet/cpp/clist-class_18.cpp)]  
  
##  <a name="a-nameremoveheada--clistremovehead"></a><a name="removehead"></a>CList::RemoveHead  
 Remove o elemento do cabeçalho da lista e retorna um ponteiro para ele.  
  
```  
TYPE RemoveHead();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento anteriormente no topo da lista.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `RemoveHead`. Se a lista estiver vazia, a versão de depuração da Microsoft Foundation Class Library declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#53;](../../mfc/codesnippet/cpp/clist-class_19.cpp)]  
  
##  <a name="a-nameremovetaila--clistremovetail"></a><a name="removetail"></a>CList::RemoveTail  
 Remove o elemento do final da lista e retorna um ponteiro para ele.  
  
```  
TYPE RemoveTail();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento que estava no final da lista.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `RemoveTail`. Se a lista estiver vazia, a versão de depuração da Microsoft Foundation Class Library declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#54;](../../mfc/codesnippet/cpp/clist-class_20.cpp)]  
  
##  <a name="a-namesetata--clistsetat"></a><a name="setat"></a>CList::SetAt  
 Uma variável do tipo **posição** é uma chave para a lista.  
  
```  
void SetAt(POSITION pos, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O **posição** do elemento a ser definido.  
  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `newElement`  
 O elemento a ser adicionado à lista.  
  
### <a name="remarks"></a>Comentários  
 Não é o mesmo que um índice, e você não pode operar em um **posição** valor por conta própria. `SetAt`grava o elemento na posição especificada na lista.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se for inválido, a versão de depuração da Microsoft Foundation Class Library declara.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections&#55;](../../mfc/codesnippet/cpp/clist-class_21.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CMap](../../mfc/reference/cmap-class.md)   
 [Classe CArray](../../mfc/reference/carray-class.md)

