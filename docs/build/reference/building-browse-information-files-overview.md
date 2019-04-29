---
title: 'Compilando arquivos de informações de navegação: Visão geral'
ms.date: 11/04/2016
helpviewer_keywords:
- .bsc files, about .bsc files
- bsc files, about bsc files
- browse information files (.bsc)
- browse information files (.bsc), creating
ms.assetid: b5c12832-51f6-4953-8044-4264dd0fb242
ms.openlocfilehash: 4f12bd25ca3ab718a845dbb04aba3169cc6d4b19
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272878"
---
# <a name="building-browse-information-files-overview"></a>Compilando arquivos de informações de navegação: Visão geral

Para criar informações de procura para navegação de símbolo, o compilador cria um arquivo. SBR para cada arquivo de origem em seu projeto, em seguida, BSCMAKE. EXE concatena os arquivos. SBR em um único arquivo. bsc.

Gerando arquivos. SBR e. bsc leva tempo, portanto, o Visual C++ desativa a essas funções por padrão. Se você deseja procurar informações atuais, você deve ativar as opções de pesquisa e compile o projeto novamente.

Use [/FR](fr-fr-create-dot-sbr-file.md) ou [/Fr](fr-fr-create-dot-sbr-file.md) para indicar ao compilador para criar arquivos. SBR. Para criar arquivos. bsc, você pode chamar [BSCMAKE](bscmake-command-line.md) da linha de comando. Usar BSCMAKE da linha de comando lhe dá controle mais preciso sobre a manipulação de arquivos de informações de procura. Ver [referência de BSCMAKE](bscmake-reference.md) para obter mais informações.

> [!TIP]
>  Você pode ativar a geração do arquivo. SBR mas deixe a geração do arquivo. bsc desativada. Isso fornece fast builds, mas também permite que você crie um arquivo. bsc atualizada rapidamente, ativar a geração do arquivo. bsc e compilar o projeto.

Você pode reduzir o tempo, memória e espaço em disco necessário para criar um arquivo. bsc, reduzindo o tamanho do arquivo. bsc.

Ver [página de propriedades gerais (projeto)](general-property-page-project.md) para obter informações sobre como criar um arquivo de navegador no ambiente de desenvolvimento.

### <a name="to-create-a-smaller-bsc-file"></a>Para criar um arquivo. bsc menor

1. Use [opções de linha de comando BSCMAKE](bscmake-options.md) para excluir informações do arquivo de informações de procura.

1. Omita símbolos locais em um ou mais arquivos. SBR durante a compilação ou a montagem.

1. Se um arquivo de objeto não contém informações necessárias para o estágio atual de depuração, omita o seu arquivo. SBR do comando BSCMAKE ao recriar o arquivo de informações de procura.

### <a name="to-combine-the-browse-information-from-several-projects-into-one-browser-file-bsc"></a>Para combinar informações de procura de vários projetos em arquivo de um navegador (. bsc)

1. Não criar o arquivo. bsc no nível do projeto ou usar a opção /n para impedir que os arquivos. SBR sejam truncados.

1. Depois que todos os projetos são criados, execute BSCMAKE com todos os arquivos. SBR como entrada. Caracteres curinga é aceitos. Por exemplo, se você tivesse os diretórios de projeto C:\X, C:\Y e C:\Z com arquivos. SBR neles e você desejar combiná-los todos em um único arquivo. bsc, em seguida, usar BSCMAKE C:\X\\\*. SBR C:\Y\\\*. SBR C:\Z\\ \*. SBR /o c:\whatever_directory\combined.bsc para criar o arquivo. bsc combinado.

## <a name="see-also"></a>Consulte também

[Ferramentas de Build do MSVC adicionais](c-cpp-build-tools.md)<br/>
[Referência de BSCMAKE](bscmake-reference.md)
