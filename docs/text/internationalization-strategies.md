---
title: "Estratégias de internacionalização | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- globalization [C++], character sets
- language-portable code [C++]
- MBCS [C++], internationalization strategies
- Windows API [C++], international programming strategies
- Win32 [C++], international programming strategies
- Unicode [C++], globalizing applications
- character sets [C++], international programming strategies
- localization [C++], character sets
ms.assetid: b09d9854-0709-4b9a-a00c-b0b8bc4199b1
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ead6470bbbeacd43326f4373877eb991e5899116
ms.sourcegitcommit: a5916b48541f804a79891ff04e246628b5f9a24a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/09/2018
---
# <a name="internationalization-strategies"></a>Estratégias de internacionalização
Dependendo dos sistemas operacionais de destino e mercados, você tem várias estratégias de internacionalização:  
  
-   Seu aplicativo usa o Unicode.  
  
     Você usa a funcionalidade específica do Unicode e todos os caracteres são 16 bits de largura (embora você pode usar caracteres ANSI em algumas partes do seu programa para fins especiais). A biblioteca de tempo de execução do C fornece tipos de dados, funções e macros para programação somente Unicode. MFC é totalmente habilitado para Unicode.  
  
-   Seu aplicativo usa MBCS e pode ser executado em qualquer plataforma Win32.  
  
     Você usar a funcionalidade específica de MBCS. Cadeias de caracteres podem conter caracteres de byte único, caracteres de byte duplo ou ambos. A biblioteca de tempo de execução do C fornece tipos de dados, funções e macros para programação de MBCS. MFC é totalmente habilitado MBCS.  
  
-   O código-fonte para o seu aplicativo é gravado para portabilidade completa — através da recompilação com o símbolo **Unicode** ou o símbolo **MBCS** definido, você pode gerar versões que usam um. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
     Use o totalmente portáteis C Runtime funções, macros e tipos de dados. Flexibilidade do MFC oferece suporte a um dos seguintes métodos.  
  
 O restante desses tópicos se concentrar em escrever código totalmente portáteis que você pode criar como Unicode ou MBCS.  
  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Localidades e páginas de código](../text/locales-and-code-pages.md)