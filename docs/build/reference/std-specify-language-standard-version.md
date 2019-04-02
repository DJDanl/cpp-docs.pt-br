---
title: /STD (especificar versão de idioma padrão)
ms.date: 11/26/2018
f1_keywords:
- /std
- -std
- VC.Project.VCCLCompilerTool.CppLanguageStandard
ms.assetid: 0acb74ba-1aa8-4c05-b96c-682988dc19bd
ms.openlocfilehash: 32c63240f578b6170ae351cdf0cd1628167464b6
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58779736"
---
# <a name="std-specify-language-standard-version"></a>/STD (especificar versão de idioma padrão)

Habilitar suporte para recursos da linguagem C++ da versão especificada da linguagem C++ padrão.

## <a name="syntax"></a>Sintaxe

> /std:\[c++14\|c++17\|c++latest]

## <a name="remarks"></a>Comentários

O **/std** opção está disponível no Visual Studio 2017 e posterior. Ele é usado para controlar a versão específica de programação ISO C++ recursos padrão de idioma habilitados durante a compilação do seu código. Essa opção permite que você desabilite o suporte para determinados recursos de linguagem e biblioteca novos que podem quebrar o código existente que esteja de acordo com uma versão específica do idioma padrão. Por padrão, **/std: c + + 14** for especificado, que desabilita recursos de linguagem e biblioteca padrão encontrados nas versões mais recentes da linguagem C++ padrão. Use **/std: c + + 17** para habilitar o comportamento e específicas do padrão de recursos do c++17. Para habilitar explicitamente o compilador implementado atualmente e recursos da biblioteca padrão propostos para o próximo padrão de rascunho, use **/std: c + + mais recente**.

O padrão **/std: c + + 14** opção permite que o conjunto de recursos do c++14 implementado pelo compilador MSVC. Esta opção desabilita o compilador e suporte de biblioteca padrão para recursos que são alterados ou novos em versões mais recentes do idioma padrão, com exceção de alguns recursos do c++17 já implementados em versões anteriores do compilador MSVC. Para evitar alterações interruptivas para os usuários que já obtiveram dependências nos recursos disponíveis a partir do Visual Studio 2015 atualização 2, esses recursos permanecerão habilitados quando o **/std: c + + 14** opção for especificada:

- [Regras para automático com listas de inicialização entre chaves](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html)

- [TypeName nos parâmetros de modelo do modelo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4051.html)

- [Removendo trígrafos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4086.html)

- [Atributos para namespaces e enumeradores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html)

- [literais de caracteres U8](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html)

Para obter mais informações sobre quais C + + 14 e C + + 17 recursos estão habilitados quando **/std:c++17 + + 14** é especificado, consulte as notas na [conformidade com a linguagem Visual C++](../../overview/visual-cpp-language-conformance.md).

O **/std: c + + 17** opção habilita o conjunto completo de recursos do c++17 implementado pelo compilador MSVC. Essa opção desabilita o suporte ao compilador e à biblioteca padrão para funcionalidades alteradas ou novas nas versões das atualizações de defeito e de rascunho de trabalho do C++ Standard após o C++17.

O **/std:c++17 + + mais recente** opção permite que o post-C + + 17 recursos de linguagem e biblioteca atualmente implementados no compilador e bibliotecas. Eles podem incluir recursos das C + + 20 defeito e rascunho de trabalho atualizações do C++ Standard que não estão incluídos no c++17, bem como propostas experimentais para o padrão de rascunho. Para obter uma lista de idiomas com suporte e recursos de biblioteca, consulte [o que há de novo para o Visual C++](../../overview/what-s-new-for-visual-cpp-in-visual-studio.md). O **/std:c++17 + + mais recente** opção não permite recursos protegidos pela **/ experimental** mudar, mas pode ser necessário habilitá-los.

> [!IMPORTANT]
> Os recursos de biblioteca e compilador habilitados pela **/std:c++17 + + mais recente** são fornecidos como-está e sem suporte. Eles estão sujeitos às últimas alterações ou remoção sem aviso prévio. Eles destinam-se como uma visualização dos recursos de linguagem que podem aparecer na próxima versão do padrão, mas o padrão é um trabalho em andamento. Use **/std: c + + 17** para usar os recursos no padrão ISO C++ mais recente.

O **/std** opção em vigor durante a compilação de C++ pode ser detectada pelo uso das [ \_MSVC\_LANG](../../preprocessor/predefined-macros.md) macro do pré-processador. Para obter mais informações, consulte [Macros de pré-processador](../../preprocessor/predefined-macros.md).

O **/std:c++17 + + 14** e **/std: c + + mais recente** opções estão disponíveis no Visual C++ 2015 atualização 3. O **/std: c + + 17** opção está disponível a partir no Visual C++ 2017 versão 15.3. Conforme observado acima, algumas padrão c++17 comportamento é habilitado pela **/std:c++17 + + 14** opção, mas todos os outros recursos do c++17 são habilitadas por **/std: c + + 17**.

> [!NOTE]
> Dependendo do MSVC compilador versão ou atualização do nível, determinados C + + 14 ou C + + 17 recursos talvez não estejam totalmente implementados ou totalmente compatível com quando você especifica o **/std:c++17 + + 14** ou **/std:c++17 + + 17** opções. Por exemplo, o compilador Visual C++ 2017 RTM não suporta totalmente C + + 14-compatível com `constexpr`, expressão SFINAE ou pesquisa de nome de fase 2. Para uma visão geral de conformidade com a linguagem C++ no Visual C++ por versão de lançamento, consulte [conformidade com a linguagem Visual C++](../../overview/visual-cpp-language-conformance.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **propriedades de configuração**, **C/C++**, **idioma**.

1. Na **padrão de linguagem C++**, escolha o padrão de linguagem para dar suporte a partir do controle de lista suspensa, em seguida, escolha **Okey** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
