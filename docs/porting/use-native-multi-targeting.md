---
title: Usar multiplataforma nativa no Visual Studio para compilar projetos antigos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- C++ native multi-targeting
- upgrading Visual C++ applications, retargeting
ms.assetid: b115aabe-a9dc-4525-90d3-367d97ea20c9
caps.latest.revision: 2
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Human Translation
ms.sourcegitcommit: 8953e3bd81158ce183e1abb5dfa969164c1f9ced
ms.openlocfilehash: 1088f17c1d758589fba146f82b2544ae17090a22
ms.lasthandoff: 02/25/2017

---
# <a name="use-native-multi-targeting-in-visual-studio-to-build-old-projects"></a>Usar multiplataforma nativa no Visual Studio para compilar projetos antigos  
  
Normalmente, é recomendável atualizar seus projetos ao instalar a versão mais recente do Visual Studio. O custo de atualização de seus projetos e do seu código é geralmente mais do que o deslocamento pelos benefícios do novo IDE, compilador, bibliotecas e ferramentas. No entanto, sabemos que talvez não será possível atualizar alguns projetos. Talvez você tenha binários vinculados a bibliotecas ou plataformas mais antigas que, por razões de manutenção, não podem ser atualizadas. Seu código pode usar constructos de linguagem não padrão que poderiam ser interrompidos se você passasse para um compilador mais recente. Seu código pode depender de bibliotecas de terceiros compiladas para uma versão específica do Visual C++. Ou você pode produzir bibliotecas para outros que devem definir como destino uma versão mais antiga específica do Visual C++.  
  
Felizmente, é possível usar o Visual Studio 2017 e o Visual Studio 2015 para compilar projetos que definem como destino conjuntos de ferramentas e bibliotecas de compilador mais antigos. Não é necessário atualizar um projeto do Visual Studio 2010, do Visual Studio 2012, do Visual Studio 2013 ou do Visual Studio 2015 para aproveitar os novos recursos no IDE:  
 - Novos recursos experimentais do editor e de refatoração do C++  
 - Nova janela do depurador de ferramentas de diagnóstico e nova janela Lista de Erros  
 - Pontos de interrupção e janela de exceções renovados e novos PerfTips  
 - Novas ferramentas de pesquisa e de navegação de código  
 - Novas correções rápidas do C++ e extensões de Ferramentas Avançadas de Produtividade.  
  
Também é possível definir como destino projetos do Visual Studio 2008, mas eles não podem ser usados sem ser alterados. Para obter detalhes, consulte a seção Instruções para o Visual Studio 2008.
  
As versões mais recentes do Visual Studio dão suporte à multiplataforma nativa e ao ciclo completo de projetos. A multiplataforma nativa é a capacidade que o IDE mais recente tem de compilar usando conjuntos de ferramentas instalados por versões anteriores do Visual Studio. O ciclo completo é a capacidade que o IDE mais recente tem de carregar projetos criados por uma versão anterior do IDE sem fazer alterações no projeto. Se você instalar a versão mais recente do Visual Studio juntamente com sua versão existente, é possível usar a nova versão do IDE com o compilador e as ferramentas da versão existente para compilar seus projetos. Outros membros da sua equipe podem continuar usando os projetos na versão mais antiga do Visual Studio.  
  
Ao usar um conjunto de ferramentas mais antigo, é possível aproveitar muitos dos recursos mais recentes do IDE, mas não os avanços mais recentes no compilador, nas bibliotecas e nas ferramentas de build C++. Por exemplo, não será possível usar as novas melhorias de conformidade de linguagem, os novos recursos de depuração e de análise de código nem obter a taxa de transferência de build mais rápida do mais recente conjunto de ferramentas. Também há alguns recursos do IDE incompatíveis com conjuntos de ferramentas mais recentes. Por exemplo, as informações de tipo podem estar ausentes no Criador de Perfil de Memória, e a operação de refatoração "Converter em literais de cadeia de caracteres brutos" gera código em conformidade com C++11 que não será compilado ao usar o Visual Studio 2012 ou conjuntos de ferramentas mais antigos.

## <a name="how-to-use-native-multi-targeting-in-visual-studio"></a>Como usar a multiplataforma nativa no Visual Studio
Depois de instalar o Visual Studio juntamente com sua versão mais antiga, abra seu projeto existente na nova versão do Visual Studio. Quando o projeto é carregado, o Visual Studio pergunta se você deseja atualizá-lo para usar o compilador e as bibliotecas mais recentes do C++. Como você deseja que o projeto mantenha a biblioteca e o compilador mais antigos, escolha o botão **Cancelar**.  
  
O Visual Studio é persistente na atualização do seu projeto. Para evitar ver a caixa de diálogo de atualização sempre que carregar o projeto, é possível definir a seguinte propriedade em seus projetos ou nos arquivos .props ou .targets importados:  
  
`<VCProjectUpgraderObjectName>NoUpgrade</VCProjectUpgraderObjectName>`  
  
É necessário remover essa propriedade quando você desejar atualizar seus projetos.  
  
Se você optar por não atualizar, o Visual Studio não fará nenhuma alteração em seus arquivos de solução nem de projeto. Ao compilar o projeto, os binários gerados são totalmente compatíveis com aqueles criados com a versão mais antiga do Visual Studio. Isso ocorre porque o Visual Studio usa o mesmo compilador C++ e vincula as mesmas bibliotecas que acompanhavam o seu IDE mais antigo. É por isso também que a caixa de diálogo de atualização avisa você para manter a versão mais antiga do Visual Studio instalada se você escolhe **Cancelar**.  
  
## <a name="instructions-for-visual-studio-2008"></a>Instruções para o Visual Studio 2008  
  
