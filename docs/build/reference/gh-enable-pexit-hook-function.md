---
title: /GH (habilitar função de gancho _pexit)
ms.date: 11/04/2016
f1_keywords:
- _pexit
helpviewer_keywords:
- /Gh compiler option [C++]
- Gh compiler option [C++]
- _pexit function
- -Gh compiler option [C++]
ms.assetid: 93181453-2676-42e5-bf63-3b19e07299b6
ms.openlocfilehash: 5382ba90f490aaa12e9e55767fdf15170a69ced5
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749232"
---
# <a name="gh-enable-_pexit-hook-function"></a>/GH (habilitar função de gancho _pexit)

Chama `_pexit` a função no final de cada método ou função.

## <a name="syntax"></a>Sintaxe

```
/GH
```

## <a name="remarks"></a>Comentários

A `_pexit` função não faz parte de nenhuma biblioteca e cabe `_pexit`a você fornecer uma definição para .

A menos que você `_pexit`planeje ligar explicitamente, você não precisa fornecer um protótipo. A função deve aparecer como se tivesse o seguinte protótipo, e deve empurrar o conteúdo de todos os registros na entrada e colocar o conteúdo inalterado na saída:

```cpp
void __declspec(naked) __cdecl _pexit( void );
```

`_pexit`é semelhante `_penter`a; ver [/Gh (Habilitar _penter Função de Gancho)](gh-enable-penter-hook-function.md) para um exemplo de como escrever uma `_pexit` função.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página de propriedade Linha de **Comando.**

1. Digite a opção compilador na **caixa Opções adicionais.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
