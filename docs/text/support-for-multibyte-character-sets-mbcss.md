---
title: "Suporte para Conjuntos de Caracteres Multibyte (MBCSs) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_mbcs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conjunto de caracteres [C++], multibyte"
  - "MBCS [C++]"
  - "MBCS [C++], sobre MBCS"
  - "caracteres multibyte [C++]"
ms.assetid: b498733c-a1e1-45e3-8f26-d6da3cb5f2dd
caps.latest.revision: 11
caps.handback.revision: 11
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Suporte para Conjuntos de Caracteres Multibyte (MBCSs)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conjuntos de caracteres multibyte \(MBCSs\) são uma abordagem mais antiga para a necessidade de oferecer suporte a conjuntos de caracteres, como japonês e chinês, que não podem ser representados em um único byte.  Se você estiver fazendo novo desenvolvimento, você deve usar Unicode para todas as cadeias de caracteres de texto exceto talvez sistema cadeias de caracteres que não são vistas pelos usuários finais.  MBCS é uma tecnologia herdada e não é recomendado para nova implantação.  
  
 A implementação de MBCS mais comum é a conjuntos de caracteres de byte duplo \(DBCSs\).  Visual C\+\+ em geral e o MFC em especial, é totalmente habilitado para DBCS.  
  
> [!WARNING]
>  No Visual Studio 2013 e posterior, as bibliotecas MFC para codificação de caracteres de vários byle \(MBCS\) será fornecido como um complemento ao Visual Studio e estará disponível gratuitamente para os clientes do Visual Studio \(apenas para edições Professional e Enterprise\) no site de download do MSDN.  
>   
>  As bibliotecas exigem cerca de 440 MB na unidade de disco e a instalação inclui todas as versões localizadas das bibliotecas.  Você pode instalá\-lo em qualquer computador no qual edição Enterprise, Professional ou comunidade do Visual Studio está instalada e que tem o recurso MFC em caixa habilitado.  
>   
>  Se você desinstalar ou reparar o Visual Studio, as bibliotecas MBCS também serão desinstaladas ou reparadas.  No entanto, se você simplesmente remover o recurso do MFC, as bibliotecas MBCS permanecerá em seu sistema.  Se você reparar as bibliotecas MBCS, Visual Studio não é modificado de alguma forma.  
>   
>  Os pacotes redistribuíveis do Visual Studio 2013 e posterior ainda incluirá as DLLs do MFC MBCS.  Não há etapas adicionais são necessários para redistribuir DLLs para seus clientes.  
  
 Para obter exemplos, consulte os arquivos de código de origem do MFC.  
  
 Para plataformas usadas em mercados cujos idiomas usam conjuntos de caracteres grandes, a melhor alternativa para Unicode é MBCS.  MFC suporta MBCS usando tipos de dados internationalizable e funções de tempo de execução C.  Você deve fazer o mesmo em seu código.  
  
 Em MBCS, os caracteres são codificados em 1 ou 2 bytes.  Em caracteres de 2 bytes, o primeiro ou o byte inicial, sinaliza que ele e o byte seguinte devem ser interpretado como um caractere.  O primeiro byte vem de um intervalo de códigos reservado para uso como líder de bytes.  Os intervalos de bytes podem ser líder bytes depende da página de código em uso.  Por exemplo, a página de código japonesa 932 usa o intervalo de 0x81 por meio de 0x9F como líder de bytes, mas a página de código coreano 949 usa um intervalo diferente.  
  
 Considere as seguintes em sua programação de MBCS.  
  
 Caracteres MBCS no ambiente  
 Caracteres MBCS podem aparecer em cadeias de caracteres, como nomes de arquivos e diretórios.  
  
 Operações de edição  
 Edição de operações em aplicativos de MBCS deve operar em caracteres, não em bytes.  O cursor não deve dividir um caractere, a tecla de seta para a direita deve mover um caractere à direita e assim por diante.  **Excluir** deve excluir um caractere; **Desfazer** deve inseri\-lo novamente.  
  
 Manipulação de cadeia de caracteres  
 Em um aplicativo que usa MBCS, manipulação de cadeia de caracteres apresenta problemas especiais.  Caracteres de ambas as larguras são combinados em uma única cadeia de caracteres; Portanto, você deve se lembrar ao procurar o líder de bytes.  
  
 Suporte à biblioteca de tempo de execução  
 A biblioteca em tempo de execução C e MFC oferecem suporte a Unicode de byte único e MBCS de programação.  Cadeias de caracteres de byte único são processadas com o `str` família de funções de tempo de execução, cadeias de caracteres MBCS são processados com correspondente `_mbs` funções e cadeias de caracteres Unicode são processados com correspondente *wcs* funções.  Implementações de função de membro de classe MFC usam funções de tempo de execução portáteis que são mapeados, sob determinadas circunstâncias, como o normal `str` família de funções, as funções MBCS ou as funções do Unicode, conforme descrito em "MBCS\/Unicode portabilidade."  
  
 Portabilidade MBCS\/Unicode  
 Usando o arquivo de cabeçalho TCHAR, você pode criar um byte, MBCS e Unicode aplicativos as mesmas fontes.  TCHAR. h define as macros prefixadas com *\_tcs* , que mapeiam para `str`, `_mbs`, ou *wcs* funções, conforme apropriado.  Para criar MBCS, definir o símbolo **MBCS**.  Para criar o Unicode, definir o símbolo **Unicode**.  Por padrão, **MBCS** está definido para aplicativos MFC.  Para obter mais informações, consulte [mapeamentos de texto genérico em TCHAR. h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md).  
  
> [!NOTE]
>  Comportamento é indefinido se você definir ambos **Unicode** e **MBCS**.  
  
 Os arquivos de cabeçalho Mbctype.h e Mbstring.h definem funções específicas de MBCS e macros, que pode ser necessário em alguns casos.  Por exemplo, `_ismbblead` informa se um byte específico em uma cadeia de caracteres é um byte.  
  
 Para portabilidade internacional, de seu programa com código [Unicode](../text/support-for-unicode.md) ou conjuntos de caracteres multibyte \(MBCSs\).  
  
## O que você deseja fazer?  
  
-   [Habilitar MBCS em meu programa](../text/international-enabling.md)  
  
-   [Habilitar Unicode e MBCS em meu programa](../text/internationalization-strategies.md)  
  
-   [Use MBCS para criar um programa internacionalizado](../Topic/MBCS%20Programming%20Tips.md)  
  
-   [Ver um resumo da programação de MBCS](../Topic/MBCS%20Programming%20Tips.md)  
  
-   [Aprender sobre mapeamentos de texto genérico para portabilidade de largura de byte](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md)  
  
## Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Suporte de MBCS no Visual C\+\+](../text/mbcs-support-in-visual-cpp.md)