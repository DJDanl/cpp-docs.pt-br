---
title: Propriedades gerais (Projeto Linux C++)
description: Descreve as propriedades do projeto Linux que você pode definir no Visual Studio na página propriedades Gerais.
ms.date: 01/14/2020
ms.assetid: 56c800a9-3df9-4196-87b2-81adb00e4767
ms.openlocfilehash: 832f10ca2c95e40ff7ece23462105fa49014aa5d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "79446172"
---
# <a name="general-properties-linux-c"></a>Propriedades gerais (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

| Propriedade | Descrição | Opções |
|--|--|--|
| Diretório de saída | Especifica um caminho relativo para o diretório de arquivos de saída. Pode incluir variáveis de ambiente. |
| Diretório intermediário | Especifica um caminho relativo para o diretório de arquivos intermediário. Pode incluir variáveis de ambiente. |
| Nome de destino | Especifica o nome do arquivo que este projeto gera. |
| Extensão de destino | Especifica a extensão de `.a`arquivo (por exemplo) que este projeto gera. |
| Extensões a serem excluídas na limpeza | Especificação curinga delimitada em ponto e vírgula para as quais os arquivos no diretório intermediário para excluir em limpar ou reconstruir. |
| Arquivo de log de build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado. |
| Conjunto de ferramentas da plataforma | Especifica o conjunto de ferramentas usado para construir a configuração atual. Se não estiver definido, o conjunto de ferramentas padrão será usado. |
| Computador de Build Remoto | Exibe a máquina de destino ou dispositivo para usar para compilação remota, implantação e depuração. Você pode adicionar ou editar uma conexão de máquina de destino usando **o Tools** > **Options** > **Cross Platform** > **Connection Manager**.<br /> **Visual Studio 2019 versão 16.1** Você pode especificar uma máquina diferente para depuração na página [Depuração.](debugging-linux.md) |
| Diretório Raiz de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto. |
| Diretório de Projeto de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto para o projeto. |
| Diretório de implantação remota | **Visual Studio 2019 versão 16.1** Especifica o caminho do diretório na máquina ou dispositivo remoto para implantar o projeto. |
| Copiar remotamente incluir diretórios | **Visual Studio 2019 versão 16.5**  Uma lista de diretórios para copiar recursivamente do alvo linux. Essa propriedade afeta a cópia de cabeçalho remoto do IntelliSense, mas não a compilação. Ele pode ser usado quando **o IntelliSense Usa Defaults do Compilador** é definido como falso. Use **diretórios adicionais** de inclusão sob a guia C/C++ Geral para especificar diretórios adicionais para usar tanto no IntelliSense quanto na compilação. |
| Diretórios de exclusão de cópias remotas | **Visual Studio 2019 versão 16.5** Uma lista de diretórios para *não* copiar do alvo do Linux. Normalmente, esta propriedade é usada para remover subdiretórios dos diretórios de inclusão. |
| IntelliSense usa padrões do compilador | **Visual Studio 2019 versão 16.5** Se consultar o compilador referenciado por este projeto para sua lista padrão de locais incluem. Esses locais são automaticamente adicionados à lista de diretórios remotos a serem copiados. Só defina essa propriedade como falsa se o compilador não suportar parâmetros semelhantes a gcc. Tanto os compiladores gcc quanto os compiladores de clang `g++ -x c++ -E -v -std=c++11`suportam consultas para os diretórios incluem (por exemplo, ). |
| Tipo de Configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca Dinâmica (.so)**<br/><br/>**Biblioteca estática (.a)**<br/><br/>**Aplicação (.out)**<br/><br/>**Makefile** |
| Uso de STL | Especifica qual biblioteca padrão C++ deve ser usada para essa configuração. | **Biblioteca C++ Padrão do GNU Compartilhado**<br/><br/>**Biblioteca C++ Padrão do GNU Estático (-static)** |

::: moniker-end
