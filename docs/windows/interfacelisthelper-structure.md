---
title: Estrutura InterfaceListHelper | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::InterfaceListHelper
dev_langs: C++
helpviewer_keywords: InterfaceListHelper structure
ms.assetid: 4297e419-c96b-45df-8a00-7568062125ba
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 241613f94431903c7d9e3957cece46844dc67ad9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="interfacelisthelper-structure"></a>Estrutura InterfaceListHelper
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename T0,  
   typename T1 = Nil,  
   typename T2 = Nil,  
   typename T3 = Nil,  
   typename T4 = Nil,  
   typename T5 = Nil,  
   typename T6 = Nil,  
   typename T7 = Nil,  
   typename T8 = Nil,  
   typename T9 = Nil  
>  
struct InterfaceListHelper;  
  
template <  
   typename T0  
>  
struct InterfaceListHelper<T0, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T0`  
 Parâmetro de modelo 0, que é necessário.  
  
 `T1`  
 Parâmetro de modelo 1, que, por padrão, não é especificado.  
  
 `T2`  
 Parâmetro de modelo 2, que, por padrão, não é especificado. O terceiro parâmetro de modelo.  
  
 `T3`  
 Parâmetro de modelo 3, que, por padrão, não é especificado.  
  
 `T4`  
 Parâmetro de modelo 4, que, por padrão, não é especificado.  
  
 `T5`  
 Parâmetro de modelo 5, que, por padrão, não é especificado.  
  
 `T6`  
 Parâmetro de modelo 6, que, por padrão, não é especificado.  
  
 `T7`  
 Parâmetro de modelo 7, que, por padrão, não é especificado.  
  
 `T8`  
 Parâmetro de modelo 8, que, por padrão, não é especificado.  
  
 `T9`  
 Parâmetro de modelo 9, que, por padrão, não é especificado.  
  
## <a name="remarks"></a>Comentários  
 Cria um tipo InterfaceList recursivamente aplicar os argumentos de parâmetro do modelo especificado.  
  
 O modelo InterfaceListHelper usa o parâmetro de modelo `T0` para definir os primeiros dados de membro em uma estrutura InterfaceList e recursivamente aplica o modelo de InterfaceListHelper para quaisquer parâmetros de modelo restantes. InterfaceListHelper é interrompido quando não existem parâmetros modelo restantes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`TypeT`|Um sinônimo para o tipo de InterfaceList.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `InterfaceListHelper`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)