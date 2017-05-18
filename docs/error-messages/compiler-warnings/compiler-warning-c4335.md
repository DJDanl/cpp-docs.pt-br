---
title: C4335 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4335
dev_langs:
- C++
helpviewer_keywords:
- C4335
ms.assetid: e66467ad-a10b-4438-8c7c-e8e8d11d39bb
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: dc8436664038d3f53f3a01d5006c41c3d0e4c8f0
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="compiler-warning-c4335"></a>C4335 de aviso do compilador
formato de arquivo Mac detectado: converta o arquivo fonte para formato DOS ou UNIX  
  
 O caractere de terminação de linha da primeira linha de um arquivo de origem é o estilo de Macintosh ('\r') em vez de UNIX ('\n') ou DOS ('\r\n').  
  
 Esse aviso é emitido sempre como um erro.  Consulte [aviso](../../preprocessor/warning.md) pragma para obter informações sobre como desativar esse aviso.  Além disso, esse aviso somente é emitido uma vez por compiland. Portanto, se houver várias `#include` diretivas que especificam os arquivos no formato Macintosh, C4335 só serão emitidos uma vez.  
  
 Uma maneira de gerar arquivos em formato Macintosh é usando o **opções avançadas de salvar** (no **arquivo** menu) no Visual Studio.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4335.  
  
```  
// C4335 expected  
#include "c4335.h"   // assume both include files are in Macintosh format  
#include "c4335_2.h"  
```
