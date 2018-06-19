---
title: 'Guia de portabilidade: Scribble do MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8ddb517d-89ba-41a1-ab0d-4d2c6d9047e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fe0ae0580be4ab062e3ff7ee0cedfb42e201272d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33845902"
---
# <a name="porting-guide-mfc-scribble"></a>Guia de portabilidade: rabisco do MFC
Este tópico é o primeiro de vários tópicos que apresentam o procedimento de atualização para projetos do Visual C++ que foram criados em versões anteriores do Visual Studio para Visual Studio 2017. Estes tópicos apresentam o processo de atualização por exemplos, começando com um projeto muito simples e passando para outros um pouco mais complexos. Neste tópico, trabalhamos pelo processo de atualização para um projeto específico, o Scribble do MFC. Ele é adequado como uma introdução básica sobre o processo de atualização para projetos do C++.  
  
 Cada versão do Visual Studio apresenta possíveis incompatibilidades que podem complicar a mudança de um código de uma versão mais antiga do Visual Studio para uma mais nova. Às vezes, as alterações necessárias estão em seu código, portanto, você deve recompilá-lo e atualizado e às vezes as alterações necessárias são para os arquivos do projeto. Quando você abre um projeto que foi criado com uma versão anterior do Visual Studio, o Visual Studio automaticamente pergunta se você deseja atualizar um projeto ou solução para a versão mais recente. Essas ferramentas normalmente atualizam somente os arquivos de projeto, eles não modificam o código-fonte.  
  
## <a name="mfc-scribble"></a>Scribble do MFC  
 O Scribble do MFC é um exemplo bem conhecido que foi incluído em várias versões diferentes do Visual C++. É um aplicativo de desenho simples que ilustra alguns dos recursos básicos do MFC. Há várias versões dele disponíveis, incluindo as versões gerenciada e de código nativo. Neste exemplo, encontramos uma versão antiga do Scribble no código nativo do Visual Studio 2005 e o abrimos no Visual Studio 2017.  
  
 Antes de tentar atualizar, verifique se você tem a carga de trabalho da Área de Trabalho do Windows instalada. Abra o instalador do Visual Studio (vs_installer.exe). Uma maneira de abrir o instalador é escolher Arquivo | Novo Projeto e rolar até o final da lista de modelos instalados até ver “Abrir Instalador do Visual Studio”. Depois de abrir o instalador, você verá todas as cargas de trabalho disponíveis. Se a caixa para a carga de trabalho de Área de Trabalho do Windows não estiver selecionada, selecione-a e clique no botão Modificar na parte inferior da janela. 


 Em seguida, faça o backup de toda a solução e todo o seu conteúdo. 
 
 Por fim, precisamos decidir sobre o método de atualização específico. Para soluções e projetos mais complexos que não foram atualizados por um longo período, você deve considerar atualizar uma versão do Visual Studio de cada vez. Dessa forma, você pode restringir qual versão do Visual Studio introduziu um problema. Para um projeto simples, vale a pena tentar abri-lo na versão mais recente do Visual Studio e permitir que o assistente converta o projeto. Se isso não funcionar, você poderá tentar atualizar uma versão de cada vez, se tiver acesso às versões apropriadas do Visual Studio.  
  
 Observe que você também pode executar devenv na linha de comando, usando a opção `/Upgrade`, em vez de usar o assistente para atualizar seus projetos. Consulte [/Upgrade (devenv.exe)](/visualstudio/ide/reference/upgrade-devenv-exe). Isso poderia ser útil para automatizar o processo de atualização para um grande número de projetos.  
  
### <a name="step-1-converting-the-project-file"></a>Etapa 1. Conversão do arquivo de projeto  
 Quando você abre um arquivo de projeto antigo no Visual Studio 2017, o Visual Studio se oferece para converter o arquivo de projeto para a versão mais recente, o que aceitamos. A caixa de diálogo a seguir é exibida:  
  
 ![Examinar Alterações de Projeto e Solução](../porting/media/scribbleprojectupgrade.PNG "ScribbleProjectUpgrade")  
  
 Ocorreu um erro notificando que o destino do Itanium não está disponível e não será convertido.  
  
```Output  
Platform 'Itanium' is missing from this project. All the configurations and their file configuration settings specific to this platform will be ignored. If you want this platform converted, please make sure you have the corresponding platform installed under '%vctargetpath%\platforms\Itanium'.Continue to convert this project without this platform?  
```  
  
 Quando que o projeto Scribble anterior foi criado, o Itanium era uma plataforma de destino importante. A plataforma Windows não dá mais suporte ao Itanium, portanto escolhemos continuar sem dar suporte à plataforma Itanium.  
  
 O Visual Studio, em seguida, exibe um relatório de migração listando todos os problemas com o arquivo de projeto antigo.  
  
 ![Relatório de atualização](../porting/media/scribblemigrationreport.PNG "ScribbleMigrationReport")  
  
 Nesse caso, os problemas eram todos avisos e Visual Studio fez as alterações apropriadas no arquivo de projeto. A grande diferença que diz respeito ao projeto é que a ferramenta de build mudou da vcbuild para msbuild. Essa alteração foi introduzida no Visual Studio 2010. Outras alterações incluem a reorganização da sequência de elementos no arquivo de projeto em si. Nenhum dos problemas precisou de atenção adicional para esse projeto simples.  
  
