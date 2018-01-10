---
title: 'Interface Platform:: IDisposable | Microsoft Docs'
ms.custom: 
ms.date: 02/03/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: VCCORLIB/Platform::IDisposable
dev_langs: C++
helpviewer_keywords: Platform::IDisposable Interface
ms.assetid: f4344056-7030-42ed-bc98-b140edffddcd
caps.latest.revision: "4"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: db500bc5a205b97ba49d92356d2e878be3e10caf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="platformidisposable-interface"></a>Interface Platform::IDisposable
Usada para liberar recursos não gerenciados.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public interface class IDisposable  
```  
  
## <a name="attributes"></a>Atributos  
 **GuidAttribute**("de0cbaea-8065-4a45-b196-c9d443f9bab3")  
  
 **VersionAttribute**(NTDDI_WIN8)  
  
### <a name="members"></a>Membros  
 A interface IDisposable herda da interface IUnknown. IDisposable também tem os seguintes tipos de membros:  
  
 **Métodos**  
  
 A interface IDisposable tem os métodos descritos a seguir.  
  
|Método|Descrição|  
|------------|-----------------|  
|Dispose|Usada para liberar recursos não gerenciados.|  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform