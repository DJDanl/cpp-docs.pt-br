---
title: /Qfast_transcendentals (forçar transcendentais rápidos)
ms.date: 11/04/2016
f1_keywords:
- /Qfast_transcendentals
helpviewer_keywords:
- /Qfast_transcendentals
- Force Fast Transcendentals
ms.assetid: 4de24bd1-38e6-49d4-9a05-04c9937d24ac
ms.openlocfilehash: 383a915721d627367ca2ca035957df947996bbe2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319311"
---
# <a name="qfasttranscendentals-force-fast-transcendentals"></a>/Qfast_transcendentals (forçar transcendentais rápidos)

Gera código embutido para funções transcendentais.

## <a name="syntax"></a>Sintaxe

```
/Qfast_transcendentals
```

## <a name="remarks"></a>Comentários

Essa opção do compilador força funções transcendentais a ser convertido em código embutido para melhorar a velocidade de execução. Essa opção tem efeito somente quando combinado com **/fp: except** ou **/fp: preciso**. Já é o comportamento padrão em geração de código embutido para funções transcendentais **Fast**.

Essa opção é incompatível com **/fp: strict**. Ver [/fp (Especificar comportamento de ponto flutuante)](fp-specify-floating-point-behavior.md) para obter mais informações sobre opções do compilador do ponto de flutuante.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
