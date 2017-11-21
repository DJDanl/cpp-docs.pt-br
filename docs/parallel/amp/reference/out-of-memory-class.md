---
title: Classe out_of_memory | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- out_of_memory
- AMPRT/out_of_memory
- AMPRT/Concurrency::out_of_memory::out_of_memory
dev_langs: C++
helpviewer_keywords: out_of_memory class
ms.assetid: 3aa7e682-8f13-4ae6-9188-31fb423956e4
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 95694c3566ef7700d30e40c1a89af56d1e70d05b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="outofmemory-class"></a>Classe out_of_memory
A exceção que é lançada quando um método falhar devido a uma falta de memória de sistema ou dispositivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class out_of_memory : public runtime_exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de out_of_memory](#ctor)|Inicializa uma nova instância da classe `out_of_memory`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `runtime_exception`  
  
 `out_of_memory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
## <a name="ctor"></a>out_of_memory 

 Inicializa uma nova instância da classe.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
explicit out_of_memory(  
    const char * _Message ) throw();  
  
out_of_memory () throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma descrição do erro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma nova instância da classe `out_of_memory`.  
  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
