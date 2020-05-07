---
title: Como organizar arquivos de saída do projeto para compilações
ms.date: 05/06/2019
helpviewer_keywords:
- C++, output files
- output files, organizing
ms.assetid: 521d95ea-2dcc-4da0-b5eb-ac3e57941446
ms.openlocfilehash: 13aa3d1f8e2993ca34163ecbc0515948db56eb79
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328525"
---
# <a name="how-to-organize-project-output-files-for-builds"></a>Como organizar arquivos de saída do projeto para compilações

Este tópico descreve as melhores práticas para organizar arquivos de saída do projeto. Erros de build podem ocorrer ao configurar arquivos de saída do projeto incorretamente. Este tópico também descreve as vantagens e as desvantagens de cada alternativa para organização dos arquivos de saída do projeto.

## <a name="referencing-clr-assemblies"></a>Referenciando assemblies CLR

#### <a name="to-reference-assemblies-with-using"></a>Para referenciar assemblies com #using

1. Referencie um assembly diretamente no código usando a diretiva #using, como `#using <System.Data.dll>`. Para obter mais informações, confira [Diretiva #using](../preprocessor/hash-using-directive-cpp.md).

   O arquivo especificado pode ser um .dll, .exe, .netmodule ou .obj, desde que ele esteja em MSIL. O componente referenciado pode ser compilado em qualquer linguagem. Usando essa opção, você terá acesso ao IntelliSense, porque os metadados serão extraídos da MSIL. O arquivo em questão precisa estar no caminho para o projeto; caso contrário, o projeto não será compilado e o IntelliSense não ficará disponível. Uma maneira fácil de determinar se o arquivo está no caminho é clicar com o botão direito do mouse na linha #using e escolher o comando **Abrir documento**. Você será notificado se o arquivo não puder ser encontrado.

   Caso não deseje colocar o caminho completo para o arquivo, use a opção do compilador **/AI** para editar o caminho de pesquisa para as referências #using. Para obter mais informações, consulte [/AI (Especificar Diretórios de Metadados)](reference/ai-specify-metadata-directories.md).

#### <a name="to-reference-assemblies-with-fu"></a>Para referenciar assemblies com /FU

1. Em vez de referenciar um assembly diretamente em arquivo de código, conforme descrito acima, você pode usar a opção do compilador **/FU**. A vantagem desse método é que você não precisa adicionar uma instrução #using separada a cada arquivo que referencia um determinado assembly.

   Para definir essa opção, abra as **Páginas de Propriedades** do projeto. Expanda o nó **Propriedades de Configuração** e, em seguida, expanda o nó **C/C++** e selecione **Avançado**. Adicione os assemblies desejados ao lado de **Forçar #using**. Para obter mais informações, consulte [/FU (nome forçado #usando arquivo)](reference/fu-name-forced-hash-using-file.md).

#### <a name="to-reference-assemblies-with-add-new-reference"></a>Para referenciar assemblies com Adicionar Nova Referência

1. Essa é a maneira mais fácil de usar assemblies CLR. Primeiro, verifique se o projeto é compilado com a opção do compilador **/clr**. Em seguida, clique com o botão direito do mouse no projeto no **Gerenciador de Soluções** e selecione **Adicionar**, **Referências**. A caixa de diálogo **Páginas de Propriedades** será exibida.

1. Na caixa de diálogo **Páginas de Propriedades**, selecione **Adicionar Nova Referência**. Uma caixa de diálogo será exibida, listando todos os assemblies .NET, COM e outros disponíveis no projeto atual. Selecione o assembly desejado e clique em **OK**.

   Quando uma referência de projeto é definida, as dependências correspondentes são manipuladas automaticamente. Além disso, como os metadados fazem parte de um assembly, não é necessário adicionar um arquivo de cabeçalho ou criar o protótipo dos elementos que estão sendo usados em assemblies gerenciados.

## <a name="referencing-native-dlls-or-static-libraries"></a>Referenciando DLLs nativas ou bibliotecas estáticas

