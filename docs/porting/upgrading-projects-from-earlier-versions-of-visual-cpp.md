---
title: Atualizar projetos do C++ de versões anteriores do Visual Studio
description: Como atualizar os projetos do Microsoft C++ de versões anteriores do Visual Studio.
ms.date: 01/21/2020
helpviewer_keywords:
- 32-bit code porting
- upgrading Visual C++ applications, 32-bit code
ms.assetid: 18cdacaa-4742-43db-9e4c-2d9e73d8cc84
ms.openlocfilehash: 89c1df88aa8e533dd7d6e5312b1150468c905c18
ms.sourcegitcommit: 12eb6a824dd7187a065d44fceca4c410f58e121e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2020
ms.locfileid: "94334228"
---
# <a name="upgrade-c-projects-from-earlier-versions-of-visual-studio"></a>Atualizar projetos do C++ de versões anteriores do Visual Studio

Para atualizar um projeto criado em uma versão anterior do Visual Studio, basta abrir o projeto na versão mais recente do Visual Studio. O Visual Studio oferece para atualizar o projeto para o esquema atual.

Se você escolher **não** , o projeto não será atualizado. Para projetos criados no Visual Studio 2010 e posterior, você ainda pode usar o projeto na versão mais recente do Visual Studio. Basta definir as propriedades do projeto para continuar a direcionar o conjunto de ferramentas mais antigo. Se você deixar a versão mais antiga do Visual Studio em seu computador, seu conjunto de ferramentas estará disponível em versões posteriores. Por exemplo, se o seu projeto deve continuar a ser executado no Windows XP, você pode atualizar para o Visual Studio 2019. Em seguida, você especifica o conjunto de ferramentas como v141_xp ou anterior nas propriedades do projeto. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md).

Se você escolher **Sim** , o projeto será atualizado no local. Ele não pode ser convertido de volta para a versão anterior. Em cenários de atualização, é por isso que é uma boa prática fazer uma cópia de backup do projeto existente e dos arquivos de solução.

## <a name="upgrade-reports"></a>Atualizar relatórios

Ao atualizar um projeto, você obtém um relatório de atualização. O relatório também é salvo na pasta do projeto como UpgradeLog.htm. O relatório de atualização mostra um resumo dos problemas encontrados durante a conversão. Ele lista algumas informações sobre as alterações feitas, incluindo:

- Propriedades do projeto.

- Incluir arquivos.

- Código que não compila mais corretamente devido a melhorias de conformidade do compilador ou alterações no padrão.

- Código que se baseia em recursos do Visual Studio ou do Windows que não estão mais disponíveis. Ou os arquivos de cabeçalho que não estão incluídos em uma instalação padrão do Visual Studio ou foram removidos do produto.

- Código que não é mais compilado devido a alterações em APIs como APIs renomeadas, assinaturas de função alteradas ou funções preteridas.

- Código que não é mais compilado devido a alterações no diagnóstico, como um aviso que se torna um erro

- Erros de vinculador devido a bibliotecas que foram alteradas, especialmente quando/NODEFAULTLIB é usado.

- Erros de tempo de execução ou resultados inesperados devido a alterações de comportamento.

- Erros que foram introduzidos nas ferramentas. Se você encontrar um problema, relate-o à equipe de Visual C++ por meio de seus canais de suporte normal ou usando a página da [comunidade de desenvolvedores do Visual Studio C++](https://aka.ms/feedback/report?space=62) .

Alguns projetos e soluções atualizados podem ser compilados com êxito sem modificação. No entanto, a maioria dos projetos provavelmente exigirá alterações nas configurações do projeto e no código-fonte. Não há uma maneira correta de corrigir esses problemas, mas é recomendável usar uma abordagem em fases. Antes de começar, examine a [visão geral de possíveis problemas de atualização](../porting/overview-of-potential-upgrade-issues-visual-cpp.md) para obter mais informações sobre muitos tipos de erros comuns.

1. Defina o conjunto de ferramentas de plataforma, o padrão de linguagem C++ e a versão SDK do Windows (se aplicável) para as versões preferenciais. ( **Projeto**  >  **Propriedades**  >  do **Propriedades**  >  de configuração **Geral** )

1. Se você tiver muitos erros, poderá desativar temporariamente algumas opções enquanto corrigi-las. Para desativar a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção, use Propriedades de **projeto** Propriedades de  >  **Properties**  >  **configuração**  >  **linguagem C/C++**  >  **Language**. Para desativar a opção de [análise de código](../code-quality/code-analysis-for-c-cpp-overview.md) , use Propriedades do **projeto**  >  **Properties**  >  análise de código de propriedades de **configuração**  >  **Code Analysis**.

1. Verifique se todas as dependências estão presentes e se os caminhos de inclusão ou os locais de biblioteca estão corretos. ( **Projeto**  >  **Propriedades**  >  do **Propriedades**  >  de configuração **Diretórios do vc + +** )

1. Identificar e corrigir erros causados por referências a APIs que não existem mais.

1. Corrija quaisquer erros restantes que impeçam a compilação. Consulte a [visão geral de possíveis problemas de atualização](../porting/overview-of-potential-upgrade-issues-visual-cpp.md) para correções de erros comuns.

1. Ligue **`/permissive-`** novamente e corrija os novos erros causados pelo código não compatível que foi compilado anteriormente no MSVC.

1. Ative a análise de código para identificar possíveis problemas ou padrões de codificação desatualizados que não são mais considerados aceitáveis. Se a análise de código sinalizar muitos erros, você poderá desativar alguns dos avisos para se concentrar primeiro nos mais importantes. O IDE pode ajudar com correções rápidas para alguns tipos de problemas.

1. Considere outras oportunidades para modernizar o código. Por exemplo, substitua as estruturas de dados personalizadas e os algoritmos por da biblioteca padrão C++, ou aumente a biblioteca de código-fonte aberto. Usando os recursos padrão, você torna mais fácil para outras pessoas manter o código. Você pode ter certeza de que esse código foi bem testado e revisado por muitos especialistas no Comitê de padrões e na Comunidade de C++ mais ampla.

Para erros difíceis de corrigir, você pode procurar soluções ou postar uma pergunta no [Microsoft docs Q&a](/answers/topics/c%2B%2B.html). Para problemas no compilador e nas ferramentas do C++, experimente o site [da comunidade de desenvolvedores do c++](https://aka.ms/vsfeedback/browsecpp) .

## <a name="in-this-section"></a>Nesta seção

[Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)\
[Atualizar seu código para o CRT universal](upgrade-your-code-to-the-universal-crt.md)\
[Atualizar WINVER e _WIN32_WINNT](modifying-winver-and-win32-winnt.md)\
[Corrija suas dependências em elementos internos da biblioteca](fix-your-dependencies-on-library-internals.md)\
[Problemas de migração de ponto flutuante](floating-point-migration-issues.md)\
[Recursos do C++ preteridos no Visual Studio 2019](features-deprecated-in-visual-studio.md)\
[VCBuild versus MSBuild](build-system-changes.md)\
[Portabilidade de bibliotecas de terceiros](porting-third-party-libraries.md)

## <a name="see-also"></a>Veja também

[O que há de novo para Visual C++ no Visual Studio](../overview/what-s-new-for-visual-cpp-in-visual-studio.md)\
[Visual C++ histórico de alterações 2003-2015](../porting/visual-cpp-change-history-2003-2015.md)\
[Comportamento não padrão](../cpp/nonstandard-behavior.md)\
[Portabilidade de aplicativos de dados](../data/data-access-programming-mfc-atl.md)
