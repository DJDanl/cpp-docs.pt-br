---
title: "Habilita&#231;&#227;o internacional | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "globalização [C++], conjuntos de caracteres"
  - "localização [C++], conjuntos de caracteres"
  - "MBCS [C++], ativando"
  - "cadeias de caracteres [C++], habilitação internacional"
  - "Unicode [C++], ativando"
ms.assetid: b077f4ca-5865-40ef-a46e-d9e4d686ef21
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Habilita&#231;&#227;o internacional
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria de código tradicional de 2.0 C e C\+\+ fazer suposições sobre a manipulação de caractere e de cadeia de caracteres que não funcionam bem para aplicativos internacionais.  Quando o MFC e a biblioteca de tempo de execução\) Unicode ou MBCS, ainda há um trabalho para que você faça.  Para guiá\-lo, esta seção explica o significado de “international habilitando” no Visual C\+\+:  
  
-   Unicode e MBCS são habilitados por meio dos tipos de dados portáteis em listas e em tipos de retorno de parâmetro de função de MFC.  Esses tipos são definidos condicional de maneira apropriada, dependendo se sua compilação define o símbolo **\_UNICODE** ou o símbolo **\_MBCS** \(o que significa DBCS\).  As variantes diferentes das bibliotecas de MFC são vinculadas automaticamente com o aplicativo, dependendo de qual desses dois símbolos define sua compilação.  
  
-   O código de biblioteca de classe usar funções portáteis de tempo de execução e outros meios garantir Unicode correto ou o comportamento de MBCS.  
  
-   Você ainda deve tratar determinados tipos de tarefas da internacionalização em seu código:  
  
    -   Use as mesmas funções portáteis de tempo de execução que fazem a MFC inferior portátil um ou outro ambiente.  
  
    -   Faça cadeias de caracteres literais e caracteres inferior portátil um ou outro ambiente, usando a macro de **\_T** .  Para obter mais informações, consulte [Mapeamentos de Genérico\- texto em Tchar.h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md).  
  
    -   Tome precauções ao analisar cadeias de caracteres em MBCS.  Essas precauções não são necessárias em Unicode.  Para obter mais informações, consulte [MBCS programa que dicas](../Topic/MBCS%20Programming%20Tips.md).  
  
    -   Cuidado se você mescla ANSI \(8 bits\) e caracteres \(16 bits\) Unicode em seu aplicativo.  É possível usar caracteres ANSI em algumas partes de seu programa e caracteres Unicode em outro, mas você não pode misturá\-los na mesma cadeia de caracteres.  
  
    -   Não tornam as cadeias de caracteres de duro\- código no seu aplicativo.  Em vez disso, faça\-lhes recursos de STRINGTABLE adicionando ao arquivo de .rc do aplicativo.  Seu aplicativo pode ser localizado sem exigir alterações ou recompilação do código\-fonte.  Para obter mais informações sobre os recursos de STRINGTABLE, consulte [Editor da cadeia de caracteres](../mfc/string-editor.md).  
  
> [!NOTE]
>  O europeu e os conjuntos de caracteres de MBCS têm alguns caracteres, como letras acentuadas, com os códigos de caracteres maiores que 0x80.  Como a maioria de código usa caracteres assinados, esses caracteres maiores que sinal\- 0x80 estendidos são convertidos quando a `int`.  Esse é um problema para a indexação da matriz como os caracteres sinal\- estendidos, sendo negativo, índices fora da matriz.  Os idiomas que usam MBCS, como japonês, também são exclusivos.  Como um caractere pode ter de 1 ou 2 bytes, você sempre deve manipular os dois bytes ao mesmo tempo.  
  
## Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Estratégias de internacionalização](../text/internationalization-strategies.md)