---
title: 'Classe Platform:: ValueType | Microsoft Docs'
ms.custom: 
ms.date: 02/03/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: VCCORLIB/Platform::ValueType::ToString
dev_langs: C++
helpviewer_keywords: Platform::ValueType Class
ms.assetid: 79aa8754-b140-4974-a5b1-be046938a10a
caps.latest.revision: "5"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.openlocfilehash: 2f39c4f74e439fe50c13aabe2a07024536058be4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="platformvaluetype-class"></a>Classe Platform::ValueType
A classe base para instâncias de tipos de valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public ref class ValueType : Object  
```  
  
## <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|[ValueType::ToString](#tostring)|Retorna uma representação de cadeia de caracteres do objeto. Herdado de [Platform](../cppcx/platform-object-class.md).|  
  
### <a name="remarks"></a>Comentários  
 A classe ValueType é usada para construir os tipos de valor. ValueType é derivado de Object, que tem membros básicos. No entanto, o compilador desanexa os membros básicos dos tipos de valor que são derivados da classe ValueType. O compilador anexa novamente esses membros básicos quando um tipo de valor é convertido.  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd  

## <a name="tostring"></a>Método ValueType::ToString
Retorna uma representação de cadeia de caracteres do objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Platform::String ToString();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um Platform:: String que representa o valor.  
    
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)