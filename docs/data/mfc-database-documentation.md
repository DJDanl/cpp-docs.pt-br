---
title: "Documenta&#231;&#227;o do banco de dados MFC | Microsoft Docs"
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
  - "DAO [C++], MFC"
  - "bancos de dados [C++], MFC"
  - "MFC [C++], aplicativos de banco de dados"
  - "ODBC [C++], MFC"
ms.assetid: bb120282-cd0d-4bf4-a27c-93b3501fb3a0
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Documenta&#231;&#227;o do banco de dados MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A documentação MFC para classes de DAO e ODBC consiste em componentes listados na tabela a seguir.  
  
### Documentação da base de dados de MFC  
  
|Para obter a documentação aproximadamente|Consulte|  
|-----------------------------------------------|--------------|  
|Classes para DAO e ODBC|O nome da classe na *referência de MFC*|  
|Funções e macros globais para DAO e ODBC|A função ou o nome da macro *na referência de MFC*|  
|Programação com as classes de MFC ODBC|[ODBC e MFC](../data/odbc/odbc-and-mfc.md)|  
|Notas técnicas para DAO e ODBC|[Notas técnicas de MFC](../mfc/technical-notes-by-category.md)|  
  
##  <a name="_core_mfc_documentation_and_dao_documentation"></a> Documentação MFC e documentação de DAO  
 Toda a documentação MFC para classes de MFC DAO, você encontrará referências para tópicos na documentação do SDK, DAO incluída na documentação online.  Como o MFC encapsula \(ou quebras automáticas\), DAO a documentação de MFC:  
  
-   Se concentra em MFC e como difere da implementação subjacente de DAO.  
  
-   Pontos você a tópicos da Ajuda de DAO SDK para os detalhes subjacentes.  Essas referências cruzadas são exprimidas sempre como o tópico “ *X* na ajuda de DAO”.  
  
-   Indica as diferenças em que o MFC faz de forma diferente da seguinte maneira que DAO são feitas.  O MFC não envolve qualquer DAO.  Por exemplo, MFC o não fornece objetos para a funcionalidade de segurança de DAO.  
  
> [!NOTE]
>  A ajuda do SDK DAO é um arquivo de ajuda separado.  Não há nenhum link de hipertexto desta documentação da ajuda DAO nesta versão do Visual C\+\+.  
  
> [!NOTE]
>  Você pode ter que fazer algum que converte quando você estiver procurando tópicos da ajuda de DAO SDK.  Os exemplos na principal documentação do SDK DAO são gravados na linguagem de programação básica, não C\+\+. DAO \(mas o SDK fornece um conjunto de amostras C\+\+ que não usam o MFC\).  
  
##  <a name="_core_mfc_documentation_and_odbc_documentation"></a> Documentação MFC e documentação do ODBC  
 A documentação MFC para classes de MFC ODBC é organizado de modo diferente.  As classes de MFC ODBC fornecem uma abstração de alto nível que restos no ODBC em vez de um wrapper de ODBC API.  Como consequência, os dois conjuntos de documentação são conectados menor que é a documentação de MFC e DAO define.  A documentação do ODBC C usa 2.0 \- o idioma, que é muito próximo do C\+\+ do que é básico.  
  
## Consulte também  
 [Classes de banco de dados MFC \(ODBC e DAO\)](../Topic/MFC%20Database%20Classes%20\(ODBC%20and%20DAO\).md)   
 [Noções básicas de ODBC](../data/odbc/odbc-basics.md)