---
title: /FS (Forçar gravações PDB síncronas)
ms.date: 11/04/2016
f1_keywords:
- /FS
helpviewer_keywords:
- -FS compiler option [C++]
- /FS compiler option [C++]
ms.assetid: b2caaffe-f6e1-4963-b068-648f06b105e0
ms.openlocfilehash: 180fe17e2047744a68f477654dc95aa74b25f281
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50660887"
---
# <a name="fs-force-synchronous-pdb-writes"></a>/FS (Forçar gravações PDB síncronas)

Força grava no arquivo de banco de dados (PDB) do programa — criados pelo [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) ou [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md)— a ser serializado por meio de MSPDBSRV. EXE.

## <a name="syntax"></a>Sintaxe

```
/FS
```

## <a name="remarks"></a>Comentários

Por padrão, quando **/Zi** ou **/ZI** for especificado, o compilador bloqueia arquivos PDB para gravar informações de tipo e informações de depuração simbólicas. Isso pode reduzir significativamente o tempo que leva o compilador gerar informações de tipo quando o número de tipos é grande. Se outro processo bloquear temporariamente o arquivo PDB — por exemplo, um programa antivírus — gravações pelo compilador podem falhar e pode ocorrer um erro fatal. Esse problema também pode ocorrer quando várias cópias de cl.exe acessar o mesmo arquivo PDB — por exemplo, se sua solução tiver independentes diretórios de saída ou intermediário diretórios de projetos que usam o mesmo e compilações paralelas estão habilitadas. O **/FS** opção do compilador impede que o compilador está bloqueando o arquivo PDB e forçará as gravações para ir por meio de MSPDBSRV. EXE, que serializa o acesso. Isso pode tornar builds significativamente maiores, e ele não impede que todos os erros que podem ocorrer quando várias instâncias do cl.exe acessarem o arquivo PDB ao mesmo tempo. É recomendável que você altere sua solução para que os projetos independentes escreva separar intermediário e locais de saída, ou que você faça um dos projetos depende do outro para compilações de projetos de força serializada.

O [/MP](../../build/reference/mp-build-with-multiple-processes.md) opção habilita **/FS** por padrão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir `/FS` e, em seguida, escolha **Okey**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)