---
title: "Como: organizar arquivos de saída do projeto para compilações | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, output files
- output files, organizing
ms.assetid: 521d95ea-2dcc-4da0-b5eb-ac3e57941446
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 648321c41fe02541eeb746bae24236c40dc5325e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-organize-project-output-files-for-builds"></a>Como organizar arquivos de saída do projeto para builds
Este tópico descreve as práticas recomendadas para organizar arquivos de saída do projeto. Compilar erros podem ocorrer ao configurar arquivos de saída do projeto incorretamente. Este tópico também descreve as vantagens e desvantagens de cada alternativa para organizar seus arquivos de saída do projeto.  
  
## <a name="referencing-clr-assemblies"></a>Referenciando Assemblies do CLR  
  
#### <a name="to-reference-assemblies-with-using"></a>Para assemblies de referência com #using  
  
1.  Você pode fazer referência a um assembly diretamente no seu código usando a #using diretiva, como `#using <System.Data.dll>`. Para obter mais informações, consulte [#using diretiva](../preprocessor/hash-using-directive-cpp.md).  
  
     O arquivo especificado pode ser um. dll, .exe,. netmodule ou. obj, desde que ele está em MSIL. O componente referenciado pode ser criado em qualquer idioma. Usando essa opção, você terá acesso ao Intellisense porque os metadados serão extraídos do MSIL. O arquivo em questão deve estar no caminho para o projeto. Caso contrário, o projeto não será compilado e Intellisense não estarão disponível. Uma maneira fácil de determinar se o arquivo está no caminho é com o botão direito na #using linha e escolha o **documentos abertos** comando. Você será notificado se o arquivo não pode ser encontrado.  
  
     Se você não deseja colocar o caminho completo para o arquivo, você pode usar o **/AI** opção de compilador para editar o caminho de pesquisa para #using referências. Para obter mais informações, consulte [/AI (Especificar Diretórios de Metadados)](../build/reference/ai-specify-metadata-directories.md).  
  
#### <a name="to-reference-assemblies-with-fu"></a>Para fazer referência a assemblies com /FU  
  
1.  Em vez de referenciar um assembly diretamente de um arquivo de código, conforme descrito acima, você pode usar o **/FU** opção de compilador. A vantagem desse método é que você não precisa adicionar um separado #using de instrução para cada arquivo que faz referência a um determinado assembly.  
  
     Para definir essa opção, abra o **páginas de propriedades** para o projeto. Expanda o **propriedades de configuração** nó e, em seguida, expanda o **C/C++** nó e selecione **avançado**. Adicione os assemblies desejados lado **forçar #using**. Para obter mais informações, consulte [/FU (nome forçado #usando arquivo)](../build/reference/fu-name-forced-hash-using-file.md).  
  
#### <a name="to-reference-assemblies-with-add-new-reference"></a>Para fazer referência a assemblies com Adicionar nova referência  
  
1.  Essa é a maneira mais fácil usar assemblies do CLR. Primeiro, verifique se o projeto é compilado com o **/clr** opção de compilador. Em seguida, clique com botão direito do projeto a partir de **Gerenciador de soluções** e selecione **adicionar**, **referências**. O **páginas de propriedade** caixa de diálogo será exibida.  
  
2.  Do **páginas de propriedade** caixa de diálogo, selecione **adicionar nova referência**. Uma caixa de diálogo será exibida, listando todos os .NET, COM e outros assemblies disponíveis no projeto atual. Selecione o assembly desejado e clique em **Okey**.  
  
     Quando uma referência de projeto estiver definida, as dependências correspondentes são tratadas automaticamente. Além disso, como metadados são parte de um assembly, é necessário adicionar os elementos que estão sendo usados de um arquivo de cabeçalho ou o protótipo de assemblies gerenciados.  
  
## <a name="referencing-native-dlls-or-static-libraries"></a>Referência a DLLs nativas ou bibliotecas estáticas  
  
