---
title: -GL (otimização de programa inteiro) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /gl
- VC.Project.VCCLWCECompilerTool.WholeProgramOptimization
dev_langs:
- C++
helpviewer_keywords:
- /GL compiler option [C++]
- whole program optimizations and C++ compiler
- -GL compiler option [C++]
- GL compiler option [C++]
ms.assetid: 09d51e2d-9728-4bd0-b5dc-3b8284aca1d1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 97561a63a21550cc06f29a95f6ddf05687758b83
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723652"
---
# <a name="gl-whole-program-optimization"></a>/GL (otimização de todo o programa)

Habilita a otimização de todo o programa.

## <a name="syntax"></a>Sintaxe

```
/GL[-]
```

## <a name="remarks"></a>Comentários

Otimização de todo o programa permite que o compilador execute otimizações com informações sobre todos os módulos no programa. Sem otimização de todo o programa, as otimizações são executadas em uma base de módulo (compiland).

Otimização de todo o programa está desativado por padrão e deve ser habilitada explicitamente. No entanto, também é possível desabilitá-la com explicitamente **/GL-**.

Com informações sobre todos os módulos, o compilador pode:

- Otimize o uso de registros entre limites de função.

- Fazer um trabalho melhor de controlar as modificações de dados globais, permitindo uma redução no número de cargas e armazenamentos.

- Fazer um trabalho melhor de desreferenciar o possível conjunto de itens modificados por um ponteiro, reduzindo o número de cargas e armazenamentos de acompanhamento.

- Embutir uma função em um módulo, mesmo quando a função é definida em outro módulo.

arquivos. obj produzido com **/GL** não estarão disponíveis para esses utilitários do vinculador como [EDITBIN](../../build/reference/editbin-reference.md) e [DUMPBIN](../../build/reference/dumpbin-reference.md).

Se você compilar seu programa com **/GL** e [/c](../../build/reference/c-compile-without-linking.md), você deve usar a opção de vinculador /LTCG para criar o arquivo de saída.

[/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) não pode ser usado com **/GL**

O formato dos arquivos produzidos com **/GL** na versão atual podem não ser legíveis por versões subsequentes do Visual C++. Você não deve fornecer um arquivo. lib composto de arquivos. obj que foram gerados com **/GL** , a menos que você está disposto a enviar cópias do arquivo. lib para todas as versões do Visual C++ você espera que os usuários usem, agora e no futuro.

arquivos. obj produzido com **/GL** e arquivos de cabeçalho pré-compilado não devem ser usados para criar um arquivo. lib, a menos que o arquivo. lib será vinculado no mesmo computador que produziu o **/GL** arquivo. obj. Serão necessárias informações de arquivo de cabeçalho pré-compilado do arquivo. obj em tempo de vinculação.

Para obter mais informações sobre as otimizações disponíveis com e as limitações de otimização do programa completo, consulte [/LTCG](../../build/reference/ltcg-link-time-code-generation.md).  **/GL** também o torna disponível de Otimização Guiada por perfil; consulte /LTCG.  Ao compilar para otimizações e se deseja que a função de ordenação de suas otimizações guiadas por perfil guiada por perfil, você deve compilar com [/Gy](../../build/reference/gy-enable-function-level-linking.md) ou uma opção de compilador que implica /Gy.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Ver [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md) para obter informações sobre como especificar **/GL** no ambiente de desenvolvimento.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WholeProgramOptimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)