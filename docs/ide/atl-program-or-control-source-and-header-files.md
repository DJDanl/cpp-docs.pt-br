---
title: "Programa ATL ou origem de controle e arquivos de cabe&#231;alho | Microsoft Docs"
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
  - "tipos de arquivo [C++], Origem e cabeçalhos ATL"
ms.assetid: cb65372f-4880-4007-b582-a52eaa568fd1
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Programa ATL ou origem de controle e arquivos de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os seguintes arquivos são criados quando você cria um projeto ATL no Visual Studio, dependendo das opções selecionadas para o projeto que você cria.  
  
 Todos esses arquivos estão localizados na  *nomedoprojeto* e diretório, na pasta arquivos de cabeçalho \(arquivos. h\) ou a pasta arquivos de origem \(arquivos. cpp\) no Solution Explorer.  
  
|File name|Descrição|  
|---------------|---------------|  
|*Nomedoprojeto*. h|O arquivo de inclusão de principal contendo as definições de interface do C\+\+ e declarações de GUID dos itens definidos no ATLSample.idl.  Ele é regenerado pelo MIDL durante a compilação.|  
|*Nomedoprojeto*. cpp|O arquivo de origem do programa principal.  Ele contém a implementação de exportações da sua DLL para um servidor em processo e a implementação de `WinMain` para um servidor local.  Para um serviço, além disso implementa todas as funções de gerenciamento de serviço.|  
|Resource.h|O arquivo de cabeçalho para o arquivo de recurso.|  
|Stdafx|Inclui os arquivos stdafx. H e Atlimpl.cpp.|  
|Stdafx. H|Inclui os arquivos de cabeçalho do ATL.|  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Programa MFC ou origem de controle e arquivos de cabeçalho](../ide/mfc-program-or-control-source-and-header-files.md)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)