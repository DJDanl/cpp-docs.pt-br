---
title: Propriedades gerais (Projeto do Linux C++ Makefile) | Microsoft Docs
ms.custom: ''
ms.date: 9/26/2017
ms.technology:
- vs-ide-general
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: 3dec6853-43f6-412b-9806-9bfad333a204
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 6fb23d2c7275788b05fe4450613770c268ca6c64
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34705693"
---
# <a name="makefile-project-properties-linux-c"></a>Propriedades do projeto makefile (Linux C++)

Esta é uma lista parcial das propriedades disponíveis em um projeto do Linux Makefile. Muitas propriedades de projeto makefile são idênticas às propriedades do projeto de Aplicativo de Console C++ do Linux.

## <a name="general"></a>Geral

propriedade | Descrição | Opções
--- | ---| ---
Diretório de saída | Especifica um caminho relativo para o diretório de arquivo de saída e pode incluir variáveis de ambiente.
Diretório intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário e pode incluir variáveis de ambiente.
Arquivo de log de build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado.
Tipo de configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca dinâmica (.so)** – Biblioteca dinâmica (.so)<br>**Biblioteca estática (.a)** – Biblioteca Estática (.a)<br>**Aplicativo (.out)** – Aplicativo (.out)<br>**Makefile** – makefile<br>
Computador de Build Remoto | O computador ou dispositivo de destino a ser usado para build, implantação e depuração remotos.
Diretório Raiz de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto.
Diretório de Projeto de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto para o projeto.

## <a name="debugging"></a>Depuração

Consulte [Propriedades do depurador (Linux C++)](debugging-linux.md)

## <a name="copy-sources"></a>Fontes de dados

Consulta [Copiar propriedades do projeto de origem (Linux C++)](copy-sources-project.md).

## <a name="build-events"></a>Compilar Eventos

### <a name="pre-build-event"></a>Evento de Pré-Build

propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

### <a name="post-build-event"></a>Evento de Pós-Build

propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

### <a name="remote-pre-build-event"></a>Evento de Pré-Build Remoto

propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.

### <a name="remote-post-build-event"></a>Evento de Pós-Build Remoto

propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.

## <a name="cc"></a>C/C++

### <a name="intellisense"></a>IntelliSense

As propriedades do IntelliSense podem ser definidas no nível do projeto ou de arquivo para fornecer dicas para o mecanismo IntelliSense. Elas não afetam a compilação.

propriedade | Descrição
--- | ---
Caminho de pesquisa de inclusão | Especifica o caminho de pesquisa de inclusão para resolver os arquivos incluídos.
Inclusões forçadas | Especifica os arquivos que passaram por inclusão forçada.
Definições do Pré-processador | Especifica as definições do pré-processador usadas pelos arquivos de origem.
Excluir as definições do pré-processador | Especifica uma ou mais exclusões de definição do pré-processador.     (/U[macro])
Opções Adicionais | Especifica opções adicionais do compilador a serem usadas pelo IntelliSense ao analisar arquivos C++.

### <a name="build"></a>Build

propriedade | Descrição
--- | ---
Linha de comando de build | Especifica a linha de comando a ser executada para o comando ‘Build’.
Linha de comando de Rebuild All | Especifica a linha de comando a ser executada para o comando ‘Rebuild All’.
Linha de comando de Clean | Especifica a linha de comando a ser executada para o comando “Clean”.

### <a name="remote-build"></a>Build Remoto

propriedade | Descrição
--- | ---
Linha de comando de build | Especifica a linha de comando a ser executada para o comando “Build”. Isso é executado no sistema remoto.
Linha de Comando de Rebuild All | Especifica a linha de comando a ser executada para o comando “Rebuild All”. Isso é executado no sistema remoto.
Linha de Comando Clean | Especifica a linha de comando a ser executada para o comando 'Clean'. Isso é executado no sistema remoto.
Saídas | Especifica as saídas geradas pelo build remoto no sistema remoto.
