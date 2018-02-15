---
title: Classe de valor sizet | Microsoft Docs
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- VCCORLIB/PlatformSizeT::SizeT constructor
dev_langs:
- C++
helpviewer_keywords:
- Platform::SizeT Struct
ms.assetid: 0803612c-8ba1-430c-9b7b-1bebae88608d
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5f3646c07d5f351ac0c357fa99efc0148e643271
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="platformsizet-value-class"></a>Platform::classe de valor SizeT
Representa o tamanho de um objeto. SizeT é um tipo de dados sem sinal.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public ref class SizeT sealed : ValueType  
```  
  
### <a name="members"></a>Membros  
  
|Membro|Descrição|  
|------------|-----------------|  
|[Construtor SizeT::SizeT](#ctor)|Inicializa uma nova instância da classe com o valor especificado.|  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd  

 ## <a name="ctor"></a>  Construtor sizet:: Sizet
Inicializa uma nova instância de SizeT com o valor especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
SizeT( uint32 value1 );   SizeT( void* value2 );  
```  
  
### <a name="parameters"></a>Parâmetros  
 value1  
 Um valor de 32 bits sem sinal.  
  
 value2  
 Ponteiro para um valor de 32 bits sem sinal.  
  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)