---
title: "Como criar projetos C++ verific&#225;veis (C++/CLI) | Microsoft Docs"
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
  - "conversões, projetos C++"
  - "assemblies verificáveis [C++], criando"
  - "Projetos Visual C++"
ms.assetid: 4ef2cc1a-e3e5-4d67-8d8d-9c614f8ec5d3
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar projetos C++ verific&#225;veis (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Assistentes do aplicativo do Visual C\+\+ não criam projetos verificáveis, mas os projetos podem ser convertidos para ser verificáveis.  Este tópico descreve como definir as propriedades do projeto e modificar arquivos de origem do projeto para transformar seus projetos do Visual C\+\+ gerar aplicativos verificáveis.  
  
## Configurações do compilador e do vinculador  
 Por padrão, os projetos .NET usam o sinalizador de compilador de \/clr e configurar o vinculador para focar o hardware x86.  Para o código verificável, você deve usar o sinalizador de \/clr:safe , e você deve instruir o vinculador para gerar MSIL em vez de instruções do computador nativos.  
  
#### Para alterar as configurações do compilador e do vinculador  
  
1.  Exibir a página de propriedades do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md).  
  
2.  Na página de **Geral** no nó de **Propriedades de Configuração** , defina a propriedade de **Suporte a Common Language Runtime** a **Suporte seguro de MSIL Common Language Runtime \(\/clr: seguras\)**.  
  
3.  Na página de **Avançado** no nó de **Vinculador** , defina a propriedade de **Tipo de Imagem CLR** a **A intensidade IL seguro imagens \(\/CLRIMAGETYPE: SAFE\)**.  
  
## Removendo tipos de dados nativos  
 Como os tipos de dados nativos não são verificáveis, mesmo que não são usados na verdade, você deve descartar todos os arquivos de cabeçalho que contêm tipos nativos.  
  
> [!NOTE]
>  O procedimento a seguir aplica o Windows Forms a projetos do aplicativo .NET \(\) e do aplicativo de console \(.NET\).  
  
#### Para remover referências aos tipos de dados nativos  
  
1.  Utilização de comentários para fora tudo no arquivo de Stdafx.h.  
  
## Configurando um ponto de entrada  
 Como os aplicativos verificáveis não podem usar as bibliotecas de tempo de execução C \(CRT\), não pode depender do CRT para chamar a função principal como o ponto de entrada padrão.  Isso significa que você deve fornecer o nome da função a ser chamada inicialmente ao vinculador. \(Nesse caso, Main\(\) é usado em vez de main\(\) ou de \_tmain\(\) para indicar um ponto de entrada não CRT, mas como o ponto de entrada deve ser especificado explicitamente, esse nome é arbitrário.\)  
  
> [!NOTE]
>  Os procedimentos a seguir se aplicam para projetos do aplicativo de console \(.NET\).  
  
#### Para configurar um ponto de entrada  
  
1.  Alteração \_tmain\(\) a Main\(\) no arquivo .cpp do principal do projeto.  
  
2.  Exibir a página de propriedades do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md).  
  
3.  Na página de **Avançado** no nó de **Vinculador** , entre em `Principal` como o valor da propriedade de **Ponto de entrada** .  
  
## Consulte também  
 [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md)