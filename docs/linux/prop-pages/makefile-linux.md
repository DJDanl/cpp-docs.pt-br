---
title: Propriedades gerais (Projeto do Linux C++ Makefile) | Microsoft Docs
ms.custom: 
ms.date: 9/26/2017
ms.reviewer: 
ms.suite: 
ms.technology: vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 3dec6853-43f6-412b-9806-9bfad333a204
author: mikeblome
ms.author: mblome
manager: ghogen
f1_keywords:
- VC.Project.VCConfiguration.OutputDirectory
- VC.Project.VCConfiguration.IntermediateDirectory
- VC.Project.VCConfiguration.ConfigurationType
- VC.Project.VCConfiguration.BuildLogFile
ms.openlocfilehash: 9507ab2ed54d8160afdd8071b0779b51d6802bef
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="makefile-project-properties-linux-c"></a>Propriedades do projeto do MakeFile (Linux C++)
Esta é uma lista parcial das propriedades disponíveis em um projeto do Linux Makefile. Muitas propriedades do projeto do MakeFile são idênticas ao 

## <a name="general"></a>Geral
Propriedade | Descrição | Opções
--- | ---| ---
Diretório de Saída | Especifica um caminho relativo para o diretório do arquivo de saída, podendo incluir variáveis de ambiente.
Diretório Intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário, podendo incluir variáveis de ambiente.
Arquivo de Log de Build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado.
Tipo de Configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca Dinâmica (.so)** – Biblioteca Dinâmica (.so)<br>**Biblioteca estática (.a)** – Biblioteca Estática (.a)<br>**Aplicativo (.out)** – Aplicativo (.out)<br>**Makefile** – Makefile<br>
Computador de Build Remoto | O computador ou dispositivo de destino a ser usado para build, implantação e depuração remotos.
Diretório Raiz de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto.
Diretório de Projeto de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto para o projeto.

## <a name="debugging"></a>Depuração
Consulte [Propriedades do depurador (Linux C++)](debugging-linux.md)

## <a name="copy-sources"></a>Fontes de dados
Consulta [Copiar propriedades do projeto de origem (Linux C++)](copy-sources-project.md).

## <a name="build-events"></a>Compilar Eventos

### <a name="pre-build-event"></a>Evento de Pré-Build
Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

### <a name="post-build-event"></a>Evento de Pós-Build
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir.
Uso na compilação | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiados para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

### <a name="remote-pre-build-event"></a>Evento de Pré-Build Remoto
Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir.
Uso na compilação | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiados do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.

### <a name="remote-post-build-event"></a>Evento de Pós-Build Remoto
Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir.
Uso na compilação | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiados do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.

## <a name="cc"></a>C/C++

### <a name="intellisense"></a>IntelliSense
As propriedades do IntelliSense podem ser definidas no nível do projeto ou de arquivo para fornecer dicas para o mecanismo IntelliSense. Elas não afetam a compilação.

Propriedade | Descrição
--- | ---
Caminho de Pesquisa de Inclusão | Especifica o caminho de pesquisa de inclusão para resolver os arquivos incluídos.
Inclusões Forçadas | Especifica os arquivos que passaram por inclusão forçada.
Definições do Pré-processador | Especifica as definições de pré-processador usadas pelos arquivos de origem.
Excluir as definições do pré-processador | Especifica uma ou mais exclusões de definição do pré-processador.     (/U[macro])
Opções Adicionais | Especifica opções adicionais do compilador a serem usadas pelo Intellisense ao analisar arquivos C++.

### <a name="build"></a>Build
Propriedade | Descrição
--- | ---
Linha de Comando de Build | Especifica a linha de comando a ser executada para o comando “Build”.
Linha de Comando de Rebuild All | Especifica a linha de comando a ser executada para o comando “Rebuild All”.
Linha de Comando Clean | Especifica a linha de comando a ser executada para o comando “Clean”.

### <a name="remote-build"></a>Build Remoto
Propriedade | Descrição
--- | ---
Linha de Comando de Build | Especifica a linha de comando a ser executada para o comando “Build”. Isso é executado no sistema remoto.
Linha de Comando de Rebuild All | Especifica a linha de comando a ser executada para o comando “Rebuild All”. Isso é executado no sistema remoto.
Linha de Comando Clean | Especifica a linha de comando a ser executada para o comando “Clean”. Isso é executado no sistema remoto.
Saídas | Especifica as saídas geradas pelo build remoto no sistema remoto.

