---
title: -CLRHEADER | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /CLRHEADER
dev_langs:
- C++
helpviewer_keywords:
- -CLRHEADER dumpbin option
- /CLRHEADER dumpbin option
- CLRHEADER dumpbin option
ms.assetid: cf73424f-4541-47e2-b94e-69b95266ef2a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 73f68c4f73d132254ea64d4b3b3b9f787f3a4b82
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="clrheader"></a>/CLRHEADER
```  
/CLRHEADER file  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `file`  
 Um arquivo de imagem criados com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="remarks"></a>Comentários  
 CLRHEADER exibe informações sobre os cabeçalhos de .NET usado em qualquer programa gerenciado. A saída mostra o local e o tamanho, em bytes, do cabeçalho de .NET e seções de cabeçalho.  
  
 Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.  
  
 Quando /CLRHEADER é usado em um arquivo que foi compilado com /clr, haverá uma **cabeçalho do clr:** seção na saída dumpbin.  O valor de **sinalizadores** indica qual opção /clr foi usada:  
  
-   0 – /clr (a imagem pode conter código nativo).  
  
 Também por meio de programação, você pode verificar se uma imagem foi criada para o common language runtime.  Para obter mais informações, consulte [como: determinar se uma imagem é nativa ou CLR](../../dotnet/how-to-determine-if-an-image-is-native-or-clr.md).  
  
 O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e serão removidas em uma versão futura do compilador. Código que deve ser "pura" ou "segurança" deve ser movido para c#. 
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)