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
ms.sourcegitcommit: ed0e4505b68c2ea198e0771b6301e685daa8662e
ms.openlocfilehash: d2707321719e5ff6afa84203fd79d975bb696960
ms.contentlocale: pt-br
ms.lasthandoff: 06/30/2017

---

# Portabilidade de bibliotecas de terceiros
<a id="porting-third-party-libraries" class="xliff"></a>

Quando você atualiza um projeto para a versão atual do Visual C++, você também precisa atualizar todas as bibliotecas que o projeto usa, de forma que a biblioteca e seu projeto sejam compilados com a mesma versão e tipo do compilador. (Para obter mais informações, consulte [Visão geral de possíveis problemas de atualização](overview-of-potential-upgrade-issues-visual-cpp.md)). 

## Introdução a vcpkg
<a id="introducing-vcpkg" class="xliff"></a>
No passado, localizar e atualizar bibliotecas de terceiros era, às vezes, uma tarefa não trivial. Para facilitar a aquisição e recompilação de bibliotecas C++ de software livre de terceiros, a equipe do Visual C++ criou uma ferramenta de linha de comando chamada **Ferramenta de Empacotamento do VC++** ou **vcpkg**. Vcpkg tem um catálogo de muitas bibliotecas C++ de software livre populares. Você pode instalar qualquer biblioteca no catálogo diretamente da linha de comando do vcpkg. Quando você instala uma biblioteca, o Vcpkg cria uma árvore de diretório em seu computador e adiciona o .h, o .lib e os binários nessa pasta. Você pode usar essa pasta em sua linha de comando de compilação ou integrá-la no Visual Studio 2015 ou posterior usando o comando vcpkg integrate install. Depois de você integrar um local de biblioteca, o Visual Studio pode encontrá-lo e adicioná-lo a qualquer novo projeto que você criar. Para usar uma biblioteca, apenas use #include para ela e o Visual Studio adicionará automaticamente o caminho .lib às configurações do projeto e copiará a dll para a pasta da solução. Para obter mais informações, consulte [vcpkg: um gerenciador de pacotes para C++](../vcpkg.md).


## Relatando problemas
<a id="reporting-issues" class="xliff"></a>
Se sua biblioteca não está presente no catálogo de vcpkg, você pode abrir um problema no [repositório GitHub](https://github.com/Microsoft/vcpkg/issues) em que a comunidade e a equipe do Visual C++ podem vê-lo e, possivelmente criar o arquivo de porta para esta biblioteca.

Para bibliotecas de terceiros proprietárias (que não são de software livre), é recomendável que você entre em contato com o provedor da biblioteca. No entanto, estamos interessados em saber de quaisquer bibliotecas proprietárias que você está usando e que lhe bloqueiam. Informe-nos de qual delas você depende (é possível entrar contatar-nos em vcupgrade@microsoft.com).

  
## Consulte também
<a id="see-also" class="xliff"></a>  
 [Guia de atualização e portabilidade do Visual C++](visual-cpp-porting-and-upgrading-guide.md)

