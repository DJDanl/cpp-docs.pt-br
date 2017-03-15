---
title: Classe invalid_operation | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::invalid_operation
dev_langs:
- C++
helpviewer_keywords:
- invalid_operation class
ms.assetid: 26ba07dc-fcdf-44cb-b748-a31d35205b52
caps.latest.revision: 19
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
ms.openlocfilehash: 0484e149409b2515f60b2e9aa34a85d5381e05a5
ms.lasthandoff: 02/25/2017

---
# <a name="invalidoperation-class"></a>Classe invalid_operation
Esta classe descreve uma exceção gerada quando ocorre uma operação inválida que não é descrita com mais precisão por outro tipo de exceção lançado pelo tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_operation : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor invalid_operation](#ctor)|Sobrecarregado. Constrói uma `invalid_operation` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Os vários métodos que lançam essa exceção serão geralmente documento sob que circunstâncias eles lança-lo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_operation`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-invalidoperation"></a><a name="ctor"></a>invalid_operation 

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

