---
title: Portabilidade de bibliotecas de terceiros
ms.date: 10/29/2019
helpviewer_keywords:
- 3rd-party libraries
- vspkg
ms.assetid: b055ed20-8a9e-45b2-ac2a-e3d94271c009
ms.openlocfilehash: 89460af1ad0b356f4f5952141636a9f067131750
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627184"
---
# <a name="porting-third-party-libraries"></a>Portabilidade de bibliotecas de terceiros

Quando você atualiza um projeto do Visual Studio 2013 ou anterior para a versão atual do Visual C++, também precisa atualizar todas as bibliotecas usadas pelo projeto, para que a biblioteca e o projeto sejam criados com a mesma versão e o tipo do compilador. Se você não tiver acesso ao código-fonte da biblioteca e a biblioteca não estiver disponível por meio do vcpkg, você deverá obter um binário atualizado do fornecedor da biblioteca. (Para obter mais informações, consulte [Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)).

Ao atualizar um aplicativo do Visual Studio 2015 ou do Visual Studio 2017 para o Visual Studio 2019, não é necessário atualizar as dependências porque o código gerado por essas três versões é compatível com binário. Para obter mais informações, consulte [ C++ compatibilidade binária entre o Visual Studio 2015 e o Visual Studio 2019](binary-compat-2015-2017.md).

## <a name="vcpkg-for-open-source-libraries"></a>vcpkg para bibliotecas de código-fonte aberto

No passado, localizar e atualizar bibliotecas de terceiros era, às vezes, uma tarefa não trivial. Para facilitar a aquisição e a recriação C++ de bibliotecas de software livre de terceiros, a C++ equipe Visual criou uma ferramenta de linha de comando chamada de **ferramenta de empacotamento vc + +** ou **vcpkg**. Vcpkg tem um catálogo de muitas bibliotecas C++ de software livre populares. Você pode instalar qualquer biblioteca no catálogo diretamente da linha de comando do vcpkg. Quando você instala uma biblioteca, o Vcpkg cria uma árvore de diretório em seu computador e adiciona o .h, o .lib e os binários nessa pasta. Você pode usar essa pasta em sua linha de comando de compilação ou integrá-la no Visual Studio 2015 ou posterior usando o comando vcpkg integrate install. Depois de você integrar um local de biblioteca, o Visual Studio pode encontrá-lo e adicioná-lo a qualquer novo projeto que você criar. Para usar uma biblioteca, basta incluí-la com `#include` e o Visual Studio adicionará automaticamente o caminho .lib às configurações do projeto e copiará a dll na pasta da solução. Para obter mais informações, consulte [vcpkg: um gerenciador de pacotes para C++](../build/vcpkg.md).

## <a name="reporting-issues"></a>Relatando problemas

Se a biblioteca de código-fonte aberto não estiver presente no catálogo **vcpkg** , você poderá abrir um problema no [repositório GitHub](https://github.com/Microsoft/vcpkg/issues) em que a Comunidade e C++ a equipe Visual podem vê-lo e, potencialmente, criar o arquivo de porta para essa biblioteca.

## <a name="see-also"></a>Consulte também

[Guia de atualização e portabilidade do Visual C++](visual-cpp-porting-and-upgrading-guide.md)
