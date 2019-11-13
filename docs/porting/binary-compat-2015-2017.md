---
title: C++compatibilidade binária entre o Visual Studio 2015, 2017 e 2019
description: Descreve como a compatibilidade binária funciona entre C++ arquivos compilados no Visual Studio 2015, 2017 e 2019. Um pacote redistribuível do Microsoft Visual C++ funciona para todas as três versões.
ms.date: 11/11/2019
helpviewer_keywords:
- binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
ms.openlocfilehash: 118ad0a32d5dc8c344967f9a67f2d5b05aa806c0
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965564"
---
# <a name="c-binary-compatibility-between-visual-studio-2015-2017-and-2019"></a>C++compatibilidade binária entre o Visual Studio 2015, 2017 e 2019

Os conjuntos C++ de ferramentas do compilador Microsoft (MSVC) no Visual Studio 2013 e versões anteriores não garantem a compatibilidade binária entre versões. Não é possível vincular arquivos de objeto, bibliotecas estáticas, bibliotecas dinâmicas e executáveis criados por versões diferentes. O ABIs, os formatos de objeto e as bibliotecas de tempo de execução são incompatíveis.

Alteramos esse comportamento no Visual Studio 2015, 2017 e 2019. As bibliotecas de tempo de execução e os aplicativos compilados por qualquer uma dessas versões do compilador são compatíveis com binário. Ele se reflete no número C++ principal do conjunto de ferramentas, que é 14 para todas as três versões. (A versão do conjunto de ferramentas é v140 para Visual Studio 2015, v141 para 2017 e v142 para 2019). Digamos que você tenha bibliotecas de terceiros criadas pelo Visual Studio 2015. Você ainda pode usá-los em um aplicativo criado pelo Visual Studio 2017 ou 2019. Não é necessário recompilar com um conjunto de ferramentas correspondente. A versão mais recente do pacote redistribuível do Microsoft Visual C++ (o redistribuível) funciona para todos eles.

Há uma exceção a essa regra: bibliotecas estáticas ou arquivos de objeto compilados usando o `/GL` opção de compilador *não são* compatíveis com binários entre versões.

O redistribuível que seu aplicativo usa tem uma restrição de compatibilidade binária importante. Ele se aplica quando você mistura binários criados com versões diferentes com suporte do conjunto de ferramentas. A versão redistribuível deve ser pelo menos a nova do conjunto de ferramentas mais recente usado por qualquer componente de aplicativo.

## <a name="upgrade-the-microsoft-visual-c-redistributable-from-visual-studio-2015-or-2017-to-visual-studio-2019"></a>Atualizar o Microsoft Visual C++ redistribuível do visual Studio 2015 ou 2017 para o Visual Studio 2019

Mantivemos o número de versão C++ principal do Microsoft Visual redistribuível da mesma para o Visual Studio 2015, 2017 e 2019. Isso significa que apenas uma instância do redistribuível pode ser instalada de cada vez. Uma versão mais recente substitui qualquer versão mais antiga que já esteja instalada. Por exemplo, um aplicativo pode instalar os pacotes redistribuíveis do Visual Studio 2015. Em seguida, outro aplicativo instala os pacotes redistribuíveis do Visual Studio 2019. A versão 2019 substitui a versão mais antiga, mas como elas são compatíveis com binários, o aplicativo anterior ainda funciona bem. Garantimos que a versão mais recente dos redistribuíveis tenha todos os recursos mais recentes, atualizações de segurança e correções de bugs. É por isso que sempre recomendamos que você atualize para a versão mais recente disponível.

Da mesma forma, você não pode instalar um redistribuível mais antigo quando uma versão mais recente já estiver instalada. O instalador relatará um erro se você tentar. Você verá um erro como este se instalar o 2015 ou 2017 redistribuível em um computador que já tenha a versão 2019:

```Output
0x80070666 - Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
```

Esse erro é por design. Recomendamos que você mantenha a versão mais recente instalada. Verifique se o instalador pode se recuperar desse erro silenciosamente.

## <a name="see-also"></a>Consulte também

\ de [histórico de alterações visuais C++ ](../porting/visual-cpp-change-history-2003-2015.md)
[Os últimos downloads redistribuíveis do Visual C++ com suporte](https://support.microsoft.com/help/2977003/the-latest-supported-visual-c-downloads)
