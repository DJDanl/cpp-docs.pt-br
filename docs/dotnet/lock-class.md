---
title: Classe Lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a860f79b740e0f34eef33b7a96e0236835f1f6b3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="lock-class"></a>Classe lock
Essa classe automatiza colocar um bloqueio para sincronizar o acesso a um objeto de vários threads.  Quando construído adquire o bloqueio e quando destruído versões de bloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ref class lock;  
```  
  
## <a name="remarks"></a>Comentários  
 `lock` está disponível apenas para objetos CLR e só pode ser usado no código do CLR.  
  
 Internamente, os usos de classe de bloqueio <xref:System.Threading.Monitor> para sincronizar o acesso. Consulte neste tópico para obter mais informações sobre a sincronização.  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\lock.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [lock](../dotnet/lock.md)   
 [Membros lock](../dotnet/lock-members.md)