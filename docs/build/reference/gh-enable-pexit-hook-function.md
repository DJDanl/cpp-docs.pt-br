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
ms.openlocfilehash: 9be8573f5f9c344d2675bd7c9fc7d8beb3c8cffd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527641"
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

`_pexit` é semelhante à `_penter`; consulte [/Gh (habilitar penter função de gancho)](../../build/reference/gh-enable-penter-hook-function.md) para obter um exemplo de como escrever um `_pexit` função.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)