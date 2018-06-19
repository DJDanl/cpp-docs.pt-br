---
title: Guia de atualização e portabilidade do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f5fbcc3d-aa72-41a6-ad9a-a706af2166fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 084c689ad7720e36670130d552522aa2f593218e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33846591"
---
# <a name="visual-c-porting-and-upgrading-guide"></a>Guia de atualização e portabilidade do Visual C++
Este tópico fornece um guia para atualizar o código do Visual C++. Isso inclui fazer com que o código seja compilado e executado corretamente em uma versão mais recente das ferramentas, bem como tirar proveito da nova linguagem e dos recursos do Visual Studio. Este tópico também inclui informações sobre como migrar aplicativos herdados para plataformas mais modernas.  
  
## <a name="reasons-to-upgrade-visual-c-code"></a>Motivos para atualizar o código do Visual C++  
 Considere atualizar seu código pelos seguintes motivos:  
  
-   Código mais rápido, devido às otimizações do compilador aprimoradas.  
  
-   Compilações mais rápidas, devido às melhorias de desempenho do próprio compilador.  
  
-   Conformidade com os padrões aprimorada. Agora o Visual C++ implementa vários recursos dos padrões mais recentes do C++.  
  
-   Melhor segurança. Recursos de segurança, como proteção de verificação.  
  
### <a name="porting-your-code"></a>Fazer portabilidade do seu código  
 Ao atualizar, considere primeiro o código e os projetos do seu aplicativo. Seu aplicativo foi compilado com o Visual Studio?  Se sim, identifique os projetos envolvidos.  Você tem scripts de build personalizados?  Se você tiver scripts de build personalizados em vez de usar o sistema de build do Visual Studio, você terá mais trabalho a fazer na atualização, porque você não poderá economizar tempo com o Visual Studio atualizando seus arquivos de projeto e configurações de build.  
  
 O sistema de build e o formato de arquivo de projeto no Visual Studio foi alterado de vcbuild nas versões até o Visual Studio 2008 para MSBuild nas versões do Visual Studio 2010 em diante. Se a atualização é de uma versão anterior à 2010 e se você tem um sistema altamente personalizado de build, talvez seja necessário mais trabalho para atualizar.  Se você estiver atualizando a partir do Visual Studio 2010 ou versão posterior, os projetos já estarão usando o MSBuild e a atualização do projeto e o build do seu aplicativo deverá ser mais fácil.  
  
 Se você não estiver usando o sistema de build do Visual Studio, você deverá considerar a atualização para usar o MSBuild. Se você atualizar para usar o MSBuild, terá mais facilidade em atualizações futuras e será mais fácil usar serviços como o Visual Studio Online. O MSBuild oferece suporte a todas as plataformas de destino que têm suporte no Visual Studio.  
  
### <a name="porting-visual-studio-projects"></a>Portabilidade de projetos do Visual Studio  
  Para começar a atualizar um projeto ou uma solução é só abrir a solução na nova versão do Visual Studio e seguir as solicitações para iniciar a atualização.  Ao atualizar um projeto, você obtém um relatório de atualização, que também é salvo na pasta do seu projeto como UpgradeLog.htm. O relatório de atualização mostra um resumo de quais problemas foram encontrados durante o processo de atualização e algumas informações sobre as alterações que foram feitas ou problemas que não puderam ser resolvidos automaticamente.  
  
1.  Propriedades de projeto  
  
2.  Incluir arquivos  
  
3.  Código que não compila corretamente devido a melhorias de conformidade do compilador ou alterações no padrão  
  
4.  Código que depende de recursos do Visual Studio ou do Windows que não estão mais disponíveis ou de arquivos de cabeçalho que não estão incluídos em uma instalação padrão do Visual Studio ou foram removidos do produto  
  
5.  Código não compila mais devido a alterações nas APIs como APIs renomeadas, alterações nas assinaturas de função ou funções preteridas  
  
6.  Código que não compila mais devido a alterações de diagnóstico, como um aviso que se torna um erro  
  
7.  Erros de vinculador devido a bibliotecas que foram alteradas, especialmente quando /NODEFAULTLIB é usada.  
  
8.  Erros em tempo de execução ou resultados inesperados devido a alterações de comportamento  
  
