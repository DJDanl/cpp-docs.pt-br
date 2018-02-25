---
title: embedded_idl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- embedded_idl
dev_langs:
- C++
helpviewer_keywords:
- embedded_idl attribute
ms.assetid: f1c1c2e8-3872-4172-8795-8d1288a20452
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b8a93f71da7b7f0819b5a48af1541909037bbe65
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="embeddedidl"></a>embedded_idl
**Específicas do C++**  
  
 Especifica que a biblioteca de tipos é gravada no arquivo .tlh com o código gerado pelo atributo preservado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
embedded_idl[("param")]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `param`  
 Pode ser um destes dois valores:  
  
-   emitidl: informações de tipo importadas de typelib estarão presentes no IDL gerado para o projeto atribuído.  Esse é o padrão e entrará em vigor se você não especificar um parâmetro para `embedded_idl`.  
  
-   no_emitidl: informações de tipo importadas de typelib não estarão presentes no IDL gerado para o projeto atribuído.  
  
## <a name="example"></a>Exemplo  
  
```  
// import_embedded_idl.cpp  
// compile with: /LD  
#include <windows.h>  
[module(name="MyLib2")];  
#import "\school\bin\importlib.tlb" embedded_idl("no_emitidl")  
```  
  
## <a name="remarks"></a>Comentários  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)