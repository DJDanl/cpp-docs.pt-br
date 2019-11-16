---
title: Guia C++ de atualização e portabilidade da Microsoft
description: Atualize o C++ código da Microsoft para a versão mais recente do Visual Studio.
ms.date: 11/05/2019
ms.assetid: f5fbcc3d-aa72-41a6-ad9a-a706af2166fb
ms.topic: overview
ms.openlocfilehash: 04c3950d637c01031e78d0d95e13232143ceb232
ms.sourcegitcommit: 4dde7914608508e47c21cae03ac58fe953a0c29b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2019
ms.locfileid: "74119494"
---
# <a name="microsoft-c-porting-and-upgrading-guide"></a>Guia C++ de atualização e portabilidade da Microsoft

Este tópico fornece um guia para atualizar o C++ código da Microsoft para a versão mais recente do Visual Studio. Se você estiver atualizando de um projeto criado no Visual Studio 2008 ou anterior, primeiro deverá usar o Visual Studio 2010 para converter o projeto para o formato MSBuild e, em seguida, abrir o projeto no Visual Studio 2019. Para projetos criados no Visual Studio 2010 até 2015, basta abrir o projeto no Visual Studio 2019. Para obter instruções completas, [consulte C++ Atualizando projetos de versões anteriores do Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md).

Os conjuntos de ferramentas no Visual Studio 2015, Visual Studio 2017 e Visual Studio 2019 são compatíveis com binário, o que permite que você atualize para uma versão mais recente do compilador sem precisar atualizar as dependências da biblioteca. Para obter mais informações, consulte [ C++ compatibilidade binária entre 2015 e 2019](binary-compat-2015-2017.md).

Ao atualizar projetos que usam bibliotecas de software livre ou que devem ser executados em várias plataformas, recomendamos migrar para um projeto baseado em CMake. Para obter mais informações, consulte [projetos do cmake no Visual Studio](../build/cmake-projects-in-visual-studio.md)

## <a name="reasons-to-upgrade-c-code"></a>Motivos para atualizar C++ o código

Se um aplicativo herdado estiver em execução satisfatoriamente, em um ambiente seguro e não estiver sob o desenvolvimento ativo, pode não haver muito incentivo para atualizá-lo. No entanto, se um aplicativo exigir manutenção contínua ou novo desenvolvimento de recursos, incluindo melhorias de desempenho ou segurança, você pode considerar a atualização do código por qualquer um dos seguintes motivos:

- O mesmo código pode ser executado mais rapidamente devido a otimizações aprimoradas do compilador.

- Recursos C++ modernos e práticas de programação eliminam muitas causas comuns de bugs e geram código que é muito mais fácil de manter do que os idiomas do estilo C mais antigos.

- Os tempos de compilação são significativamente mais rápidos, devido a melhorias de desempenho no compilador e no vinculador.

- Melhor conformidade com os padrões. A opção de compilador [/permissive-](../build/reference/permissive-standards-conformance.md) permite que você identifique o código que anteriormente era permitido pelo C++ compilador da Microsoft, mas que não está C++ de acordo com o padrão atual.

- Melhor segurança em tempo de execução, incluindo recursos de [biblioteca de tempo de execução C]() mais seguros e recursos de compilador, como [verificação de proteção](../build/reference/guard-enable-guard-checks.md) e limpezas de endereços (Visual Studio 2019 versão 16,4).

## <a name="multitargeting-vs-upgrading"></a>Multidirecionamento versus atualização

Se a atualização de sua base de código para um novo conjunto de ferramentas não for uma opção, você ainda poderá usar uma versão recente do Visual Studio para criar e editar projetos que se compilam com conjuntos de ferramentas e bibliotecas mais antigos. No Visual Studio 2019, você pode aproveitar os recursos como:

- ferramentas de análise estática modernas, incluindo C++ os principais verificadores de diretrizes e Clang, para ajudar a identificar possíveis problemas em seu código-fonte.

- a formatação automática de acordo com a sua escolha de estilos modernos pode ajudar a tornar o código herdado muito mais legível.

Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md).

## <a name="in-this-section"></a>Nesta seção

|Título|Descrição|
|-----------|-----------------|
|[Atualizando C++ projetos de versões anteriores do Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md)|Como atualizar sua base de código para o Visual Studio 2019 e v142 do compilador.|
|[Ferramentas IDE para atualizar C++ o código](ide-tools-for-upgrading-code.md)|Recursos de IDE úteis que ajudam no processo de atualização.|
|[C++Compatibilidade binária entre 2015 e 2019](binary-compat-2015-2017.md)|Consuma bibliotecas v140 no estado em que se encontram de projetos v142.|
|[Usar direcionamento múltiplo nativo no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md)|Use o Visual Studio 2019 com compiladores e bibliotecas mais antigos.|
|[Histórico de alterações de 2003 a 2015 do Visual C++](visual-cpp-change-history-2003-2015.md)|Uma lista de todas as alterações nas bibliotecas da C++ Microsoft e ferramentas de compilação do Visual Studio 2003 até 2015 que podem exigir alterações no seu código.|
|[O que há de novo no Visual C++ de 2003 até 2015](visual-cpp-what-s-new-2003-through-2015.md)|Todas as informações de "novidades" da Microsoft C++ do visual Studio 2003 por meio do visual Studio 2015.|
|[Portabilidade e atualização: exemplos e estudos de caso](porting-and-upgrading-examples-and-case-studies.md)|Nessa seção, portamos e atualizamos vários exemplos e aplicativos e discutimos as experiências e os resultados. Ao ler essa seção você pode obter uma noção do que está envolvido no processo de portabilidade e atualização. Durante o processo, discutimos a respeito de dicas e truques para a atualização e mostramos como erros específicos foram corrigidos.|
|[Portabilidade para a Plataforma Universal do Windows](porting-to-the-universal-windows-platform-cpp.md)|Contém informações sobre como fazer portabilidade de código para o Windows 10|
|[Introdução ao Visual C++ para usuários do UNIX](introduction-to-visual-cpp-for-unix-users.md)|Fornece informações para usuários do UNIX novatos no Visual C++ e que desejam tornar-se produtivos com ele.|
|[Executando programas do Linux no Windows](porting-from-unix-to-win32.md)|Discute as opções para migrar aplicativos UNIX para o Windows.|

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
[Novidades do compilador C++ no Visual Studio](../overview/what-s-new-for-visual-cpp-in-visual-studio.md)<br/>
[Aprimoramentos de conformidade do C++ no Visual Studio](../overview/cpp-conformance-improvements.md)<br/>
