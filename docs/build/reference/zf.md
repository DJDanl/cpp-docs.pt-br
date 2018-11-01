---
title: /ZF (geração de PDB mais rápido)
ms.date: 03/29/2018
f1_keywords:
- /Zf
helpviewer_keywords:
- /Zf
- -Zf
ms.openlocfilehash: 2c3f8d08f59c3a6803eda67126ef8a8f9ba6b1fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595723"
---
# <a name="zf-faster-pdb-generation"></a>/ZF (geração de PDB mais rápido)

Habilite a geração de PDB mais rápida em compilações paralelas, minimizando as chamadas RPC para mspdbsrv.exe.

## <a name="syntax"></a>Sintaxe

> **/Zf**

## <a name="remarks"></a>Comentários

O **/Zf** opção habilita o suporte de compilador para a geração mais rápida de arquivos PDB ao usar o [/MP (compilar com vários processos)](mp-build-with-multiple-processes.md) opção, ou quando o sistema de compilação (por exemplo, [MSBuild ](/visualstudio/msbuild/msbuild-reference) ou [CMake](../../ide/cmake-tools-for-visual-cpp.md)) podem executar cl.exe vários processos de compilador ao mesmo tempo. Essa opção faz com que o compilador front-end para atrasar a geração de índices de tipo para cada registro de tipo no arquivo PDB até o término da compilação, em seguida, solicita-los todos em uma única chamada RPC para mspdbsrv.exe, em vez de fazer uma solicitação RPC para cada registro. Isso pode melhorar consideravelmente a produtividade da compilação, reduzindo a carga RPC sobre o processo de mspdbsrv.exe em um ambiente em que vários processos de compilador cl.exe executados simultaneamente.

Porque o **/Zf** opção só se aplica a geração de PDB, ele requer o [/Zi](z7-zi-zi-debug-information-format.md) ou [/ZI](z7-zi-zi-debug-information-format.md) opção.

O **/Zf** opção está disponível partir do Visual Studio 2017 versão 15.1, onde ele está desativado por padrão. A partir do Visual Studio 2017 versão 15.7 Preview 3, essa opção é ativada por padrão quando o **/Zi** ou **/ZI** opção está habilitada.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/Zf** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do Compilador Listadas em Ordem Alfabética](compiler-options-listed-alphabetically.md)<br/>
[/MP (compilar com vários processos)](mp-build-with-multiple-processes.md)<br/>
