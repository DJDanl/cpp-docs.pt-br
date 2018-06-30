---
title: Classe CStringList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CObList [MFC], CObList
- CObList [MFC], AddHead
- CObList [MFC], AddTail
- CObList [MFC], Find
- CObList [MFC], FindIndex
- CObList [MFC], GetAt
- CObList [MFC], GetCount
- CObList [MFC], GetHead
- CObList [MFC], GetHeadPosition
- CObList [MFC], GetNext
- CObList [MFC], GetPrev
- CObList [MFC], GetSize
- CObList [MFC], GetTail
- CObList [MFC], GetTailPosition
- CObList [MFC], InsertAfter
- CObList [MFC], InsertBefore
- CObList [MFC], IsEmpty
- CObList [MFC], RemoveAll
- CObList [MFC], RemoveAt
- CObList [MFC], RemoveHead
- CObList [MFC], RemoveTail
- CObList [MFC], SetAt
ms.assetid: 310a7edb-263c-4bd2-ac43-0bfbfddc5a33
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 31e13222ccd5ac12768961ff5e93d11e68ecfded
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122709"
---
# <a name="cstringlist-class"></a>Classe CStringList
Dá suporte a listas de `CString` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStringList : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro de `CStringList` são semelhantes às funções de membro da classe [CObList](../../mfc/reference/coblist-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObList` para obter a função específica de membro. Sempre que você vê um `CObject` ponteiro como um valor de retorno, substitua um `CString` (não um `CString` ponteiro). Sempre que você vê um `CObject` ponteiro como um parâmetro de função, substitua um `LPCTSTR`.  
  
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
|[CObList::AddHead](../../mfc/reference/coblist-class.md#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o início da lista (faz um novo cabeçalho).|  
|[CObList::AddTail](../../mfc/reference/coblist-class.md#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) para o fim da lista (faz uma novo final).|  
|[CObList::Find](../../mfc/reference/coblist-class.md#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|  
|[CObList::FindIndex](../../mfc/reference/coblist-class.md#findindex)|Obtém a posição de um elemento especificado por um índice com base em zero.|  
|[CObList::GetAt](../../mfc/reference/coblist-class.md#getat)|Obtém o elemento na posição especificada.|  
|[CObList::GetCount](../../mfc/reference/coblist-class.md#getcount)|Retorna o número de elementos nesta lista.|  
|[CObList::GetHead](../../mfc/reference/coblist-class.md#gethead)|Retorna o elemento principal da lista (não pode estar vazio).|  
|[CObList::GetHeadPosition](../../mfc/reference/coblist-class.md#getheadposition)|Retorna a posição do elemento principal da lista.|  
|[CObList::GetNext](../../mfc/reference/coblist-class.md#getnext)|Obtém o próximo elemento de iteração.|  
|[CObList::GetPrev](../../mfc/reference/coblist-class.md#getprev)|Obtém o elemento anterior para iteração.|  
|[CObList::GetSize](../../mfc/reference/coblist-class.md#getsize)|Retorna o número de elementos nesta lista.|  
|[CObList::GetTail](../../mfc/reference/coblist-class.md#gettail)|Retorna o elemento final da lista (não pode estar vazio).|  
|[CObList::GetTailPosition](../../mfc/reference/coblist-class.md#gettailposition)|Retorna a posição do elemento da parte final da lista.|  
|[CObList::InsertAfter](../../mfc/reference/coblist-class.md#insertafter)|Insere um novo elemento após uma posição determinada.|  
|[CObList::InsertBefore](../../mfc/reference/coblist-class.md#insertbefore)|Insere um novo elemento antes de uma determinada posição.|  
|[CObList::IsEmpty](../../mfc/reference/coblist-class.md#isempty)|Testes para a condição de lista vazia (sem elementos).|  
|[CObList::RemoveAll](../../mfc/reference/coblist-class.md#removeall)|Remove todos os elementos da lista.|  
|[CObList::RemoveAt](../../mfc/reference/coblist-class.md#removeat)|Remove um elemento nesta lista, especificada pela posição.|  
|[CObList::RemoveHead](../../mfc/reference/coblist-class.md#removehead)|Remove o elemento do cabeçalho da lista.|  
|[CObList::RemoveTail](../../mfc/reference/coblist-class.md#removetail)|Remove o elemento do final da lista.|  
|[CObList::SetAt](../../mfc/reference/coblist-class.md#setat)|Define o elemento na posição especificada.|  
  
## <a name="remarks"></a>Comentários  
 Todas as comparações são feitas por valor, o que significa que os caracteres na cadeia de caracteres são comparados, em vez dos endereços das cadeias de caracteres.  
  
 `CStringList` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e despejo de seus elementos. Se uma lista de `CString` objetos são armazenados para um arquivo, com um operador de inserção sobrecarregado ou com o `Serialize` função de membro, cada `CString` elemento é serializado por sua vez.  
  
 Se você precisar de um despejo do indivíduo `CString` elementos, você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
 Para obter mais informações sobre como usar `CStringList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CStringList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



