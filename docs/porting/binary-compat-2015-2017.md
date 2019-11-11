---
title: C++compatibilidade binária entre o Visual Studio 2015 e o Visual Studio 2019
description: Descreve como a compatibilidade binária funciona entre C++ arquivos compilados no Visual Studio 2015, 2017 e 2019. Um pacote redistribuível do Microsoft Visual C++ funciona para todas as três versões.
ms.date: 11/07/2019
helpviewer_keywords:
- binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
ms.openlocfilehash: e41c34abe25deefe100f525044faeac0b0c3054a
ms.sourcegitcommit: eb254b4462a58d219376ff501bf768bd1adc07ae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/11/2019
ms.locfileid: "73912886"
---
# <a name="c-binary-compatibility-between-visual-studio-2015-and-visual-studio-2019"></a>C++compatibilidade binária entre o Visual Studio 2015 e o Visual Studio 2019

No Microsoft Visual Studio 2013 e versões anteriores, a compatibilidade binária não é garantida entre arquivos de objeto (objs tivessem), bibliotecas estáticas (bibliotecas), DLLs (bibliotecas de vínculo dinâmico) e executáveis (EXEs) que foram criados usando versões diferentes do conjunto de ferramentas do compilador e bibliotecas de tempo de execução.

No Visual Studio 2015 e posteriores, o número principal do conjunto de ferramentas do C++ é 14 (v140 para Visual Studio 2015, v141 para Visual Studio 2017 e v142 para Visual Studio 2019). Essa numeração reflete o fato de que as bibliotecas de tempo de execução e os aplicativos compilados com qualquer uma dessas versões do compilador são compatíveis com binários. Portanto, se você tiver uma biblioteca de terceiros criada com o Visual Studio 2015, não precisará recompilá-la para consumi-la a partir de um aplicativo criado com o Visual Studio 2017 ou o Visual Studio 2019.

A única exceção a essa regra é que as bibliotecas estáticas ou os arquivos de objeto que são compilados com a opção de compilador `/GL` *não* são compatíveis com binários.

Quando você mistura binários criados com versões diferentes com suporte do C++ conjunto de ferramentas da Microsoft (MSVC C++ ), o pacote redistribuível do Visual no qual seu aplicativo é executado não pode ser mais antigo do que qualquer uma das versões do conjunto de ferramentas usadas para compilar seu aplicativo ou quaisquer bibliotecas consumidas.

## <a name="upgrade-the-microsoft-visual-c-redistributable-from-visual-studio-2015-or-2017-to-visual-studio-2019"></a>Atualizar o Microsoft Visual C++ redistribuível do visual Studio 2015 ou 2017 para o Visual Studio 2019

Como nós preservamos a compatibilidade binária e mantivemos a versão principal (14) a mesma em todos C++ os pacotes redistribuíveis do Microsoft visual Studio 2015, 2017 e 2019, apenas uma versão C++ do Visual redistribuível pode ser instalada a partir delas a qualquer momento. Uma versão mais recente substitui uma versão mais antiga que já está instalada. Se você tiver os C++ pacotes redistribuíveis do visual Studio 2015 ou 2017 e depois instalar o visual Studio 2019, a versão 2019 substituirá a versão mais antiga. Como garantimos que a versão mais recente tenha todos os recursos e correções de bugs mais recentes (incluindo correções de segurança), sempre recomendamos que você atualize para a versão mais recente disponível.

Da mesma forma, não permitimos que você instale uma versão mais C++ antiga do Visual redistribuível em um computador em que uma versão mais recente já esteja instalada. Instalar os C++ pacotes redistribuíveis do visual Studio 2015 ou 2017 em um computador que já tenha a versão 2019 dispara uma falha de instalação. O erro é semelhante ao seguinte:

```Output
0x80070666 - Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
```

Esse erro é por design. É recomendável manter a versão mais recente instalada.

## <a name="see-also"></a>Consulte também

* [Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)
* [Os últimos downloads redistribuíveis do Visual C++ com suporte](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads) 
