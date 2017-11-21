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
ms.openlocfilehash: c73a30779bf85e39ca97d0e6f4979c070de4e00c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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