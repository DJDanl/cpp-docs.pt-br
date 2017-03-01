---
title: Classe tile_barrier | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency::tile_barrier
dev_langs:
- C++
helpviewer_keywords:
- tile_barrier class
ms.assetid: b4ccdccb-0032-4e11-b7bd-dc9d43445dee
caps.latest.revision: 17
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 7ace6bb366881f9e5a9678b3a005f3079542c9cd
ms.lasthandoff: 02/25/2017

---
# <a name="tilebarrier-class"></a>Classe tile_barrier
Sincroniza a execução de threads em execução no grupo de thread (o lado a lado) usando `wait` métodos. Apenas o tempo de execução pode criar uma instância dessa classe.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
class tile_barrier;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor tile_barrier](#ctor)|Inicializa uma nova instância da classe `tile_barrier`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Wait](#wait)|Instrui a todos os threads no grupo de thread (bloco) para interromper a execução até que todos os threads no bloco concluiu a espera.|  
|[Método wait_with_all_memory_fence](#wait_with_all_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória foram concluídos e todos os threads no bloco atingiu essa chamada.|  
|[Método wait_with_global_memory_fence](#wait_with_global_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória global foram concluídos e todos os threads no bloco atingir essa chamada.|  
|[Método wait_with_tile_static_memory_fence](#wait_with_tile_static_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os `tile_static` acessos de memória foram concluídos e todos os threads no bloco atingir essa chamada.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tile_barrier`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  

## <a name="a-nametilebarrierctora--tilebarrier-constructor"></a><a name="tile_barrier__ctor"></a>Construtor tile_barrier  
 Inicializa uma nova instância da classe copiando um existente.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
tile_barrier(  
    const tile_barrier& _Other ) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `tile_barrier` objeto a ser copiado.  

## <a name="a-namewaita--wait"></a><a name="wait"></a>Aguarde 
Instrui a todos os threads no grupo de thread (bloco) para interromper a execução até que todos os threads no bloco concluiu a espera.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait() const restrict(amp);  
```    

## <a name="a-namewaitwithallmemoryfencea--waitwithallmemoryfence"></a><a name="wait_with_all_memory_fence"></a>wait_with_all_memory_fence   
Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco atingiu essa chamada. Isso garante que todos os acessos de memória são visíveis a outros threads no bloco de thread e foram executados na ordem do programa.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait_with_all_memory_fence() const restrict(amp);  
```  
  

## <a name="a-namewaitwithglobalmemoryfencea--waitwithglobalmemoryfence"></a><a name="wait_with_global_memory_fence"></a>wait_with_global_memory_fence   
Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco atingiu essa chamada. Isso garante que todos os acessos de memória global são visíveis a outros threads no bloco de thread e foram executados na ordem do programa.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait_with_global_memory_fence() const  restrict(amp);  
```

## <a name="a-namewaitwithtilestaticmemoryfencea--waitwithtilestaticmemoryfence"></a><a name="wait_with_tile_static_memory_fence"></a>wait_with_tile_static_memory_fence   
Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco atingiu essa chamada. Isso garante que `tile_static`memória acessos são visíveis a outros threads no bloco de thread e foram executados na ordem do programa.  
  
### <a name="syntax"></a>Sintaxe 
  
```  
void wait_with_tile_static_memory_fence() const restrict(amp);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

