---
title: -CLRHEADER | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /CLRHEADER
dev_langs: C++
helpviewer_keywords:
- -CLRHEADER dumpbin option
- /CLRHEADER dumpbin option
- CLRHEADER dumpbin option
ms.assetid: cf73424f-4541-47e2-b94e-69b95266ef2a
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d8ab1617cffd7560ab47d69f7304df0c76b661eb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
-   1-- /CLR: Safe (a imagem é MSIL somente, poderá ser executado em qualquer plataforma CLR e possivelmente verificável).  
  
-   3 – /clr: pure (imagem é MSIL somente, mas só poderá ser executado em x86 plataformas).  
  
 Também por meio de programação, você pode verificar se uma imagem foi criada para o common language runtime.  Para obter mais informações, consulte [como: determinar se uma imagem é nativa ou CLR](../../dotnet/how-to-determine-if-an-image-is-native-or-clr.md).  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)