---
title: Programa ATL ou origem de controle e arquivos de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- file types [C++], ATL source and headers
ms.assetid: cb65372f-4880-4007-b582-a52eaa568fd1
ms.openlocfilehash: 15d49cf984e45feeaad454de13c4ab37622000a4
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446575"
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

[Arquivo tipos criados para o Visual C++ projetos](file-types-created-for-visual-cpp-projects.md)<br>
[Programa MFC ou origem de controle e arquivos de cabeçalho](mfc-program-or-control-source-and-header-files.md)<br>
[Projetos CLR](files-created-for-clr-projects.md)