O Visual Studio 2008 tinha seu próprio sistema de build dedicado para C++ chamado VCBuild. Do Visual Studio 2010 em diante, os projetos do Visual C++ foram alterados para usar o MSBuild. Isso significa que é necessário passar por uma etapa de atualização para compilar seus projetos do Visual Studio 2008 na versão mais recente do Visual Studio. Seu projeto atualizado ainda gera binários totalmente compatíveis com os binários criados usando o Visual Studio 2008 IDE.

Primeiro, além da versão atual do Visual Studio, é necessário instalar o Visual Studio 2010 no mesmo computador que o Visual Studio 2008. Apenas o Visual Studio 2010 instala os scripts MSBuild necessários para o definir como destino os projetos do Visual Studio 2008. 

Em seguida, é necessário atualizar seus projetos e sua solução do Visual Studio 2008 para a versão atual do Visual Studio. Recomendamos que você crie um backup de seus projetos e arquivos de solução antes da atualização. Para iniciar o processo de atualização, abra a solução na versão atual do Visual Studio. Quando você receber o prompt de atualização, examine as informações apresentadas e escolha **OK** para iniciar a atualização. Se você tiver mais de um projeto na solução, será necessário atualizar O assistente cria novos arquivos de projeto .vcxproj juntamente com os arquivos .vcproj existentes. Desde que você também tenha uma cópia do arquivo .sln original, a atualização não tem nenhum outro impacto sobre os projetos existentes do Visual Studio 2008.

Quando a atualização for concluída, se o relatório de log tiver erros ou avisos para qualquer um de seus projetos, examine-os cuidadosamente. A conversão de VCBuild para MSBuild pode causar problemas. Certifique-se de entender e implementar quaisquer itens de ação listados no relatório. Para obter mais informações sobre os problemas e o relatório de log de atualização que podem ocorrer durante a conversão de VCBuild em MSBuild, consulte esta postagem de blog [Multiplataforma nativa do C++](https://blogs.msdn.microsoft.com/vcblog/2009/12/08/c-native-multi-targeting/).

Quando a atualização do projeto for concluída, e você tiver corrigido quaisquer problemas no arquivo de log, sua solução realmente define como destino o conjunto de ferramentas mais recente. Como etapa final, altere as propriedades para que cada projeto na solução use o conjunto de ferramentas do Visual Studio 2008. Com a solução carregada na versão atual do Visual Studio, para cada projeto na solução, abra o a caixa de diálogo do projeto **Páginas de Propriedades**: clique com o botão direito do mouse no projeto em **Gerenciador de Soluções** e, em seguida, selecione **Propriedades**. Na caixa de diálogo **Páginas de Propriedades**, altere o valor suspenso **Configuração** para **Todas as configurações**. Em **Propriedades de Configuração**, selecione **Geral** e, em seguida, altere o **Conjunto de Ferramentas da Plataforma** para **Visual Studio 2008 (v90)**.  
  
Após essa alteração, o compilador e as bibliotecas do Visual Studio 2008 são usados para gerar binários de projeto quando você compila a solução na versão atual do Visual Studio.

## <a name="install-an-older-visual-studio-toolset"></a>Instalar um conjunto de ferramentas do Visual Studio mais antigo  
  
Talvez você tenha um projeto antigo do Visual C++ que você não pode ou não deseja atualizar, mas não a versão de conjunto de ferramentas de plataforma correspondente ao seu projeto. Nesse caso, para obter o conjunto de ferramentas, é possível instalar gratuitamente a edição Visual Studio Community ou Express da versão necessária. Cada versão do Visual Studio, do Visual Studio 2008 em diante, pode instalar o compilador, as ferramentas e as bibliotecas necessários para definir como destino essa versão com base no Visual Studio atual. Pesquise no Centro de Download da Microsoft para localizar e baixar uma versão específica do Visual Studio. Certifique-se de que escolher as opções de instalação do C++ durante a instalação. Quando a instalação for concluída, execute essa versão do Visual Studio para instalar quaisquer atualizações. Também verifique se há alterações do Windows Update que possam ser exigidas. Talvez seja necessário repetir esse processo de verificação de atualização mais de uma vez para obter todas as atualizações.  
  
Abaixo estão alguns downloads do Visual Studio de que talvez você possa precisar:  
  
  - [Microsoft Visual Studio Community 2015](https://www.microsoft.com/en-us/download/details.aspx?id=48146)  
  - [Microsoft Visual Studio Express 2013 para Windows Desktop com Atualização 5](https://www.microsoft.com/en-us/download/details.aspx?id=48131)  
  - [Microsoft Visual Studio Express 2012 para Windows Desktop](https://www.microsoft.com/en-us/download/details.aspx?id=34673)  
  - [Visual Studio 2012 Atualização 5](https://www.microsoft.com/en-us/download/details.aspx?id=34673)  
  - [Microsoft Visual C++ 2010 Express (Instalador da Web)](https://download.microsoft.com/download/1/D/9/1D9A6C0E-FC89-43EE-9658-B9F0E3A76983/vc_web.exe)  
  - [Microsoft Visual Studio 2010 Service Pack 1](https://www.microsoft.com/en-us/download/details.aspx?id=23691)  
  - [Microsoft Visual C++ 2008 Express com SP1 (Instalador da Web)](https://go.microsoft.com/?linkid=7729279)  
  
Quando esses produtos forem instalados, o 
  
## <a name="see-also"></a>Consulte também  
 [Atualizando projetos de versões anteriores do Visual C++](upgrading-projects-from-earlier-versions-of-visual-cpp.md)  
 [Aprimoramentos de conformidade do C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md)  