#### <a name="to-reference-native-dlls-or-static-libraries"></a>Para fazer referência a DLLs nativas ou bibliotecas estáticas  
  
1.  Referenciar o arquivo de cabeçalho apropriado em seu código usando o # diretiva include. O arquivo de cabeçalho deve ser o caminho de inclusão ou parte do projeto atual. Para obter mais informações, consulte [#include (C/C++) de diretiva](../preprocessor/hash-include-directive-c-cpp.md).  
  
2.  Você também pode definir dependências do projeto. Definir dependências do projeto garante duas coisas. Primeiro, garante que os projetos sejam compilados na ordem correta para que um projeto sempre possa encontrar os arquivos dependentes que ele precisa. Em segundo lugar, ele adiciona implicitamente diretório de saída do projeto dependente para o caminho para que os arquivos podem ser encontrados facilmente em tempo de vinculação.  
  
3.  Para implantar o aplicativo, você precisará colocar a DLL em um local apropriado. Isso pode ser um dos seguintes:  
  
    1.  O mesmo caminho do executável.  
  
    2.  Em qualquer lugar no caminho do sistema (o **caminho** variável de ambiente).  
  
    3.  No assembly lado a lado. Para obter mais informações, consulte [criando conjuntos de C/C++-lado a lado](../build/building-c-cpp-side-by-side-assemblies.md).  
  
## <a name="working-with-multiple-projects"></a>Trabalhar com vários projetos  
 Por padrão, os projetos são criados, de modo que todos os arquivos de saída são criados em um subdiretório do diretório do projeto. O diretório é denominado com base na configuração de compilação (por exemplo, de depuração ou de versão). Em ordem para projetos de irmão referir-se ao outro, cada projeto deve adicionar explicitamente os outros diretórios de saída do projeto para o seu caminho na ordem de vinculação para ter êxito. Isso é feito automaticamente quando você define as dependências do projeto. No entanto, se você não usar dependências, você deve cuidadosamente lidar com isso porque compilações podem se tornar muito difíceis de gerenciar. Por exemplo, quando um projeto tem configurações Debug e Release e inclui uma biblioteca externa de um projeto de irmão, ele deve usar um arquivo de biblioteca diferente, dependendo de qual configuração está sendo compilada. Assim, codificar esses caminhos pode ser complicado.  
  
 Todos os arquivos de saída essenciais (por exemplo, executáveis, arquivos de vinculador incremental e arquivos PDB) são copiados em um diretório de solução comum. Portanto, ao trabalhar com uma solução que contém um número de projetos do C++ com configurações equivalentes, todos os arquivos de saída são centralizados para vinculação simplificado e implantação. Você pode ter certeza de que seu aplicativo/biblioteca funcione conforme o esperado se eles manter juntos os arquivos (desde que os arquivos têm garantia de estar no caminho de).  
  
 O local dos arquivos de saída pode ser um grande problema durante a implantação em um ambiente de produção. Durante a execução de projetos no IDE, os caminhos para bibliotecas incluídas não são necessariamente o mesmo que o ambiente de produção. Por exemplo, se você tiver `#using "../../lib/debug/mylib.dll"` em seu código, mas, em seguida, implantar mylib.dll em uma posição relativa diferente, o aplicativo falhará em tempo de execução. Para evitar isso, você deve evitar usar caminhos relativos no #include instruções em seu código. É melhor para garantir que os arquivos necessários estão no caminho de compilação de projeto e da mesma forma, garantindo que os arquivos de produção correspondentes são colocados corretamente.  
  
#### <a name="how-to-specify-where-output-files-go"></a>Como especificar onde os arquivos de saída go  
  
1.  O local do projeto de saída configurações podem ser encontradas no projeto de **páginas de propriedade**. Expanda o nó do lado **propriedades de configuração** e selecione **geral**. O local de saída é especificado lado **diretório de saída**. Para obter mais informações, consulte [página de propriedade geral (projeto)](../ide/general-property-page-project.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)