9. Erros devido a erros que foram introduzidos nas ferramentas. Se você encontrar um problema, envie o relato para a equipe do Visual C++ por meio dos canais de suporte normais ou usando o [Centro de Comentários do Visual Studio](http://connect.microsoft.com/VisualStudio/Feedback).  
  
 Além das alterações que você não pode evitar devido a erros de compilador, algumas alterações são opcionais em um processo de atualização, como:  
  
1.  Novos avisos podem significar que você deseja limpar seu código. Dependendo do diagnóstico específico, isso pode melhorar a portabilidade, a conformidade com os padrões e a segurança de seu código.  
  
2.  Talvez você queira tirar proveito dos recursos mais novos do compilador, como a opção do compilador [/guard:cf (Habilitar o fluxo de proteção de controle)](../build/reference/guard-enable-control-flow-guard.md), que adiciona verificações de execução não autorizada de código.  
  
3.  Você pode atualizar o código para usar os novos recursos de linguagem que simplificam o código, melhoram o desempenho de seus programas ou atualizar o código para usar bibliotecas modernas e entrar em conformidade com padrões modernos e melhores práticas.  
  
 Depois de ter atualizado e testado seu projeto, você também pode melhorar ainda mais seu código ou planejar a direção futura do seu código ou até mesmo reconsiderar a arquitetura do seu projeto. Ele receberá trabalho de desenvolvimento contínuo? Será importante que seu código seja executado em outras plataformas?  Em caso afirmativo, quais plataformas?  O C++ é uma linguagem padronizada projetada com a ideia de desenvolvimento de portabilidade de plataforma cruzada e ainda assim, o código para muitos aplicativos do Windows está intimamente ligado à plataforma Windows. Você deseja refatorar o seu código para separar as partes que estão mais ligadas à plataforma do Windows?  
  
 E a sua interface do usuário?  Se você estiver usando o MFC, convém atualizar a interface do usuário.  Você está usando algum dos recursos mais recentes do MFC que foram introduzidos no 2008 como um Feature Pack?  Se você só deseja dar uma aparência e funcionalidade mais recente ao seu aplicativo sem reescrevê-lo, considere usar as APIs da Faixa de Opções no MFC ou alguns dos novos recursos do MFC.  
  
 Se você deseja dar ao programa uma interface do usuário de XAML, mas não deseja criar um aplicativo UWP, use C# com o WPF para criar a camada de interface do usuário e refatorar sua lógica padrão do C++ em DLLs. Criar uma camada de interoperabilidade no C++/CLI para conectar o C# com seu código nativo. Outra opção é criar um aplicativo UWP usando [C++/CX](https://msdn.microsoft.com/en-us/library/windows/apps/xaml/hh699871.aspx) ou [C++/WinRT](https://github.com/microsoft/cppwinrt). No Windows 10, você pode usar o [Desktop App Converter](https://msdn.microsoft.com/en-us/windows/uwp/porting/desktop-to-uwp-run-desktop-app-converter) para empacotar o aplicativo da área de trabalho existente como um aplicativo UWP sem a necessidade de modificar nenhum código.   
 Como alternativa, você pode ter novos requisitos ou prever a necessidade de direcionamento a plataformas diferentes da área de trabalho do Windows, como o Windows Phone ou dispositivos Android. Você poderia portar seu código de interface do usuário para uma biblioteca de interface do usuário de plataforma cruzada. Com essas estruturas de interface do usuário, você pode ter vários dispositivos de destino e ainda usar o Visual Studio e o depurador do Visual Studio como ambiente de desenvolvimento.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Atualizando projetos de versões anteriores do Visual C++](upgrading-projects-from-earlier-versions-of-visual-cpp.md)|Discute como usar projetos criados em versões anteriores do Visual C++.|  
|[Novidades do compilador C++ no Visual Studio 2017 RC](../what-s-new-for-visual-cpp-in-visual-studio.md)|Alterações no IDE e nas ferramentas do Visual Studio 2015 até o Visual Studio 2017|  
|[Aprimoramentos de conformidade do C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md)|Aprimoramentos de conformidade com padrões do Visual Studio 2015 até o Visual Studio 2017|  
|[Histórico de alterações de 2003 a 2015 do Visual C++](visual-cpp-change-history-2003-2015.md)|Uma lista de todas as alterações nas bibliotecas e ferramentas de build do Visual C++ do Visual Studio 2003 até 2015 que podem exigir alterações em seu código.|  
|[O que há de novo no Visual C++ de 2003 até 2015](visual-cpp-what-s-new-2003-through-2015.md)|Todas as informações sobre "Novidades" para o Visual C++ do Visual Studio 2003 até o Visual Studio 2015.|  
|[Portabilidade de bibliotecas de terceiros](porting-third-party-libraries.md)|Como usar a ferramenta de linha de comando **vcpkg** para portar bibliotecas de software livre mais antigas para versões compiladas com conjuntos de ferramentas mais recentes do Visual C++.|  
|[Portabilidade e atualização: exemplos e estudos de caso](porting-and-upgrading-examples-and-case-studies.md)|Nessa seção, portamos e atualizamos vários exemplos e aplicativos e discutimos as experiências e os resultados. Ao ler essa seção você pode obter uma noção do que está envolvido no processo de portabilidade e atualização. Durante o processo, discutimos a respeito de dicas e truques para a atualização e mostramos como erros específicos foram corrigidos.|  
|[Portabilidade para a Plataforma Universal do Windows](porting-to-the-universal-windows-platform-cpp.md)|Contém informações sobre como fazer portabilidade de código para o Windows 10|  
|[Introdução ao Visual C++ para usuários do UNIX](introduction-to-visual-cpp-for-unix-users.md)|Fornece informações para usuários do UNIX novatos no Visual C++ e que desejam tornar-se produtivos com ele.|  
|[Portabilidade de UNIX para Win32](porting-from-unix-to-win32.md)|Discute as opções para migrar aplicativos UNIX para o Windows.|  
|[Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)|Mostra detalhadamente como atualizar suas sintaxes de Managed Extensions for C++ para usar a nova sintaxe. Para obter mais informações, consulte [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md).|  
  
## <a name="see-also"></a>Consulte também  
 [Visual C++](../visual-cpp-in-visual-studio.md)
