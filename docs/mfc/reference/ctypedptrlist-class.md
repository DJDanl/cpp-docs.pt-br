---
title: Classe CTypedPtrList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CTypedPtrList
- AFXTEMPL/CTypedPtrList
- AFXTEMPL/CTypedPtrList::AddHead
- AFXTEMPL/CTypedPtrList::AddTail
- AFXTEMPL/CTypedPtrList::GetAt
- AFXTEMPL/CTypedPtrList::GetHead
- AFXTEMPL/CTypedPtrList::GetNext
- AFXTEMPL/CTypedPtrList::GetPrev
- AFXTEMPL/CTypedPtrList::GetTail
- AFXTEMPL/CTypedPtrList::RemoveHead
- AFXTEMPL/CTypedPtrList::RemoveTail
- AFXTEMPL/CTypedPtrList::SetAt
dev_langs:
- C++
helpviewer_keywords:
- CTypedPtrList [MFC], AddHead
- CTypedPtrList [MFC], AddTail
- CTypedPtrList [MFC], GetAt
- CTypedPtrList [MFC], GetHead
- CTypedPtrList [MFC], GetNext
- CTypedPtrList [MFC], GetPrev
- CTypedPtrList [MFC], GetTail
- CTypedPtrList [MFC], RemoveHead
- CTypedPtrList [MFC], RemoveTail
- CTypedPtrList [MFC], SetAt
ms.assetid: c273096e-1756-4340-864b-4a08b674a65e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: afb32a662c538526c4fe26f6abf46e56a42de728
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33374582"
---
# <a name="ctypedptrlist-class"></a>Classe CTypedPtrList
Fornece um "wrapper" de tipo seguro para objetos da classe `CPtrList`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class BASE_CLASS, class TYPE>  
class CTypedPtrList : public BASE_CLASS  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `BASE_CLASS`  
 Classe base da classe lista ponteiro tipado; deve ser uma classe de lista de ponteiro ( `CObList` ou `CPtrList`).  
  
 `TYPE`  
 Tipo dos elementos armazenados na lista de classe base.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTypedPtrList::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o início da lista (faz um novo cabeçalho).|  
