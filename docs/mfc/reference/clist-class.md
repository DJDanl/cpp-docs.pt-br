---
title: Classe CList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CList
- AFXTEMPL/CList
- AFXTEMPL/CList::CList
- AFXTEMPL/CList::AddHead
- AFXTEMPL/CList::AddTail
- AFXTEMPL/CList::Find
- AFXTEMPL/CList::FindIndex
- AFXTEMPL/CList::GetAt
- AFXTEMPL/CList::GetCount
- AFXTEMPL/CList::GetHead
- AFXTEMPL/CList::GetHeadPosition
- AFXTEMPL/CList::GetNext
- AFXTEMPL/CList::GetPrev
- AFXTEMPL/CList::GetSize
- AFXTEMPL/CList::GetTail
- AFXTEMPL/CList::GetTailPosition
- AFXTEMPL/CList::InsertAfter
- AFXTEMPL/CList::InsertBefore
- AFXTEMPL/CList::IsEmpty
- AFXTEMPL/CList::RemoveAll
- AFXTEMPL/CList::RemoveAt
- AFXTEMPL/CList::RemoveHead
- AFXTEMPL/CList::RemoveTail
- AFXTEMPL/CList::SetAt
dev_langs:
- C++
helpviewer_keywords:
- CList [MFC], CList
- CList [MFC], AddHead
- CList [MFC], AddTail
- CList [MFC], Find
- CList [MFC], FindIndex
- CList [MFC], GetAt
- CList [MFC], GetCount
- CList [MFC], GetHead
- CList [MFC], GetHeadPosition
- CList [MFC], GetNext
- CList [MFC], GetPrev
- CList [MFC], GetSize
- CList [MFC], GetTail
- CList [MFC], GetTailPosition
- CList [MFC], InsertAfter
- CList [MFC], InsertBefore
- CList [MFC], IsEmpty
- CList [MFC], RemoveAll
- CList [MFC], RemoveAt
- CList [MFC], RemoveHead
- CList [MFC], RemoveTail
- CList [MFC], SetAt
ms.assetid: 6f6273c3-c8f6-47f5-ac2a-0a950379ae5d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b2a84e73c165efd8f2f17e66af149e33d90395e8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33372515"
---
# <a name="clist-class"></a>Classe CList
Dá suporte a ordenados listas de objetos não exclusivos acessíveis em sequência ou por valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class TYPE, class ARG_TYPE = const TYPE&>  
class CList : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CList::CList](#clist)|Constrói uma lista ordenada vazia.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CList::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o início da lista (faz um novo cabeçalho).|  
|[CList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) para o fim da lista (faz uma novo final).|  
|[CList::Find](#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|  
|[CList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice com base em zero.|  
|[CList::GetAt](#getat)|Obtém o elemento na posição especificada.|  
|[CList::GetCount](#getcount)|Retorna o número de elementos nesta lista.|  
|[CList::GetHead](#gethead)|Retorna o elemento principal da lista (não pode estar vazio).|  
|[CList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento principal da lista.|  
|[CList::](#getnext)|Obtém o próximo elemento de iteração.|  
|[CList::GetPrev](#getprev)|Obtém o elemento anterior para iteração.|  
|[CList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|  
|[CList::GetTail](#gettail)|Retorna o elemento final da lista (não pode estar vazio).|  
|[CList::GetTailPosition](#gettailposition)|Retorna a posição do elemento da parte final da lista.|  
|[CList::InsertAfter](#insertafter)|Insere um novo elemento após uma posição determinada.|  
|[CList::InsertBefore](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|  
|[CList::IsEmpty](#isempty)|Testes para a condição de lista vazia (sem elementos).|  
|[CList::RemoveAll](#removeall)|Remove todos os elementos da lista.|  
|[CList::RemoveAt](#removeat)|Remove um elemento nesta lista, especificada pela posição.|  
|[CList::RemoveHead](#removehead)|Remove o elemento do cabeçalho da lista.|  
|[CList::RemoveTail](#removetail)|Remove o elemento do final da lista.|  
|[CList::SetAt](#setat)|Define o elemento na posição especificada.|  
  
#### <a name="parameters"></a>Parâmetros  
 `TYPE`  
 Tipo de objeto armazenado na lista.  
  
 `ARG` *_* `TYPE`  
 Tipo usado para fazer referência a objetos armazenados na lista. Pode ser uma referência.  
  
## <a name="remarks"></a>Comentários  
 `CList` listas se comportam como listas duplamente vinculada.  
  
 Uma variável do tipo **posição** é uma chave para a lista. Você pode usar um **posição** variável como um iterador para percorrer uma lista em sequência e como um indicador para manter um lugar. Uma posição porém não é o mesmo que um índice.  
  
 Inserção de elemento é muito rápido no topo lista, ao final e em um conhecido **posição**. Uma pesquisa sequencial é necessária procurar um elemento por valor ou índice. A pesquisa pode ser lenta se a lista for longa.  
  
 Se você precisar de um despejo de elementos individuais na lista, você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
 Determinadas funções de membro dessa chamada de classe auxiliar global funções que devem ser personalizadas para a maioria dos usos do `CList` classe. Consulte [auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção "Macros e globais".  
  
 Para obter mais informações sobre como usar `CList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#35](../../mfc/codesnippet/cpp/clist-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtempl.h  
  
##  <a name="addhead"></a>  CList::AddHead  
 Adiciona um novo elemento ou a lista de elementos para o início da lista.  
  
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
 Um ponteiro para outro `CList` lista. Os elementos no `pNewList` será adicionado a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a primeira versão do **posição** valor do elemento recentemente inserido.  
  
### <a name="remarks"></a>Comentários  
 A lista pode estar vazia antes da operação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#36](../../mfc/codesnippet/cpp/clist-class_2.cpp)]  
  
##  <a name="addtail"></a>  CList::AddTail  
 Adiciona um novo elemento ou a lista de elementos para o fim desta lista.  
  
```  
POSITION AddTail(ARG_TYPE newElement);  
void AddTail(CList* pNewList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `newElement`  
 O elemento a ser adicionada à lista.  
  
 `pNewList`  
 Um ponteiro para outro `CList` lista. Os elementos no `pNewList` será adicionado a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a primeira versão do **posição** valor do elemento recentemente inserido.  
  
### <a name="remarks"></a>Comentários  
 A lista pode estar vazia antes da operação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#37](../../mfc/codesnippet/cpp/clist-class_3.cpp)]  
  
##  <a name="clist"></a>  CList::CList  
 Constrói uma lista ordenada vazia.  
  
```  
CList(INT_PTR nBlockSize = 10);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 A granularidade de alocação de memória para estender a lista.  
  
### <a name="remarks"></a>Comentários  
 À medida que aumenta a lista, a memória é alocada em unidades de `nBlockSize` entradas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#38](../../mfc/codesnippet/cpp/clist-class_4.cpp)]  
  
##  <a name="find"></a>  CList::Find  
 Pesquisa a lista em sequência para localizar o primeiro elemento de correspondência especificado `searchValue`.  
  
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
 A posição inicial da pesquisa. Se nenhum valor for especificado, a pesquisa começa com o elemento head.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se o objeto não foi encontrado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#39](../../mfc/codesnippet/cpp/clist-class_5.cpp)]  
  
##  <a name="findindex"></a>  CList::FindIndex  
 Usa o valor de `nIndex` como um índice na lista.  
  
```  
POSITION FindIndex(INT_PTR nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice de base zero do elemento de lista a ser localizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se `nIndex` for negativo ou muito grande.  
  
### <a name="remarks"></a>Comentários  
 Iniciar uma verificação sequencial do início da lista, parando o *n*elemento th.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#40](../../mfc/codesnippet/cpp/clist-class_6.cpp)]  
  
##  <a name="getat"></a>  CList::GetAt  
 Obtém o elemento de lista na posição especificada.  
  
```  
TYPE& GetAt(POSITION position);  
const TYPE& GetAt(POSITION position) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo de objeto na lista de parâmetro de modelo.  
  
 *Posição*  
 A posição na lista do elemento a ser obtido.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte a descrição do valor de retorno de `GetHead`.  
  
### <a name="remarks"></a>Comentários  
 `GetAt` Retorna o elemento (ou uma referência ao elemento) associada à posição especificada. Não é o mesmo que um índice, e você não pode operar em um **posição** valor por conta própria. Uma variável do tipo **posição** é uma chave para a lista.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CList::GetHeadPosition](#getheadposition).  
  
##  <a name="getcount"></a>  CList::GetCount  
 Obtém o número de elementos nesta lista.  
  
```  
INT_PTR GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que contém a contagem de elementos.  
  
### <a name="remarks"></a>Comentários  
 Chamar esse método gerará o mesmo resultado que o [CList::GetSize](#getsize) método.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CList::RemoveHead](#removehead).  
  
##  <a name="gethead"></a>  CList::GetHead  
 Obtém o elemento head (ou uma referência para o elemento head) desta lista.  
  
```  
const TYPE& GetHead() const;  
  
TYPE& GetHead();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo de objeto na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista estiver **const**, `GetHead` retorna uma cópia do elemento no início da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.  
  
 Se a lista não é **const**, `GetHead` retorna uma referência ao elemento no início da lista. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `GetHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#41](../../mfc/codesnippet/cpp/clist-class_7.cpp)]  
  
##  <a name="getheadposition"></a>  CList::GetHeadPosition  
 Obtém a posição do elemento principal desta lista.  
  
```  
POSITION GetHeadPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se a lista está vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#42](../../mfc/codesnippet/cpp/clist-class_8.cpp)]  
  
##  <a name="getnext"></a>  CList::  
 Obtém o elemento de lista, identificado pelo `rPosition`, em seguida, define `rPosition` para o **posição** valor da próxima entrada na lista.  
  
```  
TYPE& GetNext(POSITION& rPosition);  
const TYPE& GetNext(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
 `rPosition`  
 Uma referência a um **posição** valor retornado pelo anterior `GetNext`, [GetHeadPosition](#getheadposition), ou outra chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista estiver **const**, `GetNext` retorna uma cópia de um elemento da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.  
  
 Se a lista não é **const**, `GetNext` retorna uma referência a um elemento da lista. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetNext` em um loop de interação direta se estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou **localizar**.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Se o elemento recuperado é o último na lista, em seguida, o novo valor de `rPosition` é definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#43](../../mfc/codesnippet/cpp/clist-class_9.cpp)]  
  
##  <a name="getprev"></a>  CList::GetPrev  
 Obtém o elemento de lista, identificado pelo `rPosition`, em seguida, define `rPosition` para o **posição** valor da entrada anterior na lista.  
  
```  
TYPE& GetPrev(POSITION& rPosition);  
const TYPE& GetPrev(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Parâmetro de modelo especificando o tipo dos elementos na lista.  
  
 `rPosition`  
 Uma referência a um **posição** valor retornado pelo anterior `GetPrev` ou outra chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista estiver **const**, `GetPrev` retorna uma cópia do elemento no início da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.  
  
 Se a lista não é **const**, `GetPrev` retorna uma referência a um elemento da lista. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetPrev` em um loop de iteração inversa se estabelecer a posição inicial com uma chamada para `GetTailPosition` ou **localizar**.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Se o elemento recuperado é o primeiro na lista, em seguida, o novo valor de `rPosition` é definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#44](../../mfc/codesnippet/cpp/clist-class_10.cpp)]  
  
##  <a name="getsize"></a>  CList::GetSize  
 Retorna o número de elementos da lista.  
  
```  
INT_PTR GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na lista.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número de elementos na lista.  Chamar esse método gerará o mesmo resultado que o [CList::GetCount](#getcount) método.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#45](../../mfc/codesnippet/cpp/clist-class_11.cpp)]  
  
##  <a name="gettail"></a>  CList::GetTail  
 Obtém o `CObject` ponteiro que representa o elemento final desta lista.  
  
```  
TYPE& GetTail();  
const TYPE& GetTail() const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo de elementos na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte a descrição do valor de retorno para [GetHead](../../mfc/reference/coblist-class.md#gethead).  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `GetTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#46](../../mfc/codesnippet/cpp/clist-class_12.cpp)]  
  
##  <a name="gettailposition"></a>  CList::GetTailPosition  
 Obtém a posição do elemento final desta lista; **Nulo** se a lista está vazia.  
  
```  
POSITION GetTailPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se a lista está vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#47](../../mfc/codesnippet/cpp/clist-class_13.cpp)]  
  
##  <a name="insertafter"></a>  CList::InsertAfter  
 Adiciona um elemento a essa lista depois do elemento na posição especificada.  
  
```  
POSITION InsertAfter(POSITION position, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Posição*  
 Um **posição** valor retornado pelo anterior `GetNext`, `GetPrev`, ou **localizar** chamada de função de membro.  
  
 `ARG_TYPE`  
 Especifica o tipo de elemento de lista de parâmetro de modelo.  
  
 `newElement`  
 O elemento a ser adicionada à lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para recuperação de elemento de iteração ou lista.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#48](../../mfc/codesnippet/cpp/clist-class_14.cpp)]  
  
##  <a name="insertbefore"></a>  CList::InsertBefore  
 Adiciona um elemento a essa lista antes do elemento na posição especificada.  
  
```  
POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Posição*  
 Um **posição** valor retornado pelo anterior `GetNext`, `GetPrev`, ou **localizar** chamada de função de membro.  
  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo de elemento de lista (pode ser uma referência).  
  
 `newElement`  
 O elemento a ser adicionada à lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para recuperação de elemento de iteração ou lista.  
  
### <a name="remarks"></a>Comentários  
 Se *posição* é **nulo**, o elemento é inserido no topo da lista.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#49](../../mfc/codesnippet/cpp/clist-class_15.cpp)]  
  
##  <a name="isempty"></a>  CList::IsEmpty  
 Indica se esta lista não contém elementos.  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a lista estiver vazia; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#50](../../mfc/codesnippet/cpp/clist-class_16.cpp)]  
  
##  <a name="removeall"></a>  CList::RemoveAll  
 Remove todos os elementos da lista e libera a memória associada.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Nenhum erro será gerado se a lista já está vazia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#51](../../mfc/codesnippet/cpp/clist-class_17.cpp)]  
  
##  <a name="removeat"></a>  CList::RemoveAt  
 Remove o elemento especificado da lista.  
  
```  
void RemoveAt(POSITION position);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Posição*  
 A posição do elemento a ser removido da lista.  
  
### <a name="remarks"></a>Comentários  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#52](../../mfc/codesnippet/cpp/clist-class_18.cpp)]  
  
##  <a name="removehead"></a>  CList::RemoveHead  
 Remove o elemento do cabeçalho da lista e retorna um ponteiro para ele.  
  
```  
TYPE RemoveHead();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo de elementos na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento anteriormente no topo da lista.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `RemoveHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#53](../../mfc/codesnippet/cpp/clist-class_19.cpp)]  
  
##  <a name="removetail"></a>  CList::RemoveTail  
 Remove o elemento do final da lista e retorna um ponteiro para ele.  
  
```  
TYPE RemoveTail();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo de elementos na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento que estava no final da lista.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `RemoveTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#54](../../mfc/codesnippet/cpp/clist-class_20.cpp)]  
  
##  <a name="setat"></a>  CList::SetAt  
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
 Não é o mesmo que um índice, e você não pode operar em um **posição** valor por conta própria. `SetAt` grava o elemento para a posição especificada na lista.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#55](../../mfc/codesnippet/cpp/clist-class_21.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CMap](../../mfc/reference/cmap-class.md)   
 [Classe CArray](../../mfc/reference/carray-class.md)
