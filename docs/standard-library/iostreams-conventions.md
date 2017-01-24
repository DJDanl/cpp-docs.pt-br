---
title: "Conven&#231;&#245;es iostreams | Microsoft Docs"
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
  - "Cabeçalho iostream"
  - "Biblioteca Padrão C++, iostreams"
ms.assetid: 9fe5ded0-37a1-48d1-9671-c81ffc4760ad
caps.latest.revision: 10
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conven&#231;&#245;es iostreams
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os cabeçalhos de iostreams dão suporte a conversões entre o texto e formas codificados, e entrada e saída arquivos externos:  
  
|||  
|-|-|  
|[\<fstream\>](../standard-library/fstream.md)|[\< iomanip \>](../Topic/%3Ciomanip%3E.md)|  
|[\<ios\>](../standard-library/ios.md)|[\<iosfwd\>](../standard-library/iosfwd.md)|  
|[\<iostream\>](../standard-library/iostream.md)|[\< istream \>](../standard-library/istream.md)|  
|[\<ostream\>](../standard-library/ostream.md)|[\<sstream\>](../standard-library/sstream.md)|  
|[\< streambuf \>](../standard-library/streambuf.md)|[\<strstream\>](../standard-library/strstream.md)|  
  
 O uso mais simples de iostreams só requer que você incluir o cabeçalho [\<iostream\>](../standard-library/iostream.md).  Você pode então extrair valores de [cin](../Topic/cin.md) ou de [wcin](../Topic/wcin.md) para ler a entrada padrão.  As regras para fazer isso estão descritas na descrição da classe [Classe basic\_istream](../Topic/basic_istream%20Class.md).  Você também pode inserir valores a [cout](../Topic/cout.md) ou a [wcout](../Topic/wcout.md) para gravar a saída padrão.  As regras para fazer isso estão descritas na descrição da classe [Classe basic\_ostream](../Topic/basic_ostream%20Class.md).  As comuns de controle de formato aos extratores e insertors é gerenciada pela classe [Classe basic\_ios](../Topic/basic_ios%20Class.md).  Manipular essas informações de formato em guisa da extração e de inserir objetos é o município de vários manipuladores.  
  
 Você pode executar as mesmas operações de iostreams em arquivos que você abre por nome, usando as classes declaradas em [\<fstream\>](../standard-library/fstream.md).  Para converter entre iostreams e objetos da classe [Classe basic\_string](../standard-library/basic-string-class.md), use as classes declaradas em [\<sstream\>](../standard-library/sstream.md).  Para fazer o mesmo com cadeias de caracteres C, use as classes declaradas em [\<strstream\>](../standard-library/strstream.md).  
  
 Os cabeçalhos restantes forneçam serviços de suporte, normalmente de interesse direto apenas à maioria dos usuários avançados das classes de iostreams.  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)