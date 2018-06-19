---
title: Classe unsupported_os | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- unsupported_os
- CONCRT/concurrency::unsupported_os
- CONCRT/concurrency::unsupported_os::unsupported_os
dev_langs:
- C++
helpviewer_keywords:
- unsupported_os class
ms.assetid: 6fa57636-341b-4b51-84cc-261d283ff736
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7a4881bc0182c0d7bfbc5b5806fd6a59eea7fb25
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33687420"
---
# <a name="unsupportedos-class"></a>Classe unsupported_os
Esta classe descreve uma exceção gerada quando é usado um sistema operacional sem suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class unsupported_os : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[unsupported_os](#ctor)|Sobrecarregado. Constrói uma `unsupported_os` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `unsupported_os`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> unsupported_os 

 Constrói uma `unsupported_os` objeto.  
  
```
explicit _CRTIMP unsupported_os(_In_z_ const char* _Message) throw();

unsupported_os() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
