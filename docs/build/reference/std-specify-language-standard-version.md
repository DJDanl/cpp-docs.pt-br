---
title: /std (Especificar versão padrão da linguagem)
ms.date: 06/04/2020
f1_keywords:
- /std
- -std
- VC.Project.VCCLCompilerTool.CppLanguageStandard
ms.assetid: 0acb74ba-1aa8-4c05-b96c-682988dc19bd
ms.openlocfilehash: 9755194d70774f27af4c5174151588cc03d5f97a
ms.sourcegitcommit: 65fead53d56d531d71be42216056aca5f44def11
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/19/2020
ms.locfileid: "88610953"
---
# <a name="std-specify-language-standard-version"></a>`/std` (Especifique a versão padrão do idioma)

Habilite as funcionalidades da linguagem C++ compatíveis da versão especificada do padrão da linguagem C++.

## <a name="syntax"></a>Sintaxe

> **`/std:c++14`**\
> **`/std:c++17`**\
> **`/std:c++latest`**

## <a name="remarks"></a>Comentários

A **`/std`** opção está disponível no Visual Studio 2017 e posterior. Ele é usado para controlar os recursos padrão de linguagem de programação ISO C++ específicos da versão habilitados durante a compilação do seu código. Essa opção permite que você desabilite o suporte para determinados novos recursos de linguagem e biblioteca: aqueles que podem dividir seu código existente em conformidade com uma versão específica do padrão de idioma. Por padrão, **`/std:c++14`** é especificado, que desabilita os recursos de biblioteca padrão e idioma encontrados em versões posteriores do padrão de linguagem C++. Use  **`/std:c++17`** para habilitar o comportamento e os recursos específicos padrão do c++ 17. Para habilitar explicitamente o compilador atualmente implementado e os recursos de biblioteca padrão propostos para o próximo padrão de rascunho, use **`/std:c++latest`** . Todos os recursos do C++ 20 exigem **`/std:c++latest`** ; quando a implementação for concluída, uma nova **`/std:c++20`** opção será habilitada.

A **`/std:c++14`** opção padrão habilita o conjunto de recursos do c++ 14 implementados pelo compilador MSVC. Essa opção desabilita o suporte do compilador e da biblioteca padrão para recursos que são alterados ou novos em versões mais recentes do padrão de idioma. Ele não desabilita alguns recursos do C++ 17 já implementados em versões anteriores do compilador do MSVC. Para evitar alterações significativas para usuários que já fizeram dependências nos recursos disponíveis no ou antes do Visual Studio 2015 atualização 2, esses recursos permanecem habilitados quando a **`/std:c++14`** opção é especificada:

- [Regras para `auto` com chaves-init-Lists](https://wg21.link/n3922)

- [`typename` em modelo de modelo-parâmetros](https://wg21.link/n4051)

- [Como remover trígrafos](https://wg21.link/n4086)

- [Atributos para namespaces e enumeradores](https://wg21.link/n4266)

- [Literais de caracteres u8](https://wg21.link/n4267)

Uma lista de quais recursos C++ 14 e C++ 17 estão habilitados quando você especifica o **`/std:c++14`** está disponível. Para obter mais informações, consulte as observações na [tabela de conformidade da linguagem Microsoft C++](../../overview/visual-cpp-language-conformance.md).

A **`/std:c++17`** opção habilita o conjunto completo de recursos do c++ 17 implementados pelo compilador do MSVC. Esta opção desabilita o suporte do compilador e da biblioteca padrão para recursos novos ou alterados após o C++ 17. Isso inclui alterações pós-C + + 17 em versões do rascunho de trabalho e atualizações de defeito do padrão C++.

A **`/std:c++latest`** opção habilita os recursos de linguagem e biblioteca pós-C + + 17 atualmente implementados no compilador e nas bibliotecas. Esses recursos podem incluir alterações do rascunho de trabalho do C++ 20, atualizações de defeito que não estão incluídas em C++ 17 e propostas experimentais para o padrão de rascunho. Para obter uma lista de funcionalidades de linguagem e biblioteca compatíveis, confira [Novidades do Visual C++](../../overview/what-s-new-for-visual-cpp-in-visual-studio.md). A **`/std:c++latest`** opção não habilita recursos protegidos pelo **`/experimental`** comutador, mas pode ser necessário habilitá-los.

> [!IMPORTANT]
> Os recursos de biblioteca e compilador habilitados pelo **`/std:c++latest`** representam recursos que podem aparecer em um futuro padrão c++, bem como recursos do c++ 20 que são aprovados. As funcionalidades que não foram aprovadas estão sujeitas à alteração da falha ou à remoção sem aviso prévio e são fornecidas no estado em que se encontram.

A **`/std`** opção em vigor durante uma compilação de C++ pode ser detectada pelo uso da macro de pré-processador do [ \_ MSVC \_ Lang](../../preprocessor/predefined-macros.md) . Para obter mais informações, confira [Macros do pré-processador](../../preprocessor/predefined-macros.md).

As **`/std:c++14`** **`/std:c++latest`** Opções e estão disponíveis a partir do Visual Studio 2015 atualização 3. A **`/std:c++17`** opção está disponível a partir do Visual Studio 2017 versão 15,3. Conforme observado acima, alguns comportamentos padrão do C++ 17 são habilitados pela **`/std:c++14`** opção, mas todos os outros recursos do c++ 17 são habilitados pelo **`/std:c++17`** . Os recursos do c++ 20 são habilitados **`/std:c++latest`** até que a implementação seja concluída.

> [!NOTE]
> Dependendo da versão do compilador MSVC ou do nível de atualização, os recursos do C++ 17 podem não ser totalmente implementados ou estar totalmente em conformidade quando você especifica as **`/std:c++17`** opções. Para obter uma visão geral da conformidade da linguagem C++ em Visual C++ pela versão de lançamento, consulte a [tabela de conformidade da linguagem Microsoft C++](../../overview/visual-cpp-language-conformance.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **Propriedades de Configuração**, **C/C++**, **Linguagem**.

1. Em **Padrão de Linguagem C++**, escolha o padrão de linguagem para dar suporte no controle suspenso e, em seguida, escolha **OK** ou **Aplicar** para salvar as alterações.

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