|[CTypedPtrList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) para o fim da lista (faz uma novo final).|  
|[CTypedPtrList::GetAt](#getat)|Obtém o elemento na posição especificada.|  
|[CTypedPtrList::GetHead](#gethead)|Retorna o elemento principal da lista (não pode estar vazio).|  
|[CTypedPtrList::GetNext](#getnext)|Obtém o próximo elemento de iteração.|  
|[CTypedPtrList::GetPrev](#getprev)|Obtém o elemento anterior para iteração.|  
|[CTypedPtrList::GetTail](#gettail)|Retorna o elemento final da lista (não pode estar vazio).|  
|[CTypedPtrList::RemoveHead](#removehead)|Remove o elemento do cabeçalho da lista.|  
|[CTypedPtrList::RemoveTail](#removetail)|Remove o elemento do final da lista.|  
|[CTypedPtrList::SetAt](#setat)|Define o elemento na posição especificada.|  
  
## <a name="remarks"></a>Comentários  
 Quando você usa `CTypedPtrList` em vez de `CObList` ou `CPtrList`, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiro incompatíveis.  
  
 Além disso, o `CTypedPtrList` wrapper executa muito a conversão que seria necessária se você usou `CObList` ou `CPtrList`.  
  
 Como todos os `CTypedPtrList` funções embutidas, uso deste modelo não afeta significativamente o tamanho ou velocidade do seu código.  
  
 Listas derivam de `CObList` pode ser serializado, mas os derivados de `CPtrList` não é possível.  
  
 Quando um `CTypedPtrList` objeto é excluído, ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que fazem referência.  
  
 Para obter mais informações sobre como usar `CTypedPtrList`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base no modelo](../../mfc/template-based-classes.md).  
  
## <a name="example"></a>Exemplo  
 Este exemplo cria uma instância de `CTypedPtrList`, adiciona um objeto, serializa a lista para o disco e, em seguida, exclui o objeto:  
  
 [!code-cpp[NVC_MFCCollections#110](../../mfc/codesnippet/cpp/ctypedptrlist-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCCollections#111](../../mfc/codesnippet/cpp/ctypedptrlist-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `BASE_CLASS`  
  
 `_CTypedPtrList`  
  
 `CTypedPtrList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtempl.h  
  
##  <a name="addhead"></a>  CTypedPtrList::AddHead  
 Esta função de membro chama `BASE_CLASS` **:: AddHead**.  
  
```  
POSITION AddHead(TYPE newElement);  
void AddHead(CTypedPtrList<BASE_CLASS, TYPE>* pNewList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Tipo dos elementos armazenados na lista de classe base.  
  
 `newElement`  
 O ponteiro de objeto a ser adicionado a essa lista. Um **nulo** valor permitido.  
  
 `BASE_CLASS`  
 Classe base da classe lista ponteiro tipado; deve ser uma classe de lista de ponteiro ( [CObList](../../mfc/reference/coblist-class.md) ou [CPtrList](../../mfc/reference/cptrlist-class.md)).  
  
 `pNewList`  
 Um ponteiro para outro [CTypedPtrList](../../mfc/reference/ctypedptrlist-class.md) objeto. Os elementos no `pNewList` será adicionado a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a primeira versão do **posição** valor do elemento recentemente inserido.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão adiciona um novo elemento antes do início da lista. A segunda versão adiciona outra lista de elementos antes do início.  
  
##  <a name="addtail"></a>  CTypedPtrList::AddTail  
 Esta função de membro chama `BASE_CLASS` **:: AddTail**.  
  
```  
POSITION AddTail(TYPE newElement);  
void AddTail(CTypedPtrList<BASE_CLASS, TYPE>* pNewList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Tipo dos elementos armazenados na lista de classe base.  
  
 `newElement`  
 O ponteiro de objeto a ser adicionado a essa lista. Um **nulo** valor permitido.  
  
 `BASE_CLASS`  
 Classe base da classe lista ponteiro tipado; deve ser uma classe de lista de ponteiro ( [CObList](../../mfc/reference/coblist-class.md) ou [CPtrList](../../mfc/reference/cptrlist-class.md)).  
  
 `pNewList`  
 Um ponteiro para outro [CTypedPtrList](../../mfc/reference/ctypedptrlist-class.md) objeto. Os elementos no `pNewList` será adicionado a essa lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a primeira versão do **posição** valor do elemento recentemente inserido.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão adiciona um novo elemento após o final da lista. A segunda versão adiciona outra lista de elementos após o final da lista.  
  
##  <a name="getat"></a>  CTypedPtrList::GetAt  
 Uma variável do tipo **posição** é uma chave para a lista.  
  
```  
TYPE& GetAt(POSITION position);  
TYPE GetAt(POSITION position) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especificar o tipo dos elementos armazenados na lista de parâmetro de modelo.  
  
 *Posição*  
 Um **posição** valor retornado pelo anterior `GetHeadPosition` ou **localizar** chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista é acessada por meio de um ponteiro para um **CTypedPtrList const**, em seguida, `GetAt` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.  
  
 Se a lista é acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetAt` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Não é o mesmo que um índice, e você não pode operar em um **posição** valor por conta própria. `GetAt` recupera o `CObject` ponteiro associado com uma posição determinada.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Esta função embutida chama `BASE_CLASS` **:: GetAt**.  
  
##  <a name="gethead"></a>  CTypedPtrList::GetHead  
 Obtém o ponteiro que representa o elemento principal desta lista.  
  
```  
TYPE& GetHead();  
TYPE GetHead() const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especificar o tipo dos elementos armazenados na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista é acessada por meio de um ponteiro para um **CTypedPtrList const**, em seguida, `GetHead` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.  
  
 Se a lista é acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetHead` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `GetHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.  
  
##  <a name="getnext"></a>  CTypedPtrList::GetNext  
 Obtém o elemento de lista, identificado pelo `rPosition`, em seguida, define `rPosition` para o **posição** valor da próxima entrada na lista.  
  
```  
TYPE& GetNext(POSITION& rPosition);  
TYPE GetNext(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Parâmetro de modelo especificando o tipo de elementos contidos nesta lista.  
  
 `rPosition`  
 Uma referência a um **posição** valor retornado pelo anterior `GetNext`, `GetHeadPosition`, ou outra chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista é acessada por meio de um ponteiro para um **CTypedPtrList const**, em seguida, `GetNext` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.  
  
 Se a lista é acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetNext` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetNext` em um loop de interação direta se estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou [CPtrList::Find](../../mfc/reference/coblist-class.md#find).  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Se o elemento recuperado é o último na lista, em seguida, o novo valor de `rPosition` é definido como **nulo**.  
  
 É possível remover um elemento durante uma iteração. Consulte o exemplo para [CObList::RemoveAt](../../mfc/reference/coblist-class.md#removeat).  
  
##  <a name="getprev"></a>  CTypedPtrList::GetPrev  
 Obtém o elemento de lista, identificado pelo `rPosition`, em seguida, define `rPosition` para o **posição** valor da entrada anterior na lista.  
  
```  
TYPE& GetPrev(POSITION& rPosition);  
TYPE GetPrev(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Parâmetro de modelo especificando o tipo de elementos contidos nesta lista.  
  
 `rPosition`  
 Uma referência a um **posição** valor retornado pelo anterior `GetPrev` ou outra chamada de função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista é acessada por meio de um ponteiro para um **CTypedPtrList const**, em seguida, `GetPrev` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.  
  
 Se a lista é acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetPrev` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetPrev` em um loop de iteração inversa se estabelecer a posição inicial com uma chamada para `GetTailPosition` ou **localizar**.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Se o elemento recuperado é o primeiro na lista, em seguida, o novo valor de `rPosition` é definido como **nulo**.  
  
##  <a name="gettail"></a>  CTypedPtrList::GetTail  
 Obtém o ponteiro que representa o elemento principal desta lista.  
  
```  
TYPE& GetTail();  
TYPE GetTail() const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especificar o tipo dos elementos armazenados na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a lista é acessada por meio de um ponteiro para um **CTypedPtrList const**, em seguida, `GetTail` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.  
  
 Se a lista é acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetTail` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificada.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `GetTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.  
  
##  <a name="removehead"></a>  CTypedPtrList::RemoveHead  
 Remove o elemento do cabeçalho da lista e o retorna.  
  
```  
TYPE RemoveHead();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especificar o tipo dos elementos armazenados na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro anteriormente no topo da lista. Esse ponteiro for do tipo especificado pelo parâmetro de modelo *tipo*.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `RemoveHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.  
  
##  <a name="removetail"></a>  CTypedPtrList::RemoveTail  
 Remove o elemento do final da lista e o retorna.  
  
```  
TYPE RemoveTail();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especificar o tipo dos elementos armazenados na lista de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro anteriormente ao final da lista. Esse ponteiro for do tipo especificado pelo parâmetro de modelo *tipo*.  
  
### <a name="remarks"></a>Comentários  
 Certifique-se de que a lista não está vazia antes de chamar `RemoveTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.  
  
##  <a name="setat"></a>  CTypedPtrList::SetAt  
 Esta função de membro chama `BASE_CLASS` **:: SetAt**.  
  
```  
void SetAt(POSITION pos, TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O **posição** do elemento a ser definido.  
  
 *TIPO DE*  
 Tipo dos elementos armazenados na lista de classe base.  
  
 `newElement`  
 O ponteiro de objeto a ser gravado para a lista.  
  
### <a name="remarks"></a>Comentários  
 Uma variável do tipo **posição** é uma chave para a lista. Não é o mesmo que um índice, e você não pode operar em um **posição** valor por conta própria. `SetAt` grava o ponteiro de objeto para a posição especificada na lista.  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Para obter mais comentários, consulte [CObList::SetAt](../../mfc/reference/coblist-class.md#setat).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CPtrList](../../mfc/reference/cptrlist-class.md)   
 [Classe CObList](../../mfc/reference/coblist-class.md)
