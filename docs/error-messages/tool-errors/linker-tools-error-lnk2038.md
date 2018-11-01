---
title: Erro das Ferramentas de Vinculador LNK2038
ms.date: 12/15/2017
f1_keywords:
- LNK2038
helpviewer_keywords:
- LNK2038
ms.openlocfilehash: a22b31f1ac3226271ed7ff03b5be7dad7fff6b93
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594305"
---
# <a name="linker-tools-error-lnk2038"></a>Erro das Ferramentas de Vinculador LNK2038

> incompatibilidade detectada para '*nome*': valor '*value_1*'não corresponde ao valor'*value_2*' em *filename. obj*

Foi detectada uma incompatibilidade de símbolo pelo vinculador. Esse erro indica que diferentes partes de um aplicativo, incluindo bibliotecas ou outro objeto de código que os links do aplicativo, use definições conflitantes do símbolo. O [detectar incompatibilidade de](../../preprocessor/detect-mismatch.md) pragma é usado para definir esses símbolos e detectar seus valores conflitante.

## <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Esse erro pode ocorrer quando um arquivo de objeto em seu projeto está desatualizado. Antes de tentar outras soluções para esse erro, execute uma compilação limpa para garantir que os arquivos de objeto sejam atuais.

O Visual Studio define os símbolos a seguir para evitar vincular códigos incompatíveis, que pode causar erros de tempo de execução ou outro comportamento inesperado.

- `_MSC_VER` Indica os números de versão principal e secundária do compilador Visual C++ que é usado para compilar um aplicativo ou biblioteca. Código que é compilado usando uma versão do compilador do Visual C++ é compatível com o código é compilado usando uma versão que tem números de versão principal e secundário diferentes. Para obter mais informações, consulte `_MSC_VER` na [Macros predefinidas](../../preprocessor/predefined-macros.md).

   Se você estiver vinculando a uma biblioteca que não é compatível com a versão do compilador do Visual C++ que você está usando, e você não pode adquirir ou compilar uma versão compatível da biblioteca, você pode usar uma versão anterior do compilador para compilar seu projeto: alterar o <C1/>conjunto de ferramentas de plataforma** propriedade do projeto para o conjunto de ferramentas anterior. Para obter mais informações, consulte [como: modificar a estrutura de destino e o conjunto de ferramentas de plataforma](../../build/how-to-modify-the-target-framework-and-platform-toolset.md).

- `_ITERATOR_DEBUG_LEVEL` Indica o nível de segurança e funcionalidades de depuração que estão habilitadas na biblioteca padrão C++. Esses recursos podem alterar a representação de determinados objetos de biblioteca padrão C++ e, portanto, torná-los incompatíveis com aqueles que use a segurança diferentes e recursos de depuração. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../../standard-library/iterator-debug-level.md).

- `RuntimeLibrary` Indica a versão do tempo de execução do C e de biblioteca padrão C++ que é usado por um aplicativo ou uma biblioteca. Código que usa uma versão de tempo de execução do C ou C++ Standard Library é compatível com o código que usa uma versão diferente. Para obter mais informações, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md).

- `_PPLTASKS_WITH_WINRT` Indica que o código que usa o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) está vinculado a objetos compilados usando uma configuração diferente para o [/ZW](../../build/reference/zw-windows-runtime-compilation.md) opção de compilador. (**/ZW** dá suporte a C + + c++ /CLI CX.) Código que usa ou depende PPL deve ser compilado usando o mesmo **/ZW** configuração que é usada no restante do aplicativo.

Certifique-se de que os valores desses símbolos sejam consistentes em todos os projetos na solução do Visual Studio e que também são consistentes com o código e bibliotecas que seu aplicativo é vinculado.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e Vcpkg

Se você vir esse erro quando você está tentando configurar uma biblioteca de terceiros como parte da compilação, considere o uso [Vcpkg](../../vcpkg.md), o Visual C++ Gerenciador de pacotes para instalar e criar a biblioteca. Vcpkg dá suporte a um grande e crescente [lista de bibliotecas de terceiros](https://github.com/Microsoft/vcpkg/tree/master/ports)e define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto. Para obter mais informações, consulte relacionado [Blog do Visual C++](https://blogs.msdn.microsoft.com/vcblog/2016/09/19/vcpkg-a-tool-to-acquire-and-build-c-open-source-libraries-on-windows/) lançar.

## <a name="see-also"></a>Consulte também

[Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)