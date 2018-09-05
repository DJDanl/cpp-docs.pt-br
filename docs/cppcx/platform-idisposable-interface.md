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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f3899c25d71ad08cc058280271080c19d11222ed
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43751002"
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
 **Mínimo de cliente com suporte:** Windows 8  
  
 **Mínimo de servidor com suporte:** Windows Server 2012  
  
 **Namespace:** Platform