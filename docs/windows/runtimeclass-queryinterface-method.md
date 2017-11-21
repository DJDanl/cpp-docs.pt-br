---
title: "Método Runtimeclass: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::RuntimeClass::QueryInterface
dev_langs: C++
helpviewer_keywords: QueryInterface method
ms.assetid: 8f01f4a1-3fa2-4a8e-88c6-03629236cb9f
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f6d3684c377cc5d56e6e3da78f5b57983f32c2c5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="runtimeclassqueryinterface-method"></a>Método RuntimeClass::QueryInterface
Recupera um ponteiro para a ID de interface especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
STDMETHOD(  
   QueryInterface  
)  
   (REFIID riid,   
   _Deref_out_ void **ppvObject);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Uma ID de interface.  
  
 `ppvObject`  
 Quando este opereation for concluído, um ponteiro para a interface especificada pelo `riid` parâmetro.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)