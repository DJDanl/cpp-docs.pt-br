---
title: Propriedades gerais (projeto C++ do Linux)
description: Descreve as propriedades de projeto do Linux que podem ser definidas no Visual Studio na página Propriedades gerais.
ms.date: 01/14/2020
ms.assetid: 56c800a9-3df9-4196-87b2-81adb00e4767
ms.openlocfilehash: 6d598e9d52037d709cba87d98ad375455d8c00b0
ms.sourcegitcommit: 49e4fb3e0300fe86c814130661f1bf68b16e72e2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/15/2020
ms.locfileid: "76031339"
---
# <a name="general-properties-linux-c"></a>Propriedades gerais (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

propriedade | Descrição | Opções
--- | ---| ---
Diretório de Saída | Especifica um caminho relativo para o diretório do arquivo de saída. Ele pode incluir variáveis de ambiente.
Diretório intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário. Ele pode incluir variáveis de ambiente.
Nome do Destino | Especifica o nome do arquivo que este projeto gera.
Extensão de Destino | Especifica a extensão de arquivo (por exemplo, `.a`) que este projeto gera.
Extensões a serem excluídas na limpeza | Especificação de curinga delimitado por ponto e vírgula para os arquivos no diretório intermediário a serem excluídos na limpeza ou na recompilação.
Arquivo de log de build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado.
Conjunto de ferramentas da plataforma | Especifica o conjunto de ferramentas usado para compilar a configuração atual. Se não estiver definido, o conjunto de ferramentas padrão será usado.
Computador de Build Remoto | O computador de destino ou o dispositivo a ser usado para compilação remota, implantação e depuração. **Visual Studio 2019 versão 16,1** Você pode especificar um computador diferente para depuração na página de [depuração](debugging-linux.md) .
Diretório Raiz de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto.
Diretório de Projeto de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto para o projeto.
Diretório de implantação remota | **Visual Studio 2019 versão 16,1** Especifica o caminho do diretório no computador remoto ou dispositivo para implantar o projeto.
Diretórios de inclusão de cópia remota | **Visual Studio 2019 versão 16,5**  Uma lista de diretórios para copiar recursivamente do destino do Linux. Essa propriedade afeta a cópia de cabeçalho remoto para o IntelliSense, mas não a compilação. Ele pode ser usado quando o **IntelliSense usa padrões do compilador** definido como false. Use **diretórios de inclusão adicionais** na guia CC++ /geral para especificar diretórios de inclusão adicionais para usar tanto para IntelliSense quanto para compilação.
Cópia remota de diretórios de exclusão | **Visual Studio 2019 versão 16,5** Uma lista de diretórios que *não* deve ser copiada do destino do Linux. Normalmente, essa propriedade é usada para remover subdiretórios dos diretórios de inclusão.
O IntelliSense usa padrões do compilador | **Visual Studio 2019 versão 16,5** Se é para consultar o compilador referenciado por este projeto para sua lista padrão de locais de inclusão. Esses locais são adicionados automaticamente à lista de diretórios remotos a serem copiados. Defina essa propriedade como false somente se o compilador não der suporte a parâmetros do tipo gcc. Os compiladores gcc e Clang dão suporte a consultas para os diretórios de inclusão (por exemplo, `g++ -x c++ -E -v -std=c++11`).
Tipo de Configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca dinâmica (. so)**<br/>**Biblioteca estática (. a)**<br/>**Aplicativo (. out)**<br/>**Makefile**
Uso de STL | Especifica qual biblioteca padrão C++ deve ser usada para essa configuração. | **Biblioteca C++ Padrão do GNU Compartilhado**<br/>**Biblioteca C++ Padrão do GNU Estático (-static)**

::: moniker-end
