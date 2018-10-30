---
title: Eventos de build remotos (Linux C++) | Microsoft Docs
ms.custom: ''
ms.date: 9/26/2017
ms.technology:
- vs-ide-general
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: 165d3690-5bd8-4b0b-bc66-8b699d85a61b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 2ea01c5d92cbdb6066dc87675221eae6865af354
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50070968"
---
# <a name="build-event-properties-linux-c"></a>Propriedades de evento de build (Linux C++)

## <a name="pre-build-event"></a>Evento de Pré-Build

Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

## <a name="pre-link-event"></a>Evento de Pré-link

Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-link executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-link exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

## <a name="post-build-event"></a>Evento de Pós-Build

Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar.
Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

## <a name="remote-pre-build-event"></a>Evento de Pré-Build Remoto

Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.

## <a name="remote-pre-link-event"></a>Evento de Pré-Link Remoto

Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pré-link executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pré-link exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.

## <a name="remote-post-build-event"></a>Evento de Pós-Build Remoto

Propriedade | Descrição
--- | ---
Linha de Comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar no sistema remoto.
Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir.
Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual.
Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, a lista pode ser fornecida como um remoto para pares de mapeamento local usando uma sintaxe como essa: fullremotepath1:=fulllocalpath1;fullremotepath2:=fulllocalpath2, na qual um arquivo remoto pode ser copiado para um local especificado no computador local.
