---
title: Classe tile_barrier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 62e81b7cab8d7e8774e6ac50c5de5f256d76b232
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686484"
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

## <a name="tile_barrier__ctor"></a>  Construtor de tile_barrier  
 Inicializa uma nova instância da classe copiando um existente.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
tile_barrier(  
    const tile_barrier& _Other ) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `tile_barrier` objeto a ser copiado.  

## <a name="wait"></a>  Aguarde 
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
