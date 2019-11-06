---
title: Atualizar C++ projetos de versões anteriores do Visual Studio
description: Como atualizar os projetos do Microsoft C++ de versões anteriores do Visual Studio.
ms.date: 10/29/2019
helpviewer_keywords:
- 32-bit code porting
- upgrading Visual C++ applications, 32-bit code
ms.assetid: 18cdacaa-4742-43db-9e4c-2d9e73d8cc84
ms.openlocfilehash: b317271a9cd0873e60a6dd9acd1b73a766aaea19
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627160"
---
# <a name="upgrade-c-projects-from-earlier-versions-of-visual-studio"></a>Atualizar C++ projetos de versões anteriores do Visual Studio

Para atualizar um projeto criado no Visual Studio 2008 ou anterior, você deve primeiro usar o Visual Studio 2010 para converter o projeto do formato VCBuild (. vcproj) no formato do MSBuild (. vcxproj). Para obter mais informações, consulte [as instruções para o Visual Studio 2008](use-native-multi-targeting.md#instructions-for-visual-studio-2008).

Para atualizar um projeto criado no Visual Studio 2010 ou posterior, basta abrir o projeto na versão mais recente do Visual Studio. O Visual Studio oferece para atualizar o projeto para o esquema atual. Se você escolher **não**, e tiver a versão mais antiga do Visual Studio em seu computador, poderá trabalhar no projeto em uma versão mais recente do Visual Studio e continuar a direcionar o conjunto de ferramentas mais antigo. Por exemplo, se o seu projeto precisar continuar a ser executado no Windows XP, você poderá atualizá-lo para o Visual Studio 2019, mas precisará especificar o conjunto de ferramentas como v141 ou anterior. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md). Se você escolher **Sim**, o projeto será convertido e não poderá ser convertido de volta para a versão anterior. Portanto, em cenários de atualização, é uma boa prática fazer uma cópia do projeto existente e dos arquivos de solução.

## <a name="upgrade-reports"></a>Relatórios de atualização

Ao atualizar um projeto, você obtém um relatório de atualização, que também é salvo na pasta do seu projeto como UpgradeLog.htm. O relatório de atualização mostra um resumo de quais problemas foram encontrados e algumas informações sobre as alterações feitas, incluindo:

1. Propriedades de projeto

2. Incluir arquivos

3. Código que não compila mais corretamente devido a melhorias de conformidade do compilador ou alterações no padrão

4. Código que depende de recursos do Visual Studio ou do Windows que não estão mais disponíveis ou de arquivos de cabeçalho que não estão incluídos em uma instalação padrão do Visual Studio ou foram removidos do produto

5. Código não compila mais devido a alterações nas APIs como APIs renomeadas, alterações nas assinaturas de função ou funções preteridas

6. Código que não é mais compilado devido a alterações no diagnóstico, como um aviso que se torna um erro

7. Erros de vinculador devido a bibliotecas que foram alteradas, especialmente quando /NODEFAULTLIB é usada.

8. Erros em runtime ou resultados inesperados devido a alterações de comportamento

9. Erros que foram introduzidos nas ferramentas. Se você encontrar um problema, relate-o à equipe do Visual C++ por meio dos canais de suporte normais ou usando a página [Comunidade de Desenvolvedores do Visual Studio C++](https://developercommunity.visualstudio.com/spaces/62/index.html).

Alguns projetos e soluções atualizados podem ser compilados com êxito sem modificação. No entanto, a maioria dos projetos provavelmente exigirá alterações nas configurações do projeto, bem como no código-fonte. Não há uma maneira correta de corrigi-los, mas é recomendável algum tipo de abordagem em fases. Antes de começar, examine a [visão geral de possíveis problemas de atualização](../porting/overview-of-potential-upgrade-issues-visual-cpp.md) para obter mais informações sobre muitos tipos de erros comuns.

 1. Defina o conjunto de ferramentas C++ de plataforma, o padrão de idioma e a versão SDK do Windows (se aplicável) para as versões desejadas. (**Projeto** > **Propriedades** > **Propriedades de configuração** > **geral**)
 1. Se você tiver muitos erros, desative a opção [permissiva](../build/reference/permissive-standards-conformance.md) (**projeto** > **Propriedades** > **Propriedades de configuração** > **linguagem** **CC++ /**  > ) e análise de [código ](/visualstudio/code-quality/code-analysis-for-c-cpp-overview)( **As propriedades** do**projeto** >  > a opção de **configuração** > **análise de código**) temporariamente para reduzir a contagem de erros.
 1. Verifique se todas as dependências estão presentes e se os caminhos de inclusão ou os locais de biblioteca estão corretos. (**Projeto** > **Propriedades** > **Propriedades de configuração** > **diretórios vc + +** )
 1. Identificar e corrigir erros devido a referências a APIs que não existem mais.
 1. Corrija quaisquer erros restantes que impeçam a compilação. Consulte a [visão geral de possíveis problemas de atualização](../porting/overview-of-potential-upgrade-issues-visual-cpp.md) para correções de erros comuns.
 1. Transforme o desempenho de forma **permissiva** e corrija quaisquer erros novos que apareçam devido ao código não compatível que foi compilado anteriormente em MSVC.
 1. Ative a análise de código para identificar possíveis problemas ou padrões de codificação desatualizados que não são mais considerados aceitáveis. Se a análise de código sinalizar muitos erros, você poderá desativar alguns dos avisos para se concentrar primeiro nos mais importantes. O IDE pode ajudar com correções rápidas para alguns tipos de problemas.
 1. Considere outras oportunidades para modernizar o código, por exemplo, substituindo estruturas de dados personalizadas e algoritmos por C++ aqueles da biblioteca padrão ou da biblioteca de aprimoramento de software livre. Usando os recursos padrão, você torna mais fácil para outras pessoas manter o código e também ter uma forte confiança de que o código foi bem testado e revisado por muitos especialistas no Comitê de padrões e na C++ comunidade mais ampla.

Para erros difíceis de corrigir, tente pesquisar ou postar uma pergunta em Stack Overflow ou [ C++ na Comunidade de desenvolvedores](https://developercommunity.visualstudio.com/spaces/62/index.html).

## <a name="in-this-section"></a>Nesta seção

[Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)<br/>
[Atualizar seu código para o CRT Universal](upgrade-your-code-to-the-universal-crt.md)<br/>
[Atualizar WINVER e _WIN32_WINNT](modifying-winver-and-win32-winnt.md)<br/>
[Corrigir suas dependências em recursos internos de biblioteca](fix-your-dependencies-on-library-internals.md)<br/>
[Problemas de migração de ponto flutuante](floating-point-migration-issues.md)<br/>
[C++recursos preteridos no Visual Studio 2019](features-deprecated-in-visual-studio.md)<br/>
[VCBuild versus MSBuild](build-system-changes.md)<br/>
[Bibliotecas de terceiros da porta](porting-third-party-libraries.md)<br/>

## <a name="see-also"></a>Consulte também

[Novidades do Visual C++ no Visual Studio](../overview/what-s-new-for-visual-cpp-in-visual-studio.md)<br/>
[Histórico de alterações de 2003 a 2015 do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)<br/>
[Comportamento não padrão](../cpp/nonstandard-behavior.md)<br/>
[Aplicativos de dados de porta](../data/data-access-programming-mfc-atl.md)<br/>
