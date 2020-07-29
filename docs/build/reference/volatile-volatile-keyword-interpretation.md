---
title: /volatile (Interpretação da palavra-chave volatile)
ms.date: 11/04/2016
f1_keywords:
- /volatile:iso
- /volatile:ms
- /volatile
helpviewer_keywords:
- /volatile compiler option
- /volatile compiler option [C++]
- -volatile compiler option
- volatile compiler option [C++]
- volatile compiler option
- -volatile compiler option [C++]
ms.assetid: 9d08fcc6-5bda-44c8-8151-8d8d54f164b8
ms.openlocfilehash: 7c2c1cd477b424f56e66bd9246e7bde76ad06120
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223779"
---
# <a name="volatile-volatile-keyword-interpretation"></a>/volatile (Interpretação da palavra-chave volatile)

Especifica como a palavra-chave [volatile](../../cpp/volatile-cpp.md) deve ser interpretada.

## <a name="syntax"></a>Sintaxe

> **/volatile:**{**ISO** | **MS**}

## <a name="arguments"></a>Argumentos

**/volatile: ISO**<br/>
Seleciona **`volatile`** semântica estrita, conforme definido pela linguagem de C++ ISO-Standard. A semântica de aquisição/liberação não é garantida em acessos voláteis. Se o compilador tiver como alvo o ARM, essa é a interpretação padrão do **`volatile`** .

**/volatile: MS**<br/>
Seleciona a semântica estendida da Microsoft **`volatile`** , que adiciona garantias de ordenação de memória além da linguagem C++ padrão ISO. A semântica de aquisição/liberação é garantida em acessos voláteis. No entanto, essa opção também força o compilador a gerar barreiras de memória de hardware, o que pode adicionar uma sobrecarga significativa no ARM e outras arquiteturas de ordenação de memória fracas. Se o compilador tiver como alvo qualquer plataforma, exceto ARM, essa será a interpretação padrão do **`volatile`** .

## <a name="remarks"></a>Comentários

É altamente recomendável que você use **/volatile: ISO** juntamente com primitivos de sincronização explícitos e intrínsecos de compilador quando estiver lidando com a memória que é compartilhada entre threads. Para obter mais informações, consulte [volátil](../../cpp/volatile-cpp.md).

Se você portar o código existente ou alterar essa opção no meio de um projeto, poderá ser útil habilitar o [C4746](../../error-messages/compiler-warnings/compiler-warning-c4746.md) de aviso para identificar os locais de código afetados pela diferença em semântica.

Não há nenhum `#pragma` equivalente para controlar essa opção.

### <a name="to-set-the-volatile-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/volatile no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Na caixa **Opções adicionais** , adicione **/volatile: ISO** ou **/volatile: MS** e, em seguida, escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[volatile](../../cpp/volatile-cpp.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
