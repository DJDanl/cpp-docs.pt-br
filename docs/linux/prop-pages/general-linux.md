---
title: Propriedades gerais (projeto C++ do Linux)
description: Descreve as propriedades de projeto do Linux que podem ser definidas no Visual Studio na página Propriedades gerais.
ms.date: 10/14/2020
ms.assetid: 56c800a9-3df9-4196-87b2-81adb00e4767
ms.openlocfilehash: 9d6cb4ca51eff799788776c2641364939d438d63
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176184"
---
# <a name="general-properties-linux-c"></a>Propriedades gerais (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

| Propriedade | Descrição |
|--|--|
| Diretório de saída | Especifica um caminho relativo para o diretório do arquivo de saída. Ele pode incluir variáveis de ambiente. |
| Diretório intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário. Ele pode incluir variáveis de ambiente. |
| Nome de destino | Especifica o nome do arquivo que este projeto gera. |
| Extensão de destino | Especifica a extensão de arquivo (por exemplo, `.a` ) que este projeto gera. |
| Extensões a serem excluídas na limpeza | Especificação de curinga delimitado por ponto e vírgula para os arquivos no diretório intermediário a serem excluídos na limpeza ou na recompilação. |
| Arquivo de log de build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado. |
| Conjunto de ferramentas da plataforma | Especifica o conjunto de ferramentas usado para compilar a configuração atual. Se não estiver definido, o conjunto de ferramentas padrão será usado. |
| Caminho completo do WSL *. exe | **Visual Studio 2019 versão 16,1** Caminho completo para o executável do subsistema do Windows para Linux (WSL) usado para compilar e depurar. |
| Computador de Build Remoto | Exibe o computador de destino ou o dispositivo a ser usado para compilação remota, implantação e depuração. Você pode adicionar ou editar uma conexão de computador de destino usando **ferramentas**  >  **Opções**  >  Gerenciador de conexões**entre plataformas**  >  **Connection Manager**.<br /> **Visual Studio 2019 versão 16,1** Você pode especificar um computador diferente para depuração na página de [depuração](debugging-linux.md) . |
| Diretório Raiz de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto. |
| Diretório de Projeto de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto para o projeto. |
| Diretório de implantação remota | **Visual Studio 2019 versão 16,1** Especifica o caminho do diretório no computador remoto ou dispositivo para implantar o projeto. |
| Habilitar compilação incremental | **Visual Studio 2019 versão 16,7** Especifica se as compilações incrementais devem ser efetuadas usando o sistema de compilação [ninja](https://ninja-build.org/) . As compilações geralmente serão mais rápidas para a maioria dos projetos com essa configuração habilitada. |
| Diretórios de inclusão de cópia remota | **Visual Studio 2019 versão 16,5**  Uma lista de diretórios para copiar recursivamente do destino do Linux. Essa propriedade afeta a cópia de cabeçalho remoto para o IntelliSense, mas não a compilação. Ele pode ser usado quando o **IntelliSense usa padrões do compilador** definido como false. Use **diretórios de inclusão adicionais** na guia geral C/C++ para especificar diretórios de inclusão adicionais para usar tanto para IntelliSense quanto para compilação. |
| Cópia remota de diretórios de exclusão | **Visual Studio 2019 versão 16,5** Uma lista de diretórios que *não* deve ser copiada do destino do Linux. Normalmente, essa propriedade é usada para remover subdiretórios dos diretórios de inclusão. |
| O IntelliSense usa padrões do compilador | **Visual Studio 2019 versão 16,5** Se é para consultar o compilador referenciado por este projeto para sua lista padrão de locais de inclusão. Esses locais são adicionados automaticamente à lista de diretórios remotos a serem copiados. Defina essa propriedade como false somente se o compilador não der suporte a parâmetros do tipo gcc. Os compiladores gcc e Clang dão suporte a consultas para os diretórios de inclusão (por exemplo, `g++ -x c++ -E -v -std=c++11` ). |
| Tipo de Configuração | Especifica o tipo de saída que essa configuração gera, como: **biblioteca dinâmica (. so)**, **biblioteca estática (. a)**, **aplicativo (. out)** e **makefile** |
| Uso de STL | Especifica qual biblioteca padrão do C++ usar para essa configuração, como: **biblioteca C++ padrão GNU compartilhada**ou **biblioteca C++ padrão GNU estática (-static)** |

::: moniker-end
