---
title: Classe CStringList | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStringList
- AFXCOLL/CStringList
- AFXCOLL/CObList::CObList
- AFXCOLL/CObList::AddHead
- AFXCOLL/CObList::AddTail
- AFXCOLL/CObList::Find
- AFXCOLL/CObList::FindIndex
- AFXCOLL/CObList::GetAt
- AFXCOLL/CObList::GetCount
- AFXCOLL/CObList::GetHead
- AFXCOLL/CObList::GetHeadPosition
- AFXCOLL/CObList::GetNext
- AFXCOLL/CObList::GetPrev
- AFXCOLL/CObList::GetSize
- AFXCOLL/CObList::GetTail
- AFXCOLL/CObList::GetTailPosition
- AFXCOLL/CObList::InsertAfter
- AFXCOLL/CObList::InsertBefore
- AFXCOLL/CObList::IsEmpty
- AFXCOLL/CObList::RemoveAll
- AFXCOLL/CObList::RemoveAt
- AFXCOLL/CObList::RemoveHead
- AFXCOLL/CObList::RemoveTail
- AFXCOLL/CObList::SetAt
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], lists
- lists, string
- CStringList class
- strings [C++], collections
ms.assetid: 310a7edb-263c-4bd2-ac43-0bfbfddc5a33
caps.latest.revision: 25
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 0b67104e330890ffe8f67bac0dd3b129c7742a29
ms.lasthandoff: 02/25/2017

---
# <a name="cstringlist-class"></a>Classe CStringList
Oferece suporte a listas de `CString` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStringList : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro do `CStringList` são semelhantes às funções de membro da classe [CObList](../../mfc/reference/coblist-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObList` para obter a função específica de membro. Ao ver um `CObject` ponteiro como um valor de retorno, substitua um `CString` (não um `CString` ponteiro). Ao ver um `CObject` ponteiro como um parâmetro de função, substitua um `LPCTSTR`.  
  
 `CObject*& CObList::GetHead() const;`  
  
 por exemplo, traduz para  
  
 `CString& CStringList::GetHead() const;`  
  
 e  
  
 `POSITION AddHead( CObject* <newElement> );`  
  
 traduz para  
  
 `POSITION AddHead( LPCTSTR <newElement> );`  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObList::CObList](../../mfc/reference/coblist-class.md#coblist)|Constrói uma lista vazia.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObList::AddHead](../../mfc/reference/coblist-class.md#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o topo da lista (faz um novo cabeçalho).|  
|[CObList::AddTail](../../mfc/reference/coblist-class.md#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) até o final da lista (faz uma nova final).|  
|[CObList::Find](../../mfc/reference/coblist-class.md#find)|Obtém a posição de um elemento especificado pelo valor de ponteiro.|  
|[CObList::FindIndex](../../mfc/reference/coblist-class.md#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|  
|[CObList::GetAt](../../mfc/reference/coblist-class.md#getat)|Obtém o elemento na posição especificada.|  
|[CObList::GetCount](../../mfc/reference/coblist-class.md#getcount)|Retorna o número de elementos nesta lista.|  
|[CObList::GetHead](../../mfc/reference/coblist-class.md#gethead)|Retorna o elemento principal da lista (não pode ser vazio).|  
|[CObList::GetHeadPosition](../../mfc/reference/coblist-class.md#getheadposition)|Retorna a posição do elemento principal da lista.|  
|[CObList::GetNext](../../mfc/reference/coblist-class.md#getnext)|Obtém o próximo elemento de iteração.|  
|[CObList::GetPrev](../../mfc/reference/coblist-class.md#getprev)|Obtém o elemento anterior para iteração.|  
|[CObList::GetSize](../../mfc/reference/coblist-class.md#getsize)|Retorna o número de elementos nesta lista.|  
|[CObList::GetTail](../../mfc/reference/coblist-class.md#gettail)|Retorna o elemento final da lista (não pode ser vazio).|  
|[CObList::GetTailPosition](../../mfc/reference/coblist-class.md#gettailposition)|Retorna a posição do elemento final da lista.|  
|[CObList::InsertAfter](../../mfc/reference/coblist-class.md#insertafter)|Insere um novo elemento após uma determinada posição.|  
|[CObList::InsertBefore](../../mfc/reference/coblist-class.md#insertbefore)|Insere um novo elemento antes de uma determinada posição.|  
|[CObList::IsEmpty](../../mfc/reference/coblist-class.md#isempty)|Testa a condição da lista vazia (sem elementos).|  
|[CObList::RemoveAll](../../mfc/reference/coblist-class.md#removeall)|Remove todos os elementos dessa lista.|  
|[CObList::RemoveAt](../../mfc/reference/coblist-class.md#removeat)|Remove um elemento dessa lista, especificada pela posição.|  
|[CObList::RemoveHead](../../mfc/reference/coblist-class.md#removehead)|Remove o elemento do cabeçalho da lista.|  
|[CObList::RemoveTail](../../mfc/reference/coblist-class.md#removetail)|Remove o elemento final da lista.|  
|[CObList::SetAt](../../mfc/reference/coblist-class.md#setat)|Define o elemento na posição especificada.|  
  
## <a name="remarks"></a>Comentários  
 Todas as comparações são feitas por valor, o que significa que os caracteres na cadeia de caracteres são comparados, em vez dos endereços das cadeias de caracteres.  
  
 A `CStringList` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Se uma lista de `CString` objetos são armazenados em um arquivo, com um operador de inserção sobrecarregado ou com o `Serialize` função do membro, cada `CString` elemento é serializado por vez.  
  
 Se for necessário um despejo de individuais `CString` elementos, você deve definir a profundidade do contexto do despejo como 1 ou maior.  
  
 Para obter mais informações sobre como usar o `CStringList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CStringList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll. h  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




