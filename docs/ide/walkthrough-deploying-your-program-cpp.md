---
title: "Instru&#231;&#245;es passo a passo: implantando o programa (C++) | Microsoft Docs"
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
  - "Implantando aplicativos [C++], instruções passo a passo"
  - "projeto de instalação [C++]"
  - "implantações de programa [C++]"
  - "configuração de projetos [C++]"
  - "projetos [C++], Implantando programas"
  - "implantação de aplicativo [C++], instruções passo a passo"
ms.assetid: 79e6cc4e-dced-419d-aaf7-d62d1367603f
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: implantando o programa (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Agora que você criou seu aplicativo completando passo a passo relacionados anteriormente, que estão listados em [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md), a última etapa é criar um instalador de modo que outros usuários possam instalar o programa em seus computadores.  Para fazer isso, você adicionará um novo projeto à solução existente.  A saída desse novo projeto é um arquivo setup.exe que instalará o seu aplicativo em outro computador.  
  
 Essa explicação passo a passo mostra como usar o Windows Installer para implantar seu aplicativo.  Você também pode usar o ClickOnce para implantar um aplicativo.  Para obter mais informações, consulte [ClickOnce Implantação para aplicativos do Visual C\+\+](../ide/clickonce-deployment-for-visual-cpp-applications.md).  Para obter mais informações sobre implantação em geral, consulte [Implantando aplicativos, serviços e componentes](../Topic/Deploying%20Applications,%20Services,%20and%20Components.md).  
  
## Pré-requisitos  
  
-   Esta explicação passo a passo pressupõe que você compreenda os fundamentos da linguagem C\+\+.  
  
-   Também pressupõe que você tenha concluído os passo a passo relacionados anteriormente, que estão listados em [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
-   Essa explicação passo a passo não pode ser concluído nas edições Express do Visual Studio.  
  
-   Caso você ainda não tenha feito isso, baixe a Edição Limitada do InstallShield \(ISLE\), conforme descrito nas etapas posteriores neste artigo.  ISLE é gratuito para desenvolvedores do Visual Studio e substitui a funcionalidade dos modelos de projeto de instalação e implantação nas edições anteriores do Visual Studio.  
  
### Para instalar o modelo de projeto da configuração e implantação de ILHA  
  
1.  Quando você estiver conectado à Internet, na barra de menus, selecione **Arquivo**, **Novo**, **Projeto** para abrir a caixa de diálogo **Novo Projeto**.  
  
2.  No painel esquerdo da caixa de diálogo, expanda os nós **Instalado**, **Modelos** e **Outros Tipos de Projetos**, e selecione **Instalação e Implantação**.  No painel central, selecione **Habilitar InstallShield Limited Edition** e escolha o botão **OK**.  
  
3.  Siga as instruções para instalar o InstallShield Limited Edition para Visual Studio \(ISLE\).  
  
4.  Depois que você baixou, instalou e ativou o ISLE, feche o Visual Studio e reabra\-o.  
  
5.  Na barra de menus, escolha **Arquivo**, **Projetos e Soluções Recentes**, e então escolha a solução **Jogo** para reabri\-lo.  
  
### Para criar um projeto de configuração e instalar seu programa  
  
1.  Altere a configuração ativa de solução para Release.  Na barra de menus, escolha **Compilar**, **Gerenciador de Configurações**.  Na caixa de diálogo **Gerenciador de Configurações**, na lista suspensa **Configuração da solução ativa**, selecione **Versão**.  Escolha o botão **Fechar** para salvar a configuração.  
  
2.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto** para abrir a caixa de diálogo **Novo Projeto**.  
  
3.  No painel esquerdo da caixa de diálogo, expanda os nós **Instalado**, **Modelos** e **Outros Tipos de Projetos**, e selecione **Instalação e Implantação**.  No painel central, selecione **Projeto InstallShield Limited Edition**.  
  
4.  Insira um nome para o projeto de configuração na caixa **Nome**.  Para esse exemplo, digite Instalador do jogo.  Na lista suspensa **Solução**, selecione **Adicionar para solução**.  Escolha o botão **OK** para criar o projeto de configuração.  Uma guia **Assistente de Projeto \(Instalador de Jogos\)** é aberta na janela do editor.  
  
5.  Na parte inferior da guia **Assistente de Projeto \(Instalador do Jogo\)**, escolha o link **Informações do Aplicativo**.  
  
6.  Na página **Informações do Aplicativo**, especifique o nome da empresa como você deseja que ele apareça no instalador.  É possível usar seu próprio nome da empresa, ou para esse exemplo, use Contoso.  Especifique o nome do seu aplicativo; neste exemplo, especifique Jogo.  Especificar o endereço Web da empresa ou, para este exemplo, use http:\/\/www.contoso.com.  
  
7.  Na parte inferior da guia **Assistente de Projeto \(Instalador do Jogo\)**, escolha o link **Entrevista de Instalação**.  
  
8.  Na página **Entrevista de Instalação**, em **Você deseja exibir uma Caixa de Diálogo de Contrato de Licença**, selecione o botão de opção **Não**.  Em **Você deseja solicitar aos usuários para que insiram seu nome de empresa e nome de usuário**, clique no botão de opção **Não**.  
  
9. Em **Gerenciador de Soluções**, expanda o projeto **Instalador do Jogo**, expanda o nó **Organize sua Configuração** e abra a página **Informações Gerais**.  
  
10. Na guia **Informações Gerais \(instalador do jogo\)** na janela do editor, especifique uma **Identificação do Criador de Guia**, por exemplo, regid.2012\-12.com.Contoso.  
  
11. Em **Gerenciador de Soluções**, no projeto **Instalador do Jogo**, expanda o nó **Especificar Dados do Aplicativo** e abra a página **Arquivos**.  
  
12. Na guia **Arquivos \(instalador do jogo\)** na janela do editor, em **Arquivos de origem do computador**, abra o menu de atalho para **Saída Primária do Jogo** e escolha **Copiar**.  
  
13. Abra um menu de atalho no espaço sob a coluna **Nome** em **Arquivos do computador de destino** e escolha **Colar**.  Um novo item chamado **Game.Primary Output** aparece.  
  
14. Em **Gerenciador de Soluções**, no nó de **Especificar Dados de Aplicativo**, abra a página **Redistribuíveis**.  
  
15. Na guia **Redistribuíveis \(instalador do jogo\)** na janela do editor, selecione a caixa de seleção **Visual C\+\+ 11.0 CRT \(x86\)**.  
  
16. Na barra de menus, escolha **Compilar**, **Compilar Solução**, para compilar o projeto e jogo e o projeto de instalação do jogo.  
  
17. Na pasta de solução, localize o programa setup.exe que foi compilado a partir do projeto de instalação do jogo, e o execute para instalar o aplicativo do jogo no seu computador.  É possível copiar esse arquivo para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador.  
  
18. É possível definir muitas opções no projeto de configuração para atender às suas necessidades.  Para obter mais informações, em **Gerenciador de Soluções**, no projeto **Instalador do jogo**, abra a página **Introdução** e aperte a tecla F1 para abrir a biblioteca de ajuda ISLE.  
  
## Próximas etapas  
 **Anterior:** [Instruções passo a passo: depurando um projeto \(C\+\+\)](../ide/walkthrough-debugging-a-project-cpp.md)  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)