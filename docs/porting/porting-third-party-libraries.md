---
title: Portabilidade de bibliotecas de terceiros | Microsoft Docs
ms.custom: 
ms.date: 01/10/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- 3rd-party libraries
- vspkg
ms.assetid: b055ed20-8a9e-45b2-ac2a-e3d94271c009
caps.latest.revision: 0
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: 8630a5c0b97b85e0dc75e8b470974bb7d223a511
ms.openlocfilehash: 1d85010b6068d52d8522875a3c47561ad777d345
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---

# <a name="porting-third-party-libraries"></a>Portabilidade de bibliotecas de terceiros

Quando você atualiza um projeto para a versão atual do Visual C++, você também precisa atualizar todas as bibliotecas que o projeto usa, de forma que a biblioteca e seu projeto sejam compilados com a mesma versão e tipo do compilador. (Para obter mais informações, consulte [Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)). 

## <a name="introducing-vcpkg"></a>Introdução a vcpkg
No passado, localizar e atualizar bibliotecas de terceiros era, às vezes, uma tarefa não trivial. Para facilitar a aquisição e recompilação de bibliotecas C++ de software livre de terceiros, a equipe do Visual C++ criou uma ferramenta de linha de comando chamada **Ferramenta de Empacotamento do VC++** ou **vcpkg**. Vcpkg tem um catálogo de muitas bibliotecas C++ de software livre populares. Você pode instalar qualquer biblioteca no catálogo diretamente da linha de comando do vcpkg. Quando você instala uma biblioteca, o Vcpkg cria uma árvore de diretório em seu computador e adiciona o .h, o .lib e os binários nessa pasta. Você pode usar essa pasta em sua linha de comando de compilação ou integrá-la no Visual Studio 2015 ou posterior usando o comando vcpkg integrate install. Depois de você integrar um local de biblioteca, o Visual Studio pode encontrá-lo e adicioná-lo a qualquer novo projeto que você criar. Para usar uma biblioteca, apenas use #include para ela e o Visual Studio adicionará automaticamente o caminho .lib às configurações do projeto e copiará a dll para a pasta da solução.

## <a name="acquisition-and-usage"></a>Aquisição e uso

Você pode baixar o vcpkg do [repositório do GitHub do vcpkg][vcpkg](https://github.com/Microsoft/vcpkg/).

 - Para pesquisar por uma biblioteca no catálogo: vcpkg search <LibName>
 - Para adquirir uma biblioteca (por exemplo, Boost): vcpkg install boost
 - Para listar as bibliotecas que estão instaladas atualmente: lista de vcpkg

A postagem de blog [Vcpkg: uma ferramenta para adquirir e compilar bibliotecas C++ de software livre no Windows](https://blogs.msdn.microsoft.com/vcblog/2016/09/19/vcpkg-a-tool-to-acquire-and-build-c-open-source-libraries-on-windows/) explica como o vcpkg funciona e fornece uma lista de bibliotecas com suporte. A lista é atualizada toda semana.

## <a name="reporting-issues"></a>Relatando problemas
Se sua biblioteca não está presente no catálogo de vcpkg, você pode abrir um problema no [repositório GitHub](https://github.com/Microsoft/vcpkg/issues) em que a comunidade e a equipe do Visual C++ podem vê-lo e, possivelmente criar o arquivo de porta para esta biblioteca.

Para bibliotecas de terceiros proprietárias (que não são de software livre), é recomendável que você entre em contato com o provedor da biblioteca. No entanto, estamos interessados em saber de quaisquer bibliotecas proprietárias que você está usando e que lhe bloqueiam. Informe-nos de qual delas você depende (é possível entrar contatar-nos em vcupgrade@microsoft.com).

  
## <a name="see-also"></a>Consulte também  
 [Guia de atualização e portabilidade do Visual C++](visual-cpp-porting-and-upgrading-guide.md)

