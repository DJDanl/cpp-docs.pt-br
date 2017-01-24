---
title: "Guia de portabilidade: rabisco do MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 8ddb517d-89ba-41a1-ab0d-4d2c6d9047e8
caps.latest.revision: 5
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Guia de portabilidade: rabisco do MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico é o primeiro de vários tópicos que apresentam a você o procedimento de atualização para projetos do Visual C\+\+ que foram criados em versões anteriores do Visual Studio para [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)].  Estes tópicos apresentam o processo de atualização, por exemplo, iniciando com um projeto muito simple e movendo a pouco mais complexas.  Neste tópico, trabalhamos pelo processo de atualização para um projeto específico, rabisco MFC.  Ele é adequado como uma introdução básica sobre o processo de atualização para projetos do C\+\+.  
  
 Cada versão do Visual Studio apresenta possíveis incompatibilidades que podem complicar o código de movimentação de uma versão anterior do Visual Studio para uma mais recente.  Às vezes, as alterações necessárias estão em seu código, então você deve recompilar e atualizar seu código e, às vezes, as alterações necessárias são para os arquivos de projeto.  Quando você abre um projeto que foi criado com uma versão anterior do Visual Studio, Visual Studio automaticamente perguntará se deseja atualizar um projeto ou solução para a versão mais recente.  Essas ferramentas normalmente atualizarem somente os arquivos de projeto; eles não modificam o código\-fonte.  
  
## Rabisco MFC  
 Rabisco MFC é um exemplo bem conhecido que foi incluído em várias versões diferentes do Visual C\+\+.  É um aplicativo de desenho simple que ilustra alguns dos recursos básicos do MFC.  Há várias versões dele disponíveis, incluindo gerenciado e código nativo.  Neste exemplo, podemos encontrou uma versão antiga do Rabisco em código nativo do Visual Studio 2005 e aberto na [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)].  
  
 Antes de tentar atualizar, fazemos backup nossa solução inteira e todo o seu conteúdo.  Em seguida, precisamos decidir sobre o método específico de atualização.  Para soluções e projetos que ainda não foram atualizados por um longo tempo mais complexas, considere atualizar uma versão do Visual Studio por vez.  Dessa forma, você pode restringir qual versão do Visual Studio introduziu um problema.  Para um projeto simples, vale a pena tentar abri\-lo na versão mais recente do Visual Studio e permitir que o assistente converter o projeto.  Se isso não funcionar, você pode tentar atualizar uma versão de uma vez, se você tiver acesso para as versões apropriadas do Visual Studio.  
  
 Observe que você também pode executar devenv na linha de comando, usando o `/Upgrade` opção, em vez de usar o Assistente para atualizar seus projetos.  Consulte [\/Upgrade](../Topic/-Upgrade%20\(devenv.exe\).md).  Isso poderia ser útil para automatizar o processo de atualização para um grande número de projetos.  
  
### Etapa 1.Convertendo o arquivo do projeto  
 Quando você abre um arquivo de projeto antigo no Visual Studio de 2015, o Visual Studio oferece para converter o arquivo de projeto para a versão mais recente, que é aceito.  A caixa de diálogo a seguir é exibida:  
  
 ![Review Project and Solution Changes](../porting/media/scribbleprojectupgrade.PNG "ScribbleProjectUpgrade")  
  
 Ocorreu um erro notificando que o destino do Itanium não está disponível e não ser convertido.  
  
  **Plataforma 'Itanium' está ausente deste projeto.  Todas as configurações e suas definições de configuração de arquivo específicas para essa plataforma serão ignoradas.  Se você quiser que essa plataforma convertida, verifique se que você tem a plataforma correspondente instalado em '% vctargetpath%\\platforms\\Itanium'.  Continuar converter esse projeto sem essa plataforma?**  No momento em que o projeto Rabisco anterior foi criado, Itanium foi uma plataforma de destino importante.  A plataforma Windows não suporta Itanium, de forma que escolhemos continuar sem suporte para a plataforma Itanium.  
  
 O Visual Studio, em seguida, exibir um relatório de migração listando todos os problemas com o arquivo de projeto antigo.  
  
 ![Upgrade Report](../Image/ScribbleMigrationReport.PNG "ScribbleMigrationReport")  
  
 Nesse caso, os problemas foram todos os avisos e Visual Studio feitas as alterações apropriadas no arquivo de projeto.  A grande diferença que diz respeito o projeto é que a ferramenta de compilação mudou de vcbuild para msbuild.  Essa alteração foi introduzida no Visual Studio 2010.  Outras alterações incluem alguns reorganização da sequência de elementos no arquivo de projeto em si.  Nenhum dos problemas ainda mais necessária atenção para esse projeto simple.  
  
