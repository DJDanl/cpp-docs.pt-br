---
title: "Unicode em MFC | Microsoft Docs"
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
  - "cadeias de caracteres [C++], Unicode"
  - "Unicode [C++], ativando"
  - "Unicode [C++], MFC"
  - "caracteres largos, codificação"
  - "caracteres largos, Unicode"
ms.assetid: 1002004b-4113-4380-bf63-e1570934b793
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Unicode em MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O da suporte ao padrão Unicode para codificar caracteres amplos em plataformas do Windows NT, Windows 2000, e Windows XP.  Os aplicativos Unicode não podem realizar em plataformas do Windows 98.  
  
 As versões de Unicode as bibliotecas de MFC são descritas abaixo:  
  
### Bibliotecas de vínculo estáticos  
  
|Versão|Depurar|Descrição|  
|------------|-------------|---------------|  
|UAFXCW.lib, .pdb|UAFXCWD.lib, .pdb|Biblioteca de vínculo estático Unicode MFC|  
  
### Bibliotecas de vínculo dinâmico\) nativa  
  
|Versão|Depurar|Descrição|  
|------------|-------------|---------------|  
|MFC100U.lib, .dbg, def, .dll, .map, .pdb, .prf|MFC100UD.lib, .def, .dll, .map, .pdb|Biblioteca de importação de MFC Unicode \(veja anotações abaixo para a explicação de extensões de arquivo\)|  
|MFCS100U.lib, .pdb|MFCS100UD.lib, .pdb|Biblioteca de importação de MFC Unicode que contém o código que deve ser vinculado estaticamente em um aplicativo ou em uma DLL|  
  
 **Tipos de arquivo**  
  
-   Os arquivos de biblioteca de importação têm a extensão \(.lib\).  
  
-   Os arquivos de biblioteca de vínculo dinâmico\) nativa têm a extensão \(.dll\).  
  
-   Os arquivos de definição de módulo \(.def\) são arquivos de texto que contêm instruções para definir um ou um arquivo .dll.  
  
-   Os arquivos de mapa \(.map\) são arquivos de texto que contêm informações que o vinculador usa ao vincular um programa.  
  
-   Os arquivos de biblioteca \(.lib\) são usados em conjunto com as versões da DLL MFC.  Esses arquivos contêm código que deve ser vinculado estaticamente no aplicativo ou na DLL.  
  
-   Os arquivos de base de dados de programa \(.pdb\) contêm a depuração de projeto e informações de estado.  
  
-   Os arquivos de depuração \(\) .dbg contêm informações \(COFF FPO, e o CodeView\) que o depurador do Visual C\+\+ usa.  
  
 Para obter informações detalhadas sobre as convenções de nomenclatura, consulte [Convenções de nomenclatura de biblioteca](../Topic/Library%20Naming%20Conventions.md).  
  
 Para obter informações sobre como usar Unicode com MFC, consulte [Cadeias de caracteres: Unicode e suporte ao conjunto de caracteres de vários bytes \(MBCS\)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)