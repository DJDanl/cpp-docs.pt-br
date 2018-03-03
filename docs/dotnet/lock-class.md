---
title: Classe Lock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- msclr::lock
- msclr.lock
- lock
dev_langs:
- C++
helpviewer_keywords:
- lock class
ms.assetid: 5123edd9-6aed-497d-9a0b-f4b6d6c0d666
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c2f2a8e371803d33a2c42508ec595681ada3bab8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lock-class"></a>Classe lock
Essa classe automatiza colocar um bloqueio para sincronizar o acesso a um objeto de vários threads.  Quando construído adquire o bloqueio e quando destruído versões de bloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ref class lock;  
```  
  
## <a name="remarks"></a>Comentários  
 `lock`está disponível apenas para objetos CLR e só pode ser usado no código do CLR.  
  
 Internamente, os usos de classe de bloqueio <xref:System.Threading.Monitor> para sincronizar o acesso. Consulte neste tópico para obter mais informações sobre a sincronização.  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\lock.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [bloqueio](../dotnet/lock.md)   
 [Membros lock](../dotnet/lock-members.md)