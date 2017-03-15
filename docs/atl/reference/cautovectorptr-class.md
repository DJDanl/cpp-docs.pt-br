---
title: Classe CAutoVectorPtr | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CAutoVectorPtr
- ATL.CAutoVectorPtr
- ATL.CAutoVectorPtr<T>
- CAutoVectorPtr
- ATL::CAutoVectorPtr<T>
dev_langs:
- C++
helpviewer_keywords:
- CAutoVectorPtr class
ms.assetid: 0030362b-6bc4-4a47-9b5b-3c3899dceab4
caps.latest.revision: 20
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: bb4bbd110552d1e3cf604add44de7e428d2703ee
ms.lasthandoff: 02/25/2017

---
# <a name="cautovectorptr-class"></a>Classe CAutoVectorPtr
Essa classe representa um objeto de ponteiro inteligente usando o vetor novo e excluir operadores.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CAutoVectorPtr
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de ponteiro.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtr::CAutoVectorPtr](#cautovectorptr)|O construtor.|  
|[CAutoVectorPtr:: ~ CAutoVectorPtr](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtr::Allocate](#allocate)|Chame esse método para alocar a memória necessária para a matriz de objetos apontados por `CAutoVectorPtr`.|  
|[CAutoVectorPtr::Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|  
|[CAutoVectorPtr::Detach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|  
|[CAutoVectorPtr::Free](#free)|Chame esse método para excluir um objeto apontado por um `CAutoVectorPtr`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtr::operator T *](#operator_t__star)|O operador cast.|  
|[CAutoVectorPtr::operator =](#operator_eq)|O operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtr::m_p](#m_p)|A variável de membro de dados do ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, o que ajudará a proteger contra vazamentos de memória, liberando os recursos automaticamente quando ele ficar fora do escopo. `CAutoVectorPtr`é semelhante ao `CAutoPtr`, a única diferença é que `CAutoVectorPtr` usa [vetor [novo]](../../standard-library/new-operators.md#operator_new_arr) e [vetor delete []](../../standard-library/new-operators.md#operator_delete_arr) para alocar e liberar memória, em vez do C++ **novo** e **excluir** operadores. Consulte [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) se as classes de coleção de `CAutoVectorPtr` são necessários.  

  
 Consulte [CAutoPtr](../../atl/reference/cautoptr-class.md) para obter um exemplo do uso de uma classe de ponteiro inteligente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-nameallocatea--cautovectorptrallocate"></a><a name="allocate"></a>CAutoVectorPtr::Allocate  
 Chame esse método para alocar a memória necessária para a matriz de objetos apontados por `CAutoVectorPtr`.  
  
```
bool Allocate(size_t nElements) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nElements`  
 O número de elementos na matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se a memória com êxito é alocado, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoVectorPtr::m_p](#m_p) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a nulo.  
  
##  <a name="a-nameattacha--cautovectorptrattach"></a><a name="attach"></a>CAutoVectorPtr::Attach  
 Chame esse método para apropriar-se de um ponteiro existente.  
  
```
void Attach(T* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 O `CAutoVectorPtr` objeto será assumir a propriedade deste ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Quando um `CAutoVectorPtr` objeto se apropria de um ponteiro, ele excluirá automaticamente o ponteiro e todos os dados alocados quando ele sai do escopo. Se [CAutoVectorPtr::Detach](#detach) é chamado, o programador é novamente determinado responsabilidade para liberar qualquer recursos alocado.  
  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoVectorPtr::m_p](#m_p) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a nulo.  
  
##  <a name="a-namecautovectorptra--cautovectorptrcautovectorptr"></a><a name="cautovectorptr"></a>CAutoVectorPtr::CAutoVectorPtr  
 O construtor.  
  
```
CAutoVectorPtr() throw();
explicit CAutoVectorPtr(T* p) throw();
CAutoVectorPtr(CAutoVectorPtr<T>& p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Um ponteiro existente.  
  
### <a name="remarks"></a>Comentários  
 O `CAutoVectorPtr` objeto pode ser criado usando um ponteiro existente, caso em que ele transfere a propriedade do ponteiro.  
  
##  <a name="a-namedtora--cautovectorptrcautovectorptr"></a><a name="dtor"></a>CAutoVectorPtr:: ~ CAutoVectorPtr  
 O destruidor.  
  
```
~CAutoVectorPtr() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados. Chamadas [CAutoVectorPtr::Free](#free).  
  
##  <a name="a-namedetacha--cautovectorptrdetach"></a><a name="detach"></a>CAutoVectorPtr::Detach  
 Chame esse método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CAutoVectorPtr::m_p](#m_p) variável de membro para NULL e retorna uma cópia do ponteiro. Depois de chamar **desanexar**, é responsabilidade do programador para liberar qualquer alocado recursos através da qual o `CAutoVectorPtr` objeto pode ter anteriormente assumiu a responsabilidade.  
  
##  <a name="a-namefreea--cautovectorptrfree"></a><a name="free"></a>CAutoVectorPtr::Free  
 Chame esse método para excluir um objeto apontado por um `CAutoVectorPtr`.  
  
```
void Free() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto apontado pelo `CAutoVectorPtr` é liberado e o [CAutoVectorPtr::m_p](#m_p) variável de membro é definido como NULL.  
  
##  <a name="a-namempa--cautovectorptrmp"></a><a name="m_p"></a>CAutoVectorPtr::m_p  
 A variável de membro de dados do ponteiro.  
  
```
T* m_p;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações do ponteiro.  
  
##  <a name="a-nameoperatoreqa--cautovectorptroperator-"></a><a name="operator_eq"></a>CAutoVectorPtr::operator =  
 O operador de atribuição.  
  
```
CAutoVectorPtr<T>& operator= (CAutoVectorPtr<T>& p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Um ponteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência a um **CAutoVectorPtr\< T >**.  
  
### <a name="remarks"></a>Comentários  
 O operador de atribuição desanexa o `CAutoVectorPtr` objeto a partir de qualquer ponteiro atual e anexa o novo ponteiro, `p`, em seu lugar.  
  
##  <a name="a-nameoperatortstara--cautovectorptroperator-t-"></a><a name="operator_t__star"></a>CAutoVectorPtr::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAutoPtr](../../atl/reference/cautoptr-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

