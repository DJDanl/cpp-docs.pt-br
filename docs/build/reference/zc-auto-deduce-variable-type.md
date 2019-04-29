---
title: /Zc:auto (deduzir tipo variável)
ms.date: 02/28/2018
f1_keywords:
- /Zc:auto
helpviewer_keywords:
- -Zc compiler options (C++)
- Deduce variable type (C++)
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 5f5bc102-44c3-4688-bbe1-080594dcee5c
ms.openlocfilehash: ea977020286d720ed3a6b1b13bf8ff8f5c85e5b2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315957"
---
# <a name="zcauto-deduce-variable-type"></a>/Zc:auto (deduzir tipo variável)

O **/ZC: auto [-]** opção de compilador informa ao compilador como usar o [palavra-chave auto](../../cpp/auto-keyword.md) para declarar variáveis. Se você especificar a opção padrão, **/ZC: auto**, o compilador deduzirá o tipo da variável declarada da expressão de inicialização. Se você especificar **/Zc:auto-**, o compilador alocará a variável de classe de armazenamento automática.

## <a name="syntax"></a>Sintaxe

> **/Zc:auto**[**-**]

## <a name="remarks"></a>Comentários

O padrão C++ define um significado original e um significado revisado para a palavra-chave `auto`. Antes do Visual C++ 2010, a palavra-chave declara uma variável na classe de armazenamento automática; ou seja, uma variável que tem um tempo de vida local. Começando com o Visual C++ 2010, a palavra-chave deduz o tipo de uma variável da expressão de inicialização da declaração. Use o **/ZC: auto [-]** para informar ao compilador para usar o significado original ou revisado da opção do compilador o `auto` palavra-chave. O **/ZC: auto** opção permanece ativada por padrão. O [/permissive--](permissive-standards-conformance.md) opção não altera a configuração padrão de **/ZC: auto**.

O compilador emite uma mensagem de diagnóstico apropriada se o uso do `auto` palavra-chave contradiz atual **/ZC: auto** opção de compilador. Para obter mais informações, consulte [palavra-chave auto](../../cpp/auto-keyword.md). Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Adicione **/ZC: auto** ou **/Zc:auto-** para o **opções adicionais:** painel.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
[Palavra-chave auto](../../cpp/auto-keyword.md)
