---
title: /GH (habilitar função de gancho _pexit)
description: Descreve a opção de compilador/GH para definir uma função de gancho de _pexit local.
ms.date: 07/06/2020
f1_keywords:
- _pexit
helpviewer_keywords:
- /Gh compiler option [C++]
- Gh compiler option [C++]
- _pexit function
- -Gh compiler option [C++]
ms.assetid: 93181453-2676-42e5-bf63-3b19e07299b6
ms.openlocfilehash: b8fc355503055af8b928874ced39cb8224901d3e
ms.sourcegitcommit: 85d96eeb1ce41d9e1dea947f65ded672e146238b
ms.contentlocale: pt-BR
ms.lasthandoff: 07/07/2020
ms.locfileid: "86058601"
---
# <a name="gh-enable-_pexit-hook-function"></a>/GH (habilitar função de gancho _pexit)

Chama a `_pexit` função no final de cada método ou função.

## <a name="syntax"></a>Sintaxe

> **`/GH`**

## <a name="remarks"></a>Comentários

A `_pexit` função não faz parte de nenhuma biblioteca. Cabe a você fornecer uma definição para `_pexit` .

A menos que você planeje chamar explicitamente `_pexit` , não precisa fornecer um protótipo. A função deve enviar por push o conteúdo de todos os registros na entrada e retirar o conteúdo inalterado na saída. Ele deve aparecer como se tivesse o seguinte protótipo:

```cpp
void __declspec(naked) __cdecl _pexit( void );
```

Essa declaração não está disponível para projetos de 64 bits.

`_pexit`é semelhante a `_penter` ; consulte [ `/Gh` (habilitar função de gancho de _penter)](gh-enable-penter-hook-function.md) para obter um exemplo de como escrever uma `_penter` função.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a **Configuration Properties**página de propriedades de  >  linha de comando**C/C++** Properties  >  **Command Line** .

1. Insira a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[`/Gh`(Habilitar função de gancho de _penter)](gh-enable-penter-hook-function.md)
