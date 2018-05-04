---
title: /ZF (geração de PDB mais rápido) | Microsoft Docs
ms.date: 03/29/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Zf
dev_langs:
- C++
helpviewer_keywords:
- /Zf
- -Zf
author: corob-msft
ms.author: corob
ms.openlocfilehash: 968ce17302fa608888c7ae2fedf695946b0119bd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zf-faster-pdb-generation"></a>/ZF (geração de PDB mais rápido)

Habilite a geração de PDB mais rápida em compilações paralelas, minimizando as chamadas RPC para mspdbsrv.exe.

## <a name="syntax"></a>Sintaxe

> **/Zf**

## <a name="remarks"></a>Comentários

O **/Zf** opção habilita o suporte de compilador para a geração mais rápida de arquivos PDB ao usar o [/MP (compilar com vários processos)](mp-build-with-multiple-processes.md) opção, ou quando o sistema de compilação (por exemplo, [MSBuild ](/visualstudio/msbuild/msbuild-reference) ou [CMake](../../ide/cmake-tools-for-visual-cpp.md)) podem executar cl.exe vários processos de compilador ao mesmo tempo. Esta opção faz com que o front-end de compilador atrasar a geração de índices de tipo para cada registro de tipo no arquivo PDB até o término da compilação e solicita-los em uma única chamada RPC para mspdbsrv.exe, em vez de fazer uma solicitação RPC para cada registro. Isso pode aprimorar substancialmente taxa de transferência de compilação, reduzindo a carga RPC do processo mspdbsrv.exe em um ambiente em que vários processos de compilador cl.exe executados simultaneamente.

Porque o **/Zf** opção só se aplica a geração de PDB, ele requer o [/Zi](z7-zi-zi-debug-information-format.md) ou [/ZI](z7-zi-zi-debug-information-format.md) opção.

O **/Zf** opção está disponível a partir no Visual Studio 2017 versão 15.1, onde ele está desativado por padrão. A partir do Visual Studio 2017 versão 15,7 Preview 3, essa opção é ativada por padrão quando o **/Zi** ou **/ZI** opção é habilitada.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/Zf** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do Compilador Listadas em Ordem Alfabética](compiler-options-listed-alphabetically.md)<br/>
[/MP (compilar com vários processos)](mp-build-with-multiple-processes.md)<br/>
