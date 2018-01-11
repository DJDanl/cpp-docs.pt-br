---
title: Classe progress_reporter | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- progress_reporter
- PPLTASKS/concurrency::progress_reporter
- PPLTASKS/concurrency::progress_reporter::progress_reporter
- PPLTASKS/concurrency::progress_reporter::report
dev_langs: C++
helpviewer_keywords: progress_reporter class
ms.assetid: b836efab-2d05-4649-b6fa-d15236f1f813
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1dcdba2e5242dcd750eea42b61575ebea921d7b6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[progress_reporter](#ctor)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[relatório](#report)|Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.|  
  
## <a name="remarks"></a>Comentários  
 Esse tipo só está disponível para aplicativos da Windows Store.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `progress_reporter`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppltasks  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>progress_reporter 

```
progress_reporter();
```  
  
##  <a name="report"></a>relatório 

 Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.  
  
```
void report(const _ProgressType& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 A carga de relatório por meio de uma notificação de progresso.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
