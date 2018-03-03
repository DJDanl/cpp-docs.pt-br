---
title: Classe CAtlAutoThreadModuleT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlAutoThreadModuleT
- ATLBASE/ATL::CAtlAutoThreadModuleT
- ATLBASE/ATL::CAtlAutoThreadModuleT::GetDefaultThreads
dev_langs:
- C++
helpviewer_keywords:
- CAtlAutoThreadModuleT class
ms.assetid: ae1667c6-3fb8-47bc-b35d-9ea5e9896d7f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 082214794b2caa66e8be1127c664e0ffec18a394
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="catlautothreadmodulet-class"></a>Classe CAtlAutoThreadModuleT
Essa classe fornece métodos para a implementação de um servidor de pool de thread, o modelo de apartment COM.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, 
         class ThreadAllocator = CComSimpleThreadAllocator,
         DWORD dwWait = INFINITE>  
class ATL_NO_VTABLE CAtlAutoThreadModuleT : public IAtlAutoThreadModule
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe que implementará o servidor COM.  
  
 `ThreadAllocator`  
 A classe de gerenciar a seleção de thread. O valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).  
  
 `dwWait`  
 Especifica o intervalo de tempo limite em milissegundos. O padrão é infinito, o que significa que o intervalo de tempo limite do método nunca tiver decorrido.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlAutoThreadModuleT::GetDefaultThreads](#getdefaultthreads)|Função estática dinamicamente calcula e retorna o número máximo de threads para o módulo EXE, com base no número de processadores.|  
  
## <a name="remarks"></a>Comentários  
 A classe [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) deriva `CAtlAutoThreadModuleT` para implementar um servidor de pool de thread, o modelo de apartment COM. Ele substitui a classe obsoleta [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  
  
> [!NOTE]
>  Essa classe não deve ser usada em uma DLL, como o padrão `dwWait` valor infinito causará um deadlock quando a DLL é descarregada.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlAutoThreadModule`  
  
 `CAtlAutoThreadModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="getdefaultthreads"></a>CAtlAutoThreadModuleT::GetDefaultThreads  
 Função estática dinamicamente calcula e retorna o número máximo de threads para o módulo EXE, com base no número de processadores.  
  
```
static int GetDefaultThreads();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de threads a ser criado no módulo EXE.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se você quiser usar um método diferente para calcular o número de threads. Por padrão, o número de threads com base no número de processadores.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)
