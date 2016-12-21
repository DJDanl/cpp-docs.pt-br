---
title: "Como organizar arquivos de sa&#237;da do projeto para compila&#231;&#245;es | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de saída, organizando"
  - "Visual C++, arquivos de saída"
ms.assetid: 521d95ea-2dcc-4da0-b5eb-ac3e57941446
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como organizar arquivos de sa&#237;da do projeto para compila&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve as práticas recomendadas para organização de arquivos de saída do projeto.  Erros de compilação podem ocorrer quando você configura arquivos de saída do projeto incorretamente.  Este tópico também descreve as vantagens e desvantagens de cada alternativa para organizar seus arquivos de saída do projeto.  
  
## Referenciando assemblies do CLR  
  
#### Para referenciar assemblies com \#using  
  
1.  Você pode fazer referência a um assembly diretamente do seu código usando a diretiva \#using, como `#using <System.Data.dll>`.  Para obter mais informações, consulte [Diretiva \#using](../preprocessor/hash-using-directive-cpp.md).  
  
     O arquivo especificado pode ser um arquivo .dll, .exe, .netmodule ou .obj, desde que ele esteja em MSIL.  O componente referenciado pode ser integrado a qualquer linguagem.  Usando essa opção, você terá acesso ao Intellisense desde que os metadados sejam extraídos do MSIL.  O arquivo em questão deve estar no caminho para o projeto; caso contrário, o projeto não será compilado e o Intellisense não estará disponível.  Uma maneira fácil para determinar se o arquivo está no caminho é clicar com o botão direito do mouse na linha \#using e selecionar o comando **Abrir documento**.  Você será notificado se o arquivo não puder ser encontrado.  
  
     Se você não desejar colocar o caminho completo do arquivo, poderá usar a opção de compilador **\/AI** para editar o caminho de pesquisa para referências \#using.  Para obter mais informações, consulte [\/AI \(especificar diretórios de metadados\)](../build/reference/ai-specify-metadata-directories.md).  
  
#### Para referenciar assemblies com \/FU  
  
1.  Em vez de referenciar um assembly diretamente de um arquivo de código como descrito acima, você pode usar a opção de compilador **\/FU** .  A vantagem desse método é que você não precisa adicionar uma instrução \#using separada para cada arquivo que faz referência a um determinado assembly.  
  
     Para definir esta opção, abra as **Páginas de propriedades** para o projeto.  Expanda o nó **Propriedades de Configuração** e, em seguida, expanda o nó **C\/C\+\+** e selecione **Avançado**.  Adicione os assemblies desejados ao lado de **Forçar \#using**.  Para obter mais informações, consulte [\/FU \(nome forçado \#usando arquivo\)](../build/reference/fu-name-forced-hash-using-file.md).  
  
#### Para assemblies de referência com Adicionar Nova Referência  
  
1.  Esta é a maneira mais fácil de usar assemblies CLR.  Primeiro, certifique\-se de que o projeto seja compilado com a opção de compilador **\/clr** .  Em seguida, clique com o botão direito no projeto do **Gerenciador de Soluções** e selecione **Adicionar**, **Referências**.  A caixa de diálogo **Páginas de Propriedades** será exibida.  
  
2.  Da caixa de diálogo **Páginas de Propriedade**, selecione **Adicionar Nova Referência**.  Uma caixa de diálogo aparecerá listando qualquer assembly .NET, COM, e outros assemblies disponíveis no projeto atual.  Selecione o assembly desejado e clique em **OK**.  
  
     Assim que uma referência de projeto é definida, as dependências correspondentes são automaticamente tratadas.  Além disso, desde que os metadados façam parte de um assembly, não será preciso adicionar um arquivo ou criar um protótipo de elementos que estão sendo usados de assemblies gerenciados.  
  
## Fazendo referência a DLLs nativas ou a bibliotecas estáticas  
  
#### Para DLLs nativos de referência ou bibliotecas estáticas  
  
