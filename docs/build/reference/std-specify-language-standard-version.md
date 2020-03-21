---
title: /std (Especificar versão padrão da linguagem)
ms.date: 05/16/2019
f1_keywords:
- /std
- -std
- VC.Project.VCCLCompilerTool.CppLanguageStandard
ms.assetid: 0acb74ba-1aa8-4c05-b96c-682988dc19bd
ms.openlocfilehash: 52aa99cf5bdf7ddcf83a8423b946a03d2ca95d2d
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079263"
---
# <a name="std-specify-language-standard-version"></a>/std (Especificar versão padrão da linguagem)

Habilite as funcionalidades da linguagem C++ compatíveis da versão especificada do padrão da linguagem C++.

## <a name="syntax"></a>Sintaxe

> /std:\[c++14\|c++17\|c++latest]

## <a name="remarks"></a>Comentários

A opção **/std** está disponível no Visual Studio 2017 e posterior. Ela é usada para controlar as funcionalidades padrão da linguagem de programação C++ do ISO específico da versão habilitadas durante a compilação do código. Essa opção permite que você desabilite o suporte para algumas novas funcionalidades de linguagem e biblioteca que possam interromper o código existente em conformidade com uma versão específica do padrão da linguagem. Por padrão, **/std:c++14** é especificado, o que desabilita funcionalidades da linguagem e da biblioteca padrão encontradas nas versões posteriores do padrão da linguagem C++. Use **/std:c++17** para habilitar o comportamento e as funcionalidades específicas do padrão do C++17. Para habilitar explicitamente o compilador atualmente implementado e as funcionalidades da biblioteca padrão propostas para o próximo padrão de rascunho, use **/std:c++latest**. Todos os recursos do C++ 20 exigem **/std: C + + mais recente**; Quando a implementação for concluída, uma nova opção **/std: c++ 20** será habilitada.

A opção **/std:c++14** padrão habilita o conjunto de funcionalidades do C++14 implementado pelo compilador do MSVC. Essa opção desabilita o suporte do compilador e da biblioteca padrão para as funcionalidades que são alteradas ou novas em versões mais recentes do padrão da linguagem, com exceção de algumas funcionalidades do C++17 já implementadas em versões anteriores do compilador do MSVC. Para evitar alterações da falha para os usuários que já usaram dependências nas funcionalidades disponíveis no Visual Studio 2015 Atualização 2 em diante, essas funcionalidades permanecerão habilitadas quando a opção **/std:c++14** for especificada:

- [Regras para automático com listas de inicialização entre chaves](https://wg21.link/n3922)

- [Nome de tipo em parâmetros de modelo do modelo](https://wg21.link/n4051)

- [Como remover trígrafos](https://wg21.link/n4086)

- [Atributos para namespaces e enumeradores](https://wg21.link/n4266)

- [Literais de caracteres u8](https://wg21.link/n4267)

Para obter informações adicionais sobre quais recursos C++ 14 e C++ 17 estão habilitados quando **/std: c++ 14** for especificado, consulte as observações na [tabela de conformidade de idioma da Microsoft C++ ](../../overview/visual-cpp-language-conformance.md).

A opção **/std:c++17** habilita o conjunto completo de funcionalidades do C++17 implementado pelo compilador do MSVC. Essa opção desabilita o suporte ao compilador e à biblioteca padrão para funcionalidades alteradas ou novas nas versões das atualizações de defeito e de rascunho de trabalho do C++ Standard após o C++17.

A opção **/std:c++latest** habilita as funcionalidades de linguagem e biblioteca pós C++17 atualmente implementadas no compilador e nas bibliotecas. Elas podem incluir funcionalidades do Rascunho de Trabalho do C++20 e atualizações de defeitos do Padrão do C++ que não estão incluídos no C++17, bem como propostas experimentais para o padrão de rascunho. Para obter uma lista de funcionalidades de linguagem e biblioteca compatíveis, confira [Novidades do Visual C++](../../overview/what-s-new-for-visual-cpp-in-visual-studio.md). A opção **/std:c++latest** não habilita as funcionalidades protegidas pela opção **/experimental**, mas pode ser necessário habilitá-las.

> [!IMPORTANT]
> As funcionalidades de compilador e de biblioteca habilitadas por **/std:c++latest** representam as funcionalidades que podem aparecer em um padrão futuro do C++, bem como as funcionalidades aprovadas do C++20. As funcionalidades que não foram aprovadas estão sujeitas à alteração da falha ou à remoção sem aviso prévio e são fornecidas no estado em que se encontram.

A opção **/std** em vigor durante uma compilação do C++ pode ser detectada por meio do uso da macro do pré-processador [\_MSVC\_LANG](../../preprocessor/predefined-macros.md). Para obter mais informações, confira [Macros do pré-processador](../../preprocessor/predefined-macros.md).

As opções **/std:c++14** e **/std:c++latest** estão disponíveis no Visual Studio 2015 Atualização 3. A opção **/std:c++17** está disponível no Visual Studio 2017 versão 15.3 em diante. Conforme indicado acima, alguns comportamentos padrão do C++17 são habilitados pela opção **/std:c++14**, mas todas as outras funcionalidades do C++17 são habilitadas por **/std:c++17**. As funcionalidades do C++20 são habilitadas por **/std:latest** até a implementação ser concluída.

> [!NOTE]
> Dependendo da versão do compilador do MSVC ou do nível da atualização, as funcionalidades do C++17 talvez não sejam totalmente implementadas nem estejam totalmente em conformidade quando você especificar as opções **/std:c++17**. Para obter uma visão C++ geral da conformidade de C++ idioma no Visual pela versão de lançamento, consulte [tabela de conformidade de idioma da Microsoft C++ ](../../overview/visual-cpp-language-conformance.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **Propriedades de Configuração**, **C/C++** , **Linguagem**.

1. Em **Padrão de Linguagem C++** , escolha o padrão de linguagem para dar suporte no controle suspenso e, em seguida, escolha **OK** ou **Aplicar** para salvar as alterações.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
