---
title: "Portando de UNIX para Win32 | Microsoft Docs"
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
  - "APIs [C++], movimentando para Win32"
  - "migração [C++]"
  - "movimentando para Win32 [C++]"
  - "movimentando para Win32 [C++], de UNIX"
  - "UNIX [C++], movimentando para Win32"
  - "Aplicativos Win32 [C++], migrando de UNIX"
  - "API do Windows [C++], migrando de UNIX"
ms.assetid: 3837e4fe-3f96-4f24-b2a1-7be94718a881
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Portando de UNIX para Win32
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao migrar aplicativos UNIX para Windows, você tem várias opções:  
  
-   Usando bibliotecas de UNIX para portar aplicativos UNIX para Win32  
  
-   Portando aplicativos do UNIX para Win32 nativo  
  
-   Execução de aplicativos do UNIX no Windows usando o subsistema POSIX  
  
## Bibliotecas do UNIX  
 Os programadores do UNIX uma opção considere normalmente está usando bibliotecas de tipo UNIX de terceiros para permitir que sua compilação de código UNIX como um executável do Win32.  Vários comerciais \(e pelo menos um domínio público\) bibliotecas de fazer isso.  Essa é uma opção para alguns aplicativos.  A vantagem dessas bibliotecas de portabilidade é minimizar o esforço de portagem inicial.  A principal desvantagem de um produto de software concorrente, é que uma porta Win32 nativa de um aplicativo geralmente será mais rápida e, inevitavelmente, terá mais funcionalidade.  Pode ser complicado para o aplicativo para a etapa fora do seu shell UNIX se precisar fazer chamadas do Win32 para obter mais energia do Windows.  
  
 A lista a seguir fornece recursos de terceiros para portabilidade e oferecer suporte a migração do UNIX para o Visual C\+\+ e Microsoft:  
  
