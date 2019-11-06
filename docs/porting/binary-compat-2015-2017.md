---
title: C++compatibilidade binária entre o Visual Studio 2015 e o Visual Studio 2019
ms.date: 10/17/2019
helpviewer_keywords:
- binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
ms.openlocfilehash: 761f6187a8b30ecb4214821c7f91d1b26e9c647c
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627017"
---
# <a name="c-binary-compatibility-between-visual-studio-2015-and-visual-studio-2019"></a>C++compatibilidade binária entre o Visual Studio 2015 e o Visual Studio 2019

No Visual Studio 2013 e em versões anteriores, não havia garantia de compatibilidade binária entre arquivos-objetos (OBJs), bibliotecas estáticas (LIBs), bibliotecas dinâmicas (DLLs) e executáveis (EXEs) compilados com versões diferentes do conjunto de ferramentas do compilador e das bibliotecas de runtime. 

No Visual Studio 2015 e posteriores, o número principal do conjunto de ferramentas do C++ é 14 (v140 para Visual Studio 2015, v141 para Visual Studio 2017 e v142 para Visual Studio 2019). Isso reflete o fato de que as bibliotecas de tempo de execução e os aplicativos compilados com qualquer uma dessas versões do compilador são compatíveis com binários. Isso significa que, se você tiver uma biblioteca de terceiros que foi criada com o Visual Studio 2015, você não precisará recompilá-la a fim de consumi-la de um aplicativo criado com o Visual Studio 2017 ou com o Visual Studio 2019.

A única exceção a essa regra é que as bibliotecas estáticas ou os arquivos-objeto são compilados com o comutador de compilador `/GL` que não apresenta compatibilidade binária.

Quando você mistura binários criados com versões diferentes com suporte do conjunto de ferramentas do C++ MSVC, o Visual redistribuível no qual seu aplicativo é executado não pode ser mais antigo do que qualquer uma das versões do conjunto de ferramentas usadas para criar seu aplicativo ou quaisquer bibliotecas consumidas.

## <a name="upgrade-microsoft-visual-c-redistributable-from-visual-studio-2015-or-2017-to-visual-studio-2019"></a>Atualizar o Microsoft C++ Visual redistribuível do visual Studio 2015 ou 2017 para o Visual Studio 2019

Como preservamos a compatibilidade binária e mantivemos a versão principal (14) a mesma para os C++ pacotes redistribuíveis do visual Studio 2015, 2017 e 2019, apenas uma versão do Visual C++ redistribuível pode ser instalada a qualquer momento. Uma versão mais recente substituirá uma mais antiga instalada. Se você tiver os C++ pacotes redistribuíveis do visual Studio 2015 ou 2017 e, depois, instalar o 2019, a versão 2019 substituirá uma versão mais antiga. Como garantimos que a versão mais recente terá todos os recursos e correções de bugs mais recentes, incluindo correções de segurança, recomendamos sempre atualizar para a versão mais recente disponível.

Da mesma forma, não permitimos a instalação de uma versão C++ mais antiga do Visual redistribuível em um computador em que já exista uma mais nova. Instalar os C++ pacotes redistribuíveis do visual Studio 2015 ou 2017 em um computador que já tenha 2019, resultará em uma falha de instalação. O erro terá uma aparência semelhante a esta:

```
*0x80070666 - Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.*.
```

Esse erro é por design. É recomendável manter o mais recente instalado.

## <a name="see-also"></a>Consulte também

* [Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)
* [Os últimos downloads redistribuíveis do Visual C++ com suporte](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads) 
