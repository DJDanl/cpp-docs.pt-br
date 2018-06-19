---
title: Classe invalid_operation | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- invalid_operation
- CONCRT/concurrency::invalid_operation
- CONCRT/concurrency::invalid_operation::invalid_operation
dev_langs:
- C++
helpviewer_keywords:
- invalid_operation class
ms.assetid: 26ba07dc-fcdf-44cb-b748-a31d35205b52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fa6d1152bb1f9a9c5671d1f7f0cdf0e426c02575
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33696089"
---
# <a name="invalidoperation-class"></a>Classe invalid_operation
Esta classe descreve uma exceção gerada quando uma operação inválida é executada com mais precisão não é descrita por outro tipo de exceção lançado pelo tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_operation : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[invalid_operation](#ctor)|Sobrecarregado. Constrói uma `invalid_operation` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Os vários métodos que lançam essa exceção serão geralmente documento sob quais circunstâncias eles lançará-lo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_operation`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> invalid_operation 

 Constrói uma `invalid_operation` objeto.  
  
```
explicit _CRTIMP invalid_operation(_In_z_ const char* _Message) throw();

invalid_operation() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
