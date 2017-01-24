---
title: "Guia de portabilidade e de atualiza&#231;&#227;o do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: f5fbcc3d-aa72-41a6-ad9a-a706af2166fb
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Guia de portabilidade e de atualiza&#231;&#227;o do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico fornece um guia para atualizar o código do Visual C\+\+. Isso inclui o código seja compilado e executado corretamente em uma versão mais recente das ferramentas, bem como tirar proveito da nova linguagem e recursos do Visual Studio. Este tópico também inclui informações sobre como migrar aplicativos herdados para plataformas mais modernos.  
  
## Motivos para atualizar o código do Visual C\+\+  
 Considere atualizar seu código pelos seguintes motivos:  
  
-   Código mais rápido, devido a otimizações do compilador aprimorada.  
  
-   Compilações mais rápidas, devido a melhorias de desempenho do compilador em si.  
  
-   Recursos de linguagem. Agora, o Visual C\+\+ implementa vários recursos de novos padrões de C\+\+.  
  
-   Melhor segurança. Recursos de segurança, como proteção de verificação.  
  
### Portar seu código  
 Ao atualizar, considere primeiro código de seu aplicativo e projetos. Seu aplicativo é criado com o Visual Studio?  Nesse caso, identifica os projetos envolvidos.  Você tem scripts de compilação personalizado?  Se você tiver scripts de compilação personalizado em vez de usar o sistema de compilação do Visual Studio, você terá mais trabalho a fazer na atualização, porque você não pode economizar tempo com o Visual Studio atualize seus arquivos de projeto e as configurações de compilação.  
  
 Compilação sistema e projeto de formato de arquivo no Visual Studio alterado de vcbuild nas versões para Visual Studio 2008 para MSBuild em versões do Visual Studio 2010 em diante. Se a atualização é de uma versão anterior 2010 e você tiver um sistema altamente personalizado de compilação, você terá que fazer mais trabalho para atualizar.  Se você estiver atualizando a partir do Visual Studio 2010 ou posterior, os projetos já estão usando MSBuild, para que atualizar o projeto e a compilação do seu aplicativo deve ser mais fácil.  
  
 Se você não estiver usando o sistema de compilação do Visual Studio, você deve considerar a atualização para usar o MSBuild. Se você atualizar para usar o MSBuild, você terá mais facilidade em atualizações futuras e é mais fácil de usar serviços como o Visual Studio Online. MSBuild oferece suporte a todas as plataformas de destino oferece suporte ao Visual Studio.  
  
### Portabilidade de projetos do Visual Studio  
 Para projetos maiores, convém atualizar apenas uma versão do Visual Studio ao mesmo tempo, pois caso contrário, pode ser difícil saber qual versão introduziu uma alteração de quebra específico que afetou o seu código.  
  
 Para começar a atualizar um projeto ou solução, abra a solução na nova versão do Visual Studio e siga os prompts para iniciar a atualização.  Quando você atualiza um projeto, você pode obter um relatório de atualização, que também é salvo na pasta do projeto como UpgradeLog.htm. O relatório de atualização mostra um resumo de quais problemas foram encontrados durante o processo de atualização e algumas informações sobre as alterações que foram feitas ou problemas que não pode ser resolvidos automaticamente.  
  
1.  Propriedades do projeto  
  
2.  Incluir arquivos  
  
3.  Código não compila corretamente devido a alterações de conformidade do compilador  
  
4.  Código que dependa de recursos do Visual Studio ou do Windows que não estão mais disponíveis ou arquivos de cabeçalho que não estão incluídos em uma instalação padrão do Visual Studio ou foram removidos do produto  
  
5.  Código não compila devido a alterações nas APIs como renomeado APIs, alterou assinaturas de função ou funções preteridas  
  
6.  Código não compila devido a alterações de diagnóstico, como se tornar um erro de aviso  
  
7.  Erros de vinculador devido às bibliotecas que foram alteradas, especialmente quando \/NODEFAULTLIB é usada.  
  
8.  Erros de tempo de execução ou resultados inesperados devido a alterações de comportamento  
  
