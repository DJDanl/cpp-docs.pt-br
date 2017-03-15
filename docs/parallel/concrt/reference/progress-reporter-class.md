---
title: Classe progress_reporter | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ppltasks/concurrency::progress_reporter
dev_langs:
- C++
helpviewer_keywords:
- progress_reporter class
ms.assetid: b836efab-2d05-4649-b6fa-d15236f1f813
caps.latest.revision: 11
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
ms.openlocfilehash: c6b4dfee5b5f9df98a36fcdac116182ced4cbe30
ms.lasthandoff: 02/25/2017

---
# <a name="progressreporter-class"></a>Classe progress_reporter
A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename _ProgressType>
class progress_reporter;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_ProgressType`  
 O tipo de carga de cada notificação de andamento relatada pelo relator de andamento.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor progress_reporter](#ctor)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método de relatório](#report)|Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.|  
  
## <a name="remarks"></a>Comentários  
 Esse tipo só está disponível para aplicativos da Windows Store.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `progress_reporter`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-progressreporter"></a><a name="ctor"></a>progress_reporter 

```
progress_reporter();
```  
  
##  <a name="a-namereporta-report"></a><a name="report"></a>relatório 

 Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.  
  
```
void report(const _ProgressType& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 A carga de relatório por meio de uma notificação de progresso.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

