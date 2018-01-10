---
title: "-std (especificar a versão padrão do idioma) | Microsoft Docs"
ms.custom: 
ms.date: 11/16/2017
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /std
- -std
- VC.Project.VCCLCompilerTool.CppLanguageStandard
dev_langs: C++
ms.assetid: 0acb74ba-1aa8-4c05-b96c-682988dc19bd
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cb248f4c7ce1d9520bc328ed59b75ff081659996
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="std-specify-language-standard-version"></a>/STD (especificar a versão de idioma padrão)

Habilitar suporte para recursos de linguagem do C++ da versão especificada da linguagem C++ padrão.

## <a name="syntax"></a>Sintaxe

> /std: [c + + 14 | c++ 17 | mais recente do c + +]

## <a name="remarks"></a>Comentários

O **/std** opção é usada para controlar a versão específica ISO C++ recursos padrão do idioma habilitados durante a compilação do seu código de programação. Essa opção permite que você desabilite o suporte para determinados recursos novos do idioma e a biblioteca que pode interromper o seu código existente que esteja de acordo com uma versão específica do idioma padrão. Por padrão, **/std:c + + 14** for especificado, que desabilita o idioma e recursos de biblioteca padrão encontrados nas versões mais recentes da linguagem C++ padrão. Use **/std:c + + 17** para habilitar o C++ 17 específicas do padrão de recursos e o comportamento. Para habilitar explicitamente o mais recente com suporte compilador e recursos de biblioteca padrão, use **/std:c + + mais recente**.

O padrão **/std:c + + 14** opção permite que o conjunto de funcionalidades C++ 14 implementado pelo compilador do Visual C++. Esta opção desabilita o compilador e o suporte da biblioteca padrão para recursos que são alterados ou novos em versões mais recentes do idioma padrão, com exceção de alguns C++ 17 recursos já foi implementados em versões anteriores do compilador Visual C++. Para evitar alterações para usuários que já obtiveram dependências nos recursos disponíveis a partir do Visual Studio 2015 atualização 2, esses recursos permanecerão habilitados quando o **/std:c + + 14** opção é especificada:

- [Regras para auto com listas entre chaves de inicialização](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html)

- [TypeName em parâmetros de modelo do modelo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4051.html)

- [Removendo trigraphs](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4086.html)

- [Atributos para namespaces e enumeradores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html)

- [literais de caracteres U8](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html)

Para obter informações adicionais sobre quais C + + 14 e C++ 17 recursos estão habilitados quando **/std:c + + 14** é especificado, consulte as observações [conformidade de linguagem do Visual C++](../../visual-cpp-language-conformance.md).
  
O **/std:c + + 17** opção permite que o conjunto completo de 17 funcionalidades C++ implementado pelo compilador do Visual C++. Esta opção desabilita o compilador e o suporte da biblioteca padrão para recursos que são alterados ou novas versões das atualizações do rascunho de trabalho e defeito do C++ padrão após C++ 17.  
  
O **/std:c + + mais recente** opção permite que o conjunto de recursos de idioma e a biblioteca do C++ implementada pelo Visual C++ para controlar a maioria dos C + + 20 rascunho de trabalho e defeito atualizações recentes do C++ padrão que não estão incluídas no C++ 17. Use esta opção para obter o post-recursos de linguagem C++ 17 compatíveis com o compilador e a biblioteca padrão. Para obter uma lista de idiomas com suporte e recursos de biblioteca, consulte [novidades do Visual C++](../../what-s-new-for-visual-cpp-in-visual-studio.md). O **/std:c + + mais recente** opção não habilita recursos protegidos pelo **/ experimental** alternar.  
  
O **/std** opção em vigor durante uma compilação de C++ pode ser detectada usando o [ \_MSVC\_LANG](../../preprocessor/predefined-macros.md) macro de pré-processador. Para obter mais informações, consulte [Macros de pré-processador](../../preprocessor/predefined-macros.md).

O **/std:c + + 14** e **/std:c + + mais recente** opções estão disponível a partir do Visual C++ 2015 atualização 3. O **/std:c + + 17** opção está disponível a partir versão 15,3 2017 de Visual C++. Conforme observado acima, algum padrão C++ 17 comportamento é habilitado pelo **/std:c + + 14** opção, mas todos os outros recursos C++ 17 são habilitados por **/std:c + + 17**.
  
> [!NOTE]
> Dependendo do Visual C++ compilador versão ou atualização de nível, determinados C + + 14 ou C++ 17 recursos podem não ser totalmente implementados ou totalmente compatível ao especificar o **/std:c + + 14** ou **/std:c + + 17** opções. Por exemplo, o compilador do Visual C++ 2017 RTM não suporta completamente C + + 14-compatível `constexpr`, SFINAE de expressão ou pesquisa de nome de fase 2. Para obter uma visão geral de conformidade de linguagem C++ no Visual C++ por versão de lançamento, consulte [conformidade de linguagem do Visual C++](../../visual-cpp-language-conformance.md). 
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione **propriedades de configuração**, **C/C++**, **idioma**.  
  
3.  Em **padrão de linguagem do C++**, escolha o padrão de linguagem para dar suporte o controle de lista suspensa e escolha **Okey** ou **aplicar** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
  
[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
