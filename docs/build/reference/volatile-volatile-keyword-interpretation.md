---
title: -volatile (interpretação da palavra-chave volatile) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /volatile:iso
- /volatile:ms
- /volatile
dev_langs:
- C++
helpviewer_keywords:
- /volatile compiler option
- /volatile compiler option [C++]
- -volatile compiler option
- volatile compiler option [C++]
- volatile compiler option
- -volatile compiler option [C++]
ms.assetid: 9d08fcc6-5bda-44c8-8151-8d8d54f164b8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4204d602d1390bf30080a800174426513faf0467
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723626"
---
# <a name="volatile-volatile-keyword-interpretation"></a>/volatile (Interpretação da palavra-chave volatile)

Especifica como o [volátil](../../cpp/volatile-cpp.md) palavra-chave deve ser interpretado.

## <a name="syntax"></a>Sintaxe

> **/volatile:**{**iso**|**ms**}

## <a name="arguments"></a>Arguments

**/volatile:iso**<br/>
Seleciona estrita `volatile` semântica conforme definido pela linguagem C++ padrão ISO. Semântica de aquisição/liberação não é garantida em acessos voláteis. Se o compilador direciona o ARM, essa é a interpretação padrão do `volatile`.

**/volatile:ms**<br/>
Seleciona estendidas da Microsoft `volatile` semântica, que adiciona garantias além da linguagem C++ padrão ISO de ordenação de memória. Semântica de aquisição/liberação é garantida em acessos voláteis. No entanto, essa opção também força o compilador a gerar as barreiras de memória do hardware, que podem adicionar uma sobrecarga significativa no ARM e outras arquiteturas fracas de classificação de memória. Se o compilador direciona qualquer plataforma exceto o ARM, essa é a interpretação padrão do `volatile`.

## <a name="remarks"></a>Comentários

É altamente recomendável que você use **/volatile: ISO** junto com primitivos de sincronização explícitos e intrínsecos do compilador quando você está lidando com a memória que é compartilhada entre threads. Para obter mais informações, consulte [volátil](../../cpp/volatile-cpp.md).

Se você porta o código existente ou alterar essa opção no meio de um projeto, pode ser útil habilitar o aviso [C4746](../../error-messages/compiler-warnings/compiler-warning-c4746.md) para identificar os locais de código que são afetados pela diferença na semântica.

Não há nenhum `#pragma` equivalente para controlar essa opção.

### <a name="to-set-the-volatile-compiler-option-in-visual-studio"></a>Para definir o /volatile opção de compilador no Visual Studio

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. No **opções adicionais** caixa, adicione **/volatile: ISO** ou **/volatile: MS** e, em seguida, escolha **Okey** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[volatile](../../cpp/volatile-cpp.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
