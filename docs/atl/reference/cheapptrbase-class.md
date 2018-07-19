---
title: Classe CHeapPtrBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d847c83fce13ea39c3032e7db638a91b1cb7ad85
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37880314"
---
# <a name="cheapptrbase-class"></a>Classe CHeapPtrBase
Essa classe constitui a base para várias classes de ponteiro inteligente de heap.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class Allocator = CCRTAllocator>  
class CHeapPtrBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo de objeto a ser armazenado no heap.  
  
 *Alocador*  
 A classe de alocação de memória para usar. Por padrão, as rotinas de CRT são usadas para alocar e liberar memória.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase:: ~ CHeapPtrBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase::AllocateBytes](#allocatebytes)|Chame esse método para alocar memória.|  
|[CHeapPtrBase::Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|  
|[CHeapPtrBase::Detach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|  
|[CHeapPtrBase::Free](#free)|Chame esse método para excluir um objeto apontado por um `CHeapPtrBase`.|  
|[CHeapPtrBase::ReallocateBytes](#reallocatebytes)|Chame esse método para realocar a memória.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase::operator T *](#operator_t_star)|O operador cast.|  
|[CHeapPtrBase::operator &](#operator_amp)|A & operador.|  
|[CHeapPtrBase::operator ->](#operator_ptr)|O operador de ponteiro para membro.|  

  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrBase::m_pData](#m_pdata)|A variável de membro de dados de ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe constitui a base para várias classes de ponteiro inteligente de heap. As classes derivadas, por exemplo, [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), adicionar seus próprios construtores e operadores. Consulte essas classes para obter exemplos de implementação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="allocatebytes"></a>  CHeapPtrBase::AllocateBytes  
 Chame esse método para alocar memória.  
  
```
bool AllocateBytes(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBytes*  
 O número de bytes de memória para alocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a memória com êxito é alocado, false caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CHeapPtrBase::m_pData](#m_pdata) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.  
  
##  <a name="attach"></a>  CHeapPtrBase::Attach  
 Chame esse método para apropriar-se de um ponteiro existente.  
  
```
void Attach(T* pData) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pData*  
 O `CHeapPtrBase` objeto assumirá a propriedade do ponteiro this.  
  
### <a name="remarks"></a>Comentários  
 Quando um `CHeapPtrBase` objeto assume a propriedade de um ponteiro, ele automaticamente excluirá o ponteiro e todos os dados alocados quando ele sai do escopo.  
  
 Em compilações de depuração, uma falha de asserção ocorrerá se o [CHeapPtrBase::m_pData](#m_pdata) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.  
  
##  <a name="dtor"></a>  CHeapPtrBase:: ~ CHeapPtrBase  
 O destruidor.  
  
```
~CHeapPtrBase() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="detach"></a>  CHeapPtrBase::Detach  
 Chame esse método para liberar a propriedade de um ponteiro.  
  
```
T* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade de um ponteiro, define o [CHeapPtrBase::m_pData](#m_pdata) variável de membro para NULL e retorna uma cópia do ponteiro.  
  
##  <a name="free"></a>  CHeapPtrBase::Free  
 Chame esse método para excluir um objeto apontado por um `CHeapPtrBase`.  
  
```
void Free() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto apontado pela `CHeapPtrBase` é liberado e o [CHeapPtrBase::m_pData](#m_pdata) variável de membro é definido como NULL.  
  
##  <a name="m_pdata"></a>  CHeapPtrBase::m_pData  
 A variável de membro de dados de ponteiro.  
  
```
T* m_pData;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável de membro contém as informações de ponteiro.  
  
##  <a name="operator_amp"></a>  CHeapPtrBase::operator &amp;  
 A & operador.  
  
```
T** operator&() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o endereço do objeto apontado pelo `CHeapPtrBase` objeto.  
  

##  <a name="operator_ptr"></a>  CHeapPtrBase::operator-&gt;  

 O operador de ponteiro para membro.  
  
```
T* operator->() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da [CHeapPtrBase::m_pData](#m_pdata) variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Use este operador para chamar um método em uma classe apontada pelo `CHeapPtrBase` objeto. Em compilações de depuração, uma falha de asserção ocorrerá se o `CHeapPtrBase` aponta para NULL.  
  
##  <a name="operator_t_star"></a>  CHeapPtrBase::operator T *  
 O operador cast.  
  
```  
operator T*() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna [CHeapPtrBase::m_pData](#m_pdata).  
  
##  <a name="reallocatebytes"></a>  CHeapPtrBase::ReallocateBytes  
 Chame esse método para realocar a memória.  
  
```
bool ReallocateBytes(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBytes*  
 A nova quantidade de memória para alocar, em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a memória com êxito é alocado, false caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
