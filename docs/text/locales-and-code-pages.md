---
title: "Localidades e páginas de código | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- locales [C++], about locales
- locale IDs [C++]
- locales [C++]
- code pages [C++]
- code pages [C++], dynamically changing
- character sets [C++], code pages
- multibyte code pages [C++]
- character sets [C++], locales
- localization [C++], code pages
- localization [C++], locales
- code pages [C++], locales
- conventions [C++], international character support
ms.assetid: bd937361-b6d3-4c98-af95-beb7c903187b
caps.latest.revision: "9"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8f1134d106949918c7e8984835b86bbc4c6062f8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="locales-and-code-pages"></a>Localidades e páginas de código
Uma identificação de localidade reflete as convenções de locais e o idioma para uma determinada região geográfica. Um idioma específico pode ser falado em mais de um país/região; Por exemplo, português é falada no Brasil, bem como em Portugal. Por outro lado, um país/região pode ter mais de um idioma oficial. Por exemplo, Canadá tem dois idiomas: inglês e francês. Assim, Canadá tem dois locais diferentes: canadense inglês e francês (Canadá). Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários.  
  
 O idioma determina o texto e formatação convenções, enquanto o país/região determina as convenções de locais de dados. Todos os idiomas tem um único mapeamento, representado por páginas de código, que inclui caracteres diferente do alfabeto (por exemplo, sinais de pontuação e números). Uma página de código é um conjunto de caracteres e está relacionada ao idioma. Como tal, um [localidade](../c-runtime-library/locale.md) é uma combinação exclusiva de idioma, país/região e página de código. A configuração de página de localidade e o código pode ser alterada em tempo de execução chamando o [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) função.  
  
 Idiomas diferentes podem usar páginas de código diferentes. Por exemplo, a página de código ANSI 1252 é usada para inglês e a maioria dos idiomas europeus, e a página de código ANSI 932 é usada para Kanji japonês. Praticamente todas as páginas de código compartilham um conjunto para os mais baixos 128 caracteres (0x00 para 0x7F) de caracteres ASCII.  
  
 Qualquer página de código de byte único pode ser representada em uma tabela (com 256 entradas) como um mapeamento de valores de byte para caracteres (incluindo números e pontuação), ou glifos. Qualquer página de código multibyte também pode ser representada como uma tabela muito grande (com entradas de 64K) dos valores de byte duplo para caracteres. Na prática, no entanto, ele são geralmente representados como uma tabela para os primeiros 256 caracteres (byte único) e intervalos para os valores de byte duplo.  
  
 Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).  
  
 A biblioteca de tempo de execução C tem dois tipos de páginas de código interno: localidade e multibyte. Você pode alterar a página de código atual durante a execução do programa (consulte a documentação para o [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) e [setmbcp](../c-runtime-library/reference/setmbcp.md) funções). Além disso, a biblioteca de tempo de execução pode obter e usar o valor da página de código do sistema operacional. No Windows 2000, a página de código do sistema operacional é a página de código "sistema padrão ANSI". Essa página de código é constante para a duração da execução do programa.  
  
 Quando a página de código da localidade muda, o comportamento do conjunto de alterações de funções que ditada pela página de código escolhido dependente de localidade. Por padrão, todas as funções dependentes de localidade começam a execução de uma página de código de localidade exclusiva para a localidade "C". Você pode alterar a página de código da localidade interno (assim como outras propriedades específicas da localidade) ao chamar o `setlocale` função. Uma chamada para `setlocale`(LC_ALL, "") define a localidade para que o indicado pela localidade do usuário do sistema operacional.  
  
 Da mesma forma, quando a página de código multibyte muda, o comportamento das alterações multibyte funções que ditada pela página de código escolhida. Por padrão, todas as funções de multibyte começam a execução de uma página de código multibyte correspondente à página de código padrão do sistema operacional. Você pode alterar a página de código multibyte interno chamando o `_setmbcp` função.  
  
 A função de tempo de execução C `setlocale` define, as alterações ou consultas algumas ou todas as informações de localidade do programa atual. O [wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) rotina é uma versão de caractere largo de `setlocale`; os argumentos e valores de retorno de `_wsetlocale` são cadeias de caracteres do caractere largo.  
  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Benefícios da portabilidade do conjunto de caracteres](../text/benefits-of-character-set-portability.md)