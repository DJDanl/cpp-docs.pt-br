---
title: Classe CHeapPtrBase | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHeapPtrBase
- ATLCORE/ATL::CHeapPtrBase
- ATLCORE/ATL::CHeapPtrBase::AllocateBytes
- ATLCORE/ATL::CHeapPtrBase::Attach
- ATLCORE/ATL::CHeapPtrBase::Detach
- ATLCORE/ATL::CHeapPtrBase::Free
- ATLCORE/ATL::CHeapPtrBase::ReallocateBytes
- ATLCORE/ATL::CHeapPtrBase::m_pData
dev_langs:
- C++
helpviewer_keywords:
- CHeapPtrBase class
ms.assetid: 501ac1b2-fb34-4c72-b7e6-a4f1fc8fda21
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 59520211ae577c4ca4358874ef1d8ff71de59921
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cheapptrbase-class"></a>Classe CHeapPtrBase
Essa classe constitui a base para várias classes de ponteiro inteligente do heap.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class Allocator = CCRTAllocator>  
class CHeapPtrBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de objeto a ser armazenado no heap.  
  
 `Allocator`  
 A classe de alocação de memória a ser usado. Por padrão, as rotinas de CRT são usadas para alocar e liberar memória.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase:: ~ CHeapPtrBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase::AllocateBytes](#allocatebytes)|Chame esse método para alocar memória.|  
|[CHeapPtrBase::Attach](#attach)|Chame esse método para assumir a propriedade de um ponteiro existente.|  
|[CHeapPtrBase::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|  
|[CHeapPtrBase::Free](#free)|Chame esse método para excluir um objeto que aponta para um `CHeapPtrBase`.|  
|[CHeapPtrBase::ReallocateBytes](#reallocatebytes)|Chame este método para realocar a memória.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase::operator T *](#operator_t_star)|O operador cast.|  
|[CHeapPtrBase::operator &](#operator_amp)|A & operador.|  
|[CHeapPtrBase::operator ->](#operator_ptr)|O operador de ponteiro-para-membro.|  

  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase::m_pData](#m_pdata)|A variável de membro de dados de ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe constitui a base para várias classes de ponteiro inteligente do heap. As classes derivadas, por exemplo, [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), adicionar seus próprios operadores e construtores. Consulte essas classes para obter exemplos de implementação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="allocatebytes"></a>CHeapPtrBase::AllocateBytes  
 Chame esse método para alocar memória.  
  
```
bool AllocateBytes(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número de bytes de memória a ser alocada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se a memória com êxito é alocado, false caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CHeapPtrBase::m_pData](#m_pdata) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.  
  
##  <a name="attach"></a>CHeapPtrBase::Attach  
 Chame esse método para assumir a propriedade de um ponteiro existente.  
  
```
void Attach(T* pData) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pData`  
 O `CHeapPtrBase` objeto será assumir a propriedade deste ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Quando um `CHeapPtrBase` objeto assume a propriedade de um ponteiro, ele automaticamente excluirá o ponteiro e quaisquer dados alocados quando ele sai do escopo.  
  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CHeapPtrBase::m_pData](#m_pdata) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.  
  
##  <a name="dtor"></a>CHeapPtrBase:: ~ CHeapPtrBase  
 O destruidor.  
  
```
~CHeapPtrBase() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="detach"></a>CHeapPtrBase::Detach  
 Chame este método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CHeapPtrBase::m_pData](#m_pdata) variável de membro para NULL e retorna uma cópia do ponteiro.  
  
##  <a name="free"></a>CHeapPtrBase::Free  
 Chame esse método para excluir um objeto que aponta para um `CHeapPtrBase`.  
  
```
void Free() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto apontado pelo `CHeapPtrBase` é liberado e o [CHeapPtrBase::m_pData](#m_pdata) variável de membro é definido como NULL.  
  
##  <a name="m_pdata"></a>CHeapPtrBase::m_pData  
 A variável de membro de dados de ponteiro.  
  
```
T* m_pData;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações do ponteiro.  
  
##  <a name="operator_amp"></a>CHeapPtrBase::operator&amp;  
 A & operador.  
  
```
T** operator&() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o endereço do objeto que aponta para o `CHeapPtrBase` objeto.  
  

##  <a name="operator_ptr"></a>CHeapPtrBase::operator-&gt;  

 O operador de ponteiro-para-membro.  
  
```
T* operator->() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da [CHeapPtrBase::m_pData](#m_pdata) variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Use este operador para chamar um método em uma classe que aponta para o `CHeapPtrBase` objeto. Em compilações de depuração, uma falha de asserção ocorrerá se o `CHeapPtrBase` aponta para NULL.  
  
##  <a name="operator_t_star"></a>CHeapPtrBase::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna [CHeapPtrBase::m_pData](#m_pdata).  
  
##  <a name="reallocatebytes"></a>CHeapPtrBase::ReallocateBytes  
 Chame este método para realocar a memória.  
  
```
bool ReallocateBytes(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 A nova quantidade de memória a ser alocada em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se a memória com êxito é alocado, false caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
