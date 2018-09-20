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
ms.openlocfilehash: 02133e6b9d884fa8e0a175dd01845035ec8b96a7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435942"
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
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)