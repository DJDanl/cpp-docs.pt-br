---
title: Programa ATL ou arquivos de cabeçalho e de origem de controle | Microsoft Docs
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
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33321620"
---
# <a name="atl-program-or-control-source-and-header-files"></a>Programa ATL ou origem de controle e arquivos de cabeçalho
Os arquivos a seguir são criados quando você cria um projeto ATL no Visual Studio, dependendo das opções selecionadas para o projeto criado.  
  
 Todos esses arquivos estão localizados no diretório *Nome_do_projeto* e na pasta Arquivos de Cabeçalho (arquivos .h) ou na pasta Arquivos de Origem (arquivos .cpp) do Gerenciador de Soluções.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|*Nome_do_projeto*.h|O arquivo de inclusão principal que contém as definições de interface C++ e as declarações de GUID dos itens definidos em ATLSample.idl. Ele é regenerado pela MIDL durante a compilação.|  
|*Nome_do_projeto*.cpp|O arquivo de origem do programa principal. Ele contém a implementação das exportações da DLL para um servidor em processo e a implementação de `WinMain` para um servidor local. Para um serviço, isso implementa também todas as funções de gerenciamento de serviços.|  
|Resource.h|O arquivo de cabeçalho do arquivo de recurso.|  
|StdAfx.cpp|Inclui os arquivos StdAfx.h e Atlimpl.cpp.|  
|StdAfx.h|Inclui os arquivos de cabeçalho ATL.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Programa MFC ou arquivos de cabeçalho e de origem de controle](../ide/mfc-program-or-control-source-and-header-files.md)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)