#### <a name="to-reference-native-dlls-or-static-libraries"></a>Para referenciar DLLs nativas ou bibliotecas estáticas

1. Referencie o arquivo de cabeçalho apropriado no código usando a diretiva #include. O arquivo de cabeçalho precisa estar no caminho de inclusão ou fazer parte do projeto atual. Para obter mais informações, confira [Diretiva #include (C/C++)](../preprocessor/hash-include-directive-c-cpp.md).

1. Defina também as dependências do projeto. A definição das dependências do projeto garante duas coisas. Primeiro, garante que os projetos sejam compilados na ordem correta, de modo que um projeto sempre possa encontrar os arquivos dependentes de que precisa. Em segundo lugar, ele adiciona implicitamente o diretório de saída do projeto dependente ao caminho para que os arquivos possam ser encontrados facilmente no momento do link.

1. Para implantar o aplicativo, você precisará colocar a DLL em um local apropriado. Pode ser um dos seguintes:

   1. No mesmo caminho do executável.

   1. Em qualquer lugar no caminho do sistema (a variável de ambiente **path**).

   1. No assembly lado a lado. Para obter mais informações, confira [Compilando assemblies lado a lado do C/C++](building-c-cpp-side-by-side-assemblies.md).

## <a name="working-with-multiple-projects"></a>Trabalhando com vários projetos

Por padrão, os projetos são compilados de modo que todos os arquivos de saída sejam criados em um subdiretório do diretório do projeto. O diretório é nomeado com base na configuração de build (por exemplo, Depuração ou Versão). Para que os projetos irmãos se refiram um ao outro, cada projeto precisa adicionar explicitamente os outros diretórios de saída do projeto ao seu caminho, para que vinculação tenha êxito. Isso é feito automaticamente quando você define as dependências do projeto. No entanto, se você não usar dependências, precisará lidar com isso cuidadosamente porque os builds podem se tornar muito difíceis de serem gerenciados. Por exemplo, quando um projeto tem configurações de Depuração e Versão e inclui uma biblioteca externa de um projeto irmão, ele deve usar um arquivo de biblioteca diferente, dependendo da configuração que está sendo compilada. Portanto, embutir esses caminhos em código pode ser complicado.

Todos os arquivos de saída essenciais (como executáveis, arquivos de vinculador incremental e arquivos PDB) são copiados para um diretório de solução comum. Portanto, ao trabalhar com uma solução que contém diversos projetos do C++ com configurações equivalentes, todos os arquivos de saída são centralizados para vinculação e implantação simplificadas. Você pode ter certeza de que os aplicativos/bibliotecas funcionarão conforme esperado se eles manterem esses arquivos juntos (desde que seja garantido de que os arquivos estarão no caminho).

O local dos arquivos de saída pode ser um grande problema durante a implantação em um ambiente de produção. Durante a execução de projetos no IDE, os caminhos para as bibliotecas incluídas não são necessariamente as mesmas do ambiente de produção. Por exemplo, se você tiver `#using "../../lib/debug/mylib.dll"` no código, mas, em seguida, implantar mylib.dll em uma posição relativa diferente, o aplicativo falhará em runtime. Para evitar isso, você deve evitar o uso de caminhos relativos em instruções #include no código. É melhor garantir que os arquivos necessários estejam no caminho de build do projeto e, da mesma forma, garantir que os arquivos de produção correspondentes sejam colocados corretamente.

#### <a name="how-to-specify-where-output-files-go"></a>Como especificar o local dos arquivos de saída

1. O local das configurações de saída do projeto pode ser encontrado nas **Páginas de Propriedades** do projeto. Expanda o nó ao lado de **Propriedades de Configuração** e selecione **Geral**. O local de saída é especificado ao lado de **Diretório de Saída**. Para obter mais informações, confira [Página de propriedades Geral (projeto)](reference/general-property-page-project.md).

## <a name="see-also"></a>Confira também

[Tipos de projeto do C++ no Visual Studio](reference/visual-cpp-project-types.md)
