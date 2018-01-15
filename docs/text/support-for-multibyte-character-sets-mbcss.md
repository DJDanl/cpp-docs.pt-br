---
title: Suporte a conjuntos de caracteres Multibyte (MBCSs) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: _mbcs
dev_langs: C++
helpviewer_keywords:
- MBCS [C++], about MBCS
- character sets [C++], multibyte
- multibyte characters [C++]
- MBCS [C++]
ms.assetid: b498733c-a1e1-45e3-8f26-d6da3cb5f2dd
caps.latest.revision: "11"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8c6c7bd1477f62e9c78b5e71dfe3723e804283d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="support-for-multibyte-character-sets-mbcss"></a>Suporte para Conjuntos de Caracteres Multibyte (MBCSs)
Conjuntos de caracteres multibyte (MBCSs) são uma abordagem mais antiga para a necessidade de oferecer suporte a conjuntos de caracteres, como japonês e chinês, que não podem ser representado em um único byte. Se você estiver fazendo um novo desenvolvimento, você deve usar Unicode para todas as cadeias de caracteres de texto exceto talvez sistema cadeias de caracteres que não são vistas por usuários finais. MBCS é uma tecnologia herdada e não é recomendado para novo desenvolvimento.  
  
 A implementação de MBCS mais comum é a conjuntos de caracteres de byte duplo (DBCSs). Visual C++ em geral e MFC em particular, é totalmente habilitado para DBCS.  
  
 Para obter exemplos, consulte os arquivos de código de origem do MFC.  
  
 Para plataformas usadas em mercados cujos idiomas usam conjuntos de caracteres grandes, a melhor alternativa para Unicode é MBCS. MFC suporta MBCS usando tipos de dados internationalizable e funções de tempo de execução C. Você deve fazer o mesmo em seu código.  
  
 Em MBCS, os caracteres são codificados em 1 ou 2 bytes. Em caracteres de 2 bytes, o primeiro ou o byte inicial, sinaliza que ele e o byte seguinte devem ser interpretado como um caractere. O primeiro byte vêm de um intervalo de códigos reservado para uso como bytes de cliente potencial. Os intervalos de bytes podem ser lead bytes depende da página de código em uso. Por exemplo, a página de código japonês 932 usa o intervalo de 0x81 por meio de 0x9F como bytes de cliente potencial, mas a página de código coreano 949 usa um intervalo diferente.  
  
 Considere a possibilidade de todos os procedimentos no seu MBCS de programação.  
  
 Caracteres MBCS no ambiente  
 Caracteres MBCS podem aparecer em cadeias de caracteres, como nomes de arquivos e diretórios.  
  
 Operações de edição  
 Operações em aplicativos de MBCS de edição devem operar em caracteres, não em bytes. O cursor não deve dividir um caractere, a tecla de seta à direita deve mover um caractere à direita e assim por diante. **Excluir** deve excluir um caractere; **Desfazer** deve inseri-lo novamente.  
  
 Manipulação de cadeia de caracteres  
 Em um aplicativo que usa MBCS, a manipulação de cadeia de caracteres apresenta problemas especiais. Caracteres de ambas as larguras são mesclados em uma única cadeia de caracteres; Portanto, você deve se lembrar verificar se há lead bytes.  
  
 Suporte à biblioteca de tempo de execução  
 A biblioteca de tempo de execução do C e MFC oferecem suporte a Unicode de byte único e MBCS de programação. Cadeias de caracteres de byte único são processadas com o `str` família de funções de tempo de execução, cadeias de caracteres MBCS são processados com correspondente `_mbs` funções e cadeias de caracteres Unicode são processados com correspondente *wcs* funções. Implementações de função de membro de classe MFC usam funções de tempo de execução portátil que mapeiam sob determinadas circunstâncias, como o normal `str` família de funções, as funções MBCS ou as funções de Unicode, conforme descrito em "MBCS/Unicode portabilidade".  
  
 Portabilidade MBCS/Unicode  
 Usando o arquivo de cabeçalho TCHAR. h, você pode criar Unicode de byte único e MBCS aplicativos sejam as mesmas fontes. TCHAR. h define as macros prefixadas com *_tcs* , que mapeiam para `str`, `_mbs`, ou *wcs* funções, conforme apropriado. Para criar MBCS, defina o símbolo **MBCS**. Para criar o Unicode, defina o símbolo **Unicode**. Por padrão, **MBCS** está definido para aplicativos MFC. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
> [!NOTE]
>  Comportamento será indefinido se você definir ambos **Unicode** e **MBCS**.  
  
 Os arquivos de cabeçalho Mbctype.h e Mbstring.h definem funções específicas de MBCS e macros, que talvez seja necessário em alguns casos. Por exemplo, `_ismbblead` informa se um byte específico em uma cadeia de caracteres é um byte.  
  
 Para portabilidade internacional, o código de seu programa com [Unicode](../text/support-for-unicode.md) ou conjuntos de caracteres de multibyte (MBCSs).  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Habilitar MBCS no meu programa](../text/international-enabling.md)  
  
-   [Habilitar o Unicode e MBCS no meu programa](../text/internationalization-strategies.md)  
  
-   [Use MBCS para criar um programa internacionalizado](../text/mbcs-programming-tips.md)  
  
-   [Ver um resumo de programação de MBCS](../text/mbcs-programming-tips.md)  
  
-   [Saiba mais sobre mapeamentos de texto genérico para a portabilidade de largura de bytes](../text/generic-text-mappings-in-tchar-h.md)  
  
## <a name="see-also"></a>Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Suporte a MBCS no Visual C++](../text/mbcs-support-in-visual-cpp.md)