1.  Faça referência ao arquivo de cabeçalho apropriado em seu código usando a diretiva \#include.  O arquivo de cabeçalho deve estar no caminho de include ou na parte do projeto atual.  Para obter mais informações, consulte [Diretiva \#include](../preprocessor/hash-include-directive-c-cpp.md).  
  
2.  Você também pode definir dependências do projeto.  Definir as dependências do projeto garante duas coisas.  Primeiro, garante que os projetos sejam criados na ordem correta de forma que um projeto sempre possa localizar os arquivos dependentes de que você precisa.  Segunda, ele adiciona implicitamente o diretório de saída do projeto dependente ao caminho para que os arquivos possam ser encontrados facilmente no tempo de vinculação.  
  
3.  Para implantar o aplicativo, você precisará colocar o DLL em um local apropriado.  Pode ser um dos seguintes:  
  
    1.  O mesmo caminho do executável.  
  
    2.  Em qualquer lugar no caminho do sistema \(variável de ambiente **path**\).  
  
    3.  No assembly lado a lado.  Para obter mais informações, consulte [Compilando assemblies lado a lado do C\/C\+\+](../build/building-c-cpp-side-by-side-assemblies.md).  
  
## Trabalhando com projetos múltiplos  
 Por padrão, os projetos são compilados para que todos os arquivos de saída sejam criados em um subdiretório do diretório do projeto.  O diretório é nomeado com base na configuração de compilação \(por exemplo.  Depuração ou Versão\).  Para projetos irmãos fazerem referência uns aos outros, cada projeto deve adicionar explicitamente os outros diretórios de saída de projeto ao caminho dele para que a vinculação tenha êxito.  Isso é feito automaticamente quando você define as dependências do projeto.  No entanto, se você não usar dependências, deverá lidar com cuidado com isso porque as compilações podem se tornar muito difíceis de gerenciar.  Por exemplo, quando um projeto tem configurações de Depuração e Versão e inclui uma biblioteca externa de um projeto irmão, deverá usar um arquivo de biblioteca diferente dependendo da configuração que estiver sendo criada.  Assim, embutir esses caminhos pode ser complicado.  
  
 Todos os arquivos de saída essenciais \(como arquivos executáveis, incrementais de vinculador, e arquivos PDB\) são copiados em um diretório de solução comum.  Assim, ao trabalhar com uma solução que contém um número de projetos C\+\+ com configurações equivalentes, todos os arquivos de saída são centralizados para vinculação e implantação simplificadas.  Você pode ter certeza que seu aplicativo\/biblioteca funcionará conforme o esperado se os arquivos forem mantidos juntos \(já que há a garantia de os arquivos estarem no caminho\).  
  
 O local dos arquivos de saída pode ser um grande problema na implantação em um ambiente de produção.  Ao executar projetos no IDE, os caminhos para bibliotecas incluídas não são necessariamente os mesmos que o ambiente de produção.  Por exemplo, se você tiver `#using "../../lib/debug/mylib.dll"` no seu código mas então implantar mylib.dll em uma posição relativa diferente, o aplicativo falhará em tempo de execução.  Para evitar isso, você deve evitar usar caminhos relativos em instruções \#include em seu código.  É melhor garantir que os arquivos necessários estejam no caminho de compilação do projeto e, da mesma forma, assegurando\-se de que os arquivos de produção correspondentes estejam posicionados adequadamente.  
  
#### Como especificar para onde os arquivos de saída irão  
  
1.  O local das configurações de saída do projeto pode ser encontrado nas **Páginas de Propriedade** do projeto.  Expanda o nó ao lado de **Propriedades de Configuração** e selecione **Geral**.  O local de saída é especificado ao lado de **Diretório de Saída**.  Para obter mais informações, consulte [Página de propriedade geral \(projeto\)](../Topic/General%20Property%20Page%20\(Project\).md).  
  
## Consulte também  
 [Tipos de projeto do Visual C\+\+](../ide/visual-cpp-project-types.md)