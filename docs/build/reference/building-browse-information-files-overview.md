---
title: 'Compilando arquivos de informações de navegação: visão geral'
ms.date: 05/06/2019
helpviewer_keywords:
- .bsc files, about .bsc files
- bsc files, about bsc files
- browse information files (.bsc)
- browse information files (.bsc), creating
ms.assetid: b5c12832-51f6-4953-8044-4264dd0fb242
ms.openlocfilehash: ffacb7aaf9ac1f7ad6fc4cf12ab479099dc57725
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320677"
---
# <a name="building-browse-information-files-overview"></a>Compilando arquivos de informações de navegação: visão geral

> [!WARNING]
> Embora o BSCMAKE ainda esteja instalado no Visual Studio, ele não é mais usado pelo IDE. Desde o Visual Studio 2008, as informações de navegação e símbolo são armazenadas automaticamente em um arquivo SQL Server .sdf na pasta de solução.

Para criar informações de navegação para navegação de símbolos, o compilador cria um arquivo .sbr para cada arquivo de origem em seu projeto e, em seguida, BSCMAKE. EXE concatena os arquivos .sbr em um arquivo .bsc.

Gerar arquivos .sbr e .bsc leva tempo, então o Visual Studio desliga essas funções por padrão. Se você quiser navegar pelas informações atuais, você deve ativar as opções de navegação e construir seu projeto novamente.

Use [/FR](fr-fr-create-dot-sbr-file.md) ou [/Fr](fr-fr-create-dot-sbr-file.md) para dizer ao compilador para criar arquivos .sbr. Para criar arquivos .bsc, você pode chamar [BSCMAKE](bscmake-command-line.md) a partir da linha de comando. O uso do BSCMAKE da linha de comando dá-lhe um controle mais preciso sobre a manipulação de arquivos de informações de navegação. Consulte [BSCMAKE Reference](bscmake-reference.md) para obter mais informações.

> [!TIP]
> Você pode ativar a geração de arquivos .sbr, mas deixar a geração de arquivos .bsc desligada. Isso fornece compilações rápidas, mas também permite que você crie um arquivo .bsc fresco rapidamente, ativando a geração de arquivos .bsc e construindo o projeto.

Você pode reduzir o tempo, a memória e o espaço em disco necessários para construir um arquivo .bsc reduzindo o tamanho do arquivo .bsc.

Consulte [General Property Page (Project)](general-property-page-project.md) para obter informações sobre como construir um arquivo de navegador no ambiente de desenvolvimento.

### <a name="to-create-a-smaller-bsc-file"></a>Para criar um arquivo .bsc menor

1. Use [opções de linha de comando BSCMAKE](bscmake-options.md) para excluir informações do arquivo de informações de navegação.

1. Omita símbolos locais em um ou mais arquivos .sbr ao compilar ou montar.

1. Se um arquivo de objeto não contiver as informações necessárias para o estágio atual de depuração, omita seu arquivo .sbr do comando BSCMAKE quando você reconstrói o arquivo de informações de navegação.

### <a name="to-combine-the-browse-information-from-several-projects-into-one-browser-file-bsc"></a>Para combinar as informações de navegação de vários projetos em um arquivo do navegador (.bsc)

1. Ou não construa o arquivo .bsc no nível do projeto ou use o switch /n para evitar que os arquivos .sbr sejam truncados.

1. Depois que todos os projetos forem construídos, execute o BSCMAKE com todos os arquivos .sbr como entrada. Curingas são aceitos. Por exemplo, se você tinha diretórios de projeto C:\X, C:\Y e C:\Z com arquivos .sbr neles e você quisesse combiná-los\\\*todos em um\\\*arquivo .bsc,\\então use BSCMAKE C:\X .sbr C:\Y .sbr C:\Z\*.sbr /o c:\whatever_directory\combined.bsc para construir o arquivo combinado .bsc.

## <a name="see-also"></a>Confira também

[Ferramentas adicionais de construção de MSVC](c-cpp-build-tools.md)<br/>
[Referência de BSCMAKE](bscmake-reference.md)
