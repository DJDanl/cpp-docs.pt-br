---
title: "Método ClassFactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::ClassFactory::QueryInterface
dev_langs: C++
helpviewer_keywords: QueryInterface method
ms.assetid: 9593881f-4585-4d70-8ca6-b328918d4d6b
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0c4abb408ded66f9768cd1e1476f131b3f82cd30
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="classfactoryqueryinterface-method"></a>Método ClassFactory::QueryInterface
Recupera um ponteiro para a interface especificada pelo parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   QueryInterface  
)(REFIID riid, _Deref_out_ void **ppvObject);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Uma ID de interface.  
  
 `ppvObject`  
 Quando essa operação for concluída, um ponteiro para a interface especificada pelo parâmetro `riid`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que descreve a falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ClassFactory](../windows/classfactory-class.md)