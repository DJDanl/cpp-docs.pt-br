---
title: 'Interface Platform:: IDisposable | Microsoft Docs'
ms.custom: ''
ms.date: 02/03/2017
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::IDisposable
dev_langs:
- C++
helpviewer_keywords:
- Platform::IDisposable Interface
ms.assetid: f4344056-7030-42ed-bc98-b140edffddcd
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 68c5425d5d65acc194287a97068df7da15f37275
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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