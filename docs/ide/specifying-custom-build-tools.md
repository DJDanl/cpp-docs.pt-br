---
title: Especificando ferramentas de build personalizadas | Microsoft Docs
ms.custom: ''
ms.date: 06/05/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCCustomBuildTool.CustomBuildToolBeforeTargets
- VC.Project.VCCustomBuildTool.Outputs
- VC.Project.VCCustomBuildTool.Command
- VC.Project.VCCustomBuildTool.CommandLine
- VC.Project.VCCustomBuildTool.AdditionalDependencies
- VC.Project.VCCustomBuildTool.Message
- VC.Project.VCCustomBuildTool.CustomBuildToolAfterTargets
- VC.Project.VCCustomBuildTool.Description
- VC.Project.VCCustomBuildTool.AdditionalInputs
dev_langs:
- C++
helpviewer_keywords:
- build tools (C++), specifying
- custom build tools (C++), specifying
- builds (C++), custom build tools
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a880d8cac05ea662feafa4c309f70bb91179fb2c
ms.sourcegitcommit: 6784c1d5081dbe4d8119379647a34666328e1fdf
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/05/2018
ms.locfileid: "34798925"
---
# <a name="specify-custom-build-tools"></a>Especificar ferramentas de build personalizadas

Uma *ferramenta de build personalizada* fornece ao sistema de build as informações necessárias para que ele compile arquivos de entrada específicos. Uma ferramenta de build personalizada especifica um comando a ser executado, uma lista de arquivos de entrada, uma lista dos arquivos de saída gerados pelo comando e uma descrição opcional da ferramenta.

Para obter informações gerais sobre as ferramentas e as etapas de build personalizadas, confira [Noções básicas sobre eventos e etapas de build personalizadas](../ide/understanding-custom-build-steps-and-build-events.md).

### <a name="to-specify-a-custom-build-tool"></a>Para especificar uma ferramenta de build personalizada

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Configurando as propriedades do projeto do Visual C++](../ide/working-with-project-properties.md).

1. Escolha **Propriedades de Configuração** para habilitar a caixa **Configuração**. Na caixa **Configuração**, selecione a configuração para a qual deseja especificar uma ferramenta de build personalizada.

1. No **Gerenciador de Soluções**, selecione o arquivo de entrada para a ferramenta de build personalizada.

   Se a pasta **Ferramenta de Build Personalizada** não for exibida, a extensão do arquivo selecionado será associada a uma ferramenta padrão. Por exemplo, a ferramenta padrão para arquivos .c e .cpp é o compilador. Para substituir uma configuração de ferramenta padrão, no nó **Propriedades de Configuração**, na pasta **Geral**, na propriedade **Tipo de Item**, escolha **Ferramenta de Build Personalizada**. Escolha **Aplicar** e o nó **Ferramenta de Build Personalizada** será exibido.

