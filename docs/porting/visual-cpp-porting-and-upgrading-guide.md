---
title: Guia de atualização e portabilidade do Microsoft C++
description: Atualize o código do Microsoft C++ para a versão mais recente do Visual Studio.
ms.date: 09/10/2020
ms.assetid: f5fbcc3d-aa72-41a6-ad9a-a706af2166fb
ms.topic: overview
ms.openlocfilehash: b6cd3461ee16a44162fdb641170a2f05d9b77369
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039528"
---
# <a name="microsoft-c-porting-and-upgrading-guide"></a>Guia de atualização e portabilidade do Microsoft C++

Este artigo fornece um guia para atualizar o código do Microsoft C++ para a versão mais recente do Visual Studio. Para projetos criados no Visual Studio 2010 até 2015, basta abrir o projeto no Visual Studio 2019. Você pode atualizar um projeto do Visual Studio 2008 ou anterior em duas etapas. Use o Visual Studio 2010 para converter o projeto para o formato MSBuild primeiro. Em seguida, abra o projeto no Visual Studio 2019. Para obter instruções completas, consulte [Atualizando projetos C++ de versões anteriores do Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md).

Os conjuntos de ferramentas no Visual Studio 2015, Visual Studio 2017 e Visual Studio 2019 são compatíveis com binários. Agora você pode atualizar para uma versão mais recente do compilador sem precisar atualizar suas dependências de biblioteca. Para obter mais informações, consulte [compatibilidade binária de C++ 2015-2019](binary-compat-2015-2017.md).

Ao atualizar projetos que usam bibliotecas de software livre ou que devem ser executados em várias plataformas, recomendamos migrar para um projeto baseado em CMake. Para obter mais informações, consulte [projetos do cmake no Visual Studio](../build/cmake-projects-in-visual-studio.md)

## <a name="reasons-to-upgrade-c-code"></a>Motivos para atualizar o código C++

Se um aplicativo herdado estiver em execução satisfatoriamente, em um ambiente seguro e não estiver em desenvolvimento ativo, pode não haver muito incentivo para atualizá-lo. No entanto, considere uma atualização nesses casos: seu aplicativo requer manutenção contínua. Ou você está fazendo um novo desenvolvimento de recursos ou fazendo melhorias de desempenho ou segurança. Uma atualização traz estes benefícios:

- O mesmo código pode ser executado mais rapidamente, pois aprimoramos as otimizações do compilador.

- Os recursos modernos do C++ e as práticas de programação eliminam muitas causas comuns dos bugs e geram um código que é muito mais fácil de manter do que os idiomas do estilo C mais antigos.

- Os tempos de compilação são mais rápidos, devido às melhorias de desempenho no compilador e no vinculador.

- Melhor conformidade com os padrões. A opção de compilador [/permissive-](../build/reference/permissive-standards-conformance.md) ajuda a identificar o código que não está em conformidade com o padrão C++ atual. O [novo pré-processador](../preprocessor/preprocessor-experimental-overview.md) também dá suporte à conformidade de código.

- Melhor segurança em tempo de execução, incluindo recursos mais seguros da [biblioteca de tempo de execução C](../c-runtime-library/security-features-in-the-crt.md) . E, os recursos do compilador, como [verificação de proteção](../build/reference/guard-enable-guard-checks.md) e corrigir os limpezas (novo no Visual Studio 2019 versão 16,4).

## <a name="multitargeting-vs-upgrading"></a>Multidirecionamento versus atualização

Talvez atualizar sua base de código para um novo conjunto de ferramentas não é uma opção para você. Você ainda pode usar o Visual Studio mais recente para criar e editar projetos que usam conjuntos de ferramentas e bibliotecas mais antigos. No Visual Studio 2019, você pode aproveitar os recursos como:

- ferramentas de análise estática modernas, incluindo os verificadores de Diretrizes Principais do C++ e Clang, para ajudar a identificar possíveis problemas no código-fonte.

- a formatação automática de acordo com a sua escolha de estilos modernos pode ajudar a tornar o código herdado muito mais legível.

Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md).

## <a name="in-this-section"></a>Nesta seção

|Title|Descrição|
|-----------|-----------------|
|[Atualizando projetos C++ de versões anteriores do Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md)|Como atualizar sua base de código para o Visual Studio 2019 e v142 do compilador.|
|[Ferramentas IDE para atualizar o código C++](ide-tools-for-upgrading-code.md)|Recursos de IDE úteis que ajudam no processo de atualização.|
|[Compatibilidade binária de C++ 2015-2019](binary-compat-2015-2017.md)|Consuma bibliotecas v140 e v141 no estado em que se encontram de projetos v142.|
|[Usar multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md)|Use o Visual Studio 2019 com compiladores e bibliotecas mais antigos.|
|[Histórico de alterações de 2003 a 2015 do Visual C++](visual-cpp-change-history-2003-2015.md)|Uma lista de todas as alterações nas bibliotecas do Microsoft C++ e ferramentas de compilação do Visual Studio 2003 até 2015 que podem exigir alterações no seu código.|
|[O que há de novo no Visual C++ de 2003 até 2015](visual-cpp-what-s-new-2003-through-2015.md)|Todas as informações de "novidades" do Microsoft C++ do Visual Studio 2003 por meio do Visual Studio 2015.|
|[Portabilidade e atualização: exemplos e estudos de caso](porting-and-upgrading-examples-and-case-studies.md)|Nessa seção, portamos e atualizamos vários exemplos e aplicativos e discutimos as experiências e os resultados. Esses artigos oferecem uma noção do que está envolvido no processo de portabilidade e atualização. Durante o processo, discutimos a respeito de dicas e truques para a atualização e mostramos como erros específicos foram corrigidos.|
|[Portabilidade para a Plataforma Universal do Windows](porting-to-the-universal-windows-platform-cpp.md)|Contém informações sobre como fazer portabilidade de código para o Windows 10|
|[Introdução ao Visual C++ para usuários do UNIX](introduction-to-visual-cpp-for-unix-users.md)|Fornece informações para usuários do UNIX novatos no Visual C++ e que desejam tornar-se produtivos com ele.|
|[Como executar programas do Linux no Windows](porting-from-unix-to-win32.md)|Discute as opções para migrar aplicativos UNIX para o Windows.|

## <a name="see-also"></a>Confira também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
[Novidades do compilador C++ no Visual Studio](../overview/what-s-new-for-visual-cpp-in-visual-studio.md)<br/>
[Aprimoramentos de conformidade do C++ no Visual Studio](../overview/cpp-conformance-improvements.md)<br/>
