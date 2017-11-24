---
title: Propriedades de vinculador (Linux C++) | Microsoft Docs
ms.custom: 
ms.date: 9/26/2017
ms.reviewer: 
ms.suite: 
ms.technology: vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: a0243a94-8164-425b-b2fe-b84ff363d546
author: mikeblome
ms.author: mblome
manager: ghogen
f1_keywords:
- VC.Project.VCLinkerTool.OutputFile
- VC.Project.VCLinkerTool.ShowProgress
- VC.Project.VCLinkerTool.Version
- VC.Project.VCLinkerTool.VerboseOutput
- VC.Project.VCLinkerTool.UnresolvedReferences
- VC.Project.VCLinkerTool.OptimizeForMemory
- VC.Project.VCLinkerTool.SharedLibrarySearchPath
- VC.Project.VCLinkerTool.AdditionalLibraryDirectories
- VC.Project.VCConfiguration.BuildLogFile
- VC.Project.VCLinkerTool.IgnoreDefaultLibraryNames
- VC.Project.VCLinkerTool.ForceSymbolReferences
- VC.Project.VCLinkerTool.LibraryDependencies
- VC.Project.VCLinkerTool.ForceFileOutput
- VC.Project.VCLinkerTool.GenerateMapFile
- VC.Project.VCLinkerTool.Relocation
- VC.Project.VCLinkerTool.FunctionBinding
- VC.Project.VCLinkerTool.NoExecStackRequired
- VC.Project.WholeArchive
- VC.Project.AdditionalOptionsPage
- VC.Project.VCLinkerTool.AdditionalDependencies
ms.openlocfilehash: 963d73e73e42930f0245c0fef443da27bf451bc6
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="linker-properties-linux-c"></a>Propriedades de vinculador (Linux C++)

## <a name="general"></a>Geral
Propriedade | Descrição | Opções
--- | ---| ---
Arquivo de Saída | A opção substitui o nome padrão e o local do programa que o vinculador cria. (-o)
Mostrar Andamento | Imprime mensagens de andamento do vinculador.
Versão | A opção -version instrui o vinculador a colocar um número de versão no cabeçalho do executável.
Habilitar Saída Detalhada | A opção -verbose instrui o vinculador a produzir mensagens detalhadas para depuração.
Rastrear | A opção --trace instrui o vinculador a produzir os arquivos de entrada conforme eles são processados.
Rastrear Símbolos | Imprime a lista de arquivos na qual um símbolo aparece. (--trace-symbol=symbol)
Imprimir Mapa | A opção --print-map instrui o vinculador a produzir um mapa de links.
Relatar Referências de Símbolo não Resolvido | Quando habilitada, esta opção relata referências de símbolo não resolvido.
Otimizar para Uso de Memória | Otimizar para uso de memória relendo as tabelas de símbolo se necessário.
Caminho de Pesquisa de Biblioteca Compartilhada | Permite ao usuário popular o caminho de pesquisa de biblioteca compartilhada. (-rpath-link=path)
Diretórios de Biblioteca Adicionais | Permite que o usuário substitua o caminho da biblioteca ambiental. (-L folder).
Vinculador | Especifica o programa a ser invocado durante a vinculação ou o caminho para o vinculador no sistema remoto.
Tempo Limite da Vinculação | Tempo limite da vinculação remota em milissegundos.
Saída da Cópia | Especifica se é necessário copiar o arquivo de saída de build do sistema remoto para o computador local.

## <a name="input"></a>Entrada
Propriedade | Descrição | Opções
--- | ---| ---
Ignorar Bibliotecas Padrão Específicas | Especifica um ou mais nomes de bibliotecas padrão a serem ignoradas. (--exclude-libs lib,lib)
Ignorar Bibliotecas Padrão | Ignorar as bibliotecas padrão e pesquisar somente as bibliotecas explicitamente especificadas.
Forçar Referências de Símbolo Não Definido | Forçar o símbolo a ser inserido no arquivo de saída como um símbolo indefinido. (-u symbol --undefined=symbol)
Dependências da Biblioteca | Essa opção permite especificar as bibliotecas adicionais a serem adicionadas à linha de comando do vinculador. A biblioteca adicional será adicionada ao final da linha de comando do vinculador prefixada com “lib” e terminando com a extensão “.a”.  (-lFILE)
Dependências Adicionais | Especifica itens adicionais a serem adicionados à linha de comando do link.

## <a name="debugging"></a>Depuração
Propriedade | Descrição | Opções
--- | ---| ---
Informações do Símbolo do Depurador | Informações do símbolo do depurador do arquivo de saída. | **Incluir Tudo**<br>**Omitir Somente Informações do Símbolo do Depurador**<br>**Omitir Todas as Informações de Símbolos**<br>
Nome de Arquivo de Mapa | A opção Map instrui o vinculador a criar um arquivo de mapa com o nome especificado pelo usuário. (-Map=)

## <a name="advanced"></a>Avançado
Propriedade | Descrição | Opções
--- | ---| ---
Marcar Variáveis ReadOnly Após a Realocação | Essa opção marca variáveis somente leitura após a realocação.
Habilitar Associação de Função Imediata | Essa opção marca o objeto para associação de função imediata.
Não Exigir Pilha Executável | Essa opção marca que a saída não exigirá pilha executável.
Arquivo Inteiro | O Arquivo Inteiro usa todo o código de Fontes e Dependências Adicionais.


## <a name="additional-options"></a>Opções Adicionais



