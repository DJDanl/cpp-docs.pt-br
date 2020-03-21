---
title: 'Compilando arquivos de informações de navegação: visão geral'
ms.date: 05/06/2019
helpviewer_keywords:
- .bsc files, about .bsc files
- bsc files, about bsc files
- browse information files (.bsc)
- browse information files (.bsc), creating
ms.assetid: b5c12832-51f6-4953-8044-4264dd0fb242
ms.openlocfilehash: 94cb5865e56e12f51ef4a8598a5df3fcbe69fa0f
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078353"
---
# <a name="building-browse-information-files-overview"></a>Compilando arquivos de informações de navegação: visão geral

> [!WARNING]
> Embora o BSCMAKE ainda esteja instalado com o Visual Studio, ele não é mais usado pelo IDE. Como o Visual Studio 2008, as informações de procura e símbolo são armazenadas automaticamente em um arquivo SQL Server. sdf na pasta da solução.

Para criar informações de procura para navegação de símbolo, o compilador cria um arquivo. sbr para cada arquivo de origem em seu projeto, em seguida, BSCMAKE. EXE concatena os arquivos. sbr em um arquivo. BSC.

Gerar arquivos. sbr e. BSC leva tempo, portanto, o Visual Studio desativa essas funções por padrão. Se você quiser procurar informações atuais, deverá ativar as opções de procura e criar seu projeto novamente.

Use [/fr](fr-fr-create-dot-sbr-file.md) ou [/fr](fr-fr-create-dot-sbr-file.md) para instruir o compilador a criar arquivos. sbr. Para criar arquivos. BSC, você pode chamar [BSCMAKE](bscmake-command-line.md) na linha de comando. O uso do BSCMAKE da linha de comando proporciona um controle mais preciso sobre a manipulação de arquivos de informações de procura. Consulte [referência de BSCMAKE](bscmake-reference.md) para obter mais informações.

> [!TIP]
>  Você pode ativar a geração de arquivo. SBR, mas deixar a geração de arquivo BSC desativada. Isso fornece compilações rápidas, mas também permite que você crie um novo arquivo. BSC rapidamente ativando a geração de arquivo BSC e compilando o projeto.

Você pode reduzir o tempo, a memória e o espaço em disco necessários para criar um arquivo. BSC, reduzindo o tamanho do arquivo. BSC.

Consulte a [página de propriedades geral (projeto)](general-property-page-project.md) para obter informações sobre como criar um arquivo de navegador no ambiente de desenvolvimento.

### <a name="to-create-a-smaller-bsc-file"></a>Para criar um arquivo. BSC menor

1. Use [as opções de linha de comando do BSCMAKE](bscmake-options.md) para excluir informações do arquivo de informações de procura.

1. Omita símbolos locais em um ou mais arquivos. sbr durante a compilação ou montagem.

1. Se um arquivo de objeto não contiver informações necessárias para o estágio atual de depuração, omita seu arquivo. sbr do comando BSCMAKE ao recriar o arquivo de informações de procura.

### <a name="to-combine-the-browse-information-from-several-projects-into-one-browser-file-bsc"></a>Para combinar as informações de procura de vários projetos em um arquivo de navegador (. BSC)

1. Não crie o arquivo. BSC no nível do projeto ou use a opção/n para impedir que os arquivos. sbr sejam truncados.

1. Depois que todos os projetos forem compilados, execute BSCMAKE com todos os arquivos. sbr como entrada. Caracteres curinga são aceitos. Por exemplo, se você tivesse os diretórios de projeto C:\X, C:\Y e C:\Z com arquivos. sbr neles e quisesse combiná-los em um arquivo. BSC, use BSCMAKE C:\X\\\*. sbr C:\Y\\\*. sbr C:\Z\\\*. sbr/o c:\ whatever_directory \combined.BSC para criar o arquivo. BSC combinado.

## <a name="see-also"></a>Confira também

[Ferramentas de build adicionais do MSVC](c-cpp-build-tools.md)<br/>
[Referência de BSCMAKE](bscmake-reference.md)
