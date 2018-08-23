---
title: raw_dispinterfaces | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- raw_dispinterfaces
dev_langs:
- C++
helpviewer_keywords:
- raw_dispinterfaces attribute
ms.assetid: f762864d-29bf-445b-825a-ba7b29a95409
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 093c994de24b947c53bfc19d33213e77f3ec2593
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42541522"
---
# <a name="rawdispinterfaces"></a>raw_dispinterfaces
**Específico do C++**  
  
Instrui o compilador a gerar funções wrapper de nível baixo para dispinterface métodos e propriedades que chamam `IDispatch::Invoke` e retornar o código de erro HRESULT.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_dispinterfaces  
```  
  
## <a name="remarks"></a>Comentários  
 
Se esse atributo não for especificado, apenas os wrappers de alto nível serão gerados, que lançam exceções de C++ em caso de falha.  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)