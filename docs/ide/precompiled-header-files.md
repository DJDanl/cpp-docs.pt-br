---
title: "Arquivos de cabe&#231;alho pr&#233;-compilado | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - ""stdafx.h""
  - "stdafx.h"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "stdafx.h"
  - "Arquivos PCH, descrições de arquivos"
  - "arquivos. pch, descrições de arquivos"
  - "arquivos de cabeçalho pré-compilado, descrições de arquivos"
  - "stdafx.cpp"
ms.assetid: 8228d87a-5609-41f3-9697-b16094c000e5
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos de cabe&#231;alho pr&#233;-compilado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esses arquivos são usados para criar um arquivo de cabeçalho pré\-compilado *NomeDoProjeto*Stdafx.obj de arquivos. pch e a tipos pré\-compilado.  
  
 Esses arquivos estão localizados na *NomeDoProjeto* directory. No Solution Explorer, Stdafx. h está na pasta arquivos de cabeçalho e Stdafx está localizado na pasta arquivos de origem.  
  
|Nome do arquivo|Descrição|  
|---------------------|---------------|  
|Stdafx. h|Um arquivo de inclusão para arquivos de inclusão padrão do sistema e arquivos específicos do projeto que são usados com freqüência, mas raramente são alterados.<br /><br /> Você não deve definir ou cancele qualquer as macros \_AFX\_NO\_XXX Stdafx. h; Consulte o artigo da Base de dados de Conhecimento "PRB: problemas ao definir \_AFX\_NO\_XXX". Você pode encontrar artigos da Base de dados de Conhecimento na biblioteca MSDN ou em [http:\/\/ support.microsoft.com\/](http://%20support.microsoft.com/).|  
|Stdafx|Contém a política de pré\-processador `#include "stdafx.h"` e adiciona incluir arquivos para tipos pré\-compilado. Arquivos pré\-compilado de qualquer tipo, incluindo arquivos de cabeçalho, oferecem suporte a tempos de compilação, restringindo compilação apenas para os arquivos que precisam dele. Depois que o projeto é criado na primeira vez, você observará tempos de compilação muito mais rápido em compilações subseqüentes devido à presença de arquivos de cabeçalho pré\-compilado.|  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Como especificar propriedades do projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md)