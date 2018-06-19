---
title: C4335 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4335
dev_langs:
- C++
helpviewer_keywords:
- C4335
ms.assetid: e66467ad-a10b-4438-8c7c-e8e8d11d39bb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: adb8a7b484ce0946f385c3b2a8669ba1b5ccf0d0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33270503"
---
# <a name="compiler-warning-c4335"></a>C4335 de aviso do compilador
Formato de arquivo Mac detectado: converta o arquivo de origem para o formato DOS ou UNIX  
  
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