### Guias de migração do UNIX  
 Guia de migração de aplicativos UNIX personalizados fornece ajuda técnica sobre migração de código do UNIX para o ambiente Win32.  
  
 [http:\/\/go.microsoft.com\/fwlink\/?LinkId\=95428](http://go.microsoft.com/fwlink/?LinkId=95428)  
  
 O Unix Migration Project Guide complementa o guia de migração de aplicativos UNIX personalizados, fornecendo alto nível ajuda em projetos substanciais de migração do UNIX para Win32.  O guia fornece conselhos sobre problemas a serem considerados em cada fase da migração de projeto.  O guia pode ser baixado em:  
  
 [http:\/\/go.microsoft.com\/fwlink\/?linkid\=20012](http://go.microsoft.com/fwlink/?linkid=20012)  
  
### Microsoft Windows Services for UNIX \(SFU\)  
 Microsoft Windows Services for UNIX \(SFU\) oferece uma gama completa de serviços de plataforma cruzada para integrar o Windows em ambientes UNIX.  Serviços para UNIX fornece compartilhamento de arquivos, acesso remoto e administração, a sincronização de senha, gerenciamento de diretório comum, um conjunto comum de utilitários e um shell.  
  
 [Windows Services for UNIX](http://www.microsoft.com/downloads/details.aspx?FamilyID=896c9688-601b-44f1-81a4-02878ff11778&displaylang=en)  
  
### InteropSystems.com  
 [http:\/\/www.interopsystems.com\/](http://www.interopsystems.com/)  
  
 Um terceiro site para uma empresa que fornece suporte a portabilidade do UNIX para Win32 de software.  
  
### Site do aumento do C\+\+  
 [http:\/\/boost.sourceforge.net\/regression\-logs\/](http://boost.sourceforge.net/regression-logs/)  
  
 [http:\/\/boost.sourceforge.net\/boost\-build2\/](http://boost.sourceforge.net/boost-build2/)  
  
## Portando aplicativos UNIX diretamente para Win32  
 Outra opção é portar aplicativos UNIX diretamente ao Win32.  Usando o ANSI C\/C\+\+ e bibliotecas de compilador C comerciais, muitos do sistema tradicional dependiam chamadas por aplicativos UNIX estão disponíveis em aplicativos Win32.  
  
 O modelo de saída de **stdio**\-aplicativos baseados no não precisa ser alterado, desde o console Win32 APIs imitam o **stdio** modelo e versões do *curse* existe esse console de uso do Win32 APIs.  Para obter mais informações, consulte [SetConsoleCursorPosition](http://msdn.microsoft.com/library/windows/desktop/ms686025).  
  
 Aplicativos baseados em soquetes de Berkeley necessitam muito poucas alterações para funcionar como aplicativos Win32.  A interface do Windows Sockets foi projetada para portabilidade com soquetes BSD, com alterações mínimas são indicadas nas seções Introdução da especificação do WinSock.  
  
 O Windows oferece suporte a RPC compatível com DCE, para que aplicativos baseados em RPC são fáceis de usar.  Consulte [funções RPC](http://msdn.microsoft.com/library/windows/desktop/aa378623).  
  
 Uma das maiores áreas de diferença está no modelo de processo.  UNIX tem **bifurcação**; Win32 não.  Dependendo do uso do **bifurcação** e a base de código Win32 tem duas APIs que podem ser usados: **CreateProcess** e `CreateThread`.  Um aplicativo UNIX que bifurcações de várias cópias de si mesmo pode ser corrigido no Win32 ter vários processos ou um único processo com vários threads.  Se vários processos forem usados, há vários métodos do IPC que pode ser usado para comunicação entre processos \(e talvez para atualizar o código e os dados do novo processo como pai, se a funcionalidade que **bifurcação** fornece é necessária\).  Para obter mais informações sobre IPC, consulte [Interprocess comunicações](http://msdn.microsoft.com/library/windows/desktop/aa365574).  
  
 Modelos de gráficos de UNIX e Windows são muito diferentes.  UNIX usa a GUI do sistema de janela X, enquanto o Windows usa GDI.  Embora semelhantes em conceito, não há nenhum mapeamento simple da API X para a API de GDI.  No entanto, suporte OpenGL está disponível para migração de aplicativos baseados em UNIX OpenGL.  E há clientes e servidores do Windows.  Consulte [contextos de dispositivo](http://msdn.microsoft.com/library/windows/desktop/dd183553) para obter informações sobre GDI.  
  
 Aplicativos básicos do UNIX, incluindo muitos aplicativos CGI, devem portar facilmente para o Visual C\+\+ em execução no Windows.  Funções como **Abrir**, `fopen`, **ler**, **gravar** e outras estão disponíveis na biblioteca de tempo de execução do Visual C\+\+.  Além disso, há um mapeamento individual entre as APIs do UNIX C e APIs do Win32: **Abrir** para **CreateFile**, **ler** para **ReadFile**, **gravar** para **WriteFile**, `ioctl` para **DeviceIOControl**, **Fechar** para **CloseFile**, e assim por diante.  
  
## Subsistema POSIX do Windows  
 Outra opção UNIX programadores examinar é o subsistema POSIX do Windows.  No entanto, ele suporta apenas 1003.1 POSIX, que era a única versão POSIX padronizada quando o Windows NT foi criado.  Desde então, houve pouca demanda para estender esse subsistema, porque a maioria dos aplicativos foram convertidos em Win32.  O sistema 1003.1 é de interesse limitado para aplicativos completos, porque ele não inclui muitos recursos \(como aqueles em 1003.2, suporte de rede e assim por diante\).  Aplicativos em destaque total executados sob o subsistema POSIX do Windows não têm acesso a recursos do Windows disponíveis para aplicativos do Win32, como arquivos mapeados na memória, rede e gráficos.  Aplicativos como VI, LS e GREP são os principais alvos para o subsistema POSIX do Windows.  
  
## Consulte também  
 [Portabilidade programas](http://msdn.microsoft.com/pt-br/c36c44b3-5a9b-4bb4-9b7a-469aa770ed00)   
 [UNIX](../Topic/UNIX.md)   
 [Regras de inferência](../build/inference-rules.md)