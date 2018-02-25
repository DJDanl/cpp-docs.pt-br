---
title: Classe tile_barrier | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- tile_barrier
- AMP/tile_barrier
- AMP/Concurrency::tile_barrier::tile_barrier::tile_barrier
- AMP/Concurrency::tile_barrier::tile_barrier::wait
- AMP/Concurrency::tile_barrier::tile_barrier::wait_with_all_memory_fence
- AMP/Concurrency::tile_barrier::tile_barrier::wait_with_global_memory_fence
- AMP/Concurrency::tile_barrier::tile_barrier::wait_with_tile_static_memory_fence
dev_langs:
- C++
helpviewer_keywords:
- tile_barrier class
ms.assetid: b4ccdccb-0032-4e11-b7bd-dc9d43445dee
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e7d868b4bd677d207590de6449e3d5643001e857
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="tilebarrier-class"></a>Classe tile_barrier
Sincroniza a execução de threads que estão em execução no grupo de thread (bloco) usando `wait` métodos. Apenas o tempo de execução pode criar uma instância dessa classe.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
class tile_barrier;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de tile_barrier](#ctor)|Inicializa uma nova instância da classe `tile_barrier`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[wait](#wait)|Instrui a todos os threads no grupo de thread (bloco) para parar a execução até que todos os threads no bloco concluiu a espera.|  
|[wait_with_all_memory_fence](#wait_with_all_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória tiveram sido concluídos e todos os threads no bloco atingiu esta chamada.|  
|[wait_with_global_memory_fence](#wait_with_global_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória global foram concluídos e todos os threads no bloco atingiu esta chamada.|  
|[wait_with_tile_static_memory_fence](#wait_with_tile_static_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os `tile_static` acessos de memória foram concluídos e todos os threads no bloco atingiu esta chamada.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tile_barrier`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  

## <a name="tile_barrier__ctor">Construtor de tile_barrier</a>  
 Inicializa uma nova instância da classe copiando um existente.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
tile_barrier(  
    const tile_barrier& _Other ) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `tile_barrier` objeto a ser copiado.  

## <a name="wait"></a>  wait 
Instrui a todos os threads no grupo de thread (bloco) para interromper a execução até que todos os threads no bloco concluiu a espera.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait() const restrict(amp);  
```    

## <a name="wait_with_all_memory_fence"></a>  wait_with_all_memory_fence   
Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco atingiu esta chamada. Isso garante que todos os acessos de memória são visíveis para outros threads no bloco do thread e foram executados na ordem do programa.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait_with_all_memory_fence() const restrict(amp);  
```  
  

## <a name="wait_with_global_memory_fence"></a>  wait_with_global_memory_fence   
Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco atingiu esta chamada. Isso garante que todos os acessos de memória global são visíveis para outros threads no bloco do thread e foram executados na ordem do programa.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait_with_global_memory_fence() const  restrict(amp);  
```

## <a name="wait_with_tile_static_memory_fence"></a>  wait_with_tile_static_memory_fence   
Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco atingiu esta chamada. Isso assegura que `tile_static` memória acessos são visíveis para outros threads no bloco do thread e foram executados na ordem do programa.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait_with_tile_static_memory_fence() const restrict(amp);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
