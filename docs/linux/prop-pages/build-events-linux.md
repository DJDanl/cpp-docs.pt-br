---
title: Eventos de build remoto (Linux C++)
ms.date: 06/07/2019
ms.assetid: 165d3690-5bd8-4b0b-bc66-8b699d85a61b
ms.openlocfilehash: 4a3e9019d4dacc3d494feb5d6de8f5c2247e4d12
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441504"
---
# <a name="build-event-properties-linux-c"></a>Propriedades de evento de build (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="pre-build-event"></a>Evento de Pré-Build

| Propriedade | Descrição |
|--|--|
| Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar. |
| Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir. |
| Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual. |
| Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, especifique pares de mapeamento local para remoto usando uma sintaxe como esta: fulllocalpath1: = fullremotepath1; fulllocalpath2: = fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto. |

## <a name="pre-link-event"></a>Evento de Pré-link

| Propriedade | Descrição |
|--|--|
| Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pré-link executar. |
| Descrição | Especifica uma descrição para a ferramenta de evento de pré-link exibir. |
| Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual. |
| Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, especifique pares de mapeamento local para remoto usando uma sintaxe como esta: fulllocalpath1: = fullremotepath1; fulllocalpath2: = fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto. |

## <a name="post-build-event"></a>Evento de Pós-Build

| Propriedade | Descrição |
|--|--|
| Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar. |
| Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir. |
| Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual. |
| Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas para o sistema remoto. Opcionalmente, especifique pares de mapeamento local para remoto usando uma sintaxe como esta: fulllocalpath1: = fullremotepath1; fulllocalpath2: = fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto. |

## <a name="remote-pre-build-event"></a>Evento de Pré-Build Remoto

| Propriedade | Descrição |
|--|--|
| Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pré-build executar no sistema remoto. |
| Descrição | Especifica uma descrição para a ferramenta de evento de pré-build exibir. |
| Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual. |
| Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, especifique os pares de mapeamento remoto para local usando uma sintaxe como esta: fullremotepath1: = fulllocalpath1; fullremotepath2: = fulllocalpath2, em que um arquivo remoto pode ser copiado para o local especificado no computador local. |

## <a name="remote-pre-link-event"></a>Evento de Pré-Link Remoto

| Propriedade | Descrição |
|--|--|
| Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pré-link executar no sistema remoto. |
| Descrição | Especifica uma descrição para a ferramenta de evento de pré-link exibir. |
| Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual. |
| Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, especifique os pares de mapeamento remoto para local usando uma sintaxe como esta: fullremotepath1: = fulllocalpath1; fullremotepath2: = fulllocalpath2, em que um arquivo remoto pode ser copiado para o local especificado no computador local. |

## <a name="remote-post-build-event"></a>Evento de Pós-Build Remoto

| Propriedade | Descrição |
|--|--|
| Linha de comando | Especifica uma linha de comando para a ferramenta de evento de pós-build executar no sistema remoto. |
| Descrição | Especifica uma descrição para a ferramenta de evento de pós-build exibir. |
| Uso no build | Especifica se esse evento de build é excluído da build para a configuração atual. |
| Arquivos adicionais a serem copiados | Especifica os arquivos adicionais a serem copiadas do sistema remoto. Opcionalmente, especifique os pares de mapeamento remoto para local usando uma sintaxe como esta: fullremotepath1: = fulllocalpath1; fullremotepath2: = fulllocalpath2, em que um arquivo remoto pode ser copiado para o local especificado no computador local. |

::: moniker-end
