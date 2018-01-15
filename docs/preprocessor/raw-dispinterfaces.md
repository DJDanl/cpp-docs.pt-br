---
title: raw_dispinterfaces | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: raw_dispinterfaces
dev_langs: C++
helpviewer_keywords: raw_dispinterfaces attribute
ms.assetid: f762864d-29bf-445b-825a-ba7b29a95409
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3d92c6940c4eabc83143ce1054604ae4648347d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rawdispinterfaces"></a>raw_dispinterfaces
**Específicas do C++**  
  
 Informa ao compilador para gerar funções de invólucro de baixo nível para dispinterface métodos e propriedades que chamam **IDispatch:: Invoke** e retornar o `HRESULT` código de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_dispinterfaces  
```  
  
## <a name="remarks"></a>Comentários  
 Se esse atributo não for especificado, apenas os wrappers de alto nível serão gerados, que lançam exceções de C++ em caso de falha.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)