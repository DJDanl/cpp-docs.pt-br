---
title: Programa ATL ou origem de controle e arquivos de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- file types [C++], ATL source and headers
ms.assetid: cb65372f-4880-4007-b582-a52eaa568fd1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3e8e5065cebab002e9c48aef560eb9f2feab67e3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="atl-program-or-control-source-and-header-files"></a>Programa ATL ou origem de controle e arquivos de cabeçalho
Os seguintes arquivos são criados quando você cria um projeto de ATL do Visual Studio, dependendo das opções selecionadas para o projeto que você criar.  
  
 Todos esses arquivos estão localizados no *NomeDoProjeto* diretório e na pasta arquivos de cabeçalho (arquivos. h) ou pasta de arquivos de origem (arquivos. cpp) no Gerenciador de soluções.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|*NomeDoProjeto*. h|O arquivo de inclusão principal que contém as definições de interface de C++ e declarações de GUID dos itens definidos no ATLSample.idl. Ela é gerada novamente pelos MIDL durante a compilação.|  
|*NomeDoProjeto*. cpp|O arquivo de origem do programa principal. Contém a implementação das exportações de DLL para um servidor em processo e a implementação de `WinMain` para um servidor local. Para um serviço, isso adicionalmente implementa todas as funções de gerenciamento de serviço.|  
|Resource.h|O arquivo de cabeçalho do arquivo de recurso.|  
|StdAfx.cpp|Inclui os arquivos Stdafx. H e Atlimpl.cpp.|  
|Stdafx. H|Inclui os arquivos de cabeçalho do ATL.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Programa MFC ou origem de controle e arquivos de cabeçalho](../ide/mfc-program-or-control-source-and-header-files.md)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)