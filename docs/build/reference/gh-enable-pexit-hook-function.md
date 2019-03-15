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
ms.openlocfilehash: 077096cc296f2aa2128127493a84a91da9a067c5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822165"
---
# <a name="gh-enable-pexit-hook-function"></a>/GH (habilitar função de gancho _pexit)

Chamadas a `_pexit` função ao final de cada método ou função.

## <a name="syntax"></a>Sintaxe

```
/GH
```

## <a name="remarks"></a>Comentários

O `_pexit` função não faz parte de qualquer biblioteca e cabe a você fornecer uma definição para `_pexit`.

A menos que você planeja chamar explicitamente `_pexit`, você não precisa fornecer um protótipo. A função deve aparecer como se tivesse o protótipo a seguir, e ele deve enviar por push o conteúdo de todos os registros na entrada e pop o conteúdo inalterado na saída:

```
void __declspec(naked) __cdecl _pexit( void );
```

`_pexit` é semelhante à `_penter`; consulte [/Gh (habilitar penter função de gancho)](gh-enable-penter-hook-function.md) para obter um exemplo de como escrever um `_pexit` função.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
