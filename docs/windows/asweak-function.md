---
title: "Função AsWeak | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::AsWeak
dev_langs: C++
helpviewer_keywords: AsWeak function
ms.assetid: a6f10cfc-c1d6-4761-adb9-1a119cc99913
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 36cf91b969ac1c180f7060c2518e626a22a08284
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="asweak-function"></a>Função AsWeak
Recupera uma referência fraca a uma instância especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename T  
>  
HRESULT AsWeak(  
   _In_ T* p,  
   _Out_ WeakRef* pWeak  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um ponteiro para o tipo de parâmetro `p`.  
  
 `p`  
 Uma instância de um tipo.  
  
 `pWeak`  
 Quando essa operação for concluída, um ponteiro para uma referência fraca a parâmetro `p`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK, se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica a causa da falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)