1. No nó **Ferramenta de Build Personalizada**, na pasta **Geral**, especifique as propriedades associadas à ferramenta de build personalizada:

   - Em **Dependências Adicionais**, especifique os arquivos adicionais além daquele com o qual a ferramenta de build personalizada está sendo definida (o arquivo associado à ferramenta de build personalizada é implicitamente considerado uma entrada para a ferramenta). Não é um requisito ter arquivos de entrada adicionais para uma ferramenta de build personalizada. Caso você tenha mais de uma entrada adicional, separe-as com ponto-e-vírgula.

      Se a data de um arquivo de **Dependências Adicionais** é posterior ao arquivo de entrada, a ferramenta de build personalizada é executada. Se todos os arquivos de **Dependências Adicionais** são mais antigos que o arquivo de entrada e o arquivo de entrada é mais antigo que o arquivo de propriedade **Saídas**, a ferramenta de build personalizada não é executada.

      Por exemplo, suponha que você tenha uma ferramenta de build personalizada que usa MyInput.x como entrada e gera MyInput.cpp, e que MyInput.x inclua um arquivo de cabeçalho, MyHeader.h. Você pode especificar MyHeader.h como uma dependência de entrada para MyInput.x, e o sistema de build compilará MyInput.cpp quando ele estiver desatualizado em relação a MyInput.x ou MyHeader.h.

      As dependências de entrada também podem garantir que as ferramentas de build personalizadas sejam executadas na ordem necessária. No exemplo anterior, suponha que MyHeader.h seja, na verdade, a saída de uma ferramenta de build personalizada. Como MyHeader.h é uma dependência de MyInput.x, o sistema de build compilará primeiro Myheader.h antes de executar a ferramenta de build personalizada em MyInput.x.

   - Em **Linha de Comando**, especifique um comando como se o estivesse especificando no prompt de comando. Especifique um comando ou arquivo em lotes válido e os arquivos de entrada ou de saída necessários. Especifique o comando em lote **call** antes do nome de um arquivo em lotes para assegurar que todos os comandos seguintes sejam executados.

      Vários arquivos de entrada e de saída podem ser especificados simbolicamente com macros do MSBuild. Para obter informações sobre como especificar o local dos arquivos ou os nomes dos conjuntos de arquivos, confira [Macros comuns para comandos e propriedades de build](../ide/common-macros-for-build-commands-and-properties.md).

      Como o caractere '%' é reservado pelo MSBuild, se você especificar uma variável de ambiente, substitua cada caractere de escape **%** pela sequência de escape hexadecimal **%25**. Por exemplo, substitua **%WINDIR%** por **%25WINDIR%25**. O MSBuild substitui cada sequência **%25** pelo caractere **%** antes de acessar a variável de ambiente.

   - Em **Descrição**, insira uma mensagem descritiva sobre essa ferramenta de build personalizada. A mensagem será impressa na janela de **Saída** quando o sistema de build processar essa ferramenta.

   - Em **Saídas**, especifique o nome do arquivo de saída. Essa é uma entrada obrigatória; sem um valor para essa propriedade, a ferramenta de build personalizada não será executada. Se uma ferramenta de build personalizada tiver mais de uma saída, separe os nomes de arquivo com um ponto-e-vírgula.

      O nome do arquivo de saída deve ser o mesmo especificado na propriedade **Linha de Comando**. O sistema de build do projeto procurará o arquivo e verificará sua data. Se o arquivo de saída é mais antigo que o arquivo de entrada ou se o arquivo de saída não é encontrado, a ferramenta de build personalizada é executada. Se todos os arquivos de **Dependências Adicionais** são mais antigos que o arquivo de entrada e o arquivo de entrada é mais antigo que o arquivo especificado na propriedade **Saídas**, a ferramenta de build personalizada não é executada.

Caso deseje que o sistema de build opere em um arquivo de saída gerado pela ferramenta de build personalizada, adicione-o manualmente ao projeto. A ferramenta de build personalizada atualizará o arquivo durante o build.

## <a name="example"></a>Exemplo

Suponha que você deseje incluir um arquivo chamado parser.l no projeto. Você tem um analisador léxico, **lexer.exe**, no caminho do executável. Você deseja usá-lo para processar parser.l, a fim de produzir um arquivo .c que tenha o mesmo nome base (parser.c).

Primeiro, adicione parser.l e parser.c ao projeto. Se os arquivos ainda não existirem, adicione uma referência aos arquivos. Crie uma ferramenta de build personalizada para parser.l e insira o seguinte na propriedade **Comandos**:

> **lexer %(FullPath) .\%(Nome do arquivo).c**

Esse comando executa o analisador léxico em parser.l e gera parser.c no diretório do projeto.

Na propriedade **Saídas**, insira o seguinte:

> **.\%(Nome do arquivo).c**

Quando você compilar o projeto, o sistema de build comparará os carimbos de data/hora de parser.l e parser.c. Se parser.l for mais recente ou se parser.c não existir, o sistema de build executará o valor da propriedade **Linha de Comando** para atualizar parser.c. Como parser.c também foi adicionado ao projeto, o sistema de build, em seguida, compila parser.c.

## <a name="see-also"></a>Consulte também

[Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)  
[Solucionando problemas de personalização de compilação](../ide/troubleshooting-build-customizations.md)  