### Etapa 2.Fazer a compilação  
 Antes de compilar, verificamos o conjunto de ferramentas de plataforma para que saibamos qual versão do compilador está usando o sistema de projeto.  Na caixa de diálogo de propriedades da projeto, em **Propriedades de configuração**, no **geral** categoria, examinar o **Ferramentas da plataforma** propriedade.  Ele contém a versão do Visual Studio e o número de versão da ferramenta de plataforma, que nesse caso é v140 para o [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)] versão das ferramentas.  Quando você converter um projeto que foi originalmente compilado com o Visual C\+\+ 2010, 2012 ou 2013, o conjunto de ferramentas não é atualizado automaticamente para a [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)] conjunto de ferramentas.  No caso de mão livre, a versão convertemos foi criada para o Visual Studio 2005, portanto ele é convertido para usar o conjunto de ferramentas mais recente.  
  
 Durante a criação, o primeiro problema que aparece é sobre código MBCS.  
  
  **Erro MSB8031:**  O link na mensagem de erro nos leva a um tópico sobre a substituição de MBCS no Visual Studio 2013.  Por padrão, a instalação do MFC no Visual C\+\+ 2013 não inclui a versão MBCS do MFC.  A versão MBCS MFC é necessário para compilar esse projeto em sua forma atual.  É possível migrar tanto o código para usar Unicode ou podemos baixar e instalar a versão MBCS do MFC.  Se entrarmos com o download da versão de MBCS do MFC, podemos adicionar uma definição para a macro NO\_WARN\_MBCS\_MFC\_DEPRECATION para suprimir esse aviso.  
  
 Para baixar a versão MBCS do MFC, primeiro leia sobre a substituição da versão do MFC MBCS no artigo [Suplemento MFC MBCS DLL](../mfc/mfc-mbcs-dll-add-on.md), e o blog do VC e baixar a versão MBCS MFC [aqui](http://www.microsoft.com/download/details.aspx?id=44930).  Na caixa de diálogo Propriedades do projeto, sob o **C\/C\+\+** categoria, em **pré\-processador**, adicione o NO\_WARN\_MBCS\_MFC\_DEPRECATION à lista de macros predefinidas.  
  
 Para fazer a transição para Unicode, abra as propriedades do projeto, em **Propriedades de configuração**, escolha o **geral** seção e localize o **do conjunto de caracteres** propriedade.  Alterar isso na **usar o conjunto de caracteres multibyte** para **usar o conjunto de caracteres Unicode**.  O efeito dessa alteração é que agora o Unicode e UNICODE macros são definidas e MBCS não for, que pode ser verificado na caixa de diálogo Propriedades no **C\/C\+\+** categoria ao **linha de comando** propriedade.  
  
  **\/GS \/ANALYZE \-\/W4 \/Gy \/ZC: \/Zi \/Gm\-\/O2 \/Ob1 \/Fd ".  \\Release\\vc140.PDB"\/ZC: inline \/fp: preciso \/D"\_AFXDLL"\/D"WIN32"\/D"NDEBUG"\/D Windows" \/D Unicode"\/D"UNICODE"\/errorReport:prompt \/GF \/WX \/ZC: forScope \/Gd \/Oy \/MD \/Fa".  \\Release\\ "\/EHsc \/nologo \/Fo".  \\Release\\ "Fp".  \\Release\\Scribble.pch"**  Embora Rabisco projeto não foi configurado para compilar com caracteres Unicode, ele foi já gravado com TCHAR, em vez de char para que nada, na verdade, precisa ser alterada.  O projeto for compilado com êxito com o conjunto de caracteres Unicode.  
  
 No entanto, há outro problema.  O compilador informa que \_WINNT32\_WINNT não está definido:  
  
  **\_WIN32\_WINNT não definido.  O padrão é \_WIN32\_WINNT\_MAXVER \(consulte WinSDKVer.h\)**  Isso é um aviso, não um erro e é muito comum ao atualizar um projeto do Visual C\+\+.  Esta é a macro que define que a versão menor do que o aplicativo será executado no Windows.  Se podemos ignorar o aviso, podemos aceitar o valor padrão, \_WIN32\_WINNT\_MAXVER, o que significa que a versão atual do Windows.  Para uma tabela de valores possíveis, consulte [usando os cabeçalhos do Windows](https://msdn.microsoft.com/en-us/library/aa383745.aspx).  Por exemplo, podemos definir para ser executado em qualquer versão do Vista em diante.  
  
```  
#define _WIN32_WINNT _WIN32_WINNT_VISTA  
```  
  
 Se o código usa partes da API do Windows que não estão disponíveis na versão do Windows que você especificar com essa macro, você verá que como um erro do compilador.  No caso do código rabisco, não há nenhum erro.  
  
### Etapa 3.Testando e depurando  
 Não há nenhum conjunto de testes, assim, começamos apenas o aplicativo testado seus recursos manualmente por meio da interface do usuário.  Nenhum problema foi observado.  
  
### Etapa 4.Melhorar o código  
 Agora que você já migrou para o Visual Studio de 2015, convém fazer algumas alterações para tirar proveito dos novos recursos do C\+\+.  A versão atual do compilador Visual C\+\+ é muito mais em conformidade com as versões C\+\+ padrão e anteriores, portanto, se você tiver uma idéia fazer algum código altera para tornar seu código mais seguro e mais portáteis para outros compiladores e sistemas operacionais, você deve considerar algumas melhorias.  
  
## Próximas etapas  
 Rabisco era um aplicativo de desktop Windows pequeno e simple, e não era difícil de converter.  Muitos aplicativos pequenos e simples facilmente converter para a nova versão.  Para aplicativos mais complexos, com muitos mais linhas de código, código herdado mais antigo que não pode ser até modernos padrões de engenharia, etapas de compilação de vários projetos e bibliotecas, personalizadas ou para compilações automatizadas com scripts complexas, levará mais tempo para atualizar.  Continuar com a [próximo exemplo](../porting/porting-guide-com-spy.md), um aplicativo\/COM ATL chamado COM Spy.  
  
## Consulte também  
 [Portando e atualizando: exemplos e estudos de caso](../porting/porting-and-upgrading-examples-and-case-studies.md)   
 [próximo exemplo: COM Spy](../porting/porting-guide-com-spy.md)