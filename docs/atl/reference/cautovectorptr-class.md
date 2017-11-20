---
title: Classe CAutoVectorPtr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAutoVectorPtr
- ATLBASE/ATL::CAutoVectorPtr
- ATLBASE/ATL::CAutoVectorPtr::CAutoVectorPtr
- ATLBASE/ATL::CAutoVectorPtr::Allocate
- ATLBASE/ATL::CAutoVectorPtr::Attach
- ATLBASE/ATL::CAutoVectorPtr::Detach
- ATLBASE/ATL::CAutoVectorPtr::Free
- ATLBASE/ATL::CAutoVectorPtr::m_p
dev_langs: C++
helpviewer_keywords: CAutoVectorPtr class
ms.assetid: 0030362b-6bc4-4a47-9b5b-3c3899dceab4
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 304f21e226e88f4c18b218ac580d82fdb2f776a4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cautovectorptr-class"></a>Classe CAutoVectorPtr
Essa classe representa um objeto de ponteiro inteligente usando o vetor de novo e excluir operadores.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
|[CAutoVectorPtr::Allocate](#allocate)|Chame esse método para alocar a memória necessária à matriz de objetos apontada pelo `CAutoVectorPtr`.|  
|[CAutoVectorPtr::Attach](#attach)|Chame esse método para assumir a propriedade de um ponteiro existente.|  
|[CAutoVectorPtr::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|  
|[CAutoVectorPtr::Free](#free)|Chame esse método para excluir um objeto que aponta para um `CAutoVectorPtr`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtr::operator T *](#operator_t__star)|O operador cast.|  
|[CAutoVectorPtr::operator =](#operator_eq)|O operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtr::m_p](#m_p)|A variável de membro de dados de ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, o que ajudará a proteger contra vazamentos de memória, a liberação de recursos automaticamente quando ele ficar fora do escopo. `CAutoVectorPtr`é semelhante a `CAutoPtr`, a única diferença é que `CAutoVectorPtr` usa [vetor novo &#91; &#93;](../../standard-library/new-operators.md#op_new_arr) e [Excluir &#91; &#93; de vetor](../../standard-library/new-operators.md#op_delete_arr) para alocar e liberar memória, em vez de o C++ **novo** e **excluir** operadores. Consulte [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) se classes de coleção de `CAutoVectorPtr` são necessários.  

  
 Consulte [CAutoPtr](../../atl/reference/cautoptr-class.md) para obter um exemplo do uso de uma classe de ponteiro inteligente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="allocate"></a>CAutoVectorPtr::Allocate  
 Chame esse método para alocar a memória necessária à matriz de objetos apontada pelo `CAutoVectorPtr`.  
  
```
bool Allocate(size_t nElements) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nElements`  
 O número de elementos na matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se a memória com êxito é alocado, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoVectorPtr::m_p](#m_p) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.  
  
##  <a name="attach"></a>CAutoVectorPtr::Attach  
 Chame esse método para assumir a propriedade de um ponteiro existente.  
  
```
void Attach(T* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 O `CAutoVectorPtr` objeto será assumir a propriedade deste ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Quando um `CAutoVectorPtr` objeto assume a propriedade de um ponteiro, ele automaticamente excluirá o ponteiro e quaisquer dados alocados quando ele sai do escopo. Se [CAutoVectorPtr::Detach](#detach) é chamado, o programador é novamente determinado responsabilidade para liberar qualquer recursos alocado.  
  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoVectorPtr::m_p](#m_p) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.  
  
##  <a name="cautovectorptr"></a>CAutoVectorPtr::CAutoVectorPtr  
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
 O `CAutoVectorPtr` objeto pode ser criado com um indicador existente, caso em que ele transfere a propriedade do ponteiro.  
  
##  <a name="dtor"></a>CAutoVectorPtr:: ~ CAutoVectorPtr  
 O destruidor.  
  
```
~CAutoVectorPtr() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados. Chamadas [CAutoVectorPtr::Free](#free).  
  
##  <a name="detach"></a>CAutoVectorPtr::Detach  
 Chame este método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CAutoVectorPtr::m_p](#m_p) variável de membro para NULL e retorna uma cópia do ponteiro. Depois de chamar **desanexar**, é responsabilidade do programador para liberar qualquer alocado recursos durante o qual o `CAutoVectorPtr` objeto pode ter achado anteriormente responsabilidade.  
  
##  <a name="free"></a>CAutoVectorPtr::Free  
 Chame esse método para excluir um objeto que aponta para um `CAutoVectorPtr`.  
  
```
void Free() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto apontado pelo `CAutoVectorPtr` é liberado e o [CAutoVectorPtr::m_p](#m_p) variável de membro é definido como NULL.  
  
##  <a name="m_p"></a>CAutoVectorPtr::m_p  
 A variável de membro de dados de ponteiro.  
  
```
T* m_p;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações do ponteiro.  
  
##  <a name="operator_eq"></a>CAutoVectorPtr::operator =  
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
 O operador de atribuição desanexa o `CAutoVectorPtr` objeto a partir de qualquer ponteiro atual e anexa o ponteiro, `p`, em seu lugar.  
  
##  <a name="operator_t__star"></a>CAutoVectorPtr::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAutoPtr](../../atl/reference/cautoptr-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
