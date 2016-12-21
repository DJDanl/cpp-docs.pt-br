---
title: "Op&#231;&#245;es LINK controladas por compilador | Microsoft Docs"
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
  - "link"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compilador cl.exe [C++], controlando vinculador"
  - "compilador cl.exe [C++], recursos que afetam a vinculação"
  - "ferramenta LINK [C++], opções controladas por compilador"
  - "vinculador [C++], controle de compilador CL"
  - "vinculando [C++], afetado por recursos CL"
ms.assetid: e4c03896-c99c-4599-8502-e0f4bebe69d0
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Op&#231;&#245;es LINK controladas por compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As chamadas do compilador de CL automaticamente VINCULAM a menos que você especifique a opção \/c.  CL O fornece algum controle sobre o vinculador pelas opções de linha de comando e os argumentos.  A tabela a seguir resume os recursos em CL que afetam vincular.  
  
|Especificação de CL|Ação de CL que afeta o LINK|  
|-------------------------|---------------------------------|  
|Qualquer extensão de nome de arquivo diferente .c, .cxx, .cpp, ou .def|Passa um nome de arquivo como entrada para LINK|  
|*filename.def*|\/DEF Passa:*filename.def*|  
|\/F`number`|\/STACK Passa:`number`|  
|*nome de arquivo*\/Fd|\/PDB Passa:*nome do arquivo*|  
|*nome de arquivo*\/Fe|\/OUT Passa:*nome do arquivo*|  
|*nome de arquivo*\/Fm|\/MAP Passa:*nome do arquivo*|  
|\/Gy|Cria empacotou funções \(COMDATs\); permite vincular do papel nível|  
|\/LD|Passa \/DLL|  
|\/LDd|Passa \/DLL|  
|\/link|Passa o restante da linha de comando ao LINK|  
|\/MD ou \/MT|Coloca um nome de biblioteca padrão no arquivo de .obj|  
|\/MDd ou \/MTd|Coloca um nome de biblioteca padrão no arquivo de .obj.  Define o símbolo **\_DEBUG**|  
|\/nologo|Passa \/NOLOGO|  
|\/Zd|Passa \/DEBUG|  
|\/Zi ou \/Z7|Passa \/DEBUG|  
|\/Zl|Omite o nome da biblioteca padrão do arquivo de .obj|  
  
 Para obter mais informações, consulte [Opções do compilador](../../build/reference/compiler-options.md).  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)