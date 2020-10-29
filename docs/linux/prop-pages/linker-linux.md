---
title: Propriedades de vinculador (Linux C++)
ms.date: 06/07/2019
ms.assetid: a0243a94-8164-425b-b2fe-b84ff363d546
ms.openlocfilehash: d6c6bc44a4d681f442a5a85ca9d5865c4590f884
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921484"
---
# <a name="linker-properties-linux-c"></a>Propriedades de vinculador (Linux C++)

::: moniker range="msvc-140"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=msvc-150"

## <a name="general"></a>Geral

| Propriedade | Descrição | Opções |
|--|--|--|
| Arquivo de saída | A opção substitui o nome e o local padrão do programa que o vinculador cria. (-o) |
| Mostrar progresso | Imprime mensagens de progresso do vinculador. |
| Versão | A opção -version instrui o vinculador a colocar um número de versão no cabeçalho do executável. |
| Habilitar saída detalhada | A opção -verbose instrui o vinculador a produzir mensagens detalhadas para depuração. |
| Trace | A opção --trace instrui o vinculador a produzir os arquivos de entrada conforme eles são processados. |
| Rastrear Símbolos | Imprime a lista de arquivos na qual um símbolo aparece. (--trace-symbol=symbol) |
| Imprimir Mapa | A opção --print-map instrui o vinculador a produzir um mapa de links. |
| Relatar Referências de Símbolo não Resolvido | Quando habilitada, esta opção relatará referências de símbolo não resolvidas. |
| Otimizar uso de memória | Otimizar o uso de memória relendo as tabelas de símbolos, conforme o necessário. |
| Caminho de pesquisa de biblioteca de compartilhada | Permite ao usuário popular o caminho de pesquisa de biblioteca compartilhada. (-rpath-link=path) |
| Diretórios de Biblioteca Adicionais | Permite que o usuário substitua o caminho da biblioteca ambiental. (-L folder). |
| Vinculador | Especifica o programa a ser invocado durante a vinculação ou o caminho para o vinculador no sistema remoto. |
| Tempo Limite da Vinculação | Tempo limite da vinculação remota em milissegundos. |
| Saída da Cópia | Especifica se é necessário copiar o arquivo de saída de build do sistema remoto para o computador local. |

## <a name="input"></a>Entrada

| Propriedade | Descrição | Opções |
|--|--|--|
| Ignorar bibliotecas padrão específicas | Especifica um ou mais nomes de bibliotecas padrão a serem ignoradas. (--exclude-libs lib,lib) |
| Ignorar Bibliotecas Padrão | Ignorar as bibliotecas padrão e pesquisar somente as bibliotecas explicitamente especificadas. |
| Forçar Referências de Símbolo Não Definido | Forçar o símbolo a ser inserido no arquivo de saída como um símbolo indefinido. (-u symbol --undefined=symbol) |
| Dependências de biblioteca | Essa opção permite especificar as bibliotecas adicionais a serem adicionadas à linha de comando do vinculador. A biblioteca adicional será adicionada ao final da linha de comando do vinculador prefixada com “lib” e terminando com a extensão “.a”.  (-lFILE) |
| Dependências adicionais | Especifica itens adicionais a serem adicionados à linha de comando do link. |

## <a name="debugging"></a>Depuração

| Propriedade | Descrição | Opções |
|--|--|--|
| Informações de símbolo do depurador | Informações de símbolo do depurador do arquivo de saída. | **Incluir Todos**<br>**Omitir somente informações de símbolo do depurador**<br>**Omitir todas as informações de símbolo**<br> |
| Nome de Arquivo de Mapa | A opção Map instrui o vinculador a criar um arquivo de mapa com o nome especificado pelo usuário. (-Map=) |

## <a name="advanced"></a>Avançado

| Propriedade | Descrição | Opções |
|--|--|--|
| Marcar variáveis como ReadOnly após a realocação | Essa opção marca as variáveis como somente leitura após a realocação. |
| Habilitar associação de função imediata | Essa opção marca o objeto para associação de função imediata. |
| Não Exigir Pilha Executável | Essa opção marca a saída para não exigir uma pilha executável. |
| Arquivo morto inteiro | O Arquivo Inteiro usa todo o código de Fontes e Dependências Adicionais. |

::: moniker-end