9. Erros devido a erros que foram introduzidos nas ferramentas. Se você encontrar um problema, o relatório para a equipe de Visual C\+\+ por meio dos canais de suporte normal ou usando o [Centro de comentários do Visual Studio](http://connect.microsoft.com/VisualStudio/Feedback).  
  
 Além das alterações que você não pode evitar devido a erros de compilador, algumas alterações são opcionais em um processo de atualização, como:  
  
1.  Novos avisos podem significar que você deseja limpar seu código. Dependendo do diagnóstico específico, isso pode melhorar a portabilidade, conformidade com os padrões e segurança de seu código.  
  
2.  Talvez você queira tirar proveito dos novos recursos do compilador, como o [\/guard:cf \(habilitar o fluxo de controle proteger\)](../build/reference/guard-enable-control-flow-guard.md) opção de compilador, que adiciona verificações para a execução de código não autorizado.  
  
3.  Você pode atualizar algum código para usar os novos recursos de linguagem que simplificam o código, melhorar o desempenho de seus programas ou atualizar o código para usar bibliotecas modernas e em conformidade com padrões modernos e práticas recomendadas.  
  
 Depois de você ter atualizado o seu projeto \(e testou\), você também poderá considerar melhorar ainda mais seu código ou planejar a direção futura do seu código ou até mesmo reconsiderar a arquitetura do seu projeto. Será importante para seu código seja executado em outras plataformas?  Em caso afirmativo, quais plataformas?  C\+\+ é uma linguagem padronizada projetada com mobilidade e desenvolvimento de plataforma cruzada em mente, e ainda o código para muitos aplicativos do Windows está intimamente ligado à plataforma Windows. Você deseja refatorar seu código, separar as partes mais estão ligadas à plataforma do Windows?  
  
 E sua interface do usuário?  Se você estiver usando o MFC, convém atualizar a interface do usuário.  Você está usando qualquer um dos recursos mais recentes do MFC que foram introduzidos no 2008 como um Feature Pack?  Se você quiser dar aparência e funcionalidade mais recente de seu aplicativo sem reescrever o aplicativo inteiro, você pode considerar usando a APIs da faixa de opções no MFC ou alguns dos novos recursos do MFC.  
  
 Para adicionar uma nova interface de usuário da área de trabalho do Windows, você pode usar C \+ c\+\+ \/CX \(extensões de componente\), ou adicionar código gerenciado em c\# e uma camada de interoperabilidade no C \+ c\+\+ CLI para conectar\-se de que c\# com o código nativo.  
  
 Como alternativa, talvez você agora tem novos requisitos ou você pode prever a necessidade de direcionamento de plataformas diferentes do Windows desktop, como Windows Phone ou dispositivos com Android. Você pode portar seu código de interface do usuário em uma biblioteca de interface do usuário de plataforma cruzada. Com essas estruturas de interface do usuário, você pode direcionar vários dispositivos e ainda usar o Visual Studio e o depurador do Visual Studio como ambiente de desenvolvimento.  
  
## Tópicos relacionados  
  
|Título|Descrição|  
|------------|---------------|  
|[Atualizando projetos a partir de versões anteriores do Visual C\+\+](../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md)|Discute como usar projetos criados em versões anteriores do Visual C\+\+.|  
|[Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md)|Uma lista de alterações na bibliotecas do Visual C\+\+ e ferramentas de compilação que podem exigir alterações em seu código.|  
|[Melhorias de conformidade do compilador do Visual C\+\+ 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md)|Uma lista de melhorias de conformidade e outras alterações no compilador do Visual C\+\+ que podem exigir alterações em seu código.|  
|[Portando e atualizando: exemplos e estudos de caso](../porting/porting-and-upgrading-examples-and-case-studies.md)|Para essa seção, é transportado e atualiza vários exemplos e os aplicativos e discutido o experiências e os resultados. Você pode achar que ler essas dá é você uma noção do que participar de portabilidade e atualização de processo. Durante o processo, discutir dicas e truques para atualizar e mostrar específicos como erros foram corrigidos.|  
|[Portando para a Plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md)|Contém informações sobre como mover o código para Windows 10|  
|[Introdução ao Visual C\+\+ para usuários do UNIX](../porting/introduction-to-visual-cpp-for-unix-users.md)|Fornece informações para usuários do UNIX novatos no [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] e deseja se tornar produtivo com ele.|  
|[Portando de UNIX para Win32](../porting/porting-from-unix-to-win32.md)|Descreve as opções para migrar aplicativos UNIX para Windows.|  
|[Primer de migração C\+\+\/CLI](../dotnet/cpp-cli-migration-primer.md)|Mostra detalhadamente como atualizar suas extensões gerenciadas para a sintaxe do C\+\+ para usar a nova sintaxe. Para obter mais informações, consulte [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md).|  
  
## Consulte também  
 [Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md)