---
title: "Altera&#231;&#245;es no sistema de compila&#231;&#227;o | Microsoft Docs"
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
  - "vc.msbuild.changes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "alterações no sistema de compilação, $(Inherit)"
  - "alterações no sistema de compilação, $(NoInherit)"
  - "alterações no sistema de compilação, .vsprops"
  - "alterações no sistema de compilação, regras de compilação personalizadas"
  - "alterações no sistema de compilação, MSBuild"
  - "alterações no sistema de compilação, arquivo de projeto (.vcxprog)"
  - "MSBuild, alterações no sistema de compilação"
ms.assetid: e564d95f-a6cc-4d97-b57e-1a71daf66f4a
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Altera&#231;&#245;es no sistema de compila&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O sistema de MSBuild é usado para construir projetos do Visual C\+\+.  No entanto, no Visual Studio 2008 e em versões anteriores, o sistema de VCBuild foi usado.  Determinados tipos de arquivo e conceitos que dependem de VCBuild não existir ou são representados do sistema atual.  Este documento discute as diferenças no sistema atual de compilação.  
  
## .vcproj agora é .vcxproj  
 Os arquivos de projeto ainda não usam a extensão de nome de arquivo de .vcproj.  Visual Studio converte automaticamente os arquivos de projeto que foram criados por uma versão anterior do Visual C\+\+ para o formato usado pelo sistema atual.  Para obter mais informações sobre como atualizar manualmente um projeto do, consulte [\/Upgrade](../Topic/-Upgrade%20\(devenv.exe\).md).  
  
 Na versão atual, a extensão de nome de arquivo para um arquivo de projeto é .vcxproj.  
  
## .vsprops agora é .props  
 Em versões anteriores, *uma folha de propriedade do projeto* é um arquivo baseado em XML com uma extensão de nome de arquivo de .vsprops.  Uma folha de propriedade do projeto permite especificar opções para ferramentas de criação como o compilador ou o vinculador e criar macros definidos pelo usuário.  
  
 Na versão atual, a extensão de nome de arquivo para uma folha de propriedade do projeto é .props.  
  
## Regras personalizadas da construção e arquivos de .rules  
 Em versões anteriores, *um arquivo de regra* é um arquivo baseado em XML com uma extensão de nome de arquivo de .rules.  Um arquivo de regra permite definir regras personalizadas da construção e incorporar\-las no processo de criação de um projeto do Visual C\+\+.  Uma regra personalizada de construção, que pode ser associada a uma ou mais extensões de nome de arquivo, permite passar arquivos de entrada a uma ferramenta que cria um ou mais arquivos de saída.  
  
 Nesta versão, as regras personalizados de compilação são representadas por três tipos de arquivo, .xml, .props, e .targets, em vez de um arquivo de .rules.  Quando um arquivo de .rules que foi criada usando uma versão anterior do Visual C\+\+ for migrado para a versão atual, os arquivos de equivalente .xml, de .props, e o .targets são criados e armazenados em seu projeto com o arquivo original .rules.  
  
> [!IMPORTANT]
>  Na versão atual, [!INCLUDE[TLA2#tla_ide](../build/includes/tla2sharptla_ide_md.md)] não oferece suporte à criação de novas regras.  Por esse motivo, a maneira mais fácil de usar um arquivo de regra de um projeto criado com uma versão anterior do Visual C\+\+ é migrar o projeto à versão atual.  
  
## Macros de herança  
 Em versões anteriores, a macro de **$\(Inherit\)** especifica a ordem em que herdou propriedades aparecem na linha de comando que é composto pelo sistema de criação do projeto.  A macro de **$\(NoInherit\)** faz com que todas as ocorrências de $ \(herde\) a serem ignorados e causas de quaisquer propriedades que são herdadas de outra forma, não ser herdado.  Por exemplo, por padrão os arquivos macro das causas de $ \(herde\) especificados usando a opção de compilador de [\/I \(Adicional inclua diretórios\)](../build/reference/i-additional-include-directories.md) ser anexado à linha de comando.  
  
 Na versão atual, a herança é suportada especificando o valor de uma propriedade como concatenação de um ou mais valores literais e macros da propriedade.  Macros de **$\(Inherit\)** e de **$\(NoInherit\)** não têm suporte.  
  
 No exemplo a seguir, uma lista delimitada por ponto\-e\-vírgula é atribuída a uma propriedade em uma página de propriedades.  A lista consistir na concatenação de *\<value\>* literal e o valor da propriedade de `MyProperty` , que pode ser acessada usando a notação macro, **$\(***MyProperty***\)**.  
  
```  
Property=<value>;$(MyProperty)  
```  
  
## arquivos de .vcxproj.user  
 Um arquivo de usuário \(\) .vcxproj.user armazena propriedades específicas do usuário, por exemplo, depurar e configurações de implantação.  O arquivo de vcxproj.user se aplica a todos os projetos para um usuário específico.  
  
## .vcxproj.filters Arquivo  
 Quando **Gerenciador de Soluções** é usado para adicionar um arquivo a um projeto, o arquivo de filtros \(.vcxproj.filters\) define onde na exibição de árvore de **Gerenciador de Soluções** o arquivo é adicionado, com base na sua extensão de nome de arquivo.  
  
## Configurações de diretórios de VC\+\+  
 As configurações de diretórios do Visual C\+\+ são especificadas em [Página de propriedade dos diretórios do VC\+\+](../ide/vcpp-directories-property-page.md).  Em versões anteriores do Visual Studio, as configurações de diretórios aplicam pelo usuário e a lista de diretórios excluídos é especificada no arquivo de sysincl.dat.  
  
 Você não pode alterar as configurações de diretórios de VC\+\+ se você executar [devenv \/resetsettings](../Topic/-ResetSettings%20\(devenv.exe\).md) na linha de comando.  Você também não pode alterar as configurações se você abre o menu de **Ferramentas** , clique em **Importar e exportar configurações**, e selecione a opção de **Redefinir todas as configurações** .  
  
 Migrar configurações de diretórios de VC\+\+ de um arquivo de .vssettings criado por uma versão anterior do Visual C\+\+.  Abrir o menu de **Ferramentas** , clique **Importar e exportar configurações**, **Importar configurações de ambiente selecionadas**selecione, e siga as instruções no assistente.  Ou quando você iniciar o Visual Studio pela primeira vez, na caixa de diálogo de **Escolher Configurações de Ambiente Padrão** , **Migrar minhas configurações qualificadas de uma versão anterior e aplicá\-las em acréscimo às configurações padrão selecionadas abaixo**selecione.  
  
## Consulte também  
 [MSBuild \(Visual C\+\+\)](../Topic/MSBuild%20\(Visual%20C++\).md)