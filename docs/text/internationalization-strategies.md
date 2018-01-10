---
title: "Estratégias de internacionalização | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "8"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6b7ab27bb7a6458efde84451febaeb6f3ef37115
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="internationalization-strategies"></a>Estratégias de internacionalização
Dependendo dos sistemas operacionais de destino e mercados, você tem várias estratégias de internacionalização:  
  
-   Seu aplicativo usa o Unicode e, portanto, é executado no Windows 2000 e Windows NT, mas não no Windows 95 ou Windows 98.  
  
     Você usa a funcionalidade específica do Unicode e todos os caracteres são 16 bits de largura (embora você pode usar caracteres ANSI em algumas partes do seu programa para fins especiais). A biblioteca de tempo de execução do C fornece tipos de dados, funções e macros para programação somente Unicode. MFC é totalmente habilitado para Unicode.  
  
-   Seu aplicativo usa MBCS e pode ser executado em qualquer plataforma Win32.  
  
     Você usar a funcionalidade específica de MBCS. Cadeias de caracteres podem conter caracteres de byte único, caracteres de byte duplo ou ambos. A biblioteca de tempo de execução do C fornece tipos de dados, funções e macros para programação de MBCS. MFC é totalmente habilitado MBCS.  
  
-   O código-fonte para o seu aplicativo é gravado para portabilidade completa — através da recompilação com o símbolo **Unicode** ou o símbolo **MBCS** definido, você pode gerar versões que usam um. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
-   O aplicativo usa uma biblioteca de wrapper para ausente funções Unicode no Windows 95, Windows 98 e Windows ME, como o descrito em [criar um único App Unicode que é executado em ambos os Windows 98 e Windows 2000](http://go.microsoft.com/fwlink/p/?LinkId=250770). Bibliotecas de wrapper também estão disponíveis no mercado.  
  
     Use o totalmente portáteis C Runtime funções, macros e tipos de dados. Flexibilidade do MFC oferece suporte a um dos seguintes métodos.  
  
 O restante desses tópicos se concentrar em escrever código totalmente portáteis que você pode criar como Unicode ou MBCS.  
  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Localidades e páginas de código](../text/locales-and-code-pages.md)