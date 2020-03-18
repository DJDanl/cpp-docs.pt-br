---
title: Propriedades de vinculador (Linux C++)
ms.date: 06/07/2019
ms.assetid: a0243a94-8164-425b-b2fe-b84ff363d546
ms.openlocfilehash: 934e639199d663cba391c9913b067f32e5e32165
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441275"
---
# <a name="linker-properties-linux-c"></a>Propriedades de vinculador (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="general"></a>Geral

| Propriedade | Descrição | Opções |
|--|--|--|
| Arquivo de Saída | A opção substitui o nome e o local padrão do programa que o vinculador cria. (-o) |
| Mostrar progresso | Imprime mensagens de progresso do vinculador. |
| {1&gt;Version&lt;1} | A opção -version instrui o vinculador a colocar um número de versão no cabeçalho do executável. |
| Habilitar saída detalhada | A opção -verbose instrui o vinculador a produzir mensagens detalhadas para depuração. |
| Rastreamento | A opção --trace instrui o vinculador a produzir os arquivos de entrada conforme eles são processados. |
| Rastrear Símbolos | Imprime a lista de arquivos na qual um símbolo aparece. (--trace-symbol=symbol) |
| Imprimir Mapa | A opção --print-map instrui o vinculador a produzir um mapa de links. |
| Relatar referências de símbolo não resolvidas | Quando habilitada, esta opção relatará referências de símbolo não resolvidas. |
| Otimizar uso de memória | Otimizar para uso de memória relendo as tabelas de símbolo se necessário. |
| Caminho de Pesquisa de Biblioteca Compartilhada | Permite que o usuário popule o caminho de pesquisa de biblioteca compartilhada. (-rpath-link=path) |
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
| Dependências da Biblioteca | Essa opção permite especificar as bibliotecas adicionais a serem adicionadas à linha de comando do vinculador. A biblioteca adicional será adicionada ao final da linha de comando do vinculador prefixada com “lib” e terminando com a extensão “.a”.  (-lFILE) |
| {1&gt;Dependências adicionais&lt;1} | Especifica itens adicionais a serem adicionados à linha de comando do link. |

## <a name="debugging"></a>Depuração

| Propriedade | Descrição | Opções |
|--|--|--|
| Informações do Símbolo do Depurador | Informações de símbolo do depurador do arquivo de saída. | **Incluir tudo**<br>**Omitir Somente Informações do Símbolo do Depurador**<br>**Omitir Todas as Informações de Símbolos**<br> |
| Nome do arquivo de mapa | A opção Map instrui o vinculador a criar um arquivo de mapa com o nome especificado pelo usuário. (-Map=) |

## <a name="advanced"></a>Avançado

| Propriedade | Descrição | Opções |
|--|--|--|
| Marcar variáveis como ReadOnly após a realocação | Essa opção marca as variáveis como somente leitura após a realocação. |
| Habilitar associação de função imediata | Essa opção marca o objeto para associação de função imediata. |
| Não Exigir Pilha Executável | Essa opção marca que a saída não exigirá pilha executável. |
| Arquivo morto inteiro | O arquivo morto inteiro usa todo o código das fontes e das dependências adicionais. |

::: moniker-end
