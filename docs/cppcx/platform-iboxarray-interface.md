---
title: 'Interface Platform:: iboxarray | Microsoft Docs'
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- VCCORLIB/Namespace not found::Platform
- VCCORLIB/Namespace not found::Platform::Value
dev_langs:
- C++
helpviewer_keywords:
- Platform::IBoxArray
ms.assetid: 6cd82c9e-4230-4147-9edb-7a652875dbf1
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f52f8c95851ec80df41fe9f0838345cf46876227
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="platformiboxarray-interface"></a>Interface Platform::IBoxArray
`IBoxArray` é o wrapper para arrays de tipos de valores que são transmitidos pela interface binária de aplicativo (ABI) ou armazenados em coleções de elementos `Platform::Object^` como aqueles em controles XAML.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <typename T>  
interface class IBoxArray  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do valor demarcado em cada elemento da matriz.  
  
### <a name="remarks"></a>Comentários  
 `IBoxArray` é o C + + nome CX para `Windows::Foundation::IReferenceArray`.  
  
### <a name="members"></a>Membros  
 A interface `IBoxArray` herda da interface `IValueType` . `IBoxArray` também tem estes membros:  
  
|Método|Descrição|  
|------------|-----------------|  
|[Valor](#value)|Retorna a matriz não demarcada que foi armazenadas anteriormente nessa instância de `IBoxArray` .|  

## <a name="value"></a> IBoxArray::Value Property
Retorna o valor que foi originalmente armazenado neste objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
property T Value {T get();}  
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do valor demarcado.  
  
### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno  
 Retorna o valor que foi originalmente armazenado neste objeto.  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo, consulte [Boxing](../cppcx/boxing-c-cx.md).  
  
  
## <a name="see-also"></a>Consulte também  
 [Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)