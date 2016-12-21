---
title: "Especificando ferramentas de compila&#231;&#227;o personalizadas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCCustomBuildTool.CustomBuildToolBeforeTargets"
  - "VC.Project.VCCustomBuildTool.Outputs"
  - "VC.Project.VCCustomBuildTool.Command"
  - "VC.Project.VCCustomBuildTool.CommandLine"
  - "VC.Project.VCCustomBuildTool.AdditionalDependencies"
  - "VC.Project.VCCustomBuildTool.Message"
  - "VC.Project.VCCustomBuildTool.CustomBuildToolAfterTargets"
  - "VC.Project.VCCustomBuildTool.Description"
  - "VC.Project.VCCustomBuildTool.AdditionalInputs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ferramentas de compilação (C++), especificando"
  - "compilações (C++), ferramentas de compilação personalizadas"
  - "ferramentas de compilação personalizadas (C++), especificando"
ms.assetid: e5161946-8002-418d-991e-219e6a8586f5
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especificando ferramentas de compila&#231;&#227;o personalizadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*Uma ferramenta de criação personalizado* fornece o sistema de compilação as informações necessárias para criar arquivos de entrada específicos.  Uma ferramenta de criação personalizado especifica um comando a ser executado, uma lista de arquivos de entrada, uma lista de arquivos de saída que são gerados pelo comando, e uma descrição opcional da ferramenta.  
  
 Para obter informações gerais sobre as ferramentas personalizadas de compilação e das etapas de criação personalizado, consulte [Noções básicas de etapas e eventos de compilação personalizados](../ide/understanding-custom-build-steps-and-build-events.md).  
  
### Para especificar uma ferramenta de criação personalizado  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter mais informações, consulte [Propriedades do projeto do Visual C\+\+ de configuração](../ide/working-with-project-properties.md).  
  
2.  Clique em **Propriedades de Configuração** para habilitar a caixa de **Configuração** .  Na caixa de **Configuração** , selecione a configuração a qual você deseja especificar uma ferramenta de criação personalizado.  
  
3.  Em **Gerenciador de Soluções**, selecione o arquivo de entrada para a ferramenta de criação personalizado.  
  
     Se a pasta de **Ferramenta de Compilação Personalizada** não aparecer, a extensão do arquivo que você selecionou é associada a uma ferramenta padrão.  Por exemplo, a ferramenta padrão para .c e arquivos .cpp é o compilador.  Para substituir uma ferramenta padrão que define, no nó de **Propriedades de Configuração** , na pasta de **Geral** , na propriedade de **Tipo de Item** , clique em **Ferramenta de Compilação Personalizada**.  Clique em **Aplicar** e o nó de **Ferramenta de Compilação Personalizada** são exibidos.  
  
