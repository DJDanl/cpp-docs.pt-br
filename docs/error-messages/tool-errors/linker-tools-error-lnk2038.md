---
title: Erro das Ferramentas de Vinculador LNK2038
ms.date: 12/15/2017
f1_keywords:
- LNK2038
helpviewer_keywords:
- LNK2038
ms.openlocfilehash: ea1509d846c0bc5a85f0f0252b611dfd38496bcb
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506006"
---
# <a name="linker-tools-error-lnk2038"></a>Erro das Ferramentas de Vinculador LNK2038

> incompatibilidade detectada para '*Name*': o valor '*value_1*' não corresponde ao valor '*value_2*' em *filename. obj*

Uma incompatibilidade de símbolo foi detectada pelo vinculador. Esse erro indica que partes diferentes de um aplicativo, incluindo bibliotecas ou outro código de objeto ao qual o aplicativo se vincula, usam definições conflitantes do símbolo. O pragma de [incompatibilidade de detecção](../../preprocessor/detect-mismatch.md) é usado para definir esses símbolos e detectar seus valores conflitantes.

## <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Esse erro pode ocorrer quando um arquivo de objeto em seu projeto está desatualizado. Antes de tentar outras soluções para esse erro, execute uma compilação limpa para garantir que os arquivos de objeto sejam atuais.

O Visual Studio define os seguintes símbolos para evitar a vinculação de código incompatível, o que pode causar erros em tempo de execução ou outro comportamento inesperado.

- `_MSC_VER` Indica os números de versão principal e secundária do compilador do Microsoft C++ (MSVC) que é usado para criar um aplicativo ou uma biblioteca. O código que é compilado usando uma versão do MSVC é incompatível com o código que é compilado usando uma versão que tem números de versão principais e secundários diferentes. Para obter mais informações, consulte `_MSC_VER` em [macros predefinidas](../../preprocessor/predefined-macros.md).

   Se você estiver vinculando a uma biblioteca que não é compatível com a versão do MSVC que você está usando e não puder adquirir ou criar uma versão compatível da biblioteca, poderá usar uma versão anterior do compilador para compilar seu projeto: alterar a propriedade do conjunto de **ferramentas da plataforma** do projeto para o conjunto de ferramentas anterior. Para obter mais informações, consulte [como modificar o Framework de destino e o conjunto de ferramentas de plataforma](../../build/how-to-modify-the-target-framework-and-platform-toolset.md).

- `_ITERATOR_DEBUG_LEVEL` Indica o nível de recursos de segurança e depuração habilitados na biblioteca padrão C++. Esses recursos podem alterar a representação de certos objetos de biblioteca padrão do C++ e, portanto, torná-los incompatíveis com aqueles que usam recursos diferentes de segurança e depuração. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../../standard-library/iterator-debug-level.md).

- `RuntimeLibrary` Indica a versão da biblioteca padrão C++ e do tempo de execução C usado por um aplicativo ou uma biblioteca. O código que usa uma versão da biblioteca C++ Standard ou do tempo de execução C é incompatível com o código que usa uma versão diferente. Para obter mais informações, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md).

- `_PPLTASKS_WITH_WINRT` Indica que o código que usa a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) está vinculado a objetos compilados usando uma configuração diferente para a opção de compilador [/zw](../../build/reference/zw-windows-runtime-compilation.md) . (**/Zw** dá suporte a C++/CX.) O código que usa ou depende da PPL deve ser compilado usando a mesma configuração de **/zw** que é usada no restante do aplicativo.

Certifique-se de que os valores desses símbolos sejam consistentes em todos os projetos em sua solução do Visual Studio e também que eles sejam consistentes com o código e as bibliotecas aos quais seu aplicativo se vincula.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e vcpkg

Se você vir esse erro ao tentar configurar uma biblioteca de terceiros como parte de sua compilação, considere usar o [vcpkg](../../build/vcpkg.md), um Gerenciador de pacotes do C++, para instalar e criar a biblioteca. o vcpkg dá suporte a uma lista grande e crescente [de bibliotecas de](https://github.com/Microsoft/vcpkg/tree/master/ports)terceiros e define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto.

## <a name="see-also"></a>Consulte também

[Erros e avisos das ferramentas do vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)
