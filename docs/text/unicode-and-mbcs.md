---
title: "Unicode e MBCS | Microsoft Docs"
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
  - "MBCS [C++], Unicode"
  - "MFC [C++], conjuntos de caracteres"
  - "conjuntos de caracteres [C++] multibyte"
  - "bibliotecas de tempo de execução [C++], portabilidade de idioma"
  - "conjuntos de caracteres [C++], Unicode"
  - "Unicode [C++], funções de tempo de execução MFC e C"
  - "caracteres multibyte [C++]"
  - "tempo de execução [C++], portabilidade de idioma"
ms.assetid: 677baec6-71b4-4579-94df-64f18bc117c4
caps.latest.revision: 9
caps.handback.revision: 9
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Unicode e MBCS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A Microsoft foundation classifica a biblioteca de \(MFC\), a biblioteca de tempo de execução C para Visual C\+\+, e o ambiente de desenvolvimento do Visual C\+\+ é habilitado para ajudar a sua programação internacional.  Oferecem:  
  
-   Suporte para o padrão Unicode no Windows 2000 \(anteriormente Windows NT\).  Unicode é o padrão atual e deve ser usado sempre que possível.  
  
     Unicode é uma codificação de caracteres de 16 bits, fornecendo codificações suficiente para todos os idiomas.  Todos os caracteres ASCII são incluídos em Unicode como caracteres alargados.  
  
    > [!NOTE]
    >  O padrão Unicode não tem suporte no Windows 95, Windows 98, ou no Windows Millennium Edition.  
  
-   O suporte para um formulário de conjunto de caracteres multibyte \(MBCS\) chamou o conjunto de caracteres de dois bytes \(DBCS\) em todas as plataformas.  
  
     Os caracteres DBCS são compostas de 1 ou 2 bytes.  Alguns intervalos de bytes são reservados para uso como bytes iniciais.  Um byte inicial e especifica que o seguinte byte final compõem um único caractere 2 byte\- todo o servidor.  Você deve manter o controle de bytes que são bytes iniciais.  Em um conjunto específico de multibyte\- caractere, os bytes iniciais estão em um determinado intervalo, como faz os bytes finais.  Quando esses intervalos sobrepostos, pode ser necessário avaliar o contexto para determinar se um byte determinado está funcionando como um byte inicial ou um byte final.  
  
-   Suporte para ferramentas que simplificam a programação de MBCS de aplicativos escritos para mercados internacionais.  
  
     Quando executado em uma versão MBCS\- habilitada do sistema operacional Windows, o sistema de desenvolvimento do Visual C\+\+ — incluindo o publicador, o depurador, e as ferramentas de linha de comando do código\-fonte integrados — MBCS\- é habilitado por meio de.  Para obter mais informações, consulte [Suporte de MBCS no Visual C\+\+](../text/mbcs-support-in-visual-cpp.md).  
  
> [!NOTE]
>  Nesta documentação, MBCS é usado para descrever todo o suporte não Unicode para caracteres multibyte.  No Visual C\+\+, MBCS significa sempre DBCS.  Os conjuntos de caracteres de 2 bytes não há suporte para mais largura.  
  
 Por definição, o conjunto de caracteres ASCII é um subconjunto de todos os conjuntos de multibyte\- caractere.  Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII.  Por exemplo, em cadeias de caracteres ASCII e de MBCS, 1 caractere de **nulo** de byte \(“\\ " 0\) tem o valor 0x00 e indica o caractere nulo sendo encerrado.  
  
## Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Habilitação internacional](../text/international-enabling.md)