4.  No nó de **Ferramenta de Compilação Personalizada** , na pasta de **Geral** , especifique as propriedades associadas com a ferramenta de criação personalizado:  
  
    -   Em **Dependências Adicionais**, especifique outros arquivos além do para que a ferramenta de criação personalizado está sendo definida \(o arquivo associado com a ferramenta de criação personalizado é considerado implicitamente uma entrada para a ferramenta\).  Ter arquivos de entrada adicionais não é um requisito para uma ferramenta de criação personalizado.  Se você tiver mais de uma entrada adicional, separe\-os com ponto\-e\-vírgula.  
  
         Se a data de um arquivo de **Dependências Adicionais** for posterior ao arquivo de entrada, a ferramenta de criação personalizado é executada.  Se todos os arquivos de **Dependências Adicionais** sejam mais antigos do que o arquivo de entrada, e o arquivo de entrada for mais antigo que o arquivo de propriedade de **Saídas** , a ferramenta de criação personalizado não será executada.  
  
         Por exemplo, suponhamos que você tenha uma ferramenta de criação personalizado que usem MyInput.x como entrada e gerenciar MyInput.cpp, e que MyInput.x inclui um arquivo de cabeçalho, MyHeader.h.  Você pode especificar MyHeader.h como uma dependência de entrada a MyInput.x, e o sistema de compilação criará MyInput.cpp quando estiver expirado em relação a MyInput.x ou a MyHeader.h.  
  
         As dependências de entrada também podem garantir que sua execução personalizada das ferramentas de criação na ordem você precisa das.  No exemplo anterior, suponha que MyHeader.h é realmente a saída de uma ferramenta de criação personalizado.  Como MyHeader.h é uma dependência de MyInput.x, o sistema de compilação criará primeiro Myheader.h antes de executar a ferramenta de criação personalizado em MyInput.x.  
  
    -   Em **Linha de Comando**, especifique um comando como se você especificou no prompt de comando.  Especifique um comando ou um arquivo em lotes válido, e qualquer entrada ou de saída arquivos necessários.  Especifique o comando do lote de **call** antes do nome de um arquivo em lotes garantir que todos os comandos subsequentes serão executados.  
  
         A vários arquivos de entrada e de saída podem ser especificados simbolicamente com macros de MSBuild.  [!INCLUDE[crabout](../Token/crabout_md.md)] que especificam o local dos arquivos, ou os nomes dos conjuntos de arquivos, consulte [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md).  
  
         Como o caractere “%” é permitido por MSBuild, se você especificar uma variável de ambiente substituir cada caractere de escape de **%** com a sequência de escape hexadecimal de **%25** .  Por exemplo, substitua **%WINDIR%** com **%25WINDIR%25**.  MSBuild substitui cada sequência de **%25** com o caractere de **%** antes de acessar a variável de ambiente.  
  
    -   Em **Descrição**, digite uma mensagem descritivas sobre essa ferramenta personalizado de compilação.  A mensagem será impressa à janela de **Saída** quando o sistema de compilação processa esta ferramenta.  
  
    -   Em **Saídas**, especifique o nome do arquivo de saída.  Essa é uma entrada necessária; sem um valor para essa propriedade, a ferramenta de criação personalizado não será executado.  Se uma ferramenta de criação personalizado tiver mais de uma saída, nomes de arquivos separados por um ponto\-e\-vírgula.  
  
         O nome do arquivo de saída deve ser o mesmo que é especificado na propriedade de **Linha de Comando** .  O sistema de construção do projeto procurará o arquivo e verificará a data.  Se o arquivo de saída for mais novo que o arquivo de entrada ou se o arquivo de saída não está localizado, a ferramenta de criação personalizado é executada.  Se todos os arquivos de **Dependências Adicionais** sejam mais antigos do que o arquivo de entrada, e o arquivo de entrada for mais antigo que o arquivo especificado na propriedade de **Saídas** , a ferramenta de criação personalizado não será executada.  
  
 Se desejar que o sistema de compilação para funcionar em um arquivo de saída gerado pela ferramenta de criação personalizado, você deve adicioná\-la manualmente ao projeto.  A ferramenta de criação personalizado atualizará o arquivo durante a compilação.  
  
## Exemplo  
 Assuma que você quer incluir em seu projeto um arquivo chamado parser.l.  Você desejar um analisador léxica para processar parser.l para gerar o arquivo de C.A. que tem o mesmo nome de base \(parser.c\).  
  
 Primeiro, você adiciona parser.l e parser.c ao projeto.  Se os arquivos ainda não existem, você adiciona apenas uma referência aos arquivos.  Você cria uma ferramenta de criação personalizado para parser.l e digite o seguinte na propriedade de **Comandos** :  
  
```  
lexer %(FullPath) .\%(Filename).c  
```  
  
 Este comando executará o analisador léxica em parser.l e a saída parser.c para o diretório do projeto.  
  
 Na propriedade de **Saídas** , digite o seguinte:  
  
```  
.\%(Filename).c  
```  
  
 Quando você cria o projeto, o sistema de compilação compara os carimbos de data\/hora de parser.l e de parser.c.  Se parser.l for mais recente, ou se parser.c não existir, o sistema de compilação executa o valor da propriedade de **Linha de Comando** para trazer parser.c atualizado.  Desde que parser.c também foi adicionado ao projeto, o sistema de construção a seguir cria parser.c.  
  
## Consulte também  
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)   
 [Solucionando problemas de personalizações da compilação](../ide/troubleshooting-build-customizations.md)