### <a name="step-2-getting-it-to-build"></a>Etapa 2. Realização do build  
 Antes de compilar, verificamos o conjunto de ferramentas de plataforma para que saibamos qual versão do compilador o sistema de projeto está usando. Na caixa de diálogo de propriedades do projeto, em **Propriedades de Configuração**, na categoria **Geral**, observe a propriedade **Conjunto de Ferramentas da Plataforma**. Ela contém a versão do Visual Studio e o número de versão da ferramenta de plataforma, que nesse caso é v141 para a versão do Visual Studio 2017 das ferramentas. Quando você converte um projeto que foi originalmente compilado com o Visual C++ 2010, 2012, 2013 ou 2015, o conjunto de ferramentas não é automaticamente atualizado para o conjunto de ferramentas do Visual Studio 2017.   
  
  Para fazer a transição para Unicode, abra as propriedades do projeto, em **Propriedades de Configuração**, escolha a seção **Geral** e localize a propriedade **Conjunto de Caracteres**. Altere-a de **Usar Conjunto de Caracteres Multibyte** para **Usar Conjunto de Caracteres Unicode**. O efeito dessa alteração é que agora as macros _UNICODE e UNICODE estão definidas e _MBCS não está, o que pode ser verificado na caixa de diálogo de propriedades na categoria **C/C++** na propriedade **Linha de Comando**.  
  
```Output  
/GS /analyze- /W4 /Zc:wchar_t /Zi /Gm- /Od /Fd".\Debug\vc141.pdb" /Zc:inline /fp:precise /D "_AFXDLL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX /Zc:forScope /Gd /Oy- /MDd /Fa".\Debug\" /EHsc /nologo /Fo".\Debug\" /Fp".\Debug\Scribble.pch" /diagnostics:classic 
```  
  
 Embora o projeto Scribble não tenha sido configurado para ser compilado com caracteres Unicode, ele já foi gravado com TCHAR em vez de char, portanto, na verdade não é necessário mudar nada. O projeto é compilado com êxito com o conjunto de caracteres Unicode.  
  
 Agora compile a solução. Na janela de saída, o compilador nos diz que _WINNT32_WINNT não está definido:  
  
```Output  
_WIN32_WINNT not defined. Defaulting to _WIN32_WINNT_MAXVER (see WinSDKVer.h)  
```  
  
 Isso é um aviso, não um erro e é muito comum ao atualizar um projeto do Visual C++. Essa é a macro que define qual é a menor versão do Windows em que o aplicativo será executado. Se ignorarmos o aviso, aceitamos o valor padrão, _WIN32_WINNT_MAXVER, que significa a versão atual do Windows. Para encontrar uma tabela dos valores possíveis, consulte [Using the Windows Headers](https://msdn.microsoft.com/en-us/library/aa383745.aspx) (Usando os cabeçalhos do Windows). Por exemplo, podemos defini-lo para ser executado em qualquer versão do Vista em diante.  
  
```  
#define _WIN32_WINNT _WIN32_WINNT_VISTA  
```  
  
 Se o código usa partes da API do Windows que não estão disponíveis na versão do Windows especificada com essa macro, você deve ver isso como um erro de compilador. No caso do código do Scribble, não há erro.  
  
### <a name="step-3-testing-and-debugging"></a>Etapa 3. Teste e depuração  
 Não há nenhum conjunto de testes, portanto, apenas iniciamos o aplicativo e testamos seus recursos manualmente pela interface do usuário. Nenhum problema foi observado.  
  
### <a name="step-4-improve-the-code"></a>Etapa 4. Aprimoramento do código  
 Agora que você migrou para o Visual Studio 2017, convém fazer algumas alterações para aproveitar os novos recursos do C++. A versão atual do compilador C++ está muito mais em conformidade com o padrão C++ do que as versões anteriores, portanto, se você tem planos de fazer algumas alterações no código para tornar o código mais seguro e mais portável para outros compiladores e sistemas operacionais, deve considerar alguns aprimoramentos.  
  
## <a name="next-steps"></a>Próximas etapas  
 O Scribble era um aplicativo de área de trabalho do Windows pequeno e simples e não foi difícil converter. Muitos aplicativos pequenos e simples são convertidos com a mesma facilidade para a nova versão.  Para aplicativos mais complexos, com muito mais linhas de código, código herdado mais antigo que pode não estar de acordo com os padrões de engenharia modernos, vários projetos e bibliotecas, etapas de build personalizadas ou builds automatizadas com scripts complexas, levará mais tempo para atualizar. Continuar com o [próximo exemplo](../porting/porting-guide-com-spy.md), um aplicativo ATL/COM chamado COM Spy.  
  
## <a name="see-also"></a>Consulte também  
 [Portabilidade e atualização: exemplos e estudos de caso](../porting/porting-and-upgrading-examples-and-case-studies.md)   
 [Próximo exemplo: COM Spy](../porting/porting-guide-com-spy.md)
