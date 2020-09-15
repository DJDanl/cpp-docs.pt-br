---
title: /std (Especificar versão padrão da linguagem)
description: A opção de compilador MSVC/STD especifica o padrão de linguagem C ou C++ com suporte do compilador.
ms.date: 09/11/2020
f1_keywords:
- /std
- -std
- /std:c++14
- /std:c++17
- /std:c11
- /std:c17
- VC.Project.VCCLCompilerTool.CppLanguageStandard
ms.assetid: 0acb74ba-1aa8-4c05-b96c-682988dc19bd
ms.openlocfilehash: 82f37377dc223bfe3f5e578e1c7f390da91752a1
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90075823"
---
# <a name="std-specify-language-standard-version"></a>`/std` (Especifique a versão padrão do idioma)

Habilite os recursos de linguagem C e C++ com suporte da versão especificada do padrão de linguagem C ou C++.

## <a name="syntax"></a>Sintaxe

> **`/std:c++14`**\
> **`/std:c++17`**\
> **`/std:c++latest`**\
> **`/std:c11`**\
> **`/std:c17`**

## <a name="remarks"></a>Comentários

A **`/std`** opção está disponível no Visual Studio 2017 e posterior. Ele é usado para controlar os recursos padrão de linguagem de programação ISO C ou C++, específicos da versão, habilitados durante a compilação do seu código. Essa opção permite que você desabilite o suporte para determinados novos recursos de linguagem e biblioteca: aqueles que podem dividir seu código existente em conformidade com uma versão específica do padrão de idioma.

### <a name="c-standards-support"></a>Suporte para padrões do C++

Por padrão, **`/std:c++14`** é especificado, que desabilita os recursos de biblioteca padrão e idioma encontrados em versões posteriores do padrão de linguagem C++. Use  **`/std:c++17`** para habilitar o comportamento e os recursos específicos padrão do c++ 17. Para habilitar explicitamente o compilador atualmente implementado e os recursos de biblioteca padrão propostos para o próximo padrão de rascunho, use **`/std:c++latest`** . Todos os recursos do C++ 20 exigem **`/std:c++latest`** ; quando a implementação for concluída, uma nova **`/std:c++20`** opção será habilitada.

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

### <a name="c-standards-support"></a>Suporte a padrões de C

Por padrão, quando o código é compilado como C, o compilador MSVC não está de acordo com um padrão C específico. Ele implementa o ANSI C89 com várias extensões da Microsoft, algumas das quais fazem parte do ISO C99. Algumas extensões da Microsoft podem ser desabilitadas usando a [`/Za`](za-ze-disable-language-extensions.md) opção do compilador, mas outras permanecem em vigor. Não é possível especificar a conformidade C89 estrita.

A partir do Visual Studio 2019 versão 16,8, você pode especificar **`/std:c11`** ou **`/std:c17`** para o código compilado como C. Essas opções especificam os modos de conformidade que correspondem ao ISO C11 e ao ISO C17. Como o novo pré-processador é necessário para dar suporte a esses padrões, as **`/std:c11`** Opções do compilador e do **`/std:c17`** definem a [`/Zc:preprocessor`](zc-preprocessor.md) opção automaticamente. Se você quiser usar o pré-processador tradicional (Herdado) para C11 ou C17, deverá definir a **`/Zc:preprocessor-`** opção de compilador explicitamente. Definir a **`/Zc:preprocessor-`** opção pode levar a um comportamento inesperado e não é recomendado.

> [!NOTE]
> No momento do lançamento, as bibliotecas SDK do Windows e UCRT mais recentes ainda não dão suporte a C11 e a código C17. Uma versão de pré-lançamento do SDK do Windows e do UCRT é necessária. Para obter mais informações e instruções de instalação, confira [instalar o suporte a C11 e C17 no Visual Studio](../../overview/install-c17-support.md).

Quando você especifica **`/std:c11`** ou **`/std:c17`** , o MSVC dá suporte a todos os recursos necessários de C11 e C17. As opções do compilador habilitam o suporte para essas funcionalidades:

- **`_Pragma`**

- **`restrict`**

- **`_Noreturn`** e \<stdnoreturn.h>

- **`_Alignas`****`_Alignof`** e\<stdalign.h>

- **`_Generic`** e \<tgmath.h>

- **`_Static_assert`**

O IDE usa as configurações de C para IntelliSense e o realce de código quando os arquivos de origem têm uma *`.c`* extensão de arquivo ou quando você especifica a [`/TC`](tc-tp-tc-tp-specify-source-file-type.md) opção do compilador. Atualmente, o realce do IntelliSense só está disponível para palavras-chave e não as macros introduzidas pelos cabeçalhos padrão.

Como C17 é basicamente um lançamento de correção de bug do ISO, o suporte do MSVC para C11 já inclui todos os relatórios de defeito relevantes. No momento, não há nenhuma diferença entre as versões C11 e C17, exceto a `__STDC_VERSION__` macro. Ele se expande para o `201112L` C11 e `201710L` para C17.

O compilador não dá suporte a recursos opcionais do ISO C11. Vários desses recursos opcionais do C11 eram os recursos necessários do C99 que o MSVC não implementou por motivos de arquitetura. Você pode usar as macros de teste de recurso, como `__STDC_NO_VLA__` para detectar níveis de suporte do compilador para recursos individuais. Para obter mais informações sobre macros predefinidas específicas de C, consulte [macros predefinidas](../../preprocessor/predefined-macros.md).

- Não há suporte para vários threads, atômicos ou de números complexos na versão 16,8 do Visual Studio 2019.

- `aligned_alloc` o suporte está ausente, devido à implementação do heap do Windows. A alternativa é usar [`_aligned_malloc`](../../c-runtime-library/reference/aligned-malloc.md) .

- O suporte a DR 400 não está implementado atualmente para `realloc` , pois essa alteração interromperia a Abi.

- O suporte a VLA (matriz de comprimento variável) não está planejado. Matrizes de comprimento variável geralmente são menos eficientes do que matrizes de tamanhos fixos comparáveis. Eles também são ineficientes em comparação com as alocações de memória de heap equivalentes, quando implementados com segurança e segurança. O VLAs fornece vetores de ataque comparáveis ao `gets()` , que são preteridos e planejados para remoção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **Propriedades de Configuração**, **C/C++**, **Linguagem**.

1. No **padrão de linguagem C++** (ou para c, **c Language Standard**), escolha o padrão de idioma para dar suporte a partir do controle suspenso e escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
