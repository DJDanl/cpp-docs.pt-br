---
title: Portabilidade de bibliotecas de terceiros
ms.date: 01/10/2017
helpviewer_keywords:
- 3rd-party libraries
- vspkg
ms.assetid: b055ed20-8a9e-45b2-ac2a-e3d94271c009
ms.openlocfilehash: 1abd7f05614317237c911ceb69c243211a373e34
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658296"
---
# <a name="porting-third-party-libraries"></a>Portabilidade de bibliotecas de terceiros

Quando você atualiza um projeto para a versão atual do Visual C++, você também precisa atualizar todas as bibliotecas que o projeto usa, de forma que a biblioteca e seu projeto sejam compilados com a mesma versão e tipo do compilador. (Para obter mais informações, consulte [Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)).

## <a name="introducing-vcpkg"></a>Introdução a vcpkg

No passado, localizar e atualizar bibliotecas de terceiros era, às vezes, uma tarefa não trivial. Para facilitar a aquisição e recompilação de bibliotecas C++ de software livre de terceiros, a equipe do Visual C++ criou uma ferramenta de linha de comando chamada **Ferramenta de Empacotamento do VC++** ou **vcpkg**. Vcpkg tem um catálogo de muitas bibliotecas C++ de software livre populares. Você pode instalar qualquer biblioteca no catálogo diretamente da linha de comando do vcpkg. Quando você instala uma biblioteca, o Vcpkg cria uma árvore de diretório em seu computador e adiciona o .h, o .lib e os binários nessa pasta. Você pode usar essa pasta em sua linha de comando de compilação ou integrá-la no Visual Studio 2015 ou posterior usando o comando vcpkg integrate install. Depois de você integrar um local de biblioteca, o Visual Studio pode encontrá-lo e adicioná-lo a qualquer novo projeto que você criar. Para usar uma biblioteca, basta incluí-la com `#include` e o Visual Studio adicionará automaticamente o caminho .lib às configurações do projeto e copiará a dll na pasta da solução. Para obter mais informações, consulte [vcpkg: um gerenciador de pacotes para C++](../vcpkg.md).

## <a name="reporting-issues"></a>Relatando problemas

Se sua biblioteca não estiver presente no catálogo do **vcpkg**, abra um problema no [repositório do GitHub](https://github.com/Microsoft/vcpkg/issues), no qual a comunidade e a equipe do Visual C++ poderão vê-lo e, possivelmente, criar o arquivo de porta para essa biblioteca.

Para bibliotecas de terceiros proprietárias (que não são de software livre), é recomendável que você entre em contato com o provedor da biblioteca. No entanto, estamos interessados em saber de quaisquer bibliotecas proprietárias que você está usando e que lhe bloqueiam. Informe-nos de qual delas você depende (é possível entrar contatar-nos em vcupgrade@microsoft.com).

## <a name="see-also"></a>Consulte também

[Guia de atualização e portabilidade do Visual C++](visual-cpp-porting-and-upgrading-guide.md)